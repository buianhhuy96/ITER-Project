//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RRDetectionKnuckle.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef RRDETECTIONKNUCKLE_H
#define RRDETECTIONKNUCKLE_H

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
RRDetectionKnuckle(const ::coder::array<unsigned char, 4U> &ImgVGA,
                   const struct2_T *params, const double f_K[3][3],
                   ::coder::array<double, 2U> &markerCentroidsOrdered,
                   int *err);

}

#endif
//
// File trailer for RRDetectionKnuckle.h
//
// [EOF]
//
