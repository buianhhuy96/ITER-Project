//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: setProblemType.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "setProblemType.h"
#include "ITER_API_internal_types.h"
#include "modifyOverheadPhaseOne_.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : o_struct_T *obj
//                int PROBLEM_TYPE
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void setProblemType(o_struct_T *obj, int PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
  case 3: {
    obj->nVar = obj->nVarOrig;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      int i3;
      i3 = obj->sizesNormal[4];
      for (int idx{0}; idx < i3; idx++) {
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + idx) - 1] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < 5; i5++) {
      obj->sizes[i5] = obj->sizesNormal[i5];
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < 6; i7++) {
      obj->isActiveIdx[i7] = obj->isActiveIdxNormal[i7];
    }
  } break;
  case 1:
    obj->nVar = obj->nVarOrig + 1;
    obj->mConstr = obj->mConstrOrig + 1;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < 5; i1++) {
      obj->sizes[i1] = obj->sizesPhaseOne[i1];
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < 6; i6++) {
      obj->isActiveIdx[i6] = obj->isActiveIdxPhaseOne[i6];
    }
    modifyOverheadPhaseOne_(obj);
    break;
  case 2: {
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < 5; i2++) {
      obj->sizes[i2] = obj->sizesRegularized[i2];
    }
    if (obj->probType != 4) {
      int colOffsetATw;
      int i10;
      int i12;
      int i15;
      int i16;
      int i17;
      int i18;
      int i19;
      int i20;
      int i9;
      int idxStartIneq;
      int idx_lb;
      int offsetIneq;
      offsetIneq = obj->nVarOrig + 1;
      i9 = obj->sizes[0];
      for (int idx_col{0}; idx_col < i9; idx_col++) {
        int i11;
        int i13;
        colOffsetATw = obj->ldA * idx_col;
        i11 = obj->nVarOrig + 1;
        i13 = obj->nVar;
        if (i11 <= i13) {
          (void)std::memset(
              &obj->ATwset[(i11 + colOffsetATw) + -1], 0,
              (static_cast<unsigned int>(static_cast<int>(
                  (((i13 + colOffsetATw) - i11) - colOffsetATw) + 1))) *
                  (sizeof(double)));
        }
      }
      idx_lb = obj->nVarOrig;
      i10 = obj->sizesNormal[3] + 1;
      i12 = obj->sizesRegularized[3];
      for (int b_idx{i10}; b_idx <= i12; b_idx++) {
        idx_lb++;
        obj->indexLB[b_idx - 1] = idx_lb;
      }
      if (obj->nWConstr[4] > 0) {
        int i14;
        i14 = obj->sizesRegularized[4];
        for (int c_idx{0}; c_idx < i14; c_idx++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + c_idx] =
              obj->isActiveConstr[(obj->isActiveIdx[4] + c_idx) - 1];
        }
      }
      i15 = obj->isActiveIdx[4];
      i16 = obj->isActiveIdxRegularized[4] - 1;
      if ((static_cast<int>(((i16 - i15) + 1) < 4)) != 0) {
        if (i15 <= i16) {
          (void)std::memset(
              &obj->isActiveConstr[i15 + -1], 0,
              (static_cast<unsigned int>(static_cast<int>((i16 - i15) + 1))) *
                  (sizeof(bool)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_idx = i15; d_idx <= i16; d_idx++) {
          obj->isActiveConstr[d_idx - 1] = false;
        }
      }
      i17 = obj->nVarOrig + 1;
      i18 = i17;
      i19 = (obj->nVarOrig + obj->sizes[2]) + (obj->sizes[1] * 2);
      if ((static_cast<int>(((i19 - i17) + 1) < 4)) != 0) {
        if (i17 <= i19) {
          (void)std::memset(
              &obj->lb[i17 + -1], 0,
              (static_cast<unsigned int>(static_cast<int>((i19 - i17) + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_idx = i18; e_idx <= i19; e_idx++) {
          obj->lb[e_idx - 1] = 0.0;
        }
      }
      idxStartIneq = obj->isActiveIdx[2];
      i20 = obj->nActiveConstr;
      for (int b_idx_col{idxStartIneq}; b_idx_col <= i20; b_idx_col++) {
        colOffsetATw = (obj->ldA * (b_idx_col - 1)) - 1;
        if (obj->Wid[b_idx_col - 1] == 3) {
          int i22;
          int i23;
          int i24;
          i22 = (offsetIneq + obj->Wlocalidx[b_idx_col - 1]) - 2;
          if (offsetIneq <= i22) {
            (void)std::memset(
                &obj->ATwset[offsetIneq + colOffsetATw], 0,
                (static_cast<unsigned int>(static_cast<int>(
                    (((i22 + colOffsetATw) - offsetIneq) - colOffsetATw) +
                    1))) *
                    (sizeof(double)));
          }
          obj->ATwset[((offsetIneq + obj->Wlocalidx[b_idx_col - 1]) +
                       colOffsetATw) -
                      1] = -1.0;
          i23 = offsetIneq + obj->Wlocalidx[b_idx_col - 1];
          i24 = obj->nVar;
          if (i23 <= i24) {
            (void)std::memset(
                &obj->ATwset[i23 + colOffsetATw], 0,
                (static_cast<unsigned int>(static_cast<int>(
                    (((i24 + colOffsetATw) - i23) - colOffsetATw) + 1))) *
                    (sizeof(double)));
          }
        } else {
          int i21;
          i21 = obj->nVar;
          if (offsetIneq <= i21) {
            (void)std::memset(
                &obj->ATwset[offsetIneq + colOffsetATw], 0,
                (static_cast<unsigned int>(static_cast<int>(
                    (((i21 + colOffsetATw) - offsetIneq) - colOffsetATw) +
                    1))) *
                    (sizeof(double)));
          }
        }
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < 6; b_i8++) {
      obj->isActiveIdx[b_i8] = obj->isActiveIdxRegularized[b_i8];
    }
  } break;
  default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < 5; b_i++) {
      obj->sizes[b_i] = obj->sizesRegPhaseOne[b_i];
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < 6; i4++) {
      obj->isActiveIdx[i4] = obj->isActiveIdxRegPhaseOne[i4];
    }
    modifyOverheadPhaseOne_(obj);
    break;
  }
  obj->probType = PROBLEM_TYPE;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for setProblemType.cpp
//
// [EOF]
//
