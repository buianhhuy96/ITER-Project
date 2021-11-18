//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "xzlarf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int m
//                int h_n
//                int iv0
//                double tau
//                ::coder::array<double, 2U> &b_C
//                int ic0
//                int ldc
//                ::coder::array<double, 1U> &work
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzlarf(int m, int h_n, int iv0, double tau,
            ::coder::array<double, 2U> &b_C, int ic0, int ldc,
            ::coder::array<double, 1U> &work)
{
  int lastc;
  int lastv;
  if (tau != 0.0) {
    int b_i;
    int b_lastc;
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
    b_lastc = h_n - 1;
    exitg1 = false;
    while ((!exitg1) && ((b_lastc + 1) > 0)) {
      int coltop;
      int exitg2;
      int ia;
      coltop = ic0 + (b_lastc * ldc);
      ia = coltop;
      do {
        exitg2 = 0;
        if (ia <= ((coltop + lastv) - 1)) {
          if (b_C[ia - 1] != 0.0) {
            exitg2 = 1;
          } else {
            ia++;
          }
        } else {
          b_lastc--;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
    lastc = b_lastc;
  } else {
    lastv = 0;
    lastc = -1;
  }
  if (lastv > 0) {
    if ((lastc + 1) != 0) {
      int c_i;
      int d_iy;
      int iac;
      for (int c_iy{0}; c_iy <= lastc; c_iy++) {
        work[c_iy] = 0.0;
      }
      d_iy = 0;
      c_i = ic0 + (ldc * lastc);
      iac = ic0;
      while (((ldc > 0) && (iac <= c_i)) || ((ldc < 0) && (iac >= c_i))) {
        double c;
        int i2;
        c = 0.0;
        i2 = (iac + lastv) - 1;
        for (int b_ia{iac}; b_ia <= i2; b_ia++) {
          c += b_C[b_ia - 1] * b_C[((iv0 + b_ia) - iac) - 1];
        }
        work[d_iy] = work[d_iy] + c;
        d_iy++;
        iac += ldc;
      }
    }
    if (!((-tau) == 0.0)) {
      int jA;
      jA = ic0;
      for (int j{0}; j <= lastc; j++) {
        if (work[j] != 0.0) {
          double temp;
          int i1;
          temp = work[j] * (-tau);
          i1 = lastv + jA;
          for (int ijA{jA}; ijA < i1; ijA++) {
            b_C[ijA - 1] = b_C[ijA - 1] + (b_C[((iv0 + ijA) - jA) - 1] * temp);
          }
        }
        jA += ldc;
      }
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzlarf.cpp
//
// [EOF]
//
