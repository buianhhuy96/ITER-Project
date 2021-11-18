//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imfilter.h
//
// Code generation for function 'imfilter'
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
void b_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1);

void c_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1);

void d_imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1);

void imfilter(const emlrtStack *sp, ::coder::array<real32_T, 2U> &varargin_1);

void padImage(const emlrtStack *sp, const ::coder::array<real32_T, 2U> &a_tmp,
              const real_T pad[2], ::coder::array<real32_T, 2U> &a);

} // namespace coder
} // namespace Codegen

// End of code generation (imfilter.h)
