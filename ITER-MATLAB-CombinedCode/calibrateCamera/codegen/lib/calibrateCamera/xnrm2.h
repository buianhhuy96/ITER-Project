//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XNRM2_H
#define XNRM2_H

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
real_T b_xnrm2(int32_T g_n, const real_T b_x[8], int32_T ix0);

real_T c_xnrm2(int32_T g_n, const real_T b_x[6], int32_T ix0);

real_T d_xnrm2(int32_T g_n, const real_T b_x[3][3], int32_T ix0);

real_T e_xnrm2(const real_T b_x[3]);

real_T xnrm2(int32_T g_n, const ::coder::array<real_T, 2U> &b_x, int32_T ix0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xnrm2.h
//
// [EOF]
//
