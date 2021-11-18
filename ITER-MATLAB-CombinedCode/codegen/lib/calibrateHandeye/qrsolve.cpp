//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &tau
//                const ::coder::array<int, 2U> &jpvt
//                ::coder::array<double, 1U> &b_B
//                int rankA
//                ::coder::array<double, 1U> &h_Y
// Return Type  : void
//
namespace coder {
namespace internal {
void LSQFromQR(const ::coder::array<double, 2U> &A,
               const ::coder::array<double, 1U> &tau,
               const ::coder::array<int, 2U> &jpvt,
               ::coder::array<double, 1U> &b_B, int rankA,
               ::coder::array<double, 1U> &h_Y)
{
  int loop_ub;
  int m;
  int mn;
  int u0;
  int u1;
  h_Y.set_size(A.size(1));
  loop_ub = A.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    h_Y[b_i] = 0.0;
  }
  m = A.size(0);
  u0 = A.size(0);
  u1 = A.size(1);
  if (u0 <= u1) {
    mn = u0;
  } else {
    mn = u1;
  }
  for (int j{0}; j < mn; j++) {
    if (tau[j] != 0.0) {
      double wj;
      int i1;
      wj = b_B[j];
      i1 = j + 2;
      for (int d_i{i1}; d_i <= m; d_i++) {
        wj += A[(d_i + (A.size(0) * j)) - 1] * b_B[d_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        b_B[j] = b_B[j] - wj;
        for (int g_i{i1}; g_i <= m; g_i++) {
          b_B[g_i - 1] = b_B[g_i - 1] - (A[(g_i + (A.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
  for (int c_i{0}; c_i < rankA; c_i++) {
    h_Y[jpvt[c_i] - 1] = b_B[c_i];
  }
  for (int b_j{rankA}; b_j >= 1; b_j--) {
    int i2;
    i2 = jpvt[b_j - 1];
    h_Y[i2 - 1] = h_Y[i2 - 1] / A[(b_j + (A.size(0) * (b_j - 1))) - 1];
    for (int e_i{0}; e_i <= (b_j - 2); e_i++) {
      h_Y[jpvt[e_i] - 1] =
          h_Y[jpvt[e_i] - 1] -
          (h_Y[jpvt[b_j - 1] - 1] * A[e_i + (A.size(0) * (b_j - 1))]);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &b_B
//                ::coder::array<double, 1U> &h_Y
//                int *rankA
// Return Type  : void
//
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &b_B,
             ::coder::array<double, 1U> &h_Y, int *rankA)
{
  array<double, 2U> e_A;
  array<double, 1U> e_B;
  array<double, 1U> tau;
  array<int, 2U> jpvt;
  int assumedRank;
  int b_rankA;
  int c_loop_ub;
  int loop_ub;
  int maxmn;
  int minmn;
  int mn;
  int u0;
  int u1;
  e_A.set_size(A.size(0), A.size(1));
  loop_ub = A.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = A.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  lapack::xgeqp3(e_A, tau, jpvt);
  b_rankA = 0;
  if (e_A.size(0) < e_A.size(1)) {
    minmn = e_A.size(0);
    maxmn = e_A.size(1);
  } else {
    minmn = e_A.size(1);
    maxmn = e_A.size(0);
  }
  if (minmn > 0) {
    double tol;
    bool exitg1;
    tol = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
          std::abs(e_A[0]);
    exitg1 = false;
    while ((!exitg1) && (b_rankA < minmn)) {
      if (!(std::abs(e_A[b_rankA + (e_A.size(0) * b_rankA)]) <= tol)) {
        b_rankA++;
      } else {
        exitg1 = true;
      }
    }
  }
  assumedRank = 0;
  u0 = e_A.size(0);
  u1 = e_A.size(1);
  if (u0 <= u1) {
    mn = u0;
  } else {
    mn = u1;
  }
  if (mn > 0) {
    for (int k{0}; k < mn; k++) {
      if (e_A[k + (e_A.size(0) * k)] != 0.0) {
        assumedRank++;
      }
    }
  }
  e_B.set_size(b_B.size(0));
  c_loop_ub = b_B.size(0) - 1;
  for (int i2{0}; i2 <= c_loop_ub; i2++) {
    e_B[i2] = b_B[i2];
  }
  LSQFromQR(e_A, tau, jpvt, e_B, assumedRank, h_Y);
  *rankA = b_rankA;
}

} // namespace internal
} // namespace coder

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
