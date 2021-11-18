//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdot.h
//
// Code generation for function 'xdot'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
real_T xdot(int32_T n, const ::coder::array<real_T, 1U> &x,
            const ::coder::array<real_T, 1U> &y);

}
} // namespace internal
} // namespace coder

// End of code generation (xdot.h)
