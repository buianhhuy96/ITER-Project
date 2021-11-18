//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "lsqnonlin.h"
#include "CalculateCost.h"
#include "ITER_API_v2_internal_types.h"
#include "ITER_API_v2_internal_types1.h"
#include "ITER_API_v2_internal_types11.h"
#include "ITER_API_v2_internal_types2.h"
#include "ITER_API_v2_internal_types3.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
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
  array<double, 2U> augJacobian;
  array<double, 1U> a__2;
  array<double, 1U> a__4;
  array<double, 1U> b_dx;
  array<double, 1U> c_x;
  array<double, 1U> fNew;
  array<double, 1U> f_temp;
  array<double, 1U> finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize;
  array<double, 1U> finiteDifferenceRunTimeOptions_TypicalX;
  array<double, 1U> gradf;
  array<double, 1U> rhs;
  array<double, 1U> scaleFactors;
  array<double, 1U> xp;
  array<bool, 1U> hasLB;
  array<bool, 1U> hasUB;
  array<bool, 1U> indActive;
  g_struct_T FiniteDifferences;
  double b_gamma;
  double b_output_firstorderopt;
  double b_output_stepsize;
  double b_resnorm;
  double funDiff;
  double relFactor;
  int b_exitflag;
  int b_funcCount;
  int b_loop_ub;
  int b_nvar;
  int funcCount;
  int h_n;
  int idx;
  int iter;
  int m;
  int m_temp;
  int options_MaxFunctionEvaluations;
  int varargin_1_idx_0;
  int x0_size_idx_0;
  int xCurrent_idx_0;
  bool a__1;
  bool exitg1;
  bool stepSuccessful;
  x0_size_idx_0 = xCurrent.size(0);
  h_n = xCurrent.size(0);
  xCurrent_idx_0 = xCurrent.size(0);
  indActive.set_size(xCurrent_idx_0);
  for (int b_i{0}; b_i < xCurrent_idx_0; b_i++) {
    indActive[b_i] = false;
  }
  gradf.set_size(xCurrent.size(0));
  varargin_1_idx_0 = xCurrent.size(0);
  b_dx.set_size(varargin_1_idx_0);
  for (int i1{0}; i1 < varargin_1_idx_0; i1++) {
    b_dx[i1] = rtInf;
  }
  funDiff = rtInf;
  xCurrent_idx_0 = xCurrent.size(0);
  scaleFactors.set_size(xCurrent_idx_0);
  for (int i2{0}; i2 < xCurrent_idx_0; i2++) {
    scaleFactors[i2] = 1.0;
  }
  iter = 0;
  options_MaxFunctionEvaluations = 200 * xCurrent.size(0);
  hasLB.set_size(xCurrent.size(0));
  hasUB.set_size(xCurrent.size(0));
  b_nvar = xCurrent.size(0);
  idx = 0;
  while ((idx + 1) <= b_nvar) {
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
  for (int c_i{0}; c_i <= m; c_i++) {
    fval[c_i] = f_temp[c_i];
  }
  augJacobian.set_size(f_temp.size(0) + x0_size_idx_0, x0_size_idx_0);
  for (int i3{0}; i3 < x0_size_idx_0; i3++) {
    int loop_ub;
    loop_ub = jacob.size(0);
    for (int i4{0}; i4 < loop_ub; i4++) {
      augJacobian[i4 + (augJacobian.size(0) * i3)] =
          jacob[i4 + (jacob.size(0) * i3)];
    }
  }
  rhs.set_size(f_temp.size(0) + x0_size_idx_0);
  b_resnorm = 0.0;
  if (f_temp.size(0) >= 1) {
    int ixlast;
    ixlast = f_temp.size(0);
    for (int k{0}; k < ixlast; k++) {
      b_resnorm += fval[k] * fval[k];
    }
  }
  b_this.workspace.fun = *fun;
  optim::coder::utils::FiniteDifferences::factoryConstruct(
      &b_this, x0_size_idx_0, f_temp.size(0), t2_FiniteDifferenceType,
      &FiniteDifferences);
  finiteDifferenceRunTimeOptions_TypicalX.set_size(x0_size_idx_0);
  finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize.set_size(
      x0_size_idx_0);
  for (int i5{0}; i5 < x0_size_idx_0; i5++) {
    finiteDifferenceRunTimeOptions_TypicalX[i5] = 1.0;
    finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize[i5] =
        1.4901161193847656E-8;
  }
  optim::coder::levenbergMarquardt::jacobianFiniteDifference(
      augJacobian, fval, xCurrent, t2_FiniteDifferenceType, &FiniteDifferences,
      finiteDifferenceRunTimeOptions_TypicalX,
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize, &funcCount,
      &a__1);
  b_funcCount = funcCount;
  b_gamma = 0.01;
  for (int e_i{0}; e_i < h_n; e_i++) {
    int b_iy0;
    int ix0;
    int iy0;
    int iy0_tmp;
    iy0_tmp = m_temp + h_n;
    iy0 = (iy0_tmp * (e_i + 1)) - h_n;
    for (int b_k{0}; b_k < h_n; b_k++) {
      augJacobian[iy0 + b_k] = 0.0;
    }
    augJacobian[(m_temp + e_i) + (augJacobian.size(0) * e_i)] = 0.1;
    ix0 = iy0_tmp * e_i;
    b_iy0 = m_temp * e_i;
    for (int c_k{0}; c_k <= m; c_k++) {
      jacob[b_iy0 + c_k] = augJacobian[ix0 + c_k];
    }
  }
  internal::blas::xgemv(f_temp.size(0), x0_size_idx_0, jacob, f_temp.size(0),
                        fval, gradf);
  a__2.set_size(gradf.size(0));
  b_loop_ub = gradf.size(0);
  for (int i6{0}; i6 < b_loop_ub; i6++) {
    a__2[i6] = -gradf[i6];
  }
  double b_x;
  b_x = optim::coder::levenbergMarquardt::computeFirstOrderOpt(gradf);
  relFactor = std::fmax(b_x, 1.4901161193847656E-8);
  stepSuccessful = true;
  b_exitflag = optim::coder::levenbergMarquardt::checkStoppingCriteria(
      static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
      xCurrent, b_dx, funcCount);
  exitg1 = false;
  while ((!exitg1) && (b_exitflag == -5)) {
    double resnormNew;
    int c_loop_ub;
    int d_loop_ub;
    bool evalOK;
    bool guard1{false};
    c_x.set_size(fval.size(0));
    c_loop_ub = fval.size(0);
    for (int i8{0}; i8 < c_loop_ub; i8++) {
      c_x[i8] = -fval[i8];
    }
    for (int d_k{0}; d_k <= m; d_k++) {
      rhs[d_k] = c_x[d_k];
    }
    for (int e_k{0}; e_k < h_n; e_k++) {
      rhs[(m + e_k) + 1] = 0.0;
    }
    optim::coder::levenbergMarquardt::linearLeastSquares(augJacobian, rhs, b_dx,
                                                         m_temp + h_n, h_n);
    xp.set_size(xCurrent.size(0));
    d_loop_ub = xCurrent.size(0);
    for (int i10{0}; i10 < d_loop_ub; i10++) {
      xp[i10] = xCurrent[i10] + b_dx[i10];
    }
    CalculateCost(xp, fun->workspace.calibration.CameraParameters.ImageSize,
                  fun->workspace.calibration.PatternPositions,
                  fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
    for (int g_i{0}; g_i <= m; g_i++) {
      fNew[g_i] = f_temp[g_i];
    }
    resnormNew = 0.0;
    if (m_temp >= 1) {
      for (int f_k{0}; f_k <= m; f_k++) {
        resnormNew += fNew[f_k] * fNew[f_k];
      }
    }
    evalOK = true;
    for (int h_i{0}; h_i < m_temp; h_i++) {
      if (evalOK) {
        double d_x;
        d_x = fNew[h_i];
        if ((std::isinf(d_x)) || (std::isnan(d_x))) {
          evalOK = false;
        }
      } else {
        evalOK = false;
      }
    }
    b_funcCount++;
    guard1 = false;
    if ((resnormNew < b_resnorm) && evalOK) {
      int f_loop_ub;
      bool b_evalOK;
      iter++;
      funDiff = std::abs(resnormNew - b_resnorm) / b_resnorm;
      b_resnorm = resnormNew;
      fval.set_size(fNew.size(0));
      f_loop_ub = fNew.size(0);
      for (int i12{0}; i12 < f_loop_ub; i12++) {
        fval[i12] = fNew[i12];
      }
      b_evalOK = optim::coder::levenbergMarquardt::b_jacobianFiniteDifference(
          augJacobian, fval, &b_funcCount, xp, t2_FiniteDifferenceType,
          &FiniteDifferences, finiteDifferenceRunTimeOptions_TypicalX,
          finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize);
      for (int k_i{0}; k_i < h_n; k_i++) {
        int b_ix0;
        int d_iy0;
        b_ix0 = (m_temp + h_n) * k_i;
        d_iy0 = m_temp * k_i;
        for (int h_k{0}; h_k <= m; h_k++) {
          jacob[d_iy0 + h_k] = augJacobian[b_ix0 + h_k];
        }
      }
      if (b_evalOK) {
        int h_loop_ub;
        xCurrent.set_size(xp.size(0));
        h_loop_ub = xp.size(0);
        for (int i14{0}; i14 < h_loop_ub; i14++) {
          xCurrent[i14] = xp[i14];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        int i_n;
        b_exitflag = 2;
        i_n = m_temp * h_n;
        for (int i_k{0}; i_k < i_n; i_k++) {
          jacob[i_k] = rtNaN;
        }
        exitg1 = true;
      }
    } else {
      int e_loop_ub;
      b_gamma *= 10.0;
      stepSuccessful = false;
      e_loop_ub = jacob.size(1);
      for (int i11{0}; i11 < e_loop_ub; i11++) {
        int g_loop_ub;
        g_loop_ub = jacob.size(0);
        for (int i13{0}; i13 < g_loop_ub; i13++) {
          augJacobian[i13 + (augJacobian.size(0) * i11)] =
              jacob[i13 + (jacob.size(0) * i11)];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      double sqrtGamma;
      int c_exitflag;
      int i_loop_ub;
      sqrtGamma = std::sqrt(b_gamma);
      for (int m_i{0}; m_i < h_n; m_i++) {
        int c_iy0;
        c_iy0 = ((m_temp + h_n) * (m_i + 1)) - h_n;
        for (int g_k{0}; g_k < h_n; g_k++) {
          augJacobian[c_iy0 + g_k] = 0.0;
        }
        augJacobian[(m_temp + m_i) + (augJacobian.size(0) * m_i)] = sqrtGamma;
      }
      internal::blas::xgemv(m_temp, h_n, jacob, m_temp, fval, gradf);
      a__4.set_size(gradf.size(0));
      i_loop_ub = gradf.size(0);
      for (int i15{0}; i15 < i_loop_ub; i15++) {
        a__4[i15] = -gradf[i15];
      }
      c_exitflag = optim::coder::levenbergMarquardt::b_checkStoppingCriteria(
          static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
          funDiff, xCurrent, b_dx, b_funcCount, stepSuccessful, &iter);
      b_exitflag = c_exitflag;
      if (c_exitflag != -5) {
        exitg1 = true;
      }
    }
  }
  b_output_firstorderopt =
      optim::coder::levenbergMarquardt::computeFirstOrderOpt(gradf);
  b_output_stepsize = b_norm(b_dx);
  for (int i7{0}; i7 < 19; i7++) {
    output_algorithm[i7] = b_cv[i7];
  }
  lambda_lower.set_size(x0_size_idx_0);
  lambda_upper.set_size(x0_size_idx_0);
  for (int i9{0}; i9 < x0_size_idx_0; i9++) {
    lambda_lower[i9] = 0.0;
    lambda_upper[i9] = 0.0;
  }
  *resnorm = b_resnorm;
  *exitflag = static_cast<double>(b_exitflag);
  *output_iterations = static_cast<double>(iter);
  *output_funcCount = static_cast<double>(b_funcCount);
  *output_stepsize = b_output_stepsize;
  *output_firstorderopt = b_output_firstorderopt;
}

} // namespace coder

//
// File trailer for lsqnonlin.cpp
//
// [EOF]
//
