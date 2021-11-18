//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xswap.h
//
// Code generation for function 'xswap'
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
void xswap(real_T x[9], int32_T ix0, int32_T iy0);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xswap.h)
