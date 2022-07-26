//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quat2rotm.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "quat2rotm.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_q[4]
//                double b_R[3][3]
// Return Type  : void
//
namespace ITER {
namespace coder {
void quat2rotm(const double b_q[4], double b_R[3][3])
{
  double tempR[9];
  double normRowMatrix[4];
  double z1[4];
  double b;
  for (int k{0}; k < 4; k++) {
    z1[k] = rt_powd_snf(b_q[k], 2.0);
  }
  b = 1.0 / std::sqrt(((z1[0] + z1[1]) + z1[2]) + z1[3]);
  for (int b_k{0}; b_k < 4; b_k++) {
    normRowMatrix[b_k] = b_q[b_k] * b;
  }
  double b_tempR_tmp;
  double c_tempR_tmp;
  double d_tempR_tmp;
  double e_tempR_tmp;
  double f_tempR_tmp;
  double g_tempR_tmp;
  double h_tempR_tmp;
  double i_tempR_tmp;
  double tempR_tmp;
  tempR_tmp = normRowMatrix[3] * normRowMatrix[3];
  b_tempR_tmp = normRowMatrix[2] * normRowMatrix[2];
  tempR[0] = 1.0 - (2.0 * (b_tempR_tmp + tempR_tmp));
  c_tempR_tmp = normRowMatrix[1] * normRowMatrix[2];
  d_tempR_tmp = normRowMatrix[0] * normRowMatrix[3];
  tempR[1] = 2.0 * (c_tempR_tmp - d_tempR_tmp);
  e_tempR_tmp = normRowMatrix[1] * normRowMatrix[3];
  f_tempR_tmp = normRowMatrix[0] * normRowMatrix[2];
  tempR[2] = 2.0 * (e_tempR_tmp + f_tempR_tmp);
  tempR[3] = 2.0 * (c_tempR_tmp + d_tempR_tmp);
  g_tempR_tmp = normRowMatrix[1] * normRowMatrix[1];
  tempR[4] = 1.0 - (2.0 * (g_tempR_tmp + tempR_tmp));
  h_tempR_tmp = normRowMatrix[2] * normRowMatrix[3];
  i_tempR_tmp = normRowMatrix[0] * normRowMatrix[1];
  tempR[5] = 2.0 * (h_tempR_tmp - i_tempR_tmp);
  tempR[6] = 2.0 * (e_tempR_tmp - f_tempR_tmp);
  tempR[7] = 2.0 * (h_tempR_tmp + i_tempR_tmp);
  tempR[8] = 1.0 - (2.0 * (g_tempR_tmp + b_tempR_tmp));
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    b_R[b_i][0] = tempR[3 * b_i];
    b_R[b_i][1] = tempR[(3 * b_i) + 1];
    b_R[b_i][2] = tempR[(3 * b_i) + 2];
  }
  for (int c_k{0}; c_k < 3; c_k++) {
    int R_tmp;
    R_tmp = 3 * c_k;
    b_R[0][c_k] = tempR[R_tmp];
    b_R[1][c_k] = tempR[R_tmp + 1];
    b_R[2][c_k] = tempR[R_tmp + 2];
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for quat2rotm.cpp
//
// [EOF]
//
