//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "interp2.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &V
//                const ::coder::array<float, 2U> &Xq
//                const ::coder::array<float, 2U> &Yq
//                float extrapval
//                const ::coder::array<float, 2U> &d_X
//                const ::coder::array<float, 2U> &g_Y
//                ::coder::array<float, 2U> &Vq
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
namespace coder {
void interp2_local(const ::coder::array<float, 2U> &V,
                   const ::coder::array<float, 2U> &Xq,
                   const ::coder::array<float, 2U> &Yq, float extrapval,
                   const ::coder::array<float, 2U> &d_X,
                   const ::coder::array<float, 2U> &g_Y,
                   ::coder::array<float, 2U> &Vq)
{
  float f;
  float f1;
  float qx1;
  float qx2;
  float rx;
  float ry;
  float zx1y1;
  float zx1y2;
  float zx2y1;
  float zx2y2;
  int b_ix;
  int b_iy;
  int ub_loop;
  Vq.set_size(Xq.size(0), Xq.size(1));
  ub_loop = (Xq.size(0) * Xq.size(1)) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_ix, b_iy, zx1y1, zx2y1, zx1y2, zx2y2, f, qx1, qx2, f1, ry, rx)

  for (int k = 0; k <= ub_loop; k++) {
    if (Xq[k] >= d_X[0]) {
      if (Xq[k] <= d_X[d_X.size(1) - 1]) {
        if (Yq[k] >= g_Y[0]) {
          if (Yq[k] <= g_Y[g_Y.size(1) - 1]) {
            b_ix = ::coder::internal::b_bsearch(d_X, Xq[k]);
            b_iy = ::coder::internal::b_bsearch(g_Y, Yq[k]);
            zx1y1 = V[(b_iy + (V.size(0) * (b_ix - 1))) - 1];
            zx2y1 = V[(b_iy + (V.size(0) * b_ix)) - 1];
            zx1y2 = V[b_iy + (V.size(0) * (b_ix - 1))];
            zx2y2 = V[b_iy + (V.size(0) * b_ix)];
            f = d_X[b_ix - 1];
            if (Xq[k] == f) {
              qx1 = zx1y1;
              qx2 = zx1y2;
            } else if (Xq[k] == d_X[b_ix]) {
              qx1 = zx2y1;
              qx2 = zx2y2;
            } else {
              rx = (Xq[k] - f) / (d_X[b_ix] - f);
              if (zx1y1 == zx2y1) {
                qx1 = zx1y1;
              } else {
                qx1 = ((1.0F - rx) * zx1y1) + (rx * zx2y1);
              }
              if (zx1y2 == zx2y2) {
                qx2 = zx1y2;
              } else {
                qx2 = ((1.0F - rx) * zx1y2) + (rx * zx2y2);
              }
            }
            f1 = g_Y[b_iy - 1];
            if (Yq[k] == f1) {
              Vq[k] = qx1;
            } else if (qx1 == qx2) {
              Vq[k] = qx1;
            } else if (Yq[k] == g_Y[b_iy]) {
              Vq[k] = qx2;
            } else {
              ry = (Yq[k] - f1) / (g_Y[b_iy] - f1);
              Vq[k] = ((1.0F - ry) * qx1) + (ry * qx2);
            }
          } else {
            Vq[k] = extrapval;
          }
        } else {
          Vq[k] = extrapval;
        }
      } else {
        Vq[k] = extrapval;
      }
    } else {
      Vq[k] = extrapval;
    }
  }
}

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder

//
// File trailer for interp2.cpp
//
// [EOF]
//
