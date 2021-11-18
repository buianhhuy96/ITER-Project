//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.cpp
//
// Code generation for function 'svd'
//

// Include files
#include "svd.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "xzsvdc.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo gu_emlrtRSI{
    36,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo nu_emlrtRSI{
    34,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

static emlrtRSInfo sab_emlrtRSI{
    42,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo tab_emlrtRSI{
    43,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo uab_emlrtRSI{
    44,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRSInfo vab_emlrtRSI{
    51,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

static emlrtRTEInfo rs_emlrtRTEI{
    41,    // lineNo
    14,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo ss_emlrtRTEI{
    43,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo ts_emlrtRTEI{
    44,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo us_emlrtRTEI{
    49,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

// Function Definitions
namespace coder {
void b_svd(const emlrtStack *sp, const real_T A[81], real_T U[81], real_T S[81],
           real_T V[81])
{
  array<real_T, 2U> b_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T U1[81];
  real_T V1[81];
  real_T b_dv[81];
  real_T s[9];
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cy_emlrtRSI;
  b_A.set((real_T *)&A[0], 9, 9);
  c_st.site = &dy_emlrtRSI;
  nx = b_A.size(0) * b_A.size(1);
  p = true;
  d_st.site = &vd_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    e_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(b_A[k]) || muDoubleScalarIsNaN(b_A[k]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &gu_emlrtRSI;
    internal::c_svd(&st, A, U, s, V);
  } else {
    std::memset(&b_dv[0], 0, 81U * sizeof(real_T));
    st.site = &sab_emlrtRSI;
    internal::c_svd(&st, b_dv, U1, s, V1);
    for (nx = 0; nx < 81; nx++) {
      U[nx] = rtNaN;
    }
    for (nx = 0; nx < 9; nx++) {
      s[nx] = rtNaN;
    }
    for (nx = 0; nx < 81; nx++) {
      V[nx] = rtNaN;
    }
  }
  std::memset(&S[0], 0, 81U * sizeof(real_T));
  for (k = 0; k < 9; k++) {
    S[k + 9 * k] = s[k];
  }
}

void svd(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
         ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 2U> &S,
         real_T V[36])
{
  array<real_T, 2U> U1;
  array<real_T, 2U> r;
  array<real_T, 1U> s;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T V1[36];
  int32_T k;
  int32_T nx;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &yx_emlrtRSI;
  b_st.site = &cy_emlrtRSI;
  c_st.site = &dy_emlrtRSI;
  nx = A.size(0) * 6;
  p = true;
  d_st.site = &vd_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    e_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &gu_emlrtRSI;
    internal::c_svd(&st, A, U, s, V);
  } else {
    r.set_size(&rs_emlrtRTEI, sp, A.size(0), 6);
    nx = A.size(0) * 6;
    for (k = 0; k < nx; k++) {
      r[k] = 0.0;
    }
    st.site = &sab_emlrtRSI;
    internal::c_svd(&st, r, U1, s, V1);
    st.site = &tab_emlrtRSI;
    U.set_size(&ss_emlrtRTEI, &st, U1.size(0), U1.size(1));
    nx = U1.size(0) * U1.size(1);
    for (k = 0; k < nx; k++) {
      U[k] = rtNaN;
    }
    st.site = &uab_emlrtRSI;
    nx = s.size(0);
    s.set_size(&ts_emlrtRTEI, &st, nx);
    for (k = 0; k < nx; k++) {
      s[k] = rtNaN;
    }
    for (k = 0; k < 36; k++) {
      V[k] = rtNaN;
    }
  }
  S.set_size(&us_emlrtRTEI, sp, U.size(1), 6);
  nx = U.size(1) * 6;
  for (k = 0; k < nx; k++) {
    S[k] = 0.0;
  }
  nx = s.size(0) - 1;
  st.site = &vab_emlrtRSI;
  for (k = 0; k <= nx; k++) {
    S[k + S.size(0) * k] = s[k];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void svd(const emlrtStack *sp, real_T U[841], real_T S[841], real_T V[841])
{
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T A[841];
  real_T Vt[841];
  real_T b_S[29];
  real_T superb[28];
  int32_T info;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gu_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hu_emlrtRSI;
  c_st.site = &iu_emlrtRSI;
  std::copy(&dv[0], &dv[841], &A[0]);
  info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)29, (ptrdiff_t)29, &A[0],
                          (ptrdiff_t)29, &b_S[0], &U[0], (ptrdiff_t)29, &Vt[0],
                          (ptrdiff_t)29);
  info = (int32_T)info_t;
  d_st.site = &lu_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, info);
    }
  }
  if (info > 0) {
    c_st.site = &ju_emlrtRSI;
    d_st.site = &mu_emlrtRSI;
    std::copy(&dv[0], &dv[841], &A[0]);
    info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)29, (ptrdiff_t)29, &A[0],
                            (ptrdiff_t)29, &b_S[0], &U[0], (ptrdiff_t)29,
                            &Vt[0], (ptrdiff_t)29, &superb[0]);
    info = (int32_T)info_t;
    for (int32_T i{0}; i < 29; i++) {
      for (int32_T i1{0}; i1 < 29; i1++) {
        V[i1 + 29 * i] = Vt[i + 29 * i1];
      }
    }
    e_st.site = &ou_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, info);
      }
    }
  } else {
    for (int32_T i{0}; i < 29; i++) {
      for (int32_T i1{0}; i1 < 29; i1++) {
        V[i1 + 29 * i] = Vt[i + 29 * i1];
      }
    }
  }
  if (info > 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &vb_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
  std::memset(&S[0], 0, 841U * sizeof(real_T));
  for (info = 0; info < 29; info++) {
    S[info + 29 * info] = b_S[info];
  }
}

void svd(const emlrtStack *sp, const real_T A[9], real_T U[9], real_T S[9],
         real_T V[9])
{
  array<real_T, 2U> b_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T c_A[9];
  real_T s[3];
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yx_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cy_emlrtRSI;
  b_A.set((real_T *)&A[0], 3, 3);
  c_st.site = &dy_emlrtRSI;
  nx = b_A.size(0) * b_A.size(1);
  p = true;
  d_st.site = &vd_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    e_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(b_A[k]) || muDoubleScalarIsNaN(b_A[k]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &gu_emlrtRSI;
    b_st.site = &hu_emlrtRSI;
    c_st.site = &ku_emlrtRSI;
    std::copy(&A[0], &A[9], &c_A[0]);
    d_st.site = &nu_emlrtRSI;
    internal::reflapack::xzsvdc(&d_st, c_A, U, s, V);
  } else {
    st.site = &sab_emlrtRSI;
    b_st.site = &hu_emlrtRSI;
    c_st.site = &ku_emlrtRSI;
    std::memset(&c_A[0], 0, 9U * sizeof(real_T));
    d_st.site = &nu_emlrtRSI;
    internal::reflapack::xzsvdc(&d_st, c_A, U, s, V);
    s[0] = rtNaN;
    s[1] = rtNaN;
    s[2] = rtNaN;
    for (nx = 0; nx < 9; nx++) {
      U[nx] = rtNaN;
      V[nx] = rtNaN;
    }
  }
  std::memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

} // namespace coder

// End of code generation (svd.cpp)
