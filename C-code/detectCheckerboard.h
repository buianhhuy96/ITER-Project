//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef DETECTCHECKERBOARD_H
#define DETECTCHECKERBOARD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
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

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<float, 2U> &b_I,
                        ::coder::array<double, 2U> &points,
                        double boardSize[2]);

Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &points,
                               const ::coder::array<float, 1U> &scores,
                               const ::coder::array<float, 2U> &Ix2,
                               const ::coder::array<float, 2U> &Iy2,
                               const ::coder::array<float, 2U> &Ixy,
                               double theta, Checkerboard *iobj_0);

Checkerboard *orient(Checkerboard *board, const ::coder::array<float, 2U> &b_I);

void toPoints(const Checkerboard *b_this, ::coder::array<double, 2U> &points,
              double boardSize[2]);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

#endif
//
// File trailer for detectCheckerboard.h
//
// [EOF]
//
