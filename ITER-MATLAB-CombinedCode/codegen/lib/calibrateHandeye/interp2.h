//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

#ifndef INTERP2_H
#define INTERP2_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace images {
namespace internal {
namespace coder {
void interp2_local(const ::coder::array<float, 2U> &V,
                   const ::coder::array<float, 2U> &Xq,
                   const ::coder::array<float, 2U> &Yq, float extrapval,
                   const ::coder::array<float, 2U> &e_X,
                   const ::coder::array<float, 2U> &h_Y,
                   ::coder::array<float, 2U> &Vq);

}
} // namespace internal
} // namespace images
} // namespace coder

#endif
//
// File trailer for interp2.h
//
// [EOF]
//
