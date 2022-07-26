//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: relaxed.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "relaxed.h"
#include "ITER_API_internal_types.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "sortLambdaQP.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double Hessian[7][7]
//                const double grad[8]
//                m_struct_T *TrialState
//                u_struct_T *MeritFunction
//                b_struct_T *memspace
//                o_struct_T *WorkingSet
//                struct_T *b_QRManager
//                y_struct_T *b_CholManager
//                x_struct_T *QPObjective
//                e_struct_T *qpoptions
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void relaxed(const double Hessian[7][7], const double grad[8],
             m_struct_T *TrialState, u_struct_T *MeritFunction,
             b_struct_T *memspace, o_struct_T *WorkingSet,
             struct_T *b_QRManager, y_struct_T *b_CholManager,
             x_struct_T *QPObjective, e_struct_T *qpoptions)
{
  e_struct_T b_qpoptions;
  o_struct_T b_WorkingSet;
  o_struct_T c_WorkingSet;
  double beta;
  double rho;
  int b_mEq;
  int b_mIneq;
  int b_nActiveLBArtificial;
  int c_mEq;
  int f_idx;
  int isAineqActive;
  int mEq;
  int mFiniteLB;
  int mFiniteLBOrig;
  int mIneq;
  int mLBOrig;
  int nActiveLBArtificial;
  int nArtificial;
  int nArtificial_tmp_tmp_tmp;
  int nVarOrig;
  nVarOrig = WorkingSet->nVar - 1;
  mEq = WorkingSet->sizes[1];
  beta = 0.0;
  for (int idx{0}; idx <= nVarOrig; idx++) {
    beta += Hessian[idx][idx];
  }
  beta /= static_cast<double>(WorkingSet->nVar);
  if (TrialState->sqpIterations <= 1) {
    int b_idx_max;
    int p_n;
    p_n = QPObjective->b_nvar;
    if (QPObjective->b_nvar < 1) {
      b_idx_max = 0;
    } else {
      b_idx_max = 1;
      if (QPObjective->b_nvar > 1) {
        double b_smax;
        b_smax = std::abs(grad[0]);
        for (int b_k{2}; b_k <= p_n; b_k++) {
          double b_s;
          b_s = std::abs(grad[b_k - 1]);
          if (b_s > b_smax) {
            b_idx_max = b_k;
            b_smax = b_s;
          }
        }
      }
    }
    rho = 100.0 * std::fmax(1.0, std::abs(grad[b_idx_max - 1]));
  } else {
    int b_idx_max;
    int h_n;
    h_n = WorkingSet->mConstr;
    if (WorkingSet->mConstr < 1) {
      b_idx_max = 0;
    } else {
      b_idx_max = 1;
      if (WorkingSet->mConstr > 1) {
        double smax;
        smax = std::abs(TrialState->lambdasqp[0]);
        for (int k{2}; k <= h_n; k++) {
          double s;
          s = std::abs(TrialState->lambdasqp[k - 1]);
          if (s > smax) {
            b_idx_max = k;
            smax = s;
          }
        }
      }
    }
    rho = std::abs(TrialState->lambdasqp[b_idx_max - 1]);
  }
  QPObjective->b_nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = rho;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  b_WorkingSet = *WorkingSet;
  qpactiveset::WorkingSet::setProblemType(&b_WorkingSet, 2);
  mIneq = b_WorkingSet.sizes[2] + 1;
  b_mEq = b_WorkingSet.sizes[1];
  mLBOrig = (b_WorkingSet.sizes[3] - (b_WorkingSet.sizes[1] * 2)) -
            b_WorkingSet.sizes[2];
  for (int b_idx{0}; b_idx <= (mIneq - 2); b_idx++) {
    TrialState->xstar[(nVarOrig + b_idx) + 1] =
        (static_cast<double>((&memspace->workspace_double[0][0])[b_idx] >
                             0.0)) *
        (&memspace->workspace_double[0][0])[b_idx];
  }
  for (int c_idx{0}; c_idx < b_mEq; c_idx++) {
    int idx_negative;
    int idx_positive;
    idx_positive = mIneq + c_idx;
    idx_negative = (mIneq + b_mEq) + c_idx;
    if ((&memspace->workspace_double[0][0])[c_idx] <= 0.0) {
      TrialState->xstar[nVarOrig + idx_positive] = 0.0;
      TrialState->xstar[nVarOrig + idx_negative] =
          -(&memspace->workspace_double[0][0])[c_idx];
      qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
          &b_WorkingSet, 4, mLBOrig + idx_positive);
      if ((&memspace->workspace_double[0][0])[c_idx] >= -1.0E-6) {
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            &b_WorkingSet, 4, mLBOrig + idx_negative);
      }
    } else {
      TrialState->xstar[nVarOrig + idx_positive] =
          (&memspace->workspace_double[0][0])[c_idx];
      TrialState->xstar[nVarOrig + idx_negative] = 0.0;
      qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
          &b_WorkingSet, 4, mLBOrig + idx_negative);
      if ((&memspace->workspace_double[0][0])[c_idx] <= 1.0E-6) {
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            &b_WorkingSet, 4, mLBOrig + idx_positive);
      }
    }
  }
  int temp;
  temp = qpoptions->MaxIterations;
  qpoptions->MaxIterations =
      (qpoptions->MaxIterations + b_WorkingSet.nVar) - WorkingSet->nVar;
  b_qpoptions = *qpoptions;
  ::ITER::coder::optim::coder::qpactiveset::driver(
      Hessian, grad, TrialState, memspace, &b_WorkingSet, b_QRManager,
      b_CholManager, QPObjective, qpoptions, &b_qpoptions);
  qpoptions->MaxIterations = temp;
  b_mIneq = b_WorkingSet.sizes[2];
  c_mEq = b_WorkingSet.sizes[1];
  nArtificial_tmp_tmp_tmp = b_WorkingSet.sizes[1] * 2;
  nArtificial = nArtificial_tmp_tmp_tmp + b_WorkingSet.sizes[2];
  mFiniteLB = b_WorkingSet.sizes[3] - 1;
  nActiveLBArtificial = 0;
  for (int d_idx{0}; d_idx < c_mEq; d_idx++) {
    int tf_tmp;
    bool c_tf;
    bool tf;
    tf_tmp = b_WorkingSet.isActiveIdx[3] + mFiniteLB;
    tf =
        b_WorkingSet.isActiveConstr[(tf_tmp - nArtificial_tmp_tmp_tmp) + d_idx];
    c_tf = b_WorkingSet.isActiveConstr[(tf_tmp - c_mEq) + d_idx];
    memspace->workspace_int[d_idx] = static_cast<int>(tf);
    memspace->workspace_int[d_idx + c_mEq] = static_cast<int>(c_tf);
    nActiveLBArtificial = (nActiveLBArtificial + (static_cast<int>(tf))) +
                          (static_cast<int>(c_tf));
  }
  for (int e_idx{0}; e_idx < b_mIneq; e_idx++) {
    bool b_tf;
    b_tf =
        b_WorkingSet.isActiveConstr[((b_WorkingSet.isActiveIdx[3] + mFiniteLB) -
                                     nArtificial) +
                                    e_idx];
    memspace->workspace_int[e_idx + nArtificial_tmp_tmp_tmp] =
        static_cast<int>(b_tf);
    nActiveLBArtificial += static_cast<int>(b_tf);
  }
  if (TrialState->state != -6) {
    double constrViolDelta;
    double linearizedConstrViolPrev;
    double penaltyParamTrial;
    double qpfvalLinearExcess;
    double qpfvalQuadExcess;
    double qpval;
    double y;
    int b_nArtificial;
    int iEq0;
    int iIneq0;
    int iIneqEnd;
    int ix0_tmp;
    int q_n;
    b_nArtificial = (b_WorkingSet.nVarMax - WorkingSet->nVar) - 1;
    ix0_tmp = WorkingSet->nVar + 1;
    qpfvalLinearExcess = 0.0;
    qpfvalQuadExcess = 0.0;
    if (b_nArtificial >= 1) {
      int kend;
      kend = WorkingSet->nVar + b_nArtificial;
      for (int c_k{ix0_tmp}; c_k <= kend; c_k++) {
        qpfvalLinearExcess += std::abs(TrialState->xstar[c_k - 1]);
      }
    }
    if (b_nArtificial >= 1) {
      int b_iy;
      int c_ix;
      c_ix = WorkingSet->nVar;
      b_iy = WorkingSet->nVar;
      for (int d_k{0}; d_k < b_nArtificial; d_k++) {
        qpfvalQuadExcess +=
            TrialState->xstar[c_ix + d_k] * TrialState->xstar[b_iy + d_k];
      }
    }
    qpval = (TrialState->fstar - (rho * qpfvalLinearExcess)) -
            ((beta / 2.0) * qpfvalQuadExcess);
    q_n = (WorkingSet->nVarMax - WorkingSet->nVar) - 1;
    penaltyParamTrial = MeritFunction->penaltyParam;
    linearizedConstrViolPrev = MeritFunction->linearizedConstrViol;
    y = 0.0;
    if (q_n >= 1) {
      int c_kend;
      c_kend = WorkingSet->nVar + q_n;
      for (int e_k{ix0_tmp}; e_k <= c_kend; e_k++) {
        y += std::abs(TrialState->xstar[e_k - 1]);
      }
    }
    MeritFunction->linearizedConstrViol = y;
    constrViolDelta = linearizedConstrViolPrev - y;
    if ((constrViolDelta > 2.2204460492503131E-16) && (qpval > 0.0)) {
      double b_TrialState;
      if (TrialState->sqpFval == 0.0) {
        b_TrialState = 1.0;
      } else {
        b_TrialState = 1.5;
      }
      penaltyParamTrial = (b_TrialState * qpval) / constrViolDelta;
    }
    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi = TrialState->sqpFval + (penaltyParamTrial * 0.0);
      if (((MeritFunction->initFval +
            (penaltyParamTrial * (MeritFunction->initConstrViolationEq +
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
    MeritFunction->phiPrimePlus =
        std::fmin(qpval - (MeritFunction->penaltyParam * 0.0), 0.0);
    iEq0 = b_WorkingSet.isActiveIdx[1] - 2;
    for (int h_idx{0}; h_idx < mEq; h_idx++) {
      int i1;
      bool isAeqActive;
      if ((memspace->workspace_int[h_idx] != 0) &&
          (memspace->workspace_int[h_idx + mEq] != 0)) {
        isAeqActive = true;
      } else {
        isAeqActive = false;
      }
      i1 = (iEq0 + h_idx) + 1;
      TrialState->lambda[i1] *= static_cast<double>(isAeqActive);
    }
    iIneq0 = b_WorkingSet.isActiveIdx[2];
    iIneqEnd = b_WorkingSet.nActiveConstr;
    if ((static_cast<int>(
            ((b_WorkingSet.nActiveConstr - b_WorkingSet.isActiveIdx[2]) + 1) <
            4)) != 0) {
      for (int j_idx{iIneq0}; j_idx <= iIneqEnd; j_idx++) {
        if (b_WorkingSet.Wid[j_idx - 1] == 3) {
          TrialState->lambda[j_idx - 1] *= static_cast<double>(
              memspace->workspace_int
                  [(b_WorkingSet.Wlocalidx[j_idx - 1] + (mEq * 2)) - 1]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    isAineqActive)

      for (int j_idx = iIneq0; j_idx <= iIneqEnd; j_idx++) {
        if (b_WorkingSet.Wid[j_idx - 1] == 3) {
          isAineqActive =
              memspace->workspace_int[(b_WorkingSet.Wlocalidx[j_idx - 1] +
                                       (mEq * 2)) -
                                      1];
          TrialState->lambda[j_idx - 1] *= static_cast<double>(isAineqActive);
        }
      }
    }
  }
  b_nActiveLBArtificial = nActiveLBArtificial;
  c_WorkingSet = b_WorkingSet;
  mFiniteLBOrig = (b_WorkingSet.sizes[3] - (b_WorkingSet.sizes[1] * 2)) -
                  b_WorkingSet.sizes[2];
  f_idx = b_WorkingSet.nActiveConstr;
  while ((f_idx > (b_WorkingSet.sizes[0] + b_WorkingSet.sizes[1])) &&
         (b_nActiveLBArtificial > 0)) {
    if ((c_WorkingSet.Wid[f_idx - 1] == 4) &&
        (c_WorkingSet.Wlocalidx[f_idx - 1] > mFiniteLBOrig)) {
      double tmp;
      int TYPE_tmp;
      int b_i;
      tmp = TrialState->lambda[c_WorkingSet.nActiveConstr - 1];
      TrialState->lambda[c_WorkingSet.nActiveConstr - 1] = 0.0;
      TrialState->lambda[f_idx - 1] = tmp;
      TYPE_tmp = c_WorkingSet.Wid[f_idx - 1] - 1;
      c_WorkingSet.isActiveConstr[(b_WorkingSet.isActiveIdx[TYPE_tmp] +
                                   c_WorkingSet.Wlocalidx[f_idx - 1]) -
                                  2] = false;
      c_WorkingSet.Wid[f_idx - 1] =
          c_WorkingSet.Wid[c_WorkingSet.nActiveConstr - 1];
      c_WorkingSet.Wlocalidx[f_idx - 1] =
          c_WorkingSet.Wlocalidx[c_WorkingSet.nActiveConstr - 1];
      b_i = b_WorkingSet.nVar;
      for (int g_idx{0}; g_idx < b_i; g_idx++) {
        c_WorkingSet.ATwset[g_idx + (b_WorkingSet.ldA * (f_idx - 1))] =
            c_WorkingSet.ATwset[g_idx + (b_WorkingSet.ldA *
                                         (c_WorkingSet.nActiveConstr - 1))];
      }
      c_WorkingSet.bwset[f_idx - 1] =
          c_WorkingSet.bwset[c_WorkingSet.nActiveConstr - 1];
      c_WorkingSet.nActiveConstr--;
      c_WorkingSet.nWConstr[TYPE_tmp]--;
      b_nActiveLBArtificial--;
    }
    f_idx--;
  }
  QPObjective->b_nvar = WorkingSet->nVar;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  *WorkingSet = c_WorkingSet;
  qpactiveset::WorkingSet::setProblemType(WorkingSet, 3);
  qpactiveset::parseoutput::sortLambdaQP(
      TrialState->lambda, WorkingSet->nActiveConstr, WorkingSet->sizes,
      WorkingSet->isActiveIdx, WorkingSet->Wid, WorkingSet->Wlocalidx,
      memspace->workspace_double);
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for relaxed.cpp
//
// [EOF]
//
