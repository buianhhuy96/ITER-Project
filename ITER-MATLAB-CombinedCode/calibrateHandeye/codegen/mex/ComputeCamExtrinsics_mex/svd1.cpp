//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd1.cpp
//
// Code generation for function 'svd1'
//

// Include files
#include "svd1.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <algorithm>
#include <cstddef>

// Function Definitions
namespace coder {
namespace internal {
void c_svd(const emlrtStack *sp, const real_T A[81], real_T U[81], real_T s[9],
           real_T V[81])
{
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Vt[81];
  real_T b_A[81];
  real_T superb[8];
  int32_T info;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &iu_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ju_emlrtRSI;
  std::copy(&A[0], &A[81], &b_A[0]);
  info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)9, (ptrdiff_t)9, &b_A[0],
                          (ptrdiff_t)9, &s[0], &U[0], (ptrdiff_t)9, &Vt[0],
                          (ptrdiff_t)9);
  info = (int32_T)info_t;
  c_st.site = &mu_emlrtRSI;
  if (info < 0) {
    if (info == -1010) {
      emlrtErrorWithMessageIdR2018a(&c_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, info);
    }
  }
  if (info > 0) {
    b_st.site = &ku_emlrtRSI;
    c_st.site = &nu_emlrtRSI;
    std::copy(&A[0], &A[81], &b_A[0]);
    info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)9, (ptrdiff_t)9, &b_A[0],
                            (ptrdiff_t)9, &s[0], &U[0], (ptrdiff_t)9, &Vt[0],
                            (ptrdiff_t)9, &superb[0]);
    info = (int32_T)info_t;
    for (int32_T i{0}; i < 9; i++) {
      for (int32_T i1{0}; i1 < 9; i1++) {
        V[i1 + 9 * i] = Vt[i + 9 * i1];
      }
    }
    d_st.site = &pu_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&d_st, &kb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &lb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv[0], 12, info);
      }
    }
  } else {
    for (int32_T i{0}; i < 9; i++) {
      for (int32_T i1{0}; i1 < 9; i1++) {
        V[i1 + 9 * i] = Vt[i + 9 * i1];
      }
    }
  }
  if (info > 0) {
    emlrtErrorWithMessageIdR2018a(&st, &yb_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (svd1.cpp)
