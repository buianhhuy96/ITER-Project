//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// lsqnonlin.cpp
//
// Code generation for function 'lsqnonlin'
//

// Include files
#include "lsqnonlin.h"
#include "anonymous_function1.h"
#include "calibrateCamera_data.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ny_emlrtRSI{
    1,           // lineNo
    "lsqnonlin", // fcnName
    "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\optim\\eml\\lsqnonlin.p" // pathName
};

static emlrtRSInfo oy_emlrtRSI{
    1,         // lineNo
    "checkX0", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+validate\\checkX0."
    "p" // pathName
};

static emlrtRSInfo
    py_emlrtRSI{
        16,    // lineNo
        "all", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m" // pathName
    };

static emlrtRSInfo
    qy_emlrtRSI{
        57,         // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

static emlrtRSInfo ry_emlrtRSI{
    106,                   // lineNo
    "applyToMultipleDims", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyToMultipleDims.m" // pathName
};

static emlrtRSInfo
    ty_emlrtRSI{
        56, // lineNo
        "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

static emlrtRTEInfo gc_emlrtRTEI{
    1,         // lineNo
    1,         // colNo
    "checkX0", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+validate\\checkX0."
    "p" // pName
};

static emlrtRTEInfo rs_emlrtRTEI{
    16,      // lineNo
    13,      // colNo
    "isinf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\isinf.m" // pName
};

static emlrtRTEInfo ss_emlrtRTEI{
    1,           // lineNo
    1,           // colNo
    "lsqnonlin", // fName
    "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\optim\\eml\\lsqnonlin.p" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void lsqnonlin(const emlrtStack *sp, const anonymous_function *fun,
               ::coder::array<real_T, 1U> &xCurrent, real_T *resnorm,
               ::coder::array<real_T, 1U> &fval, real_T *exitflag,
               ::coder::array<real_T, 2U> &jacob)
{
  ::coder::array<real_T, 1U> b_xCurrent;
  ::coder::array<real_T, 1U> f_expl_temp;
  ::coder::array<real_T, 1U> g_expl_temp;
  ::coder::array<boolean_T, 1U> b;
  ::coder::array<boolean_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T b_expl_temp;
  real_T c_expl_temp;
  real_T d_expl_temp;
  real_T expl_temp;
  int32_T i;
  int32_T loop_ub;
  char_T e_expl_temp[19];
  boolean_T exitg1;
  boolean_T y;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &ny_emlrtRSI;
  b.set_size(&rs_emlrtRTEI, &st, xCurrent.size(0));
  loop_ub = xCurrent.size(0);
  for (i = 0; i < loop_ub; i++) {
    b[i] = muDoubleScalarIsInf(xCurrent[i]);
  }
  r.set_size(&rc_emlrtRTEI, &st, xCurrent.size(0));
  loop_ub = xCurrent.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = muDoubleScalarIsNaN(xCurrent[i]);
  }
  loop_ub = b.size(0);
  for (i = 0; i < loop_ub; i++) {
    b[i] = ((!b[i]) && (!r[i]));
  }
  b_st.site = &oy_emlrtRSI;
  c_st.site = &py_emlrtRSI;
  d_st.site = &qy_emlrtRSI;
  e_st.site = &ry_emlrtRSI;
  f_st.site = &sy_emlrtRSI;
  g_st.site = &ty_emlrtRSI;
  y = true;
  h_st.site = &bi_emlrtRSI;
  if ((1 <= b.size(0)) && (b.size(0) > 2147483646)) {
    i_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= b.size(0))) {
    if (!b[loop_ub - 1]) {
      y = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        &st, &gc_emlrtRTEI, "optim_codegen:common:InfNaNComplexDetected",
        "optim_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  b_xCurrent.set_size(&ss_emlrtRTEI, sp, xCurrent.size(0));
  loop_ub = xCurrent.size(0) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_xCurrent[i] = xCurrent[i];
  }
  st.site = &ny_emlrtRSI;
  optim::coder::levenbergMarquardt::driver(
      &st, fun, b_xCurrent, xCurrent, resnorm, fval, exitflag, &expl_temp,
      &b_expl_temp, &c_expl_temp, &d_expl_temp, e_expl_temp, f_expl_temp,
      g_expl_temp, jacob);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (lsqnonlin.cpp)
