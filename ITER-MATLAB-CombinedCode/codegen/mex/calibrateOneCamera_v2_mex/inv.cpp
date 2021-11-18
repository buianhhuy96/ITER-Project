//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inv.cpp
//
// Code generation for function 'inv'
//

// Include files
#include "inv.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo aab_emlrtRSI{
    59,      // lineNo
    "xtrsm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" // pathName
};

static emlrtRSInfo cab_emlrtRSI{
    51,      // lineNo
    "xtrsm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsm.m" // pathName
};

static emlrtRSInfo iab_emlrtRSI{
    31,    // lineNo
    "inv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo jab_emlrtRSI{
    42,          // lineNo
    "checkcond", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo kab_emlrtRSI{
    46,          // lineNo
    "checkcond", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo ugb_emlrtRSI{
    21,    // lineNo
    "inv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo vgb_emlrtRSI{
    22,    // lineNo
    "inv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo wgb_emlrtRSI{
    173,      // lineNo
    "invNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo xgb_emlrtRSI{
    180,      // lineNo
    "invNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo ygb_emlrtRSI{
    183,      // lineNo
    "invNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

static emlrtRSInfo ahb_emlrtRSI{
    190,      // lineNo
    "invNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" // pathName
};

// Function Definitions
namespace coder {
void b_inv(const emlrtStack *sp, const real_T x[16], real_T y[16])
{
  static const int32_T b_iv[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  real_T b_x[16];
  real_T n1x;
  real_T n1xinv;
  real_T s;
  real_T smax;
  int32_T a;
  int32_T b;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int32_T n;
  char_T str[14];
  int8_T ipiv[4];
  int8_T p[4];
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ugb_emlrtRSI;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  std::memset(&y[0], 0, 16U * sizeof(real_T));
  b_st.site = &wgb_emlrtRSI;
  std::copy(&x[0], &x[16], &b_x[0]);
  c_st.site = &py_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    int32_T b_tmp;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    n = 4 - j;
    d_st.site = &sy_emlrtRSI;
    e_st.site = &rm_emlrtRSI;
    a = 0;
    smax = muDoubleScalarAbs(b_x[b_tmp]);
    f_st.site = &sm_emlrtRSI;
    for (k = 2; k <= n; k++) {
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = static_cast<int8_T>(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 4];
        b_x[j + 4] = b_x[jA + 4];
        b_x[jA + 4] = smax;
        smax = b_x[j + 8];
        b_x[j + 8] = b_x[jA + 8];
        b_x[jA + 8] = smax;
        smax = b_x[j + 12];
        b_x[j + 12] = b_x[jA + 12];
        b_x[jA + 12] = smax;
      }
      b = (b_tmp - j) + 4;
      d_st.site = &ty_emlrtRSI;
      for (i = jp1j; i <= b; i++) {
        b_x[i - 1] /= b_x[b_tmp];
      }
    }
    n = 2 - j;
    d_st.site = &uy_emlrtRSI;
    e_st.site = &vy_emlrtRSI;
    f_st.site = &xm_emlrtRSI;
    g_st.site = &ym_emlrtRSI;
    jA = b_tmp + 6;
    h_st.site = &an_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_x[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0) {
        b = (jA - j) + 2;
        h_st.site = &bn_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          i_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (a = jA; a <= b; a++) {
          b_x[a - 1] += b_x[((b_tmp + a) - jA) + 1] * -smax;
        }
      }
      jA += 4;
    }
  }
  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  if (ipiv[0] > 1) {
    jA = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = 1;
    p[0] = static_cast<int8_T>(jA);
  }
  if (ipiv[1] > 2) {
    jA = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = static_cast<int8_T>(jA);
  }
  if (ipiv[2] > 3) {
    jA = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = static_cast<int8_T>(jA);
  }
  for (k = 0; k < 4; k++) {
    b = (p[k] - 1) << 2;
    y[k + b] = 1.0;
    b_st.site = &xgb_emlrtRSI;
    for (j = k + 1; j < 5; j++) {
      n = (j + b) - 1;
      if (y[n] != 0.0) {
        a = j + 1;
        b_st.site = &ygb_emlrtRSI;
        for (i = a; i < 5; i++) {
          jA = (i + b) - 1;
          y[jA] -= y[n] * b_x[(i + ((j - 1) << 2)) - 1];
        }
      }
    }
  }
  b_st.site = &ahb_emlrtRSI;
  c_st.site = &aab_emlrtRSI;
  for (j = 0; j < 4; j++) {
    jA = j << 2;
    for (k = 3; k >= 0; k--) {
      jp1j = k << 2;
      n = k + jA;
      smax = y[n];
      if (smax != 0.0) {
        y[n] = smax / b_x[k + jp1j];
        d_st.site = &cab_emlrtRSI;
        for (i = 0; i < k; i++) {
          b = i + jA;
          y[b] -= y[n] * b_x[i + jp1j];
        }
      }
    }
  }
  st.site = &vgb_emlrtRSI;
  n1x = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 4)) {
    jA = j << 2;
    s = ((muDoubleScalarAbs(x[jA]) + muDoubleScalarAbs(x[jA + 1])) +
         muDoubleScalarAbs(x[jA + 2])) +
        muDoubleScalarAbs(x[jA + 3]);
    if (muDoubleScalarIsNaN(s)) {
      n1x = rtNaN;
      exitg1 = true;
    } else {
      if (s > n1x) {
        n1x = s;
      }
      j++;
    }
  }
  n1xinv = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 4)) {
    jA = j << 2;
    s = ((muDoubleScalarAbs(y[jA]) + muDoubleScalarAbs(y[jA + 1])) +
         muDoubleScalarAbs(y[jA + 2])) +
        muDoubleScalarAbs(y[jA + 3]);
    if (muDoubleScalarIsNaN(s)) {
      n1xinv = rtNaN;
      exitg1 = true;
    } else {
      if (s > n1xinv) {
        n1xinv = s;
      }
      j++;
    }
  }
  smax = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (smax == 0.0)) {
    b_st.site = &jab_emlrtRSI;
    internal::d_warning(&b_st);
  } else if (muDoubleScalarIsNaN(smax) || (smax < 2.2204460492503131E-16)) {
    b_st.site = &kab_emlrtRSI;
    b_y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 6, m, &rfmt[0]);
    emlrtAssign(&b_y, m);
    c_st.site = &djb_emlrtRSI;
    emlrt_marshallIn(
        &c_st, b_sprintf(&c_st, b_y, emlrt_marshallOut(smax), &c_emlrtMCI),
        "<output of sprintf>", str);
    b_st.site = &kab_emlrtRSI;
    internal::warning(&b_st, str);
  }
}

void inv(const emlrtStack *sp, const real_T x[9], real_T y[9])
{
  static const int32_T b_iv[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  real_T b_x[9];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  char_T str[14];
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  std::copy(&x[0], &x[9], &b_x[0]);
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = muDoubleScalarAbs(x[0]);
  absx21 = muDoubleScalarAbs(x[1]);
  absx31 = muDoubleScalarAbs(x[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
  } else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    b_x[0] = x[2];
    b_x[2] = x[0];
    b_x[3] = x[5];
    b_x[5] = x[3];
    b_x[6] = x[8];
    b_x[8] = x[6];
  }
  b_x[1] /= b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= b_x[1] * b_x[3];
  b_x[5] -= b_x[2] * b_x[3];
  b_x[7] -= b_x[1] * b_x[6];
  b_x[8] -= b_x[2] * b_x[6];
  if (muDoubleScalarAbs(b_x[5]) > muDoubleScalarAbs(b_x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx11;
    absx11 = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx11;
    absx11 = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx11;
  }
  b_x[5] /= b_x[4];
  b_x[8] -= b_x[5] * b_x[7];
  absx11 = (b_x[1] * b_x[5] - b_x[2]) / b_x[8];
  absx21 = -(b_x[1] + b_x[7] * absx11) / b_x[4];
  y[p1] = ((1.0 - b_x[3] * absx21) - b_x[6] * absx11) / b_x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -b_x[5] / b_x[8];
  absx21 = (1.0 - b_x[7] * absx11) / b_x[4];
  y[p2] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / b_x[8];
  absx21 = -b_x[7] * absx11 / b_x[4];
  y[p3] = -(b_x[3] * absx21 + b_x[6] * absx11) / b_x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
  st.site = &iab_emlrtRSI;
  absx21 = 0.0;
  p1 = 0;
  exitg1 = false;
  while ((!exitg1) && (p1 < 3)) {
    absx11 = (muDoubleScalarAbs(x[3 * p1]) + muDoubleScalarAbs(x[3 * p1 + 1])) +
             muDoubleScalarAbs(x[3 * p1 + 2]);
    if (muDoubleScalarIsNaN(absx11)) {
      absx21 = rtNaN;
      exitg1 = true;
    } else {
      if (absx11 > absx21) {
        absx21 = absx11;
      }
      p1++;
    }
  }
  absx31 = 0.0;
  p1 = 0;
  exitg1 = false;
  while ((!exitg1) && (p1 < 3)) {
    absx11 = (muDoubleScalarAbs(y[3 * p1]) + muDoubleScalarAbs(y[3 * p1 + 1])) +
             muDoubleScalarAbs(y[3 * p1 + 2]);
    if (muDoubleScalarIsNaN(absx11)) {
      absx31 = rtNaN;
      exitg1 = true;
    } else {
      if (absx11 > absx31) {
        absx31 = absx11;
      }
      p1++;
    }
  }
  absx11 = 1.0 / (absx21 * absx31);
  if ((absx21 == 0.0) || (absx31 == 0.0) || (absx11 == 0.0)) {
    b_st.site = &jab_emlrtRSI;
    internal::d_warning(&b_st);
  } else if (muDoubleScalarIsNaN(absx11) || (absx11 < 2.2204460492503131E-16)) {
    b_st.site = &kab_emlrtRSI;
    b_y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 6, m, &rfmt[0]);
    emlrtAssign(&b_y, m);
    c_st.site = &djb_emlrtRSI;
    emlrt_marshallIn(
        &c_st, b_sprintf(&c_st, b_y, emlrt_marshallOut(absx11), &c_emlrtMCI),
        "<output of sprintf>", str);
    b_st.site = &kab_emlrtRSI;
    internal::warning(&b_st, str);
  }
}

} // namespace coder

// End of code generation (inv.cpp)
