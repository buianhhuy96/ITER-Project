//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkFinite.cpp
//
// Code generation for function 'checkFinite'
//

// Include files
#include "checkFinite.h"
#include "calibrateCamera_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo xy_emlrtRSI{
    1,             // lineNo
    "checkFinite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p" // pathName
};

static emlrtRTEInfo hc_emlrtRTEI{
    1,             // lineNo
    1,             // colNo
    "checkFinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p" // pName
};

static emlrtBCInfo mv_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "checkFinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p", // pName
    0                          // checkKind
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace validate {
boolean_T checkFinite(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
                      int32_T m, int32_T n)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = m * n;
  if (x.size(0) * x.size(1) != b) {
    emlrtErrorWithMessageIdR2018a(
        sp, &hc_emlrtRTEI,
        "optim_codegen:common:IncorrectSizeObjectiveJacobian",
        "optim_codegen:common:IncorrectSizeObjectiveJacobian", 4, 12, m, 12, n);
  }
  evalOK = true;
  st.site = &xy_emlrtRSI;
  if ((1 <= b) && (b > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T i{0}; i < b; i++) {
    if (evalOK) {
      real_T b_x;
      int32_T b_i;
      b_i = x.size(0) * x.size(1);
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &mv_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_x = x[i];
      if (muDoubleScalarIsInf(b_x) || muDoubleScalarIsNaN(b_x)) {
        evalOK = false;
      }
    } else {
      evalOK = false;
    }
  }
  return evalOK;
}

boolean_T checkFinite(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
                      int32_T m)
{
  emlrtStack b_st;
  emlrtStack st;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (x.size(0) != m) {
    emlrtErrorWithMessageIdR2018a(
        sp, &hc_emlrtRTEI, "optim_codegen:common:IncorrectSizeObjective",
        "optim_codegen:common:IncorrectSizeObjective", 2, 12, m);
  }
  evalOK = true;
  st.site = &xy_emlrtRSI;
  if ((1 <= m) && (m > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T i{0}; i < m; i++) {
    if (evalOK) {
      real_T b_x;
      int32_T b_i;
      b_i = x.size(0);
      if ((i + 1 < 1) || (i + 1 > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &mv_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_x = x[i];
      if (muDoubleScalarIsInf(b_x) || muDoubleScalarIsNaN(b_x)) {
        evalOK = false;
      }
    } else {
      evalOK = false;
    }
  }
  return evalOK;
}

} // namespace validate
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (checkFinite.cpp)
