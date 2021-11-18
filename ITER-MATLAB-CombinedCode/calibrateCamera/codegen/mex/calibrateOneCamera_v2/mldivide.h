//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mldivide.h
//
// Code generation for function 'mldivide'
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
void mldivide(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
              ::coder::array<real_T, 1U> &B);

void mldivide(const emlrtStack *sp, const real_T A[9], const real_T B[9],
              real_T Y[9]);

} // namespace coder

// End of code generation (mldivide.h)
