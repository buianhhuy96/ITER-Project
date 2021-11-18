//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// polyval.cpp
//
// Code generation for function 'polyval'
//

// Include files
#include "polyval.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo hk_emlrtRTEI{
    33,        // lineNo
    20,        // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

static emlrtRTEInfo ik_emlrtRTEI{
    37,        // lineNo
    5,         // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

static emlrtRTEInfo jk_emlrtRTEI{
    39,        // lineNo
    9,         // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void polyval(const emlrtStack *sp, const real_T p_data[],
             const int32_T p_size[2], const ::coder::array<real_T, 2U> &x,
             ::coder::array<real_T, 2U> &y)
{
  y.set_size(&hk_emlrtRTEI, sp, 1, x.size(1));
  if (x.size(1) != 0) {
    int32_T i;
    int32_T y_idx_1;
    y_idx_1 = x.size(1);
    y.set_size(&ik_emlrtRTEI, sp, 1, x.size(1));
    for (i = 0; i < y_idx_1; i++) {
      y[i] = p_data[0];
    }
    i = p_size[1];
    for (int32_T k{0}; k <= i - 2; k++) {
      real_T p;
      y.set_size(&jk_emlrtRTEI, sp, 1, x.size(1));
      p = p_data[k + 1];
      y_idx_1 = x.size(1) - 1;
      for (int32_T i1{0}; i1 <= y_idx_1; i1++) {
        y[i1] = x[i1] * y[i1] + p;
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

// End of code generation (polyval.cpp)
