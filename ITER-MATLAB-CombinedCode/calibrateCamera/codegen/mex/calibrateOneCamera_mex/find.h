//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.h
//
// Code generation for function 'find'
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
void b_eml_find(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
                ::coder::array<int32_T, 2U> &i);

void b_eml_find(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
                ::coder::array<int32_T, 1U> &i);

void c_eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 1U> &x,
                real_T kin, ::coder::array<int32_T, 1U> &i);

void eml_find(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &x,
              ::coder::array<int32_T, 1U> &i);

} // namespace coder
} // namespace Codegen

// End of code generation (find.h)
