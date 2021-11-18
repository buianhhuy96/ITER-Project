//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// power.cpp
//
// Code generation for function 'power'
//

// Include files
#include "power.h"
#include "calibrateOneCamera_v2_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    nd_emlrtRSI{
        84,         // lineNo
        "fltpower", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

static emlrtRSInfo ud_emlrtRSI{
    202,        // lineNo
    "flatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

// Function Definitions
namespace coder {
void b_power(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
             ::coder::array<real32_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
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
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  e_st.site = &rd_emlrtRSI;
  d_st.site = &qd_emlrtRSI;
  e_st.site = &td_emlrtRSI;
  f_st.site = &sd_emlrtRSI;
  y.set_size(&ue_emlrtRTEI, &f_st, a.size(0), 2);
  nx = a.size(0) << 1;
  e_st.site = &ud_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    f_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    y[k] = a[k] * a[k];
  }
}

void power(const emlrtStack *sp, const ::coder::array<real_T, 1U> &a,
           ::coder::array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
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
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  e_st.site = &rd_emlrtRSI;
  d_st.site = &qd_emlrtRSI;
  e_st.site = &td_emlrtRSI;
  f_st.site = &sd_emlrtRSI;
  y.set_size(&ue_emlrtRTEI, &f_st, a.size(0));
  nx = a.size(0);
  e_st.site = &ud_emlrtRSI;
  if ((1 <= a.size(0)) && (a.size(0) > 2147483646)) {
    f_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    y[k] = a[k] * a[k];
  }
}

void power(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
           ::coder::array<real32_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fd_emlrtRSI;
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
  b_st.site = &nd_emlrtRSI;
  c_st.site = &od_emlrtRSI;
  d_st.site = &pd_emlrtRSI;
  e_st.site = &rd_emlrtRSI;
  d_st.site = &qd_emlrtRSI;
  e_st.site = &td_emlrtRSI;
  f_st.site = &sd_emlrtRSI;
  y.set_size(&ue_emlrtRTEI, &f_st, a.size(0), a.size(1));
  nx = a.size(0) * a.size(1);
  e_st.site = &ud_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    f_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    y[k] = a[k] * a[k];
  }
}

} // namespace coder

// End of code generation (power.cpp)
