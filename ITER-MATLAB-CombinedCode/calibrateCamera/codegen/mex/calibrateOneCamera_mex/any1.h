//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// any1.h
//
// Code generation for function 'any1'
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
boolean_T any(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x);

boolean_T b_any(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x);

boolean_T c_any(const emlrtStack *sp, const ::coder::array<boolean_T, 3U> &x);

} // namespace coder
} // namespace Codegen

// End of code generation (any1.h)
