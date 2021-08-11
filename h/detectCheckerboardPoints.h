//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
void detectCheckerboardPoints(const ::coder::array<unsigned char, 3U> &b_I,
                              ::coder::array<double, 2U> &imagePoints,
                              double boardSize[2]);

}

#endif
//
// File trailer for detectCheckerboardPoints.h
//
// [EOF]
//
