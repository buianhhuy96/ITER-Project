//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "computeErrors.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_rtwutil.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "rotm2axang.h"
#include "rt_nonfinite.h"
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
//                const double K[4][3]
//                double errors[3]
// Return Type  : void
//
void computeErrors(const coder::array<double, 3U> &Hhand2base,
                   const double Hhand2eye[4][4], const double Hbase2grid[4][4],
                   const coder::array<double, 3U> &Hcam2grid,
                   const coder::array<double, 3U> &imgPts,
                   const coder::array<double, 2U> &Worldpts,
                   const double K[4][3], double errors[3])
{
  coder::array<double, 3U> PoseErrR;
  coder::array<double, 2U> PoseErrt;
  coder::array<double, 2U> a;
  coder::array<double, 2U> b_x;
  coder::array<double, 2U> b_z1;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> d_y;
  coder::array<double, 2U> err;
  coder::array<double, 2U> r;
  coder::array<double, 2U> z1;
  coder::array<double, 1U> angR;
  coder::array<double, 1U> x;
  coder::array<double, 1U> y;
  double HT[4][4];
  double b_y[4][4];
  double e_y[4][4];
  double b_Hhand2eye[3][3];
  double dv[3][3];
  double AxAngVec[4];
  double d;
  double s;
  double smax;
  int N;
  int i;
  int i1;
  int i2;
  int j;
  int jp1j;
  int k;
  int sizes_idx_1;
  signed char ipiv[4];
  signed char p[4];
  signed char b_input_sizes_idx_1;
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
    N = Worldpts.size(0);
  } else {
    N = 0;
  }
  empty_non_axis_sizes = (N == 0);
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
    sizes_idx_1 = 1;
  } else if (Worldpts.size(0) != 0) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  r.set_size(N, ((static_cast<int>(input_sizes_idx_1)) +
                 (static_cast<int>(b_input_sizes_idx_1))) +
                    sizes_idx_1);
  jp1j = static_cast<int>(input_sizes_idx_1);
  for (i = 0; i < jp1j; i++) {
    for (i1 = 0; i1 < N; i1++) {
      r[i1 + (r.size(0) * i)] = Worldpts[i1 + (N * i)];
    }
  }
  jp1j = static_cast<int>(b_input_sizes_idx_1);
  for (i = 0; i < jp1j; i++) {
    for (i1 = 0; i1 < N; i1++) {
      r[i1 + (r.size(0) * (static_cast<int>(input_sizes_idx_1)))] = 0.0;
    }
  }
  for (i = 0; i < sizes_idx_1; i++) {
    for (i1 = 0; i1 < N; i1++) {
      r[i1 + (r.size(0) * ((static_cast<int>(input_sizes_idx_1)) +
                           (static_cast<int>(b_input_sizes_idx_1))))] = 1.0;
    }
  }
  //  Computing Errors
  //     %% Computing Rotation errors distribution
  angR.set_size(imgPts.size(2));
  jp1j = imgPts.size(2);
  for (i = 0; i < jp1j; i++) {
    angR[i] = 0.0;
  }
  PoseErrR.set_size(3, 3, imgPts.size(2));
  jp1j = imgPts.size(2);
  for (i = 0; i < jp1j; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      PoseErrR[(3 * i1) + (9 * i)] = 0.0;
      PoseErrR[((3 * i1) + (9 * i)) + 1] = 0.0;
      PoseErrR[((3 * i1) + (9 * i)) + 2] = 0.0;
    }
  }
  // %%%%%%% length(Hcam2grid) -> number of images
  i = imgPts.size(2);
  for (j = 0; j < i; j++) {
    for (i1 = 0; i1 < 3; i1++) {
      smax = Hhand2eye[0][i1];
      s = Hhand2eye[1][i1];
      d = Hhand2eye[2][i1];
      for (i2 = 0; i2 < 3; i2++) {
        b_Hhand2eye[i2][i1] = ((smax * Hcam2grid[(4 * i2) + (16 * j)]) +
                               (s * Hcam2grid[((4 * i2) + (16 * j)) + 1])) +
                              (d * Hcam2grid[((4 * i2) + (16 * j)) + 2]);
      }
    }
    coder::inv(b_Hhand2eye, dv);
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        b_Hhand2eye[i2][i1] =
            ((Hhand2base[i1 + (16 * j)] * Hbase2grid[i2][0]) +
             (Hhand2base[(i1 + (16 * j)) + 4] * Hbase2grid[i2][1])) +
            (Hhand2base[(i1 + (16 * j)) + 8] * Hbase2grid[i2][2]);
      }
    }
    for (i1 = 0; i1 < 3; i1++) {
      smax = dv[0][i1];
      s = dv[1][i1];
      d = dv[2][i1];
      for (i2 = 0; i2 < 3; i2++) {
        PoseErrR[(i1 + (3 * i2)) + (9 * j)] =
            ((smax * b_Hhand2eye[i2][0]) + (s * b_Hhand2eye[i2][1])) +
            (d * b_Hhand2eye[i2][2]);
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    coder::rotm2axang(*((double(*)[3][3])(&PoseErrR[9 * j])), AxAngVec);
    angR[j] = AxAngVec[3] * 57.295779513082323;
  }
  y.set_size(angR.size(0));
  N = angR.size(0);
  for (k = 0; k < N; k++) {
    y[k] = rt_powd_snf(angR[k], 2.0);
  }
  if (y.size(0) == 0) {
    angR.set_size(0);
  } else {
    angR.set_size(y.size(0));
    i = y.size(0);
    for (k = 0; k < i; k++) {
      angR[k] = y[k];
    }
  }
  i = angR.size(0);
  for (k = 0; k < i; k++) {
    angR[k] = std::sqrt(angR[k]);
  }
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(imgPts.size(2), 3);
  i = imgPts.size(2);
  for (j = 0; j < i; j++) {
    smax = Hbase2grid[3][0];
    s = Hbase2grid[3][1];
    d = Hbase2grid[3][2];
    for (i1 = 0; i1 < 3; i1++) {
      PoseErrt[j + (PoseErrt.size(0) * i1)] =
          ((((Hhand2base[i1 + (16 * j)] * smax) +
             (Hhand2base[(i1 + (16 * j)) + 4] * s)) +
            (Hhand2base[(i1 + (16 * j)) + 8] * d)) +
           Hhand2base[(i1 + (16 * j)) + 12]) -
          ((((Hhand2eye[0][i1] * Hcam2grid[(16 * j) + 12]) +
             (Hhand2eye[1][i1] * Hcam2grid[(16 * j) + 13])) +
            (Hhand2eye[2][i1] * Hcam2grid[(16 * j) + 14])) +
           Hhand2eye[3][i1]);
    }
    // (Ra*tx)+ta -(Rz*tb)+tz
  }
  z1.set_size(PoseErrt.size(0), 3);
  for (k = 0; k < 3; k++) {
    N = z1.size(0);
    for (sizes_idx_1 = 0; sizes_idx_1 < N; sizes_idx_1++) {
      z1[sizes_idx_1 + (z1.size(0) * k)] =
          rt_powd_snf(PoseErrt[sizes_idx_1 + (PoseErrt.size(0) * k)], 2.0);
    }
  }
  if (z1.size(0) == 0) {
    x.set_size(0);
  } else {
    x.set_size(z1.size(0));
    i = z1.size(0);
    for (k = 0; k < i; k++) {
      x[k] = z1[k];
    }
    i = z1.size(0);
    for (k = 0; k < 2; k++) {
      for (sizes_idx_1 = 0; sizes_idx_1 < i; sizes_idx_1++) {
        x[sizes_idx_1] =
            x[sizes_idx_1] + z1[sizes_idx_1 + (z1.size(0) * (k + 1))];
      }
    }
  }
  i = x.size(0);
  for (k = 0; k < i; k++) {
    x[k] = std::sqrt(x[k]);
  }
  //     %% Computing Reprojection errors
  err.set_size(imgPts.size(0), imgPts.size(2));
  jp1j = imgPts.size(2);
  for (i = 0; i < jp1j; i++) {
    N = imgPts.size(0);
    for (i1 = 0; i1 < N; i1++) {
      err[i1 + (err.size(0) * i)] = 0.0;
    }
  }
  i = imgPts.size(2);
  for (j = 0; j < i; j++) {
    int b_i;
    int b_j;
    for (i1 = 0; i1 < 4; i1++) {
      b_y[i1][0] = 0.0;
      HT[i1][0] = Hhand2eye[i1][0];
      b_y[i1][1] = 0.0;
      HT[i1][1] = Hhand2eye[i1][1];
      b_y[i1][2] = 0.0;
      HT[i1][2] = Hhand2eye[i1][2];
      b_y[i1][3] = 0.0;
      HT[i1][3] = Hhand2eye[i1][3];
      ipiv[i1] = static_cast<signed char>(i1 + 1);
    }
    for (b_j = 0; b_j < 3; b_j++) {
      int b_tmp;
      int mmj_tmp;
      mmj_tmp = 2 - b_j;
      b_tmp = b_j * 5;
      jp1j = b_tmp + 2;
      N = 4 - b_j;
      sizes_idx_1 = 0;
      smax = std::abs((&HT[0][0])[b_tmp]);
      for (k = 2; k <= N; k++) {
        s = std::abs((&HT[0][0])[(b_tmp + k) - 1]);
        if (s > smax) {
          sizes_idx_1 = k - 1;
          smax = s;
        }
      }
      if ((&HT[0][0])[b_tmp + sizes_idx_1] != 0.0) {
        if (sizes_idx_1 != 0) {
          sizes_idx_1 += b_j;
          ipiv[b_j] = static_cast<signed char>(sizes_idx_1 + 1);
          smax = (&HT[0][0])[b_j];
          (&HT[0][0])[b_j] = (&HT[0][0])[sizes_idx_1];
          (&HT[0][0])[sizes_idx_1] = smax;
          smax = (&HT[0][0])[b_j + 4];
          (&HT[0][0])[b_j + 4] = (&HT[0][0])[sizes_idx_1 + 4];
          (&HT[0][0])[sizes_idx_1 + 4] = smax;
          smax = (&HT[0][0])[b_j + 8];
          (&HT[0][0])[b_j + 8] = (&HT[0][0])[sizes_idx_1 + 8];
          (&HT[0][0])[sizes_idx_1 + 8] = smax;
          smax = (&HT[0][0])[b_j + 12];
          (&HT[0][0])[b_j + 12] = (&HT[0][0])[sizes_idx_1 + 12];
          (&HT[0][0])[sizes_idx_1 + 12] = smax;
        }
        i1 = (b_tmp - b_j) + 4;
        for (b_i = jp1j; b_i <= i1; b_i++) {
          (&HT[0][0])[b_i - 1] /= (&HT[0][0])[b_tmp];
        }
      }
      sizes_idx_1 = b_tmp;
      for (N = 0; N <= mmj_tmp; N++) {
        smax = (&HT[0][0])[(b_tmp + (N * 4)) + 4];
        if (smax != 0.0) {
          i1 = sizes_idx_1 + 6;
          i2 = (sizes_idx_1 - b_j) + 8;
          for (b_i = i1; b_i <= i2; b_i++) {
            (&HT[0][0])[b_i - 1] +=
                (&HT[0][0])[((b_tmp + b_i) - sizes_idx_1) - 5] * (-smax);
          }
        }
        sizes_idx_1 += 4;
      }
    }
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    if (ipiv[0] > 1) {
      N = static_cast<int>(p[ipiv[0] - 1]);
      p[ipiv[0] - 1] = 1;
      p[0] = static_cast<signed char>(N);
    }
    if (ipiv[1] > 2) {
      N = static_cast<int>(p[ipiv[1] - 1]);
      p[ipiv[1] - 1] = p[1];
      p[1] = static_cast<signed char>(N);
    }
    if (ipiv[2] > 3) {
      N = static_cast<int>(p[ipiv[2] - 1]);
      p[ipiv[2] - 1] = p[2];
      p[2] = static_cast<signed char>(N);
    }
    for (k = 0; k < 4; k++) {
      sizes_idx_1 = (static_cast<int>(p[k])) - 1;
      b_y[sizes_idx_1][k] = 1.0;
      for (b_j = k + 1; b_j < 5; b_j++) {
        if (b_y[sizes_idx_1][b_j - 1] != 0.0) {
          i1 = b_j + 1;
          for (b_i = i1; b_i < 5; b_i++) {
            b_y[sizes_idx_1][b_i - 1] -=
                b_y[sizes_idx_1][b_j - 1] * HT[b_j - 1][b_i - 1];
          }
        }
      }
    }
    for (b_j = 0; b_j < 4; b_j++) {
      sizes_idx_1 = b_j * 4;
      for (k = 3; k >= 0; k--) {
        N = k * 4;
        i1 = k + sizes_idx_1;
        smax = (&b_y[0][0])[i1];
        if (smax != 0.0) {
          (&b_y[0][0])[i1] = smax / (&HT[0][0])[k + N];
          for (b_i = 0; b_i < k; b_i++) {
            i2 = b_i + sizes_idx_1;
            (&b_y[0][0])[i2] -= (&b_y[0][0])[i1] * (&HT[0][0])[b_i + N];
          }
        }
      }
    }
    for (i1 = 0; i1 < 4; i1++) {
      double d1;
      smax = b_y[0][i1];
      s = b_y[1][i1];
      d = b_y[2][i1];
      d1 = b_y[3][i1];
      for (i2 = 0; i2 < 4; i2++) {
        e_y[i2][i1] = (((smax * Hhand2base[(4 * i2) + (16 * j)]) +
                        (s * Hhand2base[((4 * i2) + (16 * j)) + 1])) +
                       (d * Hhand2base[((4 * i2) + (16 * j)) + 2])) +
                      (d1 * Hhand2base[((4 * i2) + (16 * j)) + 3]);
      }
      smax = e_y[0][i1];
      s = e_y[1][i1];
      d = e_y[2][i1];
      d1 = e_y[3][i1];
      for (i2 = 0; i2 < 4; i2++) {
        HT[i2][i1] = (((smax * Hbase2grid[i2][0]) + (s * Hbase2grid[i2][1])) +
                      (d * Hbase2grid[i2][2])) +
                     (d1 * Hbase2grid[i2][3]);
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    N = r.size(0);
    c_y.set_size(4, r.size(0));
    for (b_j = 0; b_j < N; b_j++) {
      for (b_i = 0; b_i < 4; b_i++) {
        c_y[b_i + (4 * b_j)] =
            (((HT[0][b_i] * r[b_j]) + (HT[1][b_i] * r[b_j + r.size(0)])) +
             (HT[2][b_i] * r[b_j + (r.size(0) * 2)])) +
            (HT[3][b_i] * r[b_j + (r.size(0) * 3)]);
      }
    }
    N = c_y.size(1);
    d_y.set_size(3, c_y.size(1));
    for (b_j = 0; b_j < N; b_j++) {
      for (b_i = 0; b_i < 3; b_i++) {
        d_y[b_i + (3 * b_j)] =
            (((K[0][b_i] * c_y[4 * b_j]) + (K[1][b_i] * c_y[(4 * b_j) + 1])) +
             (K[2][b_i] * c_y[(4 * b_j) + 2])) +
            (K[3][b_i] * c_y[(4 * b_j) + 3]);
      }
    }
    if (d_y.size(1) == 1) {
      i1 = 1;
    } else if (d_y.size(1) == 1) {
      i1 = 1;
    } else {
      i1 = d_y.size(1);
    }
    b_x.set_size(3, i1);
    if (i1 != 0) {
      sizes_idx_1 = (d_y.size(1) != 1);
      N = (d_y.size(1) != 1);
      i1--;
      for (k = 0; k <= i1; k++) {
        jp1j = sizes_idx_1 * k;
        b_i = N * k;
        b_x[3 * k] = d_y[3 * jp1j] / d_y[(3 * b_i) + 2];
        b_x[(3 * k) + 1] = d_y[(3 * jp1j) + 1] / d_y[(3 * b_i) + 2];
        b_x[(3 * k) + 2] = d_y[(3 * jp1j) + 2] / d_y[(3 * b_i) + 2];
      }
    }
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    jp1j = imgPts.size(0);
    a.set_size(imgPts.size(0), 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < jp1j; i2++) {
        a[i2 + (a.size(0) * i1)] =
            imgPts[(i2 + (imgPts.size(0) * i1)) + ((imgPts.size(0) * 2) * j)] -
            b_x[i1 + (3 * i2)];
      }
    }
    b_z1.set_size(a.size(0), 2);
    for (k = 0; k < 2; k++) {
      N = b_z1.size(0);
      for (sizes_idx_1 = 0; sizes_idx_1 < N; sizes_idx_1++) {
        b_z1[sizes_idx_1 + (b_z1.size(0) * k)] =
            rt_powd_snf(a[sizes_idx_1 + (a.size(0) * k)], 2.0);
      }
    }
    if (b_z1.size(0) == 0) {
      y.set_size(0);
    } else {
      y.set_size(b_z1.size(0));
      i1 = b_z1.size(0);
      for (k = 0; k < i1; k++) {
        y[k] = b_z1[k];
      }
      i1 = b_z1.size(0);
      for (k = 0; k < i1; k++) {
        y[k] = y[k] + b_z1[k + b_z1.size(0)];
      }
    }
    jp1j = y.size(0);
    for (i1 = 0; i1 < jp1j; i1++) {
      err[i1 + (err.size(0) * j)] = y[i1];
    }
    //  adopted approach
  }
  // rrmse
  N = err.size(0) * err.size(1);
  errors[0] =
      coder::combineVectorElements(angR) / (static_cast<double>(angR.size(0)));
  errors[1] =
      coder::combineVectorElements(x) / (static_cast<double>(x.size(0)));
  angR = err.reshape(N);
  errors[2] = std::sqrt(
      coder::combineVectorElements(angR) /
      (static_cast<double>(static_cast<int>(err.size(0) * err.size(1)))));
}

//
// File trailer for computeErrors.cpp
//
// [EOF]
//
