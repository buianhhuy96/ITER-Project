//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef NORMALIZECONTROLPOINTS_H
#define NORMALIZECONTROLPOINTS_H

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
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void b_normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                              ::coder::array<double, 2U> &ptsNorm,
                              double normMatrixInv[3][3]);

void normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                            ::coder::array<double, 2U> &ptsNorm,
                            double normMatrixInv[3][3]);

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for normalizeControlPoints.h
//
// [EOF]
//
