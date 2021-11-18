//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rot90.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "rot90.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &c_B
// Return Type  : void
//
namespace coder {
void b_rot90(const ::coder::array<double, 2U> &A,
             ::coder::array<double, 2U> &c_B)
{
  int c_i;
  int h_n;
  int m;
  m = A.size(0);
  h_n = A.size(1);
  c_B.set_size(A.size(0), A.size(1));
  if ((A.size(0) * A.size(1)) >= 8192) {
    int ub_loop;
    ub_loop = A.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i)

    for (int b_j = 0; b_j <= ub_loop; b_j++) {
      for (c_i = 0; c_i < m; c_i++) {
        c_B[c_i + (c_B.size(0) * b_j)] =
            A[((m - c_i) + (A.size(0) * ((h_n - b_j) - 1))) - 1];
      }
    }
  } else {
    for (int j{0}; j < h_n; j++) {
      for (int b_i{0}; b_i < m; b_i++) {
        c_B[b_i + (c_B.size(0) * j)] =
            A[((m - b_i) + (A.size(0) * ((h_n - j) - 1))) - 1];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &c_B
// Return Type  : void
//
void rot90(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &c_B)
{
  int b_j;
  int h_n;
  int m;
  m = A.size(0);
  h_n = A.size(1);
  c_B.set_size(A.size(1), A.size(0));
  if ((A.size(0) * A.size(1)) >= 8192) {
    int ub_loop;
    ub_loop = A.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_j)

    for (int c_i = 0; c_i <= ub_loop; c_i++) {
      for (b_j = 0; b_j < m; b_j++) {
        c_B[c_i + (c_B.size(0) * b_j)] =
            A[b_j + (A.size(0) * ((h_n - c_i) - 1))];
      }
    }
  } else {
    for (int b_i{0}; b_i < h_n; b_i++) {
      for (int j{0}; j < m; j++) {
        c_B[b_i + (c_B.size(0) * j)] = A[j + (A.size(0) * ((h_n - b_i) - 1))];
      }
    }
  }
}

} // namespace coder

//
// File trailer for rot90.cpp
//
// [EOF]
//
