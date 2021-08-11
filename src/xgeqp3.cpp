//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "xgeqp3.h"
#include "calibrateHandeye_rtwutil.h"
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
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
            int jpvt[8])
{
  double vn1[8];
  double vn2[8];
  double work[8];
  int i;
  int knt;
  int m;
  int minmana;
  boolean_T guard1{false};
  m = A.size(0);
  minmana = A.size(0);
  if (minmana >= 8) {
    minmana = 8;
  }
  tau.set_size(minmana);
  for (i = 0; i < minmana; i++) {
    tau[i] = 0.0;
  }
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else {
    minmana = A.size(0);
    if (minmana >= 8) {
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
      if (minmn >= 8) {
        minmn = 8;
      }
      for (lastv = 0; lastv < 8; lastv++) {
        jpvt[lastv] = lastv + 1;
        work[lastv] = 0.0;
        d = blas::xnrm2(m, A, (lastv * ma) + 1);
        vn1[lastv] = d;
        vn2[lastv] = d;
      }
      for (int b_i{0}; b_i < minmn; b_i++) {
        double atmp;
        double s;
        double smax;
        int ii;
        int ii_tmp;
        int ip1;
        int mmi;
        int pvt;
        ip1 = b_i + 2;
        ii_tmp = b_i * ma;
        ii = ii_tmp + b_i;
        mmi = m - b_i;
        minmana = 8 - b_i;
        if ((8 - b_i) < 1) {
          knt = -1;
        } else {
          knt = 0;
          if ((8 - b_i) > 1) {
            smax = std::abs(vn1[b_i]);
            for (lastv = 2; lastv <= minmana; lastv++) {
              s = std::abs(vn1[(b_i + lastv) - 1]);
              if (s > smax) {
                knt = lastv - 1;
                smax = s;
              }
            }
          }
        }
        pvt = b_i + knt;
        if ((pvt + 1) != (b_i + 1)) {
          minmana = pvt * ma;
          for (lastv = 0; lastv < m; lastv++) {
            knt = minmana + lastv;
            smax = A[knt];
            i = ii_tmp + lastv;
            A[knt] = A[i];
            A[i] = smax;
          }
          minmana = static_cast<int>(static_cast<signed char>(jpvt[pvt]));
          jpvt[pvt] = static_cast<int>(static_cast<signed char>(jpvt[b_i]));
          jpvt[b_i] = minmana;
          vn1[pvt] = vn1[b_i];
          vn2[pvt] = vn2[b_i];
        }
        if ((b_i + 1) < m) {
          atmp = A[ii];
          minmana = ii + 2;
          tau[b_i] = 0.0;
          if (mmi > 0) {
            smax = blas::xnrm2(mmi - 1, A, ii + 2);
            if (smax != 0.0) {
              s = rt_hypotd_snf(A[ii], smax);
              if (A[ii] >= 0.0) {
                s = -s;
              }
              if (std::abs(s) < 1.0020841800044864E-292) {
                knt = -1;
                i = ii + mmi;
                do {
                  knt++;
                  for (lastv = minmana; lastv <= i; lastv++) {
                    A[lastv - 1] = 9.9792015476736E+291 * A[lastv - 1];
                  }
                  s *= 9.9792015476736E+291;
                  atmp *= 9.9792015476736E+291;
                } while (!(std::abs(s) >= 1.0020841800044864E-292));
                s = rt_hypotd_snf(atmp, blas::xnrm2(mmi - 1, A, ii + 2));
                if (atmp >= 0.0) {
                  s = -s;
                }
                tau[b_i] = (s - atmp) / s;
                smax = 1.0 / (atmp - s);
                for (lastv = minmana; lastv <= i; lastv++) {
                  A[lastv - 1] = smax * A[lastv - 1];
                }
                for (lastv = 0; lastv <= knt; lastv++) {
                  s *= 1.0020841800044864E-292;
                }
                atmp = s;
              } else {
                tau[b_i] = (s - A[ii]) / s;
                smax = 1.0 / (A[ii] - s);
                i = ii + mmi;
                for (lastv = minmana; lastv <= i; lastv++) {
                  A[lastv - 1] = smax * A[lastv - 1];
                }
                atmp = s;
              }
            }
          }
          A[ii] = atmp;
        } else {
          tau[b_i] = 0.0;
        }
        if ((b_i + 1) < 8) {
          int ia;
          int jA;
          atmp = A[ii];
          A[ii] = 1.0;
          jA = (ii + ma) + 1;
          if (tau[b_i] != 0.0) {
            boolean_T exitg1;
            lastv = mmi - 1;
            minmana = (ii + mmi) - 1;
            exitg1 = false;
            while ((!exitg1) && ((lastv + 1) > 0)) {
              if (A[minmana] == 0.0) {
                lastv--;
                minmana--;
              } else {
                exitg1 = true;
              }
            }
            pvt = 6 - b_i;
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
              i = jA + (ma * pvt);
              for (ii_tmp = jA; (ma < 0) ? (ii_tmp >= i) : (ii_tmp <= i);
                   ii_tmp += ma) {
                smax = 0.0;
                knt = ii_tmp + lastv;
                for (ia = ii_tmp; ia <= knt; ia++) {
                  smax += A[ia - 1] * A[(ii + ia) - ii_tmp];
                }
                work[minmana] += smax;
                minmana++;
              }
            }
            if (!((-tau[b_i]) == 0.0)) {
              for (knt = 0; knt <= pvt; knt++) {
                d = work[knt];
                if (d != 0.0) {
                  smax = d * (-tau[b_i]);
                  i = lastv + jA;
                  for (minmana = jA; minmana <= i; minmana++) {
                    A[minmana - 1] =
                        A[minmana - 1] + (A[(ii + minmana) - jA] * smax);
                  }
                }
                jA += ma;
              }
            }
          }
          A[ii] = atmp;
        }
        for (knt = ip1; knt < 9; knt++) {
          minmana = b_i + ((knt - 1) * ma);
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
              if ((b_i + 1) < m) {
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

//
// Arguments    : ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &tau
//                ::coder::array<int, 2U> &jpvt
// Return Type  : void
//
void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
            ::coder::array<int, 2U> &jpvt)
{
  array<double, 1U> vn1;
  array<double, 1U> vn2;
  array<double, 1U> work;
  int i;
  int j;
  int knt;
  int m;
  int minmana;
  int n;
  boolean_T guard1{false};
  m = A.size(0);
  n = A.size(1);
  knt = A.size(0);
  minmana = A.size(1);
  if (knt < minmana) {
    minmana = knt;
  }
  tau.set_size(minmana);
  for (i = 0; i < minmana; i++) {
    tau[i] = 0.0;
  }
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else {
    knt = A.size(0);
    minmana = A.size(1);
    if (knt < minmana) {
      minmana = knt;
    }
    if (minmana < 1) {
      guard1 = true;
    } else {
      double smax;
      int k;
      int ma;
      int minmn;
      minmana = A.size(1);
      jpvt.set_size(1, minmana);
      for (i = 0; i < minmana; i++) {
        jpvt[i] = 0;
      }
      for (k = 0; k < n; k++) {
        jpvt[k] = k + 1;
      }
      ma = A.size(0);
      knt = A.size(0);
      minmn = A.size(1);
      if (knt < minmn) {
        minmn = knt;
      }
      minmana = A.size(1);
      work.set_size(minmana);
      for (i = 0; i < minmana; i++) {
        work[i] = 0.0;
      }
      minmana = A.size(1);
      vn1.set_size(minmana);
      for (i = 0; i < minmana; i++) {
        vn1[i] = 0.0;
      }
      minmana = A.size(1);
      vn2.set_size(minmana);
      for (i = 0; i < minmana; i++) {
        vn2[i] = 0.0;
      }
      for (j = 0; j < n; j++) {
        smax = blas::xnrm2(m, A, (j * ma) + 1);
        vn1[j] = smax;
        vn2[j] = smax;
      }
      for (int b_i{0}; b_i < minmn; b_i++) {
        double s;
        double temp2;
        int ii;
        int ip1;
        int mmi;
        int nmi;
        int pvt;
        ip1 = b_i + 2;
        j = b_i * ma;
        ii = j + b_i;
        nmi = n - b_i;
        mmi = m - b_i;
        if (nmi < 1) {
          minmana = -1;
        } else {
          minmana = 0;
          if (nmi > 1) {
            smax = std::abs(vn1[b_i]);
            for (k = 2; k <= nmi; k++) {
              s = std::abs(vn1[(b_i + k) - 1]);
              if (s > smax) {
                minmana = k - 1;
                smax = s;
              }
            }
          }
        }
        pvt = b_i + minmana;
        if ((pvt + 1) != (b_i + 1)) {
          minmana = pvt * ma;
          for (k = 0; k < m; k++) {
            knt = minmana + k;
            smax = A[knt];
            i = j + k;
            A[knt] = A[i];
            A[i] = smax;
          }
          minmana = jpvt[pvt];
          jpvt[pvt] = jpvt[b_i];
          jpvt[b_i] = minmana;
          vn1[pvt] = vn1[b_i];
          vn2[pvt] = vn2[b_i];
        }
        if ((b_i + 1) < m) {
          temp2 = A[ii];
          minmana = ii + 2;
          tau[b_i] = 0.0;
          if (mmi > 0) {
            smax = blas::xnrm2(mmi - 1, A, ii + 2);
            if (smax != 0.0) {
              s = rt_hypotd_snf(A[ii], smax);
              if (A[ii] >= 0.0) {
                s = -s;
              }
              if (std::abs(s) < 1.0020841800044864E-292) {
                knt = -1;
                i = ii + mmi;
                do {
                  knt++;
                  for (k = minmana; k <= i; k++) {
                    A[k - 1] = 9.9792015476736E+291 * A[k - 1];
                  }
                  s *= 9.9792015476736E+291;
                  temp2 *= 9.9792015476736E+291;
                } while (!(std::abs(s) >= 1.0020841800044864E-292));
                s = rt_hypotd_snf(temp2, blas::xnrm2(mmi - 1, A, ii + 2));
                if (temp2 >= 0.0) {
                  s = -s;
                }
                tau[b_i] = (s - temp2) / s;
                smax = 1.0 / (temp2 - s);
                for (k = minmana; k <= i; k++) {
                  A[k - 1] = smax * A[k - 1];
                }
                for (k = 0; k <= knt; k++) {
                  s *= 1.0020841800044864E-292;
                }
                temp2 = s;
              } else {
                tau[b_i] = (s - A[ii]) / s;
                smax = 1.0 / (A[ii] - s);
                i = ii + mmi;
                for (k = minmana; k <= i; k++) {
                  A[k - 1] = smax * A[k - 1];
                }
                temp2 = s;
              }
            }
          }
          A[ii] = temp2;
        } else {
          tau[b_i] = 0.0;
        }
        if ((b_i + 1) < n) {
          int jA;
          int lastv;
          temp2 = A[ii];
          A[ii] = 1.0;
          jA = (ii + ma) + 1;
          if (tau[b_i] != 0.0) {
            boolean_T exitg1;
            lastv = mmi - 1;
            minmana = (ii + mmi) - 1;
            exitg1 = false;
            while ((!exitg1) && ((lastv + 1) > 0)) {
              if (A[minmana] == 0.0) {
                lastv--;
                minmana--;
              } else {
                exitg1 = true;
              }
            }
            knt = nmi - 2;
            exitg1 = false;
            while ((!exitg1) && ((knt + 1) > 0)) {
              int exitg2;
              minmana = jA + (knt * ma);
              k = minmana;
              do {
                exitg2 = 0;
                if (k <= (minmana + lastv)) {
                  if (A[k - 1] != 0.0) {
                    exitg2 = 1;
                  } else {
                    k++;
                  }
                } else {
                  knt--;
                  exitg2 = 2;
                }
              } while (exitg2 == 0);
              if (exitg2 == 1) {
                exitg1 = true;
              }
            }
          } else {
            lastv = -1;
            knt = -1;
          }
          if ((lastv + 1) > 0) {
            if ((knt + 1) != 0) {
              for (pvt = 0; pvt <= knt; pvt++) {
                work[pvt] = 0.0;
              }
              pvt = 0;
              i = jA + (ma * knt);
              for (j = jA; (ma < 0) ? (j >= i) : (j <= i); j += ma) {
                smax = 0.0;
                minmana = j + lastv;
                for (k = j; k <= minmana; k++) {
                  smax += A[k - 1] * A[(ii + k) - j];
                }
                work[pvt] = work[pvt] + smax;
                pvt++;
              }
            }
            if (!((-tau[b_i]) == 0.0)) {
              for (j = 0; j <= knt; j++) {
                if (work[j] != 0.0) {
                  smax = work[j] * (-tau[b_i]);
                  i = lastv + jA;
                  for (minmana = jA; minmana <= i; minmana++) {
                    A[minmana - 1] =
                        A[minmana - 1] + (A[(ii + minmana) - jA] * smax);
                  }
                }
                jA += ma;
              }
            }
          }
          A[ii] = temp2;
        }
        for (j = ip1; j <= n; j++) {
          knt = b_i + ((j - 1) * ma);
          smax = vn1[j - 1];
          if (smax != 0.0) {
            s = std::abs(A[knt]) / smax;
            s = 1.0 - (s * s);
            if (s < 0.0) {
              s = 0.0;
            }
            temp2 = smax / vn2[j - 1];
            temp2 = s * (temp2 * temp2);
            if (temp2 <= 1.4901161193847656E-8) {
              if ((b_i + 1) < m) {
                smax = blas::xnrm2(mmi - 1, A, knt + 2);
                vn1[j - 1] = smax;
                vn2[j - 1] = smax;
              } else {
                vn1[j - 1] = 0.0;
                vn2[j - 1] = 0.0;
              }
            } else {
              vn1[j - 1] = smax * std::sqrt(s);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    minmana = A.size(1);
    jpvt.set_size(1, minmana);
    for (i = 0; i < minmana; i++) {
      jpvt[i] = 0;
    }
    for (j = 0; j < n; j++) {
      jpvt[j] = j + 1;
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

//
// File trailer for xgeqp3.cpp
//
// [EOF]
//
