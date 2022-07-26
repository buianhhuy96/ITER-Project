//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPUTECAMEXTRINSICS_H
#define COMPUTECAMEXTRINSICS_H

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
extern void
ComputeCamExtrinsics(const ::coder::array<unsigned char, 4U> &images,
                     double squareSize, const struct1_T *cameraParams,
                     ::coder::array<double, 3U> &b_imagePoints,
                     ::coder::array<bool, 1U> &validIdx,
                     ::coder::array<double, 3U> &camExtrinsics,
                     ::coder::array<double, 3U> &cameraPoses,
                     ::coder::array<double, 2U> &c_worldPoints, int *err);

}

#endif
//
// File trailer for ComputeCamExtrinsics.h
//
// [EOF]
//
