//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeFval_ReuseHx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeFval_ReuseHx.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const x_struct_T *obj
//                double workspace[8][15]
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
double computeFval_ReuseHx(const x_struct_T *obj, double workspace[8][15],
                           const double f[8], const double b_x[8])
{
  double val;
  val = 0.0;
  switch (obj->objtype) {
  case 5:
    val = obj->gammaScalar * b_x[obj->b_nvar - 1];
    break;
  case 3: {
    if (obj->hasLinear) {
      int b_i;
      b_i = obj->b_nvar;
      if ((static_cast<int>(b_i < 4)) != 0) {
        for (int c_i{0}; c_i < b_i; c_i++) {
          (&workspace[0][0])[c_i] = (0.5 * obj->Hx[c_i]) + f[c_i];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int c_i = 0; c_i < b_i; c_i++) {
          (&workspace[0][0])[c_i] = (0.5 * obj->Hx[c_i]) + f[c_i];
        }
      }
      if (obj->b_nvar >= 1) {
        int c_ixlast;
        c_ixlast = obj->b_nvar;
        for (int c_k{0}; c_k < c_ixlast; c_k++) {
          val += b_x[c_k] * (&workspace[0][0])[c_k];
        }
      }
    } else {
      if (obj->b_nvar >= 1) {
        int ixlast;
        ixlast = obj->b_nvar;
        for (int k{0}; k < ixlast; k++) {
          val += b_x[k] * obj->Hx[k];
        }
      }
      val *= 0.5;
    }
  } break;
  case 4: {
    int maxRegVar;
    int maxRegVar_tmp_tmp;
    maxRegVar_tmp_tmp = obj->maxVar - 1;
    maxRegVar = maxRegVar_tmp_tmp;
    if (obj->hasLinear) {
      int i1;
      int i3;
      i1 = obj->b_nvar;
      if ((static_cast<int>(i1 < 4)) != 0) {
        for (int d_i{0}; d_i < i1; d_i++) {
          (&workspace[0][0])[d_i] = f[d_i];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_i = 0; d_i < i1; d_i++) {
          (&workspace[0][0])[d_i] = f[d_i];
        }
      }
      i3 = obj->maxVar - obj->b_nvar;
      for (int e_i{0}; e_i <= (i3 - 2); e_i++) {
        (&workspace[0][0])[obj->b_nvar + e_i] = obj->rho;
      }
      for (int g_i{0}; g_i < maxRegVar; g_i++) {
        (&workspace[0][0])[g_i] += 0.5 * obj->Hx[g_i];
      }
      if ((obj->maxVar - 1) >= 1) {
        int d_ixlast;
        d_ixlast = obj->maxVar;
        for (int d_k{0}; d_k <= (d_ixlast - 2); d_k++) {
          val += b_x[d_k] * (&workspace[0][0])[d_k];
        }
      }
    } else {
      int i2;
      if (maxRegVar_tmp_tmp >= 1) {
        int b_ixlast;
        b_ixlast = obj->maxVar;
        for (int b_k{0}; b_k <= (b_ixlast - 2); b_k++) {
          val += b_x[b_k] * obj->Hx[b_k];
        }
      }
      val *= 0.5;
      i2 = obj->b_nvar + 1;
      for (int idx{i2}; idx <= maxRegVar_tmp_tmp; idx++) {
        val += b_x[idx - 1] * obj->rho;
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
// File trailer for computeFval_ReuseHx.cpp
//
// [EOF]
//
