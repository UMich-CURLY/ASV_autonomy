#!/usr/bin/env python3

"""
Creates a global occupancy grid from semantic point clouds or operates in 
free-space mode for testing. The grid origin is fixed at the boat's starting 
position to provide a consistent global reference frame.

Features:
- Fixed global coordinate system (doesn't follow the boat)
- Chunked map expansion from incoming observations
- Semantic point cloud processing with color-based obstacle detection
- Free-space mode for testing without perception data
"""
import os
import yaml
import pathlib
import numpy as np
import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from sensor_msgs.msg import PointCloud2
from sensor_msgs_py import point_cloud2
from geometry_msgs.msg import PoseStamped
from tf2_ros import Buffer, TransformListener
import tf_transformations as tft

# File paths for persistent storage
SAVE_DIR = pathlib.Path.home() / ".ros"
GRID_FILE = SAVE_DIR / "ogm.npy"
META_FILE = SAVE_DIR / "ogm_meta.json"

class OccupancyGridBuilder(Node):
    def __init__(self):
        super().__init__('occupancy_grid_builder')

        pkg_path = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '..', '..'))
        config_path = os.path.join(pkg_path, 'configs', 'params.yaml')
        
        # Load model parameters
        with open(config_path, "r") as stream:
            try:
                self.configs = yaml.safe_load(stream)
            except yaml.YAMLError as exc:
                print(exc)

        self.ros_topic = self.configs["ros_parameters"]
        self.ogm_params = self.configs["OGM_builder"]
        self.rviz_colors = self.configs["rviz_colors"]
        self.global_frame = self.ros_topic.get("global_frame", "map")

        self._setup_parameters()
        self._setup_tf()
        self._setup_ros_communication()
        self._initialize_state()
        self._configure_free_space_mode()

    def _setup_parameters(self):
        """Initialize all OGM parameters with defaults."""
        self.resolution = self.ogm_params["grid_resolution"]
        self.grid_width = self.ogm_params["grid_width"]
        self.grid_height = self.ogm_params["grid_height"]
        self.free_space_mode = self.ogm_params["no_perception"]
        self.free_space_ids = self._id_set(self.ogm_params.get("free_space_id", []))
        self.unknown_ids = self._id_set(self.ogm_params.get("unknown_id", []))
        self.map_expansion_margin = float(self.ogm_params.get("map_expansion_margin", 0.0))
        self.map_expansion_chunk_size = float(self.ogm_params.get("map_expansion_chunk_size", 0.0))
        self.map_expansion_chunk_cells = int(np.ceil(self.map_expansion_chunk_size / self.resolution))
        self.free_space_inflation_radius = float(self.ogm_params.get("free_space_inflation_radius", 0.0))
        self.free_space_inflation_cells = int(np.ceil(self.free_space_inflation_radius / self.resolution))
        self.obstacle_inflation_radius = float(self.ogm_params.get("obstacle_inflation_radius", 0.0))
        self.obstacle_inflation_cells = int(np.ceil(self.obstacle_inflation_radius / self.resolution))
        self.map_plane_z_mode = str(self.ogm_params.get("map_plane_z_mode", "initial_pose"))
        self.map_plane_z_fixed = float(self.ogm_params.get("map_plane_z", 0.0))
        self.align_origin_to_convbki_lattice = bool(
            self.ogm_params.get("align_origin_to_convbki_lattice", True))
        self.cell_centered_observations = bool(
            self.ogm_params.get("cell_centered_observations", True))

        convbki_params = self.configs.get("ConvBKI", {})
        convbki_min_bound = convbki_params.get("min_bound", [0.0, 0.0, 0.0])
        convbki_voxel_sizes = convbki_params.get(
            "voxel_sizes", [self.resolution, self.resolution, self.resolution])
        self.convbki_lattice_origin_x = float(convbki_min_bound[0])
        self.convbki_lattice_origin_y = float(convbki_min_bound[1])

        for axis, voxel_size in zip(("x", "y"), convbki_voxel_sizes[:2]):
            if abs(float(voxel_size) - self.resolution) > 1e-6:
                self.get_logger().warning(
                    f"OGM resolution ({self.resolution:.3f}) differs from ConvBKI {axis} "
                    f"voxel size ({float(voxel_size):.3f}); cell-center alignment assumes they match.")

    @staticmethod
    def _id_set(value):
        """Normalize scalar/list YAML class IDs into a set of ints."""
        if isinstance(value, (list, tuple, set)):
            return {int(v) for v in value}
        return {int(value)}

    def _setup_tf(self):
        """Initialize transform buffer and listener."""
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

    def _setup_ros_communication(self):
        """Setup publishers and subscribers."""

        self.create_subscription(PoseStamped, self.ros_topic["pose_topic"], self._pose_callback, 10)
        self.create_subscription(PointCloud2, self.ros_topic["global_pcd_topic"], self._pointcloud_callback, 10)
        self.grid_publisher = self.create_publisher(OccupancyGrid, self.ros_topic["ogm_topic"], 10)
        self.create_timer(0.2, self._publish_grid)

    def _initialize_state(self):
        """Initialize internal state variables."""
        self.origin_x = None
        self.origin_y = None
        self.occupancy_grid = np.full((self.grid_height, self.grid_width), -1, dtype=np.int8)
        self.current_pose = None
        self.origin_initialized = False
        self.origin_z = self.map_plane_z_fixed


    # no perception mode
    def _configure_free_space_mode(self):       
        """Configure settings for free-space testing mode."""
        if self.free_space_mode:
            # Create a 100m x 100m map for testing
            map_size_meters = 100
            self.grid_width = int(map_size_meters / self.resolution)
            self.grid_height = int(map_size_meters / self.resolution)
            self.occupancy_grid = np.zeros((self.grid_height, self.grid_width), dtype=np.int8)
            
            self.get_logger().info(
                f"Free-space mode: Creating {map_size_meters}m x {map_size_meters}m global map")

    def _pose_callback(self, msg: PoseStamped):
        """Handle incoming pose messages and initialize map origin if needed."""
        self.current_pose = msg
        
        if not self.origin_initialized:
            self._initialize_map_origin(msg)

    def _initialize_map_origin(self, pose_msg: PoseStamped):
        """Set the map origin based on the boat's starting position."""
        if pose_msg.header.frame_id and pose_msg.header.frame_id != self.global_frame:
            self.get_logger().warning(
                f"Pose frame '{pose_msg.header.frame_id}' does not match OGM frame "
                f"'{self.global_frame}'. Using pose coordinates as-is.")

        boat_x = pose_msg.pose.position.x
        boat_y = pose_msg.pose.position.y
        boat_z = pose_msg.pose.position.z
        
        # Center the map around the starting position, then snap the grid corners
        # to the ConvBKI voxel-boundary lattice so OGM cell centers coincide with
        # ConvBKI cube centers.
        raw_origin_x = boat_x - 0.5 * self.grid_width * self.resolution
        raw_origin_y = boat_y - 0.5 * self.grid_height * self.resolution
        self.origin_x, self.origin_y = self._align_map_origin(raw_origin_x, raw_origin_y)
        if self.map_plane_z_mode == "initial_pose":
            self.origin_z = boat_z
        elif self.map_plane_z_mode == "fixed":
            self.origin_z = self.map_plane_z_fixed
        else:
            self.get_logger().warning(
                f"Unknown map_plane_z_mode '{self.map_plane_z_mode}', using initial_pose.")
            self.map_plane_z_mode = "initial_pose"
            self.origin_z = boat_z
        self.origin_initialized = True

        # Log the map configuration
        map_size_x = self.grid_width * self.resolution
        map_size_y = self.grid_height * self.resolution
        
        self.get_logger().info(
            f"Map origin set at ({self.origin_x:.2f}, {self.origin_y:.2f}, {self.origin_z:.2f})")
        self.get_logger().info(
            f"Map coverage: X[{self.origin_x:.1f} to {self.origin_x + map_size_x:.1f}], "
            f"Y[{self.origin_y:.1f} to {self.origin_y + map_size_y:.1f}]")

    def _align_map_origin(self, origin_x, origin_y):
        """Align OccupancyGrid cell centers with ConvBKI voxel centers."""
        if not self.align_origin_to_convbki_lattice:
            return origin_x, origin_y

        aligned_x = self._snap_to_lattice(origin_x, self.convbki_lattice_origin_x)
        aligned_y = self._snap_to_lattice(origin_y, self.convbki_lattice_origin_y)

        if abs(aligned_x - origin_x) > 1e-6 or abs(aligned_y - origin_y) > 1e-6:
            self.get_logger().info(
                f"Aligned OGM origin to ConvBKI cell lattice: "
                f"({origin_x:.2f}, {origin_y:.2f}) -> ({aligned_x:.2f}, {aligned_y:.2f})")

        return aligned_x, aligned_y

    def _snap_to_lattice(self, value, lattice_origin):
        """Return the nearest value on lattice_origin + N * resolution."""
        return float(
            lattice_origin
            + np.round((value - lattice_origin) / self.resolution) * self.resolution)

    def _map_plane_z(self):
        """Return the visualization plane for this 2D grid."""
        if self.map_plane_z_mode == "current_pose" and self.current_pose is not None:
            return self.current_pose.pose.position.z
        return self.origin_z

    def _pointcloud_callback(self, msg: PointCloud2):
        """Process incoming point cloud data to update the occupancy grid."""
        # Skip point cloud processing in free-space mode
        if self.free_space_mode:
            return
            
        # Wait for map origin to be initialized
        if not self.origin_initialized:
            return

        # Parse point cloud data
        points, labels = self._parse_pointcloud(msg)
        if points is None:
            return
            
        # Transform points to map frame if necessary
        points = self._transform_to_map_frame(points, msg)
        if points is None:
            return
            
        # Update occupancy grid with new observations
        self._update_occupancy_grid(points, labels)

    def _parse_pointcloud(self, msg: PointCloud2):
        """Extract XYZ coordinates and semantic labels from point cloud."""
        try:
            point_array = point_cloud2.read_points_numpy(
                msg, field_names=("x", "y", "z", "rgb"), skip_nans=True)
        except Exception as exc:
            self.get_logger().warning(f"Invalid point cloud format: {exc}")
            return None, None

        if point_array.size == 0:
            return None, None

        point_array = np.asarray(point_array, dtype=np.float32)
        if point_array.ndim == 1:
            point_array = point_array.reshape(1, -1)

        xyz_points = point_array[:, :3]
        rgb_values = point_array[:, 3].view(np.uint32)
        
        # Convert RGB to semantic labels
        labels = self._rgb_to_semantic_labels(rgb_values)
        
        # Filter out unknown labels
        valid_mask = labels != -1
        return xyz_points[valid_mask], labels[valid_mask]

    def _rgb_to_semantic_labels(self, rgb_values):
        """Convert RGB color values to semantic labels."""
        # Extract RGB components
        red = (rgb_values >> 16) & 0xFF
        green = (rgb_values >> 8) & 0xFF
        blue = rgb_values & 0xFF
        colors = np.stack([red, green, blue], axis=1)
        
        color_map = {}

        for class_id, rgb in self.rviz_colors.items():
            rgb_tuple = tuple(rgb)
            class_id = int(class_id)

            if class_id in self.free_space_ids:  # water
                color_map[rgb_tuple] = 0
            elif class_id in self.unknown_ids:   # background
                color_map[rgb_tuple] = -1  # keep as -1
            else:
                color_map[rgb_tuple] = 100
        labels = np.full(colors.shape[0], -1, dtype=np.int8)
        
        # Assign labels based on color matching
        for color, label in color_map.items():
            color_match = np.all(colors == color, axis=1)
            labels[color_match] = label
            
        return labels

    def _transform_to_map_frame(self, points, msg):
        """Transform points to map coordinate frame if needed."""
        if msg.header.frame_id == self.global_frame:
            return points

        try:
            # Look up transform from point cloud frame to map frame
            transform = self.tf_buffer.lookup_transform(
                self.global_frame, msg.header.frame_id, msg.header.stamp,
                timeout=rclpy.duration.Duration(seconds=0.2))
                
        except Exception as e:
            self.get_logger().warning(f"Transform lookup failed: {e}")
            return None
            
        # Apply transformation
        rotation_matrix = tft.quaternion_matrix([
            transform.transform.rotation.x,
            transform.transform.rotation.y,
            transform.transform.rotation.z,
            transform.transform.rotation.w])[:3, :3]
            
        translation = np.array([
            transform.transform.translation.x,
            transform.transform.translation.y,
            transform.transform.translation.z])
            
        transformed_points = (rotation_matrix @ points.T).T + translation
        return transformed_points

    def _update_occupancy_grid(self, points, labels):
        """Update the occupancy grid with new point observations."""
        self._expand_grid_to_include(points)

        # Convert global-frame coordinates to grid indices.
        grid_x, grid_y = self._points_to_grid_indices(points)
        
        # Filter points that fall within the grid bounds
        valid_points = ((grid_x >= 0) & (grid_x < self.grid_width) & 
                       (grid_y >= 0) & (grid_y < self.grid_height))
        
        grid_x = grid_x[valid_points]
        grid_y = grid_y[valid_points]
        labels = labels[valid_points]
        
        # Free observations only clear unknown/free cells; occupied observations win.
        free_mask = labels == 0
        if np.any(free_mask):
            self._mark_free_space(grid_x[free_mask], grid_y[free_mask])

        obstacle_mask = labels == 100
        if np.any(obstacle_mask):
            self._mark_obstacles(grid_x[obstacle_mask], grid_y[obstacle_mask])

    def _points_to_grid_indices(self, points):
        """Map ConvBKI center samples to the matching OGM cell indices."""
        if self.cell_centered_observations:
            half_cell = 0.5 * self.resolution
            grid_x = np.rint(
                (points[:, 0] - self.origin_x - half_cell) / self.resolution).astype(int)
            grid_y = np.rint(
                (points[:, 1] - self.origin_y - half_cell) / self.resolution).astype(int)
            return grid_x, grid_y

        grid_x = np.floor((points[:, 0] - self.origin_x) / self.resolution).astype(int)
        grid_y = np.floor((points[:, 1] - self.origin_y) / self.resolution).astype(int)
        return grid_x, grid_y

    def _expand_grid_to_include(self, points):
        """Grow the fixed-frame grid in chunks to include incoming observations."""
        if self.map_expansion_chunk_cells <= 0 or points.size == 0:
            return

        footprint = max(self.free_space_inflation_radius, self.obstacle_inflation_radius)
        padding = footprint + self.map_expansion_margin

        required_min_x = float(np.min(points[:, 0]) - padding)
        required_max_x = float(np.max(points[:, 0]) + padding)
        required_min_y = float(np.min(points[:, 1]) - padding)
        required_max_y = float(np.max(points[:, 1]) + padding)

        current_max_x = self.origin_x + self.grid_width * self.resolution
        current_max_y = self.origin_y + self.grid_height * self.resolution

        left = self._chunked_cells(self.origin_x - required_min_x)
        right = self._chunked_cells(required_max_x - current_max_x)
        bottom = self._chunked_cells(self.origin_y - required_min_y)
        top = self._chunked_cells(required_max_y - current_max_y)

        if left == 0 and right == 0 and bottom == 0 and top == 0:
            return

        old_grid = self.occupancy_grid
        old_height, old_width = old_grid.shape
        new_height = old_height + bottom + top
        new_width = old_width + left + right

        expanded_grid = np.full((new_height, new_width), -1, dtype=np.int8)
        expanded_grid[bottom:bottom + old_height, left:left + old_width] = old_grid

        self.occupancy_grid = expanded_grid
        self.grid_width = new_width
        self.grid_height = new_height
        self.origin_x -= left * self.resolution
        self.origin_y -= bottom * self.resolution

        self.get_logger().info(
            f"Expanded OGM to {self.grid_width}x{self.grid_height} cells "
            f"origin=({self.origin_x:.2f}, {self.origin_y:.2f})")

    def _chunked_cells(self, meters_needed):
        """Round positive meters up to a whole expansion chunk in cells."""
        if meters_needed <= 0.0:
            return 0

        needed_cells = int(np.ceil(meters_needed / self.resolution))
        chunks = int(np.ceil(needed_cells / self.map_expansion_chunk_cells))
        return chunks * self.map_expansion_chunk_cells

    def _mark_obstacles(self, grid_x, grid_y):
        """Mark occupied cells, inflating ConvBKI voxel centers into OGM cells."""
        self._mark_cells(
            grid_x, grid_y,
            self.obstacle_inflation_cells,
            self.obstacle_inflation_radius,
            value=100,
            preserve_obstacles=False)

    def _mark_free_space(self, grid_x, grid_y):
        """Mark free cells while preserving any existing occupied cells."""
        self._mark_cells(
            grid_x, grid_y,
            self.free_space_inflation_cells,
            self.free_space_inflation_radius,
            value=0,
            preserve_obstacles=True)

    def _mark_cells(self, grid_x, grid_y, inflation_cells, inflation_radius,
                    value, preserve_obstacles):
        """Mark cells in a circular footprint around each observed grid cell."""
        if grid_x.size == 0:
            return

        cells = np.unique(np.column_stack((grid_x, grid_y)), axis=0)
        grid_x = cells[:, 0]
        grid_y = cells[:, 1]

        if inflation_cells <= 0:
            self._set_cells(grid_x, grid_y, value, preserve_obstacles)
            return

        for dy in range(-inflation_cells, inflation_cells + 1):
            for dx in range(-inflation_cells, inflation_cells + 1):
                if np.hypot(dx, dy) * self.resolution > inflation_radius:
                    continue

                inflated_x = grid_x + dx
                inflated_y = grid_y + dy
                valid = ((inflated_x >= 0) & (inflated_x < self.grid_width) &
                         (inflated_y >= 0) & (inflated_y < self.grid_height))
                self._set_cells(inflated_x[valid], inflated_y[valid], value, preserve_obstacles)

    def _set_cells(self, grid_x, grid_y, value, preserve_obstacles):
        """Set grid cells, optionally keeping occupied cells unchanged."""
        if not preserve_obstacles:
            self.occupancy_grid[grid_y, grid_x] = value
            return

        not_occupied = self.occupancy_grid[grid_y, grid_x] != 100
        self.occupancy_grid[grid_y[not_occupied], grid_x[not_occupied]] = value

    def _publish_grid(self):
        """Publish the current occupancy grid."""
        if not self.origin_initialized:
            return
            
        # Create and populate OccupancyGrid message
        grid_msg = OccupancyGrid()
        grid_msg.header.stamp = self.get_clock().now().to_msg()
        grid_msg.header.frame_id = self.global_frame
        
        # Set grid metadata
        grid_msg.info.resolution = self.resolution
        grid_msg.info.width = self.grid_width
        grid_msg.info.height = self.grid_height
        grid_msg.info.origin.position.x = self.origin_x
        grid_msg.info.origin.position.y = self.origin_y
        grid_msg.info.origin.position.z = float(self._map_plane_z())
        grid_msg.info.origin.orientation.w = 1.0
        
        # Flatten grid data for message
        grid_msg.data = self.occupancy_grid.flatten().tolist()
        
        self.grid_publisher.publish(grid_msg)

def main(args=None):
    """Main entry point for the occupancy grid builder node."""
    rclpy.init(args=args)
    
    try:
        node = OccupancyGridBuilder()
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
