//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCalibrationPoses_internal.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef COMPUTECALIBRATIONPOSES_INTERNAL_H
#define COMPUTECALIBRATIONPOSES_INTERNAL_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
extern void computeCalibrationPoses_internal(
    const coder::array<unsigned char, 3U> &initialImage,
    const double initialRobotPose[4][4], const double handEyeEstimate[4][4],
    double roughDistance, const double angularBounds[3][2], double squareSize,
    const int boardSize[2], const struct1_T *factoryCamParam,
    const int requestedNumPoses[3], coder::array<double, 3U> &robotPoses,
    int *err);

#endif
//
// File trailer for computeCalibrationPoses_internal.h
//
// [EOF]
//
