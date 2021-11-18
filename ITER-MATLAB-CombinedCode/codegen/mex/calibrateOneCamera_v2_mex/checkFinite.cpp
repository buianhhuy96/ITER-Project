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
#include "calibrateOneCamera_v2_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo meb_emlrtRSI{
    1,             // lineNo
    "checkFinite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p" // pathName
};

static emlrtBCInfo wy_emlrtBCI{
    0,             // iFirst
    MAX_int32_T,   // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "checkFinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p", // pName
    0                          // checkKind
};

static emlrtRTEInfo ed_emlrtRTEI{
    1,             // lineNo
    1,             // colNo
    "checkFinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "validate\\checkFinite.p" // pName
};

static emlrtBCInfo xy_emlrtBCI{
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
  int32_T i;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((m == 1) || (n == 1)) {
    i = x.size(0) * x.size(1);
    if (i < 0) {
      emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &wy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (i != m * n) {
      emlrtErrorWithMessageIdR2018a(
          sp, &ed_emlrtRTEI, "optim_codegen:common:IncorrectSizeObjective",
          "optim_codegen:common:IncorrectSizeObjective", 2, 12, m * n);
    }
  } else if ((m > 1) && (n > 1)) {
    i = x.size(0) * x.size(1);
    if (i < 0) {
      emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &wy_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (i != m * n) {
      emlrtErrorWithMessageIdR2018a(
          sp, &ed_emlrtRTEI,
          "optim_codegen:common:IncorrectSizeObjectiveJacobian",
          "optim_codegen:common:IncorrectSizeObjectiveJacobian", 4, 12, m, 12,
          n);
    }
  }
  evalOK = true;
  b = m * n;
  st.site = &meb_emlrtRSI;
  if ((1 <= b) && (b > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T b_i{0}; b_i < b; b_i++) {
    if (evalOK) {
      real_T b_x;
      i = x.size(0) * x.size(1);
      if ((b_i + 1 < 1) || (b_i + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &xy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_x = x[b_i];
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
  int32_T i;
  boolean_T evalOK;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = x.size(0);
  if (i < 0) {
    emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &wy_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (i != m) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ed_emlrtRTEI, "optim_codegen:common:IncorrectSizeObjective",
        "optim_codegen:common:IncorrectSizeObjective", 2, 12, m);
  }
  evalOK = true;
  st.site = &meb_emlrtRSI;
  if ((1 <= m) && (m > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T b_i{0}; b_i < m; b_i++) {
    if (evalOK) {
      real_T b_x;
      i = x.size(0);
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &xy_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_x = x[b_i];
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

// End of code generation (checkFinite.cpp)
