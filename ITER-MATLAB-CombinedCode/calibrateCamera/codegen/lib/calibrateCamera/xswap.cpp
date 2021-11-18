//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xswap.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : real_T b_x[3][3]
//                int32_T ix0
//                int32_T iy0
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void b_xswap(real_T b_x[3][3], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = (&b_x[0][0])[ix0 - 1];
  (&b_x[0][0])[ix0 - 1] = (&b_x[0][0])[iy0 - 1];
  (&b_x[0][0])[iy0 - 1] = temp;
  temp = (&b_x[0][0])[ix0];
  (&b_x[0][0])[ix0] = (&b_x[0][0])[iy0];
  (&b_x[0][0])[iy0] = temp;
  temp = (&b_x[0][0])[ix0 + 1];
  (&b_x[0][0])[ix0 + 1] = (&b_x[0][0])[iy0 + 1];
  (&b_x[0][0])[iy0 + 1] = temp;
}

//
// Arguments    : real_T b_x[6][6]
//                int32_T ix0
//                int32_T iy0
// Return Type  : void
//
void xswap(real_T b_x[6][6], int32_T ix0, int32_T iy0)
{
  for (int32_T k{0}; k < 6; k++) {
    real_T temp;
    int32_T b_i;
    int32_T temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = (&b_x[0][0])[temp_tmp];
    b_i = (iy0 + k) - 1;
    (&b_x[0][0])[temp_tmp] = (&b_x[0][0])[b_i];
    (&b_x[0][0])[b_i] = temp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xswap.cpp
//
// [EOF]
//
