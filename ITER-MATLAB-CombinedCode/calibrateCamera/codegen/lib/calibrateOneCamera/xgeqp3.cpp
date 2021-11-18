//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xgeqp3.h"
#include "calibrateOneCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &tau
//                int jpvt[8]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
            int jpvt[8])
{
  double vn1[8];
  double vn2[8];
  double work[8];
  int b_i;
  int knt;
  int m;
  int minmana;
  bool guard1{false};
  m = A.size(0);
  minmana = A.size(0);
  if (minmana > 8) {
    minmana = 8;
  }
  tau.set_size(minmana);
  for (b_i = 0; b_i < minmana; b_i++) {
    tau[b_i] = 0.0;
  }
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else {
    minmana = A.size(0);
    if (minmana > 8) {
      minmana = 8;
    }
    if (minmana < 1) {
      guard1 = true;
    } else {
      double d;
      int lastv;
      int ma;
      int minmn;
      ma = A.size(0);
      minmn = A.size(0);
      if (minmn > 8) {
        minmn = 8;
      }
      for (lastv = 0; lastv < 8; lastv++) {
        jpvt[lastv] = lastv + 1;
        work[lastv] = 0.0;
        d = blas::xnrm2(m, A, (lastv * ma) + 1);
        vn1[lastv] = d;
        vn2[lastv] = d;
      }
      for (int c_i{0}; c_i < minmn; c_i++) {
        double b_atmp;
        double s;
        double smax;
        int b_ii;
        int ii_tmp;
        int ip1;
        int mmi;
        int pvt;
        ip1 = c_i + 2;
        ii_tmp = c_i * ma;
        b_ii = ii_tmp + c_i;
        mmi = m - c_i;
        minmana = 8 - c_i;
        if ((8 - c_i) < 1) {
          knt = -1;
        } else {
          knt = 0;
          if ((8 - c_i) > 1) {
            smax = std::abs(vn1[c_i]);
            for (lastv = 2; lastv <= minmana; lastv++) {
              s = std::abs(vn1[(c_i + lastv) - 1]);
              if (s > smax) {
                knt = lastv - 1;
                smax = s;
              }
            }
          }
        }
        pvt = c_i + knt;
        if ((pvt + 1) != (c_i + 1)) {
          minmana = pvt * ma;
          for (lastv = 0; lastv < m; lastv++) {
            knt = minmana + lastv;
            smax = A[knt];
            b_i = ii_tmp + lastv;
            A[knt] = A[b_i];
            A[b_i] = smax;
          }
          minmana = static_cast<int>(static_cast<signed char>(jpvt[pvt]));
          jpvt[pvt] = static_cast<int>(static_cast<signed char>(jpvt[c_i]));
          jpvt[c_i] = minmana;
          vn1[pvt] = vn1[c_i];
          vn2[pvt] = vn2[c_i];
        }
        if ((c_i + 1) < m) {
          b_atmp = A[b_ii];
          minmana = b_ii + 2;
          tau[c_i] = 0.0;
          if (mmi > 0) {
            smax = blas::xnrm2(mmi - 1, A, b_ii + 2);
            if (smax != 0.0) {
              s = rt_hypotd_snf(A[b_ii], smax);
              if (A[b_ii] >= 0.0) {
                s = -s;
              }
              if (std::abs(s) < 1.0020841800044864E-292) {
                knt = -1;
                b_i = b_ii + mmi;
                do {
                  knt++;
                  for (lastv = minmana; lastv <= b_i; lastv++) {
                    A[lastv - 1] = 9.9792015476736E+291 * A[lastv - 1];
                  }
                  s *= 9.9792015476736E+291;
                  b_atmp *= 9.9792015476736E+291;
                } while (!(std::abs(s) >= 1.0020841800044864E-292));
                s = rt_hypotd_snf(b_atmp, blas::xnrm2(mmi - 1, A, b_ii + 2));
                if (b_atmp >= 0.0) {
                  s = -s;
                }
                tau[c_i] = (s - b_atmp) / s;
                smax = 1.0 / (b_atmp - s);
                for (lastv = minmana; lastv <= b_i; lastv++) {
                  A[lastv - 1] = smax * A[lastv - 1];
                }
                for (lastv = 0; lastv <= knt; lastv++) {
                  s *= 1.0020841800044864E-292;
                }
                b_atmp = s;
              } else {
                tau[c_i] = (s - A[b_ii]) / s;
                smax = 1.0 / (A[b_ii] - s);
                b_i = b_ii + mmi;
                for (lastv = minmana; lastv <= b_i; lastv++) {
                  A[lastv - 1] = smax * A[lastv - 1];
                }
                b_atmp = s;
              }
            }
          }
          A[b_ii] = b_atmp;
        } else {
          tau[c_i] = 0.0;
        }
        if ((c_i + 1) < 8) {
          int ia;
          int jA;
          b_atmp = A[b_ii];
          A[b_ii] = 1.0;
          jA = (b_ii + ma) + 1;
          if (tau[c_i] != 0.0) {
            bool exitg1;
            lastv = mmi - 1;
            minmana = (b_ii + mmi) - 1;
            exitg1 = false;
            while ((!exitg1) && ((lastv + 1) > 0)) {
              if (A[minmana] == 0.0) {
                lastv--;
                minmana--;
              } else {
                exitg1 = true;
              }
            }
            pvt = 6 - c_i;
            exitg1 = false;
            while ((!exitg1) && ((pvt + 1) > 0)) {
              int exitg2;
              minmana = jA + (pvt * ma);
              ia = minmana;
              do {
                exitg2 = 0;
                if (ia <= (minmana + lastv)) {
                  if (A[ia - 1] != 0.0) {
                    exitg2 = 1;
                  } else {
                    ia++;
                  }
                } else {
                  pvt--;
                  exitg2 = 2;
                }
              } while (exitg2 == 0);
              if (exitg2 == 1) {
                exitg1 = true;
              }
            }
          } else {
            lastv = -1;
            pvt = -1;
          }
          if ((lastv + 1) > 0) {
            if ((pvt + 1) != 0) {
              if (0 <= pvt) {
                (void)std::memset(
                    &work[0], 0,
                    (static_cast<unsigned int>(static_cast<int>(pvt + 1))) *
                        (sizeof(double)));
              }
              minmana = 0;
              b_i = jA + (ma * pvt);
              ii_tmp = jA;
              while (((ma > 0) && (ii_tmp <= b_i)) ||
                     ((ma < 0) && (ii_tmp >= b_i))) {
                smax = 0.0;
                knt = ii_tmp + lastv;
                for (ia = ii_tmp; ia <= knt; ia++) {
                  smax += A[ia - 1] * A[(b_ii + ia) - ii_tmp];
                }
                work[minmana] += smax;
                minmana++;
                ii_tmp += ma;
              }
            }
            if (!((-tau[c_i]) == 0.0)) {
              for (knt = 0; knt <= pvt; knt++) {
                d = work[knt];
                if (d != 0.0) {
                  smax = d * (-tau[c_i]);
                  b_i = lastv + jA;
                  for (minmana = jA; minmana <= b_i; minmana++) {
                    A[minmana - 1] =
                        A[minmana - 1] + (A[(b_ii + minmana) - jA] * smax);
                  }
                }
                jA += ma;
              }
            }
          }
          A[b_ii] = b_atmp;
        }
        for (knt = ip1; knt < 9; knt++) {
          minmana = c_i + ((knt - 1) * ma);
          d = vn1[knt - 1];
          if (d != 0.0) {
            smax = std::abs(A[minmana]) / d;
            smax = 1.0 - (smax * smax);
            if (smax < 0.0) {
              smax = 0.0;
            }
            s = d / vn2[knt - 1];
            s = smax * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if ((c_i + 1) < m) {
                d = blas::xnrm2(mmi - 1, A, minmana + 2);
                vn1[knt - 1] = d;
                vn2[knt - 1] = d;
              } else {
                vn1[knt - 1] = 0.0;
                vn2[knt - 1] = 0.0;
              }
            } else {
              vn1[knt - 1] = d * std::sqrt(smax);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    for (knt = 0; knt < 8; knt++) {
      jpvt[knt] = knt + 1;
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xgeqp3.cpp
//
// [EOF]
//
