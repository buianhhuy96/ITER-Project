//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef CALIBRATEONECAMERA_H
#define CALIBRATEONECAMERA_H

// Include Files
#include "ITER_API_v2_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void calibrateOneCamera(const coder::array<unsigned char, 4U> &images,
                               double squareSize, const double boardSize[2],
                               struct0_T *b_cameraParameters,
                               coder::array<double, 1U> &errorOptimized,
                               double *calculation_err, int *err);

#endif
//
// File trailer for calibrateOneCamera.h
//
// [EOF]
//
