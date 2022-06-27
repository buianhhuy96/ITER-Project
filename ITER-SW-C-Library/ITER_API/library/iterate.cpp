//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: iterate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "iterate.h"
#include "ITER_API_internal_types.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "maxConstraintViolation.h"
#include "printInfo.h"
#include "ratiotest.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xgemv.h"
#include "xnrm2.h"
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// Arguments    : const double H[7][7]
//                const double f[8]
//                i_struct_T *solution
//                b_struct_T *memspace
//                j_struct_T *d_workingset
//                struct_T *c_qrmanager
//                s_struct_T *c_cholmanager
//                r_struct_T *b_objective
//                const char options_SolverName[7]
//                double options_StepTolerance
//                double options_ConstraintTolerance
//                double options_ObjectiveLimit
//                double options_PricingTolerance
//                bool options_IterDisplayQP
//                const d_struct_T *runTimeOptions
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void iterate(const double H[7][7], const double f[8], i_struct_T *solution,
             b_struct_T *memspace, j_struct_T *d_workingset,
             struct_T *c_qrmanager, s_struct_T *c_cholmanager,
             r_struct_T *b_objective, const char options_SolverName[7],
             double options_StepTolerance, double options_ConstraintTolerance,
             double options_ObjectiveLimit, double options_PricingTolerance,
             bool options_IterDisplayQP, const d_struct_T *runTimeOptions)
{
  static const char b_cv[13]{'N', 'o', 'r', 'm', 'a', 'l', ' ',
                             ' ', ' ', ' ', ' ', ' ', ' '};
  static const char cv1[13]{'P', 'h', 'a', 's', 'e', ' ', 'O',
                            'n', 'e', ' ', ' ', ' ', ' '};
  static const char cv2[13]{'R', 'e', 'g', 'u', 'l', 'a', 'r',
                            'i', 'z', 'e', 'd', ' ', ' '};
  static const char cv3[13]{'P', 'h', 'a', 's', 'e', ' ', 'O',
                            'n', 'e', ' ', 'R', 'e', 'g'};
  static const char b[7]{'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  double alpha;
  double normDelta;
  double tolDelta;
  int TYPE;
  int activeConstrChangedType;
  int activeSetChangeID;
  int b_activeSetChangeID;
  int globalActiveConstrIdx;
  int h_n;
  int localActiveConstrIdx;
  int nVar;
  char varargin_4[14];
  char stepType_str[13];
  bool newBlocking;
  bool subProblemChanged;
  bool updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = b_objective->objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = d_workingset->nVar;
  activeConstrChangedType = 1;
  localActiveConstrIdx = 0;
  globalActiveConstrIdx = 0;
  Objective::computeGrad_StoreHx(b_objective, H, f, solution->xstar);
  solution->fstar = Objective::computeFval_ReuseHx(
      b_objective, memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions->MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }
  h_n = d_workingset->mConstrMax;
  if ((static_cast<int>(h_n < 4)) != 0) {
    if (0 <= (h_n - 1)) {
      (void)std::memset(&solution->lambda[0], 0,
                        (static_cast<unsigned int>(h_n)) * (sizeof(double)));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < h_n; k++) {
      solution->lambda[k] = 0.0;
    }
  }
  if ((solution->iterations == 0) && options_IterDisplayQP) {
    (void)printf("                          First-order                        "
                 "                                                  Active\n");
    (void)fflush(stdout);
    (void)printf(
        " Iter            Fval      Optimality     Feasibility           alpha "
        "   Norm of step           Action     Constraints    Step T"
        "ype\n");
    (void)fflush(stdout);
    (void)printf("\n");
    (void)fflush(stdout);
    switch (d_workingset->probType) {
    case 1:
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < 13; i1++) {
        stepType_str[i1] = cv1[i1];
      }
      break;
    case 2:
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < 13; i2++) {
        stepType_str[i2] = cv2[i2];
      }
      break;
    case 4:
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < 13; i3++) {
        stepType_str[i3] = cv3[i3];
      }
      break;
    default:
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i = 0; b_i < 13; b_i++) {
        stepType_str[b_i] = b_cv[b_i];
      }
      break;
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < 13; i4++) {
      varargin_4[i4] = stepType_str[i4];
    }
    varargin_4[13] = '\x00';
    (void)printf("%5i  %14.6e                                                  "
                 "                                          %5i    %s",
                 solution->iterations, solution->fstar,
                 d_workingset->nActiveConstr, &varargin_4[0]);
    (void)fflush(stdout);
    (void)printf("\n");
    (void)fflush(stdout);
  }
  int exitg1;
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      bool guard1{false};
      bool guard2{false};
      newBlocking = false;
      guard1 = false;
      guard2 = false;
      if (subProblemChanged) {
        int ret;
        switch (activeSetChangeID) {
        case 1:
          QRManager::squareQ_appendCol(
              c_qrmanager, d_workingset->ATwset,
              (d_workingset->ldA * (d_workingset->nActiveConstr - 1)) + 1);
          break;
        case -1:
          QRManager::deleteColMoveEnd(c_qrmanager, globalActiveConstrIdx);
          break;
        default:
          QRManager::factorQR(c_qrmanager, d_workingset->ATwset, nVar,
                              d_workingset->nActiveConstr, d_workingset->ldA);
          QRManager::computeQ_(c_qrmanager, c_qrmanager->mrows);
          break;
        }
        ret = memcmp(&options_SolverName[0], &b[0], 7);
        compute_deltax(H, solution, memspace, c_qrmanager, c_cholmanager,
                       b_objective, ret == 0);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = internal::blas::h_xnrm2(nVar, solution->searchDir);
          if ((normDelta < options_StepTolerance) ||
              (d_workingset->nActiveConstr >= nVar)) {
            guard2 = true;
          } else {
            bool isLP;
            isLP = (TYPE == 5);
            if (isLP || (runTimeOptions->RemainFeasible)) {
              feasibleratiotest(
                  solution->xstar, solution->searchDir,
                  memspace->workspace_double, d_workingset->nVar,
                  d_workingset->lb, d_workingset->ub, d_workingset->indexLB,
                  d_workingset->indexUB, d_workingset->sizes,
                  d_workingset->isActiveIdx, d_workingset->isActiveConstr,
                  d_workingset->nWConstr, isLP, options_ConstraintTolerance,
                  &alpha, &newBlocking, &activeConstrChangedType,
                  &localActiveConstrIdx);
            } else {
              ratiotest(solution->xstar, solution->searchDir,
                        memspace->workspace_double, d_workingset->nVar,
                        d_workingset->lb, d_workingset->ub,
                        d_workingset->indexLB, d_workingset->indexUB,
                        d_workingset->sizes, d_workingset->isActiveIdx,
                        d_workingset->isActiveConstr, d_workingset->nWConstr,
                        options_ConstraintTolerance, &tolDelta, &alpha,
                        &newBlocking, &activeConstrChangedType,
                        &localActiveConstrIdx);
            }
            if (newBlocking) {
              switch (activeConstrChangedType) {
              case 3:
                d_workingset->nWConstr[2]++;
                d_workingset->isActiveConstr[(d_workingset->isActiveIdx[2] +
                                              localActiveConstrIdx) -
                                             2] = true;
                d_workingset->nActiveConstr++;
                d_workingset->Wid[d_workingset->nActiveConstr - 1] = 3;
                d_workingset->Wlocalidx[d_workingset->nActiveConstr - 1] =
                    localActiveConstrIdx;
                // A check that is always false is detected at compile-time.
                // Eliminating code that follows.
                break;
              case 4:
                WorkingSet::addBoundToActiveSetMatrix_(d_workingset, 4,
                                                       localActiveConstrIdx);
                break;
              default:
                WorkingSet::addBoundToActiveSetMatrix_(d_workingset, 5,
                                                       localActiveConstrIdx);
                break;
              }
              activeSetChangeID = 1;
            } else {
              if (b_objective->objtype == 5) {
                if (internal::blas::h_xnrm2(b_objective->b_nvar,
                                            solution->searchDir) >
                    ((100.0 * (static_cast<double>(b_objective->b_nvar))) *
                     1.4901161193847656E-8)) {
                  solution->state = 3;
                } else {
                  solution->state = 4;
                }
              }
              subProblemChanged = false;
              if (d_workingset->nActiveConstr == 0) {
                solution->state = 1;
              }
            }
            if ((nVar >= 1) && (!(alpha == 0.0))) {
              int ixlast;
              ixlast = nVar - 1;
              for (int c_k{0}; c_k <= ixlast; c_k++) {
                solution->xstar[c_k] += alpha * solution->searchDir[c_k];
              }
            }
            Objective::computeGrad_StoreHx(b_objective, H, f, solution->xstar);
            updateFval = true;
            guard1 = true;
          }
        }
      } else {
        if (0 <= (nVar - 1)) {
          (void)std::memset(&solution->searchDir[0], 0,
                            (static_cast<unsigned int>(nVar)) *
                                (sizeof(double)));
        }
        normDelta = 0.0;
        guard2 = true;
      }
      if (guard2) {
        int nActiveConstr_tmp;
        nActiveConstr_tmp = c_qrmanager->ncols;
        if (c_qrmanager->ncols > 0) {
          bool b_guard1{false};
          b_guard1 = false;
          if (b_objective->objtype != 4) {
            double tol;
            bool b_nonDegenerate;
            bool nonDegenerate;
            tol = (100.0 * (static_cast<double>(c_qrmanager->mrows))) *
                  2.2204460492503131E-16;
            if ((c_qrmanager->mrows > 0) && (c_qrmanager->ncols > 0)) {
              nonDegenerate = true;
            } else {
              nonDegenerate = false;
            }
            b_nonDegenerate = nonDegenerate;
            if (nonDegenerate) {
              int c_idx;
              int idxQR;
              bool b_guard2{false};
              bool exitg2;
              c_idx = nActiveConstr_tmp;
              b_guard2 = false;
              if (c_qrmanager->mrows < c_qrmanager->ncols) {
                idxQR = c_qrmanager->mrows +
                        (c_qrmanager->ldq * (c_qrmanager->ncols - 1));
                exitg2 = false;
                while ((!exitg2) && (c_idx > c_qrmanager->mrows)) {
                  if (std::abs((&c_qrmanager->QR[0][0])[idxQR - 1]) >= tol) {
                    c_idx--;
                    idxQR -= c_qrmanager->ldq;
                  } else {
                    exitg2 = true;
                  }
                }
                b_nonDegenerate = (c_idx == c_qrmanager->mrows);
                if (b_nonDegenerate) {
                  b_guard2 = true;
                }
              } else {
                b_guard2 = true;
              }
              if (b_guard2) {
                idxQR = c_idx + (c_qrmanager->ldq * (c_idx - 1));
                exitg2 = false;
                while ((!exitg2) && (c_idx >= 1)) {
                  if (std::abs((&c_qrmanager->QR[0][0])[idxQR - 1]) >= tol) {
                    c_idx--;
                    idxQR = (idxQR - c_qrmanager->ldq) - 1;
                  } else {
                    exitg2 = true;
                  }
                }
                b_nonDegenerate = (c_idx == 0);
              }
            }
            if (!b_nonDegenerate) {
              solution->state = -7;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
          if (b_guard1) {
            internal::blas::b_xgemv(c_qrmanager->mrows, c_qrmanager->ncols,
                                    c_qrmanager->Q, c_qrmanager->ldq,
                                    b_objective->grad,
                                    memspace->workspace_double);
            if (c_qrmanager->ncols != 0) {
              for (int j{nActiveConstr_tmp}; j >= 1; j--) {
                int jjA;
                jjA = (j + ((j - 1) * c_qrmanager->ldq)) - 1;
                (&memspace->workspace_double[0][0])[j - 1] /=
                    (&c_qrmanager->QR[0][0])[jjA];
                for (int c_i{0}; c_i <= (j - 2); c_i++) {
                  int c_ix;
                  c_ix = (j - c_i) - 2;
                  (&memspace->workspace_double[0][0])[c_ix] -=
                      (&memspace->workspace_double[0][0])[j - 1] *
                      (&c_qrmanager->QR[0][0])[(jjA - c_i) - 1];
                }
              }
            }
            for (int b_idx{0}; b_idx < nActiveConstr_tmp; b_idx++) {
              solution->lambda[b_idx] =
                  -(&memspace->workspace_double[0][0])[b_idx];
            }
          }
        }
        if ((solution->state != -7) || (d_workingset->nActiveConstr > nVar)) {
          double minLambda;
          int i5;
          int i6;
          int idxMinLambda;
          idxMinLambda = 0;
          minLambda =
              (options_PricingTolerance * runTimeOptions->ProbRelTolFactor) *
              (static_cast<double>(TYPE != 5));
          i5 = (d_workingset->nWConstr[0] + d_workingset->nWConstr[1]) + 1;
          i6 = d_workingset->nActiveConstr;
          for (int idx{i5}; idx <= i6; idx++) {
            double d;
            d = solution->lambda[idx - 1];
            if (d < minLambda) {
              minLambda = d;
              idxMinLambda = idx;
            }
          }
          if (idxMinLambda == 0) {
            solution->state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            activeConstrChangedType = d_workingset->Wid[idxMinLambda - 1];
            localActiveConstrIdx = d_workingset->Wlocalidx[idxMinLambda - 1];
            WorkingSet::removeConstr(d_workingset, idxMinLambda);
            solution->lambda[idxMinLambda - 1] = 0.0;
          }
        } else {
          int activeConstrChangedType_tmp;
          int idxMinLambda;
          idxMinLambda = d_workingset->nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = d_workingset->nActiveConstr;
          subProblemChanged = true;
          activeConstrChangedType_tmp = d_workingset->nActiveConstr - 1;
          activeConstrChangedType =
              d_workingset->Wid[activeConstrChangedType_tmp];
          localActiveConstrIdx =
              d_workingset->Wlocalidx[activeConstrChangedType_tmp];
          WorkingSet::removeConstr(d_workingset, d_workingset->nActiveConstr);
          solution->lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        alpha = rtNaN;
        guard1 = true;
      }
      if (guard1) {
        b_activeSetChangeID = activeSetChangeID;
        stopping::checkStoppingAndUpdateFval(
            &b_activeSetChangeID, f, solution, memspace, b_objective,
            d_workingset, c_qrmanager, options_ConstraintTolerance,
            options_ObjectiveLimit, options_IterDisplayQP,
            runTimeOptions->MaxIterations, runTimeOptions->ConstrRelTolFactor,
            updateFval);
        activeSetChangeID = b_activeSetChangeID;
        if (options_IterDisplayQP) {
          int d_lda;
          int i7;
          int idxmax;
          if ((solution->iterations - ((solution->iterations / 50) * 50)) ==
              0) {
            (void)printf(
                "                          First-order                         "
                "                                                 Active\n");
            (void)fflush(stdout);
            (void)printf(" Iter            Fval      Optimality     "
                         "Feasibility           alpha    Norm of step          "
                         " Action     Constraints    Step T"
                         "ype\n");
            (void)fflush(stdout);
            (void)printf("\n");
            (void)fflush(stdout);
          } else {
            solution->maxConstr = WorkingSet::b_maxConstraintViolation(
                d_workingset, solution->xstar);
          }
          i7 = d_workingset->nVar;
          d_lda = d_workingset->ldA;
          for (int b_k{0}; b_k < i7; b_k++) {
            (&memspace->workspace_double[0][0])[b_k] = b_objective->grad[b_k];
          }
          if ((d_workingset->nVar != 0) && (d_workingset->nActiveConstr != 0)) {
            int b_i8;
            int b_ix;
            int iac;
            b_ix = 0;
            b_i8 = (d_workingset->ldA * (d_workingset->nActiveConstr - 1)) + 1;
            iac = 1;
            while (((d_lda > 0) && (iac <= b_i8)) ||
                   ((d_lda < 0) && (iac >= b_i8))) {
              int i9;
              i9 = (iac + i7) - 1;
              for (int ia{iac}; ia <= i9; ia++) {
                int i10;
                i10 = ia - iac;
                (&memspace->workspace_double[0][0])[i10] +=
                    d_workingset->ATwset[ia - 1] * solution->lambda[b_ix];
              }
              b_ix++;
              iac += d_lda;
            }
          }
          if (d_workingset->nVar < 1) {
            idxmax = 0;
          } else {
            idxmax = 1;
            if (d_workingset->nVar > 1) {
              double smax;
              smax = std::abs((&memspace->workspace_double[0][0])[0]);
              for (int d_k{2}; d_k <= i7; d_k++) {
                double s;
                s = std::abs((&memspace->workspace_double[0][0])[d_k - 1]);
                if (s > smax) {
                  idxmax = d_k;
                  smax = s;
                }
              }
            }
          }
          solution->firstorderopt =
              std::abs((&memspace->workspace_double[0][0])[idxmax - 1]);
          display::printInfo(
              newBlocking, d_workingset->probType, alpha, normDelta,
              activeConstrChangedType, localActiveConstrIdx,
              b_activeSetChangeID, solution->fstar, solution->firstorderopt,
              solution->maxConstr, solution->iterations, d_workingset->indexLB,
              d_workingset->indexUB, d_workingset->nActiveConstr);
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = Objective::computeFval_ReuseHx(
            b_objective, memspace->workspace_double, f, solution->xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for iterate.cpp
//
// [EOF]
//
