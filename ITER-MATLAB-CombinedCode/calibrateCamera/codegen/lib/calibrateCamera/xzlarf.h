//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XZLARF_H
#define XZLARF_H

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
void xzlarf(int32_T m, int32_T g_n, int32_T iv0, real_T tau,
            ::coder::array<real_T, 2U> &b_C, int32_T ic0, int32_T ldc,
            ::coder::array<real_T, 1U> &work);

}
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xzlarf.h
//
// [EOF]
//
