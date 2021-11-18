//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeErrors.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
//                const double b_K[4][3]
//                double errors[3]
// Return Type  : void
//
void computeErrors(const coder::array<double, 3U> &Hhand2base,
                   const double Hhand2eye[4][4], const double Hbase2grid[4][4],
                   const coder::array<double, 3U> &Hcam2grid,
                   const coder::array<double, 3U> &imgPts,
                   const coder::array<double, 2U> &Worldpts,
                   const double b_K[4][3], double errors[3])
{
  coder::array<double, 3U> PoseErrR;
  coder::array<double, 2U> PoseErrt;
  coder::array<double, 2U> c_x;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> e_y;
  coder::array<double, 2U> err;
  coder::array<double, 2U> f_y;
  coder::array<double, 2U> r;
  coder::array<double, 1U> angR;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> y;
  double HT[4][4];
  double b_y[4][4];
  double d_y[4][4];
  double b_Hhand2eye[3][3];
  double dv[3][3];
  double AxAngVec[4];
  double d;
  double s;
  double smax;
  int b_i;
  int i1;
  int j;
  int jA;
  int jp1j;
  int k;
  int loop_ub;
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
    jA = Worldpts.size(0);
  } else {
    jA = 0;
  }
  empty_non_axis_sizes = (jA == 0);
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
  r.set_size(jA, ((static_cast<int>(input_sizes_idx_1)) +
                  (static_cast<int>(b_input_sizes_idx_1))) +
                     sizes_idx_1);
  loop_ub = static_cast<int>(input_sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < jA; i1++) {
      r[i1 + (r.size(0) * b_i)] = Worldpts[i1 + (jA * b_i)];
    }
  }
  loop_ub = static_cast<int>(b_input_sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < jA; i1++) {
      r[i1 + (r.size(0) * (static_cast<int>(input_sizes_idx_1)))] = 0.0;
    }
  }
  for (b_i = 0; b_i < sizes_idx_1; b_i++) {
    for (i1 = 0; i1 < jA; i1++) {
      r[i1 + (r.size(0) * ((static_cast<int>(input_sizes_idx_1)) +
                           (static_cast<int>(b_input_sizes_idx_1))))] = 1.0;
    }
  }
  //  Computing Errors
  //     %% Computing Rotation errors distribution
  angR.set_size(imgPts.size(2));
  loop_ub = imgPts.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    angR[b_i] = 0.0;
  }
  PoseErrR.set_size(3, 3, imgPts.size(2));
  loop_ub = imgPts.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      PoseErrR[(3 * i1) + (9 * b_i)] = 0.0;
      PoseErrR[((3 * i1) + (9 * b_i)) + 1] = 0.0;
      PoseErrR[((3 * i1) + (9 * b_i)) + 2] = 0.0;
    }
  }
  // %%%%%%% length(Hcam2grid) -> number of images
  b_i = imgPts.size(2);
  for (j = 0; j < b_i; j++) {
    for (i1 = 0; i1 < 3; i1++) {
      smax = Hhand2eye[0][i1];
      s = Hhand2eye[1][i1];
      d = Hhand2eye[2][i1];
      for (jp1j = 0; jp1j < 3; jp1j++) {
        b_Hhand2eye[jp1j][i1] = ((smax * Hcam2grid[(4 * jp1j) + (16 * j)]) +
                                 (s * Hcam2grid[((4 * jp1j) + (16 * j)) + 1])) +
                                (d * Hcam2grid[((4 * jp1j) + (16 * j)) + 2]);
      }
    }
    coder::inv(b_Hhand2eye, dv);
    for (i1 = 0; i1 < 3; i1++) {
      for (jp1j = 0; jp1j < 3; jp1j++) {
        b_Hhand2eye[jp1j][i1] =
            ((Hhand2base[i1 + (16 * j)] * Hbase2grid[jp1j][0]) +
             (Hhand2base[(i1 + (16 * j)) + 4] * Hbase2grid[jp1j][1])) +
            (Hhand2base[(i1 + (16 * j)) + 8] * Hbase2grid[jp1j][2]);
      }
    }
    for (i1 = 0; i1 < 3; i1++) {
      smax = dv[0][i1];
      s = dv[1][i1];
      d = dv[2][i1];
      for (jp1j = 0; jp1j < 3; jp1j++) {
        PoseErrR[(i1 + (3 * jp1j)) + (9 * j)] =
            ((smax * b_Hhand2eye[jp1j][0]) + (s * b_Hhand2eye[jp1j][1])) +
            (d * b_Hhand2eye[jp1j][2]);
      }
    }
    //  inv(Rz*Rb)(Ra*Rx)
    coder::rotm2axang(*((double(*)[3][3])(&PoseErrR[9 * j])), AxAngVec);
    angR[j] = AxAngVec[3] * 57.295779513082323;
  }
  loop_ub = angR.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    smax = angR[b_i];
    angR[b_i] = smax * smax;
  }
  if (angR.size(0) == 0) {
    y.set_size(0);
  } else {
    y.set_size(angR.size(0));
    b_i = angR.size(0);
    for (k = 0; k < b_i; k++) {
      y[k] = angR[k];
    }
  }
  b_i = y.size(0);
  for (k = 0; k < b_i; k++) {
    y[k] = std::sqrt(y[k]);
  }
  //     %% Computing Translation errors distribution
  PoseErrt.set_size(imgPts.size(2), 3);
  b_i = imgPts.size(2);
  for (j = 0; j < b_i; j++) {
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
  PoseErrt.set_size(PoseErrt.size(0), 3);
  for (b_i = 0; b_i < 3; b_i++) {
    loop_ub = PoseErrt.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      smax = PoseErrt[i1 + (PoseErrt.size(0) * b_i)];
      PoseErrt[i1 + (PoseErrt.size(0) * b_i)] = smax * smax;
    }
  }
  if (PoseErrt.size(0) == 0) {
    b_x.set_size(0);
  } else {
    b_x.set_size(PoseErrt.size(0));
    b_i = PoseErrt.size(0);
    for (k = 0; k < b_i; k++) {
      b_x[k] = PoseErrt[k];
    }
    b_i = PoseErrt.size(0);
    for (k = 0; k < 2; k++) {
      for (jA = 0; jA < b_i; jA++) {
        b_x[jA] = b_x[jA] + PoseErrt[jA + (PoseErrt.size(0) * (k + 1))];
      }
    }
  }
  b_i = b_x.size(0);
  for (k = 0; k < b_i; k++) {
    b_x[k] = std::sqrt(b_x[k]);
  }
  //     %% Computing Reprojection errors
  err.set_size(imgPts.size(0), imgPts.size(2));
  loop_ub = imgPts.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    jA = imgPts.size(0);
    for (i1 = 0; i1 < jA; i1++) {
      err[i1 + (err.size(0) * b_i)] = 0.0;
    }
  }
  b_i = imgPts.size(2);
  for (j = 0; j < b_i; j++) {
    int b_j;
    for (i1 = 0; i1 < 4; i1++) {
      for (jp1j = 0; jp1j < 4; jp1j++) {
        b_y[i1][jp1j] = 0.0;
        HT[i1][jp1j] = Hhand2eye[i1][jp1j];
      }
      ipiv[i1] = static_cast<signed char>(i1 + 1);
    }
    for (b_j = 0; b_j < 3; b_j++) {
      int b_tmp;
      int mmj_tmp;
      mmj_tmp = 2 - b_j;
      b_tmp = b_j * 5;
      jp1j = b_tmp + 2;
      sizes_idx_1 = 4 - b_j;
      jA = 0;
      smax = std::abs((&HT[0][0])[b_tmp]);
      for (k = 2; k <= sizes_idx_1; k++) {
        s = std::abs((&HT[0][0])[(b_tmp + k) - 1]);
        if (s > smax) {
          jA = k - 1;
          smax = s;
        }
      }
      if ((&HT[0][0])[b_tmp + jA] != 0.0) {
        if (jA != 0) {
          sizes_idx_1 = b_j + jA;
          ipiv[b_j] = static_cast<signed char>(sizes_idx_1 + 1);
          for (k = 0; k < 4; k++) {
            jA = k * 4;
            loop_ub = b_j + jA;
            smax = (&HT[0][0])[loop_ub];
            i1 = sizes_idx_1 + jA;
            (&HT[0][0])[loop_ub] = (&HT[0][0])[i1];
            (&HT[0][0])[i1] = smax;
          }
        }
        i1 = (b_tmp - b_j) + 4;
        for (loop_ub = jp1j; loop_ub <= i1; loop_ub++) {
          (&HT[0][0])[loop_ub - 1] /= (&HT[0][0])[b_tmp];
        }
      }
      jA = b_tmp;
      for (sizes_idx_1 = 0; sizes_idx_1 <= mmj_tmp; sizes_idx_1++) {
        smax = (&HT[0][0])[(b_tmp + (sizes_idx_1 * 4)) + 4];
        if (smax != 0.0) {
          i1 = jA + 6;
          jp1j = (jA - b_j) + 8;
          for (loop_ub = i1; loop_ub <= jp1j; loop_ub++) {
            (&HT[0][0])[loop_ub - 1] +=
                (&HT[0][0])[((b_tmp + loop_ub) - jA) - 5] * (-smax);
          }
        }
        jA += 4;
      }
    }
    for (i1 = 0; i1 < 4; i1++) {
      p[i1] = static_cast<signed char>(i1 + 1);
    }
    if (ipiv[0] > 1) {
      jA = static_cast<int>(p[ipiv[0] - 1]);
      p[ipiv[0] - 1] = p[0];
      p[0] = static_cast<signed char>(jA);
    }
    if (ipiv[1] > 2) {
      jA = static_cast<int>(p[ipiv[1] - 1]);
      p[ipiv[1] - 1] = p[1];
      p[1] = static_cast<signed char>(jA);
    }
    if (ipiv[2] > 3) {
      jA = static_cast<int>(p[ipiv[2] - 1]);
      p[ipiv[2] - 1] = p[2];
      p[2] = static_cast<signed char>(jA);
    }
    for (k = 0; k < 4; k++) {
      jA = (static_cast<int>(p[k])) - 1;
      b_y[jA][k] = 1.0;
      for (b_j = k + 1; b_j < 5; b_j++) {
        if (b_y[jA][b_j - 1] != 0.0) {
          i1 = b_j + 1;
          for (loop_ub = i1; loop_ub < 5; loop_ub++) {
            b_y[jA][loop_ub - 1] -= b_y[jA][b_j - 1] * HT[b_j - 1][loop_ub - 1];
          }
        }
      }
    }
    for (b_j = 0; b_j < 4; b_j++) {
      jA = b_j * 4;
      for (k = 3; k >= 0; k--) {
        sizes_idx_1 = k * 4;
        i1 = k + jA;
        smax = (&b_y[0][0])[i1];
        if (smax != 0.0) {
          (&b_y[0][0])[i1] = smax / (&HT[0][0])[k + sizes_idx_1];
          for (loop_ub = 0; loop_ub < k; loop_ub++) {
            jp1j = loop_ub + jA;
            (&b_y[0][0])[jp1j] -=
                (&b_y[0][0])[i1] * (&HT[0][0])[loop_ub + sizes_idx_1];
          }
        }
      }
    }
    for (i1 = 0; i1 < 4; i1++) {
      for (jp1j = 0; jp1j < 4; jp1j++) {
        smax = 0.0;
        for (jA = 0; jA < 4; jA++) {
          smax += b_y[jA][i1] * Hhand2base[(jA + (4 * jp1j)) + (16 * j)];
        }
        d_y[jp1j][i1] = smax;
      }
      for (jp1j = 0; jp1j < 4; jp1j++) {
        smax = 0.0;
        for (jA = 0; jA < 4; jA++) {
          smax += d_y[jA][i1] * Hbase2grid[jp1j][jA];
        }
        HT[jp1j][i1] = smax;
      }
    }
    //  either inv(Z)*A*X  ,where Z is H2e and X is base 2 grid
    sizes_idx_1 = r.size(0);
    c_y.set_size(4, r.size(0));
    for (b_j = 0; b_j < sizes_idx_1; b_j++) {
      for (loop_ub = 0; loop_ub < 4; loop_ub++) {
        s = 0.0;
        for (k = 0; k < 4; k++) {
          s += HT[k][loop_ub] * r[b_j + (r.size(0) * k)];
        }
        c_y[loop_ub + (4 * b_j)] = s;
      }
    }
    sizes_idx_1 = c_y.size(1);
    e_y.set_size(3, c_y.size(1));
    for (b_j = 0; b_j < sizes_idx_1; b_j++) {
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        s = 0.0;
        for (k = 0; k < 4; k++) {
          s += b_K[k][loop_ub] * c_y[k + (4 * b_j)];
        }
        e_y[loop_ub + (3 * b_j)] = s;
      }
    }
    if (e_y.size(1) == 1) {
      i1 = 1;
    } else if (e_y.size(1) == 1) {
      i1 = 1;
    } else {
      i1 = e_y.size(1);
    }
    c_x.set_size(3, i1);
    if (i1 != 0) {
      jA = static_cast<int>(e_y.size(1) != 1);
      sizes_idx_1 = static_cast<int>(e_y.size(1) != 1);
      i1--;
      for (k = 0; k <= i1; k++) {
        loop_ub = jA * k;
        jp1j = sizes_idx_1 * k;
        c_x[3 * k] = e_y[3 * loop_ub] / e_y[(3 * jp1j) + 2];
        c_x[(3 * k) + 1] = e_y[(3 * loop_ub) + 1] / e_y[(3 * jp1j) + 2];
        c_x[(3 * k) + 2] = e_y[(3 * loop_ub) + 2] / e_y[(3 * jp1j) + 2];
      }
    }
    // need to invert HT befor invR, if the representation change of whole
    // inverse is followed
    loop_ub = imgPts.size(0);
    if (imgPts.size(0) == c_x.size(1)) {
      f_y.set_size(imgPts.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        for (jp1j = 0; jp1j < loop_ub; jp1j++) {
          smax = imgPts[(jp1j + (imgPts.size(0) * i1)) +
                        ((imgPts.size(0) * 2) * j)] -
                 c_x[i1 + (3 * jp1j)];
          f_y[jp1j + (f_y.size(0) * i1)] = smax * smax;
        }
      }
    } else {
      binary_expand_op(f_y, imgPts, j, c_x);
    }
    if (f_y.size(0) == 0) {
      angR.set_size(0);
    } else {
      angR.set_size(f_y.size(0));
      i1 = f_y.size(0);
      for (k = 0; k < i1; k++) {
        angR[k] = f_y[k];
      }
      i1 = f_y.size(0);
      for (k = 0; k < i1; k++) {
        angR[k] = angR[k] + f_y[k + f_y.size(0)];
      }
    }
    loop_ub = angR.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      err[i1 + (err.size(0) * j)] = angR[i1];
    }
    //  adopted approach
  }
  // rrmse
  jA = err.size(0) * err.size(1);
  errors[0] =
      coder::combineVectorElements(y) / (static_cast<double>(y.size(0)));
  errors[1] =
      coder::combineVectorElements(b_x) / (static_cast<double>(b_x.size(0)));
  angR = err.reshape(jA);
  errors[2] = std::sqrt(
      coder::combineVectorElements(angR) /
      (static_cast<double>(static_cast<int>(err.size(0) * err.size(1)))));
}

//
// File trailer for computeErrors.cpp
//
// [EOF]
//
