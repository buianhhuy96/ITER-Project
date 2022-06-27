//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearForm_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : bool obj_hasLinear
//                int obj_nvar
//                double workspace[8][15]
//                const double H[7][7]
//                const double f[8]
//                const double b_x[8]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void linearForm_(bool obj_hasLinear, int obj_nvar, double workspace[8][15],
                 const double H[7][7], const double f[8], const double b_x[8])
{
  int beta1;
  beta1 = 0;
  if (obj_hasLinear) {
    if ((static_cast<int>(obj_nvar < 4)) != 0) {
      for (int b_i{0}; b_i < obj_nvar; b_i++) {
        (&workspace[0][0])[b_i] = f[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i = 0; b_i < obj_nvar; b_i++) {
        (&workspace[0][0])[b_i] = f[b_i];
      }
    }
    beta1 = 1;
  }
  if (obj_nvar != 0) {
    int b_ix;
    int c_i;
    int iac;
    if (beta1 != 1) {
      if ((static_cast<int>(obj_nvar < 4)) != 0) {
        for (int b_iy{0}; b_iy < obj_nvar; b_iy++) {
          (&workspace[0][0])[b_iy] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_iy = 0; b_iy < obj_nvar; b_iy++) {
          (&workspace[0][0])[b_iy] = 0.0;
        }
      }
    }
    b_ix = 0;
    c_i = (obj_nvar * (obj_nvar - 1)) + 1;
    iac = 1;
    while (((obj_nvar > 0) && (iac <= c_i)) ||
           ((obj_nvar < 0) && (iac >= c_i))) {
      double c;
      int i1;
      c = 0.5 * b_x[b_ix];
      i1 = (iac + obj_nvar) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        int i2;
        i2 = ia - iac;
        (&workspace[0][0])[i2] += (&H[0][0])[ia - 1] * c;
      }
      b_ix++;
      iac += obj_nvar;
    }
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for linearForm_.cpp
//
// [EOF]
//
