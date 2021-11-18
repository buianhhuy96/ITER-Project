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
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "blas.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>

// Variable Definitions
static emlrtRSInfo yt_emlrtRSI{
    90,              // lineNo
    "warn_singular", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo jy_emlrtRSI{
    42,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo ly_emlrtRSI{
    67,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo my_emlrtRSI{
    112,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ny_emlrtRSI{
    109,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo oy_emlrtRSI{
    124,          // lineNo
    "InvAtimesX", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo py_emlrtRSI{
    26,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo qy_emlrtRSI{
    27,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo ry_emlrtRSI{
    27,       // lineNo
    "xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo ty_emlrtRSI{
    91,             // lineNo
    "ceval_xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo aab_emlrtRSI{
    18,       // lineNo
    "xgetrs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrs.m" // pathName
};

static emlrtRSInfo jab_emlrtRSI{
    61,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo kab_emlrtRSI{
    293,          // lineNo
    "lusolve3x3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRTEInfo pc_emlrtRTEI{
    16,         // lineNo
    19,         // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo gw_emlrtRTEI{
    20,         // lineNo
    5,          // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo hw_emlrtRTEI{
    1,        // lineNo
    37,       // colNo
    "xgetrf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pName
};

static emlrtRTEInfo iw_emlrtRTEI{
    89,       // lineNo
    27,       // colNo
    "xgetrf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pName
};

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
  st.site = &iy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jy_emlrtRSI;
  c_st.site = &jab_emlrtRSI;
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
    d_st.site = &kab_emlrtRSI;
    e_st.site = &yt_emlrtRSI;
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
  static const char_T fname[19]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 't', 'r', 'f',
                                '_', 'w', 'o', 'r', 'k'};
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
    emlrtErrorWithMessageIdR2018a(sp, &pc_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &iy_emlrtRSI;
  if ((A.size(0) == 0) || (B.size(0) == 0)) {
    B.set_size(&gw_emlrtRTEI, &st, 8);
    for (int32_T kAcol{0}; kAcol < 8; kAcol++) {
      B[kAcol] = 0.0;
    }
  } else if (A.size(0) == 8) {
    int32_T i;
    int32_T info;
    int32_T k;
    int32_T kAcol;
    b_st.site = &jy_emlrtRSI;
    c_st.site = &ly_emlrtRSI;
    d_st.site = &ny_emlrtRSI;
    e_st.site = &oy_emlrtRSI;
    f_st.site = &py_emlrtRSI;
    b_A.set_size(&hw_emlrtRTEI, &f_st, 8, 8);
    for (kAcol = 0; kAcol < 64; kAcol++) {
      b_A[kAcol] = A[kAcol];
    }
    ptrdiff_t info_t;
    g_st.site = &ry_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)8, (ptrdiff_t)8,
                                 &(b_A.data())[0], (ptrdiff_t)8, &ipiv_t[0]);
    info = (int32_T)info_t;
    ipiv.set_size(&iw_emlrtRTEI, &g_st, 1, 8);
    h_st.site = &ty_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&h_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &h_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, &fname[0], 12, info);
      }
    }
    for (k = 0; k < 8; k++) {
      ipiv[k] = (int32_T)ipiv_t[k];
    }
    f_st.site = &qy_emlrtRSI;
    g_st.site = &aab_emlrtRSI;
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
      d_st.site = &my_emlrtRSI;
      e_st.site = &yt_emlrtRSI;
      internal::d_warning(&e_st);
    }
  } else {
    b_st.site = &ky_emlrtRSI;
    internal::qrsolve(&b_st, A, B, b_dv);
    B.set_size(&gw_emlrtRTEI, &st, 8);
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
  st.site = &iy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jy_emlrtRSI;
  c_st.site = &jab_emlrtRSI;
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
    d_st.site = &kab_emlrtRSI;
    e_st.site = &yt_emlrtRSI;
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

} // namespace coder

// End of code generation (mldivide.cpp)
