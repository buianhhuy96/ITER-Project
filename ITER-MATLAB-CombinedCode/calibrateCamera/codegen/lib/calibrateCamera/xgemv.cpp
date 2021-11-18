//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int32_T m
//                int32_T g_n
//                const ::coder::array<real_T, 2U> &A
//                int32_T b_lda
//                const ::coder::array<real_T, 1U> &b_x
//                ::coder::array<real_T, 1U> &y
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void xgemv(int32_T m, int32_T g_n, const ::coder::array<real_T, 2U> &A,
           int32_T b_lda, const ::coder::array<real_T, 1U> &b_x,
           ::coder::array<real_T, 1U> &y)
{
  if (m != 0) {
    int32_T b_i;
    int32_T b_iy;
    int32_T iac;
    for (b_iy = 0; b_iy < g_n; b_iy++) {
      y[b_iy] = 0.0;
    }
    b_iy = 0;
    b_i = (b_lda * (g_n - 1)) + 1;
    iac = 1;
    while (((b_lda > 0) && (iac <= b_i)) || ((b_lda < 0) && (iac >= b_i))) {
      real_T c;
      int32_T i1;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (int32_T ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[b_iy] = y[b_iy] + c;
      b_iy++;
      iac += b_lda;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xgemv.cpp
//
// [EOF]
//
