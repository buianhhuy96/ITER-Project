//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeComplError.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeComplError.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double xCurrent[7]
//                int mIneq
//                const int finiteLB[8]
//                int mLB
//                const int finiteUB[8]
//                int mUB
//                const double lambda[15]
//                int c_iL0
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
double computeComplError(const double xCurrent[7], int mIneq,
                         const int finiteLB[8], int mLB, const int finiteUB[8],
                         int mUB, const double lambda[15], int c_iL0)
{
  double nlpComplError;
  nlpComplError = 0.0;
  if (((mIneq + mLB) + mUB) > 0) {
    int lbOffset;
    int ubOffset;
    lbOffset = (c_iL0 + mIneq) - 1;
    ubOffset = lbOffset + mLB;
    for (int idx{0}; idx < mLB; idx++) {
      double b_nlpComplError_tmp;
      double lbLambda;
      lbLambda = lambda[lbOffset + idx];
      b_nlpComplError_tmp =
          xCurrent[finiteLB[idx] - 1] - -1.7976931348623157E+308;
      nlpComplError = std::fmax(
          nlpComplError,
          std::fmin(std::abs(b_nlpComplError_tmp * lbLambda),
                    std::fmin(std::abs(b_nlpComplError_tmp), lbLambda)));
    }
    for (int b_idx{0}; b_idx < mUB; b_idx++) {
      double c_nlpComplError_tmp;
      double ubLambda;
      ubLambda = lambda[ubOffset + b_idx];
      c_nlpComplError_tmp =
          1.7976931348623157E+308 - xCurrent[finiteUB[b_idx] - 1];
      nlpComplError = std::fmax(
          nlpComplError,
          std::fmin(std::abs(c_nlpComplError_tmp * ubLambda),
                    std::fmin(std::abs(c_nlpComplError_tmp), ubLambda)));
    }
  }
  return nlpComplError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computeComplError.cpp
//
// [EOF]
//
