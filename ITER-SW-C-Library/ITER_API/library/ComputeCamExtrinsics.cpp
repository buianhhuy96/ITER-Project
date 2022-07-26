//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ComputeCamExtrinsics.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_types.h"
#include "cameraParameters.h"
#include "detectCheckerboardPoints.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "isequal.h"
#include "mldivide.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Initialize error and camera parameters
//
// Arguments    : const ::coder::array<unsigned char, 4U> &images
//                double squareSize
//                const struct1_T *cameraParams
//                ::coder::array<double, 3U> &b_imagePoints
//                ::coder::array<bool, 1U> &validIdx
//                ::coder::array<double, 3U> &camExtrinsics
//                ::coder::array<double, 3U> &cameraPoses
//                ::coder::array<double, 2U> &c_worldPoints
//                int *err
// Return Type  : void
//
namespace ITER {
void ComputeCamExtrinsics(const ::coder::array<unsigned char, 4U> &images,
                          double squareSize, const struct1_T *cameraParams,
                          ::coder::array<double, 3U> &b_imagePoints,
                          ::coder::array<bool, 1U> &validIdx,
                          ::coder::array<double, 3U> &camExtrinsics,
                          ::coder::array<double, 3U> &cameraPoses,
                          ::coder::array<double, 2U> &c_worldPoints, int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::cameraParameters b_cameraParams;
  coder::projective2d H;
  ::coder::array<cell_wrap_19, 2U> board_points;
  ::coder::array<double, 2U> c_imagePoints;
  ::coder::array<double, 2U> current_board_points;
  ::coder::array<double, 2U> d_worldPoints;
  ::coder::array<unsigned char, 2U> b_images;
  ::coder::array<signed char, 1U> c_r1;
  ::coder::array<signed char, 1U> r;
  ::coder::array<bool, 1U> b_x;
  double c_orientation_matrix[4][4];
  double dv3[4][4];
  double A[3][3];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_H[3][3];
  double b_dv2[3][3];
  double b_orientation_matrix[3][3];
  double b_r1[3][3];
  double intrinsics[3][3];
  double orientation_matrix[3][3];
  double b_dv1[3];
  double b_lambda[3];
  double b_translation_vector[3];
  double e_x[3];
  double r1[3];
  double r2[3];
  double b_dv[2];
  double board_size_detected[2];
  double board_size_valid[2];
  int translation_vector[3];
  int b_err;
  int b_i;
  int c_err;
  int i10;
  int i12;
  int i15;
  int i17;
  int i25;
  int i29;
  int i5;
  int i7;
  int i_loop_ub;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  int k_loop_ub;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  cameraParams: camera parameters  matlab object
  (void)b_cameraParams.b_init(
      cameraParams->RadialDistortion, cameraParams->TangentialDistortion,
      cameraParams->ImageSize, cameraParams->WorldUnits,
      cameraParams->EstimateSkew, cameraParams->NumRadialDistortionCoefficients,
      cameraParams->EstimateTangentialDistortion,
      cameraParams->IntrinsicMatrix);
  //  Get checkerboard points
  //  Initialize error flags
  b_err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size_idx_0 = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size_idx_1 = 0;
  validIdx.set_size(images.size(3));
  //  perform checkerboards detection in each image
  b_i = images.size(3);
  board_points.set_size(1, images.size(3));
  for (int c_i{0}; c_i < b_i; c_i++) {
    int b_loop_ub;
    int e_loop_ub;
    int loop_ub;
    loop_ub = images.size(0);
    b_loop_ub = images.size(1);
    b_images.set_size(images.size(0), images.size(1));
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_images[i2 + (b_images.size(0) * i1)] =
            images[(i2 + (images.size(0) * i1)) +
                   ((images.size(0) * images.size(1)) * c_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    if (coder::isequal(board_size_detected, b_dv)) {
      validIdx[c_i] = false;
    } else {
      b_dv[0] = 0.0;
      b_dv[1] = 0.0;
      if (coder::isequal(board_size_valid, b_dv)) {
        board_size_valid[0] = board_size_detected[0];
        image_point_valid_size_idx_0 = current_board_points.size(0);
        board_size_valid[1] = board_size_detected[1];
        image_point_valid_size_idx_1 = current_board_points.size(1);
      } else if (!coder::isequal(board_size_valid, board_size_detected)) {
        b_err = -102;
      } else {
        /* no actions */
      }
      validIdx[c_i] = true;
    }
    e_loop_ub = current_board_points.size(1);
    board_points[board_points.size(0) * c_i].f1.set_size(
        current_board_points.size(0), current_board_points.size(1));
    for (int i6{0}; i6 < e_loop_ub; i6++) {
      int g_loop_ub;
      g_loop_ub = current_board_points.size(0);
      for (int b_i8{0}; b_i8 < g_loop_ub; b_i8++) {
        board_points[c_i].f1[b_i8 + (board_points[c_i].f1.size(0) * i6)] =
            current_board_points[b_i8 + (current_board_points.size(0) * i6)];
      }
    }
  }
  if (b_err != 0) {
    // err = "Checkerboards detected has different size from given boardSize";
    b_imagePoints.set_size(0, 0, 1);
    c_worldPoints.set_size(0, 0);
  } else {
    int k;
    bool exitg1;
    bool varargout_1;
    varargout_1 = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (validIdx.size(0) - 1))) {
      if (validIdx[k]) {
        varargout_1 = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!varargout_1) {
      // err = "No detect of checkerboard in all images";
      b_err = -101;
      b_imagePoints.set_size(0, 0, 1);
      c_worldPoints.set_size(0, 0);
    } else {
      int b_y;
      int board_size_valid_idx_0;
      unsigned int c_k;
      int c_loop_ub;
      int h_loop_ub;
      int i14;
      int i26;
      unsigned int j;
      int q_loop_ub;
      int r_loop_ub;
      int vlen;
      //  Extract valid image points into matrix
      b_x.set_size(validIdx.size(0));
      c_loop_ub = validIdx.size(0);
      if ((static_cast<int>(validIdx.size(0) < 4)) != 0) {
        for (int i3{0}; i3 < c_loop_ub; i3++) {
          b_x[i3] = validIdx[i3];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i3 = 0; i3 < c_loop_ub; i3++) {
          b_x[i3] = validIdx[i3];
        }
      }
      vlen = b_x.size(0);
      if (b_x.size(0) == 0) {
        b_y = 0;
      } else {
        int y;
        y = static_cast<int>(b_x[0]);
        for (int b_k{2}; b_k <= vlen; b_k++) {
          int c_y;
          c_y = y;
          if (vlen >= 2) {
            c_y = y + (static_cast<int>(b_x[b_k - 1]));
          }
          y = c_y;
        }
        b_y = y;
      }
      translation_vector[0] = image_point_valid_size_idx_0;
      translation_vector[1] = image_point_valid_size_idx_1;
      b_imagePoints.set_size(image_point_valid_size_idx_0,
                             image_point_valid_size_idx_1, b_y);
      h_loop_ub = b_y;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i15, i_loop_ub, i17, k_loop_ub)

      for (int i13 = 0; i13 < h_loop_ub; i13++) {
        k_loop_ub = translation_vector[1];
        for (i17 = 0; i17 < k_loop_ub; i17++) {
          i_loop_ub = translation_vector[0];
          for (i15 = 0; i15 < i_loop_ub; i15++) {
            b_imagePoints[(i15 + (b_imagePoints.size(0) * i17)) +
                          ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                           i13)] = 0.0;
          }
        }
      }
      j = 1U;
      i14 = images.size(3);
      for (int e_i{0}; e_i < i14; e_i++) {
        if (validIdx[e_i]) {
          int j_loop_ub;
          j_loop_ub = board_points[e_i].f1.size(1);
          for (int i19{0}; i19 < j_loop_ub; i19++) {
            int p_loop_ub;
            p_loop_ub = board_points[e_i].f1.size(0);
            for (int i21{0}; i21 < p_loop_ub; i21++) {
              b_imagePoints[(i21 + (b_imagePoints.size(0) * i19)) +
                            ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                             ((static_cast<int>(j)) - 1))] =
                  board_points[e_i]
                      .f1[i21 + (board_points[e_i].f1.size(0) * i19)];
            }
          }
          j++;
        }
      }
      //  Generate world coordinates of the corners of the squares in meters
      board_size_valid[0]--;
      board_size_valid[1]--;
      board_size_valid_idx_0 = static_cast<int>(
          static_cast<double>(board_size_valid[0] * board_size_valid[1]));
      d_worldPoints.set_size(board_size_valid_idx_0, 2);
      q_loop_ub = board_size_valid_idx_0;
      if ((static_cast<int>((board_size_valid_idx_0 * 2) < 4)) != 0) {
        for (int i23{0}; i23 < 2; i23++) {
          for (i25 = 0; i25 < board_size_valid_idx_0; i25++) {
            d_worldPoints[i25 + (d_worldPoints.size(0) * i23)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i25)

        for (int i23 = 0; i23 < 2; i23++) {
          for (i25 = 0; i25 < q_loop_ub; i25++) {
            d_worldPoints[i25 + (d_worldPoints.size(0) * i23)] = 0.0;
          }
        }
      }
      c_k = 1U;
      i26 = static_cast<int>(
          static_cast<double>((board_size_valid[1] - 1.0) + 1.0));
      for (int b_j{0}; b_j < i26; b_j++) {
        int i27;
        i27 = static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0));
        for (int g_i{0}; g_i < i27; g_i++) {
          int b_worldPoints_tmp;
          b_worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                  c_k + (static_cast<unsigned int>(g_i))))) -
                              1;
          d_worldPoints[b_worldPoints_tmp] =
              (static_cast<double>(b_j)) * squareSize;
          d_worldPoints[b_worldPoints_tmp + d_worldPoints.size(0)] =
              (static_cast<double>(g_i)) * squareSize;
        }
        c_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0)));
      }
      c_worldPoints.set_size(d_worldPoints.size(0), 2);
      r_loop_ub = d_worldPoints.size(0);
      if ((static_cast<int>((d_worldPoints.size(0) * 2) < 4)) != 0) {
        for (int i28{0}; i28 < 2; i28++) {
          for (i29 = 0; i29 < r_loop_ub; i29++) {
            c_worldPoints[i29 + (c_worldPoints.size(0) * i28)] =
                d_worldPoints[i29 + (d_worldPoints.size(0) * i28)];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i29)

        for (int i28 = 0; i28 < 2; i28++) {
          for (i29 = 0; i29 < r_loop_ub; i29++) {
            c_worldPoints[i29 + (c_worldPoints.size(0) * i28)] =
                d_worldPoints[i29 + (d_worldPoints.size(0) * i28)];
          }
        }
      }
    }
  }
  c_err = b_err;
  //  Terminate in case of error
  if (b_err != 0) {
    camExtrinsics.set_size(0, 0, 1);
    cameraPoses.set_size(0, 0, 1);
  } else {
    int d_loop_ub;
    int f_loop_ub;
    int i11;
    //  compute extrinsics
    camExtrinsics.set_size(4, 4, b_imagePoints.size(2));
    d_loop_ub = b_imagePoints.size(2);
    if ((static_cast<int>((b_imagePoints.size(2) * 16) < 4)) != 0) {
      for (int i4{0}; i4 < d_loop_ub; i4++) {
        for (i5 = 0; i5 < 4; i5++) {
          for (i7 = 0; i7 < 4; i7++) {
            camExtrinsics[(i7 + (camExtrinsics.size(0) * i5)) +
                          ((camExtrinsics.size(0) * camExtrinsics.size(1)) *
                           i4)] = 0.0;
          }
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7, i5)

      for (int i4 = 0; i4 < d_loop_ub; i4++) {
        for (i5 = 0; i5 < 4; i5++) {
          for (i7 = 0; i7 < 4; i7++) {
            camExtrinsics[(i7 + (camExtrinsics.size(0) * i5)) +
                          ((camExtrinsics.size(0) * camExtrinsics.size(1)) *
                           i4)] = 0.0;
          }
        }
      }
    }
    cameraPoses.set_size(4, 4, b_imagePoints.size(2));
    f_loop_ub = b_imagePoints.size(2);
    if ((static_cast<int>((b_imagePoints.size(2) * 16) < 4)) != 0) {
      for (int i9{0}; i9 < f_loop_ub; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          for (i12 = 0; i12 < 4; i12++) {
            cameraPoses[(i12 + (cameraPoses.size(0) * i10)) +
                        ((cameraPoses.size(0) * cameraPoses.size(1)) * i9)] =
                0.0;
          }
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12, i10)

      for (int i9 = 0; i9 < f_loop_ub; i9++) {
        for (i10 = 0; i10 < 4; i10++) {
          for (i12 = 0; i12 < 4; i12++) {
            cameraPoses[(i12 + (cameraPoses.size(0) * i10)) +
                        ((cameraPoses.size(0) * cameraPoses.size(1)) * i9)] =
                0.0;
          }
        }
      }
    }
    i11 = b_imagePoints.size(2);
    for (int d_i{0}; d_i < i11; d_i++) {
      double absxk;
      double b_t;
      double d3;
      double d4;
      double d5;
      double d_y;
      double lambda;
      double scale;
      int m_loop_ub;
      int o_loop_ub;
      //  transformations from the grid/world coordinates to the camera-based
      //  coordinates
      for (int i16{0}; i16 < 3; i16++) {
        intrinsics[i16][0] = b_cameraParams.IntrinsicMatrixInternal[0][i16];
        intrinsics[i16][1] = b_cameraParams.IntrinsicMatrixInternal[1][i16];
        intrinsics[i16][2] = b_cameraParams.IntrinsicMatrixInternal[2][i16];
      }
      for (int i18{0}; i18 < 3; i18++) {
        A[i18][0] = intrinsics[0][i18];
        A[i18][1] = intrinsics[1][i18];
        A[i18][2] = intrinsics[2][i18];
      }
      m_loop_ub = b_imagePoints.size(0);
      o_loop_ub = b_imagePoints.size(1);
      c_imagePoints.set_size(b_imagePoints.size(0), b_imagePoints.size(1));
      for (int i20{0}; i20 < o_loop_ub; i20++) {
        for (int i22{0}; i22 < m_loop_ub; i22++) {
          c_imagePoints[i22 + (c_imagePoints.size(0) * i20)] =
              b_imagePoints[(i22 + (b_imagePoints.size(0) * i20)) +
                            ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                             d_i)];
        }
      }
      coder::fitgeotrans(c_worldPoints, c_imagePoints, &H);
      for (int i24{0}; i24 < 3; i24++) {
        b_H[i24][0] = H.T[0][i24];
        b_H[i24][1] = H.T[1][i24];
        b_H[i24][2] = H.T[2][i24];
      }
      coder::c_mldivide(A, *((double(*)[3])(&b_H[0][0])), e_x);
      scale = 3.3121686421112381E-170;
      absxk = std::abs(e_x[0]);
      if (absxk > 3.3121686421112381E-170) {
        d_y = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        d_y = b_t * b_t;
      }
      absxk = std::abs(e_x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        d_y = ((d_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        d_y += b_t * b_t;
      }
      absxk = std::abs(e_x[2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        d_y = ((d_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        d_y += b_t * b_t;
      }
      d_y = scale * std::sqrt(d_y);
      lambda = 1.0 / d_y;
      b_lambda[0] = lambda * b_H[0][0];
      b_lambda[1] = lambda * b_H[0][1];
      b_lambda[2] = lambda * b_H[0][2];
      coder::c_mldivide(A, b_lambda, r1);
      b_lambda[0] = lambda * b_H[1][0];
      b_lambda[1] = lambda * b_H[1][1];
      b_lambda[2] = lambda * b_H[1][2];
      coder::c_mldivide(A, b_lambda, r2);
      b_r1[0][0] = r1[0];
      b_r1[0][1] = r2[0];
      b_r1[1][0] = r1[1];
      b_r1[1][1] = r2[1];
      b_r1[2][0] = r1[2];
      b_r1[2][1] = r2[2];
      b_r1[0][2] = (r1[1] * r2[2]) - (r2[1] * r1[2]);
      b_r1[1][2] = (r2[0] * r1[2]) - (r1[0] * r2[2]);
      b_r1[2][2] = (r1[0] * r2[1]) - (r2[0] * r1[1]);
      coder::b_svd(b_r1, U, a__1, V);
      for (int i30{0}; i30 < 3; i30++) {
        double b_d1;
        double d;
        double d2;
        d = U[0][i30];
        b_d1 = U[1][i30];
        d2 = U[2][i30];
        for (int i31{0}; i31 < 3; i31++) {
          orientation_matrix[i31][i30] =
              ((d * V[0][i31]) + (b_d1 * V[1][i31])) + (d2 * V[2][i31]);
        }
        b_lambda[i30] = lambda * b_H[2][i30];
      }
      coder::c_mldivide(A, b_lambda, b_dv1);
      b_translation_vector[0] = b_dv1[0];
      b_translation_vector[1] = b_dv1[1];
      b_translation_vector[2] = b_dv1[2];
      r.set_size(4);
      c_r1.set_size(4);
      for (int i32{0}; i32 < 4; i32++) {
        r[i32] = static_cast<signed char>(i32);
        c_r1[i32] = static_cast<signed char>(i32);
      }
      coder::inv(orientation_matrix, b_dv2);
      for (int i33{0}; i33 < 3; i33++) {
        dv3[i33][0] = b_dv2[i33][0];
        dv3[i33][1] = b_dv2[i33][1];
        dv3[i33][2] = b_dv2[i33][2];
        dv3[3][i33] = b_translation_vector[i33];
      }
      for (int i34{0}; i34 < 4; i34++) {
        dv3[i34][3] = static_cast<double>(b_iv[i34]);
      }
      for (int i35{0}; i35 < 4; i35++) {
        for (int i36{0}; i36 < 4; i36++) {
          camExtrinsics
              [((static_cast<int>(r[i36])) +
                (camExtrinsics.size(0) * (static_cast<int>(c_r1[i35])))) +
               ((camExtrinsics.size(0) * camExtrinsics.size(1)) * d_i)] =
                  (&dv3[0][0])[i36 + (4 * i35)];
        }
      }
      //  inverted of camExtrinsics
      r.set_size(4);
      c_r1.set_size(4);
      for (int i37{0}; i37 < 4; i37++) {
        r[i37] = static_cast<signed char>(i37);
        c_r1[i37] = static_cast<signed char>(i37);
      }
      for (int i38{0}; i38 < 3; i38++) {
        b_orientation_matrix[i38][0] = -orientation_matrix[i38][0];
        b_orientation_matrix[i38][1] = -orientation_matrix[i38][1];
        b_orientation_matrix[i38][2] = -orientation_matrix[i38][2];
      }
      d3 = b_dv1[0];
      d4 = b_dv1[1];
      d5 = b_dv1[2];
      for (int i39{0}; i39 < 3; i39++) {
        c_orientation_matrix[i39][0] = orientation_matrix[i39][0];
        c_orientation_matrix[i39][1] = orientation_matrix[i39][1];
        c_orientation_matrix[i39][2] = orientation_matrix[i39][2];
        c_orientation_matrix[3][i39] = ((b_orientation_matrix[0][i39] * d3) +
                                        (b_orientation_matrix[1][i39] * d4)) +
                                       (b_orientation_matrix[2][i39] * d5);
      }
      for (int i40{0}; i40 < 4; i40++) {
        c_orientation_matrix[i40][3] = static_cast<double>(b_iv[i40]);
      }
      for (int i41{0}; i41 < 4; i41++) {
        for (int i42{0}; i42 < 4; i42++) {
          cameraPoses[((static_cast<int>(r[i42])) +
                       (cameraPoses.size(0) * (static_cast<int>(c_r1[i41])))) +
                      ((cameraPoses.size(0) * cameraPoses.size(1)) * d_i)] =
              (&c_orientation_matrix[0][0])[i42 + (4 * i41)];
        }
      }
    }
  }
  *err = c_err;
}

} // namespace ITER

//
// File trailer for ComputeCamExtrinsics.cpp
//
// [EOF]
//
