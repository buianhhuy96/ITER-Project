//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: det.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "det.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double b_x[3][3]
// Return Type  : double
//
namespace coder {
double det(const double b_x[3][3])
{
  double c_x[3][3];
  double y;
  int b_i;
  signed char ipiv[3];
  bool isodd;
  for (b_i = 0; b_i < 3; b_i++) {
    c_x[b_i][0] = b_x[b_i][0];
    c_x[b_i][1] = b_x[b_i][1];
    c_x[b_i][2] = b_x[b_i][2];
    ipiv[b_i] = static_cast<signed char>(b_i + 1);
  }
  for (int j{0}; j < 2; j++) {
    double smax;
    int b_a;
    int b_tmp;
    int jA;
    int jp1j;
    int k;
    int mmj_tmp;
    mmj_tmp = 1 - j;
    b_tmp = j * 4;
    jp1j = b_tmp + 2;
    jA = 3 - j;
    b_a = 0;
    smax = std::abs((&c_x[0][0])[b_tmp]);
    for (k = 2; k <= jA; k++) {
      double s;
      s = std::abs((&c_x[0][0])[(b_tmp + k) - 1]);
      if (s > smax) {
        b_a = k - 1;
        smax = s;
      }
    }
    if ((&c_x[0][0])[b_tmp + b_a] != 0.0) {
      if (b_a != 0) {
        jA = j + b_a;
        ipiv[j] = static_cast<signed char>(jA + 1);
        smax = (&c_x[0][0])[j];
        (&c_x[0][0])[j] = (&c_x[0][0])[jA];
        (&c_x[0][0])[jA] = smax;
        smax = (&c_x[0][0])[j + 3];
        (&c_x[0][0])[j + 3] = (&c_x[0][0])[jA + 3];
        (&c_x[0][0])[jA + 3] = smax;
        smax = (&c_x[0][0])[j + 6];
        (&c_x[0][0])[j + 6] = (&c_x[0][0])[jA + 6];
        (&c_x[0][0])[jA + 6] = smax;
      }
      b_i = (b_tmp - j) + 3;
      for (jA = jp1j; jA <= b_i; jA++) {
        (&c_x[0][0])[jA - 1] /= (&c_x[0][0])[b_tmp];
      }
    }
    jA = b_tmp;
    for (b_a = 0; b_a <= mmj_tmp; b_a++) {
      smax = (&c_x[0][0])[(b_tmp + (b_a * 3)) + 3];
      if (smax != 0.0) {
        b_i = jA + 5;
        k = (jA - j) + 6;
        for (jp1j = b_i; jp1j <= k; jp1j++) {
          (&c_x[0][0])[jp1j - 1] +=
              (&c_x[0][0])[((b_tmp + jp1j) - jA) - 4] * (-smax);
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = (c_x[0][0] * c_x[1][1]) * c_x[2][2];
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
