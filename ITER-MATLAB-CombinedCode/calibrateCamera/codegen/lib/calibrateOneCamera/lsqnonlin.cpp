//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "lsqnonlin.h"
#include "CalculateCost.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_internal_types1.h"
#include "calibrateOneCamera_internal_types11.h"
#include "calibrateOneCamera_internal_types2.h"
#include "calibrateOneCamera_types.h"
#include "checkStoppingCriteria.h"
#include "driver.h"
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
//                ::coder::array<double, 1U> &xCurrent
//                double *resnorm
//                ::coder::array<double, 1U> &fval
//                double *exitflag
//                double *output_iterations
//                double *output_funcCount
//                double *output_stepsize
//                double *output_firstorderopt
//                char output_algorithm[19]
//                ::coder::array<double, 1U> &lambda_lower
//                ::coder::array<double, 1U> &lambda_upper
//                ::coder::array<double, 2U> &jacob
// Return Type  : void
//
namespace Codegen {
namespace coder {
void lsqnonlin(const anonymous_function *fun,
               ::coder::array<double, 1U> &xCurrent, double *resnorm,
               ::coder::array<double, 1U> &fval, double *exitflag,
               double *output_iterations, double *output_funcCount,
               double *output_stepsize, double *output_firstorderopt,
               char output_algorithm[19],
               ::coder::array<double, 1U> &lambda_lower,
               ::coder::array<double, 1U> &lambda_upper,
               ::coder::array<double, 2U> &jacob)
{
  static const char b_cv[19]{'l', 'e', 'v', 'e', 'n', 'b', 'e', 'r', 'g', '-',
                             'm', 'a', 'r', 'q', 'u', 'a', 'r', 'd', 't'};
  static const char t2_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                               'a', 'r', 'd'};
  b_anonymous_function b_this;
  ::coder::array<double, 2U> augJacobian;
  ::coder::array<double, 1U> b_dx;
  ::coder::array<double, 1U> fNew;
  ::coder::array<double, 1U> f_temp;
  ::coder::array<double, 1U>
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize;
  ::coder::array<double, 1U> finiteDifferenceRunTimeOptions_TypicalX;
  ::coder::array<double, 1U> gradf;
  ::coder::array<double, 1U> rhs;
  ::coder::array<double, 1U> xp;
  ::coder::array<signed char, 1U> scaleFactors;
  ::coder::array<bool, 1U> hasLB;
  ::coder::array<bool, 1U> hasUB;
  g_struct_T FiniteDifferences;
  double b_gamma;
  double funDiff;
  double relFactor;
  double sqrtGamma;
  int b_i;
  int funcCount;
  int g_n;
  int idx;
  int iter;
  int ixlast;
  int k;
  int m;
  int m_temp;
  int options_MaxFunctionEvaluations;
  int x0_size_idx_0;
  bool exitg1;
  bool stepSuccessful;
  for (k = 0; k < 19; k++) {
    output_algorithm[k] = b_cv[k];
  }
  x0_size_idx_0 = xCurrent.size(0);
  g_n = xCurrent.size(0);
  gradf.set_size(xCurrent.size(0));
  ixlast = xCurrent.size(0);
  b_dx.set_size(ixlast);
  for (k = 0; k < ixlast; k++) {
    b_dx[k] = rtInf;
  }
  funDiff = rtInf;
  ixlast = xCurrent.size(0);
  scaleFactors.set_size(ixlast);
  for (k = 0; k < ixlast; k++) {
    scaleFactors[k] = 1;
  }
  iter = 0;
  options_MaxFunctionEvaluations = 200 * xCurrent.size(0);
  hasLB.set_size(xCurrent.size(0));
  hasUB.set_size(xCurrent.size(0));
  ixlast = xCurrent.size(0);
  idx = 0;
  while ((idx + 1) <= ixlast) {
    hasLB[idx] = false;
    hasUB[idx] = false;
    idx++;
  }
  CalculateCost(xCurrent, fun->workspace.calibration.CameraParameters.ImageSize,
                fun->workspace.calibration.PatternPositions,
                fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
  m_temp = f_temp.size(0);
  jacob.set_size(f_temp.size(0), x0_size_idx_0);
  m = f_temp.size(0) - 1;
  fval.set_size(f_temp.size(0));
  fNew.set_size(f_temp.size(0));
  for (b_i = 0; b_i <= m; b_i++) {
    fval[b_i] = f_temp[b_i];
  }
  augJacobian.set_size(f_temp.size(0) + x0_size_idx_0, x0_size_idx_0);
  for (k = 0; k < x0_size_idx_0; k++) {
    idx = jacob.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      augJacobian[b_i + (augJacobian.size(0) * k)] =
          jacob[b_i + (jacob.size(0) * k)];
    }
  }
  rhs.set_size(f_temp.size(0) + x0_size_idx_0);
  *resnorm = 0.0;
  if (f_temp.size(0) >= 1) {
    ixlast = f_temp.size(0);
    for (k = 0; k < ixlast; k++) {
      *resnorm += fval[k] * fval[k];
    }
  }
  b_this.workspace.fun = *fun;
  optim::coder::utils::FiniteDifferences::factoryConstruct(
      &b_this, x0_size_idx_0, f_temp.size(0), t2_FiniteDifferenceType,
      &FiniteDifferences);
  finiteDifferenceRunTimeOptions_TypicalX.set_size(x0_size_idx_0);
  finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize.set_size(
      x0_size_idx_0);
  for (k = 0; k < x0_size_idx_0; k++) {
    finiteDifferenceRunTimeOptions_TypicalX[k] = 1.0;
    finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize[k] =
        1.4901161193847656E-8;
  }
  optim::coder::levenbergMarquardt::jacobianFiniteDifference(
      augJacobian, fval, xCurrent, t2_FiniteDifferenceType, &FiniteDifferences,
      finiteDifferenceRunTimeOptions_TypicalX,
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize, &funcCount,
      &stepSuccessful);
  b_gamma = 0.01;
  for (b_i = 0; b_i < g_n; b_i++) {
    idx = m_temp + g_n;
    ixlast = (idx * (b_i + 1)) - g_n;
    for (k = 0; k < g_n; k++) {
      augJacobian[ixlast + k] = 0.0;
    }
    augJacobian[(m_temp + b_i) + (augJacobian.size(0) * b_i)] = 0.1;
    idx *= b_i;
    ixlast = m_temp * b_i;
    for (k = 0; k <= m; k++) {
      jacob[ixlast + k] = augJacobian[idx + k];
    }
  }
  internal::blas::xgemv(f_temp.size(0), x0_size_idx_0, jacob, f_temp.size(0),
                        fval, gradf);
  f_temp.set_size(gradf.size(0));
  idx = gradf.size(0);
  for (k = 0; k < idx; k++) {
    f_temp[k] = -gradf[k];
  }
  sqrtGamma = optim::coder::levenbergMarquardt::computeFirstOrderOpt(gradf);
  relFactor = std::fmax(sqrtGamma, 1.4901161193847656E-8);
  stepSuccessful = true;
  idx = optim::coder::levenbergMarquardt::checkStoppingCriteria(
      static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
      xCurrent, b_dx, funcCount);
  exitg1 = false;
  while ((!exitg1) && (idx == -5)) {
    double resnormNew;
    bool evalOK;
    bool guard1{false};
    f_temp.set_size(fval.size(0));
    idx = fval.size(0);
    for (k = 0; k < idx; k++) {
      f_temp[k] = -fval[k];
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
    idx = xCurrent.size(0);
    for (k = 0; k < idx; k++) {
      xp[k] = xCurrent[k] + b_dx[k];
    }
    CalculateCost(xp, fun->workspace.calibration.CameraParameters.ImageSize,
                  fun->workspace.calibration.PatternPositions,
                  fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
    for (b_i = 0; b_i <= m; b_i++) {
      fNew[b_i] = f_temp[b_i];
    }
    resnormNew = 0.0;
    if (m_temp >= 1) {
      for (k = 0; k <= m; k++) {
        resnormNew += fNew[k] * fNew[k];
      }
    }
    evalOK = true;
    for (b_i = 0; b_i < m_temp; b_i++) {
      if (evalOK) {
        sqrtGamma = fNew[b_i];
        if ((std::isinf(sqrtGamma)) || (std::isnan(sqrtGamma))) {
          evalOK = false;
        }
      } else {
        evalOK = false;
      }
    }
    funcCount++;
    guard1 = false;
    if ((resnormNew < (*resnorm)) && evalOK) {
      iter++;
      funDiff = std::abs(resnormNew - (*resnorm)) / (*resnorm);
      *resnorm = resnormNew;
      fval.set_size(fNew.size(0));
      idx = fNew.size(0);
      for (k = 0; k < idx; k++) {
        fval[k] = fNew[k];
      }
      evalOK = optim::coder::levenbergMarquardt::b_jacobianFiniteDifference(
          augJacobian, fval, &funcCount, xp, t2_FiniteDifferenceType,
          &FiniteDifferences, finiteDifferenceRunTimeOptions_TypicalX,
          finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize);
      for (b_i = 0; b_i < g_n; b_i++) {
        idx = (m_temp + g_n) * b_i;
        ixlast = m_temp * b_i;
        for (k = 0; k <= m; k++) {
          jacob[ixlast + k] = augJacobian[idx + k];
        }
      }
      if (evalOK) {
        xCurrent.set_size(xp.size(0));
        idx = xp.size(0);
        for (k = 0; k < idx; k++) {
          xCurrent[k] = xp[k];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        idx = 2;
        g_n *= m_temp;
        for (k = 0; k < g_n; k++) {
          jacob[k] = rtNaN;
        }
        exitg1 = true;
      }
    } else {
      b_gamma *= 10.0;
      stepSuccessful = false;
      idx = jacob.size(1);
      for (k = 0; k < idx; k++) {
        ixlast = jacob.size(0);
        for (b_i = 0; b_i < ixlast; b_i++) {
          augJacobian[b_i + (augJacobian.size(0) * k)] =
              jacob[b_i + (jacob.size(0) * k)];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      sqrtGamma = std::sqrt(b_gamma);
      for (b_i = 0; b_i < g_n; b_i++) {
        ixlast = ((m_temp + g_n) * (b_i + 1)) - g_n;
        for (k = 0; k < g_n; k++) {
          augJacobian[ixlast + k] = 0.0;
        }
        augJacobian[(m_temp + b_i) + (augJacobian.size(0) * b_i)] = sqrtGamma;
      }
      internal::blas::xgemv(m_temp, g_n, jacob, m_temp, fval, gradf);
      f_temp.set_size(gradf.size(0));
      idx = gradf.size(0);
      for (k = 0; k < idx; k++) {
        f_temp[k] = -gradf[k];
      }
      idx = optim::coder::levenbergMarquardt::b_checkStoppingCriteria(
          static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
          funDiff, xCurrent, b_dx, funcCount, stepSuccessful, &iter);
      if (idx != -5) {
        exitg1 = true;
      }
    }
  }
  *output_firstorderopt =
      optim::coder::levenbergMarquardt::computeFirstOrderOpt(gradf);
  *output_stepsize = b_norm(b_dx);
  lambda_lower.set_size(x0_size_idx_0);
  lambda_upper.set_size(x0_size_idx_0);
  for (k = 0; k < x0_size_idx_0; k++) {
    lambda_lower[k] = 0.0;
    lambda_upper[k] = 0.0;
  }
  *exitflag = static_cast<double>(idx);
  *output_iterations = static_cast<double>(iter);
  *output_funcCount = static_cast<double>(funcCount);
}

} // namespace coder
} // namespace Codegen

//
// File trailer for lsqnonlin.cpp
//
// [EOF]
//
