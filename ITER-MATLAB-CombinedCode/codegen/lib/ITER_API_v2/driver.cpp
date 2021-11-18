//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "driver.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &gradf
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
double computeFirstOrderOpt(const ::coder::array<double, 1U> &gradf)
{
  double firstOrderOpt;
  if (gradf.size(0) == 0) {
    firstOrderOpt = 0.0;
  } else {
    int b_i;
    firstOrderOpt = 0.0;
    b_i = gradf.size(0);
    for (int k{0}; k < b_i; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        firstOrderOpt = absx;
      } else if (absx > firstOrderOpt) {
        firstOrderOpt = absx;
      } else {
        /* no actions */
      }
    }
  }
  return firstOrderOpt;
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
