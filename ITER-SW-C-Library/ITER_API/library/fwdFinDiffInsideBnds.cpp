//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fwdFinDiffInsideBnds.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "fwdFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : double xC_i
//                double b_lb_i
//                double ub_i
//                double *b_delta_i
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
bool fwdFinDiffInsideBnds(double xC_i, double b_lb_i, double ub_i,
                          double *b_delta_i)
{
  bool modifiedStep;
  modifiedStep = false;
  if (((b_lb_i != ub_i) && (xC_i >= b_lb_i)) && (xC_i <= ub_i)) {
    double d;
    d = xC_i + (*b_delta_i);
    if ((d > ub_i) || (d < b_lb_i)) {
      *b_delta_i = -(*b_delta_i);
      modifiedStep = true;
      if (((xC_i + (*b_delta_i)) > ub_i) || ((xC_i + (*b_delta_i)) < b_lb_i)) {
        double lbDiff;
        double ubDiff;
        lbDiff = xC_i - b_lb_i;
        ubDiff = ub_i - xC_i;
        if (lbDiff <= ubDiff) {
          *b_delta_i = -lbDiff;
        } else {
          *b_delta_i = ubDiff;
        }
      }
    }
  }
  return modifiedStep;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for fwdFinDiffInsideBnds.cpp
//
// [EOF]
//
