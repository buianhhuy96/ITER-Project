//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp2.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "interp2.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &V
//                const ::coder::array<float, 2U> &Xq
//                const ::coder::array<float, 2U> &Yq
//                float extrapval
//                const ::coder::array<float, 2U> &b_X
//                const ::coder::array<float, 2U> &Y
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
                   const ::coder::array<float, 2U> &b_X,
                   const ::coder::array<float, 2U> &Y,
                   ::coder::array<float, 2U> &Vq)
{
  float qx1;
  float qx2;
  float rx;
  float zx1y1;
  float zx1y2;
  int ix;
  int iy;
  int k;
  int ub_loop;
  Vq.set_size(Xq.size(0), Xq.size(1));
  ub_loop = (Xq.size(0) * Xq.size(1)) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    k, ix, iy, zx1y1, qx1, zx1y2, qx2, rx)

  for (k = 0; k <= ub_loop; k++) {
    if (Xq[k] >= b_X[0]) {
      if (Xq[k] <= b_X[b_X.size(1) - 1]) {
        if (Yq[k] >= Y[0]) {
          if (Yq[k] <= Y[Y.size(1) - 1]) {
            ix = ::coder::internal::b_bsearch(b_X, Xq[k]);
            iy = ::coder::internal::b_bsearch(Y, Yq[k]);
            zx1y1 = V[(iy + (V.size(0) * (ix - 1))) - 1];
            qx1 = V[(iy + (V.size(0) * ix)) - 1];
            zx1y2 = V[iy + (V.size(0) * (ix - 1))];
            qx2 = V[iy + (V.size(0) * ix)];
            rx = b_X[ix - 1];
            if (Xq[k] == rx) {
              qx1 = zx1y1;
              qx2 = zx1y2;
            } else if (!(Xq[k] == b_X[ix])) {
              rx = (Xq[k] - rx) / (b_X[ix] - rx);
              if (zx1y1 == qx1) {
                qx1 = zx1y1;
              } else {
                qx1 = ((1.0F - rx) * zx1y1) + (rx * qx1);
              }
              if (zx1y2 == qx2) {
                qx2 = zx1y2;
              } else {
                qx2 = ((1.0F - rx) * zx1y2) + (rx * qx2);
              }
            } else {
              /* no actions */
            }
            rx = Y[iy - 1];
            if (Yq[k] == rx) {
              Vq[k] = qx1;
            } else if (qx1 == qx2) {
              Vq[k] = qx1;
            } else if (Yq[k] == Y[iy]) {
              Vq[k] = qx2;
            } else {
              rx = (Yq[k] - rx) / (Y[iy] - rx);
              Vq[k] = ((1.0F - rx) * qx1) + (rx * qx2);
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
