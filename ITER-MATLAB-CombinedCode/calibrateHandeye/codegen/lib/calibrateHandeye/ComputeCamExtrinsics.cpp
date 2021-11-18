//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ComputeCamExtrinsics.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
struct cell_wrap_1 {
  double f1[2];
};

struct cell_wrap_0 {
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
  coder::array<cell_wrap_0, 1U> board_points;
  coder::array<cell_wrap_1, 1U> board_sizes;
  coder::array<double, 2U> b_image_points;
  coder::array<double, 2U> c_worldPoints;
  coder::array<unsigned char, 2U> b_images;
  coder::array<signed char, 1U> c_r1;
  coder::array<signed char, 1U> r;
  coder::array<bool, 1U> b_x;
  double d__1[4][4];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_H[3][3];
  double b_r1[3][3];
  double rotationMatrix[3][3];
  double lambda[3];
  double r1[3];
  double r2[3];
  double board_size[2];
  double dv[2];
  int b_i;
  int b_loop_ub;
  int c_i;
  int c_loop_ub;
  int i1;
  int i2;
  int loop_ub;
  int vlen;
  bool exitg1;
  bool y;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  //  images: images in a [row x col x channel x numImages] array
  //  square: Checkerboard square size in meter size
  //  camera_params: camera parameters  matlab object
  image_points.set_size(0, 0, 1);
  cam_extrinsics.set_size(0, 0, 1);
  camera_poses.set_size(0, 0, 1);
  b_world_points.set_size(0, 0);
  *err = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    b_camera_params.IntrinsicMatrixInternal[b_i][0] =
        camera_params->IntrinsicMatrix[0][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][1] =
        camera_params->IntrinsicMatrix[1][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][2] =
        camera_params->IntrinsicMatrix[2][b_i];
  }
  //  Detect checkerboards in images
  valid_idx.set_size(images.size(3));
  b_i = images.size(3);
  board_points.set_size(images.size(3));
  board_sizes.set_size(images.size(3));
  if (0 <= (b_i - 1)) {
    vlen = images.size(0);
    loop_ub = images.size(1);
    dv[0] = 0.0;
    dv[1] = 0.0;
  }
  for (c_i = 0; c_i < b_i; c_i++) {
    //  perform checkerboards detection in each image
    b_images.set_size(images.size(0), images.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < vlen; i2++) {
        b_images[i2 + (b_images.size(0) * i1)] =
            images[(i2 + (images.size(0) * i1)) +
                   ((images.size(0) * images.size(1)) * c_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, board_points[c_i].f1, board_size);
    //  mark if checkerboards is detected or not
    board_sizes[c_i].f1[0] = board_size[0];
    board_sizes[c_i].f1[1] = board_size[1];
    valid_idx[c_i] = !coder::isequal(board_size, dv);
  }
  y = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= (valid_idx.size(0) - 1))) {
    if (!valid_idx[loop_ub]) {
      y = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if (!y) {
    // err = "Error during detection of checkerboard in images";
    *err = -1;
  } else {
    int nz;
    b_x.set_size(valid_idx.size(0));
    vlen = valid_idx.size(0);
    for (b_i = 0; b_i < vlen; b_i++) {
      b_x[b_i] = valid_idx[b_i];
    }
    vlen = b_x.size(0);
    if (b_x.size(0) == 0) {
      nz = 0;
    } else {
      nz = static_cast<int>(b_x[0]);
      for (loop_ub = 2; loop_ub <= vlen; loop_ub++) {
        if (vlen >= 2) {
          nz += static_cast<int>(b_x[loop_ub - 1]);
        }
      }
    }
    vlen = board_points[0].f1.size(0);
    loop_ub = board_points[0].f1.size(1);
    image_points.set_size(board_points[0].f1.size(0),
                          board_points[0].f1.size(1), nz);
    for (b_i = 0; b_i < nz; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < vlen; i2++) {
          image_points[(i2 + (image_points.size(0) * i1)) +
                       ((image_points.size(0) * image_points.size(1)) * b_i)] =
              0.0;
        }
      }
    }
    board_size[0] = 0.0;
    board_size[1] = 0.0;
    c_i = 0;
    int exitg2;
    do {
      exitg2 = 0;
      if (c_i <= (nz - 1)) {
        bool guard1{false};
        guard1 = false;
        if (valid_idx[c_i]) {
          dv[0] = 0.0;
          dv[1] = 0.0;
          if (coder::isequal(board_size, dv)) {
            board_size[0] = board_sizes[c_i].f1[0];
            board_size[1] = board_sizes[c_i].f1[1];
            guard1 = true;
          } else if (!coder::isequal(board_size, board_sizes[c_i].f1)) {
            // err = "Detect checker board with different size at " +
            // int2str(i);
            *err = -1;
            exitg2 = 1;
          } else {
            guard1 = true;
          }
        } else {
          c_i++;
        }
        if (guard1) {
          vlen = board_points[c_i].f1.size(1);
          for (b_i = 0; b_i < vlen; b_i++) {
            loop_ub = board_points[c_i].f1.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              image_points[(i1 + (image_points.size(0) * b_i)) +
                           ((image_points.size(0) * image_points.size(1)) *
                            c_i)] =
                  board_points[c_i]
                      .f1[i1 + (board_points[c_i].f1.size(0) * b_i)];
            }
          }
          c_i++;
        }
      } else {
        unsigned int k;
        //  Generate world coordinates of the corners of the squares in meters
        board_size[0]--;
        board_size[1]--;
        vlen = static_cast<int>(
            static_cast<double>(board_size[0] * board_size[1]));
        c_worldPoints.set_size(vlen, 2);
        for (b_i = 0; b_i < 2; b_i++) {
          for (i1 = 0; i1 < vlen; i1++) {
            c_worldPoints[i1 + (c_worldPoints.size(0) * b_i)] = 0.0;
          }
        }
        k = 1U;
        b_i =
            static_cast<int>(static_cast<double>((board_size[1] - 1.0) + 1.0));
        for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
          i1 = static_cast<int>(
              static_cast<double>((board_size[0] - 1.0) + 1.0));
          for (c_i = 0; c_i < i1; c_i++) {
            vlen = (static_cast<int>(static_cast<unsigned int>(
                       k + (static_cast<unsigned int>(c_i))))) -
                   1;
            c_worldPoints[vlen] = (static_cast<double>(loop_ub)) * square_size;
            c_worldPoints[vlen + c_worldPoints.size(0)] =
                (static_cast<double>(c_i)) * square_size;
          }
          k += static_cast<unsigned int>(static_cast<int>(
              static_cast<double>((board_size[0] - 1.0) + 1.0)));
        }
        b_world_points.set_size(c_worldPoints.size(0), 2);
        vlen = c_worldPoints.size(0);
        for (b_i = 0; b_i < 2; b_i++) {
          for (i1 = 0; i1 < vlen; i1++) {
            b_world_points[i1 + (b_world_points.size(0) * b_i)] =
                c_worldPoints[i1 + (c_worldPoints.size(0) * b_i)];
          }
        }
        //  compute extrinsics
        cam_extrinsics.set_size(4, 4, nz);
        camera_poses.set_size(4, 4, nz);
        for (b_i = 0; b_i < nz; b_i++) {
          for (i1 = 0; i1 < 4; i1++) {
            for (i2 = 0; i2 < 4; i2++) {
              cam_extrinsics
                  [(i2 + (cam_extrinsics.size(0) * i1)) +
                   ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) * b_i)] =
                      0.0;
              camera_poses[(i2 + (camera_poses.size(0) * i1)) +
                           ((camera_poses.size(0) * camera_poses.size(1)) *
                            b_i)] = 0.0;
            }
          }
        }
        if (0 <= (nz - 1)) {
          b_loop_ub = image_points.size(0);
          c_loop_ub = image_points.size(1);
        }
        for (c_i = 0; c_i < nz; c_i++) {
          double absxk;
          double b_t;
          double b_y;
          double scale;
          //  transformations from the grid/world coordinates to the
          //  camera-based coordinates
          b_image_points.set_size(image_points.size(0), image_points.size(1));
          for (b_i = 0; b_i < c_loop_ub; b_i++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_image_points[i1 + (b_image_points.size(0) * b_i)] =
                  image_points[(i1 + (image_points.size(0) * b_i)) +
                               ((image_points.size(0) * image_points.size(1)) *
                                c_i)];
            }
          }
          coder::findProjectiveTransform(c_worldPoints, b_image_points, &H);
          for (b_i = 0; b_i < 3; b_i++) {
            b_H[b_i][0] = H.T[0][b_i];
            b_H[b_i][1] = H.T[1][b_i];
            b_H[b_i][2] = H.T[2][b_i];
          }
          coder::mldivide(b_camera_params.IntrinsicMatrixInternal,
                          *((double(*)[3])(&b_H[0][0])), r1);
          scale = 3.3121686421112381E-170;
          absxk = std::abs(r1[0]);
          if (absxk > 3.3121686421112381E-170) {
            b_y = 1.0;
            scale = absxk;
          } else {
            b_t = absxk / 3.3121686421112381E-170;
            b_y = b_t * b_t;
          }
          absxk = std::abs(r1[1]);
          if (absxk > scale) {
            b_t = scale / absxk;
            b_y = ((b_y * b_t) * b_t) + 1.0;
            scale = absxk;
          } else {
            b_t = absxk / scale;
            b_y += b_t * b_t;
          }
          absxk = std::abs(r1[2]);
          if (absxk > scale) {
            b_t = scale / absxk;
            b_y = ((b_y * b_t) * b_t) + 1.0;
            scale = absxk;
          } else {
            b_t = absxk / scale;
            b_y += b_t * b_t;
          }
          b_y = scale * std::sqrt(b_y);
          scale = 1.0 / b_y;
          lambda[0] = scale * b_H[0][0];
          lambda[1] = scale * b_H[0][1];
          lambda[2] = scale * b_H[0][2];
          coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, r1);
          lambda[0] = scale * b_H[1][0];
          lambda[1] = scale * b_H[1][1];
          lambda[2] = scale * b_H[1][2];
          coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, r2);
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
          for (b_i = 0; b_i < 3; b_i++) {
            absxk = U[0][b_i];
            b_t = U[1][b_i];
            b_y = U[2][b_i];
            for (i1 = 0; i1 < 3; i1++) {
              rotationMatrix[i1][b_i] =
                  ((absxk * V[0][i1]) + (b_t * V[1][i1])) + (b_y * V[2][i1]);
            }
            lambda[b_i] = scale * b_H[2][b_i];
          }
          coder::mldivide(b_camera_params.IntrinsicMatrixInternal, lambda, r1);
          r.set_size(4);
          c_r1.set_size(4);
          for (b_i = 0; b_i < 4; b_i++) {
            r[b_i] = static_cast<signed char>(b_i);
            c_r1[b_i] = static_cast<signed char>(b_i);
          }
          coder::inv(rotationMatrix, a__1);
          for (b_i = 0; b_i < 3; b_i++) {
            d__1[b_i][0] = a__1[b_i][0];
            d__1[b_i][1] = a__1[b_i][1];
            d__1[b_i][2] = a__1[b_i][2];
            d__1[3][b_i] = r1[b_i];
          }
          for (b_i = 0; b_i < 4; b_i++) {
            d__1[b_i][3] = static_cast<double>(iv[b_i]);
          }
          for (b_i = 0; b_i < 4; b_i++) {
            for (i1 = 0; i1 < 4; i1++) {
              cam_extrinsics
                  [((static_cast<int>(r[i1])) +
                    (cam_extrinsics.size(0) * (static_cast<int>(c_r1[b_i])))) +
                   ((cam_extrinsics.size(0) * cam_extrinsics.size(1)) * c_i)] =
                      (&d__1[0][0])[i1 + (4 * b_i)];
            }
          }
          //  inverted of cam_extrinsics
          r.set_size(4);
          c_r1.set_size(4);
          for (b_i = 0; b_i < 4; b_i++) {
            r[b_i] = static_cast<signed char>(b_i);
            c_r1[b_i] = static_cast<signed char>(b_i);
          }
          for (b_i = 0; b_i < 3; b_i++) {
            b_r1[b_i][0] = -rotationMatrix[b_i][0];
            b_r1[b_i][1] = -rotationMatrix[b_i][1];
            b_r1[b_i][2] = -rotationMatrix[b_i][2];
          }
          absxk = r1[0];
          b_t = r1[1];
          b_y = r1[2];
          for (b_i = 0; b_i < 3; b_i++) {
            d__1[b_i][0] = rotationMatrix[b_i][0];
            d__1[b_i][1] = rotationMatrix[b_i][1];
            d__1[b_i][2] = rotationMatrix[b_i][2];
            d__1[3][b_i] = ((b_r1[0][b_i] * absxk) + (b_r1[1][b_i] * b_t)) +
                           (b_r1[2][b_i] * b_y);
          }
          for (b_i = 0; b_i < 4; b_i++) {
            d__1[b_i][3] = static_cast<double>(iv[b_i]);
          }
          for (b_i = 0; b_i < 4; b_i++) {
            for (i1 = 0; i1 < 4; i1++) {
              camera_poses
                  [((static_cast<int>(r[i1])) +
                    (camera_poses.size(0) * (static_cast<int>(c_r1[b_i])))) +
                   ((camera_poses.size(0) * camera_poses.size(1)) * c_i)] =
                      (&d__1[0][0])[i1 + (4 * b_i)];
            }
          }
        }
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

//
// File trailer for ComputeCamExtrinsics.cpp
//
// [EOF]
//
