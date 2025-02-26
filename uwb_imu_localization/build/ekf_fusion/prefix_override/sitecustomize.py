import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/asv/asv_autonomy/uwb_imu_localization/install/ekf_fusion'
