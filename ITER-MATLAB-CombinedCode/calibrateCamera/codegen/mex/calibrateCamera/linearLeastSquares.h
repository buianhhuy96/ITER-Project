//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linearLeastSquares.h
//
// Code generation for function 'linearLeastSquares'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void linearLeastSquares(const emlrtStack *sp, ::coder::array<real_T, 2U> &lhs,
                        ::coder::array<real_T, 1U> &rhs,
                        ::coder::array<real_T, 1U> &dx, int32_T m, int32_T n);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (linearLeastSquares.h)
