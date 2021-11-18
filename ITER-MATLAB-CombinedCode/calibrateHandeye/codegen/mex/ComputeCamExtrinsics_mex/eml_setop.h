//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eml_setop.h
//
// Code generation for function 'eml_setop'
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
void do_vectors(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                const ::coder::array<real_T, 2U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                ::coder::array<int32_T, 1U> &ib);

void do_vectors(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                ::coder::array<int32_T, 1U> &ib);

} // namespace coder

// End of code generation (eml_setop.h)
