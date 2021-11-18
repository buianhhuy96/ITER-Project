//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectMyCheckerboard.h
//
// Code generation for function 'detectMyCheckerboard'
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
void detectMyCheckerboard(const emlrtStack *sp,
                          const ::coder::array<uint8_T, 4U> &images,
                          const real_T boardSize[2],
                          ::coder::array<real_T, 3U> &image_points);

}

// End of code generation (detectMyCheckerboard.h)
