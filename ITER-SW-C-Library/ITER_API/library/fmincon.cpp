//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fmincon.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "fmincon.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types1.h"
#include "anonymous_function.h"
#include "computeForwardDifferences.h"
#include "driver2.h"
#include "optimizeCamPose.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : const b_anonymous_function *fun
//                const double x0[7]
//                double b_x[7]
// Return Type  : void
//
namespace ITER {
namespace coder {
void fmincon(const b_anonymous_function *fun, const double x0[7], double b_x[7])
{
  static const signed char b_iv[8]{1, 2, 3, 4, 5, 6, 7, 0};
  static const signed char t5_indexLB[8]{1, 2, 3, 4, 5, 6, 7, 0};
  static const signed char t5_indexUB[8]{1, 2, 3, 4, 5, 6, 7, 0};
  static const signed char t5_isActiveIdx[6]{1, 1, 1, 1, 8, 15};
  static const signed char t5_isActiveIdxNormal[6]{1, 1, 1, 1, 8, 15};
  static const signed char t5_isActiveIdxPhaseOne[6]{1, 1, 1, 1, 9, 16};
  static const signed char t5_isActiveIdxRegPhaseOne[6]{1, 1, 1, 1, 9, 16};
  static const signed char t5_isActiveIdxRegularized[6]{1, 1, 1, 1, 8, 15};
  static const signed char t5_sizes[5]{0, 0, 0, 7, 7};
  static const signed char t5_sizesNormal[5]{0, 0, 0, 7, 7};
  static const signed char t5_sizesPhaseOne[5]{0, 0, 0, 8, 7};
  static const signed char t5_sizesRegPhaseOne[5]{0, 0, 0, 8, 7};
  static const signed char t5_sizesRegularized[5]{0, 0, 0, 7, 7};
  b_struct_T memspace;
  m_struct_T TrialState;
  o_struct_T WorkingSet;
  q_struct_T FcnEvaluator;
  struct_T QRManager;
  t_struct_T FiniteDifferences;
  u_struct_T MeritFunction;
  x_struct_T QPObjective;
  y_struct_T CholManager;
  double Hessian[7][7];
  double fval;
  int i2;
  int idx;
  int idxFillStart;
  int nWFixed;
  int nWeq;
  TrialState.nVarMax = 8;
  TrialState.mNonlinIneq = 0;
  TrialState.mNonlinEq = 0;
  TrialState.mIneq = 0;
  TrialState.mEq = 0;
  TrialState.iNonIneq0 = 1;
  TrialState.iNonEq0 = 1;
  TrialState.sqpFval_old = 0.0;
  TrialState.sqpIterations = 0;
  TrialState.sqpExitFlag = 0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 15; b_i++) {
    TrialState.lambdasqp[b_i] = 0.0;
  }
  TrialState.steplength = 1.0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_i = 0; c_i < 8; c_i++) {
    TrialState.delta_x[c_i] = 0.0;
  }
  TrialState.fstar = 0.0;
  TrialState.firstorderopt = 0.0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int d_i = 0; d_i < 15; d_i++) {
    TrialState.lambda[d_i] = 0.0;
  }
  TrialState.state = 0;
  TrialState.maxConstr = 0.0;
  TrialState.iterations = 0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int k = 0; k < 7; k++) {
    TrialState.xstarsqp[k] = x0[k];
  }
  FcnEvaluator.objfun = *fun;
  FcnEvaluator.nVar = 7;
  FcnEvaluator.mCineq = 0;
  FcnEvaluator.mCeq = 0;
  FcnEvaluator.NonFiniteSupport = true;
  FcnEvaluator.SpecifyObjectiveGradient = false;
  FcnEvaluator.SpecifyConstraintGradient = false;
  FcnEvaluator.ScaleProblem = false;
  FiniteDifferences.objfun = *fun;
  FiniteDifferences.b_f_1 = 0.0;
  FiniteDifferences.f_2 = 0.0;
  FiniteDifferences.nVar = 7;
  FiniteDifferences.mIneq = 0;
  FiniteDifferences.mEq = 0;
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.SpecifyObjectiveGradient = false;
  FiniteDifferences.SpecifyConstraintGradient = false;
  FiniteDifferences.isEmptyNonlcon = true;
  FiniteDifferences.FiniteDifferenceType = 0;
  FiniteDifferences.hasLB[0] = true;
  FiniteDifferences.hasUB[0] = true;
  idx = 1;
  while ((idx + 1) <= 7) {
    FiniteDifferences.hasLB[idx] = true;
    FiniteDifferences.hasUB[idx] = true;
    idx++;
  }
  FiniteDifferences.hasBounds = true;
  WorkingSet.mConstr = 14;
  WorkingSet.mConstrOrig = 14;
  WorkingSet.mConstrMax = 15;
  WorkingSet.nVar = 7;
  WorkingSet.nVarOrig = 7;
  WorkingSet.nVarMax = 8;
  WorkingSet.ldA = 8;
  for (int e_i{0}; e_i < 8; e_i++) {
    WorkingSet.lb[e_i] = 0.0;
    WorkingSet.ub[e_i] = 0.0;
    WorkingSet.indexLB[e_i] = static_cast<int>(t5_indexLB[e_i]);
    WorkingSet.indexUB[e_i] = static_cast<int>(t5_indexUB[e_i]);
    WorkingSet.indexFixed[e_i] = 0;
  }
  WorkingSet.mEqRemoved = 0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int g_i = 0; g_i < 120; g_i++) {
    WorkingSet.ATwset[g_i] = 0.0;
  }
  WorkingSet.nActiveConstr = 0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int h_i = 0; h_i < 15; h_i++) {
    WorkingSet.bwset[h_i] = 0.0;
    WorkingSet.maxConstrWorkspace[h_i] = 0.0;
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int k_i = 0; k_i < 5; k_i++) {
    WorkingSet.sizes[k_i] = static_cast<int>(t5_sizes[k_i]);
    WorkingSet.sizesNormal[k_i] = static_cast<int>(t5_sizesNormal[k_i]);
    WorkingSet.sizesPhaseOne[k_i] = static_cast<int>(t5_sizesPhaseOne[k_i]);
    WorkingSet.sizesRegularized[k_i] =
        static_cast<int>(t5_sizesRegularized[k_i]);
    WorkingSet.sizesRegPhaseOne[k_i] =
        static_cast<int>(t5_sizesRegPhaseOne[k_i]);
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int m_i = 0; m_i < 6; m_i++) {
    WorkingSet.isActiveIdx[m_i] = static_cast<int>(t5_isActiveIdx[m_i]);
    WorkingSet.isActiveIdxNormal[m_i] =
        static_cast<int>(t5_isActiveIdxNormal[m_i]);
    WorkingSet.isActiveIdxPhaseOne[m_i] =
        static_cast<int>(t5_isActiveIdxPhaseOne[m_i]);
    WorkingSet.isActiveIdxRegularized[m_i] =
        static_cast<int>(t5_isActiveIdxRegularized[m_i]);
    WorkingSet.isActiveIdxRegPhaseOne[m_i] =
        static_cast<int>(t5_isActiveIdxRegPhaseOne[m_i]);
  }
  for (int q_i{0}; q_i < 15; q_i++) {
    WorkingSet.isActiveConstr[q_i] = false;
    WorkingSet.Wid[q_i] = 0;
    WorkingSet.Wlocalidx[q_i] = 0;
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int t_i = 0; t_i < 5; t_i++) {
    WorkingSet.nWConstr[t_i] = 0;
  }
  WorkingSet.probType = 3;
  WorkingSet.SLACK0 = 1.0E-5;
  for (int b_idx{0}; b_idx < 7; b_idx++) {
    int w_i;
    w_i = (static_cast<int>(b_iv[b_idx])) - 1;
    TrialState.xstarsqp[w_i] =
        std::fmax(TrialState.xstarsqp[w_i], -1.7976931348623157E+308);
  }
  for (int c_idx{0}; c_idx < 7; c_idx++) {
    int i1;
    i1 = (static_cast<int>(b_iv[c_idx])) - 1;
    TrialState.xstarsqp[i1] =
        std::fmin(TrialState.xstarsqp[i1], 1.7976931348623157E+308);
  }
  fval = optimizeCamPose_anonFcn1(fun->workspace.undist_imgMarkerPts,
                                  fun->workspace.WptsTrio, fun->workspace.K11,
                                  TrialState.xstarsqp);
  TrialState.sqpFval = fval;
  (void)optim::coder::utils::FiniteDifferences::internal::
      computeForwardDifferences(&FiniteDifferences, fval, TrialState.xstarsqp,
                                TrialState.grad);
  TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
  for (int d_idx{0}; d_idx < 7; d_idx++) {
    WorkingSet.lb[WorkingSet.indexLB[d_idx] - 1] =
        x0[WorkingSet.indexLB[d_idx] - 1] + 1.7976931348623157E+308;
  }
  for (int e_idx{0}; e_idx < 7; e_idx++) {
    WorkingSet.ub[WorkingSet.indexUB[e_idx] - 1] =
        1.7976931348623157E+308 - x0[WorkingSet.indexUB[e_idx] - 1];
  }
  optim::coder::qpactiveset::WorkingSet::setProblemType(&WorkingSet, 3);
  idxFillStart = WorkingSet.isActiveIdx[2];
  i2 = WorkingSet.mConstrMax;
  if ((static_cast<int>(((WorkingSet.mConstrMax - WorkingSet.isActiveIdx[2]) +
                         1) < 4)) != 0) {
    if (idxFillStart <= i2) {
      (void)std::memset(&WorkingSet.isActiveConstr[idxFillStart + -1], 0,
                        (static_cast<unsigned int>(
                            static_cast<int>((i2 - idxFillStart) + 1))) *
                            (sizeof(bool)));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int f_idx = idxFillStart; f_idx <= i2; f_idx++) {
      WorkingSet.isActiveConstr[f_idx - 1] = false;
    }
  }
  WorkingSet.nWConstr[0] = WorkingSet.sizes[0];
  WorkingSet.nWConstr[1] = WorkingSet.sizes[1];
  WorkingSet.nWConstr[2] = 0;
  WorkingSet.nWConstr[3] = 0;
  WorkingSet.nWConstr[4] = 0;
  WorkingSet.nActiveConstr = WorkingSet.nWConstr[0] + WorkingSet.nWConstr[1];
  nWFixed = WorkingSet.sizes[0] - 1;
  for (int idx_local{0}; idx_local <= nWFixed; idx_local++) {
    int colOffsetATw;
    int i3;
    int i4;
    int i5;
    WorkingSet.Wid[idx_local] = 1;
    WorkingSet.Wlocalidx[idx_local] = idx_local + 1;
    WorkingSet.isActiveConstr[idx_local] = true;
    colOffsetATw = WorkingSet.ldA * idx_local;
    i3 = WorkingSet.indexFixed[idx_local];
    if (0 <= (i3 - 2)) {
      (void)std::memset(&WorkingSet.ATwset[colOffsetATw], 0,
                        (static_cast<unsigned int>(static_cast<int>(
                            ((i3 + colOffsetATw) - colOffsetATw) + -1))) *
                            (sizeof(double)));
    }
    WorkingSet.ATwset[(WorkingSet.indexFixed[idx_local] + colOffsetATw) - 1] =
        1.0;
    i4 = WorkingSet.indexFixed[idx_local] + 1;
    i5 = WorkingSet.nVar;
    if (i4 <= i5) {
      (void)std::memset(&WorkingSet.ATwset[(i4 + colOffsetATw) + -1], 0,
                        (static_cast<unsigned int>(static_cast<int>(
                            (((i5 + colOffsetATw) - i4) - colOffsetATw) + 1))) *
                            (sizeof(double)));
    }
    WorkingSet.bwset[idx_local] =
        WorkingSet.ub[WorkingSet.indexFixed[idx_local] - 1];
  }
  nWeq = WorkingSet.sizes[1];
  for (int b_idx_local{0}; b_idx_local < nWeq; b_idx_local++) {
    int idx_global;
    idx_global = (nWFixed + b_idx_local) + 1;
    WorkingSet.Wid[idx_global] = 2;
    WorkingSet.Wlocalidx[idx_global] = b_idx_local + 1;
    WorkingSet.isActiveConstr[idx_global] = true;
    // A check that is always false is detected at compile-time. Eliminating
    // code that follows.
  }
  MeritFunction.initFval = fval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  MeritFunction.initConstrViolationEq = 0.0;
  MeritFunction.initConstrViolationIneq = 0.0;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.b_firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  optim::coder::fminconsqp::driver(
      &TrialState, &MeritFunction, &FcnEvaluator, &FiniteDifferences, &memspace,
      &WorkingSet, Hessian, &QRManager, &CholManager, &QPObjective);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i6 = 0; i6 < 7; i6++) {
    b_x[i6] = TrialState.xstarsqp[i6];
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for fmincon.cpp
//
// [EOF]
//
