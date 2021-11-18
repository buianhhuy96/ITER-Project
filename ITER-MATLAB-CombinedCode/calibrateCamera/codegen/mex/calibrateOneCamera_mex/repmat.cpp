//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo dn_emlrtRSI{
    66,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo en_emlrtRSI{
    69,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRTEInfo kb_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo kk_emlrtRTEI{
    59,       // lineNo
    28,       // colNo
    "repmat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void repmat(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
            real_T varargin_1, ::coder::array<real32_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T ncols;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ec_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &kb_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  i = static_cast<int32_T>(varargin_1);
  b.set_size(&kk_emlrtRTEI, sp, i, a.size(1));
  ncols = a.size(1);
  st.site = &dn_emlrtRSI;
  if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
    b_st.site = &hc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T jcol{0}; jcol < ncols; jcol++) {
    int32_T ibmat;
    ibmat = jcol * static_cast<int32_T>(varargin_1);
    st.site = &en_emlrtRSI;
    if ((1 <= static_cast<int32_T>(varargin_1)) &&
        (static_cast<int32_T>(varargin_1) > 2147483646)) {
      b_st.site = &hc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (repmat.cpp)
