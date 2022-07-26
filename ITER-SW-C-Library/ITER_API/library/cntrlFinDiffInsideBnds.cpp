//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cntrlFinDiffInsideBnds.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "cntrlFinDiffInsideBnds.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double xC_i
//                double b_lb_i
//                double ub_i
//                double *b_delta_i
// Return Type  : int
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
int cntrlFinDiffInsideBnds(double xC_i, double b_lb_i, double ub_i,
                           double *b_delta_i)
{
  int formulaType;
  formulaType = 0;
  if (((b_lb_i != ub_i) && (xC_i >= b_lb_i)) && (xC_i <= ub_i)) {
    if ((xC_i - (*b_delta_i)) < b_lb_i) {
      if (ub_i < (xC_i + (*b_delta_i))) {
        double b_distNear_tmp;
        double distFar;
        double distNear;
        double distNear_tmp;
        distNear_tmp = xC_i - b_lb_i;
        b_distNear_tmp = ub_i - xC_i;
        distNear = std::fmin(distNear_tmp, b_distNear_tmp);
        distFar = std::fmax(distNear_tmp, b_distNear_tmp);
        if (distNear >= (distFar / 2.0)) {
          *b_delta_i = distNear;
        } else {
          *b_delta_i = distFar / 2.0;
          if ((xC_i - b_lb_i) >= (ub_i - xC_i)) {
            formulaType = -1;
          } else {
            formulaType = 1;
          }
        }
      } else if ((xC_i + (2.0 * (*b_delta_i))) <= ub_i) {
        formulaType = 1;
      } else {
        double b_d1;
        double d3;
        b_d1 = (ub_i - xC_i) / 2.0;
        d3 = xC_i - b_lb_i;
        if (d3 >= b_d1) {
          *b_delta_i = d3;
        } else {
          *b_delta_i = b_d1;
          formulaType = 1;
        }
      }
    } else if (ub_i < (xC_i + (*b_delta_i))) {
      if (b_lb_i <= (xC_i - (2.0 * (*b_delta_i)))) {
        formulaType = -1;
      } else {
        double d;
        double d2;
        d = (xC_i - b_lb_i) / 2.0;
        d2 = ub_i - xC_i;
        if (d2 >= d) {
          *b_delta_i = d2;
        } else {
          *b_delta_i = d;
          formulaType = -1;
        }
      }
    } else {
      /* no actions */
    }
  }
  return formulaType;
}

} // namespace internal
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for cntrlFinDiffInsideBnds.cpp
//
// [EOF]
//
