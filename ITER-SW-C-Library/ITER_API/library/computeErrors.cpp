//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "computeErrors.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "bsxfun.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "rotm2axang.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const coder::array<double, 3U> &Hhand2base
//                const double Hhand2eye[4][4]
//                const double Hbase2grid[4][4]
//                const coder::array<double, 3U> &Hcam2grid
//                const coder::array<double, 3U> &imgPts
//                const coder::array<double, 2U> &Worldpts
//                const double f_K[4][3]
//                double errors[3]
// Return Type  : void
//
void computeErrors(const coder::array<double, 3U> &Hhand2base,
                   const double Hhand2eye[4][4], const double Hbase2grid[4][4],
                   const coder::array<double, 3U> &Hcam2grid,
                   const coder::array<double, 3U> &imgPts,
                   const coder::array<double, 2U> &Worldpts,
                   const double f_K[4][3], double errors[3])
{
  coder::array<double, 3U> PoseErrR;
  coder::array<double, 2U> PoseErrt;
  coder::array<double, 2U> b_y;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> d_y;
  coder::array<double, 2U> e_y;
  coder::array<double, 2U> err;
  coder::array<double, 2U> g_x;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 1U> angR;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> r2;
  coder::array<double, 1U> y;
  double HT[4][4];
  double dv1[4][4];
  double dv2[4][4];
  double b_Hhand2base[3][3];
  double b_Hhand2eye[3][3];
  double dv[3][3];
  double AxAngVec[4];
  double b_varargin_1;
  double d10;
  double d11;
  double d12;
  double d13;
  double d9;
  double d_varargin_1;
  int b_imgPts[2];
  int b_result[2];
  int c_result[2];
  int d_result[2];
  int b_i8;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int h_n;
  int i19;
  int i2;
  int i20;
  int i21;
  int i23;
  int i25;
  int i28;
  int i29;
  int i4;
  int i5;
  int i9;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m_loop_ub;
  int o_loop_ub;
  int result;
  signed char b_input_sizes_idx_1;
  signed char c_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  // where the Input:
  // Hhand2base         a 4x4xNumber_of_Views Matrix of the form
  //                    Hhand2base(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  //                    with
  //                    i = number of the view,
  //                    Ri_3x3 the rotation matrix
  //                    ti_3x1 the translation vector.
  // Hhand2eye          a 4x4xNumber_entries_to_examine Matrix of the form
  //                    Hhand2eye(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  // Hbase2grid         a 4x4xNumber_entries_to_examine Matrix of the form
  //                    Hbase2grid(:,:,i) = [Ri_3x3 ti_3x1;[ 0 0 0 1]]
  // Hcam2grid          a 4x4xNumber_of_Views Matrix (like above)
  //                    Defining the transformation of the  camera to the
  //                    grid/calibration block/world
  // K                  The camera intrinsic  (4x4 matrix)
  // imgPts             an array with  containing the imgpoints corresponding to
  // the corner points on the
  //                    calibration board.(Nx2xM), where N is number of corners
  //                    in M images
  //                    and M is the number of calibration images
  // Worldpts           world coordinates of the corners (Nx2) matrix
  // Output:
  // Rerr               The rotation error in degrees corresponding to each
  //                    each entry
  // terr               The translation error in meters corresponding to each
  // each entry ReprojErr          The reprojection error from reprojecting the
  // world/grid
  //                    points on the camera images corresponding to each each
  //                    entry
  //  computing dependencies
  //  % Divide with Z to complete the perspective projection
  if (Worldpts.size(0) != 0) {
    result = Worldpts.size(0);
  } else {
    result = 0;
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = 2;
  } else if (Worldpts.size(0) != 0) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 1;
  } else if (Worldpts.size(0) != 0) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    c_input_sizes_idx_1 = 1;
  } else if (Worldpts.size(0) != 0) {
    c_input_sizes_idx_1 = 1;
  } else {
    c_input_sizes_idx_1 = 0;
  }
  b_result[0] = result;
  b_result[1] = static_cast<int>(input_sizes_idx_1);
  c_result[0] = result;
  c_result[1] = static_cast<int>(b_input_sizes_idx_1);
  d_result[0] = result;
  d_result[1] = static_cast<int>(c_input_sizes_idx_1);
  r.set_size(result, ((static_cast<int>(input_sizes_idx_1)) +
                      (static_cast<int>(b_input_sizes_idx_1))) +
                         (static_cast<int>(c_input_sizes_idx_1)));
  loop_ub = static_cast<int>(input_sizes_idx_1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    d_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    d_loop_ub = b_result[0];
    for (i2 = 0; i2 < d_loop_ub; i2++) {
      r[i2 + (r.size(0) * b_i)] = Worldpts[i2 + (b_result[0] * b_i)];
    }
  }
  b_loop_ub = c_result[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4,        \
                                                                    e_loop_ub)

  for (int i1 = 0; i1 < b_loop_ub; i1++) {
    e_loop_ub = c_result[0];
    for (i4 = 0; i4 < e_loop_ub; i4++) {
      r[i4 + (r.size(0) * b_result[1])] = 0.0;
    }
  }
  c_loop_ub = d_result[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5,        \
                                                                    g_loop_ub)

  for (int i3 = 0; i3 < c_loop_ub; i3++) {
    g_loop_ub = d_result[0];
    for (i5 = 0; i5 < g_loop_ub; i5++) {
      r[i5 + (r.size(0) * (b_result[1] + c_result[1]))] = 1.0;
    }
  }
  //  Computing Errors
  //     %% Computing Rotation errors distribution
  angR.set_size(imgPts.size(2));
  f_loop_ub = imgPts.size(2);
  if ((static_cast<int>(imgPts.size(2) < 4)) != 0) {
    for (int i6{0}; i6 < f_loop_ub; i6++) {
      angR[i6] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < f_loop_ub; i6++) {
      angR[i6] = 0.0;
    }
  }
  PoseErrR.set_size(3, 3, imgPts.size(2));
  h_loop_ub = imgPts.size(2);
  if ((static_cast<int>((imgPts.size(2) * 9) < 4)) != 0) {
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      for (b_i8 = 0; b_i8 < 3; b_i8++) {
        PoseErrR[(3 * b_i8) + (9 * i7)] = 0.0;
        PoseErrR[((3 * b_i8) + (9 * i7)) + 1] = 0.0;
        PoseErrR[((3 * b_i8) + (9 * i7)) + 2] = 0.0;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

    for (int i7 = 0; i7 < h_loop_ub; i7++) {
      for (b_i8 = 0; b_i8 < 3; b_i8++) {
        PoseErrR[(3 * b_i8) + (9 * i7)] = 0.0;
        PoseErrR[((3 * b_i8) + (9 * i7)) + 1] = 0.0;
        PoseErrR[((3 * b_i8) + (9 * i7)) + 2] = 0.0;
      }
    }
  }
  i9 = imgPts.size(2);
  for (int j{0}; j < i9; j++) {
    for (int i10{0}; i10 < 3; i10++) {
      double b_d1;
      double d;
      double d2;
      d = Hhand2eye[0][i10];
      b_d1 = Hhand2eye[1][i10];
      d2 = Hhand2eye[2][i10];
      for (int i15{0}; i15 < 3; i15++) {
        b_Hhand2eye[i15][i10] =
            ((d * Hcam2grid[(4 * i15) + (16 * j)]) +
             (b_d1 * Hcam2grid[((4 * i15) + (16 * j)) + 1])) +
            (d2 * Hcam2grid[((4 * i15) + (16 * j)) + 2]);
      }
    }
    coder::inv(b_Hhand2eye, dv);
    for (int i12{0}; i12 < 3; i12++) {
      for (int i14{0}; i14 < 3; i14++) {
        b_Hhand2base[i14][i12] =
            ((Hhand2base[i12 + (16 * j)] * Hbase2grid[i14][0]) +
             (Hhand2base[(i12 + (16 * j)) + 4] * Hbase2grid[i14][1])) +
            (Hhand2base[(i12 + (16 * j)) + 8] * Hbase2grid[i14][2]);
      }
    }
    for (int i13{0}; i13 < 3; i13++) {
      double d3;
      double d4;
      double d5;
      d3 = dv[0][i13];
      d4 = dv[1][i13];
      d5 = dv[2][i13];
      for (int i17{0}; i17 < 3; i17++) {
        PoseErrR[(i13 + (3 * i17)) + (9 * j)] =
            ((d3 * b_Hhand2base[i17][0]) + (d4 * b_Hhand2base[i17][1])) +
            (d5 * b_Hhand2base[i17][2]);
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    coder::rotm2axang(*((double(*)[3][3])(&PoseErrR[9 * j])), AxAngVec);
    angR[j] = AxAngVec[3] * 57.295779513082323;
  }
  b_x.set_size(angR.size(0));
  i_loop_ub = angR.size(0);
  if ((static_cast<int>(angR.size(0) < 4)) != 0) {
    for (int i11{0}; i11 < i_loop_ub; i11++) {
      double varargin_1;
      varargin_1 = angR[i11];
      b_x[i11] = varargin_1 * varargin_1;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_varargin_1)

    for (int i11 = 0; i11 < i_loop_ub; i11++) {
      b_varargin_1 = angR[i11];
      b_x[i11] = b_varargin_1 * b_varargin_1;
    }
  }
  if (b_x.size(0) == 0) {
    y.set_size(0);
  } else {
    int i16;
    y.set_size(b_x.size(0));
    i16 = b_x.size(0);
    if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
      for (int k{0}; k < i16; k++) {
        y[k] = b_x[k];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < i16; k++) {
        y[k] = b_x[k];
      }
    }
  }
  b_x.set_size(y.size(0));
  j_loop_ub = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int i18{0}; i18 < j_loop_ub; i18++) {
      b_x[i18] = y[i18];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < j_loop_ub; i18++) {
      b_x[i18] = y[i18];
    }
  }
  i19 = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int b_k{0}; b_k < i19; b_k++) {
      b_x[b_k] = std::sqrt(b_x[b_k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_k = 0; b_k < i19; b_k++) {
      b_x[b_k] = std::sqrt(b_x[b_k]);
    }
  }
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(imgPts.size(2), 3);
  i20 = imgPts.size(2);
  if ((static_cast<int>((imgPts.size(2) * 9) < 4)) != 0) {
    for (int b_j{0}; b_j < i20; b_j++) {
      double d6;
      double d7;
      double d8;
      d6 = Hbase2grid[3][0];
      d7 = Hbase2grid[3][1];
      d8 = Hbase2grid[3][2];
      for (i21 = 0; i21 < 3; i21++) {
        PoseErrt[b_j + (PoseErrt.size(0) * i21)] =
            ((((Hhand2base[i21 + (16 * b_j)] * d6) +
               (Hhand2base[(i21 + (16 * b_j)) + 4] * d7)) +
              (Hhand2base[(i21 + (16 * b_j)) + 8] * d8)) +
             Hhand2base[(i21 + (16 * b_j)) + 12]) -
            ((((Hhand2eye[0][i21] * Hcam2grid[(16 * b_j) + 12]) +
               (Hhand2eye[1][i21] * Hcam2grid[(16 * b_j) + 13])) +
              (Hhand2eye[2][i21] * Hcam2grid[(16 * b_j) + 14])) +
             Hhand2eye[3][i21]);
      }
      // (Ra*tx)+ta -(Rz*tb)+tz
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d9, d10, i21, d11, d12, d13)

    for (int b_j = 0; b_j < i20; b_j++) {
      d11 = Hbase2grid[3][0];
      d12 = Hbase2grid[3][1];
      d13 = Hbase2grid[3][2];
      for (i21 = 0; i21 < 3; i21++) {
        d10 = ((Hhand2base[i21 + (16 * b_j)] * d11) +
               (Hhand2base[(i21 + (16 * b_j)) + 4] * d12)) +
              (Hhand2base[(i21 + (16 * b_j)) + 8] * d13);
        d9 = ((Hhand2eye[0][i21] * Hcam2grid[(16 * b_j) + 12]) +
              (Hhand2eye[1][i21] * Hcam2grid[(16 * b_j) + 13])) +
             (Hhand2eye[2][i21] * Hcam2grid[(16 * b_j) + 14]);
        PoseErrt[b_j + (PoseErrt.size(0) * i21)] =
            (d10 + Hhand2base[(i21 + (16 * b_j)) + 12]) -
            (d9 + Hhand2eye[3][i21]);
      }
      // (Ra*tx)+ta -(Rz*tb)+tz
    }
  }
  b_y.set_size(PoseErrt.size(0), 3);
  k_loop_ub = PoseErrt.size(0);
  if ((static_cast<int>((3 * PoseErrt.size(0)) < 4)) != 0) {
    for (int i22{0}; i22 < 3; i22++) {
      for (i23 = 0; i23 < k_loop_ub; i23++) {
        double c_varargin_1;
        c_varargin_1 = PoseErrt[i23 + (PoseErrt.size(0) * i22)];
        b_y[i23 + (b_y.size(0) * i22)] = c_varargin_1 * c_varargin_1;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i23, d_varargin_1)

    for (int i22 = 0; i22 < 3; i22++) {
      for (i23 = 0; i23 < k_loop_ub; i23++) {
        d_varargin_1 = PoseErrt[i23 + (PoseErrt.size(0) * i22)];
        b_y[i23 + (b_y.size(0) * i22)] = d_varargin_1 * d_varargin_1;
      }
    }
  }
  if (b_y.size(0) == 0) {
    y.set_size(0);
  } else {
    int i24;
    int i26;
    y.set_size(b_y.size(0));
    i24 = b_y.size(0);
    if ((static_cast<int>(b_y.size(0) < 4)) != 0) {
      for (int c_k{0}; c_k < i24; c_k++) {
        y[c_k] = b_y[c_k];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_k = 0; c_k < i24; c_k++) {
        y[c_k] = b_y[c_k];
      }
    }
    i26 = b_y.size(0);
    for (int e_k{0}; e_k < 2; e_k++) {
      for (int g_k{0}; g_k < i26; g_k++) {
        y[g_k] = y[g_k] + b_y[g_k + (b_y.size(0) * (e_k + 1))];
      }
    }
  }
  i25 = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int d_k{0}; d_k < i25; d_k++) {
      y[d_k] = std::sqrt(y[d_k]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int d_k = 0; d_k < i25; d_k++) {
      y[d_k] = std::sqrt(y[d_k]);
    }
  }
  //     %% Computing Reprojection errors
  b_imgPts[0] = imgPts.size(0);
  err.set_size(imgPts.size(0), imgPts.size(2));
  m_loop_ub = imgPts.size(2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i29,       \
                                                                    o_loop_ub)

  for (int i27 = 0; i27 < m_loop_ub; i27++) {
    o_loop_ub = b_imgPts[0];
    for (i29 = 0; i29 < o_loop_ub; i29++) {
      err[i29 + (err.size(0) * i27)] = 0.0;
    }
  }
  i28 = imgPts.size(2);
  if (0 <= (imgPts.size(2) - 1)) {
    coder::b_inv(Hhand2eye, dv1);
    h_n = r.size(0);
  }
  for (int c_j{0}; c_j < i28; c_j++) {
    int i_n;
    int p_loop_ub;
    int q_loop_ub;
    int r_loop_ub;
    for (int i30{0}; i30 < 4; i30++) {
      for (int i31{0}; i31 < 4; i31++) {
        double d14;
        d14 = 0.0;
        for (int i33{0}; i33 < 4; i33++) {
          d14 += dv1[i33][i30] * Hhand2base[(i33 + (4 * i31)) + (16 * c_j)];
        }
        dv2[i31][i30] = d14;
      }
      for (int i32{0}; i32 < 4; i32++) {
        double d15;
        d15 = 0.0;
        for (int i34{0}; i34 < 4; i34++) {
          d15 += dv2[i34][i30] * Hbase2grid[i32][i34];
        }
        HT[i32][i30] = d15;
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    c_y.set_size(4, r.size(0));
    for (int d_j{0}; d_j < h_n; d_j++) {
      for (int c_i{0}; c_i < 4; c_i++) {
        double s;
        s = 0.0;
        for (int h_k{0}; h_k < 4; h_k++) {
          s += HT[h_k][c_i] * r[d_j + (r.size(0) * h_k)];
        }
        c_y[c_i + (4 * d_j)] = s;
      }
    }
    i_n = c_y.size(1);
    d_y.set_size(3, c_y.size(1));
    for (int e_j{0}; e_j < i_n; e_j++) {
      for (int d_i{0}; d_i < 3; d_i++) {
        double b_s;
        b_s = 0.0;
        for (int i_k{0}; i_k < 4; i_k++) {
          b_s += f_K[i_k][d_i] * c_y[i_k + (4 * e_j)];
        }
        d_y[d_i + (3 * e_j)] = b_s;
      }
    }
    p_loop_ub = d_y.size(1);
    e_y.set_size(1, d_y.size(1));
    for (int i35{0}; i35 < p_loop_ub; i35++) {
      e_y[i35] = d_y[(3 * i35) + 2];
    }
    coder::b_bsxfun(d_y, e_y, g_x);
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    q_loop_ub = imgPts.size(0);
    if (imgPts.size(0) == g_x.size(1)) {
      r1.set_size(imgPts.size(0), 2);
      for (int i36{0}; i36 < 2; i36++) {
        for (int i37{0}; i37 < q_loop_ub; i37++) {
          double e_varargin_1;
          e_varargin_1 = imgPts[(i37 + (imgPts.size(0) * i36)) +
                                ((imgPts.size(0) * 2) * c_j)] -
                         g_x[i36 + (3 * i37)];
          r1[i37 + (r1.size(0) * i36)] = e_varargin_1 * e_varargin_1;
        }
      }
    } else {
      b_binary_expand_op(r1, imgPts, c_j, g_x);
    }
    coder::sum(r1, r2);
    r_loop_ub = r2.size(0);
    for (int i38{0}; i38 < r_loop_ub; i38++) {
      err[i38 + (err.size(0) * c_j)] = r2[i38];
    }
    //  adopted approach
  }
  coder::array<double, 1U> c_err;
  int b_err;
  // rrmse
  b_err = err.size(0) * err.size(1);
  errors[0] =
      coder::combineVectorElements(b_x) / (static_cast<double>(b_x.size(0)));
  errors[1] =
      coder::combineVectorElements(y) / (static_cast<double>(y.size(0)));
  c_err = err.reshape(b_err);
  errors[2] = std::sqrt(
      coder::combineVectorElements(c_err) /
      (static_cast<double>(static_cast<int>(err.size(0) * err.size(1)))));
}

//
// File trailer for computeErrors.cpp
//
// [EOF]
//
