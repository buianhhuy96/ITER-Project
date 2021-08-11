//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: det.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "det.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[3][3]
// Return Type  : double
//
namespace coder {
double det(const double x[3][3])
{
  double b_x[3][3];
  double y;
  int i;
  signed char ipiv[3];
  boolean_T isodd;
  for (i = 0; i < 3; i++) {
    b_x[i][0] = x[i][0];
    b_x[i][1] = x[i][1];
    b_x[i][2] = x[i][2];
    ipiv[i] = static_cast<signed char>(i + 1);
  }
  for (int j{0}; j < 2; j++) {
    double smax;
    int a;
    int b_tmp;
    int jA;
    int jp1j;
    int k;
    int mmj_tmp;
    mmj_tmp = 1 - j;
    b_tmp = j * 4;
    jp1j = b_tmp + 2;
    jA = 3 - j;
    a = 0;
    smax = std::abs((&b_x[0][0])[b_tmp]);
    for (k = 2; k <= jA; k++) {
      double s;
      s = std::abs((&b_x[0][0])[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if ((&b_x[0][0])[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = static_cast<signed char>(jA + 1);
        smax = (&b_x[0][0])[j];
        (&b_x[0][0])[j] = (&b_x[0][0])[jA];
        (&b_x[0][0])[jA] = smax;
        smax = (&b_x[0][0])[j + 3];
        (&b_x[0][0])[j + 3] = (&b_x[0][0])[jA + 3];
        (&b_x[0][0])[jA + 3] = smax;
        smax = (&b_x[0][0])[j + 6];
        (&b_x[0][0])[j + 6] = (&b_x[0][0])[jA + 6];
        (&b_x[0][0])[jA + 6] = smax;
      }
      i = (b_tmp - j) + 3;
      for (jA = jp1j; jA <= i; jA++) {
        (&b_x[0][0])[jA - 1] /= (&b_x[0][0])[b_tmp];
      }
    }
    jA = b_tmp;
    for (a = 0; a <= mmj_tmp; a++) {
      smax = (&b_x[0][0])[(b_tmp + (a * 3)) + 3];
      if (smax != 0.0) {
        i = jA + 5;
        k = (jA - j) + 6;
        for (jp1j = i; jp1j <= k; jp1j++) {
          (&b_x[0][0])[jp1j - 1] +=
              (&b_x[0][0])[((b_tmp + jp1j) - jA) - 4] * (-smax);
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = (b_x[0][0] * b_x[1][1]) * b_x[2][2];
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
