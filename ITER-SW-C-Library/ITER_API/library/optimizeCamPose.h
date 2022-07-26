//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: optimizeCamPose.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef OPTIMIZECAMPOSE_H
#define OPTIMIZECAMPOSE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
double
optimizeCamPose_anonFcn1(const ::coder::array<double, 2U> &undist_imgMarkerPts,
                         const ::coder::array<double, 2U> &WptsTrio,
                         const double K11[4][3], const double est[7]);

}

#endif
//
// File trailer for optimizeCamPose.h
//
// [EOF]
//
