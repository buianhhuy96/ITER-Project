//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &c_B
//                ::coder::array<double, 1U> &d_Y
//                int *rankA
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &c_B,
             ::coder::array<double, 1U> &d_Y, int *rankA)
{
  ::coder::array<double, 2U> e_A;
  ::coder::array<double, 1U> tau;
  ::coder::array<double, 1U> vn1;
  ::coder::array<double, 1U> vn2;
  ::coder::array<double, 1U> work;
  ::coder::array<int, 2U> jpvt;
  double smax;
  int b_i;
  int c_i;
  int g_n;
  int k;
  int loop_ub;
  int m;
  int minmana;
  int minmn;
  int pvt;
  int u0;
  e_A.set_size(A.size(0), A.size(1));
  loop_ub = A.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    minmana = A.size(0);
    for (u0 = 0; u0 < minmana; u0++) {
      e_A[u0 + (e_A.size(0) * b_i)] = A[u0 + (A.size(0) * b_i)];
    }
  }
  m = A.size(0);
  g_n = A.size(1);
  u0 = A.size(0);
  minmana = A.size(1);
  if (u0 <= minmana) {
    minmana = u0;
  }
  tau.set_size(minmana);
  for (b_i = 0; b_i < minmana; b_i++) {
    tau[b_i] = 0.0;
  }
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    jpvt.set_size(1, A.size(1));
    loop_ub = A.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      jpvt[b_i] = 0;
    }
    for (u0 = 0; u0 < g_n; u0++) {
      jpvt[u0] = u0 + 1;
    }
  } else {
    double d;
    int ma;
    jpvt.set_size(1, A.size(1));
    loop_ub = A.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      jpvt[b_i] = 0;
    }
    for (k = 0; k < g_n; k++) {
      jpvt[k] = k + 1;
    }
    ma = A.size(0);
    u0 = A.size(0);
    minmn = A.size(1);
    if (u0 <= minmn) {
      minmn = u0;
    }
    work.set_size(A.size(1));
    loop_ub = A.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      work[b_i] = 0.0;
    }
    vn1.set_size(A.size(1));
    loop_ub = A.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      vn1[b_i] = 0.0;
    }
    vn2.set_size(A.size(1));
    loop_ub = A.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      vn2[b_i] = 0.0;
    }
    for (u0 = 0; u0 < g_n; u0++) {
      d = blas::xnrm2(m, A, (u0 * ma) + 1);
      vn1[u0] = d;
      vn2[u0] = d;
    }
    for (c_i = 0; c_i < minmn; c_i++) {
      double s;
      int b_ii;
      int ip1;
      int mmi;
      int nmi;
      ip1 = c_i + 2;
      loop_ub = c_i * ma;
      b_ii = loop_ub + c_i;
      nmi = g_n - c_i;
      mmi = m - c_i;
      if (nmi < 1) {
        minmana = -1;
      } else {
        minmana = 0;
        if (nmi > 1) {
          smax = std::abs(vn1[c_i]);
          for (k = 2; k <= nmi; k++) {
            s = std::abs(vn1[(c_i + k) - 1]);
            if (s > smax) {
              minmana = k - 1;
              smax = s;
            }
          }
        }
      }
      pvt = c_i + minmana;
      if ((pvt + 1) != (c_i + 1)) {
        minmana = pvt * ma;
        for (k = 0; k < m; k++) {
          u0 = minmana + k;
          smax = e_A[u0];
          b_i = loop_ub + k;
          e_A[u0] = e_A[b_i];
          e_A[b_i] = smax;
        }
        minmana = jpvt[pvt];
        jpvt[pvt] = jpvt[c_i];
        jpvt[c_i] = minmana;
        vn1[pvt] = vn1[c_i];
        vn2[pvt] = vn2[c_i];
      }
      if ((c_i + 1) < m) {
        smax = e_A[b_ii];
        d = reflapack::xzlarfg(mmi, &smax, e_A, b_ii + 2);
        tau[c_i] = d;
        e_A[b_ii] = smax;
      } else {
        d = 0.0;
        tau[c_i] = 0.0;
      }
      if ((c_i + 1) < g_n) {
        smax = e_A[b_ii];
        e_A[b_ii] = 1.0;
        reflapack::xzlarf(mmi, nmi - 1, b_ii + 1, d, e_A, (b_ii + ma) + 1, ma,
                          work);
        e_A[b_ii] = smax;
      }
      for (u0 = ip1; u0 <= g_n; u0++) {
        minmana = c_i + ((u0 - 1) * ma);
        d = vn1[u0 - 1];
        if (d != 0.0) {
          smax = std::abs(e_A[minmana]) / d;
          smax = 1.0 - (smax * smax);
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[u0 - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if ((c_i + 1) < m) {
              d = blas::xnrm2(mmi - 1, e_A, minmana + 2);
              vn1[u0 - 1] = d;
              vn2[u0 - 1] = d;
            } else {
              vn1[u0 - 1] = 0.0;
              vn2[u0 - 1] = 0.0;
            }
          } else {
            vn1[u0 - 1] = d * std::sqrt(smax);
          }
        }
      }
    }
  }
  *rankA = 0;
  if (e_A.size(0) < e_A.size(1)) {
    minmn = e_A.size(0);
    minmana = e_A.size(1);
  } else {
    minmn = e_A.size(1);
    minmana = e_A.size(0);
  }
  if (minmn > 0) {
    bool exitg1;
    smax = std::fmin(1.4901161193847656E-8,
                     2.2204460492503131E-15 * (static_cast<double>(minmana))) *
           std::abs(e_A[0]);
    exitg1 = false;
    while ((!exitg1) && ((*rankA) < minmn)) {
      if (!(std::abs(e_A[(*rankA) + (e_A.size(0) * (*rankA))]) <= smax)) {
        (*rankA)++;
      } else {
        exitg1 = true;
      }
    }
  }
  pvt = 0;
  u0 = e_A.size(0);
  minmana = e_A.size(1);
  if (u0 <= minmana) {
    minmana = u0;
  }
  if (minmana > 0) {
    for (k = 0; k < minmana; k++) {
      if (e_A[k + (e_A.size(0) * k)] != 0.0) {
        pvt++;
      }
    }
  }
  d_Y.set_size(e_A.size(1));
  loop_ub = e_A.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_Y[b_i] = 0.0;
  }
  work.set_size(c_B.size(0));
  loop_ub = c_B.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    work[b_i] = c_B[b_i];
  }
  m = e_A.size(0);
  u0 = e_A.size(0);
  minmana = e_A.size(1);
  if (u0 <= minmana) {
    minmana = u0;
  }
  for (u0 = 0; u0 < minmana; u0++) {
    if (tau[u0] != 0.0) {
      smax = work[u0];
      b_i = u0 + 2;
      for (c_i = b_i; c_i <= m; c_i++) {
        smax += e_A[(c_i + (e_A.size(0) * u0)) - 1] * work[c_i - 1];
      }
      smax *= tau[u0];
      if (smax != 0.0) {
        work[u0] = work[u0] - smax;
        for (c_i = b_i; c_i <= m; c_i++) {
          work[c_i - 1] =
              work[c_i - 1] - (e_A[(c_i + (e_A.size(0) * u0)) - 1] * smax);
        }
      }
    }
  }
  for (c_i = 0; c_i < pvt; c_i++) {
    d_Y[jpvt[c_i] - 1] = work[c_i];
  }
  for (u0 = pvt; u0 >= 1; u0--) {
    b_i = jpvt[u0 - 1];
    d_Y[b_i - 1] = d_Y[b_i - 1] / e_A[(u0 + (e_A.size(0) * (u0 - 1))) - 1];
    for (c_i = 0; c_i <= (u0 - 2); c_i++) {
      d_Y[jpvt[c_i] - 1] =
          d_Y[jpvt[c_i] - 1] -
          (d_Y[jpvt[u0 - 1] - 1] * e_A[c_i + (e_A.size(0) * (u0 - 1))]);
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
