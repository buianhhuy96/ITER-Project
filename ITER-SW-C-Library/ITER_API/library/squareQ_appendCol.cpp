//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squareQ_appendCol.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "squareQ_appendCol.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

// Function Definitions
//
// Arguments    : struct_T *obj
//                const double vec[120]
//                int iv0
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void squareQ_appendCol(struct_T *obj, const double vec[120], int iv0)
{
  double c;
  double d;
  double s;
  int b_u1;
  int d_lda;
  int idx;
  int iy0;
  int u0;
  int y;
  u0 = obj->mrows;
  b_u1 = obj->ncols + 1;
  if (u0 <= b_u1) {
    y = u0;
  } else {
    y = b_u1;
  }
  obj->minRowCol = y;
  iy0 = obj->ldq * obj->ncols;
  d_lda = obj->ldq;
  if (obj->mrows != 0) {
    int b_i;
    int c_iy;
    int iac;
    int iyend;
    iyend = iy0 + obj->mrows;
    if ((static_cast<int>((iyend - iy0) < 4)) != 0) {
      for (int b_iy{iy0 + 1}; b_iy <= iyend; b_iy++) {
        (&obj->QR[0][0])[b_iy - 1] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_iy = iy0 + 1; b_iy <= iyend; b_iy++) {
        (&obj->QR[0][0])[b_iy - 1] = 0.0;
      }
    }
    c_iy = iy0;
    b_i = (obj->ldq * (obj->mrows - 1)) + 1;
    iac = 1;
    while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
      double c_c;
      int i2;
      c_c = 0.0;
      i2 = (iac + obj->mrows) - 1;
      for (int ia{iac}; ia <= i2; ia++) {
        c_c += (&obj->Q[0][0])[ia - 1] * vec[((iv0 + ia) - iac) - 1];
      }
      (&obj->QR[0][0])[c_iy] += c_c;
      c_iy++;
      iac += d_lda;
    }
  }
  obj->ncols++;
  obj->jpvt[obj->ncols - 1] = obj->ncols;
  idx = obj->mrows - 2;
  while ((idx + 2) > obj->ncols) {
    int Qk0;
    int h_n;
    int i1;
    int idxRotGCol;
    idxRotGCol = obj->ldq * (obj->ncols - 1);
    i1 = (idx + idxRotGCol) + 1;
    d = (&obj->QR[0][0])[i1];
    internal::blas::xrotg(&(&obj->QR[0][0])[idx + idxRotGCol], &d, &c, &s);
    (&obj->QR[0][0])[i1] = d;
    Qk0 = obj->ldq * idx;
    h_n = obj->mrows;
    if (obj->mrows >= 1) {
      int d_iy;
      d_iy = obj->ldq + Qk0;
      for (int k{0}; k < h_n; k++) {
        double temp;
        int b_temp_tmp;
        int temp_tmp;
        temp_tmp = d_iy + k;
        b_temp_tmp = Qk0 + k;
        temp =
            (c * (&obj->Q[0][0])[b_temp_tmp]) + (s * (&obj->Q[0][0])[temp_tmp]);
        (&obj->Q[0][0])[temp_tmp] =
            (c * (&obj->Q[0][0])[temp_tmp]) - (s * (&obj->Q[0][0])[b_temp_tmp]);
        (&obj->Q[0][0])[b_temp_tmp] = temp;
      }
    }
    idx--;
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for squareQ_appendCol.cpp
//
// [EOF]
//
