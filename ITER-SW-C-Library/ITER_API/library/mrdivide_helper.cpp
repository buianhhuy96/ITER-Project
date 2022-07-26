//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mrdivide_helper.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double A[3][4]
//                const double e_B[3][3]
//                double g_Y[3][4]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
void mrdiv(const double A[3][4], const double e_B[3][3], double g_Y[3][4])
{
  double j_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    j_A[b_i][0] = e_B[b_i][0];
    j_A[b_i][1] = e_B[b_i][1];
    j_A[b_i][2] = e_B[b_i][2];
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(e_B[0][0]);
  a21 = std::abs(e_B[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(e_B[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  j_A[0][r2] = e_B[0][r2] / e_B[0][r1];
  j_A[0][r3] /= j_A[0][r1];
  j_A[1][r2] -= j_A[0][r2] * j_A[1][r1];
  j_A[1][r3] -= j_A[0][r3] * j_A[1][r1];
  j_A[2][r2] -= j_A[0][r2] * j_A[2][r1];
  j_A[2][r3] -= j_A[0][r3] * j_A[2][r1];
  if (std::abs(j_A[1][r3]) > std::abs(j_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  j_A[1][r3] /= j_A[1][r2];
  j_A[2][r3] -= j_A[1][r3] * j_A[2][r2];
  for (int k{0}; k < 4; k++) {
    g_Y[r1][k] = A[0][k] / j_A[0][r1];
    g_Y[r2][k] = A[1][k] - (g_Y[r1][k] * j_A[1][r1]);
    g_Y[r3][k] = A[2][k] - (g_Y[r1][k] * j_A[2][r1]);
    g_Y[r2][k] /= j_A[1][r2];
    g_Y[r3][k] -= g_Y[r2][k] * j_A[2][r2];
    g_Y[r3][k] /= j_A[2][r3];
    g_Y[r2][k] -= g_Y[r3][k] * j_A[1][r3];
    g_Y[r1][k] -= g_Y[r3][k] * j_A[0][r3];
    g_Y[r1][k] -= g_Y[r2][k] * j_A[0][r2];
  }
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for mrdivide_helper.cpp
//
// [EOF]
//
