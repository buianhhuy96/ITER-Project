//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rot90.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "rot90.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &B
// Return Type  : void
//
namespace coder {
void b_rot90(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &B)
{
  int b_i;
  int m;
  int n;
  m = A.size(0);
  n = A.size(1);
  B.set_size(A.size(0), A.size(1));
  if ((A.size(0) * A.size(1)) >= 8192) {
    int j;
    j = A.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i)

    for (int b_j = 0; b_j <= j; b_j++) {
      for (b_i = 0; b_i < m; b_i++) {
        B[b_i + (B.size(0) * b_j)] =
            A[((m - b_i) + (A.size(0) * ((n - b_j) - 1))) - 1];
      }
    }
  } else {
    for (int j{0}; j < n; j++) {
      for (int i{0}; i < m; i++) {
        B[i + (B.size(0) * j)] = A[((m - i) + (A.size(0) * ((n - j) - 1))) - 1];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &B
// Return Type  : void
//
void rot90(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &B)
{
  int b_i;
  int b_j;
  int m;
  int n;
  m = A.size(0);
  n = A.size(1);
  B.set_size(A.size(1), A.size(0));
  if ((A.size(0) * A.size(1)) >= 8192) {
    int i;
    i = A.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_j, b_i)

    for (b_i = 0; b_i <= i; b_i++) {
      for (b_j = 0; b_j < m; b_j++) {
        B[b_i + (B.size(0) * b_j)] = A[b_j + (A.size(0) * ((n - b_i) - 1))];
      }
    }
  } else {
    for (int i{0}; i < n; i++) {
      for (int j{0}; j < m; j++) {
        B[i + (B.size(0) * j)] = A[j + (A.size(0) * ((n - i) - 1))];
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
