//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// vAllOrAny.cpp
//
// Code generation for function 'vAllOrAny'
//

// Include files
#include "vAllOrAny.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
namespace internal {
boolean_T flatVectorAllOrAny(const emlrtStack *sp,
                             const ::coder::array<real_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nx = x.size(0) * x.size(1);
  p = true;
  st.site = &ae_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    b_st.site = &ed_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(x[k]) || muDoubleScalarIsNaN(x[k]))) {
      p = false;
    }
  }
  return p;
}

} // namespace internal
} // namespace coder

// End of code generation (vAllOrAny.cpp)
