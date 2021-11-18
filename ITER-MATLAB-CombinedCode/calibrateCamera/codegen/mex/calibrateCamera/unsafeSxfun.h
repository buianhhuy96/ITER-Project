//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// unsafeSxfun.h
//
// Code generation for function 'unsafeSxfun'
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
void binary_expand_op(const emlrtStack *sp, ::coder::array<real_T, 2U> &points,
                      const ::coder::array<real_T, 2U> &distortedPoints);

}

// End of code generation (unsafeSxfun.h)
