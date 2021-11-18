//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectCheckerboardPoints.h
//
// Code generation for function 'detectCheckerboardPoints'
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
void detectCheckerboardPoints(const emlrtStack *sp,
                              const ::coder::array<uint8_T, 2U> &b_I,
                              ::coder::array<real_T, 2U> &imagePoints,
                              real_T boardSize[2]);

}
} // namespace Codegen

// End of code generation (detectCheckerboardPoints.h)
