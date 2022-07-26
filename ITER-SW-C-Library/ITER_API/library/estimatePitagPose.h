//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: estimatePitagPose.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ESTIMATEPITAGPOSE_H
#define ESTIMATEPITAGPOSE_H

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
extern void estimatePitagPose(const ::coder::array<double, 2U> &b_imagePoints,
                              const double b_robotpose[4][4],
                              const ::coder::array<double, 2U> &b_worldpts,
                              const double handeye[4][4],
                              const struct1_T *cameraParams,
                              double poseCamera[4][4], double poseRobot[4][4]);

}

#endif
//
// File trailer for estimatePitagPose.h
//
// [EOF]
//
