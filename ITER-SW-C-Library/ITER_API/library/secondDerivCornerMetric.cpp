//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: secondDerivCornerMetric.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "secondDerivCornerMetric.h"
#include "imfilter.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &o_I
//                ::coder::array<float, 2U> &cxy
//                ::coder::array<float, 2U> &c45
//                ::coder::array<float, 2U> &b_Ix
//                ::coder::array<float, 2U> &Iy
//                ::coder::array<float, 2U> &Ixy
//                ::coder::array<float, 2U> &I_45_45
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void b_secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                               ::coder::array<float, 2U> &cxy,
                               ::coder::array<float, 2U> &c45,
                               ::coder::array<float, 2U> &b_Ix,
                               ::coder::array<float, 2U> &Iy,
                               ::coder::array<float, 2U> &Ixy,
                               ::coder::array<float, 2U> &I_45_45)
{
  ::coder::array<float, 2U> I_45_x;
  ::coder::array<float, 2U> I_45_y;
  ::coder::array<float, 2U> b;
  ::coder::array<float, 2U> b_I_45;
  ::coder::array<float, 2U> b_x;
  ::coder::array<float, 2U> r;
  ::coder::array<float, 2U> r1;
  ::coder::array<float, 2U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  int ab_loop_ub;
  int b_end;
  int b_k;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int bb_loop_ub;
  int c_loop_ub;
  int cb_loop_ub;
  int d_loop_ub;
  int e_k;
  int e_loop_ub;
  int eb_loop_ub;
  int end;
  int f_loop_ub;
  int fb_loop_ub;
  int g_k;
  int g_loop_ub;
  int gb_loop_ub;
  int h_loop_ub;
  int hb_loop_ub;
  int i1;
  int i10;
  int i11;
  int i13;
  int i15;
  int i19;
  int i20;
  int i24;
  int i26;
  int i27;
  int i3;
  int i30;
  int i31;
  int i33;
  int i34;
  int i35;
  int i37;
  int i42;
  int i45;
  int i48;
  int i49;
  int i5;
  int i51;
  int i52;
  int i53;
  int i54;
  int i7;
  int i_loop_ub;
  int ib_loop_ub;
  int j_loop_ub;
  int jb_loop_ub;
  int k_k;
  int k_loop_ub;
  int loop_ub;
  int m_k;
  int m_loop_ub;
  int o_k;
  int o_loop_ub;
  int ob_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int pb_loop_ub;
  int q_loop_ub;
  int rb_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int tb_loop_ub;
  int trueCount;
  int u_loop_ub;
  int ub_loop_ub;
  int vb_loop_ub;
  int wb_loop_ub;
  int x_loop_ub;
  int y_loop_ub;
  b_Ix.set_size(o_I.size(0), o_I.size(1));
  loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    c_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    c_loop_ub = o_I.size(0);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      b_Ix[i1 + (b_Ix.size(0) * b_i)] = o_I[i1 + (o_I.size(0) * b_i)];
    }
  }
  d_imfilter(b_Ix);
  Iy.set_size(b_Ix.size(0), b_Ix.size(1));
  b_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    e_loop_ub)

  for (int i2 = 0; i2 < b_loop_ub; i2++) {
    e_loop_ub = b_Ix.size(0);
    for (i3 = 0; i3 < e_loop_ub; i3++) {
      Iy[i3 + (Iy.size(0) * i2)] = b_Ix[i3 + (b_Ix.size(0) * i2)];
    }
  }
  imfilter(Iy);
  b_imfilter(b_Ix);
  Ixy.set_size(b_Ix.size(0), b_Ix.size(1));
  d_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5,        \
                                                                    g_loop_ub)

  for (int i4 = 0; i4 < d_loop_ub; i4++) {
    g_loop_ub = b_Ix.size(0);
    for (i5 = 0; i5 < g_loop_ub; i5++) {
      Ixy[i5 + (Ixy.size(0) * i4)] = b_Ix[i5 + (b_Ix.size(0) * i4)];
    }
  }
  imfilter(Ixy);
  r.set_size(b_Ix.size(0), b_Ix.size(1));
  f_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    i_loop_ub)

  for (int i6 = 0; i6 < f_loop_ub; i6++) {
    i_loop_ub = b_Ix.size(0);
    for (i7 = 0; i7 < i_loop_ub; i7++) {
      r[i7 + (r.size(0) * i6)] = b_Ix[i7 + (b_Ix.size(0) * i6)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  h_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i10,       \
                                                                    k_loop_ub)

  for (int b_i8 = 0; b_i8 < h_loop_ub; b_i8++) {
    k_loop_ub = r.size(0);
    for (i10 = 0; i10 < k_loop_ub; i10++) {
      b_I_45[i10 + (b_I_45.size(0) * b_i8)] =
          r[i10 + (r.size(0) * b_i8)] +
          (Iy[i10 + (Iy.size(0) * b_i8)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  j_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11,       \
                                                                    o_loop_ub)

  for (int i9 = 0; i9 < j_loop_ub; i9++) {
    o_loop_ub = b_I_45.size(0);
    for (i11 = 0; i11 < o_loop_ub; i11++) {
      I_45_x[i11 + (I_45_x.size(0) * i9)] = b_I_45[i11 + (b_I_45.size(0) * i9)];
    }
  }
  b_imfilter(I_45_x);
  I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
  m_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13,       \
                                                                    q_loop_ub)

  for (int i12 = 0; i12 < m_loop_ub; i12++) {
    q_loop_ub = b_I_45.size(0);
    for (i13 = 0; i13 < q_loop_ub; i13++) {
      I_45_y[i13 + (I_45_y.size(0) * i12)] =
          b_I_45[i13 + (b_I_45.size(0) * i12)];
    }
  }
  imfilter(I_45_y);
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  p_loop_ub = I_45_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    t_loop_ub)

  for (int i14 = 0; i14 < p_loop_ub; i14++) {
    t_loop_ub = I_45_x.size(0);
    for (i15 = 0; i15 < t_loop_ub; i15++) {
      I_45_45[i15 + (I_45_45.size(0) * i14)] =
          (I_45_x[i15 + (I_45_x.size(0) * i14)] * 0.707106769F) +
          (I_45_y[i15 + (I_45_y.size(0) * i14)] * -0.707106769F);
    }
  }
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int i18;
    int r_loop_ub;
    int w_loop_ub;
    b.set_size(b_I_45.size(0), b_I_45.size(1));
    r_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19,       \
                                                                    u_loop_ub)

    for (int i16 = 0; i16 < r_loop_ub; i16++) {
      u_loop_ub = r1.size(0);
      for (i19 = 0; i19 < u_loop_ub; i19++) {
        b[i19 + (b.size(0) * i16)] = r1[i19 + (r1.size(0) * i16)];
      }
    }
    i18 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i24)

    for (int k = 0; k < i18; k++) {
      i24 = b.size(0);
      for (b_k = 0; b_k < i24; b_k++) {
        b[b_k + (b.size(0) * k)] = std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b.size(0), b.size(1));
    w_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, bb_loop_ub)

    for (int i22 = 0; i22 < w_loop_ub; i22++) {
      bb_loop_ub = b.size(0);
      for (i27 = 0; i27 < bb_loop_ub; i27++) {
        r1[i27 + (r1.size(0) * i22)] = b[i27 + (b.size(0) * i22)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  s_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i20,       \
                                                                    x_loop_ub)

  for (int i17 = 0; i17 < s_loop_ub; i17++) {
    x_loop_ub = r.size(0);
    for (i20 = 0; i20 < x_loop_ub; i20++) {
      b_x[i20 + (b_x.size(0) * i17)] =
          r[i20 + (r.size(0) * i17)] +
          (Iy[i20 + (Iy.size(0) * i17)] * -0.707106769F);
    }
  }
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int db_loop_ub;
    int i25;
    int v_loop_ub;
    b.set_size(b_x.size(0), b_x.size(1));
    v_loop_ub = b_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i26, ab_loop_ub)

    for (int i21 = 0; i21 < v_loop_ub; i21++) {
      ab_loop_ub = r.size(0);
      for (i26 = 0; i26 < ab_loop_ub; i26++) {
        b[i26 + (b.size(0) * i21)] = r[i26 + (r.size(0) * i21)];
      }
    }
    i25 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_k, i33)

    for (int d_k = 0; d_k < i25; d_k++) {
      i33 = b.size(0);
      for (g_k = 0; g_k < i33; g_k++) {
        b[g_k + (b.size(0) * d_k)] = std::abs(b_x[g_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b.size(0), b.size(1));
    db_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i35, hb_loop_ub)

    for (int i32 = 0; i32 < db_loop_ub; i32++) {
      hb_loop_ub = b.size(0);
      for (i35 = 0; i35 < hb_loop_ub; i35++) {
        r[i35 + (r.size(0) * i32)] = b[i35 + (b.size(0) * i32)];
      }
    }
  }
  b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i23;
    i23 = Ixy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_k, i31)

    for (int c_k = 0; c_k < i23; c_k++) {
      i31 = b.size(0);
      for (e_k = 0; e_k < i31; e_k++) {
        b[e_k + (b.size(0) * c_k)] = std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b.size(0), b.size(1));
  y_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i30, eb_loop_ub)

  for (int i28 = 0; i28 < y_loop_ub; i28++) {
    eb_loop_ub = b.size(0);
    for (i30 = 0; i30 < eb_loop_ub; i30++) {
      r2[i30 + (r2.size(0) * i28)] = 16.0F * b[i30 + (b.size(0) * i28)];
    }
  }
  cb_loop_ub = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i34, gb_loop_ub)

  for (int i29 = 0; i29 < cb_loop_ub; i29++) {
    gb_loop_ub = r1.size(0);
    for (i34 = 0; i34 < gb_loop_ub; i34++) {
      r1[i34 + (r1.size(0) * i29)] =
          6.0F * (r1[i34 + (r1.size(0) * i29)] + r[i34 + (r.size(0) * i29)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  fb_loop_ub = r2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i37, ib_loop_ub)

  for (int i36 = 0; i36 < fb_loop_ub; i36++) {
    ib_loop_ub = r2.size(0);
    for (i37 = 0; i37 < ib_loop_ub; i37++) {
      cxy[i37 + (cxy.size(0) * i36)] =
          r2[i37 + (r2.size(0) * i36)] - r1[i37 + (r1.size(0) * i36)];
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
  jb_loop_ub = r3.size(0);
  for (int i38{0}; i38 < jb_loop_ub; i38++) {
    cxy[r3[i38] - 1] = 0.0F;
  }
  r.set_size(b_Ix.size(0), b_Ix.size(1));
  if ((b_Ix.size(0) != 0) && (b_Ix.size(1) != 0)) {
    int i40;
    int kb_loop_ub;
    int qb_loop_ub;
    b.set_size(b_Ix.size(0), b_Ix.size(1));
    kb_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i42, ob_loop_ub)

    for (int i39 = 0; i39 < kb_loop_ub; i39++) {
      ob_loop_ub = r.size(0);
      for (i42 = 0; i42 < ob_loop_ub; i42++) {
        b[i42 + (b.size(0) * i39)] = r[i42 + (r.size(0) * i39)];
      }
    }
    i40 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, i48)

    for (int h_k = 0; h_k < i40; h_k++) {
      i48 = b.size(0);
      for (k_k = 0; k_k < i48; k_k++) {
        b[k_k + (b.size(0) * h_k)] = std::abs(b_Ix[k_k + (b_Ix.size(0) * h_k)]);
      }
    }
    r.set_size(b.size(0), b.size(1));
    qb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i51, tb_loop_ub)

    for (int i47 = 0; i47 < qb_loop_ub; i47++) {
      tb_loop_ub = b.size(0);
      for (i51 = 0; i51 < tb_loop_ub; i51++) {
        r[i51 + (r.size(0) * i47)] = b[i51 + (b.size(0) * i47)];
      }
    }
  }
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    int i44;
    int mb_loop_ub;
    int sb_loop_ub;
    b.set_size(Iy.size(0), Iy.size(1));
    mb_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i45, rb_loop_ub)

    for (int i41 = 0; i41 < mb_loop_ub; i41++) {
      rb_loop_ub = r1.size(0);
      for (i45 = 0; i45 < rb_loop_ub; i45++) {
        b[i45 + (b.size(0) * i41)] = r1[i45 + (r1.size(0) * i41)];
      }
    }
    i44 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(o_k, i52)

    for (int j_k = 0; j_k < i44; j_k++) {
      i52 = b.size(0);
      for (o_k = 0; o_k < i52; o_k++) {
        b[o_k + (b.size(0) * j_k)] = std::abs(Iy[o_k + (Iy.size(0) * j_k)]);
      }
    }
    r1.set_size(b.size(0), b.size(1));
    sb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i54, vb_loop_ub)

    for (int i50 = 0; i50 < sb_loop_ub; i50++) {
      vb_loop_ub = b.size(0);
      for (i54 = 0; i54 < vb_loop_ub; i54++) {
        r1[i54 + (r1.size(0) * i50)] = b[i54 + (b.size(0) * i50)];
      }
    }
  }
  b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i43;
    i43 = I_45_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(m_k, i49)

    for (int i_k = 0; i_k < i43; i_k++) {
      i49 = b.size(0);
      for (m_k = 0; m_k < i49; m_k++) {
        b[m_k + (b.size(0) * i_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * i_k)]);
      }
    }
  }
  c45.set_size(b.size(0), b.size(1));
  pb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i53, ub_loop_ub)

  for (int i46 = 0; i46 < pb_loop_ub; i46++) {
    ub_loop_ub = b.size(0);
    for (i53 = 0; i53 < ub_loop_ub; i53++) {
      c45[i53 + (c45.size(0) * i46)] =
          (16.0F * b[i53 + (b.size(0) * i46)]) -
          (6.0F * (r[i53 + (r.size(0) * i46)] + r1[i53 + (r1.size(0) * i46)]));
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
  wb_loop_ub = r4.size(0);
  for (int i55{0}; i55 < wb_loop_ub; i55++) {
    c45[r4[i55] - 1] = 0.0F;
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &o_I
//                ::coder::array<float, 2U> &cxy
//                ::coder::array<float, 2U> &c45
//                ::coder::array<float, 2U> &b_Ix
//                ::coder::array<float, 2U> &Iy
//                ::coder::array<float, 2U> &Ixy
//                ::coder::array<float, 2U> &I_45_45
// Return Type  : void
//
void secondDerivCornerMetric(const ::coder::array<float, 2U> &o_I,
                             ::coder::array<float, 2U> &cxy,
                             ::coder::array<float, 2U> &c45,
                             ::coder::array<float, 2U> &b_Ix,
                             ::coder::array<float, 2U> &Iy,
                             ::coder::array<float, 2U> &Ixy,
                             ::coder::array<float, 2U> &I_45_45)
{
  static const double kernel[15][15]{
      {1.9045144150126356E-7, 9.6719222617840546E-7, 3.8253194603479445E-6,
       1.1782813454257772E-5, 2.826550008884209E-5, 5.2806906275779353E-5,
       7.683359526380697E-5, 8.70638696167455E-5, 7.683359526380697E-5,
       5.2806906275779353E-5, 2.826550008884209E-5, 1.1782813454257772E-5,
       3.8253194603479445E-6, 9.6719222617840546E-7, 1.9045144150126356E-7},
      {9.6719222617840546E-7, 4.9118074140369968E-6, 1.9426575170726439E-5,
       5.983806415764425E-5, 0.00014354405374659092, 0.00026817559812550214,
       0.0003901931928827066, 0.00044214681291224477, 0.0003901931928827066,
       0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
       1.9426575170726439E-5, 4.9118074140369968E-6, 9.6719222617840546E-7},
      {3.8253194603479445E-6, 1.9426575170726439E-5, 7.683359526380697E-5,
       0.00023666413469452686, 0.000567727745686802, 0.0010606550658014767,
       0.0015432440146124519, 0.0017487245678627389, 0.0015432440146124519,
       0.0010606550658014767, 0.000567727745686802, 0.00023666413469452686,
       7.683359526380697E-5, 1.9426575170726439E-5, 3.8253194603479445E-6},
      {1.1782813454257772E-5, 5.983806415764425E-5, 0.00023666413469452686,
       0.000728976855220688, 0.0017487245678627389, 0.0032670476045719718,
       0.0047535262158011791, 0.005386450878047711, 0.0047535262158011791,
       0.0032670476045719718, 0.0017487245678627389, 0.000728976855220688,
       0.00023666413469452686, 5.983806415764425E-5, 1.1782813454257772E-5},
      {2.826550008884209E-5, 0.00014354405374659092, 0.000567727745686802,
       0.0017487245678627389, 0.0041949721617992137, 0.0078372397828220912,
       0.011403116598310359, 0.012921423933516035, 0.011403116598310359,
       0.0078372397828220912, 0.0041949721617992137, 0.0017487245678627389,
       0.000567727745686802, 0.00014354405374659092, 2.826550008884209E-5},
      {5.2806906275779353E-5, 0.00026817559812550214, 0.0010606550658014767,
       0.0032670476045719718, 0.0078372397828220912, 0.014641891541684361,
       0.021303826486921609, 0.0241403980280593, 0.021303826486921609,
       0.014641891541684361, 0.0078372397828220912, 0.0032670476045719718,
       0.0010606550658014767, 0.00026817559812550214, 5.2806906275779353E-5},
      {7.683359526380697E-5, 0.0003901931928827066, 0.0015432440146124519,
       0.0047535262158011791, 0.011403116598310359, 0.021303826486921609,
       0.030996884636986775, 0.035124071876292441, 0.030996884636986775,
       0.021303826486921609, 0.011403116598310359, 0.0047535262158011791,
       0.0015432440146124519, 0.0003901931928827066, 7.683359526380697E-5},
      {8.70638696167455E-5, 0.00044214681291224477, 0.0017487245678627389,
       0.005386450878047711, 0.012921423933516035, 0.0241403980280593,
       0.035124071876292441, 0.039800787712028794, 0.035124071876292441,
       0.0241403980280593, 0.012921423933516035, 0.005386450878047711,
       0.0017487245678627389, 0.00044214681291224477, 8.70638696167455E-5},
      {7.683359526380697E-5, 0.0003901931928827066, 0.0015432440146124519,
       0.0047535262158011791, 0.011403116598310359, 0.021303826486921609,
       0.030996884636986775, 0.035124071876292441, 0.030996884636986775,
       0.021303826486921609, 0.011403116598310359, 0.0047535262158011791,
       0.0015432440146124519, 0.0003901931928827066, 7.683359526380697E-5},
      {5.2806906275779353E-5, 0.00026817559812550214, 0.0010606550658014767,
       0.0032670476045719718, 0.0078372397828220912, 0.014641891541684361,
       0.021303826486921609, 0.0241403980280593, 0.021303826486921609,
       0.014641891541684361, 0.0078372397828220912, 0.0032670476045719718,
       0.0010606550658014767, 0.00026817559812550214, 5.2806906275779353E-5},
      {2.826550008884209E-5, 0.00014354405374659092, 0.000567727745686802,
       0.0017487245678627389, 0.0041949721617992137, 0.0078372397828220912,
       0.011403116598310359, 0.012921423933516035, 0.011403116598310359,
       0.0078372397828220912, 0.0041949721617992137, 0.0017487245678627389,
       0.000567727745686802, 0.00014354405374659092, 2.826550008884209E-5},
      {1.1782813454257772E-5, 5.983806415764425E-5, 0.00023666413469452686,
       0.000728976855220688, 0.0017487245678627389, 0.0032670476045719718,
       0.0047535262158011791, 0.005386450878047711, 0.0047535262158011791,
       0.0032670476045719718, 0.0017487245678627389, 0.000728976855220688,
       0.00023666413469452686, 5.983806415764425E-5, 1.1782813454257772E-5},
      {3.8253194603479445E-6, 1.9426575170726439E-5, 7.683359526380697E-5,
       0.00023666413469452686, 0.000567727745686802, 0.0010606550658014767,
       0.0015432440146124519, 0.0017487245678627389, 0.0015432440146124519,
       0.0010606550658014767, 0.000567727745686802, 0.00023666413469452686,
       7.683359526380697E-5, 1.9426575170726439E-5, 3.8253194603479445E-6},
      {9.6719222617840546E-7, 4.9118074140369968E-6, 1.9426575170726439E-5,
       5.983806415764425E-5, 0.00014354405374659092, 0.00026817559812550214,
       0.0003901931928827066, 0.00044214681291224477, 0.0003901931928827066,
       0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
       1.9426575170726439E-5, 4.9118074140369968E-6, 9.6719222617840546E-7},
      {1.9045144150126356E-7, 9.6719222617840546E-7, 3.8253194603479445E-6,
       1.1782813454257772E-5, 2.826550008884209E-5, 5.2806906275779353E-5,
       7.683359526380697E-5, 8.70638696167455E-5, 7.683359526380697E-5,
       5.2806906275779353E-5, 2.826550008884209E-5, 1.1782813454257772E-5,
       3.8253194603479445E-6, 9.6719222617840546E-7, 1.9045144150126356E-7}};
  static const double nonZeroKernel[225]{
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      8.70638696167455E-5,    0.00044214681291224477, 0.0017487245678627389,
      0.005386450878047711,   0.012921423933516035,   0.0241403980280593,
      0.035124071876292441,   0.039800787712028794,   0.035124071876292441,
      0.0241403980280593,     0.012921423933516035,   0.005386450878047711,
      0.0017487245678627389,  0.00044214681291224477, 8.70638696167455E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7};
  ::coder::array<float, 2U> I_45_x;
  ::coder::array<float, 2U> I_45_y;
  ::coder::array<float, 2U> b;
  ::coder::array<float, 2U> b_I_45;
  ::coder::array<float, 2U> b_a;
  ::coder::array<float, 2U> b_x;
  ::coder::array<float, 2U> r;
  ::coder::array<float, 2U> r1;
  ::coder::array<float, 2U> r2;
  ::coder::array<int, 1U> r3;
  ::coder::array<int, 1U> r4;
  double connDimsT[2];
  double finalSize[2];
  double kernelSizeT[2];
  double pad[2];
  double padSizeT[2];
  int ab_loop_ub;
  int b_end;
  int b_k;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int bb_loop_ub;
  int c_loop_ub;
  int cb_loop_ub;
  int d_loop_ub;
  int e_k;
  int e_loop_ub;
  int eb_loop_ub;
  int end;
  int f_loop_ub;
  int fb_loop_ub;
  int g_k;
  int g_loop_ub;
  int gb_loop_ub;
  int h_loop_ub;
  int hb_loop_ub;
  int i1;
  int i12;
  int i13;
  int i15;
  int i17;
  int i21;
  int i22;
  int i26;
  int i28;
  int i29;
  int i32;
  int i33;
  int i35;
  int i36;
  int i37;
  int i39;
  int i4;
  int i44;
  int i47;
  int i5;
  int i50;
  int i51;
  int i53;
  int i54;
  int i55;
  int i56;
  int i7;
  int i9;
  int i_loop_ub;
  int ib_loop_ub;
  int j_loop_ub;
  int jb_loop_ub;
  int k_k;
  int k_loop_ub;
  int m_k;
  int m_loop_ub;
  int o_k;
  int o_loop_ub;
  int ob_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int pb_loop_ub;
  int q_loop_ub;
  int rb_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int tb_loop_ub;
  int trueCount;
  int u_loop_ub;
  int ub_loop_ub;
  int vb_loop_ub;
  int wb_loop_ub;
  int x_loop_ub;
  int y_loop_ub;
  bool conn[15][15];
  finalSize[0] = static_cast<double>(o_I.size(0));
  pad[0] = 7.0;
  finalSize[1] = static_cast<double>(o_I.size(1));
  pad[1] = 7.0;
  if ((o_I.size(0) == 0) || (o_I.size(1) == 0)) {
    int loop_ub;
    b_Ix.set_size(o_I.size(0), o_I.size(1));
    loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    c_loop_ub)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      c_loop_ub = o_I.size(0);
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        b_Ix[i1 + (b_Ix.size(0) * b_i)] = o_I[i1 + (o_I.size(0) * b_i)];
      }
    }
  } else {
    bool tooBig;
    padImage(o_I, pad, b_a);
    tooBig = true;
    if (o_I.size(0) <= 65500) {
      tooBig = false;
    } else if (o_I.size(1) <= 65500) {
      tooBig = false;
    } else {
      /* no actions */
    }
    b_Ix.set_size(o_I.size(0), o_I.size(1));
    if (!tooBig) {
      padSizeT[0] = static_cast<double>(b_a.size(0));
      kernelSizeT[0] = 15.0;
      padSizeT[1] = static_cast<double>(b_a.size(1));
      kernelSizeT[1] = 15.0;
      ippfilter_real32(&b_a[0], &b_Ix[0], &finalSize[0], 2.0, &padSizeT[0],
                       &kernel[0][0], &kernelSizeT[0], true);
    } else {
      padSizeT[0] = static_cast<double>(b_a.size(0));
      padSizeT[1] = static_cast<double>(b_a.size(1));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5)

      for (int i3 = 0; i3 < 15; i3++) {
        for (i5 = 0; i5 < 15; i5++) {
          conn[i3][i5] = true;
        }
      }
      connDimsT[0] = 15.0;
      connDimsT[1] = 15.0;
      imfilter_real32(&b_a[0], &b_Ix[0], 2.0, &finalSize[0], 2.0, &padSizeT[0],
                      &nonZeroKernel[0], 225.0, &conn[0][0], 2.0, &connDimsT[0],
                      &pad[0], 2.0, true, true);
    }
  }
  Iy.set_size(b_Ix.size(0), b_Ix.size(1));
  b_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4,        \
                                                                    e_loop_ub)

  for (int i2 = 0; i2 < b_loop_ub; i2++) {
    e_loop_ub = b_Ix.size(0);
    for (i4 = 0; i4 < e_loop_ub; i4++) {
      Iy[i4 + (Iy.size(0) * i2)] = b_Ix[i4 + (b_Ix.size(0) * i2)];
    }
  }
  imfilter(Iy);
  b_imfilter(b_Ix);
  Ixy.set_size(b_Ix.size(0), b_Ix.size(1));
  d_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    g_loop_ub)

  for (int i6 = 0; i6 < d_loop_ub; i6++) {
    g_loop_ub = b_Ix.size(0);
    for (i7 = 0; i7 < g_loop_ub; i7++) {
      Ixy[i7 + (Ixy.size(0) * i6)] = b_Ix[i7 + (b_Ix.size(0) * i6)];
    }
  }
  imfilter(Ixy);
  r.set_size(b_Ix.size(0), b_Ix.size(1));
  f_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    i_loop_ub)

  for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
    i_loop_ub = b_Ix.size(0);
    for (i9 = 0; i9 < i_loop_ub; i9++) {
      r[i9 + (r.size(0) * b_i8)] =
          b_Ix[i9 + (b_Ix.size(0) * b_i8)] * 0.707106769F;
    }
  }
  b_I_45.set_size(r.size(0), r.size(1));
  h_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12,       \
                                                                    k_loop_ub)

  for (int i10 = 0; i10 < h_loop_ub; i10++) {
    k_loop_ub = r.size(0);
    for (i12 = 0; i12 < k_loop_ub; i12++) {
      b_I_45[i12 + (b_I_45.size(0) * i10)] =
          r[i12 + (r.size(0) * i10)] +
          (Iy[i12 + (Iy.size(0) * i10)] * 0.707106769F);
    }
  }
  I_45_x.set_size(b_I_45.size(0), b_I_45.size(1));
  j_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13,       \
                                                                    o_loop_ub)

  for (int i11 = 0; i11 < j_loop_ub; i11++) {
    o_loop_ub = b_I_45.size(0);
    for (i13 = 0; i13 < o_loop_ub; i13++) {
      I_45_x[i13 + (I_45_x.size(0) * i11)] =
          b_I_45[i13 + (b_I_45.size(0) * i11)];
    }
  }
  b_imfilter(I_45_x);
  I_45_y.set_size(b_I_45.size(0), b_I_45.size(1));
  m_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    q_loop_ub)

  for (int i14 = 0; i14 < m_loop_ub; i14++) {
    q_loop_ub = b_I_45.size(0);
    for (i15 = 0; i15 < q_loop_ub; i15++) {
      I_45_y[i15 + (I_45_y.size(0) * i14)] =
          b_I_45[i15 + (b_I_45.size(0) * i14)];
    }
  }
  imfilter(I_45_y);
  I_45_45.set_size(I_45_x.size(0), I_45_x.size(1));
  p_loop_ub = I_45_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i17,       \
                                                                    t_loop_ub)

  for (int i16 = 0; i16 < p_loop_ub; i16++) {
    t_loop_ub = I_45_x.size(0);
    for (i17 = 0; i17 < t_loop_ub; i17++) {
      I_45_45[i17 + (I_45_45.size(0) * i16)] =
          (I_45_x[i17 + (I_45_x.size(0) * i16)] * 0.707106769F) +
          (I_45_y[i17 + (I_45_y.size(0) * i16)] * -0.707106769F);
    }
  }
  r1.set_size(b_I_45.size(0), b_I_45.size(1));
  if ((b_I_45.size(0) != 0) && (b_I_45.size(1) != 0)) {
    int i20;
    int r_loop_ub;
    int w_loop_ub;
    b.set_size(b_I_45.size(0), b_I_45.size(1));
    r_loop_ub = b_I_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i21,       \
                                                                    u_loop_ub)

    for (int i18 = 0; i18 < r_loop_ub; i18++) {
      u_loop_ub = r1.size(0);
      for (i21 = 0; i21 < u_loop_ub; i21++) {
        b[i21 + (b.size(0) * i18)] = r1[i21 + (r1.size(0) * i18)];
      }
    }
    i20 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i26)

    for (int k = 0; k < i20; k++) {
      i26 = b.size(0);
      for (b_k = 0; b_k < i26; b_k++) {
        b[b_k + (b.size(0) * k)] = std::abs(b_I_45[b_k + (b_I_45.size(0) * k)]);
      }
    }
    r1.set_size(b.size(0), b.size(1));
    w_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i29, bb_loop_ub)

    for (int i24 = 0; i24 < w_loop_ub; i24++) {
      bb_loop_ub = b.size(0);
      for (i29 = 0; i29 < bb_loop_ub; i29++) {
        r1[i29 + (r1.size(0) * i24)] = b[i29 + (b.size(0) * i24)];
      }
    }
  }
  b_x.set_size(r.size(0), r.size(1));
  s_loop_ub = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i22,       \
                                                                    x_loop_ub)

  for (int i19 = 0; i19 < s_loop_ub; i19++) {
    x_loop_ub = r.size(0);
    for (i22 = 0; i22 < x_loop_ub; i22++) {
      b_x[i22 + (b_x.size(0) * i19)] =
          r[i22 + (r.size(0) * i19)] +
          (Iy[i22 + (Iy.size(0) * i19)] * -0.707106769F);
    }
  }
  r.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    int db_loop_ub;
    int i27;
    int v_loop_ub;
    b.set_size(b_x.size(0), b_x.size(1));
    v_loop_ub = b_x.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i28, ab_loop_ub)

    for (int i23 = 0; i23 < v_loop_ub; i23++) {
      ab_loop_ub = r.size(0);
      for (i28 = 0; i28 < ab_loop_ub; i28++) {
        b[i28 + (b.size(0) * i23)] = r[i28 + (r.size(0) * i23)];
      }
    }
    i27 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_k, i35)

    for (int d_k = 0; d_k < i27; d_k++) {
      i35 = b.size(0);
      for (g_k = 0; g_k < i35; g_k++) {
        b[g_k + (b.size(0) * d_k)] = std::abs(b_x[g_k + (b_x.size(0) * d_k)]);
      }
    }
    r.set_size(b.size(0), b.size(1));
    db_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i37, hb_loop_ub)

    for (int i34 = 0; i34 < db_loop_ub; i34++) {
      hb_loop_ub = b.size(0);
      for (i37 = 0; i37 < hb_loop_ub; i37++) {
        r[i37 + (r.size(0) * i34)] = b[i37 + (b.size(0) * i34)];
      }
    }
  }
  b.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    int i25;
    i25 = Ixy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_k, i33)

    for (int c_k = 0; c_k < i25; c_k++) {
      i33 = b.size(0);
      for (e_k = 0; e_k < i33; e_k++) {
        b[e_k + (b.size(0) * c_k)] = std::abs(Ixy[e_k + (Ixy.size(0) * c_k)]);
      }
    }
  }
  r2.set_size(b.size(0), b.size(1));
  y_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i32, eb_loop_ub)

  for (int i30 = 0; i30 < y_loop_ub; i30++) {
    eb_loop_ub = b.size(0);
    for (i32 = 0; i32 < eb_loop_ub; i32++) {
      r2[i32 + (r2.size(0) * i30)] = 4.0F * b[i32 + (b.size(0) * i30)];
    }
  }
  cb_loop_ub = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i36, gb_loop_ub)

  for (int i31 = 0; i31 < cb_loop_ub; i31++) {
    gb_loop_ub = r1.size(0);
    for (i36 = 0; i36 < gb_loop_ub; i36++) {
      r1[i36 + (r1.size(0) * i31)] =
          3.0F * (r1[i36 + (r1.size(0) * i31)] + r[i36 + (r.size(0) * i31)]);
    }
  }
  cxy.set_size(r2.size(0), r2.size(1));
  fb_loop_ub = r2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i39, ib_loop_ub)

  for (int i38 = 0; i38 < fb_loop_ub; i38++) {
    ib_loop_ub = r2.size(0);
    for (i39 = 0; i39 < ib_loop_ub; i39++) {
      cxy[i39 + (cxy.size(0) * i38)] =
          r2[i39 + (r2.size(0) * i38)] - r1[i39 + (r1.size(0) * i38)];
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
  jb_loop_ub = r3.size(0);
  for (int i40{0}; i40 < jb_loop_ub; i40++) {
    cxy[r3[i40] - 1] = 0.0F;
  }
  r.set_size(b_Ix.size(0), b_Ix.size(1));
  if ((b_Ix.size(0) != 0) && (b_Ix.size(1) != 0)) {
    int i42;
    int kb_loop_ub;
    int qb_loop_ub;
    b.set_size(b_Ix.size(0), b_Ix.size(1));
    kb_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i44, ob_loop_ub)

    for (int i41 = 0; i41 < kb_loop_ub; i41++) {
      ob_loop_ub = r.size(0);
      for (i44 = 0; i44 < ob_loop_ub; i44++) {
        b[i44 + (b.size(0) * i41)] = r[i44 + (r.size(0) * i41)];
      }
    }
    i42 = r.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, i50)

    for (int h_k = 0; h_k < i42; h_k++) {
      i50 = b.size(0);
      for (k_k = 0; k_k < i50; k_k++) {
        b[k_k + (b.size(0) * h_k)] = std::abs(b_Ix[k_k + (b_Ix.size(0) * h_k)]);
      }
    }
    r.set_size(b.size(0), b.size(1));
    qb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i53, tb_loop_ub)

    for (int i49 = 0; i49 < qb_loop_ub; i49++) {
      tb_loop_ub = b.size(0);
      for (i53 = 0; i53 < tb_loop_ub; i53++) {
        r[i53 + (r.size(0) * i49)] = b[i53 + (b.size(0) * i49)];
      }
    }
  }
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    int i46;
    int mb_loop_ub;
    int sb_loop_ub;
    b.set_size(Iy.size(0), Iy.size(1));
    mb_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i47, rb_loop_ub)

    for (int i43 = 0; i43 < mb_loop_ub; i43++) {
      rb_loop_ub = r1.size(0);
      for (i47 = 0; i47 < rb_loop_ub; i47++) {
        b[i47 + (b.size(0) * i43)] = r1[i47 + (r1.size(0) * i43)];
      }
    }
    i46 = r1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(o_k, i54)

    for (int j_k = 0; j_k < i46; j_k++) {
      i54 = b.size(0);
      for (o_k = 0; o_k < i54; o_k++) {
        b[o_k + (b.size(0) * j_k)] = std::abs(Iy[o_k + (Iy.size(0) * j_k)]);
      }
    }
    r1.set_size(b.size(0), b.size(1));
    sb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i56, vb_loop_ub)

    for (int i52 = 0; i52 < sb_loop_ub; i52++) {
      vb_loop_ub = b.size(0);
      for (i56 = 0; i56 < vb_loop_ub; i56++) {
        r1[i56 + (r1.size(0) * i52)] = b[i56 + (b.size(0) * i52)];
      }
    }
  }
  b.set_size(I_45_45.size(0), I_45_45.size(1));
  if ((I_45_45.size(0) != 0) && (I_45_45.size(1) != 0)) {
    int i45;
    i45 = I_45_45.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(m_k, i51)

    for (int i_k = 0; i_k < i45; i_k++) {
      i51 = b.size(0);
      for (m_k = 0; m_k < i51; m_k++) {
        b[m_k + (b.size(0) * i_k)] =
            std::abs(I_45_45[m_k + (I_45_45.size(0) * i_k)]);
      }
    }
  }
  c45.set_size(b.size(0), b.size(1));
  pb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i55, ub_loop_ub)

  for (int i48 = 0; i48 < pb_loop_ub; i48++) {
    ub_loop_ub = b.size(0);
    for (i55 = 0; i55 < ub_loop_ub; i55++) {
      c45[i55 + (c45.size(0) * i48)] =
          (4.0F * b[i55 + (b.size(0) * i48)]) -
          (3.0F * (r[i55 + (r.size(0) * i48)] + r1[i55 + (r1.size(0) * i48)]));
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
  wb_loop_ub = r4.size(0);
  for (int i57{0}; i57 < wb_loop_ub; i57++) {
    c45[r4[i57] - 1] = 0.0F;
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for secondDerivCornerMetric.cpp
//
// [EOF]
//
