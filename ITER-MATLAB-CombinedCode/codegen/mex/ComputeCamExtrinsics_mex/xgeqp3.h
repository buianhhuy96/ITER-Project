//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqp3.h
//
// Code generation for function 'xgeqp3'
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
void xgeqp3(const emlrtStack *sp, ::coder::array<real_T, 2U> &A,
            ::coder::array<real_T, 1U> &tau, ::coder::array<int32_T, 2U> &jpvt);

}
} // namespace internal
} // namespace coder

// End of code generation (xgeqp3.h)
