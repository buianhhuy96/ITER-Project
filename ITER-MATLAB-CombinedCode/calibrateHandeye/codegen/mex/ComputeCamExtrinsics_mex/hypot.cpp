//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// hypot.cpp
//
// Code generation for function 'hypot'
//

// Include files
#include "hypot.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ni_emlrtRSI{
    14,      // lineNo
    "hypot", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\hypot.m" // pathName
};

static emlrtRSInfo oi_emlrtRSI{
    19,             // lineNo
    "scalexpAlloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc."
    "m" // pathName
};

static emlrtRSInfo pi_emlrtRSI{
    216,        // lineNo
    "flatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

static emlrtRTEInfo cb_emlrtRTEI{
    14,             // lineNo
    15,             // colNo
    "scalexpCheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpCheck."
    "m" // pName
};

// Function Definitions
namespace coder {
void b_hypot(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y, ::coder::array<real_T, 1U> &r)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ni_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d_st.site = &td_emlrtRSI;
  nx = x.size(0);
  k = y.size(0);
  nx = muIntScalarMin_sint32(nx, k);
  d_st.site = &oi_emlrtRSI;
  p = true;
  if (nx == x.size(0)) {
    if (nx != y.size(0)) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &cb_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &sd_emlrtRSI;
  d_st.site = &vd_emlrtRSI;
  e_st.site = &ud_emlrtRSI;
  nx = x.size(0);
  k = y.size(0);
  r.set_size(&ye_emlrtRTEI, &e_st, muIntScalarMin_sint32(nx, k));
  nx = x.size(0);
  k = y.size(0);
  nx = muIntScalarMin_sint32(nx, k);
  d_st.site = &pi_emlrtRSI;
  if ((1 <= r.size(0)) && (r.size(0) > 2147483646)) {
    e_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < nx; k++) {
    r[k] = muDoubleScalarHypot(x[k], y[k]);
  }
}

void b_hypot(const emlrtStack *sp, const ::coder::array<real32_T, 1U> &x,
             const ::coder::array<real32_T, 1U> &y,
             ::coder::array<real32_T, 1U> &r)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ni_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d_st.site = &td_emlrtRSI;
  nx = x.size(0);
  k = y.size(0);
  nx = muIntScalarMin_sint32(nx, k);
  d_st.site = &oi_emlrtRSI;
  p = true;
  if (nx == x.size(0)) {
    if (nx != y.size(0)) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &cb_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &sd_emlrtRSI;
  d_st.site = &vd_emlrtRSI;
  e_st.site = &ud_emlrtRSI;
  nx = x.size(0);
  k = y.size(0);
  r.set_size(&ye_emlrtRTEI, &e_st, muIntScalarMin_sint32(nx, k));
  nx = x.size(0);
  k = y.size(0);
  nx = muIntScalarMin_sint32(nx, k);
  d_st.site = &pi_emlrtRSI;
  if ((1 <= r.size(0)) && (r.size(0) > 2147483646)) {
    e_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < nx; k++) {
    r[k] = muSingleScalarHypot(x[k], y[k]);
  }
}

} // namespace coder

// End of code generation (hypot.cpp)
