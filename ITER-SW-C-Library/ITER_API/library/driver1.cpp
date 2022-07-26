//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "driver1.h"
#include "ITER_API_internal_types.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include <algorithm>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : const double H[7][7]
//                const double f[8]
//                m_struct_T *solution
//                b_struct_T *memspace
//                o_struct_T *d_workingset
//                struct_T *c_qrmanager
//                y_struct_T *c_cholmanager
//                x_struct_T *b_objective
//                const e_struct_T *options
//                e_struct_T *runTimeOptions
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const double H[7][7], const double f[8], m_struct_T *solution,
            b_struct_T *memspace, o_struct_T *d_workingset,
            struct_T *c_qrmanager, y_struct_T *c_cholmanager,
            x_struct_T *b_objective, const e_struct_T *options,
            e_struct_T *runTimeOptions)
{
  o_struct_T e_workingset;
  int nVar;
  bool guard1{false};
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = (options->PricingTolerance <= 0.0);
  nVar = d_workingset->nVar - 1;
  guard1 = false;
  if (d_workingset->probType == 3) {
    int b_i;
    int i1;
    int i2;
    b_i = d_workingset->sizes[0];
    for (int idx{0}; idx < b_i; idx++) {
      solution->xstar[d_workingset->indexFixed[idx] - 1] =
          d_workingset->ub[d_workingset->indexFixed[idx] - 1];
    }
    i1 = d_workingset->sizes[3];
    for (int b_idx{0}; b_idx < i1; b_idx++) {
      if (d_workingset
              ->isActiveConstr[(d_workingset->isActiveIdx[3] + b_idx) - 1]) {
        solution->xstar[d_workingset->indexLB[b_idx] - 1] =
            -d_workingset->lb[d_workingset->indexLB[b_idx] - 1];
      }
    }
    i2 = d_workingset->sizes[4];
    for (int c_idx{0}; c_idx < i2; c_idx++) {
      if (d_workingset
              ->isActiveConstr[(d_workingset->isActiveIdx[4] + c_idx) - 1]) {
        solution->xstar[d_workingset->indexUB[c_idx] - 1] =
            d_workingset->ub[d_workingset->indexUB[c_idx] - 1];
      }
    }
    initialize::PresolveWorkingSet(solution, memspace, d_workingset,
                                   c_qrmanager, options);
    if (solution->state >= 0) {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }
  if (guard1) {
    double d;
    solution->iterations = 0;
    solution->maxConstr =
        WorkingSet::b_maxConstraintViolation(d_workingset, solution->xstar);
    d = options->ConstraintTolerance * runTimeOptions->ConstrRelTolFactor;
    if (solution->maxConstr > d) {
      int f_workingset;
      int idxEndIneq;
      int idxStartIneq;
      int mConstr;
      int mEqFixed;
      solution->xstar[d_workingset->nVar] = solution->maxConstr + 1.0;
      e_workingset = *d_workingset;
      if (d_workingset->probType == 3) {
        f_workingset = 1;
      } else {
        f_workingset = 4;
      }
      WorkingSet::setProblemType(&e_workingset, f_workingset);
      idxStartIneq = (e_workingset.nWConstr[0] + e_workingset.nWConstr[1]) + 1;
      idxEndIneq = e_workingset.nActiveConstr;
      for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq;
           idx_global++) {
        e_workingset.isActiveConstr
            [(e_workingset.isActiveIdx[e_workingset.Wid[idx_global - 1] - 1] +
              e_workingset.Wlocalidx[idx_global - 1]) -
             2] = false;
      }
      e_workingset.nWConstr[2] = 0;
      e_workingset.nWConstr[3] = 0;
      e_workingset.nWConstr[4] = 0;
      e_workingset.nActiveConstr =
          e_workingset.nWConstr[0] + e_workingset.nWConstr[1];
      b_objective->prev_objtype = b_objective->objtype;
      b_objective->prev_nvar = b_objective->b_nvar;
      b_objective->prev_hasLinear = b_objective->hasLinear;
      b_objective->objtype = 5;
      b_objective->b_nvar = d_workingset->nVar + 1;
      b_objective->gammaScalar = 1.0;
      b_objective->hasLinear = true;
      solution->fstar = Objective::computeFval(
          b_objective, memspace->workspace_double, H, f, solution->xstar);
      solution->state = 5;
      iterate(H, f, solution, memspace, &e_workingset, c_qrmanager,
              c_cholmanager, b_objective, options->SolverName,
              1.4901161193847657E-10, options->ConstraintTolerance, d,
              options->PricingTolerance, options->IterDisplayQP,
              runTimeOptions);
      if (e_workingset.isActiveConstr
              [(e_workingset.isActiveIdx[3] + e_workingset.sizes[3]) - 2]) {
        int d_idx;
        bool exitg1;
        d_idx = e_workingset.sizes[0] + e_workingset.sizes[1];
        exitg1 = false;
        while ((!exitg1) && ((d_idx + 1) <= e_workingset.nActiveConstr)) {
          if ((e_workingset.Wid[d_idx] == 4) &&
              (e_workingset.Wlocalidx[d_idx] == e_workingset.sizes[3])) {
            int b_TYPE_tmp;
            int i4;
            b_TYPE_tmp = e_workingset.Wid[d_idx] - 1;
            e_workingset.isActiveConstr[(e_workingset.isActiveIdx[b_TYPE_tmp] +
                                         e_workingset.Wlocalidx[d_idx]) -
                                        2] = false;
            e_workingset.Wid[d_idx] =
                e_workingset.Wid[e_workingset.nActiveConstr - 1];
            e_workingset.Wlocalidx[d_idx] =
                e_workingset.Wlocalidx[e_workingset.nActiveConstr - 1];
            i4 = e_workingset.nVar;
            for (int f_idx{0}; f_idx < i4; f_idx++) {
              e_workingset.ATwset[f_idx + (e_workingset.ldA * d_idx)] =
                  e_workingset
                      .ATwset[f_idx + (e_workingset.ldA *
                                       (e_workingset.nActiveConstr - 1))];
            }
            e_workingset.bwset[d_idx] =
                e_workingset.bwset[e_workingset.nActiveConstr - 1];
            e_workingset.nActiveConstr--;
            e_workingset.nWConstr[b_TYPE_tmp]--;
            exitg1 = true;
          } else {
            d_idx++;
          }
        }
      }
      mConstr = e_workingset.nActiveConstr;
      mEqFixed = e_workingset.sizes[0] + e_workingset.sizes[1];
      while ((mConstr > mEqFixed) && (mConstr > d_workingset->nVar)) {
        int TYPE_tmp;
        int i3;
        TYPE_tmp = e_workingset.Wid[mConstr - 1] - 1;
        e_workingset.isActiveConstr[(e_workingset.isActiveIdx[TYPE_tmp] +
                                     e_workingset.Wlocalidx[mConstr - 1]) -
                                    2] = false;
        e_workingset.Wid[mConstr - 1] =
            e_workingset.Wid[e_workingset.nActiveConstr - 1];
        e_workingset.Wlocalidx[mConstr - 1] =
            e_workingset.Wlocalidx[e_workingset.nActiveConstr - 1];
        i3 = e_workingset.nVar;
        for (int e_idx{0}; e_idx < i3; e_idx++) {
          e_workingset.ATwset[e_idx + (e_workingset.ldA * (mConstr - 1))] =
              e_workingset.ATwset[e_idx + (e_workingset.ldA *
                                           (e_workingset.nActiveConstr - 1))];
        }
        e_workingset.bwset[mConstr - 1] =
            e_workingset.bwset[e_workingset.nActiveConstr - 1];
        e_workingset.nActiveConstr--;
        e_workingset.nWConstr[TYPE_tmp]--;
        mConstr--;
      }
      solution->maxConstr = solution->xstar[d_workingset->nVar];
      WorkingSet::setProblemType(&e_workingset, d_workingset->probType);
      b_objective->objtype = b_objective->prev_objtype;
      b_objective->b_nvar = b_objective->prev_nvar;
      b_objective->hasLinear = b_objective->prev_hasLinear;
      *d_workingset = e_workingset;
      if (solution->state != 0) {
        solution->maxConstr = WorkingSet::b_maxConstraintViolation(
            &e_workingset, solution->xstar);
        if (solution->maxConstr > d) {
          int h_n;
          h_n = e_workingset.mConstrMax;
          if ((static_cast<int>(e_workingset.mConstrMax < 4)) != 0) {
            if (0 <= (h_n - 1)) {
              (void)std::memset(&solution->lambda[0], 0,
                                (static_cast<unsigned int>(h_n)) *
                                    (sizeof(double)));
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

            for (int b_k = 0; b_k < h_n; b_k++) {
              solution->lambda[b_k] = 0.0;
            }
          }
          solution->fstar = Objective::computeFval(
              b_objective, memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            double maxConstr_new;
            if ((static_cast<int>((nVar + 1) < 4)) != 0) {
              if (0 <= nVar) {
                (void)std::copy(&solution->xstar[0], &solution->xstar[nVar + 1],
                                &solution->searchDir[0]);
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int k = 0; k <= nVar; k++) {
                solution->searchDir[k] = solution->xstar[k];
              }
            }
            initialize::PresolveWorkingSet(solution, memspace, &e_workingset,
                                           c_qrmanager, options);
            *d_workingset = e_workingset;
            maxConstr_new = WorkingSet::b_maxConstraintViolation(
                d_workingset, solution->xstar);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              if ((static_cast<int>((nVar + 1) < 4)) != 0) {
                if (0 <= nVar) {
                  (void)std::copy(&solution->searchDir[0],
                                  &solution->searchDir[nVar + 1],
                                  &solution->xstar[0]);
                }
              } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                for (int c_k = 0; c_k <= nVar; c_k++) {
                  solution->xstar[c_k] = solution->searchDir[c_k];
                }
              }
            }
          }
          iterate(H, f, solution, memspace, d_workingset, c_qrmanager,
                  c_cholmanager, b_objective, options->SolverName,
                  options->StepTolerance, options->ConstraintTolerance,
                  options->ObjectiveLimit, options->PricingTolerance,
                  options->IterDisplayQP, runTimeOptions);
        }
      }
    } else {
      iterate(H, f, solution, memspace, d_workingset, c_qrmanager,
              c_cholmanager, b_objective, options->SolverName,
              options->StepTolerance, options->ConstraintTolerance,
              options->ObjectiveLimit, options->PricingTolerance,
              options->IterDisplayQP, runTimeOptions);
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for driver1.cpp
//
// [EOF]
//
