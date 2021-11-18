//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cat.cpp
//
// Code generation for function 'cat'
//

// Include files
#include "cat.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    eq_emlrtRSI{
        87,    // lineNo
        "cat", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRTEInfo
    qb_emlrtRTEI{
        71,    // lineNo
        27,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

// Function Definitions
namespace Codegen {
namespace coder {
void cat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &varargin_1,
         const ::coder::array<real_T, 2U> &varargin_2,
         ::coder::array<real_T, 3U> &y)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T b_b;
  int32_T j;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y.set_size(&qo_emlrtRTEI, sp, varargin_1.size(0), varargin_1.size(1), 2);
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (y.size(j) != varargin_1.size(j)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &qb_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (y.size(j) != varargin_2.size(j)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &qb_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }
  b = varargin_1.size(0) * varargin_1.size(1);
  st.site = &eq_emlrtRSI;
  if ((1 <= b) && (b > 2147483646)) {
    b_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j = 0; j < b; j++) {
    y[j] = varargin_1[j];
  }
  b_b = varargin_2.size(0) * varargin_2.size(1);
  st.site = &eq_emlrtRSI;
  if ((1 <= b_b) && (b_b > 2147483646)) {
    b_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j = 0; j < b_b; j++) {
    y[b + j] = varargin_2[j];
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (cat.cpp)
