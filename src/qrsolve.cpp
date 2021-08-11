//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
//                ::coder::array<double, 1U> &B
//                int rankA
//                ::coder::array<double, 1U> &Y
// Return Type  : void
//
namespace coder {
namespace internal {
void LSQFromQR(const ::coder::array<double, 2U> &A,
               const ::coder::array<double, 1U> &tau,
               const ::coder::array<int, 2U> &jpvt,
               ::coder::array<double, 1U> &B, int rankA,
               ::coder::array<double, 1U> &Y)
{
  int b_i;
  int i;
  int loop_ub;
  int m;
  int mn;
  Y.set_size(A.size(1));
  loop_ub = A.size(1);
  for (i = 0; i < loop_ub; i++) {
    Y[i] = 0.0;
  }
  m = A.size(0);
  loop_ub = A.size(0);
  mn = A.size(1);
  if (loop_ub < mn) {
    mn = loop_ub;
  }
  for (loop_ub = 0; loop_ub < mn; loop_ub++) {
    if (tau[loop_ub] != 0.0) {
      double wj;
      wj = B[loop_ub];
      i = loop_ub + 2;
      for (b_i = i; b_i <= m; b_i++) {
        wj += A[(b_i + (A.size(0) * loop_ub)) - 1] * B[b_i - 1];
      }
      wj *= tau[loop_ub];
      if (wj != 0.0) {
        B[loop_ub] = B[loop_ub] - wj;
        for (b_i = i; b_i <= m; b_i++) {
          B[b_i - 1] = B[b_i - 1] - (A[(b_i + (A.size(0) * loop_ub)) - 1] * wj);
        }
      }
    }
  }
  for (b_i = 0; b_i < rankA; b_i++) {
    Y[jpvt[b_i] - 1] = B[b_i];
  }
  for (loop_ub = rankA; loop_ub >= 1; loop_ub--) {
    i = jpvt[loop_ub - 1];
    Y[i - 1] = Y[i - 1] / A[(loop_ub + (A.size(0) * (loop_ub - 1))) - 1];
    for (b_i = 0; b_i <= (loop_ub - 2); b_i++) {
      Y[jpvt[b_i] - 1] =
          Y[jpvt[b_i] - 1] -
          (Y[jpvt[loop_ub - 1] - 1] * A[b_i + (A.size(0) * (loop_ub - 1))]);
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &B
//                ::coder::array<double, 1U> &Y
//                int *rankA
// Return Type  : void
//
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &B, ::coder::array<double, 1U> &Y,
             int *rankA)
{
  array<double, 2U> b_A;
  array<double, 1U> b_B;
  array<double, 1U> tau;
  array<int, 2U> jpvt;
  int assumedRank;
  int i;
  int maxmn;
  int minmn;
  b_A.set_size(A.size(0), A.size(1));
  maxmn = A.size(1);
  for (i = 0; i < maxmn; i++) {
    minmn = A.size(0);
    for (assumedRank = 0; assumedRank < minmn; assumedRank++) {
      b_A[assumedRank + (b_A.size(0) * i)] = A[assumedRank + (A.size(0) * i)];
    }
  }
  lapack::xgeqp3(b_A, tau, jpvt);
  *rankA = 0;
  if (b_A.size(0) < b_A.size(1)) {
    minmn = b_A.size(0);
    maxmn = b_A.size(1);
  } else {
    minmn = b_A.size(1);
    maxmn = b_A.size(0);
  }
  if (minmn > 0) {
    double tol;
    boolean_T exitg1;
    tol = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
          std::abs(b_A[0]);
    exitg1 = false;
    while ((!exitg1) && ((*rankA) < minmn)) {
      if (!(std::abs(b_A[(*rankA) + (b_A.size(0) * (*rankA))]) <= tol)) {
        (*rankA)++;
      } else {
        exitg1 = true;
      }
    }
  }
  assumedRank = 0;
  minmn = b_A.size(0);
  maxmn = b_A.size(1);
  if (minmn < maxmn) {
    maxmn = minmn;
  }
  if (maxmn > 0) {
    for (minmn = 0; minmn < maxmn; minmn++) {
      if (b_A[minmn + (b_A.size(0) * minmn)] != 0.0) {
        assumedRank++;
      }
    }
  }
  b_B.set_size(B.size(0));
  maxmn = B.size(0) - 1;
  for (i = 0; i <= maxmn; i++) {
    b_B[i] = B[i];
  }
  LSQFromQR(b_A, tau, jpvt, b_B, assumedRank, Y);
}

} // namespace internal
} // namespace coder

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
