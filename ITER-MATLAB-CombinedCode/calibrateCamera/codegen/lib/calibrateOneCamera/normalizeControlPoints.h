//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
namespace Codegen {
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                            ::coder::array<double, 2U> &ptsNorm,
                            double normMatrixInv[3][3]);

}
} // namespace geotrans
} // namespace images
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for normalizeControlPoints.h
//
// [EOF]
//
