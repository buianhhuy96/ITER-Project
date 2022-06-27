//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solve1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "solve1.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const s_struct_T *obj
//                double rhs[8]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void solve(const s_struct_T *obj, double rhs[8])
{
  int b_i;
  int h_n;
  int i_n;
  h_n = obj->ndims - 2;
  if (obj->ndims != 0) {
    for (int j{0}; j <= (h_n + 1); j++) {
      int i1;
      int jjA;
      jjA = j + (j * obj->ldm);
      i1 = h_n - j;
      for (int c_i{0}; c_i <= i1; c_i++) {
        int b_ix;
        b_ix = (j + c_i) + 1;
        rhs[b_ix] -= rhs[j] * (&obj->FMat[0][0])[(jjA + c_i) + 1];
      }
    }
  }
  b_i = obj->ndims;
  for (int idx{0}; idx < b_i; idx++) {
    rhs[idx] /= (&obj->FMat[0][0])[idx + (obj->ldm * idx)];
  }
  i_n = obj->ndims;
  if (obj->ndims != 0) {
    for (int b_j{i_n}; b_j >= 1; b_j--) {
      double temp;
      int i2;
      int jA;
      jA = (b_j - 1) * obj->ldm;
      temp = rhs[b_j - 1];
      i2 = b_j + 1;
      for (int d_i{i_n}; d_i >= i2; d_i--) {
        temp -= (&obj->FMat[0][0])[(jA + d_i) - 1] * rhs[d_i - 1];
      }
      rhs[b_j - 1] = temp;
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for solve1.cpp
//
// [EOF]
//
