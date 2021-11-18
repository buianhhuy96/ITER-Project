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
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_mexutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "infocheck.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xunormqr.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo dm_emlrtRSI{
    61,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo em_emlrtRSI{
    80,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo fm_emlrtRSI{
    85,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo cn_emlrtRSI{
    189,       // lineNo
    "nnzDiag", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo dn_emlrtRSI{
    119,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo en_emlrtRSI{
    128,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo fn_emlrtRSI{
    135,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo gn_emlrtRSI{
    138,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo dab_emlrtRSI{
    72,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo eab_emlrtRSI{
    173,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRSInfo fab_emlrtRSI{
    172,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

static emlrtRTEInfo rj_emlrtRTEI{
    1,        // lineNo
    32,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

static emlrtRTEInfo sj_emlrtRTEI{
    61,       // lineNo
    9,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

static emlrtRTEInfo wj_emlrtRTEI{
    85,        // lineNo
    1,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo xj_emlrtRTEI{
    119,       // lineNo
    5,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

static emlrtRTEInfo js_emlrtRTEI{
    85,        // lineNo
    26,        // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, real_T Y[8])
{
  static const int32_T iv[2]{1, 6};
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
  st.site = &dm_emlrtRSI;
  b_A.set_size(&rj_emlrtRTEI, &st, A.size(0), 8);
  maxmn = A.size(0) * 8;
  for (minmn = 0; minmn < maxmn; minmn++) {
    b_A[minmn] = A[minmn];
  }
  minmn = b_A.size(0);
  b_st.site = &gm_emlrtRSI;
  ma = b_A.size(0);
  minmana = muIntScalarMin_sint32(ma, 8);
  tau.set_size(&tj_emlrtRTEI, &b_st, minmana);
  if (b_A.size(0) == 0) {
    tau.set_size(&vj_emlrtRTEI, &b_st, minmana);
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
    c_st.site = &im_emlrtRSI;
    maxmn = (int32_T)info_t;
    if (maxmn != 0) {
      overflow = true;
      if (maxmn != -4) {
        if (maxmn == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, maxmn);
        }
      }
    } else {
      overflow = false;
    }
    if (overflow) {
      overflow = ((1 <= minmn) && (minmn > 2147483646));
      for (j = 0; j < 8; j++) {
        c_st.site = &km_emlrtRSI;
        if (overflow) {
          d_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (i = 0; i < minmn; i++) {
          b_A[j * ma + i] = rtNaN;
        }
      }
      minmn = muIntScalarMin_sint32(minmn, 8) - 1;
      c_st.site = &lm_emlrtRSI;
      for (ma = 0; ma <= minmn; ma++) {
        tau[ma] = rtNaN;
      }
      maxmn = minmn + 2;
      c_st.site = &mm_emlrtRSI;
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
  st.site = &dab_emlrtRSI;
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
    b_st.site = &eab_emlrtRSI;
    y = nullptr;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 6, m, &rfmt[0]);
    emlrtAssign(&y, m);
    c_st.site = &tfb_emlrtRSI;
    emlrt_marshallIn(&c_st,
                     b_sprintf(&c_st, y, emlrt_marshallOut(tol), &c_emlrtMCI),
                     "<output of sprintf>", str);
    b_st.site = &fab_emlrtRSI;
    warning(&b_st, ma, str);
  }
  st.site = &fm_emlrtRSI;
  b_B.set_size(&js_emlrtRTEI, &st, B.size(0));
  maxmn = B.size(0);
  for (minmn = 0; minmn < maxmn; minmn++) {
    b_B[minmn] = B[minmn];
  }
  std::memset(&Y[0], 0, 8U * sizeof(real_T));
  b_st.site = &dn_emlrtRSI;
  c_st.site = &hn_emlrtRSI;
  if ((b_A.size(0) != 0) && (b_B.size(0) != 0)) {
    info_t = (ptrdiff_t)b_B.size(0);
    maxmn = b_A.size(0);
    info_t = LAPACKE_dormqr(102, 'L', 'T', info_t, (ptrdiff_t)1,
                            (ptrdiff_t)muIntScalarMin_sint32(maxmn, 8),
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &(tau.data())[0], &(b_B.data())[0], info_t);
    d_st.site = &in_emlrtRSI;
    if (lapack::infocheck(&d_st, (int32_T)info_t)) {
      maxmn = b_B.size(0);
      b_B.set_size(&xj_emlrtRTEI, &c_st, maxmn);
      for (minmn = 0; minmn < maxmn; minmn++) {
        b_B[minmn] = rtNaN;
      }
    }
  }
  b_st.site = &en_emlrtRSI;
  for (i = 0; i < ma; i++) {
    Y[jpvt[i] - 1] = b_B[i];
  }
  b_st.site = &fn_emlrtRSI;
  for (j = ma; j >= 1; j--) {
    maxmn = jpvt[j - 1] - 1;
    Y[maxmn] /= b_A[(j + b_A.size(0) * (j - 1)) - 1];
    b_st.site = &gn_emlrtRSI;
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
  array<ptrdiff_t, 1U> jpvt_t;
  array<real_T, 2U> b_A;
  array<real_T, 1U> b_B;
  array<real_T, 1U> tau;
  array<int32_T, 2U> jpvt;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T b_na;
  int32_T i;
  int32_T j;
  int32_T ma;
  int32_T minmana;
  int32_T minmn;
  int32_T na;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &dm_emlrtRSI;
  b_A.set_size(&rj_emlrtRTEI, &st, A.size(0), A.size(1));
  na = A.size(0) * A.size(1);
  for (i = 0; i < na; i++) {
    b_A[i] = A[i];
  }
  minmn = b_A.size(0);
  b_na = b_A.size(1);
  jpvt.set_size(&sj_emlrtRTEI, &st, 1, b_A.size(1));
  na = b_A.size(1);
  for (i = 0; i < na; i++) {
    jpvt[i] = 0;
  }
  b_st.site = &gm_emlrtRSI;
  ma = b_A.size(0);
  na = b_A.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  tau.set_size(&tj_emlrtRTEI, &b_st, minmana);
  if ((b_A.size(0) == 0) || (b_A.size(1) == 0)) {
    tau.set_size(&vj_emlrtRTEI, &b_st, minmana);
    for (i = 0; i < minmana; i++) {
      tau[i] = 0.0;
    }
    c_st.site = &hm_emlrtRSI;
    if ((1 <= b_A.size(1)) && (b_A.size(1) > 2147483646)) {
      d_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (ma = 0; ma < b_na; ma++) {
      jpvt[ma] = ma + 1;
    }
  } else {
    boolean_T p;
    jpvt_t.set_size(&uj_emlrtRTEI, &b_st, b_A.size(1));
    na = b_A.size(1);
    for (i = 0; i < na; i++) {
      jpvt_t[i] = (ptrdiff_t)0;
    }
    ptrdiff_t info_t;
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)b_A.size(0), (ptrdiff_t)b_A.size(1),
                            &(b_A.data())[0], (ptrdiff_t)b_A.size(0),
                            &(jpvt_t.data())[0], &(tau.data())[0]);
    c_st.site = &im_emlrtRSI;
    na = (int32_T)info_t;
    if (na != 0) {
      p = true;
      if (na != -4) {
        if (na == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, na);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      c_st.site = &jm_emlrtRSI;
      if ((1 <= b_na) && (b_na > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (j = 0; j < b_na; j++) {
        c_st.site = &km_emlrtRSI;
        if ((1 <= minmn) && (minmn > 2147483646)) {
          d_st.site = &yc_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (na = 0; na < minmn; na++) {
          b_A[j * ma + na] = rtNaN;
        }
      }
      minmn = muIntScalarMin_sint32(minmn, b_na);
      c_st.site = &lm_emlrtRSI;
      if ((1 <= minmn) && (minmn > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ma = 0; ma < minmn; ma++) {
        tau[ma] = rtNaN;
      }
      na = minmn + 1;
      c_st.site = &mm_emlrtRSI;
      if ((minmn + 1 <= minmana) && (minmana > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ma = na; ma <= minmana; ma++) {
        tau[ma - 1] = 0.0;
      }
      c_st.site = &nm_emlrtRSI;
      if ((1 <= b_na) && (b_na > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ma = 0; ma < b_na; ma++) {
        jpvt[ma] = ma + 1;
      }
    } else {
      c_st.site = &om_emlrtRSI;
      if ((1 <= b_na) && (b_na > 2147483646)) {
        d_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (ma = 0; ma < b_na; ma++) {
        jpvt[ma] = (int32_T)jpvt_t[ma];
      }
    }
  }
  *rankA = 0;
  if (b_A.size(0) < b_A.size(1)) {
    minmn = b_A.size(0);
    na = b_A.size(1);
  } else {
    minmn = b_A.size(1);
    na = b_A.size(0);
  }
  if (minmn > 0) {
    real_T tol;
    tol = muDoubleScalarMin(1.4901161193847656E-8,
                            2.2204460492503131E-15 * static_cast<real_T>(na)) *
          muDoubleScalarAbs(b_A[0]);
    while ((*rankA < minmn) &&
           (!(muDoubleScalarAbs(b_A[*rankA + b_A.size(0) * *rankA]) <= tol))) {
      (*rankA)++;
    }
  }
  st.site = &em_emlrtRSI;
  minmn = 0;
  i = b_A.size(0);
  b_na = b_A.size(1);
  na = muIntScalarMin_sint32(i, b_na);
  if (na > 0) {
    b_st.site = &cn_emlrtRSI;
    if (na > 2147483646) {
      c_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ma = 0; ma < na; ma++) {
      if (b_A[ma + b_A.size(0) * ma] != 0.0) {
        minmn++;
      }
    }
  }
  st.site = &fm_emlrtRSI;
  Y.set_size(&wj_emlrtRTEI, &st, b_A.size(1));
  na = b_A.size(1);
  for (i = 0; i < na; i++) {
    Y[i] = 0.0;
  }
  b_B.set_size(&xj_emlrtRTEI, &st, B.size(0));
  na = B.size(0);
  for (i = 0; i < na; i++) {
    b_B[i] = B[i];
  }
  b_st.site = &dn_emlrtRSI;
  lapack::xunormqr(&b_st, b_A, b_B, tau);
  b_st.site = &en_emlrtRSI;
  if ((1 <= minmn) && (minmn > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (na = 0; na < minmn; na++) {
    Y[jpvt[na] - 1] = b_B[na];
  }
  b_st.site = &fn_emlrtRSI;
  for (j = minmn; j >= 1; j--) {
    i = jpvt[j - 1];
    Y[i - 1] = Y[i - 1] / b_A[(j + b_A.size(0) * (j - 1)) - 1];
    b_st.site = &gn_emlrtRSI;
    for (na = 0; na <= j - 2; na++) {
      Y[jpvt[na] - 1] = Y[jpvt[na] - 1] -
                        Y[jpvt[j - 1] - 1] * b_A[na + b_A.size(0) * (j - 1)];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder

// End of code generation (qrsolve.cpp)
