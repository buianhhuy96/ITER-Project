//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "qrsolve.h"
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                const ::coder::array<real_T, 1U> &c_B
//                real_T d_Y[8]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
void b_qrsolve(const ::coder::array<real_T, 2U> &A,
               const ::coder::array<real_T, 1U> &c_B, real_T d_Y[8])
{
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> d_B;
  real_T tau_data[8];
  real_T vn1[8];
  real_T vn2[8];
  real_T work[8];
  real_T smax;
  int32_T b_i;
  int32_T d_i;
  int32_T k;
  int32_T knt;
  int32_T m;
  int32_T minmana;
  int32_T minmn;
  int32_T pvt;
  int8_T jpvt[8];
  boolean_T exitg1;
  e_A.set_size(A.size(0), 8);
  minmana = A.size(0);
  for (b_i = 0; b_i < 8; b_i++) {
    for (pvt = 0; pvt < minmana; pvt++) {
      e_A[pvt + (e_A.size(0) * b_i)] = A[pvt + (A.size(0) * b_i)];
    }
  }
  m = A.size(0);
  minmana = A.size(0);
  if (minmana > 8) {
    minmana = 8;
  }
  if (0 <= (minmana - 1)) {
    (void)std::memset(&tau_data[0], 0,
                      (static_cast<uint32_T>(minmana)) * (sizeof(real_T)));
  }
  if (A.size(0) == 0) {
    for (k = 0; k < 8; k++) {
      jpvt[k] = static_cast<int8_T>(k + 1);
    }
  } else {
    real_T d;
    int32_T ma;
    ma = A.size(0);
    minmn = A.size(0);
    if (minmn > 8) {
      minmn = 8;
    }
    for (k = 0; k < 8; k++) {
      jpvt[k] = static_cast<int8_T>(k + 1);
      work[k] = 0.0;
      d = blas::xnrm2(m, A, (k * ma) + 1);
      vn1[k] = d;
      vn2[k] = d;
    }
    for (d_i = 0; d_i < minmn; d_i++) {
      real_T b_atmp;
      real_T s;
      int32_T b_ii;
      int32_T ip1;
      int32_T lastc;
      int32_T mmi;
      ip1 = d_i + 2;
      lastc = d_i * ma;
      b_ii = lastc + d_i;
      mmi = m - d_i;
      minmana = 8 - d_i;
      knt = 0;
      if ((8 - d_i) > 1) {
        smax = std::abs(vn1[d_i]);
        for (k = 2; k <= minmana; k++) {
          s = std::abs(vn1[(d_i + k) - 1]);
          if (s > smax) {
            knt = k - 1;
            smax = s;
          }
        }
      }
      pvt = d_i + knt;
      if (pvt != d_i) {
        minmana = pvt * ma;
        for (k = 0; k < m; k++) {
          knt = minmana + k;
          smax = e_A[knt];
          b_i = lastc + k;
          e_A[knt] = e_A[b_i];
          e_A[b_i] = smax;
        }
        minmana = static_cast<int32_T>(jpvt[pvt]);
        jpvt[pvt] = jpvt[d_i];
        jpvt[d_i] = static_cast<int8_T>(minmana);
        vn1[pvt] = vn1[d_i];
        vn2[pvt] = vn2[d_i];
      }
      if ((d_i + 1) < m) {
        b_atmp = e_A[b_ii];
        minmana = b_ii + 2;
        tau_data[d_i] = 0.0;
        if (mmi > 0) {
          smax = blas::xnrm2(mmi - 1, e_A, b_ii + 2);
          if (smax != 0.0) {
            s = rt_hypotd_snf(e_A[b_ii], smax);
            if (e_A[b_ii] >= 0.0) {
              s = -s;
            }
            if (std::abs(s) < 1.0020841800044864E-292) {
              knt = -1;
              b_i = b_ii + mmi;
              do {
                knt++;
                for (k = minmana; k <= b_i; k++) {
                  e_A[k - 1] = 9.9792015476736E+291 * e_A[k - 1];
                }
                s *= 9.9792015476736E+291;
                b_atmp *= 9.9792015476736E+291;
              } while (!(std::abs(s) >= 1.0020841800044864E-292));
              s = rt_hypotd_snf(b_atmp, blas::xnrm2(mmi - 1, e_A, b_ii + 2));
              if (b_atmp >= 0.0) {
                s = -s;
              }
              tau_data[d_i] = (s - b_atmp) / s;
              smax = 1.0 / (b_atmp - s);
              for (k = minmana; k <= b_i; k++) {
                e_A[k - 1] = smax * e_A[k - 1];
              }
              for (k = 0; k <= knt; k++) {
                s *= 1.0020841800044864E-292;
              }
              b_atmp = s;
            } else {
              tau_data[d_i] = (s - e_A[b_ii]) / s;
              smax = 1.0 / (e_A[b_ii] - s);
              b_i = b_ii + mmi;
              for (k = minmana; k <= b_i; k++) {
                e_A[k - 1] = smax * e_A[k - 1];
              }
              b_atmp = s;
            }
          }
        }
        e_A[b_ii] = b_atmp;
      } else {
        tau_data[d_i] = 0.0;
      }
      if ((d_i + 1) < 8) {
        int32_T jA;
        int32_T lastv;
        b_atmp = e_A[b_ii];
        e_A[b_ii] = 1.0;
        jA = (b_ii + ma) + 1;
        if (tau_data[d_i] != 0.0) {
          lastv = mmi - 1;
          minmana = (b_ii + mmi) - 1;
          exitg1 = false;
          while ((!exitg1) && ((lastv + 1) > 0)) {
            if (e_A[minmana] == 0.0) {
              lastv--;
              minmana--;
            } else {
              exitg1 = true;
            }
          }
          lastc = 6 - d_i;
          exitg1 = false;
          while ((!exitg1) && ((lastc + 1) > 0)) {
            int32_T exitg2;
            minmana = jA + (lastc * ma);
            k = minmana;
            do {
              exitg2 = 0;
              if (k <= (minmana + lastv)) {
                if (e_A[k - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  k++;
                }
              } else {
                lastc--;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
        } else {
          lastv = -1;
          lastc = -1;
        }
        if ((lastv + 1) > 0) {
          if ((lastc + 1) != 0) {
            if (0 <= lastc) {
              (void)std::memset(
                  &work[0], 0,
                  (static_cast<uint32_T>(static_cast<int32_T>(lastc + 1))) *
                      (sizeof(real_T)));
            }
            minmana = 0;
            b_i = jA + (ma * lastc);
            knt = jA;
            while (((ma > 0) && (knt <= b_i)) || ((ma < 0) && (knt >= b_i))) {
              smax = 0.0;
              pvt = knt + lastv;
              for (k = knt; k <= pvt; k++) {
                smax += e_A[k - 1] * e_A[(b_ii + k) - knt];
              }
              work[minmana] += smax;
              minmana++;
              knt += ma;
            }
          }
          if (!((-tau_data[d_i]) == 0.0)) {
            for (k = 0; k <= lastc; k++) {
              d = work[k];
              if (d != 0.0) {
                smax = d * (-tau_data[d_i]);
                b_i = lastv + jA;
                for (minmana = jA; minmana <= b_i; minmana++) {
                  e_A[minmana - 1] =
                      e_A[minmana - 1] + (e_A[(b_ii + minmana) - jA] * smax);
                }
              }
              jA += ma;
            }
          }
        }
        e_A[b_ii] = b_atmp;
      }
      for (k = ip1; k < 9; k++) {
        minmana = d_i + ((k - 1) * ma);
        d = vn1[k - 1];
        if (d != 0.0) {
          smax = std::abs(e_A[minmana]) / d;
          smax = 1.0 - (smax * smax);
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[k - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if ((d_i + 1) < m) {
              d = blas::xnrm2(mmi - 1, e_A, minmana + 2);
              vn1[k - 1] = d;
              vn2[k - 1] = d;
            } else {
              vn1[k - 1] = 0.0;
              vn2[k - 1] = 0.0;
            }
          } else {
            vn1[k - 1] = d * std::sqrt(smax);
          }
        }
      }
    }
  }
  pvt = 0;
  if (e_A.size(0) < 8) {
    minmn = e_A.size(0);
    minmana = 8;
  } else {
    minmn = 8;
    minmana = e_A.size(0);
  }
  if (minmn > 0) {
    smax = std::fmin(1.4901161193847656E-8,
                     2.2204460492503131E-15 * (static_cast<real_T>(minmana))) *
           std::abs(e_A[0]);
    exitg1 = false;
    while ((!exitg1) && (pvt < minmn)) {
      if (!(std::abs(e_A[pvt + (e_A.size(0) * pvt)]) <= smax)) {
        pvt++;
      } else {
        exitg1 = true;
      }
    }
  }
  d_B.set_size(c_B.size(0));
  minmana = c_B.size(0);
  for (b_i = 0; b_i < minmana; b_i++) {
    d_B[b_i] = c_B[b_i];
  }
  (void)std::memset(&d_Y[0], 0, 8U * (sizeof(real_T)));
  m = e_A.size(0);
  minmana = e_A.size(0);
  if (minmana > 8) {
    minmana = 8;
  }
  for (k = 0; k < minmana; k++) {
    if (tau_data[k] != 0.0) {
      smax = d_B[k];
      b_i = k + 2;
      for (d_i = b_i; d_i <= m; d_i++) {
        smax += e_A[(d_i + (e_A.size(0) * k)) - 1] * d_B[d_i - 1];
      }
      smax *= tau_data[k];
      if (smax != 0.0) {
        d_B[k] = d_B[k] - smax;
        for (d_i = b_i; d_i <= m; d_i++) {
          d_B[d_i - 1] =
              d_B[d_i - 1] - (e_A[(d_i + (e_A.size(0) * k)) - 1] * smax);
        }
      }
    }
  }
  for (d_i = 0; d_i < pvt; d_i++) {
    d_Y[jpvt[d_i] - 1] = d_B[d_i];
  }
  for (k = pvt; k >= 1; k--) {
    minmana = (static_cast<int32_T>(jpvt[k - 1])) - 1;
    d_Y[minmana] /= e_A[(k + (e_A.size(0) * (k - 1))) - 1];
    for (d_i = 0; d_i <= (k - 2); d_i++) {
      knt = (static_cast<int32_T>(jpvt[d_i])) - 1;
      d_Y[knt] -= d_Y[minmana] * e_A[d_i + (e_A.size(0) * (k - 1))];
    }
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                const ::coder::array<real_T, 1U> &c_B
//                real_T b_Y_data[]
//                int32_T *Y_size
//                int32_T *rankA
// Return Type  : void
//
void qrsolve(const ::coder::array<real_T, 2U> &A,
             const ::coder::array<real_T, 1U> &c_B, real_T b_Y_data[],
             int32_T *Y_size, int32_T *rankA)
{
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> d_B;
  ::coder::array<real_T, 1U> tau;
  ::coder::array<int32_T, 2U> jpvt;
  real_T tol;
  int32_T assumedRank;
  int32_T b_i;
  int32_T d_i;
  int32_T maxmn;
  int32_T minmn;
  int32_T mn;
  e_A.set_size(A.size(0), A.size(1));
  mn = A.size(1);
  for (b_i = 0; b_i < mn; b_i++) {
    minmn = A.size(0);
    for (maxmn = 0; maxmn < minmn; maxmn++) {
      e_A[maxmn + (e_A.size(0) * b_i)] = A[maxmn + (A.size(0) * b_i)];
    }
  }
  lapack::xgeqp3(e_A, tau, jpvt);
  *rankA = 0;
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
    while ((!exitg1) && ((*rankA) < minmn)) {
      if (!(std::abs(e_A[(*rankA) + (e_A.size(0) * (*rankA))]) <= tol)) {
        (*rankA)++;
      } else {
        exitg1 = true;
      }
    }
  }
  assumedRank = 0;
  minmn = e_A.size(0);
  mn = e_A.size(1);
  if (minmn <= mn) {
    mn = minmn;
  }
  if (mn > 0) {
    for (minmn = 0; minmn < mn; minmn++) {
      if (e_A[minmn + (e_A.size(0) * minmn)] != 0.0) {
        assumedRank++;
      }
    }
  }
  *Y_size = e_A.size(1);
  mn = e_A.size(1);
  if (0 <= (mn - 1)) {
    (void)std::memset(&b_Y_data[0], 0,
                      (static_cast<uint32_T>(mn)) * (sizeof(real_T)));
  }
  d_B.set_size(c_B.size(0));
  mn = c_B.size(0);
  for (b_i = 0; b_i < mn; b_i++) {
    d_B[b_i] = c_B[b_i];
  }
  maxmn = e_A.size(0);
  minmn = e_A.size(0);
  mn = e_A.size(1);
  if (minmn <= mn) {
    mn = minmn;
  }
  for (minmn = 0; minmn < mn; minmn++) {
    if (tau[minmn] != 0.0) {
      tol = d_B[minmn];
      b_i = minmn + 2;
      for (d_i = b_i; d_i <= maxmn; d_i++) {
        tol += e_A[(d_i + (e_A.size(0) * minmn)) - 1] * d_B[d_i - 1];
      }
      tol *= tau[minmn];
      if (tol != 0.0) {
        d_B[minmn] = d_B[minmn] - tol;
        for (d_i = b_i; d_i <= maxmn; d_i++) {
          d_B[d_i - 1] =
              d_B[d_i - 1] - (e_A[(d_i + (e_A.size(0) * minmn)) - 1] * tol);
        }
      }
    }
  }
  for (d_i = 0; d_i < assumedRank; d_i++) {
    b_Y_data[jpvt[d_i] - 1] = d_B[d_i];
  }
  for (minmn = assumedRank; minmn >= 1; minmn--) {
    b_Y_data[jpvt[minmn - 1] - 1] /=
        e_A[(minmn + (e_A.size(0) * (minmn - 1))) - 1];
    for (d_i = 0; d_i <= (minmn - 2); d_i++) {
      b_Y_data[jpvt[d_i] - 1] -= b_Y_data[jpvt[minmn - 1] - 1] *
                                 e_A[d_i + (e_A.size(0) * (minmn - 1))];
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
