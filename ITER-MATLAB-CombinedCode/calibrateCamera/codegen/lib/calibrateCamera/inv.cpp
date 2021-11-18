//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: inv.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "inv.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const real_T b_x[3][3]
//                real_T y[3][3]
// Return Type  : void
//
namespace Codegen {
namespace coder {
void inv(const real_T b_x[3][3], real_T y[3][3])
{
  real_T c_x[3][3];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  for (p1 = 0; p1 < 3; p1++) {
    c_x[p1][0] = b_x[p1][0];
    c_x[p1][1] = b_x[p1][1];
    c_x[p1][2] = b_x[p1][2];
  }
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = std::abs(b_x[0][0]);
  absx21 = std::abs(b_x[0][1]);
  absx31 = std::abs(b_x[0][2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    c_x[0][0] = b_x[0][1];
    c_x[0][1] = b_x[0][0];
    c_x[1][0] = b_x[1][1];
    c_x[1][1] = b_x[1][0];
    c_x[2][0] = b_x[2][1];
    c_x[2][1] = b_x[2][0];
  } else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    c_x[0][0] = b_x[0][2];
    c_x[0][2] = b_x[0][0];
    c_x[1][0] = b_x[1][2];
    c_x[1][2] = b_x[1][0];
    c_x[2][0] = b_x[2][2];
    c_x[2][2] = b_x[2][0];
  } else {
    /* no actions */
  }
  c_x[0][1] /= c_x[0][0];
  c_x[0][2] /= c_x[0][0];
  c_x[1][1] -= c_x[1][0] * c_x[0][1];
  c_x[1][2] -= c_x[1][0] * c_x[0][2];
  c_x[2][1] -= c_x[2][0] * c_x[0][1];
  c_x[2][2] -= c_x[2][0] * c_x[0][2];
  if (std::abs(c_x[1][2]) > std::abs(c_x[1][1])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = c_x[0][1];
    c_x[0][1] = c_x[0][2];
    c_x[0][2] = absx11;
    absx11 = c_x[1][1];
    c_x[1][1] = c_x[1][2];
    c_x[1][2] = absx11;
    absx11 = c_x[2][1];
    c_x[2][1] = c_x[2][2];
    c_x[2][2] = absx11;
  }
  c_x[1][2] /= c_x[1][1];
  c_x[2][2] -= c_x[2][1] * c_x[1][2];
  absx11 = ((c_x[0][1] * c_x[1][2]) - c_x[0][2]) / c_x[2][2];
  absx21 = (-(c_x[0][1] + (c_x[2][1] * absx11))) / c_x[1][1];
  (&y[0][0])[p1] =
      ((1.0 - (c_x[1][0] * absx21)) - (c_x[2][0] * absx11)) / c_x[0][0];
  (&y[0][0])[p1 + 1] = absx21;
  (&y[0][0])[p1 + 2] = absx11;
  absx11 = (-c_x[1][2]) / c_x[2][2];
  absx21 = (1.0 - (c_x[2][1] * absx11)) / c_x[1][1];
  (&y[0][0])[p2] = (-((c_x[1][0] * absx21) + (c_x[2][0] * absx11))) / c_x[0][0];
  (&y[0][0])[p2 + 1] = absx21;
  (&y[0][0])[p2 + 2] = absx11;
  absx11 = 1.0 / c_x[2][2];
  absx21 = ((-c_x[2][1]) * absx11) / c_x[1][1];
  (&y[0][0])[p3] = (-((c_x[1][0] * absx21) + (c_x[2][0] * absx11))) / c_x[0][0];
  (&y[0][0])[p3 + 1] = absx21;
  (&y[0][0])[p3 + 2] = absx11;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for inv.cpp
//
// [EOF]
//
