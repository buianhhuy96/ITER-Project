//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maxConstraintViolation.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "maxConstraintViolation.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const j_struct_T *obj
//                const double b_x[8]
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
double b_maxConstraintViolation(const j_struct_T *obj, const double b_x[8])
{
  double b_v;
  int mFixed;
  int mLB;
  int mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  b_v = 0.0;
  if (obj->sizes[3] > 0) {
    for (int idx{0}; idx < mLB; idx++) {
      int b_idxLB;
      b_idxLB = obj->indexLB[idx] - 1;
      b_v = std::fmax(b_v, (-b_x[b_idxLB]) - obj->lb[b_idxLB]);
    }
  }
  if (obj->sizes[4] > 0) {
    for (int b_idx{0}; b_idx < mUB; b_idx++) {
      int idxUB;
      idxUB = obj->indexUB[b_idx] - 1;
      b_v = std::fmax(b_v, b_x[idxUB] - obj->ub[idxUB]);
    }
  }
  if (obj->sizes[0] > 0) {
    for (int c_idx{0}; c_idx < mFixed; c_idx++) {
      b_v = std::fmax(b_v, std::abs(b_x[obj->indexFixed[c_idx] - 1] -
                                    obj->ub[obj->indexFixed[c_idx] - 1]));
    }
  }
  return b_v;
}

//
// Arguments    : const j_struct_T *obj
//                const double b_x[8][15]
//                int ix0
// Return Type  : double
//
double maxConstraintViolation(const j_struct_T *obj, const double b_x[8][15],
                              int ix0)
{
  double b_v;
  int mFixed;
  int mLB;
  int mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  b_v = 0.0;
  if (obj->sizes[3] > 0) {
    for (int idx{0}; idx < mLB; idx++) {
      b_v = std::fmax(b_v, (-(&b_x[0][0])[(ix0 + obj->indexLB[idx]) - 2]) -
                               obj->lb[obj->indexLB[idx] - 1]);
    }
  }
  if (obj->sizes[4] > 0) {
    for (int b_idx{0}; b_idx < mUB; b_idx++) {
      b_v = std::fmax(b_v, (&b_x[0][0])[(ix0 + obj->indexUB[b_idx]) - 2] -
                               obj->ub[obj->indexUB[b_idx] - 1]);
    }
  }
  if (obj->sizes[0] > 0) {
    for (int c_idx{0}; c_idx < mFixed; c_idx++) {
      b_v = std::fmax(
          b_v, std::abs((&b_x[0][0])[(ix0 + obj->indexFixed[c_idx]) - 2] -
                        obj->ub[obj->indexFixed[c_idx] - 1]));
    }
  }
  return b_v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for maxConstraintViolation.cpp
//
// [EOF]
//
