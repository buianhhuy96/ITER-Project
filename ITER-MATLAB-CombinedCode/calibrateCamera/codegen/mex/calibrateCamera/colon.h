//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// colon.h
//
// Code generation for function 'colon'
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
void eml_float_colon(const emlrtStack *sp, real_T a, real_T b,
                     ::coder::array<real_T, 2U> &y);

}
} // namespace Codegen

// End of code generation (colon.h)
