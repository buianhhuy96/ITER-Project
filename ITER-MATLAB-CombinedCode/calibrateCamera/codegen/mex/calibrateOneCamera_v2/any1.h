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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
boolean_T any(const boolean_T x[2]);

boolean_T b_any(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x);

boolean_T c_any(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x);

boolean_T d_any(const emlrtStack *sp, const ::coder::array<boolean_T, 3U> &x);

} // namespace coder

// End of code generation (any1.h)
