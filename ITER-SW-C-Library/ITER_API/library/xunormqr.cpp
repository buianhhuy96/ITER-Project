//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xunormqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xunormqr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &Q
//                ::coder::array<double, 1U> &c_C
//                const ::coder::array<double, 1U> &tau
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace lapack {
void xunormqr(const ::coder::array<double, 2U> &Q,
              ::coder::array<double, 1U> &c_C,
              const ::coder::array<double, 1U> &tau)
{
  int b_mn;
  int b_u1;
  int m;
  int u0;
  m = Q.size(0);
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
      wj = c_C[j];
      b_i = j + 2;
      for (int c_i{b_i}; c_i <= m; c_i++) {
        wj += Q[(c_i + (Q.size(0) * j)) - 1] * c_C[c_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        c_C[j] = c_C[j] - wj;
        for (int d_i{b_i}; d_i <= m; d_i++) {
          c_C[d_i - 1] = c_C[d_i - 1] - (Q[(d_i + (Q.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xunormqr.cpp
//
// [EOF]
//
