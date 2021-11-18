//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgerc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xgerc.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int32_T m
//                int32_T g_n
//                real_T alpha1
//                int32_T ix0
//                const ::coder::array<real_T, 1U> &y
//                ::coder::array<real_T, 2U> &A
//                int32_T ia0
//                int32_T b_lda
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void xgerc(int32_T m, int32_T g_n, real_T alpha1, int32_T ix0,
           const ::coder::array<real_T, 1U> &y, ::coder::array<real_T, 2U> &A,
           int32_T ia0, int32_T b_lda)
{
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    for (int32_T j{0}; j < g_n; j++) {
      if (y[j] != 0.0) {
        real_T temp;
        int32_T b_i;
        temp = y[j] * alpha1;
        b_i = m + jA;
        for (int32_T ijA{jA}; ijA < b_i; ijA++) {
          A[ijA - 1] = A[ijA - 1] + (A[((ix0 + ijA) - jA) - 1] * temp);
        }
      }
      jA += b_lda;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xgerc.cpp
//
// [EOF]
//
