//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef COMPUTECAMEXTRINSICS_H
#define COMPUTECAMEXTRINSICS_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void ComputeCamExtrinsics(
    const coder::array<unsigned char, 4U> &images, double squareSize,
    const struct1_T *cameraParams, coder::array<double, 3U> &b_imagePoints,
    coder::array<bool, 1U> &validIdx, coder::array<double, 3U> &camExtrinsics,
    coder::array<double, 3U> &cameraPoses,
    coder::array<double, 2U> &c_worldPoints, int *err);

#endif
//
// File trailer for ComputeCamExtrinsics.h
//
// [EOF]
//
