//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "inv.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double x[3][3]
//                double y[3][3]
// Return Type  : void
//
namespace coder {
void inv(const double x[3][3], double y[3][3])
{
  double b_x[3][3];
  double absx11;
  double absx21;
  double absx31;
  int p1;
  int p2;
  int p3;
  for (p1 = 0; p1 < 3; p1++) {
    b_x[p1][0] = x[p1][0];
    b_x[p1][1] = x[p1][1];
    b_x[p1][2] = x[p1][2];
  }
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = std::abs(x[0][0]);
  absx21 = std::abs(x[0][1]);
  absx31 = std::abs(x[0][2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    b_x[0][0] = x[0][1];
    b_x[0][1] = x[0][0];
    b_x[1][0] = x[1][1];
    b_x[1][1] = x[1][0];
    b_x[2][0] = x[2][1];
    b_x[2][1] = x[2][0];
  } else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    b_x[0][0] = x[0][2];
    b_x[0][2] = x[0][0];
    b_x[1][0] = x[1][2];
    b_x[1][2] = x[1][0];
    b_x[2][0] = x[2][2];
    b_x[2][2] = x[2][0];
  } else {
    /* no actions */
  }
  b_x[0][1] /= b_x[0][0];
  b_x[0][2] /= b_x[0][0];
  b_x[1][1] -= b_x[1][0] * b_x[0][1];
  b_x[1][2] -= b_x[1][0] * b_x[0][2];
  b_x[2][1] -= b_x[2][0] * b_x[0][1];
  b_x[2][2] -= b_x[2][0] * b_x[0][2];
  if (std::abs(b_x[1][2]) > std::abs(b_x[1][1])) {
    int itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = b_x[0][1];
    b_x[0][1] = b_x[0][2];
    b_x[0][2] = absx11;
    absx11 = b_x[1][1];
    b_x[1][1] = b_x[1][2];
    b_x[1][2] = absx11;
    absx11 = b_x[2][1];
    b_x[2][1] = b_x[2][2];
    b_x[2][2] = absx11;
  }
  b_x[1][2] /= b_x[1][1];
  b_x[2][2] -= b_x[2][1] * b_x[1][2];
  absx11 = ((b_x[0][1] * b_x[1][2]) - b_x[0][2]) / b_x[2][2];
  absx21 = (-(b_x[0][1] + (b_x[2][1] * absx11))) / b_x[1][1];
  (&y[0][0])[p1] =
      ((1.0 - (b_x[1][0] * absx21)) - (b_x[2][0] * absx11)) / b_x[0][0];
  (&y[0][0])[p1 + 1] = absx21;
  (&y[0][0])[p1 + 2] = absx11;
  absx11 = (-b_x[1][2]) / b_x[2][2];
  absx21 = (1.0 - (b_x[2][1] * absx11)) / b_x[1][1];
  (&y[0][0])[p2] = (-((b_x[1][0] * absx21) + (b_x[2][0] * absx11))) / b_x[0][0];
  (&y[0][0])[p2 + 1] = absx21;
  (&y[0][0])[p2 + 2] = absx11;
  absx11 = 1.0 / b_x[2][2];
  absx21 = ((-b_x[2][1]) * absx11) / b_x[1][1];
  (&y[0][0])[p3] = (-((b_x[1][0] * absx21) + (b_x[2][0] * absx11))) / b_x[0][0];
  (&y[0][0])[p3 + 1] = absx21;
  (&y[0][0])[p3 + 2] = absx11;
}

} // namespace coder

//
// File trailer for inv.cpp
//
// [EOF]
//