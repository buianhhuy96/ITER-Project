//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xzlarf.h"
#include "rt_nonfinite.h"
#include "xgerc.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int32_T m
//                int32_T g_n
//                int32_T iv0
//                real_T tau
//                ::coder::array<real_T, 2U> &b_C
//                int32_T ic0
//                int32_T ldc
//                ::coder::array<real_T, 1U> &work
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
void xzlarf(int32_T m, int32_T g_n, int32_T iv0, real_T tau,
            ::coder::array<real_T, 2U> &b_C, int32_T ic0, int32_T ldc,
            ::coder::array<real_T, 1U> &work)
{
  int32_T b_i;
  int32_T ia;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg1;
    lastv = m;
    b_i = iv0 + m;
    exitg1 = false;
    while ((!exitg1) && (lastv > 0)) {
      if (b_C[b_i - 2] == 0.0) {
        lastv--;
        b_i--;
      } else {
        exitg1 = true;
      }
    }
    lastc = g_n;
    exitg1 = false;
    while ((!exitg1) && (lastc > 0)) {
      int32_T exitg2;
      b_i = ic0 + ((lastc - 1) * ldc);
      ia = b_i;
      do {
        exitg2 = 0;
        if (ia <= ((b_i + lastv) - 1)) {
          if (b_C[ia - 1] != 0.0) {
            exitg2 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    if (lastc != 0) {
      int32_T b_iy;
      int32_T iac;
      for (b_iy = 0; b_iy < lastc; b_iy++) {
        work[b_iy] = 0.0;
      }
      b_iy = 0;
      b_i = ic0 + (ldc * (lastc - 1));
      iac = ic0;
      while (((ldc > 0) && (iac <= b_i)) || ((ldc < 0) && (iac >= b_i))) {
        real_T c;
        int32_T d_i;
        c = 0.0;
        d_i = (iac + lastv) - 1;
        for (ia = iac; ia <= d_i; ia++) {
          c += b_C[ia - 1] * b_C[((iv0 + ia) - iac) - 1];
        }
        work[b_iy] = work[b_iy] + c;
        b_iy++;
        iac += ldc;
      }
    }
    blas::xgerc(lastv, lastc, -tau, iv0, work, b_C, ic0, ldc);
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xzlarf.cpp
//
// [EOF]
//
