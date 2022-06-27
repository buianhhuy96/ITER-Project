//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xunormqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xunormqr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &Q
//                ::coder::array<double, 1U> &b_C
//                const ::coder::array<double, 1U> &tau
// Return Type  : void
//
namespace coder {
namespace internal {
namespace lapack {
void xunormqr(const ::coder::array<double, 2U> &Q,
              ::coder::array<double, 1U> &b_C,
              const ::coder::array<double, 1U> &tau)
{
  int b_m;
  int b_mn;
  int b_u1;
  int u0;
  b_m = Q.size(0);
  u0 = Q.size(0);
  b_u1 = Q.size(1);
  if (u0 <= b_u1) {
    b_mn = u0;
  } else {
    b_mn = b_u1;
  }
  for (int j{0}; j < b_mn; j++) {
    if (tau[j] != 0.0) {
      double wj;
      int b_i;
      wj = b_C[j];
      b_i = j + 2;
      for (int c_i{b_i}; c_i <= b_m; c_i++) {
        wj += Q[(c_i + (Q.size(0) * j)) - 1] * b_C[c_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        b_C[j] = b_C[j] - wj;
        for (int d_i{b_i}; d_i <= b_m; d_i++) {
          b_C[d_i - 1] = b_C[d_i - 1] - (Q[(d_i + (Q.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

//
// File trailer for xunormqr.cpp
//
// [EOF]
//
