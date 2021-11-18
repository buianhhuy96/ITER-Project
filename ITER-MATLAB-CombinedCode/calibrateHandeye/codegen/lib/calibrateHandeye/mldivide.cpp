//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "mldivide.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &b_B
// Return Type  : void
//
namespace coder {
void b_mldivide(const ::coder::array<double, 2U> &A,
                ::coder::array<double, 1U> &b_B)
{
  array<double, 2U> d_A;
  array<double, 1U> c_B;
  array<double, 1U> tau;
  array<int, 2U> jpvt;
  int b_i;
  int maxmn;
  bool guard1{false};
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else if (b_B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == A.size(1)) {
    double tol;
    int LDA;
    int c_n;
    int jp1j;
    int k;
    int minmn;
    int u0;
    u0 = A.size(0);
    c_n = A.size(1);
    if (u0 <= c_n) {
      c_n = u0;
    }
    u0 = b_B.size(0);
    if (u0 <= c_n) {
      c_n = u0;
    }
    LDA = A.size(0);
    d_A.set_size(A.size(0), A.size(1));
    maxmn = A.size(1);
    for (b_i = 0; b_i < maxmn; b_i++) {
      minmn = A.size(0);
      for (jp1j = 0; jp1j < minmn; jp1j++) {
        d_A[jp1j + (d_A.size(0) * b_i)] = A[jp1j + (A.size(0) * b_i)];
      }
    }
    if (c_n < 1) {
      minmn = 0;
    } else {
      minmn = c_n;
    }
    jpvt.set_size(1, minmn);
    if (minmn > 0) {
      jpvt[0] = 1;
      maxmn = 1;
      for (k = 2; k <= minmn; k++) {
        maxmn++;
        jpvt[k - 1] = maxmn;
      }
    }
    if (c_n >= 1) {
      int ldap1;
      ldap1 = A.size(0);
      u0 = c_n - 1;
      if (u0 > c_n) {
        u0 = c_n;
      }
      for (int j{0}; j < u0; j++) {
        int b;
        int jj;
        int mmj_tmp;
        int rankA;
        mmj_tmp = c_n - j;
        b = j * (LDA + 1);
        jj = j * (ldap1 + 1);
        jp1j = b + 2;
        if (mmj_tmp < 1) {
          minmn = -1;
        } else {
          minmn = 0;
          if (mmj_tmp > 1) {
            tol = std::abs(d_A[jj]);
            for (k = 2; k <= mmj_tmp; k++) {
              double s;
              s = std::abs(d_A[(b + k) - 1]);
              if (s > tol) {
                minmn = k - 1;
                tol = s;
              }
            }
          }
        }
        if (d_A[jj + minmn] != 0.0) {
          if (minmn != 0) {
            maxmn = j + minmn;
            jpvt[j] = maxmn + 1;
            for (k = 0; k < c_n; k++) {
              minmn = k * LDA;
              rankA = j + minmn;
              tol = d_A[rankA];
              b_i = maxmn + minmn;
              d_A[rankA] = d_A[b_i];
              d_A[b_i] = tol;
            }
          }
          b_i = jj + mmj_tmp;
          for (maxmn = jp1j; maxmn <= b_i; maxmn++) {
            d_A[maxmn - 1] = d_A[maxmn - 1] / d_A[jj];
          }
        }
        maxmn = b + LDA;
        rankA = jj + ldap1;
        for (b = 0; b <= (mmj_tmp - 2); b++) {
          minmn = maxmn + (b * LDA);
          tol = d_A[minmn];
          if (d_A[minmn] != 0.0) {
            b_i = rankA + 2;
            jp1j = mmj_tmp + rankA;
            for (minmn = b_i; minmn <= jp1j; minmn++) {
              d_A[minmn - 1] =
                  d_A[minmn - 1] + (d_A[((jj + minmn) - rankA) - 1] * (-tol));
            }
          }
          rankA += LDA;
        }
      }
    }
    LDA = d_A.size(0);
    for (maxmn = 0; maxmn <= (c_n - 2); maxmn++) {
      b_i = jpvt[maxmn];
      if (b_i != (maxmn + 1)) {
        tol = b_B[maxmn];
        b_B[maxmn] = b_B[b_i - 1];
        b_B[b_i - 1] = tol;
      }
    }
    if (b_B.size(0) != 0) {
      for (k = 0; k < c_n; k++) {
        minmn = LDA * k;
        if (b_B[k] != 0.0) {
          b_i = k + 2;
          for (maxmn = b_i; maxmn <= c_n; maxmn++) {
            b_B[maxmn - 1] =
                b_B[maxmn - 1] - (b_B[k] * d_A[(maxmn + minmn) - 1]);
          }
        }
      }
    }
    if (b_B.size(0) != 0) {
      for (k = c_n; k >= 1; k--) {
        minmn = LDA * (k - 1);
        tol = b_B[k - 1];
        if (tol != 0.0) {
          b_B[k - 1] = tol / d_A[(k + minmn) - 1];
          for (maxmn = 0; maxmn <= (k - 2); maxmn++) {
            b_B[maxmn] = b_B[maxmn] - (b_B[k - 1] * d_A[maxmn + minmn]);
          }
        }
      }
    }
  } else {
    int minmn;
    int rankA;
    d_A.set_size(A.size(0), A.size(1));
    maxmn = A.size(1);
    for (b_i = 0; b_i < maxmn; b_i++) {
      minmn = A.size(0);
      for (int jp1j{0}; jp1j < minmn; jp1j++) {
        d_A[jp1j + (d_A.size(0) * b_i)] = A[jp1j + (A.size(0) * b_i)];
      }
    }
    internal::lapack::xgeqp3(d_A, tau, jpvt);
    rankA = 0;
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
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(d_A[rankA + (d_A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    c_B.set_size(b_B.size(0));
    maxmn = b_B.size(0) - 1;
    for (b_i = 0; b_i <= maxmn; b_i++) {
      c_B[b_i] = b_B[b_i];
    }
    internal::LSQFromQR(d_A, tau, jpvt, c_B, rankA, b_B);
  }
  if (guard1) {
    b_B.set_size(A.size(1));
    maxmn = A.size(1);
    for (b_i = 0; b_i < maxmn; b_i++) {
      b_B[b_i] = 0.0;
    }
  }
}

//
// Arguments    : const double A[3][3]
//                const double b_B[3]
//                double g_Y[3]
// Return Type  : void
//
void mldivide(const double A[3][3], const double b_B[3], double g_Y[3])
{
  double d_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  for (r1 = 0; r1 < 3; r1++) {
    d_A[r1][0] = A[r1][0];
    d_A[r1][1] = A[r1][1];
    d_A[r1][2] = A[r1][2];
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(A[0][0]);
  a21 = std::abs(A[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(A[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  d_A[0][r2] = A[0][r2] / A[0][r1];
  d_A[0][r3] /= d_A[0][r1];
  d_A[1][r2] -= d_A[0][r2] * d_A[1][r1];
  d_A[1][r3] -= d_A[0][r3] * d_A[1][r1];
  d_A[2][r2] -= d_A[0][r2] * d_A[2][r1];
  d_A[2][r3] -= d_A[0][r3] * d_A[2][r1];
  if (std::abs(d_A[1][r3]) > std::abs(d_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  d_A[1][r3] /= d_A[1][r2];
  d_A[2][r3] -= d_A[1][r3] * d_A[2][r2];
  g_Y[1] = b_B[r2] - (b_B[r1] * d_A[0][r2]);
  g_Y[2] = (b_B[r3] - (b_B[r1] * d_A[0][r3])) - (g_Y[1] * d_A[1][r3]);
  g_Y[2] /= d_A[2][r3];
  g_Y[0] = b_B[r1] - (g_Y[2] * d_A[2][r1]);
  g_Y[1] -= g_Y[2] * d_A[2][r2];
  g_Y[1] /= d_A[1][r2];
  g_Y[0] -= g_Y[1] * d_A[1][r1];
  g_Y[0] /= d_A[0][r1];
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
