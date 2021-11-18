//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// bsxfun.h
//
// Code generation for function 'bsxfun'
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
void bsxfun(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a,
            const real_T b[2], ::coder::array<real32_T, 2U> &c);

void bsxfun(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
            const ::coder::array<real_T, 1U> &b, ::coder::array<real_T, 2U> &c);

} // namespace coder
} // namespace Codegen

// End of code generation (bsxfun.h)
