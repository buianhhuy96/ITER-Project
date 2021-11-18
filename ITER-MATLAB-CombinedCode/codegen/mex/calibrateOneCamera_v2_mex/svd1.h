//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd1.h
//
// Code generation for function 'svd1'
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
namespace internal {
void c_svd(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
           ::coder::array<real_T, 2U> &U, ::coder::array<real_T, 1U> &s,
           real_T V[36]);

void c_svd(const emlrtStack *sp, const real_T A[81], real_T U[81], real_T s[9],
           real_T V[81]);

} // namespace internal
} // namespace coder

// End of code generation (svd1.h)
