//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : int b_m
//                int h_n
//                const double A[15][15]
//                int d_lda
//                const double b_x[8]
//                double y[8][15]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xgemv(int b_m, int h_n, const double A[15][15], int d_lda,
             const double b_x[8], double y[8][15])
{
  if ((b_m != 0) && (h_n != 0)) {
    int b_i;
    int c_iy;
    int iac;
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int b_iy{0}; b_iy < h_n; b_iy++) {
        (&y[0][0])[b_iy] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_iy = 0; b_iy < h_n; b_iy++) {
        (&y[0][0])[b_iy] = 0.0;
      }
    }
    c_iy = 0;
    b_i = (d_lda * (h_n - 1)) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + b_m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += (&A[0][0])[ia - 1] * b_x[ia - iac];
      }
      (&y[0][0])[c_iy] += c;
      c_iy++;
      iac += d_lda;
    }
  }
}

//
// Arguments    : int b_m
//                int h_n
//                int d_lda
//                const double b_x[15]
//                int ix0
//                double y[8]
// Return Type  : void
//
void c_xgemv(int b_m, int h_n, int d_lda, const double b_x[15], int ix0,
             double y[8])
{
  if ((b_m != 0) && (h_n != 0)) {
    int b_i;
    int b_ix;
    int iac;
    b_ix = ix0;
    b_i = (d_lda * (h_n - 1)) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      int i1;
      i1 = (iac + b_m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        int i2;
        i2 = ia - iac;
        y[i2] += y[ia - 1] * (-b_x[b_ix - 1]);
      }
      b_ix++;
      iac += d_lda;
    }
  }
}

//
// Arguments    : int b_m
//                int h_n
//                const ::coder::array<double, 2U> &A
//                int d_lda
//                const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
void xgemv(int b_m, int h_n, const ::coder::array<double, 2U> &A, int d_lda,
           const ::coder::array<double, 1U> &b_x, ::coder::array<double, 1U> &y)
{
  if ((b_m != 0) && (h_n != 0)) {
    int b_i;
    int c_iy;
    int iac;
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int b_iy{0}; b_iy < h_n; b_iy++) {
        y[b_iy] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_iy = 0; b_iy < h_n; b_iy++) {
        y[b_iy] = 0.0;
      }
    }
    c_iy = 0;
    b_i = (d_lda * (h_n - 1)) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + b_m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[c_iy] = y[c_iy] + c;
      c_iy++;
      iac += d_lda;
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
