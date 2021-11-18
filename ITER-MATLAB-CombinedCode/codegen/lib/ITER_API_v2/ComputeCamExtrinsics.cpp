//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "ComputeCamExtrinsics.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_initialize.h"
#include "ITER_API_v2_internal_types.h"
#include "ITER_API_v2_types.h"
#include "cameraParameters.h"
#include "detectCheckerboardPoints.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "isequal.h"
#include "mldivide.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                double b_square_size
//                const struct1_T *camera_params
//                coder::array<double, 3U> &e_image_points
//                coder::array<bool, 1U> &b_valid_idx
//                coder::array<double, 3U> &cam_extrinsics
//                coder::array<double, 3U> &camera_poses
//                coder::array<double, 2U> &b_world_points
//                int *err
// Return Type  : void
//
void ComputeCamExtrinsics(const coder::array<unsigned char, 4U> &images,
                          double b_square_size, const struct1_T *camera_params,
                          coder::array<double, 3U> &e_image_points,
                          coder::array<bool, 1U> &b_valid_idx,
                          coder::array<double, 3U> &cam_extrinsics,
                          coder::array<double, 3U> &camera_poses,
                          coder::array<double, 2U> &b_world_points, int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::c_cameraParameters b_camera_params;
  coder::projective2d H;
  coder::array<cell_wrap_1, 2U> board_points;
  coder::array<double, 2U> c_worldPoints;
  coder::array<double, 2U> current_board_points;
  coder::array<double, 2U> f_image_points;
  coder::array<unsigned char, 2U> b_images;
  coder::array<signed char, 1U> c_r1;
  coder::array<signed char, 1U> r;
  coder::array<bool, 1U> b_x;
  double c_orientation_matrix[4][4];
  double dv3[4][4];
  double a__1[3][3];
  double b_H[3][3];
  double b_orientation_matrix[3][3];
  double b_r1[3][3];
  double d_U[3][3];
  double dv2[3][3];
  double e_V[3][3];
  double orientation_matrix[3][3];
  double b_lambda[3];
  double c_x[3];
  double dv1[3];
  double r1[3];
  double r2[3];
  double translation_vector[3];
  double board_size_detected[2];
  double board_size_valid[2];
  double dv[2];
  int b_err;
  int i1;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  if (!isInitialized_ITER_API_v2) {
    ITER_API_v2_initialize();
  }
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  camera_params: camera parameters  matlab object
  for (int b_i{0}; b_i < 3; b_i++) {
    b_camera_params.IntrinsicMatrixInternal[b_i][0] =
        camera_params->IntrinsicMatrix[0][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][1] =
        camera_params->IntrinsicMatrix[1][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][2] =
        camera_params->IntrinsicMatrix[2][b_i];
  }
  b_err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size_idx_0 = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size_idx_1 = 0;
  // board_sizes = zeros(num_of_images,1);
  b_valid_idx.set_size(images.size(3));
  i1 = images.size(3);
  board_points.set_size(1, images.size(3));
  for (int c_i{0}; c_i < i1; c_i++) {
    int b_loop_ub;
    int f_loop_ub;
    int loop_ub;
    //  perform checkerboards detection in each image
    loop_ub = images.size(0);
    b_loop_ub = images.size(1);
    b_images.set_size(images.size(0), images.size(1));
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      for (int i3{0}; i3 < loop_ub; i3++) {
        b_images[i3 + (b_images.size(0) * i2)] =
            images[(i3 + (images.size(0) * i2)) +
                   ((images.size(0) * images.size(1)) * c_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    dv[0] = 0.0;
    dv[1] = 0.0;
    if (coder::isequal(board_size_detected, dv)) {
      b_valid_idx[c_i] = false;
    } else {
      dv[0] = 0.0;
      dv[1] = 0.0;
      if (coder::isequal(board_size_valid, dv)) {
        board_size_valid[0] = board_size_detected[0];
        image_point_valid_size_idx_0 = current_board_points.size(0);
        board_size_valid[1] = board_size_detected[1];
        image_point_valid_size_idx_1 = current_board_points.size(1);
      } else if (!coder::isequal(board_size_valid, board_size_detected)) {
        b_err = -1;
      } else {
        /* no actions */
      }
      b_valid_idx[c_i] = true;
    }
    f_loop_ub = current_board_points.size(1);
    board_points[board_points.size(0) * c_i].f1.set_size(
        current_board_points.size(0), current_board_points.size(1));
    for (int i11{0}; i11 < f_loop_ub; i11++) {
      int g_loop_ub;
      g_loop_ub = current_board_points.size(0);
      for (int i16{0}; i16 < g_loop_ub; i16++) {
        board_points[c_i].f1[i16 + (board_points[c_i].f1.size(0) * i11)] =
            current_board_points[i16 + (current_board_points.size(0) * i11)];
      }
    }
  }
  if (b_err != 0) {
    e_image_points.set_size(0, 0, 1);
    b_world_points.set_size(0, 0);
  } else {
    int k;
    bool exitg1;
    bool y;
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (b_valid_idx.size(0) - 1))) {
      if (!b_valid_idx[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!y) {
      // err = "Wrong detection of board size";
      b_err = -1;
      e_image_points.set_size(0, 0, 1);
      b_world_points.set_size(0, 0);
    } else {
      int board_size_valid_idx_0;
      unsigned int c_k;
      int d_loop_ub;
      int d_y;
      int i14;
      int i25;
      int m_loop_ub;
      int vlen;
      b_x.set_size(b_valid_idx.size(0));
      d_loop_ub = b_valid_idx.size(0);
      for (int i5{0}; i5 < d_loop_ub; i5++) {
        b_x[i5] = b_valid_idx[i5];
      }
      vlen = b_x.size(0);
      if (b_x.size(0) == 0) {
        d_y = 0;
      } else {
        int b_y;
        b_y = static_cast<int>(b_x[0]);
        for (int b_k{2}; b_k <= vlen; b_k++) {
          int e_y;
          e_y = b_y;
          if (vlen >= 2) {
            e_y = b_y + (static_cast<int>(b_x[b_k - 1]));
          }
          b_y = e_y;
        }
        d_y = b_y;
      }
      e_image_points.set_size(image_point_valid_size_idx_0,
                              image_point_valid_size_idx_1, d_y);
      for (int i12{0}; i12 < d_y; i12++) {
        for (int i15{0}; i15 < image_point_valid_size_idx_1; i15++) {
          for (int i17{0}; i17 < image_point_valid_size_idx_0; i17++) {
            e_image_points[(i17 + (e_image_points.size(0) * i15)) +
                           ((e_image_points.size(0) * e_image_points.size(1)) *
                            i12)] = 0.0;
          }
        }
      }
      i14 = images.size(3);
      for (int g_i{0}; g_i < i14; g_i++) {
        if (b_valid_idx[g_i]) {
          int j_loop_ub;
          j_loop_ub = board_points[g_i].f1.size(1);
          for (int i19{0}; i19 < j_loop_ub; i19++) {
            int k_loop_ub;
            k_loop_ub = board_points[g_i].f1.size(0);
            for (int i23{0}; i23 < k_loop_ub; i23++) {
              e_image_points
                  [(i23 + (e_image_points.size(0) * i19)) +
                   ((e_image_points.size(0) * e_image_points.size(1)) * g_i)] =
                      board_points[g_i]
                          .f1[i23 + (board_points[g_i].f1.size(0) * i19)];
            }
          }
        }
      }
      //  Generate world coordinates of the corners of the squares in meters
      board_size_valid[0]--;
      board_size_valid[1]--;
      board_size_valid_idx_0 = static_cast<int>(
          static_cast<double>(board_size_valid[0] * board_size_valid[1]));
      c_worldPoints.set_size(board_size_valid_idx_0, 2);
      for (int i22{0}; i22 < 2; i22++) {
        for (int i24{0}; i24 < board_size_valid_idx_0; i24++) {
          c_worldPoints[i24 + (c_worldPoints.size(0) * i22)] = 0.0;
        }
      }
      c_k = 1U;
      i25 = static_cast<int>(
          static_cast<double>((board_size_valid[1] - 1.0) + 1.0));
      for (int j{0}; j < i25; j++) {
        int i26;
        i26 = static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0));
        for (int h_i{0}; h_i < i26; h_i++) {
          int worldPoints_tmp;
          worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                c_k + (static_cast<unsigned int>(h_i))))) -
                            1;
          c_worldPoints[worldPoints_tmp] =
              (static_cast<double>(j)) * b_square_size;
          c_worldPoints[worldPoints_tmp + c_worldPoints.size(0)] =
              (static_cast<double>(h_i)) * b_square_size;
        }
        c_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0)));
      }
      b_world_points.set_size(c_worldPoints.size(0), 2);
      m_loop_ub = c_worldPoints.size(0);
      for (int i27{0}; i27 < 2; i27++) {
        for (int i28{0}; i28 < m_loop_ub; i28++) {
          b_world_points[i28 + (b_world_points.size(0) * i27)] =
              c_worldPoints[i28 + (c_worldPoints.size(0) * i27)];
        }
      }
    }
  }
  if (b_err != 0) {
    cam_extrinsics.set_size(0, 0, 1);
    camera_poses.set_size(0, 0, 1);
  } else {
    int c_loop_ub;
    int e_loop_ub;
    int i9;
    //  compute extrinsics
    cam_extrinsics.set_size(4, 4, e_image_points.size(2));
    c_loop_ub = e_image_points.size(2);
    for (int i4{0}; i4 < c_loop_ub; i4++) {
      for (int i6{0}; i6 < 4; i6++) {
        for (int i8{0}; i8 < 4; i8++) {
          cam_extrinsics[(i8 + (cam_extrinsics.size(0) * i6)) +
                         ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) *
                          i4)] = 0.0;
        }
      }
    }
    camera_poses.set_size(4, 4, e_image_points.size(2));
    e_loop_ub = e_image_points.size(2);
    for (int i7{0}; i7 < e_loop_ub; i7++) {
      for (int i10{0}; i10 < 4; i10++) {
        for (int i13{0}; i13 < 4; i13++) {
          camera_poses[(i13 + (camera_poses.size(0) * i10)) +
                       ((camera_poses.size(0) * camera_poses.size(1)) * i7)] =
              0.0;
        }
      }
    }
    i9 = e_image_points.size(2);
    for (int e_i{0}; e_i < i9; e_i++) {
      double absxk;
      double b_t;
      double d3;
      double d4;
      double d5;
      double g_y;
      double lambda;
      double scale;
      int h_loop_ub;
      int i_loop_ub;
      //  transformations from the grid/world coordinates to the camera-based
      //  coordinates
      h_loop_ub = e_image_points.size(0);
      i_loop_ub = e_image_points.size(1);
      f_image_points.set_size(e_image_points.size(0), e_image_points.size(1));
      for (int i18{0}; i18 < i_loop_ub; i18++) {
        for (int i20{0}; i20 < h_loop_ub; i20++) {
          f_image_points[i20 + (f_image_points.size(0) * i18)] = e_image_points
              [(i20 + (e_image_points.size(0) * i18)) +
               ((e_image_points.size(0) * e_image_points.size(1)) * e_i)];
        }
      }
      coder::fitgeotrans(b_world_points, f_image_points, &H);
      for (int i21{0}; i21 < 3; i21++) {
        b_H[i21][0] = H.T[0][i21];
        b_H[i21][1] = H.T[1][i21];
        b_H[i21][2] = H.T[2][i21];
      }
      coder::mldivide(b_camera_params.IntrinsicMatrixInternal,
                      *((double(*)[3])(&b_H[0][0])), c_x);
      scale = 3.3121686421112381E-170;
      absxk = std::abs(c_x[0]);
      if (absxk > 3.3121686421112381E-170) {
        g_y = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        g_y = b_t * b_t;
      }
      absxk = std::abs(c_x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        g_y = ((g_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        g_y += b_t * b_t;
      }
      absxk = std::abs(c_x[2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        g_y = ((g_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        g_y += b_t * b_t;
      }
      g_y = scale * std::sqrt(g_y);
      lambda = 1.0 / g_y;
      b_lambda[0] = lambda * b_H[0][0];
      b_lambda[1] = lambda * b_H[0][1];
      b_lambda[2] = lambda * b_H[0][2];
      coder::mldivide(b_camera_params.IntrinsicMatrixInternal, b_lambda, r1);
      b_lambda[0] = lambda * b_H[1][0];
      b_lambda[1] = lambda * b_H[1][1];
      b_lambda[2] = lambda * b_H[1][2];
      coder::mldivide(b_camera_params.IntrinsicMatrixInternal, b_lambda, r2);
      b_r1[0][0] = r1[0];
      b_r1[0][1] = r2[0];
      b_r1[1][0] = r1[1];
      b_r1[1][1] = r2[1];
      b_r1[2][0] = r1[2];
      b_r1[2][1] = r2[2];
      b_r1[0][2] = (r1[1] * r2[2]) - (r2[1] * r1[2]);
      b_r1[1][2] = (r2[0] * r1[2]) - (r1[0] * r2[2]);
      b_r1[2][2] = (r1[0] * r2[1]) - (r2[0] * r1[1]);
      coder::svd(b_r1, d_U, a__1, e_V);
      for (int i29{0}; i29 < 3; i29++) {
        double b_d1;
        double d;
        double d2;
        d = d_U[0][i29];
        b_d1 = d_U[1][i29];
        d2 = d_U[2][i29];
        for (int i30{0}; i30 < 3; i30++) {
          orientation_matrix[i30][i29] =
              ((d * e_V[0][i30]) + (b_d1 * e_V[1][i30])) + (d2 * e_V[2][i30]);
        }
        b_lambda[i29] = lambda * b_H[2][i29];
      }
      coder::mldivide(b_camera_params.IntrinsicMatrixInternal, b_lambda, dv1);
      translation_vector[0] = dv1[0];
      translation_vector[1] = dv1[1];
      translation_vector[2] = dv1[2];
      r.set_size(4);
      c_r1.set_size(4);
      for (int i31{0}; i31 < 4; i31++) {
        r[i31] = static_cast<signed char>(i31);
        c_r1[i31] = static_cast<signed char>(i31);
      }
      coder::inv(orientation_matrix, dv2);
      for (int i32{0}; i32 < 3; i32++) {
        dv3[i32][0] = dv2[i32][0];
        dv3[i32][1] = dv2[i32][1];
        dv3[i32][2] = dv2[i32][2];
        dv3[3][i32] = translation_vector[i32];
      }
      for (int i33{0}; i33 < 4; i33++) {
        dv3[i33][3] = static_cast<double>(b_iv[i33]);
      }
      for (int i34{0}; i34 < 4; i34++) {
        for (int i35{0}; i35 < 4; i35++) {
          cam_extrinsics
              [((static_cast<int>(r[i35])) +
                (cam_extrinsics.size(0) * (static_cast<int>(c_r1[i34])))) +
               ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) * e_i)] =
                  (&dv3[0][0])[i35 + (4 * i34)];
        }
      }
      //  inverted of cam_extrinsics
      r.set_size(4);
      c_r1.set_size(4);
      for (int i36{0}; i36 < 4; i36++) {
        r[i36] = static_cast<signed char>(i36);
        c_r1[i36] = static_cast<signed char>(i36);
      }
      for (int i37{0}; i37 < 3; i37++) {
        b_orientation_matrix[i37][0] = -orientation_matrix[i37][0];
        b_orientation_matrix[i37][1] = -orientation_matrix[i37][1];
        b_orientation_matrix[i37][2] = -orientation_matrix[i37][2];
      }
      d3 = dv1[0];
      d4 = dv1[1];
      d5 = dv1[2];
      for (int i38{0}; i38 < 3; i38++) {
        c_orientation_matrix[i38][0] = orientation_matrix[i38][0];
        c_orientation_matrix[i38][1] = orientation_matrix[i38][1];
        c_orientation_matrix[i38][2] = orientation_matrix[i38][2];
        c_orientation_matrix[3][i38] = ((b_orientation_matrix[0][i38] * d3) +
                                        (b_orientation_matrix[1][i38] * d4)) +
                                       (b_orientation_matrix[2][i38] * d5);
      }
      for (int i39{0}; i39 < 4; i39++) {
        c_orientation_matrix[i39][3] = static_cast<double>(b_iv[i39]);
      }
      for (int i40{0}; i40 < 4; i40++) {
        for (int i41{0}; i41 < 4; i41++) {
          camera_poses[((static_cast<int>(r[i41])) +
                        (camera_poses.size(0) *
                         (static_cast<int>(c_r1[i40])))) +
                       ((camera_poses.size(0) * camera_poses.size(1)) * e_i)] =
              (&c_orientation_matrix[0][0])[i41 + (4 * i40)];
        }
      }
    }
  }
  *err = b_err;
}

//
// File trailer for ComputeCamExtrinsics.cpp
//
// [EOF]
//
