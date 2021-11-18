//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// polyfit.h
//
// Code generation for function 'polyfit'
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
void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y, real_T n,
             ::coder::array<real_T, 2U> &p);

void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             const ::coder::array<real_T, 2U> &y, real_T n,
             ::coder::array<real_T, 2U> &p);

} // namespace coder

// End of code generation (polyfit.h)
