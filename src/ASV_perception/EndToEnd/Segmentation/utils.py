# FROM https://github.com/mit-han-lab/spvnas
import os
import re
import sys
import time
from contextlib import nullcontext
from pathlib import Path

import numpy as np
import torch
from torchvision.ops import box_convert

try:
    import torchsparse.nn.functional as F
    from torchsparse import PointTensor, SparseTensor
    from torchsparse.nn.utils import get_kernel_offsets
    from torchsparse.utils.quantize import sparse_quantize
    from torchsparse.utils.collate import sparse_collate
    TORCHSPARSE_AVAILABLE = True
except ImportError:
    F = None
    PointTensor = None
    SparseTensor = None
    get_kernel_offsets = None
    sparse_quantize = None
    sparse_collate = None
    TORCHSPARSE_AVAILABLE = False

SEGMENTATION_DIR = Path(__file__).resolve().parent
if str(SEGMENTATION_DIR) not in sys.path:
    sys.path.append(str(SEGMENTATION_DIR))

from sam2.build_sam import build_sam2
from sam2.sam2_image_predictor import SAM2ImagePredictor
from grounding_dino.groundingdino.util.inference import load_model, load_image, predict



__all__ = [
    'initial_voxelize',
    'point_to_voxel',
    'voxel_to_point',
    'generate_seg_in',
    'project_lidar_to_image',
    'initialize_segmentation_models',
    'generate_point_labels',
]


def _require_torchsparse():
    if not TORCHSPARSE_AVAILABLE:
        raise ImportError(
            "TorchSparse is not installed. The current online Blueboat perception path "
            "does not require it, but the legacy voxelization helpers still do."
        )


# z: PointTensor
# return: SparseTensor
def initial_voxelize(z, init_res, after_res):
    _require_torchsparse()
    new_float_coord = torch.cat(
        [(z.C[:, :3] * init_res) / after_res, z.C[:, -1].view(-1, 1)], 1)

    pc_hash = F.sphash(torch.floor(new_float_coord).int())
    sparse_hash = torch.unique(pc_hash)
    idx_query = F.sphashquery(pc_hash, sparse_hash)
    counts = F.spcount(idx_query.int(), len(sparse_hash))

    inserted_coords = F.spvoxelize(torch.floor(new_float_coord), idx_query,
                                   counts)
    inserted_coords = torch.round(inserted_coords).int()
    inserted_feat = F.spvoxelize(z.F, idx_query, counts)

    new_tensor = SparseTensor(inserted_feat, inserted_coords, 1)
    new_tensor.cmaps.setdefault(new_tensor.stride, new_tensor.coords)
    z.additional_features['idx_query'][1] = idx_query
    z.additional_features['counts'][1] = counts
    z.C = new_float_coord

    return new_tensor


# x: SparseTensor, z: PointTensor
# return: SparseTensor
def point_to_voxel(x, z):
    _require_torchsparse()
    if z.additional_features is None or z.additional_features.get(
            'idx_query') is None or z.additional_features['idx_query'].get(
                x.s) is None:
        pc_hash = F.sphash(
            torch.cat([
                torch.floor(z.C[:, :3] / x.s[0]).int() * x.s[0],
                z.C[:, -1].int().view(-1, 1)
            ], 1))
        sparse_hash = F.sphash(x.C)
        idx_query = F.sphashquery(pc_hash, sparse_hash)
        counts = F.spcount(idx_query.int(), x.C.shape[0])
        z.additional_features['idx_query'][x.s] = idx_query
        z.additional_features['counts'][x.s] = counts
    else:
        idx_query = z.additional_features['idx_query'][x.s]
        counts = z.additional_features['counts'][x.s]

    inserted_feat = F.spvoxelize(z.F, idx_query, counts)
    new_tensor = SparseTensor(inserted_feat, x.C, x.s)
    new_tensor.cmaps = x.cmaps
    new_tensor.kmaps = x.kmaps

    return new_tensor


# x: SparseTensor, z: PointTensor
# return: PointTensor
def voxel_to_point(x, z, nearest=False):
    _require_torchsparse()
    if z.idx_query is None or z.weights is None or z.idx_query.get(
            x.s) is None or z.weights.get(x.s) is None:
        off = get_kernel_offsets(2, x.s, 1, device=z.F.device)
        old_hash = F.sphash(
            torch.cat([
                torch.floor(z.C[:, :3] / x.s[0]).int() * x.s[0],
                z.C[:, -1].int().view(-1, 1)
            ], 1), off)
        pc_hash = F.sphash(x.C.to(z.F.device))
        idx_query = F.sphashquery(old_hash, pc_hash)
        weights = F.calc_ti_weights(z.C, idx_query,
                                    scale=x.s[0]).transpose(0, 1).contiguous()
        idx_query = idx_query.transpose(0, 1).contiguous()
        if nearest:
            weights[:, 1:] = 0.
            idx_query[:, 1:] = -1
        new_feat = F.spdevoxelize(x.F, idx_query, weights)
        new_tensor = PointTensor(new_feat,
                                 z.C,
                                 idx_query=z.idx_query,
                                 weights=z.weights)
        new_tensor.additional_features = z.additional_features
        new_tensor.idx_query[x.s] = idx_query
        new_tensor.weights[x.s] = weights
        z.idx_query[x.s] = idx_query
        z.weights[x.s] = weights

    else:
        new_feat = F.spdevoxelize(x.F, z.idx_query.get(x.s), z.weights.get(x.s))
        new_tensor = PointTensor(new_feat,
                                 z.C,
                                 idx_query=z.idx_query,
                                 weights=z.weights)
        new_tensor.additional_features = z.additional_features

    return new_tensor


def generate_seg_in(lidar, res):
    _require_torchsparse()
    # Create input data
    coords = np.round(lidar[:, :3] / res)
    coords -= coords.min(0, keepdims=1)
    feats = lidar
    # Filter out duplicate points
    coords, indices, inverse = sparse_quantize(coords, return_index=True, return_inverse=True)
    coords = torch.tensor(coords, dtype=torch.int)
    feats = torch.tensor(feats[indices], dtype=torch.float)

    inputs = SparseTensor(coords=coords, feats=feats)
    inputs = sparse_collate([inputs]).cuda()
    return inputs, inverse

def project_lidar_to_image(points_3d, camera_intrinsics, lidar_to_camera_transform, image_width, image_height):
    """Project 3D LiDAR points into a 2D camera image plane."""

    points_3d_h = np.hstack((points_3d, np.ones((points_3d.shape[0], 1), dtype=np.float64)))
    points_camera = (lidar_to_camera_transform @ points_3d_h.T).T[:, :3]

    valid_camera_indices = points_camera[:, 2] > 0.0
    points_camera = points_camera[valid_camera_indices]
    if points_camera.size == 0:
        return (
            np.empty((0, 2), dtype=np.int32),
            np.empty((0,), dtype=np.float32),
            np.empty((0,), dtype=np.int64),
        )

    pixels = (camera_intrinsics @ points_camera.T).T
    pixels = pixels[:, :2] / points_camera[:, 2:3]

    valid_fov_indices = (
        (pixels[:, 0] >= 0.0)
        & (pixels[:, 0] < image_width)
        & (pixels[:, 1] >= 0.0)
        & (pixels[:, 1] < image_height)
    )

    valid_indices = np.where(valid_camera_indices)[0][valid_fov_indices]
    pixels = pixels[valid_fov_indices].astype(np.int32)

    return pixels, points_camera[valid_fov_indices, 2], valid_indices

DEFAULT_SAM2_VARIANT = os.environ.get("SAM2_VARIANT", "small").strip().lower()
SAM2_VARIANTS = {
    "tiny": ("sam2.1_hiera_tiny.pt", "configs/sam2.1/sam2.1_hiera_t.yaml"),
    "small": ("sam2.1_hiera_small.pt", "configs/sam2.1/sam2.1_hiera_s.yaml"),
    "base_plus": ("sam2.1_hiera_base_plus.pt", "configs/sam2.1/sam2.1_hiera_b+.yaml"),
    "large": ("sam2.1_hiera_large.pt", "configs/sam2.1/sam2.1_hiera_l.yaml"),
}
GROUNDING_DINO_CONFIG = str(
    SEGMENTATION_DIR / "grounding_dino" / "groundingdino" / "config" / "GroundingDINO_SwinT_OGC.py"
)
GROUNDING_DINO_CHECKPOINT = str(
    SEGMENTATION_DIR / "gdino_checkpoints" / "groundingdino_swint_ogc.pth"
)
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"

_sam2_predictor = None
_grounding_model = None
_model_signature = None


def _log(logger, level, message):
    if logger is None:
        print(message)
    else:
        method_name = {"warn": "warning"}.get(level, level)
        log_method = getattr(logger, method_name, None)
        if log_method is None:
            print(message)
            return
        try:
            log_method(message)
        except Exception:
            # Logging should never take down online perception. Fall back to stdout.
            print(message)


def _normalize_label_alias(value):
    return re.sub(r"[^a-z0-9]+", "", str(value).strip().lower())


def _get_segmentation_config(model_params):
    segmentation_config = dict(model_params.get("segmentation", {}))
    if not segmentation_config:
        raise KeyError("Perception config is missing the required 'segmentation' section.")
    if not segmentation_config.get("classes") or not segmentation_config.get("label_to_index"):
        raise KeyError(
            "Perception config is missing segmentation.classes or the derived label index map."
        )
    return segmentation_config


def _resolve_sam2_variant(segmentation_config):
    sam2_variant = str(segmentation_config.get("sam2_variant", DEFAULT_SAM2_VARIANT)).strip().lower()
    if sam2_variant not in SAM2_VARIANTS:
        raise ValueError(
            f"Unsupported SAM2 variant '{sam2_variant}'. "
            f"Choose one of: {', '.join(sorted(SAM2_VARIANTS))}."
        )
    return sam2_variant


def _resolve_sam2_autocast_dtype(segmentation_config):
    autocast_value = str(
        segmentation_config.get(
            "sam2_autocast_dtype",
            segmentation_config.get("autocast_dtype", ""),
        )
    ).strip().lower()
    if DEVICE != "cuda" or autocast_value in {"", "none", "off", "false"}:
        return None

    dtype_lookup = {
        "float16": torch.float16,
        "fp16": torch.float16,
        "half": torch.float16,
        "bfloat16": torch.bfloat16,
        "bf16": torch.bfloat16,
    }
    if autocast_value not in dtype_lookup:
        raise ValueError(
            f"Unsupported segmentation sam2_autocast_dtype '{autocast_value}'. "
            "Choose one of: bfloat16, bf16, float16, fp16, half, none."
        )
    return dtype_lookup[autocast_value]


def _sam2_autocast_context(segmentation_config):
    autocast_dtype = _resolve_sam2_autocast_dtype(segmentation_config)
    if autocast_dtype is None:
        return nullcontext()
    return torch.autocast(device_type="cuda", dtype=autocast_dtype)


def _resolve_grounding_dino_autocast_dtype(segmentation_config):
    autocast_value = str(
        segmentation_config.get(
            "grounding_dino_autocast_dtype",
            segmentation_config.get("grounding_autocast_dtype", ""),
        )
    ).strip().lower()
    if DEVICE != "cuda" or autocast_value in {"", "none", "off", "false", "float32", "fp32"}:
        return None

    if autocast_value in {"bfloat16", "bf16"}:
        raise ValueError(
            "GroundingDINO autocast does not support bfloat16 on the current Jetson CUDA build. "
            "Use float16/fp16/half or disable autocast."
        )

    dtype_lookup = {
        "float16": torch.float16,
        "fp16": torch.float16,
        "half": torch.float16,
    }
    if autocast_value not in dtype_lookup:
        raise ValueError(
            f"Unsupported segmentation grounding_dino_autocast_dtype '{autocast_value}'. "
            "Choose one of: float16, fp16, half, none."
        )
    return dtype_lookup[autocast_value]


def _grounding_dino_autocast_context(segmentation_config):
    autocast_dtype = _resolve_grounding_dino_autocast_dtype(segmentation_config)
    if autocast_dtype is None:
        return nullcontext()
    return torch.autocast(device_type="cuda", dtype=autocast_dtype)


def initialize_segmentation_models(model_params, logger=None, force_reload=False):
    global _sam2_predictor, _grounding_model, _model_signature

    segmentation_config = _get_segmentation_config(model_params)
    sam2_variant = _resolve_sam2_variant(segmentation_config)
    model_signature = (DEVICE, sam2_variant)

    if (
        not force_reload
        and _sam2_predictor is not None
        and _grounding_model is not None
        and _model_signature == model_signature
    ):
        return _sam2_predictor, _grounding_model

    sam2_checkpoint_name, sam2_model_config = SAM2_VARIANTS[sam2_variant]
    sam2_checkpoint = str(SEGMENTATION_DIR / "checkpoints" / sam2_checkpoint_name)

    if not os.path.exists(sam2_checkpoint):
        raise FileNotFoundError(
            f"SAM2 checkpoint not found at {sam2_checkpoint}. "
            "Run setup_perception.sh to install the required weights."
        )
    if not os.path.exists(GROUNDING_DINO_CHECKPOINT):
        raise FileNotFoundError(
            f"GroundingDINO checkpoint not found at {GROUNDING_DINO_CHECKPOINT}. "
            "Run setup_perception.sh to install the required weights."
        )

    _log(
        logger,
        "info",
        f"Loading segmentation models on {DEVICE} using SAM2 variant '{sam2_variant}'"
        + (
            f" with SAM2 autocast={str(_resolve_sam2_autocast_dtype(segmentation_config)).split('.')[-1]}."
            if _resolve_sam2_autocast_dtype(segmentation_config) is not None else "."
        )
        + (
            f" GroundingDINO autocast={str(_resolve_grounding_dino_autocast_dtype(segmentation_config)).split('.')[-1]}."
            if _resolve_grounding_dino_autocast_dtype(segmentation_config) is not None else ""
        ),
    )
    start_t = time.time()

    sam2_model = build_sam2(sam2_model_config, sam2_checkpoint, device=DEVICE)
    _sam2_predictor = SAM2ImagePredictor(sam2_model)

    _grounding_model = load_model(
        model_config_path=GROUNDING_DINO_CONFIG,
        model_checkpoint_path=GROUNDING_DINO_CHECKPOINT,
        device=DEVICE,
    )

    _log(
        logger,
        "info",
        f"Segmentation models loaded in {time.time() - start_t:.2f}s.",
    )
    _model_signature = model_signature
    return _sam2_predictor, _grounding_model


def generate_point_labels(lidar, model_params, image, projected_pixels=None, logger=None):
    """
    Generates per-point semantic labels by projecting filtered LiDAR into the
    current camera view, then transferring GroundingDINO + SAM2 image masks
    back onto those visible points.
    
    Args:
        lidar (np.array): LiDAR point cloud (N, 4) [x, y, z, intensity].
        model_params (dict): Active perception config.
        image (np.array): RGB image from the camera.

    Returns:
        None: Legacy sparse segmentation input is unused in the active Blueboat path.
        None: Legacy inverse map is unused in the active Blueboat path.
        point_labels (np.array): One-hot encoded labels for each LiDAR point (N, num_classes).
    """
    segmentation_config = _get_segmentation_config(model_params)
    sam2_predictor, grounding_model = initialize_segmentation_models(model_params, logger=logger)
    label_to_index = segmentation_config["label_to_index"]
    num_classes = int(model_params["num_classes"])
    text_prompt = str(segmentation_config["text_prompt"]).strip()
    box_threshold = float(segmentation_config.get("box_threshold", 0.30))
    text_threshold = float(segmentation_config.get("text_threshold", 0.05))
    grounding_input_size = int(segmentation_config.get("grounding_input_size", 800))
    grounding_max_size = int(segmentation_config.get("grounding_max_size", 1333))
    grounding_allow_upscale = bool(segmentation_config.get("grounding_allow_upscale", True))

    def empty_point_labels(reason):
        _log(logger, "warn", reason)
        return None, None, np.zeros((lidar.shape[0], num_classes), dtype=np.float32)

    # Step 1: Run Grounded SAM2 on `image` to get segmentation masks
    image_source, image_tensor = load_image(
        image,
        resize_short_side=grounding_input_size,
        max_size=grounding_max_size,
        allow_upscale=grounding_allow_upscale,
    )

    with _grounding_dino_autocast_context(segmentation_config):
        boxes, confidences, labels = predict(
            model=grounding_model,
            image=image_tensor,
            caption=text_prompt,
            box_threshold=box_threshold,
            text_threshold=text_threshold,
            device=DEVICE,
            remove_combined=True,
        )

    if boxes is None or boxes.numel() == 0:
        return empty_point_labels(
            "GroundingDINO returned no detections; publishing empty semantic labels for this frame."
        )

    if boxes.ndim == 1:
        boxes = boxes.unsqueeze(0)

    valid_box_mask = torch.isfinite(boxes).all(dim=1)
    if confidences is not None and torch.is_tensor(confidences) and confidences.numel() == boxes.shape[0]:
        valid_box_mask &= torch.isfinite(confidences)
    if boxes.shape[1] >= 4:
        valid_box_mask &= torch.isfinite(boxes[:, 2:4]).all(dim=1)
        valid_box_mask &= (boxes[:, 2] > 0) & (boxes[:, 3] > 0)

    if not torch.any(valid_box_mask):
        return empty_point_labels(
            "GroundingDINO produced only invalid/NaN detections; skipping SAM2 for this frame."
        )

    boxes = boxes[valid_box_mask]
    if confidences is not None and torch.is_tensor(confidences) and confidences.numel() == valid_box_mask.shape[0]:
        confidences = confidences[valid_box_mask]
    labels = [label for label, keep in zip(labels, valid_box_mask.tolist()) if keep]

    # Process bounding boxes
    h, w, _ = image_source.shape
    boxes = boxes * torch.Tensor([w, h, w, h])
    input_boxes = box_convert(boxes=boxes, in_fmt="cxcywh", out_fmt="xyxy").numpy()
    finite_input_mask = np.isfinite(input_boxes).all(axis=1)
    positive_extent_mask = (input_boxes[:, 2] > input_boxes[:, 0]) & (input_boxes[:, 3] > input_boxes[:, 1])
    valid_input_mask = finite_input_mask & positive_extent_mask
    if not np.any(valid_input_mask):
        return empty_point_labels(
            "Converted SAM2 prompt boxes were empty/invalid; skipping semantic labeling for this frame."
        )
    input_boxes = input_boxes[valid_input_mask]
    labels = [label for label, keep in zip(labels, valid_input_mask.tolist()) if keep]

    # Get segmentation masks
    try:
        with _sam2_autocast_context(segmentation_config):
            sam2_predictor.set_image(image_source)
            masks, _, _ = sam2_predictor.predict(
                point_coords=None, point_labels=None, box=input_boxes, multimask_output=False
            )
    except (AssertionError, RuntimeError, ValueError) as exc:
        return empty_point_labels(
            f"SAM2 mask prediction failed for this frame ({exc}); publishing empty semantic labels."
        )

    # Convert masks to (num_classes, H, W) format
    if masks.ndim == 4:
        masks = masks.squeeze(1)
    if masks.ndim == 2:
        masks = masks[None, ...]

    class_ids = np.array([
        label_to_index.get(_normalize_label_alias(class_name), -1)
        for class_name in labels
    ], dtype=np.int32)

    known_class_mask = class_ids >= 0
    if not np.any(known_class_mask):
        return empty_point_labels(
            "GroundingDINO detections did not match any configured semantic class; publishing empty labels."
        )

    masks = masks[known_class_mask]
    class_ids = class_ids[known_class_mask]

    # Initialize a combined mask (same size as image)
    h, w, _ = image_source.shape
    combined_mask = np.zeros((h, w), dtype=np.uint8)

    # Assign unique class IDs to the combined mask
    for class_idx, mask in zip(class_ids, masks):
        combined_mask[mask > 0] = class_idx + 1  # Avoid class ID 0 (reserved for background)

    if projected_pixels is None:
        raise ValueError("projected_pixels must be provided by the geometry layer.")

    projected_pixels = np.asarray(projected_pixels, dtype=np.int32)
    if projected_pixels.shape[0] != lidar.shape[0]:
        raise ValueError(
            "Projected pixel count must match the filtered LiDAR point count. "
            f"Got {projected_pixels.shape[0]} pixels for {lidar.shape[0]} points."
        )

    # Step 3: Assign class labels based on projection
    img_h, img_w, _ = image_source.shape
    valid_indices = (
        (0 <= projected_pixels[:, 0]) & (projected_pixels[:, 0] < img_w) &
        (0 <= projected_pixels[:, 1]) & (projected_pixels[:, 1] < img_h)
    )

    # Initialize point labels (N, num_classes) → One-hot encoding
    point_labels = np.zeros((lidar.shape[0], num_classes), dtype=np.float32)
    valid_projected_pixels = projected_pixels[valid_indices]
    mask_classes = combined_mask[valid_projected_pixels[:, 1], valid_projected_pixels[:, 0]].astype(np.int32) - 1
    labeled_mask = mask_classes >= 0
    if np.any(labeled_mask):
        valid_point_indices = np.nonzero(valid_indices)[0][labeled_mask]
        point_labels[valid_point_indices, mask_classes[labeled_mask]] = 1.0

    # The current Blueboat online mapping path only consumes point_labels.
    # Keep the return shape stable for callers while avoiding the legacy
    # TorchSparse/CUDA preprocessing that is unused here.
    return None, None, point_labels
