//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// flip.cpp
//
// Code generation for function 'flip'
//

// Include files
#include "flip.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ar_emlrtRSI{
    37,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo br_emlrtRSI{
    29,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRSInfo cr_emlrtRSI{
    20,     // lineNo
    "flip", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m" // pathName
};

static emlrtRTEInfo ic_emlrtRTEI{
    57,               // lineNo
    27,               // colNo
    "assertValidDim", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\assertValidDim.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void flip(const emlrtStack *sp, ::coder::array<real_T, 2U> &x, real_T dim)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cr_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (!(dim == muDoubleScalarFloor(dim))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ic_emlrtRTEI, "MATLAB:getdimarg:dimensionMustBePositiveInteger",
        "MATLAB:getdimarg:dimensionMustBePositiveInteger", 0);
  }
  if ((x.size(0) != 0) && (x.size(1) != 0) &&
      (x.size(static_cast<int32_T>(dim) - 1) > 1)) {
    int32_T i;
    int32_T k;
    int32_T nd2;
    int32_T npages;
    int32_T pagelen;
    int32_T vstride;
    st.site = &br_emlrtRSI;
    vstride = 1;
    npages = static_cast<int32_T>(dim);
    b_st.site = &lf_emlrtRSI;
    if ((1 <= static_cast<int32_T>(dim) - 1) &&
        (static_cast<int32_T>(dim) - 1 > 2147483646)) {
      c_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= npages - 2; k++) {
      vstride *= x.size(0);
    }
    pagelen = vstride * x.size(static_cast<int32_T>(dim) - 1);
    npages = 1;
    i = static_cast<int32_T>(dim) + 1;
    for (k = i; k < 3; k++) {
      npages *= x.size(1);
    }
    i = x.size(static_cast<int32_T>(dim) - 1) - 1;
    nd2 = x.size(static_cast<int32_T>(dim) - 1) >> 1;
    npages--;
    for (int32_T j{0}; j <= npages; j++) {
      int32_T i1;
      i1 = vstride - 1;
      for (int32_T b_i{0}; b_i <= i1; b_i++) {
        int32_T offset;
        offset = j * pagelen + b_i;
        st.site = &ar_emlrtRSI;
        for (k = 0; k < nd2; k++) {
          real_T tmp;
          int32_T i2;
          int32_T tmp_tmp;
          tmp_tmp = offset + k * vstride;
          tmp = x[tmp_tmp];
          i2 = offset + (i - k) * vstride;
          x[tmp_tmp] = x[i2];
          x[i2] = tmp;
        }
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (flip.cpp)
