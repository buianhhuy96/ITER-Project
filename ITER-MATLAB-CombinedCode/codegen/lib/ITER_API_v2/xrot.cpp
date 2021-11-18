//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "xrot.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double b_x[3][3]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xrot(double b_x[3][3], int ix0, int iy0, double c, double s)
{
  double b_temp_tmp_tmp;
  double c_temp_tmp_tmp;
  double d_temp_tmp_tmp;
  double temp;
  double temp_tmp_tmp;
  temp_tmp_tmp = (&b_x[0][0])[iy0 - 1];
  b_temp_tmp_tmp = (&b_x[0][0])[ix0 - 1];
  (&b_x[0][0])[iy0 - 1] =
      (c * (&b_x[0][0])[iy0 - 1]) - (s * (&b_x[0][0])[ix0 - 1]);
  (&b_x[0][0])[ix0 - 1] = (c * b_temp_tmp_tmp) + (s * temp_tmp_tmp);
  temp = (c * (&b_x[0][0])[ix0]) + (s * (&b_x[0][0])[iy0]);
  (&b_x[0][0])[iy0] = (c * (&b_x[0][0])[iy0]) - (s * (&b_x[0][0])[ix0]);
  (&b_x[0][0])[ix0] = temp;
  c_temp_tmp_tmp = (&b_x[0][0])[iy0 + 1];
  d_temp_tmp_tmp = (&b_x[0][0])[ix0 + 1];
  (&b_x[0][0])[iy0 + 1] =
      (c * (&b_x[0][0])[iy0 + 1]) - (s * (&b_x[0][0])[ix0 + 1]);
  (&b_x[0][0])[ix0 + 1] = (c * d_temp_tmp_tmp) + (s * c_temp_tmp_tmp);
}

//
// Arguments    : double b_x[9][9]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void c_xrot(double b_x[9][9], int ix0, int iy0, double c, double s)
{
  for (int k{0}; k < 9; k++) {
    double b_temp_tmp;
    double d_temp_tmp;
    int c_temp_tmp;
    int temp_tmp;
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = (&b_x[0][0])[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = (&b_x[0][0])[c_temp_tmp];
    (&b_x[0][0])[temp_tmp] =
        (c * (&b_x[0][0])[temp_tmp]) - (s * (&b_x[0][0])[c_temp_tmp]);
    (&b_x[0][0])[c_temp_tmp] = (c * d_temp_tmp) + (s * b_temp_tmp);
  }
}

//
// Arguments    : double b_x[6][6]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void xrot(double b_x[6][6], int ix0, int iy0, double c, double s)
{
  for (int k{0}; k < 6; k++) {
    double b_temp_tmp;
    double d_temp_tmp;
    int c_temp_tmp;
    int temp_tmp;
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

//
// File trailer for xrot.cpp
//
// [EOF]
//
