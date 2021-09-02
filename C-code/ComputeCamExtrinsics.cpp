//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
#include "mldivide.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &b_images
//                double square_size
//                const struct0_T *camera_params
//                coder::array<double, 3U> &image_points
//                coder::array<bool, 1U> &valid_idx
//                coder::array<double, 3U> &cam_extrinsics
//                coder::array<double, 3U> &camera_poses
//                coder::array<double, 2U> &world_points
// Return Type  : void
//
void ComputeCamExtrinsics(const coder::array<unsigned char, 4U> &b_images,
                          double square_size, const struct0_T *camera_params,
                          coder::array<double, 3U> &image_points,
                          coder::array<bool, 1U> &valid_idx,
                          coder::array<double, 3U> &cam_extrinsics,
                          coder::array<double, 3U> &camera_poses,
                          coder::array<double, 2U> &world_points)
{
  coder::cameraParameters b_camera_params;
  coder::projective2d H;
  coder::array<double, 3U> b_board_points;
  coder::array<double, 2U> board_points;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> r2;
  coder::array<unsigned char, 2U> c_images;
  double U[3][3];
  double V[3][3];
  double b_H[3][3];
  double b_a__1[3][3];
  double c_r1[3][3];
  double rotationMatrix[3][3];
  double b_r1[3];
  double b_r2[3];
  double lambda[3];
  double a__1[2];
  double board_size[2];
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  unsigned int k;
  int loop_ub;
  int num_of_valid_images;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  camera_params: camera parameters  matlab object
  for (i = 0; i < 3; i++) {
    b_camera_params.IntrinsicMatrixInternal[i][0] =
        camera_params->IntrinsicMatrix[0][i];
    b_camera_params.IntrinsicMatrixInternal[i][1] =
        camera_params->IntrinsicMatrix[1][i];
    b_camera_params.IntrinsicMatrixInternal[i][2] =
        camera_params->IntrinsicMatrix[2][i];
  }
  //  Detect checkerboards in images
  loop_ub = b_images.size(0);
  b_loop_ub = b_images.size(1);
  c_images.set_size(b_images.size(0), b_images.size(1));
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_images[i1 + (c_images.size(0) * i)] =
          b_images[i1 + (b_images.size(0) * i)];
    }
  }
  coder::detectCheckerboardPoints(c_images, board_points, board_size);
  loop_ub = board_points.size(0);
  b_loop_ub = board_points.size(1);
  b_board_points.set_size(board_points.size(0), board_points.size(1),
                          b_images.size(3));
  c_loop_ub = b_images.size(3);
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (num_of_valid_images = 0; num_of_valid_images < loop_ub;
           num_of_valid_images++) {
        b_board_points[(num_of_valid_images + (b_board_points.size(0) * i1)) +
                       ((b_board_points.size(0) * b_board_points.size(1)) *
                        i)] = 0.0;
      }
    }
  }
  valid_idx.set_size(b_images.size(3));
  loop_ub = b_images.size(3);
  for (i = 0; i < loop_ub; i++) {
    valid_idx[i] = false;
  }
  i = b_images.size(3);
  for (b_i = 0; b_i < i; b_i++) {
    //  perform checkerboards detection in each image
    loop_ub = b_images.size(0);
    b_loop_ub = b_images.size(1);
    c_images.set_size(b_images.size(0), b_images.size(1));
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (num_of_valid_images = 0; num_of_valid_images < loop_ub;
           num_of_valid_images++) {
        c_images[num_of_valid_images + (c_images.size(0) * i1)] =
            b_images[(num_of_valid_images + (b_images.size(0) * i1)) +
                     ((b_images.size(0) * b_images.size(1)) * b_i)];
      }
    }
    coder::detectCheckerboardPoints(c_images, board_points, a__1);
    //  mark if checkerboards is detected or not
    loop_ub = board_points.size(1);
    if ((board_points.size(0) == 0) || (board_points.size(1) == 0)) {
      valid_idx[b_i] = false;
    } else {
      valid_idx[b_i] = true;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = board_points.size(0);
        for (num_of_valid_images = 0; num_of_valid_images < b_loop_ub;
             num_of_valid_images++) {

      	  volatile double a = board_points[num_of_valid_images + (board_points.size(0) * i1)];
          b_board_points[(num_of_valid_images + (b_board_points.size(0) * i1)) +
                         ((b_board_points.size(0) * b_board_points.size(1)) *
                          b_i)] =
              board_points[num_of_valid_images + (board_points.size(0) * i1)];
        }
      }
    }
  }
  loop_ub = valid_idx.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (valid_idx[b_i]) {
      c_loop_ub++;
    }
  }
  r.set_size(c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (valid_idx[b_i]) {
      r[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  loop_ub = b_board_points.size(0);
  b_loop_ub = b_board_points.size(1);
  image_points.set_size(b_board_points.size(0), b_board_points.size(1),
                        r.size(0));
  c_loop_ub = r.size(0);
  for (i = 0; i < c_loop_ub; i++) {
	  volatile int a = r[i];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (num_of_valid_images = 0; num_of_valid_images < loop_ub;
           num_of_valid_images++) {
    	  volatile double u =   b_board_points[(num_of_valid_images +
    	                              (b_board_points.size(0) * i1)) +
    	                             ((b_board_points.size(0) * b_board_points.size(1)) *
    	                              (r[i] - 1))];
        image_points[(num_of_valid_images + (image_points.size(0) * i1)) +
                     ((image_points.size(0) * image_points.size(1)) * i)] =
            b_board_points[(num_of_valid_images +
                            (b_board_points.size(0) * i1)) +
                           ((b_board_points.size(0) * b_board_points.size(1)) *
                            (r[i] - 1))];
      }
    }
  }
  //  Generate world coordinates of the corners of the squares in meters
  board_size[0]--;
  board_size[1]--;
  c_loop_ub =
      static_cast<int>(static_cast<double>(board_size[0] * board_size[1]));
  world_points.set_size(c_loop_ub, 2);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      world_points[i1 + (world_points.size(0) * i)] = 0.0;
    }
  }
  k = 1U;
  i = static_cast<int>(static_cast<double>((board_size[1] - 1.0) + 1.0));
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    i1 = static_cast<int>(static_cast<double>((board_size[0] - 1.0) + 1.0));
    for (b_i = 0; b_i < i1; b_i++) {
      c_loop_ub = (static_cast<int>(static_cast<unsigned int>(
                      k + (static_cast<unsigned int>(b_i))))) -
                  1;
      world_points[c_loop_ub] = (static_cast<double>(loop_ub)) * square_size;
      world_points[c_loop_ub + world_points.size(0)] =
          (static_cast<double>(b_i)) * square_size;
    }
    k += static_cast<unsigned int>(
        static_cast<int>(static_cast<double>((board_size[0] - 1.0) + 1.0)));
  }
  //  compute extrinsics
  loop_ub = valid_idx.size(0) - 1;
  c_loop_ub = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (valid_idx[b_i]) {
      c_loop_ub++;
    }
  }
  r1.set_size(c_loop_ub);
  c_loop_ub = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (valid_idx[b_i]) {
      r1[c_loop_ub] = b_i + 1;
      c_loop_ub++;
    }
  }
  num_of_valid_images = r1.size(0);
  cam_extrinsics.set_size(4, 4, r1.size(0));
  camera_poses.set_size(4, 4, r1.size(0));
  for (b_i = 0; b_i < num_of_valid_images; b_i++) {
    double absxk;
    double scale;
    double t;
    double y;
    //  transformations from the grid/world coordinates to the camera-based
    //  coordinates
    loop_ub = valid_idx.size(0) - 1;
    c_loop_ub = 0;
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      if (valid_idx[b_loop_ub]) {
        c_loop_ub++;
      }
    }
    r2.set_size(c_loop_ub);
    c_loop_ub = 0;
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      if (valid_idx[b_loop_ub]) {
        r2[c_loop_ub] = b_loop_ub + 1;
        c_loop_ub++;
      }
    }
    loop_ub = b_board_points.size(0) - 1;
    b_loop_ub = b_board_points.size(1) - 1;
    board_points.set_size(b_board_points.size(0), b_board_points.size(1));
    for (i = 0; i <= b_loop_ub; i++) {
      for (i1 = 0; i1 <= loop_ub; i1++) {
        board_points[i1 + (board_points.size(0) * i)] =
            b_board_points[(i1 + (b_board_points.size(0) * i)) +
                           ((b_board_points.size(0) * b_board_points.size(1)) *
                            (r2[b_i] - 1))];
      }
    }
    coder::findProjectiveTransform(world_points, board_points, &H);
    for (i = 0; i < 3; i++) {
      b_H[i][0] = H.T[0][i];
      b_H[i][1] = H.T[1][i];
      b_H[i][2] = H.T[2][i];
    }
    coder::mldivide(b_camera_params.IntrinsicMatrixInternal,
                    *((double(*)[3])(&b_H[0][0])), b_r1);
    scale = 3.3121686421112381E-170;
    absxk = std::abs(b_r1[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }
    absxk = std::abs(b_r1[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = ((y * t) * t) + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    absxk = std::abs(b_r1[2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = ((y * t) * t) + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
    y = scale * std::sqrt(y);
    scale = 1.0 / y;
    lambda[0] = scale * b_H[0][0];
    lambda[1] = scale * b_H[0][1];
    lambda[2] = scale * b_H[0][2];
    coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, b_r1);
    lambda[0] = scale * b_H[1][0];
    lambda[1] = scale * b_H[1][1];
    lambda[2] = scale * b_H[1][2];
    coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, b_r2);
    c_r1[0][0] = b_r1[0];
    c_r1[0][1] = b_r2[0];
    c_r1[1][0] = b_r1[1];
    c_r1[1][1] = b_r2[1];
    c_r1[2][0] = b_r1[2];
    c_r1[2][1] = b_r2[2];
    c_r1[0][2] = (b_r1[1] * b_r2[2]) - (b_r2[1] * b_r1[2]);
    c_r1[1][2] = (b_r2[0] * b_r1[2]) - (b_r1[0] * b_r2[2]);
    c_r1[2][2] = (b_r1[0] * b_r2[1]) - (b_r2[0] * b_r1[1]);
    coder::svd(c_r1, U, b_a__1, V);
    for (i = 0; i < 3; i++) {
      absxk = U[0][i];
      t = U[1][i];
      y = U[2][i];
      for (i1 = 0; i1 < 3; i1++) {
        rotationMatrix[i1][i] =
            ((absxk * V[0][i1]) + (t * V[1][i1])) + (y * V[2][i1]);
      }
      lambda[i] = scale * b_H[2][i];
    }
    coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, b_r1);
    coder::inv(rotationMatrix, b_a__1);
    for (i = 0; i < 3; i++) {
      cam_extrinsics[(4 * i) + (16 * b_i)] = b_a__1[i][0];
      cam_extrinsics[((4 * i) + (16 * b_i)) + 1] = b_a__1[i][1];
      cam_extrinsics[((4 * i) + (16 * b_i)) + 2] = b_a__1[i][2];
      cam_extrinsics[(i + (16 * b_i)) + 12] = b_r1[i];
    }
    cam_extrinsics[(16 * b_i) + 3] = 0.0;
    cam_extrinsics[(16 * b_i) + 7] = 0.0;
    cam_extrinsics[(16 * b_i) + 11] = 0.0;
    cam_extrinsics[(16 * b_i) + 15] = 1.0;
    //  inverted of cam_extrinsics
    for (i = 0; i < 3; i++) {
      c_r1[i][0] = -rotationMatrix[i][0];
      c_r1[i][1] = -rotationMatrix[i][1];
      c_r1[i][2] = -rotationMatrix[i][2];
    }
    absxk = b_r1[0];
    t = b_r1[1];
    y = b_r1[2];
    for (i = 0; i < 3; i++) {
      camera_poses[(4 * i) + (16 * b_i)] = rotationMatrix[i][0];
      camera_poses[((4 * i) + (16 * b_i)) + 1] = rotationMatrix[i][1];
      camera_poses[((4 * i) + (16 * b_i)) + 2] = rotationMatrix[i][2];
      camera_poses[(i + (16 * b_i)) + 12] =
          ((c_r1[0][i] * absxk) + (c_r1[1][i] * t)) + (c_r1[2][i] * y);
    }
    camera_poses[(16 * b_i) + 3] = 0.0;
    camera_poses[(16 * b_i) + 7] = 0.0;
    camera_poses[(16 * b_i) + 11] = 0.0;
    camera_poses[(16 * b_i) + 15] = 1.0;
  }
}

//
// File trailer for ComputeCamExtrinsics.cpp
//
// [EOF]
//
