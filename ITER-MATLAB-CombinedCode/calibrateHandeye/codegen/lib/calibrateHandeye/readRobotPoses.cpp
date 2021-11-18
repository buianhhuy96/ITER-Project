//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readRobotPoses.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "readRobotPoses.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const coder::array<double, 3U> &robot_poses_vec
//                const coder::array<bool, 1U> &valid_idx
//                coder::array<double, 3U> &poses
//                coder::array<double, 3U> &extrinsics
// Return Type  : void
//
void readRobotPoses(const coder::array<double, 3U> &robot_poses_vec,
                    const coder::array<bool, 1U> &valid_idx,
                    coder::array<double, 3U> &poses,
                    coder::array<double, 3U> &extrinsics)
{
  static const signed char iv[4]{0, 0, 0, 1};
  coder::array<double, 3U> c_poses;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  double b_poses[3][3];
  int b_i;
  int c_i;
  int end;
  int i1;
  int loop_ub;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  poses.set_size(4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        poses[(i1 + (4 * b_i)) + (16 * end)] = 0.0;
      }
    }
  }
  extrinsics.set_size(4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        extrinsics[(i1 + (4 * b_i)) + (16 * end)] = 0.0;
      }
    }
  }
  // read valid poses and reshape them to 4x4xn matrix
  end = robot_poses_vec.size(2);
  for (c_i = 0; c_i < end; c_i++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        poses[(i1 + (4 * b_i)) + (16 * c_i)] =
            robot_poses_vec[(i1 + (4 * b_i)) + (16 * c_i)];
      }
    }
    for (b_i = 0; b_i < 3; b_i++) {
      b_poses[b_i][0] = -poses[b_i + (16 * c_i)];
      b_poses[b_i][1] = -poses[(b_i + (16 * c_i)) + 4];
      b_poses[b_i][2] = -poses[(b_i + (16 * c_i)) + 8];
    }
    for (b_i = 0; b_i < 3; b_i++) {
      extrinsics[(4 * b_i) + (16 * c_i)] = poses[b_i + (16 * c_i)];
      extrinsics[((4 * b_i) + (16 * c_i)) + 1] = poses[(b_i + (16 * c_i)) + 4];
      extrinsics[((4 * b_i) + (16 * c_i)) + 2] = poses[(b_i + (16 * c_i)) + 8];
      extrinsics[(b_i + (16 * c_i)) + 12] =
          ((b_poses[0][b_i] * poses[(16 * c_i) + 12]) +
           (b_poses[1][b_i] * poses[(16 * c_i) + 13])) +
          (b_poses[2][b_i] * poses[(16 * c_i) + 14]);
    }
    for (b_i = 0; b_i < 4; b_i++) {
      extrinsics[((4 * b_i) + (16 * c_i)) + 3] = static_cast<double>(iv[b_i]);
    }
  }
  //  keep valid poses that have corresponding image with detected feature
  //  points
  end = valid_idx.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if (valid_idx[c_i]) {
      loop_ub++;
    }
  }
  r.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if (valid_idx[c_i]) {
      r[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  c_poses.set_size(4, 4, r.size(0));
  loop_ub = r.size(0);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        c_poses[(i1 + (4 * b_i)) + (16 * end)] =
            poses[(i1 + (4 * b_i)) + (16 * (r[end] - 1))];
      }
    }
  }
  poses.set_size(4, 4, c_poses.size(2));
  loop_ub = c_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        poses[(i1 + (4 * b_i)) + (16 * end)] =
            c_poses[(i1 + (4 * b_i)) + (16 * end)];
      }
    }
  }
  end = valid_idx.size(0) - 1;
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if (valid_idx[c_i]) {
      loop_ub++;
    }
  }
  r1.set_size(loop_ub);
  loop_ub = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    if (valid_idx[c_i]) {
      r1[loop_ub] = c_i + 1;
      loop_ub++;
    }
  }
  c_poses.set_size(4, 4, r1.size(0));
  loop_ub = r1.size(0);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        c_poses[(i1 + (4 * b_i)) + (16 * end)] =
            extrinsics[(i1 + (4 * b_i)) + (16 * (r1[end] - 1))];
      }
    }
  }
  extrinsics.set_size(4, 4, c_poses.size(2));
  loop_ub = c_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (b_i = 0; b_i < 4; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        extrinsics[(i1 + (4 * b_i)) + (16 * end)] =
            c_poses[(i1 + (4 * b_i)) + (16 * end)];
      }
    }
  }
}

//
// File trailer for readRobotPoses.cpp
//
// [EOF]
//
