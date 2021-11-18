//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "xzlarfg.h"
#include "ITER_API_v2_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int h_n
//                double *alpha1
//                ::coder::array<double, 2U> &b_x
//                int ix0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int h_n, double *alpha1, ::coder::array<double, 2U> &b_x,
               int ix0)
{
  double tau;
  tau = 0.0;
  if (h_n > 0) {
    double xnorm;
    xnorm = blas::xnrm2(h_n - 1, b_x, ix0);
    if (xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(*alpha1, xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        double b_a;
        int b_i;
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
        beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(h_n - 1, b_x, ix0));
        if ((*alpha1) >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - (*alpha1)) / beta1;
        b_a = 1.0 / ((*alpha1) - beta1);
        for (int c_k{ix0}; c_k <= b_i; c_k++) {
          b_x[c_k - 1] = b_a * b_x[c_k - 1];
        }
        for (int d_k{0}; d_k <= knt; d_k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        double a;
        int i1;
        tau = (beta1 - (*alpha1)) / beta1;
        a = 1.0 / ((*alpha1) - beta1);
        i1 = (ix0 + h_n) - 2;
        for (int k{ix0}; k <= i1; k++) {
          b_x[k - 1] = a * b_x[k - 1];
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

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
