//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qrsolve.cpp
//
// Code generation for function 'qrsolve'
//

// Include files
#include "qrsolve.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "ComputeCamExtrinsics_mex_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "infocheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo jm_emlrtRSI{
    80,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo fn_emlrtRSI{
    189,       // lineNo
    "nnzDiag", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo gn_emlrtRSI{
    119,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo hn_emlrtRSI{
    128,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo in_emlrtRSI{
    135,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo jn_emlrtRSI{
    138,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo kn_emlrtRSI{
    31,         // lineNo
    "xunormqr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" // pathName
};

static emlrtRSInfo ln_emlrtRSI{
    102,              // lineNo
    "ceval_xunormqr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" // pathName
};

static emlrtRTEInfo pj_emlrtRTEI{
    61,        // lineNo
    2,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo qj_emlrtRTEI{
    85,        // lineNo
    26,        // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo rj_emlrtRTEI{
    109,       // lineNo
    1,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo sj_emlrtRTEI{
    119,       // lineNo
    5,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo or_emlrtRTEI{
    1,        // lineNo
    32,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void LSQFromQR(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
               const ::coder::array<real_T, 1U> &tau,
               const ::coder::array<int32_T, 2U> &jpvt,
               ::coder::array<real_T, 1U> &B, int32_T rankA,
               ::coder::array<real_T, 1U> &Y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  Y.set_size(&rj_emlrtRTEI, sp, A.size(1));
  loop_ub = A.size(1);
  for (i = 0; i < loop_ub; i++) {
    Y[i] = 0.0;
  }
  st.site = &gn_emlrtRSI;
  b_st.site = &kn_emlrtRSI;
  if ((A.size(0) != 0) && (A.size(1) != 0) && (B.size(0) != 0)) {
    ptrdiff_t nrc_t;
    nrc_t = (ptrdiff_t)B.size(0);
    i = A.size(0);
    loop_ub = A.size(1);
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1,
                           (ptrdiff_t)muIntScalarMin_sint32(i, loop_ub),
                           &(((::coder::array<real_T, 2U> *)&A)->data())[0],
                           (ptrdiff_t)A.size(0),
                           &(((::coder::array<real_T, 1U> *)&tau)->data())[0],
                           &(B.data())[0], nrc_t);
    c_st.site = &ln_emlrtRSI;
    if (lapack::infocheck(&c_st, (int32_T)nrc_t)) {
      loop_ub = B.size(0);
      B.set_size(&sj_emlrtRTEI, &b_st, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        B[i] = rtNaN;
      }
    }
  }
  st.site = &hn_emlrtRSI;
  if ((1 <= rankA) && (rankA > 2147483646)) {
    b_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (loop_ub = 0; loop_ub < rankA; loop_ub++) {
    Y[jpvt[loop_ub] - 1] = B[loop_ub];
  }
  st.site = &in_emlrtRSI;
  for (int32_T j{rankA}; j >= 1; j--) {
    i = jpvt[j - 1];
    Y[i - 1] = Y[i - 1] / A[(j + A.size(0) * (j - 1)) - 1];
    st.site = &jn_emlrtRSI;
    for (loop_ub = 0; loop_ub <= j - 2; loop_ub++) {
      Y[jpvt[loop_ub] - 1] =
          Y[jpvt[loop_ub] - 1] -
          Y[jpvt[j - 1] - 1] * A[loop_ub + A.size(0) * (j - 1)];
    }
  }
}

void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, real_T Y[8])
{
  static const int32_T b_iv[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  ptrdiff_t jpvt_t[8];
  ptrdiff_t info_t;
  array<real_T, 2U> b_A;
  array<real_T, 1U> b_B;
  array<real_T, 1U> tau;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T tol;
  int32_T jpvt[8];
  int32_T i;
  int32_T j;
  int32_T ma;
  int32_T maxmn;
  int32_T minmana;
  int32_T minmn;
  char_T str[14];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &im_emlrtRSI;
  b_A.set_size(&or_emlrtRTEI, &st, A.size(0), 8);
  maxmn = A.size(0) * 8;
  for (minmn = 0; minmn < maxmn; minmn++) {
    b_A[minmn] = A[minmn];
  }
  minmn = b_A.size(0);
  b_st.site = &lm_emlrtRSI;
  ma = b_A.size(0);
  minmana = muIntScalarMin_sint32(ma, 8);
  tau.set_size(&pr_emlrtRTEI, &b_st, minmana);
  if (b_A.size(0) == 0) {
    tau.set_size(&qr_emlrtRTEI, &b_st, minmana);
    for (minmn = 0; minmn < minmana; minmn++) {
      tau[minmn] = 0.0;
    }
    for (ma = 0; ma < 8; ma++) {
      jpvt[ma] = ma + 1;
    }
  } else {
    boolean_T overflow;
    for (i = 0; i < 8; i++) {
      jpvt_t[i] = (ptrdiff_t)0;
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)b_A.size(0), (ptrdiff_t)8,
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &jpvt_t[0], &(tau.data())[0]);
    c_st.site = &nm_emlrtRSI;
    maxmn = (int32_T)info_t;
    if (maxmn != 0) {
      overflow = true;
      if (maxmn != -4) {
        if (maxmn == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &lb_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &cv2[0], 12, maxmn);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      overflow = ((1 <= minmn) && (minmn > 2147483646));
      for (j = 0; j < 8; j++) {
        c_st.site = &pm_emlrtRSI;
        if (overflow) {
          d_st.site = &ed_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (i = 0; i < minmn; i++) {
          b_A[j * ma + i] = rtNaN;
        }
      }
      minmn = muIntScalarMin_sint32(minmn, 8) - 1;
      c_st.site = &qm_emlrtRSI;
      for (ma = 0; ma <= minmn; ma++) {
        tau[ma] = rtNaN;
      }
      maxmn = minmn + 2;
      c_st.site = &rm_emlrtRSI;
      for (ma = maxmn; ma <= minmana; ma++) {
        tau[ma - 1] = 0.0;
      }
      for (ma = 0; ma < 8; ma++) {
        jpvt[ma] = ma + 1;
      }
    } else {
      for (ma = 0; ma < 8; ma++) {
        jpvt[ma] = (int32_T)jpvt_t[ma];
      }
    }
  }
  st.site = &gab_emlrtRSI;
  ma = 0;
  tol = 0.0;
  if (b_A.size(0) < 8) {
    minmn = b_A.size(0);
    maxmn = 8;
  } else {
    minmn = 8;
    maxmn = b_A.size(0);
  }
  if (minmn > 0) {
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 * static_cast<real_T>(maxmn)) *
        muDoubleScalarAbs(b_A[0]);
    while ((ma < minmn) &&
           (!(muDoubleScalarAbs(b_A[ma + b_A.size(0) * ma]) <= tol))) {
      ma++;
    }
  }
  if (ma < minmn) {
    b_st.site = &hab_emlrtRSI;
    y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 6, m, &rfmt[0]);
    emlrtAssign(&y, m);
    b_y = nullptr;
    m = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m);
    c_st.site = &xdb_emlrtRSI;
    emlrt_marshallIn(&c_st, b_sprintf(&c_st, y, b_y, &c_emlrtMCI),
                     "<output of sprintf>", str);
    b_st.site = &iab_emlrtRSI;
    warning(&b_st, ma, str);
  }
  st.site = &km_emlrtRSI;
  b_B.set_size(&qj_emlrtRTEI, &st, B.size(0));
  maxmn = B.size(0);
  for (minmn = 0; minmn < maxmn; minmn++) {
    b_B[minmn] = B[minmn];
  }
  std::memset(&Y[0], 0, 8U * sizeof(real_T));
  b_st.site = &gn_emlrtRSI;
  c_st.site = &kn_emlrtRSI;
  if ((b_A.size(0) != 0) && (b_B.size(0) != 0)) {
    info_t = (ptrdiff_t)b_B.size(0);
    maxmn = b_A.size(0);
    info_t = LAPACKE_dormqr(102, 'L', 'T', info_t, (ptrdiff_t)1,
                            (ptrdiff_t)muIntScalarMin_sint32(maxmn, 8),
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &(tau.data())[0], &(b_B.data())[0], info_t);
    d_st.site = &ln_emlrtRSI;
    if (lapack::infocheck(&d_st, (int32_T)info_t)) {
      maxmn = b_B.size(0);
      b_B.set_size(&sj_emlrtRTEI, &c_st, maxmn);
      for (minmn = 0; minmn < maxmn; minmn++) {
        b_B[minmn] = rtNaN;
      }
    }
  }
  b_st.site = &hn_emlrtRSI;
  for (i = 0; i < ma; i++) {
    Y[jpvt[i] - 1] = b_B[i];
  }
  b_st.site = &in_emlrtRSI;
  for (j = ma; j >= 1; j--) {
    maxmn = jpvt[j - 1] - 1;
    Y[maxmn] /= b_A[(j + b_A.size(0) * (j - 1)) - 1];
    b_st.site = &jn_emlrtRSI;
    for (i = 0; i <= j - 2; i++) {
      minmn = jpvt[i];
      Y[minmn - 1] -= Y[maxmn] * b_A[i + b_A.size(0) * (j - 1)];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, ::coder::array<real_T, 1U> &Y,
             int32_T *rankA)
{
  array<real_T, 2U> b_A;
  array<real_T, 1U> b_B;
  array<real_T, 1U> tau;
  array<int32_T, 2U> jpvt;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T maxmn;
  int32_T minmn;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  b_A.set_size(&pj_emlrtRTEI, sp, A.size(0), A.size(1));
  minmn = A.size(0) * A.size(1);
  for (k = 0; k < minmn; k++) {
    b_A[k] = A[k];
  }
  st.site = &im_emlrtRSI;
  lapack::xgeqp3(&st, b_A, tau, jpvt);
  *rankA = 0;
  if (b_A.size(0) < b_A.size(1)) {
    minmn = b_A.size(0);
    maxmn = b_A.size(1);
  } else {
    minmn = b_A.size(1);
    maxmn = b_A.size(0);
  }
  if (minmn > 0) {
    real_T tol;
    tol =
        muDoubleScalarMin(1.4901161193847656E-8,
                          2.2204460492503131E-15 * static_cast<real_T>(maxmn)) *
        muDoubleScalarAbs(b_A[0]);
    while ((*rankA < minmn) &&
           (!(muDoubleScalarAbs(b_A[*rankA + b_A.size(0) * *rankA]) <= tol))) {
      (*rankA)++;
    }
  }
  st.site = &jm_emlrtRSI;
  maxmn = 0;
  minmn = b_A.size(0);
  k = b_A.size(1);
  minmn = muIntScalarMin_sint32(minmn, k);
  if (minmn > 0) {
    b_st.site = &fn_emlrtRSI;
    if (minmn > 2147483646) {
      c_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k < minmn; k++) {
      if (b_A[k + b_A.size(0) * k] != 0.0) {
        maxmn++;
      }
    }
  }
  b_B.set_size(&qj_emlrtRTEI, sp, B.size(0));
  minmn = B.size(0) - 1;
  for (k = 0; k <= minmn; k++) {
    b_B[k] = B[k];
  }
  st.site = &km_emlrtRSI;
  LSQFromQR(&st, b_A, tau, jpvt, b_B, maxmn, Y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder

// End of code generation (qrsolve.cpp)
