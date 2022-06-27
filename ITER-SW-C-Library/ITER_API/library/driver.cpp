//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "driver.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &gradf
//                bool hasFiniteBounds
//                const double *projSteepestDescentInfNorm
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
double computeFirstOrderOpt(const ::coder::array<double, 1U> &gradf,
                            bool hasFiniteBounds,
                            const double *projSteepestDescentInfNorm)
{
  double b_firstOrderOpt;
  if (hasFiniteBounds) {
    double b;
    if (gradf.size(0) == 0) {
      b = 0.0;
    } else {
      int i1;
      b = 0.0;
      i1 = gradf.size(0);
      for (int b_k{0}; b_k < i1; b_k++) {
        double b_absx;
        b_absx = std::abs(gradf[b_k]);
        if (std::isnan(b_absx)) {
          b = b_absx;
        } else if (b_absx > b) {
          b = b_absx;
        } else {
          /* no actions */
        }
      }
    }
    if (std::abs((*projSteepestDescentInfNorm) - b) <
        (2.2204460492503131E-16 * std::fmax(*projSteepestDescentInfNorm, b))) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else if (b == 0.0) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else {
      b_firstOrderOpt =
          ((*projSteepestDescentInfNorm) * (*projSteepestDescentInfNorm)) / b;
    }
  } else if (gradf.size(0) == 0) {
    b_firstOrderOpt = 0.0;
  } else {
    int b_i;
    b_firstOrderOpt = 0.0;
    b_i = gradf.size(0);
    for (int k{0}; k < b_i; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        b_firstOrderOpt = absx;
      } else if (absx > b_firstOrderOpt) {
        b_firstOrderOpt = absx;
      } else {
        /* no actions */
      }
    }
  }
  return b_firstOrderOpt;
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for driver.cpp
//
// [EOF]
//
