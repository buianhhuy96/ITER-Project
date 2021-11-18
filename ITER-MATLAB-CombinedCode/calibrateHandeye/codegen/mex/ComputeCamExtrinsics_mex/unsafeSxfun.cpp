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
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo sw_emlrtRTEI{
    76,              // lineNo
    25,              // colNo
    "computeErrors", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-HandeyeCalibration\\Matlab-"
    "code\\computeErrors.m" // pName
};

// Function Definitions
void binary_expand_op(const emlrtStack *sp, coder::array<real_T, 2U> &proj,
                      const coder::array<real_T, 3U> &imgPts, int32_T j)
{
  coder::array<real_T, 2U> b_imgPts;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = imgPts.size(0);
  if (proj.size(0) == 1) {
    i1 = i;
  } else {
    i1 = proj.size(0);
  }
  b_imgPts.set_size(&sw_emlrtRTEI, sp, i1, 2);
  stride_0_0 = (i != 1);
  stride_1_0 = (proj.size(0) != 1);
  if (proj.size(0) == 1) {
    loop_ub = i;
  } else {
    loop_ub = proj.size(0);
  }
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_imgPts[i1 + b_imgPts.size(0) * i] =
          imgPts[(i1 * stride_0_0 + imgPts.size(0) * i) +
                 imgPts.size(0) * 2 * j] -
          proj[i1 * stride_1_0 + proj.size(0) * i];
    }
  }
  proj.set_size(&bs_emlrtRTEI, sp, b_imgPts.size(0), 2);
  loop_ub = b_imgPts.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T varargin_1;
      varargin_1 = b_imgPts[i1 + b_imgPts.size(0) * i];
      proj[i1 + proj.size(0) * i] = varargin_1 * varargin_1;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (unsafeSxfun.cpp)
