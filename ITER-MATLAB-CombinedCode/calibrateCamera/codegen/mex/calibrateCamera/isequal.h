//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// isequal.h
//
// Code generation for function 'isequal'
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
boolean_T isequal(const real_T varargin_1[2]);

boolean_T isequal(const real_T varargin_1_data[],
                  const int32_T varargin_1_size[2], real_T varargin_2);

} // namespace coder
} // namespace Codegen

// End of code generation (isequal.h)
