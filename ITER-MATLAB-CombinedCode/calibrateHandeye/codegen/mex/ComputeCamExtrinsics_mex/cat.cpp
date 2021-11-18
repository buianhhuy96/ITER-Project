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
#include "ComputeCamExtrinsics_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    ls_emlrtRSI{
        87,    // lineNo
        "cat", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pathName
    };

static emlrtRTEInfo
    wb_emlrtRTEI{
        71,    // lineNo
        27,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

static emlrtRTEInfo
    pq_emlrtRTEI{
        56,    // lineNo
        20,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

// Function Declarations
namespace coder {
static boolean_T isconsistent(const ::coder::array<real_T, 3U> &y,
                              const ::coder::array<real_T, 2U> &x);

}

// Function Definitions
namespace coder {
static boolean_T isconsistent(const ::coder::array<real_T, 3U> &y,
                              const ::coder::array<real_T, 2U> &x)
{
  int32_T j;
  boolean_T p;
  j = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (j < 2) {
      if (y.size(j) != x.size(j)) {
        p = false;
        exitg1 = 1;
      } else {
        j++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return p;
}

void cat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &varargin_1,
         const ::coder::array<real_T, 2U> &varargin_2,
         ::coder::array<real_T, 3U> &y)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T b_b;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y.set_size(&pq_emlrtRTEI, sp, varargin_1.size(0), varargin_1.size(1), 2);
  if (!isconsistent(y, varargin_1)) {
    emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
                                  "Coder:MATLAB:catenate_dimensionMismatch",
                                  "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }
  if (!isconsistent(y, varargin_2)) {
    emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
                                  "Coder:MATLAB:catenate_dimensionMismatch",
                                  "Coder:MATLAB:catenate_dimensionMismatch", 0);
  }
  b = varargin_1.size(0) * varargin_1.size(1);
  st.site = &ls_emlrtRSI;
  if ((1 <= b) && (b > 2147483646)) {
    b_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j = 0; j < b; j++) {
    y[j] = varargin_1[j];
  }
  b_b = varargin_2.size(0) * varargin_2.size(1);
  st.site = &ls_emlrtRSI;
  if ((1 <= b_b) && (b_b > 2147483646)) {
    b_st.site = &cd_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (j = 0; j < b_b; j++) {
    y[b + j] = varargin_2[j];
  }
}

} // namespace coder

// End of code generation (cat.cpp)
