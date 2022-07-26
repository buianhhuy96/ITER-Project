//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DETECTCHECKERBOARD_H
#define DETECTCHECKERBOARD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
class b_Checkerboard;

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
b_Checkerboard *b_growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                   const ::coder::array<float, 1U> &scores,
                                   const ::coder::array<float, 2U> &Ix2,
                                   const ::coder::array<float, 2U> &Iy2,
                                   const ::coder::array<float, 2U> &Ixy,
                                   double theta, b_Checkerboard *c_iobj_0);

b_Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                 const ::coder::array<float, 1U> &scores,
                                 const ::coder::array<float, 2U> &Ix2,
                                 const ::coder::array<float, 2U> &Iy2,
                                 const ::coder::array<float, 2U> &Ixy,
                                 double theta, b_Checkerboard *c_iobj_0);

b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<float, 2U> &o_I);

void toPoints(const b_Checkerboard *b_this,
              ::coder::array<double, 2U> &b_points, double boardSize[2]);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for detectCheckerboard.h
//
// [EOF]
//
