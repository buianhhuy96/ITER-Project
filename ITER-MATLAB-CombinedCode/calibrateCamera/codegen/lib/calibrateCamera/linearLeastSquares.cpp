//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linearLeastSquares.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "linearLeastSquares.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xunormqr.h"
#include "xzgeqp3.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &lhs
//                ::coder::array<real_T, 1U> &rhs
//                ::coder::array<real_T, 1U> &b_dx
//                int32_T m
//                int32_T g_n
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
void linearLeastSquares(::coder::array<real_T, 2U> &lhs,
                        ::coder::array<real_T, 1U> &rhs,
                        ::coder::array<real_T, 1U> &b_dx, int32_T m,
                        int32_T g_n)
{
  ::coder::array<real_T, 1U> tau;
  ::coder::array<real_T, 1U> vn1;
  ::coder::array<real_T, 1U> vn2;
  ::coder::array<real_T, 1U> work;
  ::coder::array<int32_T, 1U> jpvt;
  real_T temp;
  int32_T b_i;
  int32_T b_ii;
  int32_T d_i;
  int32_T ij;
  int32_T ix;
  int32_T ma;
  int32_T minmana;
  int32_T minmn_tmp;
  jpvt.set_size(g_n);
  for (b_i = 0; b_i < g_n; b_i++) {
    jpvt[b_i] = 0;
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
  if ((lhs.size(0) == 0) || (lhs.size(1) == 0)) {
    for (b_ii = 0; b_ii < g_n; b_ii++) {
      jpvt[b_ii] = b_ii + 1;
    }
  } else {
    int32_T k;
    int32_T nfxd;
    int32_T temp_tmp;
    nfxd = 0;
    for (b_ii = 0; b_ii < g_n; b_ii++) {
      if (jpvt[b_ii] != 0) {
        nfxd++;
        if ((b_ii + 1) != nfxd) {
          ix = b_ii * ma;
          minmana = (nfxd - 1) * ma;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = lhs[temp_tmp];
            b_i = minmana + k;
            lhs[temp_tmp] = lhs[b_i];
            lhs[b_i] = temp;
          }
          jpvt[b_ii] = jpvt[nfxd - 1];
          jpvt[nfxd - 1] = b_ii + 1;
        } else {
          jpvt[b_ii] = b_ii + 1;
        }
      } else {
        jpvt[b_ii] = b_ii + 1;
      }
    }
    if (nfxd > minmn_tmp) {
      nfxd = minmn_tmp;
    }
    internal::reflapack::qrf(lhs, m, g_n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      real_T d;
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
      for (b_ii = b_i; b_ii <= g_n; b_ii++) {
        d = internal::blas::xnrm2(m - nfxd, lhs,
                                  (nfxd + ((b_ii - 1) * ma)) + 1);
        vn1[b_ii - 1] = d;
        vn2[b_ii - 1] = d;
      }
      for (d_i = b_i; d_i <= minmn_tmp; d_i++) {
        real_T s;
        int32_T ip1;
        int32_T mmi;
        int32_T nmi;
        ip1 = d_i + 1;
        ij = (d_i - 1) * ma;
        b_ii = (ij + d_i) - 1;
        nmi = (g_n - d_i) + 1;
        mmi = m - d_i;
        if (nmi < 1) {
          minmana = -2;
        } else {
          minmana = -1;
          if (nmi > 1) {
            temp = std::abs(vn1[d_i - 1]);
            for (k = 2; k <= nmi; k++) {
              s = std::abs(vn1[(d_i + k) - 2]);
              if (s > temp) {
                minmana = k - 2;
                temp = s;
              }
            }
          }
        }
        nfxd = d_i + minmana;
        if ((nfxd + 1) != d_i) {
          ix = nfxd * ma;
          for (k = 0; k < m; k++) {
            temp_tmp = ix + k;
            temp = lhs[temp_tmp];
            minmana = ij + k;
            lhs[temp_tmp] = lhs[minmana];
            lhs[minmana] = temp;
          }
          minmana = jpvt[nfxd];
          jpvt[nfxd] = jpvt[d_i - 1];
          jpvt[d_i - 1] = minmana;
          vn1[nfxd] = vn1[d_i - 1];
          vn2[nfxd] = vn2[d_i - 1];
        }
        if (d_i < m) {
          temp = lhs[b_ii];
          d = internal::reflapack::xzlarfg(mmi + 1, &temp, lhs, b_ii + 2);
          tau[d_i - 1] = d;
          lhs[b_ii] = temp;
        } else {
          d = 0.0;
          tau[d_i - 1] = 0.0;
        }
        if (d_i < g_n) {
          temp = lhs[b_ii];
          lhs[b_ii] = 1.0;
          internal::reflapack::xzlarf(mmi + 1, nmi - 1, b_ii + 1, d, lhs,
                                      (b_ii + ma) + 1, ma, work);
          lhs[b_ii] = temp;
        }
        for (b_ii = ip1; b_ii <= g_n; b_ii++) {
          ij = d_i + ((b_ii - 1) * ma);
          d = vn1[b_ii - 1];
          if (d != 0.0) {
            temp = std::abs(lhs[ij - 1]) / d;
            temp = 1.0 - (temp * temp);
            if (temp < 0.0) {
              temp = 0.0;
            }
            s = d / vn2[b_ii - 1];
            s = temp * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if (d_i < m) {
                d = internal::blas::xnrm2(mmi, lhs, ij + 1);
                vn1[b_ii - 1] = d;
                vn2[b_ii - 1] = d;
              } else {
                vn1[b_ii - 1] = 0.0;
                vn2[b_ii - 1] = 0.0;
              }
            } else {
              vn1[b_ii - 1] = d * std::sqrt(temp);
            }
          }
        }
      }
    }
  }
  internal::lapack::xunormqr(lhs, rhs, tau);
  b_dx.set_size(g_n);
  for (b_i = 0; b_i < g_n; b_i++) {
    b_dx[b_i] = rhs[b_i];
  }
  if ((lhs.size(0) != 0) && (lhs.size(1) != 0)) {
    for (b_ii = g_n; b_ii >= 1; b_ii--) {
      ij = (b_ii + ((b_ii - 1) * m)) - 1;
      b_dx[b_ii - 1] = b_dx[b_ii - 1] / lhs[ij];
      for (d_i = 0; d_i <= (b_ii - 2); d_i++) {
        ix = (b_ii - d_i) - 2;
        b_dx[ix] = b_dx[ix] - (b_dx[b_ii - 1] * lhs[(ij - d_i) - 1]);
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
    b_dx[jpvt[b_i] - 1] = tau[b_i];
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
