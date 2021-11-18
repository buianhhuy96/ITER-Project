//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xunormqr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef XUNORMQR_H
#define XUNORMQR_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace lapack {
void xunormqr(const ::coder::array<double, 2U> &b_Q,
              ::coder::array<double, 1U> &b_C,
              const ::coder::array<double, 1U> &tau);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xunormqr.h
//
// [EOF]
//
