//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readRobotPoses.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
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
  coder::array<double, 3U> b_extrinsics;
  coder::array<double, 3U> c_poses;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  double b_poses[3][3];
  int b_end;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int i5;
  int loop_ub;
  int partialTrueCount;
  int trueCount;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  poses.set_size(4, 4, robot_poses_vec.size(2));
  loop_ub = robot_poses_vec.size(2);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    for (int i1{0}; i1 < 4; i1++) {
      for (int i3{0}; i3 < 4; i3++) {
        poses[(i3 + (4 * i1)) + (16 * b_i)] = 0.0;
      }
    }
  }
  extrinsics.set_size(4, 4, robot_poses_vec.size(2));
  b_loop_ub = robot_poses_vec.size(2);
  for (int i2{0}; i2 < b_loop_ub; i2++) {
    for (int i4{0}; i4 < 4; i4++) {
      for (int i6{0}; i6 < 4; i6++) {
        extrinsics[(i6 + (4 * i4)) + (16 * i2)] = 0.0;
      }
    }
  }
  // read valid poses and reshape them to 4x4xn matrix
  i5 = robot_poses_vec.size(2);
  for (int c_i{0}; c_i < i5; c_i++) {
    for (int i7{0}; i7 < 4; i7++) {
      for (int i9{0}; i9 < 4; i9++) {
        poses[(i9 + (4 * i7)) + (16 * c_i)] =
            robot_poses_vec[(i9 + (4 * i7)) + (16 * c_i)];
      }
    }
    for (int i8{0}; i8 < 3; i8++) {
      b_poses[i8][0] = -poses[i8 + (16 * c_i)];
      b_poses[i8][1] = -poses[(i8 + (16 * c_i)) + 4];
      b_poses[i8][2] = -poses[(i8 + (16 * c_i)) + 8];
    }
    for (int i10{0}; i10 < 3; i10++) {
      extrinsics[(4 * i10) + (16 * c_i)] = poses[i10 + (16 * c_i)];
      extrinsics[((4 * i10) + (16 * c_i)) + 1] = poses[(i10 + (16 * c_i)) + 4];
      extrinsics[((4 * i10) + (16 * c_i)) + 2] = poses[(i10 + (16 * c_i)) + 8];
      extrinsics[(i10 + (16 * c_i)) + 12] =
          ((b_poses[0][i10] * poses[(16 * c_i) + 12]) +
           (b_poses[1][i10] * poses[(16 * c_i) + 13])) +
          (b_poses[2][i10] * poses[(16 * c_i) + 14]);
    }
    for (int i11{0}; i11 < 4; i11++) {
      extrinsics[((4 * i11) + (16 * c_i)) + 3] = static_cast<double>(iv[i11]);
    }
  }
  //  keep valid poses that have corresponding image with detected feature
  //  points
  end = valid_idx.size(0) - 1;
  trueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if (valid_idx[d_i]) {
      trueCount++;
    }
  }
  r.set_size(trueCount);
  partialTrueCount = 0;
  for (int e_i{0}; e_i <= end; e_i++) {
    if (valid_idx[e_i]) {
      r[partialTrueCount] = e_i + 1;
      partialTrueCount++;
    }
  }
  c_poses.set_size(4, 4, r.size(0));
  c_loop_ub = r.size(0);
  for (int i12{0}; i12 < c_loop_ub; i12++) {
    for (int i13{0}; i13 < 4; i13++) {
      for (int i15{0}; i15 < 4; i15++) {
        c_poses[(i15 + (4 * i13)) + (16 * i12)] =
            poses[(i15 + (4 * i13)) + (16 * (r[i12] - 1))];
      }
    }
  }
  poses.set_size(4, 4, c_poses.size(2));
  d_loop_ub = c_poses.size(2);
  for (int i14{0}; i14 < d_loop_ub; i14++) {
    for (int i16{0}; i16 < 4; i16++) {
      for (int i17{0}; i17 < 4; i17++) {
        poses[(i17 + (4 * i16)) + (16 * i14)] =
            c_poses[(i17 + (4 * i16)) + (16 * i14)];
      }
    }
  }
  b_end = valid_idx.size(0) - 1;
  b_trueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (valid_idx[g_i]) {
      b_trueCount++;
    }
  }
  r1.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int h_i{0}; h_i <= b_end; h_i++) {
    if (valid_idx[h_i]) {
      r1[b_partialTrueCount] = h_i + 1;
      b_partialTrueCount++;
    }
  }
  b_extrinsics.set_size(4, 4, r1.size(0));
  e_loop_ub = r1.size(0);
  for (int i18{0}; i18 < e_loop_ub; i18++) {
    for (int i19{0}; i19 < 4; i19++) {
      for (int i21{0}; i21 < 4; i21++) {
        b_extrinsics[(i21 + (4 * i19)) + (16 * i18)] =
            extrinsics[(i21 + (4 * i19)) + (16 * (r1[i18] - 1))];
      }
    }
  }
  extrinsics.set_size(4, 4, b_extrinsics.size(2));
  f_loop_ub = b_extrinsics.size(2);
  for (int i20{0}; i20 < f_loop_ub; i20++) {
    for (int i22{0}; i22 < 4; i22++) {
      for (int i23{0}; i23 < 4; i23++) {
        extrinsics[(i23 + (4 * i22)) + (16 * i20)] =
            b_extrinsics[(i23 + (4 * i22)) + (16 * i20)];
      }
    }
  }
}

//
// File trailer for readRobotPoses.cpp
//
// [EOF]
//
