//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "inv.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_x[4][4]
//                double y[4][4]
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_inv(const double b_x[4][4], double y[4][4])
{
  double A[4][4];
  int i2;
  int pipk;
  signed char ipiv[4];
  signed char p[4];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

  for (int b_i = 0; b_i < 4; b_i++) {
    for (i2 = 0; i2 < 4; i2++) {
      y[b_i][i2] = 0.0;
      A[b_i][i2] = b_x[b_i][i2];
    }
    ipiv[b_i] = static_cast<signed char>(b_i + 1);
  }
  for (int j{0}; j < 3; j++) {
    double smax;
    int b_a;
    int b_jA;
    int b_tmp;
    int h_n;
    int jp1j;
    int mmj_tmp;
    mmj_tmp = 2 - j;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    h_n = 4 - j;
    b_a = 0;
    smax = std::abs((&A[0][0])[b_tmp]);
    for (int k{2}; k <= h_n; k++) {
      double s;
      s = std::abs((&A[0][0])[(b_tmp + k) - 1]);
      if (s > smax) {
        b_a = k - 1;
        smax = s;
      }
    }
    if ((&A[0][0])[b_tmp + b_a] != 0.0) {
      int i3;
      if (b_a != 0) {
        int ipiv_tmp;
        ipiv_tmp = j + b_a;
        ipiv[j] = static_cast<signed char>(ipiv_tmp + 1);
        for (int c_k{0}; c_k < 4; c_k++) {
          double temp;
          int b_i8;
          int b_temp_tmp;
          int temp_tmp;
          temp_tmp = c_k * 4;
          b_temp_tmp = j + temp_tmp;
          temp = (&A[0][0])[b_temp_tmp];
          b_i8 = ipiv_tmp + temp_tmp;
          (&A[0][0])[b_temp_tmp] = (&A[0][0])[b_i8];
          (&A[0][0])[b_i8] = temp;
        }
      }
      i3 = (b_tmp - j) + 4;
      for (int c_i{jp1j}; c_i <= i3; c_i++) {
        (&A[0][0])[c_i - 1] /= (&A[0][0])[b_tmp];
      }
    }
    b_jA = b_tmp;
    for (int c_j{0}; c_j <= mmj_tmp; c_j++) {
      double yjy_tmp;
      yjy_tmp = (&A[0][0])[(b_tmp + (c_j * 4)) + 4];
      if (yjy_tmp != 0.0) {
        int i5;
        int i7;
        i5 = b_jA + 6;
        i7 = (b_jA - j) + 8;
        for (int ijA{i5}; ijA <= i7; ijA++) {
          (&A[0][0])[ijA - 1] +=
              (&A[0][0])[((b_tmp + ijA) - b_jA) - 5] * (-yjy_tmp);
        }
      }
      b_jA += 4;
    }
  }
  for (int i1{0}; i1 < 4; i1++) {
    p[i1] = static_cast<signed char>(i1 + 1);
  }
  if (ipiv[0] > 1) {
    pipk = static_cast<int>(p[ipiv[0] - 1]);
    p[ipiv[0] - 1] = p[0];
    p[0] = static_cast<signed char>(pipk);
  }
  if (ipiv[1] > 2) {
    pipk = static_cast<int>(p[ipiv[1] - 1]);
    p[ipiv[1] - 1] = p[1];
    p[1] = static_cast<signed char>(pipk);
  }
  if (ipiv[2] > 3) {
    pipk = static_cast<int>(p[ipiv[2] - 1]);
    p[ipiv[2] - 1] = p[2];
    p[2] = static_cast<signed char>(pipk);
  }
  for (int b_k{0}; b_k < 4; b_k++) {
    int d_y_tmp;
    d_y_tmp = (static_cast<int>(p[b_k])) - 1;
    y[d_y_tmp][b_k] = 1.0;
    for (int d_j{b_k + 1}; d_j < 5; d_j++) {
      if (y[d_y_tmp][d_j - 1] != 0.0) {
        int i4;
        i4 = d_j + 1;
        for (int d_i{i4}; d_i < 5; d_i++) {
          y[d_y_tmp][d_i - 1] -= y[d_y_tmp][d_j - 1] * A[d_j - 1][d_i - 1];
        }
      }
    }
  }
  for (int b_j{0}; b_j < 4; b_j++) {
    int jBcol;
    jBcol = b_j * 4;
    for (int d_k{3}; d_k >= 0; d_k--) {
      double d;
      int i6;
      int kAcol;
      kAcol = d_k * 4;
      i6 = d_k + jBcol;
      d = (&y[0][0])[i6];
      if (d != 0.0) {
        (&y[0][0])[i6] = d / (&A[0][0])[d_k + kAcol];
        for (int e_i{0}; e_i < d_k; e_i++) {
          int i9;
          i9 = e_i + jBcol;
          (&y[0][0])[i9] -= (&y[0][0])[i6] * (&A[0][0])[e_i + kAcol];
        }
      }
    }
  }
}

//
// Arguments    : const double b_x[3][3]
//                double y[3][3]
// Return Type  : void
//
void inv(const double b_x[3][3], double y[3][3])
{
  double e_x[3][3];
  double absx11;
  double absx21;
  double absx31;
  double t2;
  double t3;
  int b_p1;
  int p2;
  int p3;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    e_x[b_i][0] = b_x[b_i][0];
    e_x[b_i][1] = b_x[b_i][1];
    e_x[b_i][2] = b_x[b_i][2];
  }
  b_p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = std::abs(b_x[0][0]);
  absx21 = std::abs(b_x[0][1]);
  absx31 = std::abs(b_x[0][2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    b_p1 = 3;
    p2 = 0;
    e_x[0][0] = b_x[0][1];
    e_x[0][1] = b_x[0][0];
    e_x[1][0] = b_x[1][1];
    e_x[1][1] = b_x[1][0];
    e_x[2][0] = b_x[2][1];
    e_x[2][1] = b_x[2][0];
  } else if (absx31 > absx11) {
    b_p1 = 6;
    p3 = 0;
    e_x[0][0] = b_x[0][2];
    e_x[0][2] = b_x[0][0];
    e_x[1][0] = b_x[1][2];
    e_x[1][2] = b_x[1][0];
    e_x[2][0] = b_x[2][2];
    e_x[2][2] = b_x[2][0];
  } else {
    /* no actions */
  }
  e_x[0][1] /= e_x[0][0];
  e_x[0][2] /= e_x[0][0];
  e_x[1][1] -= e_x[1][0] * e_x[0][1];
  e_x[1][2] -= e_x[1][0] * e_x[0][2];
  e_x[2][1] -= e_x[2][0] * e_x[0][1];
  e_x[2][2] -= e_x[2][0] * e_x[0][2];
  if (std::abs(e_x[1][2]) > std::abs(e_x[1][1])) {
    double b_t1;
    int b_itmp;
    b_itmp = p2;
    p2 = p3;
    p3 = b_itmp;
    b_t1 = e_x[0][1];
    e_x[0][1] = e_x[0][2];
    e_x[0][2] = b_t1;
    b_t1 = e_x[1][1];
    e_x[1][1] = e_x[1][2];
    e_x[1][2] = b_t1;
    b_t1 = e_x[2][1];
    e_x[2][1] = e_x[2][2];
    e_x[2][2] = b_t1;
  }
  e_x[1][2] /= e_x[1][1];
  e_x[2][2] -= e_x[2][1] * e_x[1][2];
  t3 = ((e_x[0][1] * e_x[1][2]) - e_x[0][2]) / e_x[2][2];
  t2 = (-(e_x[0][1] + (e_x[2][1] * t3))) / e_x[1][1];
  (&y[0][0])[b_p1] = ((1.0 - (e_x[1][0] * t2)) - (e_x[2][0] * t3)) / e_x[0][0];
  (&y[0][0])[b_p1 + 1] = t2;
  (&y[0][0])[b_p1 + 2] = t3;
  t3 = (-e_x[1][2]) / e_x[2][2];
  t2 = (1.0 - (e_x[2][1] * t3)) / e_x[1][1];
  (&y[0][0])[p2] = (-((e_x[1][0] * t2) + (e_x[2][0] * t3))) / e_x[0][0];
  (&y[0][0])[p2 + 1] = t2;
  (&y[0][0])[p2 + 2] = t3;
  t3 = 1.0 / e_x[2][2];
  t2 = ((-e_x[2][1]) * t3) / e_x[1][1];
  (&y[0][0])[p3] = (-((e_x[1][0] * t2) + (e_x[2][0] * t3))) / e_x[0][0];
  (&y[0][0])[p3 + 1] = t2;
  (&y[0][0])[p3 + 2] = t3;
}

} // namespace coder
} // namespace ITER

//
// File trailer for inv.cpp
//
// [EOF]
//
