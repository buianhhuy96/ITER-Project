//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_exit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "test_exit.h"
#include "ITER_API_internal_types.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computeLambdaLSQ.h"
#include "computePrimalFeasError.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "updateWorkingSetForNewQP.h"
#include <algorithm>
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : c_struct_T *Flags
//                b_struct_T *memspace
//                p_struct_T *MeritFunction
//                j_struct_T *WorkingSet
//                i_struct_T *TrialState
//                struct_T *b_QRManager
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(c_struct_T *Flags, b_struct_T *memspace,
                 p_struct_T *MeritFunction, j_struct_T *WorkingSet,
                 i_struct_T *TrialState, struct_T *b_QRManager)
{
  double nlpDualFeasErrorLSQ;
  double nlpDualFeasErrorTmp;
  double optimRelativeFactor;
  int b_idx_max;
  int mEq;
  int mFixed;
  int mIneq;
  int mLB;
  int mLambda;
  int mUB;
  int nVar;
  bool a__1;
  bool a__2;
  bool isFeasible;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda =
      ((((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->sizes[2]) +
        WorkingSet->sizes[3]) +
       WorkingSet->sizes[4]) -
      1;
  if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
    if (0 <= mLambda) {
      (void)std::copy(&TrialState->lambdasqp[0],
                      &TrialState->lambdasqp[mLambda + 1],
                      &TrialState->lambdaStopTest[0]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= mLambda; k++) {
      TrialState->lambdaStopTest[k] = TrialState->lambdasqp[k];
    }
  }
  stopping::computeGradLag(
      TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
      WorkingSet->sizes[2], WorkingSet->sizes[1], WorkingSet->indexFixed,
      WorkingSet->sizes[0], WorkingSet->indexLB, WorkingSet->sizes[3],
      WorkingSet->indexUB, WorkingSet->sizes[4], TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    b_idx_max = 0;
  } else {
    b_idx_max = 1;
    if (WorkingSet->nVar > 1) {
      double smax;
      smax = std::abs(TrialState->grad[0]);
      for (int b_k{2}; b_k <= nVar; b_k++) {
        double s;
        s = std::abs(TrialState->grad[b_k - 1]);
        if (s > smax) {
          b_idx_max = b_k;
          smax = s;
        }
      }
    }
  }
  optimRelativeFactor =
      std::fmax(1.0, std::abs(TrialState->grad[b_idx_max - 1]));
  if (std::isinf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  MeritFunction->nlpPrimalFeasError = stopping::computePrimalFeasError(
      TrialState->xstarsqp, WorkingSet->indexLB, WorkingSet->sizes[3],
      WorkingSet->indexUB, WorkingSet->sizes[4]);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        std::fmax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                (1.0E-6 * MeritFunction->feasRelativeFactor));
  stopping::computeDualFeasError(WorkingSet->nVar, TrialState->gradLag,
                                 &Flags->gradOK,
                                 &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = stopping::computeComplError(
        TrialState->xstarsqp, WorkingSet->sizes[2], WorkingSet->indexLB,
        WorkingSet->sizes[3], WorkingSet->indexUB, WorkingSet->sizes[4],
        TrialState->lambdaStopTest,
        (WorkingSet->sizes[0] + WorkingSet->sizes[1]) + 1);
    MeritFunction->b_firstOrderOpt = std::fmax(MeritFunction->nlpDualFeasError,
                                               MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      double d;
      double nlpComplErrorTmp;
      stopping::b_computeGradLag(
          memspace->workspace_double, WorkingSet->nVar, TrialState->grad,
          WorkingSet->sizes[2], WorkingSet->sizes[1], WorkingSet->indexFixed,
          WorkingSet->sizes[0], WorkingSet->indexLB, WorkingSet->sizes[3],
          WorkingSet->indexUB, WorkingSet->sizes[4],
          TrialState->lambdaStopTestPrev);
      stopping::b_computeDualFeasError(WorkingSet->nVar,
                                       memspace->workspace_double, &a__1,
                                       &nlpDualFeasErrorTmp);
      nlpComplErrorTmp = stopping::computeComplError(
          TrialState->xstarsqp, WorkingSet->sizes[2], WorkingSet->indexLB,
          WorkingSet->sizes[3], WorkingSet->indexUB, WorkingSet->sizes[4],
          TrialState->lambdaStopTestPrev,
          (WorkingSet->sizes[0] + WorkingSet->sizes[1]) + 1);
      d = std::fmax(nlpDualFeasErrorTmp, nlpComplErrorTmp);
      if (d < std::fmax(MeritFunction->nlpDualFeasError,
                        MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = nlpDualFeasErrorTmp;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->b_firstOrderOpt = d;
        if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
          if (0 <= mLambda) {
            (void)std::copy(&TrialState->lambdaStopTestPrev[0],
                            &TrialState->lambdaStopTestPrev[mLambda + 1],
                            &TrialState->lambdaStopTest[0]);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int e_k = 0; e_k <= mLambda; e_k++) {
            TrialState->lambdaStopTest[e_k] =
                TrialState->lambdaStopTestPrev[e_k];
          }
        }
      } else if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
        if (0 <= mLambda) {
          (void)std::copy(&TrialState->lambdaStopTest[0],
                          &TrialState->lambdaStopTest[mLambda + 1],
                          &TrialState->lambdaStopTestPrev[0]);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_k = 0; d_k <= mLambda; d_k++) {
          TrialState->lambdaStopTestPrev[d_k] = TrialState->lambdaStopTest[d_k];
        }
      }
    } else if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
      if (0 <= mLambda) {
        (void)std::copy(&TrialState->lambdaStopTest[0],
                        &TrialState->lambdaStopTest[mLambda + 1],
                        &TrialState->lambdaStopTestPrev[0]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_k = 0; c_k <= mLambda; c_k++) {
        TrialState->lambdaStopTestPrev[c_k] = TrialState->lambdaStopTest[c_k];
      }
    }
    if ((isFeasible &&
         (MeritFunction->nlpDualFeasError <= (1.0E-6 * optimRelativeFactor))) &&
        (MeritFunction->nlpComplError <= (1.0E-6 * optimRelativeFactor))) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        bool guard1{false};
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          int idx;
          bool dxTooSmall;
          bool exitg1;
          dxTooSmall = true;
          idx = 0;
          exitg1 = false;
          while ((!exitg1) && (idx <= (nVar - 1))) {
            if ((1.0E-6 *
                 std::fmax(1.0, std::abs(TrialState->xstarsqp[idx]))) <=
                std::abs(TrialState->delta_x[idx])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              idx++;
            }
          }
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              int nActiveConstr;
              nActiveConstr = WorkingSet->nActiveConstr;
              if (WorkingSet->nActiveConstr > 0) {
                double nlpComplErrorLSQ;
                int b_i;
                int i1;
                int i2;
                if ((TrialState->mNonlinEq + TrialState->mNonlinIneq) > 0) {
                  internal::updateWorkingSetForNewQP(
                      TrialState->xstarsqp, WorkingSet, WorkingSet->sizes[1],
                      WorkingSet->sizes[3], WorkingSet->sizes[4],
                      WorkingSet->sizes[0]);
                }
                stopping::computeLambdaLSQ(nVar, nActiveConstr, b_QRManager,
                                           WorkingSet->ATwset, WorkingSet->ldA,
                                           TrialState->grad, TrialState->lambda,
                                           memspace->workspace_double);
                b_i = mFixed + 1;
                i1 = mFixed + mEq;
                i2 = i1;
                if ((static_cast<int>((i1 - mFixed) < 4)) != 0) {
                  for (int b_idx{b_i}; b_idx <= i1; b_idx++) {
                    TrialState->lambda[b_idx - 1] =
                        -TrialState->lambda[b_idx - 1];
                  }
                } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                  for (int b_idx = b_i; b_idx <= i2; b_idx++) {
                    TrialState->lambda[b_idx - 1] =
                        -TrialState->lambda[b_idx - 1];
                  }
                }
                qpactiveset::parseoutput::sortLambdaQP(
                    TrialState->lambda, WorkingSet->nActiveConstr,
                    WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                    WorkingSet->Wlocalidx, memspace->workspace_double);
                stopping::b_computeGradLag(
                    memspace->workspace_double, nVar, TrialState->grad, mIneq,
                    mEq, WorkingSet->indexFixed, mFixed, WorkingSet->indexLB,
                    mLB, WorkingSet->indexUB, mUB, TrialState->lambda);
                stopping::b_computeDualFeasError(nVar,
                                                 memspace->workspace_double,
                                                 &a__2, &nlpDualFeasErrorLSQ);
                nlpComplErrorLSQ = stopping::computeComplError(
                    TrialState->xstarsqp, mIneq, WorkingSet->indexLB, mLB,
                    WorkingSet->indexUB, mUB, TrialState->lambda, mFixed + 1);
                if ((nlpDualFeasErrorLSQ <= (1.0E-6 * optimRelativeFactor)) &&
                    (nlpComplErrorLSQ <= (1.0E-6 * optimRelativeFactor))) {
                  MeritFunction->nlpDualFeasError = nlpDualFeasErrorLSQ;
                  MeritFunction->nlpComplError = nlpComplErrorLSQ;
                  MeritFunction->b_firstOrderOpt =
                      std::fmax(nlpDualFeasErrorLSQ, nlpComplErrorLSQ);
                  if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
                    if (0 <= mLambda) {
                      (void)std::copy(&TrialState->lambda[0],
                                      &TrialState->lambda[mLambda + 1],
                                      &TrialState->lambdaStopTest[0]);
                    }
                  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                    for (int g_k = 0; g_k <= mLambda; g_k++) {
                      TrialState->lambdaStopTest[g_k] = TrialState->lambda[g_k];
                    }
                  }
                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else if (TrialState->FunctionEvaluations >= 2500) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else {
            /* no actions */
          }
        }
      }
    }
  }
}

//
// Arguments    : b_struct_T *memspace
//                p_struct_T *MeritFunction
//                j_struct_T *WorkingSet
//                i_struct_T *TrialState
//                struct_T *b_QRManager
//                bool *Flags_gradOK
//                bool *Flags_fevalOK
//                bool *Flags_done
//                bool *Flags_stepAccepted
//                bool *Flags_failedLineSearch
//                int *Flags_stepType
// Return Type  : void
//
void test_exit(b_struct_T *memspace, p_struct_T *MeritFunction,
               j_struct_T *WorkingSet, i_struct_T *TrialState,
               struct_T *b_QRManager, bool *Flags_gradOK, bool *Flags_fevalOK,
               bool *Flags_done, bool *Flags_stepAccepted,
               bool *Flags_failedLineSearch, int *Flags_stepType)
{
  double nlpDualFeasErrorLSQ;
  double nlpDualFeasErrorTmp;
  double optimRelativeFactor;
  int b_idx_max;
  int mEq;
  int mFixed;
  int mIneq;
  int mLB;
  int mLambda;
  int mUB;
  int nVar;
  bool a__1;
  bool a__2;
  bool isFeasible;
  *Flags_fevalOK = true;
  *Flags_done = false;
  *Flags_stepAccepted = false;
  *Flags_failedLineSearch = false;
  *Flags_stepType = 1;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mEq = WorkingSet->sizes[1];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mLambda =
      ((((WorkingSet->sizes[0] + WorkingSet->sizes[1]) + WorkingSet->sizes[2]) +
        WorkingSet->sizes[3]) +
       WorkingSet->sizes[4]) -
      1;
  if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
    if (0 <= mLambda) {
      (void)std::copy(&TrialState->lambdasqp[0],
                      &TrialState->lambdasqp[mLambda + 1],
                      &TrialState->lambdaStopTest[0]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= mLambda; k++) {
      TrialState->lambdaStopTest[k] = TrialState->lambdasqp[k];
    }
  }
  stopping::computeGradLag(
      TrialState->gradLag, WorkingSet->nVar, TrialState->grad,
      WorkingSet->sizes[2], WorkingSet->sizes[1], WorkingSet->indexFixed,
      WorkingSet->sizes[0], WorkingSet->indexLB, WorkingSet->sizes[3],
      WorkingSet->indexUB, WorkingSet->sizes[4], TrialState->lambdaStopTest);
  if (WorkingSet->nVar < 1) {
    b_idx_max = 0;
  } else {
    b_idx_max = 1;
    if (WorkingSet->nVar > 1) {
      double smax;
      smax = std::abs(TrialState->grad[0]);
      for (int b_k{2}; b_k <= nVar; b_k++) {
        double s;
        s = std::abs(TrialState->grad[b_k - 1]);
        if (s > smax) {
          b_idx_max = b_k;
          smax = s;
        }
      }
    }
  }
  optimRelativeFactor =
      std::fmax(1.0, std::abs(TrialState->grad[b_idx_max - 1]));
  if (std::isinf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  MeritFunction->nlpPrimalFeasError = stopping::computePrimalFeasError(
      TrialState->xstarsqp, WorkingSet->indexLB, WorkingSet->sizes[3],
      WorkingSet->indexUB, WorkingSet->sizes[4]);
  if (TrialState->sqpIterations == 0) {
    MeritFunction->feasRelativeFactor =
        std::fmax(1.0, MeritFunction->nlpPrimalFeasError);
  }
  isFeasible = (MeritFunction->nlpPrimalFeasError <=
                (1.0E-6 * MeritFunction->feasRelativeFactor));
  stopping::computeDualFeasError(WorkingSet->nVar, TrialState->gradLag,
                                 Flags_gradOK,
                                 &MeritFunction->nlpDualFeasError);
  if (!(*Flags_gradOK)) {
    *Flags_done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = stopping::computeComplError(
        TrialState->xstarsqp, WorkingSet->sizes[2], WorkingSet->indexLB,
        WorkingSet->sizes[3], WorkingSet->indexUB, WorkingSet->sizes[4],
        TrialState->lambdaStopTest,
        (WorkingSet->sizes[0] + WorkingSet->sizes[1]) + 1);
    MeritFunction->b_firstOrderOpt = std::fmax(MeritFunction->nlpDualFeasError,
                                               MeritFunction->nlpComplError);
    if (TrialState->sqpIterations > 1) {
      double d;
      double nlpComplErrorTmp;
      stopping::b_computeGradLag(
          memspace->workspace_double, WorkingSet->nVar, TrialState->grad,
          WorkingSet->sizes[2], WorkingSet->sizes[1], WorkingSet->indexFixed,
          WorkingSet->sizes[0], WorkingSet->indexLB, WorkingSet->sizes[3],
          WorkingSet->indexUB, WorkingSet->sizes[4],
          TrialState->lambdaStopTestPrev);
      stopping::b_computeDualFeasError(WorkingSet->nVar,
                                       memspace->workspace_double, &a__1,
                                       &nlpDualFeasErrorTmp);
      nlpComplErrorTmp = stopping::computeComplError(
          TrialState->xstarsqp, WorkingSet->sizes[2], WorkingSet->indexLB,
          WorkingSet->sizes[3], WorkingSet->indexUB, WorkingSet->sizes[4],
          TrialState->lambdaStopTestPrev,
          (WorkingSet->sizes[0] + WorkingSet->sizes[1]) + 1);
      d = std::fmax(nlpDualFeasErrorTmp, nlpComplErrorTmp);
      if (d < std::fmax(MeritFunction->nlpDualFeasError,
                        MeritFunction->nlpComplError)) {
        MeritFunction->nlpDualFeasError = nlpDualFeasErrorTmp;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->b_firstOrderOpt = d;
        if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
          if (0 <= mLambda) {
            (void)std::copy(&TrialState->lambdaStopTestPrev[0],
                            &TrialState->lambdaStopTestPrev[mLambda + 1],
                            &TrialState->lambdaStopTest[0]);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int e_k = 0; e_k <= mLambda; e_k++) {
            TrialState->lambdaStopTest[e_k] =
                TrialState->lambdaStopTestPrev[e_k];
          }
        }
      } else if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
        if (0 <= mLambda) {
          (void)std::copy(&TrialState->lambdaStopTest[0],
                          &TrialState->lambdaStopTest[mLambda + 1],
                          &TrialState->lambdaStopTestPrev[0]);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_k = 0; d_k <= mLambda; d_k++) {
          TrialState->lambdaStopTestPrev[d_k] = TrialState->lambdaStopTest[d_k];
        }
      }
    } else if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
      if (0 <= mLambda) {
        (void)std::copy(&TrialState->lambdaStopTest[0],
                        &TrialState->lambdaStopTest[mLambda + 1],
                        &TrialState->lambdaStopTestPrev[0]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_k = 0; c_k <= mLambda; c_k++) {
        TrialState->lambdaStopTestPrev[c_k] = TrialState->lambdaStopTest[c_k];
      }
    }
    if ((isFeasible &&
         (MeritFunction->nlpDualFeasError <= (1.0E-6 * optimRelativeFactor))) &&
        (MeritFunction->nlpComplError <= (1.0E-6 * optimRelativeFactor))) {
      *Flags_done = true;
      TrialState->sqpExitFlag = 1;
    } else if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
      *Flags_done = true;
      TrialState->sqpExitFlag = -3;
    } else {
      bool guard1{false};
      guard1 = false;
      if (TrialState->sqpIterations > 0) {
        int idx;
        bool dxTooSmall;
        bool exitg1;
        dxTooSmall = true;
        idx = 0;
        exitg1 = false;
        while ((!exitg1) && (idx <= (nVar - 1))) {
          if ((1.0E-6 * std::fmax(1.0, std::abs(TrialState->xstarsqp[idx]))) <=
              std::abs(TrialState->delta_x[idx])) {
            dxTooSmall = false;
            exitg1 = true;
          } else {
            idx++;
          }
        }
        if (dxTooSmall) {
          if (!isFeasible) {
            *Flags_stepType = 2;
            guard1 = true;
          } else {
            int nActiveConstr;
            nActiveConstr = WorkingSet->nActiveConstr;
            if (WorkingSet->nActiveConstr > 0) {
              double nlpComplErrorLSQ;
              int b_i;
              int i1;
              int i2;
              if ((TrialState->mNonlinEq + TrialState->mNonlinIneq) > 0) {
                internal::updateWorkingSetForNewQP(
                    TrialState->xstarsqp, WorkingSet, WorkingSet->sizes[1],
                    WorkingSet->sizes[3], WorkingSet->sizes[4],
                    WorkingSet->sizes[0]);
              }
              stopping::computeLambdaLSQ(nVar, nActiveConstr, b_QRManager,
                                         WorkingSet->ATwset, WorkingSet->ldA,
                                         TrialState->grad, TrialState->lambda,
                                         memspace->workspace_double);
              b_i = mFixed + 1;
              i1 = mFixed + mEq;
              i2 = i1;
              if ((static_cast<int>((i1 - mFixed) < 4)) != 0) {
                for (int b_idx{b_i}; b_idx <= i1; b_idx++) {
                  TrialState->lambda[b_idx - 1] =
                      -TrialState->lambda[b_idx - 1];
                }
              } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                for (int b_idx = b_i; b_idx <= i2; b_idx++) {
                  TrialState->lambda[b_idx - 1] =
                      -TrialState->lambda[b_idx - 1];
                }
              }
              qpactiveset::parseoutput::sortLambdaQP(
                  TrialState->lambda, WorkingSet->nActiveConstr,
                  WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid,
                  WorkingSet->Wlocalidx, memspace->workspace_double);
              stopping::b_computeGradLag(
                  memspace->workspace_double, nVar, TrialState->grad, mIneq,
                  mEq, WorkingSet->indexFixed, mFixed, WorkingSet->indexLB, mLB,
                  WorkingSet->indexUB, mUB, TrialState->lambda);
              stopping::b_computeDualFeasError(nVar, memspace->workspace_double,
                                               &a__2, &nlpDualFeasErrorLSQ);
              nlpComplErrorLSQ = stopping::computeComplError(
                  TrialState->xstarsqp, mIneq, WorkingSet->indexLB, mLB,
                  WorkingSet->indexUB, mUB, TrialState->lambda, mFixed + 1);
              if ((nlpDualFeasErrorLSQ <= (1.0E-6 * optimRelativeFactor)) &&
                  (nlpComplErrorLSQ <= (1.0E-6 * optimRelativeFactor))) {
                MeritFunction->nlpDualFeasError = nlpDualFeasErrorLSQ;
                MeritFunction->nlpComplError = nlpComplErrorLSQ;
                MeritFunction->b_firstOrderOpt =
                    std::fmax(nlpDualFeasErrorLSQ, nlpComplErrorLSQ);
                if ((static_cast<int>((mLambda + 1) < 4)) != 0) {
                  if (0 <= mLambda) {
                    (void)std::copy(&TrialState->lambda[0],
                                    &TrialState->lambda[mLambda + 1],
                                    &TrialState->lambdaStopTest[0]);
                  }
                } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                  for (int g_k = 0; g_k <= mLambda; g_k++) {
                    TrialState->lambdaStopTest[g_k] = TrialState->lambda[g_k];
                  }
                }
                *Flags_done = true;
                TrialState->sqpExitFlag = 1;
              } else {
                *Flags_done = true;
                TrialState->sqpExitFlag = 2;
              }
            } else {
              *Flags_done = true;
              TrialState->sqpExitFlag = 2;
            }
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        if (TrialState->sqpIterations >= 400) {
          *Flags_done = true;
          TrialState->sqpExitFlag = 0;
        } else if (TrialState->FunctionEvaluations >= 2500) {
          *Flags_done = true;
          TrialState->sqpExitFlag = 0;
        } else {
          /* no actions */
        }
      }
    }
  }
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for test_exit.cpp
//
// [EOF]
//
