//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "ComputeCamExtrinsics.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_types.h"
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

// Type Definitions
struct cell_wrap_22 {
  coder::array<double, 2U> f1;
};

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                double square_size
//                const struct0_T *camera_params
//                coder::array<double, 3U> &image_points
//                coder::array<bool, 1U> &valid_idx
//                coder::array<double, 3U> &cam_extrinsics
//                coder::array<double, 3U> &camera_poses
//                coder::array<double, 2U> &b_world_points
//                int *err
// Return Type  : void
//
void ComputeCamExtrinsics(const coder::array<unsigned char, 4U> &images,
                          double square_size, const struct0_T *camera_params,
                          coder::array<double, 3U> &image_points,
                          coder::array<bool, 1U> &valid_idx,
                          coder::array<double, 3U> &cam_extrinsics,
                          coder::array<double, 3U> &camera_poses,
                          coder::array<double, 2U> &b_world_points, int *err)
{
  static const signed char iv[4]{0, 0, 0, 1};
  coder::cameraParameters b_camera_params;
  coder::projective2d H;
  coder::array<cell_wrap_22, 2U> board_points;
  coder::array<double, 2U> b_image_points;
  coder::array<double, 2U> c_worldPoints;
  coder::array<double, 2U> current_board_points;
  coder::array<unsigned char, 2U> b_images;
  coder::array<signed char, 1U> c_r1;
  coder::array<signed char, 1U> r;
  coder::array<bool, 1U> b_x;
  double c_orientation_matrix[4][4];
  double dv3[4][4];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_H[3][3];
  double b_orientation_matrix[3][3];
  double b_r1[3][3];
  double dv2[3][3];
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
  int b_vlen;
  int i1;
  int i_loop_ub;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  int k;
  int nz;
  bool exitg1;
  bool y;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
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
  valid_idx.set_size(images.size(3));
  i1 = images.size(3);
  board_points.set_size(1, images.size(3));
  for (int c_i{0}; c_i < i1; c_i++) {
    int b_loop_ub;
    int d_loop_ub;
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
      valid_idx[c_i] = false;
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
        // return;
      } else {
        /* no actions */
      }
      valid_idx[c_i] = true;
    }
    d_loop_ub = current_board_points.size(1);
    board_points[board_points.size(0) * c_i].f1.set_size(
        current_board_points.size(0), current_board_points.size(1));
    for (int i6{0}; i6 < d_loop_ub; i6++) {
      int e_loop_ub;
      e_loop_ub = current_board_points.size(0);
      for (int i9{0}; i9 < e_loop_ub; i9++) {
        board_points[c_i].f1[i9 + (board_points[c_i].f1.size(0) * i6)] =
            current_board_points[i9 + (current_board_points.size(0) * i6)];
      }
    }
  }
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (valid_idx.size(0) - 1))) {
    if (!valid_idx[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!y) {
    // err = "Wrong detection of board size";
    b_err = -1;
    image_points.set_size(0, 0, 1);
    b_world_points.set_size(0, 0);
  } else {
    int board_size_valid_idx_0;
    unsigned int c_k;
    int c_loop_ub;
    int c_y;
    int h_loop_ub;
    int i15;
    int i7;
    int vlen;
    b_x.set_size(valid_idx.size(0));
    c_loop_ub = valid_idx.size(0);
    for (int i4{0}; i4 < c_loop_ub; i4++) {
      b_x[i4] = valid_idx[i4];
    }
    vlen = b_x.size(0);
    if (b_x.size(0) == 0) {
      c_y = 0;
    } else {
      int b_y;
      b_y = static_cast<int>(b_x[0]);
      for (int b_k{2}; b_k <= vlen; b_k++) {
        int d_y;
        d_y = b_y;
        if (vlen >= 2) {
          d_y = b_y + (static_cast<int>(b_x[b_k - 1]));
        }
        b_y = d_y;
      }
      c_y = b_y;
    }
    image_points.set_size(image_point_valid_size_idx_0,
                          image_point_valid_size_idx_1, c_y);
    for (int i5{0}; i5 < c_y; i5++) {
      for (int i8{0}; i8 < image_point_valid_size_idx_1; i8++) {
        for (int i10{0}; i10 < image_point_valid_size_idx_0; i10++) {
          image_points[(i10 + (image_points.size(0) * i8)) +
                       ((image_points.size(0) * image_points.size(1)) * i5)] =
              0.0;
        }
      }
    }
    i7 = images.size(3);
    for (int d_i{0}; d_i < i7; d_i++) {
      if (valid_idx[d_i]) {
        int f_loop_ub;
        f_loop_ub = board_points[d_i].f1.size(1);
        for (int i11{0}; i11 < f_loop_ub; i11++) {
          int g_loop_ub;
          g_loop_ub = board_points[d_i].f1.size(0);
          for (int i13{0}; i13 < g_loop_ub; i13++) {
            image_points[(i13 + (image_points.size(0) * i11)) +
                         ((image_points.size(0) * image_points.size(1)) *
                          d_i)] =
                board_points[d_i]
                    .f1[i13 + (board_points[d_i].f1.size(0) * i11)];
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
    for (int i12{0}; i12 < 2; i12++) {
      for (int i14{0}; i14 < board_size_valid_idx_0; i14++) {
        c_worldPoints[i14 + (c_worldPoints.size(0) * i12)] = 0.0;
      }
    }
    c_k = 1U;
    i15 = static_cast<int>(
        static_cast<double>((board_size_valid[1] - 1.0) + 1.0));
    for (int j{0}; j < i15; j++) {
      int i16;
      i16 = static_cast<int>(
          static_cast<double>((board_size_valid[0] - 1.0) + 1.0));
      for (int e_i{0}; e_i < i16; e_i++) {
        int worldPoints_tmp;
        worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                              c_k + (static_cast<unsigned int>(e_i))))) -
                          1;
        c_worldPoints[worldPoints_tmp] = (static_cast<double>(j)) * square_size;
        c_worldPoints[worldPoints_tmp + c_worldPoints.size(0)] =
            (static_cast<double>(e_i)) * square_size;
      }
      c_k += static_cast<unsigned int>(static_cast<int>(
          static_cast<double>((board_size_valid[0] - 1.0) + 1.0)));
    }
    b_world_points.set_size(c_worldPoints.size(0), 2);
    h_loop_ub = c_worldPoints.size(0);
    for (int i17{0}; i17 < 2; i17++) {
      for (int i18{0}; i18 < h_loop_ub; i18++) {
        b_world_points[i18 + (b_world_points.size(0) * i17)] =
            c_worldPoints[i18 + (c_worldPoints.size(0) * i17)];
      }
    }
  }
  // {
  //  Detect checkerboards in images
  // valid_idx = false(num_of_images,1);
  // board_points = cell(num_of_images,1);
  // board_sizes = cell(num_of_images,1);
  // valid_counter = int32(0);
  // for i=1:num_of_images
  // 	% perform checkerboards detection in each image
  //     current_image=images(:,:,:,i);
  //     [current_board_points, board_size_detected] =
  //     detectCheckerboardPoints(current_image, 'PartialDetections', false);
  //
  // 	% mark if checkerboards is detected or not
  //     if (isequal(board_size_detected, [0 0]))
  //         valid_idx(i)=false;
  //     else
  //         valid_idx(i)=true;
  //     end
  //     board_points{i} = current_board_points;
  //     board_sizes{i} = board_size_detected;
  //
  // end
  //
  // if ~all(valid_idx)
  //     %err = "Error during detection of checkerboard in images";
  //     err = int32(-1);
  //     return;
  // end
  //
  // num_of_valid_images = sum(valid_idx(:) == true);
  // image_points = zeros([size(board_points{1}) num_of_valid_images]);
  // board_size = zeros(1,2);
  // for i=1:num_of_valid_images
  //     if valid_idx(i)
  //         if (isequal(board_size, [0 0]))
  //             board_size = board_sizes{i};
  //         elseif (~isequal(board_size, board_sizes{i}))
  //               %err = "Detect checker board with different size at " +
  //               int2str(i); err = int32(-1); return;
  //         end
  //         image_points(:,:,i) = board_points{i};
  //     end
  // end
  // }
  //  compute extrinsics
  b_x.set_size(valid_idx.size(0));
  i_loop_ub = valid_idx.size(0);
  for (int i19{0}; i19 < i_loop_ub; i19++) {
    b_x[i19] = valid_idx[i19];
  }
  b_vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    nz = 0;
  } else {
    int e_y;
    e_y = static_cast<int>(b_x[0]);
    for (int d_k{2}; d_k <= b_vlen; d_k++) {
      int f_y;
      f_y = e_y;
      if (b_vlen >= 2) {
        f_y = e_y + (static_cast<int>(b_x[d_k - 1]));
      }
      e_y = f_y;
    }
    nz = e_y;
  }
  cam_extrinsics.set_size(4, 4, nz);
  camera_poses.set_size(4, 4, nz);
  for (int i20{0}; i20 < nz; i20++) {
    for (int i21{0}; i21 < 4; i21++) {
      for (int i22{0}; i22 < 4; i22++) {
        cam_extrinsics[(i22 + (cam_extrinsics.size(0) * i21)) +
                       ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) *
                        i20)] = 0.0;
        camera_poses[(i22 + (camera_poses.size(0) * i21)) +
                     ((camera_poses.size(0) * camera_poses.size(1)) * i20)] =
            0.0;
      }
    }
  }
  for (int g_i{0}; g_i < nz; g_i++) {
    double absxk;
    double b_t;
    double d3;
    double d4;
    double d5;
    double g_y;
    double lambda;
    double scale;
    int j_loop_ub;
    int k_loop_ub;
    //  transformations from the grid/world coordinates to the camera-based
    //  coordinates
    j_loop_ub = image_points.size(0);
    k_loop_ub = image_points.size(1);
    b_image_points.set_size(image_points.size(0), image_points.size(1));
    for (int i23{0}; i23 < k_loop_ub; i23++) {
      for (int i24{0}; i24 < j_loop_ub; i24++) {
        b_image_points[i24 + (b_image_points.size(0) * i23)] =
            image_points[(i24 + (image_points.size(0) * i23)) +
                         ((image_points.size(0) * image_points.size(1)) * g_i)];
      }
    }
    coder::findProjectiveTransform(b_world_points, b_image_points, &H);
    for (int i25{0}; i25 < 3; i25++) {
      b_H[i25][0] = H.T[0][i25];
      b_H[i25][1] = H.T[1][i25];
      b_H[i25][2] = H.T[2][i25];
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
    coder::svd(b_r1, U, a__1, V);
    for (int i26{0}; i26 < 3; i26++) {
      double b_d1;
      double d;
      double d2;
      d = U[0][i26];
      b_d1 = U[1][i26];
      d2 = U[2][i26];
      for (int i27{0}; i27 < 3; i27++) {
        orientation_matrix[i27][i26] =
            ((d * V[0][i27]) + (b_d1 * V[1][i27])) + (d2 * V[2][i27]);
      }
      b_lambda[i26] = lambda * b_H[2][i26];
    }
    coder::mldivide(b_camera_params.IntrinsicMatrixInternal, b_lambda, dv1);
    translation_vector[0] = dv1[0];
    translation_vector[1] = dv1[1];
    translation_vector[2] = dv1[2];
    r.set_size(4);
    c_r1.set_size(4);
    for (int i28{0}; i28 < 4; i28++) {
      r[i28] = static_cast<signed char>(i28);
      c_r1[i28] = static_cast<signed char>(i28);
    }
    coder::inv(orientation_matrix, dv2);
    for (int i29{0}; i29 < 3; i29++) {
      dv3[i29][0] = dv2[i29][0];
      dv3[i29][1] = dv2[i29][1];
      dv3[i29][2] = dv2[i29][2];
      dv3[3][i29] = translation_vector[i29];
    }
    for (int i30{0}; i30 < 4; i30++) {
      dv3[i30][3] = static_cast<double>(iv[i30]);
    }
    for (int i31{0}; i31 < 4; i31++) {
      for (int i32{0}; i32 < 4; i32++) {
        cam_extrinsics
            [((static_cast<int>(r[i32])) +
              (cam_extrinsics.size(0) * (static_cast<int>(c_r1[i31])))) +
             ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) * g_i)] =
                (&dv3[0][0])[i32 + (4 * i31)];
      }
    }
    //  inverted of cam_extrinsics
    r.set_size(4);
    c_r1.set_size(4);
    for (int i33{0}; i33 < 4; i33++) {
      r[i33] = static_cast<signed char>(i33);
      c_r1[i33] = static_cast<signed char>(i33);
    }
    for (int i34{0}; i34 < 3; i34++) {
      b_orientation_matrix[i34][0] = -orientation_matrix[i34][0];
      b_orientation_matrix[i34][1] = -orientation_matrix[i34][1];
      b_orientation_matrix[i34][2] = -orientation_matrix[i34][2];
    }
    d3 = dv1[0];
    d4 = dv1[1];
    d5 = dv1[2];
    for (int i35{0}; i35 < 3; i35++) {
      c_orientation_matrix[i35][0] = orientation_matrix[i35][0];
      c_orientation_matrix[i35][1] = orientation_matrix[i35][1];
      c_orientation_matrix[i35][2] = orientation_matrix[i35][2];
      c_orientation_matrix[3][i35] = ((b_orientation_matrix[0][i35] * d3) +
                                      (b_orientation_matrix[1][i35] * d4)) +
                                     (b_orientation_matrix[2][i35] * d5);
    }
    for (int i36{0}; i36 < 4; i36++) {
      c_orientation_matrix[i36][3] = static_cast<double>(iv[i36]);
    }
    for (int i37{0}; i37 < 4; i37++) {
      for (int i38{0}; i38 < 4; i38++) {
        camera_poses[((static_cast<int>(r[i38])) +
                      (camera_poses.size(0) * (static_cast<int>(c_r1[i37])))) +
                     ((camera_poses.size(0) * camera_poses.size(1)) * g_i)] =
            (&c_orientation_matrix[0][0])[i38 + (4 * i37)];
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
