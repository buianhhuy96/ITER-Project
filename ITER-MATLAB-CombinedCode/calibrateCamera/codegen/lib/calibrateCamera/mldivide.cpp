//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                const ::coder::array<real_T, 2U> &c_B
//                ::coder::array<real_T, 2U> &d_Y
// Return Type  : void
//
namespace Codegen {
namespace coder {
void mldivide(const ::coder::array<real_T, 2U> &A,
              const ::coder::array<real_T, 2U> &c_B,
              ::coder::array<real_T, 2U> &d_Y)
{
  ::coder::array<real_T, 2U> d_B;
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> tau;
  ::coder::array<int32_T, 2U> jpvt;
  int32_T b_i;
  int32_T i1;
  int32_T maxmn;
  int32_T minmn;
  boolean_T guard1{false};
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else if ((c_B.size(0) == 0) || (c_B.size(1) == 0)) {
    guard1 = true;
  } else if (A.size(0) == A.size(1)) {
    real_T tol;
    int32_T LDA;
    int32_T d_i;
    int32_T g_n;
    int32_T j;
    int32_T k;
    int32_T ldap1;
    int32_T mn;
    int32_T nb;
    int32_T nrhs;
    int32_T u0;
    d_Y.set_size(c_B.size(0), c_B.size(1));
    minmn = c_B.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = c_B.size(0);
      for (i1 = 0; i1 < maxmn; i1++) {
        d_Y[i1 + (d_Y.size(0) * b_i)] = c_B[i1 + (c_B.size(0) * b_i)];
      }
    }
    u0 = A.size(0);
    g_n = A.size(1);
    if (u0 <= g_n) {
      g_n = u0;
    }
    u0 = c_B.size(0);
    if (u0 <= g_n) {
      g_n = u0;
    }
    nrhs = c_B.size(1) - 1;
    LDA = A.size(0);
    e_A.set_size(A.size(0), A.size(1));
    minmn = A.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = A.size(0);
      for (i1 = 0; i1 < maxmn; i1++) {
        e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
    jpvt.set_size(1, g_n);
    jpvt[0] = 1;
    minmn = 1;
    for (k = 2; k <= g_n; k++) {
      minmn++;
      jpvt[k - 1] = minmn;
    }
    ldap1 = A.size(0);
    u0 = g_n - 1;
    if (u0 > g_n) {
      u0 = g_n;
    }
    for (j = 0; j < u0; j++) {
      int32_T jj;
      int32_T mmj_tmp;
      int32_T rankA;
      mmj_tmp = g_n - j;
      nb = j * (LDA + 1);
      jj = j * (ldap1 + 1);
      rankA = nb + 2;
      if (mmj_tmp < 1) {
        minmn = -1;
      } else {
        minmn = 0;
        if (mmj_tmp > 1) {
          tol = std::abs(e_A[jj]);
          for (k = 2; k <= mmj_tmp; k++) {
            real_T s;
            s = std::abs(e_A[(nb + k) - 1]);
            if (s > tol) {
              minmn = k - 1;
              tol = s;
            }
          }
        }
      }
      if (e_A[jj + minmn] != 0.0) {
        if (minmn != 0) {
          maxmn = j + minmn;
          jpvt[j] = maxmn + 1;
          for (k = 0; k < g_n; k++) {
            minmn = k * LDA;
            mn = j + minmn;
            tol = e_A[mn];
            b_i = maxmn + minmn;
            e_A[mn] = e_A[b_i];
            e_A[b_i] = tol;
          }
        }
        b_i = jj + mmj_tmp;
        for (d_i = rankA; d_i <= b_i; d_i++) {
          e_A[d_i - 1] = e_A[d_i - 1] / e_A[jj];
        }
      }
      maxmn = nb + LDA;
      mn = jj + ldap1;
      for (nb = 0; nb <= (mmj_tmp - 2); nb++) {
        minmn = maxmn + (nb * LDA);
        tol = e_A[minmn];
        if (e_A[minmn] != 0.0) {
          b_i = mn + 2;
          i1 = mmj_tmp + mn;
          for (minmn = b_i; minmn <= i1; minmn++) {
            e_A[minmn - 1] =
                e_A[minmn - 1] + (e_A[((jj + minmn) - mn) - 1] * (-tol));
          }
        }
        mn += LDA;
      }
    }
    LDA = e_A.size(0);
    minmn = c_B.size(0);
    for (d_i = 0; d_i <= (g_n - 2); d_i++) {
      b_i = jpvt[d_i];
      if (b_i != (d_i + 1)) {
        for (j = 0; j <= nrhs; j++) {
          tol = d_Y[d_i + (d_Y.size(0) * j)];
          d_Y[d_i + (d_Y.size(0) * j)] = d_Y[(b_i + (d_Y.size(0) * j)) - 1];
          d_Y[(b_i + (d_Y.size(0) * j)) - 1] = tol;
        }
      }
    }
    for (j = 0; j <= nrhs; j++) {
      maxmn = minmn * j;
      for (k = 0; k < g_n; k++) {
        mn = LDA * k;
        b_i = k + maxmn;
        if (d_Y[b_i] != 0.0) {
          i1 = k + 2;
          for (d_i = i1; d_i <= g_n; d_i++) {
            nb = (d_i + maxmn) - 1;
            d_Y[nb] = d_Y[nb] - (d_Y[b_i] * e_A[(d_i + mn) - 1]);
          }
        }
      }
    }
    for (j = 0; j <= nrhs; j++) {
      maxmn = (minmn * j) - 1;
      for (k = g_n; k >= 1; k--) {
        mn = (LDA * (k - 1)) - 1;
        b_i = k + maxmn;
        if (d_Y[b_i] != 0.0) {
          d_Y[b_i] = d_Y[b_i] / e_A[k + mn];
          for (d_i = 0; d_i <= (k - 2); d_i++) {
            i1 = (d_i + maxmn) + 1;
            d_Y[i1] = d_Y[i1] - (d_Y[b_i] * e_A[(d_i + mn) + 1]);
          }
        }
      }
    }
  } else {
    real_T tol;
    int32_T d_i;
    int32_T j;
    int32_T k;
    int32_T mn;
    int32_T nb;
    int32_T rankA;
    int32_T u0;
    e_A.set_size(A.size(0), A.size(1));
    minmn = A.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = A.size(0);
      for (i1 = 0; i1 < maxmn; i1++) {
        e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
    internal::lapack::xgeqp3(e_A, tau, jpvt);
    rankA = 0;
    if (e_A.size(0) < e_A.size(1)) {
      minmn = e_A.size(0);
      maxmn = e_A.size(1);
    } else {
      minmn = e_A.size(1);
      maxmn = e_A.size(0);
    }
    if (minmn > 0) {
      boolean_T exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<real_T>(maxmn))) *
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
    d_B.set_size(c_B.size(0), c_B.size(1));
    minmn = c_B.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = c_B.size(0);
      for (i1 = 0; i1 < maxmn; i1++) {
        d_B[i1 + (d_B.size(0) * b_i)] = c_B[i1 + (c_B.size(0) * b_i)];
      }
    }
    nb = c_B.size(1);
    d_Y.set_size(e_A.size(1), c_B.size(1));
    minmn = c_B.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = e_A.size(1);
      for (i1 = 0; i1 < maxmn; i1++) {
        d_Y[i1 + (d_Y.size(0) * b_i)] = 0.0;
      }
    }
    minmn = e_A.size(0);
    maxmn = c_B.size(1);
    u0 = e_A.size(0);
    mn = e_A.size(1);
    if (u0 <= mn) {
      mn = u0;
    }
    for (j = 0; j < mn; j++) {
      if (tau[j] != 0.0) {
        for (k = 0; k < maxmn; k++) {
          tol = d_B[j + (d_B.size(0) * k)];
          b_i = j + 2;
          for (d_i = b_i; d_i <= minmn; d_i++) {
            tol += e_A[(d_i + (e_A.size(0) * j)) - 1] *
                   d_B[(d_i + (d_B.size(0) * k)) - 1];
          }
          tol *= tau[j];
          if (tol != 0.0) {
            d_B[j + (d_B.size(0) * k)] = d_B[j + (d_B.size(0) * k)] - tol;
            for (d_i = b_i; d_i <= minmn; d_i++) {
              d_B[(d_i + (d_B.size(0) * k)) - 1] =
                  d_B[(d_i + (d_B.size(0) * k)) - 1] -
                  (e_A[(d_i + (e_A.size(0) * j)) - 1] * tol);
            }
          }
        }
      }
    }
    for (k = 0; k < nb; k++) {
      for (d_i = 0; d_i < rankA; d_i++) {
        d_Y[(jpvt[d_i] + (d_Y.size(0) * k)) - 1] = d_B[d_i + (d_B.size(0) * k)];
      }
      for (j = rankA; j >= 1; j--) {
        b_i = jpvt[j - 1];
        d_Y[(b_i + (d_Y.size(0) * k)) - 1] =
            d_Y[(b_i + (d_Y.size(0) * k)) - 1] /
            e_A[(j + (e_A.size(0) * (j - 1))) - 1];
        for (d_i = 0; d_i <= (j - 2); d_i++) {
          d_Y[(jpvt[d_i] + (d_Y.size(0) * k)) - 1] =
              d_Y[(jpvt[d_i] + (d_Y.size(0) * k)) - 1] -
              (d_Y[(jpvt[j - 1] + (d_Y.size(0) * k)) - 1] *
               e_A[d_i + (e_A.size(0) * (j - 1))]);
        }
      }
    }
  }
  if (guard1) {
    d_Y.set_size(A.size(1), c_B.size(1));
    minmn = c_B.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      maxmn = A.size(1);
      for (i1 = 0; i1 < maxmn; i1++) {
        d_Y[i1 + (d_Y.size(0) * b_i)] = 0.0;
      }
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
