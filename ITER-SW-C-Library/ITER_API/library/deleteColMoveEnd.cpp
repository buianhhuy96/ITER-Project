//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: deleteColMoveEnd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "deleteColMoveEnd.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include "xrotg.h"
#include <string.h>

// Function Definitions
//
// Arguments    : struct_T *obj
//                int idx
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void deleteColMoveEnd(struct_T *obj, int idx)
{
  double b_c;
  double b_d1;
  double b_s;
  double c;
  double d;
  double s;
  if (obj->usedPivoting) {
    int b_i;
    b_i = 1;
    while ((b_i <= obj->ncols) && (obj->jpvt[b_i - 1] != idx)) {
      b_i++;
    }
    idx = b_i;
  }
  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    int b_u1;
    int c_i;
    int u0;
    int y;
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    c_i = obj->minRowCol;
    for (int k{0}; k < c_i; k++) {
      (&obj->QR[0][0])[k + (obj->ldq * (idx - 1))] =
          (&obj->QR[0][0])[k + (obj->ldq * (obj->ncols - 1))];
    }
    obj->ncols--;
    u0 = obj->mrows;
    b_u1 = obj->ncols;
    if (u0 <= b_u1) {
      y = u0;
    } else {
      y = b_u1;
    }
    obj->minRowCol = y;
    if (idx < obj->mrows) {
      int QRk0;
      int b_k;
      int b_u0;
      int c_u1;
      int endIdx;
      int i1;
      int idxRotGCol;
      b_u0 = obj->mrows - 1;
      c_u1 = obj->ncols;
      if (b_u0 <= c_u1) {
        endIdx = b_u0;
      } else {
        endIdx = c_u1;
      }
      b_k = endIdx;
      idxRotGCol = obj->ldq * (idx - 1);
      while (b_k >= idx) {
        int h_n;
        int i2;
        int i4;
        int q_n;
        i2 = b_k + idxRotGCol;
        d = (&obj->QR[0][0])[i2];
        internal::blas::xrotg(&(&obj->QR[0][0])[(b_k + idxRotGCol) - 1], &d, &c,
                              &s);
        (&obj->QR[0][0])[i2] = d;
        (&obj->QR[0][0])[b_k + (obj->ldq * (b_k - 1))] = 0.0;
        QRk0 = b_k + (obj->ldq * idx);
        h_n = obj->ncols - idx;
        if (h_n >= 1) {
          int b_iy;
          int c_ix;
          c_ix = QRk0 - 1;
          b_iy = QRk0;
          for (int d_k{0}; d_k < h_n; d_k++) {
            double temp;
            temp = (c * (&obj->QR[0][0])[c_ix]) + (s * (&obj->QR[0][0])[b_iy]);
            (&obj->QR[0][0])[b_iy] =
                (c * (&obj->QR[0][0])[b_iy]) - (s * (&obj->QR[0][0])[c_ix]);
            (&obj->QR[0][0])[c_ix] = temp;
            b_iy += obj->ldq;
            c_ix += obj->ldq;
          }
        }
        i4 = obj->ldq * (b_k - 1);
        q_n = obj->mrows;
        if (obj->mrows >= 1) {
          int d_iy;
          d_iy = obj->ldq + i4;
          for (int g_k{0}; g_k < q_n; g_k++) {
            double c_temp;
            int b_temp_tmp;
            int temp_tmp;
            temp_tmp = d_iy + g_k;
            b_temp_tmp = i4 + g_k;
            c_temp = (c * (&obj->Q[0][0])[b_temp_tmp]) +
                     (s * (&obj->Q[0][0])[temp_tmp]);
            (&obj->Q[0][0])[temp_tmp] = (c * (&obj->Q[0][0])[temp_tmp]) -
                                        (s * (&obj->Q[0][0])[b_temp_tmp]);
            (&obj->Q[0][0])[b_temp_tmp] = c_temp;
          }
        }
        b_k--;
      }
      i1 = idx + 1;
      for (int c_k{i1}; c_k <= endIdx; c_k++) {
        int i3;
        int i5;
        int idxRotGCol_tmp_tmp;
        int p_n;
        int s_n;
        idxRotGCol_tmp_tmp = obj->ldq * (c_k - 1);
        i3 = c_k + idxRotGCol_tmp_tmp;
        b_d1 = (&obj->QR[0][0])[i3];
        internal::blas::xrotg(&(&obj->QR[0][0])[(c_k + idxRotGCol_tmp_tmp) - 1],
                              &b_d1, &b_c, &b_s);
        (&obj->QR[0][0])[i3] = b_d1;
        QRk0 = c_k * (obj->ldq + 1);
        p_n = obj->ncols - c_k;
        if (p_n >= 1) {
          int c_iy;
          int d_ix;
          d_ix = QRk0 - 1;
          c_iy = QRk0;
          for (int e_k{0}; e_k < p_n; e_k++) {
            double b_temp;
            b_temp =
                (b_c * (&obj->QR[0][0])[d_ix]) + (b_s * (&obj->QR[0][0])[c_iy]);
            (&obj->QR[0][0])[c_iy] =
                (b_c * (&obj->QR[0][0])[c_iy]) - (b_s * (&obj->QR[0][0])[d_ix]);
            (&obj->QR[0][0])[d_ix] = b_temp;
            c_iy += obj->ldq;
            d_ix += obj->ldq;
          }
        }
        i5 = obj->ldq * (c_k - 1);
        s_n = obj->mrows;
        if (obj->mrows >= 1) {
          int e_iy;
          e_iy = obj->ldq + i5;
          for (int h_k{0}; h_k < s_n; h_k++) {
            double d_temp;
            int c_temp_tmp;
            int d_temp_tmp;
            c_temp_tmp = e_iy + h_k;
            d_temp_tmp = i5 + h_k;
            d_temp = (b_c * (&obj->Q[0][0])[d_temp_tmp]) +
                     (b_s * (&obj->Q[0][0])[c_temp_tmp]);
            (&obj->Q[0][0])[c_temp_tmp] = (b_c * (&obj->Q[0][0])[c_temp_tmp]) -
                                          (b_s * (&obj->Q[0][0])[d_temp_tmp]);
            (&obj->Q[0][0])[d_temp_tmp] = d_temp;
          }
        }
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for deleteColMoveEnd.cpp
//
// [EOF]
//
