//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// nanmean.cpp
//
// Code generation for function 'nanmean'
//

// Include files
#include "nanmean.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo pfb_emlrtRSI{
    7,         // lineNo
    "nanmean", // fcnName
    "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\stats\\eml\\nanmean.m" // pathName
};

static emlrtRSInfo qfb_emlrtRSI{
    74,                // lineNo
    "nan_sum_or_mean", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\stats\\eml\\private\\nan_sum_or_mean.m" // pathName
};

static emlrtBCInfo
    jv_emlrtBCI{
        -1,                // iFirst
        -1,                // iLast
        75,                // lineNo
        21,                // colNo
        "",                // aName
        "nan_sum_or_mean", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\stats\\eml\\private\\nan_sum_or_mean."
        "m", // pName
        0    // checkKind
    };

static emlrtBCInfo
    kv_emlrtBCI{
        -1,                // iFirst
        -1,                // iLast
        76,                // lineNo
        23,                // colNo
        "",                // aName
        "nan_sum_or_mean", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\stats\\eml\\private\\nan_sum_or_mean."
        "m", // pName
        0    // checkKind
    };

// Function Definitions
namespace coder {
real_T nanmean(const emlrtStack *sp,
               const ::coder::array<real_T, 1U> &varargin_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pfb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (varargin_1.size(0) == 0) {
    y = rtNaN;
  } else {
    int32_T c;
    int32_T vlen;
    vlen = varargin_1.size(0);
    y = 0.0;
    c = 0;
    b_st.site = &qfb_emlrtRSI;
    if (varargin_1.size(0) > 2147483646) {
      c_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (int32_T k{0}; k < vlen; k++) {
      if (k + 1 > varargin_1.size(0)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, varargin_1.size(0),
                                      &jv_emlrtBCI, &st);
      }
      if (!muDoubleScalarIsNaN(varargin_1[k])) {
        if (k + 1 > varargin_1.size(0)) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, varargin_1.size(0),
                                        &kv_emlrtBCI, &st);
        }
        y += varargin_1[k];
        c++;
      }
    }
    if (c == 0) {
      y = rtNaN;
    } else {
      y /= static_cast<real_T>(c);
    }
  }
  return y;
}

} // namespace coder

// End of code generation (nanmean.cpp)
