//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: det.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "det.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_x[3][3]
// Return Type  : double
//
namespace coder {
double det(const double b_x[3][3])
{
  double A[3][3];
  double y;
  signed char ipiv[3];
  bool isodd;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    A[b_i][0] = b_x[b_i][0];
    A[b_i][1] = b_x[b_i][1];
    A[b_i][2] = b_x[b_i][2];
    ipiv[b_i] = static_cast<signed char>(b_i + 1);
  }
  for (int j{0}; j < 2; j++) {
    double smax;
    int b_a;
    int b_tmp;
    int h_n;
    int jA;
    int jp1j;
    int mmj_tmp;
    mmj_tmp = 1 - j;
    b_tmp = j * 4;
    jp1j = b_tmp + 2;
    h_n = 3 - j;
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
      int i1;
      if (b_a != 0) {
        double temp;
        int ipiv_tmp;
        ipiv_tmp = j + b_a;
        ipiv[j] = static_cast<signed char>(ipiv_tmp + 1);
        temp = (&A[0][0])[j];
        (&A[0][0])[j] = (&A[0][0])[ipiv_tmp];
        (&A[0][0])[ipiv_tmp] = temp;
        temp = (&A[0][0])[j + 3];
        (&A[0][0])[j + 3] = (&A[0][0])[ipiv_tmp + 3];
        (&A[0][0])[ipiv_tmp + 3] = temp;
        temp = (&A[0][0])[j + 6];
        (&A[0][0])[j + 6] = (&A[0][0])[ipiv_tmp + 6];
        (&A[0][0])[ipiv_tmp + 6] = temp;
      }
      i1 = (b_tmp - j) + 3;
      for (int c_i{jp1j}; c_i <= i1; c_i++) {
        (&A[0][0])[c_i - 1] /= (&A[0][0])[b_tmp];
      }
    }
    jA = b_tmp;
    for (int b_j{0}; b_j <= mmj_tmp; b_j++) {
      double yjy_tmp;
      yjy_tmp = (&A[0][0])[(b_tmp + (b_j * 3)) + 3];
      if (yjy_tmp != 0.0) {
        int i2;
        int i3;
        i2 = jA + 5;
        i3 = (jA - j) + 6;
        for (int ijA{i2}; ijA <= i3; ijA++) {
          (&A[0][0])[ijA - 1] +=
              (&A[0][0])[((b_tmp + ijA) - jA) - 4] * (-yjy_tmp);
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = (A[0][0] * A[1][1]) * A[2][2];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

} // namespace coder

//
// File trailer for det.cpp
//
// [EOF]
//
