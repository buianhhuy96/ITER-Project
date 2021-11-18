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
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRTEInfo eq_emlrtRTEI{
    41,    // lineNo
    14,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo fq_emlrtRTEI{
    43,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

static emlrtRTEInfo gq_emlrtRTEI{
    49,    // lineNo
    9,     // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pName
};

// Function Definitions
namespace Codegen {
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
  st.site = &es_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &fs_emlrtRSI;
  c_st.site = &hs_emlrtRSI;
  std::copy(&dv[0], &dv[841], &A[0]);
  info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)29, (ptrdiff_t)29, &A[0],
                          (ptrdiff_t)29, &b_S[0], &U[0], (ptrdiff_t)29, &Vt[0],
                          (ptrdiff_t)29);
  info = (int32_T)info_t;
  d_st.site = &is_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(&d_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv2[0], 12, info);
    }
  }
  if (info > 0) {
    c_st.site = &gs_emlrtRSI;
    std::copy(&dv[0], &dv[841], &A[0]);
    d_st.site = &js_emlrtRSI;
    info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)29, (ptrdiff_t)29, &A[0],
                            (ptrdiff_t)29, &b_S[0], &U[0], (ptrdiff_t)29,
                            &Vt[0], (ptrdiff_t)29, &superb[0]);
    info = (int32_T)info_t;
    for (int32_T i{0}; i < 29; i++) {
      for (int32_T i1{0}; i1 < 29; i1++) {
        V[i1 + 29 * i] = Vt[i + 29 * i1];
      }
    }
    e_st.site = &ks_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, info);
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
    emlrtErrorWithMessageIdR2018a(&b_st, &sb_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
  std::memset(&S[0], 0, 841U * sizeof(real_T));
  for (info = 0; info < 29; info++) {
    S[info + 29 * info] = b_S[info];
  }
}

void svd(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
         ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 2U> &S,
         real_T V[36])
{
  ::coder::array<real_T, 2U> U1;
  ::coder::array<real_T, 2U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T V1[36];
  real_T s_data[6];
  int32_T i;
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
  st.site = &eu_emlrtRSI;
  b_st.site = &gu_emlrtRSI;
  c_st.site = &hu_emlrtRSI;
  nx = A.size(0) * 6;
  p = true;
  d_st.site = &jd_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    e_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(A[k]) || muDoubleScalarIsNaN(A[k]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &es_emlrtRSI;
    internal::b_svd(&st, A, U, s_data, &k, V);
  } else {
    r.set_size(&eq_emlrtRTEI, sp, A.size(0), 6);
    nx = A.size(0) * 6;
    for (i = 0; i < nx; i++) {
      r[i] = 0.0;
    }
    st.site = &sv_emlrtRSI;
    internal::b_svd(&st, r, U1, s_data, &k, V1);
    U.set_size(&fq_emlrtRTEI, sp, U1.size(0), U1.size(1));
    nx = U1.size(0) * U1.size(1);
    for (i = 0; i < nx; i++) {
      U[i] = rtNaN;
    }
    for (i = 0; i < k; i++) {
      s_data[i] = rtNaN;
    }
    for (i = 0; i < 36; i++) {
      V[i] = rtNaN;
    }
  }
  S.set_size(&gq_emlrtRTEI, sp, U.size(1), 6);
  nx = U.size(1) * 6;
  for (i = 0; i < nx; i++) {
    S[i] = 0.0;
  }
  i = k - 1;
  for (k = 0; k <= i; k++) {
    S[k + S.size(0) * k] = s_data[k];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (svd.cpp)
