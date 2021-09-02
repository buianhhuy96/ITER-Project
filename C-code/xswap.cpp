//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "xswap.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double x[9][9]
//                int ix0
//                int iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xswap(double x[9][9], int ix0, int iy0)
{
  for (int k{0}; k < 9; k++) {
    double temp;
    int i;
    int temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = (&x[0][0])[temp_tmp];
    i = (iy0 + k) - 1;
    (&x[0][0])[temp_tmp] = (&x[0][0])[i];
    (&x[0][0])[i] = temp;
  }
}

//
// Arguments    : double x[3][3]
//                int ix0
//                int iy0
// Return Type  : void
//
void xswap(double x[3][3], int ix0, int iy0)
{
  double temp;
  temp = (&x[0][0])[ix0 - 1];
  (&x[0][0])[ix0 - 1] = (&x[0][0])[iy0 - 1];
  (&x[0][0])[iy0 - 1] = temp;
  temp = (&x[0][0])[ix0];
  (&x[0][0])[ix0] = (&x[0][0])[iy0];
  (&x[0][0])[iy0] = temp;
  temp = (&x[0][0])[ix0 + 1];
  (&x[0][0])[ix0 + 1] = (&x[0][0])[iy0 + 1];
  (&x[0][0])[iy0 + 1] = temp;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xswap.cpp
//
// [EOF]
//
