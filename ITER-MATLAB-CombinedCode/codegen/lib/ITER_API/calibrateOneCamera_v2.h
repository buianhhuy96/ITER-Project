//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_v2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef CALIBRATEONECAMERA_V2_H
#define CALIBRATEONECAMERA_V2_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void calibrateOneCamera_v2(const coder::array<unsigned char, 4U> &images,
                                  double squareSize, const int boardSize[2],
                                  struct0_T *cameraParams,
                                  coder::array<double, 1U> &errorOptimized,
                                  double *MREf,
                                  coder::array<bool, 1U> &validIdx, int *err);

void reprojectWrapper(const coder::array<double, 1U> &paramsVector,
                      const c_struct_T *cameraParams,
                      const coder::array<double, 2U> &c_worldPoints,
                      const coder::array<double, 3U> &e_ImagePoints,
                      coder::array<double, 1U> &cost);

#endif
//
// File trailer for calibrateOneCamera_v2.h
//
// [EOF]
//
