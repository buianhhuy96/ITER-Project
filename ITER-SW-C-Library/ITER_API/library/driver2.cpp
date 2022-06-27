//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "driver2.h"
#include "BFGSUpdate.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types1.h"
#include "anonymous_function.h"
#include "computeCentralDifferences.h"
#include "computeForwardDifferences.h"
#include "optimizeCamPose.h"
#include "rt_nonfinite.h"
#include "step.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "xgemv.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : i_struct_T *TrialState
//                p_struct_T *MeritFunction
//                const k_struct_T *FcnEvaluator
//                o_struct_T *FiniteDifferences
//                b_struct_T *memspace
//                j_struct_T *WorkingSet
//                double Hessian[7][7]
//                struct_T *b_QRManager
//                s_struct_T *b_CholManager
//                r_struct_T *QPObjective
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(i_struct_T *TrialState, p_struct_T *MeritFunction,
            const k_struct_T *FcnEvaluator, o_struct_T *FiniteDifferences,
            b_struct_T *memspace, j_struct_T *WorkingSet, double Hessian[7][7],
            struct_T *b_QRManager, s_struct_T *b_CholManager,
            r_struct_T *QPObjective)
{
  static const signed char b_iv[7][7]{
      {1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 1}};
  static const char qpoptions_SolverName[7]{'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  c_struct_T Flags;
  d_struct_T b_expl_temp;
  d_struct_T expl_temp;
  int b_u1;
  int i1;
  int mConstr;
  int mEq;
  int mFixed;
  int mLB;
  int mUB;
  int nVar;
  int qpoptions_MaxIterations;
  int u0;
  int y;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 8; b_i++) {
    QPObjective->grad[b_i] = 0.0;
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_i = 0; c_i < 7; c_i++) {
    QPObjective->Hx[c_i] = 0.0;
  }
  QPObjective->hasLinear = true;
  QPObjective->b_nvar = 7;
  QPObjective->maxVar = 8;
  QPObjective->beta = 0.0;
  QPObjective->rho = 0.0;
  QPObjective->objtype = 3;
  QPObjective->prev_objtype = 3;
  QPObjective->prev_nvar = 0;
  QPObjective->prev_hasLinear = false;
  QPObjective->gammaScalar = 0.0;
  b_CholManager->ldm = 15;
  b_CholManager->ndims = 0;
  b_CholManager->info = 0;
  b_CholManager->scaleFactor = 0.0;
  b_CholManager->ConvexCheck = true;
  b_CholManager->regTol_ = rtInf;
  b_CholManager->b_workspace_ = rtInf;
  b_CholManager->workspace2_ = rtInf;
  b_QRManager->ldq = 15;
  b_QRManager->mrows = 0;
  b_QRManager->ncols = 0;
  (void)std::memset(&b_CholManager->FMat[0][0], 0, 225U * (sizeof(double)));
  (void)std::memset(&b_QRManager->QR[0][0], 0, 225U * (sizeof(double)));
  (void)std::memset(&b_QRManager->Q[0][0], 0, 225U * (sizeof(double)));
  (void)std::memset(&b_QRManager->tau[0], 0, 15U * (sizeof(double)));
  for (int d_i{0}; d_i < 15; d_i++) {
    b_QRManager->jpvt[d_i] = 0;
  }
  b_QRManager->minRowCol = 0;
  b_QRManager->usedPivoting = false;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

  for (int e_i = 0; e_i < 7; e_i++) {
    for (i1 = 0; i1 < 7; i1++) {
      Hessian[e_i][i1] = static_cast<double>(b_iv[e_i][i1]);
    }
  }
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr =
      (((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->sizes[2]) +
       WorkingSet->sizes[3]) +
      WorkingSet->sizes[4];
  u0 = WorkingSet->nVar;
  b_u1 =
      ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
      (WorkingSet->sizes[0] * 2);
  if (u0 >= b_u1) {
    y = u0;
  } else {
    y = b_u1;
  }
  qpoptions_MaxIterations = 10 * y;
  TrialState->steplength = 1.0;
  test_exit(memspace, MeritFunction, WorkingSet, TrialState, b_QRManager,
            &Flags.gradOK, &Flags.fevalOK, &Flags.done, &Flags.stepAccepted,
            &Flags.failedLineSearch, &Flags.stepType);
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (int k{0}; k < 7; k++) {
    TrialState->xstarsqp_old[k] = TrialState->xstarsqp[k];
    TrialState->grad_old[k] = TrialState->grad[k];
  }
  if (!Flags.done) {
    TrialState->sqpIterations++;
  }
  while (!Flags.done) {
    while (!((Flags.stepAccepted) || (Flags.failedLineSearch))) {
      if (Flags.stepType != 3) {
        internal::updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet,
                                           mEq, mLB, mUB, mFixed);
      }
      expl_temp.IterDisplayQP = false;
      expl_temp.RemainFeasible = false;
      expl_temp.ProbRelTolFactor = 1.0;
      expl_temp.ConstrRelTolFactor = 1.0;
      expl_temp.PricingTolerance = 0.0;
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (int i2{0}; i2 < 7; i2++) {
        expl_temp.SolverName[i2] = qpoptions_SolverName[i2];
      }
      b_expl_temp = expl_temp;
      Flags.stepAccepted = b_step(
          &Flags.stepType, Hessian, TrialState, MeritFunction, memspace,
          WorkingSet, b_QRManager, b_CholManager, QPObjective, &b_expl_temp);
      if (Flags.stepAccepted) {
        double fval;
        int fevalSuccess;
        int status;
        for (int g_i{0}; g_i < nVar; g_i++) {
          TrialState->xstarsqp[g_i] += TrialState->delta_x[g_i];
        }
        fval = optimizeCamPose_anonFcn1(
            FcnEvaluator->objfun.workspace.undist_imgMarkerPts,
            FcnEvaluator->objfun.workspace.WptsTrio,
            FcnEvaluator->objfun.workspace.K11, TrialState->xstarsqp);
        status = 1;
        if ((std::isinf(fval)) || (std::isnan(fval))) {
          if (std::isnan(fval)) {
            status = -3;
          } else if (fval < 0.0) {
            status = -1;
          } else {
            status = -2;
          }
        }
        TrialState->sqpFval = fval;
        fevalSuccess = status;
        if (status == 1) {
          fevalSuccess = 1;
        }
        Flags.fevalOK = (fevalSuccess == 1);
        TrialState->FunctionEvaluations++;
        if (Flags.fevalOK) {
          MeritFunction->phiFullStep =
              fval + (MeritFunction->penaltyParam * 0.0);
        } else {
          MeritFunction->phiFullStep = rtInf;
        }
      }
      if (((((Flags.stepType == 1) && (Flags.stepAccepted)) &&
            (Flags.fevalOK)) &&
           (MeritFunction->phi < MeritFunction->phiFullStep)) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        double alpha;
        double phi_alpha;
        int c_nVar;
        int exitflagLnSrch;
        bool evalWellDefined;
        bool socTaken;
        if ((Flags.stepType == 3) && (Flags.stepAccepted)) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        evalWellDefined = Flags.fevalOK;
        c_nVar = WorkingSet->nVar - 1;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = MeritFunction->phiFullStep;
        if (0 <= c_nVar) {
          (void)std::copy(&TrialState->delta_x[0],
                          &TrialState->delta_x[c_nVar + 1],
                          &TrialState->searchDir[0]);
        }
        int exitg1;
        do {
          exitg1 = 0;
          if (TrialState->FunctionEvaluations < 2500) {
            if (evalWellDefined &&
                (phi_alpha <=
                 (MeritFunction->phi +
                  ((alpha * 0.0001) * MeritFunction->phiPrimePlus)))) {
              exitg1 = 1;
            } else {
              int d_idx;
              bool exitg2;
              bool tooSmallX;
              alpha *= 0.7;
              for (int c_idx{0}; c_idx <= c_nVar; c_idx++) {
                TrialState->delta_x[c_idx] = alpha * TrialState->xstar[c_idx];
              }
              if (socTaken) {
                double b_a;
                b_a = alpha * alpha;
                if (((c_nVar + 1) >= 1) && (!(b_a == 0.0))) {
                  for (int e_k{0}; e_k <= c_nVar; e_k++) {
                    TrialState->delta_x[e_k] +=
                        b_a * TrialState->socDirection[e_k];
                  }
                }
              }
              tooSmallX = true;
              d_idx = 0;
              exitg2 = false;
              while ((!exitg2) && (d_idx <= c_nVar)) {
                if ((1.0E-6 *
                     std::fmax(1.0, std::abs(TrialState->xstarsqp[d_idx]))) <=
                    std::abs(TrialState->delta_x[d_idx])) {
                  tooSmallX = false;
                  exitg2 = true;
                } else {
                  d_idx++;
                }
              }
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                double b_fval;
                int b_status;
                int evalStatus;
                for (int e_idx{0}; e_idx <= c_nVar; e_idx++) {
                  TrialState->xstarsqp[e_idx] =
                      TrialState->xstarsqp_old[e_idx] +
                      TrialState->delta_x[e_idx];
                }
                b_fval = optimizeCamPose_anonFcn1(
                    FcnEvaluator->objfun.workspace.undist_imgMarkerPts,
                    FcnEvaluator->objfun.workspace.WptsTrio,
                    FcnEvaluator->objfun.workspace.K11, TrialState->xstarsqp);
                b_status = 1;
                if ((std::isinf(b_fval)) || (std::isnan(b_fval))) {
                  if (std::isnan(b_fval)) {
                    b_status = -3;
                  } else if (b_fval < 0.0) {
                    b_status = -1;
                  } else {
                    b_status = -2;
                  }
                }
                TrialState->sqpFval = b_fval;
                evalStatus = b_status;
                if (b_status == 1) {
                  evalStatus = 1;
                }
                TrialState->FunctionEvaluations++;
                evalWellDefined = (evalStatus == 1);
                if (evalWellDefined) {
                  phi_alpha = b_fval + (MeritFunction->penaltyParam * 0.0);
                } else {
                  phi_alpha = rtInf;
                }
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = evalWellDefined;
        TrialState->steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if ((Flags.stepAccepted) && (!Flags.failedLineSearch)) {
      for (int idx{0}; idx < nVar; idx++) {
        TrialState->xstarsqp[idx] =
            TrialState->xstarsqp_old[idx] + TrialState->delta_x[idx];
      }
      for (int b_idx{0}; b_idx < mConstr; b_idx++) {
        TrialState->lambdasqp[b_idx] +=
            TrialState->steplength *
            (TrialState->lambda[b_idx] - TrialState->lambdasqp[b_idx]);
      }
      TrialState->sqpFval_old = TrialState->sqpFval;
      for (int c_k{0}; c_k < 7; c_k++) {
        TrialState->xstarsqp_old[c_k] = TrialState->xstarsqp[c_k];
        TrialState->grad_old[c_k] = TrialState->grad[c_k];
      }
      if (FiniteDifferences->FiniteDifferenceType == 0) {
        Flags.gradOK =
            utils::FiniteDifferences::internal::computeForwardDifferences(
                FiniteDifferences, TrialState->sqpFval, TrialState->xstarsqp,
                TrialState->grad);
      } else {
        Flags.gradOK =
            utils::FiniteDifferences::internal::computeCentralDifferences(
                FiniteDifferences, TrialState->sqpFval, TrialState->xstarsqp,
                TrialState->grad);
      }
      TrialState->FunctionEvaluations += FiniteDifferences->numEvals;
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      for (int b_k{0}; b_k < 7; b_k++) {
        TrialState->xstarsqp[b_k] = TrialState->xstarsqp_old[b_k];
      }
    }
    b_test_exit(&Flags, memspace, MeritFunction, WorkingSet, TrialState,
                b_QRManager);
    if ((!Flags.done) && (Flags.stepAccepted)) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      if (0 <= (nVar - 1)) {
        (void)std::copy(&TrialState->grad[0], &TrialState->grad[nVar],
                        &TrialState->delta_gradLag[0]);
      }
      if (nVar >= 1) {
        int ixlast;
        ixlast = nVar - 1;
        for (int d_k{0}; d_k <= ixlast; d_k++) {
          TrialState->delta_gradLag[d_k] += -TrialState->grad_old[d_k];
        }
      }
      if (TrialState->mNonlinEq > 0) {
        ::coder::internal::blas::c_xgemv(
            nVar, TrialState->mNonlinEq, WorkingSet->ldA, TrialState->lambdasqp,
            mFixed + TrialState->iNonEq0, TrialState->delta_gradLag);
      }
      if (TrialState->mNonlinIneq > 0) {
        ::coder::internal::blas::c_xgemv(nVar, TrialState->mNonlinIneq,
                                         WorkingSet->ldA, TrialState->lambdasqp,
                                         (mFixed + mEq) + TrialState->iNonIneq0,
                                         TrialState->delta_gradLag);
      }
      (void)BFGSUpdate(nVar, Hessian, TrialState->delta_x,
                       TrialState->delta_gradLag, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for driver2.cpp
//
// [EOF]
//
