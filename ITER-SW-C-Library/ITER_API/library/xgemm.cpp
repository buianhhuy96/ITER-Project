//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemm.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xgemm.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : int m
//                int h_n
//                int k
//                const double A[15][15]
//                int ia0
//                int d_lda
//                const double e_B[8][15]
//                double c_C[15][15]
//                int ldc
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace blas {
void b_xgemm(int m, int h_n, int k, const double A[15][15], int ia0, int d_lda,
             const double e_B[8][15], double c_C[15][15], int ldc)
{
  if ((m != 0) && (h_n != 0)) {
    int b_br;
    int b_cr;
    int c_cr;
    int lastColC;
    lastColC = ldc * (h_n - 1);
    b_cr = 0;
    while (((ldc > 0) && (b_cr <= lastColC)) ||
           ((ldc < 0) && (b_cr >= lastColC))) {
      int b_i;
      int i1;
      b_i = b_cr + 1;
      i1 = b_cr + m;
      for (int ic{b_i}; ic <= i1; ic++) {
        (&c_C[0][0])[ic - 1] = 0.0;
      }
      b_cr += ldc;
    }
    b_br = -1;
    c_cr = 0;
    while (((ldc > 0) && (c_cr <= lastColC)) ||
           ((ldc < 0) && (c_cr >= lastColC))) {
      int ar;
      int i2;
      int i3;
      ar = ia0;
      i2 = c_cr + 1;
      i3 = c_cr + m;
      for (int b_ic{i2}; b_ic <= i3; b_ic++) {
        double temp;
        temp = 0.0;
        for (int w{0}; w < k; w++) {
          temp += (&A[0][0])[(w + ar) - 1] * (&e_B[0][0])[(w + b_br) + 1];
        }
        (&c_C[0][0])[b_ic - 1] += temp;
        ar += d_lda;
      }
      b_br += 15;
      c_cr += ldc;
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                int k
//                const double A[7][7]
//                int d_lda
//                const double e_B[15][15]
//                int b_ib0
//                int ldb
//                double c_C[8][15]
// Return Type  : void
//
void xgemm(int m, int h_n, int k, const double A[7][7], int d_lda,
           const double e_B[15][15], int b_ib0, int ldb, double c_C[8][15])
{
  if ((m != 0) && (h_n != 0)) {
    int b_br;
    int lastColC;
    b_br = b_ib0;
    lastColC = 15 * (h_n - 1);
    for (int b_cr{0}; b_cr <= lastColC; b_cr += 15) {
      int b_i;
      int i1;
      b_i = b_cr + 1;
      i1 = b_cr + m;
      for (int ic{b_i}; ic <= i1; ic++) {
        (&c_C[0][0])[ic - 1] = 0.0;
      }
    }
    for (int c_cr{0}; c_cr <= lastColC; c_cr += 15) {
      int ar;
      int i2;
      ar = -1;
      i2 = b_br + k;
      for (int c_ib{b_br}; c_ib < i2; c_ib++) {
        int i3;
        int i4;
        i3 = c_cr + 1;
        i4 = c_cr + m;
        for (int b_ic{i3}; b_ic <= i4; b_ic++) {
          (&c_C[0][0])[b_ic - 1] +=
              (&e_B[0][0])[c_ib - 1] * (&A[0][0])[(ar + b_ic) - c_cr];
        }
        ar += d_lda;
      }
      b_br += ldb;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xgemm.cpp
//
// [EOF]
//
