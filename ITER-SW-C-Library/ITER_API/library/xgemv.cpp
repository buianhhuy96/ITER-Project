//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xgemv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : int m
//                int h_n
//                const ::coder::array<double, 2U> &A
//                int d_lda
//                const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace blas {
void b_xgemv(int m, int h_n, const ::coder::array<double, 2U> &A, int d_lda,
             const ::coder::array<double, 1U> &b_x,
             ::coder::array<double, 1U> &y)
{
  if ((m != 0) && (h_n != 0)) {
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
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[c_iy] = y[c_iy] + c;
      c_iy++;
      iac += d_lda;
    }
  }
}

//
// Arguments    : int m
//                const ::coder::array<double, 2U> &A
//                int d_lda
//                const ::coder::array<double, 2U> &b_x
//                double y[6]
// Return Type  : void
//
void c_xgemv(int m, const ::coder::array<double, 2U> &A, int d_lda,
             const ::coder::array<double, 2U> &b_x, double y[6])
{
  if (m != 0) {
    int b_i;
    int c_iy;
    int iac;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_iy = 0; b_iy < 6; b_iy++) {
      y[b_iy] = 0.0;
    }
    c_iy = 0;
    b_i = (d_lda * 5) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[ia - iac];
      }
      y[c_iy] += c;
      c_iy++;
      iac += d_lda;
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                const double A[15][15]
//                int d_lda
//                const double b_x[8]
//                double y[8][15]
// Return Type  : void
//
void d_xgemv(int m, int h_n, const double A[15][15], int d_lda,
             const double b_x[8], double y[8][15])
{
  if ((m != 0) && (h_n != 0)) {
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
      i1 = (iac + m) - 1;
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
// Arguments    : int m
//                int h_n
//                int d_lda
//                const double b_x[15]
//                int ix0
//                double y[8]
// Return Type  : void
//
void e_xgemv(int m, int h_n, int d_lda, const double b_x[15], int ix0,
             double y[8])
{
  if ((m != 0) && (h_n != 0)) {
    int b_i;
    int c_ix;
    int iac;
    c_ix = ix0;
    b_i = (d_lda * (h_n - 1)) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      int i1;
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        int i2;
        i2 = ia - iac;
        y[i2] += y[ia - 1] * (-b_x[c_ix - 1]);
      }
      c_ix++;
      iac += d_lda;
    }
  }
}

//
// Arguments    : int m
//                int h_n
//                const ::coder::array<double, 2U> &A
//                int ia0
//                int d_lda
//                const ::coder::array<double, 2U> &b_x
//                int ix0
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
void xgemv(int m, int h_n, const ::coder::array<double, 2U> &A, int ia0,
           int d_lda, const ::coder::array<double, 2U> &b_x, int ix0,
           ::coder::array<double, 1U> &y)
{
  if ((m != 0) && (h_n != 0)) {
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
    b_i = ia0 + (d_lda * (h_n - 1));
    iac = ia0;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      double c;
      int i1;
      c = 0.0;
      i1 = (iac + m) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        c += A[ia - 1] * b_x[((ix0 + ia) - iac) - 1];
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
} // namespace ITER

//
// File trailer for xgemv.cpp
//
// [EOF]
//
