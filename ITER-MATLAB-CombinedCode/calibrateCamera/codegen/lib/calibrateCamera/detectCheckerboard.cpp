//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "calibrateCamera_rtwutil.h"
#include "cat.h"
#include "find_peaks.h"
#include "flip.h"
#include "imfilter.h"
#include "isequal.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(real_T d_X[4], real_T d_Y[4], real_T height,
                          real_T width, ::coder::array<boolean_T, 2U> &mask);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static real32_T rt_atan2f_snf(real32_T u0, real32_T u1);

} // namespace Codegen

// Function Definitions
//
// Arguments    : real_T d_X[4]
//                real_T d_Y[4]
//                real_T height
//                real_T width
//                ::coder::array<boolean_T, 2U> &mask
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(real_T d_X[4], real_T d_Y[4], real_T height,
                          real_T width, ::coder::array<boolean_T, 2U> &mask)
{
  int32_T b_i;
  int32_T b_loop_ub_tmp;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  ::Codegen::coder::internal::d_sort(d_X);
  ::Codegen::coder::internal::d_sort(d_Y);
  loop_ub_tmp = static_cast<int32_T>(height);
  b_loop_ub_tmp = static_cast<int32_T>(width);
  mask.set_size(loop_ub_tmp, b_loop_ub_tmp);
  for (b_i = 0; b_i < b_loop_ub_tmp; b_i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      mask[i1 + (mask.size(0) * b_i)] = false;
    }
  }
  if (d_Y[1] > d_Y[2]) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (static_cast<int32_T>(d_Y[1])) - 1;
    i1 = static_cast<int32_T>(d_Y[2]);
  }
  if (d_X[1] > d_X[2]) {
    loop_ub_tmp = 0;
    i2 = 0;
  } else {
    loop_ub_tmp = (static_cast<int32_T>(d_X[1])) - 1;
    i2 = static_cast<int32_T>(d_X[2]);
  }
  b_loop_ub_tmp = i1 - b_i;
  loop_ub = i2 - loop_ub_tmp;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
      mask[(b_i + i2) + (mask.size(0) * (loop_ub_tmp + i1))] = true;
    }
  }
}

//
// Arguments    : real32_T u0
//                real32_T u1
// Return Type  : real32_T
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaNF;
  } else if ((std::isinf(u0)) && (std::isinf(u1))) {
    int32_T b_u0;
    int32_T b_u1;
    if (u0 > 0.0F) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0F) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = std::atan2(static_cast<real32_T>(b_u0), static_cast<real32_T>(b_u1));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<real32_T, 2U> &g_I
//                ::coder::array<real_T, 2U> &b_points
//                real_T boardSize[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<real32_T, 2U> &g_I,
                        ::coder::array<real_T, 2U> &b_points,
                        real_T boardSize[2])
{
  static const real_T dv[29]{
      0.00021823147295907278, 0.00050740337669472676, 0.0011082708667872047,
      0.0022740241675853856,  0.0043832963079210854,  0.0079371242384296773,
      0.013501503141458728,   0.02157534058754523,    0.032388422317464506,
      0.045674996382257374,   0.060509539062210613,   0.075305338074579134,
      0.088040859838021152,   0.096693968100022676,   0.099763364132126955,
      0.096693968100022676,   0.088040859838021152,   0.075305338074579134,
      0.060509539062210613,   0.045674996382257374,   0.032388422317464506,
      0.02157534058754523,    0.013501503141458728,   0.0079371242384296773,
      0.0043832963079210854,  0.0022740241675853856,  0.0011082708667872047,
      0.00050740337669473586, 0.00021823147295907272};
  static const real_T hCol[29]{
      0.00021823147295907269, 0.00050740337669472686, 0.0011082708667872049,
      0.0022740241675853852,  0.0043832963079210854,  0.0079371242384296756,
      0.013501503141458728,   0.021575340587545226,   0.0323884223174645,
      0.04567499638225736,    0.06050953906221062,    0.0753053380745791,
      0.088040859838021152,   0.09669396810002269,    0.099763364132126942,
      0.09669396810002269,    0.088040859838021152,   0.0753053380745791,
      0.06050953906221062,    0.04567499638225736,    0.0323884223174645,
      0.021575340587545226,   0.013501503141458728,   0.0079371242384296756,
      0.0043832963079210854,  0.0022740241675853852,  0.0011082708667872049,
      0.00050740337669472686, 0.00021823147295905031};
  b_Checkerboard lobj_0[6];
  b_Checkerboard *board0;
  b_Checkerboard *board45;
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> c_a;
  ::coder::array<real_T, 2U> temp;
  ::coder::array<real_T, 1U> s;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<real32_T, 2U> I_45;
  ::coder::array<real32_T, 2U> I_45_x;
  ::coder::array<real32_T, 2U> Ig;
  ::coder::array<real32_T, 2U> Ixy;
  ::coder::array<real32_T, 2U> Iy;
  ::coder::array<real32_T, 2U> b_a;
  ::coder::array<real32_T, 2U> b_x;
  ::coder::array<real32_T, 2U> b_y;
  ::coder::array<real32_T, 2U> points0;
  ::coder::array<real32_T, 2U> y;
  ::coder::array<real32_T, 1U> d_a;
  real_T b_board45[2];
  real_T pad[2];
  int32_T b_i;
  int32_T b_ix;
  int32_T b_loop_ub;
  int32_T d_i;
  int32_T h_N;
  int32_T i1;
  int32_T loop_ub;
  boolean_T guard1{false};
  boolean_T guard2{false};
  pad[0] = 14.0;
  pad[1] = 14.0;
  if ((g_I.size(0) == 0) || (g_I.size(1) == 0)) {
    Ig.set_size(g_I.size(0), g_I.size(1));
    loop_ub = g_I.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = g_I.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Ig[i1 + (Ig.size(0) * b_i)] = g_I[i1 + (g_I.size(0) * b_i)];
      }
    }
  } else {
    int32_T ix;
    padImage_outSize(g_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b_a.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c_a[i1 + (c_a.size(0) * b_i)] =
            static_cast<real_T>(b_a[i1 + (b_a.size(0) * b_i)]);
      }
    }
    b.set_size(g_I.size(0), g_I.size(1));
    temp.set_size(c_a.size(0), g_I.size(1));
    b_i = g_I.size(1);
    loop_ub = c_a.size(0);
    i1 = c_a.size(0);
    b_loop_ub = c_a.size(0);
    for (ix = 0; ix < b_i; ix++) {
      int32_T i2;
      for (i2 = 0; i2 < loop_ub; i2++) {
        temp[i2 + (temp.size(0) * ix)] = 0.0;
      }
      for (d_i = 0; d_i < 29; d_i++) {
        b_ix = static_cast<int32_T>(static_cast<uint32_T>(
            (static_cast<uint32_T>(ix)) + (static_cast<uint32_T>(d_i))));
        s.set_size(i1);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          s[i2] = c_a[i2 + (c_a.size(0) * b_ix)] * dv[d_i];
        }
        h_N = temp.size(0) - 1;
        s.set_size(temp.size(0));
        for (i2 = 0; i2 <= h_N; i2++) {
          s[i2] = temp[i2 + (temp.size(0) * ix)] + s[i2];
        }
        h_N = s.size(0);
        for (i2 = 0; i2 < h_N; i2++) {
          temp[i2 + (temp.size(0) * ix)] = s[i2];
        }
      }
    }
    b_i = g_I.size(1);
    for (ix = 0; ix < b_i; ix++) {
      i1 = g_I.size(0);
      for (h_N = 0; h_N < i1; h_N++) {
        real_T d;
        d = 0.0;
        for (d_i = 0; d_i < 29; d_i++) {
          d += temp[(static_cast<int32_T>(
                        static_cast<uint32_T>((static_cast<uint32_T>(h_N)) +
                                              (static_cast<uint32_T>(d_i))))) +
                    (temp.size(0) * ix)] *
               hCol[d_i];
        }
        b[h_N + (b.size(0) * ix)] = d;
      }
    }
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Ig[i1 + (Ig.size(0) * b_i)] =
            static_cast<real32_T>(b[i1 + (b.size(0) * b_i)]);
      }
    }
  }
  Iy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Iy[i1 + (Iy.size(0) * b_i)] = Ig[i1 + (Ig.size(0) * b_i)];
    }
  }
  imfilter(Iy);
  b_imfilter(Ig);
  Ixy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Ixy[i1 + (Ixy.size(0) * b_i)] = Ig[i1 + (Ig.size(0) * b_i)];
    }
  }
  imfilter(Ixy);
  b_x.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_x[i1 + (b_x.size(0) * b_i)] =
          Ig[i1 + (Ig.size(0) * b_i)] * 0.707106769F;
    }
  }
  I_45.set_size(b_x.size(0), b_x.size(1));
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45[i1 + (I_45.size(0) * b_i)] =
          b_x[i1 + (b_x.size(0) * b_i)] +
          (Iy[i1 + (Iy.size(0) * b_i)] * 0.707106769F);
    }
  }
  I_45_x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45_x[i1 + (I_45_x.size(0) * b_i)] = I_45[i1 + (I_45.size(0) * b_i)];
    }
  }
  b_imfilter(I_45_x);
  b_a.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_a[i1 + (b_a.size(0) * b_i)] = I_45[i1 + (I_45.size(0) * b_i)];
    }
  }
  imfilter(b_a);
  loop_ub = I_45_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45_x[i1 + (I_45_x.size(0) * b_i)] =
          (I_45_x[i1 + (I_45_x.size(0) * b_i)] * 0.707106769F) +
          (b_a[i1 + (b_a.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = Ixy.size(1);
  y.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        y[b_ix + (y.size(0) * loop_ub)] =
            std::abs(Ixy[b_ix + (Ixy.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + (y.size(0) * b_i)] = 16.0F * y[i1 + (y.size(0) * b_i)];
    }
  }
  b_i = I_45.size(1);
  b_y.set_size(I_45.size(0), I_45.size(1));
  if ((I_45.size(0) != 0) && (I_45.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = b_y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        b_y[b_ix + (b_y.size(0) * loop_ub)] =
            std::abs(I_45[b_ix + (I_45.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_x[i1 + (b_x.size(0) * b_i)] =
          b_x[i1 + (b_x.size(0) * b_i)] +
          (Iy[i1 + (Iy.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = b_x.size(1);
  I_45.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = I_45.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        I_45[b_ix + (I_45.size(0) * loop_ub)] =
            std::abs(b_x[b_ix + (b_x.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = b_y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_y[i1 + (b_y.size(0) * b_i)] = 6.0F * (b_y[i1 + (b_y.size(0) * b_i)] +
                                              I_45[i1 + (I_45.size(0) * b_i)]);
    }
  }
  b_a.set_size(y.size(0), y.size(1));
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_a[i1 + (b_a.size(0) * b_i)] =
          y[i1 + (y.size(0) * b_i)] - b_y[i1 + (b_y.size(0) * b_i)];
    }
  }
  b_ix = (y.size(0) * y.size(1)) - 1;
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if ((y[d_i] - b_y[d_i]) < 0.0F) {
      h_N++;
    }
  }
  r.set_size(h_N);
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if ((y[d_i] - b_y[d_i]) < 0.0F) {
      r[h_N] = d_i + 1;
      h_N++;
    }
  }
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_a[r[b_i] - 1] = 0.0F;
  }
  b_i = I_45_x.size(1);
  y.set_size(I_45_x.size(0), I_45_x.size(1));
  if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        y[b_ix + (y.size(0) * loop_ub)] =
            std::abs(I_45_x[b_ix + (I_45_x.size(0) * loop_ub)]);
      }
    }
  }
  b_i = Ig.size(1);
  b_y.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = b_y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        b_y[b_ix + (b_y.size(0) * loop_ub)] =
            std::abs(Ig[b_ix + (Ig.size(0) * loop_ub)]);
      }
    }
  }
  b_i = Iy.size(1);
  I_45.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = I_45.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        I_45[b_ix + (I_45.size(0) * loop_ub)] =
            std::abs(Iy[b_ix + (Iy.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + (y.size(0) * b_i)] = (16.0F * y[i1 + (y.size(0) * b_i)]) -
                                  (6.0F * (b_y[i1 + (b_y.size(0) * b_i)] +
                                           I_45[i1 + (I_45.size(0) * b_i)]));
    }
  }
  b_ix = (y.size(0) * y.size(1)) - 1;
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if (y[d_i] < 0.0F) {
      h_N++;
    }
  }
  r1.set_size(h_N);
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if (y[d_i] < 0.0F) {
      r1[h_N] = d_i + 1;
      h_N++;
    }
  }
  loop_ub = r1.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    y[r1[b_i] - 1] = 0.0F;
  }
  b_i = Ig.size(1);
  b_y.set_size(Ig.size(0), Ig.size(1));
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    h_N = b_y.size(0);
    for (b_ix = 0; b_ix < h_N; b_ix++) {
      b_y[b_ix + (b_y.size(0) * loop_ub)] =
          rt_powf_snf(Ig[b_ix + (Ig.size(0) * loop_ub)], 2.0F);
    }
  }
  c_imfilter(b_y);
  b_i = Iy.size(1);
  I_45.set_size(Iy.size(0), Iy.size(1));
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    h_N = I_45.size(0);
    for (b_ix = 0; b_ix < h_N; b_ix++) {
      I_45[b_ix + (I_45.size(0) * loop_ub)] =
          rt_powf_snf(Iy[b_ix + (Iy.size(0) * loop_ub)], 2.0F);
    }
  }
  c_imfilter(I_45);
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Ig[i1 + (Ig.size(0) * b_i)] =
          Ig[i1 + (Ig.size(0) * b_i)] * Iy[i1 + (Iy.size(0) * b_i)];
    }
  }
  c_imfilter(Ig);
  find_peaks(b_a, points0);
  h_N = b_a.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<real_T>(static_cast<int32_T>(
        (static_cast<int32_T>(points0[b_i + points0.size(0)])) +
        (h_N * ((static_cast<int32_T>(points0[b_i])) - 1))));
  }
  d_a.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_a[b_i] = b_a[(static_cast<int32_T>(s[b_i])) - 1];
  }
  board0 = growCheckerboard(points0, d_a, b_y, I_45, Ig, 0.0, &lobj_0[0]);
  b_points.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  find_peaks(y, points0);
  h_N = y.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<real_T>(static_cast<int32_T>(
        (static_cast<int32_T>(points0[b_i + points0.size(0)])) +
        (h_N * ((static_cast<int32_T>(points0[b_i])) - 1))));
  }
  d_a.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_a[b_i] = y[(static_cast<int32_T>(s[b_i])) - 1];
  }
  board45 = growCheckerboard(points0, d_a, b_y, I_45, Ig, 0.78539816339744828,
                             &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      pad[0] = static_cast<real_T>(board0->BoardIdx.size(0));
      pad[1] = static_cast<real_T>(board0->BoardIdx.size(1));
      b_board45[0] = static_cast<real_T>(board45->BoardIdx.size(0));
      b_board45[1] = static_cast<real_T>(board45->BoardIdx.size(1));
      if (isequal(pad, b_board45)) {
        h_N = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(h_N);
        for (b_i = 0; b_i < h_N; b_i++) {
          s[b_i] = board0->BoardIdx[b_i];
        }
        b_loop_ub = 0;
        b_i = s.size(0);
        for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            b_loop_ub++;
          }
        }
        h_N = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(h_N);
        for (b_i = 0; b_i < h_N; b_i++) {
          s[b_i] = board45->BoardIdx[b_i];
        }
        b_ix = 0;
        b_i = s.size(0);
        for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            b_ix++;
          }
        }
        if (b_loop_ub > b_ix) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }
  if (guard2) {
    board0 = orient(board0, g_I);
    toPoints(board0, b_points, boardSize);
    subPixelLocation(Ixy, b_points);
  }
  if (guard1 && (board45->isValid)) {
    board45 = orient(board45, g_I);
    toPoints(board45, b_points, boardSize);
    subPixelLocation(I_45_x, b_points);
  }
}

//
// Arguments    : const ::coder::array<real32_T, 2U> &b_points
//                const ::coder::array<real32_T, 1U> &scores
//                const ::coder::array<real32_T, 2U> &Ix2
//                const ::coder::array<real32_T, 2U> &Iy2
//                const ::coder::array<real32_T, 2U> &Ixy
//                real_T theta
//                b_Checkerboard *b_iobj_0
// Return Type  : b_Checkerboard *
//
b_Checkerboard *growCheckerboard(const ::coder::array<real32_T, 2U> &b_points,
                                 const ::coder::array<real32_T, 1U> &scores,
                                 const ::coder::array<real32_T, 2U> &Ix2,
                                 const ::coder::array<real32_T, 2U> &Iy2,
                                 const ::coder::array<real32_T, 2U> &Ixy,
                                 real_T theta, b_Checkerboard *b_iobj_0)
{
  b_Checkerboard *board;
  b_Checkerboard *currentBoard;
  b_Checkerboard *tmpBoard;
  ::coder::array<real_T, 2U> b_seedIdx;
  ::coder::array<real_T, 2U> seedIdx;
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<real32_T, 1U> b_x;
  real32_T v1[2];
  real32_T v2[2];
  if (scores.size(0) == 0) {
    int32_T b_i;
    b_iobj_0[0].isValid = false;
    b_iobj_0[0].Energy = rtInfF;
    b_iobj_0[0].IsDistortionHigh = false;
    board = &b_iobj_0[0];
    b_iobj_0[0].BoardIdx.set_size(1, 1);
    b_iobj_0[0].BoardIdx[0] = 0.0;
    b_iobj_0[0].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[0].BoardIdx[b_iobj_0[0].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[0].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[0].BoardCoords[0] = 0.0;
    b_iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (int32_T i1{0}; i1 < 3; i1++) {
        b_iobj_0[0].BoardCoords[(b_iobj_0[0].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[0].BoardCoords.size(0) *
                                  b_iobj_0[0].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[0].Points.set_size(1, 1);
    b_iobj_0[0].Points[0] = 0.0F;
    b_iobj_0[0].Points.set_size(0, 2);
  } else {
    int32_T b_i;
    int32_T i1;
    int32_T loop_ub;
    if (b_points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      seedIdx.set_size(1, b_points.size(0));
      loop_ub = b_points.size(0) - 1;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        seedIdx[b_i] = (static_cast<real_T>(b_i)) + 1.0;
      }
    }
    b_x.set_size(seedIdx.size(1));
    loop_ub = seedIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_x[b_i] = scores[(static_cast<int32_T>(seedIdx[b_i])) - 1];
    }
    ::Codegen::coder::internal::sort(b_x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    loop_ub = iidx.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_seedIdx[b_i] =
          static_cast<real_T>(static_cast<uint32_T>(seedIdx[iidx[b_i] - 1]));
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    loop_ub = b_seedIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      seedIdx[b_i] = b_seedIdx[b_i];
    }
    if (iidx.size(0) > 2000) {
      b_i = static_cast<int32_T>(std::fmin(
          2000.0, std::round((static_cast<real_T>(seedIdx.size(1))) / 2.0)));
      if (1 > b_i) {
        loop_ub = 0;
      } else {
        loop_ub = b_i;
      }
      for (b_i = 0; b_i < loop_ub; b_i++) {
        seedIdx[b_i] = static_cast<real_T>(static_cast<uint32_T>(seedIdx[b_i]));
      }
      seedIdx.set_size(1, loop_ub);
    }
    board = &b_iobj_0[1];
    b_iobj_0[1].isValid = false;
    b_iobj_0[1].Energy = rtInfF;
    b_iobj_0[1].IsDistortionHigh = false;
    b_iobj_0[1].BoardIdx.set_size(1, 1);
    b_iobj_0[1].BoardIdx[0] = 0.0;
    b_iobj_0[1].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[1].BoardIdx[b_iobj_0[1].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[1].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[1].BoardCoords[0] = 0.0;
    b_iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_iobj_0[1].BoardCoords[(b_iobj_0[1].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[1].BoardCoords.size(0) *
                                  b_iobj_0[1].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[1].Points.set_size(1, 1);
    b_iobj_0[1].Points[0] = 0.0F;
    b_iobj_0[1].Points.set_size(0, 2);
    b_iobj_0[1].IsDistortionHigh = false;
    currentBoard = &b_iobj_0[2];
    b_iobj_0[2].isValid = false;
    b_iobj_0[2].Energy = rtInfF;
    b_iobj_0[2].IsDistortionHigh = false;
    b_iobj_0[2].BoardIdx.set_size(1, 1);
    b_iobj_0[2].BoardIdx[0] = 0.0;
    b_iobj_0[2].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[2].BoardIdx[b_iobj_0[2].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[2].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[2].BoardCoords[0] = 0.0;
    b_iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_iobj_0[2].BoardCoords[(b_iobj_0[2].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[2].BoardCoords.size(0) *
                                  b_iobj_0[2].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[2].Points.set_size(1, 1);
    b_iobj_0[2].Points[0] = 0.0F;
    b_iobj_0[2].Points.set_size(0, 2);
    b_iobj_0[2].IsDistortionHigh = false;
    b_i = seedIdx.size(1);
    for (int32_T d_i{0}; d_i < b_i; d_i++) {
      real_T d;
      int32_T sgn2;
      real32_T ab;
      real32_T adf;
      real32_T b;
      real32_T b_a;
      real32_T c;
      real32_T df;
      real32_T tb;
      boolean_T guard1{false};
      d = seedIdx[d_i];
      sgn2 = (static_cast<int32_T>(
                 b_points[((static_cast<int32_T>(static_cast<uint32_T>(d))) +
                           b_points.size(0)) -
                          1])) -
             1;
      loop_ub =
          (static_cast<int32_T>(
              b_points[(static_cast<int32_T>(static_cast<uint32_T>(d))) - 1])) -
          1;
      b_a = Ix2[sgn2 + (Ix2.size(0) * loop_ub)];
      b = Ixy[sgn2 + (Ixy.size(0) * loop_ub)];
      c = Iy2[sgn2 + (Iy2.size(0) * loop_ub)];
      df = b_a - c;
      adf = std::abs(df);
      tb = b + b;
      ab = std::abs(tb);
      if (adf > ab) {
        b = adf * std::sqrt(rt_powf_snf(ab / adf, 2.0F) + 1.0F);
      } else if (adf < ab) {
        b = ab * std::sqrt(rt_powf_snf(adf / ab, 2.0F) + 1.0F);
      } else {
        b = ab * 1.41421354F;
      }
      if (df > 0.0F) {
        adf = df + b;
        sgn2 = 1;
      } else {
        adf = df - b;
        sgn2 = -1;
      }
      if (std::abs(adf) > ab) {
        b = (-tb) / adf;
        tb = 1.0F / std::sqrt((b * b) + 1.0F);
        df = b * tb;
      } else if (ab == 0.0F) {
        df = 1.0F;
        tb = 0.0F;
      } else {
        b = (-adf) / tb;
        df = 1.0F / std::sqrt((b * b) + 1.0F);
        tb = b * df;
      }
      if ((b_a + c) < 0.0F) {
        loop_ub = -1;
      } else {
        loop_ub = 1;
      }
      if (loop_ub == sgn2) {
        b = df;
        df = -tb;
        tb = b;
      }
      v1[0] = ((-tb) * 0.707106769F) + (df * 0.707106769F);
      adf = ((-tb) * -0.707106769F) + (df * 0.707106769F);
      v1[1] = adf;
      v2[0] = (df * 0.707106769F) + (tb * 0.707106769F);
      b = (df * -0.707106769F) + (tb * 0.707106769F);
      v2[1] = b;
      guard1 = false;
      if ((static_cast<real_T>(std::abs(
              std::abs(std::abs(rt_atan2f_snf(adf, v1[0])) - 3.14159274F) -
              (static_cast<real32_T>(theta))))) > 0.58904862254808621) {
        if (!((static_cast<real_T>(std::abs(
                  std::abs(std::abs(rt_atan2f_snf(b, v2[0])) - 3.14159274F) -
                  (static_cast<real32_T>(theta))))) > 0.58904862254808621)) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        currentBoard->initialize(static_cast<real_T>(static_cast<uint32_T>(d)),
                                 b_points, v1, v2);
        if (currentBoard->isValid) {
          boolean_T hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            int32_T e_i;
            currentBoard->PreviousEnergy = currentBoard->Energy;
            e_i = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (e_i < 4) {
                if (!currentBoard->IsDirectionBad[e_i]) {
                  currentBoard->LastExpandDirection =
                      (static_cast<real_T>(e_i)) + 1.0;
                  currentBoard->expandBoardDirectionally(
                      (static_cast<real_T>(e_i)) + 1.0);
                  if (currentBoard->Energy < currentBoard->PreviousEnergy) {
                    exitg1 = 1;
                  } else {
                    currentBoard->Energy = currentBoard->PreviousEnergy;
                    switch (static_cast<int32_T>(
                        currentBoard->LastExpandDirection)) {
                    case 1: {
                      int32_T b_currentBoard;
                      int32_T c_currentBoard;
                      int32_T i2;
                      int32_T i3;
                      int32_T i4;
                      i1 = currentBoard->BoardIdx.size(0);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (i3 = 0; i3 <= b_currentBoard; i3++) {
                        sgn2 = i1 - i2;
                        for (i4 = 0; i4 < sgn2; i4++) {
                          currentBoard->BoardIdx[i4 + (sgn2 * i3)] =
                              currentBoard
                                  ->BoardIdx[((i2 + i4) +
                                              (currentBoard->BoardIdx.size(0) *
                                               i3)) +
                                             1];
                        }
                      }
                      currentBoard->BoardIdx.set_size(i1 - i2,
                                                      b_currentBoard + 1);
                      i1 = currentBoard->BoardCoords.size(0);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      loop_ub = b_currentBoard + 1;
                      for (i3 = 0; i3 <= c_currentBoard; i3++) {
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          sgn2 = i1 - i2;
                          for (int32_T i5{0}; i5 < sgn2; i5++) {
                            currentBoard
                                ->BoardCoords[(i5 + (sgn2 * i4)) +
                                              ((sgn2 * (b_currentBoard + 1)) *
                                               i3)] =
                                currentBoard->BoardCoords
                                    [(((i2 + i5) +
                                       (currentBoard->BoardCoords.size(0) *
                                        i4)) +
                                      ((currentBoard->BoardCoords.size(0) *
                                        currentBoard->BoardCoords.size(1)) *
                                       i3)) +
                                     1];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          i1 - i2, b_currentBoard + 1, c_currentBoard + 1);
                    } break;
                    case 2: {
                      int32_T b_currentBoard;
                      int32_T c_currentBoard;
                      int32_T i2;
                      d = (static_cast<real_T>(
                              currentBoard->BoardIdx.size(0))) -
                          1.0;
                      if (1.0 > d) {
                        loop_ub = 0;
                      } else {
                        loop_ub = static_cast<int32_T>(d);
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (i1 = 0; i1 <= b_currentBoard; i1++) {
                        for (i2 = 0; i2 < loop_ub; i2++) {
                          currentBoard->BoardIdx[i2 + (loop_ub * i1)] =
                              currentBoard->BoardIdx
                                  [i2 + (currentBoard->BoardIdx.size(0) * i1)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(loop_ub,
                                                      b_currentBoard + 1);
                      d = (static_cast<real_T>(
                              currentBoard->BoardCoords.size(0))) -
                          1.0;
                      if (1.0 > d) {
                        loop_ub = 0;
                      } else {
                        loop_ub = static_cast<int32_T>(d);
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 <= c_currentBoard; i1++) {
                        for (i2 = 0; i2 < sgn2; i2++) {
                          for (int32_T i3{0}; i3 < loop_ub; i3++) {
                            currentBoard->BoardCoords
                                [(i3 + (loop_ub * i2)) +
                                 ((loop_ub * (b_currentBoard + 1)) * i1)] =
                                currentBoard->BoardCoords
                                    [(i3 + (currentBoard->BoardCoords.size(0) *
                                            i2)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i1)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          loop_ub, b_currentBoard + 1, c_currentBoard + 1);
                    } break;
                    case 3: {
                      int32_T b_currentBoard;
                      int32_T c_currentBoard;
                      int32_T i2;
                      int32_T i3;
                      i1 = currentBoard->BoardIdx.size(1);
                      if (2 > i1) {
                        i2 = 0;
                        i1 = 0;
                      } else {
                        i2 = 1;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      loop_ub = b_currentBoard + 1;
                      sgn2 = i1 - i2;
                      for (i1 = 0; i1 < sgn2; i1++) {
                        for (i3 = 0; i3 < loop_ub; i3++) {
                          currentBoard
                              ->BoardIdx[i3 + ((b_currentBoard + 1) * i1)] =
                              currentBoard
                                  ->BoardIdx[i3 +
                                             (currentBoard->BoardIdx.size(0) *
                                              (i2 + i1))];
                        }
                      }
                      currentBoard->BoardIdx.set_size(b_currentBoard + 1, sgn2);
                      i1 = currentBoard->BoardCoords.size(1);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      loop_ub = b_currentBoard + 1;
                      for (i3 = 0; i3 <= c_currentBoard; i3++) {
                        sgn2 = i1 - i2;
                        for (int32_T i4{0}; i4 < sgn2; i4++) {
                          for (int32_T i5{0}; i5 < loop_ub; i5++) {
                            currentBoard->BoardCoords
                                [(i5 + ((b_currentBoard + 1) * i4)) +
                                 (((b_currentBoard + 1) * sgn2) * i3)] =
                                currentBoard->BoardCoords
                                    [(i5 + (currentBoard->BoardCoords.size(0) *
                                            ((i2 + i4) + 1))) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i3)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          b_currentBoard + 1, i1 - i2, c_currentBoard + 1);
                    } break;
                    case 4: {
                      int32_T b_currentBoard;
                      int32_T c_currentBoard;
                      int32_T i2;
                      d = (static_cast<real_T>(
                              currentBoard->BoardIdx.size(1))) -
                          1.0;
                      if (1.0 > d) {
                        loop_ub = 0;
                      } else {
                        loop_ub = static_cast<int32_T>(d);
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        for (i2 = 0; i2 < sgn2; i2++) {
                          currentBoard
                              ->BoardIdx[i2 + ((b_currentBoard + 1) * i1)] =
                              currentBoard->BoardIdx
                                  [i2 + (currentBoard->BoardIdx.size(0) * i1)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(b_currentBoard + 1,
                                                      loop_ub);
                      d = (static_cast<real_T>(
                              currentBoard->BoardCoords.size(1))) -
                          1.0;
                      if (1.0 > d) {
                        loop_ub = 0;
                      } else {
                        loop_ub = static_cast<int32_T>(d);
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 <= c_currentBoard; i1++) {
                        for (i2 = 0; i2 < loop_ub; i2++) {
                          for (int32_T i3{0}; i3 < sgn2; i3++) {
                            currentBoard->BoardCoords
                                [(i3 + ((b_currentBoard + 1) * i2)) +
                                 (((b_currentBoard + 1) * loop_ub) * i1)] =
                                currentBoard->BoardCoords
                                    [(i3 + (currentBoard->BoardCoords.size(0) *
                                            i2)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i1)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          b_currentBoard + 1, loop_ub, c_currentBoard + 1);
                    } break;
                    default:
                      /* no actions */
                      break;
                    }
                    currentBoard->IsDirectionBad[e_i] = true;
                    e_i++;
                  }
                } else {
                  e_i++;
                }
              } else {
                hasExpanded = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (currentBoard->Energy < board->Energy) {
          tmpBoard = board;
          board = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
  }
  return board;
}

//
// Arguments    : b_Checkerboard *board
//                const ::coder::array<real32_T, 2U> &g_I
// Return Type  : b_Checkerboard *
//
b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<real32_T, 2U> &g_I)
{
  b_Checkerboard *b_board;
  ::coder::array<real_T, 2U> *c_B;
  ::coder::array<real_T, 3U> r1;
  ::coder::array<real_T, 3U> r4;
  ::coder::array<real_T, 3U> r5;
  ::coder::array<real_T, 2U> newBoardCoords1;
  ::coder::array<real_T, 2U> newBoardCoords2;
  ::coder::array<real_T, 2U> r;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<real32_T, 1U> h_I;
  ::coder::array<real32_T, 1U> m_I;
  ::coder::array<boolean_T, 3U> c_x;
  ::coder::array<boolean_T, 2U> nextSquareMask;
  ::coder::array<boolean_T, 2U> upperLeftMask;
  ::coder::array<boolean_T, 2U> y;
  real_T c_board[4];
  real_T cornerIdx[4];
  real_T numRot_data;
  int32_T numRot_size[2];
  real32_T b_x;
  int8_T ii_data;
  b_board = board;
  b_x = b_board->Energy;
  if (!std::isinf(b_x)) {
    int32_T b_i;
    int32_T d_i;
    int32_T g_n;
    int32_T loop_ub;
    int32_T m;
    boolean_T b_y;
    boolean_T exitg1;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                               b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(1) - 1;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        g_n = b_board->BoardIdx.size(0) - 1;
        for (d_i = 0; d_i <= g_n; d_i++) {
          newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
              b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
        }
      }
      c_B = &b_board->BoardIdx;
      m = newBoardCoords2.size(0) - 1;
      g_n = newBoardCoords2.size(1) - 1;
      b_board->BoardIdx.set_size(newBoardCoords2.size(1),
                                 newBoardCoords2.size(0));
      if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      } else {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      }
      loop_ub = b_board->BoardCoords.size(0);
      g_n = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, g_n);
      for (b_i = 0; b_i < g_n; b_i++) {
        for (d_i = 0; d_i < loop_ub; d_i++) {
          newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
              b_board->BoardCoords[d_i + (b_board->BoardCoords.size(0) * b_i)];
        }
      }
      m = newBoardCoords2.size(0) - 1;
      g_n = newBoardCoords2.size(1) - 1;
      newBoardCoords1.set_size(newBoardCoords2.size(1),
                               newBoardCoords2.size(0));
      if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      } else {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      }
      loop_ub = b_board->BoardCoords.size(0);
      g_n = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, g_n);
      for (b_i = 0; b_i < g_n; b_i++) {
        for (d_i = 0; d_i < loop_ub; d_i++) {
          newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
              b_board
                  ->BoardCoords[(d_i + (b_board->BoardCoords.size(0) * b_i)) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))];
        }
      }
      m = newBoardCoords2.size(0) - 1;
      g_n = newBoardCoords2.size(1) - 1;
      r.set_size(newBoardCoords2.size(1), newBoardCoords2.size(0));
      if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            r[d_i + (r.size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      } else {
        for (d_i = 0; d_i <= g_n; d_i++) {
          for (loop_ub = 0; loop_ub <= m; loop_ub++) {
            r[d_i + (r.size(0) * loop_ub)] =
                newBoardCoords2[loop_ub +
                                (newBoardCoords2.size(0) * (g_n - d_i))];
          }
        }
      }
      cat(newBoardCoords1, r, r1);
      b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
      loop_ub = r1.size(1);
      for (b_i = 0; b_i < 2; b_i++) {
        for (d_i = 0; d_i < loop_ub; d_i++) {
          g_n = r1.size(0);
          for (m = 0; m < g_n; m++) {
            b_board->BoardCoords[(m + (b_board->BoardCoords.size(0) * d_i)) +
                                 ((b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)) *
                                  b_i)] = r1[(m + (r1.size(0) * d_i)) +
                                             ((r1.size(0) * r1.size(1)) * b_i)];
          }
        }
      }
    }
    newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                             b_board->BoardIdx.size(1));
    loop_ub = b_board->BoardIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      g_n = b_board->BoardIdx.size(0);
      for (d_i = 0; d_i < g_n; d_i++) {
        newBoardCoords1[d_i + (newBoardCoords1.size(0) * b_i)] =
            b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
      }
    }
    m = newBoardCoords1.size(1);
    y.set_size(1, newBoardCoords1.size(1));
    for (b_i = 0; b_i < m; b_i++) {
      y[b_i] = false;
    }
    m = newBoardCoords1.size(1);
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      y[loop_ub] = true;
      g_n = 0;
      exitg1 = false;
      while ((!exitg1) && (g_n <= (newBoardCoords1.size(0) - 1))) {
        if (newBoardCoords1[g_n + (newBoardCoords1.size(0) * loop_ub)] == 0.0) {
          y[loop_ub] = false;
          exitg1 = true;
        } else {
          g_n++;
        }
      }
    }
    b_y = (y.size(1) != 0);
    if (b_y) {
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (y.size(1) - 1))) {
        if (!y[loop_ub]) {
          b_y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (b_y) {
      cornerIdx[0] = b_board->BoardCoords[0];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[2] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      cornerIdx[3] = b_board->BoardCoords[1];
      c_board[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1)];
      c_board[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                        (b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1))];
      c_board[2] = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                         (b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1))) +
                                        1];
      c_board[3] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1)) +
                                        1];
      poly2RectMask(cornerIdx, c_board, static_cast<real_T>(g_I.size(0)),
                    static_cast<real_T>(g_I.size(1)), upperLeftMask);
      cornerIdx[0] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) * 2];
      cornerIdx[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) + 1];
      cornerIdx[3] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      c_board[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                        (b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1))];
      c_board[1] = b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) +
                                        (b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1))];
      c_board[2] = b_board->BoardCoords[((b_board->BoardCoords.size(0) * 2) +
                                         (b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1))) +
                                        1];
      c_board[3] = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                         (b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1))) +
                                        1];
      poly2RectMask(cornerIdx, c_board, static_cast<real_T>(g_I.size(0)),
                    static_cast<real_T>(g_I.size(1)), nextSquareMask);
      g_n = (upperLeftMask.size(0) * upperLeftMask.size(1)) - 1;
      m = 0;
      for (d_i = 0; d_i <= g_n; d_i++) {
        if (upperLeftMask[d_i]) {
          m++;
        }
      }
      r2.set_size(m);
      m = 0;
      for (d_i = 0; d_i <= g_n; d_i++) {
        if (upperLeftMask[d_i]) {
          r2[m] = d_i + 1;
          m++;
        }
      }
      g_n = (nextSquareMask.size(0) * nextSquareMask.size(1)) - 1;
      m = 0;
      for (d_i = 0; d_i <= g_n; d_i++) {
        if (nextSquareMask[d_i]) {
          m++;
        }
      }
      r3.set_size(m);
      m = 0;
      for (d_i = 0; d_i <= g_n; d_i++) {
        if (nextSquareMask[d_i]) {
          r3[m] = d_i + 1;
          m++;
        }
      }
      h_I.set_size(r2.size(0));
      loop_ub = r2.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        h_I[b_i] = g_I[r2[b_i] - 1];
      }
      m_I.set_size(r3.size(0));
      loop_ub = r3.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        m_I[b_i] = g_I[r3[b_i] - 1];
      }
      if (!(b_mean(h_I) < b_mean(m_I))) {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          g_n = b_board->BoardIdx.size(0) - 1;
          for (d_i = 0; d_i <= g_n; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
          }
        }
        c_B = &b_board->BoardIdx;
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        b_board->BoardIdx.set_size(newBoardCoords2.size(0),
                                   newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        loop_ub = b_board->BoardCoords.size(0);
        g_n = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, g_n);
        for (b_i = 0; b_i < g_n; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[d_i + (b_board->BoardCoords.size(0) * b_i)];
          }
        }
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        newBoardCoords1.set_size(newBoardCoords2.size(0),
                                 newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        loop_ub = b_board->BoardCoords.size(0);
        g_n = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, g_n);
        for (b_i = 0; b_i < g_n; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[(d_i + (b_board->BoardCoords.size(0) * b_i)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        r.set_size(newBoardCoords2.size(0), newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              r[d_i + (r.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              r[d_i + (r.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (b_i = 0; b_i < 2; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            g_n = r1.size(0);
            for (m = 0; m < g_n; m++) {
              b_board->BoardCoords[(m + (b_board->BoardCoords.size(0) * d_i)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    b_i)] =
                  r1[(m + (r1.size(0) * d_i)) +
                     ((r1.size(0) * r1.size(1)) * b_i)];
            }
          }
        }
      }
    } else {
      cornerIdx[0] = b_board->BoardIdx[0];
      cornerIdx[1] = b_board->BoardIdx[b_board->BoardIdx.size(0) - 1];
      cornerIdx[2] = b_board->BoardIdx[(b_board->BoardIdx.size(0) +
                                        (b_board->BoardIdx.size(0) *
                                         (b_board->BoardIdx.size(1) - 1))) -
                                       1];
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) *
                                       (b_board->BoardIdx.size(1) - 1)];
      m = 0;
      loop_ub = 1;
      g_n = 0;
      exitg1 = false;
      while ((!exitg1) && (g_n < 4)) {
        if (cornerIdx[g_n] != 0.0) {
          m = 1;
          ii_data = static_cast<int8_T>(g_n + 1);
          exitg1 = true;
        } else {
          g_n++;
        }
      }
      if (m == 0) {
        loop_ub = 0;
      }
      numRot_size[0] = 1;
      numRot_size[1] = loop_ub;
      for (b_i = 0; b_i < loop_ub; b_i++) {
        numRot_data = (static_cast<real_T>(ii_data)) - 1.0;
      }
      if (loop_ub == 0) {
        numRot_size[0] = 1;
        numRot_size[1] = 1;
        numRot_data = 0.0;
      }
      y.set_size(1, 1);
      y[0] = (numRot_data == 2.0);
      if (!y[0]) {
        if (c_isequal((real_T *)(&numRot_data), numRot_size, 1.0)) {
          m = 1;
        } else if (c_isequal((real_T *)(&numRot_data), numRot_size, 3.0)) {
          m = 2;
        } else {
          m = 0;
        }
        if (m != 0) {
          newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            g_n = b_board->BoardIdx.size(0);
            for (d_i = 0; d_i < g_n; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * b_i)] =
                  b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
            }
          }
          flip(newBoardCoords1, static_cast<real_T>(m));
          b_board->BoardIdx.set_size(newBoardCoords1.size(0),
                                     newBoardCoords1.size(1));
          loop_ub = newBoardCoords1.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            g_n = newBoardCoords1.size(0);
            for (d_i = 0; d_i < g_n; d_i++) {
              b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)] =
                  newBoardCoords1[d_i + (newBoardCoords1.size(0) * b_i)];
            }
          }
          loop_ub = b_board->BoardCoords.size(0);
          g_n = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(loop_ub, g_n);
          for (b_i = 0; b_i < g_n; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * b_i)] =
                  b_board
                      ->BoardCoords[d_i + (b_board->BoardCoords.size(0) * b_i)];
            }
          }
          flip(newBoardCoords1, static_cast<real_T>(m));
          loop_ub = b_board->BoardCoords.size(0);
          g_n = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, g_n);
          for (b_i = 0; b_i < g_n; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardCoords[(d_i +
                                        (b_board->BoardCoords.size(0) * b_i)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          flip(newBoardCoords2, static_cast<real_T>(m));
          cat(newBoardCoords1, newBoardCoords2, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (b_i = 0; b_i < 2; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              g_n = r1.size(0);
              for (m = 0; m < g_n; m++) {
                b_board
                    ->BoardCoords[(m + (b_board->BoardCoords.size(0) * d_i)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   b_i)] =
                    r1[(m + (r1.size(0) * d_i)) +
                       ((r1.size(0) * r1.size(1)) * b_i)];
              }
            }
          }
        }
      } else {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          g_n = b_board->BoardIdx.size(0) - 1;
          for (d_i = 0; d_i <= g_n; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
          }
        }
        c_B = &b_board->BoardIdx;
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        b_board->BoardIdx.set_size(newBoardCoords2.size(0),
                                   newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        loop_ub = b_board->BoardCoords.size(0);
        g_n = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, g_n);
        for (b_i = 0; b_i < g_n; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[d_i + (b_board->BoardCoords.size(0) * b_i)];
          }
        }
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        newBoardCoords1.set_size(newBoardCoords2.size(0),
                                 newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        loop_ub = b_board->BoardCoords.size(0);
        g_n = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, g_n);
        for (b_i = 0; b_i < g_n; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[(d_i + (b_board->BoardCoords.size(0) * b_i)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        m = newBoardCoords2.size(0) - 1;
        g_n = newBoardCoords2.size(1) - 1;
        r.set_size(newBoardCoords2.size(0), newBoardCoords2.size(1));
        if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              r[d_i + (r.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        } else {
          for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
            for (d_i = 0; d_i <= m; d_i++) {
              r[d_i + (r.size(0) * loop_ub)] =
                  newBoardCoords2[(m - d_i) +
                                  (newBoardCoords2.size(0) * (g_n - loop_ub))];
            }
          }
        }
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (b_i = 0; b_i < 2; b_i++) {
          for (d_i = 0; d_i < loop_ub; d_i++) {
            g_n = r1.size(0);
            for (m = 0; m < g_n; m++) {
              b_board->BoardCoords[(m + (b_board->BoardCoords.size(0) * d_i)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    b_i)] =
                  r1[(m + (r1.size(0) * d_i)) +
                     ((r1.size(0) * r1.size(1)) * b_i)];
            }
          }
        }
      }
    }
    m = b_board->BoardCoords.size(0);
    if (m == 0) {
      g_n = 0;
    } else {
      g_n = static_cast<int32_T>(std::fmod(static_cast<real_T>(m), 2.0));
      if (g_n == 0) {
        g_n = 0;
      }
    }
    m = b_board->BoardCoords.size(1);
    if (m == 0) {
      m = 0;
    } else {
      m = static_cast<int32_T>(std::fmod(static_cast<real_T>(m), 2.0));
      if (m == 0) {
        m = 0;
      }
    }
    if ((g_n == 0) == (m == 0)) {
      loop_ub = b_board->BoardCoords.size(2);
      r4.set_size(1, 1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r4[b_i] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1)) *
                                       b_i];
      }
      m = b_board->BoardCoords.size(0);
      g_n = b_board->BoardCoords.size(1);
      loop_ub = b_board->BoardCoords.size(2);
      r5.set_size(1, 1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r5[b_i] = b_board->BoardCoords[((m + (b_board->BoardCoords.size(0) *
                                              (g_n - 1))) +
                                        ((b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1)) *
                                         b_i)) -
                                       1];
      }
      c_x.set_size(1, 1, r4.size(2));
      loop_ub = r4.size(2);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = (r4[b_i] > r5[b_i]);
      }
      b_y = false;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (c_x.size(2) - 1))) {
        if (c_x[loop_ub]) {
          b_y = true;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (b_y) {
        numRot_data =
            b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                  (b_board->BoardCoords.size(0) *
                                   (b_board->BoardCoords.size(1) - 1))) -
                                 1];
        if (numRot_data != 0.0) {
          newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1) - 1;
          for (b_i = 0; b_i <= loop_ub; b_i++) {
            g_n = b_board->BoardIdx.size(0) - 1;
            for (d_i = 0; d_i <= g_n; d_i++) {
              newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardIdx[d_i + (b_board->BoardIdx.size(0) * b_i)];
            }
          }
          c_B = &b_board->BoardIdx;
          m = newBoardCoords2.size(0) - 1;
          g_n = newBoardCoords2.size(1) - 1;
          b_board->BoardIdx.set_size(newBoardCoords2.size(0),
                                     newBoardCoords2.size(1));
          if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          } else {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                (*c_B)[d_i + (c_B->size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          }
          loop_ub = b_board->BoardCoords.size(0);
          g_n = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, g_n);
          for (b_i = 0; b_i < g_n; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                  b_board
                      ->BoardCoords[d_i + (b_board->BoardCoords.size(0) * b_i)];
            }
          }
          m = newBoardCoords2.size(0) - 1;
          g_n = newBoardCoords2.size(1) - 1;
          newBoardCoords1.set_size(newBoardCoords2.size(0),
                                   newBoardCoords2.size(1));
          if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          } else {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                newBoardCoords1[d_i + (newBoardCoords1.size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          }
          loop_ub = b_board->BoardCoords.size(0);
          g_n = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, g_n);
          for (b_i = 0; b_i < g_n; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              newBoardCoords2[d_i + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardCoords[(d_i +
                                        (b_board->BoardCoords.size(0) * b_i)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          m = newBoardCoords2.size(0) - 1;
          g_n = newBoardCoords2.size(1) - 1;
          r.set_size(newBoardCoords2.size(0), newBoardCoords2.size(1));
          if ((newBoardCoords2.size(0) * newBoardCoords2.size(1)) >= 8192) {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                r[d_i + (r.size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          } else {
            for (loop_ub = 0; loop_ub <= g_n; loop_ub++) {
              for (d_i = 0; d_i <= m; d_i++) {
                r[d_i + (r.size(0) * loop_ub)] =
                    newBoardCoords2[(m - d_i) + (newBoardCoords2.size(0) *
                                                 (g_n - loop_ub))];
              }
            }
          }
          cat(newBoardCoords1, r, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (b_i = 0; b_i < 2; b_i++) {
            for (d_i = 0; d_i < loop_ub; d_i++) {
              g_n = r1.size(0);
              for (m = 0; m < g_n; m++) {
                b_board
                    ->BoardCoords[(m + (b_board->BoardCoords.size(0) * d_i)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   b_i)] =
                    r1[(m + (r1.size(0) * d_i)) +
                       ((r1.size(0) * r1.size(1)) * b_i)];
              }
            }
          }
        }
      }
    }
  }
  return b_board;
}

//
// Arguments    : const b_Checkerboard *b_this
//                ::coder::array<real_T, 2U> &b_points
//                real_T boardSize[2]
// Return Type  : void
//
void toPoints(const b_Checkerboard *b_this,
              ::coder::array<real_T, 2U> &b_points, real_T boardSize[2])
{
  ::coder::array<real_T, 2U> c_x;
  ::coder::array<boolean_T, 1U> b_x;
  int32_T b_i;
  int32_T c_this;
  boolean_T exitg1;
  boolean_T y;
  c_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  b_x.set_size(c_this);
  for (b_i = 0; b_i < c_this; b_i++) {
    b_x[b_i] = (b_this->BoardIdx[b_i] == 0.0);
  }
  y = false;
  c_this = 0;
  exitg1 = false;
  while ((!exitg1) && (c_this <= (b_x.size(0) - 1))) {
    if (b_x[c_this]) {
      y = true;
      exitg1 = true;
    } else {
      c_this++;
    }
  }
  if (y) {
    b_points.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    real_T numPoints;
    int32_T i1;
    int32_T loop_ub;
    numPoints = (static_cast<real_T>(b_this->BoardCoords.size(0))) *
                (static_cast<real_T>(b_this->BoardCoords.size(1)));
    b_points.set_size(static_cast<int32_T>(numPoints), 2);
    c_this = static_cast<int32_T>(numPoints);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < c_this; i1++) {
        b_points[i1 + (b_points.size(0) * b_i)] = 0.0;
      }
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    c_x.set_size(loop_ub, c_this);
    for (b_i = 0; b_i < c_this; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_x[i1 + (c_x.size(0) * b_i)] =
            b_this->BoardCoords[b_i + (b_this->BoardCoords.size(0) * i1)];
      }
    }
    c_this = c_x.size(0) * c_x.size(1);
    for (b_i = 0; b_i < c_this; b_i++) {
      b_points[b_i] = c_x[b_i];
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    c_x.set_size(loop_ub, c_this);
    for (b_i = 0; b_i < c_this; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_x[i1 + (c_x.size(0) * b_i)] =
            b_this->BoardCoords[(b_i + (b_this->BoardCoords.size(0) * i1)) +
                                (b_this->BoardCoords.size(0) *
                                 b_this->BoardCoords.size(1))];
      }
    }
    c_this = c_x.size(0) * c_x.size(1);
    for (b_i = 0; b_i < c_this; b_i++) {
      b_points[b_i + b_points.size(0)] = c_x[b_i];
    }
    boardSize[0] = (static_cast<real_T>(b_this->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<real_T>(b_this->BoardCoords.size(0))) + 1.0;
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for detectCheckerboard.cpp
//
// [EOF]
//
