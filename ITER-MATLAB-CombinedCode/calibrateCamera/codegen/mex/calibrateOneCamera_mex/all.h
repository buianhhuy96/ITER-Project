//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// all.h
//
// Code generation for function 'all'
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
boolean_T all(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x);

boolean_T b_all(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x);

} // namespace coder
} // namespace Codegen

// End of code generation (all.h)
