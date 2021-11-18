//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xzlarf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int m
//                int g_n
//                int iv0
//                double tau
//                ::coder::array<double, 2U> &b_C
//                int ic0
//                int ldc
//                ::coder::array<double, 1U> &work
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
void xzlarf(int m, int g_n, int iv0, double tau,
            ::coder::array<double, 2U> &b_C, int ic0, int ldc,
            ::coder::array<double, 1U> &work)
{
  int b_i;
  int ia;
  int lastc;
  int lastv;
  if (tau != 0.0) {
    bool exitg1;
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
    lastc = g_n - 1;
    exitg1 = false;
    while ((!exitg1) && ((lastc + 1) > 0)) {
      int exitg2;
      b_i = ic0 + (lastc * ldc);
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
    lastc = -1;
  }
  if (lastv > 0) {
    double c;
    int b_iy;
    int c_i;
    int iac;
    if ((lastc + 1) != 0) {
      for (b_iy = 0; b_iy <= lastc; b_iy++) {
        work[b_iy] = 0.0;
      }
      b_iy = 0;
      c_i = ic0 + (ldc * lastc);
      iac = ic0;
      while (((ldc > 0) && (iac <= c_i)) || ((ldc < 0) && (iac >= c_i))) {
        c = 0.0;
        b_i = (iac + lastv) - 1;
        for (ia = iac; ia <= b_i; ia++) {
          c += b_C[ia - 1] * b_C[((iv0 + ia) - iac) - 1];
        }
        work[b_iy] = work[b_iy] + c;
        b_iy++;
        iac += ldc;
      }
    }
    if (!((-tau) == 0.0)) {
      b_i = ic0;
      for (b_iy = 0; b_iy <= lastc; b_iy++) {
        if (work[b_iy] != 0.0) {
          c = work[b_iy] * (-tau);
          c_i = lastv + b_i;
          for (iac = b_i; iac < c_i; iac++) {
            b_C[iac - 1] = b_C[iac - 1] + (b_C[((iv0 + iac) - b_i) - 1] * c);
          }
        }
        b_i += ldc;
      }
    }
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
