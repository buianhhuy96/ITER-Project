//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef CALIBRATEONECAMERA_H
#define CALIBRATEONECAMERA_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
extern void calibrateOneCamera(const ::coder::array<unsigned char, 4U> &images,
                               double squareSize, const int boardSize[2],
                               struct0_T *cameraParams,
                               ::coder::array<double, 1U> &errorOptimized,
                               double *MREf, ::coder::array<bool, 1U> &validIdx,
                               int *err);

void reprojectWrapper(const ::coder::array<double, 1U> &paramsVector,
                      const k_struct_T *cameraParams,
                      const ::coder::array<double, 2U> &c_worldPoints,
                      const ::coder::array<double, 3U> &e_ImagePoints,
                      ::coder::array<double, 1U> &b_cost);

} // namespace ITER

#endif
//
// File trailer for calibrateOneCamera.h
//
// [EOF]
//
