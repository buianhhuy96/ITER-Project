//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "xrot.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double x[3][3]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xrot(double x[3][3], int ix0, int iy0, double c, double s)
{
  double temp;
  double temp_tmp_tmp;
  temp = (&x[0][0])[iy0 - 1];
  temp_tmp_tmp = (&x[0][0])[ix0 - 1];
  (&x[0][0])[iy0 - 1] = (c * (&x[0][0])[iy0 - 1]) - (s * (&x[0][0])[ix0 - 1]);
  (&x[0][0])[ix0 - 1] = (c * temp_tmp_tmp) + (s * temp);
  temp = (c * (&x[0][0])[ix0]) + (s * (&x[0][0])[iy0]);
  (&x[0][0])[iy0] = (c * (&x[0][0])[iy0]) - (s * (&x[0][0])[ix0]);
  (&x[0][0])[ix0] = temp;
  temp = (&x[0][0])[iy0 + 1];
  temp_tmp_tmp = (&x[0][0])[ix0 + 1];
  (&x[0][0])[iy0 + 1] = (c * (&x[0][0])[iy0 + 1]) - (s * (&x[0][0])[ix0 + 1]);
  (&x[0][0])[ix0 + 1] = (c * temp_tmp_tmp) + (s * temp);
}

//
// Arguments    : double x[9][9]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void c_xrot(double x[9][9], int ix0, int iy0, double c, double s)
{
  for (int k{0}; k < 9; k++) {
    double b_temp_tmp;
    double d_temp_tmp;
    int c_temp_tmp;
    int temp_tmp;
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = (&x[0][0])[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = (&x[0][0])[c_temp_tmp];
    (&x[0][0])[temp_tmp] =
        (c * (&x[0][0])[temp_tmp]) - (s * (&x[0][0])[c_temp_tmp]);
    (&x[0][0])[c_temp_tmp] = (c * d_temp_tmp) + (s * b_temp_tmp);
  }
}

//
// Arguments    : double x[29][29]
//                int ix0
//                int iy0
//                double c
//                double s
// Return Type  : void
//
void xrot(double x[29][29], int ix0, int iy0, double c, double s)
{
  for (int k{0}; k < 29; k++) {
    double b_temp_tmp;
    double d_temp_tmp;
    int c_temp_tmp;
    int temp_tmp;
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = (&x[0][0])[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = (&x[0][0])[c_temp_tmp];
    (&x[0][0])[temp_tmp] =
        (c * (&x[0][0])[temp_tmp]) - (s * (&x[0][0])[c_temp_tmp]);
    (&x[0][0])[c_temp_tmp] = (c * d_temp_tmp) + (s * b_temp_tmp);
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
