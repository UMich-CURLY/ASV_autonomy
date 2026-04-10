import os
import re
from pathlib import Path

import yaml


ENDTOEND_DIR = Path(__file__).resolve().parent
CONFIGS_DIR = ENDTOEND_DIR / "Configs"

CONFIG_ENV_VAR = "ASV_PERCEPTION_CONFIG"
DEFAULT_CONFIG_NAME = "blueboat_real"
LEGACY_CONFIG_ALIASES = {
    "KITTI": DEFAULT_CONFIG_NAME,
}


def _normalize_label_alias(value):
    return re.sub(r"[^a-z0-9]+", "", str(value).strip().lower())


def _resolve_named_config_path(config_name):
    resolved_name = LEGACY_CONFIG_ALIASES.get(str(config_name), str(config_name))
    return resolved_name, CONFIGS_DIR / f"{resolved_name}.yaml"


def resolve_model_config_path(selection=None):
    selection = selection or os.environ.get(CONFIG_ENV_VAR, DEFAULT_CONFIG_NAME)
    selection = str(selection).strip()
    if not selection:
        selection = DEFAULT_CONFIG_NAME

    if selection.endswith(".yaml") or os.sep in selection:
        candidate = Path(selection).expanduser()
        if not candidate.is_absolute():
            config_path = (Path.cwd() / candidate).resolve()
        else:
            config_path = candidate.resolve()
        config_name = config_path.stem
    else:
        config_name, config_path = _resolve_named_config_path(selection)
        config_path = config_path.resolve()

    if not config_path.exists():
        raise FileNotFoundError(
            f"Perception config '{selection}' could not be resolved. "
            f"Set {CONFIG_ENV_VAR} to a config name under {CONFIGS_DIR} "
            "or to an explicit .yaml path."
        )

    config_name = LEGACY_CONFIG_ALIASES.get(config_name, config_name)
    return config_name, config_path


def _normalize_segmentation_config(segmentation_config):
    classes = segmentation_config.get("classes")
    if not classes:
        return segmentation_config, None, None

    normalized_classes = []
    color_map = {}
    label_to_index = {}

    for index, entry in enumerate(classes):
        if not isinstance(entry, dict):
            raise ValueError("Each segmentation class entry must be a mapping.")

        name = str(entry["name"]).strip()
        aliases = entry.get("aliases", [])
        color = entry["color"]
        if len(color) != 3:
            raise ValueError(f"Segmentation class '{name}' must define an RGB color triplet.")

        normalized_entry = {
            "name": name,
            "aliases": [str(alias).strip() for alias in aliases],
            "color": [int(channel) for channel in color],
        }
        normalized_classes.append(normalized_entry)
        color_map[index] = normalized_entry["color"]

        all_aliases = [name] + normalized_entry["aliases"]
        for alias in all_aliases:
            label_to_index[_normalize_label_alias(alias)] = index

    text_prompt = segmentation_config.get("text_prompt")
    if not text_prompt:
        text_prompt = ". ".join(entry["name"] for entry in normalized_classes) + "."

    normalized_segmentation = dict(segmentation_config)
    normalized_segmentation["classes"] = normalized_classes
    normalized_segmentation["text_prompt"] = str(text_prompt).strip()
    normalized_segmentation["label_to_index"] = label_to_index
    normalized_segmentation["color_map"] = color_map
    return normalized_segmentation, len(normalized_classes), color_map


def normalize_model_params(model_params, config_name=None, config_path=None):
    normalized = dict(model_params)
    segmentation_config = dict(normalized.get("segmentation", {}))
    normalized_segmentation, inferred_num_classes, color_map = _normalize_segmentation_config(
        segmentation_config
    )
    normalized["segmentation"] = normalized_segmentation

    if inferred_num_classes is not None:
        normalized["num_classes"] = inferred_num_classes
    if color_map is not None:
        normalized["colors"] = color_map

    if config_name is not None:
        normalized["config_name"] = str(config_name)
    if config_path is not None:
        normalized["config_path"] = str(config_path)

    return normalized


def load_model_params(selection=None):
    config_name, config_path = resolve_model_config_path(selection)
    with config_path.open("r", encoding="utf-8") as stream:
        model_params = yaml.safe_load(stream) or {}
    return normalize_model_params(model_params, config_name=config_name, config_path=config_path)
