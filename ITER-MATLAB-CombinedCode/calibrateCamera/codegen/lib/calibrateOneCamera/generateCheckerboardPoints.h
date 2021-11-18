//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: generateCheckerboardPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef GENERATECHECKERBOARDPOINTS_H
#define GENERATECHECKERBOARDPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
void generateCheckerboardPoints(const int boardSize[2], double squareSize,
                                ::coder::array<double, 2U> &c_worldPoints);

}
} // namespace Codegen

#endif
//
// File trailer for generateCheckerboardPoints.h
//
// [EOF]
//
