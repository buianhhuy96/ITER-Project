//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALIBRATEONECAMERA_H
#define CALIBRATEONECAMERA_H

// Include Files
#include "calibrateOneCamera_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
extern void calibrateOneCamera(const ::coder::array<unsigned char, 4U> &images,
                               double squareSize, const int boardSize[2],
                               struct0_T *calibrationOptimized,
                               double *calculation_err, int *err);

}

#endif
//
// File trailer for calibrateOneCamera.h
//
// [EOF]
//
