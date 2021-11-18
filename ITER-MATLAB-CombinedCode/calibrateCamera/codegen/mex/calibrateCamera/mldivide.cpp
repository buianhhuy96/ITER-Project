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
#include "calibrateCamera_data.h"
#include "calibrateCamera_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "infocheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo tr_emlrtRSI{
    90,              // lineNo
    "warn_singular", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ku_emlrtRSI{
    20,         // lineNo
    "mldivide", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo lu_emlrtRSI{
    42,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo mu_emlrtRSI{
    44,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

static emlrtRSInfo nu_emlrtRSI{
    67,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ou_emlrtRSI{
    112,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo pu_emlrtRSI{
    109,          // lineNo
    "lusolveNxN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo qu_emlrtRSI{
    124,          // lineNo
    "InvAtimesX", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo ru_emlrtRSI{
    26,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo su_emlrtRSI{
    27,        // lineNo
    "xgetrfs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" // pathName
};

static emlrtRSInfo tu_emlrtRSI{
    27,       // lineNo
    "xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo uu_emlrtRSI{
    91,             // lineNo
    "ceval_xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

static emlrtRSInfo wu_emlrtRSI{
    18,       // lineNo
    "xgetrs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrs.m" // pathName
};

static emlrtRSInfo bv_emlrtRSI{
    72,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo cv_emlrtRSI{
    173,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo dv_emlrtRSI{
    172,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo ev_emlrtRSI{
    61,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo fv_emlrtRSI{
    293,          // lineNo
    "lusolve3x3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRTEInfo fc_emlrtRTEI{
    16,         // lineNo
    19,         // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

static emlrtRTEInfo qs_emlrtRTEI{
    20,         // lineNo
    5,          // colNo
    "mldivide", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void mldivide(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
              ::coder::array<real_T, 1U> &B)
{
  static const int32_T iv[2]{1, 6};
  static const char_T fname[19]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 't', 'r', 'f',
                                '_', 'w', 'o', 'r', 'k'};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  ptrdiff_t jpvt_t[8];
  ::coder::array<real_T, 2U> b_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T A_data[64];
  real_T Y[8];
  real_T tau_data[8];
  int32_T jpvt[8];
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (B.size(0) != A.size(0)) {
    emlrtErrorWithMessageIdR2018a(sp, &fc_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &ku_emlrtRSI;
  if ((A.size(0) == 0) || (B.size(0) == 0)) {
    B.set_size(&qs_emlrtRTEI, &st, 8);
    for (int32_T ma{0}; ma < 8; ma++) {
      B[ma] = 0.0;
    }
  } else if (A.size(0) == 8) {
    int32_T i;
    int32_T k;
    int32_T ma;
    int32_T maxmn;
    int32_T rankA;
    b_st.site = &lu_emlrtRSI;
    for (ma = 0; ma < 64; ma++) {
      A_data[ma] = A[ma];
    }
    ptrdiff_t info_t;
    c_st.site = &nu_emlrtRSI;
    d_st.site = &pu_emlrtRSI;
    e_st.site = &qu_emlrtRSI;
    f_st.site = &ru_emlrtRSI;
    g_st.site = &tu_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)8, (ptrdiff_t)8, &A_data[0],
                                 (ptrdiff_t)8, &jpvt_t[0]);
    rankA = (int32_T)info_t;
    h_st.site = &uu_emlrtRSI;
    if (rankA < 0) {
      if (rankA == -1010) {
        emlrtErrorWithMessageIdR2018a(&h_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&h_st, &gb_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &fname[0], 12, rankA);
      }
    }
    for (k = 0; k < 8; k++) {
      jpvt[k] = (int32_T)jpvt_t[k];
    }
    f_st.site = &su_emlrtRSI;
    g_st.site = &wu_emlrtRSI;
    for (i = 0; i < 7; i++) {
      ma = jpvt[i];
      if (ma != i + 1) {
        real_T tol;
        tol = B[i];
        B[i] = B[ma - 1];
        B[ma - 1] = tol;
      }
    }
    for (k = 0; k < 8; k++) {
      maxmn = k << 3;
      if (B[k] != 0.0) {
        ma = k + 2;
        for (i = ma; i < 9; i++) {
          B[i - 1] = B[i - 1] - B[k] * A_data[(i + maxmn) - 1];
        }
      }
    }
    for (k = 7; k >= 0; k--) {
      maxmn = k << 3;
      if (B[k] != 0.0) {
        B[k] = B[k] / A_data[k + maxmn];
        for (i = 0; i < k; i++) {
          B[i] = B[i] - B[k] * A_data[i + maxmn];
        }
      }
    }
    if (rankA > 0) {
      d_st.site = &ou_emlrtRSI;
      if (!emlrtSetWarningFlag(&d_st)) {
        e_st.site = &tr_emlrtRSI;
        internal::warning(&e_st);
      }
    }
  } else {
    ptrdiff_t info_t;
    real_T tol;
    int32_T i;
    int32_T k;
    int32_T ma;
    int32_T maxmn;
    int32_T minmana;
    int32_T rankA;
    boolean_T overflow;
    b_st.site = &mu_emlrtRSI;
    c_st.site = &yk_emlrtRSI;
    b_A.set_size(&cj_emlrtRTEI, &c_st, A.size(0), 8);
    maxmn = A.size(0) * 8;
    for (ma = 0; ma < maxmn; ma++) {
      b_A[ma] = A[ma];
    }
    maxmn = b_A.size(0);
    d_st.site = &cl_emlrtRSI;
    ma = b_A.size(0);
    minmana = muIntScalarMin_sint32(ma, 8);
    for (i = 0; i < 8; i++) {
      jpvt_t[i] = (ptrdiff_t)0;
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)b_A.size(0), (ptrdiff_t)8,
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &jpvt_t[0], &tau_data[0]);
    e_st.site = &jl_emlrtRSI;
    rankA = (int32_T)info_t;
    if (rankA != 0) {
      overflow = true;
      if (rankA != -4) {
        if (rankA == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, rankA);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      overflow = (maxmn > 2147483646);
      for (k = 0; k < 8; k++) {
        e_st.site = &hl_emlrtRSI;
        if (overflow) {
          f_st.site = &qc_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
        for (i = 0; i < maxmn; i++) {
          b_A[k * ma + i] = rtNaN;
        }
      }
      ma = muIntScalarMin_sint32(maxmn, 8) - 1;
      e_st.site = &gl_emlrtRSI;
      for (k = 0; k <= ma; k++) {
        tau_data[k] = rtNaN;
      }
      maxmn = ma + 2;
      e_st.site = &fl_emlrtRSI;
      if (maxmn <= minmana) {
        std::memset(&tau_data[maxmn + -1], 0,
                    ((minmana - maxmn) + 1) * sizeof(real_T));
      }
      for (k = 0; k < 8; k++) {
        jpvt[k] = k + 1;
      }
    } else {
      for (k = 0; k < 8; k++) {
        jpvt[k] = (int32_T)jpvt_t[k];
      }
    }
    c_st.site = &bv_emlrtRSI;
    rankA = 0;
    if (b_A.size(0) < 8) {
      ma = b_A.size(0);
      maxmn = 8;
    } else {
      ma = 8;
      maxmn = b_A.size(0);
    }
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 * static_cast<real_T>(maxmn)) *
        muDoubleScalarAbs(b_A[0]);
    while ((rankA < ma) &&
           (!(muDoubleScalarAbs(b_A[rankA + b_A.size(0) * rankA]) <= tol))) {
      rankA++;
    }
    if ((rankA < ma) && (!emlrtSetWarningFlag(&c_st))) {
      d_st.site = &cv_emlrtRSI;
      y = nullptr;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&d_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = nullptr;
      m = emlrtCreateDoubleScalar(tol);
      emlrtAssign(&b_y, m);
      e_st.site = &sab_emlrtRSI;
      e_emlrt_marshallIn(&e_st, b_sprintf(&e_st, y, b_y, &c_emlrtMCI),
                         "<output of sprintf>", str);
      d_st.site = &dv_emlrtRSI;
      internal::warning(&d_st, rankA, str);
    }
    c_st.site = &bl_emlrtRSI;
    std::memset(&Y[0], 0, 8U * sizeof(real_T));
    d_st.site = &xl_emlrtRSI;
    e_st.site = &bm_emlrtRSI;
    info_t = (ptrdiff_t)B.size(0);
    maxmn = b_A.size(0);
    info_t = LAPACKE_dormqr(102, 'L', 'T', info_t, (ptrdiff_t)1,
                            (ptrdiff_t)muIntScalarMin_sint32(maxmn, 8),
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &tau_data[0], &(B.data())[0], info_t);
    f_st.site = &cm_emlrtRSI;
    if (internal::lapack::infocheck(&f_st, (int32_T)info_t)) {
      maxmn = B.size(0);
      B.set_size(&fj_emlrtRTEI, &e_st, maxmn);
      for (ma = 0; ma < maxmn; ma++) {
        B[ma] = rtNaN;
      }
    }
    d_st.site = &yl_emlrtRSI;
    for (i = 0; i < rankA; i++) {
      Y[jpvt[i] - 1] = B[i];
    }
    for (k = rankA; k >= 1; k--) {
      maxmn = jpvt[k - 1] - 1;
      Y[maxmn] /= b_A[(k + b_A.size(0) * (k - 1)) - 1];
      d_st.site = &am_emlrtRSI;
      for (i = 0; i <= k - 2; i++) {
        ma = jpvt[i];
        Y[ma - 1] -= Y[maxmn] * b_A[i + b_A.size(0) * (k - 1)];
      }
    }
    B.set_size(&qs_emlrtRTEI, &st, 8);
    for (ma = 0; ma < 8; ma++) {
      B[ma] = Y[ma];
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
  st.site = &ku_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &lu_emlrtRSI;
  c_st.site = &ev_emlrtRSI;
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
    d_st.site = &fv_emlrtRSI;
    if (!emlrtSetWarningFlag(&d_st)) {
      e_st.site = &tr_emlrtRSI;
      internal::warning(&e_st);
    }
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
} // namespace Codegen

// End of code generation (mldivide.cpp)
