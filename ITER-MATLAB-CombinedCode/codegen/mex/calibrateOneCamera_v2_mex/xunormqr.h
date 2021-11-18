//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xunormqr.h
//
// Code generation for function 'xunormqr'
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
namespace lapack {
void xunormqr(const emlrtStack *sp, const ::coder::array<real_T, 2U> &Q,
              ::coder::array<real_T, 1U> &C,
              const ::coder::array<real_T, 1U> &tau);

}
} // namespace internal
} // namespace coder

// End of code generation (xunormqr.h)
