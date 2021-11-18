//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "xswap.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double b_x[3][3]
//                int ix0
//                int iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xswap(double b_x[3][3], int ix0, int iy0)
{
  double temp;
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
// Arguments    : double b_x[9][9]
//                int ix0
//                int iy0
// Return Type  : void
//
void c_xswap(double b_x[9][9], int ix0, int iy0)
{
  for (int k{0}; k < 9; k++) {
    double temp;
    int b_i;
    int temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = (&b_x[0][0])[temp_tmp];
    b_i = (iy0 + k) - 1;
    (&b_x[0][0])[temp_tmp] = (&b_x[0][0])[b_i];
    (&b_x[0][0])[b_i] = temp;
  }
}

//
// Arguments    : double b_x[6][6]
//                int ix0
//                int iy0
// Return Type  : void
//
void xswap(double b_x[6][6], int ix0, int iy0)
{
  for (int k{0}; k < 6; k++) {
    double temp;
    int b_i;
    int temp_tmp;
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

//
// File trailer for xswap.cpp
//
// [EOF]
//
