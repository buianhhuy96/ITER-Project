//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "svd1.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double A[29][29]
//                double U[29][29]
//                double s[29]
//                double V[29][29]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
void c_svd(const double A[29][29], double U[29][29], double s[29],
           double V[29][29])
{
  double j_A[29][29];
  double e[29];
  double work[29];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  double rt;
  double snorm;
  int b_iter;
  int c_i;
  int m;
  int qjj;
  int qp1;
  int qq;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i)

  for (int b_i = 0; b_i < 29; b_i++) {
    s[b_i] = 0.0;
    e[b_i] = 0.0;
    work[b_i] = 0.0;
    for (c_i = 0; c_i < 29; c_i++) {
      j_A[b_i][c_i] = A[b_i][c_i];
      U[b_i][c_i] = 0.0;
      V[b_i][c_i] = 0.0;
    }
  }
  for (int b_q{0}; b_q < 28; b_q++) {
    double nrm;
    bool apply_transform;
    qp1 = b_q + 2;
    qq = (b_q + (29 * b_q)) + 1;
    apply_transform = false;
    nrm = blas::c_xnrm2(29 - b_q, j_A, qq);
    if (nrm > 0.0) {
      double d;
      apply_transform = true;
      if ((&j_A[0][0])[qq - 1] < 0.0) {
        d = -nrm;
      } else {
        d = nrm;
      }
      s[b_q] = d;
      if (std::abs(d) >= 1.0020841800044864E-292) {
        double b_a;
        int i2;
        b_a = 1.0 / d;
        i2 = (qq - b_q) + 28;
        for (int b_k{qq}; b_k <= i2; b_k++) {
          (&j_A[0][0])[b_k - 1] *= b_a;
        }
      } else {
        int i1;
        i1 = (qq - b_q) + 28;
        for (int k{qq}; k <= i1; k++) {
          (&j_A[0][0])[k - 1] /= s[b_q];
        }
      }
      (&j_A[0][0])[qq - 1]++;
      s[b_q] = -s[b_q];
    } else {
      s[b_q] = 0.0;
    }
    for (int jj{qp1}; jj < 30; jj++) {
      qjj = b_q + (29 * (jj - 1));
      if (apply_transform) {
        blas::xaxpy(
            29 - b_q,
            -(blas::xdotc(29 - b_q, j_A, qq, j_A, qjj + 1) / j_A[b_q][b_q]), qq,
            j_A, qjj + 1);
      }
      e[jj - 1] = (&j_A[0][0])[qjj];
    }
    for (int e_ii{b_q + 1}; e_ii < 30; e_ii++) {
      U[b_q][e_ii - 1] = j_A[b_q][e_ii - 1];
    }
    if ((b_q + 1) <= 27) {
      nrm = blas::d_xnrm2(28 - b_q, e, b_q + 2);
      if (nrm == 0.0) {
        e[b_q] = 0.0;
      } else {
        double c_a;
        if (e[b_q + 1] < 0.0) {
          e[b_q] = -nrm;
        } else {
          e[b_q] = nrm;
        }
        c_a = e[b_q];
        if (std::abs(e[b_q]) >= 1.0020841800044864E-292) {
          double d_a;
          d_a = 1.0 / e[b_q];
          for (int d_k{qp1}; d_k < 30; d_k++) {
            e[d_k - 1] *= d_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 30; c_k++) {
            e[c_k - 1] /= c_a;
          }
        }
        e[b_q + 1]++;
        e[b_q] = -e[b_q];
        for (int q_ii{qp1}; q_ii < 30; q_ii++) {
          work[q_ii - 1] = 0.0;
        }
        for (int d_jj{qp1}; d_jj < 30; d_jj++) {
          blas::b_xaxpy(28 - b_q, e[d_jj - 1], j_A,
                        (b_q + (29 * (d_jj - 1))) + 2, work, b_q + 2);
        }
        for (int e_jj{qp1}; e_jj < 30; e_jj++) {
          blas::c_xaxpy(28 - b_q, (-e[e_jj - 1]) / e[b_q + 1], work, b_q + 2,
                        j_A, (b_q + (29 * (e_jj - 1))) + 2);
        }
      }
      for (int m_ii{qp1}; m_ii < 30; m_ii++) {
        V[b_q][m_ii - 1] = e[m_ii - 1];
      }
    }
  }
  m = 27;
  s[28] = j_A[28][28];
  e[27] = j_A[28][27];
  e[28] = 0.0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_ii = 0; c_ii < 29; c_ii++) {
    U[28][c_ii] = 0.0;
  }
  U[28][28] = 1.0;
  for (int c_q{27}; c_q >= 0; c_q--) {
    qp1 = c_q + 2;
    qq = c_q + (29 * c_q);
    if (s[c_q] != 0.0) {
      for (int b_jj{qp1}; b_jj < 30; b_jj++) {
        qjj = (c_q + (29 * (b_jj - 1))) + 1;
        blas::xaxpy(
            29 - c_q,
            -(blas::xdotc(29 - c_q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (int h_ii{c_q + 1}; h_ii < 30; h_ii++) {
        U[c_q][h_ii - 1] = -U[c_q][h_ii - 1];
      }
      (&U[0][0])[qq]++;
      for (int p_ii{0}; p_ii < c_q; p_ii++) {
        U[c_q][p_ii] = 0.0;
      }
    } else {
      for (int f_ii{0}; f_ii < 29; f_ii++) {
        U[c_q][f_ii] = 0.0;
      }
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (int d_q{28}; d_q >= 0; d_q--) {
    if (((d_q + 1) <= 27) && (e[d_q] != 0.0)) {
      int qp1q;
      qp1 = d_q + 2;
      qp1q = (d_q + (29 * d_q)) + 2;
      for (int c_jj{qp1}; c_jj < 30; c_jj++) {
        int qp1jj;
        qp1jj = (d_q + (29 * (c_jj - 1))) + 2;
        blas::xaxpy(
            28 - d_q,
            -(blas::xdotc(28 - d_q, V, qp1q, V, qp1jj) / (&V[0][0])[qp1q - 1]),
            qp1q, V, qp1jj);
      }
    }
    for (int g_ii{0}; g_ii < 29; g_ii++) {
      V[d_q][g_ii] = 0.0;
    }
    V[d_q][d_q] = 1.0;
  }
  b_iter = 0;
  snorm = 0.0;
  for (int e_q{0}; e_q < 29; e_q++) {
    double b_d1;
    double r;
    b_d1 = s[e_q];
    if (b_d1 != 0.0) {
      int i3;
      int ix0;
      rt = std::abs(b_d1);
      r = b_d1 / rt;
      s[e_q] = rt;
      if ((e_q + 1) < 29) {
        e[e_q] /= r;
      }
      ix0 = 29 * e_q;
      i3 = ix0 + 29;
      for (int e_k{ix0 + 1}; e_k <= i3; e_k++) {
        (&U[0][0])[e_k - 1] *= r;
      }
    }
    if ((e_q + 1) < 29) {
      double d2;
      d2 = e[e_q];
      if (d2 != 0.0) {
        int b_ix0;
        int i4;
        rt = std::abs(d2);
        r = rt / d2;
        e[e_q] = rt;
        s[e_q + 1] *= r;
        b_ix0 = 29 * (e_q + 1);
        i4 = b_ix0 + 29;
        for (int g_k{b_ix0 + 1}; g_k <= i4; g_k++) {
          (&V[0][0])[g_k - 1] *= r;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[e_q]), std::abs(e[e_q])));
  }
  while (((m + 2) > 0) && (b_iter < 75)) {
    int f_q;
    int kase;
    int o_ii;
    o_ii = m;
    int exitg1;
    do {
      exitg1 = 0;
      f_q = o_ii + 1;
      if ((o_ii + 1) == 0) {
        exitg1 = 1;
      } else {
        double ztest0;
        ztest0 = std::abs(e[o_ii]);
        if (ztest0 <= (2.2204460492503131E-16 *
                       (std::abs(s[o_ii]) + std::abs(s[o_ii + 1])))) {
          e[o_ii] = 0.0;
          exitg1 = 1;
        } else if ((ztest0 <= 1.0020841800044864E-292) ||
                   ((b_iter > 20) &&
                    (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
          e[o_ii] = 0.0;
          exitg1 = 1;
        } else {
          o_ii--;
        }
      }
    } while (exitg1 == 0);
    if ((o_ii + 1) == (m + 1)) {
      kase = 4;
    } else {
      int qs;
      int r_ii;
      bool exitg2;
      qs = m + 2;
      r_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (r_ii >= (o_ii + 1))) {
        qs = r_ii;
        if (r_ii == (o_ii + 1)) {
          exitg2 = true;
        } else {
          double test;
          double ztest;
          test = 0.0;
          if (r_ii < (m + 2)) {
            test = std::abs(e[r_ii - 1]);
          }
          if (r_ii > (o_ii + 2)) {
            test += std::abs(e[r_ii - 2]);
          }
          ztest = std::abs(s[r_ii - 1]);
          if ((ztest <= (2.2204460492503131E-16 * test)) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[r_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            r_ii--;
          }
        }
      }
      if (qs == (o_ii + 1)) {
        kase = 3;
      } else if (qs == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        f_q = qs;
      }
    }
    switch (kase) {
    case 1: {
      int i5;
      f = e[m];
      e[m] = 0.0;
      i5 = m + 1;
      for (int i_k{i5}; i_k >= (f_q + 1); i_k--) {
        blas::xrotg(&s[i_k - 1], &f, &b_cs, &b_sn);
        if (i_k > (f_q + 1)) {
          double b_f_tmp;
          b_f_tmp = e[i_k - 2];
          f = (-b_sn) * b_f_tmp;
          e[i_k - 2] = b_f_tmp * b_cs;
        }
        blas::xrot(V, (29 * (i_k - 1)) + 1, (29 * (m + 1)) + 1, b_cs, b_sn);
      }
    } break;
    case 2: {
      f = e[f_q - 1];
      e[f_q - 1] = 0.0;
      for (int h_k{f_q + 1}; h_k <= (m + 2); h_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[h_k - 1], &a__1, &c_cs, &c_sn);
        f_tmp = e[h_k - 1];
        f = (-c_sn) * f_tmp;
        e[h_k - 1] = f_tmp * c_cs;
        blas::xrot(U, (29 * (h_k - 1)) + 1, (29 * (f_q - 1)) + 1, c_cs, c_sn);
      }
    } break;
    case 3: {
      double b;
      double c;
      double emm1;
      double g;
      double scale;
      double scale_tmp;
      double shift;
      double sm;
      double smm1;
      double sqds;
      int mm1;
      mm1 = m + 1;
      scale_tmp = s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(scale_tmp), std::abs(s[m])),
                              std::abs(e[m])),
                    std::abs(s[f_q])),
          std::abs(e[f_q]));
      sm = scale_tmp / scale;
      smm1 = s[m] / scale;
      emm1 = e[m] / scale;
      sqds = s[f_q] / scale;
      b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
      c = sm * emm1;
      c *= c;
      if ((b != 0.0) || (c != 0.0)) {
        shift = std::sqrt((b * b) + c);
        if (b < 0.0) {
          shift = -shift;
        }
        shift = c / (b + shift);
      } else {
        shift = 0.0;
      }
      f = ((sqds + sm) * (sqds - sm)) + shift;
      g = sqds * (e[f_q] / scale);
      for (int k_k{f_q + 1}; k_k <= mm1; k_k++) {
        double c_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
        if (k_k > (f_q + 1)) {
          e[k_k - 2] = b_f;
        }
        f_tmp_tmp = e[k_k - 1];
        c_f_tmp = s[k_k - 1];
        e[k_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * c_f_tmp);
        a__3 = d_sn * s[k_k];
        s[k_k] *= d_cs;
        blas::xrot(V, (29 * (k_k - 1)) + 1, (29 * k_k) + 1, d_cs, d_sn);
        s[k_k - 1] = (d_cs * c_f_tmp) + (d_sn * f_tmp_tmp);
        blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &e_sn);
        f = (e_cs * e[k_k - 1]) + (e_sn * s[k_k]);
        s[k_k] = ((-e_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
        g = e_sn * e[k_k];
        e[k_k] *= e_cs;
        blas::xrot(U, (29 * (k_k - 1)) + 1, (29 * k_k) + 1, e_cs, e_sn);
      }
      e[m] = f;
      b_iter++;
    } break;
    default: {
      if (s[f_q] < 0.0) {
        int c_ix0;
        int i6;
        s[f_q] = -s[f_q];
        c_ix0 = 29 * f_q;
        i6 = c_ix0 + 29;
        for (int j_k{c_ix0 + 1}; j_k <= i6; j_k++) {
          (&V[0][0])[j_k - 1] = -(&V[0][0])[j_k - 1];
        }
      }
      qp1 = f_q + 1;
      while (((f_q + 1) < 29) && (s[f_q] < s[qp1])) {
        rt = s[f_q];
        s[f_q] = s[qp1];
        s[qp1] = rt;
        blas::xswap(V, (29 * f_q) + 1, (29 * (f_q + 1)) + 1);
        blas::xswap(U, (29 * f_q) + 1, (29 * (f_q + 1)) + 1);
        f_q = qp1;
        qp1++;
      }
      b_iter = 0;
      m--;
    } break;
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &U
// Return Type  : void
//
void d_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U)
{
  ::coder::array<double, 2U> j_A;
  ::coder::array<double, 1U> s;
  ::coder::array<double, 1U> work;
  double e[8];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  int b_loop_ub;
  int b_u0;
  int c_loop_ub;
  int c_u0;
  int h_n;
  int i1;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  int y;
  j_A.set_size(A.size(0), 8);
  loop_ub = A.size(0);
  if ((static_cast<int>((A.size(0) * 8) < 4)) != 0) {
    for (int b_i{0}; b_i < 8; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 8; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  }
  h_n = A.size(0);
  u0 = A.size(0);
  if (u0 <= 8) {
    minnp = u0;
  } else {
    minnp = 8;
  }
  b_u0 = A.size(0) + 1;
  if (b_u0 <= 8) {
    unnamed_idx_0 = b_u0;
  } else {
    unnamed_idx_0 = 8;
  }
  s.set_size(unnamed_idx_0);
  b_loop_ub = unnamed_idx_0;
  c_u0 = A.size(0) + 1;
  if (c_u0 <= 8) {
    y = c_u0;
  } else {
    y = 8;
  }
  if ((static_cast<int>(y < 4)) != 0) {
    for (int i2{0}; i2 < unnamed_idx_0; i2++) {
      s[i2] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      s[i2] = 0.0;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_i = 0; c_i < 8; c_i++) {
    e[c_i] = 0.0;
  }
  work.set_size(A.size(0));
  c_loop_ub = A.size(0);
  if ((static_cast<int>(A.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < c_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  }
  if (A.size(0) != 0) {
    double rt;
    double snorm;
    int b_iter;
    int b_u1;
    int d_u0;
    int i4;
    int m;
    int mm;
    int nct;
    int nrt;
    int qp1;
    b_u1 = A.size(0);
    if (6 <= b_u1) {
      nrt = 6;
    } else {
      nrt = b_u1;
    }
    d_u0 = A.size(0) - 1;
    if (d_u0 <= 8) {
      nct = d_u0;
    } else {
      nct = 8;
    }
    if (nct >= nrt) {
      i4 = nct;
    } else {
      i4 = nrt;
    }
    for (int b_q{0}; b_q < i4; b_q++) {
      double nrm;
      int nmq;
      int qq;
      bool apply_transform;
      qp1 = b_q + 2;
      qq = (b_q + (h_n * b_q)) + 1;
      nmq = (h_n - b_q) - 1;
      apply_transform = false;
      if ((b_q + 1) <= nct) {
        nrm = blas::b_xnrm2(nmq + 1, j_A, qq);
        if (nrm > 0.0) {
          double d;
          apply_transform = true;
          if (j_A[qq - 1] < 0.0) {
            d = -nrm;
          } else {
            d = nrm;
          }
          s[b_q] = d;
          if (std::abs(d) >= 1.0020841800044864E-292) {
            double b_a;
            int i6;
            b_a = 1.0 / d;
            i6 = qq + nmq;
            for (int e_k{qq}; e_k <= i6; e_k++) {
              j_A[e_k - 1] = b_a * j_A[e_k - 1];
            }
          } else {
            int i5;
            i5 = qq + nmq;
            for (int c_k{qq}; c_k <= i5; c_k++) {
              j_A[c_k - 1] = j_A[c_k - 1] / s[b_q];
            }
          }
          j_A[qq - 1] = j_A[qq - 1] + 1.0;
          s[b_q] = -s[b_q];
        } else {
          s[b_q] = 0.0;
        }
      }
      for (int jj{qp1}; jj < 9; jj++) {
        int qjj;
        qjj = b_q + (h_n * (jj - 1));
        if (apply_transform) {
          double b_t;
          b_t = 0.0;
          if ((nmq + 1) >= 1) {
            for (int b_k{0}; b_k <= nmq; b_k++) {
              b_t += j_A[(qq + b_k) - 1] * j_A[qjj + b_k];
            }
          }
          b_t = -(b_t / j_A[b_q + (j_A.size(0) * b_q)]);
          if (((nmq + 1) >= 1) && (!(b_t == 0.0))) {
            for (int d_k{0}; d_k <= nmq; d_k++) {
              int i7;
              i7 = qjj + d_k;
              j_A[i7] = j_A[i7] + (b_t * j_A[(qq + d_k) - 1]);
            }
          }
        }
        e[jj - 1] = j_A[qjj];
      }
      if ((b_q + 1) <= nrt) {
        nrm = blas::e_xnrm2(7 - b_q, e, b_q + 2);
        if (nrm == 0.0) {
          e[b_q] = 0.0;
        } else {
          double c_a;
          if (e[b_q + 1] < 0.0) {
            e[b_q] = -nrm;
          } else {
            e[b_q] = nrm;
          }
          c_a = e[b_q];
          if (std::abs(e[b_q]) >= 1.0020841800044864E-292) {
            double d_a;
            d_a = 1.0 / e[b_q];
            for (int h_k{qp1}; h_k < 9; h_k++) {
              e[h_k - 1] *= d_a;
            }
          } else {
            for (int g_k{qp1}; g_k < 9; g_k++) {
              e[g_k - 1] /= c_a;
            }
          }
          e[b_q + 1]++;
          e[b_q] = -e[b_q];
          if ((b_q + 2) <= h_n) {
            for (int e_ii{qp1}; e_ii <= h_n; e_ii++) {
              work[e_ii - 1] = 0.0;
            }
            for (int b_jj{qp1}; b_jj < 9; b_jj++) {
              blas::d_xaxpy(nmq, e[b_jj - 1], j_A,
                            (b_q + (h_n * (b_jj - 1))) + 2, work, b_q + 2);
            }
            for (int c_jj{qp1}; c_jj < 9; c_jj++) {
              blas::e_xaxpy(nmq, (-e[c_jj - 1]) / e[b_q + 1], work, b_q + 2,
                            j_A, (b_q + (h_n * (c_jj - 1))) + 2);
            }
          }
        }
      }
    }
    if (8 <= (A.size(0) + 1)) {
      m = 7;
    } else {
      m = A.size(0);
    }
    if (nct < 8) {
      s[nct] = j_A[nct + (j_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = j_A[nrt + (j_A.size(0) * m)];
    }
    e[m] = 0.0;
    mm = m;
    b_iter = 0;
    snorm = 0.0;
    for (int c_q{0}; c_q <= m; c_q++) {
      double b_d1;
      double r;
      b_d1 = s[c_q];
      if (s[c_q] != 0.0) {
        rt = std::abs(s[c_q]);
        r = s[c_q] / rt;
        b_d1 = rt;
        s[c_q] = rt;
        if ((c_q + 1) < (m + 1)) {
          e[c_q] /= r;
        }
      }
      if (((c_q + 1) < (m + 1)) && (e[c_q] != 0.0)) {
        rt = std::abs(e[c_q]);
        r = rt / e[c_q];
        e[c_q] = rt;
        s[c_q + 1] = s[c_q + 1] * r;
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(b_d1), std::abs(e[c_q])));
    }
    while (((m + 1) > 0) && (b_iter < 75)) {
      int c_ii;
      int d_q;
      int kase;
      bool exitg2;
      c_ii = m;
      int exitg1;
      do {
        exitg1 = 0;
        d_q = c_ii;
        if (c_ii == 0) {
          exitg1 = 1;
        } else {
          double ztest0;
          ztest0 = std::abs(e[c_ii - 1]);
          if (ztest0 <= (2.2204460492503131E-16 *
                         (std::abs(s[c_ii - 1]) + std::abs(s[c_ii])))) {
            e[c_ii - 1] = 0.0;
            exitg1 = 1;
          } else if ((ztest0 <= 1.0020841800044864E-292) ||
                     ((b_iter > 20) &&
                      (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
            e[c_ii - 1] = 0.0;
            exitg1 = 1;
          } else {
            c_ii--;
          }
        }
      } while (exitg1 == 0);
      if (c_ii == m) {
        kase = 4;
      } else {
        int f_ii;
        int qs;
        qs = m + 1;
        f_ii = m + 1;
        exitg2 = false;
        while ((!exitg2) && (f_ii >= c_ii)) {
          qs = f_ii;
          if (f_ii == c_ii) {
            exitg2 = true;
          } else {
            double test;
            double ztest;
            test = 0.0;
            if (f_ii < (m + 1)) {
              test = std::abs(e[f_ii - 1]);
            }
            if (f_ii > (c_ii + 1)) {
              test += std::abs(e[f_ii - 2]);
            }
            ztest = std::abs(s[f_ii - 1]);
            if ((ztest <= (2.2204460492503131E-16 * test)) ||
                (ztest <= 1.0020841800044864E-292)) {
              s[f_ii - 1] = 0.0;
              exitg2 = true;
            } else {
              f_ii--;
            }
          }
        }
        if (qs == c_ii) {
          kase = 3;
        } else if (qs == (m + 1)) {
          kase = 1;
        } else {
          kase = 2;
          d_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (int i_k{m}; i_k >= (d_q + 1); i_k--) {
          blas::xrotg(&s[i_k - 1], &f, &b_cs, &b_sn);
          if (i_k > (d_q + 1)) {
            double f_tmp;
            f_tmp = e[i_k - 2];
            f = (-b_sn) * f_tmp;
            e[i_k - 2] = f_tmp * b_cs;
          }
        }
      } break;
      case 2: {
        f = e[d_q - 1];
        e[d_q - 1] = 0.0;
        for (int j_k{d_q + 1}; j_k <= (m + 1); j_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[j_k - 1], &a__1, &c_cs, &c_sn);
          b_f_tmp = e[j_k - 1];
          f = (-c_sn) * b_f_tmp;
          e[j_k - 1] = b_f_tmp * c_cs;
        }
      } break;
      case 3: {
        double b;
        double b_scale_tmp;
        double c;
        double emm1;
        double g;
        double scale;
        double scale_tmp;
        double shift;
        double sm;
        double smm1;
        double sqds;
        scale_tmp = s[m - 1];
        b_scale_tmp = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s[m]), std::abs(scale_tmp)),
                                std::abs(b_scale_tmp)),
                      std::abs(s[d_q])),
            std::abs(e[d_q]));
        sm = s[m] / scale;
        smm1 = scale_tmp / scale;
        emm1 = b_scale_tmp / scale;
        sqds = s[d_q] / scale;
        b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
        c = sm * emm1;
        c *= c;
        if ((b != 0.0) || (c != 0.0)) {
          shift = std::sqrt((b * b) + c);
          if (b < 0.0) {
            shift = -shift;
          }
          shift = c / (b + shift);
        } else {
          shift = 0.0;
        }
        f = ((sqds + sm) * (sqds - sm)) + shift;
        g = sqds * (e[d_q] / scale);
        for (int k_k{d_q + 1}; k_k <= m; k_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
          if (k_k > (d_q + 1)) {
            e[k_k - 2] = b_f;
          }
          f_tmp_tmp = e[k_k - 1];
          c_f_tmp = s[k_k - 1];
          e[k_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * c_f_tmp);
          a__3 = d_sn * s[k_k];
          s[k_k] = s[k_k] * d_cs;
          s[k_k - 1] = (d_cs * c_f_tmp) + (d_sn * f_tmp_tmp);
          blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &e_sn);
          f = (e_cs * e[k_k - 1]) + (e_sn * s[k_k]);
          s[k_k] = ((-e_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
          g = e_sn * e[k_k];
          e[k_k] *= e_cs;
        }
        e[m - 1] = f;
        b_iter++;
      } break;
      default:
        if (s[d_q] < 0.0) {
          s[d_q] = -s[d_q];
        }
        qp1 = d_q + 1;
        exitg2 = false;
        while ((!exitg2) && ((d_q + 1) < (mm + 1))) {
          if (s[d_q] < s[qp1]) {
            rt = s[d_q];
            s[d_q] = s[qp1];
            s[qp1] = rt;
            d_q = qp1;
            qp1++;
          } else {
            exitg2 = true;
          }
        }
        b_iter = 0;
        m--;
        break;
      }
    }
  }
  U.set_size(minnp);
  if ((static_cast<int>(minnp < 4)) != 0) {
    for (int k{0}; k < minnp; k++) {
      U[k] = s[k];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < minnp; k++) {
      U[k] = s[k];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &U
//                ::coder::array<double, 1U> &s
//                double V[6][6]
// Return Type  : void
//
void e_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           ::coder::array<double, 1U> &s, double V[6][6])
{
  ::coder::array<double, 2U> j_A;
  ::coder::array<double, 1U> c_S;
  ::coder::array<double, 1U> work;
  double e[6];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  int b_iv[2];
  int b_loop_ub;
  int b_u0;
  int c_loop_ub;
  int c_u0;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int h_n;
  int i1;
  int i6;
  int i7;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  int y;
  j_A.set_size(A.size(0), 6);
  loop_ub = A.size(0);
  if ((static_cast<int>((6 * A.size(0)) < 4)) != 0) {
    for (int b_i{0}; b_i < 6; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 6; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  }
  h_n = A.size(0);
  u0 = A.size(0);
  if (u0 <= 6) {
    minnp = u0;
  } else {
    minnp = 6;
  }
  b_u0 = A.size(0) + 1;
  if (b_u0 <= 6) {
    unnamed_idx_0 = b_u0;
  } else {
    unnamed_idx_0 = 6;
  }
  s.set_size(unnamed_idx_0);
  b_loop_ub = unnamed_idx_0;
  c_u0 = A.size(0) + 1;
  if (c_u0 <= 6) {
    y = c_u0;
  } else {
    y = 6;
  }
  if ((static_cast<int>(y < 4)) != 0) {
    for (int i2{0}; i2 < unnamed_idx_0; i2++) {
      s[i2] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      s[i2] = 0.0;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_i = 0; c_i < 6; c_i++) {
    e[c_i] = 0.0;
  }
  work.set_size(A.size(0));
  c_loop_ub = A.size(0);
  if ((static_cast<int>(A.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < c_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  }
  b_iv[0] = A.size(0);
  U.set_size(A.size(0), A.size(0));
  d_loop_ub = A.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    e_loop_ub)

  for (int i4 = 0; i4 < d_loop_ub; i4++) {
    e_loop_ub = b_iv[0];
    for (i6 = 0; i6 < e_loop_ub; i6++) {
      U[i6 + (U.size(0) * i4)] = 0.0;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

  for (int i5 = 0; i5 < 6; i5++) {
    for (i7 = 0; i7 < 6; i7++) {
      V[i5][i7] = 0.0;
    }
  }
  if (A.size(0) == 0) {
    for (int c_ii{0}; c_ii < 6; c_ii++) {
      V[c_ii][c_ii] = 1.0;
    }
  } else {
    double b_t;
    double rt;
    double snorm;
    int b_i8;
    int b_iter;
    int b_u1;
    int d_u0;
    int m;
    int mm;
    int nct;
    int nctp1;
    int nrt;
    int qjj;
    int qp1;
    int qq;
    b_u1 = A.size(0);
    if (4 <= b_u1) {
      nrt = 4;
    } else {
      nrt = b_u1;
    }
    d_u0 = A.size(0) - 1;
    if (d_u0 <= 6) {
      nct = d_u0;
    } else {
      nct = 6;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      b_i8 = nct;
    } else {
      b_i8 = nrt;
    }
    for (int b_q{0}; b_q < b_i8; b_q++) {
      double nrm;
      int nmq;
      bool apply_transform;
      qp1 = b_q + 2;
      qq = (b_q + (h_n * b_q)) + 1;
      nmq = (h_n - b_q) - 1;
      apply_transform = false;
      if ((b_q + 1) <= nct) {
        nrm = blas::b_xnrm2(nmq + 1, j_A, qq);
        if (nrm > 0.0) {
          double d;
          apply_transform = true;
          if (j_A[qq - 1] < 0.0) {
            d = -nrm;
          } else {
            d = nrm;
          }
          s[b_q] = d;
          if (std::abs(d) >= 1.0020841800044864E-292) {
            double b_a;
            int i11;
            b_a = 1.0 / d;
            i11 = qq + nmq;
            for (int e_k{qq}; e_k <= i11; e_k++) {
              j_A[e_k - 1] = b_a * j_A[e_k - 1];
            }
          } else {
            int i10;
            i10 = qq + nmq;
            for (int c_k{qq}; c_k <= i10; c_k++) {
              j_A[c_k - 1] = j_A[c_k - 1] / s[b_q];
            }
          }
          j_A[qq - 1] = j_A[qq - 1] + 1.0;
          s[b_q] = -s[b_q];
        } else {
          s[b_q] = 0.0;
        }
      }
      for (int jj{qp1}; jj < 7; jj++) {
        qjj = b_q + (h_n * (jj - 1));
        if (apply_transform) {
          b_t = 0.0;
          if ((nmq + 1) >= 1) {
            for (int b_k{0}; b_k <= nmq; b_k++) {
              b_t += j_A[(qq + b_k) - 1] * j_A[qjj + b_k];
            }
          }
          b_t = -(b_t / j_A[b_q + (j_A.size(0) * b_q)]);
          if (((nmq + 1) >= 1) && (!(b_t == 0.0))) {
            for (int d_k{0}; d_k <= nmq; d_k++) {
              int i12;
              i12 = qjj + d_k;
              j_A[i12] = j_A[i12] + (b_t * j_A[(qq + d_k) - 1]);
            }
          }
        }
        e[jj - 1] = j_A[qjj];
      }
      if ((b_q + 1) <= nct) {
        for (int e_ii{b_q + 1}; e_ii <= h_n; e_ii++) {
          U[(e_ii + (U.size(0) * b_q)) - 1] =
              j_A[(e_ii + (j_A.size(0) * b_q)) - 1];
        }
      }
      if ((b_q + 1) <= nrt) {
        nrm = blas::f_xnrm2(5 - b_q, e, b_q + 2);
        if (nrm == 0.0) {
          e[b_q] = 0.0;
        } else {
          double c_a;
          if (e[b_q + 1] < 0.0) {
            e[b_q] = -nrm;
          } else {
            e[b_q] = nrm;
          }
          c_a = e[b_q];
          if (std::abs(e[b_q]) >= 1.0020841800044864E-292) {
            double d_a;
            d_a = 1.0 / e[b_q];
            for (int h_k{qp1}; h_k < 7; h_k++) {
              e[h_k - 1] *= d_a;
            }
          } else {
            for (int g_k{qp1}; g_k < 7; g_k++) {
              e[g_k - 1] /= c_a;
            }
          }
          e[b_q + 1]++;
          e[b_q] = -e[b_q];
          if ((b_q + 2) <= h_n) {
            for (int r_ii{qp1}; r_ii <= h_n; r_ii++) {
              work[r_ii - 1] = 0.0;
            }
            for (int e_jj{qp1}; e_jj < 7; e_jj++) {
              blas::d_xaxpy(nmq, e[e_jj - 1], j_A,
                            (b_q + (h_n * (e_jj - 1))) + 2, work, b_q + 2);
            }
            for (int f_jj{qp1}; f_jj < 7; f_jj++) {
              blas::e_xaxpy(nmq, (-e[f_jj - 1]) / e[b_q + 1], work, b_q + 2,
                            j_A, (b_q + (h_n * (f_jj - 1))) + 2);
            }
          }
        }
        for (int g_ii{qp1}; g_ii < 7; g_ii++) {
          V[b_q][g_ii - 1] = e[g_ii - 1];
        }
      }
    }
    if (6 <= (A.size(0) + 1)) {
      m = 5;
    } else {
      m = A.size(0);
    }
    if (nct < 6) {
      s[nct] = j_A[nct + (j_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = j_A[nrt + (j_A.size(0) * m)];
    }
    e[m] = 0.0;
    if ((nct + 1) <= A.size(0)) {
      for (int b_jj{nctp1}; b_jj <= h_n; b_jj++) {
        for (int f_ii{0}; f_ii < h_n; f_ii++) {
          U[f_ii + (U.size(0) * (b_jj - 1))] = 0.0;
        }
        U[(b_jj + (U.size(0) * (b_jj - 1))) - 1] = 1.0;
      }
    }
    for (int c_q{nct}; c_q >= 1; c_q--) {
      int nmq_tmp;
      qp1 = c_q + 1;
      nmq_tmp = h_n - c_q;
      qq = (c_q + (h_n * (c_q - 1))) - 1;
      if (s[c_q - 1] != 0.0) {
        for (int c_jj{qp1}; c_jj <= h_n; c_jj++) {
          qjj = c_q + (h_n * (c_jj - 1));
          b_t = 0.0;
          if ((nmq_tmp + 1) >= 1) {
            for (int i_k{0}; i_k <= nmq_tmp; i_k++) {
              b_t += U[qq + i_k] * U[(qjj + i_k) - 1];
            }
          }
          b_t = -(b_t / U[qq]);
          blas::f_xaxpy(nmq_tmp + 1, b_t, qq + 1, U, qjj);
        }
        for (int o_ii{c_q}; o_ii <= h_n; o_ii++) {
          U[(o_ii + (U.size(0) * (c_q - 1))) - 1] =
              -U[(o_ii + (U.size(0) * (c_q - 1))) - 1];
        }
        U[qq] = U[qq] + 1.0;
        for (int q_ii{0}; q_ii <= (c_q - 2); q_ii++) {
          U[q_ii + (U.size(0) * (c_q - 1))] = 0.0;
        }
      } else {
        for (int m_ii{0}; m_ii < h_n; m_ii++) {
          U[m_ii + (U.size(0) * (c_q - 1))] = 0.0;
        }
        U[qq] = 1.0;
      }
    }
    for (int d_q{5}; d_q >= 0; d_q--) {
      if (((d_q + 1) <= nrt) && (e[d_q] != 0.0)) {
        int qp1q;
        qp1 = d_q + 2;
        qp1q = (d_q + (6 * d_q)) + 2;
        for (int d_jj{qp1}; d_jj < 7; d_jj++) {
          int qp1jj;
          qp1jj = (d_q + (6 * (d_jj - 1))) + 2;
          blas::g_xaxpy(5 - d_q,
                        -(blas::b_xdotc(5 - d_q, V, qp1q, V, qp1jj) /
                          (&V[0][0])[qp1q - 1]),
                        qp1q, V, qp1jj);
        }
      }
      for (int h_ii{0}; h_ii < 6; h_ii++) {
        V[d_q][h_ii] = 0.0;
      }
      V[d_q][d_q] = 1.0;
    }
    mm = m;
    b_iter = 0;
    snorm = 0.0;
    for (int e_q{0}; e_q <= m; e_q++) {
      double r;
      if (s[e_q] != 0.0) {
        rt = std::abs(s[e_q]);
        r = s[e_q] / rt;
        s[e_q] = rt;
        if ((e_q + 1) < (m + 1)) {
          e[e_q] /= r;
        }
        if ((e_q + 1) <= h_n) {
          int i13;
          int ix0;
          ix0 = h_n * e_q;
          i13 = ix0 + h_n;
          for (int j_k{ix0 + 1}; j_k <= i13; j_k++) {
            U[j_k - 1] = r * U[j_k - 1];
          }
        }
      }
      if ((e_q + 1) < (m + 1)) {
        double b_d1;
        b_d1 = e[e_q];
        if (b_d1 != 0.0) {
          int b_ix0;
          int i14;
          rt = std::abs(b_d1);
          r = rt / b_d1;
          e[e_q] = rt;
          s[e_q + 1] = s[e_q + 1] * r;
          b_ix0 = 6 * (e_q + 1);
          i14 = b_ix0 + 6;
          for (int k_k{b_ix0 + 1}; k_k <= i14; k_k++) {
            (&V[0][0])[k_k - 1] *= r;
          }
        }
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(s[e_q]), std::abs(e[e_q])));
    }
    while (((m + 1) > 0) && (b_iter < 75)) {
      int f_q;
      int kase;
      int p_ii;
      bool exitg2;
      p_ii = m;
      int exitg1;
      do {
        exitg1 = 0;
        f_q = p_ii;
        if (p_ii == 0) {
          exitg1 = 1;
        } else {
          double ztest0;
          ztest0 = std::abs(e[p_ii - 1]);
          if (ztest0 <= (2.2204460492503131E-16 *
                         (std::abs(s[p_ii - 1]) + std::abs(s[p_ii])))) {
            e[p_ii - 1] = 0.0;
            exitg1 = 1;
          } else if ((ztest0 <= 1.0020841800044864E-292) ||
                     ((b_iter > 20) &&
                      (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
            e[p_ii - 1] = 0.0;
            exitg1 = 1;
          } else {
            p_ii--;
          }
        }
      } while (exitg1 == 0);
      if (p_ii == m) {
        kase = 4;
      } else {
        int qs;
        int s_ii;
        qs = m + 1;
        s_ii = m + 1;
        exitg2 = false;
        while ((!exitg2) && (s_ii >= p_ii)) {
          qs = s_ii;
          if (s_ii == p_ii) {
            exitg2 = true;
          } else {
            double test;
            double ztest;
            test = 0.0;
            if (s_ii < (m + 1)) {
              test = std::abs(e[s_ii - 1]);
            }
            if (s_ii > (p_ii + 1)) {
              test += std::abs(e[s_ii - 2]);
            }
            ztest = std::abs(s[s_ii - 1]);
            if ((ztest <= (2.2204460492503131E-16 * test)) ||
                (ztest <= 1.0020841800044864E-292)) {
              s[s_ii - 1] = 0.0;
              exitg2 = true;
            } else {
              s_ii--;
            }
          }
        }
        if (qs == p_ii) {
          kase = 3;
        } else if (qs == (m + 1)) {
          kase = 1;
        } else {
          kase = 2;
          f_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (int m_k{m}; m_k >= (f_q + 1); m_k--) {
          blas::xrotg(&s[m_k - 1], &f, &b_cs, &b_sn);
          if (m_k > (f_q + 1)) {
            double f_tmp;
            f_tmp = e[m_k - 2];
            f = (-b_sn) * f_tmp;
            e[m_k - 2] = f_tmp * b_cs;
          }
          blas::b_xrot(V, (6 * (m_k - 1)) + 1, (6 * m) + 1, b_cs, b_sn);
        }
      } break;
      case 2: {
        f = e[f_q - 1];
        e[f_q - 1] = 0.0;
        for (int o_k{f_q + 1}; o_k <= (m + 1); o_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[o_k - 1], &a__1, &c_cs, &c_sn);
          b_f_tmp = e[o_k - 1];
          f = (-c_sn) * b_f_tmp;
          e[o_k - 1] = b_f_tmp * c_cs;
          if (h_n >= 1) {
            int b_iy;
            int c_ix;
            c_ix = h_n * (o_k - 1);
            b_iy = h_n * (f_q - 1);
            for (int q_k{0}; q_k < h_n; q_k++) {
              double temp;
              int b_temp_tmp;
              int temp_tmp;
              temp_tmp = b_iy + q_k;
              b_temp_tmp = c_ix + q_k;
              temp = (c_cs * U[b_temp_tmp]) + (c_sn * U[temp_tmp]);
              U[temp_tmp] = (c_cs * U[temp_tmp]) - (c_sn * U[b_temp_tmp]);
              U[b_temp_tmp] = temp;
            }
          }
        }
      } break;
      case 3: {
        double b;
        double b_scale_tmp;
        double c;
        double emm1;
        double g;
        double scale;
        double scale_tmp;
        double shift;
        double sm;
        double smm1;
        double sqds;
        scale_tmp = s[m - 1];
        b_scale_tmp = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s[m]), std::abs(scale_tmp)),
                                std::abs(b_scale_tmp)),
                      std::abs(s[f_q])),
            std::abs(e[f_q]));
        sm = s[m] / scale;
        smm1 = scale_tmp / scale;
        emm1 = b_scale_tmp / scale;
        sqds = s[f_q] / scale;
        b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
        c = sm * emm1;
        c *= c;
        if ((b != 0.0) || (c != 0.0)) {
          shift = std::sqrt((b * b) + c);
          if (b < 0.0) {
            shift = -shift;
          }
          shift = c / (b + shift);
        } else {
          shift = 0.0;
        }
        f = ((sqds + sm) * (sqds - sm)) + shift;
        g = sqds * (e[f_q] / scale);
        for (int s_k{f_q + 1}; s_k <= m; s_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
          if (s_k > (f_q + 1)) {
            e[s_k - 2] = b_f;
          }
          f_tmp_tmp = e[s_k - 1];
          c_f_tmp = s[s_k - 1];
          e[s_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * c_f_tmp);
          a__3 = d_sn * s[s_k];
          s[s_k] = s[s_k] * d_cs;
          blas::b_xrot(V, (6 * (s_k - 1)) + 1, (6 * s_k) + 1, d_cs, d_sn);
          s[s_k - 1] = (d_cs * c_f_tmp) + (d_sn * f_tmp_tmp);
          blas::xrotg(&s[s_k - 1], &a__3, &e_cs, &e_sn);
          f = (e_cs * e[s_k - 1]) + (e_sn * s[s_k]);
          s[s_k] = ((-e_sn) * e[s_k - 1]) + (e_cs * s[s_k]);
          g = e_sn * e[s_k];
          e[s_k] *= e_cs;
          if ((s_k < h_n) && (h_n >= 1)) {
            int d_iy;
            int e_ix;
            e_ix = h_n * (s_k - 1);
            d_iy = h_n * s_k;
            for (int t_k{0}; t_k < h_n; t_k++) {
              double c_temp;
              int d_temp_tmp;
              int e_temp_tmp;
              d_temp_tmp = d_iy + t_k;
              e_temp_tmp = e_ix + t_k;
              c_temp = (e_cs * U[e_temp_tmp]) + (e_sn * U[d_temp_tmp]);
              U[d_temp_tmp] = (e_cs * U[d_temp_tmp]) - (e_sn * U[e_temp_tmp]);
              U[e_temp_tmp] = c_temp;
            }
          }
        }
        e[m - 1] = f;
        b_iter++;
      } break;
      default: {
        if (s[f_q] < 0.0) {
          int c_ix0;
          int i15;
          s[f_q] = -s[f_q];
          c_ix0 = 6 * f_q;
          i15 = c_ix0 + 6;
          for (int p_k{c_ix0 + 1}; p_k <= i15; p_k++) {
            (&V[0][0])[p_k - 1] = -(&V[0][0])[p_k - 1];
          }
        }
        qp1 = f_q + 1;
        exitg2 = false;
        while ((!exitg2) && ((f_q + 1) < (mm + 1))) {
          if (s[f_q] < s[qp1]) {
            rt = s[f_q];
            s[f_q] = s[qp1];
            s[qp1] = rt;
            if ((f_q + 1) < 6) {
              blas::b_xswap(V, (6 * f_q) + 1, (6 * (f_q + 1)) + 1);
            }
            if ((f_q + 1) < h_n) {
              int c_iy;
              int d_ix;
              d_ix = h_n * f_q;
              c_iy = h_n * (f_q + 1);
              for (int r_k{0}; r_k < h_n; r_k++) {
                double b_temp;
                int c_temp_tmp;
                int i16;
                c_temp_tmp = d_ix + r_k;
                b_temp = U[c_temp_tmp];
                i16 = c_iy + r_k;
                U[c_temp_tmp] = U[i16];
                U[i16] = b_temp;
              }
            }
            f_q = qp1;
            qp1++;
          } else {
            exitg2 = true;
          }
        }
        b_iter = 0;
        m--;
      } break;
      }
    }
  }
  c_S.set_size(minnp);
  if ((static_cast<int>(minnp < 4)) != 0) {
    for (int k{0}; k < minnp; k++) {
      c_S[k] = s[k];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < minnp; k++) {
      c_S[k] = s[k];
    }
  }
  s.set_size(c_S.size(0));
  f_loop_ub = c_S.size(0);
  if ((static_cast<int>(c_S.size(0) < 4)) != 0) {
    for (int i9{0}; i9 < f_loop_ub; i9++) {
      s[i9] = c_S[i9];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i9 = 0; i9 < f_loop_ub; i9++) {
      s[i9] = c_S[i9];
    }
  }
}

//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double s[3]
//                double V[3][3]
// Return Type  : void
//
void f_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3])
{
  double j_A[3][3];
  double e[3];
  double work[3];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  double rt;
  double snorm;
  int b_iter;
  int m;
  int qjj;
  int qp1;
  int qq;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    s[b_i] = 0.0;
    e[b_i] = 0.0;
    work[b_i] = 0.0;
    j_A[b_i][0] = A[b_i][0];
    U[b_i][0] = 0.0;
    V[b_i][0] = 0.0;
    j_A[b_i][1] = A[b_i][1];
    U[b_i][1] = 0.0;
    V[b_i][1] = 0.0;
    j_A[b_i][2] = A[b_i][2];
    U[b_i][2] = 0.0;
    V[b_i][2] = 0.0;
  }
  for (int b_q{0}; b_q < 2; b_q++) {
    double nrm;
    bool apply_transform;
    qp1 = b_q + 2;
    qq = (b_q + (3 * b_q)) + 1;
    apply_transform = false;
    nrm = blas::g_xnrm2(3 - b_q, j_A, qq);
    if (nrm > 0.0) {
      double d;
      apply_transform = true;
      if ((&j_A[0][0])[qq - 1] < 0.0) {
        d = -nrm;
      } else {
        d = nrm;
      }
      s[b_q] = d;
      if (std::abs(d) >= 1.0020841800044864E-292) {
        double b_a;
        int i1;
        b_a = 1.0 / d;
        i1 = (qq - b_q) + 2;
        for (int b_k{qq}; b_k <= i1; b_k++) {
          (&j_A[0][0])[b_k - 1] *= b_a;
        }
      } else {
        int c_i;
        c_i = (qq - b_q) + 2;
        for (int k{qq}; k <= c_i; k++) {
          (&j_A[0][0])[k - 1] /= s[b_q];
        }
      }
      (&j_A[0][0])[qq - 1]++;
      s[b_q] = -s[b_q];
    } else {
      s[b_q] = 0.0;
    }
    for (int jj{qp1}; jj < 4; jj++) {
      qjj = b_q + (3 * (jj - 1));
      if (apply_transform) {
        blas::h_xaxpy(
            3 - b_q,
            -(blas::c_xdotc(3 - b_q, j_A, qq, j_A, qjj + 1) / j_A[b_q][b_q]),
            qq, j_A, qjj + 1);
      }
      e[jj - 1] = (&j_A[0][0])[qjj];
    }
    for (int c_ii{b_q + 1}; c_ii < 4; c_ii++) {
      U[b_q][c_ii - 1] = j_A[b_q][c_ii - 1];
    }
    if ((b_q + 1) <= 1) {
      nrm = blas::o_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        double c_a;
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        c_a = e[0];
        if (std::abs(e[0]) >= 1.0020841800044864E-292) {
          double d_a;
          d_a = 1.0 / e[0];
          for (int d_k{qp1}; d_k < 4; d_k++) {
            e[d_k - 1] *= d_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 4; c_k++) {
            e[c_k - 1] /= c_a;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (int h_ii{qp1}; h_ii < 4; h_ii++) {
          work[h_ii - 1] = 0.0;
        }
        for (int c_jj{qp1}; c_jj < 4; c_jj++) {
          blas::m_xaxpy(e[c_jj - 1], j_A, (3 * (c_jj - 1)) + 2, work);
        }
        for (int d_jj{qp1}; d_jj < 4; d_jj++) {
          blas::o_xaxpy((-e[d_jj - 1]) / e[1], work, j_A, (3 * (d_jj - 1)) + 2);
        }
      }
      for (int f_ii{qp1}; f_ii < 4; f_ii++) {
        V[0][f_ii - 1] = e[f_ii - 1];
      }
    }
  }
  m = 1;
  s[2] = j_A[2][2];
  e[1] = j_A[2][1];
  e[2] = 0.0;
  U[2][0] = 0.0;
  U[2][1] = 0.0;
  U[2][2] = 1.0;
  for (int c_q{1}; c_q >= 0; c_q--) {
    qp1 = c_q + 2;
    qq = c_q + (3 * c_q);
    if (s[c_q] != 0.0) {
      for (int b_jj{qp1}; b_jj < 4; b_jj++) {
        qjj = (c_q + (3 * (b_jj - 1))) + 1;
        blas::h_xaxpy(
            3 - c_q,
            -(blas::c_xdotc(3 - c_q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (int e_ii{c_q + 1}; e_ii < 4; e_ii++) {
        U[c_q][e_ii - 1] = -U[c_q][e_ii - 1];
      }
      (&U[0][0])[qq]++;
      if (0 <= (c_q - 1)) {
        U[c_q][0] = 0.0;
      }
    } else {
      U[c_q][0] = 0.0;
      U[c_q][1] = 0.0;
      U[c_q][2] = 0.0;
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (int d_q{2}; d_q >= 0; d_q--) {
    if (((d_q + 1) <= 1) && (e[0] != 0.0)) {
      blas::h_xaxpy(2, -(blas::c_xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V,
                    5);
      blas::h_xaxpy(2, -(blas::c_xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V,
                    8);
    }
    V[d_q][0] = 0.0;
    V[d_q][1] = 0.0;
    V[d_q][2] = 0.0;
    V[d_q][d_q] = 1.0;
  }
  b_iter = 0;
  snorm = 0.0;
  for (int e_q{0}; e_q < 3; e_q++) {
    double b_d1;
    double r;
    b_d1 = s[e_q];
    if (b_d1 != 0.0) {
      int i2;
      int ix0;
      rt = std::abs(b_d1);
      r = b_d1 / rt;
      s[e_q] = rt;
      if ((e_q + 1) < 3) {
        e[e_q] /= r;
      }
      ix0 = 3 * e_q;
      i2 = ix0 + 3;
      for (int e_k{ix0 + 1}; e_k <= i2; e_k++) {
        (&U[0][0])[e_k - 1] *= r;
      }
    }
    if ((e_q + 1) < 3) {
      double d2;
      d2 = e[e_q];
      if (d2 != 0.0) {
        int b_ix0;
        int i3;
        rt = std::abs(d2);
        r = rt / d2;
        e[e_q] = rt;
        s[e_q + 1] *= r;
        b_ix0 = 3 * (e_q + 1);
        i3 = b_ix0 + 3;
        for (int g_k{b_ix0 + 1}; g_k <= i3; g_k++) {
          (&V[0][0])[g_k - 1] *= r;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[e_q]), std::abs(e[e_q])));
  }
  while (((m + 2) > 0) && (b_iter < 75)) {
    int f_q;
    int g_ii;
    int kase;
    g_ii = m;
    int exitg1;
    do {
      exitg1 = 0;
      f_q = g_ii + 1;
      if ((g_ii + 1) == 0) {
        exitg1 = 1;
      } else {
        double ztest0;
        ztest0 = std::abs(e[g_ii]);
        if (ztest0 <= (2.2204460492503131E-16 *
                       (std::abs(s[g_ii]) + std::abs(s[g_ii + 1])))) {
          e[g_ii] = 0.0;
          exitg1 = 1;
        } else if ((ztest0 <= 1.0020841800044864E-292) ||
                   ((b_iter > 20) &&
                    (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
          e[g_ii] = 0.0;
          exitg1 = 1;
        } else {
          g_ii--;
        }
      }
    } while (exitg1 == 0);
    if ((g_ii + 1) == (m + 1)) {
      kase = 4;
    } else {
      int m_ii;
      int qs;
      bool exitg2;
      qs = m + 2;
      m_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (m_ii >= (g_ii + 1))) {
        qs = m_ii;
        if (m_ii == (g_ii + 1)) {
          exitg2 = true;
        } else {
          double test;
          double ztest;
          test = 0.0;
          if (m_ii < (m + 2)) {
            test = std::abs(e[m_ii - 1]);
          }
          if (m_ii > (g_ii + 2)) {
            test += std::abs(e[m_ii - 2]);
          }
          ztest = std::abs(s[m_ii - 1]);
          if ((ztest <= (2.2204460492503131E-16 * test)) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[m_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            m_ii--;
          }
        }
      }
      if (qs == (g_ii + 1)) {
        kase = 3;
      } else if (qs == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        f_q = qs;
      }
    }
    switch (kase) {
    case 1: {
      int i4;
      f = e[m];
      e[m] = 0.0;
      i4 = m + 1;
      for (int i_k{i4}; i_k >= (f_q + 1); i_k--) {
        blas::xrotg(&s[i_k - 1], &f, &b_cs, &b_sn);
        if (i_k > (f_q + 1)) {
          f = (-b_sn) * e[0];
          e[0] *= b_cs;
        }
        blas::c_xrot(V, (3 * (i_k - 1)) + 1, (3 * (m + 1)) + 1, b_cs, b_sn);
      }
    } break;
    case 2: {
      f = e[f_q - 1];
      e[f_q - 1] = 0.0;
      for (int h_k{f_q + 1}; h_k <= (m + 2); h_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[h_k - 1], &a__1, &c_cs, &c_sn);
        f_tmp = e[h_k - 1];
        f = (-c_sn) * f_tmp;
        e[h_k - 1] = f_tmp * c_cs;
        blas::c_xrot(U, (3 * (h_k - 1)) + 1, (3 * (f_q - 1)) + 1, c_cs, c_sn);
      }
    } break;
    case 3: {
      double b;
      double c;
      double emm1;
      double g;
      double scale;
      double scale_tmp;
      double shift;
      double sm;
      double smm1;
      double sqds;
      int mm1;
      mm1 = m + 1;
      scale_tmp = s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(scale_tmp), std::abs(s[m])),
                              std::abs(e[m])),
                    std::abs(s[f_q])),
          std::abs(e[f_q]));
      sm = scale_tmp / scale;
      smm1 = s[m] / scale;
      emm1 = e[m] / scale;
      sqds = s[f_q] / scale;
      b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
      c = sm * emm1;
      c *= c;
      if ((b != 0.0) || (c != 0.0)) {
        shift = std::sqrt((b * b) + c);
        if (b < 0.0) {
          shift = -shift;
        }
        shift = c / (b + shift);
      } else {
        shift = 0.0;
      }
      f = ((sqds + sm) * (sqds - sm)) + shift;
      g = sqds * (e[f_q] / scale);
      for (int k_k{f_q + 1}; k_k <= mm1; k_k++) {
        double b_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
        if (k_k > (f_q + 1)) {
          e[0] = b_f;
        }
        f_tmp_tmp = e[k_k - 1];
        b_f_tmp = s[k_k - 1];
        e[k_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * b_f_tmp);
        a__3 = d_sn * s[k_k];
        s[k_k] *= d_cs;
        blas::c_xrot(V, (3 * (k_k - 1)) + 1, (3 * k_k) + 1, d_cs, d_sn);
        s[k_k - 1] = (d_cs * b_f_tmp) + (d_sn * f_tmp_tmp);
        blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &e_sn);
        f = (e_cs * e[k_k - 1]) + (e_sn * s[k_k]);
        s[k_k] = ((-e_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
        g = e_sn * e[k_k];
        e[k_k] *= e_cs;
        blas::c_xrot(U, (3 * (k_k - 1)) + 1, (3 * k_k) + 1, e_cs, e_sn);
      }
      e[m] = f;
      b_iter++;
    } break;
    default: {
      if (s[f_q] < 0.0) {
        int c_ix0;
        int i5;
        s[f_q] = -s[f_q];
        c_ix0 = 3 * f_q;
        i5 = c_ix0 + 3;
        for (int j_k{c_ix0 + 1}; j_k <= i5; j_k++) {
          (&V[0][0])[j_k - 1] = -(&V[0][0])[j_k - 1];
        }
      }
      qp1 = f_q + 1;
      while (((f_q + 1) < 3) && (s[f_q] < s[qp1])) {
        rt = s[f_q];
        s[f_q] = s[qp1];
        s[qp1] = rt;
        blas::c_xswap(V, (3 * f_q) + 1, (3 * (f_q + 1)) + 1);
        blas::c_xswap(U, (3 * f_q) + 1, (3 * (f_q + 1)) + 1);
        f_q = qp1;
        qp1++;
      }
      b_iter = 0;
      m--;
    } break;
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &U
//                ::coder::array<double, 1U> &s
//                double V[3][3]
// Return Type  : void
//
void g_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           ::coder::array<double, 1U> &s, double V[3][3])
{
  ::coder::array<double, 2U> j_A;
  ::coder::array<double, 1U> c_S;
  ::coder::array<double, 1U> work;
  double e[3];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  int b_iv[2];
  int b_loop_ub;
  int b_u0;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int h_n;
  int i1;
  int i6;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  j_A.set_size(A.size(0), 3);
  loop_ub = A.size(0);
  if ((static_cast<int>((3 * A.size(0)) < 4)) != 0) {
    for (int b_i{0}; b_i < 3; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 3; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
      }
    }
  }
  h_n = A.size(0);
  u0 = A.size(0);
  if (u0 <= 3) {
    minnp = u0;
  } else {
    minnp = 3;
  }
  b_u0 = A.size(0) + 1;
  if (b_u0 <= 3) {
    unnamed_idx_0 = b_u0;
  } else {
    unnamed_idx_0 = 3;
  }
  s.set_size(unnamed_idx_0);
  for (int i2{0}; i2 < unnamed_idx_0; i2++) {
    s[i2] = 0.0;
  }
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  work.set_size(A.size(0));
  b_loop_ub = A.size(0);
  if ((static_cast<int>(A.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < b_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < b_loop_ub; i3++) {
      work[i3] = 0.0;
    }
  }
  b_iv[0] = A.size(0);
  U.set_size(A.size(0), A.size(0));
  c_loop_ub = A.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    d_loop_ub)

  for (int i4 = 0; i4 < c_loop_ub; i4++) {
    d_loop_ub = b_iv[0];
    for (i6 = 0; i6 < d_loop_ub; i6++) {
      U[i6 + (U.size(0) * i4)] = 0.0;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i5 = 0; i5 < 3; i5++) {
    V[i5][0] = 0.0;
    V[i5][1] = 0.0;
    V[i5][2] = 0.0;
  }
  if (A.size(0) == 0) {
    V[0][0] = 1.0;
    V[1][1] = 1.0;
    V[2][2] = 1.0;
  } else {
    double b_t;
    double rt;
    double snorm;
    int b_iter;
    int c_u0;
    int i7;
    int m;
    int mm;
    int nct;
    int nctp1;
    int qjj;
    int qp1;
    int qq;
    c_u0 = A.size(0) - 1;
    if (c_u0 <= 3) {
      nct = c_u0;
    } else {
      nct = 3;
    }
    nctp1 = nct + 1;
    if (nct >= 1) {
      i7 = nct;
    } else {
      i7 = 1;
    }
    for (int b_q{0}; b_q < i7; b_q++) {
      double nrm;
      int nmq;
      bool apply_transform;
      qp1 = b_q + 2;
      qq = (b_q + (h_n * b_q)) + 1;
      nmq = (h_n - b_q) - 1;
      apply_transform = false;
      if ((b_q + 1) <= nct) {
        nrm = blas::b_xnrm2(nmq + 1, j_A, qq);
        if (nrm > 0.0) {
          double d;
          apply_transform = true;
          if (j_A[qq - 1] < 0.0) {
            d = -nrm;
          } else {
            d = nrm;
          }
          s[b_q] = d;
          if (std::abs(d) >= 1.0020841800044864E-292) {
            double b_a;
            int i10;
            b_a = 1.0 / d;
            i10 = qq + nmq;
            for (int e_k{qq}; e_k <= i10; e_k++) {
              j_A[e_k - 1] = b_a * j_A[e_k - 1];
            }
          } else {
            int i9;
            i9 = qq + nmq;
            for (int c_k{qq}; c_k <= i9; c_k++) {
              j_A[c_k - 1] = j_A[c_k - 1] / s[b_q];
            }
          }
          j_A[qq - 1] = j_A[qq - 1] + 1.0;
          s[b_q] = -s[b_q];
        } else {
          s[b_q] = 0.0;
        }
      }
      for (int jj{qp1}; jj < 4; jj++) {
        qjj = b_q + (h_n * (jj - 1));
        if (apply_transform) {
          b_t = 0.0;
          if ((nmq + 1) >= 1) {
            for (int b_k{0}; b_k <= nmq; b_k++) {
              b_t += j_A[(qq + b_k) - 1] * j_A[qjj + b_k];
            }
          }
          b_t = -(b_t / j_A[b_q + (j_A.size(0) * b_q)]);
          if (((nmq + 1) >= 1) && (!(b_t == 0.0))) {
            for (int d_k{0}; d_k <= nmq; d_k++) {
              int i11;
              i11 = qjj + d_k;
              j_A[i11] = j_A[i11] + (b_t * j_A[(qq + d_k) - 1]);
            }
          }
        }
        e[jj - 1] = j_A[qjj];
      }
      if ((b_q + 1) <= nct) {
        for (int c_ii{b_q + 1}; c_ii <= h_n; c_ii++) {
          U[(c_ii + (U.size(0) * b_q)) - 1] =
              j_A[(c_ii + (j_A.size(0) * b_q)) - 1];
        }
      }
      if ((b_q + 1) <= 1) {
        nrm = blas::o_xnrm2(e);
        if (nrm == 0.0) {
          e[0] = 0.0;
        } else {
          double c_a;
          if (e[1] < 0.0) {
            e[0] = -nrm;
          } else {
            e[0] = nrm;
          }
          c_a = e[0];
          if (std::abs(e[0]) >= 1.0020841800044864E-292) {
            double d_a;
            d_a = 1.0 / e[0];
            for (int h_k{qp1}; h_k < 4; h_k++) {
              e[h_k - 1] *= d_a;
            }
          } else {
            for (int g_k{qp1}; g_k < 4; g_k++) {
              e[g_k - 1] /= c_a;
            }
          }
          e[1]++;
          e[0] = -e[0];
          if (2 <= h_n) {
            for (int p_ii{qp1}; p_ii <= h_n; p_ii++) {
              work[p_ii - 1] = 0.0;
            }
            for (int d_jj{qp1}; d_jj < 4; d_jj++) {
              blas::p_xaxpy(nmq, e[d_jj - 1], j_A, (h_n * (d_jj - 1)) + 2,
                            work);
            }
            for (int e_jj{qp1}; e_jj < 4; e_jj++) {
              blas::q_xaxpy(nmq, (-e[e_jj - 1]) / e[1], work, j_A,
                            (h_n * (e_jj - 1)) + 2);
            }
          }
        }
        for (int f_ii{qp1}; f_ii < 4; f_ii++) {
          V[0][f_ii - 1] = e[f_ii - 1];
        }
      }
    }
    if (3 <= (A.size(0) + 1)) {
      m = 2;
    } else {
      m = A.size(0);
    }
    if (nct < 3) {
      s[nct] = j_A[nct + (j_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if (2 < (m + 1)) {
      e[1] = j_A[(j_A.size(0) * m) + 1];
    }
    e[m] = 0.0;
    if ((nct + 1) <= A.size(0)) {
      for (int b_jj{nctp1}; b_jj <= h_n; b_jj++) {
        for (int e_ii{0}; e_ii < h_n; e_ii++) {
          U[e_ii + (U.size(0) * (b_jj - 1))] = 0.0;
        }
        U[(b_jj + (U.size(0) * (b_jj - 1))) - 1] = 1.0;
      }
    }
    for (int c_q{nct}; c_q >= 1; c_q--) {
      int nmq_tmp;
      qp1 = c_q + 1;
      nmq_tmp = h_n - c_q;
      qq = (c_q + (h_n * (c_q - 1))) - 1;
      if (s[c_q - 1] != 0.0) {
        for (int c_jj{qp1}; c_jj <= h_n; c_jj++) {
          qjj = c_q + (h_n * (c_jj - 1));
          b_t = 0.0;
          if ((nmq_tmp + 1) >= 1) {
            for (int i_k{0}; i_k <= nmq_tmp; i_k++) {
              b_t += U[qq + i_k] * U[(qjj + i_k) - 1];
            }
          }
          b_t = -(b_t / U[qq]);
          blas::f_xaxpy(nmq_tmp + 1, b_t, qq + 1, U, qjj);
        }
        for (int h_ii{c_q}; h_ii <= h_n; h_ii++) {
          U[(h_ii + (U.size(0) * (c_q - 1))) - 1] =
              -U[(h_ii + (U.size(0) * (c_q - 1))) - 1];
        }
        U[qq] = U[qq] + 1.0;
        for (int o_ii{0}; o_ii <= (c_q - 2); o_ii++) {
          U[o_ii + (U.size(0) * (c_q - 1))] = 0.0;
        }
      } else {
        for (int g_ii{0}; g_ii < h_n; g_ii++) {
          U[g_ii + (U.size(0) * (c_q - 1))] = 0.0;
        }
        U[qq] = 1.0;
      }
    }
    for (int d_q{2}; d_q >= 0; d_q--) {
      if (((d_q + 1) <= 1) && (e[0] != 0.0)) {
        blas::h_xaxpy(2, -(blas::c_xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V,
                      5);
        blas::h_xaxpy(2, -(blas::c_xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V,
                      8);
      }
      V[d_q][0] = 0.0;
      V[d_q][1] = 0.0;
      V[d_q][2] = 0.0;
      V[d_q][d_q] = 1.0;
    }
    mm = m;
    b_iter = 0;
    snorm = 0.0;
    for (int e_q{0}; e_q <= m; e_q++) {
      double r;
      if (s[e_q] != 0.0) {
        rt = std::abs(s[e_q]);
        r = s[e_q] / rt;
        s[e_q] = rt;
        if ((e_q + 1) < (m + 1)) {
          e[e_q] /= r;
        }
        if ((e_q + 1) <= h_n) {
          int i12;
          int ix0;
          ix0 = h_n * e_q;
          i12 = ix0 + h_n;
          for (int j_k{ix0 + 1}; j_k <= i12; j_k++) {
            U[j_k - 1] = r * U[j_k - 1];
          }
        }
      }
      if ((e_q + 1) < (m + 1)) {
        double b_d1;
        b_d1 = e[e_q];
        if (b_d1 != 0.0) {
          int b_ix0;
          int i13;
          rt = std::abs(b_d1);
          r = rt / b_d1;
          e[e_q] = rt;
          s[e_q + 1] = s[e_q + 1] * r;
          b_ix0 = 3 * (e_q + 1);
          i13 = b_ix0 + 3;
          for (int k_k{b_ix0 + 1}; k_k <= i13; k_k++) {
            (&V[0][0])[k_k - 1] *= r;
          }
        }
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(s[e_q]), std::abs(e[e_q])));
    }
    while (((m + 1) > 0) && (b_iter < 75)) {
      int f_q;
      int kase;
      int m_ii;
      bool exitg2;
      m_ii = m;
      int exitg1;
      do {
        exitg1 = 0;
        f_q = m_ii;
        if (m_ii == 0) {
          exitg1 = 1;
        } else {
          double ztest0;
          ztest0 = std::abs(e[m_ii - 1]);
          if (ztest0 <= (2.2204460492503131E-16 *
                         (std::abs(s[m_ii - 1]) + std::abs(s[m_ii])))) {
            e[m_ii - 1] = 0.0;
            exitg1 = 1;
          } else if ((ztest0 <= 1.0020841800044864E-292) ||
                     ((b_iter > 20) &&
                      (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
            e[m_ii - 1] = 0.0;
            exitg1 = 1;
          } else {
            m_ii--;
          }
        }
      } while (exitg1 == 0);
      if (m_ii == m) {
        kase = 4;
      } else {
        int q_ii;
        int qs;
        qs = m + 1;
        q_ii = m + 1;
        exitg2 = false;
        while ((!exitg2) && (q_ii >= m_ii)) {
          qs = q_ii;
          if (q_ii == m_ii) {
            exitg2 = true;
          } else {
            double test;
            double ztest;
            test = 0.0;
            if (q_ii < (m + 1)) {
              test = std::abs(e[q_ii - 1]);
            }
            if (q_ii > (m_ii + 1)) {
              test += std::abs(e[q_ii - 2]);
            }
            ztest = std::abs(s[q_ii - 1]);
            if ((ztest <= (2.2204460492503131E-16 * test)) ||
                (ztest <= 1.0020841800044864E-292)) {
              s[q_ii - 1] = 0.0;
              exitg2 = true;
            } else {
              q_ii--;
            }
          }
        }
        if (qs == m_ii) {
          kase = 3;
        } else if (qs == (m + 1)) {
          kase = 1;
        } else {
          kase = 2;
          f_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (int m_k{m}; m_k >= (f_q + 1); m_k--) {
          blas::xrotg(&s[m_k - 1], &f, &b_cs, &b_sn);
          if (m_k > (f_q + 1)) {
            double f_tmp;
            f_tmp = e[m_k - 2];
            f = (-b_sn) * f_tmp;
            e[m_k - 2] = f_tmp * b_cs;
          }
          blas::c_xrot(V, (3 * (m_k - 1)) + 1, (3 * m) + 1, b_cs, b_sn);
        }
      } break;
      case 2: {
        f = e[f_q - 1];
        e[f_q - 1] = 0.0;
        for (int o_k{f_q + 1}; o_k <= (m + 1); o_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[o_k - 1], &a__1, &c_cs, &c_sn);
          b_f_tmp = e[o_k - 1];
          f = (-c_sn) * b_f_tmp;
          e[o_k - 1] = b_f_tmp * c_cs;
          if (h_n >= 1) {
            int b_iy;
            int c_ix;
            c_ix = h_n * (o_k - 1);
            b_iy = h_n * (f_q - 1);
            for (int q_k{0}; q_k < h_n; q_k++) {
              double temp;
              int b_temp_tmp;
              int temp_tmp;
              temp_tmp = b_iy + q_k;
              b_temp_tmp = c_ix + q_k;
              temp = (c_cs * U[b_temp_tmp]) + (c_sn * U[temp_tmp]);
              U[temp_tmp] = (c_cs * U[temp_tmp]) - (c_sn * U[b_temp_tmp]);
              U[b_temp_tmp] = temp;
            }
          }
        }
      } break;
      case 3: {
        double b;
        double b_scale_tmp;
        double c;
        double emm1;
        double g;
        double scale;
        double scale_tmp;
        double shift;
        double sm;
        double smm1;
        double sqds;
        scale_tmp = s[m - 1];
        b_scale_tmp = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s[m]), std::abs(scale_tmp)),
                                std::abs(b_scale_tmp)),
                      std::abs(s[f_q])),
            std::abs(e[f_q]));
        sm = s[m] / scale;
        smm1 = scale_tmp / scale;
        emm1 = b_scale_tmp / scale;
        sqds = s[f_q] / scale;
        b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
        c = sm * emm1;
        c *= c;
        if ((b != 0.0) || (c != 0.0)) {
          shift = std::sqrt((b * b) + c);
          if (b < 0.0) {
            shift = -shift;
          }
          shift = c / (b + shift);
        } else {
          shift = 0.0;
        }
        f = ((sqds + sm) * (sqds - sm)) + shift;
        g = sqds * (e[f_q] / scale);
        for (int s_k{f_q + 1}; s_k <= m; s_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
          if (s_k > (f_q + 1)) {
            e[s_k - 2] = b_f;
          }
          f_tmp_tmp = e[s_k - 1];
          c_f_tmp = s[s_k - 1];
          e[s_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * c_f_tmp);
          a__3 = d_sn * s[s_k];
          s[s_k] = s[s_k] * d_cs;
          blas::c_xrot(V, (3 * (s_k - 1)) + 1, (3 * s_k) + 1, d_cs, d_sn);
          s[s_k - 1] = (d_cs * c_f_tmp) + (d_sn * f_tmp_tmp);
          blas::xrotg(&s[s_k - 1], &a__3, &e_cs, &e_sn);
          f = (e_cs * e[s_k - 1]) + (e_sn * s[s_k]);
          s[s_k] = ((-e_sn) * e[s_k - 1]) + (e_cs * s[s_k]);
          g = e_sn * e[s_k];
          e[s_k] *= e_cs;
          if ((s_k < h_n) && (h_n >= 1)) {
            int d_iy;
            int e_ix;
            e_ix = h_n * (s_k - 1);
            d_iy = h_n * s_k;
            for (int t_k{0}; t_k < h_n; t_k++) {
              double c_temp;
              int d_temp_tmp;
              int e_temp_tmp;
              d_temp_tmp = d_iy + t_k;
              e_temp_tmp = e_ix + t_k;
              c_temp = (e_cs * U[e_temp_tmp]) + (e_sn * U[d_temp_tmp]);
              U[d_temp_tmp] = (e_cs * U[d_temp_tmp]) - (e_sn * U[e_temp_tmp]);
              U[e_temp_tmp] = c_temp;
            }
          }
        }
        e[m - 1] = f;
        b_iter++;
      } break;
      default: {
        if (s[f_q] < 0.0) {
          int c_ix0;
          int i14;
          s[f_q] = -s[f_q];
          c_ix0 = 3 * f_q;
          i14 = c_ix0 + 3;
          for (int p_k{c_ix0 + 1}; p_k <= i14; p_k++) {
            (&V[0][0])[p_k - 1] = -(&V[0][0])[p_k - 1];
          }
        }
        qp1 = f_q + 1;
        exitg2 = false;
        while ((!exitg2) && ((f_q + 1) < (mm + 1))) {
          if (s[f_q] < s[qp1]) {
            rt = s[f_q];
            s[f_q] = s[qp1];
            s[qp1] = rt;
            if ((f_q + 1) < 3) {
              blas::c_xswap(V, (3 * f_q) + 1, (3 * (f_q + 1)) + 1);
            }
            if ((f_q + 1) < h_n) {
              int c_iy;
              int d_ix;
              d_ix = h_n * f_q;
              c_iy = h_n * (f_q + 1);
              for (int r_k{0}; r_k < h_n; r_k++) {
                double b_temp;
                int c_temp_tmp;
                int i15;
                c_temp_tmp = d_ix + r_k;
                b_temp = U[c_temp_tmp];
                i15 = c_iy + r_k;
                U[c_temp_tmp] = U[i15];
                U[i15] = b_temp;
              }
            }
            f_q = qp1;
            qp1++;
          } else {
            exitg2 = true;
          }
        }
        b_iter = 0;
        m--;
      } break;
      }
    }
  }
  c_S.set_size(minnp);
  for (int k{0}; k < minnp; k++) {
    c_S[k] = s[k];
  }
  s.set_size(c_S.size(0));
  e_loop_ub = c_S.size(0);
  for (int b_i8{0}; b_i8 < e_loop_ub; b_i8++) {
    s[b_i8] = c_S[b_i8];
  }
}

//
// Arguments    : const double A[9][9]
//                double U[9][9]
//                double s[9]
//                double V[9][9]
// Return Type  : void
//
void h_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9])
{
  double j_A[9][9];
  double e[9];
  double work[9];
  double a__1;
  double a__2;
  double a__3;
  double b_cs;
  double b_f;
  double b_sn;
  double c_cs;
  double c_sn;
  double d_cs;
  double d_sn;
  double e_cs;
  double e_sn;
  double f;
  double rt;
  double snorm;
  int b_iter;
  int c_i;
  int m;
  int qjj;
  int qp1;
  int qq;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i)

  for (int b_i = 0; b_i < 9; b_i++) {
    s[b_i] = 0.0;
    e[b_i] = 0.0;
    work[b_i] = 0.0;
    for (c_i = 0; c_i < 9; c_i++) {
      j_A[b_i][c_i] = A[b_i][c_i];
      U[b_i][c_i] = 0.0;
      V[b_i][c_i] = 0.0;
    }
  }
  for (int b_q{0}; b_q < 8; b_q++) {
    double nrm;
    bool apply_transform;
    qp1 = b_q + 2;
    qq = (b_q + (9 * b_q)) + 1;
    apply_transform = false;
    nrm = blas::k_xnrm2(9 - b_q, j_A, qq);
    if (nrm > 0.0) {
      double d;
      apply_transform = true;
      if ((&j_A[0][0])[qq - 1] < 0.0) {
        d = -nrm;
      } else {
        d = nrm;
      }
      s[b_q] = d;
      if (std::abs(d) >= 1.0020841800044864E-292) {
        double b_a;
        int i2;
        b_a = 1.0 / d;
        i2 = (qq - b_q) + 8;
        for (int b_k{qq}; b_k <= i2; b_k++) {
          (&j_A[0][0])[b_k - 1] *= b_a;
        }
      } else {
        int i1;
        i1 = (qq - b_q) + 8;
        for (int k{qq}; k <= i1; k++) {
          (&j_A[0][0])[k - 1] /= s[b_q];
        }
      }
      (&j_A[0][0])[qq - 1]++;
      s[b_q] = -s[b_q];
    } else {
      s[b_q] = 0.0;
    }
    for (int jj{qp1}; jj < 10; jj++) {
      qjj = b_q + (9 * (jj - 1));
      if (apply_transform) {
        blas::i_xaxpy(
            9 - b_q,
            -(blas::d_xdotc(9 - b_q, j_A, qq, j_A, qjj + 1) / j_A[b_q][b_q]),
            qq, j_A, qjj + 1);
      }
      e[jj - 1] = (&j_A[0][0])[qjj];
    }
    for (int e_ii{b_q + 1}; e_ii < 10; e_ii++) {
      U[b_q][e_ii - 1] = j_A[b_q][e_ii - 1];
    }
    if ((b_q + 1) <= 7) {
      nrm = blas::m_xnrm2(8 - b_q, e, b_q + 2);
      if (nrm == 0.0) {
        e[b_q] = 0.0;
      } else {
        double c_a;
        if (e[b_q + 1] < 0.0) {
          e[b_q] = -nrm;
        } else {
          e[b_q] = nrm;
        }
        c_a = e[b_q];
        if (std::abs(e[b_q]) >= 1.0020841800044864E-292) {
          double d_a;
          d_a = 1.0 / e[b_q];
          for (int d_k{qp1}; d_k < 10; d_k++) {
            e[d_k - 1] *= d_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 10; c_k++) {
            e[c_k - 1] /= c_a;
          }
        }
        e[b_q + 1]++;
        e[b_q] = -e[b_q];
        for (int q_ii{qp1}; q_ii < 10; q_ii++) {
          work[q_ii - 1] = 0.0;
        }
        for (int d_jj{qp1}; d_jj < 10; d_jj++) {
          blas::j_xaxpy(8 - b_q, e[d_jj - 1], j_A, (b_q + (9 * (d_jj - 1))) + 2,
                        work, b_q + 2);
        }
        for (int e_jj{qp1}; e_jj < 10; e_jj++) {
          blas::k_xaxpy(8 - b_q, (-e[e_jj - 1]) / e[b_q + 1], work, b_q + 2,
                        j_A, (b_q + (9 * (e_jj - 1))) + 2);
        }
      }
      for (int m_ii{qp1}; m_ii < 10; m_ii++) {
        V[b_q][m_ii - 1] = e[m_ii - 1];
      }
    }
  }
  m = 7;
  s[8] = j_A[8][8];
  e[7] = j_A[8][7];
  e[8] = 0.0;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_ii = 0; c_ii < 9; c_ii++) {
    U[8][c_ii] = 0.0;
  }
  U[8][8] = 1.0;
  for (int c_q{7}; c_q >= 0; c_q--) {
    qp1 = c_q + 2;
    qq = c_q + (9 * c_q);
    if (s[c_q] != 0.0) {
      for (int b_jj{qp1}; b_jj < 10; b_jj++) {
        qjj = (c_q + (9 * (b_jj - 1))) + 1;
        blas::i_xaxpy(
            9 - c_q,
            -(blas::d_xdotc(9 - c_q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (int h_ii{c_q + 1}; h_ii < 10; h_ii++) {
        U[c_q][h_ii - 1] = -U[c_q][h_ii - 1];
      }
      (&U[0][0])[qq]++;
      for (int p_ii{0}; p_ii < c_q; p_ii++) {
        U[c_q][p_ii] = 0.0;
      }
    } else {
      for (int f_ii{0}; f_ii < 9; f_ii++) {
        U[c_q][f_ii] = 0.0;
      }
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (int d_q{8}; d_q >= 0; d_q--) {
    if (((d_q + 1) <= 7) && (e[d_q] != 0.0)) {
      int qp1q;
      qp1 = d_q + 2;
      qp1q = (d_q + (9 * d_q)) + 2;
      for (int c_jj{qp1}; c_jj < 10; c_jj++) {
        int qp1jj;
        qp1jj = (d_q + (9 * (c_jj - 1))) + 2;
        blas::i_xaxpy(
            8 - d_q,
            -(blas::d_xdotc(8 - d_q, V, qp1q, V, qp1jj) / (&V[0][0])[qp1q - 1]),
            qp1q, V, qp1jj);
      }
    }
    for (int g_ii{0}; g_ii < 9; g_ii++) {
      V[d_q][g_ii] = 0.0;
    }
    V[d_q][d_q] = 1.0;
  }
  b_iter = 0;
  snorm = 0.0;
  for (int e_q{0}; e_q < 9; e_q++) {
    double b_d1;
    double r;
    b_d1 = s[e_q];
    if (b_d1 != 0.0) {
      int i3;
      int ix0;
      rt = std::abs(b_d1);
      r = b_d1 / rt;
      s[e_q] = rt;
      if ((e_q + 1) < 9) {
        e[e_q] /= r;
      }
      ix0 = 9 * e_q;
      i3 = ix0 + 9;
      for (int e_k{ix0 + 1}; e_k <= i3; e_k++) {
        (&U[0][0])[e_k - 1] *= r;
      }
    }
    if ((e_q + 1) < 9) {
      double d2;
      d2 = e[e_q];
      if (d2 != 0.0) {
        int b_ix0;
        int i4;
        rt = std::abs(d2);
        r = rt / d2;
        e[e_q] = rt;
        s[e_q + 1] *= r;
        b_ix0 = 9 * (e_q + 1);
        i4 = b_ix0 + 9;
        for (int g_k{b_ix0 + 1}; g_k <= i4; g_k++) {
          (&V[0][0])[g_k - 1] *= r;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[e_q]), std::abs(e[e_q])));
  }
  while (((m + 2) > 0) && (b_iter < 75)) {
    int f_q;
    int kase;
    int o_ii;
    o_ii = m;
    int exitg1;
    do {
      exitg1 = 0;
      f_q = o_ii + 1;
      if ((o_ii + 1) == 0) {
        exitg1 = 1;
      } else {
        double ztest0;
        ztest0 = std::abs(e[o_ii]);
        if (ztest0 <= (2.2204460492503131E-16 *
                       (std::abs(s[o_ii]) + std::abs(s[o_ii + 1])))) {
          e[o_ii] = 0.0;
          exitg1 = 1;
        } else if ((ztest0 <= 1.0020841800044864E-292) ||
                   ((b_iter > 20) &&
                    (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
          e[o_ii] = 0.0;
          exitg1 = 1;
        } else {
          o_ii--;
        }
      }
    } while (exitg1 == 0);
    if ((o_ii + 1) == (m + 1)) {
      kase = 4;
    } else {
      int qs;
      int r_ii;
      bool exitg2;
      qs = m + 2;
      r_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (r_ii >= (o_ii + 1))) {
        qs = r_ii;
        if (r_ii == (o_ii + 1)) {
          exitg2 = true;
        } else {
          double test;
          double ztest;
          test = 0.0;
          if (r_ii < (m + 2)) {
            test = std::abs(e[r_ii - 1]);
          }
          if (r_ii > (o_ii + 2)) {
            test += std::abs(e[r_ii - 2]);
          }
          ztest = std::abs(s[r_ii - 1]);
          if ((ztest <= (2.2204460492503131E-16 * test)) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[r_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            r_ii--;
          }
        }
      }
      if (qs == (o_ii + 1)) {
        kase = 3;
      } else if (qs == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        f_q = qs;
      }
    }
    switch (kase) {
    case 1: {
      int i5;
      f = e[m];
      e[m] = 0.0;
      i5 = m + 1;
      for (int i_k{i5}; i_k >= (f_q + 1); i_k--) {
        blas::xrotg(&s[i_k - 1], &f, &b_cs, &b_sn);
        if (i_k > (f_q + 1)) {
          double b_f_tmp;
          b_f_tmp = e[i_k - 2];
          f = (-b_sn) * b_f_tmp;
          e[i_k - 2] = b_f_tmp * b_cs;
        }
        blas::d_xrot(V, (9 * (i_k - 1)) + 1, (9 * (m + 1)) + 1, b_cs, b_sn);
      }
    } break;
    case 2: {
      f = e[f_q - 1];
      e[f_q - 1] = 0.0;
      for (int h_k{f_q + 1}; h_k <= (m + 2); h_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[h_k - 1], &a__1, &c_cs, &c_sn);
        f_tmp = e[h_k - 1];
        f = (-c_sn) * f_tmp;
        e[h_k - 1] = f_tmp * c_cs;
        blas::d_xrot(U, (9 * (h_k - 1)) + 1, (9 * (f_q - 1)) + 1, c_cs, c_sn);
      }
    } break;
    case 3: {
      double b;
      double c;
      double emm1;
      double g;
      double scale;
      double scale_tmp;
      double shift;
      double sm;
      double smm1;
      double sqds;
      int mm1;
      mm1 = m + 1;
      scale_tmp = s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(scale_tmp), std::abs(s[m])),
                              std::abs(e[m])),
                    std::abs(s[f_q])),
          std::abs(e[f_q]));
      sm = scale_tmp / scale;
      smm1 = s[m] / scale;
      emm1 = e[m] / scale;
      sqds = s[f_q] / scale;
      b = (((smm1 + sm) * (smm1 - sm)) + (emm1 * emm1)) / 2.0;
      c = sm * emm1;
      c *= c;
      if ((b != 0.0) || (c != 0.0)) {
        shift = std::sqrt((b * b) + c);
        if (b < 0.0) {
          shift = -shift;
        }
        shift = c / (b + shift);
      } else {
        shift = 0.0;
      }
      f = ((sqds + sm) * (sqds - sm)) + shift;
      g = sqds * (e[f_q] / scale);
      for (int k_k{f_q + 1}; k_k <= mm1; k_k++) {
        double c_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &d_sn);
        if (k_k > (f_q + 1)) {
          e[k_k - 2] = b_f;
        }
        f_tmp_tmp = e[k_k - 1];
        c_f_tmp = s[k_k - 1];
        e[k_k - 1] = (d_cs * f_tmp_tmp) - (d_sn * c_f_tmp);
        a__3 = d_sn * s[k_k];
        s[k_k] *= d_cs;
        blas::d_xrot(V, (9 * (k_k - 1)) + 1, (9 * k_k) + 1, d_cs, d_sn);
        s[k_k - 1] = (d_cs * c_f_tmp) + (d_sn * f_tmp_tmp);
        blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &e_sn);
        f = (e_cs * e[k_k - 1]) + (e_sn * s[k_k]);
        s[k_k] = ((-e_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
        g = e_sn * e[k_k];
        e[k_k] *= e_cs;
        blas::d_xrot(U, (9 * (k_k - 1)) + 1, (9 * k_k) + 1, e_cs, e_sn);
      }
      e[m] = f;
      b_iter++;
    } break;
    default: {
      if (s[f_q] < 0.0) {
        int c_ix0;
        int i6;
        s[f_q] = -s[f_q];
        c_ix0 = 9 * f_q;
        i6 = c_ix0 + 9;
        for (int j_k{c_ix0 + 1}; j_k <= i6; j_k++) {
          (&V[0][0])[j_k - 1] = -(&V[0][0])[j_k - 1];
        }
      }
      qp1 = f_q + 1;
      while (((f_q + 1) < 9) && (s[f_q] < s[qp1])) {
        rt = s[f_q];
        s[f_q] = s[qp1];
        s[qp1] = rt;
        blas::d_xswap(V, (9 * f_q) + 1, (9 * (f_q + 1)) + 1);
        blas::d_xswap(U, (9 * f_q) + 1, (9 * (f_q + 1)) + 1);
        f_q = qp1;
        qp1++;
      }
      b_iter = 0;
      m--;
    } break;
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for svd1.cpp
//
// [EOF]
//
