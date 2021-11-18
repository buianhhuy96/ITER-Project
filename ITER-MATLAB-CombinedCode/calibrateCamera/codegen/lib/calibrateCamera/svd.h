//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef SVD_H
#define SVD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
void b_svd(const ::coder::array<real_T, 2U> &A, ::coder::array<real_T, 2U> &U,
           real_T s_data[], int32_T *s_size, real_T V[6][6]);

void c_svd(const real_T A[3][3], real_T U[3][3], real_T s[3], real_T V[3][3]);

void svd(const ::coder::array<real_T, 2U> &A, real_T d_U_data[],
         int32_T *U_size);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for svd.h
//
// [EOF]
//
