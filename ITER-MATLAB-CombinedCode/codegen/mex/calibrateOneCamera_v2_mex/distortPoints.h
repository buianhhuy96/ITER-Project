//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// distortPoints.h
//
// Code generation for function 'distortPoints'
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
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const emlrtStack *sp,
                   const ::coder::array<real_T, 2U> &points,
                   const real_T intrinsicMatrix[9],
                   const ::coder::array<real_T, 2U> &radialDistortion,
                   const real_T tangentialDistortion[2],
                   ::coder::array<real_T, 2U> &distortedPoints);

void distortPoints(const emlrtStack *sp,
                   const ::coder::array<real_T, 2U> &points,
                   const real_T intrinsicMatrix[9],
                   const real_T radialDistortion[3],
                   const real_T tangentialDistortion[2],
                   ::coder::array<real_T, 2U> &distortedPoints);

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (distortPoints.h)
