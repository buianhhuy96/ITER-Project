//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef DETECTCHECKERBOARDPOINTS_H
#define DETECTCHECKERBOARDPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &w_I,
                              ::coder::array<double, 2U> &b_imagePoints,
                              double boardSize[2]);

}

#endif
//
// File trailer for detectCheckerboardPoints.h
//
// [EOF]
//
