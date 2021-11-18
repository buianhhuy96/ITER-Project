//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef QRSOLVE_H
#define QRSOLVE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
void b_qrsolve(const ::coder::array<real_T, 2U> &A,
               const ::coder::array<real_T, 1U> &c_B, real_T d_Y[8]);

void qrsolve(const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &c_B, real_T b_Y_data[],
             int32_T *Y_size, int32_T *rankA);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for qrsolve.h
//
// [EOF]
//
