//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef XZLARF_H
#define XZLARF_H

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
namespace reflapack {
void xzlarf(int m, int g_n, int iv0, double tau,
            ::coder::array<double, 2U> &b_C, int ic0, int ldc,
            ::coder::array<double, 1U> &work);

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
