//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdotc.cpp
//
// Code generation for function 'xdotc'
//

// Include files
#include "xdotc.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo fs_emlrtRSI{
    32,      // lineNo
    "xdotc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc."
    "m" // pathName
};

static emlrtRSInfo
    gs_emlrtRSI{
        35,     // lineNo
        "xdot", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xdot.m" // pathName
    };

static emlrtRSInfo hs_emlrtRSI{
    15,     // lineNo
    "xdot", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdot.m" // pathName
};

static emlrtRSInfo is_emlrtRSI{
    42,      // lineNo
    "xdotx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xdotx.m" // pathName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
             const real_T y[9], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fs_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gs_emlrtRSI;
  c_st.site = &hs_emlrtRSI;
  d = 0.0;
  d_st.site = &is_emlrtRSI;
  if ((1 <= n) && (n > 2147483646)) {
    e_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (int32_T k{0}; k < n; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xdotc.cpp)
