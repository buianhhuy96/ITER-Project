//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// det.cpp
//
// Code generation for function 'det'
//

// Include files
#include "det.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo pab_emlrtRSI{
    21,    // lineNo
    "det", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\det.m" // pathName
};

// Function Definitions
namespace coder {
real_T det(const emlrtStack *sp, const real_T x[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_x[9];
  real_T y;
  int8_T ipiv[3];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pab_emlrtRSI;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  std::copy(&x[0], &x[9], &b_x[0]);
  b_st.site = &qy_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (int32_T j{0}; j < 2; j++) {
    real_T smax;
    int32_T b_tmp;
    int32_T jA;
    int32_T jp1j;
    int32_T k;
    int32_T n;
    b_tmp = j << 2;
    jp1j = b_tmp + 2;
    n = 3 - j;
    c_st.site = &ty_emlrtRSI;
    d_st.site = &um_emlrtRSI;
    jA = 0;
    smax = muDoubleScalarAbs(b_x[b_tmp]);
    e_st.site = &vm_emlrtRSI;
    for (k = 2; k <= n; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + jA] != 0.0) {
      if (jA != 0) {
        jA += j;
        ipiv[j] = static_cast<int8_T>(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 3];
        b_x[j + 3] = b_x[jA + 3];
        b_x[jA + 3] = smax;
        smax = b_x[j + 6];
        b_x[j + 6] = b_x[jA + 6];
        b_x[jA + 6] = smax;
      }
      k = (b_tmp - j) + 3;
      c_st.site = &uy_emlrtRSI;
      for (jA = jp1j; jA <= k; jA++) {
        b_x[jA - 1] /= b_x[b_tmp];
      }
    }
    n = 1 - j;
    c_st.site = &vy_emlrtRSI;
    d_st.site = &wy_emlrtRSI;
    e_st.site = &ym_emlrtRSI;
    f_st.site = &an_emlrtRSI;
    jA = b_tmp + 5;
    g_st.site = &bn_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_x[(b_tmp + jp1j * 3) + 3];
      if (smax != 0.0) {
        k = (jA - j) + 1;
        g_st.site = &cn_emlrtRSI;
        if ((jA <= k) && (k > 2147483646)) {
          h_st.site = &cd_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (int32_T ijA{jA}; ijA <= k; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -smax;
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = b_x[0] * b_x[4] * b_x[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

} // namespace coder

// End of code generation (det.cpp)
