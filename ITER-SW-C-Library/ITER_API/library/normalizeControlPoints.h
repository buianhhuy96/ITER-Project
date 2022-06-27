//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef NORMALIZECONTROLPOINTS_H
#define NORMALIZECONTROLPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
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

#endif
//
// File trailer for normalizeControlPoints.h
//
// [EOF]
//
