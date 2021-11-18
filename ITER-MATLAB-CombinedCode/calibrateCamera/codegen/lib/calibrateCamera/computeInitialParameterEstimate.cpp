//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "computeInitialParameterEstimate.h"
#include "calibrateCamera_types.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Solve for the camera intriniscs and extrinsics in closed form ignoring
//  distortion.
//
// Arguments    : const ::coder::array<real_T, 2U> &d_worldPoints
//                const ::coder::array<real_T, 3U> &b_imagePoints
//                struct1_T *iniltialParams
//                ::coder::array<boolean_T, 1U> &b_validIdx
//                coder::rtString *err
// Return Type  : void
//
namespace Codegen {
void computeInitialParameterEstimate(
    const ::coder::array<real_T, 2U> &d_worldPoints,
    const ::coder::array<real_T, 3U> &b_imagePoints, struct1_T *iniltialParams,
    ::coder::array<boolean_T, 1U> &b_validIdx, coder::rtString *err)
{
  static const char_T b_cv[29]{'n', 'o', 't', ' ', 'e', 'n', 'o', 'u', 'g', 'h',
                               ' ', 'v', 'a', 'l', 'i', 'd', ' ', 'H', 'o', 'm',
                               'o', 'g', 'r', 'a', 'p', 'h', 'i', 'e', 's'};
  coder::projective2d c_H;
  ::coder::array<real_T, 3U> H;
  ::coder::array<real_T, 3U> b_H;
  ::coder::array<real_T, 3U> b_rotationMatrices;
  ::coder::array<real_T, 2U> V;
  ::coder::array<real_T, 2U> a__1;
  ::coder::array<real_T, 2U> b_rotationVectors;
  ::coder::array<real_T, 2U> b_translationVectors;
  ::coder::array<real_T, 2U> c_imagePoints;
  ::coder::array<real_T, 2U> e_worldPoints;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<boolean_T, 1U> validPointsIdx;
  real_T U[6][6];
  real_T A[3][3];
  real_T b_R[3][3];
  real_T b_r1[3][3];
  real_T d_H[3][3];
  real_T e_H[6];
  real_T f_H[6];
  real_T s_data[6];
  real_T c_r1[3];
  real_T r2[3];
  real_T fy;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_i;
  int32_T e_i;
  int32_T end;
  int32_T loop_ub;
  boolean_T equal;
  //  Compute homographies for all images
  // --------------------------------------------------------------------------
  err->Value.size[0] = 1;
  err->Value.size[1] = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  b_validIdx.set_size(b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_validIdx[b_i] = true;
  }
  H.set_size(3, 3, b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (d_i = 0; d_i < 3; d_i++) {
      H[(3 * d_i) + (9 * b_i)] = 0.0;
      H[((3 * d_i) + (9 * b_i)) + 1] = 0.0;
      H[((3 * d_i) + (9 * b_i)) + 2] = 0.0;
    }
  }
  b_i = b_imagePoints.size(2);
  if (0 <= (b_i - 1)) {
    b_loop_ub = b_imagePoints.size(0) - 1;
    c_loop_ub = b_imagePoints.size(1) - 1;
  }
  for (e_i = 0; e_i < b_i; e_i++) {
    //  try
    //  Compute projective transformation from worldPoints to imagePoints
    // --------------------------------------------------------------------------
    validPointsIdx.set_size(b_imagePoints.size(0));
    for (d_i = 0; d_i <= b_loop_ub; d_i++) {
      validPointsIdx[d_i] = std::isnan(
          b_imagePoints[d_i + ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                               e_i)]);
    }
    loop_ub = validPointsIdx.size(0);
    for (d_i = 0; d_i < loop_ub; d_i++) {
      validPointsIdx[d_i] = !validPointsIdx[d_i];
    }
    end = validPointsIdx.size(0) - 1;
    loop_ub = 0;
    for (d_i = 0; d_i <= end; d_i++) {
      if (validPointsIdx[d_i]) {
        loop_ub++;
      }
    }
    r1.set_size(loop_ub);
    loop_ub = 0;
    for (d_i = 0; d_i <= end; d_i++) {
      if (validPointsIdx[d_i]) {
        r1[loop_ub] = d_i + 1;
        loop_ub++;
      }
    }
    loop_ub = r1.size(0);
    e_worldPoints.set_size(r1.size(0), 2);
    for (d_i = 0; d_i < 2; d_i++) {
      for (end = 0; end < loop_ub; end++) {
        e_worldPoints[end + (e_worldPoints.size(0) * d_i)] =
            d_worldPoints[(r1[end] + (d_worldPoints.size(0) * d_i)) - 1];
      }
    }
    c_imagePoints.set_size(r1.size(0), b_imagePoints.size(1));
    for (d_i = 0; d_i <= c_loop_ub; d_i++) {
      loop_ub = r1.size(0);
      for (end = 0; end < loop_ub; end++) {
        c_imagePoints[end + (c_imagePoints.size(0) * d_i)] =
            b_imagePoints[((r1[end] + (b_imagePoints.size(0) * d_i)) +
                           ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                            e_i)) -
                          1];
      }
    }
    coder::findProjectiveTransform(e_worldPoints, c_imagePoints, &c_H);
    for (d_i = 0; d_i < 3; d_i++) {
      H[(3 * d_i) + (9 * e_i)] = c_H.T[0][d_i];
      H[((3 * d_i) + (9 * e_i)) + 1] = c_H.T[1][d_i];
      H[((3 * d_i) + (9 * e_i)) + 2] = c_H.T[2][d_i];
    }
    fy = H[(9 * e_i) + 8];
    for (d_i = 0; d_i < 3; d_i++) {
      H[(3 * d_i) + (9 * e_i)] = H[(3 * d_i) + (9 * e_i)] / fy;
      H[((3 * d_i) + (9 * e_i)) + 1] = H[((3 * d_i) + (9 * e_i)) + 1] / fy;
      H[((3 * d_i) + (9 * e_i)) + 2] = H[((3 * d_i) + (9 * e_i)) + 2] / fy;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
  }
  // warning(w1);
  // warning(w2);
  end = b_imagePoints.size(2) - 1;
  loop_ub = 0;
  for (e_i = 0; e_i <= end; e_i++) {
    loop_ub++;
  }
  r.set_size(loop_ub);
  for (e_i = 0; e_i <= end; e_i++) {
    r[e_i] = e_i + 1;
  }
  b_H.set_size(3, 3, r.size(0));
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (d_i = 0; d_i < 3; d_i++) {
      b_H[(3 * d_i) + (9 * b_i)] = H[(3 * d_i) + (9 * (r[b_i] - 1))];
      b_H[((3 * d_i) + (9 * b_i)) + 1] =
          H[((3 * d_i) + (9 * (r[b_i] - 1))) + 1];
      b_H[((3 * d_i) + (9 * b_i)) + 2] =
          H[((3 * d_i) + (9 * (r[b_i] - 1))) + 2];
    }
  }
  H.set_size(3, 3, b_H.size(2));
  loop_ub = b_H.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (d_i = 0; d_i < 3; d_i++) {
      H[(3 * d_i) + (9 * b_i)] = b_H[(3 * d_i) + (9 * b_i)];
      H[((3 * d_i) + (9 * b_i)) + 1] = b_H[((3 * d_i) + (9 * b_i)) + 1];
      H[((3 * d_i) + (9 * b_i)) + 2] = b_H[((3 * d_i) + (9 * b_i)) + 2];
    }
  }
  if (H.size(2) < 2) {
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    err->Value.size[0] = 1;
    err->Value.size[1] = 29;
    for (b_i = 0; b_i < 29; b_i++) {
      err->Value.data[b_i] = b_cv[b_i];
    }
  }
  equal = false;
  if (err->Value.size[1] == 0) {
    equal = true;
  } else if (err->Value.size[1] == 0) {
    equal = true;
  } else {
    /* no actions */
  }
  if (equal) {
    real_T b_skew;
    real_T b_t;
    real_T cy;
    real_T fx;
    real_T lambda;
    real_T scale;
    // {
    // if isempty(initIntrinsics)
    //     if ~isempty(imageSize)
    //         % assume zero skew and centered principal point for initial guess
    //         cx = (imageSize(2)-1)/2;
    //         cy = (imageSize(1)-1)/2;
    //         [fx, fy] = computeFocalLength(H, cx, cy);
    //         A = [fx, 0, cx; ...
    //                 0, fy, cy; ...
    //                 0, 0, 1];
    //         if ~isreal(A)
    //             %error(message('vision:calibrate:complexCameraMatrix'));
    //
    //             err = "complex Camera Matrix";
    //             return;
    //         end
    //     else
    //         V = computeV(H);
    //         B = computeB(V);
    //         A = computeIntrinsics(B);
    //     end
    // else
    //     % initial guess for the intrinsics has been provided. No need to
    //     solve. A = initIntrinsics';
    // end
    //
    // [rvecs, tvecs] = computeExtrinsics(A, H);
    // radialCoeffs = zeros(1, cameraModel.NumRadialDistortionCoefficients);
    // if isempty(initRadial)
    //     radialCoeffs = zeros(1, cameraModel.NumRadialDistortionCoefficients);
    // else
    //     radialCoeffs = initRadial;
    // end
    // }
    //  Vb = 0
    // --------------------------------------------------------------------------
    loop_ub = 2 * H.size(2);
    V.set_size(loop_ub, 6);
    for (b_i = 0; b_i < 6; b_i++) {
      for (d_i = 0; d_i < loop_ub; d_i++) {
        V[d_i + (V.size(0) * b_i)] = 0.0;
      }
    }
    b_i = H.size(2);
    for (e_i = 0; e_i < b_i; e_i++) {
      for (d_i = 0; d_i < 3; d_i++) {
        d_H[d_i][0] = H[d_i + (9 * e_i)];
        d_H[d_i][1] = H[(d_i + (9 * e_i)) + 3];
        d_H[d_i][2] = H[(d_i + (9 * e_i)) + 6];
      }
      // --------------------------------------------------------------------------
      loop_ub = static_cast<int32_T>(static_cast<uint32_T>(
          (static_cast<uint32_T>(static_cast<int32_T>(e_i + 1))) << 1UL));
      V[loop_ub - 2] = d_H[0][0] * d_H[0][1];
      V[(loop_ub + V.size(0)) - 2] =
          (d_H[0][0] * d_H[1][1]) + (d_H[1][0] * d_H[0][1]);
      V[(loop_ub + (V.size(0) * 2)) - 2] = d_H[1][0] * d_H[1][1];
      V[(loop_ub + (V.size(0) * 3)) - 2] =
          (d_H[2][0] * d_H[0][1]) + (d_H[0][0] * d_H[2][1]);
      V[(loop_ub + (V.size(0) * 4)) - 2] =
          (d_H[2][0] * d_H[1][1]) + (d_H[1][0] * d_H[2][1]);
      V[(loop_ub + (V.size(0) * 5)) - 2] = d_H[2][0] * d_H[2][1];
      // --------------------------------------------------------------------------
      e_H[0] = d_H[0][0] * d_H[0][0];
      fy = d_H[0][0] * d_H[1][0];
      e_H[1] = fy + fy;
      e_H[2] = d_H[1][0] * d_H[1][0];
      fy = d_H[0][0] * d_H[2][0];
      e_H[3] = fy + fy;
      fy = d_H[1][0] * d_H[2][0];
      e_H[4] = fy + fy;
      e_H[5] = d_H[2][0] * d_H[2][0];
      f_H[0] = d_H[0][1] * d_H[0][1];
      fy = d_H[0][1] * d_H[1][1];
      f_H[1] = fy + fy;
      f_H[2] = d_H[1][1] * d_H[1][1];
      fy = d_H[0][1] * d_H[2][1];
      f_H[3] = fy + fy;
      fy = d_H[1][1] * d_H[2][1];
      f_H[4] = fy + fy;
      f_H[5] = d_H[2][1] * d_H[2][1];
      for (d_i = 0; d_i < 6; d_i++) {
        V[(loop_ub + (V.size(0) * d_i)) - 1] = e_H[d_i] - f_H[d_i];
      }
    }
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    // --------------------------------------------------------------------------
    equal = true;
    b_i = V.size(0);
    for (end = 0; end < 6; end++) {
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        fy = V[loop_ub + (V.size(0) * end)];
        if (equal) {
          if ((std::isinf(fy)) || (std::isnan(fy))) {
            equal = false;
          }
        } else {
          equal = false;
        }
      }
    }
    if (equal) {
      coder::internal::b_svd(V, a__1, s_data, &loop_ub, U);
    } else {
      for (b_i = 0; b_i < 6; b_i++) {
        for (d_i = 0; d_i < 6; d_i++) {
          U[b_i][d_i] = rtNaN;
        }
      }
    }
    //  b = [B11, B12, B22, B13, B23, B33]
    //  Compute the intrinsic matrix
    // --------------------------------------------------------------------------
    fy = (U[5][1] * U[5][3]) - (U[5][0] * U[5][4]);
    b_t = (U[5][0] * U[5][2]) - (U[5][1] * U[5][1]);
    cy = fy / b_t;
    lambda = U[5][5] - (((U[5][3] * U[5][3]) + (cy * fy)) / U[5][0]);
    fx = std::sqrt(lambda / U[5][0]);
    fy = std::sqrt((lambda * U[5][0]) / b_t);
    scale = fx * fx;
    b_skew = (((-U[5][1]) * scale) * fy) / lambda;
    A[0][0] = fx;
    A[1][0] = b_skew;
    A[2][0] = ((b_skew * cy) / fx) - ((U[5][3] * scale) / lambda);
    A[0][1] = 0.0;
    A[1][1] = fy;
    A[2][1] = cy;
    A[0][2] = 0.0;
    A[1][2] = 0.0;
    A[2][2] = 1.0;
    //  Compute translation and rotation vectors for all images
    // --------------------------------------------------------------------------
    b_rotationVectors.set_size(3, H.size(2));
    b_translationVectors.set_size(3, H.size(2));
    coder::inv(A, d_H);
    b_i = H.size(2);
    for (e_i = 0; e_i < b_i; e_i++) {
      fy = 0.0;
      scale = 3.3121686421112381E-170;
      for (end = 0; end < 3; end++) {
        b_skew = std::abs(
            ((d_H[0][end] * H[9 * e_i]) + (d_H[1][end] * H[(9 * e_i) + 1])) +
            (d_H[2][end] * H[(9 * e_i) + 2]));
        if (b_skew > scale) {
          b_t = scale / b_skew;
          fy = ((fy * b_t) * b_t) + 1.0;
          scale = b_skew;
        } else {
          b_t = b_skew / scale;
          fy += b_t * b_t;
        }
      }
      fy = scale * std::sqrt(fy);
      fy = 1.0 / fy;
      //  3D rotation matrix
      for (d_i = 0; d_i < 3; d_i++) {
        b_R[d_i][0] = fy * d_H[d_i][0];
        b_R[d_i][1] = fy * d_H[d_i][1];
        b_R[d_i][2] = fy * d_H[d_i][2];
      }
      for (d_i = 0; d_i < 3; d_i++) {
        fy = b_R[0][d_i];
        scale = b_R[1][d_i];
        b_skew = b_R[2][d_i];
        b_t = ((fy * H[9 * e_i]) + (scale * H[(9 * e_i) + 1])) +
              (b_skew * H[(9 * e_i) + 2]);
        fy = ((fy * H[(9 * e_i) + 3]) + (scale * H[(9 * e_i) + 4])) +
             (b_skew * H[(9 * e_i) + 5]);
        r2[d_i] = fy;
        c_r1[d_i] = b_t;
        b_r1[0][d_i] = b_t;
        b_r1[1][d_i] = fy;
      }
      b_r1[2][0] = (c_r1[1] * r2[2]) - (r2[1] * c_r1[2]);
      b_r1[2][1] = (r2[0] * c_r1[2]) - (c_r1[0] * r2[2]);
      b_r1[2][2] = (c_r1[0] * r2[1]) - (r2[0] * c_r1[1]);
      coder::vision::internal::calibration::rodriguesMatrixToVector(b_r1, c_r1);
      (*((real_T(*)[3])(&b_rotationVectors[3 * e_i])))[0] = c_r1[0];
      (*((real_T(*)[3])(&b_rotationVectors[3 * e_i])))[1] = c_r1[1];
      (*((real_T(*)[3])(&b_rotationVectors[3 * e_i])))[2] = c_r1[2];
      //  translation vector
      for (d_i = 0; d_i < 3; d_i++) {
        b_translationVectors[d_i + (3 * e_i)] =
            ((b_R[0][d_i] * H[(9 * e_i) + 6]) +
             (b_R[1][d_i] * H[(9 * e_i) + 7])) +
            (b_R[2][d_i] * H[(9 * e_i) + 8]);
      }
    }
    iniltialParams->RotationVectors.set_size(b_rotationVectors.size(1), 3);
    // {
    // iniltialParams = cameraParameters('IntrinsicMatrix', A', ...
    //     'RotationVectors', rvecs, ...
    //     'TranslationVectors', tvecs, 'WorldPoints', worldPoints, ...
    //     'WorldUnits', worldUnits, 'EstimateSkew',
    //     cameraModel.EstimateSkew,... 'NumRadialDistortionCoefficients',
    //     cameraModel.NumRadialDistortionCoefficients,...
    //     'EstimateTangentialDistortion',
    //     cameraModel.EstimateTangentialDistortion,... 'RadialDistortion',
    //     radialCoeffs, 'ImageSize', imageSize);
    // }
    loop_ub = b_rotationVectors.size(1);
    for (b_i = 0; b_i < 3; b_i++) {
      for (d_i = 0; d_i < loop_ub; d_i++) {
        iniltialParams
            ->RotationVectors[d_i + (iniltialParams->RotationVectors.size(0) *
                                     b_i)] = b_rotationVectors[b_i + (3 * d_i)];
      }
      iniltialParams->IntrinsicMatrix[b_i][0] = A[0][b_i];
      iniltialParams->IntrinsicMatrix[b_i][1] = A[1][b_i];
      iniltialParams->IntrinsicMatrix[b_i][2] = A[2][b_i];
    }
    b_rotationMatrices.set_size(3, 3, b_imagePoints.size(2));
    b_i = b_imagePoints.size(2);
    for (e_i = 0; e_i < b_i; e_i++) {
      scale = 3.3121686421112381E-170;
      b_skew = std::abs(iniltialParams->RotationVectors[e_i]);
      if (b_skew > 3.3121686421112381E-170) {
        lambda = 1.0;
        scale = b_skew;
      } else {
        b_t = b_skew / 3.3121686421112381E-170;
        lambda = b_t * b_t;
      }
      b_skew = std::abs(
          iniltialParams
              ->RotationVectors[e_i + iniltialParams->RotationVectors.size(0)]);
      if (b_skew > scale) {
        b_t = scale / b_skew;
        lambda = ((lambda * b_t) * b_t) + 1.0;
        scale = b_skew;
      } else {
        b_t = b_skew / scale;
        lambda += b_t * b_t;
      }
      b_skew = std::abs(
          iniltialParams
              ->RotationVectors[e_i +
                                (iniltialParams->RotationVectors.size(0) * 2)]);
      if (b_skew > scale) {
        b_t = scale / b_skew;
        lambda = ((lambda * b_t) * b_t) + 1.0;
        scale = b_skew;
      } else {
        b_t = b_skew / scale;
        lambda += b_t * b_t;
      }
      lambda = scale * std::sqrt(lambda);
      if (lambda < 1.0E-6) {
        for (d_i = 0; d_i < 3; d_i++) {
          b_R[d_i][0] = 0.0;
          b_R[d_i][1] = 0.0;
          b_R[d_i][2] = 0.0;
        }
        b_R[0][0] = 1.0;
        b_R[1][1] = 1.0;
        b_R[2][2] = 1.0;
      } else {
        scale = std::cos(lambda);
        fy = std::sin(lambda);
        for (d_i = 0; d_i < 3; d_i++) {
          b_skew = iniltialParams->RotationVectors
                       [e_i + (iniltialParams->RotationVectors.size(0) * d_i)] /
                   lambda;
          c_r1[d_i] = b_skew;
          r2[d_i] = b_skew;
          d_H[d_i][0] = 0.0;
          d_H[d_i][1] = 0.0;
          d_H[d_i][2] = 0.0;
        }
        b_R[0][0] = fy * 0.0;
        b_R[1][0] = fy * (-r2[2]);
        b_R[2][0] = fy * r2[1];
        b_R[0][1] = fy * r2[2];
        b_R[1][1] = fy * 0.0;
        b_R[2][1] = fy * (-r2[0]);
        b_R[0][2] = fy * (-r2[1]);
        b_R[1][2] = fy * r2[0];
        b_R[2][2] = fy * 0.0;
        for (end = 0; end < 3; end++) {
          d_H[end][end] = 1.0;
          b_r1[end][0] = c_r1[0] * c_r1[end];
          b_r1[end][1] = c_r1[1] * c_r1[end];
          b_r1[end][2] = c_r1[2] * c_r1[end];
        }
        for (d_i = 0; d_i < 3; d_i++) {
          b_R[d_i][0] = ((d_H[d_i][0] * scale) + b_R[d_i][0]) +
                        ((1.0 - scale) * b_r1[d_i][0]);
          b_R[d_i][1] = ((d_H[d_i][1] * scale) + b_R[d_i][1]) +
                        ((1.0 - scale) * b_r1[d_i][1]);
          b_R[d_i][2] = ((d_H[d_i][2] * scale) + b_R[d_i][2]) +
                        ((1.0 - scale) * b_r1[d_i][2]);
        }
      }
      for (d_i = 0; d_i < 3; d_i++) {
        b_rotationMatrices[(3 * d_i) + (9 * e_i)] = b_R[0][d_i];
        b_rotationMatrices[((3 * d_i) + (9 * e_i)) + 1] = b_R[1][d_i];
        b_rotationMatrices[((3 * d_i) + (9 * e_i)) + 2] = b_R[2][d_i];
      }
    }
    iniltialParams->RadialDistortion[0] = 0.0;
    iniltialParams->RadialDistortion[1] = 0.0;
    iniltialParams->RadialDistortion[2] = 0.0;
    iniltialParams->WorldPoints.set_size(d_worldPoints.size(0), 2);
    iniltialParams->WorldUnits.size[0] = 1;
    iniltialParams->WorldUnits.size[1] = 2;
    loop_ub = d_worldPoints.size(0);
    for (b_i = 0; b_i < 2; b_i++) {
      iniltialParams->TangentialDistortion[b_i] = 0.0;
      for (d_i = 0; d_i < loop_ub; d_i++) {
        iniltialParams
            ->WorldPoints[d_i + (iniltialParams->WorldPoints.size(0) * b_i)] =
            d_worldPoints[d_i + (d_worldPoints.size(0) * b_i)];
      }
      iniltialParams->WorldUnits.data[b_i] = 'm';
    }
    iniltialParams->EstimateSkew = false;
    iniltialParams->NumRadialDistortionCoefficients = 3.0;
    iniltialParams->EstimateTangentialDistortion = false;
    iniltialParams->TranslationVectors.set_size(b_translationVectors.size(1),
                                                3);
    loop_ub = b_translationVectors.size(1);
    for (b_i = 0; b_i < 3; b_i++) {
      for (d_i = 0; d_i < loop_ub; d_i++) {
        iniltialParams->TranslationVectors
            [d_i + (iniltialParams->TranslationVectors.size(0) * b_i)] =
            b_translationVectors[b_i + (3 * d_i)];
      }
    }
    iniltialParams->NumPatterns.size[0] = 1;
    iniltialParams->NumPatterns.size[1] = 1;
    iniltialParams->NumPatterns.data[0] =
        static_cast<real_T>(b_imagePoints.size(2));
    iniltialParams->FocalLength[0] = iniltialParams->IntrinsicMatrix[0][0];
    iniltialParams->FocalLength[1] = iniltialParams->IntrinsicMatrix[1][1];
    iniltialParams->PrincipalPoint[0] = iniltialParams->IntrinsicMatrix[0][2];
    iniltialParams->PrincipalPoint[1] = iniltialParams->IntrinsicMatrix[1][2];
    iniltialParams->Skew = iniltialParams->IntrinsicMatrix[0][1];
    iniltialParams->RotationMatrices.set_size(3, 3, b_rotationMatrices.size(2));
    loop_ub = b_rotationMatrices.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      for (d_i = 0; d_i < 3; d_i++) {
        iniltialParams
            ->RotationMatrices[(iniltialParams->RotationMatrices.size(0) *
                                d_i) +
                               ((iniltialParams->RotationMatrices.size(0) *
                                 iniltialParams->RotationMatrices.size(1)) *
                                b_i)] =
            b_rotationMatrices[(3 * d_i) + (9 * b_i)];
        iniltialParams
            ->RotationMatrices[((iniltialParams->RotationMatrices.size(0) *
                                 d_i) +
                                ((iniltialParams->RotationMatrices.size(0) *
                                  iniltialParams->RotationMatrices.size(1)) *
                                 b_i)) +
                               1] =
            b_rotationMatrices[((3 * d_i) + (9 * b_i)) + 1];
        iniltialParams
            ->RotationMatrices[((iniltialParams->RotationMatrices.size(0) *
                                 d_i) +
                                ((iniltialParams->RotationMatrices.size(0) *
                                  iniltialParams->RotationMatrices.size(1)) *
                                 b_i)) +
                               2] =
            b_rotationMatrices[((3 * d_i) + (9 * b_i)) + 2];
      }
    }
    iniltialParams->MeanReprojectionError = rtNaN;
    //     %{
    // iniltialParams.RadialDistortion = radialCoeffs;
    //     iniltialParams.TangentialDistortion = [0, 0];
    //     iniltialParams.ImageSize = [];
    //     iniltialParams.WorldPoints = worldPoints;
    //     iniltialParams.WorldUnits = worldUnits;
    //     iniltialParams.EstimateSkew = cameraModel.EstimateSkew;
    //     iniltialParams.NumRadialDistortionCoefficients =
    //     cameraModel.NumRadialDistortionCoefficients;
    //     iniltialParams.EstimateTangentialDistortion =
    //     cameraModel.EstimateTangentialDistortion;
    //     iniltialParams.RotationVectors = rvecs;
    //     iniltialParams.TranslationVectors = tvecs;
    //     iniltialParams.ReprojectionErrors = [];
    //     iniltialParams.IntrinsicMatrix = A';
    //     iniltialParams.DetectedKeypoints = [];
    //     iniltialParams.NumPatterns = size(imagePoints, 3);
    //     iniltialParams.FocalLength = [A(1, 1) A(2, 2)];
    //     iniltialParams.PrincipalPoint = [A(1, 3) A(2, 3)];
    //     iniltialParams.Skew = A(1, 2);
    //     iniltialParams.RotationMatrices = rotationMatrices;
    //     iniltialParams.MeanReprojectionError = NaN;
    //     iniltialParams.ReprojectedPoints = [];
    // }
  } else {
    iniltialParams->RadialDistortion[0] = 0.0;
    iniltialParams->RadialDistortion[1] = 0.0;
    iniltialParams->RadialDistortion[2] = 0.0;
    iniltialParams->WorldPoints.set_size(d_worldPoints.size(0), 2);
    loop_ub = d_worldPoints.size(0);
    for (b_i = 0; b_i < 2; b_i++) {
      iniltialParams->TangentialDistortion[b_i] = 0.0;
      for (d_i = 0; d_i < loop_ub; d_i++) {
        iniltialParams
            ->WorldPoints[d_i + (iniltialParams->WorldPoints.size(0) * b_i)] =
            d_worldPoints[d_i + (d_worldPoints.size(0) * b_i)];
      }
    }
    iniltialParams->WorldUnits.size[0] = 1;
    iniltialParams->WorldUnits.size[1] = 0;
    iniltialParams->EstimateSkew = false;
    iniltialParams->NumRadialDistortionCoefficients = 3.0;
    iniltialParams->EstimateTangentialDistortion = false;
    iniltialParams->RotationVectors.set_size(1, 3);
    iniltialParams->TranslationVectors.set_size(1, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      iniltialParams
          ->RotationVectors[iniltialParams->RotationVectors.size(0) * b_i] =
          0.0;
      iniltialParams
          ->TranslationVectors[iniltialParams->TranslationVectors.size(0) *
                               b_i] = 0.0;
      iniltialParams->IntrinsicMatrix[b_i][0] = 0.0;
      iniltialParams->IntrinsicMatrix[b_i][1] = 0.0;
      iniltialParams->IntrinsicMatrix[b_i][2] = 0.0;
    }
    iniltialParams->NumPatterns.size[0] = 0;
    iniltialParams->NumPatterns.size[1] = 0;
    iniltialParams->FocalLength[0] = 0.0;
    iniltialParams->PrincipalPoint[0] = 0.0;
    iniltialParams->FocalLength[1] = 0.0;
    iniltialParams->PrincipalPoint[1] = 0.0;
    iniltialParams->Skew = 0.0;
    iniltialParams->RotationMatrices.set_size(0, 0, 1);
    iniltialParams->MeanReprojectionError = rtNaN;
  }
}

} // namespace Codegen

//
// File trailer for computeInitialParameterEstimate.cpp
//
// [EOF]
//
