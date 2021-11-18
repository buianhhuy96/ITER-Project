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
#include "calibrateOneCamera_v2_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo vo_emlrtRSI{
    66,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo wo_emlrtRSI{
    69,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRTEInfo nb_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo il_emlrtRTEI{
    59,       // lineNo
    28,       // colNo
    "repmat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pName
};

// Function Definitions
namespace coder {
void repmat(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
            real_T varargin_1, ::coder::array<real32_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_varargin_1;
  int32_T i;
  int32_T ncols;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) ||
      muDoubleScalarIsInf(varargin_1) || (varargin_1 < -2.147483648E+9) ||
      (varargin_1 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &nb_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &b_emlrtDCI, (emlrtCTX)sp);
  }
  i = static_cast<int32_T>(varargin_1);
  b.set_size(&il_emlrtRTEI, sp, i, a.size(1));
  ncols = a.size(1);
  st.site = &vo_emlrtRSI;
  if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T jcol{0}; jcol < ncols; jcol++) {
    int32_T ibmat;
    ibmat = jcol * static_cast<int32_T>(varargin_1);
    st.site = &wo_emlrtRSI;
    if ((1 <= static_cast<int32_T>(varargin_1)) &&
        (static_cast<int32_T>(varargin_1) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
