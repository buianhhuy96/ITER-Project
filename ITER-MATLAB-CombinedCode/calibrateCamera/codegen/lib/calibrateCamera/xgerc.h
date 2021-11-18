//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgerc.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XGERC_H
#define XGERC_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void xgerc(int32_T m, int32_T g_n, real_T alpha1, int32_T ix0,
           const ::coder::array<real_T, 1U> &y, ::coder::array<real_T, 2U> &A,
           int32_T ia0, int32_T b_lda);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xgerc.h
//
// [EOF]
//
