//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdhseqr.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XDHSEQR_H
#define XDHSEQR_H

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
namespace internal {
namespace reflapack {
int b_eml_dlahqr(double x_h[4][4], double z[4][4]);

int eml_dlahqr(::coder::array<double, 2U> &x_h);

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xdhseqr.h
//
// [EOF]
//
