//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DETECTCHECKERBOARDPOINTS_H
#define DETECTCHECKERBOARDPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
void b_detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<double, 2U> &b_imagePoints,
                                double boardSize[2]);

void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &o_I,
                              ::coder::array<double, 2U> &b_imagePoints,
                              double boardSize[2]);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for detectCheckerboardPoints.h
//
// [EOF]
//
