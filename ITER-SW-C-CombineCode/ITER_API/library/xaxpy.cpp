//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int h_n
//                double b_a
//                int ix0
//                double y[6][6]
//                int iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int h_n, double b_a, int ix0, double y[6][6], int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      (&y[0][0])[i1] += b_a * (&y[0][0])[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int h_n
//                double b_a
//                int ix0
//                double y[3][3]
//                int iy0
// Return Type  : void
//
void c_xaxpy(int h_n, double b_a, int ix0, double y[3][3], int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      (&y[0][0])[i1] += b_a * (&y[0][0])[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int h_n
//                double b_a
//                int ix0
//                double y[9][9]
//                int iy0
// Return Type  : void
//
void d_xaxpy(int h_n, double b_a, int ix0, double y[9][9], int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      (&y[0][0])[i1] += b_a * (&y[0][0])[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int h_n
//                double b_a
//                const double b_x[9][9]
//                int ix0
//                double y[9]
//                int iy0
// Return Type  : void
//
void e_xaxpy(int h_n, double b_a, const double b_x[9][9], int ix0, double y[9],
             int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      y[i1] += b_a * (&b_x[0][0])[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int h_n
//                double b_a
//                const double b_x[9]
//                int ix0
//                double y[9][9]
//                int iy0
// Return Type  : void
//
void f_xaxpy(int h_n, double b_a, const double b_x[9], int ix0, double y[9][9],
             int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      (&y[0][0])[i1] += b_a * b_x[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : double b_a
//                const double b_x[3][3]
//                int ix0
//                double y[3]
// Return Type  : void
//
void g_xaxpy(double b_a, const double b_x[3][3], int ix0, double y[3])
{
  if (!(b_a == 0.0)) {
    for (int k{0}; k < 2; k++) {
      y[k + 1] += b_a * (&b_x[0][0])[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : double b_a
//                const double b_x[3]
//                double y[3][3]
//                int iy0
// Return Type  : void
//
void h_xaxpy(double b_a, const double b_x[3], double y[3][3], int iy0)
{
  if (!(b_a == 0.0)) {
    for (int k{0}; k < 2; k++) {
      int b_i;
      b_i = (iy0 + k) - 1;
      (&y[0][0])[b_i] += b_a * b_x[k + 1];
    }
  }
}

//
// Arguments    : int h_n
//                double b_a
//                int ix0
//                ::coder::array<double, 2U> &y
//                int iy0
// Return Type  : void
//
void xaxpy(int h_n, double b_a, int ix0, ::coder::array<double, 2U> &y, int iy0)
{
  if ((h_n >= 1) && (!(b_a == 0.0))) {
    int b_i;
    b_i = h_n - 1;
    for (int k{0}; k <= b_i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      y[i1] = y[i1] + (b_a * y[(ix0 + k) - 1]);
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xaxpy.cpp
//
// [EOF]
//
