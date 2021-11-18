//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// qrsolve.h
//
// Code generation for function 'qrsolve'
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
void LSQFromQR(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
               const ::coder::array<real_T, 1U> &tau,
               const ::coder::array<int32_T, 2U> &jpvt,
               ::coder::array<real_T, 1U> &B, int32_T rankA,
               ::coder::array<real_T, 1U> &Y);

void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, real_T Y[8]);

void qrsolve(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &B, ::coder::array<real_T, 1U> &Y,
             int32_T *rankA);

} // namespace internal
} // namespace coder

// End of code generation (qrsolve.h)
