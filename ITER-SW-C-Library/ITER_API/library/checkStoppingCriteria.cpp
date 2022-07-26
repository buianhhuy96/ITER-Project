//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingCriteria.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "checkStoppingCriteria.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double gradf[6]
//                double relFactor
//                double funDiff
//                const double b_x[6]
//                const double b_dx[6]
//                int funcCount
//                bool stepSuccessful
//                int *b_iter
//                double projSteepestDescentInfNorm
//                bool hasFiniteBounds
// Return Type  : int
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int b_checkStoppingCriteria(const double gradf[6], double relFactor,
                            double funDiff, const double b_x[6],
                            const double b_dx[6], int funcCount,
                            bool stepSuccessful, int *b_iter,
                            double projSteepestDescentInfNorm,
                            bool hasFiniteBounds)
{
  double normGradF;
  int exitflag;
  normGradF = 0.0;
  for (int k{0}; k < 6; k++) {
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
  if (hasFiniteBounds &&
      ((projSteepestDescentInfNorm * projSteepestDescentInfNorm) <=
       ((1.0E-10 * normGradF) * relFactor))) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= (1.0E-10 * relFactor))) {
    exitflag = 1;
  } else if (funcCount >= 20000) {
    exitflag = 0;
  } else if ((*b_iter) >= 1000) {
    exitflag = 0;
  } else {
    double b_y;
    double c_scale;
    double scale;
    double y;
    y = 0.0;
    scale = 3.3121686421112381E-170;
    b_y = 0.0;
    c_scale = 3.3121686421112381E-170;
    for (int b_k{0}; b_k < 6; b_k++) {
      double absxk;
      double b_absxk;
      absxk = std::abs(b_dx[b_k]);
      if (absxk > scale) {
        double b_t;
        b_t = scale / absxk;
        y = ((y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        double b_t;
        b_t = absxk / scale;
        y += b_t * b_t;
      }
      b_absxk = std::abs(b_x[b_k]);
      if (b_absxk > c_scale) {
        double d_t;
        d_t = c_scale / b_absxk;
        b_y = ((b_y * d_t) * d_t) + 1.0;
        c_scale = b_absxk;
      } else {
        double d_t;
        d_t = b_absxk / c_scale;
        b_y += d_t * d_t;
      }
    }
    y = scale * std::sqrt(y);
    b_y = c_scale * std::sqrt(b_y);
    if (y < (1.0E-6 * (b_y + 1.4901161193847656E-8))) {
      exitflag = 4;
      if (!stepSuccessful) {
        (*b_iter)++;
      }
    } else if (funDiff <= 1.0E-6) {
      exitflag = 3;
    } else {
      exitflag = -5;
    }
  }
  return exitflag;
}

//
// Arguments    : double options_MaxFunctionEvaluations
//                const ::coder::array<double, 1U> &gradf
//                double relFactor
//                double funDiff
//                const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &b_dx
//                int funcCount
//                bool stepSuccessful
//                int *b_iter
//                double projSteepestDescentInfNorm
//                bool hasFiniteBounds
// Return Type  : int
//
int c_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor, double funDiff,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, bool stepSuccessful, int *b_iter,
                            double projSteepestDescentInfNorm,
                            bool hasFiniteBounds)
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
  if (hasFiniteBounds &&
      ((projSteepestDescentInfNorm * projSteepestDescentInfNorm) <=
       ((1.0E-10 * normGradF) * relFactor))) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= (1.0E-10 * relFactor))) {
    exitflag = 1;
  } else if ((static_cast<double>(funcCount)) >=
             options_MaxFunctionEvaluations) {
    exitflag = 0;
  } else if ((*b_iter) >= 400) {
    exitflag = 0;
  } else if (b_norm(b_dx) < (1.0E-6 * (b_norm(b_x) + 1.4901161193847656E-8))) {
    exitflag = 4;
    if (!stepSuccessful) {
      (*b_iter)++;
    }
  } else if (funDiff <= 1.0E-6) {
    exitflag = 3;
  } else {
    exitflag = -5;
  }
  return exitflag;
}

//
// Arguments    : const double gradf[6]
//                double relFactor
//                const double b_x[6]
//                int funcCount
//                double projSteepestDescentInfNorm
//                bool hasFiniteBounds
// Return Type  : int
//
int checkStoppingCriteria(const double gradf[6], double relFactor,
                          const double b_x[6], int funcCount,
                          double projSteepestDescentInfNorm,
                          bool hasFiniteBounds)
{
  double normGradF;
  int exitflag;
  normGradF = 0.0;
  for (int k{0}; k < 6; k++) {
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
  if (hasFiniteBounds &&
      ((projSteepestDescentInfNorm * projSteepestDescentInfNorm) <=
       ((1.0E-10 * normGradF) * relFactor))) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= (1.0E-10 * relFactor))) {
    exitflag = 1;
  } else if (funcCount >= 20000) {
    exitflag = 0;
  } else {
    double b_y;
    double c_scale;
    double scale;
    double y;
    y = 0.0;
    scale = 3.3121686421112381E-170;
    b_y = 0.0;
    c_scale = 3.3121686421112381E-170;
    for (int b_k{0}; b_k < 6; b_k++) {
      double absxk;
      if (rtInf > scale) {
        y = ((y * 0.0) * 0.0) + 1.0;
        scale = rtInf;
      } else {
        y = rtNaN;
      }
      absxk = std::abs(b_x[b_k]);
      if (absxk > c_scale) {
        double b_t;
        b_t = c_scale / absxk;
        b_y = ((b_y * b_t) * b_t) + 1.0;
        c_scale = absxk;
      } else {
        double b_t;
        b_t = absxk / c_scale;
        b_y += b_t * b_t;
      }
    }
    y = scale * std::sqrt(y);
    b_y = c_scale * std::sqrt(b_y);
    if (y < (1.0E-6 * (b_y + 1.4901161193847656E-8))) {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
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
//                double projSteepestDescentInfNorm
//                bool hasFiniteBounds
// Return Type  : int
//
int d_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, double projSteepestDescentInfNorm,
                            bool hasFiniteBounds)
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
  if (hasFiniteBounds &&
      ((projSteepestDescentInfNorm * projSteepestDescentInfNorm) <=
       ((1.0E-10 * normGradF) * relFactor))) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= (1.0E-10 * relFactor))) {
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
} // namespace ITER

//
// File trailer for checkStoppingCriteria.cpp
//
// [EOF]
//
