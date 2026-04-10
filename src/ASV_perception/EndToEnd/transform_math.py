import math

import numpy as np


_EPS = np.finfo(float).eps * 4.0


def quaternion_matrix(quaternion):
    """Return a homogeneous rotation matrix from an ``[x, y, z, w]`` quaternion."""
    q = np.array(quaternion[:4], dtype=np.float64, copy=True)
    nq = np.dot(q, q)
    if nq < _EPS:
        return np.identity(4, dtype=np.float64)
    q *= math.sqrt(2.0 / nq)
    q = np.outer(q, q)
    return np.array(
        (
            (1.0 - q[1, 1] - q[2, 2], q[0, 1] - q[2, 3], q[0, 2] + q[1, 3], 0.0),
            (q[0, 1] + q[2, 3], 1.0 - q[0, 0] - q[2, 2], q[1, 2] - q[0, 3], 0.0),
            (q[0, 2] - q[1, 3], q[1, 2] + q[0, 3], 1.0 - q[0, 0] - q[1, 1], 0.0),
            (0.0, 0.0, 0.0, 1.0),
        ),
        dtype=np.float64,
    )


def quaternion_from_euler(roll, pitch, yaw):
    """Return an ``[x, y, z, w]`` quaternion from roll, pitch, yaw."""
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)

    return np.array(
        [
            sr * cp * cy - cr * sp * sy,
            cr * sp * cy + sr * cp * sy,
            cr * cp * sy - sr * sp * cy,
            cr * cp * cy + sr * sp * sy,
        ],
        dtype=np.float64,
    )


def quaternion_from_matrix(matrix):
    """Return an ``[x, y, z, w]`` quaternion from a rotation matrix."""
    M = np.array(matrix, dtype=np.float64, copy=False)[:4, :4]
    q = np.empty((4,), dtype=np.float64)
    t = np.trace(M[:3, :3])

    if t > M[3, 3]:
        q[3] = t
        q[2] = M[1, 0] - M[0, 1]
        q[1] = M[0, 2] - M[2, 0]
        q[0] = M[2, 1] - M[1, 2]
    else:
        i = 0
        if M[1, 1] > M[0, 0]:
            i = 1
        if M[2, 2] > M[i, i]:
            i = 2
        j = (i + 1) % 3
        k = (j + 1) % 3
        t = M[i, i] - M[j, j] - M[k, k] + M[3, 3]
        q[i] = t
        q[j] = M[j, i] + M[i, j]
        q[k] = M[k, i] + M[i, k]
        q[3] = M[k, j] - M[j, k]

    q *= 0.5 / math.sqrt(max(M[3, 3] * t, _EPS))
    return q
