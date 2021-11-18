//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xzgeqp3.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &A
//                int32_T m
//                int32_T g_n
//                int32_T nfxd
//                ::coder::array<real_T, 1U> &tau
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
void qrf(::coder::array<real_T, 2U> &A, int32_T m, int32_T g_n, int32_T nfxd,
         ::coder::array<real_T, 1U> &tau)
{
  ::coder::array<real_T, 1U> work;
  real_T b_atmp;
  int32_T b_ii;
  int32_T b_lda;
  int32_T mmi;
  b_lda = A.size(0);
  b_ii = A.size(1);
  work.set_size(b_ii);
  for (mmi = 0; mmi < b_ii; mmi++) {
    work[mmi] = 0.0;
  }
  for (int32_T b_i{0}; b_i < nfxd; b_i++) {
    b_ii = (b_i * b_lda) + b_i;
    mmi = m - b_i;
    if ((b_i + 1) < m) {
      b_atmp = A[b_ii];
      tau[b_i] = xzlarfg(mmi, &b_atmp, A, b_ii + 2);
      A[b_ii] = b_atmp;
    } else {
      tau[b_i] = 0.0;
    }
    if ((b_i + 1) < g_n) {
      b_atmp = A[b_ii];
      A[b_ii] = 1.0;
      xzlarf(mmi, (g_n - b_i) - 1, b_ii + 1, tau[b_i], A, (b_ii + b_lda) + 1,
             b_lda, work);
      A[b_ii] = b_atmp;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xzgeqp3.cpp
//
// [EOF]
//
