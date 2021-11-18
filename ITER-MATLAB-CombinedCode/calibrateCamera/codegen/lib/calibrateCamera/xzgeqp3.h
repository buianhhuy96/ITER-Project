//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XZGEQP3_H
#define XZGEQP3_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
void qrf(::coder::array<real_T, 2U> &A, int32_T m, int32_T g_n, int32_T nfxd,
         ::coder::array<real_T, 1U> &tau);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xzgeqp3.h
//
// [EOF]
//
