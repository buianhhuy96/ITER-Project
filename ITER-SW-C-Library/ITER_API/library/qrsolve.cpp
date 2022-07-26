//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &e_B
//                ::coder::array<double, 1U> &g_Y
//                int *rankA
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &e_B,
             ::coder::array<double, 1U> &g_Y, int *rankA)
{
  ::coder::array<double, 2U> j_A;
  ::coder::array<double, 1U> f_B;
  ::coder::array<double, 1U> tau;
  ::coder::array<int, 2U> jpvt;
  int assumedRank;
  int b_loop_ub;
  int b_mn;
  int b_rankA;
  int b_u0;
  int b_u1;
  int c_loop_ub;
  int c_mn;
  int c_u1;
  int d_loop_ub;
  int i1;
  int loop_ub;
  int m;
  int maxmn;
  int minmn;
  int u0;
  j_A.set_size(A.size(0), A.size(1));
  loop_ub = A.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = A.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  lapack::xgeqp3(j_A, tau, jpvt);
  b_rankA = 0;
  if (j_A.size(0) < j_A.size(1)) {
    minmn = j_A.size(0);
    maxmn = j_A.size(1);
  } else {
    minmn = j_A.size(1);
    maxmn = j_A.size(0);
  }
  if (minmn > 0) {
    double tol;
    bool exitg1;
    tol = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
          std::abs(j_A[0]);
    exitg1 = false;
    while ((!exitg1) && (b_rankA < minmn)) {
      if (!(std::abs(j_A[b_rankA + (j_A.size(0) * b_rankA)]) <= tol)) {
        b_rankA++;
      } else {
        exitg1 = true;
      }
    }
  }
  assumedRank = 0;
  u0 = j_A.size(0);
  b_u1 = j_A.size(1);
  if (u0 <= b_u1) {
    b_mn = u0;
  } else {
    b_mn = b_u1;
  }
  if (b_mn > 0) {
    for (int k{0}; k < b_mn; k++) {
      if (j_A[k + (j_A.size(0) * k)] != 0.0) {
        assumedRank++;
      }
    }
  }
  g_Y.set_size(j_A.size(1));
  c_loop_ub = j_A.size(1);
  if ((static_cast<int>(j_A.size(1) < 4)) != 0) {
    for (int i2{0}; i2 < c_loop_ub; i2++) {
      g_Y[i2] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      g_Y[i2] = 0.0;
    }
  }
  f_B.set_size(e_B.size(0));
  d_loop_ub = e_B.size(0);
  if ((static_cast<int>(e_B.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      f_B[i3] = e_B[i3];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < d_loop_ub; i3++) {
      f_B[i3] = e_B[i3];
    }
  }
  m = j_A.size(0);
  b_u0 = j_A.size(0);
  c_u1 = j_A.size(1);
  if (b_u0 <= c_u1) {
    c_mn = b_u0;
  } else {
    c_mn = c_u1;
  }
  for (int j{0}; j < c_mn; j++) {
    if (tau[j] != 0.0) {
      double wj;
      int i4;
      wj = f_B[j];
      i4 = j + 2;
      for (int d_i{i4}; d_i <= m; d_i++) {
        wj += j_A[(d_i + (j_A.size(0) * j)) - 1] * f_B[d_i - 1];
      }
      wj *= tau[j];
      if (wj != 0.0) {
        f_B[j] = f_B[j] - wj;
        for (int g_i{i4}; g_i <= m; g_i++) {
          f_B[g_i - 1] =
              f_B[g_i - 1] - (j_A[(g_i + (j_A.size(0) * j)) - 1] * wj);
        }
      }
    }
  }
  for (int c_i{0}; c_i < assumedRank; c_i++) {
    g_Y[jpvt[c_i] - 1] = f_B[c_i];
  }
  for (int b_j{assumedRank}; b_j >= 1; b_j--) {
    int i5;
    i5 = jpvt[b_j - 1];
    g_Y[i5 - 1] = g_Y[i5 - 1] / j_A[(b_j + (j_A.size(0) * (b_j - 1))) - 1];
    for (int e_i{0}; e_i <= (b_j - 2); e_i++) {
      g_Y[jpvt[e_i] - 1] =
          g_Y[jpvt[e_i] - 1] -
          (g_Y[jpvt[b_j - 1] - 1] * j_A[e_i + (j_A.size(0) * (b_j - 1))]);
    }
  }
  *rankA = b_rankA;
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
