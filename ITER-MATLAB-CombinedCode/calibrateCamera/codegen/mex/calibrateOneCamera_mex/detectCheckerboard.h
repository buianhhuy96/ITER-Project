//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectCheckerboard.h
//
// Code generation for function 'detectCheckerboard'
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

// Type Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
class Checkerboard;

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const emlrtStack *sp,
                        const ::coder::array<real32_T, 2U> &b_I,
                        ::coder::array<real_T, 2U> &points,
                        real_T boardSize[2]);

Checkerboard *growCheckerboard(const emlrtStack *sp,
                               const ::coder::array<real32_T, 2U> &points,
                               const ::coder::array<real32_T, 1U> &scores,
                               const ::coder::array<real32_T, 2U> &Ix2,
                               const ::coder::array<real32_T, 2U> &Iy2,
                               const ::coder::array<real32_T, 2U> &Ixy,
                               real_T theta, Checkerboard *iobj_0);

Checkerboard *orient(const emlrtStack *sp, Checkerboard *board,
                     const ::coder::array<real32_T, 2U> &b_I);

void toPoints(const emlrtStack *sp, const Checkerboard *b_this,
              ::coder::array<real_T, 2U> &points, real_T boardSize[2]);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (detectCheckerboard.h)
