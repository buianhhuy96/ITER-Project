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
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo qu_emlrtRSI{
    34,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

// Function Definitions
namespace coder {
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
  st.site = &ju_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &ku_emlrtRSI;
  c_st.site = &lu_emlrtRSI;
  std::copy(&dv[0], &dv[841], &A[0]);
  info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)29, (ptrdiff_t)29, &A[0],
                          (ptrdiff_t)29, &b_S[0], &U[0], (ptrdiff_t)29, &Vt[0],
                          (ptrdiff_t)29);
  info = (int32_T)info_t;
  d_st.site = &ou_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, info);
    }
  }
  if (info > 0) {
    c_st.site = &mu_emlrtRSI;
    d_st.site = &pu_emlrtRSI;
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
    e_st.site = &ru_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
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
    emlrtErrorWithMessageIdR2018a(&b_st, &yb_emlrtRTEI,
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
  st.site = &cy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &fy_emlrtRSI;
  b_A.set((real_T *)&A[0], 3, 3);
  c_st.site = &gy_emlrtRSI;
  nx = b_A.size(0) * b_A.size(1);
  p = true;
  d_st.site = &ae_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    e_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(b_A[k]) || muDoubleScalarIsNaN(b_A[k]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &ju_emlrtRSI;
    b_st.site = &ku_emlrtRSI;
    c_st.site = &nu_emlrtRSI;
    std::copy(&A[0], &A[9], &c_A[0]);
    d_st.site = &qu_emlrtRSI;
    internal::reflapack::xzsvdc(&d_st, c_A, U, s, V);
  } else {
    st.site = &sab_emlrtRSI;
    b_st.site = &ku_emlrtRSI;
    c_st.site = &nu_emlrtRSI;
    std::memset(&c_A[0], 0, 9U * sizeof(real_T));
    d_st.site = &qu_emlrtRSI;
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
