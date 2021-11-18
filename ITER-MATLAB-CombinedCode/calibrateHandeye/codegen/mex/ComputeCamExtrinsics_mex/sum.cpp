//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo bp_emlrtRSI{
    112,                // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo cp_emlrtRSI{
    173,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo dp_emlrtRSI{
    192,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRTEInfo jl_emlrtRTEI{
    146,                // lineNo
    24,                 // colNo
    "blockedSummation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pName
};

static emlrtRTEInfo kl_emlrtRTEI{
    20,    // lineNo
    1,     // colNo
    "sum", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pName
};

// Function Definitions
namespace coder {
void b_sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
           ::coder::array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yo_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ap_emlrtRSI;
  c_st.site = &ml_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&kl_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    int32_T xj;
    d_st.site = &bp_emlrtRSI;
    vstride = x.size(0) - 1;
    y.set_size(&jl_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &cp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = x[xj];
    }
    e_st.site = &dp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = y[xj] + x[x.size(0) + xj];
    }
  }
}

void sum(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &x,
         ::coder::array<real32_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yo_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ap_emlrtRSI;
  c_st.site = &ml_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&kl_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    int32_T xj;
    d_st.site = &bp_emlrtRSI;
    vstride = x.size(0) - 1;
    y.set_size(&jl_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &cp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = x[xj];
    }
    e_st.site = &dp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj <= vstride; xj++) {
      y[xj] = y[xj] + x[x.size(0) + xj];
    }
  }
}

void sum(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
         ::coder::array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yo_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ap_emlrtRSI;
  c_st.site = &ml_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&kl_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    d_st.site = &bp_emlrtRSI;
    vstride = x.size(0);
    y.set_size(&jl_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &cp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (int32_T xj{0}; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
  }
}

void sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
         ::coder::array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yo_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ap_emlrtRSI;
  c_st.site = &ml_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&kl_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    int32_T xj;
    boolean_T overflow;
    d_st.site = &bp_emlrtRSI;
    vstride = x.size(0);
    y.set_size(&jl_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &cp_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
    overflow = (x.size(0) > 2147483646);
    for (int32_T k{0}; k < 2; k++) {
      int32_T xoffset;
      xoffset = (k + 1) * vstride;
      e_st.site = &dp_emlrtRSI;
      if (overflow) {
        f_st.site = &cd_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (xj = 0; xj < vstride; xj++) {
        y[xj] = y[xj] + x[xoffset + xj];
      }
    }
  }
}

} // namespace coder

// End of code generation (sum.cpp)
