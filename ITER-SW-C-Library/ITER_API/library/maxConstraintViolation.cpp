//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maxConstraintViolation.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "maxConstraintViolation.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const o_struct_T *obj
//                const double b_x[8]
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
double b_maxConstraintViolation(const o_struct_T *obj, const double b_x[8])
{
  double e_v;
  int mFixed;
  int mLB;
  int mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  e_v = 0.0;
  if (obj->sizes[3] > 0) {
    for (int idx{0}; idx < mLB; idx++) {
      int b_idxLB;
      b_idxLB = obj->indexLB[idx] - 1;
      e_v = std::fmax(e_v, (-b_x[b_idxLB]) - obj->lb[b_idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    for (int b_idx{0}; b_idx < mUB; b_idx++) {
      int idxUB;
      idxUB = obj->indexUB[b_idx] - 1;
      e_v = std::fmax(e_v, b_x[idxUB] - obj->ub[idxUB]);
    }
  }
  if (obj->sizes[0] > 0) {
    for (int c_idx{0}; c_idx < mFixed; c_idx++) {
      e_v = std::fmax(e_v, std::abs(b_x[obj->indexFixed[c_idx] - 1] -
                                    obj->ub[obj->indexFixed[c_idx] - 1]));
    }
  }
  return e_v;
}

//
// Arguments    : const o_struct_T *obj
//                const double b_x[8][15]
//                int ix0
// Return Type  : double
//
double maxConstraintViolation(const o_struct_T *obj, const double b_x[8][15],
                              int ix0)
{
  double e_v;
  int mFixed;
  int mLB;
  int mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  e_v = 0.0;
  if (obj->sizes[3] > 0) {
    for (int idx{0}; idx < mLB; idx++) {
      e_v = std::fmax(e_v, (-(&b_x[0][0])[(ix0 + obj->indexLB[idx]) - 2]) -
                               obj->lb[obj->indexLB[idx] - 1]);
    }
  }
  if (obj->sizes[4] > 0) {
    for (int b_idx{0}; b_idx < mUB; b_idx++) {
      e_v = std::fmax(e_v, (&b_x[0][0])[(ix0 + obj->indexUB[b_idx]) - 2] -
                               obj->ub[obj->indexUB[b_idx] - 1]);
    }
  }
  if (obj->sizes[0] > 0) {
    for (int c_idx{0}; c_idx < mFixed; c_idx++) {
      e_v = std::fmax(
          e_v, std::abs((&b_x[0][0])[(ix0 + obj->indexFixed[c_idx]) - 2] -
                        obj->ub[obj->indexFixed[c_idx] - 1]));
    }
  }
  return e_v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for maxConstraintViolation.cpp
//
// [EOF]
//
