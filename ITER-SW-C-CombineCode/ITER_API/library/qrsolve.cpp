//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
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
//                const ::coder::array<double, 1U> &c_B
//                ::coder::array<double, 1U> &g_Y
//                int *rankA
// Return Type  : void
//
namespace coder {
namespace internal {
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &c_B,
             ::coder::array<double, 1U> &g_Y, int *rankA)
{
  array<double, 2U> e_A;
  array<double, 1U> e_B;
  array<double, 1U> tau;
  array<int, 2U> jpvt;
  int assumedRank;
  int b_mn;
  int b_rankA;
  int b_u0;
  int b_u1;
  int c_loop_ub;
  int c_mn;
  int c_u1;
  int d_loop_ub;
  int loop_ub;
  int m;
  int maxmn;
  int minmn;
  int u0;
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
  b_u1 = e_A.size(1);
  if (u0 <= b_u1) {
    b_mn = u0;
  } else {
    b_mn = b_u1;
  }
  if (b_mn > 0) {
    for (int k{0}; k < b_mn; k++) {
      if (e_A[k + (e_A.size(0) * k)] != 0.0) {
        assumedRank++;
      }
    }
  }
  g_Y.set_size(e_A.size(1));
  c_loop_ub = e_A.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    g_Y[i2] = 0.0;
  }
  e_B.set_size(c_B.size(0));
  d_loop_ub = c_B.size(0);
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    e_B[i3] = c_B[i3];
  }
  m = e_A.size(0);
  b_u0 = e_A.size(0);
  c_u1 = e_A.size(1);
  if (b_u0 <= c_u1) {
    c_mn = b_u0;
  } else {
    c_mn = c_u1;
  }
  for (int j{0}; j < c_mn; j++) {
    if (tau[j] != 0.0) {
      double wj;
      int i4;
      wj = e_B[j];
      i4 = j + 2;
      for (int d_i{i4}; d_i <= m; d_i++) {
        wj += e_A[(d_i + (e_A.size(0) * j)) - 1] * e_B[d_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        e_B[j] = e_B[j] - wj;
        for (int g_i{i4}; g_i <= m; g_i++) {
          e_B[g_i - 1] =
              e_B[g_i - 1] - (e_A[(g_i + (e_A.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
  for (int c_i{0}; c_i < assumedRank; c_i++) {
    g_Y[jpvt[c_i] - 1] = e_B[c_i];
  }
  for (int b_j{assumedRank}; b_j >= 1; b_j--) {
    int i5;
    i5 = jpvt[b_j - 1];
    g_Y[i5 - 1] = g_Y[i5 - 1] / e_A[(b_j + (e_A.size(0) * (b_j - 1))) - 1];
    for (int e_i{0}; e_i <= (b_j - 2); e_i++) {
      g_Y[jpvt[e_i] - 1] =
          g_Y[jpvt[e_i] - 1] -
          (g_Y[jpvt[b_j - 1] - 1] * e_A[e_i + (e_A.size(0) * (b_j - 1))]);
    }
  }
  *rankA = b_rankA;
}

} // namespace internal
} // namespace coder

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
