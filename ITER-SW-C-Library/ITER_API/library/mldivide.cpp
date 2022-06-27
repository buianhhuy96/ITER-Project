//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double A[3][3]
//                const double c_B[3][3]
//                double g_Y[3][3]
// Return Type  : void
//
namespace coder {
void b_mldivide(const double A[3][3], const double c_B[3][3], double g_Y[3][3])
{
  double e_A[3][3];
  double a21;
  double b_d1;
  double d;
  double maxval;
  int r1;
  int r2;
  int r3;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    e_A[b_i][0] = A[b_i][0];
    e_A[b_i][1] = A[b_i][1];
    e_A[b_i][2] = A[b_i][2];
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(A[0][0]);
  a21 = std::abs(A[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(A[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  e_A[0][r2] = A[0][r2] / A[0][r1];
  e_A[0][r3] /= e_A[0][r1];
  e_A[1][r2] -= e_A[0][r2] * e_A[1][r1];
  e_A[1][r3] -= e_A[0][r3] * e_A[1][r1];
  e_A[2][r2] -= e_A[0][r2] * e_A[2][r1];
  e_A[2][r3] -= e_A[0][r3] * e_A[2][r1];
  if (std::abs(e_A[1][r3]) > std::abs(e_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  e_A[1][r3] /= e_A[1][r2];
  e_A[2][r3] -= e_A[1][r3] * e_A[2][r2];
  d = c_B[0][r2] - (c_B[0][r1] * e_A[0][r2]);
  b_d1 = ((c_B[0][r3] - (c_B[0][r1] * e_A[0][r3])) - (d * e_A[1][r3])) /
         e_A[2][r3];
  g_Y[0][2] = b_d1;
  d -= b_d1 * e_A[2][r2];
  d /= e_A[1][r2];
  g_Y[0][1] = d;
  g_Y[0][0] =
      ((c_B[0][r1] - (b_d1 * e_A[2][r1])) - (d * e_A[1][r1])) / e_A[0][r1];
  d = c_B[1][r2] - (c_B[1][r1] * e_A[0][r2]);
  b_d1 = ((c_B[1][r3] - (c_B[1][r1] * e_A[0][r3])) - (d * e_A[1][r3])) /
         e_A[2][r3];
  g_Y[1][2] = b_d1;
  d -= b_d1 * e_A[2][r2];
  d /= e_A[1][r2];
  g_Y[1][1] = d;
  g_Y[1][0] =
      ((c_B[1][r1] - (b_d1 * e_A[2][r1])) - (d * e_A[1][r1])) / e_A[0][r1];
  d = c_B[2][r2] - (c_B[2][r1] * e_A[0][r2]);
  b_d1 = ((c_B[2][r3] - (c_B[2][r1] * e_A[0][r3])) - (d * e_A[1][r3])) /
         e_A[2][r3];
  g_Y[2][2] = b_d1;
  d -= b_d1 * e_A[2][r2];
  d /= e_A[1][r2];
  g_Y[2][1] = d;
  g_Y[2][0] =
      ((c_B[2][r1] - (b_d1 * e_A[2][r1])) - (d * e_A[1][r1])) / e_A[0][r1];
}

//
// Arguments    : const double A[3][3]
//                const double c_B[3]
//                double g_Y[3]
// Return Type  : void
//
void c_mldivide(const double A[3][3], const double c_B[3], double g_Y[3])
{
  double e_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    e_A[b_i][0] = A[b_i][0];
    e_A[b_i][1] = A[b_i][1];
    e_A[b_i][2] = A[b_i][2];
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(A[0][0]);
  a21 = std::abs(A[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(A[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  e_A[0][r2] = A[0][r2] / A[0][r1];
  e_A[0][r3] /= e_A[0][r1];
  e_A[1][r2] -= e_A[0][r2] * e_A[1][r1];
  e_A[1][r3] -= e_A[0][r3] * e_A[1][r1];
  e_A[2][r2] -= e_A[0][r2] * e_A[2][r1];
  e_A[2][r3] -= e_A[0][r3] * e_A[2][r1];
  if (std::abs(e_A[1][r3]) > std::abs(e_A[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  e_A[1][r3] /= e_A[1][r2];
  e_A[2][r3] -= e_A[1][r3] * e_A[2][r2];
  g_Y[1] = c_B[r2] - (c_B[r1] * e_A[0][r2]);
  g_Y[2] = (c_B[r3] - (c_B[r1] * e_A[0][r3])) - (g_Y[1] * e_A[1][r3]);
  g_Y[2] /= e_A[2][r3];
  g_Y[0] = c_B[r1] - (g_Y[2] * e_A[2][r1]);
  g_Y[1] -= g_Y[2] * e_A[2][r2];
  g_Y[1] /= e_A[1][r2];
  g_Y[0] -= g_Y[1] * e_A[1][r1];
  g_Y[0] /= e_A[0][r1];
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &c_B
//                ::coder::array<double, 1U> &g_Y
// Return Type  : void
//
void d_mldivide(const ::coder::array<double, 2U> &A,
                const ::coder::array<double, 1U> &c_B,
                ::coder::array<double, 1U> &g_Y)
{
  array<double, 2U> e_A;
  array<double, 1U> f_B;
  array<double, 1U> tau;
  array<int, 2U> ipiv;
  array<int, 2U> jpvt;
  int c_loop_ub;
  int f_loop_ub;
  int i2;
  int i5;
  bool guard1{false};
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else if (c_B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == A.size(1)) {
    int b_LDA;
    int b_u0;
    int b_u1;
    int b_yk;
    int c_LDA;
    int c_u0;
    int d_loop_ub;
    int h_loop_ub;
    int h_n;
    int i7;
    int i_loop_ub;
    int ldap1;
    int u0;
    int y;
    u0 = A.size(0);
    b_u1 = A.size(1);
    if (u0 <= b_u1) {
      y = u0;
    } else {
      y = b_u1;
    }
    b_u0 = c_B.size(0);
    if (b_u0 <= y) {
      h_n = b_u0;
    } else {
      h_n = y;
    }
    b_LDA = A.size(0);
    e_A.set_size(A.size(0), A.size(1));
    d_loop_ub = A.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5,        \
                                                                    f_loop_ub)

    for (int i3 = 0; i3 < d_loop_ub; i3++) {
      f_loop_ub = A.size(0);
      for (i5 = 0; i5 < f_loop_ub; i5++) {
        e_A[i5 + (e_A.size(0) * i3)] = A[i5 + (A.size(0) * i3)];
      }
    }
    ipiv.set_size(1, h_n);
    ipiv[0] = 1;
    b_yk = 1;
    for (int k{2}; k <= h_n; k++) {
      b_yk++;
      ipiv[k - 1] = b_yk;
    }
    ldap1 = A.size(0);
    c_u0 = h_n - 1;
    if (c_u0 <= h_n) {
      i7 = c_u0;
    } else {
      i7 = h_n;
    }
    for (int j{0}; j < i7; j++) {
      int b;
      int b_a;
      int b_jy;
      int jA;
      int jj;
      int jp1j;
      int mmj_tmp;
      mmj_tmp = h_n - j;
      b = j * (b_LDA + 1);
      jj = j * (ldap1 + 1);
      jp1j = b + 2;
      if (mmj_tmp < 1) {
        b_a = -1;
      } else {
        b_a = 0;
        if (mmj_tmp > 1) {
          double smax;
          smax = std::abs(e_A[jj]);
          for (int b_k{2}; b_k <= mmj_tmp; b_k++) {
            double s;
            s = std::abs(e_A[(b + b_k) - 1]);
            if (s > smax) {
              b_a = b_k - 1;
              smax = s;
            }
          }
        }
      }
      if (e_A[jj + b_a] != 0.0) {
        int i12;
        if (b_a != 0) {
          int ipiv_tmp;
          ipiv_tmp = j + b_a;
          ipiv[j] = ipiv_tmp + 1;
          for (int e_k{0}; e_k < h_n; e_k++) {
            double b_temp;
            int b_temp_tmp;
            int i16;
            int temp_tmp;
            temp_tmp = e_k * b_LDA;
            b_temp_tmp = j + temp_tmp;
            b_temp = e_A[b_temp_tmp];
            i16 = ipiv_tmp + temp_tmp;
            e_A[b_temp_tmp] = e_A[i16];
            e_A[i16] = b_temp;
          }
        }
        i12 = jj + mmj_tmp;
        for (int g_i{jp1j}; g_i <= i12; g_i++) {
          e_A[g_i - 1] = e_A[g_i - 1] / e_A[jj];
        }
      }
      b_jy = b + b_LDA;
      jA = jj + ldap1;
      for (int d_j{0}; d_j <= (mmj_tmp - 2); d_j++) {
        double yjy;
        int yjy_tmp;
        yjy_tmp = b_jy + (d_j * b_LDA);
        yjy = e_A[yjy_tmp];
        if (e_A[yjy_tmp] != 0.0) {
          int i15;
          int i17;
          i15 = jA + 2;
          i17 = mmj_tmp + jA;
          for (int ijA{i15}; ijA <= i17; ijA++) {
            e_A[ijA - 1] = e_A[ijA - 1] + (e_A[((jj + ijA) - jA) - 1] * (-yjy));
          }
        }
        jA += b_LDA;
      }
    }
    f_B.set_size(c_B.size(0));
    h_loop_ub = c_B.size(0);
    if ((static_cast<int>(c_B.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 < h_loop_ub; b_i8++) {
        f_B[b_i8] = c_B[b_i8];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 < h_loop_ub; b_i8++) {
        f_B[b_i8] = c_B[b_i8];
      }
    }
    c_LDA = e_A.size(0);
    for (int d_i{0}; d_i <= (h_n - 2); d_i++) {
      int i10;
      i10 = ipiv[d_i];
      if (i10 != (d_i + 1)) {
        double temp;
        temp = f_B[d_i];
        f_B[d_i] = f_B[i10 - 1];
        f_B[i10 - 1] = temp;
      }
    }
    for (int c_k{0}; c_k < h_n; c_k++) {
      int kAcol;
      kAcol = c_LDA * c_k;
      if (f_B[c_k] != 0.0) {
        int i13;
        i13 = c_k + 2;
        for (int m_i{i13}; m_i <= h_n; m_i++) {
          f_B[m_i - 1] = f_B[m_i - 1] - (f_B[c_k] * e_A[(m_i + kAcol) - 1]);
        }
      }
    }
    for (int d_k{h_n}; d_k >= 1; d_k--) {
      double d;
      int b_kAcol;
      b_kAcol = c_LDA * (d_k - 1);
      d = f_B[d_k - 1];
      if (d != 0.0) {
        f_B[d_k - 1] = d / e_A[(d_k + b_kAcol) - 1];
        for (int q_i{0}; q_i <= (d_k - 2); q_i++) {
          f_B[q_i] = f_B[q_i] - (f_B[d_k - 1] * e_A[q_i + b_kAcol]);
        }
      }
    }
    g_Y.set_size(f_B.size(0));
    i_loop_ub = f_B.size(0);
    if ((static_cast<int>(f_B.size(0) < 4)) != 0) {
      for (int i14{0}; i14 < i_loop_ub; i14++) {
        g_Y[i14] = f_B[i14];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i14 = 0; i14 < i_loop_ub; i14++) {
        g_Y[i14] = f_B[i14];
      }
    }
  } else {
    int b_m;
    int b_mn;
    int c_u1;
    int d_u0;
    int e_loop_ub;
    int g_loop_ub;
    int loop_ub;
    int maxmn;
    int minmn;
    int rankA;
    e_A.set_size(A.size(0), A.size(1));
    loop_ub = A.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    c_loop_ub)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      c_loop_ub = A.size(0);
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        e_A[i2 + (e_A.size(0) * b_i)] = A[i2 + (A.size(0) * b_i)];
      }
    }
    internal::lapack::xgeqp3(e_A, tau, jpvt);
    rankA = 0;
    if (e_A.size(0) < e_A.size(1)) {
      minmn = e_A.size(0);
      maxmn = e_A.size(1);
    } else {
      minmn = e_A.size(1);
      maxmn = e_A.size(0);
    }
    if (minmn > 0) {
      double tol;
      bool exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(e_A[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(e_A[rankA + (e_A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    g_Y.set_size(e_A.size(1));
    e_loop_ub = e_A.size(1);
    if ((static_cast<int>(e_A.size(1) < 4)) != 0) {
      for (int i4{0}; i4 < e_loop_ub; i4++) {
        g_Y[i4] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < e_loop_ub; i4++) {
        g_Y[i4] = 0.0;
      }
    }
    f_B.set_size(c_B.size(0));
    g_loop_ub = c_B.size(0);
    if ((static_cast<int>(c_B.size(0) < 4)) != 0) {
      for (int i6{0}; i6 < g_loop_ub; i6++) {
        f_B[i6] = c_B[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < g_loop_ub; i6++) {
        f_B[i6] = c_B[i6];
      }
    }
    b_m = e_A.size(0);
    d_u0 = e_A.size(0);
    c_u1 = e_A.size(1);
    if (d_u0 <= c_u1) {
      b_mn = d_u0;
    } else {
      b_mn = c_u1;
    }
    for (int b_j{0}; b_j < b_mn; b_j++) {
      if (tau[b_j] != 0.0) {
        double wj;
        int i9;
        wj = f_B[b_j];
        i9 = b_j + 2;
        for (int e_i{i9}; e_i <= b_m; e_i++) {
          wj += e_A[(e_i + (e_A.size(0) * b_j)) - 1] * f_B[e_i - 1];
        }
        wj *= tau[b_j];
        if (wj != 0.0) {
          f_B[b_j] = f_B[b_j] - wj;
          for (int k_i{i9}; k_i <= b_m; k_i++) {
            f_B[k_i - 1] =
                f_B[k_i - 1] - (e_A[(k_i + (e_A.size(0) * b_j)) - 1] * wj);
          }
        }
      }
    }
    for (int c_i{0}; c_i < rankA; c_i++) {
      g_Y[jpvt[c_i] - 1] = f_B[c_i];
    }
    for (int c_j{rankA}; c_j >= 1; c_j--) {
      int i11;
      i11 = jpvt[c_j - 1];
      g_Y[i11 - 1] = g_Y[i11 - 1] / e_A[(c_j + (e_A.size(0) * (c_j - 1))) - 1];
      for (int h_i{0}; h_i <= (c_j - 2); h_i++) {
        g_Y[jpvt[h_i] - 1] =
            g_Y[jpvt[h_i] - 1] -
            (g_Y[jpvt[c_j - 1] - 1] * e_A[h_i + (e_A.size(0) * (c_j - 1))]);
      }
    }
  }
  if (guard1) {
    int b_loop_ub;
    g_Y.set_size(A.size(1));
    b_loop_ub = A.size(1);
    if ((static_cast<int>(A.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        g_Y[i1] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        g_Y[i1] = 0.0;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &c_B
//                ::coder::array<double, 1U> &g_Y
// Return Type  : void
//
void mldivide(const ::coder::array<double, 2U> &A,
              const ::coder::array<double, 1U> &c_B,
              ::coder::array<double, 1U> &g_Y)
{
  array<double, 2U> e_A;
  array<double, 1U> tau;
  double j_Y[8];
  int jpvt[8];
  int i3;
  int i4;
  signed char ipiv[8];
  bool guard1{false};
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else if (c_B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == 8) {
    int b_loop_ub;
    e_A.set_size(8, 8);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int b_i = 0; b_i < 8; b_i++) {
      for (i4 = 0; i4 < 8; i4++) {
        e_A[i4 + (e_A.size(0) * b_i)] = A[i4 + (A.size(0) * b_i)];
      }
      ipiv[b_i] = static_cast<signed char>(b_i + 1);
    }
    for (int j{0}; j < 7; j++) {
      double smax;
      int b_a;
      int b_tmp;
      int h_n;
      int jA;
      int jp1j;
      int mmj_tmp;
      mmj_tmp = 6 - j;
      b_tmp = j * 9;
      jp1j = b_tmp + 2;
      h_n = 8 - j;
      b_a = 0;
      smax = std::abs(e_A[b_tmp]);
      for (int k{2}; k <= h_n; k++) {
        double s;
        s = std::abs(e_A[(b_tmp + k) - 1]);
        if (s > smax) {
          b_a = k - 1;
          smax = s;
        }
      }
      if (e_A[b_tmp + b_a] != 0.0) {
        int i7;
        if (b_a != 0) {
          int ipiv_tmp;
          ipiv_tmp = j + b_a;
          ipiv[j] = static_cast<signed char>(ipiv_tmp + 1);
          for (int d_k{0}; d_k < 8; d_k++) {
            double b_temp;
            int b_temp_tmp;
            int i12;
            int temp_tmp;
            temp_tmp = d_k * 8;
            b_temp_tmp = j + temp_tmp;
            b_temp = e_A[b_temp_tmp];
            i12 = ipiv_tmp + temp_tmp;
            e_A[b_temp_tmp] = e_A[i12];
            e_A[i12] = b_temp;
          }
        }
        i7 = (b_tmp - j) + 8;
        for (int d_i{jp1j}; d_i <= i7; d_i++) {
          e_A[d_i - 1] = e_A[d_i - 1] / e_A[b_tmp];
        }
      }
      jA = b_tmp;
      for (int b_j{0}; b_j <= mmj_tmp; b_j++) {
        double yjy;
        int yjy_tmp;
        yjy_tmp = (b_tmp + (b_j * 8)) + 8;
        yjy = e_A[yjy_tmp];
        if (e_A[yjy_tmp] != 0.0) {
          int i10;
          int i11;
          i10 = jA + 10;
          i11 = (jA - j) + 16;
          for (int ijA{i10}; ijA <= i11; ijA++) {
            e_A[ijA - 1] =
                e_A[ijA - 1] + (e_A[((b_tmp + ijA) - jA) - 9] * (-yjy));
          }
        }
        jA += 8;
      }
    }
    g_Y.set_size(c_B.size(0));
    b_loop_ub = c_B.size(0);
    if ((static_cast<int>(c_B.size(0) < 4)) != 0) {
      for (int i5{0}; i5 < b_loop_ub; i5++) {
        g_Y[i5] = c_B[i5];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < b_loop_ub; i5++) {
        g_Y[i5] = c_B[i5];
      }
    }
    for (int c_i{0}; c_i < 7; c_i++) {
      signed char i6;
      i6 = ipiv[c_i];
      if ((static_cast<int>(i6)) != (c_i + 1)) {
        double temp;
        int Y_tmp;
        temp = g_Y[c_i];
        Y_tmp = (static_cast<int>(i6)) - 1;
        g_Y[c_i] = g_Y[Y_tmp];
        g_Y[Y_tmp] = temp;
      }
    }
    for (int b_k{0}; b_k < 8; b_k++) {
      int kAcol;
      kAcol = b_k * 8;
      if (g_Y[b_k] != 0.0) {
        int i9;
        i9 = b_k + 2;
        for (int e_i{i9}; e_i < 9; e_i++) {
          g_Y[e_i - 1] = g_Y[e_i - 1] - (g_Y[b_k] * e_A[(e_i + kAcol) - 1]);
        }
      }
    }
    for (int c_k{7}; c_k >= 0; c_k--) {
      int b_kAcol;
      b_kAcol = c_k * 8;
      if (g_Y[c_k] != 0.0) {
        g_Y[c_k] = g_Y[c_k] / e_A[c_k + b_kAcol];
        for (int h_i{0}; h_i < c_k; h_i++) {
          g_Y[h_i] = g_Y[h_i] - (g_Y[c_k] * e_A[h_i + b_kAcol]);
        }
      }
    }
  } else {
    int b_m;
    int b_mn;
    int c_loop_ub;
    int loop_ub;
    int maxmn;
    int minmn;
    int rankA;
    int u0;
    e_A.set_size(A.size(0), 8);
    loop_ub = A.size(0);
    if ((static_cast<int>((A.size(0) * 8) < 4)) != 0) {
      for (int i2{0}; i2 < 8; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          e_A[i3 + (e_A.size(0) * i2)] = A[i3 + (A.size(0) * i2)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 8; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          e_A[i3 + (e_A.size(0) * i2)] = A[i3 + (A.size(0) * i2)];
        }
      }
    }
    internal::lapack::b_xgeqp3(e_A, tau, jpvt);
    rankA = 0;
    if (e_A.size(0) < 8) {
      minmn = e_A.size(0);
      maxmn = 8;
    } else {
      minmn = 8;
      maxmn = e_A.size(0);
    }
    if (minmn > 0) {
      double tol;
      bool exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(e_A[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(e_A[rankA + (e_A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    g_Y.set_size(c_B.size(0));
    c_loop_ub = c_B.size(0);
    if ((static_cast<int>(c_B.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 < c_loop_ub; b_i8++) {
        g_Y[b_i8] = c_B[b_i8];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 < c_loop_ub; b_i8++) {
        g_Y[b_i8] = c_B[b_i8];
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int g_i = 0; g_i < 8; g_i++) {
      j_Y[g_i] = 0.0;
    }
    b_m = e_A.size(0);
    u0 = e_A.size(0);
    if (u0 <= 8) {
      b_mn = u0;
    } else {
      b_mn = 8;
    }
    for (int c_j{0}; c_j < b_mn; c_j++) {
      if (tau[c_j] != 0.0) {
        double wj;
        int i13;
        wj = g_Y[c_j];
        i13 = c_j + 2;
        for (int m_i{i13}; m_i <= b_m; m_i++) {
          wj += e_A[(m_i + (e_A.size(0) * c_j)) - 1] * g_Y[m_i - 1];
        }
        wj *= tau[c_j];
        if (wj != 0.0) {
          g_Y[c_j] = g_Y[c_j] - wj;
          for (int t_i{i13}; t_i <= b_m; t_i++) {
            g_Y[t_i - 1] =
                g_Y[t_i - 1] - (e_A[(t_i + (e_A.size(0) * c_j)) - 1] * wj);
          }
        }
      }
    }
    for (int k_i{0}; k_i < rankA; k_i++) {
      j_Y[jpvt[k_i] - 1] = g_Y[k_i];
    }
    for (int d_j{rankA}; d_j >= 1; d_j--) {
      int b_Y_tmp;
      b_Y_tmp = jpvt[d_j - 1] - 1;
      j_Y[b_Y_tmp] /= e_A[(d_j + (e_A.size(0) * (d_j - 1))) - 1];
      for (int q_i{0}; q_i <= (d_j - 2); q_i++) {
        int i15;
        i15 = jpvt[q_i];
        j_Y[i15 - 1] -= j_Y[b_Y_tmp] * e_A[q_i + (e_A.size(0) * (d_j - 1))];
      }
    }
    g_Y.set_size(8);
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < 8; i14++) {
      g_Y[i14] = j_Y[i14];
    }
  }
  if (guard1) {
    g_Y.set_size(8);
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < 8; i1++) {
      g_Y[i1] = 0.0;
    }
  }
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
