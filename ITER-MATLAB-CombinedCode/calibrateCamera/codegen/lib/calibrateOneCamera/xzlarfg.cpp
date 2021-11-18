//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xzlarfg.h"
#include "calibrateOneCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int g_n
//                double *alpha1
//                ::coder::array<double, 2U> &b_x
//                int ix0
// Return Type  : double
//
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int g_n, double *alpha1, ::coder::array<double, 2U> &b_x,
               int ix0)
{
  double tau;
  tau = 0.0;
  if (g_n > 0) {
    double b_xnorm;
    b_xnorm = blas::xnrm2(g_n - 1, b_x, ix0);
    if (b_xnorm != 0.0) {
      double beta1;
      beta1 = rt_hypotd_snf(*alpha1, b_xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        int b_i;
        int k;
        int knt;
        knt = -1;
        b_i = (ix0 + g_n) - 2;
        do {
          knt++;
          for (k = ix0; k <= b_i; k++) {
            b_x[k - 1] = 9.9792015476736E+291 * b_x[k - 1];
          }
          beta1 *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
        beta1 = rt_hypotd_snf(*alpha1, blas::xnrm2(g_n - 1, b_x, ix0));
        if ((*alpha1) >= 0.0) {
          beta1 = -beta1;
        }
        tau = (beta1 - (*alpha1)) / beta1;
        b_xnorm = 1.0 / ((*alpha1) - beta1);
        for (k = ix0; k <= b_i; k++) {
          b_x[k - 1] = b_xnorm * b_x[k - 1];
        }
        for (k = 0; k <= knt; k++) {
          beta1 *= 1.0020841800044864E-292;
        }
        *alpha1 = beta1;
      } else {
        int b_i;
        tau = (beta1 - (*alpha1)) / beta1;
        b_xnorm = 1.0 / ((*alpha1) - beta1);
        b_i = (ix0 + g_n) - 2;
        for (int k{ix0}; k <= b_i; k++) {
          b_x[k - 1] = b_xnorm * b_x[k - 1];
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
} // namespace Codegen

//
// File trailer for xzlarfg.cpp
//
// [EOF]
//
