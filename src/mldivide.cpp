//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &B
// Return Type  : void
//
namespace coder {
void mldivide(const ::coder::array<double, 2U> &A,
              ::coder::array<double, 1U> &B)
{
  array<double, 2U> b_A;
  array<double, 1U> tau;
  double Y[8];
  int jpvt[8];
  int i;
  boolean_T guard1{false};
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else if (B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == 8) {
    int b_i;
    int k;
    int minmn;
    int rankA;
    b_A.set_size(8, 8);
    for (i = 0; i < 8; i++) {
      for (rankA = 0; rankA < 8; rankA++) {
        b_A[rankA + (b_A.size(0) * i)] = A[rankA + (A.size(0) * i)];
      }
      jpvt[i] = i + 1;
    }
    for (int j{0}; j < 7; j++) {
      double tol;
      int b_tmp;
      int jp1j;
      int maxmn;
      int mmj_tmp;
      mmj_tmp = 6 - j;
      b_tmp = j * 9;
      jp1j = b_tmp + 2;
      minmn = 8 - j;
      maxmn = 0;
      tol = std::abs(b_A[b_tmp]);
      for (k = 2; k <= minmn; k++) {
        double s;
        s = std::abs(b_A[(b_tmp + k) - 1]);
        if (s > tol) {
          maxmn = k - 1;
          tol = s;
        }
      }
      if (b_A[b_tmp + maxmn] != 0.0) {
        if (maxmn != 0) {
          maxmn += j;
          jpvt[j] = maxmn + 1;
          for (k = 0; k < 8; k++) {
            minmn = k * 8;
            rankA = j + minmn;
            tol = b_A[rankA];
            i = maxmn + minmn;
            b_A[rankA] = b_A[i];
            b_A[i] = tol;
          }
        }
        i = (b_tmp - j) + 8;
        for (b_i = jp1j; b_i <= i; b_i++) {
          b_A[b_i - 1] = b_A[b_i - 1] / b_A[b_tmp];
        }
      }
      maxmn = b_tmp;
      for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
        minmn = (b_tmp + (jp1j * 8)) + 8;
        tol = b_A[minmn];
        if (b_A[minmn] != 0.0) {
          i = maxmn + 10;
          rankA = (maxmn - j) + 16;
          for (minmn = i; minmn <= rankA; minmn++) {
            b_A[minmn - 1] =
                b_A[minmn - 1] + (b_A[((b_tmp + minmn) - maxmn) - 9] * (-tol));
          }
        }
        maxmn += 8;
      }
      i = jpvt[j];
      if (i != (j + 1)) {
        tol = B[j];
        i--;
        B[j] = B[i];
        B[i] = tol;
      }
    }
    if (B.size(0) != 0) {
      for (k = 0; k < 8; k++) {
        minmn = k * 8;
        if (B[k] != 0.0) {
          i = k + 2;
          for (b_i = i; b_i < 9; b_i++) {
            B[b_i - 1] = B[b_i - 1] - (B[k] * b_A[(b_i + minmn) - 1]);
          }
        }
      }
    }
    if (B.size(0) != 0) {
      for (k = 7; k >= 0; k--) {
        minmn = k * 8;
        if (B[k] != 0.0) {
          B[k] = B[k] / b_A[k + minmn];
          for (b_i = 0; b_i < k; b_i++) {
            B[b_i] = B[b_i] - (B[k] * b_A[b_i + minmn]);
          }
        }
      }
    }
  } else {
    double tol;
    int b_i;
    int j;
    int maxmn;
    int minmn;
    int rankA;
    b_A.set_size(A.size(0), 8);
    minmn = A.size(0);
    for (i = 0; i < 8; i++) {
      for (rankA = 0; rankA < minmn; rankA++) {
        b_A[rankA + (b_A.size(0) * i)] = A[rankA + (A.size(0) * i)];
      }
    }
    internal::lapack::xgeqp3(b_A, tau, jpvt);
    rankA = 0;
    if (b_A.size(0) < 8) {
      minmn = b_A.size(0);
      maxmn = 8;
    } else {
      minmn = 8;
      maxmn = b_A.size(0);
    }
    if (minmn > 0) {
      boolean_T exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(b_A[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(b_A[rankA + (b_A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    (void)std::memset(&Y[0], 0, 8U * (sizeof(double)));
    minmn = b_A.size(0);
    maxmn = b_A.size(0);
    if (maxmn >= 8) {
      maxmn = 8;
    }
    for (j = 0; j < maxmn; j++) {
      if (tau[j] != 0.0) {
        tol = B[j];
        i = j + 2;
        for (b_i = i; b_i <= minmn; b_i++) {
          tol += b_A[(b_i + (b_A.size(0) * j)) - 1] * B[b_i - 1];
        }
        tol *= tau[j];
        if (tol != 0.0) {
          B[j] = B[j] - tol;
          for (b_i = i; b_i <= minmn; b_i++) {
            B[b_i - 1] =
                B[b_i - 1] - (b_A[(b_i + (b_A.size(0) * j)) - 1] * tol);
          }
        }
      }
    }
    for (b_i = 0; b_i < rankA; b_i++) {
      Y[jpvt[b_i] - 1] = B[b_i];
    }
    for (j = rankA; j >= 1; j--) {
      minmn = jpvt[j - 1] - 1;
      Y[minmn] /= b_A[(j + (b_A.size(0) * (j - 1))) - 1];
      for (b_i = 0; b_i <= (j - 2); b_i++) {
        Y[jpvt[b_i] - 1] -= Y[minmn] * b_A[b_i + (b_A.size(0) * (j - 1))];
      }
    }
    B.set_size(8);
    for (i = 0; i < 8; i++) {
      B[i] = Y[i];
    }
  }
  if (guard1) {
    B.set_size(8);
    for (i = 0; i < 8; i++) {
      B[i] = 0.0;
    }
  }
}

//
// Arguments    : const double A[3][3]
//                const double B[3]
//                double Y[3]
// Return Type  : void
//
void mldivide(const double A[3][3], const double B[3], double Y[3])
{
  double b_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  for (r1 = 0; r1 < 3; r1++) {
    b_A[r1][0] = A[r1][0];
    b_A[r1][1] = A[r1][1];
    b_A[r1][2] = A[r1][2];
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
  b_A[0][r2] = A[0][r2] / A[0][r1];
  b_A[0][r3] /= b_A[0][r1];
  b_A[1][r2] -= b_A[0][r2] * b_A[1][r1];
  b_A[1][r3] -= b_A[0][r3] * b_A[1][r1];
  b_A[2][r2] -= b_A[0][r2] * b_A[2][r1];
  b_A[2][r3] -= b_A[0][r3] * b_A[2][r1];
  if (std::abs(b_A[1][r3]) > std::abs(b_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  b_A[1][r3] /= b_A[1][r2];
  b_A[2][r3] -= b_A[1][r3] * b_A[2][r2];
  Y[1] = B[r2] - (B[r1] * b_A[0][r2]);
  Y[2] = (B[r3] - (B[r1] * b_A[0][r3])) - (Y[1] * b_A[1][r3]);
  Y[2] /= b_A[2][r3];
  Y[0] = B[r1] - (Y[2] * b_A[2][r1]);
  Y[1] -= Y[2] * b_A[2][r2];
  Y[1] /= b_A[1][r2];
  Y[0] -= Y[1] * b_A[1][r1];
  Y[0] /= b_A[0][r1];
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
