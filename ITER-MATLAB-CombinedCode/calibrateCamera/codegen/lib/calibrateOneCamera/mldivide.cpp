//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
//                ::coder::array<double, 1U> &c_B
// Return Type  : void
//
namespace Codegen {
namespace coder {
void mldivide(const ::coder::array<double, 2U> &A,
              ::coder::array<double, 1U> &c_B)
{
  ::coder::array<double, 2U> e_A;
  ::coder::array<double, 1U> tau;
  double d_Y[8];
  int jpvt[8];
  int b_i;
  bool guard1{false};
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else if (c_B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == 8) {
    int c_i;
    int k;
    int minmn;
    int rankA;
    e_A.set_size(8, 8);
    for (b_i = 0; b_i < 8; b_i++) {
      for (rankA = 0; rankA < 8; rankA++) {
        e_A[rankA + (e_A.size(0) * b_i)] = A[rankA + (A.size(0) * b_i)];
      }
      jpvt[b_i] = b_i + 1;
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
      tol = std::abs(e_A[b_tmp]);
      for (k = 2; k <= minmn; k++) {
        double s;
        s = std::abs(e_A[(b_tmp + k) - 1]);
        if (s > tol) {
          maxmn = k - 1;
          tol = s;
        }
      }
      if (e_A[b_tmp + maxmn] != 0.0) {
        if (maxmn != 0) {
          maxmn += j;
          jpvt[j] = maxmn + 1;
          for (k = 0; k < 8; k++) {
            minmn = k * 8;
            rankA = j + minmn;
            tol = e_A[rankA];
            b_i = maxmn + minmn;
            e_A[rankA] = e_A[b_i];
            e_A[b_i] = tol;
          }
        }
        b_i = (b_tmp - j) + 8;
        for (c_i = jp1j; c_i <= b_i; c_i++) {
          e_A[c_i - 1] = e_A[c_i - 1] / e_A[b_tmp];
        }
      }
      maxmn = b_tmp;
      for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
        minmn = (b_tmp + (jp1j * 8)) + 8;
        tol = e_A[minmn];
        if (e_A[minmn] != 0.0) {
          b_i = maxmn + 10;
          rankA = (maxmn - j) + 16;
          for (minmn = b_i; minmn <= rankA; minmn++) {
            e_A[minmn - 1] =
                e_A[minmn - 1] + (e_A[((b_tmp + minmn) - maxmn) - 9] * (-tol));
          }
        }
        maxmn += 8;
      }
      b_i = jpvt[j];
      if (b_i != (j + 1)) {
        tol = c_B[j];
        b_i--;
        c_B[j] = c_B[b_i];
        c_B[b_i] = tol;
      }
    }
    if (c_B.size(0) != 0) {
      for (k = 0; k < 8; k++) {
        minmn = k * 8;
        if (c_B[k] != 0.0) {
          b_i = k + 2;
          for (c_i = b_i; c_i < 9; c_i++) {
            c_B[c_i - 1] = c_B[c_i - 1] - (c_B[k] * e_A[(c_i + minmn) - 1]);
          }
        }
      }
    }
    if (c_B.size(0) != 0) {
      for (k = 7; k >= 0; k--) {
        minmn = k * 8;
        if (c_B[k] != 0.0) {
          c_B[k] = c_B[k] / e_A[k + minmn];
          for (c_i = 0; c_i < k; c_i++) {
            c_B[c_i] = c_B[c_i] - (c_B[k] * e_A[c_i + minmn]);
          }
        }
      }
    }
  } else {
    double tol;
    int c_i;
    int j;
    int maxmn;
    int minmn;
    int rankA;
    e_A.set_size(A.size(0), 8);
    minmn = A.size(0);
    for (b_i = 0; b_i < 8; b_i++) {
      for (rankA = 0; rankA < minmn; rankA++) {
        e_A[rankA + (e_A.size(0) * b_i)] = A[rankA + (A.size(0) * b_i)];
      }
    }
    internal::lapack::xgeqp3(e_A, tau, jpvt);
    rankA = 0;
    if (e_A.size(0) < 8) {
      minmn = e_A.size(0);
      maxmn = 8;
    } else {
      minmn = 8;
      maxmn = e_A.size(0);
    }
    if (minmn > 0) {
      bool exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(e_A[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(e_A[rankA + (e_A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    (void)std::memset(&d_Y[0], 0, 8U * (sizeof(double)));
    minmn = e_A.size(0);
    maxmn = e_A.size(0);
    if (maxmn > 8) {
      maxmn = 8;
    }
    for (j = 0; j < maxmn; j++) {
      if (tau[j] != 0.0) {
        tol = c_B[j];
        b_i = j + 2;
        for (c_i = b_i; c_i <= minmn; c_i++) {
          tol += e_A[(c_i + (e_A.size(0) * j)) - 1] * c_B[c_i - 1];
        }
        tol *= tau[j];
        if (tol != 0.0) {
          c_B[j] = c_B[j] - tol;
          for (c_i = b_i; c_i <= minmn; c_i++) {
            c_B[c_i - 1] =
                c_B[c_i - 1] - (e_A[(c_i + (e_A.size(0) * j)) - 1] * tol);
          }
        }
      }
    }
    for (c_i = 0; c_i < rankA; c_i++) {
      d_Y[jpvt[c_i] - 1] = c_B[c_i];
    }
    for (j = rankA; j >= 1; j--) {
      minmn = jpvt[j - 1] - 1;
      d_Y[minmn] /= e_A[(j + (e_A.size(0) * (j - 1))) - 1];
      for (c_i = 0; c_i <= (j - 2); c_i++) {
        d_Y[jpvt[c_i] - 1] -= d_Y[minmn] * e_A[c_i + (e_A.size(0) * (j - 1))];
      }
    }
    c_B.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      c_B[b_i] = d_Y[b_i];
    }
  }
  if (guard1) {
    c_B.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      c_B[b_i] = 0.0;
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for mldivide.cpp
//
// [EOF]
//
