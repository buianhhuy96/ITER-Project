//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "computeErrors.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_initialize.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "rotm2axang.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
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
//
// Arguments    : const coder::array<double, 3U> &Hhand2base
//                const double Hhand2eye[4][4]
//                const double Hbase2grid[4][4]
//                const coder::array<double, 3U> &Hcam2grid
//                const coder::array<double, 3U> &imgPts
//                const coder::array<double, 2U> &Worldpts
//                const double k_K[4][3]
//                double errors[3]
// Return Type  : void
//
void computeErrors(const coder::array<double, 3U> &Hhand2base,
                   const double Hhand2eye[4][4], const double Hbase2grid[4][4],
                   const coder::array<double, 3U> &Hcam2grid,
                   const coder::array<double, 3U> &imgPts,
                   const coder::array<double, 2U> &Worldpts,
                   const double k_K[4][3], double errors[3])
{
  coder::array<double, 3U> PoseErrR;
  coder::array<double, 2U> PoseErrt;
  coder::array<double, 2U> d_x;
  coder::array<double, 2U> d_y;
  coder::array<double, 2U> e_x;
  coder::array<double, 2U> err;
  coder::array<double, 2U> g_y;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 1U> angR;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> c_x;
  coder::array<double, 1U> r2;
  coder::array<double, 1U> y;
  double HT[4][4];
  double b_y[4][4];
  double d_A[4][4];
  double e_y[4][4];
  double b_Hhand2base[3][3];
  double b_Hhand2eye[3][3];
  double dv[3][3];
  double AxAngVec[4];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i16;
  int i20;
  int i25;
  int i30;
  int i9;
  int i_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int result;
  signed char ipiv[4];
  signed char p[4];
  signed char b_input_sizes_idx_1;
  signed char c_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_ITER_API_v2) {
    ITER_API_v2_initialize();
  }
  // Output:
  // Rerr               The rotation error in degrees corresponding to each
  //                    each entry
  // terr               The translation error in meters corresponding to each
  // each entry Rterr              The combined Rotation and translation error
  // corresponding to each each entry ReprojErr          The reprojection error
  // from reprojecting the world/grid
  //                    points on the camera images corresponding to each each
  //                    entry
  // AbsoluteErr        The combined error from ground truth Transformations
  //                    corresponding to each entry
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
  r.set_size(result, ((static_cast<int>(input_sizes_idx_1)) +
                      (static_cast<int>(b_input_sizes_idx_1))) +
                         (static_cast<int>(c_input_sizes_idx_1)));
  loop_ub = static_cast<int>(input_sizes_idx_1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    for (int i1{0}; i1 < result; i1++) {
      r[i1 + (r.size(0) * b_i)] = Worldpts[i1 + (result * b_i)];
    }
  }
  b_loop_ub = static_cast<int>(b_input_sizes_idx_1);
  for (int i2{0}; i2 < b_loop_ub; i2++) {
    for (int i3{0}; i3 < result; i3++) {
      r[i3 + (r.size(0) * (static_cast<int>(input_sizes_idx_1)))] = 0.0;
    }
  }
  c_loop_ub = static_cast<int>(c_input_sizes_idx_1);
  for (int i4{0}; i4 < c_loop_ub; i4++) {
    for (int i5{0}; i5 < result; i5++) {
      r[i5 + (r.size(0) * ((static_cast<int>(input_sizes_idx_1)) +
                           (static_cast<int>(b_input_sizes_idx_1))))] = 1.0;
    }
  }
  //  Computing Errors
  //     %% Computing Rotation errors distribution
  angR.set_size(imgPts.size(2));
  d_loop_ub = imgPts.size(2);
  for (int i6{0}; i6 < d_loop_ub; i6++) {
    angR[i6] = 0.0;
  }
  PoseErrR.set_size(3, 3, imgPts.size(2));
  e_loop_ub = imgPts.size(2);
  for (int i7{0}; i7 < e_loop_ub; i7++) {
    for (int i8{0}; i8 < 3; i8++) {
      PoseErrR[(3 * i8) + (9 * i7)] = 0.0;
      PoseErrR[((3 * i8) + (9 * i7)) + 1] = 0.0;
      PoseErrR[((3 * i8) + (9 * i7)) + 2] = 0.0;
    }
  }
  // %%%%%%% length(Hcam2grid) -> number of images
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
      for (int i19{0}; i19 < 3; i19++) {
        PoseErrR[(i13 + (3 * i19)) + (9 * j)] =
            ((d3 * b_Hhand2base[i19][0]) + (d4 * b_Hhand2base[i19][1])) +
            (d5 * b_Hhand2base[i19][2]);
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    coder::rotm2axang(*((double(*)[3][3])(&PoseErrR[9 * j])), AxAngVec);
    angR[j] = AxAngVec[3] * 57.295779513082323;
  }
  b_x.set_size(angR.size(0));
  f_loop_ub = angR.size(0);
  for (int i11{0}; i11 < f_loop_ub; i11++) {
    double varargin_1;
    varargin_1 = angR[i11];
    b_x[i11] = varargin_1 * varargin_1;
  }
  if (b_x.size(0) == 0) {
    c_x.set_size(0);
  } else {
    int g_loop_ub;
    int h_loop_ub;
    int i18;
    c_x.set_size(b_x.size(0));
    y.set_size(b_x.size(0));
    g_loop_ub = b_x.size(0);
    for (int i17{0}; i17 < g_loop_ub; i17++) {
      y[i17] = c_x[i17];
    }
    i18 = b_x.size(0);
    for (int b_k{0}; b_k < i18; b_k++) {
      y[b_k] = b_x[b_k];
    }
    c_x.set_size(y.size(0));
    h_loop_ub = y.size(0);
    for (int i21{0}; i21 < h_loop_ub; i21++) {
      c_x[i21] = y[i21];
    }
  }
  i16 = c_x.size(0);
  for (int k{0}; k < i16; k++) {
    c_x[k] = std::sqrt(c_x[k]);
  }
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(imgPts.size(2), 3);
  i20 = imgPts.size(2);
  for (int b_j{0}; b_j < i20; b_j++) {
    double d6;
    double d7;
    double d8;
    d6 = Hbase2grid[3][0];
    d7 = Hbase2grid[3][1];
    d8 = Hbase2grid[3][2];
    for (int i23{0}; i23 < 3; i23++) {
      PoseErrt[b_j + (PoseErrt.size(0) * i23)] =
          ((((Hhand2base[i23 + (16 * b_j)] * d6) +
             (Hhand2base[(i23 + (16 * b_j)) + 4] * d7)) +
            (Hhand2base[(i23 + (16 * b_j)) + 8] * d8)) +
           Hhand2base[(i23 + (16 * b_j)) + 12]) -
          ((((Hhand2eye[0][i23] * Hcam2grid[(16 * b_j) + 12]) +
             (Hhand2eye[1][i23] * Hcam2grid[(16 * b_j) + 13])) +
            (Hhand2eye[2][i23] * Hcam2grid[(16 * b_j) + 14])) +
           Hhand2eye[3][i23]);
    }
    // (Ra*tx)+ta -(Rz*tb)+tz
  }
  d_x.set_size(PoseErrt.size(0), 3);
  i_loop_ub = PoseErrt.size(0);
  for (int i22{0}; i22 < 3; i22++) {
    for (int i24{0}; i24 < i_loop_ub; i24++) {
      double b_varargin_1;
      b_varargin_1 = PoseErrt[i24 + (PoseErrt.size(0) * i22)];
      d_x[i24 + (d_x.size(0) * i22)] = b_varargin_1 * b_varargin_1;
    }
  }
  if (d_x.size(0) == 0) {
    b_x.set_size(0);
  } else {
    int i27;
    int i28;
    int j_loop_ub;
    int o_loop_ub;
    b_x.set_size(d_x.size(0));
    y.set_size(d_x.size(0));
    j_loop_ub = d_x.size(0);
    for (int i26{0}; i26 < j_loop_ub; i26++) {
      y[i26] = b_x[i26];
    }
    i27 = d_x.size(0);
    for (int d_k{0}; d_k < i27; d_k++) {
      y[d_k] = d_x[d_k];
    }
    i28 = d_x.size(0);
    for (int e_k{0}; e_k < 2; e_k++) {
      for (int f_k{0}; f_k < i28; f_k++) {
        y[f_k] = y[f_k] + d_x[f_k + (d_x.size(0) * (e_k + 1))];
      }
    }
    b_x.set_size(y.size(0));
    o_loop_ub = y.size(0);
    for (int i32{0}; i32 < o_loop_ub; i32++) {
      b_x[i32] = y[i32];
    }
  }
  i25 = b_x.size(0);
  for (int c_k{0}; c_k < i25; c_k++) {
    b_x[c_k] = std::sqrt(b_x[c_k]);
  }
  //     %% Computing Reprojection errors
  err.set_size(imgPts.size(0), imgPts.size(2));
  k_loop_ub = imgPts.size(2);
  for (int i29{0}; i29 < k_loop_ub; i29++) {
    int m_loop_ub;
    m_loop_ub = imgPts.size(0);
    for (int i31{0}; i31 < m_loop_ub; i31++) {
      err[i31 + (err.size(0) * i29)] = 0.0;
    }
  }
  i30 = imgPts.size(2);
  for (int c_j{0}; c_j < i30; c_j++) {
    int i48;
    int i_n;
    int k_n;
    int p_loop_ub;
    int pipk;
    int q_loop_ub;
    for (int i33{0}; i33 < 4; i33++) {
      for (int i34{0}; i34 < 4; i34++) {
        b_y[i33][i34] = 0.0;
        d_A[i33][i34] = Hhand2eye[i33][i34];
      }
      ipiv[i33] = static_cast<signed char>(i33 + 1);
    }
    for (int d_j{0}; d_j < 3; d_j++) {
      double smax;
      int a;
      int b_tmp;
      int h_n;
      int jA;
      int jp1j;
      int mmj_tmp;
      mmj_tmp = 2 - d_j;
      b_tmp = d_j * 5;
      jp1j = b_tmp + 2;
      h_n = 4 - d_j;
      a = 0;
      smax = std::abs((&d_A[0][0])[b_tmp]);
      for (int g_k{2}; g_k <= h_n; g_k++) {
        double s;
        s = std::abs((&d_A[0][0])[(b_tmp + g_k) - 1]);
        if (s > smax) {
          a = g_k - 1;
          smax = s;
        }
      }
      if ((&d_A[0][0])[b_tmp + a] != 0.0) {
        int i36;
        if (a != 0) {
          int ipiv_tmp;
          ipiv_tmp = d_j + a;
          ipiv[d_j] = static_cast<signed char>(ipiv_tmp + 1);
          for (int i_k{0}; i_k < 4; i_k++) {
            double temp;
            int b_temp_tmp;
            int i45;
            int temp_tmp;
            temp_tmp = i_k * 4;
            b_temp_tmp = d_j + temp_tmp;
            temp = (&d_A[0][0])[b_temp_tmp];
            i45 = ipiv_tmp + temp_tmp;
            (&d_A[0][0])[b_temp_tmp] = (&d_A[0][0])[i45];
            (&d_A[0][0])[i45] = temp;
          }
        }
        i36 = (b_tmp - d_j) + 4;
        for (int c_i{jp1j}; c_i <= i36; c_i++) {
          (&d_A[0][0])[c_i - 1] /= (&d_A[0][0])[b_tmp];
        }
      }
      jA = b_tmp;
      for (int f_j{0}; f_j <= mmj_tmp; f_j++) {
        double yjy_tmp;
        yjy_tmp = (&d_A[0][0])[(b_tmp + (f_j * 4)) + 4];
        if (yjy_tmp != 0.0) {
          int i40;
          int i43;
          i40 = jA + 6;
          i43 = (jA - d_j) + 8;
          for (int ijA{i40}; ijA <= i43; ijA++) {
            (&d_A[0][0])[ijA - 1] +=
                (&d_A[0][0])[((b_tmp + ijA) - jA) - 5] * (-yjy_tmp);
          }
        }
        jA += 4;
      }
    }
    for (int i35{0}; i35 < 4; i35++) {
      p[i35] = static_cast<signed char>(i35 + 1);
    }
    if (ipiv[0] > 1) {
      pipk = static_cast<int>(p[ipiv[0] - 1]);
      p[ipiv[0] - 1] = p[0];
      p[0] = static_cast<signed char>(pipk);
    }
    if (ipiv[1] > 2) {
      pipk = static_cast<int>(p[ipiv[1] - 1]);
      p[ipiv[1] - 1] = p[1];
      p[1] = static_cast<signed char>(pipk);
    }
    if (ipiv[2] > 3) {
      pipk = static_cast<int>(p[ipiv[2] - 1]);
      p[ipiv[2] - 1] = p[2];
      p[2] = static_cast<signed char>(pipk);
    }
    for (int h_k{0}; h_k < 4; h_k++) {
      int c_tmp;
      c_tmp = (static_cast<int>(p[h_k])) - 1;
      b_y[c_tmp][h_k] = 1.0;
      for (int g_j{h_k + 1}; g_j < 5; g_j++) {
        if (b_y[c_tmp][g_j - 1] != 0.0) {
          int i39;
          i39 = g_j + 1;
          for (int e_i{i39}; e_i < 5; e_i++) {
            b_y[c_tmp][e_i - 1] -= b_y[c_tmp][g_j - 1] * d_A[g_j - 1][e_i - 1];
          }
        }
      }
    }
    for (int e_j{0}; e_j < 4; e_j++) {
      int jBcol;
      jBcol = e_j * 4;
      for (int j_k{3}; j_k >= 0; j_k--) {
        double d10;
        int i42;
        int kAcol;
        kAcol = j_k * 4;
        i42 = j_k + jBcol;
        d10 = (&b_y[0][0])[i42];
        if (d10 != 0.0) {
          (&b_y[0][0])[i42] = d10 / (&d_A[0][0])[j_k + kAcol];
          for (int h_i{0}; h_i < j_k; h_i++) {
            int i47;
            i47 = h_i + jBcol;
            (&b_y[0][0])[i47] -= (&b_y[0][0])[i42] * (&d_A[0][0])[h_i + kAcol];
          }
        }
      }
    }
    for (int i37{0}; i37 < 4; i37++) {
      for (int i38{0}; i38 < 4; i38++) {
        double d9;
        d9 = 0.0;
        for (int i44{0}; i44 < 4; i44++) {
          d9 += b_y[i44][i37] * Hhand2base[(i44 + (4 * i38)) + (16 * c_j)];
        }
        e_y[i38][i37] = d9;
      }
      for (int i41{0}; i41 < 4; i41++) {
        double d11;
        d11 = 0.0;
        for (int i46{0}; i46 < 4; i46++) {
          d11 += e_y[i46][i37] * Hbase2grid[i41][i46];
        }
        HT[i41][i37] = d11;
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    i_n = r.size(0);
    d_y.set_size(4, r.size(0));
    for (int h_j{0}; h_j < i_n; h_j++) {
      for (int g_i{0}; g_i < 4; g_i++) {
        double b_s;
        b_s = 0.0;
        for (int m_k{0}; m_k < 4; m_k++) {
          b_s += HT[m_k][g_i] * r[h_j + (r.size(0) * m_k)];
        }
        d_y[g_i + (4 * h_j)] = b_s;
      }
    }
    k_n = d_y.size(1);
    g_y.set_size(3, d_y.size(1));
    for (int i_j{0}; i_j < k_n; i_j++) {
      for (int k_i{0}; k_i < 3; k_i++) {
        double c_s;
        c_s = 0.0;
        for (int o_k{0}; o_k < 4; o_k++) {
          c_s += k_K[o_k][k_i] * d_y[o_k + (4 * i_j)];
        }
        g_y[k_i + (3 * i_j)] = c_s;
      }
    }
    if (g_y.size(1) == 1) {
      i48 = 1;
    } else if (g_y.size(1) == 1) {
      i48 = 1;
    } else {
      i48 = g_y.size(1);
    }
    e_x.set_size(3, i48);
    if (i48 != 0) {
      int acoef;
      int bcoef;
      int i49;
      acoef = static_cast<int>(g_y.size(1) != 1);
      bcoef = static_cast<int>(g_y.size(1) != 1);
      i49 = i48 - 1;
      for (int p_k{0}; p_k <= i49; p_k++) {
        int varargin_2;
        int varargin_3;
        varargin_2 = acoef * p_k;
        varargin_3 = bcoef * p_k;
        e_x[3 * p_k] = g_y[3 * varargin_2] / g_y[(3 * varargin_3) + 2];
        e_x[(3 * p_k) + 1] =
            g_y[(3 * varargin_2) + 1] / g_y[(3 * varargin_3) + 2];
        e_x[(3 * p_k) + 2] =
            g_y[(3 * varargin_2) + 2] / g_y[(3 * varargin_3) + 2];
      }
    }
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    p_loop_ub = imgPts.size(0);
    if (imgPts.size(0) == e_x.size(1)) {
      r1.set_size(imgPts.size(0), 2);
      for (int i50{0}; i50 < 2; i50++) {
        for (int i51{0}; i51 < p_loop_ub; i51++) {
          double c_varargin_1;
          c_varargin_1 = imgPts[(i51 + (imgPts.size(0) * i50)) +
                                ((imgPts.size(0) * 2) * c_j)] -
                         e_x[i50 + (3 * i51)];
          r1[i51 + (r1.size(0) * i50)] = c_varargin_1 * c_varargin_1;
        }
      }
    } else {
      b_binary_expand_op(r1, imgPts, c_j, e_x);
    }
    if (r1.size(0) == 0) {
      r2.set_size(0);
    } else {
      int i52;
      int i54;
      r2.set_size(r1.size(0));
      i52 = r1.size(0);
      for (int q_k{0}; q_k < i52; q_k++) {
        r2[q_k] = r1[q_k];
      }
      i54 = r1.size(0);
      for (int r_k{0}; r_k < i54; r_k++) {
        r2[r_k] = r2[r_k] + r1[r_k + r1.size(0)];
      }
    }
    q_loop_ub = r2.size(0);
    for (int i53{0}; i53 < q_loop_ub; i53++) {
      err[i53 + (err.size(0) * c_j)] = r2[i53];
    }
    //  adopted approach
  }
  coder::array<double, 1U> c_err;
  int b_err;
  // rrmse
  b_err = err.size(0) * err.size(1);
  errors[0] =
      coder::combineVectorElements(c_x) / (static_cast<double>(c_x.size(0)));
  errors[1] =
      coder::combineVectorElements(b_x) / (static_cast<double>(b_x.size(0)));
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
