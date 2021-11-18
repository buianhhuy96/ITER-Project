//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "ITER_API_v2_rtwutil.h"
#include "conv2AXPYValidCMP.h"
#include "detectCheckerboard.h"
#include "find_peaks.h"
#include "imfilter.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 2U> &w_I
//                ::coder::array<double, 2U> &b_imagePoints
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &w_I,
                              ::coder::array<double, 2U> &b_imagePoints,
                              double boardSize[2])
{
  static const double dv[15]{
      0.00043640742603817326, 0.0022162597803590169, 0.0087654774692430167,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430167,  0.0022162597803590169, 0.00043640742603818741};
  static const double dv1[15]{
      0.00043640742603817315, 0.0022162597803590169, 0.0087654774692430184,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430184,  0.0022162597803590156, 0.00043640742603817309};
  vision::internal::calibration::checkerboard::b_Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard *board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *board45;
  array<double, 2U> b;
  array<double, 2U> b_a;
  array<double, 1U> s;
  array<float, 2U> I_45_45;
  array<float, 2U> I_45_x;
  array<float, 2U> I_45_y;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> IxIy;
  array<float, 2U> Ixy;
  array<float, 2U> Iy2;
  array<float, 2U> a;
  array<float, 2U> ab_I;
  array<float, 2U> b_I_45;
  array<float, 2U> b_Iy;
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
  int bb_loop_ub;
  int bc_loop_ub;
  int dc_loop_ub;
  int end;
  int fd_loop_ub;
  int hb_loop_ub;
  int hc_loop_ub;
  int id_loop_ub;
  int kd_loop_ub;
  int loop_ub;
  int m_N;
  int md_loop_ub;
  int ob_loop_ub;
  int oc_loop_ub;
  int p_N;
  int partialTrueCount;
  int pc_loop_ub;
  int rc_loop_ub;
  int siz_idx_0;
  int trueCount;
  int u_loop_ub;
  int ub_loop_ub;
  unsigned int unnamed_idx_0;
  int vc_loop_ub;
  int wb_loop_ub;
  int y_loop_ub;
  bool guard1{false};
  bool guard2{false};
  ab_I.set_size(w_I.size(0), w_I.size(1));
  loop_ub = w_I.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    int b_loop_ub;
    b_loop_ub = w_I.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      ab_I[i1 + (ab_I.size(0) * b_i)] =
          (static_cast<float>(w_I[i1 + (w_I.size(0) * b_i)])) / 255.0F;
    }
  }
  finalSize[0] = static_cast<double>(ab_I.size(0));
  pad[0] = 7.0;
  finalSize[1] = static_cast<double>(ab_I.size(1));
  pad[1] = 7.0;
  if ((ab_I.size(0) == 0) || (ab_I.size(1) == 0)) {
    int c_loop_ub;
    Ig.set_size(ab_I.size(0), ab_I.size(1));
    c_loop_ub = ab_I.size(1);
    for (int i2{0}; i2 < c_loop_ub; i2++) {
      int e_loop_ub;
      e_loop_ub = ab_I.size(0);
      for (int i4{0}; i4 < e_loop_ub; i4++) {
        Ig[i4 + (Ig.size(0) * i2)] = ab_I[i4 + (ab_I.size(0) * i2)];
      }
    }
  } else {
    int d_loop_ub;
    int g_loop_ub;
    padImage_outSize(ab_I, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    d_loop_ub = a.size(1);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      int f_loop_ub;
      f_loop_ub = a.size(0);
      for (int i5{0}; i5 < f_loop_ub; i5++) {
        b_a[i5 + (b_a.size(0) * i3)] =
            static_cast<double>(a[i5 + (a.size(0) * i3)]);
      }
    }
    conv2_separable_valid(dv, dv1, b_a, finalSize, b);
    Ig.set_size(b.size(0), b.size(1));
    g_loop_ub = b.size(1);
    for (int i6{0}; i6 < g_loop_ub; i6++) {
      int i_loop_ub;
      i_loop_ub = b.size(0);
      for (int i8{0}; i8 < i_loop_ub; i8++) {
        Ig[i8 + (Ig.size(0) * i6)] =
            static_cast<float>(b[i8 + (b.size(0) * i6)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    int h_loop_ub;
    b_Iy.set_size(Ig.size(0), Ig.size(1));
    h_loop_ub = Ig.size(1);
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      int k_loop_ub;
      k_loop_ub = Ig.size(0);
      for (int i10{0}; i10 < k_loop_ub; i10++) {
        b_Iy[i10 + (b_Iy.size(0) * i7)] = Ig[i10 + (Ig.size(0) * i7)];
      }
    }
  } else {
    int j_loop_ub;
    int o_loop_ub;
    padImage_outSize(Ig, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    j_loop_ub = a.size(1);
    for (int i9{0}; i9 < j_loop_ub; i9++) {
      int m_loop_ub;
      m_loop_ub = a.size(0);
      for (int i11{0}; i11 < m_loop_ub; i11++) {
        b_a[i11 + (b_a.size(0) * i9)] =
            static_cast<double>(a[i11 + (a.size(0) * i9)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    b_Iy.set_size(b.size(0), b.size(1));
    o_loop_ub = b.size(1);
    for (int i12{0}; i12 < o_loop_ub; i12++) {
      int p_loop_ub;
      p_loop_ub = b.size(0);
      for (int i13{0}; i13 < p_loop_ub; i13++) {
        b_Iy[i13 + (b_Iy.size(0) * i12)] =
            static_cast<float>(b[i13 + (b.size(0) * i12)]);
      }
    }
  }
  imfilter(Ig);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    int q_loop_ub;
    Ixy.set_size(Ig.size(0), Ig.size(1));
    q_loop_ub = Ig.size(1);
    for (int i14{0}; i14 < q_loop_ub; i14++) {
      int s_loop_ub;
      s_loop_ub = Ig.size(0);
      for (int i16{0}; i16 < s_loop_ub; i16++) {
        Ixy[i16 + (Ixy.size(0) * i14)] = Ig[i16 + (Ig.size(0) * i14)];
      }
    }
  } else {
    int r_loop_ub;
    int v_loop_ub;
    padImage_outSize(Ig, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    r_loop_ub = a.size(1);
    for (int i15{0}; i15 < r_loop_ub; i15++) {
      int t_loop_ub;
      t_loop_ub = a.size(0);
      for (int i17{0}; i17 < t_loop_ub; i17++) {
        b_a[i17 + (b_a.size(0) * i15)] =
            static_cast<double>(a[i17 + (a.size(0) * i15)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    v_loop_ub = b.size(1);
    for (int i19{0}; i19 < v_loop_ub; i19++) {
      int x_loop_ub;
      x_loop_ub = b.size(0);
      for (int i21{0}; i21 < x_loop_ub; i21++) {
        Ixy[i21 + (Ixy.size(0) * i19)] =
            static_cast<float>(b[i21 + (b.size(0) * i19)]);
      }
    }
  }
  r.set_size(Ig.size(0), Ig.size(1));
  u_loop_ub = Ig.size(1);
  for (int i18{0}; i18 < u_loop_ub; i18++) {
    int w_loop_ub;
    w_loop_ub = Ig.size(0);
    for (int i20{0}; i20 < w_loop_ub; i20++) {
      r[i20 + (r.size(0) * i18)] = Ig[i20 + (Ig.size(0) * i18)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  y_loop_ub = r.size(1);
  for (int i22{0}; i22 < y_loop_ub; i22++) {
    int ab_loop_ub;
    ab_loop_ub = r.size(0);
    for (int i23{0}; i23 < ab_loop_ub; i23++) {
      b_I_45[i23 + (b_I_45.size(0) * i22)] =
          r[i23 + (r.size(0) * i22)] +
          (b_Iy[i23 + (b_Iy.size(0) * i22)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  bb_loop_ub = b_I_45.size(1);
  for (int i24{0}; i24 < bb_loop_ub; i24++) {
    int cb_loop_ub;
    cb_loop_ub = b_I_45.size(0);
    for (int i25{0}; i25 < cb_loop_ub; i25++) {
      I_45_x[i25 + (I_45_x.size(0) * i24)] =
          b_I_45[i25 + (b_I_45.size(0) * i24)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((b_I_45.size(0) == 0) || (b_I_45.size(1) == 0)) {
    int db_loop_ub;
    I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
    db_loop_ub = b_I_45.size(1);
    for (int i26{0}; i26 < db_loop_ub; i26++) {
      int fb_loop_ub;
      fb_loop_ub = b_I_45.size(0);
      for (int i28{0}; i28 < fb_loop_ub; i28++) {
        I_45_y[i28 + (I_45_y.size(0) * i26)] =
            b_I_45[i28 + (b_I_45.size(0) * i26)];
      }
    }
  } else {
    int eb_loop_ub;
    int ib_loop_ub;
    padImage_outSize(b_I_45, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    eb_loop_ub = a.size(1);
    for (int i27{0}; i27 < eb_loop_ub; i27++) {
      int gb_loop_ub;
      gb_loop_ub = a.size(0);
      for (int i29{0}; i29 < gb_loop_ub; i29++) {
        b_a[i29 + (b_a.size(0) * i27)] =
            static_cast<double>(a[i29 + (a.size(0) * i27)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    I_45_y.set_size(b.size(0), b.size(1));
    ib_loop_ub = b.size(1);
    for (int i31{0}; i31 < ib_loop_ub; i31++) {
      int kb_loop_ub;
      kb_loop_ub = b.size(0);
      for (int i33{0}; i33 < kb_loop_ub; i33++) {
        I_45_y[i33 + (I_45_y.size(0) * i31)] =
            static_cast<float>(b[i33 + (b.size(0) * i31)]);
      }
    }
  }
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  hb_loop_ub = I_45_x.size(1);
  for (int i30{0}; i30 < hb_loop_ub; i30++) {
    int jb_loop_ub;
    jb_loop_ub = I_45_x.size(0);
    for (int i32{0}; i32 < jb_loop_ub; i32++) {
      I_45_45[i32 + (I_45_45.size(0) * i30)] =
          (I_45_x[i32 + (I_45_x.size(0) * i30)] * 0.707106769F) +
          (I_45_y[i32 + (I_45_y.size(0) * i30)] * -0.707106769F);
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(b_I_45.size(0));
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int i36;
    int mb_loop_ub;
    int rb_loop_ub;
    b_b.set_size(b_I_45.size(0), b_I_45.size(1));
    mb_loop_ub = b_I_45.size(1);
    for (int i34{0}; i34 < mb_loop_ub; i34++) {
      int pb_loop_ub;
      pb_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i37{0}; i37 < pb_loop_ub; i37++) {
        b_b[i37 + (b_b.size(0) * i34)] = r1[i37 + (r1.size(0) * i34)];
      }
    }
    i36 = b_I_45.size(1);
    for (int k{0}; k < i36; k++) {
      int i39;
      i39 = b_b.size(0);
      for (int b_k{0}; b_k < i39; b_k++) {
        b_b[b_k + (b_b.size(0) * k)] =
            std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    rb_loop_ub = b_b.size(1);
    for (int i40{0}; i40 < rb_loop_ub; i40++) {
      int sb_loop_ub;
      sb_loop_ub = b_b.size(0);
      for (int i43{0}; i43 < sb_loop_ub; i43++) {
        r1[i43 + (r1.size(0) * i40)] = b_b[i43 + (b_b.size(0) * i40)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  ob_loop_ub = r.size(1);
  for (int i35{0}; i35 < ob_loop_ub; i35++) {
    int qb_loop_ub;
    qb_loop_ub = r.size(0);
    for (int i38{0}; i38 < qb_loop_ub; i38++) {
      b_x[i38 + (b_x.size(0) * i35)] =
          r[i38 + (r.size(0) * i35)] +
          (b_Iy[i38 + (b_Iy.size(0) * i35)] * -0.707106769F);
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int loop_ub_tmp;
    int vb_loop_ub;
    b_b.set_size(b_x.size(0), b_x.size(1));
    loop_ub_tmp = b_x.size(1);
    for (int i41{0}; i41 < loop_ub_tmp; i41++) {
      int tb_loop_ub;
      tb_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i44{0}; i44 < tb_loop_ub; i44++) {
        b_b[i44 + (b_b.size(0) * i41)] = r[i44 + (r.size(0) * i41)];
      }
    }
    for (int d_k{0}; d_k < loop_ub_tmp; d_k++) {
      int i47;
      i47 = b_b.size(0);
      for (int f_k{0}; f_k < i47; f_k++) {
        b_b[f_k + (b_b.size(0) * d_k)] =
            std::abs(b_x[f_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    vb_loop_ub = b_b.size(1);
    for (int i48{0}; i48 < vb_loop_ub; i48++) {
      int yb_loop_ub;
      yb_loop_ub = b_b.size(0);
      for (int i51{0}; i51 < yb_loop_ub; i51++) {
        r[i51 + (r.size(0) * i48)] = b_b[i51 + (b_b.size(0) * i48)];
      }
    }
  }
  b_b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i42;
    i42 = Ixy.size(1);
    for (int c_k{0}; c_k < i42; c_k++) {
      int i46;
      i46 = b_b.size(0);
      for (int e_k{0}; e_k < i46; e_k++) {
        b_b[e_k + (b_b.size(0) * c_k)] =
            std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b_b.size(0), b_b.size(1));
  ub_loop_ub = b_b.size(1);
  for (int i45{0}; i45 < ub_loop_ub; i45++) {
    int xb_loop_ub;
    xb_loop_ub = b_b.size(0);
    for (int i50{0}; i50 < xb_loop_ub; i50++) {
      r2[i50 + (r2.size(0) * i45)] = 4.0F * b_b[i50 + (b_b.size(0) * i45)];
    }
  }
  wb_loop_ub = r1.size(1);
  for (int i49{0}; i49 < wb_loop_ub; i49++) {
    int ac_loop_ub;
    ac_loop_ub = r1.size(0);
    for (int i52{0}; i52 < ac_loop_ub; i52++) {
      r1[i52 + (r1.size(0) * i49)] =
          3.0F * (r1[i52 + (r1.size(0) * i49)] + r[i52 + (r.size(0) * i49)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  bc_loop_ub = r2.size(1);
  for (int i53{0}; i53 < bc_loop_ub; i53++) {
    int cc_loop_ub;
    cc_loop_ub = r2.size(0);
    for (int i54{0}; i54 < cc_loop_ub; i54++) {
      cxy[i54 + (cxy.size(0) * i53)] =
          r2[i54 + (r2.size(0) * i53)] - r1[i54 + (r1.size(0) * i53)];
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
  for (int e_i{0}; e_i <= end; e_i++) {
    if ((r2[e_i] - r1[e_i]) < 0.0F) {
      r3[partialTrueCount] = e_i + 1;
      partialTrueCount++;
    }
  }
  dc_loop_ub = r3.size(0);
  for (int i55{0}; i55 < dc_loop_ub; i55++) {
    cxy[r3[i55] - 1] = 0.0F;
  }
  unnamed_idx_0 = static_cast<unsigned int>(Ig.size(0));
  r.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    int b_loop_ub_tmp;
    int fc_loop_ub;
    b_b.set_size(Ig.size(0), Ig.size(1));
    b_loop_ub_tmp = Ig.size(1);
    for (int i56{0}; i56 < b_loop_ub_tmp; i56++) {
      int ec_loop_ub;
      ec_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i57{0}; i57 < ec_loop_ub; i57++) {
        b_b[i57 + (b_b.size(0) * i56)] = r[i57 + (r.size(0) * i56)];
      }
    }
    for (int g_k{0}; g_k < b_loop_ub_tmp; g_k++) {
      int i59;
      i59 = b_b.size(0);
      for (int h_k{0}; h_k < i59; h_k++) {
        b_b[h_k + (b_b.size(0) * g_k)] = std::abs(Ig[h_k + (Ig.size(0) * g_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    fc_loop_ub = b_b.size(1);
    for (int i61{0}; i61 < fc_loop_ub; i61++) {
      int ic_loop_ub;
      ic_loop_ub = b_b.size(0);
      for (int i66{0}; i66 < ic_loop_ub; i66++) {
        r[i66 + (r.size(0) * i61)] = b_b[i66 + (b_b.size(0) * i61)];
      }
    }
  }
  unnamed_idx_0 = static_cast<unsigned int>(b_Iy.size(0));
  r1.set_size(b_Iy.size(0), b_Iy.size(1));
  if ((b_Iy.size(0) != 0) && (b_Iy.size(1) != 0)) {
    int c_loop_ub_tmp;
    int jc_loop_ub;
    b_b.set_size(b_Iy.size(0), b_Iy.size(1));
    c_loop_ub_tmp = b_Iy.size(1);
    for (int i58{0}; i58 < c_loop_ub_tmp; i58++) {
      int gc_loop_ub;
      gc_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i62{0}; i62 < gc_loop_ub; i62++) {
        b_b[i62 + (b_b.size(0) * i58)] = r1[i62 + (r1.size(0) * i58)];
      }
    }
    for (int j_k{0}; j_k < c_loop_ub_tmp; j_k++) {
      int i65;
      i65 = b_b.size(0);
      for (int o_k{0}; o_k < i65; o_k++) {
        b_b[o_k + (b_b.size(0) * j_k)] =
            std::abs(b_Iy[o_k + (b_Iy.size(0) * j_k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    jc_loop_ub = b_b.size(1);
    for (int i67{0}; i67 < jc_loop_ub; i67++) {
      int mc_loop_ub;
      mc_loop_ub = b_b.size(0);
      for (int i69{0}; i69 < mc_loop_ub; i69++) {
        r1[i69 + (r1.size(0) * i67)] = b_b[i69 + (b_b.size(0) * i67)];
      }
    }
  }
  b_b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i60;
    i60 = I_45_45.size(1);
    for (int i_k{0}; i_k < i60; i_k++) {
      int i64;
      i64 = b_b.size(0);
      for (int m_k{0}; m_k < i64; m_k++) {
        b_b[m_k + (b_b.size(0) * i_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * i_k)]);
      }
    }
  }
  c45.set_size(b_b.size(0), b_b.size(1));
  hc_loop_ub = b_b.size(1);
  for (int i63{0}; i63 < hc_loop_ub; i63++) {
    int kc_loop_ub;
    kc_loop_ub = b_b.size(0);
    for (int i68{0}; i68 < kc_loop_ub; i68++) {
      c45[i68 + (c45.size(0) * i63)] =
          (4.0F * b_b[i68 + (b_b.size(0) * i63)]) -
          (3.0F * (r[i68 + (r.size(0) * i63)] + r1[i68 + (r1.size(0) * i63)]));
    }
  }
  b_end = (c45.size(0) * c45.size(1)) - 1;
  b_trueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (c45[g_i] < 0.0F) {
      b_trueCount++;
    }
  }
  r4.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int h_i{0}; h_i <= b_end; h_i++) {
    if (c45[h_i] < 0.0F) {
      r4[b_partialTrueCount] = h_i + 1;
      b_partialTrueCount++;
    }
  }
  oc_loop_ub = r4.size(0);
  for (int i70{0}; i70 < oc_loop_ub; i70++) {
    c45[r4[i70] - 1] = 0.0F;
  }
  unnamed_idx_0 = static_cast<unsigned int>(Ig.size(0));
  Ix2.set_size(Ig.size(0), Ig.size(1));
  b_b.set_size(Ig.size(0), Ig.size(1));
  pc_loop_ub = Ig.size(1);
  for (int i71{0}; i71 < pc_loop_ub; i71++) {
    int qc_loop_ub;
    qc_loop_ub = static_cast<int>(unnamed_idx_0);
    for (int i72{0}; i72 < qc_loop_ub; i72++) {
      b_b[i72 + (b_b.size(0) * i71)] = Ix2[i72 + (Ix2.size(0) * i71)];
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
  rc_loop_ub = b_b.size(1);
  for (int i73{0}; i73 < rc_loop_ub; i73++) {
    int sc_loop_ub;
    sc_loop_ub = b_b.size(0);
    for (int i74{0}; i74 < sc_loop_ub; i74++) {
      Ix2[i74 + (Ix2.size(0) * i73)] = b_b[i74 + (b_b.size(0) * i73)];
    }
  }
  Iy2.set_size(b_Iy.size(0), b_Iy.size(1));
  p_N = b_Iy.size(1);
  for (int r_k{0}; r_k < p_N; r_k++) {
    int q_N;
    q_N = Iy2.size(0);
    for (int s_k{0}; s_k < q_N; s_k++) {
      Iy2[s_k + (Iy2.size(0) * r_k)] =
          rt_powf_snf(b_Iy[s_k + (b_Iy.size(0) * r_k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((b_b.size(0) != 0) && (b_b.size(1) != 0)) {
    int tc_loop_ub;
    int xc_loop_ub;
    padImage_outSize(b_b, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    tc_loop_ub = a.size(1);
    for (int i75{0}; i75 < tc_loop_ub; i75++) {
      int uc_loop_ub;
      uc_loop_ub = a.size(0);
      for (int i76{0}; i76 < uc_loop_ub; i76++) {
        b_a[i76 + (b_a.size(0) * i75)] =
            static_cast<double>(a[i76 + (a.size(0) * i75)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    xc_loop_ub = b.size(1);
    for (int i79{0}; i79 < xc_loop_ub; i79++) {
      int bd_loop_ub;
      bd_loop_ub = b.size(0);
      for (int i82{0}; i82 < bd_loop_ub; i82++) {
        Ix2[i82 + (Ix2.size(0) * i79)] =
            static_cast<float>(b[i82 + (b.size(0) * i79)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    int cd_loop_ub;
    int wc_loop_ub;
    padImage_outSize(Iy2, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    wc_loop_ub = a.size(1);
    for (int i78{0}; i78 < wc_loop_ub; i78++) {
      int ad_loop_ub;
      ad_loop_ub = a.size(0);
      for (int i81{0}; i81 < ad_loop_ub; i81++) {
        b_a[i81 + (b_a.size(0) * i78)] =
            static_cast<double>(a[i81 + (a.size(0) * i78)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    cd_loop_ub = b.size(1);
    for (int i83{0}; i83 < cd_loop_ub; i83++) {
      int ed_loop_ub;
      ed_loop_ub = b.size(0);
      for (int i85{0}; i85 < ed_loop_ub; i85++) {
        Iy2[i85 + (Iy2.size(0) * i83)] =
            static_cast<float>(b[i85 + (b.size(0) * i83)]);
      }
    }
  }
  IxIy.set_size(Ig.size(0), Ig.size(1));
  vc_loop_ub = Ig.size(1);
  for (int i77{0}; i77 < vc_loop_ub; i77++) {
    int yc_loop_ub;
    yc_loop_ub = Ig.size(0);
    for (int i80{0}; i80 < yc_loop_ub; i80++) {
      IxIy[i80 + (IxIy.size(0) * i77)] =
          Ig[i80 + (Ig.size(0) * i77)] * b_Iy[i80 + (b_Iy.size(0) * i77)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
    int dd_loop_ub;
    int hd_loop_ub;
    padImage_outSize(IxIy, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    dd_loop_ub = a.size(1);
    for (int i84{0}; i84 < dd_loop_ub; i84++) {
      int gd_loop_ub;
      gd_loop_ub = a.size(0);
      for (int i87{0}; i87 < gd_loop_ub; i87++) {
        b_a[i87 + (b_a.size(0) * i84)] =
            static_cast<double>(a[i87 + (a.size(0) * i84)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    IxIy.set_size(b.size(0), b.size(1));
    hd_loop_ub = b.size(1);
    for (int i88{0}; i88 < hd_loop_ub; i88++) {
      int jd_loop_ub;
      jd_loop_ub = b.size(0);
      for (int i90{0}; i90 < jd_loop_ub; i90++) {
        IxIy[i90 + (IxIy.size(0) * i88)] =
            static_cast<float>(b[i90 + (b.size(0) * i88)]);
      }
    }
  }
  vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  fd_loop_ub = points0.size(0);
  r3.set_size(points0.size(0));
  for (int i86{0}; i86 < fd_loop_ub; i86++) {
    r3[i86] = (static_cast<int>(points0[i86 + points0.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points0[i86])) - 1));
  }
  b_cxy.set_size(r3.size(0));
  id_loop_ub = r3.size(0);
  for (int i89{0}; i89 < id_loop_ub; i89++) {
    b_cxy[i89] = cxy[r3[i89] - 1];
  }
  board0 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, b_cxy, Ix2, Iy2, IxIy, 0.0, &lobj_0[0]);
  b_imagePoints.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(c45, points45);
  siz_idx_0 = c45.size(0);
  kd_loop_ub = points45.size(0);
  r3.set_size(points45.size(0));
  for (int i91{0}; i91 < kd_loop_ub; i91++) {
    r3[i91] = (static_cast<int>(points45[i91 + points45.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points45[i91])) - 1));
  }
  b_c45.set_size(r3.size(0));
  md_loop_ub = r3.size(0);
  for (int i92{0}; i92 < md_loop_ub; i92++) {
    b_c45[i92] = c45[r3[i92] - 1];
  }
  board45 = vision::internal::calibration::checkerboard::growCheckerboard(
      points45, b_c45, Ix2, Iy2, IxIy, 0.78539816339744828, &lobj_0[3]);
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
        int i94;
        int i96;
        int i_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int i93{0}; i93 < c_board0; i93++) {
          s[i93] = board0->BoardIdx[i93];
        }
        h_n = 0;
        i94 = s.size(0);
        for (int t_k{0}; t_k < i94; t_k++) {
          if (s[t_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i95{0}; i95 < c_board45; i95++) {
          s[i95] = board45->BoardIdx[i95];
        }
        i_n = 0;
        i96 = s.size(0);
        for (int u_k{0}; u_k < i96; u_k++) {
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
    board0 = vision::internal::calibration::checkerboard::orient(board0, ab_I);
    vision::internal::calibration::checkerboard::toPoints(board0, b_imagePoints,
                                                          boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, b_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    board45 =
        vision::internal::calibration::checkerboard::orient(board45, ab_I);
    vision::internal::calibration::checkerboard::toPoints(
        board45, b_imagePoints, boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_45, b_imagePoints);
  }
  if ((b_imagePoints.size(0) == 0) || (b_imagePoints.size(1) == 0)) {
    vision::internal::calibration::checkerboard::detectCheckerboard(
        ab_I, b_imagePoints, boardSize);
  }
}

} // namespace coder

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
