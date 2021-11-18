//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mldivide.cpp
//
// Code generation for function 'mldivide'
//

// Include files
#include "mldivide.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "ComputeCamExtrinsics_mex_mexutil.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgeqp3.h"
#include "blas.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>

// Variable Definitions
static emlrtRSInfo wt_emlrtRSI{
    90,              // lineNo
    "warn_singular", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo gy_emlrtRSI{
    20,         // lineNo
    "mldivide", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo hy_emlrtRSI{
    42,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo iy_emlrtRSI{
    44,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo jy_emlrtRSI{
    67,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ky_emlrtRSI{
    112,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ly_emlrtRSI{
    109,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo my_emlrtRSI{
    124,          // lineNo
    "InvAtimesX", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ny_emlrtRSI{
    26,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo oy_emlrtRSI{
    27,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo py_emlrtRSI{
    27,       // lineNo
    "xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo ry_emlrtRSI{
    91,             // lineNo
    "ceval_xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo xy_emlrtRSI{
    18,       // lineNo
    "xgetrs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrs.m" // pathName
};

static emlrtRSInfo hab_emlrtRSI{
    61,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo iab_emlrtRSI{
    293,          // lineNo
    "lusolve3x3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo fcb_emlrtRSI{
    19,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo hcb_emlrtRSI{
    108,      // lineNo
    "cmldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRTEInfo oc_emlrtRTEI{
    16,         // lineNo
    19,         // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo ls_emlrtRTEI{
    44,         // lineNo
    34,         // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo ms_emlrtRTEI{
    1,         // lineNo
    31,        // colNo
    "xgetrfs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pName
};

static emlrtRTEInfo ns_emlrtRTEI{
    1,         // lineNo
    33,        // colNo
    "xgetrfs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pName
};

static emlrtRTEInfo os_emlrtRTEI{
    70,        // lineNo
    23,        // colNo
    "xgetrfs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pName
};

static emlrtRTEInfo ps_emlrtRTEI{
    20,         // lineNo
    5,          // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo qw_emlrtRTEI{
    1,        // lineNo
    37,       // colNo
    "xgetrf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pName
};

static emlrtRTEInfo rw_emlrtRTEI{
    89,       // lineNo
    27,       // colNo
    "xgetrf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pName
};

static const char_T cv3[19]{'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
                            'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k'};

// Function Definitions
namespace coder {
void b_mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[3],
                real_T Y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_A[9];
  real_T a21;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hy_emlrtRSI;
  c_st.site = &hab_emlrtRSI;
  std::copy(&A[0], &A[9], &b_A[0]);
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(A[0]);
  a21 = muDoubleScalarAbs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (muDoubleScalarAbs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  b_A[r2] = A[r2] / A[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
    d_st.site = &iab_emlrtRSI;
    e_st.site = &wt_emlrtRSI;
    internal::d_warning(&e_st);
  }
  Y[1] = B[r2] - B[r1] * b_A[r2];
  Y[2] = (B[r3] - B[r1] * b_A[r3]) - Y[1] * b_A[r3 + 3];
  Y[2] /= b_A[r3 + 6];
  Y[0] = B[r1] - Y[2] * b_A[r1 + 6];
  Y[1] -= Y[2] * b_A[r2 + 6];
  Y[1] /= b_A[r2 + 3];
  Y[0] -= Y[1] * b_A[r1 + 3];
  Y[0] /= b_A[r1];
}

void mldivide(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
              ::coder::array<real_T, 1U> &B)
{
  ptrdiff_t ipiv_t[8];
  array<real_T, 2U> b_A;
  array<int32_T, 2U> ipiv;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_dv[8];
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (B.size(0) != A.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &oc_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &gy_emlrtRSI;
  if ((A.size(0) == 0) || (B.size(0) == 0)) {
    B.set_size(&ps_emlrtRTEI, &st, 8);
    for (int32_T kAcol{0}; kAcol < 8; kAcol++) {
      B[kAcol] = 0.0;
    }
  } else if (A.size(0) == 8) {
    int32_T i;
    int32_T info;
    int32_T k;
    int32_T kAcol;
    b_st.site = &hy_emlrtRSI;
    c_st.site = &jy_emlrtRSI;
    d_st.site = &ly_emlrtRSI;
    e_st.site = &my_emlrtRSI;
    f_st.site = &ny_emlrtRSI;
    b_A.set_size(&qw_emlrtRTEI, &f_st, 8, 8);
    for (kAcol = 0; kAcol < 64; kAcol++) {
      b_A[kAcol] = A[kAcol];
    }
    ptrdiff_t info_t;
    g_st.site = &py_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)8, (ptrdiff_t)8,
                                 &(b_A.data())[0], (ptrdiff_t)8, &ipiv_t[0]);
    info = (int32_T)info_t;
    ipiv.set_size(&rw_emlrtRTEI, &g_st, 1, 8);
    h_st.site = &ry_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&h_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &h_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, &cv3[0], 12, info);
      }
    }
    for (k = 0; k < 8; k++) {
      ipiv[k] = (int32_T)ipiv_t[k];
    }
    f_st.site = &oy_emlrtRSI;
    g_st.site = &xy_emlrtRSI;
    for (i = 0; i < 7; i++) {
      kAcol = ipiv[i];
      if (kAcol != i + 1) {
        real_T temp;
        temp = B[i];
        B[i] = B[kAcol - 1];
        B[kAcol - 1] = temp;
      }
    }
    if (B.size(0) != 0) {
      for (k = 0; k < 8; k++) {
        kAcol = k << 3;
        if (B[k] != 0.0) {
          int32_T a;
          a = k + 2;
          for (i = a; i < 9; i++) {
            B[i - 1] = B[i - 1] - B[k] * b_A[(i + kAcol) - 1];
          }
        }
      }
    }
    if (B.size(0) != 0) {
      for (k = 7; k >= 0; k--) {
        kAcol = k << 3;
        if (B[k] != 0.0) {
          B[k] = B[k] / b_A[k + kAcol];
          for (i = 0; i < k; i++) {
            B[i] = B[i] - B[k] * b_A[i + kAcol];
          }
        }
      }
    }
    if (info > 0) {
      d_st.site = &ky_emlrtRSI;
      e_st.site = &wt_emlrtRSI;
      internal::d_warning(&e_st);
    }
  } else {
    b_st.site = &iy_emlrtRSI;
    internal::qrsolve(&b_st, A, B, b_dv);
    B.set_size(&ps_emlrtRTEI, &st, 8);
    for (int32_T kAcol{0}; kAcol < 8; kAcol++) {
      B[kAcol] = b_dv[kAcol];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[9],
              real_T Y[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_A[9];
  real_T a21;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T maxval;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hy_emlrtRSI;
  c_st.site = &hab_emlrtRSI;
  std::copy(&A[0], &A[9], &b_A[0]);
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(A[0]);
  a21 = muDoubleScalarAbs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (muDoubleScalarAbs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  b_A[r2] = A[r2] / A[r1];
  b_A[r3] /= b_A[r1];
  b_A[r2 + 3] -= b_A[r2] * b_A[r1 + 3];
  b_A[r3 + 3] -= b_A[r3] * b_A[r1 + 3];
  b_A[r2 + 6] -= b_A[r2] * b_A[r1 + 6];
  b_A[r3 + 6] -= b_A[r3] * b_A[r1 + 6];
  if (muDoubleScalarAbs(b_A[r3 + 3]) > muDoubleScalarAbs(b_A[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[r3 + 3] /= b_A[r2 + 3];
  b_A[r3 + 6] -= b_A[r3 + 3] * b_A[r2 + 6];
  if ((b_A[r1] == 0.0) || (b_A[r2 + 3] == 0.0) || (b_A[r3 + 6] == 0.0)) {
    d_st.site = &iab_emlrtRSI;
    e_st.site = &wt_emlrtRSI;
    internal::d_warning(&e_st);
  }
  maxval = B[r1];
  a21 = B[r2] - maxval * b_A[r2];
  d = b_A[r3 + 3];
  d1 = b_A[r3 + 6];
  d2 = ((B[r3] - maxval * b_A[r3]) - a21 * d) / d1;
  Y[2] = d2;
  d3 = b_A[r1 + 6];
  maxval -= d2 * d3;
  d4 = b_A[r2 + 6];
  a21 -= d2 * d4;
  d5 = b_A[r2 + 3];
  a21 /= d5;
  Y[1] = a21;
  d6 = b_A[r1 + 3];
  maxval -= a21 * d6;
  maxval /= b_A[r1];
  Y[0] = maxval;
  maxval = B[r1 + 3];
  a21 = B[r2 + 3] - maxval * b_A[r2];
  d2 = ((B[r3 + 3] - maxval * b_A[r3]) - a21 * d) / d1;
  Y[5] = d2;
  maxval -= d2 * d3;
  a21 -= d2 * d4;
  a21 /= d5;
  Y[4] = a21;
  maxval -= a21 * d6;
  maxval /= b_A[r1];
  Y[3] = maxval;
  maxval = B[r1 + 6];
  a21 = B[r2 + 6] - maxval * b_A[r2];
  d2 = ((B[r3 + 6] - maxval * b_A[r3]) - a21 * d) / d1;
  Y[8] = d2;
  maxval -= d2 * d3;
  a21 -= d2 * d4;
  a21 /= d5;
  Y[7] = a21;
  maxval -= a21 * d6;
  maxval /= b_A[r1];
  Y[6] = maxval;
}

void mldivide(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
              const ::coder::array<real_T, 1U> &B,
              ::coder::array<real_T, 1U> &Y)
{
  static const int32_T b_iv[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  array<ptrdiff_t, 1U> IPIV;
  array<real_T, 2U> b_A;
  array<real_T, 1U> b_B;
  array<real_T, 1U> tau;
  array<int32_T, 2U> jpvt;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  char_T str[14];
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (B.size(0) != A.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &oc_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &gy_emlrtRSI;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(0) == 0)) {
    int32_T minmn;
    Y.set_size(&ps_emlrtRTEI, &st, A.size(1));
    minmn = A.size(1);
    for (int32_T maxmn{0}; maxmn < minmn; maxmn++) {
      Y[maxmn] = 0.0;
    }
  } else if (A.size(0) == A.size(1)) {
    ptrdiff_t LDA;
    ptrdiff_t N;
    int32_T maxmn;
    int32_T minmn;
    b_st.site = &hy_emlrtRSI;
    c_st.site = &jy_emlrtRSI;
    d_st.site = &ly_emlrtRSI;
    e_st.site = &my_emlrtRSI;
    b_A.set_size(&ms_emlrtRTEI, &e_st, A.size(0), A.size(1));
    minmn = A.size(0) * A.size(1);
    for (maxmn = 0; maxmn < minmn; maxmn++) {
      b_A[maxmn] = A[maxmn];
    }
    Y.set_size(&ns_emlrtRTEI, &e_st, B.size(0));
    minmn = B.size(0);
    for (maxmn = 0; maxmn < minmn; maxmn++) {
      Y[maxmn] = B[maxmn];
    }
    ptrdiff_t INFO;
    int32_T rankA;
    minmn = b_A.size(0);
    maxmn = b_A.size(1);
    rankA = B.size(0);
    minmn = muIntScalarMin_sint32(minmn, maxmn);
    minmn = muIntScalarMin_sint32(rankA, minmn);
    f_st.site = &fcb_emlrtRSI;
    IPIV.set_size(&os_emlrtRTEI, &f_st, minmn);
    N = (ptrdiff_t)minmn;
    LDA = (ptrdiff_t)b_A.size(0);
    INFO = LAPACKE_dgetrf_work(102, N, N, &(b_A.data())[0], LDA,
                               &(IPIV.data())[0]);
    minmn = (int32_T)INFO;
    g_st.site = &hcb_emlrtRSI;
    if (minmn < 0) {
      if (minmn == -1010) {
        emlrtErrorWithMessageIdR2018a(&g_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &g_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, &cv3[0], 12, minmn);
      }
    }
    LAPACKE_dgetrs_work(102, 'N', N, (ptrdiff_t)1, &(b_A.data())[0], LDA,
                        &(IPIV.data())[0], &(Y.data())[0],
                        (ptrdiff_t)B.size(0));
    if (((A.size(0) != 1) || (A.size(1) != 1)) && (minmn > 0)) {
      d_st.site = &ky_emlrtRSI;
      e_st.site = &wt_emlrtRSI;
      internal::d_warning(&e_st);
    }
  } else {
    real_T tol;
    int32_T maxmn;
    int32_T minmn;
    int32_T rankA;
    b_st.site = &iy_emlrtRSI;
    b_A.set_size(&uj_emlrtRTEI, &b_st, A.size(0), A.size(1));
    minmn = A.size(0) * A.size(1);
    for (maxmn = 0; maxmn < minmn; maxmn++) {
      b_A[maxmn] = A[maxmn];
    }
    c_st.site = &gm_emlrtRSI;
    internal::lapack::xgeqp3(&c_st, b_A, tau, jpvt);
    c_st.site = &eab_emlrtRSI;
    rankA = 0;
    tol = 0.0;
    if (b_A.size(0) < b_A.size(1)) {
      minmn = b_A.size(0);
      maxmn = b_A.size(1);
    } else {
      minmn = b_A.size(1);
      maxmn = b_A.size(0);
    }
    if (minmn > 0) {
      tol = muDoubleScalarMin(1.4901161193847656E-8,
                              2.2204460492503131E-15 *
                                  static_cast<real_T>(maxmn)) *
            muDoubleScalarAbs(b_A[0]);
      while ((rankA < minmn) &&
             (!(muDoubleScalarAbs(b_A[rankA + b_A.size(0) * rankA]) <= tol))) {
        rankA++;
      }
    }
    if (rankA < minmn) {
      d_st.site = &fab_emlrtRSI;
      y = nullptr;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(&d_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = nullptr;
      m = emlrtCreateDoubleScalar(tol);
      emlrtAssign(&b_y, m);
      e_st.site = &beb_emlrtRSI;
      emlrt_marshallIn(&e_st, b_sprintf(&e_st, y, b_y, &c_emlrtMCI),
                       "<output of sprintf>", str);
      d_st.site = &gab_emlrtRSI;
      internal::warning(&d_st, rankA, str);
    }
    b_B.set_size(&ls_emlrtRTEI, &b_st, B.size(0));
    minmn = B.size(0) - 1;
    for (maxmn = 0; maxmn <= minmn; maxmn++) {
      b_B[maxmn] = B[maxmn];
    }
    c_st.site = &im_emlrtRSI;
    internal::LSQFromQR(&c_st, b_A, tau, jpvt, b_B, rankA, Y);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (mldivide.cpp)
