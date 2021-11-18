//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "computeInitialParameterEstimate.h"
#include "calibrateOneCamera_data.h"
#include "calibrateOneCamera_types.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Solve for the camera intriniscs and extrinsics in closed form ignoring
//  distortion.
//
// Arguments    : const ::coder::array<double, 2U> &c_worldPoints
//                const ::coder::array<double, 3U> &b_imagePoints
//                const double b_imageSize[2]
//                struct1_T *initialParams
//                ::coder::array<bool, 1U> &c_validIdx
//                int *err
// Return Type  : void
//
namespace Codegen {
void computeInitialParameterEstimate(
    const ::coder::array<double, 2U> &c_worldPoints,
    const ::coder::array<double, 3U> &b_imagePoints,
    const double b_imageSize[2], struct1_T *initialParams,
    ::coder::array<bool, 1U> &c_validIdx, int *err)
{
  coder::b_cameraParameters lobj_1;
  coder::projective2d c_H;
  ::coder::array<double, 3U> H;
  ::coder::array<double, 3U> b_H;
  ::coder::array<double, 2U> V;
  ::coder::array<double, 2U> b_rotationVectors;
  ::coder::array<double, 2U> b_translationVectors;
  ::coder::array<double, 2U> c_imagePoints;
  ::coder::array<double, 2U> d_imagePoints;
  ::coder::array<double, 2U> d_worldPoints;
  ::coder::array<double, 1U> s1;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<bool, 1U> validPointsIdx;
  double V1[6][6];
  double A[3][3];
  double b_r1[3][3];
  double d_H[3][3];
  double r1_tmp[3][3];
  double e_H[6];
  double f_H[6];
  double c_r1[3];
  double r2[3];
  double fy;
  int b_i;
  int b_loop_ub;
  int c_i;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int loop_ub;
  int trueCount;
  char t3_WorldUnits[2];
  bool t3_EstimateSkew;
  bool t3_EstimateTangentialDistortion;
  //  Compute homographies for all images
  // --------------------------------------------------------------------------
  *err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  c_validIdx.set_size(b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_validIdx[b_i] = true;
  }
  H.set_size(3, 3, b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (end = 0; end < 3; end++) {
      H[(3 * end) + (9 * b_i)] = 0.0;
      H[((3 * end) + (9 * b_i)) + 1] = 0.0;
      H[((3 * end) + (9 * b_i)) + 2] = 0.0;
    }
  }
  b_i = b_imagePoints.size(2);
  if (0 <= (b_i - 1)) {
    b_loop_ub = b_imagePoints.size(0);
    c_loop_ub = b_imagePoints.size(1);
    d_loop_ub = b_imagePoints.size(0) - 1;
    e_loop_ub = b_imagePoints.size(1) - 1;
  }
  for (c_i = 0; c_i < b_i; c_i++) {
    int d_i;
    //  try
    c_imagePoints.set_size(b_imagePoints.size(0), b_imagePoints.size(1));
    for (end = 0; end < c_loop_ub; end++) {
      for (trueCount = 0; trueCount < b_loop_ub; trueCount++) {
        c_imagePoints[trueCount + (c_imagePoints.size(0) * end)] =
            b_imagePoints[(trueCount + (b_imagePoints.size(0) * end)) +
                          ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                           c_i)];
      }
    }
    //  Compute projective transformation from worldPoints to imagePoints
    // --------------------------------------------------------------------------
    validPointsIdx.set_size(b_imagePoints.size(0));
    for (end = 0; end <= d_loop_ub; end++) {
      validPointsIdx[end] = std::isnan(c_imagePoints[end]);
    }
    loop_ub = validPointsIdx.size(0);
    for (end = 0; end < loop_ub; end++) {
      validPointsIdx[end] = !validPointsIdx[end];
    }
    end = validPointsIdx.size(0) - 1;
    trueCount = 0;
    for (d_i = 0; d_i <= end; d_i++) {
      if (validPointsIdx[d_i]) {
        trueCount++;
      }
    }
    r1.set_size(trueCount);
    loop_ub = 0;
    for (d_i = 0; d_i <= end; d_i++) {
      if (validPointsIdx[d_i]) {
        r1[loop_ub] = d_i + 1;
        loop_ub++;
      }
    }
    loop_ub = r1.size(0);
    d_worldPoints.set_size(r1.size(0), 2);
    for (end = 0; end < 2; end++) {
      for (trueCount = 0; trueCount < loop_ub; trueCount++) {
        d_worldPoints[trueCount + (d_worldPoints.size(0) * end)] =
            c_worldPoints[(r1[trueCount] + (c_worldPoints.size(0) * end)) - 1];
      }
    }
    d_imagePoints.set_size(r1.size(0), b_imagePoints.size(1));
    for (end = 0; end <= e_loop_ub; end++) {
      loop_ub = r1.size(0);
      for (trueCount = 0; trueCount < loop_ub; trueCount++) {
        d_imagePoints[trueCount + (d_imagePoints.size(0) * end)] =
            c_imagePoints[(r1[trueCount] + (c_imagePoints.size(0) * end)) - 1];
      }
    }
    coder::findProjectiveTransform(d_worldPoints, d_imagePoints, &c_H);
    for (end = 0; end < 3; end++) {
      H[(3 * end) + (9 * c_i)] = c_H.T[0][end];
      H[((3 * end) + (9 * c_i)) + 1] = c_H.T[1][end];
      H[((3 * end) + (9 * c_i)) + 2] = c_H.T[2][end];
    }
    fy = H[(9 * c_i) + 8];
    for (end = 0; end < 3; end++) {
      H[(3 * end) + (9 * c_i)] = H[(3 * end) + (9 * c_i)] / fy;
      H[((3 * end) + (9 * c_i)) + 1] = H[((3 * end) + (9 * c_i)) + 1] / fy;
      H[((3 * end) + (9 * c_i)) + 2] = H[((3 * end) + (9 * c_i)) + 2] / fy;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
  }
  // warning(w1);
  // warning(w2);
  end = b_imagePoints.size(2) - 1;
  trueCount = 0;
  for (c_i = 0; c_i <= end; c_i++) {
    trueCount++;
  }
  r.set_size(trueCount);
  for (c_i = 0; c_i <= end; c_i++) {
    r[c_i] = c_i + 1;
  }
  b_H.set_size(3, 3, r.size(0));
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (end = 0; end < 3; end++) {
      b_H[(3 * end) + (9 * b_i)] = H[(3 * end) + (9 * (r[b_i] - 1))];
      b_H[((3 * end) + (9 * b_i)) + 1] =
          H[((3 * end) + (9 * (r[b_i] - 1))) + 1];
      b_H[((3 * end) + (9 * b_i)) + 2] =
          H[((3 * end) + (9 * (r[b_i] - 1))) + 2];
    }
  }
  H.set_size(3, 3, b_H.size(2));
  loop_ub = b_H.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (end = 0; end < 3; end++) {
      H[(3 * end) + (9 * b_i)] = b_H[(3 * end) + (9 * b_i)];
      H[((3 * end) + (9 * b_i)) + 1] = b_H[((3 * end) + (9 * b_i)) + 1];
      H[((3 * end) + (9 * b_i)) + 2] = b_H[((3 * end) + (9 * b_i)) + 2];
    }
  }
  if (H.size(2) < 2) {
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    *err = -201;
  }
  if ((*err) == 0) {
    double cy;
    double fx;
    double lambda;
    double scale;
    double skew;
    //  Vb = 0
    // --------------------------------------------------------------------------
    loop_ub = 2 * H.size(2);
    V.set_size(loop_ub, 6);
    for (b_i = 0; b_i < 6; b_i++) {
      for (end = 0; end < loop_ub; end++) {
        V[end + (V.size(0) * b_i)] = 0.0;
      }
    }
    b_i = H.size(2);
    for (c_i = 0; c_i < b_i; c_i++) {
      for (end = 0; end < 3; end++) {
        d_H[end][0] = H[end + (9 * c_i)];
        d_H[end][1] = H[(end + (9 * c_i)) + 3];
        d_H[end][2] = H[(end + (9 * c_i)) + 6];
      }
      // --------------------------------------------------------------------------
      loop_ub = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(static_cast<int>(c_i + 1))) << 1UL));
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
      for (end = 0; end < 6; end++) {
        V[(loop_ub + (V.size(0) * end)) - 1] = e_H[end] - f_H[end];
      }
    }
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    // --------------------------------------------------------------------------
    t3_EstimateSkew = true;
    b_i = V.size(0);
    for (trueCount = 0; trueCount < 6; trueCount++) {
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        fy = V[loop_ub + (V.size(0) * trueCount)];
        if (t3_EstimateSkew) {
          if ((std::isinf(fy)) || (std::isnan(fy))) {
            t3_EstimateSkew = false;
          }
        } else {
          t3_EstimateSkew = false;
        }
      }
    }
    if (t3_EstimateSkew) {
      coder::internal::b_svd(V, c_imagePoints, s1, V1);
    } else {
      unsigned int unnamed_idx_0;
      unnamed_idx_0 = static_cast<unsigned int>(V.size(0));
      V.set_size(static_cast<int>(unnamed_idx_0), 6);
      loop_ub = static_cast<int>(unnamed_idx_0);
      for (b_i = 0; b_i < 6; b_i++) {
        for (end = 0; end < loop_ub; end++) {
          V[end + (V.size(0) * b_i)] = 0.0;
        }
      }
      coder::internal::b_svd(V, c_imagePoints, s1, V1);
      for (b_i = 0; b_i < 6; b_i++) {
        for (end = 0; end < 6; end++) {
          V1[b_i][end] = rtNaN;
        }
      }
    }
    //  b = [B11, B12, B22, B13, B23, B33]
    //  Compute the intrinsic matrix
    // --------------------------------------------------------------------------
    fy = (V1[5][1] * V1[5][3]) - (V1[5][0] * V1[5][4]);
    scale = (V1[5][0] * V1[5][2]) - (V1[5][1] * V1[5][1]);
    cy = fy / scale;
    lambda = V1[5][5] - (((V1[5][3] * V1[5][3]) + (cy * fy)) / V1[5][0]);
    fx = std::sqrt(lambda / V1[5][0]);
    fy = std::sqrt((lambda * V1[5][0]) / scale);
    scale = fx * fx;
    skew = (((-V1[5][1]) * scale) * fy) / lambda;
    A[0][0] = fx;
    A[1][0] = skew;
    A[2][0] = ((skew * cy) / fx) - ((V1[5][3] * scale) / lambda);
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
    for (c_i = 0; c_i < b_i; c_i++) {
      fy = 0.0;
      scale = 3.3121686421112381E-170;
      for (trueCount = 0; trueCount < 3; trueCount++) {
        skew = std::abs(((d_H[0][trueCount] * H[9 * c_i]) +
                         (d_H[1][trueCount] * H[(9 * c_i) + 1])) +
                        (d_H[2][trueCount] * H[(9 * c_i) + 2]));
        if (skew > scale) {
          lambda = scale / skew;
          fy = ((fy * lambda) * lambda) + 1.0;
          scale = skew;
        } else {
          lambda = skew / scale;
          fy += lambda * lambda;
        }
      }
      fy = scale * std::sqrt(fy);
      fy = 1.0 / fy;
      //  3D rotation matrix
      for (end = 0; end < 3; end++) {
        r1_tmp[end][0] = fy * d_H[end][0];
        r1_tmp[end][1] = fy * d_H[end][1];
        r1_tmp[end][2] = fy * d_H[end][2];
      }
      for (end = 0; end < 3; end++) {
        fy = r1_tmp[0][end];
        scale = r1_tmp[1][end];
        skew = r1_tmp[2][end];
        lambda = ((fy * H[9 * c_i]) + (scale * H[(9 * c_i) + 1])) +
                 (skew * H[(9 * c_i) + 2]);
        fy = ((fy * H[(9 * c_i) + 3]) + (scale * H[(9 * c_i) + 4])) +
             (skew * H[(9 * c_i) + 5]);
        r2[end] = fy;
        c_r1[end] = lambda;
        b_r1[0][end] = lambda;
        b_r1[1][end] = fy;
      }
      b_r1[2][0] = (c_r1[1] * r2[2]) - (r2[1] * c_r1[2]);
      b_r1[2][1] = (r2[0] * c_r1[2]) - (c_r1[0] * r2[2]);
      b_r1[2][2] = (c_r1[0] * r2[1]) - (r2[0] * c_r1[1]);
      coder::vision::internal::calibration::rodriguesMatrixToVector(b_r1, c_r1);
      (*((double(*)[3])(&b_rotationVectors[3 * c_i])))[0] = c_r1[0];
      (*((double(*)[3])(&b_rotationVectors[3 * c_i])))[1] = c_r1[1];
      (*((double(*)[3])(&b_rotationVectors[3 * c_i])))[2] = c_r1[2];
      //  translation vector
      for (end = 0; end < 3; end++) {
        b_translationVectors[end + (3 * c_i)] =
            ((r1_tmp[0][end] * H[(9 * c_i) + 6]) +
             (r1_tmp[1][end] * H[(9 * c_i) + 7])) +
            (r1_tmp[2][end] * H[(9 * c_i) + 8]);
      }
    }
    // iniltialParams =
    // my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints,
    // 3));
    initialParams->RadialDistortion[0] = 0.0;
    initialParams->RadialDistortion[1] = 0.0;
    initialParams->RadialDistortion[2] = 0.0;
    initialParams->WorldPoints.set_size(c_worldPoints.size(0), 2);
    loop_ub = c_worldPoints.size(0);
    for (b_i = 0; b_i < 2; b_i++) {
      initialParams->TangentialDistortion[b_i] = 0.0;
      initialParams->ImageSize[b_i] = b_imageSize[b_i];
      for (end = 0; end < loop_ub; end++) {
        initialParams
            ->WorldPoints[end + (initialParams->WorldPoints.size(0) * b_i)] =
            c_worldPoints[end + (c_worldPoints.size(0) * b_i)];
      }
    }
    initialParams->WorldUnits.set_size(1, 1);
    initialParams->WorldUnits[0] = 'm';
    initialParams->EstimateSkew = false;
    initialParams->NumRadialDistortionCoefficients = 3.0;
    initialParams->EstimateTangentialDistortion = false;
    initialParams->RotationVectors.set_size(b_rotationVectors.size(1), 3);
    initialParams->TranslationVectors.set_size(b_translationVectors.size(1), 3);
    loop_ub = b_rotationVectors.size(1);
    b_loop_ub = b_translationVectors.size(1);
    for (b_i = 0; b_i < 3; b_i++) {
      for (end = 0; end < loop_ub; end++) {
        initialParams
            ->RotationVectors[end + (initialParams->RotationVectors.size(0) *
                                     b_i)] = b_rotationVectors[b_i + (3 * end)];
      }
      for (end = 0; end < b_loop_ub; end++) {
        initialParams->TranslationVectors
            [end + (initialParams->TranslationVectors.size(0) * b_i)] =
            b_translationVectors[b_i + (3 * end)];
      }
      initialParams->IntrinsicMatrix[b_i][0] = A[0][b_i];
      initialParams->IntrinsicMatrix[b_i][1] = A[1][b_i];
      initialParams->IntrinsicMatrix[b_i][2] = A[2][b_i];
    }
  } else {
    // iniltialParams = my_CameraParameters(zeros(1,3),worldPoints,'',
    // cameraModel,zeros(1,3),zeros(1,3),zeros(3,3),[]);
    for (b_i = 0; b_i < 3; b_i++) {
      lobj_1.IntrinsicMatrixInternal[b_i][0] = static_cast<double>(iv[b_i][0]);
      lobj_1.IntrinsicMatrixInternal[b_i][1] = static_cast<double>(iv[b_i][1]);
      lobj_1.IntrinsicMatrixInternal[b_i][2] = static_cast<double>(iv[b_i][2]);
      lobj_1.RadialDistortion[b_i] = 0.0;
    }
    lobj_1.TangentialDistortion[0] = 0.0;
    lobj_1.TangentialDistortion[1] = 0.0;
    lobj_1.ImageSize[0] = b_imageSize[0];
    lobj_1.ImageSize[1] = b_imageSize[1];
    lobj_1.WorldUnits[0] = 'm';
    lobj_1.WorldUnits[1] = 'm';
    lobj_1.EstimateSkew = false;
    lobj_1.NumRadialDistortionCoefficients = 2.0;
    lobj_1.EstimateTangentialDistortion = false;
    lobj_1.toStruct(
        initialParams->RadialDistortion, initialParams->TangentialDistortion,
        initialParams->ImageSize, t3_WorldUnits, &t3_EstimateSkew, &fy,
        &t3_EstimateTangentialDistortion, initialParams->IntrinsicMatrix);
    initialParams->WorldPoints.set_size(0, 2);
    initialParams->WorldUnits.set_size(1, 2);
    initialParams->WorldUnits[0] = t3_WorldUnits[0];
    initialParams->WorldUnits[1] = t3_WorldUnits[1];
    initialParams->EstimateSkew = t3_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients = fy;
    initialParams->EstimateTangentialDistortion =
        t3_EstimateTangentialDistortion;
    initialParams->RotationVectors.set_size(0, 3);
    initialParams->TranslationVectors.set_size(0, 3);
  }
}

} // namespace Codegen

//
// File trailer for computeInitialParameterEstimate.cpp
//
// [EOF]
//
