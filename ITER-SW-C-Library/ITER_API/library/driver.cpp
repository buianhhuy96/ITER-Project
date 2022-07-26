//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "driver.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types1.h"
#include "ITER_API_internal_types11.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "cameraParameters.h"
#include "checkStoppingCriteria.h"
#include "computeFiniteDifferences.h"
#include "estimateKnucklePose.h"
#include "hasFiniteBounds.h"
#include "linearLeastSquares.h"
#include "projectBox.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
static double b_computeFirstOrderOpt(const double gradf[6],
                                     bool hasFiniteBounds,
                                     const double *projSteepestDescentInfNorm);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

// Function Definitions
//
// Arguments    : const double gradf[6]
//                bool hasFiniteBounds
//                const double *projSteepestDescentInfNorm
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
static double b_computeFirstOrderOpt(const double gradf[6],
                                     bool hasFiniteBounds,
                                     const double *projSteepestDescentInfNorm)
{
  double b_firstOrderOpt;
  if (hasFiniteBounds) {
    double b;
    b = 0.0;
    for (int b_k{0}; b_k < 6; b_k++) {
      double b_absx;
      b_absx = std::abs(gradf[b_k]);
      if (std::isnan(b_absx)) {
        b = b_absx;
      } else if (b_absx > b) {
        b = b_absx;
      } else {
        /* no actions */
      }
    }
    if (std::abs((*projSteepestDescentInfNorm) - b) <
        (2.2204460492503131E-16 * std::fmax(*projSteepestDescentInfNorm, b))) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else if (b == 0.0) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else {
      b_firstOrderOpt =
          ((*projSteepestDescentInfNorm) * (*projSteepestDescentInfNorm)) / b;
    }
  } else {
    b_firstOrderOpt = 0.0;
    for (int k{0}; k < 6; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        b_firstOrderOpt = absx;
      } else if (absx > b_firstOrderOpt) {
        b_firstOrderOpt = absx;
      } else {
        /* no actions */
      }
    }
  }
  return b_firstOrderOpt;
}

//
// Arguments    : const ::coder::array<double, 1U> &gradf
//                bool hasFiniteBounds
//                const double *projSteepestDescentInfNorm
// Return Type  : double
//
double computeFirstOrderOpt(const ::coder::array<double, 1U> &gradf,
                            bool hasFiniteBounds,
                            const double *projSteepestDescentInfNorm)
{
  double b_firstOrderOpt;
  if (hasFiniteBounds) {
    double b;
    if (gradf.size(0) == 0) {
      b = 0.0;
    } else {
      int i1;
      b = 0.0;
      i1 = gradf.size(0);
      for (int b_k{0}; b_k < i1; b_k++) {
        double b_absx;
        b_absx = std::abs(gradf[b_k]);
        if (std::isnan(b_absx)) {
          b = b_absx;
        } else if (b_absx > b) {
          b = b_absx;
        } else {
          /* no actions */
        }
      }
    }
    if (std::abs((*projSteepestDescentInfNorm) - b) <
        (2.2204460492503131E-16 * std::fmax(*projSteepestDescentInfNorm, b))) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else if (b == 0.0) {
      b_firstOrderOpt = *projSteepestDescentInfNorm;
    } else {
      b_firstOrderOpt =
          ((*projSteepestDescentInfNorm) * (*projSteepestDescentInfNorm)) / b;
    }
  } else if (gradf.size(0) == 0) {
    b_firstOrderOpt = 0.0;
  } else {
    int b_i;
    b_firstOrderOpt = 0.0;
    b_i = gradf.size(0);
    for (int k{0}; k < b_i; k++) {
      double absx;
      absx = std::abs(gradf[k]);
      if (std::isnan(absx)) {
        b_firstOrderOpt = absx;
      } else if (absx > b_firstOrderOpt) {
        b_firstOrderOpt = absx;
      } else {
        /* no actions */
      }
    }
  }
  return b_firstOrderOpt;
}

//
// Arguments    : anonymous_function *fun
//                double x0[6]
//                double *resnorm
//                ::coder::array<double, 2U> &fCurrent
//                double *exitflag
//                double *output_iterations
//                double *output_funcCount
//                double *output_stepsize
//                double *output_firstorderopt
//                char output_algorithm[19]
//                double lambda_lower[6]
//                double lambda_upper[6]
//                ::coder::array<double, 2U> &jacobian
// Return Type  : void
//
void driver(anonymous_function *fun, double x0[6], double *resnorm,
            ::coder::array<double, 2U> &fCurrent, double *exitflag,
            double *output_iterations, double *output_funcCount,
            double *output_stepsize, double *output_firstorderopt,
            char output_algorithm[19], double lambda_lower[6],
            double lambda_upper[6], ::coder::array<double, 2U> &jacobian)
{
  c_anonymous_function b_this;
  ::coder::array<double, 2U> JacCeqTrans;
  ::coder::array<double, 2U> augJacobian;
  ::coder::array<double, 2U> e_x;
  ::coder::array<double, 2U> fNew;
  ::coder::array<double, 2U> f_temp;
  ::coder::array<double, 1U> rhs;
  w_struct_T FiniteDifferences;
  w_struct_T b_FiniteDifferences;
  w_struct_T c_FiniteDifferences;
  double a__2[6];
  double a__3[6];
  double a__4[6];
  double b_dx[6];
  double c_a__5[6];
  double gradf[6];
  double xp[6];
  double b_gamma;
  double b_output_firstorderopt;
  double b_output_stepsize;
  double b_projSteepestDescentInfNorm;
  double b_resnorm;
  double funDiff;
  double projSteepestDescentInfNorm;
  double relFactor;
  double scale;
  double tolActive;
  double y;
  int b_exitflag;
  int b_iter;
  int b_loop_ub;
  int b_output_funcCount;
  int b_output_iterations;
  int c_exitflag;
  int funcCount;
  int i1;
  int i4;
  int idx;
  int loop_ub;
  int m;
  int m_temp;
  bool b_bv[6];
  bool hasLB[6];
  bool hasUB[6];
  bool indActive[6];
  bool exitg1;
  bool hasFiniteBounds;
  bool stepSuccessful;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 6; b_i++) {
    indActive[b_i] = false;
    b_dx[b_i] = rtInf;
  }
  funDiff = rtInf;
  b_iter = 0;
  hasFiniteBounds = utils::hasFiniteBounds(hasLB, hasUB);
  if (hasFiniteBounds) {
    d_projectBox(x0, hasLB, hasUB);
  }
  estimateKnucklePose_anonFcn1(fun->workspace.imagePointsTmp,
                               fun->workspace.worldPointsTmp,
                               fun->workspace.cameraParams, x0, f_temp);
  m_temp = f_temp.size(0) * 2;
  jacobian.set_size(m_temp, 6);
  m = m_temp - 1;
  fCurrent.set_size(f_temp.size(0), 2);
  fNew.set_size(f_temp.size(0), 2);
  for (int c_i{0}; c_i <= m; c_i++) {
    fCurrent[c_i] = f_temp[c_i];
  }
  augJacobian.set_size(m_temp + 6, 6);
  loop_ub = m_temp;
  if ((static_cast<int>((6 * m_temp) < 4)) != 0) {
    for (int d_i{0}; d_i < 6; d_i++) {
      for (i1 = 0; i1 < m_temp; i1++) {
        augJacobian[i1 + (augJacobian.size(0) * d_i)] =
            jacobian[i1 + (jacobian.size(0) * d_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int d_i = 0; d_i < 6; d_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        augJacobian[i1 + (augJacobian.size(0) * d_i)] =
            jacobian[i1 + (jacobian.size(0) * d_i)];
      }
    }
  }
  rhs.set_size(m_temp + 6);
  b_resnorm = 0.0;
  if (m_temp >= 1) {
    for (int k{0}; k < m_temp; k++) {
      b_resnorm += fCurrent[k] * fCurrent[k];
    }
  }
  b_this.workspace.fun = *fun;
  FiniteDifferences.nonlin = b_this;
  FiniteDifferences.b_f_1 = 0.0;
  FiniteDifferences.cEq_1.set_size(m_temp);
  FiniteDifferences.f_2 = 0.0;
  FiniteDifferences.cEq_2.set_size(m_temp);
  FiniteDifferences.nVar = 6;
  FiniteDifferences.mIneq = 0;
  FiniteDifferences.mEq = m_temp;
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.SpecifyObjectiveGradient = false;
  FiniteDifferences.SpecifyConstraintGradient = false;
  FiniteDifferences.isEmptyNonlcon = (m_temp == 0);
  FiniteDifferences.FiniteDifferenceType = 0;
  for (int e_i{0}; e_i < 6; e_i++) {
    b_bv[e_i] = FiniteDifferences.hasUB[e_i];
  }
  FiniteDifferences.hasLB[0] = true;
  b_bv[0] = true;
  idx = 1;
  while ((idx + 1) <= 6) {
    FiniteDifferences.hasLB[idx] = true;
    b_bv[idx] = true;
    idx++;
  }
  for (int g_i{0}; g_i < 6; g_i++) {
    FiniteDifferences.hasUB[g_i] = b_bv[g_i];
  }
  FiniteDifferences.hasBounds = true;
  JacCeqTrans.set_size(6, fCurrent.size(0) * 2);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i2 = 0; i2 < 6; i2++) {
    a__3[i2] = x0[i2];
  }
  b_FiniteDifferences = FiniteDifferences;
  (void)utils::FiniteDifferences::computeFiniteDifferences(
      &b_FiniteDifferences, fCurrent, a__3, JacCeqTrans);
  b_loop_ub = JacCeqTrans.size(1);
  if ((static_cast<int>((6 * JacCeqTrans.size(1)) < 4)) != 0) {
    for (int i3{0}; i3 < 6; i3++) {
      for (i4 = 0; i4 < b_loop_ub; i4++) {
        augJacobian[i4 + (augJacobian.size(0) * i3)] =
            JacCeqTrans[i3 + (6 * i4)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int i3 = 0; i3 < 6; i3++) {
      for (i4 = 0; i4 < b_loop_ub; i4++) {
        augJacobian[i4 + (augJacobian.size(0) * i3)] =
            JacCeqTrans[i3 + (6 * i4)];
      }
    }
  }
  funcCount = b_FiniteDifferences.numEvals + 1;
  b_gamma = 0.01;
  for (int h_i{0}; h_i < 6; h_i++) {
    int b_iy0;
    int ix0;
    int iy0;
    iy0 = (m_temp + 6) * (h_i + 1);
    for (int b_k{0}; b_k < 6; b_k++) {
      augJacobian[(iy0 + b_k) - 6] = 0.0;
    }
    augJacobian[(m_temp + h_i) + (augJacobian.size(0) * h_i)] = 0.1;
    ix0 = (m_temp + 6) * h_i;
    b_iy0 = m_temp * h_i;
    for (int c_k{0}; c_k <= m; c_k++) {
      jacobian[b_iy0 + c_k] = augJacobian[ix0 + c_k];
    }
  }
  internal::blas::c_xgemv(m_temp, jacobian, m_temp, fCurrent, gradf);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int k_i = 0; k_i < 6; k_i++) {
    a__2[k_i] = -gradf[k_i];
  }
  double b_x;
  projSteepestDescentInfNorm = e_projectBox(x0, a__2, hasLB, hasUB);
  b_x = b_computeFirstOrderOpt(gradf, hasFiniteBounds,
                               &projSteepestDescentInfNorm);
  b_projSteepestDescentInfNorm = projSteepestDescentInfNorm;
  relFactor = std::fmax(b_x, 1.4901161193847656E-8);
  stepSuccessful = true;
  b_exitflag = checkStoppingCriteria(
      gradf, relFactor, x0, b_FiniteDifferences.numEvals + 1,
      projSteepestDescentInfNorm, hasFiniteBounds);
  exitg1 = false;
  while ((!exitg1) && (b_exitflag == -5)) {
    double resnormNew;
    int c_loop_ub;
    bool evalOK;
    bool guard1{false};
    e_x.set_size(fCurrent.size(0), 2);
    c_loop_ub = fCurrent.size(0);
    for (int i5{0}; i5 < 2; i5++) {
      for (int i6{0}; i6 < c_loop_ub; i6++) {
        e_x[i6 + (e_x.size(0) * i5)] = -fCurrent[i6 + (fCurrent.size(0) * i5)];
      }
    }
    for (int d_k{0}; d_k <= m; d_k++) {
      rhs[d_k] = e_x[d_k];
    }
    for (int g_k{0}; g_k < 6; g_k++) {
      rhs[m_temp + g_k] = 0.0;
    }
    if (hasFiniteBounds) {
      for (int h_k{0}; h_k < 6; h_k++) {
        a__3[h_k] = (-gradf[h_k]) / (b_gamma + 1.0);
      }
      double c_projSteepestDescentInfNorm;
      c_projSteepestDescentInfNorm = e_projectBox(x0, a__3, hasLB, hasUB);
      b_projSteepestDescentInfNorm = c_projSteepestDescentInfNorm;
      tolActive = std::fmin(c_projSteepestDescentInfNorm, rtInf);
      for (int w_i{0}; w_i < 6; w_i++) {
        if (hasLB[w_i]) {
          if (((x0[w_i] - -1.7976931348623157E+308) <= tolActive) &&
              (gradf[w_i] > 0.0)) {
            indActive[w_i] = true;
          } else {
            indActive[w_i] = false;
          }
        }
        if (hasUB[w_i]) {
          if ((indActive[w_i]) ||
              (((1.7976931348623157E+308 - x0[w_i]) <= tolActive) &&
               (gradf[w_i] < 0.0))) {
            indActive[w_i] = true;
          } else {
            indActive[w_i] = false;
          }
        }
        if (indActive[w_i]) {
          int c_iy0;
          c_iy0 = (m_temp + 6) * w_i;
          for (int j_k{0}; j_k <= m; j_k++) {
            augJacobian[c_iy0 + j_k] = 0.0;
          }
        }
      }
    }
    b_linearLeastSquares(augJacobian, rhs, b_dx, m_temp + 6);
    if (hasFiniteBounds) {
      for (int q_i{0}; q_i < 6; q_i++) {
        if (indActive[q_i]) {
          b_dx[q_i] = (-gradf[q_i]) / (b_gamma + 1.0);
        }
        xp[q_i] = x0[q_i] + b_dx[q_i];
      }
      d_projectBox(xp, hasLB, hasUB);
    } else {
      for (int b_i8{0}; b_i8 < 6; b_i8++) {
        xp[b_i8] = x0[b_i8] + b_dx[b_i8];
      }
    }
    estimateKnucklePose_anonFcn1(fun->workspace.imagePointsTmp,
                                 fun->workspace.worldPointsTmp,
                                 fun->workspace.cameraParams, xp, f_temp);
    for (int gb_i{0}; gb_i <= m; gb_i++) {
      fNew[gb_i] = f_temp[gb_i];
    }
    resnormNew = 0.0;
    if (m_temp >= 1) {
      for (int i_k{0}; i_k < m_temp; i_k++) {
        resnormNew += fNew[i_k] * fNew[i_k];
      }
    }
    evalOK = true;
    for (int kb_i{0}; kb_i < m_temp; kb_i++) {
      if (evalOK) {
        if ((std::isinf(fNew[kb_i])) || (std::isnan(fNew[kb_i]))) {
          evalOK = false;
        }
      } else {
        evalOK = false;
      }
    }
    funcCount++;
    guard1 = false;
    if ((resnormNew < b_resnorm) && evalOK) {
      int e_loop_ub;
      int f_loop_ub;
      bool b_evalOK;
      b_iter++;
      funDiff = std::abs(resnormNew - b_resnorm) / b_resnorm;
      b_resnorm = resnormNew;
      fCurrent.set_size(fNew.size(0), 2);
      e_loop_ub = fNew.size(0);
      for (int i11{0}; i11 < 2; i11++) {
        for (int i12{0}; i12 < e_loop_ub; i12++) {
          fCurrent[i12 + (fCurrent.size(0) * i11)] =
              fNew[i12 + (fNew.size(0) * i11)];
        }
      }
      JacCeqTrans.set_size(6, fNew.size(0) * 2);
      for (int i13{0}; i13 < 6; i13++) {
        a__3[i13] = xp[i13];
      }
      c_FiniteDifferences = b_FiniteDifferences;
      b_evalOK = utils::FiniteDifferences::computeFiniteDifferences(
          &c_FiniteDifferences, fNew, a__3, JacCeqTrans);
      funcCount += c_FiniteDifferences.numEvals;
      f_loop_ub = JacCeqTrans.size(1);
      for (int i14{0}; i14 < 6; i14++) {
        for (int i15{0}; i15 < f_loop_ub; i15++) {
          augJacobian[i15 + (augJacobian.size(0) * i14)] =
              JacCeqTrans[i14 + (6 * i15)];
        }
      }
      for (int pb_i{0}; pb_i < 6; pb_i++) {
        int b_ix0;
        int e_iy0;
        b_ix0 = (m_temp + 6) * pb_i;
        e_iy0 = m_temp * pb_i;
        for (int m_k{0}; m_k <= m; m_k++) {
          jacobian[e_iy0 + m_k] = augJacobian[b_ix0 + m_k];
        }
      }
      if (b_evalOK) {
        for (int i16{0}; i16 < 6; i16++) {
          x0[i16] = xp[i16];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        int h_n;
        b_exitflag = 2;
        h_n = m_temp * 6;
        if ((static_cast<int>(h_n < 4)) != 0) {
          for (int o_k{0}; o_k < h_n; o_k++) {
            jacobian[o_k] = rtNaN;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int o_k = 0; o_k < h_n; o_k++) {
            jacobian[o_k] = rtNaN;
          }
        }
        exitg1 = true;
      }
    } else {
      int d_loop_ub;
      b_gamma *= 10.0;
      stepSuccessful = false;
      d_loop_ub = jacobian.size(0);
      for (int i9{0}; i9 < 6; i9++) {
        for (int i10{0}; i10 < d_loop_ub; i10++) {
          augJacobian[i10 + (augJacobian.size(0) * i9)] =
              jacobian[i10 + (jacobian.size(0) * i9)];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      double sqrtGamma;
      int d_exitflag;
      sqrtGamma = std::sqrt(b_gamma);
      for (int mb_i{0}; mb_i < 6; mb_i++) {
        int d_iy0;
        d_iy0 = (m_temp + 6) * (mb_i + 1);
        for (int k_k{0}; k_k < 6; k_k++) {
          augJacobian[(d_iy0 + k_k) - 6] = 0.0;
        }
        augJacobian[(m_temp + mb_i) + (augJacobian.size(0) * mb_i)] = sqrtGamma;
      }
      internal::blas::c_xgemv(m_temp, jacobian, m_temp, fCurrent, gradf);
      for (int ob_i{0}; ob_i < 6; ob_i++) {
        a__4[ob_i] = -gradf[ob_i];
      }
      double d_projSteepestDescentInfNorm;
      d_projSteepestDescentInfNorm = e_projectBox(x0, a__4, hasLB, hasUB);
      b_projSteepestDescentInfNorm = d_projSteepestDescentInfNorm;
      d_exitflag = b_checkStoppingCriteria(
          gradf, relFactor, funDiff, x0, b_dx, funcCount, stepSuccessful,
          &b_iter, d_projSteepestDescentInfNorm, hasFiniteBounds);
      b_exitflag = d_exitflag;
      if (d_exitflag != -5) {
        exitg1 = true;
      }
    }
  }
  c_exitflag = b_exitflag;
  b_output_firstorderopt = b_computeFirstOrderOpt(
      gradf, hasFiniteBounds, &b_projSteepestDescentInfNorm);
  b_output_iterations = b_iter;
  b_output_funcCount = funcCount;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int e_k{0}; e_k < 6; e_k++) {
    double absxk;
    absxk = std::abs(b_dx[e_k]);
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
  }
  b_output_stepsize = scale * std::sqrt(y);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i7 = 0; i7 < 19; i7++) {
    output_algorithm[i7] = cv[i7];
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int m_i = 0; m_i < 6; m_i++) {
    lambda_lower[m_i] = 0.0;
    lambda_upper[m_i] = 0.0;
  }
  if (hasFiniteBounds) {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int t_i = 0; t_i < 6; t_i++) {
      c_a__5[t_i] = (-gradf[t_i]) / (b_gamma + 1.0);
    }
    double g_x;
    g_x = e_projectBox(x0, c_a__5, hasLB, hasUB);
    tolActive = std::fmin(g_x, rtInf);
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int jb_i = 0; jb_i < 6; jb_i++) {
      if (((hasLB[jb_i]) &&
           ((x0[jb_i] - -1.7976931348623157E+308) <= tolActive)) &&
          (gradf[jb_i] > 0.0)) {
        lambda_lower[jb_i] = 2.0 * gradf[jb_i];
      }
      if (((hasUB[jb_i]) &&
           ((1.7976931348623157E+308 - x0[jb_i]) <= tolActive)) &&
          (gradf[jb_i] < 0.0)) {
        lambda_upper[jb_i] = -2.0 * gradf[jb_i];
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

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for driver.cpp
//
// [EOF]
//
