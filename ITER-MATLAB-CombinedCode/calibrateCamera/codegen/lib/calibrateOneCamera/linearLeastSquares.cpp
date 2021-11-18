//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearLeastSquares.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
//                int g_n
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void linearLeastSquares(::coder::array<double, 2U> &lhs,
                        ::coder::array<double, 1U> &rhs,
                        ::coder::array<double, 1U> &b_dx, int m, int g_n)
{
  ::coder::array<double, 1U> tau;
  ::coder::array<double, 1U> vn1;
  ::coder::array<double, 1U> vn2;
  ::coder::array<double, 1U> work;
  ::coder::array<unsigned int, 1U> jpvt;
  double temp;
  int b_i;
  int c_i;
  int ij;
  int ix;
  int ma;
  int minmana;
  int minmn_tmp;
  int nmi;
  bool guard1{false};
  jpvt.set_size(g_n);
  for (b_i = 0; b_i < g_n; b_i++) {
    jpvt[b_i] = 0U;
  }
  ma = lhs.size(0);
  ij = lhs.size(0);
  minmana = lhs.size(1);
  if (ij <= minmana) {
    minmana = ij;
  }
  if (m <= g_n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = g_n;
  }
  tau.set_size(minmana);
  for (b_i = 0; b_i < minmana; b_i++) {
    tau[b_i] = 0.0;
  }
  guard1 = false;
  if ((lhs.size(0) == 0) || (lhs.size(1) == 0)) {
    guard1 = true;
  } else if (minmn_tmp < 1) {
    guard1 = true;
  } else {
    double d;
    int b_ii;
    int k;
    int mmi;
    int nfxd;
    int temp_tmp;
    nfxd = 0;
    for (nmi = 0; nmi < g_n; nmi++) {
      if ((static_cast<int>(jpvt[nmi])) != 0) {
        nfxd++;
        if ((nmi + 1) != nfxd) {
          ix = nmi * ma;
          minmana = (nfxd - 1) * ma;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = lhs[temp_tmp];
            b_i = minmana + k;
            lhs[temp_tmp] = lhs[b_i];
            lhs[b_i] = temp;
          }
          jpvt[nmi] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = static_cast<unsigned int>(static_cast<int>(nmi + 1));
        } else {
          jpvt[nmi] = static_cast<unsigned int>(static_cast<int>(nmi + 1));
        }
      } else {
        jpvt[nmi] = static_cast<unsigned int>(static_cast<int>(nmi + 1));
      }
    }
    if (nfxd > minmn_tmp) {
      nfxd = minmn_tmp;
    }
    minmana = lhs.size(0);
    ij = lhs.size(1);
    work.set_size(ij);
    for (b_i = 0; b_i < ij; b_i++) {
      work[b_i] = 0.0;
    }
    for (c_i = 0; c_i < nfxd; c_i++) {
      b_ii = (c_i * minmana) + c_i;
      mmi = m - c_i;
      if ((c_i + 1) < m) {
        temp = lhs[b_ii];
        d = internal::reflapack::xzlarfg(mmi, &temp, lhs, b_ii + 2);
        tau[c_i] = d;
        lhs[b_ii] = temp;
      } else {
        d = 0.0;
        tau[c_i] = 0.0;
      }
      if ((c_i + 1) < g_n) {
        temp = lhs[b_ii];
        lhs[b_ii] = 1.0;
        internal::reflapack::xzlarf(mmi, (g_n - c_i) - 1, b_ii + 1, d, lhs,
                                    (b_ii + minmana) + 1, minmana, work);
        lhs[b_ii] = temp;
      }
    }
    if (nfxd < minmn_tmp) {
      ma = lhs.size(0);
      ij = lhs.size(1);
      work.set_size(ij);
      for (b_i = 0; b_i < ij; b_i++) {
        work[b_i] = 0.0;
      }
      ij = lhs.size(1);
      vn1.set_size(ij);
      for (b_i = 0; b_i < ij; b_i++) {
        vn1[b_i] = 0.0;
      }
      ij = lhs.size(1);
      vn2.set_size(ij);
      for (b_i = 0; b_i < ij; b_i++) {
        vn2[b_i] = 0.0;
      }
      b_i = nfxd + 1;
      for (nmi = b_i; nmi <= g_n; nmi++) {
        d = internal::blas::xnrm2(m - nfxd, lhs, (nfxd + ((nmi - 1) * ma)) + 1);
        vn1[nmi - 1] = d;
        vn2[nmi - 1] = d;
      }
      for (c_i = b_i; c_i <= minmn_tmp; c_i++) {
        double s;
        int ip1;
        ip1 = c_i + 1;
        ij = (c_i - 1) * ma;
        b_ii = (ij + c_i) - 1;
        nmi = (g_n - c_i) + 1;
        mmi = m - c_i;
        if (nmi < 1) {
          minmana = -2;
        } else {
          minmana = -1;
          if (nmi > 1) {
            temp = std::abs(vn1[c_i - 1]);
            for (k = 2; k <= nmi; k++) {
              s = std::abs(vn1[(c_i + k) - 2]);
              if (s > temp) {
                minmana = k - 2;
                temp = s;
              }
            }
          }
        }
        nfxd = c_i + minmana;
        if ((nfxd + 1) != c_i) {
          ix = nfxd * ma;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = lhs[temp_tmp];
            minmana = ij + k;
            lhs[temp_tmp] = lhs[minmana];
            lhs[minmana] = temp;
          }
          minmana = static_cast<int>(jpvt[nfxd]);
          jpvt[nfxd] = jpvt[c_i - 1];
          jpvt[c_i - 1] = static_cast<unsigned int>(minmana);
          vn1[nfxd] = vn1[c_i - 1];
          vn2[nfxd] = vn2[c_i - 1];
        }
        if (c_i < m) {
          temp = lhs[b_ii];
          d = internal::reflapack::xzlarfg(mmi + 1, &temp, lhs, b_ii + 2);
          tau[c_i - 1] = d;
          lhs[b_ii] = temp;
        } else {
          d = 0.0;
          tau[c_i - 1] = 0.0;
        }
        if (c_i < g_n) {
          temp = lhs[b_ii];
          lhs[b_ii] = 1.0;
          internal::reflapack::xzlarf(mmi + 1, nmi - 1, b_ii + 1, d, lhs,
                                      (b_ii + ma) + 1, ma, work);
          lhs[b_ii] = temp;
        }
        for (nmi = ip1; nmi <= g_n; nmi++) {
          ij = c_i + ((nmi - 1) * ma);
          d = vn1[nmi - 1];
          if (d != 0.0) {
            temp = std::abs(lhs[ij - 1]) / d;
            temp = 1.0 - (temp * temp);
            if (temp < 0.0) {
              temp = 0.0;
            }
            s = d / vn2[nmi - 1];
            s = temp * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if (c_i < m) {
                d = internal::blas::xnrm2(mmi, lhs, ij + 1);
                vn1[nmi - 1] = d;
                vn2[nmi - 1] = d;
              } else {
                vn1[nmi - 1] = 0.0;
                vn2[nmi - 1] = 0.0;
              }
            } else {
              vn1[nmi - 1] = d * std::sqrt(temp);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    for (nmi = 0; nmi < g_n; nmi++) {
      jpvt[nmi] = static_cast<unsigned int>(static_cast<int>(nmi + 1));
    }
  }
  internal::lapack::xunormqr(lhs, rhs, tau);
  if (1 > g_n) {
    ij = 0;
  } else {
    ij = g_n;
  }
  b_dx.set_size(ij);
  for (b_i = 0; b_i < ij; b_i++) {
    b_dx[b_i] = rhs[b_i];
  }
  if ((lhs.size(0) != 0) && (lhs.size(1) != 0)) {
    if ((ij != 0) && (g_n != 0)) {
      for (nmi = g_n; nmi >= 1; nmi--) {
        ij = (nmi + ((nmi - 1) * m)) - 1;
        b_dx[nmi - 1] = b_dx[nmi - 1] / lhs[ij];
        for (c_i = 0; c_i <= (nmi - 2); c_i++) {
          ix = (nmi - c_i) - 2;
          b_dx[ix] = b_dx[ix] - (b_dx[nmi - 1] * lhs[(ij - c_i) - 1]);
        }
      }
    }
  }
  tau.set_size(b_dx.size(0));
  ij = b_dx.size(0);
  for (b_i = 0; b_i < ij; b_i++) {
    tau[b_i] = b_dx[b_i];
  }
  ij = tau.size(0);
  for (b_i = 0; b_i < ij; b_i++) {
    b_dx[(static_cast<int>(jpvt[b_i])) - 1] = tau[b_i];
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

//
// File trailer for linearLeastSquares.cpp
//
// [EOF]
//
