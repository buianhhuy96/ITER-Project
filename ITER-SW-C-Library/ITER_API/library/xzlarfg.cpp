//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xzlarfg.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int h_n
//                double *alpha1
//                double b_x[3]
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace internal {
namespace reflapack {
double b_xzlarfg(int h_n, double *alpha1, double b_x[3])
{
  double tau;
  tau = 0.0;
  if (h_n > 0) {
    double b_xnorm;
    b_xnorm = blas::h_xnrm2(h_n - 1, b_x);
    if (b_xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(*alpha1, b_xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        double c_a;
        int knt;
        knt = -1;
        do {
          knt++;
          for (int b_k{2}; b_k <= h_n; b_k++) {
            b_x[b_k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
        beta1 = rt_hypotd_snf(*alpha1, blas::h_xnrm2(h_n - 1, b_x));
        if ((*alpha1) >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - (*alpha1)) / beta1;
        c_a = 1.0 / ((*alpha1) - beta1);
        if ((static_cast<int>((h_n - 1) < 4)) != 0) {
          for (int c_k{2}; c_k <= h_n; c_k++) {
            b_x[c_k - 1] *= c_a;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int c_k = 2; c_k <= h_n; c_k++) {
            b_x[c_k - 1] *= c_a;
          }
        }
        for (int d_k{0}; d_k <= knt; d_k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        double b_a;
        tau = (beta1 - (*alpha1)) / beta1;
        b_a = 1.0 / ((*alpha1) - beta1);
        if ((static_cast<int>((h_n - 1) < 4)) != 0) {
          for (int k{2}; k <= h_n; k++) {
            b_x[k - 1] *= b_a;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int k = 2; k <= h_n; k++) {
            b_x[k - 1] *= b_a;
          }
        }
        *alpha1 = beta1;
      }
    }
  }
  return tau;
}

//
// Arguments    : int h_n
//                double *alpha1
//                double b_x[15][15]
//                int ix0
// Return Type  : double
//
double c_xzlarfg(int h_n, double *alpha1, double b_x[15][15], int ix0)
{
  double tau;
  tau = 0.0;
  if (h_n > 0) {
    double b_xnorm;
    b_xnorm = blas::xnrm2(h_n - 1, b_x, ix0);
    if (b_xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(*alpha1, b_xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        double c_a;
        int b_i;
        int knt;
        knt = -1;
        b_i = (ix0 + h_n) - 2;
        do {
          knt++;
          for (int b_k{ix0}; b_k <= b_i; b_k++) {
            (&b_x[0][0])[b_k - 1] *= 9.9792015476736E+291;
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
        beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(h_n - 1, b_x, ix0));
        if ((*alpha1) >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - (*alpha1)) / beta1;
        c_a = 1.0 / ((*alpha1) - beta1);
        for (int c_k{ix0}; c_k <= b_i; c_k++) {
          (&b_x[0][0])[c_k - 1] *= c_a;
        }
        for (int d_k{0}; d_k <= knt; d_k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        double b_a;
        int i1;
        tau = (beta1 - (*alpha1)) / beta1;
        b_a = 1.0 / ((*alpha1) - beta1);
        i1 = (ix0 + h_n) - 2;
        for (int k{ix0}; k <= i1; k++) {
          (&b_x[0][0])[k - 1] *= b_a;
        }
        *alpha1 = beta1;
      }
    }
  }
  return tau;
}

//
// Arguments    : int h_n
//                double *alpha1
//                ::coder::array<double, 2U> &b_x
//                int ix0
// Return Type  : double
//
double xzlarfg(int h_n, double *alpha1, ::coder::array<double, 2U> &b_x,
               int ix0)
{
  double tau;
  tau = 0.0;
  if (h_n > 0) {
    double b_xnorm;
    b_xnorm = blas::b_xnrm2(h_n - 1, b_x, ix0);
    if (b_xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(*alpha1, b_xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        double c_a;
        int b_i;
        int i2;
        int knt;
        knt = -1;
        b_i = (ix0 + h_n) - 2;
        do {
          knt++;
          for (int b_k{ix0}; b_k <= b_i; b_k++) {
            b_x[b_k - 1] = 9.9792015476736E+291 * b_x[b_k - 1];
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
        beta1 = rt_hypotd_snf(*alpha1, blas::b_xnrm2(h_n - 1, b_x, ix0));
        if ((*alpha1) >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - (*alpha1)) / beta1;
        c_a = 1.0 / ((*alpha1) - beta1);
        i2 = b_i;
        if ((static_cast<int>(((b_i - ix0) + 1) < 4)) != 0) {
          for (int c_k{ix0}; c_k <= b_i; c_k++) {
            b_x[c_k - 1] = c_a * b_x[c_k - 1];
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int c_k = ix0; c_k <= i2; c_k++) {
            b_x[c_k - 1] = c_a * b_x[c_k - 1];
          }
        }
        for (int d_k{0}; d_k <= knt; d_k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        double b_a;
        int i1;
        tau = (beta1 - (*alpha1)) / beta1;
        b_a = 1.0 / ((*alpha1) - beta1);
        i1 = (ix0 + h_n) - 2;
        if ((static_cast<int>(((i1 - ix0) + 1) < 4)) != 0) {
          for (int k{ix0}; k <= i1; k++) {
            b_x[k - 1] = b_a * b_x[k - 1];
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int k = ix0; k <= i1; k++) {
            b_x[k - 1] = b_a * b_x[k - 1];
          }
        }
        *alpha1 = beta1;
      }
    }
  }
  return tau;
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
