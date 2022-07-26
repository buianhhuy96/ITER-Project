//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computePrimalFeasError.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computePrimalFeasError.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_x[7]
//                const int finiteLB[8]
//                int mLB
//                const int finiteUB[8]
//                int mUB
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
double computePrimalFeasError(const double b_x[7], const int finiteLB[8],
                              int mLB, const int finiteUB[8], int mUB)
{
  double feasError;
  feasError = 0.0;
  for (int idx{0}; idx < mLB; idx++) {
    feasError =
        std::fmax(feasError, -1.7976931348623157E+308 - b_x[finiteLB[idx] - 1]);
  }
  for (int b_idx{0}; b_idx < mUB; b_idx++) {
    feasError = std::fmax(feasError,
                          b_x[finiteUB[b_idx] - 1] - 1.7976931348623157E+308);
  }
  return feasError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computePrimalFeasError.cpp
//
// [EOF]
//
