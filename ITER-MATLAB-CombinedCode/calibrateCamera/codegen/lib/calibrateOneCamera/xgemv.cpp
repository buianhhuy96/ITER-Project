//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int m
//                int g_n
//                const ::coder::array<double, 2U> &A
//                int lda
//                const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void xgemv(int m, int g_n, const ::coder::array<double, 2U> &A, int lda,
           const ::coder::array<double, 1U> &b_x, ::coder::array<double, 1U> &y)
{
  if ((m != 0) && (g_n != 0)) {
    int b_i;
    int b_iy;
    int iac;
    for (b_iy = 0; b_iy < g_n; b_iy++) {
      y[b_iy] = 0.0;
    }
    b_iy = 0;
    b_i = (lda * (g_n - 1)) + 1;
    iac = 1;
    while (((lda > 0) && (iac <= b_i)) || ((lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[b_iy] = y[b_iy] + c;
      b_iy++;
      iac += lda;
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
