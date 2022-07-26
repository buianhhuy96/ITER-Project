//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: estimateKnucklePose.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ESTIMATEKNUCKLEPOSE_H
#define ESTIMATEKNUCKLEPOSE_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class cameraParameters;

}
} // namespace ITER

// Function Declarations
namespace ITER {
extern void estimateKnucklePose(
    const ::coder::array<double, 2U> &markerCentroidsOrdered,
    const double robotPose[4][4], const double c_worldPoints[3][5],
    const double handEyeCalibration[4][4], const struct1_T *cameraParams,
    double RT34est[4][4], double RT14[4][4], double *finalMRE, int *err);

void estimateKnucklePose_anonFcn1(
    const ::coder::array<double, 2U> &imagePointsTmp,
    const ::coder::array<double, 2U> &worldPointsTmp,
    const coder::cameraParameters *cameraParams, const double b_x[6],
    ::coder::array<double, 2U> &varargout_1);

} // namespace ITER

#endif
//
// File trailer for estimateKnucklePose.h
//
// [EOF]
//
