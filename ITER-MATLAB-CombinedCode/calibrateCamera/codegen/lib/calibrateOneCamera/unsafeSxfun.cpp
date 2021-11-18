//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "unsafeSxfun.h"
#include "calibrateOneCamera_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &projectedPointsnorm
//                const ::coder::array<double, 2U> &centeredPoints
//                const e_struct_T *CameraParameters
//                const ::coder::array<double, 2U> &b_points
// Return Type  : void
//
namespace Codegen {
void binary_expand_op(::coder::array<double, 2U> &projectedPointsnorm,
                      const ::coder::array<double, 2U> &centeredPoints,
                      const e_struct_T *CameraParameters,
                      const ::coder::array<double, 2U> &b_points)
{
  ::coder::array<double, 2U> b_centeredPoints;
  ::coder::array<double, 2U> c_centeredPoints;
  int b_i;
  int b_loop_ub;
  int i1;
  int loop_ub;
  int stride_1_0;
  loop_ub = centeredPoints.size(0);
  b_loop_ub = centeredPoints.size(0);
  b_centeredPoints.set_size(loop_ub, 2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_centeredPoints[b_i] =
        ((centeredPoints[b_i] * CameraParameters->IntrinsicMatrix[0][0]) +
         CameraParameters->IntrinsicMatrix[0][2]) +
        (CameraParameters->IntrinsicMatrix[0][1] *
         centeredPoints[b_i + centeredPoints.size(0)]);
  }
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    b_centeredPoints[b_i + b_centeredPoints.size(0)] =
        (centeredPoints[b_i + centeredPoints.size(0)] *
         CameraParameters->IntrinsicMatrix[1][1]) +
        CameraParameters->IntrinsicMatrix[1][2];
  }
  if (b_points.size(0) == 1) {
    b_i = b_centeredPoints.size(0);
  } else {
    b_i = b_points.size(0);
  }
  c_centeredPoints.set_size(b_i, 2);
  b_loop_ub = static_cast<int>(b_centeredPoints.size(0) != 1);
  stride_1_0 = static_cast<int>(b_points.size(0) != 1);
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
      double varargin_1;
      varargin_1 = b_centeredPoints[i1 + (b_centeredPoints.size(0) * b_i)];
      projectedPointsnorm[i1 + (projectedPointsnorm.size(0) * b_i)] =
          varargin_1 * varargin_1;
    }
  }
}

} // namespace Codegen

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
