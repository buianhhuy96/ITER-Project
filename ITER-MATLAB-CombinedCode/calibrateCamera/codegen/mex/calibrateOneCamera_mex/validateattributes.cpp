//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// validateattributes.cpp
//
// Code generation for function 'validateattributes'
//

// Include files
#include "validateattributes.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo fc_emlrtRTEI{
    15,             // lineNo
    19,             // colNo
    "validatesize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatesize.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void validateattributes(const emlrtStack *sp,
                        const ::coder::array<real_T, 2U> &a,
                        const int32_T attributes_f2[2])
{
  emlrtStack st;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  p = true;
  if ((attributes_f2[0] != a.size(0)) || (attributes_f2[1] != a.size(1))) {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &fc_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:incorrectSize", 3, 4, 5, "Input");
  }
}

void validateattributes(const emlrtStack *sp,
                        const ::coder::array<real_T, 1U> &a,
                        const int32_T attributes_f2[2])
{
  emlrtStack st;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  p = true;
  if ((attributes_f2[0] != a.size(0)) || (attributes_f2[1] != 1)) {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &fc_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:incorrectSize", 3, 4, 5, "Input");
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (validateattributes.cpp)
