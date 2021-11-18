//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &c_B
//                ::coder::array<double, 1U> &g_Y
// Return Type  : void
//
namespace coder {
void b_mldivide(const ::coder::array<double, 2U> &A,
                const ::coder::array<double, 1U> &c_B,
                ::coder::array<double, 1U> &g_Y)
{
  array<double, 2U> e_A;
  array<double, 1U> e_B;
  array<double, 1U> tau;
  array<int, 2U> ipiv;
  array<int, 2U> jpvt;
  bool guard1{false};
  guard1 = false;
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    guard1 = true;
  } else if (c_B.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == A.size(1)) {
    int LDA;
    int b_LDA;
    int b_u0;
    int b_u1;
    int c_u0;
    int d_loop_ub;
    int h_loop_ub;
    int h_n;
    int i7;
    int i_loop_ub;
    int ldap1;
    int u0;
    int y;
    int yk;
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
    LDA = A.size(0);
    e_A.set_size(A.size(0), A.size(1));
    d_loop_ub = A.size(1);
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      int f_loop_ub;
      f_loop_ub = A.size(0);
      for (int i5{0}; i5 < f_loop_ub; i5++) {
        e_A[i5 + (e_A.size(0) * i3)] = A[i5 + (A.size(0) * i3)];
      }
    }
    ipiv.set_size(1, h_n);
    ipiv[0] = 1;
    yk = 1;
    for (int k{2}; k <= h_n; k++) {
      yk++;
      ipiv[k - 1] = yk;
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
      int b_jj;
      int jA;
      int jp1j;
      int jy;
      int mmj_tmp;
      mmj_tmp = h_n - j;
      b = j * (LDA + 1);
      b_jj = j * (ldap1 + 1);
      jp1j = b + 2;
      if (mmj_tmp < 1) {
        b_a = -1;
      } else {
        b_a = 0;
        if (mmj_tmp > 1) {
          double smax;
          smax = std::abs(e_A[b_jj]);
          for (int c_k{2}; c_k <= mmj_tmp; c_k++) {
            double s;
            s = std::abs(e_A[(b + c_k) - 1]);
            if (s > smax) {
              b_a = c_k - 1;
              smax = s;
            }
          }
        }
      }
      if (e_A[b_jj + b_a] != 0.0) {
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
            temp_tmp = e_k * LDA;
            b_temp_tmp = j + temp_tmp;
            b_temp = e_A[b_temp_tmp];
            i16 = ipiv_tmp + temp_tmp;
            e_A[b_temp_tmp] = e_A[i16];
            e_A[i16] = b_temp;
          }
        }
        i12 = b_jj + mmj_tmp;
        for (int k_i{jp1j}; k_i <= i12; k_i++) {
          e_A[k_i - 1] = e_A[k_i - 1] / e_A[b_jj];
        }
      }
      jy = b + LDA;
      jA = b_jj + ldap1;
      for (int d_j{0}; d_j <= (mmj_tmp - 2); d_j++) {
        double yjy;
        int yjy_tmp;
        yjy_tmp = jy + (d_j * LDA);
        yjy = e_A[yjy_tmp];
        if (e_A[yjy_tmp] != 0.0) {
          int i15;
          int i17;
          i15 = jA + 2;
          i17 = mmj_tmp + jA;
          for (int ijA{i15}; ijA <= i17; ijA++) {
            e_A[ijA - 1] =
                e_A[ijA - 1] + (e_A[((b_jj + ijA) - jA) - 1] * (-yjy));
          }
        }
        jA += LDA;
      }
    }
    e_B.set_size(c_B.size(0));
    h_loop_ub = c_B.size(0);
    for (int i8{0}; i8 < h_loop_ub; i8++) {
      e_B[i8] = c_B[i8];
    }
    b_LDA = e_A.size(0);
    for (int e_i{0}; e_i <= (h_n - 2); e_i++) {
      int i11;
      i11 = ipiv[e_i];
      if (i11 != (e_i + 1)) {
        double temp;
        temp = e_B[e_i];
        e_B[e_i] = e_B[i11 - 1];
        e_B[i11 - 1] = temp;
      }
    }
    for (int b_k{0}; b_k < h_n; b_k++) {
      int kAcol;
      kAcol = b_LDA * b_k;
      if (e_B[b_k] != 0.0) {
        int i13;
        i13 = b_k + 2;
        for (int m_i{i13}; m_i <= h_n; m_i++) {
          e_B[m_i - 1] = e_B[m_i - 1] - (e_B[b_k] * e_A[(m_i + kAcol) - 1]);
        }
      }
    }
    for (int d_k{h_n}; d_k >= 1; d_k--) {
      double d;
      int b_kAcol;
      b_kAcol = b_LDA * (d_k - 1);
      d = e_B[d_k - 1];
      if (d != 0.0) {
        e_B[d_k - 1] = d / e_A[(d_k + b_kAcol) - 1];
        for (int q_i{0}; q_i <= (d_k - 2); q_i++) {
          e_B[q_i] = e_B[q_i] - (e_B[d_k - 1] * e_A[q_i + b_kAcol]);
        }
      }
    }
    g_Y.set_size(e_B.size(0));
    i_loop_ub = e_B.size(0);
    for (int i14{0}; i14 < i_loop_ub; i14++) {
      g_Y[i14] = e_B[i14];
    }
  } else {
    int b_mn;
    int c_u1;
    int d_u0;
    int e_loop_ub;
    int g_loop_ub;
    int loop_ub;
    int m;
    int maxmn;
    int minmn;
    int rankA;
    e_A.set_size(A.size(0), A.size(1));
    loop_ub = A.size(1);
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      int c_loop_ub;
      c_loop_ub = A.size(0);
      for (int i2{0}; i2 < c_loop_ub; i2++) {
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
    for (int i4{0}; i4 < e_loop_ub; i4++) {
      g_Y[i4] = 0.0;
    }
    e_B.set_size(c_B.size(0));
    g_loop_ub = c_B.size(0);
    for (int i6{0}; i6 < g_loop_ub; i6++) {
      e_B[i6] = c_B[i6];
    }
    m = e_A.size(0);
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
        wj = e_B[b_j];
        i9 = b_j + 2;
        for (int d_i{i9}; d_i <= m; d_i++) {
          wj += e_A[(d_i + (e_A.size(0) * b_j)) - 1] * e_B[d_i - 1];
        }
        wj *= tau[b_j];
        if (wj != 0.0) {
          e_B[b_j] = e_B[b_j] - wj;
          for (int h_i{i9}; h_i <= m; h_i++) {
            e_B[h_i - 1] =
                e_B[h_i - 1] - (e_A[(h_i + (e_A.size(0) * b_j)) - 1] * wj);
          }
        }
      }
    }
    for (int c_i{0}; c_i < rankA; c_i++) {
      g_Y[jpvt[c_i] - 1] = e_B[c_i];
    }
    for (int c_j{rankA}; c_j >= 1; c_j--) {
      int i10;
      i10 = jpvt[c_j - 1];
      g_Y[i10 - 1] = g_Y[i10 - 1] / e_A[(c_j + (e_A.size(0) * (c_j - 1))) - 1];
      for (int g_i{0}; g_i <= (c_j - 2); g_i++) {
        g_Y[jpvt[g_i] - 1] =
            g_Y[jpvt[g_i] - 1] -
            (g_Y[jpvt[c_j - 1] - 1] * e_A[g_i + (e_A.size(0) * (c_j - 1))]);
      }
    }
  }
  if (guard1) {
    int b_loop_ub;
    g_Y.set_size(A.size(1));
    b_loop_ub = A.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      g_Y[i1] = 0.0;
    }
  }
}

//
// Arguments    : const double A[3][3]
//                const double c_B[3]
//                double g_Y[3]
// Return Type  : void
//
void mldivide(const double A[3][3], const double c_B[3], double g_Y[3])
{
  double e_A[3][3];
  double a21;
  double maxval;
  int r1;
  int r2;
  int r3;
  for (int b_i{0}; b_i < 3; b_i++) {
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

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
