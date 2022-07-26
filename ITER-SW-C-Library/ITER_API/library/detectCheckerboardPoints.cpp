//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "ITER_API_rtwutil.h"
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
namespace ITER {
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
  ::coder::array<double, 2U> b_points;
  ::coder::array<double, 2U> b_x;
  ::coder::array<double, 2U> y;
  ::coder::array<double, 1U> s;
  ::coder::array<float, 2U> I_45_45;
  ::coder::array<float, 2U> Ix2;
  ::coder::array<float, 2U> IxIy;
  ::coder::array<float, 2U> Ixy;
  ::coder::array<float, 2U> Iy;
  ::coder::array<float, 2U> Iy2;
  ::coder::array<float, 2U> b_Ix;
  ::coder::array<float, 2U> b_Ix2;
  ::coder::array<float, 2U> b_Iy2;
  ::coder::array<float, 2U> c45;
  ::coder::array<float, 2U> cxy;
  ::coder::array<float, 2U> p_I;
  ::coder::array<float, 2U> points0;
  ::coder::array<float, 2U> points45;
  ::coder::array<float, 1U> b_c45;
  ::coder::array<float, 1U> b_cxy;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<bool, 1U> zeroIdx;
  double b_board0[2];
  double b_board45[2];
  int b_k;
  int b_loop_ub;
  int b_siz;
  int b_y;
  int c_board0;
  int c_board45;
  int c_loop_ub;
  int cb_loop_ub;
  int d_k;
  int d_loop_ub;
  int e_loop_ub;
  int e_x;
  int f_loop_ub;
  int g_loop_ub;
  int h_k;
  int h_loop_ub;
  int i1;
  int i11;
  int i15;
  int i16;
  int i25;
  int i3;
  int i32;
  int i37;
  int i41;
  int i42;
  int i44;
  int i51;
  int i54;
  int i70;
  int i72;
  int i_N;
  int i_loop_ub;
  int j_loop_ub;
  int k_N;
  int k_k;
  int kb_loop_ub;
  int loop_ub;
  int m_N;
  int o_N;
  int pb_loop_ub;
  int siz;
  int siz_idx_0;
  int tb_loop_ub;
  int u_N;
  int u_loop_ub;
  int w_N;
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
      p_I, cxy, c45, b_Ix, Iy, Ixy, I_45_45);
  Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
  i_N = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, m_N)

  for (int k = 0; k < i_N; k++) {
    m_N = Ix2.size(0);
    for (b_k = 0; b_k < m_N; b_k++) {
      Ix2[b_k + (Ix2.size(0) * k)] =
          rt_powf_snf(b_Ix[b_k + (b_Ix.size(0) * k)], 2.0F);
    }
  }
  Iy2.set_size(Iy.size(0), Iy.size(1));
  k_N = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_k, o_N)

  for (int c_k = 0; c_k < k_N; c_k++) {
    o_N = Iy2.size(0);
    for (d_k = 0; d_k < o_N; d_k++) {
      Iy2[d_k + (Iy2.size(0) * c_k)] =
          rt_powf_snf(Iy[d_k + (Iy.size(0) * c_k)], 2.0F);
    }
  }
  c_imfilter(Ix2);
  c_imfilter(Iy2);
  IxIy.set_size(b_Ix.size(0), b_Ix.size(1));
  c_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    e_loop_ub)

  for (int i2 = 0; i2 < c_loop_ub; i2++) {
    e_loop_ub = b_Ix.size(0);
    for (i3 = 0; i3 < e_loop_ub; i3++) {
      IxIy[i3 + (IxIy.size(0) * i2)] =
          b_Ix[i3 + (b_Ix.size(0) * i2)] * Iy[i3 + (Iy.size(0) * i2)];
    }
  }
  c_imfilter(IxIy);
  vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  siz = cxy.size(0);
  d_loop_ub = points0.size(0);
  r.set_size(points0.size(0));
  f_loop_ub = points0.size(0);
  if ((static_cast<int>(points0.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < d_loop_ub; i4++) {
      r[i4] = (static_cast<int>(points0[i4 + points0.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points0[i4])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < f_loop_ub; i4++) {
      r[i4] = (static_cast<int>(points0[i4 + points0.size(0)])) +
              (siz * ((static_cast<int>(points0[i4])) - 1));
    }
  }
  b_cxy.set_size(r.size(0));
  g_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i5{0}; i5 < g_loop_ub; i5++) {
      b_cxy[i5] = cxy[r[i5] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < g_loop_ub; i5++) {
      b_cxy[i5] = cxy[r[i5] - 1];
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
  h_loop_ub = points45.size(0);
  r.set_size(points45.size(0));
  i_loop_ub = points45.size(0);
  if ((static_cast<int>(points45.size(0) < 4)) != 0) {
    for (int i6{0}; i6 < h_loop_ub; i6++) {
      r[i6] = (static_cast<int>(points45[i6 + points45.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points45[i6])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < i_loop_ub; i6++) {
      r[i6] = (static_cast<int>(points45[i6 + points45.size(0)])) +
              (b_siz * ((static_cast<int>(points45[i6])) - 1));
    }
  }
  b_c45.set_size(r.size(0));
  j_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i7{0}; i7 < j_loop_ub; i7++) {
      b_c45[i7] = c45[r[i7] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < j_loop_ub; i7++) {
      b_c45[i7] = c45[r[i7] - 1];
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
        int i12;
        int i22;
        int p_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int b_i8{0}; b_i8 < c_board0; b_i8++) {
          s[b_i8] = board0->BoardIdx[b_i8];
        }
        h_n = 0;
        i12 = s.size(0);
        for (int e_k{0}; e_k < i12; e_k++) {
          if (s[e_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i18{0}; i18 < c_board45; i18++) {
          s[i18] = board45->BoardIdx[i18];
        }
        p_n = 0;
        i22 = s.size(0);
        for (int i_k{0}; i_k < i22; i_k++) {
          if (s[i_k] != 0.0) {
            p_n++;
          }
        }
        if (h_n > p_n) {
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
    int ab_loop_ub;
    int db_loop_ub;
    int ib_loop_ub;
    int k_loop_ub;
    int loop_ub_tmp;
    int qb_loop_ub;
    int r_loop_ub;
    int s_loop_ub;
    int x_loop_ub;
    board0 = vision::internal::calibration::checkerboard::orient(board0, p_I);
    numPoints = (static_cast<double>(board0->BoardCoords.size(0))) *
                (static_cast<double>(board0->BoardCoords.size(1)));
    loop_ub_tmp = static_cast<int>(numPoints);
    b_points.set_size(loop_ub_tmp, 2);
    k_loop_ub = static_cast<int>(numPoints);
    if ((static_cast<int>(((static_cast<int>(numPoints)) * 2) < 4)) != 0) {
      for (int i9{0}; i9 < 2; i9++) {
        for (i11 = 0; i11 < loop_ub_tmp; i11++) {
          b_points[i11 + (b_points.size(0) * i9)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11)

      for (int i9 = 0; i9 < 2; i9++) {
        for (i11 = 0; i11 < k_loop_ub; i11++) {
          b_points[i11 + (b_points.size(0) * i9)] = 0.0;
        }
      }
    }
    r_loop_ub = board0->BoardCoords.size(0);
    s_loop_ub = board0->BoardCoords.size(1);
    b_x.set_size(s_loop_ub, r_loop_ub);
    for (int i17{0}; i17 < r_loop_ub; i17++) {
      for (int i19{0}; i19 < s_loop_ub; i19++) {
        b_x[i19 + (b_x.size(0) * i17)] =
            board0->BoardCoords[i17 + (board0->BoardCoords.size(0) * i19)];
      }
    }
    e_x = b_x.size(0) * b_x.size(1);
    x_loop_ub = e_x;
    if ((static_cast<int>(e_x < 4)) != 0) {
      for (int i24{0}; i24 < e_x; i24++) {
        b_points[i24] = b_x[i24];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i24 = 0; i24 < x_loop_ub; i24++) {
        b_points[i24] = b_x[i24];
      }
    }
    ab_loop_ub = board0->BoardCoords.size(0);
    db_loop_ub = board0->BoardCoords.size(1);
    y.set_size(db_loop_ub, ab_loop_ub);
    for (int i29{0}; i29 < ab_loop_ub; i29++) {
      for (int i31{0}; i31 < db_loop_ub; i31++) {
        y[i31 + (y.size(0) * i29)] =
            board0->BoardCoords[(i29 + (board0->BoardCoords.size(0) * i31)) +
                                (board0->BoardCoords.size(0) *
                                 board0->BoardCoords.size(1))];
      }
    }
    b_y = y.size(0) * y.size(1);
    ib_loop_ub = b_y;
    if ((static_cast<int>(b_y < 4)) != 0) {
      for (int i36{0}; i36 < b_y; i36++) {
        b_points[i36 + b_points.size(0)] = y[i36];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i36 = 0; i36 < ib_loop_ub; i36++) {
        b_points[i36 + b_points.size(0)] = y[i36];
      }
    }
    boardSize[0] = (static_cast<double>(board0->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(board0->BoardCoords.size(0))) + 1.0;
    b_imagePoints.set_size(b_points.size(0), 2);
    qb_loop_ub = b_points.size(0);
    if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
      for (int i40{0}; i40 < 2; i40++) {
        for (i42 = 0; i42 < qb_loop_ub; i42++) {
          b_imagePoints[i42 + (b_imagePoints.size(0) * i40)] =
              b_points[i42 + (b_points.size(0) * i40)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i42)

      for (int i40 = 0; i40 < 2; i40++) {
        for (i42 = 0; i42 < qb_loop_ub; i42++) {
          b_imagePoints[i42 + (b_imagePoints.size(0) * i40)] =
              b_points[i42 + (b_points.size(0) * i40)];
        }
      }
    }
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, b_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    double b_numPoints;
    int b_loop_ub_tmp;
    int fb_loop_ub;
    int hb_loop_ub;
    int mb_loop_ub;
    int p_loop_ub;
    int rb_loop_ub;
    int t_loop_ub;
    int v_loop_ub;
    int y_loop_ub;
    board45 = vision::internal::calibration::checkerboard::orient(board45, p_I);
    b_numPoints = (static_cast<double>(board45->BoardCoords.size(0))) *
                  (static_cast<double>(board45->BoardCoords.size(1)));
    b_loop_ub_tmp = static_cast<int>(b_numPoints);
    b_points.set_size(b_loop_ub_tmp, 2);
    p_loop_ub = static_cast<int>(b_numPoints);
    if ((static_cast<int>(((static_cast<int>(b_numPoints)) * 2) < 4)) != 0) {
      for (int i13{0}; i13 < 2; i13++) {
        for (i16 = 0; i16 < b_loop_ub_tmp; i16++) {
          b_points[i16 + (b_points.size(0) * i13)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i16)

      for (int i13 = 0; i13 < 2; i13++) {
        for (i16 = 0; i16 < p_loop_ub; i16++) {
          b_points[i16 + (b_points.size(0) * i13)] = 0.0;
        }
      }
    }
    t_loop_ub = board45->BoardCoords.size(0);
    v_loop_ub = board45->BoardCoords.size(1);
    b_x.set_size(v_loop_ub, t_loop_ub);
    for (int i20{0}; i20 < t_loop_ub; i20++) {
      for (int i23{0}; i23 < v_loop_ub; i23++) {
        b_x[i23 + (b_x.size(0) * i20)] =
            board45->BoardCoords[i20 + (board45->BoardCoords.size(0) * i23)];
      }
    }
    e_x = b_x.size(0) * b_x.size(1);
    y_loop_ub = e_x;
    if ((static_cast<int>(e_x < 4)) != 0) {
      for (int i26{0}; i26 < e_x; i26++) {
        b_points[i26] = b_x[i26];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i26 = 0; i26 < y_loop_ub; i26++) {
        b_points[i26] = b_x[i26];
      }
    }
    fb_loop_ub = board45->BoardCoords.size(0);
    hb_loop_ub = board45->BoardCoords.size(1);
    y.set_size(hb_loop_ub, fb_loop_ub);
    for (int i33{0}; i33 < fb_loop_ub; i33++) {
      for (int i35{0}; i35 < hb_loop_ub; i35++) {
        y[i35 + (y.size(0) * i33)] =
            board45->BoardCoords[(i33 + (board45->BoardCoords.size(0) * i35)) +
                                 (board45->BoardCoords.size(0) *
                                  board45->BoardCoords.size(1))];
      }
    }
    b_y = y.size(0) * y.size(1);
    mb_loop_ub = b_y;
    if ((static_cast<int>(b_y < 4)) != 0) {
      for (int i38{0}; i38 < b_y; i38++) {
        b_points[i38 + b_points.size(0)] = y[i38];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i38 = 0; i38 < mb_loop_ub; i38++) {
        b_points[i38 + b_points.size(0)] = y[i38];
      }
    }
    boardSize[0] = (static_cast<double>(board45->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(board45->BoardCoords.size(0))) + 1.0;
    b_imagePoints.set_size(b_points.size(0), 2);
    rb_loop_ub = b_points.size(0);
    if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
      for (int i43{0}; i43 < 2; i43++) {
        for (i44 = 0; i44 < rb_loop_ub; i44++) {
          b_imagePoints[i44 + (b_imagePoints.size(0) * i43)] =
              b_points[i44 + (b_points.size(0) * i43)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i44)

      for (int i43 = 0; i43 < 2; i43++) {
        for (i44 = 0; i44 < rb_loop_ub; i44++) {
          b_imagePoints[i44 + (b_imagePoints.size(0) * i43)] =
              b_points[i44 + (b_points.size(0) * i43)];
        }
      }
    }
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_45, b_imagePoints);
  }
  if ((b_imagePoints.size(0) == 0) || (b_imagePoints.size(1) == 0)) {
    int c_siz;
    int d_siz;
    int eb_loop_ub;
    int jb_loop_ub;
    int o_loop_ub;
    int ob_loop_ub;
    int sb_loop_ub;
    int t_N;
    int ub_loop_ub;
    int v_N;
    int vb_loop_ub;
    int w_loop_ub;
    int wb_loop_ub;
    int xb_loop_ub;
    int yb_loop_ub;
    vision::internal::calibration::checkerboard::b_secondDerivCornerMetric(
        p_I, cxy, c45, b_Ix, Iy, Ixy, I_45_45);
    b_Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
    Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
    o_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    u_loop_ub)

    for (int i10 = 0; i10 < o_loop_ub; i10++) {
      u_loop_ub = b_Ix2.size(0);
      for (i15 = 0; i15 < u_loop_ub; i15++) {
        Ix2[i15 + (Ix2.size(0) * i10)] = b_Ix2[i15 + (b_Ix2.size(0) * i10)];
      }
    }
    t_N = b_Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(h_k, u_N)

    for (int g_k = 0; g_k < t_N; g_k++) {
      u_N = Ix2.size(0);
      for (h_k = 0; h_k < u_N; h_k++) {
        Ix2[h_k + (Ix2.size(0) * g_k)] =
            rt_powf_snf(b_Ix[h_k + (b_Ix.size(0) * g_k)], 2.0F);
      }
    }
    b_Iy2.set_size(Iy.size(0), Iy.size(1));
    Iy2.set_size(Iy.size(0), Iy.size(1));
    w_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i25, cb_loop_ub)

    for (int i21 = 0; i21 < w_loop_ub; i21++) {
      cb_loop_ub = b_Iy2.size(0);
      for (i25 = 0; i25 < cb_loop_ub; i25++) {
        Iy2[i25 + (Iy2.size(0) * i21)] = b_Iy2[i25 + (b_Iy2.size(0) * i21)];
      }
    }
    v_N = b_Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, w_N)

    for (int j_k = 0; j_k < v_N; j_k++) {
      w_N = Iy2.size(0);
      for (k_k = 0; k_k < w_N; k_k++) {
        Iy2[k_k + (Iy2.size(0) * j_k)] =
            rt_powf_snf(Iy[k_k + (Iy.size(0) * j_k)], 2.0F);
      }
    }
    b_Ix2.set_size(Ix2.size(0), Ix2.size(1));
    eb_loop_ub = Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i32, kb_loop_ub)

    for (int i28 = 0; i28 < eb_loop_ub; i28++) {
      kb_loop_ub = Ix2.size(0);
      for (i32 = 0; i32 < kb_loop_ub; i32++) {
        b_Ix2[i32 + (b_Ix2.size(0) * i28)] = Ix2[i32 + (Ix2.size(0) * i28)];
      }
    }
    c_imfilter(b_Ix2);
    b_Iy2.set_size(Iy2.size(0), Iy2.size(1));
    jb_loop_ub = Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i37, pb_loop_ub)

    for (int i34 = 0; i34 < jb_loop_ub; i34++) {
      pb_loop_ub = Iy2.size(0);
      for (i37 = 0; i37 < pb_loop_ub; i37++) {
        b_Iy2[i37 + (b_Iy2.size(0) * i34)] = Iy2[i37 + (Iy2.size(0) * i34)];
      }
    }
    c_imfilter(b_Iy2);
    IxIy.set_size(b_Ix.size(0), b_Ix.size(1));
    ob_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i41, tb_loop_ub)

    for (int i39 = 0; i39 < ob_loop_ub; i39++) {
      tb_loop_ub = b_Ix.size(0);
      for (i41 = 0; i41 < tb_loop_ub; i41++) {
        IxIy[i41 + (IxIy.size(0) * i39)] =
            b_Ix[i41 + (b_Ix.size(0) * i39)] * Iy[i41 + (Iy.size(0) * i39)];
      }
    }
    c_imfilter(IxIy);
    vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
    siz_idx_0 = cxy.size(0);
    c_siz = cxy.size(0);
    sb_loop_ub = points0.size(0);
    r.set_size(points0.size(0));
    ub_loop_ub = points0.size(0);
    if ((static_cast<int>(points0.size(0) < 4)) != 0) {
      for (int i45{0}; i45 < sb_loop_ub; i45++) {
        r[i45] = (static_cast<int>(points0[i45 + points0.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points0[i45])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i45 = 0; i45 < ub_loop_ub; i45++) {
        r[i45] = (static_cast<int>(points0[i45 + points0.size(0)])) +
                 (c_siz * ((static_cast<int>(points0[i45])) - 1));
      }
    }
    b_cxy.set_size(r.size(0));
    vb_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i46{0}; i46 < vb_loop_ub; i46++) {
        b_cxy[i46] = cxy[r[i46] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i46 = 0; i46 < vb_loop_ub; i46++) {
        b_cxy[i46] = cxy[r[i46] - 1];
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
    wb_loop_ub = points45.size(0);
    r.set_size(points45.size(0));
    xb_loop_ub = points45.size(0);
    if ((static_cast<int>(points45.size(0) < 4)) != 0) {
      for (int i47{0}; i47 < wb_loop_ub; i47++) {
        r[i47] = (static_cast<int>(points45[i47 + points45.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points45[i47])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i47 = 0; i47 < xb_loop_ub; i47++) {
        r[i47] = (static_cast<int>(points45[i47 + points45.size(0)])) +
                 (d_siz * ((static_cast<int>(points45[i47])) - 1));
      }
    }
    b_c45.set_size(r.size(0));
    yb_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i48{0}; i48 < yb_loop_ub; i48++) {
        b_c45[i48] = c45[r[i48] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i48 = 0; i48 < yb_loop_ub; i48++) {
        b_c45[i48] = c45[r[i48] - 1];
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
          int i52;
          int i59;
          int q_n;
          int s_n;
          c_board0 = d_board0->BoardIdx.size(0) * d_board0->BoardIdx.size(1);
          s.set_size(c_board0);
          for (int i49{0}; i49 < c_board0; i49++) {
            s[i49] = d_board0->BoardIdx[i49];
          }
          q_n = 0;
          i52 = s.size(0);
          for (int m_k{0}; m_k < i52; m_k++) {
            if (s[m_k] != 0.0) {
              q_n++;
            }
          }
          c_board45 = d_board45->BoardIdx.size(0) * d_board45->BoardIdx.size(1);
          s.set_size(c_board45);
          for (int i56{0}; i56 < c_board45; i56++) {
            s[i56] = d_board45->BoardIdx[i56];
          }
          s_n = 0;
          i59 = s.size(0);
          for (int o_k{0}; o_k < i59; o_k++) {
            if (s[o_k] != 0.0) {
              s_n++;
            }
          }
          if (q_n > s_n) {
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
      int ac_loop_ub;
      int c_loop_ub_tmp;
      int cc_loop_ub;
      int dc_loop_ub;
      int gc_loop_ub;
      int ic_loop_ub;
      int jc_loop_ub;
      int oc_loop_ub;
      int qc_loop_ub;
      d_board0 =
          vision::internal::calibration::checkerboard::orient(d_board0, p_I);
      c_numPoints = (static_cast<double>(d_board0->BoardCoords.size(0))) *
                    (static_cast<double>(d_board0->BoardCoords.size(1)));
      c_loop_ub_tmp = static_cast<int>(c_numPoints);
      b_points.set_size(c_loop_ub_tmp, 2);
      ac_loop_ub = static_cast<int>(c_numPoints);
      if ((static_cast<int>(((static_cast<int>(c_numPoints)) * 2) < 4)) != 0) {
        for (int i50{0}; i50 < 2; i50++) {
          for (i51 = 0; i51 < c_loop_ub_tmp; i51++) {
            b_points[i51 + (b_points.size(0) * i50)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i51)

        for (int i50 = 0; i50 < 2; i50++) {
          for (i51 = 0; i51 < ac_loop_ub; i51++) {
            b_points[i51 + (b_points.size(0) * i50)] = 0.0;
          }
        }
      }
      cc_loop_ub = d_board0->BoardCoords.size(0);
      dc_loop_ub = d_board0->BoardCoords.size(1);
      b_x.set_size(dc_loop_ub, cc_loop_ub);
      for (int i55{0}; i55 < cc_loop_ub; i55++) {
        for (int i57{0}; i57 < dc_loop_ub; i57++) {
          b_x[i57 + (b_x.size(0) * i55)] =
              d_board0
                  ->BoardCoords[i55 + (d_board0->BoardCoords.size(0) * i57)];
        }
      }
      e_x = b_x.size(0) * b_x.size(1);
      gc_loop_ub = e_x;
      if ((static_cast<int>(e_x < 4)) != 0) {
        for (int i61{0}; i61 < e_x; i61++) {
          b_points[i61] = b_x[i61];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i61 = 0; i61 < gc_loop_ub; i61++) {
          b_points[i61] = b_x[i61];
        }
      }
      ic_loop_ub = d_board0->BoardCoords.size(0);
      jc_loop_ub = d_board0->BoardCoords.size(1);
      y.set_size(jc_loop_ub, ic_loop_ub);
      for (int i63{0}; i63 < ic_loop_ub; i63++) {
        for (int i64{0}; i64 < jc_loop_ub; i64++) {
          y[i64 + (y.size(0) * i63)] =
              d_board0
                  ->BoardCoords[(i63 + (d_board0->BoardCoords.size(0) * i64)) +
                                (d_board0->BoardCoords.size(0) *
                                 d_board0->BoardCoords.size(1))];
        }
      }
      b_y = y.size(0) * y.size(1);
      oc_loop_ub = b_y;
      if ((static_cast<int>(b_y < 4)) != 0) {
        for (int i67{0}; i67 < b_y; i67++) {
          b_points[i67 + b_points.size(0)] = y[i67];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i67 = 0; i67 < oc_loop_ub; i67++) {
          b_points[i67 + b_points.size(0)] = y[i67];
        }
      }
      boardSize[0] = (static_cast<double>(d_board0->BoardCoords.size(1))) + 1.0;
      boardSize[1] = (static_cast<double>(d_board0->BoardCoords.size(0))) + 1.0;
      b_imagePoints.set_size(b_points.size(0), 2);
      qc_loop_ub = b_points.size(0);
      if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
        for (int i69{0}; i69 < 2; i69++) {
          for (i70 = 0; i70 < qc_loop_ub; i70++) {
            b_imagePoints[i70 + (b_imagePoints.size(0) * i69)] =
                b_points[i70 + (b_points.size(0) * i69)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i70)

        for (int i69 = 0; i69 < 2; i69++) {
          for (i70 = 0; i70 < qc_loop_ub; i70++) {
            b_imagePoints[i70 + (b_imagePoints.size(0) * i69)] =
                b_points[i70 + (b_points.size(0) * i69)];
          }
        }
      }
      vision::internal::calibration::checkerboard::subPixelLocation(
          Ixy, b_imagePoints);
    }
    if (guard1 && (d_board45->isValid)) {
      double d_numPoints;
      int bc_loop_ub;
      int d_loop_ub_tmp;
      int ec_loop_ub;
      int fc_loop_ub;
      int hc_loop_ub;
      int kc_loop_ub;
      int mc_loop_ub;
      int pc_loop_ub;
      int rc_loop_ub;
      d_board45 =
          vision::internal::calibration::checkerboard::orient(d_board45, p_I);
      d_numPoints = (static_cast<double>(d_board45->BoardCoords.size(0))) *
                    (static_cast<double>(d_board45->BoardCoords.size(1)));
      d_loop_ub_tmp = static_cast<int>(d_numPoints);
      b_points.set_size(d_loop_ub_tmp, 2);
      bc_loop_ub = static_cast<int>(d_numPoints);
      if ((static_cast<int>(((static_cast<int>(d_numPoints)) * 2) < 4)) != 0) {
        for (int i53{0}; i53 < 2; i53++) {
          for (i54 = 0; i54 < d_loop_ub_tmp; i54++) {
            b_points[i54 + (b_points.size(0) * i53)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i54)

        for (int i53 = 0; i53 < 2; i53++) {
          for (i54 = 0; i54 < bc_loop_ub; i54++) {
            b_points[i54 + (b_points.size(0) * i53)] = 0.0;
          }
        }
      }
      ec_loop_ub = d_board45->BoardCoords.size(0);
      fc_loop_ub = d_board45->BoardCoords.size(1);
      b_x.set_size(fc_loop_ub, ec_loop_ub);
      for (int i58{0}; i58 < ec_loop_ub; i58++) {
        for (int i60{0}; i60 < fc_loop_ub; i60++) {
          b_x[i60 + (b_x.size(0) * i58)] =
              d_board45
                  ->BoardCoords[i58 + (d_board45->BoardCoords.size(0) * i60)];
        }
      }
      e_x = b_x.size(0) * b_x.size(1);
      hc_loop_ub = e_x;
      if ((static_cast<int>(e_x < 4)) != 0) {
        for (int i62{0}; i62 < e_x; i62++) {
          b_points[i62] = b_x[i62];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i62 = 0; i62 < hc_loop_ub; i62++) {
          b_points[i62] = b_x[i62];
        }
      }
      kc_loop_ub = d_board45->BoardCoords.size(0);
      mc_loop_ub = d_board45->BoardCoords.size(1);
      y.set_size(mc_loop_ub, kc_loop_ub);
      for (int i65{0}; i65 < kc_loop_ub; i65++) {
        for (int i66{0}; i66 < mc_loop_ub; i66++) {
          y[i66 + (y.size(0) * i65)] =
              d_board45
                  ->BoardCoords[(i65 + (d_board45->BoardCoords.size(0) * i66)) +
                                (d_board45->BoardCoords.size(0) *
                                 d_board45->BoardCoords.size(1))];
        }
      }
      b_y = y.size(0) * y.size(1);
      pc_loop_ub = b_y;
      if ((static_cast<int>(b_y < 4)) != 0) {
        for (int i68{0}; i68 < b_y; i68++) {
          b_points[i68 + b_points.size(0)] = y[i68];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i68 = 0; i68 < pc_loop_ub; i68++) {
          b_points[i68 + b_points.size(0)] = y[i68];
        }
      }
      boardSize[0] =
          (static_cast<double>(d_board45->BoardCoords.size(1))) + 1.0;
      boardSize[1] =
          (static_cast<double>(d_board45->BoardCoords.size(0))) + 1.0;
      b_imagePoints.set_size(b_points.size(0), 2);
      rc_loop_ub = b_points.size(0);
      if ((static_cast<int>((b_points.size(0) * 2) < 4)) != 0) {
        for (int i71{0}; i71 < 2; i71++) {
          for (i72 = 0; i72 < rc_loop_ub; i72++) {
            b_imagePoints[i72 + (b_imagePoints.size(0) * i71)] =
                b_points[i72 + (b_points.size(0) * i71)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i72)

        for (int i71 = 0; i71 < 2; i71++) {
          for (i72 = 0; i72 < rc_loop_ub; i72++) {
            b_imagePoints[i72 + (b_imagePoints.size(0) * i71)] =
                b_points[i72 + (b_points.size(0) * i71)];
          }
        }
      }
      vision::internal::calibration::checkerboard::subPixelLocation(
          I_45_45, b_imagePoints);
    }
  }
  if ((b_imagePoints.size(0) != 0) && (b_imagePoints.size(1) != 0)) {
    int bb_loop_ub;
    int end;
    int m_loop_ub;
    int partialTrueCount;
    int q_loop_ub;
    int trueCount;
    m_loop_ub = b_imagePoints.size(0);
    zeroIdx.set_size(b_imagePoints.size(0));
    q_loop_ub = b_imagePoints.size(0);
    if ((static_cast<int>(b_imagePoints.size(0) < 4)) != 0) {
      for (int i14{0}; i14 < m_loop_ub; i14++) {
        zeroIdx[i14] = (b_imagePoints[i14] == 0.0);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i14 = 0; i14 < q_loop_ub; i14++) {
        zeroIdx[i14] = (b_imagePoints[i14] == 0.0);
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
    bb_loop_ub = b_imagePoints.size(1);
    for (int i27{0}; i27 < bb_loop_ub; i27++) {
      int gb_loop_ub;
      gb_loop_ub = r1.size(0);
      for (int i30{0}; i30 < gb_loop_ub; i30++) {
        b_imagePoints[(r1[i30] + (b_imagePoints.size(0) * i27)) - 1] = rtNaN;
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
  ::coder::array<double, 1U> s;
  ::coder::array<float, 2U> I_45_45;
  ::coder::array<float, 2U> Ix2;
  ::coder::array<float, 2U> IxIy;
  ::coder::array<float, 2U> Ixy;
  ::coder::array<float, 2U> Iy;
  ::coder::array<float, 2U> Iy2;
  ::coder::array<float, 2U> b_Ix;
  ::coder::array<float, 2U> b_Ix2;
  ::coder::array<float, 2U> b_Iy2;
  ::coder::array<float, 2U> c45;
  ::coder::array<float, 2U> cxy;
  ::coder::array<float, 2U> p_I;
  ::coder::array<float, 2U> points0;
  ::coder::array<float, 2U> points45;
  ::coder::array<float, 1U> b_c45;
  ::coder::array<float, 1U> b_cxy;
  ::coder::array<int, 1U> r;
  double b_board0[2];
  double b_board45[2];
  int b_k;
  int b_loop_ub;
  int b_siz;
  int c_board0;
  int c_board45;
  int c_loop_ub;
  int d_k;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_k;
  int h_loop_ub;
  int i1;
  int i11;
  int i15;
  int i17;
  int i19;
  int i21;
  int i3;
  int i_N;
  int i_loop_ub;
  int j_loop_ub;
  int k_N;
  int k_k;
  int loop_ub;
  int m_N;
  int m_loop_ub;
  int o_N;
  int p_loop_ub;
  int s_loop_ub;
  int siz;
  int siz_idx_0;
  int u_N;
  int u_loop_ub;
  int w_N;
  int w_loop_ub;
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
      p_I, cxy, c45, b_Ix, Iy, Ixy, I_45_45);
  Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
  i_N = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, m_N)

  for (int k = 0; k < i_N; k++) {
    m_N = Ix2.size(0);
    for (b_k = 0; b_k < m_N; b_k++) {
      Ix2[b_k + (Ix2.size(0) * k)] =
          rt_powf_snf(b_Ix[b_k + (b_Ix.size(0) * k)], 2.0F);
    }
  }
  Iy2.set_size(Iy.size(0), Iy.size(1));
  k_N = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_k, o_N)

  for (int c_k = 0; c_k < k_N; c_k++) {
    o_N = Iy2.size(0);
    for (d_k = 0; d_k < o_N; d_k++) {
      Iy2[d_k + (Iy2.size(0) * c_k)] =
          rt_powf_snf(Iy[d_k + (Iy.size(0) * c_k)], 2.0F);
    }
  }
  c_imfilter(Ix2);
  c_imfilter(Iy2);
  IxIy.set_size(b_Ix.size(0), b_Ix.size(1));
  c_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    e_loop_ub)

  for (int i2 = 0; i2 < c_loop_ub; i2++) {
    e_loop_ub = b_Ix.size(0);
    for (i3 = 0; i3 < e_loop_ub; i3++) {
      IxIy[i3 + (IxIy.size(0) * i2)] =
          b_Ix[i3 + (b_Ix.size(0) * i2)] * Iy[i3 + (Iy.size(0) * i2)];
    }
  }
  c_imfilter(IxIy);
  vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
  siz_idx_0 = cxy.size(0);
  siz = cxy.size(0);
  d_loop_ub = points0.size(0);
  r.set_size(points0.size(0));
  f_loop_ub = points0.size(0);
  if ((static_cast<int>(points0.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < d_loop_ub; i4++) {
      r[i4] = (static_cast<int>(points0[i4 + points0.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points0[i4])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < f_loop_ub; i4++) {
      r[i4] = (static_cast<int>(points0[i4 + points0.size(0)])) +
              (siz * ((static_cast<int>(points0[i4])) - 1));
    }
  }
  b_cxy.set_size(r.size(0));
  g_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i5{0}; i5 < g_loop_ub; i5++) {
      b_cxy[i5] = cxy[r[i5] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < g_loop_ub; i5++) {
      b_cxy[i5] = cxy[r[i5] - 1];
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
  h_loop_ub = points45.size(0);
  r.set_size(points45.size(0));
  i_loop_ub = points45.size(0);
  if ((static_cast<int>(points45.size(0) < 4)) != 0) {
    for (int i6{0}; i6 < h_loop_ub; i6++) {
      r[i6] = (static_cast<int>(points45[i6 + points45.size(0)])) +
              (siz_idx_0 * ((static_cast<int>(points45[i6])) - 1));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < i_loop_ub; i6++) {
      r[i6] = (static_cast<int>(points45[i6 + points45.size(0)])) +
              (b_siz * ((static_cast<int>(points45[i6])) - 1));
    }
  }
  b_c45.set_size(r.size(0));
  j_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i7{0}; i7 < j_loop_ub; i7++) {
      b_c45[i7] = c45[r[i7] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < j_loop_ub; i7++) {
      b_c45[i7] = c45[r[i7] - 1];
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
        int i10;
        int i14;
        int p_n;
        c_board0 = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(c_board0);
        for (int b_i8{0}; b_i8 < c_board0; b_i8++) {
          s[b_i8] = board0->BoardIdx[b_i8];
        }
        h_n = 0;
        i10 = s.size(0);
        for (int e_k{0}; e_k < i10; e_k++) {
          if (s[e_k] != 0.0) {
            h_n++;
          }
        }
        c_board45 = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(c_board45);
        for (int i12{0}; i12 < c_board45; i12++) {
          s[i12] = board45->BoardIdx[i12];
        }
        p_n = 0;
        i14 = s.size(0);
        for (int i_k{0}; i_k < i14; i_k++) {
          if (s[i_k] != 0.0) {
            p_n++;
          }
        }
        if (h_n > p_n) {
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
    int ab_loop_ub;
    int bb_loop_ub;
    int c_siz;
    int cb_loop_ub;
    int d_siz;
    int k_loop_ub;
    int o_loop_ub;
    int q_loop_ub;
    int r_loop_ub;
    int t_N;
    int t_loop_ub;
    int v_N;
    int v_loop_ub;
    int x_loop_ub;
    int y_loop_ub;
    vision::internal::calibration::checkerboard::b_secondDerivCornerMetric(
        p_I, cxy, c45, b_Ix, Iy, Ixy, I_45_45);
    b_Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
    Ix2.set_size(b_Ix.size(0), b_Ix.size(1));
    k_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11,       \
                                                                    m_loop_ub)

    for (int i9 = 0; i9 < k_loop_ub; i9++) {
      m_loop_ub = b_Ix2.size(0);
      for (i11 = 0; i11 < m_loop_ub; i11++) {
        Ix2[i11 + (Ix2.size(0) * i9)] = b_Ix2[i11 + (b_Ix2.size(0) * i9)];
      }
    }
    t_N = b_Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(h_k, u_N)

    for (int g_k = 0; g_k < t_N; g_k++) {
      u_N = Ix2.size(0);
      for (h_k = 0; h_k < u_N; h_k++) {
        Ix2[h_k + (Ix2.size(0) * g_k)] =
            rt_powf_snf(b_Ix[h_k + (b_Ix.size(0) * g_k)], 2.0F);
      }
    }
    b_Iy2.set_size(Iy.size(0), Iy.size(1));
    Iy2.set_size(Iy.size(0), Iy.size(1));
    o_loop_ub = Iy.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15,       \
                                                                    p_loop_ub)

    for (int i13 = 0; i13 < o_loop_ub; i13++) {
      p_loop_ub = b_Iy2.size(0);
      for (i15 = 0; i15 < p_loop_ub; i15++) {
        Iy2[i15 + (Iy2.size(0) * i13)] = b_Iy2[i15 + (b_Iy2.size(0) * i13)];
      }
    }
    v_N = b_Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_k, w_N)

    for (int j_k = 0; j_k < v_N; j_k++) {
      w_N = Iy2.size(0);
      for (k_k = 0; k_k < w_N; k_k++) {
        Iy2[k_k + (Iy2.size(0) * j_k)] =
            rt_powf_snf(Iy[k_k + (Iy.size(0) * j_k)], 2.0F);
      }
    }
    b_Ix2.set_size(Ix2.size(0), Ix2.size(1));
    q_loop_ub = Ix2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i17,       \
                                                                    s_loop_ub)

    for (int i16 = 0; i16 < q_loop_ub; i16++) {
      s_loop_ub = Ix2.size(0);
      for (i17 = 0; i17 < s_loop_ub; i17++) {
        b_Ix2[i17 + (b_Ix2.size(0) * i16)] = Ix2[i17 + (Ix2.size(0) * i16)];
      }
    }
    c_imfilter(b_Ix2);
    b_Iy2.set_size(Iy2.size(0), Iy2.size(1));
    r_loop_ub = Iy2.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19,       \
                                                                    u_loop_ub)

    for (int i18 = 0; i18 < r_loop_ub; i18++) {
      u_loop_ub = Iy2.size(0);
      for (i19 = 0; i19 < u_loop_ub; i19++) {
        b_Iy2[i19 + (b_Iy2.size(0) * i18)] = Iy2[i19 + (Iy2.size(0) * i18)];
      }
    }
    c_imfilter(b_Iy2);
    IxIy.set_size(b_Ix.size(0), b_Ix.size(1));
    t_loop_ub = b_Ix.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i21,       \
                                                                    w_loop_ub)

    for (int i20 = 0; i20 < t_loop_ub; i20++) {
      w_loop_ub = b_Ix.size(0);
      for (i21 = 0; i21 < w_loop_ub; i21++) {
        IxIy[i21 + (IxIy.size(0) * i20)] =
            b_Ix[i21 + (b_Ix.size(0) * i20)] * Iy[i21 + (Iy.size(0) * i20)];
      }
    }
    c_imfilter(IxIy);
    vision::internal::calibration::checkerboard::find_peaks(cxy, points0);
    siz_idx_0 = cxy.size(0);
    c_siz = cxy.size(0);
    v_loop_ub = points0.size(0);
    r.set_size(points0.size(0));
    x_loop_ub = points0.size(0);
    if ((static_cast<int>(points0.size(0) < 4)) != 0) {
      for (int i22{0}; i22 < v_loop_ub; i22++) {
        r[i22] = (static_cast<int>(points0[i22 + points0.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points0[i22])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i22 = 0; i22 < x_loop_ub; i22++) {
        r[i22] = (static_cast<int>(points0[i22 + points0.size(0)])) +
                 (c_siz * ((static_cast<int>(points0[i22])) - 1));
      }
    }
    b_cxy.set_size(r.size(0));
    y_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i23{0}; i23 < y_loop_ub; i23++) {
        b_cxy[i23] = cxy[r[i23] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i23 = 0; i23 < y_loop_ub; i23++) {
        b_cxy[i23] = cxy[r[i23] - 1];
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
    ab_loop_ub = points45.size(0);
    r.set_size(points45.size(0));
    bb_loop_ub = points45.size(0);
    if ((static_cast<int>(points45.size(0) < 4)) != 0) {
      for (int i24{0}; i24 < ab_loop_ub; i24++) {
        r[i24] = (static_cast<int>(points45[i24 + points45.size(0)])) +
                 (siz_idx_0 * ((static_cast<int>(points45[i24])) - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i24 = 0; i24 < bb_loop_ub; i24++) {
        r[i24] = (static_cast<int>(points45[i24 + points45.size(0)])) +
                 (d_siz * ((static_cast<int>(points45[i24])) - 1));
      }
    }
    b_c45.set_size(r.size(0));
    cb_loop_ub = r.size(0);
    if ((static_cast<int>(r.size(0) < 4)) != 0) {
      for (int i25{0}; i25 < cb_loop_ub; i25++) {
        b_c45[i25] = c45[r[i25] - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i25 = 0; i25 < cb_loop_ub; i25++) {
        b_c45[i25] = c45[r[i25] - 1];
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
          int i27;
          int i29;
          int q_n;
          int s_n;
          c_board0 = d_board0->BoardIdx.size(0) * d_board0->BoardIdx.size(1);
          s.set_size(c_board0);
          for (int i26{0}; i26 < c_board0; i26++) {
            s[i26] = d_board0->BoardIdx[i26];
          }
          q_n = 0;
          i27 = s.size(0);
          for (int m_k{0}; m_k < i27; m_k++) {
            if (s[m_k] != 0.0) {
              q_n++;
            }
          }
          c_board45 = d_board45->BoardIdx.size(0) * d_board45->BoardIdx.size(1);
          s.set_size(c_board45);
          for (int i28{0}; i28 < c_board45; i28++) {
            s[i28] = d_board45->BoardIdx[i28];
          }
          s_n = 0;
          i29 = s.size(0);
          for (int o_k{0}; o_k < i29; o_k++) {
            if (s[o_k] != 0.0) {
              s_n++;
            }
          }
          if (q_n > s_n) {
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
} // namespace ITER

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
