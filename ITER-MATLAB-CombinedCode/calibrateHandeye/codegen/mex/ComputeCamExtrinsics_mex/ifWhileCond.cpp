//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ifWhileCond.cpp
//
// Code generation for function 'ifWhileCond'
//

// Include files
#include "ifWhileCond.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    ns_emlrtRSI{
        18,            // lineNo
        "ifWhileCond", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\ifWhileCond.m" // pathName
    };

static emlrtRSInfo
    os_emlrtRSI{
        31,            // lineNo
        "checkNoNaNs", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\ifWhileCond.m" // pathName
    };

// Function Definitions
namespace coder {
namespace internal {
boolean_T ifWhileCond(const emlrtStack *sp,
                      const ::coder::array<boolean_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = (x.size(1) != 0);
  if (y) {
    int32_T k;
    boolean_T exitg1;
    st.site = &ns_emlrtRSI;
    b_st.site = &os_emlrtRSI;
    if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
      c_st.site = &cd_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x.size(1) - 1)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return y;
}

} // namespace internal
} // namespace coder

// End of code generation (ifWhileCond.cpp)
