//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearLeastSquares.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "linearLeastSquares.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xunormqr.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &lhs
//                ::coder::array<double, 1U> &rhs
//                ::coder::array<double, 1U> &b_dx
//                int m
//                int h_n
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void linearLeastSquares(::coder::array<double, 2U> &lhs,
                        ::coder::array<double, 1U> &rhs,
                        ::coder::array<double, 1U> &b_dx, int m, int h_n)
{
  array<double, 1U> c_dx;
  array<double, 1U> tau;
  array<double, 1U> vn1;
  array<double, 1U> vn2;
  array<double, 1U> work;
  array<unsigned int, 1U> jpvt;
  double b_atmp;
  double d_atmp;
  int b_loop_ub;
  int c_loop_ub;
  int c_u1;
  int loop_ub;
  int ma;
  int minmana;
  int minmn_tmp;
  int u0;
  bool guard1{false};
  jpvt.set_size(h_n);
  for (int b_i{0}; b_i < h_n; b_i++) {
    jpvt[b_i] = 0U;
  }
  ma = lhs.size(0);
  u0 = lhs.size(0);
  c_u1 = lhs.size(1);
  if (u0 <= c_u1) {
    minmana = u0;
  } else {
    minmana = c_u1;
  }
  if (m <= h_n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = h_n;
  }
  tau.set_size(minmana);
  for (int i1{0}; i1 < minmana; i1++) {
    tau[i1] = 0.0;
  }
  guard1 = false;
  if ((lhs.size(0) == 0) || (lhs.size(1) == 0)) {
    guard1 = true;
  } else if (minmn_tmp < 1) {
    guard1 = true;
  } else {
    int b_lhs;
    int c_lda;
    int nfxd;
    nfxd = 0;
    for (int j{0}; j < h_n; j++) {
      if ((static_cast<int>(jpvt[j])) != 0) {
        nfxd++;
        if ((j + 1) != nfxd) {
          int b_ix;
          int c_iy;
          b_ix = j * ma;
          c_iy = (nfxd - 1) * ma;
          for (int k{0}; k < m; k++) {
            double temp;
            int i5;
            int temp_tmp;
            temp_tmp = b_ix + k;
            temp = lhs[temp_tmp];
            i5 = c_iy + k;
            lhs[temp_tmp] = lhs[i5];
            lhs[i5] = temp;
          }
          jpvt[j] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = static_cast<unsigned int>(static_cast<int>(j + 1));
        } else {
          jpvt[j] = static_cast<unsigned int>(static_cast<int>(j + 1));
        }
      } else {
        jpvt[j] = static_cast<unsigned int>(static_cast<int>(j + 1));
      }
    }
    if (nfxd > minmn_tmp) {
      nfxd = minmn_tmp;
    }
    tau.set_size(minmana);
    for (int i2{0}; i2 < minmana; i2++) {
      tau[i2] = 0.0;
    }
    c_lda = lhs.size(0);
    b_lhs = lhs.size(1);
    work.set_size(b_lhs);
    for (int i4{0}; i4 < b_lhs; i4++) {
      work[i4] = 0.0;
    }
    for (int c_i{0}; c_i < nfxd; c_i++) {
      double d;
      int b_mmi;
      int c_ii;
      c_ii = (c_i * c_lda) + c_i;
      b_mmi = m - c_i;
      if ((c_i + 1) < m) {
        b_atmp = lhs[c_ii];
        d = internal::reflapack::xzlarfg(b_mmi, &b_atmp, lhs, c_ii + 2);
        tau[c_i] = d;
        lhs[c_ii] = b_atmp;
      } else {
        d = 0.0;
        tau[c_i] = 0.0;
      }
      if ((c_i + 1) < h_n) {
        double c_atmp;
        c_atmp = lhs[c_ii];
        lhs[c_ii] = 1.0;
        internal::reflapack::xzlarf(b_mmi, (h_n - c_i) - 1, c_ii + 1, d, lhs,
                                    (c_ii + c_lda) + 1, c_lda, work);
        lhs[c_ii] = c_atmp;
      }
    }
    if (nfxd < minmn_tmp) {
      int b_ma;
      int i11;
      b_ma = lhs.size(0);
      b_lhs = lhs.size(1);
      work.set_size(b_lhs);
      for (int i8{0}; i8 < b_lhs; i8++) {
        work[i8] = 0.0;
      }
      b_lhs = lhs.size(1);
      vn1.set_size(b_lhs);
      for (int i9{0}; i9 < b_lhs; i9++) {
        vn1[i9] = 0.0;
      }
      b_lhs = lhs.size(1);
      vn2.set_size(b_lhs);
      for (int i10{0}; i10 < b_lhs; i10++) {
        vn2[i10] = 0.0;
      }
      i11 = nfxd + 1;
      for (int d_j{i11}; d_j <= h_n; d_j++) {
        double b_d1;
        b_d1 = internal::blas::xnrm2(m - nfxd, lhs,
                                     (nfxd + ((d_j - 1) * b_ma)) + 1);
        vn1[d_j - 1] = b_d1;
        vn2[d_j - 1] = b_d1;
      }
      for (int g_i{i11}; g_i <= minmn_tmp; g_i++) {
        double d2;
        int c_mmi;
        int e_ii;
        int idxmax;
        int ii_tmp;
        int ip1;
        int nmi;
        int pvt;
        ip1 = g_i + 1;
        ii_tmp = (g_i - 1) * b_ma;
        e_ii = (ii_tmp + g_i) - 1;
        nmi = (h_n - g_i) + 1;
        c_mmi = m - g_i;
        if (nmi < 1) {
          idxmax = -2;
        } else {
          idxmax = -1;
          if (nmi > 1) {
            double smax;
            smax = std::abs(vn1[g_i - 1]);
            for (int b_k{2}; b_k <= nmi; b_k++) {
              double s;
              s = std::abs(vn1[(g_i + b_k) - 2]);
              if (s > smax) {
                idxmax = b_k - 2;
                smax = s;
              }
            }
          }
        }
        pvt = g_i + idxmax;
        if ((pvt + 1) != g_i) {
          int d_ix;
          d_ix = pvt * b_ma;
          for (int c_k{0}; c_k < m; c_k++) {
            double b_temp;
            int b_temp_tmp;
            int i12;
            b_temp_tmp = d_ix + c_k;
            b_temp = lhs[b_temp_tmp];
            i12 = ii_tmp + c_k;
            lhs[b_temp_tmp] = lhs[i12];
            lhs[i12] = b_temp;
          }
          int itemp;
          itemp = static_cast<int>(jpvt[pvt]);
          jpvt[pvt] = jpvt[g_i - 1];
          jpvt[g_i - 1] = static_cast<unsigned int>(itemp);
          vn1[pvt] = vn1[g_i - 1];
          vn2[pvt] = vn2[g_i - 1];
        }
        if (g_i < m) {
          d_atmp = lhs[e_ii];
          d2 = internal::reflapack::xzlarfg(c_mmi + 1, &d_atmp, lhs, e_ii + 2);
          tau[g_i - 1] = d2;
          lhs[e_ii] = d_atmp;
        } else {
          d2 = 0.0;
          tau[g_i - 1] = 0.0;
        }
        if (g_i < h_n) {
          double e_atmp;
          e_atmp = lhs[e_ii];
          lhs[e_ii] = 1.0;
          internal::reflapack::xzlarf(c_mmi + 1, nmi - 1, e_ii + 1, d2, lhs,
                                      (e_ii + b_ma) + 1, b_ma, work);
          lhs[e_ii] = e_atmp;
        }
        for (int e_j{ip1}; e_j <= h_n; e_j++) {
          double d3;
          int c_ij;
          c_ij = g_i + ((e_j - 1) * b_ma);
          d3 = vn1[e_j - 1];
          if (d3 != 0.0) {
            double temp1;
            double temp2;
            temp1 = std::abs(lhs[c_ij - 1]) / d3;
            temp1 = 1.0 - (temp1 * temp1);
            if (temp1 < 0.0) {
              temp1 = 0.0;
            }
            temp2 = d3 / vn2[e_j - 1];
            temp2 = temp1 * (temp2 * temp2);
            if (temp2 <= 1.4901161193847656E-8) {
              if (g_i < m) {
                double d4;
                d4 = internal::blas::xnrm2(c_mmi, lhs, c_ij + 1);
                vn1[e_j - 1] = d4;
                vn2[e_j - 1] = d4;
              } else {
                vn1[e_j - 1] = 0.0;
                vn2[e_j - 1] = 0.0;
              }
            } else {
              vn1[e_j - 1] = d3 * std::sqrt(temp1);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    for (int b_j{0}; b_j < h_n; b_j++) {
      jpvt[b_j] = static_cast<unsigned int>(static_cast<int>(b_j + 1));
    }
  }
  internal::lapack::xunormqr(lhs, rhs, tau);
  if (1 > h_n) {
    loop_ub = 0;
  } else {
    loop_ub = h_n;
  }
  b_dx.set_size(loop_ub);
  for (int i3{0}; i3 < loop_ub; i3++) {
    b_dx[i3] = rhs[i3];
  }
  if ((lhs.size(0) != 0) && (lhs.size(1) != 0)) {
    if ((loop_ub != 0) && (h_n != 0)) {
      for (int c_j{h_n}; c_j >= 1; c_j--) {
        int jjA;
        jjA = (c_j + ((c_j - 1) * m)) - 1;
        b_dx[c_j - 1] = b_dx[c_j - 1] / lhs[jjA];
        for (int e_i{0}; e_i <= (c_j - 2); e_i++) {
          int c_ix;
          c_ix = (c_j - e_i) - 2;
          b_dx[c_ix] = b_dx[c_ix] - (b_dx[c_j - 1] * lhs[(jjA - e_i) - 1]);
        }
      }
    }
  }
  c_dx.set_size(b_dx.size(0));
  b_loop_ub = b_dx.size(0);
  for (int i6{0}; i6 < b_loop_ub; i6++) {
    c_dx[i6] = b_dx[i6];
  }
  c_loop_ub = c_dx.size(0);
  for (int i7{0}; i7 < c_loop_ub; i7++) {
    b_dx[(static_cast<int>(jpvt[i7])) - 1] = c_dx[i7];
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for linearLeastSquares.cpp
//
// [EOF]
//
