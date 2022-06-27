//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xgeqp3.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzgeqp3.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <string.h>

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
void b_xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
              int jpvt[8])
{
  double vn1[8];
  double vn2[8];
  double work[8];
  double d;
  int b_m;
  int b_u0;
  int loop_ub;
  int minmana;
  int minmn;
  int u0;
  bool guard1{false};
  b_m = A.size(0);
  u0 = A.size(0);
  if (u0 <= 8) {
    minmana = u0;
  } else {
    minmana = 8;
  }
  b_u0 = A.size(0);
  if (b_u0 <= 8) {
    minmn = b_u0;
  } else {
    minmn = 8;
  }
  tau.set_size(minmana);
  loop_ub = minmana;
  if ((static_cast<int>(minmana < 4)) != 0) {
    for (int b_i{0}; b_i < minmana; b_i++) {
      tau[b_i] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      tau[b_i] = 0.0;
    }
  }
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else if (minmn < 1) {
    guard1 = true;
  } else {
    int b_loop_ub;
    int b_minmn;
    int c_u0;
    int ma;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < 8; k++) {
      jpvt[k] = k + 1;
    }
    tau.set_size(minmana);
    b_loop_ub = minmana;
    if ((static_cast<int>(minmana < 4)) != 0) {
      for (int i1{0}; i1 < minmana; i1++) {
        tau[i1] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        tau[i1] = 0.0;
      }
    }
    ma = A.size(0);
    c_u0 = A.size(0);
    if (c_u0 <= 8) {
      b_minmn = c_u0;
    } else {
      b_minmn = 8;
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

    for (int b_j = 0; b_j < 8; b_j++) {
      work[b_j] = 0.0;
      d = blas::b_xnrm2(b_m, A, (b_j * ma) + 1);
      vn1[b_j] = d;
      vn2[b_j] = d;
    }
    for (int c_i{0}; c_i < b_minmn; c_i++) {
      int b_mmi;
      int c_ii;
      int h_n;
      int idxmax;
      int ii_tmp;
      int ip1;
      int pvt;
      ip1 = c_i + 2;
      ii_tmp = c_i * ma;
      c_ii = ii_tmp + c_i;
      b_mmi = b_m - c_i;
      h_n = 8 - c_i;
      if ((8 - c_i) < 1) {
        idxmax = -1;
      } else {
        idxmax = 0;
        if ((8 - c_i) > 1) {
          double smax;
          smax = std::abs(vn1[c_i]);
          for (int b_k{2}; b_k <= h_n; b_k++) {
            double s;
            s = std::abs(vn1[(c_i + b_k) - 1]);
            if (s > smax) {
              idxmax = b_k - 1;
              smax = s;
            }
          }
        }
      }
      pvt = c_i + idxmax;
      if ((pvt + 1) != (c_i + 1)) {
        int b_ix;
        b_ix = pvt * ma;
        for (int c_k{0}; c_k < b_m; c_k++) {
          double temp;
          int i2;
          int temp_tmp;
          temp_tmp = b_ix + c_k;
          temp = A[temp_tmp];
          i2 = ii_tmp + c_k;
          A[temp_tmp] = A[i2];
          A[i2] = temp;
        }
        int itemp;
        itemp = static_cast<int>(static_cast<signed char>(jpvt[pvt]));
        jpvt[pvt] = static_cast<int>(static_cast<signed char>(jpvt[c_i]));
        jpvt[c_i] = itemp;
        vn1[pvt] = vn1[c_i];
        vn2[pvt] = vn2[c_i];
      }
      if ((c_i + 1) < b_m) {
        double d_atmp;
        int ix0;
        d_atmp = A[c_ii];
        ix0 = c_ii + 2;
        tau[c_i] = 0.0;
        if (b_mmi > 0) {
          double xnorm_tmp;
          xnorm_tmp = blas::b_xnrm2(b_mmi - 1, A, c_ii + 2);
          if (xnorm_tmp != 0.0) {
            double beta1;
            beta1 = rt_hypotd_snf(A[c_ii], xnorm_tmp);
            if (A[c_ii] >= 0.0) {
              beta1 = -beta1;
            }
            if (std::abs(beta1) < 1.0020841800044864E-292) {
              double c_a;
              int i3;
              int knt;
              knt = -1;
              i3 = c_ii + b_mmi;
              do {
                knt++;
                for (int e_k{ix0}; e_k <= i3; e_k++) {
                  A[e_k - 1] = 9.9792015476736E+291 * A[e_k - 1];
                }
                beta1 *= 9.9792015476736E+291;
                d_atmp *= 9.9792015476736E+291;
              } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
              beta1 =
                  rt_hypotd_snf(d_atmp, blas::b_xnrm2(b_mmi - 1, A, c_ii + 2));
              if (d_atmp >= 0.0) {
                beta1 = -beta1;
              }
              tau[c_i] = (beta1 - d_atmp) / beta1;
              c_a = 1.0 / (d_atmp - beta1);
              for (int g_k{ix0}; g_k <= i3; g_k++) {
                A[g_k - 1] = c_a * A[g_k - 1];
              }
              for (int h_k{0}; h_k <= knt; h_k++) {
                beta1 *= 1.0020841800044864E-292;
              }
              d_atmp = beta1;
            } else {
              double b_a;
              int i4;
              tau[c_i] = (beta1 - A[c_ii]) / beta1;
              b_a = 1.0 / (A[c_ii] - beta1);
              i4 = c_ii + b_mmi;
              for (int d_k{ix0}; d_k <= i4; d_k++) {
                A[d_k - 1] = b_a * A[d_k - 1];
              }
              d_atmp = beta1;
            }
          }
        }
        A[c_ii] = d_atmp;
      } else {
        tau[c_i] = 0.0;
      }
      if ((c_i + 1) < 8) {
        double e_atmp;
        int ic0;
        int lastc;
        int lastv;
        e_atmp = A[c_ii];
        A[c_ii] = 1.0;
        ic0 = (c_ii + ma) + 1;
        if (tau[c_i] != 0.0) {
          int b_lastc;
          int d_i;
          bool exitg1;
          lastv = b_mmi - 1;
          d_i = (c_ii + b_mmi) - 1;
          exitg1 = false;
          while ((!exitg1) && ((lastv + 1) > 0)) {
            if (A[d_i] == 0.0) {
              lastv--;
              d_i--;
            } else {
              exitg1 = true;
            }
          }
          b_lastc = 6 - c_i;
          exitg1 = false;
          while ((!exitg1) && ((b_lastc + 1) > 0)) {
            int coltop;
            int exitg2;
            int ia;
            coltop = ic0 + (b_lastc * ma);
            ia = coltop;
            do {
              exitg2 = 0;
              if (ia <= (coltop + lastv)) {
                if (A[ia - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  ia++;
                }
              } else {
                b_lastc--;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
          lastc = b_lastc;
        } else {
          lastv = -1;
          lastc = -1;
        }
        if ((lastv + 1) > 0) {
          if ((lastc + 1) != 0) {
            int b_iy;
            int i5;
            int iac;
            if (0 <= lastc) {
              (void)std::memset(
                  &work[0], 0,
                  (static_cast<unsigned int>(static_cast<int>(lastc + 1))) *
                      (sizeof(double)));
            }
            b_iy = 0;
            i5 = ic0 + (ma * lastc);
            iac = ic0;
            while (((ma > 0) && (iac <= i5)) || ((ma < 0) && (iac >= i5))) {
              double c;
              int i7;
              c = 0.0;
              i7 = iac + lastv;
              for (int b_ia{iac}; b_ia <= i7; b_ia++) {
                c += A[b_ia - 1] * A[(c_ii + b_ia) - iac];
              }
              work[b_iy] += c;
              b_iy++;
              iac += ma;
            }
          }
          if (!((-tau[c_i]) == 0.0)) {
            int jA;
            jA = ic0;
            for (int d_j{0}; d_j <= lastc; d_j++) {
              double d3;
              d3 = work[d_j];
              if (d3 != 0.0) {
                double b_temp;
                int i6;
                b_temp = d3 * (-tau[c_i]);
                i6 = lastv + jA;
                for (int ijA{jA}; ijA <= i6; ijA++) {
                  A[ijA - 1] = A[ijA - 1] + (A[(c_ii + ijA) - jA] * b_temp);
                }
              }
              jA += ma;
            }
          }
        }
        A[c_ii] = e_atmp;
      }
      for (int c_j{ip1}; c_j < 9; c_j++) {
        double b_d1;
        int ij;
        ij = c_i + ((c_j - 1) * ma);
        b_d1 = vn1[c_j - 1];
        if (b_d1 != 0.0) {
          double temp1;
          double temp2;
          temp1 = std::abs(A[ij]) / b_d1;
          temp1 = 1.0 - (temp1 * temp1);
          if (temp1 < 0.0) {
            temp1 = 0.0;
          }
          temp2 = b_d1 / vn2[c_j - 1];
          temp2 = temp1 * (temp2 * temp2);
          if (temp2 <= 1.4901161193847656E-8) {
            if ((c_i + 1) < b_m) {
              double d2;
              d2 = blas::b_xnrm2(b_mmi - 1, A, ij + 2);
              vn1[c_j - 1] = d2;
              vn2[c_j - 1] = d2;
            } else {
              vn1[c_j - 1] = 0.0;
              vn2[c_j - 1] = 0.0;
            }
          } else {
            vn1[c_j - 1] = b_d1 * std::sqrt(temp1);
          }
        }
      }
    }
  }
  if (guard1) {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int j = 0; j < 8; j++) {
      jpvt[j] = j + 1;
    }
  }
}

//
// Arguments    : double A[15][15]
//                int b_m
//                int h_n
//                int jpvt[15]
//                double tau[15]
// Return Type  : void
//
void c_xgeqp3(double A[15][15], int b_m, int h_n, int jpvt[15], double tau[15])
{
  double vn1[15];
  double vn2[15];
  double work[15];
  double d;
  double d_atmp;
  int minmn;
  if (b_m <= h_n) {
    minmn = b_m;
  } else {
    minmn = h_n;
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 15; b_i++) {
    tau[b_i] = 0.0;
  }
  if (minmn < 1) {
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int b_j{0}; b_j < h_n; b_j++) {
        jpvt[b_j] = b_j + 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_j = 0; b_j < h_n; b_j++) {
        jpvt[b_j] = b_j + 1;
      }
    }
  } else {
    int nfxd;
    nfxd = 0;
    for (int j{0}; j < h_n; j++) {
      if (jpvt[j] != 0) {
        nfxd++;
        if ((j + 1) != nfxd) {
          int b_ix;
          int b_iy;
          b_ix = j * 15;
          b_iy = (nfxd - 1) * 15;
          for (int k{0}; k < b_m; k++) {
            double temp;
            int i1;
            int temp_tmp;
            temp_tmp = b_ix + k;
            temp = (&A[0][0])[temp_tmp];
            i1 = b_iy + k;
            (&A[0][0])[temp_tmp] = (&A[0][0])[i1];
            (&A[0][0])[i1] = temp;
          }
          jpvt[j] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = j + 1;
        } else {
          jpvt[j] = j + 1;
        }
      } else {
        jpvt[j] = j + 1;
      }
    }
    if (nfxd > minmn) {
      nfxd = minmn;
    }
    reflapack::qrf(A, b_m, h_n, nfxd, tau);
    if (nfxd < minmn) {
      int b_minmn;
      int d_i;
      int i2;
      int i3;
      if (b_m <= h_n) {
        b_minmn = b_m;
      } else {
        b_minmn = h_n;
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_i = 0; c_i < 15; c_i++) {
        work[c_i] = 0.0;
        vn1[c_i] = 0.0;
        vn2[c_i] = 0.0;
      }
      d_i = nfxd + 1;
      i2 = nfxd + 1;
      if ((static_cast<int>((h_n - nfxd) < 4)) != 0) {
        for (int c_j{d_i}; c_j <= h_n; c_j++) {
          d = blas::xnrm2(b_m - nfxd, A, (nfxd + ((c_j - 1) * 15)) + 1);
          vn1[c_j - 1] = d;
          vn2[c_j - 1] = d;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

        for (int c_j = i2; c_j <= h_n; c_j++) {
          d = blas::xnrm2(b_m - nfxd, A, (nfxd + ((c_j - 1) * 15)) + 1);
          vn1[c_j - 1] = d;
          vn2[c_j - 1] = d;
        }
      }
      i3 = nfxd + 1;
      for (int e_i{i3}; e_i <= b_minmn; e_i++) {
        double b_d1;
        int b_mmi;
        int c_ii;
        int idxmax;
        int ii_tmp;
        int ip1;
        int nmi;
        int pvt;
        ip1 = e_i + 1;
        ii_tmp = (e_i - 1) * 15;
        c_ii = (ii_tmp + e_i) - 1;
        nmi = (h_n - e_i) + 1;
        b_mmi = b_m - e_i;
        if (nmi < 1) {
          idxmax = -2;
        } else {
          idxmax = -1;
          if (nmi > 1) {
            double smax;
            smax = std::abs(vn1[e_i - 1]);
            for (int b_k{2}; b_k <= nmi; b_k++) {
              double s;
              s = std::abs(vn1[(e_i + b_k) - 2]);
              if (s > smax) {
                idxmax = b_k - 2;
                smax = s;
              }
            }
          }
        }
        pvt = e_i + idxmax;
        if ((pvt + 1) != e_i) {
          int c_ix;
          c_ix = pvt * 15;
          for (int c_k{0}; c_k < b_m; c_k++) {
            double b_temp;
            int b_temp_tmp;
            int i4;
            b_temp_tmp = c_ix + c_k;
            b_temp = (&A[0][0])[b_temp_tmp];
            i4 = ii_tmp + c_k;
            (&A[0][0])[b_temp_tmp] = (&A[0][0])[i4];
            (&A[0][0])[i4] = b_temp;
          }
          int itemp;
          itemp = jpvt[pvt];
          jpvt[pvt] = jpvt[e_i - 1];
          jpvt[e_i - 1] = itemp;
          vn1[pvt] = vn1[e_i - 1];
          vn2[pvt] = vn2[e_i - 1];
        }
        if (e_i < b_m) {
          d_atmp = (&A[0][0])[c_ii];
          b_d1 = reflapack::b_xzlarfg(b_mmi + 1, &d_atmp, A, c_ii + 2);
          tau[e_i - 1] = b_d1;
          (&A[0][0])[c_ii] = d_atmp;
        } else {
          b_d1 = 0.0;
          tau[e_i - 1] = 0.0;
        }
        if (e_i < h_n) {
          double e_atmp;
          e_atmp = (&A[0][0])[c_ii];
          (&A[0][0])[c_ii] = 1.0;
          reflapack::c_xzlarf(b_mmi + 1, nmi - 1, c_ii + 1, b_d1, A, c_ii + 16,
                              work);
          (&A[0][0])[c_ii] = e_atmp;
        }
        for (int d_j{ip1}; d_j <= h_n; d_j++) {
          double d2;
          int ij;
          ij = e_i + ((d_j - 1) * 15);
          d2 = vn1[d_j - 1];
          if (d2 != 0.0) {
            double temp1;
            double temp2;
            temp1 = std::abs((&A[0][0])[ij - 1]) / d2;
            temp1 = 1.0 - (temp1 * temp1);
            if (temp1 < 0.0) {
              temp1 = 0.0;
            }
            temp2 = d2 / vn2[d_j - 1];
            temp2 = temp1 * (temp2 * temp2);
            if (temp2 <= 1.4901161193847656E-8) {
              if (e_i < b_m) {
                double d3;
                d3 = blas::xnrm2(b_mmi, A, ij + 1);
                vn1[d_j - 1] = d3;
                vn2[d_j - 1] = d3;
              } else {
                vn1[d_j - 1] = 0.0;
                vn2[d_j - 1] = 0.0;
              }
            } else {
              vn1[d_j - 1] = d2 * std::sqrt(temp1);
            }
          }
        }
      }
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
  double d;
  double d_atmp;
  int b_m;
  int b_u0;
  int b_u1;
  int c_u1;
  int h_n;
  int loop_ub;
  int minmana;
  int minmn;
  int u0;
  int unnamed_idx_1;
  bool guard1{false};
  b_m = A.size(0);
  h_n = A.size(1);
  u0 = A.size(0);
  b_u1 = A.size(1);
  if (u0 <= b_u1) {
    minmana = u0;
  } else {
    minmana = b_u1;
  }
  b_u0 = A.size(0);
  c_u1 = A.size(1);
  if (b_u0 <= c_u1) {
    minmn = b_u0;
  } else {
    minmn = c_u1;
  }
  tau.set_size(minmana);
  loop_ub = minmana;
  if ((static_cast<int>(minmana < 4)) != 0) {
    for (int b_i{0}; b_i < minmana; b_i++) {
      tau[b_i] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      tau[b_i] = 0.0;
    }
  }
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else if (minmn < 1) {
    guard1 = true;
  } else {
    int b_loop_ub;
    int b_minmn;
    int c_u0;
    int d_loop_ub;
    int d_u1;
    int e_A;
    int e_loop_ub;
    int f_loop_ub;
    int g_loop_ub;
    int ma;
    unnamed_idx_1 = A.size(1);
    jpvt.set_size(1, unnamed_idx_1);
    b_loop_ub = unnamed_idx_1;
    if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
      for (int i1{0}; i1 < unnamed_idx_1; i1++) {
        jpvt[i1] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        jpvt[i1] = 0;
      }
    }
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int k{0}; k < h_n; k++) {
        jpvt[k] = k + 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < h_n; k++) {
        jpvt[k] = k + 1;
      }
    }
    tau.set_size(minmana);
    d_loop_ub = minmana;
    if ((static_cast<int>(minmana < 4)) != 0) {
      for (int i3{0}; i3 < minmana; i3++) {
        tau[i3] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < d_loop_ub; i3++) {
        tau[i3] = 0.0;
      }
    }
    ma = A.size(0);
    c_u0 = A.size(0);
    d_u1 = A.size(1);
    if (c_u0 <= d_u1) {
      b_minmn = c_u0;
    } else {
      b_minmn = d_u1;
    }
    e_A = A.size(1);
    work.set_size(e_A);
    e_loop_ub = e_A;
    if ((static_cast<int>(e_A < 4)) != 0) {
      for (int i4{0}; i4 < e_A; i4++) {
        work[i4] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < e_loop_ub; i4++) {
        work[i4] = 0.0;
      }
    }
    e_A = A.size(1);
    vn1.set_size(e_A);
    f_loop_ub = e_A;
    if ((static_cast<int>(e_A < 4)) != 0) {
      for (int i5{0}; i5 < e_A; i5++) {
        vn1[i5] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < f_loop_ub; i5++) {
        vn1[i5] = 0.0;
      }
    }
    e_A = A.size(1);
    vn2.set_size(e_A);
    g_loop_ub = e_A;
    if ((static_cast<int>(e_A < 4)) != 0) {
      for (int i6{0}; i6 < e_A; i6++) {
        vn2[i6] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < g_loop_ub; i6++) {
        vn2[i6] = 0.0;
      }
    }
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int b_j{0}; b_j < h_n; b_j++) {
        d = blas::b_xnrm2(b_m, A, (b_j * ma) + 1);
        vn1[b_j] = d;
        vn2[b_j] = d;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

      for (int b_j = 0; b_j < h_n; b_j++) {
        d = blas::b_xnrm2(b_m, A, (b_j * ma) + 1);
        vn1[b_j] = d;
        vn2[b_j] = d;
      }
    }
    for (int c_i{0}; c_i < b_minmn; c_i++) {
      double b_d1;
      int b_mmi;
      int c_ii;
      int idxmax;
      int ii_tmp;
      int ip1;
      int nmi;
      int pvt;
      ip1 = c_i + 2;
      ii_tmp = c_i * ma;
      c_ii = ii_tmp + c_i;
      nmi = h_n - c_i;
      b_mmi = b_m - c_i;
      if (nmi < 1) {
        idxmax = -1;
      } else {
        idxmax = 0;
        if (nmi > 1) {
          double smax;
          smax = std::abs(vn1[c_i]);
          for (int b_k{2}; b_k <= nmi; b_k++) {
            double s;
            s = std::abs(vn1[(c_i + b_k) - 1]);
            if (s > smax) {
              idxmax = b_k - 1;
              smax = s;
            }
          }
        }
      }
      pvt = c_i + idxmax;
      if ((pvt + 1) != (c_i + 1)) {
        int b_ix;
        b_ix = pvt * ma;
        for (int c_k{0}; c_k < b_m; c_k++) {
          double temp;
          int i7;
          int temp_tmp;
          temp_tmp = b_ix + c_k;
          temp = A[temp_tmp];
          i7 = ii_tmp + c_k;
          A[temp_tmp] = A[i7];
          A[i7] = temp;
        }
        int itemp;
        itemp = jpvt[pvt];
        jpvt[pvt] = jpvt[c_i];
        jpvt[c_i] = itemp;
        vn1[pvt] = vn1[c_i];
        vn2[pvt] = vn2[c_i];
      }
      if ((c_i + 1) < b_m) {
        d_atmp = A[c_ii];
        b_d1 = reflapack::xzlarfg(b_mmi, &d_atmp, A, c_ii + 2);
        tau[c_i] = b_d1;
        A[c_ii] = d_atmp;
      } else {
        b_d1 = 0.0;
        tau[c_i] = 0.0;
      }
      if ((c_i + 1) < h_n) {
        double e_atmp;
        e_atmp = A[c_ii];
        A[c_ii] = 1.0;
        reflapack::xzlarf(b_mmi, nmi - 1, c_ii + 1, b_d1, A, (c_ii + ma) + 1,
                          ma, work);
        A[c_ii] = e_atmp;
      }
      for (int c_j{ip1}; c_j <= h_n; c_j++) {
        double d2;
        int ij;
        ij = c_i + ((c_j - 1) * ma);
        d2 = vn1[c_j - 1];
        if (d2 != 0.0) {
          double temp1;
          double temp2;
          temp1 = std::abs(A[ij]) / d2;
          temp1 = 1.0 - (temp1 * temp1);
          if (temp1 < 0.0) {
            temp1 = 0.0;
          }
          temp2 = d2 / vn2[c_j - 1];
          temp2 = temp1 * (temp2 * temp2);
          if (temp2 <= 1.4901161193847656E-8) {
            if ((c_i + 1) < b_m) {
              double d3;
              d3 = blas::b_xnrm2(b_mmi - 1, A, ij + 2);
              vn1[c_j - 1] = d3;
              vn2[c_j - 1] = d3;
            } else {
              vn1[c_j - 1] = 0.0;
              vn2[c_j - 1] = 0.0;
            }
          } else {
            vn1[c_j - 1] = d2 * std::sqrt(temp1);
          }
        }
      }
    }
  }
  if (guard1) {
    int c_loop_ub;
    unnamed_idx_1 = A.size(1);
    jpvt.set_size(1, unnamed_idx_1);
    c_loop_ub = unnamed_idx_1;
    if ((static_cast<int>(unnamed_idx_1 < 4)) != 0) {
      for (int i2{0}; i2 < unnamed_idx_1; i2++) {
        jpvt[i2] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < c_loop_ub; i2++) {
        jpvt[i2] = 0;
      }
    }
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int j{0}; j < h_n; j++) {
        jpvt[j] = j + 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int j = 0; j < h_n; j++) {
        jpvt[j] = j + 1;
      }
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
