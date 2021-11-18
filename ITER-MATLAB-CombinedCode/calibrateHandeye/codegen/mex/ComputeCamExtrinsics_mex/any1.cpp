//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// any1.cpp
//
// Code generation for function 'any1'
//

// Include files
#include "any1.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    ib_emlrtRSI{
        13,    // lineNo
        "any", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\any.m" // pathName
    };

static emlrtRSInfo
    ot_emlrtRSI{
        133,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

static emlrtRSInfo
    pt_emlrtRSI{
        139,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

static emlrtRTEInfo xb_emlrtRTEI{
    19,                               // lineNo
    19,                               // colNo
    "eml_int_forloop_overflow_check", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" // pName
};

// Function Definitions
namespace coder {
boolean_T any(const boolean_T x[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return y;
}

boolean_T b_any(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = false;
  b_st.site = &dj_emlrtRSI;
  if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
    c_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(0))) {
    if (x[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

boolean_T c_any(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = false;
  b_st.site = &dj_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    c_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(1))) {
    if (x[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

boolean_T d_any(const emlrtStack *sp, const ::coder::array<boolean_T, 3U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i1;
  int32_T i2;
  int32_T k;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ib_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = false;
  k = 3;
  if (x.size(2) == 1) {
    k = 2;
  }
  if (3 > k) {
    k = x.size(2);
  } else {
    k = 1;
  }
  b_st.site = &ot_emlrtRSI;
  b_st.site = &ms_emlrtRSI;
  i1 = 0;
  i2 = (x.size(2) - 1) * k;
  b_st.site = &pt_emlrtRSI;
  if ((1 <= k) && (k > 2147483646)) {
    c_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T j{0}; j < k; j++) {
    int32_T ix;
    boolean_T exitg1;
    boolean_T overflow;
    i1++;
    i2++;
    b_st.site = &dj_emlrtRSI;
    if ((k == 0) || (i1 > i2)) {
      overflow = false;
    } else {
      overflow = (i2 > MAX_int32_T - k);
    }
    if (k == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &xb_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      c_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (x[ix - 1]) {
        y = true;
        exitg1 = true;
      } else {
        ix += k;
      }
    }
  }
  return y;
}

} // namespace coder

// End of code generation (any1.cpp)
