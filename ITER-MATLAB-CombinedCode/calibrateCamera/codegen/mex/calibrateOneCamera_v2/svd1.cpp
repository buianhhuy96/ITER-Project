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
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRTEInfo os_emlrtRTEI{
    73,    // lineNo
    63,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo ps_emlrtRTEI{
    45,       // lineNo
    24,       // colNo
    "xgesdd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" // pName
};

static emlrtRTEInfo qs_emlrtRTEI{
    57,       // lineNo
    20,       // colNo
    "xgesdd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" // pName
};

static emlrtRTEInfo rs_emlrtRTEI{
    75,       // lineNo
    24,       // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void b_svd(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
           ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 1U> &s,
           real_T V[36])
{
  ptrdiff_t info_t;
  array<real_T, 2U> b_A;
  array<real_T, 1U> superb;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Vt[36];
  int32_T i;
  int32_T loop_ub;
  int32_T m;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &hu_emlrtRSI;
  m = A.size(0);
  b_st.site = &iu_emlrtRSI;
  b_A.set_size(&os_emlrtRTEI, &b_st, A.size(0), 6);
  loop_ub = A.size(0) * 6;
  for (i = 0; i < loop_ub; i++) {
    b_A[i] = A[i];
  }
  U.set_size(&ps_emlrtRTEI, &b_st, A.size(0), A.size(0));
  s.set_size(&qs_emlrtRTEI, &b_st, muIntScalarMin_sint32(6, m));
  if (A.size(0) != 0) {
    info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)A.size(0), (ptrdiff_t)6,
                            &(b_A.data())[0], (ptrdiff_t)A.size(0),
                            &(s.data())[0], &(U.data())[0],
                            (ptrdiff_t)A.size(0), &Vt[0], (ptrdiff_t)6);
    m = (int32_T)info_t;
    c_st.site = &lu_emlrtRSI;
    if (m < 0) {
      if (m == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv2[0], 12, m);
      }
    }
  } else {
    m = 0;
  }
  if (m > 0) {
    b_st.site = &ju_emlrtRSI;
    c_st.site = &mu_emlrtRSI;
    b_A.set_size(&fs_emlrtRTEI, &c_st, A.size(0), 6);
    loop_ub = A.size(0) * 6;
    for (i = 0; i < loop_ub; i++) {
      b_A[i] = A[i];
    }
    m = A.size(0);
    m = muIntScalarMin_sint32(6, m);
    U.set_size(&rs_emlrtRTEI, &c_st, A.size(0), A.size(0));
    s.set_size(&gs_emlrtRTEI, &c_st, m);
    if (A.size(0) != 0) {
      if (m > 1) {
        superb.set_size(&is_emlrtRTEI, &c_st, m - 1);
      } else {
        superb.set_size(&hs_emlrtRTEI, &c_st, 1);
      }
      info_t = LAPACKE_dgesvd(
          102, 'A', 'A', (ptrdiff_t)A.size(0), (ptrdiff_t)6, &(b_A.data())[0],
          (ptrdiff_t)A.size(0), &(s.data())[0], &(U.data())[0],
          (ptrdiff_t)A.size(0), &Vt[0], (ptrdiff_t)6, &(superb.data())[0]);
      m = (int32_T)info_t;
    } else {
      m = 0;
    }
    for (i = 0; i < 6; i++) {
      for (loop_ub = 0; loop_ub < 6; loop_ub++) {
        V[loop_ub + 6 * i] = Vt[i + 6 * loop_ub];
      }
    }
    d_st.site = &ou_emlrtRSI;
    if (m < 0) {
      if (m == -1010) {
        emlrtErrorWithMessageIdR2018a(&d_st, &ib_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &jb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, m);
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      for (loop_ub = 0; loop_ub < 6; loop_ub++) {
        V[loop_ub + 6 * i] = Vt[i + 6 * loop_ub];
      }
    }
  }
  if (m > 0) {
    emlrtErrorWithMessageIdR2018a(&st, &vb_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder

// End of code generation (svd1.cpp)
