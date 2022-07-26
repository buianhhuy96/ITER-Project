//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: det.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "det.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
// Return Type  : double
//
namespace ITER {
namespace coder {
double b_det(const ::coder::array<double, 2U> &b_x)
{
  ::coder::array<double, 2U> A;
  ::coder::array<int, 2U> ipiv;
  double y;
  int i1;
  if (b_x.size(0) == 0) {
    y = 1.0;
  } else {
    int b;
    int b_yk;
    int i2;
    int i3;
    int i4;
    int ldap1;
    int loop_ub;
    int m;
    int u0;
    bool isodd;
    m = b_x.size(0);
    A.set_size(b_x.size(0), 3);
    loop_ub = b_x.size(0);
    if ((static_cast<int>((3 * b_x.size(0)) < 4)) != 0) {
      for (int b_i{0}; b_i < 3; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          A[i1 + (A.size(0) * b_i)] = b_x[i1 + (b_x.size(0) * b_i)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

      for (int b_i = 0; b_i < 3; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          A[i1 + (A.size(0) * b_i)] = b_x[i1 + (b_x.size(0) * b_i)];
        }
      }
    }
    u0 = b_x.size(0);
    if (u0 <= 3) {
      b = u0;
    } else {
      b = 3;
    }
    ipiv.set_size(1, b);
    ipiv[0] = 1;
    b_yk = 1;
    for (int k{2}; k <= b; k++) {
      b_yk++;
      ipiv[k - 1] = b_yk;
    }
    ldap1 = b_x.size(0);
    if ((b_x.size(0) - 1) <= 3) {
      i2 = b_x.size(0);
    } else {
      i2 = 4;
    }
    for (int j{0}; j <= (i2 - 2); j++) {
      int b_a;
      int b_b;
      int b_jA;
      int b_jy;
      int h_n;
      int jj;
      int jp1j;
      int mmj;
      mmj = m - j;
      b_b = j * (m + 1);
      jj = j * (ldap1 + 1);
      jp1j = b_b + 2;
      if (mmj < 1) {
        b_a = -1;
      } else {
        b_a = 0;
        if (mmj > 1) {
          double smax;
          smax = std::abs(A[jj]);
          for (int d_k{2}; d_k <= mmj; d_k++) {
            double s;
            s = std::abs(A[(b_b + d_k) - 1]);
            if (s > smax) {
              b_a = d_k - 1;
              smax = s;
            }
          }
        }
      }
      if (A[jj + b_a] != 0.0) {
        int i5;
        if (b_a != 0) {
          double temp;
          int ipiv_tmp;
          ipiv_tmp = j + b_a;
          ipiv[j] = ipiv_tmp + 1;
          temp = A[j];
          A[j] = A[ipiv_tmp];
          A[ipiv_tmp] = temp;
          temp = A[j + m];
          A[j + m] = A[ipiv_tmp + m];
          A[ipiv_tmp + m] = temp;
          temp = A[j + (m * 2)];
          A[j + (m * 2)] = A[ipiv_tmp + (m * 2)];
          A[ipiv_tmp + (m * 2)] = temp;
        }
        i5 = jj + mmj;
        for (int c_i{jp1j}; c_i <= i5; c_i++) {
          A[c_i - 1] = A[c_i - 1] / A[jj];
        }
      }
      h_n = 1 - j;
      b_jy = b_b + m;
      b_jA = jj + ldap1;
      for (int b_j{0}; b_j <= h_n; b_j++) {
        double yjy;
        yjy = A[b_jy + (b_j * m)];
        if (A[b_jy + (b_j * m)] != 0.0) {
          int i6;
          int i7;
          i6 = b_jA + 2;
          i7 = mmj + b_jA;
          for (int ijA{i6}; ijA <= i7; ijA++) {
            A[ijA - 1] = A[ijA - 1] + (A[((jj + ijA) - b_jA) - 1] * (-yjy));
          }
        }
        b_jA += m;
      }
    }
    y = A[0];
    i3 = A.size(0);
    for (int b_k{0}; b_k <= (i3 - 2); b_k++) {
      y *= A[(b_k + (A.size(0) * (b_k + 1))) + 1];
    }
    isodd = false;
    i4 = ipiv.size(1);
    for (int c_k{0}; c_k <= (i4 - 2); c_k++) {
      if (ipiv[c_k] > (c_k + 1)) {
        isodd = !isodd;
      }
    }
    if (isodd) {
      y = -y;
    }
  }
  return y;
}

//
// Arguments    : const double b_x[3][3]
// Return Type  : double
//
double det(const double b_x[3][3])
{
  double A[3][3];
  double y;
  signed char ipiv[3];
  bool isodd;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    A[b_i][0] = b_x[b_i][0];
    A[b_i][1] = b_x[b_i][1];
    A[b_i][2] = b_x[b_i][2];
    ipiv[b_i] = static_cast<signed char>(b_i + 1);
  }
  for (int j{0}; j < 2; j++) {
    double smax;
    int b_a;
    int b_jA;
    int b_tmp;
    int h_n;
    int jp1j;
    int mmj_tmp;
    mmj_tmp = 1 - j;
    b_tmp = j * 4;
    jp1j = b_tmp + 2;
    h_n = 3 - j;
    b_a = 0;
    smax = std::abs((&A[0][0])[b_tmp]);
    for (int k{2}; k <= h_n; k++) {
      double s;
      s = std::abs((&A[0][0])[(b_tmp + k) - 1]);
      if (s > smax) {
        b_a = k - 1;
        smax = s;
      }
    }
    if ((&A[0][0])[b_tmp + b_a] != 0.0) {
      int i1;
      if (b_a != 0) {
        double temp;
        int ipiv_tmp;
        ipiv_tmp = j + b_a;
        ipiv[j] = static_cast<signed char>(ipiv_tmp + 1);
        temp = (&A[0][0])[j];
        (&A[0][0])[j] = (&A[0][0])[ipiv_tmp];
        (&A[0][0])[ipiv_tmp] = temp;
        temp = (&A[0][0])[j + 3];
        (&A[0][0])[j + 3] = (&A[0][0])[ipiv_tmp + 3];
        (&A[0][0])[ipiv_tmp + 3] = temp;
        temp = (&A[0][0])[j + 6];
        (&A[0][0])[j + 6] = (&A[0][0])[ipiv_tmp + 6];
        (&A[0][0])[ipiv_tmp + 6] = temp;
      }
      i1 = (b_tmp - j) + 3;
      for (int c_i{jp1j}; c_i <= i1; c_i++) {
        (&A[0][0])[c_i - 1] /= (&A[0][0])[b_tmp];
      }
    }
    b_jA = b_tmp;
    for (int b_j{0}; b_j <= mmj_tmp; b_j++) {
      double yjy_tmp;
      yjy_tmp = (&A[0][0])[(b_tmp + (b_j * 3)) + 3];
      if (yjy_tmp != 0.0) {
        int i2;
        int i3;
        i2 = b_jA + 5;
        i3 = (b_jA - j) + 6;
        for (int ijA{i2}; ijA <= i3; ijA++) {
          (&A[0][0])[ijA - 1] +=
              (&A[0][0])[((b_tmp + ijA) - b_jA) - 4] * (-yjy_tmp);
        }
      }
      b_jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = (A[0][0] * A[1][1]) * A[2][2];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

} // namespace coder
} // namespace ITER

//
// File trailer for det.cpp
//
// [EOF]
//
