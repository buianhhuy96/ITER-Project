//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: secondDerivCornerMetric.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SECONDDERIVCORNERMETRIC_H
#define SECONDDERIVCORNERMETRIC_H

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
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                               ::coder::array<float, 2U> &cxy,
                               ::coder::array<float, 2U> &c45,
                               ::coder::array<float, 2U> &b_Ix,
                               ::coder::array<float, 2U> &Iy,
                               ::coder::array<float, 2U> &Ixy,
                               ::coder::array<float, 2U> &I_45_45);

void secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                             ::coder::array<float, 2U> &cxy,
                             ::coder::array<float, 2U> &c45,
                             ::coder::array<float, 2U> &b_Ix,
                             ::coder::array<float, 2U> &Iy,
                             ::coder::array<float, 2U> &Ixy,
                             ::coder::array<float, 2U> &I_45_45);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for secondDerivCornerMetric.h
//
// [EOF]
//
