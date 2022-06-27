//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: secondDerivCornerMetric.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "secondDerivCornerMetric.h"
#include "conv2AXPYValidCMP.h"
#include "imfilter.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &o_I
//                ::coder::array<float, 2U> &cxy
//                ::coder::array<float, 2U> &c45
//                ::coder::array<float, 2U> &Ix
//                ::coder::array<float, 2U> &Iy
//                ::coder::array<float, 2U> &Ixy
//                ::coder::array<float, 2U> &I_45_45
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                               ::coder::array<float, 2U> &cxy,
                               ::coder::array<float, 2U> &c45,
                               ::coder::array<float, 2U> &Ix,
                               ::coder::array<float, 2U> &Iy,
                               ::coder::array<float, 2U> &Ixy,
                               ::coder::array<float, 2U> &I_45_45)
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
  array<double, 2U> b;
  array<double, 2U> c_a;
  array<float, 2U> I_45_x;
  array<float, 2U> I_45_y;
  array<float, 2U> b_I_45;
  array<float, 2U> b_a;
  array<float, 2U> b_b;
  array<float, 2U> b_x;
  array<float, 2U> r;
  array<float, 2U> r1;
  array<float, 2U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  double finalSize[2];
  double pad[2];
  int ab_loop_ub;
  int ac_loop_ub;
  int b_end;
  int b_i8;
  int b_k;
  int b_partialTrueCount;
  int b_trueCount;
  int bc_loop_ub;
  int cc_loop_ub;
  int d_loop_ub;
  int db_loop_ub;
  int e_k;
  int e_loop_ub;
  int end;
  int fb_loop_ub;
  int fc_loop_ub;
  int g_k;
  int gb_loop_ub;
  int gc_loop_ub;
  int h_loop_ub;
  int i11;
  int i14;
  int i15;
  int i18;
  int i19;
  int i2;
  int i22;
  int i23;
  int i26;
  int i27;
  int i3;
  int i30;
  int i31;
  int i35;
  int i36;
  int i40;
  int i42;
  int i43;
  int i46;
  int i47;
  int i49;
  int i50;
  int i51;
  int i53;
  int i58;
  int i6;
  int i61;
  int i64;
  int i65;
  int i67;
  int i68;
  int i69;
  int i70;
  int i9;
  int ib_loop_ub;
  int ic_loop_ub;
  int j_loop_ub;
  int jb_loop_ub;
  int k_k;
  int k_loop_ub;
  int kb_loop_ub;
  int kc_loop_ub;
  int m_k;
  int mb_loop_ub;
  int mc_loop_ub;
  int o_k;
  int oc_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int pc_loop_ub;
  int q_loop_ub;
  int qb_loop_ub;
  int rb_loop_ub;
  int s_loop_ub;
  int sb_loop_ub;
  int t_loop_ub;
  int tb_loop_ub;
  int trueCount;
  int u_loop_ub;
  int ub_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int wb_loop_ub;
  int x_loop_ub;
  int xb_loop_ub;
  int y_loop_ub;
  int yb_loop_ub;
  finalSize[0] = static_cast<double>(o_I.size(0));
  pad[0] = 14.0;
  finalSize[1] = static_cast<double>(o_I.size(1));
  pad[1] = 14.0;
  if ((o_I.size(0) == 0) || (o_I.size(1) == 0)) {
    int loop_ub;
    Ix.set_size(o_I.size(0), o_I.size(1));
    loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    d_loop_ub)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      d_loop_ub = o_I.size(0);
      for (i2 = 0; i2 < d_loop_ub; i2++) {
        Ix[i2 + (Ix.size(0) * b_i)] = o_I[i2 + (o_I.size(0) * b_i)];
      }
    }
  } else {
    int b_loop_ub;
    int c_loop_ub;
    padImage_outSize(o_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    b_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    e_loop_ub)

    for (int i1 = 0; i1 < b_loop_ub; i1++) {
      e_loop_ub = b_a.size(0);
      for (i3 = 0; i3 < e_loop_ub; i3++) {
        c_a[i3 + (c_a.size(0) * i1)] =
            static_cast<double>(b_a[i3 + (b_a.size(0) * i1)]);
      }
    }
    b_conv2_separable_valid(dv, dv1, c_a, finalSize, b);
    Ix.set_size(b.size(0), b.size(1));
    c_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    h_loop_ub)

    for (int i4 = 0; i4 < c_loop_ub; i4++) {
      h_loop_ub = b.size(0);
      for (i6 = 0; i6 < h_loop_ub; i6++) {
        Ix[i6 + (Ix.size(0) * i4)] =
            static_cast<float>(b[i6 + (b.size(0) * i4)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ix.size(0) == 0) || (Ix.size(1) == 0)) {
    int f_loop_ub;
    Iy.set_size(Ix.size(0), Ix.size(1));
    f_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    j_loop_ub)

    for (int i5 = 0; i5 < f_loop_ub; i5++) {
      j_loop_ub = Ix.size(0);
      for (b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
        Iy[b_i8 + (Iy.size(0) * i5)] = Ix[b_i8 + (Ix.size(0) * i5)];
      }
    }
  } else {
    int g_loop_ub;
    int i_loop_ub;
    padImage_outSize(Ix, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    g_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    k_loop_ub)

    for (int i7 = 0; i7 < g_loop_ub; i7++) {
      k_loop_ub = b_a.size(0);
      for (i9 = 0; i9 < k_loop_ub; i9++) {
        c_a[i9 + (c_a.size(0) * i7)] =
            static_cast<double>(b_a[i9 + (b_a.size(0) * i7)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Iy.set_size(b.size(0), b.size(1));
    i_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11,       \
                                                                    p_loop_ub)

    for (int i10 = 0; i10 < i_loop_ub; i10++) {
      p_loop_ub = b.size(0);
      for (i11 = 0; i11 < p_loop_ub; i11++) {
        Iy[i11 + (Iy.size(0) * i10)] =
            static_cast<float>(b[i11 + (b.size(0) * i10)]);
      }
    }
  }
  imfilter(Ix);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ix.size(0) == 0) || (Ix.size(1) == 0)) {
    int m_loop_ub;
    Ixy.set_size(Ix.size(0), Ix.size(1));
    m_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i14,       \
                                                                    s_loop_ub)

    for (int i12 = 0; i12 < m_loop_ub; i12++) {
      s_loop_ub = Ix.size(0);
      for (i14 = 0; i14 < s_loop_ub; i14++) {
        Ixy[i14 + (Ixy.size(0) * i12)] = Ix[i14 + (Ix.size(0) * i12)];
      }
    }
  } else {
    int o_loop_ub;
    int r_loop_ub;
    padImage_outSize(Ix, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    o_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    t_loop_ub)

    for (int i13 = 0; i13 < o_loop_ub; i13++) {
      t_loop_ub = b_a.size(0);
      for (i15 = 0; i15 < t_loop_ub; i15++) {
        c_a[i15 + (c_a.size(0) * i13)] =
            static_cast<double>(b_a[i15 + (b_a.size(0) * i13)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    r_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19,       \
                                                                    w_loop_ub)

    for (int i17 = 0; i17 < r_loop_ub; i17++) {
      w_loop_ub = b.size(0);
      for (i19 = 0; i19 < w_loop_ub; i19++) {
        Ixy[i19 + (Ixy.size(0) * i17)] =
            static_cast<float>(b[i19 + (b.size(0) * i17)]);
      }
    }
  }
  r.set_size(Ix.size(0), Ix.size(1));
  q_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18,       \
                                                                    v_loop_ub)

  for (int i16 = 0; i16 < q_loop_ub; i16++) {
    v_loop_ub = Ix.size(0);
    for (i18 = 0; i18 < v_loop_ub; i18++) {
      r[i18 + (r.size(0) * i16)] = Ix[i18 + (Ix.size(0) * i16)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  u_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i22,       \
                                                                    y_loop_ub)

  for (int i20 = 0; i20 < u_loop_ub; i20++) {
    y_loop_ub = r.size(0);
    for (i22 = 0; i22 < y_loop_ub; i22++) {
      b_I_45[i22 + (b_I_45.size(0) * i20)] =
          r[i22 + (r.size(0) * i20)] +
          (Iy[i22 + (Iy.size(0) * i20)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  x_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i23, ab_loop_ub)

  for (int i21 = 0; i21 < x_loop_ub; i21++) {
    ab_loop_ub = b_I_45.size(0);
    for (i23 = 0; i23 < ab_loop_ub; i23++) {
      I_45_x[i23 + (I_45_x.size(0) * i21)] =
          b_I_45[i23 + (b_I_45.size(0) * i21)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((b_I_45.size(0) == 0) || (b_I_45.size(1) == 0)) {
    int bb_loop_ub;
    I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
    bb_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i26, fb_loop_ub)

    for (int i24 = 0; i24 < bb_loop_ub; i24++) {
      fb_loop_ub = b_I_45.size(0);
      for (i26 = 0; i26 < fb_loop_ub; i26++) {
        I_45_y[i26 + (I_45_y.size(0) * i24)] =
            b_I_45[i26 + (b_I_45.size(0) * i24)];
      }
    }
  } else {
    int cb_loop_ub;
    int eb_loop_ub;
    padImage_outSize(b_I_45, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    cb_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, gb_loop_ub)

    for (int i25 = 0; i25 < cb_loop_ub; i25++) {
      gb_loop_ub = b_a.size(0);
      for (i27 = 0; i27 < gb_loop_ub; i27++) {
        c_a[i27 + (c_a.size(0) * i25)] =
            static_cast<double>(b_a[i27 + (b_a.size(0) * i25)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    I_45_y.set_size(b.size(0), b.size(1));
    eb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i30, ib_loop_ub)

    for (int i29 = 0; i29 < eb_loop_ub; i29++) {
      ib_loop_ub = b.size(0);
      for (i30 = 0; i30 < ib_loop_ub; i30++) {
        I_45_y[i30 + (I_45_y.size(0) * i29)] =
            static_cast<float>(b[i30 + (b.size(0) * i29)]);
      }
    }
  }
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  db_loop_ub = I_45_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i31, kb_loop_ub)

  for (int i28 = 0; i28 < db_loop_ub; i28++) {
    kb_loop_ub = I_45_x.size(0);
    for (i31 = 0; i31 < kb_loop_ub; i31++) {
      I_45_45[i31 + (I_45_45.size(0) * i28)] =
          (I_45_x[i31 + (I_45_x.size(0) * i28)] * 0.707106769F) +
          (I_45_y[i31 + (I_45_y.size(0) * i28)] * -0.707106769F);
    }
  }
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int hb_loop_ub;
    int i34;
    int pb_loop_ub;
    b_b.set_size(b_I_45.size(0), b_I_45.size(1));
    hb_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i35, mb_loop_ub)

    for (int i32 = 0; i32 < hb_loop_ub; i32++) {
      mb_loop_ub = r1.size(0);
      for (i35 = 0; i35 < mb_loop_ub; i35++) {
        b_b[i35 + (b_b.size(0) * i32)] = r1[i35 + (r1.size(0) * i32)];
      }
    }
    i34 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i40)

    for (int k = 0; k < i34; k++) {
      i40 = b_b.size(0);
      for (b_k = 0; b_k < i40; b_k++) {
        b_b[b_k + (b_b.size(0) * k)] =
            std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    pb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i43, tb_loop_ub)

    for (int i38 = 0; i38 < pb_loop_ub; i38++) {
      tb_loop_ub = b_b.size(0);
      for (i43 = 0; i43 < tb_loop_ub; i43++) {
        r1[i43 + (r1.size(0) * i38)] = b_b[i43 + (b_b.size(0) * i38)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  jb_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i36, qb_loop_ub)

  for (int i33 = 0; i33 < jb_loop_ub; i33++) {
    qb_loop_ub = r.size(0);
    for (i36 = 0; i36 < qb_loop_ub; i36++) {
      b_x[i36 + (b_x.size(0) * i33)] =
          r[i36 + (r.size(0) * i33)] +
          (Iy[i36 + (Iy.size(0) * i33)] * -0.707106769F);
    }
  }
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int i41;
    int ob_loop_ub;
    int vb_loop_ub;
    b_b.set_size(b_x.size(0), b_x.size(1));
    ob_loop_ub = b_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i42, sb_loop_ub)

    for (int i37 = 0; i37 < ob_loop_ub; i37++) {
      sb_loop_ub = r.size(0);
      for (i42 = 0; i42 < sb_loop_ub; i42++) {
        b_b[i42 + (b_b.size(0) * i37)] = r[i42 + (r.size(0) * i37)];
      }
    }
    i41 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_k, i49)

    for (int d_k = 0; d_k < i41; d_k++) {
      i49 = b_b.size(0);
      for (g_k = 0; g_k < i49; g_k++) {
        b_b[g_k + (b_b.size(0) * d_k)] =
            std::abs(b_x[g_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    vb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i51, ac_loop_ub)

    for (int i48 = 0; i48 < vb_loop_ub; i48++) {
      ac_loop_ub = b_b.size(0);
      for (i51 = 0; i51 < ac_loop_ub; i51++) {
        r[i51 + (r.size(0) * i48)] = b_b[i51 + (b_b.size(0) * i48)];
      }
    }
  }
  b_b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i39;
    i39 = Ixy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_k, i47)

    for (int c_k = 0; c_k < i39; c_k++) {
      i47 = b_b.size(0);
      for (e_k = 0; e_k < i47; e_k++) {
        b_b[e_k + (b_b.size(0) * c_k)] =
            std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b_b.size(0), b_b.size(1));
  rb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i46, wb_loop_ub)

  for (int i44 = 0; i44 < rb_loop_ub; i44++) {
    wb_loop_ub = b_b.size(0);
    for (i46 = 0; i46 < wb_loop_ub; i46++) {
      r2[i46 + (r2.size(0) * i44)] = 16.0F * b_b[i46 + (b_b.size(0) * i44)];
    }
  }
  ub_loop_ub = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i50, yb_loop_ub)

  for (int i45 = 0; i45 < ub_loop_ub; i45++) {
    yb_loop_ub = r1.size(0);
    for (i50 = 0; i50 < yb_loop_ub; i50++) {
      r1[i50 + (r1.size(0) * i45)] =
          6.0F * (r1[i50 + (r1.size(0) * i45)] + r[i50 + (r.size(0) * i45)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  xb_loop_ub = r2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i53, bc_loop_ub)

  for (int i52 = 0; i52 < xb_loop_ub; i52++) {
    bc_loop_ub = r2.size(0);
    for (i53 = 0; i53 < bc_loop_ub; i53++) {
      cxy[i53 + (cxy.size(0) * i52)] =
          r2[i53 + (r2.size(0) * i52)] - r1[i53 + (r1.size(0) * i52)];
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
  cc_loop_ub = r3.size(0);
  for (int i54{0}; i54 < cc_loop_ub; i54++) {
    cxy[r3[i54] - 1] = 0.0F;
  }
  r.set_size(Ix.size(0), Ix.size(1));
  if ((Ix.size(0) != 0) && (Ix.size(1) != 0)) {
    int dc_loop_ub;
    int hc_loop_ub;
    int i56;
    b_b.set_size(Ix.size(0), Ix.size(1));
    dc_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i58, fc_loop_ub)

    for (int i55 = 0; i55 < dc_loop_ub; i55++) {
      fc_loop_ub = r.size(0);
      for (i58 = 0; i58 < fc_loop_ub; i58++) {
        b_b[i58 + (b_b.size(0) * i55)] = r[i58 + (r.size(0) * i55)];
      }
    }
    i56 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, i64)

    for (int h_k = 0; h_k < i56; h_k++) {
      i64 = b_b.size(0);
      for (k_k = 0; k_k < i64; k_k++) {
        b_b[k_k + (b_b.size(0) * h_k)] = std::abs(Ix[k_k + (Ix.size(0) * h_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    hc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i67, kc_loop_ub)

    for (int i63 = 0; i63 < hc_loop_ub; i63++) {
      kc_loop_ub = b_b.size(0);
      for (i67 = 0; i67 < kc_loop_ub; i67++) {
        r[i67 + (r.size(0) * i63)] = b_b[i67 + (b_b.size(0) * i63)];
      }
    }
  }
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    int ec_loop_ub;
    int i60;
    int jc_loop_ub;
    b_b.set_size(Iy.size(0), Iy.size(1));
    ec_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i61, ic_loop_ub)

    for (int i57 = 0; i57 < ec_loop_ub; i57++) {
      ic_loop_ub = r1.size(0);
      for (i61 = 0; i61 < ic_loop_ub; i61++) {
        b_b[i61 + (b_b.size(0) * i57)] = r1[i61 + (r1.size(0) * i57)];
      }
    }
    i60 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(o_k, i68)

    for (int j_k = 0; j_k < i60; j_k++) {
      i68 = b_b.size(0);
      for (o_k = 0; o_k < i68; o_k++) {
        b_b[o_k + (b_b.size(0) * j_k)] = std::abs(Iy[o_k + (Iy.size(0) * j_k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    jc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i70, oc_loop_ub)

    for (int i66 = 0; i66 < jc_loop_ub; i66++) {
      oc_loop_ub = b_b.size(0);
      for (i70 = 0; i70 < oc_loop_ub; i70++) {
        r1[i70 + (r1.size(0) * i66)] = b_b[i70 + (b_b.size(0) * i66)];
      }
    }
  }
  b_b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i59;
    i59 = I_45_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(m_k, i65)

    for (int i_k = 0; i_k < i59; i_k++) {
      i65 = b_b.size(0);
      for (m_k = 0; m_k < i65; m_k++) {
        b_b[m_k + (b_b.size(0) * i_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * i_k)]);
      }
    }
  }
  c45.set_size(b_b.size(0), b_b.size(1));
  gc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i69, mc_loop_ub)

  for (int i62 = 0; i62 < gc_loop_ub; i62++) {
    mc_loop_ub = b_b.size(0);
    for (i69 = 0; i69 < mc_loop_ub; i69++) {
      c45[i69 + (c45.size(0) * i62)] =
          (16.0F * b_b[i69 + (b_b.size(0) * i62)]) -
          (6.0F * (r[i69 + (r.size(0) * i62)] + r1[i69 + (r1.size(0) * i62)]));
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
  pc_loop_ub = r4.size(0);
  for (int i71{0}; i71 < pc_loop_ub; i71++) {
    c45[r4[i71] - 1] = 0.0F;
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &o_I
//                ::coder::array<float, 2U> &cxy
//                ::coder::array<float, 2U> &c45
//                ::coder::array<float, 2U> &Ix
//                ::coder::array<float, 2U> &Iy
//                ::coder::array<float, 2U> &Ixy
//                ::coder::array<float, 2U> &I_45_45
// Return Type  : void
//
void secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                             ::coder::array<float, 2U> &cxy,
                             ::coder::array<float, 2U> &c45,
                             ::coder::array<float, 2U> &Ix,
                             ::coder::array<float, 2U> &Iy,
                             ::coder::array<float, 2U> &Ixy,
                             ::coder::array<float, 2U> &I_45_45)
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
  array<double, 2U> b;
  array<double, 2U> c_a;
  array<float, 2U> I_45_x;
  array<float, 2U> I_45_y;
  array<float, 2U> b_I_45;
  array<float, 2U> b_a;
  array<float, 2U> b_b;
  array<float, 2U> b_x;
  array<float, 2U> r;
  array<float, 2U> r1;
  array<float, 2U> r2;
  array<int, 1U> r3;
  array<int, 1U> r4;
  double finalSize[2];
  double pad[2];
  int ab_loop_ub;
  int ac_loop_ub;
  int b_end;
  int b_i8;
  int b_k;
  int b_partialTrueCount;
  int b_trueCount;
  int bc_loop_ub;
  int cc_loop_ub;
  int d_loop_ub;
  int db_loop_ub;
  int e_k;
  int e_loop_ub;
  int end;
  int fb_loop_ub;
  int fc_loop_ub;
  int g_k;
  int gb_loop_ub;
  int gc_loop_ub;
  int h_loop_ub;
  int i11;
  int i14;
  int i15;
  int i18;
  int i19;
  int i2;
  int i22;
  int i23;
  int i26;
  int i27;
  int i3;
  int i30;
  int i31;
  int i35;
  int i36;
  int i40;
  int i42;
  int i43;
  int i46;
  int i47;
  int i49;
  int i50;
  int i51;
  int i53;
  int i58;
  int i6;
  int i61;
  int i64;
  int i65;
  int i67;
  int i68;
  int i69;
  int i70;
  int i9;
  int ib_loop_ub;
  int ic_loop_ub;
  int j_loop_ub;
  int jb_loop_ub;
  int k_k;
  int k_loop_ub;
  int kb_loop_ub;
  int kc_loop_ub;
  int m_k;
  int mb_loop_ub;
  int mc_loop_ub;
  int o_k;
  int oc_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int pc_loop_ub;
  int q_loop_ub;
  int qb_loop_ub;
  int rb_loop_ub;
  int s_loop_ub;
  int sb_loop_ub;
  int t_loop_ub;
  int tb_loop_ub;
  int trueCount;
  int u_loop_ub;
  int ub_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int wb_loop_ub;
  int x_loop_ub;
  int xb_loop_ub;
  int y_loop_ub;
  int yb_loop_ub;
  finalSize[0] = static_cast<double>(o_I.size(0));
  pad[0] = 7.0;
  finalSize[1] = static_cast<double>(o_I.size(1));
  pad[1] = 7.0;
  if ((o_I.size(0) == 0) || (o_I.size(1) == 0)) {
    int loop_ub;
    Ix.set_size(o_I.size(0), o_I.size(1));
    loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    d_loop_ub)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      d_loop_ub = o_I.size(0);
      for (i2 = 0; i2 < d_loop_ub; i2++) {
        Ix[i2 + (Ix.size(0) * b_i)] = o_I[i2 + (o_I.size(0) * b_i)];
      }
    }
  } else {
    int b_loop_ub;
    int c_loop_ub;
    padImage_outSize(o_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    b_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    e_loop_ub)

    for (int i1 = 0; i1 < b_loop_ub; i1++) {
      e_loop_ub = b_a.size(0);
      for (i3 = 0; i3 < e_loop_ub; i3++) {
        c_a[i3 + (c_a.size(0) * i1)] =
            static_cast<double>(b_a[i3 + (b_a.size(0) * i1)]);
      }
    }
    conv2_separable_valid(dv, dv1, c_a, finalSize, b);
    Ix.set_size(b.size(0), b.size(1));
    c_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    h_loop_ub)

    for (int i4 = 0; i4 < c_loop_ub; i4++) {
      h_loop_ub = b.size(0);
      for (i6 = 0; i6 < h_loop_ub; i6++) {
        Ix[i6 + (Ix.size(0) * i4)] =
            static_cast<float>(b[i6 + (b.size(0) * i4)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ix.size(0) == 0) || (Ix.size(1) == 0)) {
    int f_loop_ub;
    Iy.set_size(Ix.size(0), Ix.size(1));
    f_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    j_loop_ub)

    for (int i5 = 0; i5 < f_loop_ub; i5++) {
      j_loop_ub = Ix.size(0);
      for (b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
        Iy[b_i8 + (Iy.size(0) * i5)] = Ix[b_i8 + (Ix.size(0) * i5)];
      }
    }
  } else {
    int g_loop_ub;
    int i_loop_ub;
    padImage_outSize(Ix, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    g_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    k_loop_ub)

    for (int i7 = 0; i7 < g_loop_ub; i7++) {
      k_loop_ub = b_a.size(0);
      for (i9 = 0; i9 < k_loop_ub; i9++) {
        c_a[i9 + (c_a.size(0) * i7)] =
            static_cast<double>(b_a[i9 + (b_a.size(0) * i7)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Iy.set_size(b.size(0), b.size(1));
    i_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11,       \
                                                                    p_loop_ub)

    for (int i10 = 0; i10 < i_loop_ub; i10++) {
      p_loop_ub = b.size(0);
      for (i11 = 0; i11 < p_loop_ub; i11++) {
        Iy[i11 + (Iy.size(0) * i10)] =
            static_cast<float>(b[i11 + (b.size(0) * i10)]);
      }
    }
  }
  imfilter(Ix);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ix.size(0) == 0) || (Ix.size(1) == 0)) {
    int m_loop_ub;
    Ixy.set_size(Ix.size(0), Ix.size(1));
    m_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i14,       \
                                                                    s_loop_ub)

    for (int i12 = 0; i12 < m_loop_ub; i12++) {
      s_loop_ub = Ix.size(0);
      for (i14 = 0; i14 < s_loop_ub; i14++) {
        Ixy[i14 + (Ixy.size(0) * i12)] = Ix[i14 + (Ix.size(0) * i12)];
      }
    }
  } else {
    int o_loop_ub;
    int r_loop_ub;
    padImage_outSize(Ix, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    o_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    t_loop_ub)

    for (int i13 = 0; i13 < o_loop_ub; i13++) {
      t_loop_ub = b_a.size(0);
      for (i15 = 0; i15 < t_loop_ub; i15++) {
        c_a[i15 + (c_a.size(0) * i13)] =
            static_cast<double>(b_a[i15 + (b_a.size(0) * i13)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    r_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19,       \
                                                                    w_loop_ub)

    for (int i17 = 0; i17 < r_loop_ub; i17++) {
      w_loop_ub = b.size(0);
      for (i19 = 0; i19 < w_loop_ub; i19++) {
        Ixy[i19 + (Ixy.size(0) * i17)] =
            static_cast<float>(b[i19 + (b.size(0) * i17)]);
      }
    }
  }
  r.set_size(Ix.size(0), Ix.size(1));
  q_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18,       \
                                                                    v_loop_ub)

  for (int i16 = 0; i16 < q_loop_ub; i16++) {
    v_loop_ub = Ix.size(0);
    for (i18 = 0; i18 < v_loop_ub; i18++) {
      r[i18 + (r.size(0) * i16)] = Ix[i18 + (Ix.size(0) * i16)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  u_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i22,       \
                                                                    y_loop_ub)

  for (int i20 = 0; i20 < u_loop_ub; i20++) {
    y_loop_ub = r.size(0);
    for (i22 = 0; i22 < y_loop_ub; i22++) {
      b_I_45[i22 + (b_I_45.size(0) * i20)] =
          r[i22 + (r.size(0) * i20)] +
          (Iy[i22 + (Iy.size(0) * i20)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  x_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i23, ab_loop_ub)

  for (int i21 = 0; i21 < x_loop_ub; i21++) {
    ab_loop_ub = b_I_45.size(0);
    for (i23 = 0; i23 < ab_loop_ub; i23++) {
      I_45_x[i23 + (I_45_x.size(0) * i21)] =
          b_I_45[i23 + (b_I_45.size(0) * i21)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((b_I_45.size(0) == 0) || (b_I_45.size(1) == 0)) {
    int bb_loop_ub;
    I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
    bb_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i26, fb_loop_ub)

    for (int i24 = 0; i24 < bb_loop_ub; i24++) {
      fb_loop_ub = b_I_45.size(0);
      for (i26 = 0; i26 < fb_loop_ub; i26++) {
        I_45_y[i26 + (I_45_y.size(0) * i24)] =
            b_I_45[i26 + (b_I_45.size(0) * i24)];
      }
    }
  } else {
    int cb_loop_ub;
    int eb_loop_ub;
    padImage_outSize(b_I_45, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    cb_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, gb_loop_ub)

    for (int i25 = 0; i25 < cb_loop_ub; i25++) {
      gb_loop_ub = b_a.size(0);
      for (i27 = 0; i27 < gb_loop_ub; i27++) {
        c_a[i27 + (c_a.size(0) * i25)] =
            static_cast<double>(b_a[i27 + (b_a.size(0) * i25)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    I_45_y.set_size(b.size(0), b.size(1));
    eb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i30, ib_loop_ub)

    for (int i29 = 0; i29 < eb_loop_ub; i29++) {
      ib_loop_ub = b.size(0);
      for (i30 = 0; i30 < ib_loop_ub; i30++) {
        I_45_y[i30 + (I_45_y.size(0) * i29)] =
            static_cast<float>(b[i30 + (b.size(0) * i29)]);
      }
    }
  }
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  db_loop_ub = I_45_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i31, kb_loop_ub)

  for (int i28 = 0; i28 < db_loop_ub; i28++) {
    kb_loop_ub = I_45_x.size(0);
    for (i31 = 0; i31 < kb_loop_ub; i31++) {
      I_45_45[i31 + (I_45_45.size(0) * i28)] =
          (I_45_x[i31 + (I_45_x.size(0) * i28)] * 0.707106769F) +
          (I_45_y[i31 + (I_45_y.size(0) * i28)] * -0.707106769F);
    }
  }
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int hb_loop_ub;
    int i34;
    int pb_loop_ub;
    b_b.set_size(b_I_45.size(0), b_I_45.size(1));
    hb_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i35, mb_loop_ub)

    for (int i32 = 0; i32 < hb_loop_ub; i32++) {
      mb_loop_ub = r1.size(0);
      for (i35 = 0; i35 < mb_loop_ub; i35++) {
        b_b[i35 + (b_b.size(0) * i32)] = r1[i35 + (r1.size(0) * i32)];
      }
    }
    i34 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i40)

    for (int k = 0; k < i34; k++) {
      i40 = b_b.size(0);
      for (b_k = 0; b_k < i40; b_k++) {
        b_b[b_k + (b_b.size(0) * k)] =
            std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    pb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i43, tb_loop_ub)

    for (int i38 = 0; i38 < pb_loop_ub; i38++) {
      tb_loop_ub = b_b.size(0);
      for (i43 = 0; i43 < tb_loop_ub; i43++) {
        r1[i43 + (r1.size(0) * i38)] = b_b[i43 + (b_b.size(0) * i38)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  jb_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i36, qb_loop_ub)

  for (int i33 = 0; i33 < jb_loop_ub; i33++) {
    qb_loop_ub = r.size(0);
    for (i36 = 0; i36 < qb_loop_ub; i36++) {
      b_x[i36 + (b_x.size(0) * i33)] =
          r[i36 + (r.size(0) * i33)] +
          (Iy[i36 + (Iy.size(0) * i33)] * -0.707106769F);
    }
  }
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int i41;
    int ob_loop_ub;
    int vb_loop_ub;
    b_b.set_size(b_x.size(0), b_x.size(1));
    ob_loop_ub = b_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i42, sb_loop_ub)

    for (int i37 = 0; i37 < ob_loop_ub; i37++) {
      sb_loop_ub = r.size(0);
      for (i42 = 0; i42 < sb_loop_ub; i42++) {
        b_b[i42 + (b_b.size(0) * i37)] = r[i42 + (r.size(0) * i37)];
      }
    }
    i41 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_k, i49)

    for (int d_k = 0; d_k < i41; d_k++) {
      i49 = b_b.size(0);
      for (g_k = 0; g_k < i49; g_k++) {
        b_b[g_k + (b_b.size(0) * d_k)] =
            std::abs(b_x[g_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    vb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i51, ac_loop_ub)

    for (int i48 = 0; i48 < vb_loop_ub; i48++) {
      ac_loop_ub = b_b.size(0);
      for (i51 = 0; i51 < ac_loop_ub; i51++) {
        r[i51 + (r.size(0) * i48)] = b_b[i51 + (b_b.size(0) * i48)];
      }
    }
  }
  b_b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i39;
    i39 = Ixy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_k, i47)

    for (int c_k = 0; c_k < i39; c_k++) {
      i47 = b_b.size(0);
      for (e_k = 0; e_k < i47; e_k++) {
        b_b[e_k + (b_b.size(0) * c_k)] =
            std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b_b.size(0), b_b.size(1));
  rb_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i46, wb_loop_ub)

  for (int i44 = 0; i44 < rb_loop_ub; i44++) {
    wb_loop_ub = b_b.size(0);
    for (i46 = 0; i46 < wb_loop_ub; i46++) {
      r2[i46 + (r2.size(0) * i44)] = 4.0F * b_b[i46 + (b_b.size(0) * i44)];
    }
  }
  ub_loop_ub = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i50, yb_loop_ub)

  for (int i45 = 0; i45 < ub_loop_ub; i45++) {
    yb_loop_ub = r1.size(0);
    for (i50 = 0; i50 < yb_loop_ub; i50++) {
      r1[i50 + (r1.size(0) * i45)] =
          3.0F * (r1[i50 + (r1.size(0) * i45)] + r[i50 + (r.size(0) * i45)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  xb_loop_ub = r2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i53, bc_loop_ub)

  for (int i52 = 0; i52 < xb_loop_ub; i52++) {
    bc_loop_ub = r2.size(0);
    for (i53 = 0; i53 < bc_loop_ub; i53++) {
      cxy[i53 + (cxy.size(0) * i52)] =
          r2[i53 + (r2.size(0) * i52)] - r1[i53 + (r1.size(0) * i52)];
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
  cc_loop_ub = r3.size(0);
  for (int i54{0}; i54 < cc_loop_ub; i54++) {
    cxy[r3[i54] - 1] = 0.0F;
  }
  r.set_size(Ix.size(0), Ix.size(1));
  if ((Ix.size(0) != 0) && (Ix.size(1) != 0)) {
    int dc_loop_ub;
    int hc_loop_ub;
    int i56;
    b_b.set_size(Ix.size(0), Ix.size(1));
    dc_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i58, fc_loop_ub)

    for (int i55 = 0; i55 < dc_loop_ub; i55++) {
      fc_loop_ub = r.size(0);
      for (i58 = 0; i58 < fc_loop_ub; i58++) {
        b_b[i58 + (b_b.size(0) * i55)] = r[i58 + (r.size(0) * i55)];
      }
    }
    i56 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, i64)

    for (int h_k = 0; h_k < i56; h_k++) {
      i64 = b_b.size(0);
      for (k_k = 0; k_k < i64; k_k++) {
        b_b[k_k + (b_b.size(0) * h_k)] = std::abs(Ix[k_k + (Ix.size(0) * h_k)]);
      }
    }
    r.set_size(b_b.size(0), b_b.size(1));
    hc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i67, kc_loop_ub)

    for (int i63 = 0; i63 < hc_loop_ub; i63++) {
      kc_loop_ub = b_b.size(0);
      for (i67 = 0; i67 < kc_loop_ub; i67++) {
        r[i67 + (r.size(0) * i63)] = b_b[i67 + (b_b.size(0) * i63)];
      }
    }
  }
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    int ec_loop_ub;
    int i60;
    int jc_loop_ub;
    b_b.set_size(Iy.size(0), Iy.size(1));
    ec_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i61, ic_loop_ub)

    for (int i57 = 0; i57 < ec_loop_ub; i57++) {
      ic_loop_ub = r1.size(0);
      for (i61 = 0; i61 < ic_loop_ub; i61++) {
        b_b[i61 + (b_b.size(0) * i57)] = r1[i61 + (r1.size(0) * i57)];
      }
    }
    i60 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(o_k, i68)

    for (int j_k = 0; j_k < i60; j_k++) {
      i68 = b_b.size(0);
      for (o_k = 0; o_k < i68; o_k++) {
        b_b[o_k + (b_b.size(0) * j_k)] = std::abs(Iy[o_k + (Iy.size(0) * j_k)]);
      }
    }
    r1.set_size(b_b.size(0), b_b.size(1));
    jc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i70, oc_loop_ub)

    for (int i66 = 0; i66 < jc_loop_ub; i66++) {
      oc_loop_ub = b_b.size(0);
      for (i70 = 0; i70 < oc_loop_ub; i70++) {
        r1[i70 + (r1.size(0) * i66)] = b_b[i70 + (b_b.size(0) * i66)];
      }
    }
  }
  b_b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i59;
    i59 = I_45_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(m_k, i65)

    for (int i_k = 0; i_k < i59; i_k++) {
      i65 = b_b.size(0);
      for (m_k = 0; m_k < i65; m_k++) {
        b_b[m_k + (b_b.size(0) * i_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * i_k)]);
      }
    }
  }
  c45.set_size(b_b.size(0), b_b.size(1));
  gc_loop_ub = b_b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i69, mc_loop_ub)

  for (int i62 = 0; i62 < gc_loop_ub; i62++) {
    mc_loop_ub = b_b.size(0);
    for (i69 = 0; i69 < mc_loop_ub; i69++) {
      c45[i69 + (c45.size(0) * i62)] =
          (4.0F * b_b[i69 + (b_b.size(0) * i62)]) -
          (3.0F * (r[i69 + (r.size(0) * i62)] + r1[i69 + (r1.size(0) * i62)]));
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
  pc_loop_ub = r4.size(0);
  for (int i71{0}; i71 < pc_loop_ub; i71++) {
    c45[r4[i71] - 1] = 0.0F;
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for secondDerivCornerMetric.cpp
//
// [EOF]
//
