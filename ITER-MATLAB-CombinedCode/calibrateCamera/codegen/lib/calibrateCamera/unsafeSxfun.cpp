//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "unsafeSxfun.h"
#include "calibrateCamera_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &projectedPointsnorm
//                const ::coder::array<real_T, 2U> &centeredPoints
//                const struct1_T *calibrationConverted_CameraParameters
//                const ::coder::array<real_T, 2U> &b_points
// Return Type  : void
//
namespace Codegen {
void binary_expand_op(::coder::array<real_T, 2U> &projectedPointsnorm,
                      const ::coder::array<real_T, 2U> &centeredPoints,
                      const struct1_T *calibrationConverted_CameraParameters,
                      const ::coder::array<real_T, 2U> &b_points)
{
  ::coder::array<real_T, 2U> b_centeredPoints;
  ::coder::array<real_T, 2U> c_centeredPoints;
  real_T b_calibrationConverted_CameraPara;
  real_T c_calibrationConverted_CameraPara;
  real_T calibrationConverted_CameraPara;
  real_T d_calibrationConverted_CameraPara;
  real_T e_calibrationConverted_CameraPara;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_1_0;
  calibrationConverted_CameraPara =
      calibrationConverted_CameraParameters->IntrinsicMatrix[0][0];
  b_calibrationConverted_CameraPara =
      calibrationConverted_CameraParameters->IntrinsicMatrix[0][2];
  c_calibrationConverted_CameraPara =
      calibrationConverted_CameraParameters->IntrinsicMatrix[0][1];
  d_calibrationConverted_CameraPara =
      calibrationConverted_CameraParameters->IntrinsicMatrix[1][1];
  e_calibrationConverted_CameraPara =
      calibrationConverted_CameraParameters->IntrinsicMatrix[1][2];
  loop_ub = centeredPoints.size(0);
  b_loop_ub = centeredPoints.size(0);
  b_centeredPoints.set_size(loop_ub, 2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_centeredPoints[b_i] =
        ((centeredPoints[b_i] * calibrationConverted_CameraPara) +
         b_calibrationConverted_CameraPara) +
        (c_calibrationConverted_CameraPara *
         centeredPoints[b_i + centeredPoints.size(0)]);
  }
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    b_centeredPoints[b_i + b_centeredPoints.size(0)] =
        (centeredPoints[b_i + centeredPoints.size(0)] *
         d_calibrationConverted_CameraPara) +
        e_calibrationConverted_CameraPara;
  }
  if (b_points.size(0) == 1) {
    b_i = b_centeredPoints.size(0);
  } else {
    b_i = b_points.size(0);
  }
  c_centeredPoints.set_size(b_i, 2);
  b_loop_ub = static_cast<int32_T>(b_centeredPoints.size(0) != 1);
  stride_1_0 = static_cast<int32_T>(b_points.size(0) != 1);
  if (b_points.size(0) == 1) {
    loop_ub = b_centeredPoints.size(0);
  } else {
    loop_ub = b_points.size(0);
  }
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_centeredPoints[i1 + (c_centeredPoints.size(0) * b_i)] =
          b_centeredPoints[(i1 * b_loop_ub) +
                           (b_centeredPoints.size(0) * b_i)] -
          b_points[(i1 * stride_1_0) + (b_points.size(0) * b_i)];
    }
  }
  b_centeredPoints.set_size(c_centeredPoints.size(0), 2);
  loop_ub = c_centeredPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_centeredPoints[i1 + (b_centeredPoints.size(0) * b_i)] =
          c_centeredPoints[i1 + (c_centeredPoints.size(0) * b_i)];
    }
  }
  projectedPointsnorm.set_size(b_centeredPoints.size(0), 2);
  loop_ub = b_centeredPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      calibrationConverted_CameraPara =
          b_centeredPoints[i1 + (b_centeredPoints.size(0) * b_i)];
      projectedPointsnorm[i1 + (projectedPointsnorm.size(0) * b_i)] =
          calibrationConverted_CameraPara * calibrationConverted_CameraPara;
    }
  }
}

} // namespace Codegen

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
