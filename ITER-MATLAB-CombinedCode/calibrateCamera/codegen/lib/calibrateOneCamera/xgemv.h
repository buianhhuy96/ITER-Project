//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef XGEMV_H
#define XGEMV_H

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
namespace blas {
void xgemv(int m, int g_n, const ::coder::array<double, 2U> &A, int lda,
           const ::coder::array<double, 1U> &b_x,
           ::coder::array<double, 1U> &y);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xgemv.h
//
// [EOF]
//
