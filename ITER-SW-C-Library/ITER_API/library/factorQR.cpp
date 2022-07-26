//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factorQR.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "factorQR.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <string.h>

// Function Definitions
//
// Arguments    : struct_T *obj
//                const double A[120]
//                int mrows
//                int ncols
//                int ldA
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void factorQR(struct_T *obj, const double A[120], int mrows, int ncols, int ldA)
{
  int b_i;
  bool guard1{false};
  b_i = mrows * ncols;
  guard1 = false;
  if (b_i > 0) {
    for (int idx{0}; idx < ncols; idx++) {
      int ix0;
      int iy0;
      ix0 = ldA * idx;
      iy0 = obj->ldq * idx;
      for (int k{0}; k < mrows; k++) {
        (&obj->QR[0][0])[iy0 + k] = A[ix0 + k];
      }
    }
    guard1 = true;
  } else if (b_i == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    int i1;
    int minmn;
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if ((static_cast<int>(ncols < 4)) != 0) {
      for (int b_idx{0}; b_idx < ncols; b_idx++) {
        obj->jpvt[b_idx] = b_idx + 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_idx = 0; b_idx < ncols; b_idx++) {
        obj->jpvt[b_idx] = b_idx + 1;
      }
    }
    if (mrows <= ncols) {
      i1 = mrows;
    } else {
      i1 = ncols;
    }
    obj->minRowCol = i1;
    minmn = i1;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i < 15; c_i++) {
      obj->tau[c_i] = 0.0;
    }
    if (minmn >= 1) {
      internal::reflapack::qrf(obj->QR, mrows, ncols, minmn, obj->tau);
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for factorQR.cpp
//
// [EOF]
//
