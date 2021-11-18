//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef NORMALIZECONTROLPOINTS_H
#define NORMALIZECONTROLPOINTS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void normalizeControlPoints(const ::coder::array<real_T, 2U> &pts,
                            ::coder::array<real_T, 2U> &ptsNorm,
                            real_T normMatrixInv[3][3]);

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
