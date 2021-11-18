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
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRTEInfo hq_emlrtRTEI{
    49,    // lineNo
    33,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo iq_emlrtRTEI{
    73,    // lineNo
    63,    // colNo
    "svd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo jq_emlrtRTEI{
    45,       // lineNo
    24,       // colNo
    "xgesdd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" // pName
};

static emlrtRTEInfo kq_emlrtRTEI{
    75,       // lineNo
    24,       // colNo
    "xgesvd", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
void b_svd(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
           ::coder::array<real_T, 2U> &U, real_T s_data[], int32_T *s_size,
           real_T V[36])
{
  ptrdiff_t info_t;
  ::coder::array<real_T, 2U> b_A;
  ::coder::array<real_T, 2U> c_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Vt[36];
  real_T superb_data[5];
  int32_T i;
  int32_T info;
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
  st.site = &fs_emlrtRSI;
  b_A.set_size(&hq_emlrtRTEI, &st, A.size(0), 6);
  info = A.size(0) * 6;
  for (i = 0; i < info; i++) {
    b_A[i] = A[i];
  }
  m = A.size(0);
  b_st.site = &hs_emlrtRSI;
  c_A.set_size(&iq_emlrtRTEI, &b_st, A.size(0), 6);
  info = A.size(0) * 6;
  for (i = 0; i < info; i++) {
    c_A[i] = A[i];
  }
  U.set_size(&jq_emlrtRTEI, &b_st, A.size(0), A.size(0));
  *s_size = muIntScalarMin_sint32(6, m);
  if (A.size(0) != 0) {
    info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)A.size(0), (ptrdiff_t)6,
                            &(c_A.data())[0], (ptrdiff_t)A.size(0), &s_data[0],
                            &(U.data())[0], (ptrdiff_t)A.size(0), &Vt[0],
                            (ptrdiff_t)6);
    info = (int32_T)info_t;
    c_st.site = &is_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv2[0], 12, info);
      }
    }
  } else {
    info = 0;
  }
  if (info > 0) {
    b_st.site = &gs_emlrtRSI;
    c_st.site = &js_emlrtRSI;
    m = A.size(0);
    info = muIntScalarMin_sint32(6, m);
    U.set_size(&kq_emlrtRTEI, &c_st, A.size(0), A.size(0));
    *s_size = info;
    if (A.size(0) != 0) {
      info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)A.size(0), (ptrdiff_t)6,
                              &(b_A.data())[0], (ptrdiff_t)A.size(0),
                              &s_data[0], &(U.data())[0], (ptrdiff_t)A.size(0),
                              &Vt[0], (ptrdiff_t)6, &superb_data[0]);
      info = (int32_T)info_t;
    } else {
      info = 0;
    }
    for (i = 0; i < 6; i++) {
      for (m = 0; m < 6; m++) {
        V[m + 6 * i] = Vt[i + 6 * m];
      }
    }
    d_st.site = &ks_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&d_st, &fb_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &gb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &cv1[0], 12, info);
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      for (m = 0; m < 6; m++) {
        V[m + 6 * i] = Vt[i + 6 * m];
      }
    }
  }
  if (info > 0) {
    emlrtErrorWithMessageIdR2018a(&st, &sb_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (svd1.cpp)
