//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// unsafeSxfun.cpp
//
// Code generation for function 'unsafeSxfun'
//

// Include files
#include "unsafeSxfun.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo ws_emlrtRTEI{
    40,              // lineNo
    27,              // colNo
    "CalculateCost", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\auxiliaries\\CalculateCost.m" // pName
};

// Function Definitions
namespace Codegen {
void binary_expand_op(const emlrtStack *sp, ::coder::array<real_T, 2U> &points,
                      const ::coder::array<real_T, 2U> &distortedPoints)
{
  ::coder::array<real_T, 2U> b_distortedPoints;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (points.size(0) == 1) {
    i = distortedPoints.size(0);
  } else {
    i = points.size(0);
  }
  b_distortedPoints.set_size(&ws_emlrtRTEI, sp, i, 2);
  stride_0_0 = (distortedPoints.size(0) != 1);
  stride_1_0 = (points.size(0) != 1);
  if (points.size(0) == 1) {
    loop_ub = distortedPoints.size(0);
  } else {
    loop_ub = points.size(0);
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_distortedPoints[i1 + b_distortedPoints.size(0) * i] =
          distortedPoints[i1 * stride_0_0 + distortedPoints.size(0) * i] -
          points[i1 * stride_1_0 + points.size(0) * i];
    }
  }
  points.set_size(&ar_emlrtRTEI, sp, b_distortedPoints.size(0), 2);
  loop_ub = b_distortedPoints.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T varargin_1;
      varargin_1 = b_distortedPoints[i1 + b_distortedPoints.size(0) * i];
      points[i1 + points.size(0) * i] = varargin_1 * varargin_1;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace Codegen

// End of code generation (unsafeSxfun.cpp)
