//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgerc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xgerc.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : int m
//                int h_n
//                double alpha1
//                int ix0
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 2U> &A
//                int ia0
//                int d_lda
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace blas {
void xgerc(int m, int h_n, double alpha1, int ix0,
           const ::coder::array<double, 1U> &y, ::coder::array<double, 2U> &A,
           int ia0, int d_lda)
{
  if (!(alpha1 == 0.0)) {
    int b_jA;
    b_jA = ia0;
    for (int j{0}; j < h_n; j++) {
      if (y[j] != 0.0) {
        double temp;
        int b_i;
        temp = y[j] * alpha1;
        b_i = m + b_jA;
        for (int ijA{b_jA}; ijA < b_i; ijA++) {
          A[ijA - 1] = A[ijA - 1] + (A[((ix0 + ijA) - b_jA) - 1] * temp);
        }
      }
      b_jA += d_lda;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xgerc.cpp
//
// [EOF]
//
