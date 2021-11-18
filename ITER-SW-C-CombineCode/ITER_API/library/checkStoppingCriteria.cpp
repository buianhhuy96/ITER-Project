//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingCriteria.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "checkStoppingCriteria.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double options_MaxFunctionEvaluations
//                const ::coder::array<double, 1U> &gradf
//                double relFactor
//                double funDiff
//                const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &b_dx
//                int funcCount
//                bool stepSuccessful
//                int *iter
// Return Type  : int
//
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int b_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor, double funDiff,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, bool stepSuccessful, int *iter)
{
  double normGradF;
  int exitflag;
  if (gradf.size(0) == 0) {
    normGradF = 0.0;
  } else {
    int b_i;
    normGradF = 0.0;
    b_i = gradf.size(0);
    for (int k{0}; k < b_i; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        normGradF = absx;
      } else if (absx > normGradF) {
        normGradF = absx;
      } else {
        /* no actions */
      }
    }
  }
  if (normGradF <= (1.0E-10 * relFactor)) {
    exitflag = 1;
  } else if ((static_cast<double>(funcCount)) >=
             options_MaxFunctionEvaluations) {
    exitflag = 0;
  } else if ((*iter) >= 400) {
    exitflag = 0;
  } else if (b_norm(b_dx) < (1.0E-6 * (b_norm(b_x) + 1.4901161193847656E-8))) {
    exitflag = 4;
    if (!stepSuccessful) {
      (*iter)++;
    }
  } else if (funDiff <= 1.0E-6) {
    exitflag = 3;
  } else {
    exitflag = -5;
  }
  return exitflag;
}

//
// Arguments    : double options_MaxFunctionEvaluations
//                const ::coder::array<double, 1U> &gradf
//                double relFactor
//                const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &b_dx
//                int funcCount
// Return Type  : int
//
int checkStoppingCriteria(double options_MaxFunctionEvaluations,
                          const ::coder::array<double, 1U> &gradf,
                          double relFactor,
                          const ::coder::array<double, 1U> &b_x,
                          const ::coder::array<double, 1U> &b_dx, int funcCount)
{
  double normGradF;
  int exitflag;
  if (gradf.size(0) == 0) {
    normGradF = 0.0;
  } else {
    int b_i;
    normGradF = 0.0;
    b_i = gradf.size(0);
    for (int k{0}; k < b_i; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        normGradF = absx;
      } else if (absx > normGradF) {
        normGradF = absx;
      } else {
        /* no actions */
      }
    }
  }
  if (normGradF <= (1.0E-10 * relFactor)) {
    exitflag = 1;
  } else if ((static_cast<double>(funcCount)) >=
             options_MaxFunctionEvaluations) {
    exitflag = 0;
  } else if (b_norm(b_dx) < (1.0E-6 * (b_norm(b_x) + 1.4901161193847656E-8))) {
    exitflag = 4;
  } else {
    exitflag = -5;
  }
  return exitflag;
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for checkStoppingCriteria.cpp
//
// [EOF]
//
