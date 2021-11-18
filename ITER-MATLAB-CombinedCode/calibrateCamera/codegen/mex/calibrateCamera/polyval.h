//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// polyval.h
//
// Code generation for function 'polyval'
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
void polyval(const emlrtStack *sp, const real_T p_data[],
             const int32_T p_size[2], const ::coder::array<real_T, 2U> &x,
             ::coder::array<real_T, 2U> &y);

}
} // namespace Codegen

// End of code generation (polyval.h)
