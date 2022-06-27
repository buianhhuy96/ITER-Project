//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "ITER_API_rtwutil.h"
#include "conv2AXPYValidCMP.h"
#include "detectCheckerboard.h"
#include "find_peaks.h"
#include "imfilter.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "secondDerivCornerMetric.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<double, 2U> &b_imagePoints
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
void b_detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<double, 2U> &b_imagePoints,
                                double boardSize[2])
{
  vision::internal::calibration::checkerboard::b_Checkerboard b_lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard *board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *board45;
  vision::internal::calibration::checkerboard::b_Checkerboard *d_board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *d_board45;
  array<double, 2U> b;
  array<double, 2U> b_points;
  array<double, 2U> b_x;
  array<double, 2U> c_a;
  array<double, 2U> y;
  array<double, 1U> s;
  array<float, 2U> I_45_45;
  array<float, 2U> Ix;
  array<float, 2U> Ix2;
  array<float, 2U> IxIy;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> b_Ix2;
  array<float, 2U> b_Iy2;
  array<float, 2U> b_a;
  array<float, 2U> c45;
  array<float, 2U> cxy;
  array<float, 2U> p_I;
  array<float, 2U> points0;
  array<float, 2U> points45;
  array<float, 1U> b_c45;
  array<float, 1U> b_cxy;
  array<int, 1U> r;
  array<int, 1U> r1;
  array<bool, 1U> zeroIdx;
  double b_board0[2];
  double b_board45[2];
  double pad[2];
  int b_i8;
  int b_k;
  int b_loop_ub;
  int b_siz;
  int b_y;
  int bc_loop_ub;
  int c_board0;
  int c_board45;
  int d_k;
  int d_loop_ub;
  int g_loop_ub;
  int g_x;
  int h_k;
  int hb_loop_ub;
  int i1;
  int i12;
  int i13;
  int i16;
  int i23;
  int i27;
  int i28;
  int i3;
  int i37;
  int i41;
  int i49;
  int i53;
  int i54;
  int i59;
  int i60;
  int i61;
  int i62;
  int i65;
  int i66;
  int i69;
  int i7;
  int i75;
  int i78;
  int i9;
  int i94;
  int i96;
  int i_loop_ub;
  int ic_loop_ub;
  int j_loop_ub;
  int k_N;
  int k_k;
  int k_loop_ub;
  int kc_loop_ub;
  int loop_ub;
  int m_N;
  int mc_loop_ub;
  int o_N;
  int o_loop_ub;
  int oc_loop_ub;
  int p_N;
  int p_loop_ub;
  int pb_loop_ub;
  int q_loop_ub;
  int r_N;
  int rc_loop_ub;
  int s_loop_ub;
  int siz;
  int siz_idx_0;
  int t_N;
  int t_loop_ub;
  int u_loop_ub;
  int uc_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int wb_loop_ub;
  int wc_loop_ub;
  int x_loop_ub;
  bool guard1{false};
  bool guard2{false};
  p_I.set_size(o_I.size(0), o_I.size(1));
  loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = o_I.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      p_I[i1 + (p_I.size(0) * b_i)] =
          (static_cast<float>(o_I[i1 + (o_I.size(0) * b_i)])) / 255.0F;
    }
  }
  vision::internal::calibration::checkerboard::secondDerivCornerMetric(
      p_I, cxy, c45, Ix, Iy, Ixy, I_45_45);
  Ix2.set_size(Ix.size(0), Ix.size(1));
  k_N = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, o_N)

  for (int k = 0; k < k_N; k++) {
    o_N = Ix2.size(0);
    for (b_k = 0; b_k < o_N; b_k++) {
      Ix2[b_k + (Ix2.size(0) * k)] =
          rt_powf_snf(Ix[b_k + (Ix.size(0) * k)], 2.0F);
    }
  }
  Iy2.set_size(Iy.size(0), Iy.size(1));
  m_N = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_k, p_N)

  for (int c_k = 0; c_k < m_N; c_k++) {
    p_N = Iy2.size(0);
    for (d_k = 0; d_k < p_N; d_k++) {
      Iy2[d_k + (Iy2.size(0) * c_k)] =
          rt_powf_snf(Iy[d_k + (Iy.size(0) * c_k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
    int c_loop_ub;
    int f_loop_ub;
    padImage_outSize(Ix2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    c_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    g_loop_ub)

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      g_loop_ub = b_a.size(0);
      for (i3 = 0; i3 < g_loop_ub; i3++) {
        c_a[i3 + (c_a.size(0) * i2)] =
            static_cast<double>(b_a[i3 + (b_a.size(0) * i2)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    f_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    k_loop_ub)

    for (int i6 = 0; i6 < f_loop_ub; i6++) {
      k_loop_ub = b.size(0);
      for (i9 = 0; i9 < k_loop_ub; i9++) {
        Ix2[i9 + (Ix2.size(0) * i6)] =
            static_cast<float>(b[i9 + (b.size(0) * i6)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    int e_loop_ub;
    int h_loop_ub;
    padImage_outSize(Iy2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    e_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    i_loop_ub)

    for (int i5 = 0; i5 < e_loop_ub; i5++) {
      i_loop_ub = b_a.size(0);
      for (i7 = 0; i7 < i_loop_ub; i7++) {
        c_a[i7 + (c_a.size(0) * i5)] =
            static_cast<double>(b_a[i7 + (b_a.size(0) * i5)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    h_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12,       \
                                                                    p_loop_ub)

    for (int i10 = 0; i10 < h_loop_ub; i10++) {
      p_loop_ub = b.size(0);
      for (i12 = 0; i12 < p_loop_ub; i12++) {
        Iy2[i12 + (Iy2.size(0) * i10)] =
            static_cast<float>(b[i12 + (b.size(0) * i10)]);
      }
    }
  }
  IxIy.set_size(Ix.size(0), Ix.size(1));
  d_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    j_loop_ub)

  for (int i4 = 0; i4 < d_loop_ub; i4++) {
    j_loop_ub = Ix.size(0);
    for (b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
      IxIy[b_i8 + (IxIy.size(0) * i4)] =
          Ix[b_i8 + (Ix.size(0) * i4)] * Iy[b_i8 + (Iy.size(0) * i4)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
    int m_loop_ub;
    int r_loop_ub;
    padImage_outSize(IxIy, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    m_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13,       \
                                                                    s_loop_ub)

    for (int i11 = 0; i11 < m_loop_ub; i11++) {
      s_loop_ub = b_a.size(0);
      for (i13 = 0; i13 < s_loop_ub; i13++) {
        c_a[i13 + (c_a.size(0) * i11)] =
            static_cast<double>(b_a[i13 + (b_a.size(0) * i11)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    IxIy.set_size(b.size(0), b.size(1));
    r_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i16,       \
                                                                    u_loop_ub)

    for (int i15 = 0; i15 < r_loop_ub; i15++) {
      u_loop_ub = b.size(0);
      for (i16 = 0; i16 < u_loop_ub; i16++) {
        IxIy[i16 + (IxIy.size(0) * i15)] =
            static_cast<float>(b[i16 + (b.size(0) * i15)]);
      }
    }
  }
  vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  siz = cxy.size(0);
  o_loop_ub = points0.size(0);
  r.set_size(points0.size(0));
  q_loop_ub = points0.size(0);
  if ((static_cast<int>(points0.size(0) < 4)) != 0) {
    for (int i14{0}; i14 < o_loop_ub; i14++) {
      r[i14] = (static_cast<int>(points0[i14 + points0.size(0)])) +
               (siz_idx_0 * ((static_cast<int>(points0[i14])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < q_loop_ub; i14++) {
      r[i14] = (static_cast<int>(points0[i14 + points0.size(0)])) +
               (siz * ((static_cast<int>(points0[i14])) - 1));
    }
  }
  b_cxy.set_size(r.size(0));
  t_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i17{0}; i17 < t_loop_ub; i17++) {
      b_cxy[i17] = cxy[r[i17] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i17 = 0; i17 < t_loop_ub; i17++) {
      b_cxy[i17] = cxy[r[i17] - 1];
    }
  }
  board0 = vision::internal::calibration::checkerboard::b_growCheckerboard(
      points0, b_cxy, Ix2, Iy2, IxIy, 0.0, &lobj_0[0]);
  b_imagePoints.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(c45, points45);
  siz_idx_0 = c45.size(0);
  b_siz = c45.size(0);
  v_loop_ub = points45.size(0);
  r.set_size(points45.size(0));
  w_loop_ub = points45.size(0);
  if ((static_cast<int>(points45.size(0) < 4)) != 0) {
    for (int i18{0}; i18 < v_loop_ub; i18++) {
      r[i18] = (static_cast<int>(points45[i18 + points45.size(0)])) +
               (siz_idx_0 * ((static_cast<int>(points45[i18])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < w_loop_ub; i18++) {
      r[i18] = (static_cast<int>(points45[i18 + points45.size(0)])) +
               (b_siz * ((static_cast<int>(points45[i18])) - 1));
    }
  }
  b_c45.set_size(r.size(0));
  x_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i19{0}; i19 < x_loop_ub; i19++) {
      b_c45[i19] = c45[r[i19] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < x_loop_ub; i19++) {
      b_c45[i19] = c45[r[i19] - 1];
    }
  }
  board45 = vision::internal::calibration::checkerboard::b_growCheckerboard(
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
        int h_n;
        int i24;
        int i34;
        int i_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int i20{0}; i20 < c_board0; i20++) {
          s[i20] = board0->BoardIdx[i20];
        }
        h_n = 0;
        i24 = s.size(0);
        for (int e_k{0}; e_k < i24; e_k++) {
          if (s[e_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i30{0}; i30 < c_board45; i30++) {
          s[i30] = board45->BoardIdx[i30];
        }
        i_n = 0;
        i34 = s.size(0);
        for (int i_k{0}; i_k < i34; i_k++) {
          if (s[i_k] != 0.0) {
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
    double numPoints;
    int dc_loop_ub;
    int eb_loop_ub;
    int fb_loop_ub;
    int kb_loop_ub;
    int loop_ub_tmp;
    int qb_loop_ub;
    int sb_loop_ub;
    int y_loop_ub;
    int yb_loop_ub;
    board0 = vision::internal::calibration::checkerboard::orient(board0, p_I);
    numPoints = (static_cast<double>(board0->BoardCoords.size(0))) *
                (static_cast<double>(board0->BoardCoords.size(1)));
    loop_ub_tmp = static_cast<int>(numPoints);
    b_points.set_size(loop_ub_tmp, 2);
    y_loop_ub = static_cast<int>(numPoints);
    if ((static_cast<int>(((static_cast<int>(numPoints)) * 2) < 4)) != 0) {
      for (int i21{0}; i21 < 2; i21++) {
        for (i23 = 0; i23 < loop_ub_tmp; i23++) {
          b_points[i23 + (b_points.size(0) * i21)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i23)

      for (int i21 = 0; i21 < 2; i21++) {
        for (i23 = 0; i23 < y_loop_ub; i23++) {
          b_points[i23 + (b_points.size(0) * i21)] = 0.0;
        }
      }
    }
    eb_loop_ub = board0->BoardCoords.size(0);
    fb_loop_ub = board0->BoardCoords.size(1);
    b_x.set_size(fb_loop_ub, eb_loop_ub);
    for (int i29{0}; i29 < eb_loop_ub; i29++) {
      for (int i31{0}; i31 < fb_loop_ub; i31++) {
        b_x[i31 + (b_x.size(0) * i29)] =
            board0->BoardCoords[i29 + (board0->BoardCoords.size(0) * i31)];
      }
    }
    g_x = b_x.size(0) * b_x.size(1);
    kb_loop_ub = g_x;
    if ((static_cast<int>(g_x < 4)) != 0) {
      for (int i36{0}; i36 < g_x; i36++) {
        b_points[i36] = b_x[i36];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i36 = 0; i36 < kb_loop_ub; i36++) {
        b_points[i36] = b_x[i36];
      }
    }
    qb_loop_ub = board0->BoardCoords.size(0);
    sb_loop_ub = board0->BoardCoords.size(1);
    y.set_size(sb_loop_ub, qb_loop_ub);
    for (int i42{0}; i42 < qb_loop_ub; i42++) {
      for (int i44{0}; i44 < sb_loop_ub; i44++) {
        y[i44 + (y.size(0) * i42)] =
            board0->BoardCoords[(i42 + (board0->BoardCoords.size(0) * i44)) +
                                (board0->BoardCoords.size(0) *
                                 board0->BoardCoords.size(1))];
      }
    }
    b_y = y.size(0) * y.size(1);
    yb_loop_ub = b_y;
    if ((static_cast<int>(b_y < 4)) != 0) {
      for (int i48{0}; i48 < b_y; i48++) {
        b_points[i48 + b_points.size(0)] = y[i48];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i48 = 0; i48 < yb_loop_ub; i48++) {
        b_points[i48 + b_points.size(0)] = y[i48];
      }
    }
    boardSize[0] = (static_cast<double>(board0->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(board0->BoardCoords.size(0))) + 1.0;
    b_imagePoints.set_size(b_points.size(0), 2);
    dc_loop_ub = b_points.size(0);
    if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
      for (int i52{0}; i52 < 2; i52++) {
        for (i54 = 0; i54 < dc_loop_ub; i54++) {
          b_imagePoints[i54 + (b_imagePoints.size(0) * i52)] =
              b_points[i54 + (b_points.size(0) * i52)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i54)

      for (int i52 = 0; i52 < 2; i52++) {
        for (i54 = 0; i54 < dc_loop_ub; i54++) {
          b_imagePoints[i54 + (b_imagePoints.size(0) * i52)] =
              b_points[i54 + (b_points.size(0) * i52)];
        }
      }
    }
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, b_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    double b_numPoints;
    int ac_loop_ub;
    int b_loop_ub_tmp;
    int cb_loop_ub;
    int ec_loop_ub;
    int gb_loop_ub;
    int ib_loop_ub;
    int mb_loop_ub;
    int tb_loop_ub;
    int vb_loop_ub;
    board45 = vision::internal::calibration::checkerboard::orient(board45, p_I);
    b_numPoints = (static_cast<double>(board45->BoardCoords.size(0))) *
                  (static_cast<double>(board45->BoardCoords.size(1)));
    b_loop_ub_tmp = static_cast<int>(b_numPoints);
    b_points.set_size(b_loop_ub_tmp, 2);
    cb_loop_ub = static_cast<int>(b_numPoints);
    if ((static_cast<int>(((static_cast<int>(b_numPoints)) * 2) < 4)) != 0) {
      for (int i25{0}; i25 < 2; i25++) {
        for (i28 = 0; i28 < b_loop_ub_tmp; i28++) {
          b_points[i28 + (b_points.size(0) * i25)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i28)

      for (int i25 = 0; i25 < 2; i25++) {
        for (i28 = 0; i28 < cb_loop_ub; i28++) {
          b_points[i28 + (b_points.size(0) * i25)] = 0.0;
        }
      }
    }
    gb_loop_ub = board45->BoardCoords.size(0);
    ib_loop_ub = board45->BoardCoords.size(1);
    b_x.set_size(ib_loop_ub, gb_loop_ub);
    for (int i33{0}; i33 < gb_loop_ub; i33++) {
      for (int i35{0}; i35 < ib_loop_ub; i35++) {
        b_x[i35 + (b_x.size(0) * i33)] =
            board45->BoardCoords[i33 + (board45->BoardCoords.size(0) * i35)];
      }
    }
    g_x = b_x.size(0) * b_x.size(1);
    mb_loop_ub = g_x;
    if ((static_cast<int>(g_x < 4)) != 0) {
      for (int i39{0}; i39 < g_x; i39++) {
        b_points[i39] = b_x[i39];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i39 = 0; i39 < mb_loop_ub; i39++) {
        b_points[i39] = b_x[i39];
      }
    }
    tb_loop_ub = board45->BoardCoords.size(0);
    vb_loop_ub = board45->BoardCoords.size(1);
    y.set_size(vb_loop_ub, tb_loop_ub);
    for (int i45{0}; i45 < tb_loop_ub; i45++) {
      for (int i47{0}; i47 < vb_loop_ub; i47++) {
        y[i47 + (y.size(0) * i45)] =
            board45->BoardCoords[(i45 + (board45->BoardCoords.size(0) * i47)) +
                                 (board45->BoardCoords.size(0) *
                                  board45->BoardCoords.size(1))];
      }
    }
    b_y = y.size(0) * y.size(1);
    ac_loop_ub = b_y;
    if ((static_cast<int>(b_y < 4)) != 0) {
      for (int i50{0}; i50 < b_y; i50++) {
        b_points[i50 + b_points.size(0)] = y[i50];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i50 = 0; i50 < ac_loop_ub; i50++) {
        b_points[i50 + b_points.size(0)] = y[i50];
      }
    }
    boardSize[0] = (static_cast<double>(board45->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(board45->BoardCoords.size(0))) + 1.0;
    b_imagePoints.set_size(b_points.size(0), 2);
    ec_loop_ub = b_points.size(0);
    if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
      for (int i57{0}; i57 < 2; i57++) {
        for (i59 = 0; i59 < ec_loop_ub; i59++) {
          b_imagePoints[i59 + (b_imagePoints.size(0) * i57)] =
              b_points[i59 + (b_points.size(0) * i57)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i59)

      for (int i57 = 0; i57 < 2; i57++) {
        for (i59 = 0; i59 < ec_loop_ub; i59++) {
          b_imagePoints[i59 + (b_imagePoints.size(0) * i57)] =
              b_points[i59 + (b_points.size(0) * i57)];
        }
      }
    }
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_45, b_imagePoints);
  }
  if ((b_imagePoints.size(0) == 0) || (b_imagePoints.size(1) == 0)) {
    int ad_loop_ub;
    int bb_loop_ub;
    int c_siz;
    int d_siz;
    int fc_loop_ub;
    int jb_loop_ub;
    int ob_loop_ub;
    int q_N;
    int qc_loop_ub;
    int s_N;
    int sc_loop_ub;
    int vc_loop_ub;
    int xb_loop_ub;
    int xc_loop_ub;
    int yc_loop_ub;
    vision::internal::calibration::checkerboard::b_secondDerivCornerMetric(
        p_I, cxy, c45, Ix, Iy, Ixy, I_45_45);
    b_Ix2.set_size(Ix.size(0), Ix.size(1));
    Ix2.set_size(Ix.size(0), Ix.size(1));
    bb_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, hb_loop_ub)

    for (int i22 = 0; i22 < bb_loop_ub; i22++) {
      hb_loop_ub = b_Ix2.size(0);
      for (i27 = 0; i27 < hb_loop_ub; i27++) {
        Ix2[i27 + (Ix2.size(0) * i22)] = b_Ix2[i27 + (b_Ix2.size(0) * i22)];
      }
    }
    q_N = b_Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(h_k, r_N)

    for (int g_k = 0; g_k < q_N; g_k++) {
      r_N = Ix2.size(0);
      for (h_k = 0; h_k < r_N; h_k++) {
        Ix2[h_k + (Ix2.size(0) * g_k)] =
            rt_powf_snf(Ix[h_k + (Ix.size(0) * g_k)], 2.0F);
      }
    }
    b_Ix2.set_size(Ix2.size(0), Ix2.size(1));
    jb_loop_ub = Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i37, pb_loop_ub)

    for (int i32 = 0; i32 < jb_loop_ub; i32++) {
      pb_loop_ub = Ix2.size(0);
      for (i37 = 0; i37 < pb_loop_ub; i37++) {
        b_Ix2[i37 + (b_Ix2.size(0) * i32)] = Ix2[i37 + (Ix2.size(0) * i32)];
      }
    }
    b_Iy2.set_size(Iy.size(0), Iy.size(1));
    Iy2.set_size(Iy.size(0), Iy.size(1));
    ob_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i41, wb_loop_ub)

    for (int i38 = 0; i38 < ob_loop_ub; i38++) {
      wb_loop_ub = b_Iy2.size(0);
      for (i41 = 0; i41 < wb_loop_ub; i41++) {
        Iy2[i41 + (Iy2.size(0) * i38)] = b_Iy2[i41 + (b_Iy2.size(0) * i38)];
      }
    }
    s_N = b_Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, t_N)

    for (int j_k = 0; j_k < s_N; j_k++) {
      t_N = Iy2.size(0);
      for (k_k = 0; k_k < t_N; k_k++) {
        Iy2[k_k + (Iy2.size(0) * j_k)] =
            rt_powf_snf(Iy[k_k + (Iy.size(0) * j_k)], 2.0F);
      }
    }
    b_Iy2.set_size(Iy2.size(0), Iy2.size(1));
    xb_loop_ub = Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i49, bc_loop_ub)

    for (int i46 = 0; i46 < xb_loop_ub; i46++) {
      bc_loop_ub = Iy2.size(0);
      for (i49 = 0; i49 < bc_loop_ub; i49++) {
        b_Iy2[i49 + (b_Iy2.size(0) * i46)] = Iy2[i49 + (Iy2.size(0) * i46)];
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
      int cc_loop_ub;
      int hc_loop_ub;
      padImage_outSize(Ix2, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      cc_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i53, ic_loop_ub)

      for (int i51 = 0; i51 < cc_loop_ub; i51++) {
        ic_loop_ub = b_a.size(0);
        for (i53 = 0; i53 < ic_loop_ub; i53++) {
          c_a[i53 + (c_a.size(0) * i51)] =
              static_cast<double>(b_a[i53 + (b_a.size(0) * i51)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      b_Ix2.set_size(b.size(0), b.size(1));
      hc_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i62, oc_loop_ub)

      for (int i58 = 0; i58 < hc_loop_ub; i58++) {
        oc_loop_ub = b.size(0);
        for (i62 = 0; i62 < oc_loop_ub; i62++) {
          b_Ix2[i62 + (b_Ix2.size(0) * i58)] =
              static_cast<float>(b[i62 + (b.size(0) * i58)]);
        }
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
      int gc_loop_ub;
      int jc_loop_ub;
      padImage_outSize(Iy2, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      gc_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i60, kc_loop_ub)

      for (int i56 = 0; i56 < gc_loop_ub; i56++) {
        kc_loop_ub = b_a.size(0);
        for (i60 = 0; i60 < kc_loop_ub; i60++) {
          c_a[i60 + (c_a.size(0) * i56)] =
              static_cast<double>(b_a[i60 + (b_a.size(0) * i56)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      b_Iy2.set_size(b.size(0), b.size(1));
      jc_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i65, rc_loop_ub)

      for (int i63 = 0; i63 < jc_loop_ub; i63++) {
        rc_loop_ub = b.size(0);
        for (i65 = 0; i65 < rc_loop_ub; i65++) {
          b_Iy2[i65 + (b_Iy2.size(0) * i63)] =
              static_cast<float>(b[i65 + (b.size(0) * i63)]);
        }
      }
    }
    IxIy.set_size(Ix.size(0), Ix.size(1));
    fc_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i61, mc_loop_ub)

    for (int i55 = 0; i55 < fc_loop_ub; i55++) {
      mc_loop_ub = Ix.size(0);
      for (i61 = 0; i61 < mc_loop_ub; i61++) {
        IxIy[i61 + (IxIy.size(0) * i55)] =
            Ix[i61 + (Ix.size(0) * i55)] * Iy[i61 + (Iy.size(0) * i55)];
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
      int pc_loop_ub;
      int tc_loop_ub;
      padImage_outSize(IxIy, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      pc_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i66, uc_loop_ub)

      for (int i64 = 0; i64 < pc_loop_ub; i64++) {
        uc_loop_ub = b_a.size(0);
        for (i66 = 0; i66 < uc_loop_ub; i66++) {
          c_a[i66 + (c_a.size(0) * i64)] =
              static_cast<double>(b_a[i66 + (b_a.size(0) * i64)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      IxIy.set_size(b.size(0), b.size(1));
      tc_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i69, wc_loop_ub)

      for (int i68 = 0; i68 < tc_loop_ub; i68++) {
        wc_loop_ub = b.size(0);
        for (i69 = 0; i69 < wc_loop_ub; i69++) {
          IxIy[i69 + (IxIy.size(0) * i68)] =
              static_cast<float>(b[i69 + (b.size(0) * i68)]);
        }
      }
    }
    vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
    siz_idx_0 = cxy.size(0);
    c_siz = cxy.size(0);
    qc_loop_ub = points0.size(0);
    r.set_size(points0.size(0));
    sc_loop_ub = points0.size(0);
    if ((static_cast<int>(points0.size(0) < 4)) != 0) {
      for (int i67{0}; i67 < qc_loop_ub; i67++) {
        r[i67] = (static_cast<int>(points0[i67 + points0.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points0[i67])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i67 = 0; i67 < sc_loop_ub; i67++) {
        r[i67] = (static_cast<int>(points0[i67 + points0.size(0)])) +
                 (c_siz * ((static_cast<int>(points0[i67])) - 1));
      }
    }
    b_cxy.set_size(r.size(0));
    vc_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i70{0}; i70 < vc_loop_ub; i70++) {
        b_cxy[i70] = cxy[r[i70] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i70 = 0; i70 < vc_loop_ub; i70++) {
        b_cxy[i70] = cxy[r[i70] - 1];
      }
    }
    d_board0 = vision::internal::calibration::checkerboard::b_growCheckerboard(
        points0, b_cxy, b_Ix2, b_Iy2, IxIy, 0.0, &b_lobj_0[0]);
    b_imagePoints.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
    vision::internal::calibration::checkerboard::find_peaks(c45, points45);
    siz_idx_0 = c45.size(0);
    d_siz = c45.size(0);
    xc_loop_ub = points45.size(0);
    r.set_size(points45.size(0));
    yc_loop_ub = points45.size(0);
    if ((static_cast<int>(points45.size(0) < 4)) != 0) {
      for (int i71{0}; i71 < xc_loop_ub; i71++) {
        r[i71] = (static_cast<int>(points45[i71 + points45.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points45[i71])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i71 = 0; i71 < yc_loop_ub; i71++) {
        r[i71] = (static_cast<int>(points45[i71 + points45.size(0)])) +
                 (d_siz * ((static_cast<int>(points45[i71])) - 1));
      }
    }
    b_c45.set_size(r.size(0));
    ad_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i72{0}; i72 < ad_loop_ub; i72++) {
        b_c45[i72] = c45[r[i72] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i72 = 0; i72 < ad_loop_ub; i72++) {
        b_c45[i72] = c45[r[i72] - 1];
      }
    }
    d_board45 = vision::internal::calibration::checkerboard::b_growCheckerboard(
        points45, b_c45, b_Ix2, b_Iy2, IxIy, 0.78539816339744828, &b_lobj_0[3]);
    guard1 = false;
    guard2 = false;
    if (d_board0->isValid) {
      if (d_board0->Energy <= d_board45->Energy) {
        guard2 = true;
      } else {
        b_board0[0] = static_cast<double>(d_board0->BoardIdx.size(0));
        b_board0[1] = static_cast<double>(d_board0->BoardIdx.size(1));
        b_board45[0] = static_cast<double>(d_board45->BoardIdx.size(0));
        b_board45[1] = static_cast<double>(d_board45->BoardIdx.size(1));
        if (isequal(b_board0, b_board45)) {
          int i76;
          int i83;
          int u_n;
          int v_n;
          c_board0 = d_board0->BoardIdx.size(0) * d_board0->BoardIdx.size(1);
          s.set_size(c_board0);
          for (int i73{0}; i73 < c_board0; i73++) {
            s[i73] = d_board0->BoardIdx[i73];
          }
          u_n = 0;
          i76 = s.size(0);
          for (int m_k{0}; m_k < i76; m_k++) {
            if (s[m_k] != 0.0) {
              u_n++;
            }
          }
          c_board45 = d_board45->BoardIdx.size(0) * d_board45->BoardIdx.size(1);
          s.set_size(c_board45);
          for (int i80{0}; i80 < c_board45; i80++) {
            s[i80] = d_board45->BoardIdx[i80];
          }
          v_n = 0;
          i83 = s.size(0);
          for (int o_k{0}; o_k < i83; o_k++) {
            if (s[o_k] != 0.0) {
              v_n++;
            }
          }
          if (u_n > v_n) {
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
      double c_numPoints;
      int bd_loop_ub;
      int c_loop_ub_tmp;
      int dd_loop_ub;
      int ed_loop_ub;
      int hd_loop_ub;
      int jd_loop_ub;
      int kd_loop_ub;
      int pd_loop_ub;
      int rd_loop_ub;
      d_board0 =
          vision::internal::calibration::checkerboard::orient(d_board0, p_I);
      c_numPoints = (static_cast<double>(d_board0->BoardCoords.size(0))) *
                    (static_cast<double>(d_board0->BoardCoords.size(1)));
      c_loop_ub_tmp = static_cast<int>(c_numPoints);
      b_points.set_size(c_loop_ub_tmp, 2);
      bd_loop_ub = static_cast<int>(c_numPoints);
      if ((static_cast<int>(((static_cast<int>(c_numPoints)) * 2) < 4)) != 0) {
        for (int i74{0}; i74 < 2; i74++) {
          for (i75 = 0; i75 < c_loop_ub_tmp; i75++) {
            b_points[i75 + (b_points.size(0) * i74)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i75)

        for (int i74 = 0; i74 < 2; i74++) {
          for (i75 = 0; i75 < bd_loop_ub; i75++) {
            b_points[i75 + (b_points.size(0) * i74)] = 0.0;
          }
        }
      }
      dd_loop_ub = d_board0->BoardCoords.size(0);
      ed_loop_ub = d_board0->BoardCoords.size(1);
      b_x.set_size(ed_loop_ub, dd_loop_ub);
      for (int i79{0}; i79 < dd_loop_ub; i79++) {
        for (int i81{0}; i81 < ed_loop_ub; i81++) {
          b_x[i81 + (b_x.size(0) * i79)] =
              d_board0
                  ->BoardCoords[i79 + (d_board0->BoardCoords.size(0) * i81)];
        }
      }
      g_x = b_x.size(0) * b_x.size(1);
      hd_loop_ub = g_x;
      if ((static_cast<int>(g_x < 4)) != 0) {
        for (int i85{0}; i85 < g_x; i85++) {
          b_points[i85] = b_x[i85];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i85 = 0; i85 < hd_loop_ub; i85++) {
          b_points[i85] = b_x[i85];
        }
      }
      jd_loop_ub = d_board0->BoardCoords.size(0);
      kd_loop_ub = d_board0->BoardCoords.size(1);
      y.set_size(kd_loop_ub, jd_loop_ub);
      for (int i87{0}; i87 < jd_loop_ub; i87++) {
        for (int i88{0}; i88 < kd_loop_ub; i88++) {
          y[i88 + (y.size(0) * i87)] =
              d_board0
                  ->BoardCoords[(i87 + (d_board0->BoardCoords.size(0) * i88)) +
                                (d_board0->BoardCoords.size(0) *
                                 d_board0->BoardCoords.size(1))];
        }
      }
      b_y = y.size(0) * y.size(1);
      pd_loop_ub = b_y;
      if ((static_cast<int>(b_y < 4)) != 0) {
        for (int i91{0}; i91 < b_y; i91++) {
          b_points[i91 + b_points.size(0)] = y[i91];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i91 = 0; i91 < pd_loop_ub; i91++) {
          b_points[i91 + b_points.size(0)] = y[i91];
        }
      }
      boardSize[0] = (static_cast<double>(d_board0->BoardCoords.size(1))) + 1.0;
      boardSize[1] = (static_cast<double>(d_board0->BoardCoords.size(0))) + 1.0;
      b_imagePoints.set_size(b_points.size(0), 2);
      rd_loop_ub = b_points.size(0);
      if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
        for (int i93{0}; i93 < 2; i93++) {
          for (i94 = 0; i94 < rd_loop_ub; i94++) {
            b_imagePoints[i94 + (b_imagePoints.size(0) * i93)] =
                b_points[i94 + (b_points.size(0) * i93)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i94)

        for (int i93 = 0; i93 < 2; i93++) {
          for (i94 = 0; i94 < rd_loop_ub; i94++) {
            b_imagePoints[i94 + (b_imagePoints.size(0) * i93)] =
                b_points[i94 + (b_points.size(0) * i93)];
          }
        }
      }
      vision::internal::calibration::checkerboard::subPixelLocation(
          Ixy, b_imagePoints);
    }
    if (guard1 && (d_board45->isValid)) {
      double d_numPoints;
      int cd_loop_ub;
      int d_loop_ub_tmp;
      int fd_loop_ub;
      int gd_loop_ub;
      int id_loop_ub;
      int md_loop_ub;
      int od_loop_ub;
      int qd_loop_ub;
      int sd_loop_ub;
      d_board45 =
          vision::internal::calibration::checkerboard::orient(d_board45, p_I);
      d_numPoints = (static_cast<double>(d_board45->BoardCoords.size(0))) *
                    (static_cast<double>(d_board45->BoardCoords.size(1)));
      d_loop_ub_tmp = static_cast<int>(d_numPoints);
      b_points.set_size(d_loop_ub_tmp, 2);
      cd_loop_ub = static_cast<int>(d_numPoints);
      if ((static_cast<int>(((static_cast<int>(d_numPoints)) * 2) < 4)) != 0) {
        for (int i77{0}; i77 < 2; i77++) {
          for (i78 = 0; i78 < d_loop_ub_tmp; i78++) {
            b_points[i78 + (b_points.size(0) * i77)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i78)

        for (int i77 = 0; i77 < 2; i77++) {
          for (i78 = 0; i78 < cd_loop_ub; i78++) {
            b_points[i78 + (b_points.size(0) * i77)] = 0.0;
          }
        }
      }
      fd_loop_ub = d_board45->BoardCoords.size(0);
      gd_loop_ub = d_board45->BoardCoords.size(1);
      b_x.set_size(gd_loop_ub, fd_loop_ub);
      for (int i82{0}; i82 < fd_loop_ub; i82++) {
        for (int i84{0}; i84 < gd_loop_ub; i84++) {
          b_x[i84 + (b_x.size(0) * i82)] =
              d_board45
                  ->BoardCoords[i82 + (d_board45->BoardCoords.size(0) * i84)];
        }
      }
      g_x = b_x.size(0) * b_x.size(1);
      id_loop_ub = g_x;
      if ((static_cast<int>(g_x < 4)) != 0) {
        for (int i86{0}; i86 < g_x; i86++) {
          b_points[i86] = b_x[i86];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i86 = 0; i86 < id_loop_ub; i86++) {
          b_points[i86] = b_x[i86];
        }
      }
      md_loop_ub = d_board45->BoardCoords.size(0);
      od_loop_ub = d_board45->BoardCoords.size(1);
      y.set_size(od_loop_ub, md_loop_ub);
      for (int i89{0}; i89 < md_loop_ub; i89++) {
        for (int i90{0}; i90 < od_loop_ub; i90++) {
          y[i90 + (y.size(0) * i89)] =
              d_board45
                  ->BoardCoords[(i89 + (d_board45->BoardCoords.size(0) * i90)) +
                                (d_board45->BoardCoords.size(0) *
                                 d_board45->BoardCoords.size(1))];
        }
      }
      b_y = y.size(0) * y.size(1);
      qd_loop_ub = b_y;
      if ((static_cast<int>(b_y < 4)) != 0) {
        for (int i92{0}; i92 < b_y; i92++) {
          b_points[i92 + b_points.size(0)] = y[i92];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i92 = 0; i92 < qd_loop_ub; i92++) {
          b_points[i92 + b_points.size(0)] = y[i92];
        }
      }
      boardSize[0] =
          (static_cast<double>(d_board45->BoardCoords.size(1))) + 1.0;
      boardSize[1] =
          (static_cast<double>(d_board45->BoardCoords.size(0))) + 1.0;
      b_imagePoints.set_size(b_points.size(0), 2);
      sd_loop_ub = b_points.size(0);
      if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
        for (int i95{0}; i95 < 2; i95++) {
          for (i96 = 0; i96 < sd_loop_ub; i96++) {
            b_imagePoints[i96 + (b_imagePoints.size(0) * i95)] =
                b_points[i96 + (b_points.size(0) * i95)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i96)

        for (int i95 = 0; i95 < 2; i95++) {
          for (i96 = 0; i96 < sd_loop_ub; i96++) {
            b_imagePoints[i96 + (b_imagePoints.size(0) * i95)] =
                b_points[i96 + (b_points.size(0) * i95)];
          }
        }
      }
      vision::internal::calibration::checkerboard::subPixelLocation(
          I_45_45, b_imagePoints);
    }
  }
  if ((b_imagePoints.size(0) != 0) && (b_imagePoints.size(1) != 0)) {
    int ab_loop_ub;
    int db_loop_ub;
    int end;
    int partialTrueCount;
    int rb_loop_ub;
    int trueCount;
    ab_loop_ub = b_imagePoints.size(0);
    zeroIdx.set_size(b_imagePoints.size(0));
    db_loop_ub = b_imagePoints.size(0);
    if ((static_cast<int>(b_imagePoints.size(0) < 4)) != 0) {
      for (int i26{0}; i26 < ab_loop_ub; i26++) {
        zeroIdx[i26] = (b_imagePoints[i26] == 0.0);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i26 = 0; i26 < db_loop_ub; i26++) {
        zeroIdx[i26] = (b_imagePoints[i26] == 0.0);
      }
    }
    end = zeroIdx.size(0) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (zeroIdx[c_i]) {
        trueCount++;
      }
    }
    r1.set_size(trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if (zeroIdx[d_i]) {
        r1[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    rb_loop_ub = b_imagePoints.size(1);
    for (int i40{0}; i40 < rb_loop_ub; i40++) {
      int ub_loop_ub;
      ub_loop_ub = r1.size(0);
      for (int i43{0}; i43 < ub_loop_ub; i43++) {
        b_imagePoints[(r1[i43] + (b_imagePoints.size(0) * i40)) - 1] = rtNaN;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<double, 2U> &b_imagePoints
//                double boardSize[2]
// Return Type  : void
//
void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &o_I,
                              ::coder::array<double, 2U> &b_imagePoints,
                              double boardSize[2])
{
  vision::internal::calibration::checkerboard::b_Checkerboard b_lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard *board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *board45;
  vision::internal::calibration::checkerboard::b_Checkerboard *d_board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *d_board45;
  array<double, 2U> b;
  array<double, 2U> c_a;
  array<double, 1U> s;
  array<float, 2U> I_45_45;
  array<float, 2U> Ix;
  array<float, 2U> Ix2;
  array<float, 2U> IxIy;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> b_Ix2;
  array<float, 2U> b_Iy2;
  array<float, 2U> b_a;
  array<float, 2U> c45;
  array<float, 2U> cxy;
  array<float, 2U> p_I;
  array<float, 2U> points0;
  array<float, 2U> points45;
  array<float, 1U> b_c45;
  array<float, 1U> b_cxy;
  array<int, 1U> r;
  double b_board0[2];
  double b_board45[2];
  double pad[2];
  int ab_loop_ub;
  int ac_loop_ub;
  int b_i8;
  int b_k;
  int b_loop_ub;
  int b_siz;
  int c_board0;
  int c_board45;
  int d_k;
  int d_loop_ub;
  int db_loop_ub;
  int eb_loop_ub;
  int g_loop_ub;
  int gb_loop_ub;
  int h_k;
  int i1;
  int i12;
  int i13;
  int i16;
  int i23;
  int i27;
  int i29;
  int i3;
  int i31;
  int i33;
  int i37;
  int i38;
  int i39;
  int i42;
  int i43;
  int i46;
  int i7;
  int i9;
  int i_loop_ub;
  int j_loop_ub;
  int k_N;
  int k_k;
  int k_loop_ub;
  int loop_ub;
  int m_N;
  int mb_loop_ub;
  int o_N;
  int o_loop_ub;
  int p_N;
  int p_loop_ub;
  int pb_loop_ub;
  int q_loop_ub;
  int qb_loop_ub;
  int r_N;
  int rb_loop_ub;
  int s_loop_ub;
  int siz;
  int siz_idx_0;
  int t_N;
  int t_loop_ub;
  int u_loop_ub;
  int ub_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int x_loop_ub;
  int xb_loop_ub;
  bool guard1{false};
  bool guard2{false};
  p_I.set_size(o_I.size(0), o_I.size(1));
  loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = o_I.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      p_I[i1 + (p_I.size(0) * b_i)] =
          (static_cast<float>(o_I[i1 + (o_I.size(0) * b_i)])) / 255.0F;
    }
  }
  vision::internal::calibration::checkerboard::secondDerivCornerMetric(
      p_I, cxy, c45, Ix, Iy, Ixy, I_45_45);
  Ix2.set_size(Ix.size(0), Ix.size(1));
  k_N = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, o_N)

  for (int k = 0; k < k_N; k++) {
    o_N = Ix2.size(0);
    for (b_k = 0; b_k < o_N; b_k++) {
      Ix2[b_k + (Ix2.size(0) * k)] =
          rt_powf_snf(Ix[b_k + (Ix.size(0) * k)], 2.0F);
    }
  }
  Iy2.set_size(Iy.size(0), Iy.size(1));
  m_N = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_k, p_N)

  for (int c_k = 0; c_k < m_N; c_k++) {
    p_N = Iy2.size(0);
    for (d_k = 0; d_k < p_N; d_k++) {
      Iy2[d_k + (Iy2.size(0) * c_k)] =
          rt_powf_snf(Iy[d_k + (Iy.size(0) * c_k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
    int c_loop_ub;
    int f_loop_ub;
    padImage_outSize(Ix2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    c_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    g_loop_ub)

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      g_loop_ub = b_a.size(0);
      for (i3 = 0; i3 < g_loop_ub; i3++) {
        c_a[i3 + (c_a.size(0) * i2)] =
            static_cast<double>(b_a[i3 + (b_a.size(0) * i2)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    f_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9,        \
                                                                    k_loop_ub)

    for (int i6 = 0; i6 < f_loop_ub; i6++) {
      k_loop_ub = b.size(0);
      for (i9 = 0; i9 < k_loop_ub; i9++) {
        Ix2[i9 + (Ix2.size(0) * i6)] =
            static_cast<float>(b[i9 + (b.size(0) * i6)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    int e_loop_ub;
    int h_loop_ub;
    padImage_outSize(Iy2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    e_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    i_loop_ub)

    for (int i5 = 0; i5 < e_loop_ub; i5++) {
      i_loop_ub = b_a.size(0);
      for (i7 = 0; i7 < i_loop_ub; i7++) {
        c_a[i7 + (c_a.size(0) * i5)] =
            static_cast<double>(b_a[i7 + (b_a.size(0) * i5)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    h_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12,       \
                                                                    p_loop_ub)

    for (int i10 = 0; i10 < h_loop_ub; i10++) {
      p_loop_ub = b.size(0);
      for (i12 = 0; i12 < p_loop_ub; i12++) {
        Iy2[i12 + (Iy2.size(0) * i10)] =
            static_cast<float>(b[i12 + (b.size(0) * i10)]);
      }
    }
  }
  IxIy.set_size(Ix.size(0), Ix.size(1));
  d_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8,      \
                                                                    j_loop_ub)

  for (int i4 = 0; i4 < d_loop_ub; i4++) {
    j_loop_ub = Ix.size(0);
    for (b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
      IxIy[b_i8 + (IxIy.size(0) * i4)] =
          Ix[b_i8 + (Ix.size(0) * i4)] * Iy[b_i8 + (Iy.size(0) * i4)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
    int m_loop_ub;
    int r_loop_ub;
    padImage_outSize(IxIy, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    m_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13,       \
                                                                    s_loop_ub)

    for (int i11 = 0; i11 < m_loop_ub; i11++) {
      s_loop_ub = b_a.size(0);
      for (i13 = 0; i13 < s_loop_ub; i13++) {
        c_a[i13 + (c_a.size(0) * i11)] =
            static_cast<double>(b_a[i13 + (b_a.size(0) * i11)]);
      }
    }
    internal::c_conv2AXPYValidCMP(c_a, b);
    IxIy.set_size(b.size(0), b.size(1));
    r_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i16,       \
                                                                    u_loop_ub)

    for (int i15 = 0; i15 < r_loop_ub; i15++) {
      u_loop_ub = b.size(0);
      for (i16 = 0; i16 < u_loop_ub; i16++) {
        IxIy[i16 + (IxIy.size(0) * i15)] =
            static_cast<float>(b[i16 + (b.size(0) * i15)]);
      }
    }
  }
  vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  siz = cxy.size(0);
  o_loop_ub = points0.size(0);
  r.set_size(points0.size(0));
  q_loop_ub = points0.size(0);
  if ((static_cast<int>(points0.size(0) < 4)) != 0) {
    for (int i14{0}; i14 < o_loop_ub; i14++) {
      r[i14] = (static_cast<int>(points0[i14 + points0.size(0)])) +
               (siz_idx_0 * ((static_cast<int>(points0[i14])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < q_loop_ub; i14++) {
      r[i14] = (static_cast<int>(points0[i14 + points0.size(0)])) +
               (siz * ((static_cast<int>(points0[i14])) - 1));
    }
  }
  b_cxy.set_size(r.size(0));
  t_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i17{0}; i17 < t_loop_ub; i17++) {
      b_cxy[i17] = cxy[r[i17] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i17 = 0; i17 < t_loop_ub; i17++) {
      b_cxy[i17] = cxy[r[i17] - 1];
    }
  }
  board0 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, b_cxy, Ix2, Iy2, IxIy, 0.0, &lobj_0[0]);
  b_imagePoints.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(c45, points45);
  siz_idx_0 = c45.size(0);
  b_siz = c45.size(0);
  v_loop_ub = points45.size(0);
  r.set_size(points45.size(0));
  w_loop_ub = points45.size(0);
  if ((static_cast<int>(points45.size(0) < 4)) != 0) {
    for (int i18{0}; i18 < v_loop_ub; i18++) {
      r[i18] = (static_cast<int>(points45[i18 + points45.size(0)])) +
               (siz_idx_0 * ((static_cast<int>(points45[i18])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < w_loop_ub; i18++) {
      r[i18] = (static_cast<int>(points45[i18 + points45.size(0)])) +
               (b_siz * ((static_cast<int>(points45[i18])) - 1));
    }
  }
  b_c45.set_size(r.size(0));
  x_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i19{0}; i19 < x_loop_ub; i19++) {
      b_c45[i19] = c45[r[i19] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < x_loop_ub; i19++) {
      b_c45[i19] = c45[r[i19] - 1];
    }
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
        int h_n;
        int i22;
        int i26;
        int i_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int i20{0}; i20 < c_board0; i20++) {
          s[i20] = board0->BoardIdx[i20];
        }
        h_n = 0;
        i22 = s.size(0);
        for (int e_k{0}; e_k < i22; e_k++) {
          if (s[e_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i24{0}; i24 < c_board45; i24++) {
          s[i24] = board45->BoardIdx[i24];
        }
        i_n = 0;
        i26 = s.size(0);
        for (int i_k{0}; i_k < i26; i_k++) {
          if (s[i_k] != 0.0) {
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
    board0 = vision::internal::calibration::checkerboard::orient(board0, p_I);
    vision::internal::calibration::checkerboard::toPoints(board0, b_imagePoints,
                                                          boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, b_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    board45 = vision::internal::calibration::checkerboard::orient(board45, p_I);
    vision::internal::calibration::checkerboard::toPoints(
        board45, b_imagePoints, boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_45, b_imagePoints);
  }
  if ((b_imagePoints.size(0) == 0) || (b_imagePoints.size(1) == 0)) {
    int bb_loop_ub;
    int bc_loop_ub;
    int c_siz;
    int cb_loop_ub;
    int cc_loop_ub;
    int d_siz;
    int dc_loop_ub;
    int fb_loop_ub;
    int ib_loop_ub;
    int q_N;
    int s_N;
    int tb_loop_ub;
    int vb_loop_ub;
    int y_loop_ub;
    int yb_loop_ub;
    vision::internal::calibration::checkerboard::b_secondDerivCornerMetric(
        p_I, cxy, c45, Ix, Iy, Ixy, I_45_45);
    b_Ix2.set_size(Ix.size(0), Ix.size(1));
    Ix2.set_size(Ix.size(0), Ix.size(1));
    y_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i23, ab_loop_ub)

    for (int i21 = 0; i21 < y_loop_ub; i21++) {
      ab_loop_ub = b_Ix2.size(0);
      for (i23 = 0; i23 < ab_loop_ub; i23++) {
        Ix2[i23 + (Ix2.size(0) * i21)] = b_Ix2[i23 + (b_Ix2.size(0) * i21)];
      }
    }
    q_N = b_Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(h_k, r_N)

    for (int g_k = 0; g_k < q_N; g_k++) {
      r_N = Ix2.size(0);
      for (h_k = 0; h_k < r_N; h_k++) {
        Ix2[h_k + (Ix2.size(0) * g_k)] =
            rt_powf_snf(Ix[h_k + (Ix.size(0) * g_k)], 2.0F);
      }
    }
    b_Ix2.set_size(Ix2.size(0), Ix2.size(1));
    bb_loop_ub = Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, db_loop_ub)

    for (int i25 = 0; i25 < bb_loop_ub; i25++) {
      db_loop_ub = Ix2.size(0);
      for (i27 = 0; i27 < db_loop_ub; i27++) {
        b_Ix2[i27 + (b_Ix2.size(0) * i25)] = Ix2[i27 + (Ix2.size(0) * i25)];
      }
    }
    b_Iy2.set_size(Iy.size(0), Iy.size(1));
    Iy2.set_size(Iy.size(0), Iy.size(1));
    cb_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i29, eb_loop_ub)

    for (int i28 = 0; i28 < cb_loop_ub; i28++) {
      eb_loop_ub = b_Iy2.size(0);
      for (i29 = 0; i29 < eb_loop_ub; i29++) {
        Iy2[i29 + (Iy2.size(0) * i28)] = b_Iy2[i29 + (b_Iy2.size(0) * i28)];
      }
    }
    s_N = b_Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, t_N)

    for (int j_k = 0; j_k < s_N; j_k++) {
      t_N = Iy2.size(0);
      for (k_k = 0; k_k < t_N; k_k++) {
        Iy2[k_k + (Iy2.size(0) * j_k)] =
            rt_powf_snf(Iy[k_k + (Iy.size(0) * j_k)], 2.0F);
      }
    }
    b_Iy2.set_size(Iy2.size(0), Iy2.size(1));
    fb_loop_ub = Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i31, gb_loop_ub)

    for (int i30 = 0; i30 < fb_loop_ub; i30++) {
      gb_loop_ub = Iy2.size(0);
      for (i31 = 0; i31 < gb_loop_ub; i31++) {
        b_Iy2[i31 + (b_Iy2.size(0) * i30)] = Iy2[i31 + (Iy2.size(0) * i30)];
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
      int hb_loop_ub;
      int kb_loop_ub;
      padImage_outSize(Ix2, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      hb_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i33, mb_loop_ub)

      for (int i32 = 0; i32 < hb_loop_ub; i32++) {
        mb_loop_ub = b_a.size(0);
        for (i33 = 0; i33 < mb_loop_ub; i33++) {
          c_a[i33 + (c_a.size(0) * i32)] =
              static_cast<double>(b_a[i33 + (b_a.size(0) * i32)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      b_Ix2.set_size(b.size(0), b.size(1));
      kb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i39, rb_loop_ub)

      for (int i36 = 0; i36 < kb_loop_ub; i36++) {
        rb_loop_ub = b.size(0);
        for (i39 = 0; i39 < rb_loop_ub; i39++) {
          b_Ix2[i39 + (b_Ix2.size(0) * i36)] =
              static_cast<float>(b[i39 + (b.size(0) * i36)]);
        }
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
      int jb_loop_ub;
      int ob_loop_ub;
      padImage_outSize(Iy2, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      jb_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i37, pb_loop_ub)

      for (int i35 = 0; i35 < jb_loop_ub; i35++) {
        pb_loop_ub = b_a.size(0);
        for (i37 = 0; i37 < pb_loop_ub; i37++) {
          c_a[i37 + (c_a.size(0) * i35)] =
              static_cast<double>(b_a[i37 + (b_a.size(0) * i35)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      b_Iy2.set_size(b.size(0), b.size(1));
      ob_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i42, ub_loop_ub)

      for (int i40 = 0; i40 < ob_loop_ub; i40++) {
        ub_loop_ub = b.size(0);
        for (i42 = 0; i42 < ub_loop_ub; i42++) {
          b_Iy2[i42 + (b_Iy2.size(0) * i40)] =
              static_cast<float>(b[i42 + (b.size(0) * i40)]);
        }
      }
    }
    IxIy.set_size(Ix.size(0), Ix.size(1));
    ib_loop_ub = Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i38, qb_loop_ub)

    for (int i34 = 0; i34 < ib_loop_ub; i34++) {
      qb_loop_ub = Ix.size(0);
      for (i38 = 0; i38 < qb_loop_ub; i38++) {
        IxIy[i38 + (IxIy.size(0) * i34)] =
            Ix[i38 + (Ix.size(0) * i34)] * Iy[i38 + (Iy.size(0) * i34)];
      }
    }
    pad[0] = 3.0;
    pad[1] = 3.0;
    if ((IxIy.size(0) != 0) && (IxIy.size(1) != 0)) {
      int sb_loop_ub;
      int wb_loop_ub;
      padImage_outSize(IxIy, pad, b_a);
      c_a.set_size(b_a.size(0), b_a.size(1));
      sb_loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i43, xb_loop_ub)

      for (int i41 = 0; i41 < sb_loop_ub; i41++) {
        xb_loop_ub = b_a.size(0);
        for (i43 = 0; i43 < xb_loop_ub; i43++) {
          c_a[i43 + (c_a.size(0) * i41)] =
              static_cast<double>(b_a[i43 + (b_a.size(0) * i41)]);
        }
      }
      internal::c_conv2AXPYValidCMP(c_a, b);
      IxIy.set_size(b.size(0), b.size(1));
      wb_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i46, ac_loop_ub)

      for (int i45 = 0; i45 < wb_loop_ub; i45++) {
        ac_loop_ub = b.size(0);
        for (i46 = 0; i46 < ac_loop_ub; i46++) {
          IxIy[i46 + (IxIy.size(0) * i45)] =
              static_cast<float>(b[i46 + (b.size(0) * i45)]);
        }
      }
    }
    vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
    siz_idx_0 = cxy.size(0);
    c_siz = cxy.size(0);
    tb_loop_ub = points0.size(0);
    r.set_size(points0.size(0));
    vb_loop_ub = points0.size(0);
    if ((static_cast<int>(points0.size(0) < 4)) != 0) {
      for (int i44{0}; i44 < tb_loop_ub; i44++) {
        r[i44] = (static_cast<int>(points0[i44 + points0.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points0[i44])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i44 = 0; i44 < vb_loop_ub; i44++) {
        r[i44] = (static_cast<int>(points0[i44 + points0.size(0)])) +
                 (c_siz * ((static_cast<int>(points0[i44])) - 1));
      }
    }
    b_cxy.set_size(r.size(0));
    yb_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i47{0}; i47 < yb_loop_ub; i47++) {
        b_cxy[i47] = cxy[r[i47] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i47 = 0; i47 < yb_loop_ub; i47++) {
        b_cxy[i47] = cxy[r[i47] - 1];
      }
    }
    d_board0 = vision::internal::calibration::checkerboard::growCheckerboard(
        points0, b_cxy, b_Ix2, b_Iy2, IxIy, 0.0, &b_lobj_0[0]);
    b_imagePoints.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
    vision::internal::calibration::checkerboard::find_peaks(c45, points45);
    siz_idx_0 = c45.size(0);
    d_siz = c45.size(0);
    bc_loop_ub = points45.size(0);
    r.set_size(points45.size(0));
    cc_loop_ub = points45.size(0);
    if ((static_cast<int>(points45.size(0) < 4)) != 0) {
      for (int i48{0}; i48 < bc_loop_ub; i48++) {
        r[i48] = (static_cast<int>(points45[i48 + points45.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points45[i48])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i48 = 0; i48 < cc_loop_ub; i48++) {
        r[i48] = (static_cast<int>(points45[i48 + points45.size(0)])) +
                 (d_siz * ((static_cast<int>(points45[i48])) - 1));
      }
    }
    b_c45.set_size(r.size(0));
    dc_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i49{0}; i49 < dc_loop_ub; i49++) {
        b_c45[i49] = c45[r[i49] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i49 = 0; i49 < dc_loop_ub; i49++) {
        b_c45[i49] = c45[r[i49] - 1];
      }
    }
    d_board45 = vision::internal::calibration::checkerboard::growCheckerboard(
        points45, b_c45, b_Ix2, b_Iy2, IxIy, 0.78539816339744828, &b_lobj_0[3]);
    guard1 = false;
    guard2 = false;
    if (d_board0->isValid) {
      if (d_board0->Energy <= d_board45->Energy) {
        guard2 = true;
      } else {
        b_board0[0] = static_cast<double>(d_board0->BoardIdx.size(0));
        b_board0[1] = static_cast<double>(d_board0->BoardIdx.size(1));
        b_board45[0] = static_cast<double>(d_board45->BoardIdx.size(0));
        b_board45[1] = static_cast<double>(d_board45->BoardIdx.size(1));
        if (isequal(b_board0, b_board45)) {
          int i51;
          int i53;
          int u_n;
          int v_n;
          c_board0 = d_board0->BoardIdx.size(0) * d_board0->BoardIdx.size(1);
          s.set_size(c_board0);
          for (int i50{0}; i50 < c_board0; i50++) {
            s[i50] = d_board0->BoardIdx[i50];
          }
          u_n = 0;
          i51 = s.size(0);
          for (int m_k{0}; m_k < i51; m_k++) {
            if (s[m_k] != 0.0) {
              u_n++;
            }
          }
          c_board45 = d_board45->BoardIdx.size(0) * d_board45->BoardIdx.size(1);
          s.set_size(c_board45);
          for (int i52{0}; i52 < c_board45; i52++) {
            s[i52] = d_board45->BoardIdx[i52];
          }
          v_n = 0;
          i53 = s.size(0);
          for (int o_k{0}; o_k < i53; o_k++) {
            if (s[o_k] != 0.0) {
              v_n++;
            }
          }
          if (u_n > v_n) {
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
      d_board0 =
          vision::internal::calibration::checkerboard::orient(d_board0, p_I);
      vision::internal::calibration::checkerboard::toPoints(
          d_board0, b_imagePoints, boardSize);
      vision::internal::calibration::checkerboard::subPixelLocation(
          Ixy, b_imagePoints);
    }
    if (guard1 && (d_board45->isValid)) {
      d_board45 =
          vision::internal::calibration::checkerboard::orient(d_board45, p_I);
      vision::internal::calibration::checkerboard::toPoints(
          d_board45, b_imagePoints, boardSize);
      vision::internal::calibration::checkerboard::subPixelLocation(
          I_45_45, b_imagePoints);
    }
  }
}

} // namespace coder

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
