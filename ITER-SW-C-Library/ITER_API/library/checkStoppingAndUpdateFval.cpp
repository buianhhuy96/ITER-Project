//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingAndUpdateFval.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "checkStoppingAndUpdateFval.h"
#include "ITER_API_internal_types.h"
#include "computeFval_ReuseHx.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <string.h>

// Function Definitions
//
// Arguments    : int *activeSetChangeID
//                const double f[8]
//                i_struct_T *solution
//                b_struct_T *memspace
//                const r_struct_T *b_objective
//                const j_struct_T *d_workingset
//                struct_T *c_qrmanager
//                double options_ConstraintTolerance
//                double options_ObjectiveLimit
//                bool options_IterDisplayQP
//                int runTimeOptions_MaxIterations
//                double runTimeOptions_ConstrRelTolFactor
//                bool updateFval
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(
    int *activeSetChangeID, const double f[8], i_struct_T *solution,
    b_struct_T *memspace, const r_struct_T *b_objective,
    const j_struct_T *d_workingset, struct_T *c_qrmanager,
    double options_ConstraintTolerance, double options_ObjectiveLimit,
    bool options_IterDisplayQP, int runTimeOptions_MaxIterations,
    double runTimeOptions_ConstrRelTolFactor, bool updateFval)
{
  int b_objType;
  int nVar;
  int nVar_tmp;
  solution->iterations++;
  nVar_tmp = b_objective->b_nvar - 1;
  nVar = nVar_tmp;
  b_objType = b_objective->objtype;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (b_objective->objtype == 5))) {
    solution->state = 0;
  }
  if ((solution->iterations - ((solution->iterations / 50) * 50)) == 0) {
    double tempMaxConstr;
    solution->maxConstr =
        WorkingSet::b_maxConstraintViolation(d_workingset, solution->xstar);
    tempMaxConstr = solution->maxConstr;
    if (b_objective->objtype == 5) {
      tempMaxConstr = solution->maxConstr - solution->xstar[nVar_tmp];
    }
    if (tempMaxConstr >
        (options_ConstraintTolerance * runTimeOptions_ConstrRelTolFactor)) {
      double constrViolation_new;
      bool nonDegenerateWset;
      if ((static_cast<int>((nVar_tmp + 1) < 4)) != 0) {
        if (0 <= nVar_tmp) {
          (void)std::copy(&solution->xstar[0], &solution->xstar[nVar_tmp + 1],
                          &solution->searchDir[0]);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int k = 0; k <= nVar; k++) {
          solution->searchDir[k] = solution->xstar[k];
        }
      }
      nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
          memspace->workspace_double, solution->searchDir, d_workingset,
          c_qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }
      *activeSetChangeID = 0;
      constrViolation_new = WorkingSet::b_maxConstraintViolation(
          d_workingset, solution->searchDir);
      if (constrViolation_new < solution->maxConstr) {
        if ((static_cast<int>((nVar + 1) < 4)) != 0) {
          if (0 <= nVar) {
            (void)std::copy(&solution->searchDir[0],
                            &solution->searchDir[nVar + 1],
                            &solution->xstar[0]);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int idx = 0; idx <= nVar; idx++) {
            solution->xstar[idx] = solution->searchDir[idx];
          }
        }
        solution->maxConstr = constrViolation_new;
      }
    }
  }
  if (updateFval &&
      ((options_ObjectiveLimit > rtMinusInf) || options_IterDisplayQP)) {
    solution->fstar = Objective::computeFval_ReuseHx(
        b_objective, memspace->workspace_double, f, solution->xstar);
    if (((options_ObjectiveLimit > rtMinusInf) &&
         (solution->fstar < options_ObjectiveLimit)) &&
        ((solution->state != 0) || (b_objType != 5))) {
      solution->state = 2;
    }
  }
}

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for checkStoppingAndUpdateFval.cpp
//
// [EOF]
//
