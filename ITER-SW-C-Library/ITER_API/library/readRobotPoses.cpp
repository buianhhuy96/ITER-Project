//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: readRobotPoses.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "readRobotPoses.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Initialize arrays of poses and extrinsics
//
// Arguments    : const coder::array<double, 3U> &robotPosesVec
//                coder::array<double, 3U> &poses
//                coder::array<double, 3U> &extrinsics
// Return Type  : void
//
void readRobotPoses(const coder::array<double, 3U> &robotPosesVec,
                    coder::array<double, 3U> &poses,
                    coder::array<double, 3U> &extrinsics)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  double b_poses[3][3];
  int b_loop_ub;
  int i1;
  int i2;
  int i4;
  int i5;
  int i6;
  int loop_ub;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  poses.set_size(4, 4, robotPosesVec.size(2));
  loop_ub = robotPosesVec.size(2);
  if ((static_cast<int>((robotPosesVec.size(2) * 16) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          poses[(i2 + (4 * i1)) + (16 * b_i)] = 0.0;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2, i1)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          poses[(i2 + (4 * i1)) + (16 * b_i)] = 0.0;
        }
      }
    }
  }
  extrinsics.set_size(4, 4, robotPosesVec.size(2));
  b_loop_ub = robotPosesVec.size(2);
  if ((static_cast<int>((robotPosesVec.size(2) * 16) < 4)) != 0) {
    for (int i3{0}; i3 < b_loop_ub; i3++) {
      for (i4 = 0; i4 < 4; i4++) {
        for (i5 = 0; i5 < 4; i5++) {
          extrinsics[(i5 + (4 * i4)) + (16 * i3)] = 0.0;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5, i4)

    for (int i3 = 0; i3 < b_loop_ub; i3++) {
      for (i4 = 0; i4 < 4; i4++) {
        for (i5 = 0; i5 < 4; i5++) {
          extrinsics[(i5 + (4 * i4)) + (16 * i3)] = 0.0;
        }
      }
    }
  }
  // read valid poses and reshape them to 4x4xn matrix
  i6 = robotPosesVec.size(2);
  for (int c_i{0}; c_i < i6; c_i++) {
    for (int i7{0}; i7 < 4; i7++) {
      for (int i9{0}; i9 < 4; i9++) {
        poses[(i9 + (4 * i7)) + (16 * c_i)] =
            robotPosesVec[(i9 + (4 * i7)) + (16 * c_i)];
      }
    }
    for (int b_i8{0}; b_i8 < 3; b_i8++) {
      b_poses[b_i8][0] = -poses[b_i8 + (16 * c_i)];
      b_poses[b_i8][1] = -poses[(b_i8 + (16 * c_i)) + 4];
      b_poses[b_i8][2] = -poses[(b_i8 + (16 * c_i)) + 8];
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
      extrinsics[((4 * i11) + (16 * c_i)) + 3] = static_cast<double>(b_iv[i11]);
    }
  }
}

//
// File trailer for readRobotPoses.cpp
//
// [EOF]
//
