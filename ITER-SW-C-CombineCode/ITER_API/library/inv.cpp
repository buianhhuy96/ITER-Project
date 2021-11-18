//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "inv.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double b_x[3][3]
//                double y[3][3]
// Return Type  : void
//
namespace coder {
void inv(const double b_x[3][3], double y[3][3])
{
  double d_x[3][3];
  double absx11;
  double absx21;
  double absx31;
  double t2;
  double t3;
  int b_p1;
  int p2;
  int p3;
  for (int b_i{0}; b_i < 3; b_i++) {
    d_x[b_i][0] = b_x[b_i][0];
    d_x[b_i][1] = b_x[b_i][1];
    d_x[b_i][2] = b_x[b_i][2];
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
    d_x[0][0] = b_x[0][1];
    d_x[0][1] = b_x[0][0];
    d_x[1][0] = b_x[1][1];
    d_x[1][1] = b_x[1][0];
    d_x[2][0] = b_x[2][1];
    d_x[2][1] = b_x[2][0];
  } else if (absx31 > absx11) {
    b_p1 = 6;
    p3 = 0;
    d_x[0][0] = b_x[0][2];
    d_x[0][2] = b_x[0][0];
    d_x[1][0] = b_x[1][2];
    d_x[1][2] = b_x[1][0];
    d_x[2][0] = b_x[2][2];
    d_x[2][2] = b_x[2][0];
  } else {
    /* no actions */
  }
  d_x[0][1] /= d_x[0][0];
  d_x[0][2] /= d_x[0][0];
  d_x[1][1] -= d_x[1][0] * d_x[0][1];
  d_x[1][2] -= d_x[1][0] * d_x[0][2];
  d_x[2][1] -= d_x[2][0] * d_x[0][1];
  d_x[2][2] -= d_x[2][0] * d_x[0][2];
  if (std::abs(d_x[1][2]) > std::abs(d_x[1][1])) {
    double t1;
    int b_itmp;
    b_itmp = p2;
    p2 = p3;
    p3 = b_itmp;
    t1 = d_x[0][1];
    d_x[0][1] = d_x[0][2];
    d_x[0][2] = t1;
    t1 = d_x[1][1];
    d_x[1][1] = d_x[1][2];
    d_x[1][2] = t1;
    t1 = d_x[2][1];
    d_x[2][1] = d_x[2][2];
    d_x[2][2] = t1;
  }
  d_x[1][2] /= d_x[1][1];
  d_x[2][2] -= d_x[2][1] * d_x[1][2];
  t3 = ((d_x[0][1] * d_x[1][2]) - d_x[0][2]) / d_x[2][2];
  t2 = (-(d_x[0][1] + (d_x[2][1] * t3))) / d_x[1][1];
  (&y[0][0])[b_p1] = ((1.0 - (d_x[1][0] * t2)) - (d_x[2][0] * t3)) / d_x[0][0];
  (&y[0][0])[b_p1 + 1] = t2;
  (&y[0][0])[b_p1 + 2] = t3;
  t3 = (-d_x[1][2]) / d_x[2][2];
  t2 = (1.0 - (d_x[2][1] * t3)) / d_x[1][1];
  (&y[0][0])[p2] = (-((d_x[1][0] * t2) + (d_x[2][0] * t3))) / d_x[0][0];
  (&y[0][0])[p2 + 1] = t2;
  (&y[0][0])[p2 + 2] = t3;
  t3 = 1.0 / d_x[2][2];
  t2 = ((-d_x[2][1]) * t3) / d_x[1][1];
  (&y[0][0])[p3] = (-((d_x[1][0] * t2) + (d_x[2][0] * t3))) / d_x[0][0];
  (&y[0][0])[p3 + 1] = t2;
  (&y[0][0])[p3 + 2] = t3;
}

} // namespace coder

//
// File trailer for inv.cpp
//
// [EOF]
//
