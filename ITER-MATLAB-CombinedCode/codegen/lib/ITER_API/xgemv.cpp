//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int m
//                int h_n
//                const ::coder::array<double, 2U> &A
//                int c_lda
//                const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xgemv(int m, int h_n, const ::coder::array<double, 2U> &A, int c_lda,
           const ::coder::array<double, 1U> &b_x, ::coder::array<double, 1U> &y)
{
  if ((m != 0) && (h_n != 0)) {
    int b_i;
    int c_iy;
    int iac;
    for (int b_iy{0}; b_iy < h_n; b_iy++) {
      y[b_iy] = 0.0;
    }
    c_iy = 0;
    b_i = (c_lda * (h_n - 1)) + 1;
    iac = 1;
    while (((c_lda > 0) && (iac <= b_i)) || ((c_lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[c_iy] = y[c_iy] + c;
      c_iy++;
      iac += c_lda;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xgemv.cpp
//
// [EOF]
//
