//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readRobotPoses.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
//                const coder::array<bool, 2U> &valid_idx
//                coder::array<double, 3U> &poses
//                coder::array<double, 3U> &extrinsics
// Return Type  : void
//
void readRobotPoses(const coder::array<double, 3U> &robot_poses_vec,
                    const coder::array<bool, 2U> &valid_idx,
                    coder::array<double, 3U> &poses,
                    coder::array<double, 3U> &extrinsics)
{
  coder::array<double, 3U> c_poses;
  coder::array<int, 2U> r;
  coder::array<int, 2U> r1;
  double b_poses[3][3];
  int b_i;
  int end;
  int i;
  int loop_ub;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  poses.set_size(4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      poses[(4 * i) + (16 * end)] = 0.0;
      poses[((4 * i) + (16 * end)) + 1] = 0.0;
      poses[((4 * i) + (16 * end)) + 2] = 0.0;
      poses[((4 * i) + (16 * end)) + 3] = 0.0;
    }
  }
  extrinsics.set_size(4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      extrinsics[(4 * i) + (16 * end)] = 0.0;
      extrinsics[((4 * i) + (16 * end)) + 1] = 0.0;
      extrinsics[((4 * i) + (16 * end)) + 2] = 0.0;
      extrinsics[((4 * i) + (16 * end)) + 3] = 0.0;
    }
  }
  // read valid poses and reshape them to 4x4xn matrix
  end = robot_poses_vec.size(2);
  for (b_i = 0; b_i < end; b_i++) {
    for (i = 0; i < 4; i++) {
      poses[(4 * i) + (16 * b_i)] = robot_poses_vec[(4 * i) + (16 * b_i)];
      poses[((4 * i) + (16 * b_i)) + 1] =
          robot_poses_vec[((4 * i) + (16 * b_i)) + 1];
      poses[((4 * i) + (16 * b_i)) + 2] =
          robot_poses_vec[((4 * i) + (16 * b_i)) + 2];
      poses[((4 * i) + (16 * b_i)) + 3] =
          robot_poses_vec[((4 * i) + (16 * b_i)) + 3];
    }
    for (i = 0; i < 3; i++) {
      b_poses[i][0] = -poses[i + (16 * b_i)];
      b_poses[i][1] = -poses[(i + (16 * b_i)) + 4];
      b_poses[i][2] = -poses[(i + (16 * b_i)) + 8];
    }
    for (i = 0; i < 3; i++) {
      extrinsics[(4 * i) + (16 * b_i)] = poses[i + (16 * b_i)];
      extrinsics[((4 * i) + (16 * b_i)) + 1] = poses[(i + (16 * b_i)) + 4];
      extrinsics[((4 * i) + (16 * b_i)) + 2] = poses[(i + (16 * b_i)) + 8];
      extrinsics[(i + (16 * b_i)) + 12] =
          ((b_poses[0][i] * poses[(16 * b_i) + 12]) +
           (b_poses[1][i] * poses[(16 * b_i) + 13])) +
          (b_poses[2][i] * poses[(16 * b_i) + 14]);
    }
    extrinsics[(16 * b_i) + 3] = 0.0;
    extrinsics[(16 * b_i) + 7] = 0.0;
    extrinsics[(16 * b_i) + 11] = 0.0;
    extrinsics[(16 * b_i) + 15] = 1.0;
  }
  //  keep valid poses that have corresponding image with detected feature
  //  points
  end = valid_idx.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (valid_idx[b_i]) {
      loop_ub++;
    }
  }
  r.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (valid_idx[b_i]) {
      r[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  c_poses.set_size(4, 4, r.size(1));
  loop_ub = r.size(1);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      c_poses[(4 * i) + (16 * end)] = poses[(4 * i) + (16 * (r[end] - 1))];
      c_poses[((4 * i) + (16 * end)) + 1] =
          poses[((4 * i) + (16 * (r[end] - 1))) + 1];
      c_poses[((4 * i) + (16 * end)) + 2] =
          poses[((4 * i) + (16 * (r[end] - 1))) + 2];
      c_poses[((4 * i) + (16 * end)) + 3] =
          poses[((4 * i) + (16 * (r[end] - 1))) + 3];
    }
  }
  poses.set_size(4, 4, c_poses.size(2));
  loop_ub = c_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      poses[(4 * i) + (16 * end)] = c_poses[(4 * i) + (16 * end)];
      poses[((4 * i) + (16 * end)) + 1] = c_poses[((4 * i) + (16 * end)) + 1];
      poses[((4 * i) + (16 * end)) + 2] = c_poses[((4 * i) + (16 * end)) + 2];
      poses[((4 * i) + (16 * end)) + 3] = c_poses[((4 * i) + (16 * end)) + 3];
    }
  }
  end = valid_idx.size(1) - 1;
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (valid_idx[b_i]) {
      loop_ub++;
    }
  }
  r1.set_size(1, loop_ub);
  loop_ub = 0;
  for (b_i = 0; b_i <= end; b_i++) {
    if (valid_idx[b_i]) {
      r1[loop_ub] = b_i + 1;
      loop_ub++;
    }
  }
  c_poses.set_size(4, 4, r1.size(1));
  loop_ub = r1.size(1);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      c_poses[(4 * i) + (16 * end)] =
          extrinsics[(4 * i) + (16 * (r1[end] - 1))];
      c_poses[((4 * i) + (16 * end)) + 1] =
          extrinsics[((4 * i) + (16 * (r1[end] - 1))) + 1];
      c_poses[((4 * i) + (16 * end)) + 2] =
          extrinsics[((4 * i) + (16 * (r1[end] - 1))) + 2];
      c_poses[((4 * i) + (16 * end)) + 3] =
          extrinsics[((4 * i) + (16 * (r1[end] - 1))) + 3];
    }
  }
  extrinsics.set_size(4, 4, c_poses.size(2));
  loop_ub = c_poses.size(2);
  for (end = 0; end < loop_ub; end++) {
    for (i = 0; i < 4; i++) {
      extrinsics[(4 * i) + (16 * end)] = c_poses[(4 * i) + (16 * end)];
      extrinsics[((4 * i) + (16 * end)) + 1] =
          c_poses[((4 * i) + (16 * end)) + 1];
      extrinsics[((4 * i) + (16 * end)) + 2] =
          c_poses[((4 * i) + (16 * end)) + 2];
      extrinsics[((4 * i) + (16 * end)) + 3] =
          c_poses[((4 * i) + (16 * end)) + 3];
    }
  }
}

//
// File trailer for readRobotPoses.cpp
//
// [EOF]
//
