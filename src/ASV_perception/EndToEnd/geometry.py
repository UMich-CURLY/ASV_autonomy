from dataclasses import dataclass

import numpy as np
from rclpy.duration import Duration
from rclpy.time import Time
from sensor_msgs.msg import CameraInfo
from tf2_ros import Buffer, TransformException, TransformListener
from transform_math import quaternion_matrix


class GeometryError(RuntimeError):
    """Raised when the LiDAR/image projection inputs are incomplete or invalid."""


@dataclass
class ProjectionResult:
    pixels: np.ndarray
    depths: np.ndarray
    valid_indices: np.ndarray


class LidarCameraProjector:
    """Owns the camera model, TF lookup, and LiDAR-to-image projection."""

    def __init__(self, node, tf_timeout_sec=0.2):
        self._node = node
        self._tf_timeout = Duration(seconds=float(tf_timeout_sec))
        self._tf_buffer = Buffer(cache_time=Duration(seconds=10.0))
        self._tf_listener = TransformListener(self._tf_buffer, node, spin_thread=True)

        self._camera_info = None
        self._camera_matrix = None
        self._camera_frame = ""
        self._image_width = 0
        self._image_height = 0

    @property
    def camera_frame(self):
        return self._camera_frame

    def update_camera_info(self, camera_info: CameraInfo):
        self._camera_info = camera_info
        self._camera_frame = camera_info.header.frame_id
        self._image_width = int(camera_info.width)
        self._image_height = int(camera_info.height)

        k = np.asarray(camera_info.k, dtype=np.float64).reshape(3, 3)
        if np.count_nonzero(k) == 0:
            p = np.asarray(camera_info.p, dtype=np.float64).reshape(3, 4)
            k = p[:, :3]

        if np.count_nonzero(k) == 0:
            raise GeometryError("CameraInfo did not provide a valid projection matrix.")

        self._camera_matrix = k

    def ready(self):
        return self._camera_matrix is not None and bool(self._camera_frame)

    def project_points(self, points_lidar, source_frame, target_frame=None):
        if points_lidar.size == 0:
            return ProjectionResult(
                pixels=np.empty((0, 2), dtype=np.int32),
                depths=np.empty((0,), dtype=np.float32),
                valid_indices=np.empty((0,), dtype=np.int64),
            )

        if not self.ready():
            raise GeometryError("CameraInfo has not been received yet.")

        if not source_frame:
            raise GeometryError("PointCloud2 message is missing frame_id.")

        target_frame = target_frame or self._camera_frame
        if not target_frame:
            raise GeometryError("Camera optical frame is unknown.")

        try:
            transform = self._tf_buffer.lookup_transform(
                target_frame,
                source_frame,
                Time(),
                timeout=self._tf_timeout,
            )
        except TransformException as exc:
            raise GeometryError(
                f"TF lookup failed from {source_frame} to {target_frame}: {exc}"
            ) from exc

        transform_matrix = self._transform_to_matrix(transform)
        points_lidar_h = np.hstack(
            (points_lidar.astype(np.float64), np.ones((points_lidar.shape[0], 1), dtype=np.float64))
        )
        points_camera = (transform_matrix @ points_lidar_h.T).T[:, :3]

        valid_depth = points_camera[:, 2] > 0.0
        if not np.any(valid_depth):
            return ProjectionResult(
                pixels=np.empty((0, 2), dtype=np.int32),
                depths=np.empty((0,), dtype=np.float32),
                valid_indices=np.empty((0,), dtype=np.int64),
            )

        points_camera = points_camera[valid_depth]
        pixels = (self._camera_matrix @ points_camera.T).T
        pixels = pixels[:, :2] / points_camera[:, 2:3]

        valid_fov = (
            (pixels[:, 0] >= 0.0)
            & (pixels[:, 0] < self._image_width)
            & (pixels[:, 1] >= 0.0)
            & (pixels[:, 1] < self._image_height)
        )

        valid_indices = np.where(valid_depth)[0][valid_fov]

        return ProjectionResult(
            pixels=pixels[valid_fov].astype(np.int32),
            depths=points_camera[valid_fov, 2].astype(np.float32),
            valid_indices=valid_indices,
        )

    @staticmethod
    def _transform_to_matrix(transform_stamped):
        quat = transform_stamped.transform.rotation
        trans = transform_stamped.transform.translation

        matrix = quaternion_matrix([quat.x, quat.y, quat.z, quat.w])
        matrix[0, 3] = trans.x
        matrix[1, 3] = trans.y
        matrix[2, 3] = trans.z
        return matrix
