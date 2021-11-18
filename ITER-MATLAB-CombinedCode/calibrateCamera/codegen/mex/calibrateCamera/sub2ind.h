//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sub2ind.h
//
// Code generation for function 'sub2ind'
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
void eml_sub2ind(const emlrtStack *sp, const int32_T siz[2],
                 const ::coder::array<real32_T, 1U> &varargin_1,
                 const ::coder::array<real32_T, 1U> &varargin_2,
                 ::coder::array<int32_T, 1U> &idx);

}
} // namespace Codegen

// End of code generation (sub2ind.h)
