//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "computeErrors.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
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
//                const double e_K[4][3]
//                double errors[3]
// Return Type  : void
//
void computeErrors(const coder::array<double, 3U> &Hhand2base,
                   const double Hhand2eye[4][4], const double Hbase2grid[4][4],
                   const coder::array<double, 3U> &Hcam2grid,
                   const coder::array<double, 3U> &imgPts,
                   const coder::array<double, 2U> &Worldpts,
                   const double e_K[4][3], double errors[3])
{
  coder::array<double, 3U> PoseErrR;
  coder::array<double, 2U> PoseErrt;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> d_x;
  coder::array<double, 2U> e_y;
  coder::array<double, 2U> err;
  coder::array<double, 2U> f_y;
  coder::array<double, 2U> r;
  coder::array<double, 2U> r1;
  coder::array<double, 1U> angR;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> c_x;
  coder::array<double, 1U> y;
  double A[4][4];
  double HT[4][4];
  double b_y[4][4];
  double d_y[4][4];
  double b_Hhand2base[3][3];
  double b_Hhand2eye[3][3];
  double dv[3][3];
  double AxAngVec[4];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i17;
  int i19;
  int i24;
  int i27;
  int i9;
  int loop_ub;
  int result;
  signed char ipiv[4];
  signed char p[4];
  signed char b_input_sizes_idx_1;
  signed char c_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
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
      for (int i18{0}; i18 < 3; i18++) {
        PoseErrR[(i13 + (3 * i18)) + (9 * j)] =
            ((d3 * b_Hhand2base[i18][0]) + (d4 * b_Hhand2base[i18][1])) +
            (d5 * b_Hhand2base[i18][2]);
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    coder::rotm2axang(*((double(*)[3][3])(&PoseErrR[9 * j])), AxAngVec);
    angR[j] = AxAngVec[3] * 57.295779513082323;
  }
  y.set_size(angR.size(0));
  f_loop_ub = angR.size(0);
  for (int i11{0}; i11 < f_loop_ub; i11++) {
    double varargin_1;
    varargin_1 = angR[i11];
    y[i11] = varargin_1 * varargin_1;
  }
  if (y.size(0) == 0) {
    b_x.set_size(0);
  } else {
    int i16;
    b_x.set_size(y.size(0));
    i16 = y.size(0);
    for (int k{0}; k < i16; k++) {
      b_x[k] = y[k];
    }
  }
  i17 = b_x.size(0);
  for (int b_k{0}; b_k < i17; b_k++) {
    b_x[b_k] = std::sqrt(b_x[b_k]);
  }
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(imgPts.size(2), 3);
  i19 = imgPts.size(2);
  for (int b_j{0}; b_j < i19; b_j++) {
    double d6;
    double d7;
    double d8;
    d6 = Hbase2grid[3][0];
    d7 = Hbase2grid[3][1];
    d8 = Hbase2grid[3][2];
    for (int i21{0}; i21 < 3; i21++) {
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
  r1.set_size(PoseErrt.size(0), 3);
  g_loop_ub = PoseErrt.size(0);
  for (int i20{0}; i20 < 3; i20++) {
    for (int i22{0}; i22 < g_loop_ub; i22++) {
      double b_varargin_1;
      b_varargin_1 = PoseErrt[i22 + (PoseErrt.size(0) * i20)];
      r1[i22 + (r1.size(0) * i20)] = b_varargin_1 * b_varargin_1;
    }
  }
  if (r1.size(0) == 0) {
    c_x.set_size(0);
  } else {
    int i23;
    int i25;
    c_x.set_size(r1.size(0));
    i23 = r1.size(0);
    for (int c_k{0}; c_k < i23; c_k++) {
      c_x[c_k] = r1[c_k];
    }
    i25 = r1.size(0);
    for (int f_k{0}; f_k < 2; f_k++) {
      for (int g_k{0}; g_k < i25; g_k++) {
        c_x[g_k] = c_x[g_k] + r1[g_k + (r1.size(0) * (f_k + 1))];
      }
    }
  }
  i24 = c_x.size(0);
  for (int d_k{0}; d_k < i24; d_k++) {
    c_x[d_k] = std::sqrt(c_x[d_k]);
  }
  //     %% Computing Reprojection errors
  err.set_size(imgPts.size(0), imgPts.size(2));
  h_loop_ub = imgPts.size(2);
  for (int i26{0}; i26 < h_loop_ub; i26++) {
    int i_loop_ub;
    i_loop_ub = imgPts.size(0);
    for (int i28{0}; i28 < i_loop_ub; i28++) {
      err[i28 + (err.size(0) * i26)] = 0.0;
    }
  }
  i27 = imgPts.size(2);
  for (int c_j{0}; c_j < i27; c_j++) {
    int d_n;
    int e_n;
    int i44;
    int j_loop_ub;
    int pipk;
    for (int i29{0}; i29 < 4; i29++) {
      for (int i30{0}; i30 < 4; i30++) {
        b_y[i29][i30] = 0.0;
        A[i29][i30] = Hhand2eye[i29][i30];
      }
      ipiv[i29] = static_cast<signed char>(i29 + 1);
    }
    for (int d_j{0}; d_j < 3; d_j++) {
      double smax;
      int b_a;
      int b_tmp;
      int c_n;
      int jA;
      int jp1j;
      int mmj_tmp;
      mmj_tmp = 2 - d_j;
      b_tmp = d_j * 5;
      jp1j = b_tmp + 2;
      c_n = 4 - d_j;
      b_a = 0;
      smax = std::abs((&A[0][0])[b_tmp]);
      for (int h_k{2}; h_k <= c_n; h_k++) {
        double s;
        s = std::abs((&A[0][0])[(b_tmp + h_k) - 1]);
        if (s > smax) {
          b_a = h_k - 1;
          smax = s;
        }
      }
      if ((&A[0][0])[b_tmp + b_a] != 0.0) {
        int i32;
        if (b_a != 0) {
          int ipiv_tmp;
          ipiv_tmp = d_j + b_a;
          ipiv[d_j] = static_cast<signed char>(ipiv_tmp + 1);
          for (int j_k{0}; j_k < 4; j_k++) {
            double temp;
            int b_temp_tmp;
            int i41;
            int temp_tmp;
            temp_tmp = j_k * 4;
            b_temp_tmp = d_j + temp_tmp;
            temp = (&A[0][0])[b_temp_tmp];
            i41 = ipiv_tmp + temp_tmp;
            (&A[0][0])[b_temp_tmp] = (&A[0][0])[i41];
            (&A[0][0])[i41] = temp;
          }
        }
        i32 = (b_tmp - d_j) + 4;
        for (int c_i{jp1j}; c_i <= i32; c_i++) {
          (&A[0][0])[c_i - 1] /= (&A[0][0])[b_tmp];
        }
      }
      jA = b_tmp;
      for (int f_j{0}; f_j <= mmj_tmp; f_j++) {
        double yjy_tmp;
        yjy_tmp = (&A[0][0])[(b_tmp + (f_j * 4)) + 4];
        if (yjy_tmp != 0.0) {
          int i36;
          int i39;
          i36 = jA + 6;
          i39 = (jA - d_j) + 8;
          for (int ijA{i36}; ijA <= i39; ijA++) {
            (&A[0][0])[ijA - 1] +=
                (&A[0][0])[((b_tmp + ijA) - jA) - 5] * (-yjy_tmp);
          }
        }
        jA += 4;
      }
    }
    for (int i31{0}; i31 < 4; i31++) {
      p[i31] = static_cast<signed char>(i31 + 1);
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
    for (int i_k{0}; i_k < 4; i_k++) {
      int c_tmp;
      c_tmp = (static_cast<int>(p[i_k])) - 1;
      b_y[c_tmp][i_k] = 1.0;
      for (int g_j{i_k + 1}; g_j < 5; g_j++) {
        if (b_y[c_tmp][g_j - 1] != 0.0) {
          int i35;
          i35 = g_j + 1;
          for (int d_i{i35}; d_i < 5; d_i++) {
            b_y[c_tmp][d_i - 1] -= b_y[c_tmp][g_j - 1] * A[g_j - 1][d_i - 1];
          }
        }
      }
    }
    for (int e_j{0}; e_j < 4; e_j++) {
      int jBcol;
      jBcol = e_j * 4;
      for (int k_k{3}; k_k >= 0; k_k--) {
        double d10;
        int i38;
        int kAcol;
        kAcol = k_k * 4;
        i38 = k_k + jBcol;
        d10 = (&b_y[0][0])[i38];
        if (d10 != 0.0) {
          (&b_y[0][0])[i38] = d10 / (&A[0][0])[k_k + kAcol];
          for (int g_i{0}; g_i < k_k; g_i++) {
            int i43;
            i43 = g_i + jBcol;
            (&b_y[0][0])[i43] -= (&b_y[0][0])[i38] * (&A[0][0])[g_i + kAcol];
          }
        }
      }
    }
    for (int i33{0}; i33 < 4; i33++) {
      for (int i34{0}; i34 < 4; i34++) {
        double d9;
        d9 = 0.0;
        for (int i40{0}; i40 < 4; i40++) {
          d9 += b_y[i40][i33] * Hhand2base[(i40 + (4 * i34)) + (16 * c_j)];
        }
        d_y[i34][i33] = d9;
      }
      for (int i37{0}; i37 < 4; i37++) {
        double d11;
        d11 = 0.0;
        for (int i42{0}; i42 < 4; i42++) {
          d11 += d_y[i42][i33] * Hbase2grid[i37][i42];
        }
        HT[i37][i33] = d11;
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    d_n = r.size(0);
    c_y.set_size(4, r.size(0));
    for (int h_j{0}; h_j < d_n; h_j++) {
      for (int e_i{0}; e_i < 4; e_i++) {
        double b_s;
        b_s = 0.0;
        for (int m_k{0}; m_k < 4; m_k++) {
          b_s += HT[m_k][e_i] * r[h_j + (r.size(0) * m_k)];
        }
        c_y[e_i + (4 * h_j)] = b_s;
      }
    }
    e_n = c_y.size(1);
    e_y.set_size(3, c_y.size(1));
    for (int i_j{0}; i_j < e_n; i_j++) {
      for (int h_i{0}; h_i < 3; h_i++) {
        double c_s;
        c_s = 0.0;
        for (int o_k{0}; o_k < 4; o_k++) {
          c_s += e_K[o_k][h_i] * c_y[o_k + (4 * i_j)];
        }
        e_y[h_i + (3 * i_j)] = c_s;
      }
    }
    if (e_y.size(1) == 1) {
      i44 = 1;
    } else if (e_y.size(1) == 1) {
      i44 = 1;
    } else {
      i44 = e_y.size(1);
    }
    d_x.set_size(3, i44);
    if (i44 != 0) {
      int acoef;
      int bcoef;
      int i45;
      acoef = static_cast<int>(e_y.size(1) != 1);
      bcoef = static_cast<int>(e_y.size(1) != 1);
      i45 = i44 - 1;
      for (int p_k{0}; p_k <= i45; p_k++) {
        int varargin_2;
        int varargin_3;
        varargin_2 = acoef * p_k;
        varargin_3 = bcoef * p_k;
        d_x[3 * p_k] = e_y[3 * varargin_2] / e_y[(3 * varargin_3) + 2];
        d_x[(3 * p_k) + 1] =
            e_y[(3 * varargin_2) + 1] / e_y[(3 * varargin_3) + 2];
        d_x[(3 * p_k) + 2] =
            e_y[(3 * varargin_2) + 2] / e_y[(3 * varargin_3) + 2];
      }
    }
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    j_loop_ub = imgPts.size(0);
    if (imgPts.size(0) == d_x.size(1)) {
      f_y.set_size(imgPts.size(0), 2);
      for (int i46{0}; i46 < 2; i46++) {
        for (int i47{0}; i47 < j_loop_ub; i47++) {
          double c_varargin_1;
          c_varargin_1 = imgPts[(i47 + (imgPts.size(0) * i46)) +
                                ((imgPts.size(0) * 2) * c_j)] -
                         d_x[i46 + (3 * i47)];
          f_y[i47 + (f_y.size(0) * i46)] = c_varargin_1 * c_varargin_1;
        }
      }
    } else {
      binary_expand_op(f_y, imgPts, c_j, d_x);
    }
    if (f_y.size(0) != 0) {
      int i48;
      int i49;
      int k_loop_ub;
      y.set_size(f_y.size(0));
      i48 = f_y.size(0);
      for (int q_k{0}; q_k < i48; q_k++) {
        y[q_k] = f_y[q_k];
      }
      i49 = f_y.size(0);
      for (int r_k{0}; r_k < i49; r_k++) {
        y[r_k] = y[r_k] + f_y[r_k + f_y.size(0)];
      }
      k_loop_ub = y.size(0);
      for (int i50{0}; i50 < k_loop_ub; i50++) {
        err[i50 + (err.size(0) * c_j)] = y[i50];
      }
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
      coder::combineVectorElements(c_x) / (static_cast<double>(c_x.size(0)));
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
