//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xunormqr.cpp
//
// Code generation for function 'xunormqr'
//

// Include files
#include "xunormqr.h"
#include "calibrateOneCamera_v2_data.h"
#include "infocheck.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRTEInfo uv_emlrtRTEI{
    31,         // lineNo
    5,          // colNo
    "xunormqr", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xunormqr(const emlrtStack *sp, const ::coder::array<real_T, 2U> &Q,
              ::coder::array<real_T, 1U> &C,
              const ::coder::array<real_T, 1U> &tau)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hn_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((Q.size(0) != 0) && (Q.size(1) != 0) && (C.size(0) != 0)) {
    ptrdiff_t nrc_t;
    int32_T C_idx_0;
    int32_T i;
    nrc_t = (ptrdiff_t)C.size(0);
    i = Q.size(0);
    C_idx_0 = Q.size(1);
    nrc_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1,
                           (ptrdiff_t)muIntScalarMin_sint32(i, C_idx_0),
                           &(((::coder::array<real_T, 2U> *)&Q)->data())[0],
                           (ptrdiff_t)Q.size(0),
                           &(((::coder::array<real_T, 1U> *)&tau)->data())[0],
                           &(C.data())[0], nrc_t);
    b_st.site = &in_emlrtRSI;
    if (infocheck(&b_st, (int32_T)nrc_t)) {
      C_idx_0 = C.size(0);
      C.set_size(&uv_emlrtRTEI, &st, C_idx_0);
      for (i = 0; i < C_idx_0; i++) {
        C[i] = rtNaN;
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xunormqr.cpp)
