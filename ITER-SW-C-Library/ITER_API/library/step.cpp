//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: step.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "step.h"
#include "ITER_API_internal_types.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "relaxed.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xnrm2.h"
#include <algorithm>
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int *b_STEP_TYPE
//                double Hessian[7][7]
//                i_struct_T *TrialState
//                p_struct_T *MeritFunction
//                b_struct_T *memspace
//                j_struct_T *WorkingSet
//                struct_T *b_QRManager
//                s_struct_T *b_CholManager
//                r_struct_T *QPObjective
//                d_struct_T *qpoptions
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
bool b_step(int *b_STEP_TYPE, double Hessian[7][7], i_struct_T *TrialState,
            p_struct_T *MeritFunction, b_struct_T *memspace,
            j_struct_T *WorkingSet, struct_T *b_QRManager,
            s_struct_T *b_CholManager, r_struct_T *QPObjective,
            d_struct_T *qpoptions)
{
  d_struct_T b_qpoptions;
  d_struct_T c_qpoptions;
  double dv[8];
  int nVar;
  int nVar_tmp_tmp;
  bool checkBoundViolation;
  bool stepSuccess;
  stepSuccess = true;
  checkBoundViolation = true;
  nVar_tmp_tmp = WorkingSet->nVar - 1;
  nVar = nVar_tmp_tmp;
  if ((*b_STEP_TYPE) != 3) {
    if (0 <= nVar_tmp_tmp) {
      (void)std::copy(&TrialState->xstarsqp[0],
                      &TrialState->xstarsqp[nVar_tmp_tmp + 1],
                      &TrialState->xstar[0]);
    }
  } else if ((static_cast<int>((nVar_tmp_tmp + 1) < 4)) != 0) {
    if (0 <= nVar_tmp_tmp) {
      (void)std::copy(&TrialState->xstar[0],
                      &TrialState->xstar[nVar_tmp_tmp + 1],
                      &TrialState->searchDir[0]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= nVar; k++) {
      TrialState->searchDir[k] = TrialState->xstar[k];
    }
  }
  int exitg1;
  bool guard1{false};
  do {
    exitg1 = 0;
    guard1 = false;
    switch (*b_STEP_TYPE) {
    case 1: {
      b_qpoptions = *qpoptions;
      ::coder::optim::coder::qpactiveset::driver(
          Hessian, TrialState->grad, TrialState, memspace, WorkingSet,
          b_QRManager, b_CholManager, QPObjective, qpoptions, &b_qpoptions);
      if (TrialState->state > 0) {
        double linearizedConstrViolPrev;
        double penaltyParamTrial;
        penaltyParamTrial = MeritFunction->penaltyParam;
        linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
        MeritFunction->linearizedConstrViol = 0.0;
        if ((linearizedConstrViolPrev > 2.2204460492503131E-16) &&
            (TrialState->fstar > 0.0)) {
          double b_TrialState;
          if (TrialState->sqpFval == 0.0) {
            b_TrialState = 1.0;
          } else {
            b_TrialState = 1.5;
          }
          penaltyParamTrial =
              (b_TrialState * TrialState->fstar) / linearizedConstrViolPrev;
        }
        if (penaltyParamTrial < MeritFunction->penaltyParam) {
          MeritFunction->phi = TrialState->sqpFval + (penaltyParamTrial * 0.0);
          if (((MeritFunction->initFval +
                (penaltyParamTrial *
                 (MeritFunction->initConstrViolationEq +
                  MeritFunction->initConstrViolationIneq))) -
               MeritFunction->phi) >
              ((static_cast<double>(MeritFunction->nPenaltyDecreases)) *
               MeritFunction->threshold)) {
            MeritFunction->nPenaltyDecreases++;
            if ((MeritFunction->nPenaltyDecreases * 2) >
                TrialState->sqpIterations) {
              MeritFunction->threshold *= 10.0;
            }
            MeritFunction->penaltyParam = std::fmax(penaltyParamTrial, 1.0E-10);
          } else {
            MeritFunction->phi =
                TrialState->sqpFval + (MeritFunction->penaltyParam * 0.0);
          }
        } else {
          MeritFunction->penaltyParam = std::fmax(penaltyParamTrial, 1.0E-10);
          MeritFunction->phi =
              TrialState->sqpFval + (MeritFunction->penaltyParam * 0.0);
        }
        MeritFunction->phiPrimePlus = std::fmin(
            TrialState->fstar - (MeritFunction->penaltyParam * 0.0), 0.0);
      }
      qpactiveset::parseoutput::sortLambdaQP(
          TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
          WorkingSet->isActiveIdx, WorkingSet->Wid, WorkingSet->Wlocalidx,
          memspace->workspace_double);
      if (WorkingSet->mEqRemoved > 0) {
        int eqNonLinStart;
        int i1;
        eqNonLinStart = (WorkingSet->sizes[0] + TrialState->iNonEq0) - 1;
        i1 = TrialState->mNonlinEq;
        for (int idx{0}; idx < i1; idx++) {
          WorkingSet->Wlocalidx[eqNonLinStart + idx] =
              TrialState->iNonEq0 + idx;
        }
      }
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *b_STEP_TYPE = 2;
      } else {
        if (0 <= nVar) {
          (void)std::copy(&TrialState->xstar[0], &TrialState->xstar[nVar + 1],
                          &TrialState->delta_x[0]);
        }
        guard1 = true;
      }
    } break;
    case 2: {
      int idxEndIneq;
      int idxStartIneq;
      int mLB;
      int mUB;
      idxStartIneq = (WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1]) + 1;
      idxEndIneq = WorkingSet->nActiveConstr;
      for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq;
           idx_global++) {
        WorkingSet->isActiveConstr
            [(WorkingSet->isActiveIdx[WorkingSet->Wid[idx_global - 1] - 1] +
              WorkingSet->Wlocalidx[idx_global - 1]) -
             2] = false;
      }
      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr =
          WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
      (void)std::copy(&TrialState->xstar[0], &TrialState->xstar[8], &dv[0]);
      mLB = WorkingSet->sizes[3];
      mUB = WorkingSet->sizes[4];
      for (int b_idx{0}; b_idx < mLB; b_idx++) {
        double d;
        d = WorkingSet->lb[WorkingSet->indexLB[b_idx] - 1];
        if ((-dv[WorkingSet->indexLB[b_idx] - 1]) > d) {
          dv[WorkingSet->indexLB[b_idx] - 1] =
              (WorkingSet->ub[WorkingSet->indexLB[b_idx] - 1] - d) / 2.0;
        }
      }
      for (int c_idx{0}; c_idx < mUB; c_idx++) {
        double b_d1;
        b_d1 = WorkingSet->ub[WorkingSet->indexUB[c_idx] - 1];
        if (dv[WorkingSet->indexUB[c_idx] - 1] > b_d1) {
          dv[WorkingSet->indexUB[c_idx] - 1] =
              (b_d1 - WorkingSet->lb[WorkingSet->indexUB[c_idx] - 1]) / 2.0;
        }
      }
      (void)std::copy(&dv[0], &dv[8], &TrialState->xstar[0]);
      step::relaxed(Hessian, TrialState->grad, TrialState, MeritFunction,
                    memspace, WorkingSet, b_QRManager, b_CholManager,
                    QPObjective, qpoptions);
      if (0 <= nVar) {
        (void)std::copy(&TrialState->xstar[0], &TrialState->xstar[nVar + 1],
                        &TrialState->delta_x[0]);
      }
      guard1 = true;
    } break;
    default: {
      int b_i;
      int c_mLB;
      int idxIneqOffset;
      int mConstrMax;
      int mIneq;
      int nWIneq_old;
      int nWLower_old;
      int nWUpper_old;
      bool b_stepSuccess;
      nWIneq_old = WorkingSet->nWConstr[2];
      nWLower_old = WorkingSet->nWConstr[3];
      nWUpper_old = WorkingSet->nWConstr[4];
      b_i = WorkingSet->nVar - 1;
      mConstrMax = WorkingSet->mConstrMax - 1;
      if (0 <= b_i) {
        (void)std::copy(&TrialState->xstarsqp_old[0],
                        &TrialState->xstarsqp_old[b_i + 1],
                        &TrialState->xstarsqp[0]);
        (void)std::copy(&TrialState->xstar[0], &TrialState->xstar[b_i + 1],
                        &TrialState->socDirection[0]);
      }
      if (0 <= mConstrMax) {
        (void)std::copy(&TrialState->lambda[0],
                        &TrialState->lambda[mConstrMax + 1],
                        &TrialState->lambdaStopTest[0]);
      }
      idxIneqOffset = WorkingSet->isActiveIdx[2];
      if (WorkingSet->sizes[2] > 0) {
        int i2;
        int idx_Aineq;
        int idx_lower;
        int idx_upper;
        idx_Aineq = 1;
        idx_lower = WorkingSet->sizes[2] + 1;
        idx_upper = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
        i2 = WorkingSet->nActiveConstr;
        for (int d_idx{idxIneqOffset}; d_idx <= i2; d_idx++) {
          int idx_Partition;
          switch (WorkingSet->Wid[d_idx - 1]) {
          case 3:
            idx_Partition = idx_Aineq;
            idx_Aineq++;
            // A check that is always false is detected at compile-time.
            // Eliminating code that follows.
            break;
          case 4:
            idx_Partition = idx_lower;
            idx_lower++;
            break;
          default:
            idx_Partition = idx_upper;
            idx_upper++;
            break;
          }
          TrialState->workingset_old[idx_Partition - 1] =
              WorkingSet->Wlocalidx[d_idx - 1];
        }
      }
      if (0 <= b_i) {
        (void)std::copy(&TrialState->xstarsqp[0],
                        &TrialState->xstarsqp[b_i + 1], &TrialState->xstar[0]);
      }
      (void)std::copy(&TrialState->grad[0], &TrialState->grad[8], &dv[0]);
      c_qpoptions = *qpoptions;
      ::coder::optim::coder::qpactiveset::driver(
          Hessian, dv, TrialState, memspace, WorkingSet, b_QRManager,
          b_CholManager, QPObjective, qpoptions, &c_qpoptions);
      for (int f_idx{0}; f_idx <= b_i; f_idx++) {
        double oldDirIdx;
        oldDirIdx = TrialState->socDirection[f_idx];
        TrialState->socDirection[f_idx] =
            TrialState->xstar[f_idx] - TrialState->socDirection[f_idx];
        TrialState->xstar[f_idx] = oldDirIdx;
      }
      b_stepSuccess =
          (::coder::internal::blas::h_xnrm2(b_i + 1,
                                            TrialState->socDirection) <=
           (2.0 *
            ::coder::internal::blas::h_xnrm2(b_i + 1, TrialState->xstar)));
      mIneq = WorkingSet->sizes[2];
      c_mLB = WorkingSet->sizes[3];
      if ((WorkingSet->sizes[2] > 0) && (!b_stepSuccess)) {
        int b_idxEndIneq;
        int b_idxStartIneq;
        b_idxStartIneq =
            (WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1]) + 1;
        b_idxEndIneq = WorkingSet->nActiveConstr;
        for (int b_idx_global{b_idxStartIneq}; b_idx_global <= b_idxEndIneq;
             b_idx_global++) {
          WorkingSet->isActiveConstr
              [(WorkingSet->isActiveIdx[WorkingSet->Wid[b_idx_global - 1] - 1] +
                WorkingSet->Wlocalidx[b_idx_global - 1]) -
               2] = false;
        }
        WorkingSet->nWConstr[2] = 0;
        WorkingSet->nWConstr[3] = 0;
        WorkingSet->nWConstr[4] = 0;
        WorkingSet->nActiveConstr =
            WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1];
        for (int m_idx{0}; m_idx < nWIneq_old; m_idx++) {
          int idx_local;
          idx_local = TrialState->workingset_old[m_idx];
          WorkingSet->nWConstr[2]++;
          WorkingSet
              ->isActiveConstr[(WorkingSet->isActiveIdx[2] + idx_local) - 2] =
              true;
          WorkingSet->nActiveConstr++;
          WorkingSet->Wid[WorkingSet->nActiveConstr - 1] = 3;
          WorkingSet->Wlocalidx[WorkingSet->nActiveConstr - 1] = idx_local;
          // A check that is always false is detected at compile-time.
          // Eliminating code that follows.
        }
        for (int o_idx{0}; o_idx < nWLower_old; o_idx++) {
          qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
              WorkingSet, 4, TrialState->workingset_old[o_idx + mIneq]);
        }
        for (int p_idx{0}; p_idx < nWUpper_old; p_idx++) {
          qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
              WorkingSet, 5,
              TrialState->workingset_old[(p_idx + mIneq) + c_mLB]);
        }
      }
      if (!b_stepSuccess) {
        if (0 <= mConstrMax) {
          (void)std::copy(&TrialState->lambdaStopTest[0],
                          &TrialState->lambdaStopTest[mConstrMax + 1],
                          &TrialState->lambda[0]);
        }
      } else {
        qpactiveset::parseoutput::sortLambdaQP(
            TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
            WorkingSet->isActiveIdx, WorkingSet->Wid, WorkingSet->Wlocalidx,
            memspace->workspace_double);
      }
      stepSuccess = b_stepSuccess;
      checkBoundViolation = b_stepSuccess;
      if (b_stepSuccess && (TrialState->state != -6)) {
        for (int j_idx{0}; j_idx <= nVar; j_idx++) {
          TrialState->delta_x[j_idx] =
              TrialState->xstar[j_idx] + TrialState->socDirection[j_idx];
        }
      }
      guard1 = true;
    } break;
    }
    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        double diagVal;
        double nrmDirInf;
        double nrmGradInf;
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (int e_idx{0}; e_idx < 7; e_idx++) {
          nrmGradInf = std::fmax(nrmGradInf, std::abs(TrialState->grad[e_idx]));
          nrmDirInf = std::fmax(nrmDirInf, std::abs(TrialState->xstar[e_idx]));
        }
        diagVal = std::fmax(2.2204460492503131E-16, nrmGradInf / nrmDirInf);
        for (int idx_col{0}; idx_col < 7; idx_col++) {
          int h_n;
          int iH0;
          int iy0;
          iH0 = 7 * idx_col;
          for (int b_k{0}; b_k < idx_col; b_k++) {
            (&Hessian[0][0])[iH0 + b_k] = 0.0;
          }
          Hessian[idx_col][idx_col] = diagVal;
          iy0 = iH0 + idx_col;
          h_n = 5 - idx_col;
          for (int c_k{0}; c_k <= h_n; c_k++) {
            (&Hessian[0][0])[(iy0 + c_k) + 1] = 0.0;
          }
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    double violationResid;
    int b_mLB;
    int b_mUB;
    b_mLB = WorkingSet->sizes[3];
    b_mUB = WorkingSet->sizes[4];
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i < 8; c_i++) {
      dv[c_i] = TrialState->delta_x[c_i];
    }
    for (int g_idx{0}; g_idx < b_mLB; g_idx++) {
      double violationResid_tmp;
      violationResid_tmp = dv[WorkingSet->indexLB[g_idx] - 1];
      violationResid = (TrialState->xstarsqp[WorkingSet->indexLB[g_idx] - 1] +
                        violationResid_tmp) -
                       -1.7976931348623157E+308;
      if (violationResid < 0.0) {
        dv[WorkingSet->indexLB[g_idx] - 1] =
            violationResid_tmp - violationResid;
        TrialState->xstar[WorkingSet->indexLB[g_idx] - 1] -= violationResid;
      }
    }
    for (int h_idx{0}; h_idx < b_mUB; h_idx++) {
      double b_violationResid_tmp;
      b_violationResid_tmp = dv[WorkingSet->indexUB[h_idx] - 1];
      violationResid = (1.7976931348623157E+308 -
                        TrialState->xstarsqp[WorkingSet->indexUB[h_idx] - 1]) -
                       b_violationResid_tmp;
      if (violationResid < 0.0) {
        dv[WorkingSet->indexUB[h_idx] - 1] =
            b_violationResid_tmp + violationResid;
        TrialState->xstar[WorkingSet->indexUB[h_idx] - 1] += violationResid;
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int d_i = 0; d_i < 8; d_i++) {
      TrialState->delta_x[d_i] = dv[d_i];
    }
  }
  return stepSuccess;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for step.cpp
//
// [EOF]
//
