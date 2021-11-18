//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xcopy.cpp
//
// Code generation for function 'xcopy'
//

// Include files
#include "xcopy.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo dfb_emlrtRSI{
    38,      // lineNo
    "xcopy", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xcopy."
    "m" // pathName
};

static emlrtRSInfo efb_emlrtRSI{
    69,      // lineNo
    "xcopy", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xcopy.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 1U> &y,
           int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dfb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &efb_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < n; k++) {
    y[(iy0 + k) - 1] = 0.0;
  }
}

void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dfb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &efb_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < n; k++) {
    y[k] = rtNaN;
  }
}

void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 2U> &y,
           int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dfb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &efb_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < n; k++) {
    y[(iy0 + k) - 1] = 0.0;
  }
}

void xcopy(int32_T n, const ::coder::array<real_T, 2U> &x, int32_T ix0,
           ::coder::array<real_T, 2U> &y, int32_T iy0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, (real_T *)&x[ix0 - 1], &incx_t, &y[iy0 - 1], &incy_t);
  }
}

void xcopy(int32_T n, const ::coder::array<real_T, 1U> &x,
           ::coder::array<real_T, 1U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(((::coder::array<real_T, 1U> *)&x)->data())[0], &incx_t,
          &(y.data())[0], &incy_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xcopy.cpp)
