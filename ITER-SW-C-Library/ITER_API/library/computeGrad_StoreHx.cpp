//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGrad_StoreHx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "computeGrad_StoreHx.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : r_struct_T *obj
//                const double H[7][7]
//                const double f[8]
//                const double b_x[8]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(r_struct_T *obj, const double H[7][7],
                         const double f[8], const double b_x[8])
{
  int i12;
  switch (obj->objtype) {
  case 5: {
    int b_i;
    b_i = obj->b_nvar;
    if ((static_cast<int>((b_i - 1) < 4)) != 0) {
      if (0 <= (b_i - 2)) {
        (void)std::memset(
            &obj->grad[0], 0,
            (static_cast<unsigned int>(static_cast<int>(b_i + -1))) *
                (sizeof(double)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_i = 0; c_i <= (b_i - 2); c_i++) {
        obj->grad[c_i] = 0.0;
      }
    }
    obj->grad[obj->b_nvar - 1] = obj->gammaScalar;
  } break;
  case 3: {
    int b_m;
    int d_lda;
    int i1;
    int m_tmp_tmp;
    m_tmp_tmp = obj->b_nvar - 1;
    b_m = m_tmp_tmp;
    d_lda = obj->b_nvar;
    if (obj->b_nvar != 0) {
      int b_ix;
      int i4;
      int iac;
      if ((static_cast<int>((m_tmp_tmp + 1) < 4)) != 0) {
        if (0 <= m_tmp_tmp) {
          (void)std::memset(
              &obj->Hx[0], 0,
              (static_cast<unsigned int>(static_cast<int>(m_tmp_tmp + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_iy = 0; b_iy <= b_m; b_iy++) {
          obj->Hx[b_iy] = 0.0;
        }
      }
      b_ix = 0;
      i4 = (obj->b_nvar * (obj->b_nvar - 1)) + 1;
      iac = 1;
      while (((d_lda > 0) && (iac <= i4)) || ((d_lda < 0) && (iac >= i4))) {
        int i6;
        i6 = iac + b_m;
        for (int ia{iac}; ia <= i6; ia++) {
          int b_i8;
          b_i8 = ia - iac;
          obj->Hx[b_i8] += (&H[0][0])[ia - 1] * b_x[b_ix];
        }
        b_ix++;
        iac += d_lda;
      }
    }
    i1 = obj->b_nvar;
    if (0 <= (i1 - 1)) {
      (void)std::copy(&obj->Hx[0], &obj->Hx[i1], &obj->grad[0]);
    }
    if ((obj->hasLinear) && (obj->b_nvar >= 1)) {
      int i3;
      int ixlast;
      i3 = obj->b_nvar - 1;
      ixlast = i3;
      if ((static_cast<int>((i3 + 1) < 4)) != 0) {
        for (int k{0}; k <= i3; k++) {
          obj->grad[k] += f[k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int k = 0; k <= ixlast; k++) {
          obj->grad[k] += f[k];
        }
      }
    }
  } break;
  case 4: {
    int c_m;
    int e_lda;
    int h_n;
    int i2;
    int maxRegVar;
    maxRegVar = obj->maxVar - 1;
    c_m = obj->b_nvar - 1;
    e_lda = obj->b_nvar;
    if (obj->b_nvar != 0) {
      int b_iac;
      int c_ix;
      int i5;
      if ((static_cast<int>((c_m + 1) < 4)) != 0) {
        if (0 <= c_m) {
          (void)std::memset(
              &obj->Hx[0], 0,
              (static_cast<unsigned int>(static_cast<int>(c_m + 1))) *
                  (sizeof(double)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int c_iy = 0; c_iy <= c_m; c_iy++) {
          obj->Hx[c_iy] = 0.0;
        }
      }
      c_ix = 0;
      i5 = (obj->b_nvar * (obj->b_nvar - 1)) + 1;
      b_iac = 1;
      while (((e_lda > 0) && (b_iac <= i5)) || ((e_lda < 0) && (b_iac >= i5))) {
        int i7;
        i7 = b_iac + c_m;
        for (int b_ia{b_iac}; b_ia <= i7; b_ia++) {
          int i9;
          i9 = b_ia - b_iac;
          obj->Hx[i9] += (&H[0][0])[b_ia - 1] * b_x[c_ix];
        }
        c_ix++;
        b_iac += e_lda;
      }
    }
    i2 = obj->b_nvar + 1;
    if ((static_cast<int>(((maxRegVar - i2) + 1) < 4)) != 0) {
      for (int idx{i2}; idx <= maxRegVar; idx++) {
        obj->Hx[idx - 1] = obj->beta * b_x[idx - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = i2; idx <= maxRegVar; idx++) {
        obj->Hx[idx - 1] = obj->beta * b_x[idx - 1];
      }
    }
    if (0 <= (maxRegVar - 1)) {
      (void)std::copy(&obj->Hx[0], &obj->Hx[maxRegVar], &obj->grad[0]);
    }
    if ((obj->hasLinear) && (obj->b_nvar >= 1)) {
      int b_ixlast;
      b_ixlast = obj->b_nvar - 1;
      if ((static_cast<int>((b_ixlast + 1) < 4)) != 0) {
        for (int b_k{0}; b_k <= b_ixlast; b_k++) {
          obj->grad[b_k] += f[b_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_k = 0; b_k <= b_ixlast; b_k++) {
          obj->grad[b_k] += f[b_k];
        }
      }
    }
    h_n = (obj->maxVar - obj->b_nvar) - 1;
    if (h_n >= 1) {
      int d_iy;
      int i10;
      d_iy = obj->b_nvar;
      i10 = h_n - 1;
      if ((static_cast<int>(h_n < 4)) != 0) {
        for (int c_k{0}; c_k <= i10; c_k++) {
          int i11;
          i11 = d_iy + c_k;
          obj->grad[i11] += obj->rho;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12)

        for (int c_k = 0; c_k <= i10; c_k++) {
          i12 = d_iy + c_k;
          obj->grad[i12] += obj->rho;
        }
      }
    }
  } break;
  default:
    /* no actions */
    break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeGrad_StoreHx.cpp
//
// [EOF]
//
