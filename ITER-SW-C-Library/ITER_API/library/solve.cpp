//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "solve.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const y_struct_T *obj
//                double rhs[8]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void solve(const y_struct_T *obj, double rhs[8])
{
  int h_n;
  int n_tmp_tmp;
  n_tmp_tmp = obj->ndims;
  if (obj->ndims != 0) {
    for (int j{0}; j < n_tmp_tmp; j++) {
      double temp;
      int b_jA;
      b_jA = j * obj->ldm;
      temp = rhs[j];
      for (int b_i{0}; b_i < j; b_i++) {
        temp -= (&obj->FMat[0][0])[b_jA + b_i] * rhs[b_i];
      }
      rhs[j] = temp / (&obj->FMat[0][0])[b_jA + j];
    }
  }
  h_n = obj->ndims;
  if (obj->ndims != 0) {
    for (int b_j{h_n}; b_j >= 1; b_j--) {
      int jjA;
      jjA = (b_j + ((b_j - 1) * obj->ldm)) - 1;
      rhs[b_j - 1] /= (&obj->FMat[0][0])[jjA];
      for (int c_i{0}; c_i <= (b_j - 2); c_i++) {
        int c_ix;
        c_ix = (b_j - c_i) - 2;
        rhs[c_ix] -= rhs[b_j - 1] * (&obj->FMat[0][0])[(jjA - c_i) - 1];
      }
    }
  }
}

} // namespace CholManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for solve.cpp
//
// [EOF]
//
