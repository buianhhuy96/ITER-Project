//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "ITER_API_rtwutil.h"
#include "cat.h"
#include "conv2AXPYValidCMP.h"
#include "find_peaks.h"
#include "flip.h"
#include "imfilter.h"
#include "isequal.h"
#include "mean.h"
#include "rot90.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double i_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float b_u1);

// Function Definitions
//
// Arguments    : double i_X[4]
//                double g_Y[4]
//                double height
//                double width
//                ::coder::array<bool, 2U> &mask
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double i_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask)
{
  int b_loop_ub_tmp;
  int i2;
  int i3;
  int i4;
  int i5;
  int loop_ub;
  int loop_ub_tmp;
  int unnamed_idx_0;
  ::coder::internal::d_sort(i_X);
  ::coder::internal::d_sort(g_Y);
  loop_ub_tmp = static_cast<int>(height);
  b_loop_ub_tmp = static_cast<int>(width);
  mask.set_size(loop_ub_tmp, b_loop_ub_tmp);
  for (int b_i{0}; b_i < b_loop_ub_tmp; b_i++) {
    for (int i1{0}; i1 < loop_ub_tmp; i1++) {
      mask[i1 + (mask.size(0) * b_i)] = false;
    }
  }
  if (g_Y[1] > g_Y[2]) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = (static_cast<int>(g_Y[1])) - 1;
    i3 = static_cast<int>(g_Y[2]);
  }
  if (i_X[1] > i_X[2]) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = (static_cast<int>(i_X[1])) - 1;
    i5 = static_cast<int>(i_X[2]);
  }
  unnamed_idx_0 = i3 - i2;
  loop_ub = i5 - i4;
  for (int i6{0}; i6 < loop_ub; i6++) {
    for (int i7{0}; i7 < unnamed_idx_0; i7++) {
      mask[(i2 + i7) + (mask.size(0) * (i4 + i6))] = true;
    }
  }
}

//
// Arguments    : float u0
//                float b_u1
// Return Type  : float
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float b_u1)
{
  float y;
  if ((std::isnan(u0)) || (std::isnan(b_u1))) {
    y = rtNaNF;
  } else if ((std::isinf(u0)) && (std::isinf(b_u1))) {
    int b_u0;
    int c_u1;
    if (u0 > 0.0F) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (b_u1 > 0.0F) {
      c_u1 = 1;
    } else {
      c_u1 = -1;
    }
    y = std::atan2(static_cast<float>(b_u0), static_cast<float>(c_u1));
  } else if (b_u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, b_u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<float, 2U> &o_I
//                ::coder::array<double, 2U> &b_points
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<float, 2U> &o_I,
                        ::coder::array<double, 2U> &b_points,
                        double boardSize[2])
{
  static const double dv[29]{
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
  static const double dv1[29]{
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
  b_Checkerboard lobj_0[6];
  b_Checkerboard *board0;
  b_Checkerboard *board45;
  array<double, 2U> b;
  array<double, 2U> c_a;
  array<double, 1U> s;
  array<float, 2U> I_45_45;
  array<float, 2U> I_45_x;
  array<float, 2U> I_45_y;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> IxIy;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> b_I_45;
  array<float, 2U> b_a;
  array<float, 2U> b_b;
  array<float, 2U> b_x;
  array<float, 2U> c45;
  array<float, 2U> cxy;
  array<float, 2U> points0;
  array<float, 2U> points45;
  array<float, 2U> r;
  array<float, 2U> r1;
  array<float, 2U> r2;
  array<float, 1U> b_c45;
  array<float, 1U> b_cxy;
  array<int, 1U> r3;
  array<int, 1U> r4;
  double b_board0[2];
  double b_board45[2];
  double finalSize[2];
  double pad[2];
  int b_end;
  int b_partialTrueCount;
  int b_trueCount;
  int bc_loop_ub;
  int dd_loop_ub;
  int end;
  int fb_loop_ub;
  int fc_loop_ub;
  int gd_loop_ub;
  int id_loop_ub;
  int jd_loop_ub;
  int kb_loop_ub;
  int kc_loop_ub;
  int m_N;
  int mc_loop_ub;
  int p_N;
  int partialTrueCount;
  int pc_loop_ub;
  int s_loop_ub;
  int sb_loop_ub;
  int siz_idx_0;
  int tc_loop_ub;
  int trueCount;
  int ub_loop_ub;
  unsigned int unnamed_idx_0;
  int w_loop_ub;
  int y_loop_ub;
  int yb_loop_ub;
  bool guard1{false};
  bool guard2{false};
  finalSize[0] = static_cast<double>(o_I.size(0));
  pad[0] = 14.0;
  finalSize[1] = static_cast<double>(o_I.size(1));
  pad[1] = 14.0;
  if ((o_I.size(0) == 0) || (o_I.size(1) == 0)) {
    int loop_ub;
    Ig.set_size(o_I.size(0), o_I.size(1));
    loop_ub = o_I.size(1);
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      int c_loop_ub;
      c_loop_ub = o_I.size(0);
      for (int i2{0}; i2 < c_loop_ub; i2++) {
        Ig[i2 + (Ig.size(0) * b_i)] = o_I[i2 + (o_I.size(0) * b_i)];
      }
    }
  } else {
    int b_loop_ub;
    int e_loop_ub;
    padImage_outSize(o_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    b_loop_ub = b_a.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      int d_loop_ub;
      d_loop_ub = b_a.size(0);
      for (int i3{0}; i3 < d_loop_ub; i3++) {
        c_a[i3 + (c_a.size(0) * i1)] =
            static_cast<double>(b_a[i3 + (b_a.size(0) * i1)]);
      }
    }
    b_conv2_separable_valid(dv, dv1, c_a, finalSize, b);
    Ig.set_size(b.size(0), b.size(1));
    e_loop_ub = b.size(1);
    for (int i4{0}; i4 < e_loop_ub; i4++) {
      int g_loop_ub;
      g_loop_ub = b.size(0);
      for (int i6{0}; i6 < g_loop_ub; i6++) {
        Ig[i6 + (Ig.size(0) * i4)] =
            static_cast<float>(b[i6 + (b.size(0) * i4)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    int f_loop_ub;
    Iy.set_size(Ig.size(0), Ig.size(1));
    f_loop_ub = Ig.size(1);
    for (int i5{0}; i5 < f_loop_ub; i5++) {
      int i_loop_ub;
      i_loop_ub = Ig.size(0);
      for (int i8{0}; i8 < i_loop_ub; i8++) {
        Iy[i8 + (Iy.size(0) * i5)] = Ig[i8 + (Ig.size(0) * i5)];
      }
    }
  } else {
    int h_loop_ub;
    int k_loop_ub;
    padImage_outSize(Ig, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    h_loop_ub = b_a.size(1);
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      int j_loop_ub;
      j_loop_ub = b_a.size(0);
      for (int i9{0}; i9 < j_loop_ub; i9++) {
        c_a[i9 + (c_a.size(0) * i7)] =
            static_cast<double>(b_a[i9 + (b_a.size(0) * i7)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Iy.set_size(b.size(0), b.size(1));
    k_loop_ub = b.size(1);
    for (int i10{0}; i10 < k_loop_ub; i10++) {
      int m_loop_ub;
      m_loop_ub = b.size(0);
      for (int i11{0}; i11 < m_loop_ub; i11++) {
        Iy[i11 + (Iy.size(0) * i10)] =
            static_cast<float>(b[i11 + (b.size(0) * i10)]);
      }
    }
  }
  imfilter(Ig);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    int o_loop_ub;
    Ixy.set_size(Ig.size(0), Ig.size(1));
    o_loop_ub = Ig.size(1);
    for (int i12{0}; i12 < o_loop_ub; i12++) {
      int q_loop_ub;
      q_loop_ub = Ig.size(0);
      for (int i14{0}; i14 < q_loop_ub; i14++) {
        Ixy[i14 + (Ixy.size(0) * i12)] = Ig[i14 + (Ig.size(0) * i12)];
      }
    }
  } else {
    int p_loop_ub;
    int t_loop_ub;
    padImage_outSize(Ig, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    p_loop_ub = b_a.size(1);
    for (int i13{0}; i13 < p_loop_ub; i13++) {
      int r_loop_ub;
      r_loop_ub = b_a.size(0);
      for (int i15{0}; i15 < r_loop_ub; i15++) {
        c_a[i15 + (c_a.size(0) * i13)] =
            static_cast<double>(b_a[i15 + (b_a.size(0) * i13)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    t_loop_ub = b.size(1);
    for (int i17{0}; i17 < t_loop_ub; i17++) {
      int v_loop_ub;
      v_loop_ub = b.size(0);
      for (int i19{0}; i19 < v_loop_ub; i19++) {
        Ixy[i19 + (Ixy.size(0) * i17)] =
            static_cast<float>(b[i19 + (b.size(0) * i17)]);
      }
    }
  }
  r.set_size(Ig.size(0), Ig.size(1));
  s_loop_ub = Ig.size(1);
  for (int i16{0}; i16 < s_loop_ub; i16++) {
    int u_loop_ub;
    u_loop_ub = Ig.size(0);
    for (int i18{0}; i18 < u_loop_ub; i18++) {
      r[i18 + (r.size(0) * i16)] = Ig[i18 + (Ig.size(0) * i16)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  w_loop_ub = r.size(1);
  for (int i20{0}; i20 < w_loop_ub; i20++) {
    int x_loop_ub;
    x_loop_ub = r.size(0);
    for (int i21{0}; i21 < x_loop_ub; i21++) {
      b_I_45[i21 + (b_I_45.size(0) * i20)] =
          r[i21 + (r.size(0) * i20)] +
          (Iy[i21 + (Iy.size(0) * i20)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  y_loop_ub = b_I_45.size(1);
  for (int i22{0}; i22 < y_loop_ub; i22++) {
    int ab_loop_ub;
    ab_loop_ub = b_I_45.size(0);
    for (int i23{0}; i23 < ab_loop_ub; i23++) {
      I_45_x[i23 + (I_45_x.size(0) * i22)] =
          b_I_45[i23 + (b_I_45.size(0) * i22)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((b_I_45.size(0) == 0) || (b_I_45.size(1) == 0)) {
    int bb_loop_ub;
    I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
    bb_loop_ub = b_I_45.size(1);
    for (int i24{0}; i24 < bb_loop_ub; i24++) {
      int db_loop_ub;
      db_loop_ub = b_I_45.size(0);
      for (int i26{0}; i26 < db_loop_ub; i26++) {
        I_45_y[i26 + (I_45_y.size(0) * i24)] =
            b_I_45[i26 + (b_I_45.size(0) * i24)];
      }
    }
  } else {
    int cb_loop_ub;
    int gb_loop_ub;
    padImage_outSize(b_I_45, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    cb_loop_ub = b_a.size(1);
    for (int i25{0}; i25 < cb_loop_ub; i25++) {
      int eb_loop_ub;
      eb_loop_ub = b_a.size(0);
      for (int i27{0}; i27 < eb_loop_ub; i27++) {
        c_a[i27 + (c_a.size(0) * i25)] =
            static_cast<double>(b_a[i27 + (b_a.size(0) * i25)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    I_45_y.set_size(b.size(0), b.size(1));
    gb_loop_ub = b.size(1);
    for (int i29{0}; i29 < gb_loop_ub; i29++) {
      int ib_loop_ub;
      ib_loop_ub = b.size(0);
      for (int i31{0}; i31 < ib_loop_ub; i31++) {
        I_45_y[i31 + (I_45_y.size(0) * i29)] =
            static_cast<float>(b[i31 + (b.size(0) * i29)]);
      }
    }
  }
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  fb_loop_ub = I_45_x.size(1);
  for (int i28{0}; i28 < fb_loop_ub; i28++) {
    int hb_loop_ub;
    hb_loop_ub = I_45_x.size(0);
    for (int i30{0}; i30 < hb_loop_ub; i30++) {
      I_45_45[i30 + (I_45_45.size(0) * i28)] =
          (I_45_x[i30 + (I_45_x.size(0) * i28)] * 0.707106769F) +
          (I_45_y[i30 + (I_45_y.size(0) * i28)] * -0.707106769F);
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(b_I_45.size(0));
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int i34;
    int jb_loop_ub;
    int pb_loop_ub;
    b_b.set_size(b_I_45.size(0), b_I_45.size(1));
    jb_loop_ub = b_I_45.size(1);
    for (int i32{0}; i32 < jb_loop_ub; i32++) {
      int mb_loop_ub;
      mb_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i35{0}; i35 < mb_loop_ub; i35++) {
        b_b[i35 + (b_b.size(0) * i32)] = r1[i35 + (r1.size(0) * i32)];
      }
    }
    i34 = b_I_45.size(1);
    for (int k{0}; k < i34; k++) {
      int i37;
      i37 = b_b.size(0);
      for (int b_k{0}; b_k < i37; b_k++) {
        b_b[b_k + (b_b.size(0) * k)] =
            std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    pb_loop_ub = b_b.size(1);
    for (int i38{0}; i38 < pb_loop_ub; i38++) {
      int qb_loop_ub;
      qb_loop_ub = b_b.size(0);
      for (int i41{0}; i41 < qb_loop_ub; i41++) {
        r1[i41 + (r1.size(0) * i38)] = b_b[i41 + (b_b.size(0) * i38)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  kb_loop_ub = r.size(1);
  for (int i33{0}; i33 < kb_loop_ub; i33++) {
    int ob_loop_ub;
    ob_loop_ub = r.size(0);
    for (int i36{0}; i36 < ob_loop_ub; i36++) {
      b_x[i36 + (b_x.size(0) * i33)] =
          r[i36 + (r.size(0) * i33)] +
          (Iy[i36 + (Iy.size(0) * i33)] * -0.707106769F);
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int loop_ub_tmp;
    int tb_loop_ub;
    b_b.set_size(b_x.size(0), b_x.size(1));
    loop_ub_tmp = b_x.size(1);
    for (int i39{0}; i39 < loop_ub_tmp; i39++) {
      int rb_loop_ub;
      rb_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i42{0}; i42 < rb_loop_ub; i42++) {
        b_b[i42 + (b_b.size(0) * i39)] = r[i42 + (r.size(0) * i39)];
      }
    }
    for (int d_k{0}; d_k < loop_ub_tmp; d_k++) {
      int i45;
      i45 = b_b.size(0);
      for (int f_k{0}; f_k < i45; f_k++) {
        b_b[f_k + (b_b.size(0) * d_k)] =
            std::abs(b_x[f_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    tb_loop_ub = b_b.size(1);
    for (int i46{0}; i46 < tb_loop_ub; i46++) {
      int wb_loop_ub;
      wb_loop_ub = b_b.size(0);
      for (int i49{0}; i49 < wb_loop_ub; i49++) {
        r[i49 + (r.size(0) * i46)] = b_b[i49 + (b_b.size(0) * i46)];
      }
    }
  }
  b_b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i40;
    i40 = Ixy.size(1);
    for (int c_k{0}; c_k < i40; c_k++) {
      int i44;
      i44 = b_b.size(0);
      for (int e_k{0}; e_k < i44; e_k++) {
        b_b[e_k + (b_b.size(0) * c_k)] =
            std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b_b.size(0), b_b.size(1));
  sb_loop_ub = b_b.size(1);
  for (int i43{0}; i43 < sb_loop_ub; i43++) {
    int vb_loop_ub;
    vb_loop_ub = b_b.size(0);
    for (int i48{0}; i48 < vb_loop_ub; i48++) {
      r2[i48 + (r2.size(0) * i43)] = 16.0F * b_b[i48 + (b_b.size(0) * i43)];
    }
  }
  ub_loop_ub = r1.size(1);
  for (int i47{0}; i47 < ub_loop_ub; i47++) {
    int xb_loop_ub;
    xb_loop_ub = r1.size(0);
    for (int i50{0}; i50 < xb_loop_ub; i50++) {
      r1[i50 + (r1.size(0) * i47)] =
          6.0F * (r1[i50 + (r1.size(0) * i47)] + r[i50 + (r.size(0) * i47)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  yb_loop_ub = r2.size(1);
  for (int i51{0}; i51 < yb_loop_ub; i51++) {
    int ac_loop_ub;
    ac_loop_ub = r2.size(0);
    for (int i52{0}; i52 < ac_loop_ub; i52++) {
      cxy[i52 + (cxy.size(0) * i51)] =
          r2[i52 + (r2.size(0) * i51)] - r1[i52 + (r1.size(0) * i51)];
    }
  }
  end = (r2.size(0) * r2.size(1)) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if ((r2[c_i] - r1[c_i]) < 0.0F) {
      trueCount++;
    }
  }
  r3.set_size(trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if ((r2[d_i] - r1[d_i]) < 0.0F) {
      r3[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  bc_loop_ub = r3.size(0);
  for (int i53{0}; i53 < bc_loop_ub; i53++) {
    cxy[r3[i53] - 1] = 0.0F;
  }
  unnamed_idx_0 = static_cast<unsigned int>(Ig.size(0));
  r.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    int b_loop_ub_tmp;
    int dc_loop_ub;
    b_b.set_size(Ig.size(0), Ig.size(1));
    b_loop_ub_tmp = Ig.size(1);
    for (int i54{0}; i54 < b_loop_ub_tmp; i54++) {
      int cc_loop_ub;
      cc_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i55{0}; i55 < cc_loop_ub; i55++) {
        b_b[i55 + (b_b.size(0) * i54)] = r[i55 + (r.size(0) * i54)];
      }
    }
    for (int g_k{0}; g_k < b_loop_ub_tmp; g_k++) {
      int i57;
      i57 = b_b.size(0);
      for (int i_k{0}; i_k < i57; i_k++) {
        b_b[i_k + (b_b.size(0) * g_k)] = std::abs(Ig[i_k + (Ig.size(0) * g_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    dc_loop_ub = b_b.size(1);
    for (int i59{0}; i59 < dc_loop_ub; i59++) {
      int gc_loop_ub;
      gc_loop_ub = b_b.size(0);
      for (int i64{0}; i64 < gc_loop_ub; i64++) {
        r[i64 + (r.size(0) * i59)] = b_b[i64 + (b_b.size(0) * i59)];
      }
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(Iy.size(0));
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    int c_loop_ub_tmp;
    int hc_loop_ub;
    b_b.set_size(Iy.size(0), Iy.size(1));
    c_loop_ub_tmp = Iy.size(1);
    for (int i56{0}; i56 < c_loop_ub_tmp; i56++) {
      int ec_loop_ub;
      ec_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i60{0}; i60 < ec_loop_ub; i60++) {
        b_b[i60 + (b_b.size(0) * i56)] = r1[i60 + (r1.size(0) * i56)];
      }
    }
    for (int k_k{0}; k_k < c_loop_ub_tmp; k_k++) {
      int i63;
      i63 = b_b.size(0);
      for (int o_k{0}; o_k < i63; o_k++) {
        b_b[o_k + (b_b.size(0) * k_k)] = std::abs(Iy[o_k + (Iy.size(0) * k_k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    hc_loop_ub = b_b.size(1);
    for (int i65{0}; i65 < hc_loop_ub; i65++) {
      int jc_loop_ub;
      jc_loop_ub = b_b.size(0);
      for (int i67{0}; i67 < jc_loop_ub; i67++) {
        r1[i67 + (r1.size(0) * i65)] = b_b[i67 + (b_b.size(0) * i65)];
      }
    }
  }
  b_b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i58;
    i58 = I_45_45.size(1);
    for (int j_k{0}; j_k < i58; j_k++) {
      int i62;
      i62 = b_b.size(0);
      for (int m_k{0}; m_k < i62; m_k++) {
        b_b[m_k + (b_b.size(0) * j_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * j_k)]);
      }
    }
  }
  c45.set_size(b_b.size(0), b_b.size(1));
  fc_loop_ub = b_b.size(1);
  for (int i61{0}; i61 < fc_loop_ub; i61++) {
    int ic_loop_ub;
    ic_loop_ub = b_b.size(0);
    for (int i66{0}; i66 < ic_loop_ub; i66++) {
      c45[i66 + (c45.size(0) * i61)] =
          (16.0F * b_b[i66 + (b_b.size(0) * i61)]) -
          (6.0F * (r[i66 + (r.size(0) * i61)] + r1[i66 + (r1.size(0) * i61)]));
    }
  }
  b_end = (c45.size(0) * c45.size(1)) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if (c45[e_i] < 0.0F) {
      b_trueCount++;
    }
  }
  r4.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (c45[g_i] < 0.0F) {
      r4[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  kc_loop_ub = r4.size(0);
  for (int i68{0}; i68 < kc_loop_ub; i68++) {
    c45[r4[i68] - 1] = 0.0F;
  }
  unnamed_idx_0 = static_cast<unsigned int>(Ig.size(0));
  Ix2.set_size(Ig.size(0), Ig.size(1));
  b_b.set_size(Ig.size(0), Ig.size(1));
  mc_loop_ub = Ig.size(1);
  for (int i69{0}; i69 < mc_loop_ub; i69++) {
    int oc_loop_ub;
    oc_loop_ub = static_cast<int>(unnamed_idx_0);
    for (int i70{0}; i70 < oc_loop_ub; i70++) {
      b_b[i70 + (b_b.size(0) * i69)] = Ix2[i70 + (Ix2.size(0) * i69)];
    }
  }
  m_N = Ig.size(1);
  for (int p_k{0}; p_k < m_N; p_k++) {
    int o_N;
    o_N = b_b.size(0);
    for (int q_k{0}; q_k < o_N; q_k++) {
      b_b[q_k + (b_b.size(0) * p_k)] =
          rt_powf_snf(Ig[q_k + (Ig.size(0) * p_k)], 2.0F);
    }
  }
  Ix2.set_size(b_b.size(0), b_b.size(1));
  pc_loop_ub = b_b.size(1);
  for (int i71{0}; i71 < pc_loop_ub; i71++) {
    int qc_loop_ub;
    qc_loop_ub = b_b.size(0);
    for (int i72{0}; i72 < qc_loop_ub; i72++) {
      Ix2[i72 + (Ix2.size(0) * i71)] = b_b[i72 + (b_b.size(0) * i71)];
    }
  }
  Iy2.set_size(Iy.size(0), Iy.size(1));
  p_N = Iy.size(1);
  for (int r_k{0}; r_k < p_N; r_k++) {
    int q_N;
    q_N = Iy2.size(0);
    for (int s_k{0}; s_k < q_N; s_k++) {
      Iy2[s_k + (Iy2.size(0) * r_k)] =
          rt_powf_snf(Iy[s_k + (Iy.size(0) * r_k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((b_b.size(0) != 0) && (b_b.size(1) != 0)) {
    int rc_loop_ub;
    int vc_loop_ub;
    padImage_outSize(b_b, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    rc_loop_ub = b_a.size(1);
    for (int i73{0}; i73 < rc_loop_ub; i73++) {
      int sc_loop_ub;
      sc_loop_ub = b_a.size(0);
      for (int i74{0}; i74 < sc_loop_ub; i74++) {
        c_a[i74 + (c_a.size(0) * i73)] =
            static_cast<double>(b_a[i74 + (b_a.size(0) * i73)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    vc_loop_ub = b.size(1);
    for (int i77{0}; i77 < vc_loop_ub; i77++) {
      int yc_loop_ub;
      yc_loop_ub = b.size(0);
      for (int i80{0}; i80 < yc_loop_ub; i80++) {
        Ix2[i80 + (Ix2.size(0) * i77)] =
            static_cast<float>(b[i80 + (b.size(0) * i77)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    int ad_loop_ub;
    int uc_loop_ub;
    padImage_outSize(Iy2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    uc_loop_ub = b_a.size(1);
    for (int i76{0}; i76 < uc_loop_ub; i76++) {
      int xc_loop_ub;
      xc_loop_ub = b_a.size(0);
      for (int i79{0}; i79 < xc_loop_ub; i79++) {
        c_a[i79 + (c_a.size(0) * i76)] =
            static_cast<double>(b_a[i79 + (b_a.size(0) * i76)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    ad_loop_ub = b.size(1);
    for (int i81{0}; i81 < ad_loop_ub; i81++) {
      int cd_loop_ub;
      cd_loop_ub = b.size(0);
      for (int i83{0}; i83 < cd_loop_ub; i83++) {
        Iy2[i83 + (Iy2.size(0) * i81)] =
            static_cast<float>(b[i83 + (b.size(0) * i81)]);
      }
    }
  }
  IxIy.set_size(Ig.size(0), Ig.size(1));
  tc_loop_ub = Ig.size(1);
  for (int i75{0}; i75 < tc_loop_ub; i75++) {
    int wc_loop_ub;
    wc_loop_ub = Ig.size(0);
    for (int i78{0}; i78 < wc_loop_ub; i78++) {
      IxIy[i78 + (IxIy.size(0) * i75)] =
          Ig[i78 + (Ig.size(0) * i75)] * Iy[i78 + (Iy.size(0) * i75)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
    int bd_loop_ub;
    int fd_loop_ub;
    padImage_outSize(IxIy, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    bd_loop_ub = b_a.size(1);
    for (int i82{0}; i82 < bd_loop_ub; i82++) {
      int ed_loop_ub;
      ed_loop_ub = b_a.size(0);
      for (int i85{0}; i85 < ed_loop_ub; i85++) {
        c_a[i85 + (c_a.size(0) * i82)] =
            static_cast<double>(b_a[i85 + (b_a.size(0) * i82)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    IxIy.set_size(b.size(0), b.size(1));
    fd_loop_ub = b.size(1);
    for (int i86{0}; i86 < fd_loop_ub; i86++) {
      int hd_loop_ub;
      hd_loop_ub = b.size(0);
      for (int i88{0}; i88 < hd_loop_ub; i88++) {
        IxIy[i88 + (IxIy.size(0) * i86)] =
            static_cast<float>(b[i88 + (b.size(0) * i86)]);
      }
    }
  }
  find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  dd_loop_ub = points0.size(0);
  r3.set_size(points0.size(0));
  for (int i84{0}; i84 < dd_loop_ub; i84++) {
    r3[i84] = (static_cast<int>(points0[i84 + points0.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points0[i84])) - 1));
  }
  b_cxy.set_size(r3.size(0));
  gd_loop_ub = r3.size(0);
  for (int i87{0}; i87 < gd_loop_ub; i87++) {
    b_cxy[i87] = cxy[r3[i87] - 1];
  }
  board0 = growCheckerboard(points0, b_cxy, Ix2, Iy2, IxIy, 0.0, &lobj_0[0]);
  b_points.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  find_peaks(c45, points45);
  siz_idx_0 = c45.size(0);
  id_loop_ub = points45.size(0);
  r3.set_size(points45.size(0));
  for (int i89{0}; i89 < id_loop_ub; i89++) {
    r3[i89] = (static_cast<int>(points45[i89 + points45.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points45[i89])) - 1));
  }
  b_c45.set_size(r3.size(0));
  jd_loop_ub = r3.size(0);
  for (int i90{0}; i90 < jd_loop_ub; i90++) {
    b_c45[i90] = c45[r3[i90] - 1];
  }
  board45 = growCheckerboard(points45, b_c45, Ix2, Iy2, IxIy,
                             0.78539816339744828, &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      b_board0[0] = static_cast<double>(board0->BoardIdx.size(0));
      b_board0[1] = static_cast<double>(board0->BoardIdx.size(1));
      b_board45[0] = static_cast<double>(board45->BoardIdx.size(0));
      b_board45[1] = static_cast<double>(board45->BoardIdx.size(1));
      if (isequal(b_board0, b_board45)) {
        int c_board0;
        int c_board45;
        int h_n;
        int i92;
        int i94;
        int i_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int i91{0}; i91 < c_board0; i91++) {
          s[i91] = board0->BoardIdx[i91];
        }
        h_n = 0;
        i92 = s.size(0);
        for (int t_k{0}; t_k < i92; t_k++) {
          if (s[t_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i93{0}; i93 < c_board45; i93++) {
          s[i93] = board45->BoardIdx[i93];
        }
        i_n = 0;
        i94 = s.size(0);
        for (int u_k{0}; u_k < i94; u_k++) {
          if (s[u_k] != 0.0) {
            i_n++;
          }
        }
        if (h_n > i_n) {
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
    board0 = orient(board0, o_I);
    toPoints(board0, b_points, boardSize);
    subPixelLocation(Ixy, b_points);
  }
  if (guard1 && (board45->isValid)) {
    board45 = orient(board45, o_I);
    toPoints(board45, b_points, boardSize);
    subPixelLocation(I_45_45, b_points);
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &b_points
//                const ::coder::array<float, 1U> &scores
//                const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                double theta
//                b_Checkerboard *b_iobj_0
// Return Type  : b_Checkerboard *
//
b_Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                 const ::coder::array<float, 1U> &scores,
                                 const ::coder::array<float, 2U> &Ix2,
                                 const ::coder::array<float, 2U> &Iy2,
                                 const ::coder::array<float, 2U> &Ixy,
                                 double theta, b_Checkerboard *b_iobj_0)
{
  static const float b_fv[2][2]{{0.707106769F, 0.707106769F},
                                {-0.707106769F, 0.707106769F}};
  b_Checkerboard *board;
  b_Checkerboard *currentBoard;
  b_Checkerboard *previousBoard;
  b_Checkerboard *tmpBoard;
  array<double, 2U> b_seedIdx;
  array<double, 2U> seedIdx;
  array<float, 1U> b_x;
  array<int, 1U> iidx;
  float b_v1[2];
  float v2[2];
  if (scores.size(0) == 0) {
    b_iobj_0[0].isValid = false;
    b_iobj_0[0].Energy = rtInfF;
    b_iobj_0[0].IsDistortionHigh = false;
    board = &b_iobj_0[0];
    b_iobj_0[0].BoardIdx.set_size(1, 1);
    b_iobj_0[0].BoardIdx[0] = 0.0;
    b_iobj_0[0].BoardIdx.set_size(3, 3);
    for (int i2{0}; i2 < 3; i2++) {
      b_iobj_0[0].BoardIdx[b_iobj_0[0].BoardIdx.size(0) * i2] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * i2) + 1] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * i2) + 2] = 0.0;
    }
    b_iobj_0[0].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[0].BoardCoords[0] = 0.0;
    b_iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i6{0}; i6 < 3; i6++) {
        b_iobj_0[0].BoardCoords[(b_iobj_0[0].BoardCoords.size(0) * i6) +
                                ((b_iobj_0[0].BoardCoords.size(0) *
                                  b_iobj_0[0].BoardCoords.size(1)) *
                                 i4)] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i6) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  i4)) +
                                1] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i6) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  i4)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[0].Points.set_size(1, 1);
    b_iobj_0[0].Points[0] = 0.0F;
    b_iobj_0[0].Points.set_size(0, 2);
  } else {
    int b_loop_ub;
    int c_loop_ub;
    int d_loop_ub;
    int i16;
    if (b_points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      int loop_ub;
      seedIdx.set_size(1, b_points.size(0));
      loop_ub = b_points.size(0) - 1;
      for (int b_i{0}; b_i <= loop_ub; b_i++) {
        seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
      }
    }
    b_x.set_size(seedIdx.size(1));
    b_loop_ub = seedIdx.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_x[i1] = scores[(static_cast<int>(seedIdx[i1])) - 1];
    }
    ::coder::internal::sort(b_x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    c_loop_ub = iidx.size(0);
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      b_seedIdx[i3] =
          static_cast<double>(static_cast<unsigned int>(seedIdx[iidx[i3] - 1]));
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    d_loop_ub = b_seedIdx.size(1);
    for (int i5{0}; i5 < d_loop_ub; i5++) {
      seedIdx[i5] = b_seedIdx[i5];
    }
    if (iidx.size(0) > 2000) {
      int e_loop_ub;
      int f_loop_ub;
      int i7;
      i7 = static_cast<int>(std::fmin(
          2000.0, std::round((static_cast<double>(seedIdx.size(1))) / 2.0)));
      if (1 > i7) {
        e_loop_ub = 0;
      } else {
        e_loop_ub = i7;
      }
      b_seedIdx.set_size(1, e_loop_ub);
      for (int i8{0}; i8 < e_loop_ub; i8++) {
        b_seedIdx[i8] =
            static_cast<double>(static_cast<unsigned int>(seedIdx[i8]));
      }
      seedIdx.set_size(1, b_seedIdx.size(1));
      f_loop_ub = b_seedIdx.size(1);
      for (int i10{0}; i10 < f_loop_ub; i10++) {
        seedIdx[i10] = b_seedIdx[i10];
      }
    }
    b_iobj_0[1].isValid = false;
    b_iobj_0[1].Energy = rtInfF;
    b_iobj_0[1].IsDistortionHigh = false;
    previousBoard = &b_iobj_0[1];
    b_iobj_0[1].BoardIdx.set_size(1, 1);
    b_iobj_0[1].BoardIdx[0] = 0.0;
    b_iobj_0[1].BoardIdx.set_size(3, 3);
    for (int i9{0}; i9 < 3; i9++) {
      b_iobj_0[1].BoardIdx[b_iobj_0[1].BoardIdx.size(0) * i9] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * i9) + 1] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * i9) + 2] = 0.0;
    }
    b_iobj_0[1].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[1].BoardCoords[0] = 0.0;
    b_iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (int i11{0}; i11 < 2; i11++) {
      for (int i12{0}; i12 < 3; i12++) {
        b_iobj_0[1].BoardCoords[(b_iobj_0[1].BoardCoords.size(0) * i12) +
                                ((b_iobj_0[1].BoardCoords.size(0) *
                                  b_iobj_0[1].BoardCoords.size(1)) *
                                 i11)] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  i11)) +
                                1] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  i11)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[1].Points.set_size(1, 1);
    b_iobj_0[1].Points[0] = 0.0F;
    b_iobj_0[1].Points.set_size(0, 2);
    b_iobj_0[1].IsDistortionHigh = false;
    b_iobj_0[2].isValid = false;
    b_iobj_0[2].Energy = rtInfF;
    b_iobj_0[2].IsDistortionHigh = false;
    currentBoard = &b_iobj_0[2];
    b_iobj_0[2].BoardIdx.set_size(1, 1);
    b_iobj_0[2].BoardIdx[0] = 0.0;
    b_iobj_0[2].BoardIdx.set_size(3, 3);
    for (int i13{0}; i13 < 3; i13++) {
      b_iobj_0[2].BoardIdx[b_iobj_0[2].BoardIdx.size(0) * i13] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * i13) + 1] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * i13) + 2] = 0.0;
    }
    b_iobj_0[2].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[2].BoardCoords[0] = 0.0;
    b_iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (int i14{0}; i14 < 2; i14++) {
      for (int i15{0}; i15 < 3; i15++) {
        b_iobj_0[2].BoardCoords[(b_iobj_0[2].BoardCoords.size(0) * i15) +
                                ((b_iobj_0[2].BoardCoords.size(0) *
                                  b_iobj_0[2].BoardCoords.size(1)) *
                                 i14)] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                1] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[2].Points.set_size(1, 1);
    b_iobj_0[2].Points[0] = 0.0F;
    b_iobj_0[2].Points.set_size(0, 2);
    b_iobj_0[2].IsDistortionHigh = false;
    i16 = seedIdx.size(1);
    for (int c_i{0}; c_i < i16; c_i++) {
      double d;
      float ab;
      float adf;
      float b;
      float b_a;
      float b_cs;
      float c;
      float cs1;
      float df;
      float rt;
      float sn1;
      float tb;
      float tn;
      float x_idx_0;
      float x_idx_1;
      int c_a;
      int sgn2;
      bool guard1{false};
      d = seedIdx[c_i];
      x_idx_0 = std::round(
          b_points[(static_cast<int>(static_cast<unsigned int>(d))) - 1]);
      x_idx_1 = std::round(
          b_points[((static_cast<int>(static_cast<unsigned int>(d))) +
                    b_points.size(0)) -
                   1]);
      b_a = Ix2[((static_cast<int>(x_idx_1)) +
                 (Ix2.size(0) * ((static_cast<int>(x_idx_0)) - 1))) -
                1];
      b = Ixy[((static_cast<int>(x_idx_1)) +
               (Ixy.size(0) * ((static_cast<int>(x_idx_0)) - 1))) -
              1];
      c = Iy2[((static_cast<int>(x_idx_1)) +
               (Iy2.size(0) * ((static_cast<int>(x_idx_0)) - 1))) -
              1];
      df = b_a - c;
      adf = std::abs(df);
      tb = b + b;
      ab = std::abs(tb);
      if (adf > ab) {
        rt = adf * std::sqrt(rt_powf_snf(ab / adf, 2.0F) + 1.0F);
      } else if (adf < ab) {
        rt = ab * std::sqrt(rt_powf_snf(adf / ab, 2.0F) + 1.0F);
      } else {
        rt = ab * 1.41421354F;
      }
      if (df > 0.0F) {
        b_cs = df + rt;
        sgn2 = 1;
      } else {
        b_cs = df - rt;
        sgn2 = -1;
      }
      if (std::abs(b_cs) > ab) {
        float b_ct;
        b_ct = (-tb) / b_cs;
        sn1 = 1.0F / std::sqrt((b_ct * b_ct) + 1.0F);
        cs1 = b_ct * sn1;
      } else if (ab == 0.0F) {
        cs1 = 1.0F;
        sn1 = 0.0F;
      } else {
        tn = (-b_cs) / tb;
        cs1 = 1.0F / std::sqrt((tn * tn) + 1.0F);
        sn1 = tn * cs1;
      }
      if ((b_a + c) < 0.0F) {
        c_a = -1;
      } else {
        c_a = 1;
      }
      if (c_a == sgn2) {
        tn = cs1;
        cs1 = -sn1;
        sn1 = tn;
      }
      for (int i17{0}; i17 < 2; i17++) {
        float f;
        float f1;
        f = b_fv[i17][0];
        f1 = b_fv[i17][1];
        v2[i17] = (cs1 * f) + (sn1 * f1);
        b_v1[i17] = ((-sn1) * f) + (cs1 * f1);
      }
      guard1 = false;
      if ((static_cast<double>(
              std::abs(std::abs(std::abs(rt_atan2f_snf(b_v1[1], b_v1[0])) -
                                3.14159274F) -
                       (static_cast<float>(theta))))) > 0.58904862254808621) {
        if (!((static_cast<double>(std::abs(
                  std::abs(std::abs(rt_atan2f_snf(v2[1], v2[0])) -
                           3.14159274F) -
                  (static_cast<float>(theta))))) > 0.58904862254808621)) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        currentBoard->initialize(
            static_cast<double>(static_cast<unsigned int>(d)), b_points, b_v1,
            v2);
        if (currentBoard->isValid) {
          bool hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            int d_i;
            currentBoard->PreviousEnergy = currentBoard->Energy;
            d_i = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (d_i < 4) {
                if (!currentBoard->IsDirectionBad[d_i]) {
                  currentBoard->LastExpandDirection =
                      (static_cast<double>(d_i)) + 1.0;
                  currentBoard->expandBoardDirectionally(
                      (static_cast<double>(d_i)) + 1.0);
                  if (currentBoard->Energy < currentBoard->PreviousEnergy) {
                    exitg1 = 1;
                  } else {
                    currentBoard->Energy = currentBoard->PreviousEnergy;
                    switch (
                        static_cast<int>(currentBoard->LastExpandDirection)) {
                    case 1: {
                      int d_currentBoard;
                      int i18;
                      int i22;
                      int i24;
                      int i33;
                      int i37;
                      int i39;
                      int i_currentBoard;
                      int k_currentBoard;
                      int q_loop_ub;
                      i18 = currentBoard->BoardIdx.size(0);
                      if (2 > i18) {
                        i22 = -1;
                        i24 = -1;
                      } else {
                        i22 = 0;
                        i24 = i18 - 1;
                      }
                      d_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (int i27{0}; i27 <= d_currentBoard; i27++) {
                        int b_loop_ub_tmp;
                        b_loop_ub_tmp = i24 - i22;
                        for (int i34{0}; i34 < b_loop_ub_tmp; i34++) {
                          currentBoard->BoardIdx[i34 + (b_loop_ub_tmp * i27)] =
                              currentBoard
                                  ->BoardIdx[((i22 + i34) +
                                              (currentBoard->BoardIdx.size(0) *
                                               i27)) +
                                             1];
                        }
                      }
                      currentBoard->BoardIdx.set_size(i24 - i22,
                                                      d_currentBoard + 1);
                      i33 = currentBoard->BoardCoords.size(0);
                      if (2 > i33) {
                        i37 = -1;
                        i39 = -1;
                      } else {
                        i37 = 0;
                        i39 = i33 - 1;
                      }
                      i_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      k_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      q_loop_ub = i_currentBoard + 1;
                      for (int i44{0}; i44 <= k_currentBoard; i44++) {
                        for (int i47{0}; i47 < q_loop_ub; i47++) {
                          int c_loop_ub_tmp;
                          c_loop_ub_tmp = i39 - i37;
                          for (int i51{0}; i51 < c_loop_ub_tmp; i51++) {
                            currentBoard
                                ->BoardCoords[(i51 + (c_loop_ub_tmp * i47)) +
                                              ((c_loop_ub_tmp *
                                                (i_currentBoard + 1)) *
                                               i44)] =
                                currentBoard->BoardCoords
                                    [(((i37 + i51) +
                                       (currentBoard->BoardCoords.size(0) *
                                        i47)) +
                                      ((currentBoard->BoardCoords.size(0) *
                                        currentBoard->BoardCoords.size(1)) *
                                       i44)) +
                                     1];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          i39 - i37, i_currentBoard + 1, k_currentBoard + 1);
                    } break;
                    case 2: {
                      int b_currentBoard;
                      int f_currentBoard;
                      int g_currentBoard;
                      int g_loop_ub;
                      int i19;
                      int i30;
                      int k_loop_ub;
                      int o_loop_ub;
                      i19 = currentBoard->BoardIdx.size(0) - 2;
                      if (1 > (i19 + 1)) {
                        g_loop_ub = 0;
                      } else {
                        g_loop_ub = i19 + 1;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (int i26{0}; i26 <= b_currentBoard; i26++) {
                        for (int i29{0}; i29 < g_loop_ub; i29++) {
                          currentBoard->BoardIdx[i29 + (g_loop_ub * i26)] =
                              currentBoard
                                  ->BoardIdx[i29 +
                                             (currentBoard->BoardIdx.size(0) *
                                              i26)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(g_loop_ub,
                                                      b_currentBoard + 1);
                      i30 = currentBoard->BoardCoords.size(0) - 2;
                      if (1 > (i30 + 1)) {
                        k_loop_ub = 0;
                      } else {
                        k_loop_ub = i30 + 1;
                      }
                      f_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      g_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      o_loop_ub = f_currentBoard + 1;
                      for (int i42{0}; i42 <= g_currentBoard; i42++) {
                        for (int i45{0}; i45 < o_loop_ub; i45++) {
                          for (int i48{0}; i48 < k_loop_ub; i48++) {
                            currentBoard->BoardCoords
                                [(i48 + (k_loop_ub * i45)) +
                                 ((k_loop_ub * (f_currentBoard + 1)) * i42)] =
                                currentBoard->BoardCoords
                                    [(i48 + (currentBoard->BoardCoords.size(0) *
                                             i45)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i42)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          k_loop_ub, f_currentBoard + 1, g_currentBoard + 1);
                    } break;
                    case 3: {
                      int e_currentBoard;
                      int i20;
                      int i23;
                      int i25;
                      int i38;
                      int i40;
                      int i41;
                      int j_loop_ub;
                      int loop_ub_tmp;
                      int m_currentBoard;
                      int o_currentBoard;
                      int r_loop_ub;
                      i20 = currentBoard->BoardIdx.size(1);
                      if (2 > i20) {
                        i23 = 0;
                        i25 = 0;
                      } else {
                        i23 = 1;
                        i25 = i20;
                      }
                      e_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      j_loop_ub = e_currentBoard + 1;
                      loop_ub_tmp = i25 - i23;
                      for (int i31{0}; i31 < loop_ub_tmp; i31++) {
                        for (int i36{0}; i36 < j_loop_ub; i36++) {
                          currentBoard
                              ->BoardIdx[i36 + ((e_currentBoard + 1) * i31)] =
                              currentBoard
                                  ->BoardIdx[i36 +
                                             (currentBoard->BoardIdx.size(0) *
                                              (i23 + i31))];
                        }
                      }
                      currentBoard->BoardIdx.set_size(e_currentBoard + 1,
                                                      loop_ub_tmp);
                      i38 = currentBoard->BoardCoords.size(1);
                      if (2 > i38) {
                        i40 = -1;
                        i41 = -1;
                      } else {
                        i40 = 0;
                        i41 = i38 - 1;
                      }
                      m_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      o_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      r_loop_ub = m_currentBoard + 1;
                      for (int i49{0}; i49 <= o_currentBoard; i49++) {
                        int d_loop_ub_tmp;
                        d_loop_ub_tmp = i41 - i40;
                        for (int i52{0}; i52 < d_loop_ub_tmp; i52++) {
                          for (int i53{0}; i53 < r_loop_ub; i53++) {
                            currentBoard->BoardCoords
                                [(i53 + ((m_currentBoard + 1) * i52)) +
                                 (((m_currentBoard + 1) * d_loop_ub_tmp) *
                                  i49)] =
                                currentBoard->BoardCoords
                                    [(i53 + (currentBoard->BoardCoords.size(0) *
                                             ((i40 + i52) + 1))) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i49)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          m_currentBoard + 1, i41 - i40, o_currentBoard + 1);
                    } break;
                    case 4: {
                      int c_currentBoard;
                      int h_currentBoard;
                      int h_loop_ub;
                      int i21;
                      int i35;
                      int i_loop_ub;
                      int j_currentBoard;
                      int m_loop_ub;
                      int p_loop_ub;
                      i21 = currentBoard->BoardIdx.size(1) - 2;
                      if (1 > (i21 + 1)) {
                        h_loop_ub = -1;
                      } else {
                        h_loop_ub = i21;
                      }
                      c_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      i_loop_ub = c_currentBoard + 1;
                      for (int i28{0}; i28 <= h_loop_ub; i28++) {
                        for (int i32{0}; i32 < i_loop_ub; i32++) {
                          currentBoard
                              ->BoardIdx[i32 + ((c_currentBoard + 1) * i28)] =
                              currentBoard
                                  ->BoardIdx[i32 +
                                             (currentBoard->BoardIdx.size(0) *
                                              i28)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(c_currentBoard + 1,
                                                      h_loop_ub + 1);
                      i35 = currentBoard->BoardCoords.size(1) - 2;
                      if (1 > (i35 + 1)) {
                        m_loop_ub = 0;
                      } else {
                        m_loop_ub = i35 + 1;
                      }
                      h_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      j_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      p_loop_ub = h_currentBoard + 1;
                      for (int i43{0}; i43 <= j_currentBoard; i43++) {
                        for (int i46{0}; i46 < m_loop_ub; i46++) {
                          for (int i50{0}; i50 < p_loop_ub; i50++) {
                            currentBoard->BoardCoords
                                [(i50 + ((h_currentBoard + 1) * i46)) +
                                 (((h_currentBoard + 1) * m_loop_ub) * i43)] =
                                currentBoard->BoardCoords
                                    [(i50 + (currentBoard->BoardCoords.size(0) *
                                             i46)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i43)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          h_currentBoard + 1, m_loop_ub, j_currentBoard + 1);
                    } break;
                    default:
                      /* no actions */
                      break;
                    }
                    currentBoard->IsDirectionBad[d_i] = true;
                    d_i++;
                  }
                } else {
                  d_i++;
                }
              } else {
                hasExpanded = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (currentBoard->Energy < previousBoard->Energy) {
          tmpBoard = previousBoard;
          previousBoard = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
    board = previousBoard;
  }
  return board;
}

//
// Arguments    : b_Checkerboard *board
//                const ::coder::array<float, 2U> &o_I
// Return Type  : b_Checkerboard *
//
b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<float, 2U> &o_I)
{
  b_Checkerboard *b_board;
  array<double, 3U> r1;
  array<double, 3U> r6;
  array<double, 3U> r7;
  array<double, 2U> c_board;
  array<double, 2U> d_board;
  array<double, 2U> d_x;
  array<double, 2U> e_board;
  array<double, 2U> h_board;
  array<double, 2U> i_board;
  array<double, 2U> newBoardCoords1;
  array<double, 2U> newBoardCoords2;
  array<double, 2U> numRot;
  array<double, 2U> r;
  array<double, 2U> r3;
  array<double, 2U> r5;
  array<double, 2U> r8;
  array<double, 2U> r9;
  array<float, 1U> eb_I;
  array<float, 1U> p_I;
  array<int, 1U> r2;
  array<int, 1U> r4;
  array<signed char, 2U> c_ii;
  array<bool, 3U> m_x;
  array<bool, 2U> g_x;
  array<bool, 2U> nextSquareMask;
  array<bool, 2U> upperLeftMask;
  array<bool, 2U> y;
  double cornerIdx[4];
  double nextSquarePolyX[4];
  double nextSquarePolyY[4];
  double upperLeftPolyX[4];
  double upperLeftPolyY[4];
  float b_x;
  b_board = board;
  b_x = b_board->Energy;
  if (!std::isinf(b_x)) {
    int b_hi;
    int b_loop_ub;
    int c_r;
    int d_r;
    int h_x;
    int k_x;
    int szy_idx_1;
    bool b_y;
    bool exitg1;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int h_loop_ub;
      int i_loop_ub;
      int loop_ub;
      c_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(1) - 1;
      for (int b_i{0}; b_i <= loop_ub; b_i++) {
        int c_loop_ub;
        c_loop_ub = b_board->BoardIdx.size(0) - 1;
        for (int i2{0}; i2 <= c_loop_ub; i2++) {
          c_board[i2 + (c_board.size(0) * b_i)] =
              b_board->BoardIdx[i2 + (b_board->BoardIdx.size(0) * b_i)];
        }
      }
      rot90(c_board, b_board->BoardIdx);
      e_loop_ub = b_board->BoardCoords.size(0);
      f_loop_ub = b_board->BoardCoords.size(1);
      d_board.set_size(e_loop_ub, f_loop_ub);
      for (int i5{0}; i5 < f_loop_ub; i5++) {
        for (int i6{0}; i6 < e_loop_ub; i6++) {
          d_board[i6 + (d_board.size(0) * i5)] =
              b_board->BoardCoords[i6 + (b_board->BoardCoords.size(0) * i5)];
        }
      }
      rot90(d_board, newBoardCoords1);
      g_loop_ub = b_board->BoardCoords.size(0);
      h_loop_ub = b_board->BoardCoords.size(1);
      d_board.set_size(g_loop_ub, h_loop_ub);
      for (int i7{0}; i7 < h_loop_ub; i7++) {
        for (int i8{0}; i8 < g_loop_ub; i8++) {
          d_board[i8 + (d_board.size(0) * i7)] =
              b_board->BoardCoords[(i8 + (b_board->BoardCoords.size(0) * i7)) +
                                   (b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1))];
        }
      }
      rot90(d_board, r);
      cat(newBoardCoords1, r, r1);
      b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
      i_loop_ub = r1.size(1);
      for (int i9{0}; i9 < 2; i9++) {
        for (int i10{0}; i10 < i_loop_ub; i10++) {
          int j_loop_ub;
          j_loop_ub = r1.size(0);
          for (int i11{0}; i11 < j_loop_ub; i11++) {
            b_board->BoardCoords[(i11 + (b_board->BoardCoords.size(0) * i10)) +
                                 ((b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)) *
                                  i9)] = r1[(i11 + (r1.size(0) * i10)) +
                                            ((r1.size(0) * r1.size(1)) * i9)];
          }
        }
      }
    }
    d_x.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
    b_loop_ub = b_board->BoardIdx.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      int d_loop_ub;
      d_loop_ub = b_board->BoardIdx.size(0);
      for (int i3{0}; i3 < d_loop_ub; i3++) {
        d_x[i3 + (d_x.size(0) * i1)] =
            b_board->BoardIdx[i3 + (b_board->BoardIdx.size(0) * i1)];
      }
    }
    szy_idx_1 = d_x.size(1);
    y.set_size(1, d_x.size(1));
    for (int i4{0}; i4 < szy_idx_1; i4++) {
      y[i4] = false;
    }
    b_hi = d_x.size(1);
    for (int k{0}; k < b_hi; k++) {
      int b_k;
      y[k] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= (d_x.size(0) - 1))) {
        if (d_x[b_k + (d_x.size(0) * k)] == 0.0) {
          y[k] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    b_y = (y.size(1) != 0);
    if (b_y) {
      int c_k;
      c_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c_k <= (y.size(1) - 1))) {
        if (!y[c_k]) {
          b_y = false;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
    }
    if (b_y) {
      int ab_loop_ub;
      int b_end;
      int b_partialTrueCount;
      int b_trueCount;
      int cb_loop_ub;
      int end;
      int partialTrueCount;
      int trueCount;
      upperLeftPolyX[0] = b_board->BoardCoords[0];
      upperLeftPolyX[1] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      upperLeftPolyX[2] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      upperLeftPolyX[3] = b_board->BoardCoords[1];
      upperLeftPolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                               b_board->BoardCoords.size(1)];
      upperLeftPolyY[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                               (b_board->BoardCoords.size(0) *
                                                b_board->BoardCoords.size(1))];
      upperLeftPolyY[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      upperLeftPolyY[3] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                                b_board->BoardCoords.size(1)) +
                                               1];
      poly2RectMask(upperLeftPolyX, upperLeftPolyY,
                    static_cast<double>(o_I.size(0)),
                    static_cast<double>(o_I.size(1)), upperLeftMask);
      nextSquarePolyX[0] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      nextSquarePolyX[1] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) * 2];
      nextSquarePolyX[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) + 1];
      nextSquarePolyX[3] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      nextSquarePolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                                (b_board->BoardCoords.size(0) *
                                                 b_board->BoardCoords.size(1))];
      nextSquarePolyY[1] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) +
                               (b_board->BoardCoords.size(0) *
                                b_board->BoardCoords.size(1))];
      nextSquarePolyY[2] =
          b_board->BoardCoords[((b_board->BoardCoords.size(0) * 2) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      nextSquarePolyY[3] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      poly2RectMask(nextSquarePolyX, nextSquarePolyY,
                    static_cast<double>(o_I.size(0)),
                    static_cast<double>(o_I.size(1)), nextSquareMask);
      end = (upperLeftMask.size(0) * upperLeftMask.size(1)) - 1;
      trueCount = 0;
      for (int c_i{0}; c_i <= end; c_i++) {
        if (upperLeftMask[c_i]) {
          trueCount++;
        }
      }
      r2.set_size(trueCount);
      partialTrueCount = 0;
      for (int d_i{0}; d_i <= end; d_i++) {
        if (upperLeftMask[d_i]) {
          r2[partialTrueCount] = d_i + 1;
          partialTrueCount++;
        }
      }
      b_end = (nextSquareMask.size(0) * nextSquareMask.size(1)) - 1;
      b_trueCount = 0;
      for (int e_i{0}; e_i <= b_end; e_i++) {
        if (nextSquareMask[e_i]) {
          b_trueCount++;
        }
      }
      r4.set_size(b_trueCount);
      b_partialTrueCount = 0;
      for (int g_i{0}; g_i <= b_end; g_i++) {
        if (nextSquareMask[g_i]) {
          r4[b_partialTrueCount] = g_i + 1;
          b_partialTrueCount++;
        }
      }
      p_I.set_size(r2.size(0));
      ab_loop_ub = r2.size(0);
      for (int i22{0}; i22 < ab_loop_ub; i22++) {
        p_I[i22] = o_I[r2[i22] - 1];
      }
      eb_I.set_size(r4.size(0));
      cb_loop_ub = r4.size(0);
      for (int i27{0}; i27 < cb_loop_ub; i27++) {
        eb_I[i27] = o_I[r4[i27] - 1];
      }
      if (!(b_mean(p_I) < b_mean(eb_I))) {
        int hb_loop_ub;
        int ob_loop_ub;
        int pb_loop_ub;
        int rb_loop_ub;
        int sb_loop_ub;
        int ub_loop_ub;
        h_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
        hb_loop_ub = b_board->BoardIdx.size(1) - 1;
        for (int i33{0}; i33 <= hb_loop_ub; i33++) {
          int jb_loop_ub;
          jb_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (int i35{0}; i35 <= jb_loop_ub; i35++) {
            h_board[i35 + (h_board.size(0) * i33)] =
                b_board->BoardIdx[i35 + (b_board->BoardIdx.size(0) * i33)];
          }
        }
        b_rot90(h_board, b_board->BoardIdx);
        ob_loop_ub = b_board->BoardCoords.size(0);
        pb_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(ob_loop_ub, pb_loop_ub);
        for (int i39{0}; i39 < pb_loop_ub; i39++) {
          for (int i40{0}; i40 < ob_loop_ub; i40++) {
            d_board[i40 + (d_board.size(0) * i39)] =
                b_board
                    ->BoardCoords[i40 + (b_board->BoardCoords.size(0) * i39)];
          }
        }
        b_rot90(d_board, newBoardCoords1);
        rb_loop_ub = b_board->BoardCoords.size(0);
        sb_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(rb_loop_ub, sb_loop_ub);
        for (int i42{0}; i42 < sb_loop_ub; i42++) {
          for (int i43{0}; i43 < rb_loop_ub; i43++) {
            d_board[i43 + (d_board.size(0) * i42)] =
                b_board
                    ->BoardCoords[(i43 + (b_board->BoardCoords.size(0) * i42)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(d_board, r8);
        cat(newBoardCoords1, r8, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        ub_loop_ub = r1.size(1);
        for (int i45{0}; i45 < 2; i45++) {
          for (int i47{0}; i47 < ub_loop_ub; i47++) {
            int yb_loop_ub;
            yb_loop_ub = r1.size(0);
            for (int i49{0}; i49 < yb_loop_ub; i49++) {
              b_board
                  ->BoardCoords[(i49 + (b_board->BoardCoords.size(0) * i47)) +
                                ((b_board->BoardCoords.size(0) *
                                  b_board->BoardCoords.size(1)) *
                                 i45)] = r1[(i49 + (r1.size(0) * i47)) +
                                            ((r1.size(0) * r1.size(1)) * i45)];
            }
          }
        }
      }
    } else {
      int e_ii;
      int idx;
      int k_loop_ub;
      cornerIdx[0] = b_board->BoardIdx[0];
      cornerIdx[1] = b_board->BoardIdx[b_board->BoardIdx.size(0) - 1];
      cornerIdx[2] = b_board->BoardIdx[(b_board->BoardIdx.size(0) +
                                        (b_board->BoardIdx.size(0) *
                                         (b_board->BoardIdx.size(1) - 1))) -
                                       1];
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) *
                                       (b_board->BoardIdx.size(1) - 1)];
      idx = 0;
      c_ii.set_size(1, 1);
      e_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (e_ii < 4)) {
        if (cornerIdx[e_ii] != 0.0) {
          idx = 1;
          c_ii[0] = static_cast<signed char>(e_ii + 1);
          exitg1 = true;
        } else {
          e_ii++;
        }
      }
      if (idx == 0) {
        c_ii.set_size(1, 0);
      }
      numRot.set_size(1, c_ii.size(1));
      k_loop_ub = c_ii.size(1);
      for (int i12{0}; i12 < k_loop_ub; i12++) {
        numRot[0] = (static_cast<double>(c_ii[0])) - 1.0;
      }
      if (c_ii.size(1) == 0) {
        numRot.set_size(1, 1);
        numRot[0] = 0.0;
      }
      g_x.set_size(1, 1);
      g_x[0] = (numRot[0] == 2.0);
      if (!g_x[0]) {
        int direction;
        if (c_isequal(numRot, 1.0)) {
          direction = 1;
        } else if (c_isequal(numRot, 3.0)) {
          direction = 2;
        } else {
          direction = 0;
        }
        if (direction != 0) {
          int eb_loop_ub;
          int fb_loop_ub;
          int mb_loop_ub;
          int q_loop_ub;
          int t_loop_ub;
          int w_loop_ub;
          int y_loop_ub;
          r3.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
          q_loop_ub = b_board->BoardIdx.size(1);
          for (int i15{0}; i15 < q_loop_ub; i15++) {
            int s_loop_ub;
            s_loop_ub = b_board->BoardIdx.size(0);
            for (int i17{0}; i17 < s_loop_ub; i17++) {
              r3[i17 + (r3.size(0) * i15)] =
                  b_board->BoardIdx[i17 + (b_board->BoardIdx.size(0) * i15)];
            }
          }
          flip(r3, static_cast<double>(direction));
          b_board->BoardIdx.set_size(r3.size(0), r3.size(1));
          t_loop_ub = r3.size(1);
          for (int i19{0}; i19 < t_loop_ub; i19++) {
            int x_loop_ub;
            x_loop_ub = r3.size(0);
            for (int i21{0}; i21 < x_loop_ub; i21++) {
              b_board->BoardIdx[i21 + (b_board->BoardIdx.size(0) * i19)] =
                  r3[i21 + (r3.size(0) * i19)];
            }
          }
          w_loop_ub = b_board->BoardCoords.size(0);
          y_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(w_loop_ub, y_loop_ub);
          for (int i24{0}; i24 < y_loop_ub; i24++) {
            for (int i26{0}; i26 < w_loop_ub; i26++) {
              newBoardCoords1[i26 + (newBoardCoords1.size(0) * i24)] =
                  b_board
                      ->BoardCoords[i26 + (b_board->BoardCoords.size(0) * i24)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(direction));
          eb_loop_ub = b_board->BoardCoords.size(0);
          fb_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(eb_loop_ub, fb_loop_ub);
          for (int i30{0}; i30 < fb_loop_ub; i30++) {
            for (int i32{0}; i32 < eb_loop_ub; i32++) {
              newBoardCoords2[i32 + (newBoardCoords2.size(0) * i30)] =
                  b_board->BoardCoords[(i32 +
                                        (b_board->BoardCoords.size(0) * i30)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          flip(newBoardCoords2, static_cast<double>(direction));
          cat(newBoardCoords1, newBoardCoords2, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          mb_loop_ub = r1.size(1);
          for (int i37{0}; i37 < 2; i37++) {
            for (int i38{0}; i38 < mb_loop_ub; i38++) {
              int qb_loop_ub;
              qb_loop_ub = r1.size(0);
              for (int i41{0}; i41 < qb_loop_ub; i41++) {
                b_board
                    ->BoardCoords[(i41 + (b_board->BoardCoords.size(0) * i38)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i37)] =
                    r1[(i41 + (r1.size(0) * i38)) +
                       ((r1.size(0) * r1.size(1)) * i37)];
              }
            }
          }
        }
      } else {
        int db_loop_ub;
        int m_loop_ub;
        int p_loop_ub;
        int r_loop_ub;
        int u_loop_ub;
        int v_loop_ub;
        e_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
        m_loop_ub = b_board->BoardIdx.size(1) - 1;
        for (int i13{0}; i13 <= m_loop_ub; i13++) {
          int o_loop_ub;
          o_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (int i14{0}; i14 <= o_loop_ub; i14++) {
            e_board[i14 + (e_board.size(0) * i13)] =
                b_board->BoardIdx[i14 + (b_board->BoardIdx.size(0) * i13)];
          }
        }
        b_rot90(e_board, b_board->BoardIdx);
        p_loop_ub = b_board->BoardCoords.size(0);
        r_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(p_loop_ub, r_loop_ub);
        for (int i16{0}; i16 < r_loop_ub; i16++) {
          for (int i18{0}; i18 < p_loop_ub; i18++) {
            d_board[i18 + (d_board.size(0) * i16)] =
                b_board
                    ->BoardCoords[i18 + (b_board->BoardCoords.size(0) * i16)];
          }
        }
        b_rot90(d_board, newBoardCoords1);
        u_loop_ub = b_board->BoardCoords.size(0);
        v_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(u_loop_ub, v_loop_ub);
        for (int i20{0}; i20 < v_loop_ub; i20++) {
          for (int i23{0}; i23 < u_loop_ub; i23++) {
            d_board[i23 + (d_board.size(0) * i20)] =
                b_board
                    ->BoardCoords[(i23 + (b_board->BoardCoords.size(0) * i20)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(d_board, r5);
        cat(newBoardCoords1, r5, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        db_loop_ub = r1.size(1);
        for (int i28{0}; i28 < 2; i28++) {
          for (int i29{0}; i29 < db_loop_ub; i29++) {
            int ib_loop_ub;
            ib_loop_ub = r1.size(0);
            for (int i34{0}; i34 < ib_loop_ub; i34++) {
              b_board
                  ->BoardCoords[(i34 + (b_board->BoardCoords.size(0) * i29)) +
                                ((b_board->BoardCoords.size(0) *
                                  b_board->BoardCoords.size(1)) *
                                 i28)] = r1[(i34 + (r1.size(0) * i29)) +
                                            ((r1.size(0) * r1.size(1)) * i28)];
            }
          }
        }
      }
    }
    h_x = b_board->BoardCoords.size(0);
    if (h_x == 0) {
      c_r = 0;
    } else {
      c_r = static_cast<int>(std::fmod(static_cast<double>(h_x), 2.0));
      if (c_r == 0) {
        c_r = 0;
      } else if (h_x < 0) {
        c_r += 2;
      } else {
        /* no actions */
      }
    }
    k_x = b_board->BoardCoords.size(1);
    if (k_x == 0) {
      d_r = 0;
    } else {
      d_r = static_cast<int>(std::fmod(static_cast<double>(k_x), 2.0));
      if (d_r == 0) {
        d_r = 0;
      } else if (k_x < 0) {
        d_r += 2;
      } else {
        /* no actions */
      }
    }
    if ((c_r == 0) == (d_r == 0)) {
      int bb_loop_ub;
      int d_k;
      int f_board;
      int g_board;
      int gb_loop_ub;
      int kb_loop_ub;
      bool c_y;
      bb_loop_ub = b_board->BoardCoords.size(2);
      r6.set_size(1, 1, bb_loop_ub);
      for (int i25{0}; i25 < bb_loop_ub; i25++) {
        r6[i25] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1)) *
                                       i25];
      }
      f_board = b_board->BoardCoords.size(0);
      g_board = b_board->BoardCoords.size(1);
      gb_loop_ub = b_board->BoardCoords.size(2);
      r7.set_size(1, 1, gb_loop_ub);
      for (int i31{0}; i31 < gb_loop_ub; i31++) {
        r7[i31] =
            b_board->BoardCoords[((f_board + (b_board->BoardCoords.size(0) *
                                              (g_board - 1))) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i31)) -
                                 1];
      }
      m_x.set_size(1, 1, r6.size(2));
      kb_loop_ub = r6.size(2);
      for (int i36{0}; i36 < kb_loop_ub; i36++) {
        m_x[i36] = (r6[i36] > r7[i36]);
      }
      c_y = false;
      d_k = 0;
      exitg1 = false;
      while ((!exitg1) && (d_k <= (m_x.size(2) - 1))) {
        if (m_x[d_k]) {
          c_y = true;
          exitg1 = true;
        } else {
          d_k++;
        }
      }
      if (c_y) {
        double o_x;
        o_x = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                    (b_board->BoardCoords.size(0) *
                                     (b_board->BoardCoords.size(1) - 1))) -
                                   1];
        if (o_x != 0.0) {
          int ac_loop_ub;
          int bc_loop_ub;
          int cc_loop_ub;
          int tb_loop_ub;
          int wb_loop_ub;
          int xb_loop_ub;
          i_board.set_size(b_board->BoardIdx.size(0),
                           b_board->BoardIdx.size(1));
          tb_loop_ub = b_board->BoardIdx.size(1) - 1;
          for (int i44{0}; i44 <= tb_loop_ub; i44++) {
            int vb_loop_ub;
            vb_loop_ub = b_board->BoardIdx.size(0) - 1;
            for (int i46{0}; i46 <= vb_loop_ub; i46++) {
              i_board[i46 + (i_board.size(0) * i44)] =
                  b_board->BoardIdx[i46 + (b_board->BoardIdx.size(0) * i44)];
            }
          }
          b_rot90(i_board, b_board->BoardIdx);
          wb_loop_ub = b_board->BoardCoords.size(0);
          xb_loop_ub = b_board->BoardCoords.size(1);
          d_board.set_size(wb_loop_ub, xb_loop_ub);
          for (int i48{0}; i48 < xb_loop_ub; i48++) {
            for (int i50{0}; i50 < wb_loop_ub; i50++) {
              d_board[i50 + (d_board.size(0) * i48)] =
                  b_board
                      ->BoardCoords[i50 + (b_board->BoardCoords.size(0) * i48)];
            }
          }
          b_rot90(d_board, newBoardCoords1);
          ac_loop_ub = b_board->BoardCoords.size(0);
          bc_loop_ub = b_board->BoardCoords.size(1);
          d_board.set_size(ac_loop_ub, bc_loop_ub);
          for (int i51{0}; i51 < bc_loop_ub; i51++) {
            for (int i52{0}; i52 < ac_loop_ub; i52++) {
              d_board[i52 + (d_board.size(0) * i51)] =
                  b_board->BoardCoords[(i52 +
                                        (b_board->BoardCoords.size(0) * i51)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          b_rot90(d_board, r9);
          cat(newBoardCoords1, r9, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          cc_loop_ub = r1.size(1);
          for (int i53{0}; i53 < 2; i53++) {
            for (int i54{0}; i54 < cc_loop_ub; i54++) {
              int dc_loop_ub;
              dc_loop_ub = r1.size(0);
              for (int i55{0}; i55 < dc_loop_ub; i55++) {
                b_board
                    ->BoardCoords[(i55 + (b_board->BoardCoords.size(0) * i54)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i53)] =
                    r1[(i55 + (r1.size(0) * i54)) +
                       ((r1.size(0) * r1.size(1)) * i53)];
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
//                ::coder::array<double, 2U> &b_points
//                double boardSize[2]
// Return Type  : void
//
void toPoints(const b_Checkerboard *b_this,
              ::coder::array<double, 2U> &b_points, double boardSize[2])
{
  array<double, 2U> b_y;
  array<double, 2U> d_x;
  array<bool, 1U> b_x;
  int d_this;
  int k;
  bool exitg1;
  bool y;
  d_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  b_x.set_size(d_this);
  for (int b_i{0}; b_i < d_this; b_i++) {
    b_x[b_i] = (b_this->BoardIdx[b_i] == 0.0);
  }
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
    if (b_x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    b_points.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    double numPoints;
    int b_loop_ub;
    int c_loop_ub;
    int c_y;
    int d_loop_ub;
    int e_loop_ub;
    int g_x;
    int loop_ub;
    numPoints = (static_cast<double>(b_this->BoardCoords.size(0))) *
                (static_cast<double>(b_this->BoardCoords.size(1)));
    b_points.set_size(static_cast<int>(numPoints), 2);
    loop_ub = static_cast<int>(numPoints);
    for (int i1{0}; i1 < 2; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_points[i2 + (b_points.size(0) * i1)] = 0.0;
      }
    }
    b_loop_ub = b_this->BoardCoords.size(0);
    c_loop_ub = b_this->BoardCoords.size(1);
    d_x.set_size(c_loop_ub, b_loop_ub);
    for (int i3{0}; i3 < b_loop_ub; i3++) {
      for (int i4{0}; i4 < c_loop_ub; i4++) {
        d_x[i4 + (d_x.size(0) * i3)] =
            b_this->BoardCoords[i3 + (b_this->BoardCoords.size(0) * i4)];
      }
    }
    g_x = d_x.size(0) * d_x.size(1);
    for (int i5{0}; i5 < g_x; i5++) {
      b_points[i5] = d_x[i5];
    }
    d_loop_ub = b_this->BoardCoords.size(0);
    e_loop_ub = b_this->BoardCoords.size(1);
    b_y.set_size(e_loop_ub, d_loop_ub);
    for (int i6{0}; i6 < d_loop_ub; i6++) {
      for (int i7{0}; i7 < e_loop_ub; i7++) {
        b_y[i7 + (b_y.size(0) * i6)] =
            b_this->BoardCoords[(i6 + (b_this->BoardCoords.size(0) * i7)) +
                                (b_this->BoardCoords.size(0) *
                                 b_this->BoardCoords.size(1))];
      }
    }
    c_y = b_y.size(0) * b_y.size(1);
    for (int i8{0}; i8 < c_y; i8++) {
      b_points[i8 + b_points.size(0)] = b_y[i8];
    }
    boardSize[0] = (static_cast<double>(b_this->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(b_this->BoardCoords.size(0))) + 1.0;
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for detectCheckerboard.cpp
//
// [EOF]
//
