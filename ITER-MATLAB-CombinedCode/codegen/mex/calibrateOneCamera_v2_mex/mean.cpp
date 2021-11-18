//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mean.cpp
//
// Code generation for function 'mean'
//

// Include files
#include "mean.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo kl_emlrtRSI{
    99,                 // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

// Function Definitions
namespace coder {
real_T mean(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x)
{
  array<real_T, 1U> c_x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &il_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &jl_emlrtRSI;
  if (x.size(1) == 0) {
    y = 0.0;
  } else {
    int32_T b_x;
    c_st.site = &kl_emlrtRSI;
    b_x = x.size(1);
    c_x = x.reshape(b_x);
    d_st.site = &ll_emlrtRSI;
    y = sumMatrixColumns(&d_st, c_x, x.size(1));
  }
  y /= static_cast<real_T>(x.size(1));
  return y;
}

real32_T mean(const emlrtStack *sp, const ::coder::array<real32_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real32_T s;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &il_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jl_emlrtRSI;
  if (x.size(0) == 0) {
    s = 0.0F;
  } else {
    c_st.site = &cr_emlrtRSI;
    d_st.site = &ll_emlrtRSI;
    if (x.size(0) < 4096) {
      e_st.site = &ml_emlrtRSI;
      s = sumColumnB(&e_st, x, x.size(0));
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = x.size(0) / 4096;
      inb = nfb << 12;
      nleft = x.size(0) - inb;
      s = sumColumnB4(x, 1);
      for (int32_T ib{2}; ib <= nfb; ib++) {
        s += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        e_st.site = &ol_emlrtRSI;
        s += sumColumnB(&e_st, x, nleft, inb + 1);
      }
    }
  }
  return s / static_cast<real32_T>(x.size(0));
}

real_T mean(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &il_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &jl_emlrtRSI;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    c_st.site = &cr_emlrtRSI;
    d_st.site = &ll_emlrtRSI;
    y = sumMatrixColumns(&d_st, x, x.size(0));
  }
  y /= static_cast<real_T>(x.size(0));
  return y;
}

} // namespace coder

// End of code generation (mean.cpp)
