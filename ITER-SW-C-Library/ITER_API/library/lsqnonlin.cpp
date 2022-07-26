//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: lsqnonlin.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "lsqnonlin.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types1.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera.h"
#include "checkStoppingCriteria.h"
#include "driver.h"
#include "factoryConstruct.h"
#include "hasFiniteBounds.h"
#include "jacobianFiniteDifference.h"
#include "linearLeastSquares.h"
#include "minOrMax.h"
#include "norm.h"
#include "power.h"
#include "projectBox.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const d_anonymous_function *fun
//                ::coder::array<double, 1U> &xCurrent
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
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
namespace ITER {
namespace coder {
void lsqnonlin(
    const d_anonymous_function *fun, ::coder::array<double, 1U> &xCurrent,
    const ::coder::array<double, 1U> &lb, const ::coder::array<double, 1U> &ub,
    double *resnorm, ::coder::array<double, 1U> &fval, double *exitflag,
    double *output_iterations, double *output_funcCount,
    double *output_stepsize, double *output_firstorderopt,
    char output_algorithm[19], ::coder::array<double, 1U> &lambda_lower,
    ::coder::array<double, 1U> &lambda_upper, ::coder::array<double, 2U> &jacob)
{
  static const char t8_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                               'a', 'r', 'd'};
  e_anonymous_function b_this;
  ::coder::array<double, 2U> augJacobian;
  ::coder::array<double, 1U> a__2;
  ::coder::array<double, 1U> a__3;
  ::coder::array<double, 1U> a__4;
  ::coder::array<double, 1U> b_dx;
  ::coder::array<double, 1U> b_ub;
  ::coder::array<double, 1U> c_a__5;
  ::coder::array<double, 1U> e_x;
  ::coder::array<double, 1U> fNew;
  ::coder::array<double, 1U> f_temp;
  ::coder::array<double, 1U>
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize;
  ::coder::array<double, 1U> finiteDifferenceRunTimeOptions_TypicalX;
  ::coder::array<double, 1U> gradf;
  ::coder::array<double, 1U> maxval;
  ::coder::array<double, 1U> r;
  ::coder::array<double, 1U> rhs;
  ::coder::array<double, 1U> scaleFactors;
  ::coder::array<double, 1U> varargin_2;
  ::coder::array<double, 1U> xp;
  ::coder::array<bool, 1U> hasLB;
  ::coder::array<bool, 1U> hasUB;
  ::coder::array<bool, 1U> indActive;
  ab_struct_T FiniteDifferences;
  double b_gamma;
  double b_output_firstorderopt;
  double b_output_stepsize;
  double b_projSteepestDescentInfNorm;
  double b_resnorm;
  double b_x;
  double funDiff;
  double minWidth;
  double projSteepestDescentInfNorm;
  double relFactor;
  double tolActive;
  int b_exitflag;
  int b_funcCount;
  int b_iter;
  int b_loop_ub;
  int b_output_funcCount;
  int b_output_iterations;
  int c_exitflag;
  int c_loop_ub;
  int f_loop_ub;
  int funcCount;
  int g_loop_ub;
  int h_loop_ub;
  int h_n;
  int i6;
  int i_loop_ub;
  int j_loop_ub;
  int loop_ub;
  int m;
  int m_loop_ub;
  int m_temp;
  int options_MaxFunctionEvaluations;
  int p_loop_ub;
  unsigned int unnamed_idx_0;
  int varargin_1_idx_0;
  int x0_size_idx_0;
  int xCurrent_idx_0;
  bool a__1;
  bool exitg1;
  bool hasFiniteBounds;
  bool stepSuccessful;
  x0_size_idx_0 = xCurrent.size(0);
  h_n = xCurrent.size(0);
  xCurrent_idx_0 = xCurrent.size(0);
  indActive.set_size(xCurrent_idx_0);
  loop_ub = xCurrent_idx_0;
  if ((static_cast<int>(xCurrent_idx_0 < 4)) != 0) {
    for (int b_i{0}; b_i < xCurrent_idx_0; b_i++) {
      indActive[b_i] = false;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      indActive[b_i] = false;
    }
  }
  gradf.set_size(xCurrent.size(0));
  unnamed_idx_0 = static_cast<unsigned int>(xCurrent.size(0));
  varargin_1_idx_0 = xCurrent.size(0);
  b_dx.set_size(varargin_1_idx_0);
  b_loop_ub = varargin_1_idx_0;
  if ((static_cast<int>(xCurrent.size(0) < 4)) != 0) {
    for (int i1{0}; i1 < varargin_1_idx_0; i1++) {
      b_dx[i1] = rtInf;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < b_loop_ub; i1++) {
      b_dx[i1] = rtInf;
    }
  }
  funDiff = rtInf;
  xCurrent_idx_0 = xCurrent.size(0);
  scaleFactors.set_size(xCurrent_idx_0);
  c_loop_ub = xCurrent_idx_0;
  if ((static_cast<int>(xCurrent_idx_0 < 4)) != 0) {
    for (int i2{0}; i2 < xCurrent_idx_0; i2++) {
      scaleFactors[i2] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      scaleFactors[i2] = 1.0;
    }
  }
  b_iter = 0;
  options_MaxFunctionEvaluations = 200 * xCurrent.size(0);
  if (lb.size(0) != 0) {
    if (ub.size(0) != 0) {
      int d_loop_ub;
      b_ub.set_size(ub.size(0));
      d_loop_ub = ub.size(0);
      if ((static_cast<int>(ub.size(0) < 4)) != 0) {
        for (int i3{0}; i3 < d_loop_ub; i3++) {
          b_ub[i3] = ub[i3] - lb[i3];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i3 = 0; i3 < d_loop_ub; i3++) {
          b_ub[i3] = ub[i3] - lb[i3];
        }
      }
      minWidth = internal::d_minimum(b_ub);
    } else {
      minWidth = rtInf;
    }
  } else {
    minWidth = rtInf;
  }
  hasLB.set_size(xCurrent.size(0));
  hasUB.set_size(xCurrent.size(0));
  hasFiniteBounds = optim::coder::utils::b_hasFiniteBounds(
      xCurrent.size(0), hasLB, hasUB, lb, ub);
  if (hasFiniteBounds && (!(minWidth < 0.0))) {
    int e_loop_ub;
    r.set_size(static_cast<int>(unnamed_idx_0));
    e_loop_ub = static_cast<int>(unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
      for (int i4{0}; i4 < e_loop_ub; i4++) {
        r[i4] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < e_loop_ub; i4++) {
        r[i4] = 0.0;
      }
    }
    optim::coder::levenbergMarquardt::projectBox(r, xCurrent, lb, ub, hasLB,
                                                 hasUB);
  }
  reprojectWrapper(xCurrent, &fun->workspace.initialParams,
                   fun->workspace.b_world_points, fun->workspace.image_points,
                   f_temp);
  m_temp = f_temp.size(0);
  jacob.set_size(f_temp.size(0), x0_size_idx_0);
  m = f_temp.size(0) - 1;
  fval.set_size(f_temp.size(0));
  fNew.set_size(f_temp.size(0));
  if ((static_cast<int>(f_temp.size(0) < 4)) != 0) {
    for (int c_i{0}; c_i <= m; c_i++) {
      fval[c_i] = f_temp[c_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i <= m; c_i++) {
      fval[c_i] = f_temp[c_i];
    }
  }
  augJacobian.set_size(f_temp.size(0) + x0_size_idx_0, x0_size_idx_0);
  f_loop_ub = jacob.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    g_loop_ub)

  for (int i5 = 0; i5 < f_loop_ub; i5++) {
    g_loop_ub = jacob.size(0);
    for (i6 = 0; i6 < g_loop_ub; i6++) {
      augJacobian[i6 + (augJacobian.size(0) * i5)] =
          jacob[i6 + (jacob.size(0) * i5)];
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
      &b_this, x0_size_idx_0, f_temp.size(0), lb, ub, t8_FiniteDifferenceType,
      &FiniteDifferences);
  finiteDifferenceRunTimeOptions_TypicalX.set_size(x0_size_idx_0);
  h_loop_ub = x0_size_idx_0;
  if ((static_cast<int>(x0_size_idx_0 < 4)) != 0) {
    for (int i7{0}; i7 < x0_size_idx_0; i7++) {
      finiteDifferenceRunTimeOptions_TypicalX[i7] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < h_loop_ub; i7++) {
      finiteDifferenceRunTimeOptions_TypicalX[i7] = 1.0;
    }
  }
  finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize.set_size(
      x0_size_idx_0);
  i_loop_ub = x0_size_idx_0;
  if ((static_cast<int>(x0_size_idx_0 < 4)) != 0) {
    for (int b_i8{0}; b_i8 < x0_size_idx_0; b_i8++) {
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize[b_i8] =
          1.4901161193847656E-8;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < i_loop_ub; b_i8++) {
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize[b_i8] =
          1.4901161193847656E-8;
    }
  }
  optim::coder::levenbergMarquardt::jacobianFiniteDifference(
      augJacobian, fval, xCurrent, lb, ub, t8_FiniteDifferenceType,
      &FiniteDifferences, finiteDifferenceRunTimeOptions_TypicalX,
      finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize, &funcCount,
      &a__1);
  b_funcCount = funcCount;
  b_gamma = 0.01;
  for (int d_i{0}; d_i < h_n; d_i++) {
    int b_iy0;
    int ix0;
    int iy0;
    int iy0_tmp;
    iy0_tmp = m_temp + h_n;
    iy0 = (iy0_tmp * (d_i + 1)) - h_n;
    for (int b_k{0}; b_k < h_n; b_k++) {
      augJacobian[iy0 + b_k] = 0.0;
    }
    augJacobian[(m_temp + d_i) + (augJacobian.size(0) * d_i)] = 0.1;
    ix0 = iy0_tmp * d_i;
    b_iy0 = m_temp * d_i;
    for (int c_k{0}; c_k <= m; c_k++) {
      jacob[b_iy0 + c_k] = augJacobian[ix0 + c_k];
    }
  }
  internal::blas::b_xgemv(f_temp.size(0), x0_size_idx_0, jacob, f_temp.size(0),
                          fval, gradf);
  a__2.set_size(gradf.size(0));
  j_loop_ub = gradf.size(0);
  if ((static_cast<int>(gradf.size(0) < 4)) != 0) {
    for (int i9{0}; i9 < j_loop_ub; i9++) {
      a__2[i9] = -gradf[i9];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i9 = 0; i9 < j_loop_ub; i9++) {
      a__2[i9] = -gradf[i9];
    }
  }
  projSteepestDescentInfNorm = optim::coder::levenbergMarquardt::b_projectBox(
      xCurrent, a__2, lb, ub, hasLB, hasUB);
  b_x = optim::coder::levenbergMarquardt::computeFirstOrderOpt(
      gradf, hasFiniteBounds, &projSteepestDescentInfNorm);
  b_projSteepestDescentInfNorm = projSteepestDescentInfNorm;
  relFactor = std::fmax(b_x, 1.4901161193847656E-8);
  stepSuccessful = true;
  if (minWidth < 0.0) {
    b_exitflag = -2;
  } else {
    b_exitflag = optim::coder::levenbergMarquardt::d_checkStoppingCriteria(
        static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
        xCurrent, b_dx, funcCount, projSteepestDescentInfNorm, hasFiniteBounds);
  }
  exitg1 = false;
  while ((!exitg1) && (b_exitflag == -5)) {
    double resnormNew;
    int k_loop_ub;
    bool evalOK;
    bool guard1{false};
    e_x.set_size(fval.size(0));
    k_loop_ub = fval.size(0);
    for (int i10{0}; i10 < k_loop_ub; i10++) {
      e_x[i10] = -fval[i10];
    }
    for (int d_k{0}; d_k <= m; d_k++) {
      rhs[d_k] = e_x[d_k];
    }
    for (int e_k{0}; e_k < h_n; e_k++) {
      rhs[(m + e_k) + 1] = 0.0;
    }
    if (hasFiniteBounds) {
      int i_N;
      int r_loop_ub;
      power(scaleFactors, varargin_2);
      maxval.set_size(varargin_2.size(0));
      i_N = varargin_2.size(0);
      for (int g_k{0}; g_k < i_N; g_k++) {
        maxval[g_k] = std::fmax(2.2204460492503131E-16, varargin_2[g_k]);
      }
      a__3.set_size(gradf.size(0));
      r_loop_ub = gradf.size(0);
      for (int i16{0}; i16 < r_loop_ub; i16++) {
        a__3[i16] = ((-gradf[i16]) / (b_gamma + 1.0)) / maxval[i16];
      }
      double c_projSteepestDescentInfNorm;
      c_projSteepestDescentInfNorm =
          optim::coder::levenbergMarquardt::b_projectBox(xCurrent, a__3, lb, ub,
                                                         hasLB, hasUB);
      b_projSteepestDescentInfNorm = c_projSteepestDescentInfNorm;
      tolActive = std::fmin(c_projSteepestDescentInfNorm, minWidth / 2.0);
      for (int h_i{0}; h_i < h_n; h_i++) {
        if (hasLB[h_i]) {
          if ((xCurrent[h_i] - lb[h_i]) <= tolActive) {
            if (gradf[h_i] > 0.0) {
              indActive[h_i] = true;
            } else {
              indActive[h_i] = false;
            }
          } else {
            indActive[h_i] = false;
          }
        }
        if (hasUB[h_i]) {
          if (indActive[h_i]) {
            indActive[h_i] = true;
          } else if ((ub[h_i] - xCurrent[h_i]) <= tolActive) {
            if (gradf[h_i] < 0.0) {
              indActive[h_i] = true;
            } else {
              indActive[h_i] = false;
            }
          } else {
            indActive[h_i] = false;
          }
        }
        if (indActive[h_i]) {
          int c_iy0;
          c_iy0 = (m_temp + h_n) * h_i;
          for (int j_k{0}; j_k <= m; j_k++) {
            augJacobian[c_iy0 + j_k] = 0.0;
          }
        }
      }
    }
    optim::coder::levenbergMarquardt::linearLeastSquares(augJacobian, rhs, b_dx,
                                                         m_temp + h_n, h_n);
    if (hasFiniteBounds) {
      int q_loop_ub;
      for (int e_i{0}; e_i < h_n; e_i++) {
        if (indActive[e_i]) {
          b_dx[e_i] = (-gradf[e_i]) / (b_gamma + 1.0);
        }
      }
      xp.set_size(xCurrent.size(0));
      q_loop_ub = xCurrent.size(0);
      for (int i15{0}; i15 < q_loop_ub; i15++) {
        xp[i15] = xCurrent[i15] + b_dx[i15];
      }
      optim::coder::levenbergMarquardt::c_projectBox(xp, lb, ub, hasLB, hasUB);
    } else {
      int o_loop_ub;
      xp.set_size(xCurrent.size(0));
      o_loop_ub = xCurrent.size(0);
      for (int i13{0}; i13 < o_loop_ub; i13++) {
        xp[i13] = xCurrent[i13] + b_dx[i13];
      }
    }
    reprojectWrapper(xp, &fun->workspace.initialParams,
                     fun->workspace.b_world_points, fun->workspace.image_points,
                     f_temp);
    for (int g_i{0}; g_i <= m; g_i++) {
      fNew[g_i] = f_temp[g_i];
    }
    resnormNew = 0.0;
    if (m_temp >= 1) {
      for (int h_k{0}; h_k <= m; h_k++) {
        resnormNew += fNew[h_k] * fNew[h_k];
      }
    }
    evalOK = true;
    for (int k_i{0}; k_i < m_temp; k_i++) {
      if (evalOK) {
        double g_x;
        g_x = fNew[k_i];
        if ((std::isinf(g_x)) || (std::isnan(g_x))) {
          evalOK = false;
        }
      } else {
        evalOK = false;
      }
    }
    b_funcCount++;
    guard1 = false;
    if ((resnormNew < b_resnorm) && evalOK) {
      int u_loop_ub;
      bool b_evalOK;
      b_iter++;
      funDiff = std::abs(resnormNew - b_resnorm) / b_resnorm;
      b_resnorm = resnormNew;
      fval.set_size(fNew.size(0));
      u_loop_ub = fNew.size(0);
      for (int i19{0}; i19 < u_loop_ub; i19++) {
        fval[i19] = fNew[i19];
      }
      b_evalOK = optim::coder::levenbergMarquardt::b_jacobianFiniteDifference(
          augJacobian, fval, &b_funcCount, xp, lb, ub, t8_FiniteDifferenceType,
          &FiniteDifferences, finiteDifferenceRunTimeOptions_TypicalX,
          finiteDifferenceRunTimeOptions_FiniteDifferenceStepSize);
      for (int q_i{0}; q_i < h_n; q_i++) {
        int b_ix0;
        int e_iy0;
        b_ix0 = (m_temp + h_n) * q_i;
        e_iy0 = m_temp * q_i;
        for (int m_k{0}; m_k <= m; m_k++) {
          jacob[e_iy0 + m_k] = augJacobian[b_ix0 + m_k];
        }
      }
      if (b_evalOK) {
        int w_loop_ub;
        xCurrent.set_size(xp.size(0));
        w_loop_ub = xp.size(0);
        for (int i21{0}; i21 < w_loop_ub; i21++) {
          xCurrent[i21] = xp[i21];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        int p_n;
        b_exitflag = 2;
        p_n = m_temp * h_n;
        if ((static_cast<int>(p_n < 4)) != 0) {
          for (int o_k{0}; o_k < p_n; o_k++) {
            jacob[o_k] = rtNaN;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int o_k = 0; o_k < p_n; o_k++) {
            jacob[o_k] = rtNaN;
          }
        }
        exitg1 = true;
      }
    } else {
      int t_loop_ub;
      b_gamma *= 10.0;
      stepSuccessful = false;
      t_loop_ub = jacob.size(1);
      for (int i18{0}; i18 < t_loop_ub; i18++) {
        int v_loop_ub;
        v_loop_ub = jacob.size(0);
        for (int i20{0}; i20 < v_loop_ub; i20++) {
          augJacobian[i20 + (augJacobian.size(0) * i18)] =
              jacob[i20 + (jacob.size(0) * i18)];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      double sqrtGamma;
      int d_exitflag;
      int x_loop_ub;
      sqrtGamma = std::sqrt(b_gamma);
      for (int t_i{0}; t_i < h_n; t_i++) {
        int d_iy0;
        d_iy0 = ((m_temp + h_n) * (t_i + 1)) - h_n;
        for (int k_k{0}; k_k < h_n; k_k++) {
          augJacobian[d_iy0 + k_k] = 0.0;
        }
        augJacobian[(m_temp + t_i) + (augJacobian.size(0) * t_i)] = sqrtGamma;
      }
      internal::blas::b_xgemv(m_temp, h_n, jacob, m_temp, fval, gradf);
      a__4.set_size(gradf.size(0));
      x_loop_ub = gradf.size(0);
      for (int i22{0}; i22 < x_loop_ub; i22++) {
        a__4[i22] = -gradf[i22];
      }
      double d_projSteepestDescentInfNorm;
      d_projSteepestDescentInfNorm =
          optim::coder::levenbergMarquardt::b_projectBox(xCurrent, a__4, lb, ub,
                                                         hasLB, hasUB);
      b_projSteepestDescentInfNorm = d_projSteepestDescentInfNorm;
      d_exitflag = optim::coder::levenbergMarquardt::c_checkStoppingCriteria(
          static_cast<double>(options_MaxFunctionEvaluations), gradf, relFactor,
          funDiff, xCurrent, b_dx, b_funcCount, stepSuccessful, &b_iter,
          d_projSteepestDescentInfNorm, hasFiniteBounds);
      b_exitflag = d_exitflag;
      if (d_exitflag != -5) {
        exitg1 = true;
      }
    }
  }
  c_exitflag = b_exitflag;
  b_output_firstorderopt =
      optim::coder::levenbergMarquardt::computeFirstOrderOpt(
          gradf, hasFiniteBounds, &b_projSteepestDescentInfNorm);
  b_output_iterations = b_iter;
  b_output_funcCount = b_funcCount;
  b_output_stepsize = b_norm(b_dx);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i11 = 0; i11 < 19; i11++) {
    output_algorithm[i11] = cv[i11];
  }
  lambda_lower.set_size(x0_size_idx_0);
  m_loop_ub = x0_size_idx_0;
  if ((static_cast<int>(x0_size_idx_0 < 4)) != 0) {
    for (int i12{0}; i12 < x0_size_idx_0; i12++) {
      lambda_lower[i12] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i12 = 0; i12 < m_loop_ub; i12++) {
      lambda_lower[i12] = 0.0;
    }
  }
  lambda_upper.set_size(x0_size_idx_0);
  p_loop_ub = x0_size_idx_0;
  if ((static_cast<int>(x0_size_idx_0 < 4)) != 0) {
    for (int i14{0}; i14 < x0_size_idx_0; i14++) {
      lambda_upper[i14] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < p_loop_ub; i14++) {
      lambda_upper[i14] = 0.0;
    }
  }
  if (hasFiniteBounds) {
    double c_gamma;
    double i_x;
    int k_N;
    int s_loop_ub;
    power(scaleFactors, varargin_2);
    maxval.set_size(varargin_2.size(0));
    k_N = varargin_2.size(0);
    if ((static_cast<int>(varargin_2.size(0) < 4)) != 0) {
      for (int i_k{0}; i_k < k_N; i_k++) {
        maxval[i_k] = std::fmax(2.2204460492503131E-16, varargin_2[i_k]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i_k = 0; i_k < k_N; i_k++) {
        maxval[i_k] = std::fmax(2.2204460492503131E-16, varargin_2[i_k]);
      }
    }
    c_gamma = b_gamma + 1.0;
    c_a__5.set_size(gradf.size(0));
    s_loop_ub = gradf.size(0);
    if ((static_cast<int>(gradf.size(0) < 4)) != 0) {
      for (int i17{0}; i17 < s_loop_ub; i17++) {
        c_a__5[i17] = ((-gradf[i17]) / (b_gamma + 1.0)) / maxval[i17];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i17 = 0; i17 < s_loop_ub; i17++) {
        c_a__5[i17] = ((-gradf[i17]) / c_gamma) / maxval[i17];
      }
    }
    i_x = optim::coder::levenbergMarquardt::b_projectBox(xCurrent, c_a__5, lb,
                                                         ub, hasLB, hasUB);
    tolActive = std::fmin(i_x, minWidth / 2.0);
    if ((static_cast<int>(h_n < 4)) != 0) {
      for (int m_i{0}; m_i < h_n; m_i++) {
        if (hasLB[m_i]) {
          if ((xCurrent[m_i] - lb[m_i]) <= tolActive) {
            if (gradf[m_i] > 0.0) {
              lambda_lower[m_i] = 2.0 * gradf[m_i];
            }
          }
        }
        if (hasUB[m_i]) {
          if ((ub[m_i] - xCurrent[m_i]) <= tolActive) {
            if (gradf[m_i] < 0.0) {
              lambda_upper[m_i] = -2.0 * gradf[m_i];
            }
          }
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int m_i = 0; m_i < h_n; m_i++) {
        if (hasLB[m_i]) {
          if ((xCurrent[m_i] - lb[m_i]) <= tolActive) {
            if (gradf[m_i] > 0.0) {
              lambda_lower[m_i] = 2.0 * gradf[m_i];
            }
          }
        }
        if (hasUB[m_i]) {
          if ((ub[m_i] - xCurrent[m_i]) <= tolActive) {
            if (gradf[m_i] < 0.0) {
              lambda_upper[m_i] = -2.0 * gradf[m_i];
            }
          }
        }
      }
    }
  }
  *resnorm = b_resnorm;
  *exitflag = static_cast<double>(c_exitflag);
  *output_iterations = static_cast<double>(b_output_iterations);
  *output_funcCount = static_cast<double>(b_output_funcCount);
  *output_stepsize = b_output_stepsize;
  *output_firstorderopt = b_output_firstorderopt;
}

} // namespace coder
} // namespace ITER

//
// File trailer for lsqnonlin.cpp
//
// [EOF]
//
