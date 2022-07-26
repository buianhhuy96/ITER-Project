//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: addBoundToActiveSetMatrix_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "addBoundToActiveSetMatrix_.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : o_struct_T *obj
//                int TYPE
//                int idx_local
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addBoundToActiveSetMatrix_(o_struct_T *obj, int TYPE, int idx_local)
{
  int b_i;
  int colOffset;
  int i1;
  int idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->ldA * (obj->nActiveConstr - 1)) - 1;
  if (TYPE == 5) {
    int b_idx_bnd_local_tmp;
    b_idx_bnd_local_tmp = obj->indexUB[idx_local - 1];
    idx_bnd_local = b_idx_bnd_local_tmp;
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[b_idx_bnd_local_tmp - 1];
  } else {
    int idx_bnd_local_tmp;
    idx_bnd_local_tmp = obj->indexLB[idx_local - 1];
    idx_bnd_local = idx_bnd_local_tmp;
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local_tmp - 1];
  }
  if (0 <= (idx_bnd_local - 2)) {
    (void)std::memset(&obj->ATwset[colOffset + 1], 0,
                      (static_cast<unsigned int>(static_cast<int>(
                          ((idx_bnd_local + colOffset) - colOffset) + -1))) *
                          (sizeof(double)));
  }
  obj->ATwset[idx_bnd_local + colOffset] =
      (2.0 * (static_cast<double>(TYPE == 5))) - 1.0;
  b_i = idx_bnd_local + 1;
  i1 = obj->nVar;
  if ((static_cast<int>((i1 - idx_bnd_local) < 4)) != 0) {
    if (b_i <= i1) {
      (void)std::memset(&obj->ATwset[b_i + colOffset], 0,
                        (static_cast<unsigned int>(static_cast<int>(
                            (((i1 + colOffset) - b_i) - colOffset) + 1))) *
                            (sizeof(double)));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int idx = b_i; idx <= i1; idx++) {
      obj->ATwset[idx + colOffset] = 0.0;
    }
  }
  switch (obj->probType) {
  case 3:
  case 2:
    break;
  default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for addBoundToActiveSetMatrix_.cpp
//
// [EOF]
//
