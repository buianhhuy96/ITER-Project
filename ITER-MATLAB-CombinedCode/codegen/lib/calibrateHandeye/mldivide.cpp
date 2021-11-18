//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double A[3][3]
//                const double b_B[3]
//                double h_Y[3]
// Return Type  : void
//
namespace coder {
void mldivide(const double A[3][3], const double b_B[3], double h_Y[3])
{
  double e_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  for (int b_i{0}; b_i < 3; b_i++) {
    e_A[b_i][0] = A[b_i][0];
    e_A[b_i][1] = A[b_i][1];
    e_A[b_i][2] = A[b_i][2];
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(A[0][0]);
  a21 = std::abs(A[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(A[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  e_A[0][r2] = A[0][r2] / A[0][r1];
  e_A[0][r3] /= e_A[0][r1];
  e_A[1][r2] -= e_A[0][r2] * e_A[1][r1];
  e_A[1][r3] -= e_A[0][r3] * e_A[1][r1];
  e_A[2][r2] -= e_A[0][r2] * e_A[2][r1];
  e_A[2][r3] -= e_A[0][r3] * e_A[2][r1];
  if (std::abs(e_A[1][r3]) > std::abs(e_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  e_A[1][r3] /= e_A[1][r2];
  e_A[2][r3] -= e_A[1][r3] * e_A[2][r2];
  h_Y[1] = b_B[r2] - (b_B[r1] * e_A[0][r2]);
  h_Y[2] = (b_B[r3] - (b_B[r1] * e_A[0][r3])) - (h_Y[1] * e_A[1][r3]);
  h_Y[2] /= e_A[2][r3];
  h_Y[0] = b_B[r1] - (h_Y[2] * e_A[2][r1]);
  h_Y[1] -= h_Y[2] * e_A[2][r2];
  h_Y[1] /= e_A[1][r2];
  h_Y[0] -= h_Y[1] * e_A[1][r1];
  h_Y[0] /= e_A[0][r1];
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
