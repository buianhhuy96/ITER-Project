//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factor.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "factor.h"
#include "ITER_API_internal_types.h"
#include "fullColLDL2_.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : y_struct_T *obj
//                const double A[7][7]
//                int ndims
//                int ldA
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void factor(y_struct_T *obj, const double A[7][7], int ndims, int ldA)
{
  double SCALED_REG_PRIMAL;
  SCALED_REG_PRIMAL =
      (1.4901161193847656E-8 * obj->scaleFactor) * (static_cast<double>(ndims));
  obj->ndims = ndims;
  for (int idx{0}; idx < ndims; idx++) {
    int ix0;
    int iy0;
    ix0 = ldA * idx;
    iy0 = obj->ldm * idx;
    for (int k{0}; k < ndims; k++) {
      (&obj->FMat[0][0])[iy0 + k] = (&A[0][0])[ix0 + k];
    }
  }
  int A_maxDiag_idx;
  A_maxDiag_idx = internal::blas::ixamax(ndims, obj->FMat, obj->ldm + 1) - 1;
  obj->regTol_ = std::fmax(
      std::abs((&obj->FMat[0][0])[A_maxDiag_idx + (obj->ldm * A_maxDiag_idx)]) *
          2.2204460492503131E-16,
      std::abs(SCALED_REG_PRIMAL));
  fullColLDL2_(obj, ndims, SCALED_REG_PRIMAL);
  if (obj->ConvexCheck) {
    int b_idx;
    b_idx = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (b_idx <= (ndims - 1)) {
        if ((&obj->FMat[0][0])[b_idx + (obj->ldm * b_idx)] <= 0.0) {
          obj->info = (-b_idx) - 1;
          exitg1 = 1;
        } else {
          b_idx++;
        }
      } else {
        obj->ConvexCheck = false;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for factor.cpp
//
// [EOF]
//
