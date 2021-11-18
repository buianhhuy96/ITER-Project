//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "lsqnonlin.h"
#include "CalculateCost.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateCamera_internal_types.h"
#include "calibrateCamera_internal_types1.h"
#include "calibrateCamera_internal_types11.h"
#include "calibrateCamera_types.h"
#include "factoryConstruct.h"
#include "jacobianFiniteDifference.h"
#include "linearLeastSquares.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const anonymous_function *fun
//                ::coder::array<real_T, 1U> &xCurrent
//                real_T *resnorm
//                ::coder::array<real_T, 1U> &fval
//                real_T *exitflag
//                real_T *output_iterations
//                real_T *output_funcCount
//                real_T *output_stepsize
//                real_T *output_firstorderopt
//                char_T output_algorithm[19]
//                ::coder::array<real_T, 1U> &lambda_lower
//                ::coder::array<real_T, 1U> &lambda_upper
//                ::coder::array<real_T, 2U> &jacob
// Return Type  : void
//
namespace Codegen {
namespace coder {
void lsqnonlin(const anonymous_function *fun,
               ::coder::array<real_T, 1U> &xCurrent, real_T *resnorm,
               ::coder::array<real_T, 1U> &fval, real_T *exitflag,
               real_T *output_iterations, real_T *output_funcCount,
               real_T *output_stepsize, real_T *output_firstorderopt,
               char_T output_algorithm[19],
               ::coder::array<real_T, 1U> &lambda_lower,
               ::coder::array<real_T, 1U> &lambda_upper,
               ::coder::array<real_T, 2U> &jacob)
{
  static const char_T b_cv[19]{'l', 'e', 'v', 'e', 'n', 'b', 'e', 'r', 'g', '-',
                               'm', 'a', 'r', 'q', 'u', 'a', 'r', 'd', 't'};
  static const char_T t1_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                                 'a', 'r', 'd'};
  b_anonymous_function b_this;
  ::coder::array<real_T, 2U> augJacobian;
  ::coder::array<real_T, 1U> b_dx;
  ::coder::array<real_T, 1U> fNew;
  ::coder::array<real_T, 1U> f_temp;
  ::coder::array<real_T, 1U> gradf;
  ::coder::array<real_T, 1U> rhs;
  ::coder::array<real_T, 1U> x0;
  ::coder::array<real_T, 1U> xp;
  c_struct_T FiniteDifferences;
  real_T absx;
  real_T b_gamma;
  real_T funDiff;
  real_T normGradF;
  real_T relFactor;
  int32_T b_i;
  int32_T d_i;
  int32_T funcCount;
  int32_T g_n;
  int32_T iter;
  int32_T ixlast;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  int32_T m_temp;
  int32_T options_MaxFunctionEvaluations;
  boolean_T exitg1;
  boolean_T stepSuccessful;
  for (b_i = 0; b_i < 19; b_i++) {
    output_algorithm[b_i] = b_cv[b_i];
  }
  x0.set_size(xCurrent.size(0));
  loop_ub = xCurrent.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    x0[b_i] = xCurrent[b_i];
  }
  g_n = xCurrent.size(0);
  gradf.set_size(xCurrent.size(0));
  ixlast = xCurrent.size(0);
  b_dx.set_size(ixlast);
  for (b_i = 0; b_i < ixlast; b_i++) {
    b_dx[b_i] = rtInf;
  }
  funDiff = rtInf;
  iter = 0;
  options_MaxFunctionEvaluations = 200 * xCurrent.size(0);
  CalculateCost(x0, &fun->workspace.calibration.CameraParameters,
                fun->workspace.calibration.PatternPositions,
                fun->workspace.calibration.ImagePoints,
                fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
  m_temp = f_temp.size(0);
  jacob.set_size(f_temp.size(0), x0.size(0));
  m = f_temp.size(0) - 1;
  fval.set_size(f_temp.size(0));
  fNew.set_size(f_temp.size(0));
  for (d_i = 0; d_i <= m; d_i++) {
    fval[d_i] = f_temp[d_i];
  }
  augJacobian.set_size(f_temp.size(0) + x0.size(0), x0.size(0));
  loop_ub = x0.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    ixlast = jacob.size(0);
    for (d_i = 0; d_i < ixlast; d_i++) {
      augJacobian[d_i + (augJacobian.size(0) * b_i)] =
          jacob[d_i + (jacob.size(0) * b_i)];
    }
  }
  rhs.set_size(f_temp.size(0) + x0.size(0));
  *resnorm = 0.0;
  if (f_temp.size(0) >= 1) {
    ixlast = f_temp.size(0);
    for (k = 0; k < ixlast; k++) {
      *resnorm += fval[k] * fval[k];
    }
  }
  b_this.workspace.fun = *fun;
  optim::coder::utils::FiniteDifferences::factoryConstruct(
      &b_this, x0.size(0), f_temp.size(0), t1_FiniteDifferenceType,
      &FiniteDifferences);
  optim::coder::levenbergMarquardt::jacobianFiniteDifference(
      augJacobian, fval, x0, t1_FiniteDifferenceType, &FiniteDifferences,
      &funcCount, &stepSuccessful);
  b_gamma = 0.01;
  for (d_i = 0; d_i < g_n; d_i++) {
    ixlast = m_temp + g_n;
    loop_ub = (ixlast * (d_i + 1)) - g_n;
    for (k = 0; k < g_n; k++) {
      augJacobian[loop_ub + k] = 0.0;
    }
    augJacobian[(m_temp + d_i) + (augJacobian.size(0) * d_i)] = 0.1;
    ixlast *= d_i;
    loop_ub = m_temp * d_i;
    for (k = 0; k <= m; k++) {
      jacob[loop_ub + k] = augJacobian[ixlast + k];
    }
  }
  internal::blas::xgemv(f_temp.size(0), x0.size(0), jacob, f_temp.size(0), fval,
                        gradf);
  normGradF = 0.0;
  b_i = gradf.size(0);
  for (k = 0; k < b_i; k++) {
    absx = std::abs(gradf[k]);
    if (std::isnan(absx)) {
      normGradF = absx;
    } else if (absx > normGradF) {
      normGradF = absx;
    } else {
      /* no actions */
    }
  }
  relFactor = std::fmax(normGradF, 1.4901161193847656E-8);
  stepSuccessful = true;
  normGradF = 0.0;
  b_i = gradf.size(0);
  for (k = 0; k < b_i; k++) {
    absx = std::abs(gradf[k]);
    if (std::isnan(absx)) {
      normGradF = absx;
    } else if (absx > normGradF) {
      normGradF = absx;
    } else {
      /* no actions */
    }
  }
  if (normGradF <= (1.0E-10 * relFactor)) {
    ixlast = 1;
  } else if (funcCount >= options_MaxFunctionEvaluations) {
    ixlast = 0;
  } else if (b_norm(b_dx) < (1.0E-6 * (b_norm(x0) + 1.4901161193847656E-8))) {
    ixlast = 4;
  } else {
    ixlast = -5;
  }
  exitg1 = false;
  while ((!exitg1) && (ixlast == -5)) {
    boolean_T evalOK;
    boolean_T guard1{false};
    f_temp.set_size(fval.size(0));
    loop_ub = fval.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      f_temp[b_i] = -fval[b_i];
    }
    for (k = 0; k <= m; k++) {
      rhs[k] = f_temp[k];
    }
    for (k = 0; k < g_n; k++) {
      rhs[(m + k) + 1] = 0.0;
    }
    optim::coder::levenbergMarquardt::linearLeastSquares(augJacobian, rhs, b_dx,
                                                         m_temp + g_n, g_n);
    xp.set_size(xCurrent.size(0));
    loop_ub = xCurrent.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      xp[b_i] = xCurrent[b_i] + b_dx[b_i];
    }
    CalculateCost(xp, &fun->workspace.calibration.CameraParameters,
                  fun->workspace.calibration.PatternPositions,
                  fun->workspace.calibration.ImagePoints,
                  fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
    for (d_i = 0; d_i <= m; d_i++) {
      fNew[d_i] = f_temp[d_i];
    }
    normGradF = 0.0;
    if (m_temp >= 1) {
      for (k = 0; k <= m; k++) {
        normGradF += fNew[k] * fNew[k];
      }
    }
    evalOK = true;
    for (d_i = 0; d_i < m_temp; d_i++) {
      if (evalOK) {
        if ((std::isinf(fNew[d_i])) || (std::isnan(fNew[d_i]))) {
          evalOK = false;
        }
      } else {
        evalOK = false;
      }
    }
    funcCount++;
    guard1 = false;
    if ((normGradF < (*resnorm)) && evalOK) {
      iter++;
      funDiff = std::abs(normGradF - (*resnorm)) / (*resnorm);
      *resnorm = normGradF;
      fval.set_size(fNew.size(0));
      loop_ub = fNew.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        fval[b_i] = fNew[b_i];
      }
      evalOK = optim::coder::levenbergMarquardt::b_jacobianFiniteDifference(
          augJacobian, fval, &funcCount, xp, t1_FiniteDifferenceType,
          &FiniteDifferences);
      for (d_i = 0; d_i < g_n; d_i++) {
        ixlast = (m_temp + g_n) * d_i;
        loop_ub = m_temp * d_i;
        for (k = 0; k <= m; k++) {
          jacob[loop_ub + k] = augJacobian[ixlast + k];
        }
      }
      if (evalOK) {
        xCurrent.set_size(xp.size(0));
        loop_ub = xp.size(0);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          xCurrent[b_i] = xp[b_i];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        ixlast = 2;
        g_n *= m_temp;
        for (k = 0; k < g_n; k++) {
          jacob[k] = rtNaN;
        }
        exitg1 = true;
      }
    } else {
      b_gamma *= 10.0;
      stepSuccessful = false;
      loop_ub = jacob.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        ixlast = jacob.size(0);
        for (d_i = 0; d_i < ixlast; d_i++) {
          augJacobian[d_i + (augJacobian.size(0) * b_i)] =
              jacob[d_i + (jacob.size(0) * b_i)];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      normGradF = std::sqrt(b_gamma);
      for (d_i = 0; d_i < g_n; d_i++) {
        loop_ub = ((m_temp + g_n) * (d_i + 1)) - g_n;
        for (k = 0; k < g_n; k++) {
          augJacobian[loop_ub + k] = 0.0;
        }
        augJacobian[(m_temp + d_i) + (augJacobian.size(0) * d_i)] = normGradF;
      }
      internal::blas::xgemv(m_temp, g_n, jacob, m_temp, fval, gradf);
      normGradF = 0.0;
      b_i = gradf.size(0);
      for (k = 0; k < b_i; k++) {
        absx = std::abs(gradf[k]);
        if (std::isnan(absx)) {
          normGradF = absx;
        } else if (absx > normGradF) {
          normGradF = absx;
        } else {
          /* no actions */
        }
      }
      if (normGradF <= (1.0E-10 * relFactor)) {
        ixlast = 1;
      } else if (funcCount >= options_MaxFunctionEvaluations) {
        ixlast = 0;
      } else if (iter >= 400) {
        ixlast = 0;
      } else if (b_norm(b_dx) <
                 (1.0E-6 * (b_norm(xCurrent) + 1.4901161193847656E-8))) {
        ixlast = 4;
        if (!stepSuccessful) {
          iter++;
        }
      } else if (funDiff <= 1.0E-6) {
        ixlast = 3;
      } else {
        ixlast = -5;
      }
      if (ixlast != -5) {
        exitg1 = true;
      }
    }
  }
  normGradF = 0.0;
  b_i = gradf.size(0);
  for (k = 0; k < b_i; k++) {
    absx = std::abs(gradf[k]);
    if (std::isnan(absx)) {
      normGradF = absx;
    } else if (absx > normGradF) {
      normGradF = absx;
    } else {
      /* no actions */
    }
  }
  *output_stepsize = b_norm(b_dx);
  lambda_lower.set_size(x0.size(0));
  loop_ub = x0.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    lambda_lower[b_i] = 0.0;
  }
  lambda_upper.set_size(x0.size(0));
  loop_ub = x0.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    lambda_upper[b_i] = 0.0;
  }
  *exitflag = static_cast<real_T>(ixlast);
  *output_iterations = static_cast<real_T>(iter);
  *output_funcCount = static_cast<real_T>(funcCount);
  *output_firstorderopt = normGradF;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for lsqnonlin.cpp
//
// [EOF]
//
