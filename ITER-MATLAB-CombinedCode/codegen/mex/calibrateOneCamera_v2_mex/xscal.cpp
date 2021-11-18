//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xscal.cpp
//
// Code generation for function 'xscal'
//

// Include files
#include "xscal.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo tm_emlrtRSI{
    31,      // lineNo
    "xscal", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal."
    "m" // pathName
};

static emlrtRSInfo um_emlrtRSI{
    18,      // lineNo
    "xscal", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xscal.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tm_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = (ix0 + n) - 1;
  b_st.site = &um_emlrtRSI;
  if ((ix0 <= b) && (b > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{ix0}; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tm_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 2;
  b_st.site = &um_emlrtRSI;
  if ((ix0 <= ix0 + 2) && (ix0 + 2 > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{ix0}; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void xscal(real_T a, real_T x[3])
{
  for (int32_T k{2}; k < 4; k++) {
    x[k - 1] *= a;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xscal.cpp)
