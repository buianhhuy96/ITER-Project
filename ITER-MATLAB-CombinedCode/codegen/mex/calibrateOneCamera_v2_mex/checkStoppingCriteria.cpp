//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingCriteria.cpp
//
// Code generation for function 'checkStoppingCriteria'
//

// Include files
#include "checkStoppingCriteria.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int32_T b_checkStoppingCriteria(
    real_T options_MaxFunctionEvaluations,
    const ::coder::array<real_T, 1U> &gradf, real_T relFactor, real_T funDiff,
    const ::coder::array<real_T, 1U> &x, const ::coder::array<real_T, 1U> &dx,
    int32_T funcCount, boolean_T stepSuccessful, int32_T *iter,
    real_T projSteepestDescentInfNorm, boolean_T hasFiniteBounds)
{
  real_T normGradF;
  int32_T exitflag;
  boolean_T guard1{false};
  normGradF = c_norm(gradf);
  guard1 = false;
  if (hasFiniteBounds) {
    if (projSteepestDescentInfNorm * projSteepestDescentInfNorm <=
        1.0E-10 * normGradF * relFactor) {
      exitflag = 1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    if ((!hasFiniteBounds) && (normGradF <= 1.0E-10 * relFactor)) {
      exitflag = 1;
    } else if (funcCount >= options_MaxFunctionEvaluations) {
      exitflag = 0;
    } else if (*iter >= 400) {
      exitflag = 0;
    } else if (b_norm(dx) < 1.0E-6 * (1.4901161193847656E-8 + b_norm(x))) {
      exitflag = 4;
      if (!stepSuccessful) {
        (*iter)++;
      }
    } else if (funDiff <= 1.0E-6) {
      exitflag = 3;
    } else {
      exitflag = -5;
    }
  }
  return exitflag;
}

int32_T checkStoppingCriteria(real_T options_MaxFunctionEvaluations,
                              const ::coder::array<real_T, 1U> &gradf,
                              real_T relFactor,
                              const ::coder::array<real_T, 1U> &x,
                              const ::coder::array<real_T, 1U> &dx,
                              int32_T funcCount,
                              real_T projSteepestDescentInfNorm,
                              boolean_T hasFiniteBounds)
{
  real_T normGradF;
  int32_T exitflag;
  boolean_T guard1{false};
  normGradF = c_norm(gradf);
  guard1 = false;
  if (hasFiniteBounds) {
    if (projSteepestDescentInfNorm * projSteepestDescentInfNorm <=
        1.0E-10 * normGradF * relFactor) {
      exitflag = 1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    if ((!hasFiniteBounds) && (normGradF <= 1.0E-10 * relFactor)) {
      exitflag = 1;
    } else if (funcCount >= options_MaxFunctionEvaluations) {
      exitflag = 0;
    } else if (b_norm(dx) < 1.0E-6 * (1.4901161193847656E-8 + b_norm(x))) {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
  }
  return exitflag;
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingCriteria.cpp)
