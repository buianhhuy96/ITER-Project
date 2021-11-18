//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xunormqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xunormqr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_Q
//                ::coder::array<double, 1U> &b_C
//                const ::coder::array<double, 1U> &tau
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace lapack {
void xunormqr(const ::coder::array<double, 2U> &b_Q,
              ::coder::array<double, 1U> &b_C,
              const ::coder::array<double, 1U> &tau)
{
  int m;
  int mn;
  int u0;
  m = b_Q.size(0);
  u0 = b_Q.size(0);
  mn = b_Q.size(1);
  if (u0 <= mn) {
    mn = u0;
  }
  for (int j{0}; j < mn; j++) {
    if (tau[j] != 0.0) {
      double wj;
      int b_i;
      wj = b_C[j];
      u0 = j + 2;
      for (b_i = u0; b_i <= m; b_i++) {
        wj += b_Q[(b_i + (b_Q.size(0) * j)) - 1] * b_C[b_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        b_C[j] = b_C[j] - wj;
        for (b_i = u0; b_i <= m; b_i++) {
          b_C[b_i - 1] =
              b_C[b_i - 1] - (b_Q[(b_i + (b_Q.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xunormqr.cpp
//
// [EOF]
//
