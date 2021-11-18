//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xnrm2.h
//
// Code generation for function 'xnrm2'
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
namespace blas {
real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0);

real_T xnrm2(const real_T x[3]);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xnrm2.h)
