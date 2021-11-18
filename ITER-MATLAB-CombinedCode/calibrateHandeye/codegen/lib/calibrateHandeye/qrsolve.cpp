//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
//                ::coder::array<double, 1U> &g_Y
// Return Type  : void
//
namespace coder {
namespace internal {
void LSQFromQR(const ::coder::array<double, 2U> &A,
               const ::coder::array<double, 1U> &tau,
               const ::coder::array<int, 2U> &jpvt,
               ::coder::array<double, 1U> &b_B, int rankA,
               ::coder::array<double, 1U> &g_Y)
{
  int b_i;
  int c_i;
  int loop_ub;
  int m;
  int mn;
  g_Y.set_size(A.size(1));
  loop_ub = A.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    g_Y[b_i] = 0.0;
  }
  m = A.size(0);
  loop_ub = A.size(0);
  mn = A.size(1);
  if (loop_ub <= mn) {
    mn = loop_ub;
  }
  for (loop_ub = 0; loop_ub < mn; loop_ub++) {
    if (tau[loop_ub] != 0.0) {
      double wj;
      wj = b_B[loop_ub];
      b_i = loop_ub + 2;
      for (c_i = b_i; c_i <= m; c_i++) {
        wj += A[(c_i + (A.size(0) * loop_ub)) - 1] * b_B[c_i - 1];
      }
      wj *= tau[loop_ub];
      if (wj != 0.0) {
        b_B[loop_ub] = b_B[loop_ub] - wj;
        for (c_i = b_i; c_i <= m; c_i++) {
          b_B[c_i - 1] =
              b_B[c_i - 1] - (A[(c_i + (A.size(0) * loop_ub)) - 1] * wj);
        }
      }
    }
  }
  for (c_i = 0; c_i < rankA; c_i++) {
    g_Y[jpvt[c_i] - 1] = b_B[c_i];
  }
  for (loop_ub = rankA; loop_ub >= 1; loop_ub--) {
    b_i = jpvt[loop_ub - 1];
    g_Y[b_i - 1] =
        g_Y[b_i - 1] / A[(loop_ub + (A.size(0) * (loop_ub - 1))) - 1];
    for (c_i = 0; c_i <= (loop_ub - 2); c_i++) {
      g_Y[jpvt[c_i] - 1] =
          g_Y[jpvt[c_i] - 1] -
          (g_Y[jpvt[loop_ub - 1] - 1] * A[c_i + (A.size(0) * (loop_ub - 1))]);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &b_B
//                ::coder::array<double, 1U> &g_Y
//                int *rankA
// Return Type  : void
//
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &b_B,
             ::coder::array<double, 1U> &g_Y, int *rankA)
{
  array<double, 2U> d_A;
  array<double, 1U> c_B;
  array<double, 1U> tau;
  array<int, 2U> jpvt;
  int assumedRank;
  int b_i;
  int maxmn;
  int minmn;
  d_A.set_size(A.size(0), A.size(1));
  maxmn = A.size(1);
  for (b_i = 0; b_i < maxmn; b_i++) {
    minmn = A.size(0);
    for (assumedRank = 0; assumedRank < minmn; assumedRank++) {
      d_A[assumedRank + (d_A.size(0) * b_i)] =
          A[assumedRank + (A.size(0) * b_i)];
    }
  }
  lapack::xgeqp3(d_A, tau, jpvt);
  *rankA = 0;
  if (d_A.size(0) < d_A.size(1)) {
    minmn = d_A.size(0);
    maxmn = d_A.size(1);
  } else {
    minmn = d_A.size(1);
    maxmn = d_A.size(0);
  }
  if (minmn > 0) {
    double tol;
    bool exitg1;
    tol = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
          std::abs(d_A[0]);
    exitg1 = false;
    while ((!exitg1) && ((*rankA) < minmn)) {
      if (!(std::abs(d_A[(*rankA) + (d_A.size(0) * (*rankA))]) <= tol)) {
        (*rankA)++;
      } else {
        exitg1 = true;
      }
    }
  }
  assumedRank = 0;
  minmn = d_A.size(0);
  maxmn = d_A.size(1);
  if (minmn <= maxmn) {
    maxmn = minmn;
  }
  if (maxmn > 0) {
    for (minmn = 0; minmn < maxmn; minmn++) {
      if (d_A[minmn + (d_A.size(0) * minmn)] != 0.0) {
        assumedRank++;
      }
    }
  }
  c_B.set_size(b_B.size(0));
  maxmn = b_B.size(0) - 1;
  for (b_i = 0; b_i <= maxmn; b_i++) {
    c_B[b_i] = b_B[b_i];
  }
  LSQFromQR(d_A, tau, jpvt, c_B, assumedRank, g_Y);
}

} // namespace internal
} // namespace coder

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
