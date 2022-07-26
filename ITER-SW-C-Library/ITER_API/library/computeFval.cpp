//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFval.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeFval.h"
#include "ITER_API_internal_types.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const x_struct_T *obj
//                double workspace[8][15]
//                const double H[7][7]
//                const double f[8]
//                const double b_x[8]
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
double computeFval(const x_struct_T *obj, double workspace[8][15],
                   const double H[7][7], const double f[8], const double b_x[8])
{
  double val;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * b_x[obj->b_nvar - 1];
    break;
  case 3: {
    linearForm_(obj->hasLinear, obj->b_nvar, workspace, H, f, b_x);
    if (obj->b_nvar >= 1) {
      int ixlast;
      ixlast = obj->b_nvar;
      for (int k{0}; k < ixlast; k++) {
        val += b_x[k] * (&workspace[0][0])[k];
      }
    }
  } break;
  case 4: {
    int b_i;
    int i1;
    int i2;
    linearForm_(obj->hasLinear, obj->b_nvar, workspace, H, f, b_x);
    b_i = obj->b_nvar + 1;
    i1 = obj->maxVar - 1;
    i2 = i1;
    if ((static_cast<int>(((i1 - b_i) + 1) < 4)) != 0) {
      for (int idx{b_i}; idx <= i1; idx++) {
        (&workspace[0][0])[idx - 1] =
            ((0.5 * obj->beta) * b_x[idx - 1]) + obj->rho;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = b_i; idx <= i2; idx++) {
        (&workspace[0][0])[idx - 1] =
            ((0.5 * obj->beta) * b_x[idx - 1]) + obj->rho;
      }
    }
    if ((obj->maxVar - 1) >= 1) {
      int b_ixlast;
      b_ixlast = obj->maxVar;
      for (int b_k{0}; b_k <= (b_ixlast - 2); b_k++) {
        val += b_x[b_k] * (&workspace[0][0])[b_k];
      }
    }
  } break;
  default:
    /* no actions */
    break;
  }
  return val;
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computeFval.cpp
//
// [EOF]
//
