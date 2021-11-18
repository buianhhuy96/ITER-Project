//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// bsxfun.cpp
//
// Code generation for function 'bsxfun'
//

// Include files
#include "bsxfun.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace Codegen {
namespace coder {
void bsxfun(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
            const real_T b[2], ::coder::array<real32_T, 2U> &c)
{
  if ((a.size(1) != 1) && (a.size(1) != 2)) {
    emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  c.set_size(&mf_emlrtRTEI, sp, a.size(0), 2);
  if (a.size(0) != 0) {
    int32_T acoef;
    int32_T b_acoef;
    acoef = (a.size(1) != 1);
    b_acoef = (a.size(0) != 1);
    for (int32_T k{0}; k < 2; k++) {
      int32_T i;
      int32_T varargin_2;
      varargin_2 = acoef * k;
      i = c.size(0) - 1;
      for (int32_T b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] = a[b_acoef * b_k + a.size(0) * varargin_2] -
                                 static_cast<real32_T>(b[k]);
      }
    }
  }
}

void bsxfun(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
            const ::coder::array<real_T, 1U> &b, ::coder::array<real_T, 2U> &c)
{
  int32_T csz_idx_0;
  if (b.size(0) == 1) {
    csz_idx_0 = a.size(0);
  } else if (a.size(0) == 1) {
    csz_idx_0 = b.size(0);
  } else if (a.size(0) == b.size(0)) {
    csz_idx_0 = a.size(0);
  } else {
    emlrtErrorWithMessageIdR2018a(sp, &v_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  c.set_size(&mf_emlrtRTEI, sp, csz_idx_0, 2);
  if (csz_idx_0 != 0) {
    int32_T bcoef;
    csz_idx_0 = (a.size(0) != 1);
    bcoef = (b.size(0) != 1);
    for (int32_T k{0}; k < 2; k++) {
      int32_T i;
      i = c.size(0) - 1;
      for (int32_T b_k{0}; b_k <= i; b_k++) {
        c[b_k + c.size(0) * k] =
            a[csz_idx_0 * b_k + a.size(0) * k] / b[bcoef * b_k];
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (bsxfun.cpp)
