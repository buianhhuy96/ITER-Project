//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solve1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "solve1.h"
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
namespace DynamicRegCholManager {
void solve(const y_struct_T *obj, double rhs[8])
{
  int b_i;
  int h_n;
  int p_n;
  h_n = obj->ndims - 2;
  if (obj->ndims != 0) {
    for (int j{0}; j <= (h_n + 1); j++) {
      int i1;
      int jjA;
      jjA = j + (j * obj->ldm);
      i1 = h_n - j;
      for (int c_i{0}; c_i <= i1; c_i++) {
        int c_ix;
        c_ix = (j + c_i) + 1;
        rhs[c_ix] -= rhs[j] * (&obj->FMat[0][0])[(jjA + c_i) + 1];
      }
    }
  }
  b_i = obj->ndims;
  for (int idx{0}; idx < b_i; idx++) {
    rhs[idx] /= (&obj->FMat[0][0])[idx + (obj->ldm * idx)];
  }
  p_n = obj->ndims;
  if (obj->ndims != 0) {
    for (int b_j{p_n}; b_j >= 1; b_j--) {
      double temp;
      int b_jA;
      int i2;
      b_jA = (b_j - 1) * obj->ldm;
      temp = rhs[b_j - 1];
      i2 = b_j + 1;
      for (int d_i{p_n}; d_i >= i2; d_i--) {
        temp -= (&obj->FMat[0][0])[(b_jA + d_i) - 1] * rhs[d_i - 1];
      }
      rhs[b_j - 1] = temp;
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for solve1.cpp
//
// [EOF]
//
