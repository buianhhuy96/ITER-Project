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
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo fn_emlrtRSI{
    20,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo hn_emlrtRSI{
    112,                // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo in_emlrtRSI{
    173,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo jn_emlrtRSI{
    192,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRTEInfo lk_emlrtRTEI{
    146,                // lineNo
    24,                 // colNo
    "blockedSummation", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pName
};

static emlrtRTEInfo mk_emlrtRTEI{
    20,    // lineNo
    1,     // colNo
    "sum", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
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
  st.site = &fn_emlrtRSI;
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
  b_st.site = &gn_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&mk_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    int32_T xj;
    d_st.site = &hn_emlrtRSI;
    vstride = x.size(0);
    y.set_size(&lk_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &in_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
    e_st.site = &jn_emlrtRSI;
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = y[xj] + x[vstride + xj];
    }
  }
}

real_T sum(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fn_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gn_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    d_st.site = &xo_emlrtRSI;
    e_st.site = &ak_emlrtRSI;
    y = sumMatrixColumns(&e_st, x, x.size(0));
  }
  return y;
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
  st.site = &fn_emlrtRSI;
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
  b_st.site = &gn_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&mk_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vstride;
    int32_T xj;
    d_st.site = &hn_emlrtRSI;
    vstride = x.size(0);
    y.set_size(&lk_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &in_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
    e_st.site = &jn_emlrtRSI;
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = y[xj] + x[vstride + xj];
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (sum.cpp)
