//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// nanmean.h
//
// Code generation for function 'nanmean'
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
real_T nanmean(const emlrtStack *sp,
               const ::coder::array<real_T, 1U> &varargin_1);

}
} // namespace Codegen

// End of code generation (nanmean.h)
