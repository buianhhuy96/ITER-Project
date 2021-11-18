//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xrot.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : real_T b_x[3][3]
//                int32_T ix0
//                int32_T iy0
//                real_T c
//                real_T s
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void b_xrot(real_T b_x[3][3], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp_tmp;
  temp = (&b_x[0][0])[iy0 - 1];
  temp_tmp_tmp = (&b_x[0][0])[ix0 - 1];
  (&b_x[0][0])[iy0 - 1] =
      (c * (&b_x[0][0])[iy0 - 1]) - (s * (&b_x[0][0])[ix0 - 1]);
  (&b_x[0][0])[ix0 - 1] = (c * temp_tmp_tmp) + (s * temp);
  temp = (c * (&b_x[0][0])[ix0]) + (s * (&b_x[0][0])[iy0]);
  (&b_x[0][0])[iy0] = (c * (&b_x[0][0])[iy0]) - (s * (&b_x[0][0])[ix0]);
  (&b_x[0][0])[ix0] = temp;
  temp = (&b_x[0][0])[iy0 + 1];
  temp_tmp_tmp = (&b_x[0][0])[ix0 + 1];
  (&b_x[0][0])[iy0 + 1] =
      (c * (&b_x[0][0])[iy0 + 1]) - (s * (&b_x[0][0])[ix0 + 1]);
  (&b_x[0][0])[ix0 + 1] = (c * temp_tmp_tmp) + (s * temp);
}

//
// Arguments    : real_T b_x[6][6]
//                int32_T ix0
//                int32_T iy0
//                real_T c
//                real_T s
// Return Type  : void
//
void xrot(real_T b_x[6][6], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  for (int32_T k{0}; k < 6; k++) {
    real_T b_temp_tmp;
    real_T d_temp_tmp;
    int32_T c_temp_tmp;
    int32_T temp_tmp;
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = (&b_x[0][0])[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = (&b_x[0][0])[c_temp_tmp];
    (&b_x[0][0])[temp_tmp] =
        (c * (&b_x[0][0])[temp_tmp]) - (s * (&b_x[0][0])[c_temp_tmp]);
    (&b_x[0][0])[c_temp_tmp] = (c * d_temp_tmp) + (s * b_temp_tmp);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xrot.cpp
//
// [EOF]
//
