//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateWorkingSetForNewQP.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "updateWorkingSetForNewQP.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_xk[7]
//                j_struct_T *WorkingSet
//                int mEq
//                int mLB
//                int mUB
//                int mFixed
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void updateWorkingSetForNewQP(const double b_xk[7], j_struct_T *WorkingSet,
                              int mEq, int mLB, int mUB, int mFixed)
{
  int b_i;
  for (int idx{0}; idx < mLB; idx++) {
    WorkingSet->lb[WorkingSet->indexLB[idx] - 1] =
        b_xk[WorkingSet->indexLB[idx] - 1] + 1.7976931348623157E+308;
  }
  for (int b_idx{0}; b_idx < mUB; b_idx++) {
    WorkingSet->ub[WorkingSet->indexUB[b_idx] - 1] =
        1.7976931348623157E+308 - b_xk[WorkingSet->indexUB[b_idx] - 1];
  }
  for (int c_idx{0}; c_idx < mFixed; c_idx++) {
    WorkingSet->ub[WorkingSet->indexFixed[c_idx] - 1] =
        1.7976931348623157E+308 - b_xk[WorkingSet->indexFixed[c_idx] - 1];
    WorkingSet->bwset[c_idx] =
        1.7976931348623157E+308 - b_xk[WorkingSet->indexFixed[c_idx] - 1];
  }
  b_i = mFixed + mEq;
  if (WorkingSet->nActiveConstr > b_i) {
    int i1;
    int ineqStart;
    if (1 < (b_i + 1)) {
      ineqStart = b_i + 1;
    } else {
      ineqStart = 1;
    }
    i1 = WorkingSet->nActiveConstr;
    for (int d_idx{ineqStart}; d_idx <= i1; d_idx++) {
      switch (WorkingSet->Wid[d_idx - 1]) {
      case 4:
        WorkingSet->bwset[d_idx - 1] =
            WorkingSet
                ->lb[WorkingSet->indexLB[WorkingSet->Wlocalidx[d_idx - 1] - 1] -
                     1];
        break;
      case 5:
        WorkingSet->bwset[d_idx - 1] =
            WorkingSet
                ->ub[WorkingSet->indexUB[WorkingSet->Wlocalidx[d_idx - 1] - 1] -
                     1];
        break;
      default:
        // A check that is always false is detected at compile-time. Eliminating
        // code that follows.
        break;
      }
    }
  }
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for updateWorkingSetForNewQP.cpp
//
// [EOF]
//
