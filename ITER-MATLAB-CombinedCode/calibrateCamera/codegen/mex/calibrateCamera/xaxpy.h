//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.h
//
// Code generation for function 'xaxpy'
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
void xaxpy(real_T a, const real_T x[9], int32_T ix0, real_T y[3]);

void xaxpy(real_T a, const real_T x[3], real_T y[9], int32_T iy0);

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xaxpy.h)
