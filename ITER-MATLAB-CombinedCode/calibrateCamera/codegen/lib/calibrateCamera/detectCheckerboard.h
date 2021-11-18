//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef DETECTCHECKERBOARD_H
#define DETECTCHECKERBOARD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
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
} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<real32_T, 2U> &g_I,
                        ::coder::array<real_T, 2U> &b_points,
                        real_T boardSize[2]);

b_Checkerboard *growCheckerboard(const ::coder::array<real32_T, 2U> &b_points,
                                 const ::coder::array<real32_T, 1U> &scores,
                                 const ::coder::array<real32_T, 2U> &Ix2,
                                 const ::coder::array<real32_T, 2U> &Iy2,
                                 const ::coder::array<real32_T, 2U> &Ixy,
                                 real_T theta, b_Checkerboard *b_iobj_0);

b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<real32_T, 2U> &g_I);

void toPoints(const b_Checkerboard *b_this,
              ::coder::array<real_T, 2U> &b_points, real_T boardSize[2]);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for detectCheckerboard.h
//
// [EOF]
//
