import torch
import torch.nn.functional as F
import time

# BKINet consists of three components:
# 1) Semantic segmentation model
# 2) ConvBKI layer
# 3) Propagation method
# This module is intended for ROS integration


def remap_seg(seg):
    labels_dict = {
        1: [12], # Building
        2: [13], # Barrier
        3: [], # Other
        4: [5, 6, 7], # Pedestrian
        5: [17, 18], # Pole
        6: [8, 9], # Road
        7: [11, 16], # Ground
        8: [10],# Sidewalk
        9: [14, 15], # Vegetation
        10: [0, 1, 2, 3, 4] # Vehicle
    }
    new_labels = torch.zeros_like(seg)[:, :11]
    for i in labels_dict.keys():
        if len(labels_dict[i]) == 0:
            continue
        temp_tensor = torch.vstack([seg[:, i] for i in labels_dict[i]])
        temp_tensor = torch.sum(temp_tensor, dim=0)
        new_labels[:, i] = temp_tensor
    return new_labels


class BKINet(torch.nn.Module):
    def __init__(self, segmentation_net, convbki_net, propagation_net, grid_size,
                 device="cpu", datatype=torch.float32, num_classes=20, prior=1e-6):
        super().__init__()
        self.segmentation_net = segmentation_net
        self.convbki_net = convbki_net
        self.propagation_net = propagation_net

        self.grid_size = grid_size
        self.num_classes = num_classes
        self.dtype = datatype
        self.device = device
        self.prior = prior

        self.ego_to_map = torch.eye(4).to(device)
        self.grid = self.initialize_grid()
        self.last_stage_timings_ms = {}

        # KITTI
        if self.num_classes == 11:
            self.remap = True
        else:
            self.remap = False

    def _stage_timestamp(self, enable_timing=False):
        if enable_timing and torch.cuda.is_available() and str(self.device).startswith("cuda"):
            torch.cuda.synchronize()
        return time.perf_counter()

    def initialize_grid(self):
        self.propagation_net.reset()
        return torch.zeros(self.grid_size[0], self.grid_size[1], self.grid_size[2],
                           self.num_classes, device=self.device, requires_grad=True,
                           dtype=self.dtype) + self.prior

    def forward(self, input_data):
        '''
        Input:
        List of input for [propagation, segmentation]
        '''
        new_pose, lidar, point_labels, _ = input_data
        enable_timing = bool(getattr(self, "measure_timings", False))
        stage_start = self._stage_timestamp(enable_timing)

        # Propagate
        self.ego_to_map, self.grid = self.propagation_net(new_pose, self.grid)
        propagation_ms = (self._stage_timestamp(enable_timing) - stage_start) * 1000.0

        stage_start = self._stage_timestamp(enable_timing)
        transformed_lidar = torch.matmul(self.ego_to_map[:3, :3], lidar[:, :3].T).T + self.ego_to_map[:3, 3]
        lidar_transform_ms = (self._stage_timestamp(enable_timing) - stage_start) * 1000.0

        # Update
        stage_start = self._stage_timestamp(enable_timing)
        point_labels = torch.tensor(point_labels, dtype=torch.float32, device=self.device)  # Convert NumPy array to tensor
        label_tensor_ms = (self._stage_timestamp(enable_timing) - stage_start) * 1000.0

        # if self.remap:
        #     point_labels = remap_seg(point_labels)
        #     dists = torch.linalg.norm(lidar, axis=1)
        #     transformed_lidar = transformed_lidar[dists > 3.0, :]
        #     point_labels = point_labels[dists > 3.0, :]
        #     print("point_labels.shape: ", point_labels.shape)
        stage_start = self._stage_timestamp(enable_timing)
        segmented_points = torch.concat((transformed_lidar[:, :3], point_labels), dim=1)
        self.grid = self.convbki_net(self.grid, segmented_points)
        bki_update_ms = (self._stage_timestamp(enable_timing) - stage_start) * 1000.0

        self.last_stage_timings_ms = {
            "propagation_ms": propagation_ms,
            "lidar_transform_ms": lidar_transform_ms,
            "label_tensor_ms": label_tensor_ms,
            "bki_update_ms": bki_update_ms,
            "visible_points": int(lidar.shape[0]),
            "segmented_points": int(segmented_points.shape[0]),
        }
