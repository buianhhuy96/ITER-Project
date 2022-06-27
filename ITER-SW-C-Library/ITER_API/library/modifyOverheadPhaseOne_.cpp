//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: modifyOverheadPhaseOne_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "modifyOverheadPhaseOne_.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : j_struct_T *obj
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void modifyOverheadPhaseOne_(j_struct_T *obj)
{
  int b_i;
  int i1;
  int idxStartIneq;
  b_i = obj->sizes[0];
  for (int idx{0}; idx < b_i; idx++) {
    obj->ATwset[(obj->nVar + (obj->ldA * idx)) - 1] = 0.0;
  }
  obj->indexLB[obj->sizes[3] - 1] = obj->nVar;
  obj->lb[obj->nVar - 1] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  i1 = obj->nActiveConstr;
  for (int b_idx{idxStartIneq}; b_idx <= i1; b_idx++) {
    obj->ATwset[(obj->nVar + (obj->ldA * (b_idx - 1))) - 1] = -1.0;
  }
  if (obj->nWConstr[4] > 0) {
    int i2;
    i2 = obj->sizesNormal[4];
    for (int c_idx{0}; c_idx <= i2; c_idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + c_idx) - 1] = false;
    }
  }
  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for modifyOverheadPhaseOne_.cpp
//
// [EOF]
//
