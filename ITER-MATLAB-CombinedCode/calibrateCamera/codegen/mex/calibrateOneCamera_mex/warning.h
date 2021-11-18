//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// warning.h
//
// Code generation for function 'warning'
//

#pragma once

// Include files
#include "rtwtypes.h"
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
namespace internal {
void b_warning(const emlrtStack *sp);

void c_warning(const emlrtStack *sp);

void d_warning(const emlrtStack *sp);

void warning(const emlrtStack *sp, int32_T varargin_1,
             const char_T varargin_2[14]);

void warning(const emlrtStack *sp, const char_T varargin_1[14]);

void warning(const emlrtStack *sp);

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (warning.h)
