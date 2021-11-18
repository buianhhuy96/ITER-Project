//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xgeqp3.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &A
//                ::coder::array<real_T, 1U> &tau
//                ::coder::array<int32_T, 2U> &jpvt
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(::coder::array<real_T, 2U> &A, ::coder::array<real_T, 1U> &tau,
            ::coder::array<int32_T, 2U> &jpvt)
{
  ::coder::array<real_T, 1U> vn1;
  ::coder::array<real_T, 1U> vn2;
  ::coder::array<real_T, 1U> work;
  real_T smax;
  int32_T b_i;
  int32_T g_n;
  int32_T ij;
  int32_T m;
  int32_T minmana;
  boolean_T guard1{false};
  m = A.size(0);
  g_n = A.size(1);
  ij = A.size(0);
  minmana = A.size(1);
  if (ij <= minmana) {
    minmana = ij;
  }
  tau.set_size(minmana);
  for (b_i = 0; b_i < minmana; b_i++) {
    tau[b_i] = 0.0;
  }
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else {
    ij = A.size(0);
    minmana = A.size(1);
    if (ij <= minmana) {
      minmana = ij;
    }
    if (minmana < 1) {
      guard1 = true;
    } else {
      real_T d;
      int32_T k;
      int32_T ma;
      int32_T minmn;
      minmana = A.size(1);
      jpvt.set_size(1, minmana);
      for (b_i = 0; b_i < minmana; b_i++) {
        jpvt[b_i] = 0;
      }
      for (k = 0; k < g_n; k++) {
        jpvt[k] = k + 1;
      }
      ma = A.size(0);
      ij = A.size(0);
      minmn = A.size(1);
      if (ij <= minmn) {
        minmn = ij;
      }
      minmana = A.size(1);
      work.set_size(minmana);
      for (b_i = 0; b_i < minmana; b_i++) {
        work[b_i] = 0.0;
      }
      minmana = A.size(1);
      vn1.set_size(minmana);
      for (b_i = 0; b_i < minmana; b_i++) {
        vn1[b_i] = 0.0;
      }
      minmana = A.size(1);
      vn2.set_size(minmana);
      for (b_i = 0; b_i < minmana; b_i++) {
        vn2[b_i] = 0.0;
      }
      for (minmana = 0; minmana < g_n; minmana++) {
        d = blas::xnrm2(m, A, (minmana * ma) + 1);
        vn1[minmana] = d;
        vn2[minmana] = d;
      }
      for (int32_T d_i{0}; d_i < minmn; d_i++) {
        real_T s;
        int32_T b_ii;
        int32_T ii_tmp;
        int32_T ip1;
        int32_T mmi;
        int32_T nmi;
        int32_T pvt;
        ip1 = d_i + 2;
        ii_tmp = d_i * ma;
        b_ii = ii_tmp + d_i;
        nmi = g_n - d_i;
        mmi = m - d_i;
        if (nmi < 1) {
          minmana = -1;
        } else {
          minmana = 0;
          if (nmi > 1) {
            smax = std::abs(vn1[d_i]);
            for (k = 2; k <= nmi; k++) {
              s = std::abs(vn1[(d_i + k) - 1]);
              if (s > smax) {
                minmana = k - 1;
                smax = s;
              }
            }
          }
        }
        pvt = d_i + minmana;
        if ((pvt + 1) != (d_i + 1)) {
          minmana = pvt * ma;
          for (k = 0; k < m; k++) {
            ij = minmana + k;
            smax = A[ij];
            b_i = ii_tmp + k;
            A[ij] = A[b_i];
            A[b_i] = smax;
          }
          minmana = jpvt[pvt];
          jpvt[pvt] = jpvt[d_i];
          jpvt[d_i] = minmana;
          vn1[pvt] = vn1[d_i];
          vn2[pvt] = vn2[d_i];
        }
        if ((d_i + 1) < m) {
          smax = A[b_ii];
          d = reflapack::xzlarfg(mmi, &smax, A, b_ii + 2);
          tau[d_i] = d;
          A[b_ii] = smax;
        } else {
          d = 0.0;
          tau[d_i] = 0.0;
        }
        if ((d_i + 1) < g_n) {
          smax = A[b_ii];
          A[b_ii] = 1.0;
          reflapack::xzlarf(mmi, nmi - 1, b_ii + 1, d, A, (b_ii + ma) + 1, ma,
                            work);
          A[b_ii] = smax;
        }
        for (minmana = ip1; minmana <= g_n; minmana++) {
          ij = d_i + ((minmana - 1) * ma);
          d = vn1[minmana - 1];
          if (d != 0.0) {
            smax = std::abs(A[ij]) / d;
            smax = 1.0 - (smax * smax);
            if (smax < 0.0) {
              smax = 0.0;
            }
            s = d / vn2[minmana - 1];
            s = smax * (s * s);
            if (s <= 1.4901161193847656E-8) {
              if ((d_i + 1) < m) {
                d = blas::xnrm2(mmi - 1, A, ij + 2);
                vn1[minmana - 1] = d;
                vn2[minmana - 1] = d;
              } else {
                vn1[minmana - 1] = 0.0;
                vn2[minmana - 1] = 0.0;
              }
            } else {
              vn1[minmana - 1] = d * std::sqrt(smax);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    minmana = A.size(1);
    jpvt.set_size(1, minmana);
    for (b_i = 0; b_i < minmana; b_i++) {
      jpvt[b_i] = 0;
    }
    for (minmana = 0; minmana < g_n; minmana++) {
      jpvt[minmana] = minmana + 1;
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
