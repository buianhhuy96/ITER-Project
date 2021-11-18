//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xzlarfg.h"
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int32_T g_n
//                real_T *alpha1
//                ::coder::array<real_T, 2U> &b_x
//                int32_T ix0
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
namespace internal {
namespace reflapack {
real_T xzlarfg(int32_T g_n, real_T *alpha1, ::coder::array<real_T, 2U> &b_x,
               int32_T ix0)
{
  real_T tau;
  tau = 0.0;
  if (g_n > 0) {
    real_T b_xnorm;
    b_xnorm = blas::xnrm2(g_n - 1, b_x, ix0);
    if (b_xnorm != 0.0) {
      real_T beta1;
      beta1 = rt_hypotd_snf(*alpha1, b_xnorm);
      if ((*alpha1) >= 0.0) {
        beta1 = -beta1;
      }
      if (std::abs(beta1) < 1.0020841800044864E-292) {
        int32_T b_i;
        int32_T k;
        int32_T knt;
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
        int32_T b_i;
        tau = (beta1 - (*alpha1)) / beta1;
        b_xnorm = 1.0 / ((*alpha1) - beta1);
        b_i = (ix0 + g_n) - 2;
        for (int32_T k{ix0}; k <= b_i; k++) {
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
