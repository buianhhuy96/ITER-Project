//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isT.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "isT.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "det.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// IST Summary of this function goes here
//    Detailed explanation goes here
//
// Arguments    : const double T[4][4]
// Return Type  : bool
//
namespace ITER {
bool isT(const double T[4][4])
{
  double c_T[3][3];
  double z1[3];
  int k;
  bool exitg1;
  bool ret;
  bool y;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  z1[0] = std::abs(T[3][0]);
  z1[1] = std::abs(T[3][1]);
  z1[2] = std::abs(T[3][2]);
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (z1[k] > 1.0E-6) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  ret = ((!(std::abs(T[3][3] - 1.0) > 1.0E-6)) && (!y));
  // R = T(1:3,1:3);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    c_T[b_i][0] = T[b_i][0];
    c_T[b_i][1] = T[b_i][1];
    c_T[b_i][2] = T[b_i][2];
  }
  ret = ((!(std::abs(coder::det(c_T) - 1.0) > 1.0E-6)) && ret);
  return ret;
}

} // namespace ITER

//
// File trailer for isT.cpp
//
// [EOF]
//
