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
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo al_emlrtRTEI{
    33,        // lineNo
    20,        // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

static emlrtRTEInfo bl_emlrtRTEI{
    37,        // lineNo
    5,         // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

static emlrtRTEInfo cl_emlrtRTEI{
    39,        // lineNo
    9,         // colNo
    "polyval", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\polyfun\\polyval.m" // pName
};

// Function Definitions
namespace coder {
void polyval(const emlrtStack *sp, const ::coder::array<real_T, 2U> &p,
             const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &y)
{
  y.set_size(&al_emlrtRTEI, sp, 1, x.size(1));
  if ((x.size(1) != 0) && (p.size(1) != 0)) {
    int32_T i;
    int32_T y_idx_1;
    y_idx_1 = x.size(1);
    y.set_size(&bl_emlrtRTEI, sp, 1, x.size(1));
    for (i = 0; i < y_idx_1; i++) {
      y[i] = p[0];
    }
    i = p.size(1);
    for (int32_T k{0}; k <= i - 2; k++) {
      real_T b_p;
      y.set_size(&cl_emlrtRTEI, sp, 1, x.size(1));
      b_p = p[k + 1];
      y_idx_1 = x.size(1) - 1;
      for (int32_T i1{0}; i1 <= y_idx_1; i1++) {
        y[i1] = x[i1] * y[i1] + b_p;
      }
    }
  }
}

} // namespace coder

// End of code generation (polyval.cpp)
