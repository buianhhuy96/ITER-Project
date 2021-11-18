//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &U
// Return Type  : void
//
namespace coder {
namespace internal {
void b_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U)
{
  array<double, 2U> e_A;
  array<double, 1U> s;
  array<double, 1U> work;
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
  double f;
  double sn;
  int b_loop_ub;
  int b_u0;
  int c_n;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  e_A.set_size(A.size(0), 8);
  loop_ub = A.size(0);
  for (int b_i{0}; b_i < 8; b_i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  c_n = A.size(0);
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
  for (int i2{0}; i2 < unnamed_idx_0; i2++) {
    s[i2] = 0.0;
  }
  (void)std::memset(&e[0], 0, 8U * (sizeof(double)));
  work.set_size(A.size(0));
  b_loop_ub = A.size(0);
  for (int i3{0}; i3 < b_loop_ub; i3++) {
    work[i3] = 0.0;
  }
  if (A.size(0) != 0) {
    double rt;
    double snorm;
    int c_u0;
    int i4;
    int iter;
    int m;
    int mm;
    int nct;
    int nrt;
    int u1;
    u1 = A.size(0);
    if (6 <= u1) {
      nrt = 6;
    } else {
      nrt = u1;
    }
    c_u0 = A.size(0) - 1;
    if (c_u0 <= 8) {
      nct = c_u0;
    } else {
      nct = 8;
    }
    if (nct >= nrt) {
      i4 = nct;
    } else {
      i4 = nrt;
    }
    for (int q{0}; q < i4; q++) {
      double nrm;
      int nmq;
      int qp1_tmp;
      int qq;
      bool apply_transform;
      qp1_tmp = q + 2;
      qq = (q + (c_n * q)) + 1;
      nmq = (c_n - q) - 1;
      apply_transform = false;
      if ((q + 1) <= nct) {
        nrm = blas::xnrm2(nmq + 1, e_A, qq);
        if (nrm > 0.0) {
          double d;
          apply_transform = true;
          if (e_A[qq - 1] < 0.0) {
            d = -nrm;
          } else {
            d = nrm;
          }
          s[q] = d;
          if (std::abs(d) >= 1.0020841800044864E-292) {
            double b_a;
            int i6;
            b_a = 1.0 / d;
            i6 = qq + nmq;
            for (int f_k{qq}; f_k <= i6; f_k++) {
              e_A[f_k - 1] = b_a * e_A[f_k - 1];
            }
          } else {
            int i5;
            i5 = qq + nmq;
            for (int c_k{qq}; c_k <= i5; c_k++) {
              e_A[c_k - 1] = e_A[c_k - 1] / s[q];
            }
          }
          e_A[qq - 1] = e_A[qq - 1] + 1.0;
          s[q] = -s[q];
        } else {
          s[q] = 0.0;
        }
      }
      for (int b_jj{qp1_tmp}; b_jj < 9; b_jj++) {
        int qjj;
        qjj = q + (c_n * (b_jj - 1));
        if (apply_transform) {
          double b_t;
          b_t = 0.0;
          if ((nmq + 1) >= 1) {
            for (int b_k{0}; b_k <= nmq; b_k++) {
              b_t += e_A[(qq + b_k) - 1] * e_A[qjj + b_k];
            }
          }
          b_t = -(b_t / e_A[q + (e_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(b_t == 0.0))) {
            for (int d_k{0}; d_k <= nmq; d_k++) {
              int i7;
              i7 = qjj + d_k;
              e_A[i7] = e_A[i7] + (b_t * e_A[(qq + d_k) - 1]);
            }
          }
        }
        e[b_jj - 1] = e_A[qjj];
      }
      if ((q + 1) <= nrt) {
        nrm = blas::b_xnrm2(7 - q, e, q + 2);
        if (nrm == 0.0) {
          e[q] = 0.0;
        } else {
          double c_a;
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }
          c_a = e[q];
          if (std::abs(e[q]) >= 1.0020841800044864E-292) {
            double d_a;
            d_a = 1.0 / e[q];
            for (int h_k{qp1_tmp}; h_k < 9; h_k++) {
              e[h_k - 1] *= d_a;
            }
          } else {
            for (int g_k{qp1_tmp}; g_k < 9; g_k++) {
              e[g_k - 1] /= c_a;
            }
          }
          e[q + 1]++;
          e[q] = -e[q];
          if ((q + 2) <= c_n) {
            for (int e_ii{qp1_tmp}; e_ii <= c_n; e_ii++) {
              work[e_ii - 1] = 0.0;
            }
            for (int c_jj{qp1_tmp}; c_jj < 9; c_jj++) {
              double f_a;
              int ix0;
              f_a = e[c_jj - 1];
              ix0 = (q + (c_n * (c_jj - 1))) + 2;
              if ((nmq >= 1) && (!(f_a == 0.0))) {
                int i8;
                i8 = nmq - 1;
                for (int i_k{0}; i_k <= i8; i_k++) {
                  int i10;
                  i10 = (q + i_k) + 1;
                  work[i10] = work[i10] + (f_a * e_A[(ix0 + i_k) - 1]);
                }
              }
            }
            for (int d_jj{qp1_tmp}; d_jj < 9; d_jj++) {
              double g_a;
              int iy0;
              g_a = (-e[d_jj - 1]) / e[q + 1];
              iy0 = (q + (c_n * (d_jj - 1))) + 2;
              if ((nmq >= 1) && (!(g_a == 0.0))) {
                int i9;
                i9 = nmq - 1;
                for (int m_k{0}; m_k <= i9; m_k++) {
                  int i11;
                  i11 = (iy0 + m_k) - 1;
                  e_A[i11] = e_A[i11] + (g_a * work[(q + m_k) + 1]);
                }
              }
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
      s[nct] = e_A[nct + (e_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = e_A[nrt + (e_A.size(0) * m)];
    }
    e[m] = 0.0;
    mm = m;
    iter = 0;
    snorm = 0.0;
    for (int b_q{0}; b_q <= m; b_q++) {
      double b_d1;
      double r;
      b_d1 = s[b_q];
      if (s[b_q] != 0.0) {
        rt = std::abs(s[b_q]);
        r = s[b_q] / rt;
        b_d1 = rt;
        s[b_q] = rt;
        if ((b_q + 1) < (m + 1)) {
          e[b_q] /= r;
        }
      }
      if (((b_q + 1) < (m + 1)) && (e[b_q] != 0.0)) {
        rt = std::abs(e[b_q]);
        r = rt / e[b_q];
        e[b_q] = rt;
        s[b_q + 1] = s[b_q + 1] * r;
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(b_d1), std::abs(e[b_q])));
    }
    while (((m + 1) > 0) && (iter < 75)) {
      int c_ii;
      int c_q;
      int kase;
      bool exitg2;
      c_ii = m;
      int exitg1;
      do {
        exitg1 = 0;
        c_q = c_ii;
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
                     ((iter > 20) &&
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
          c_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (int j_k{m}; j_k >= (c_q + 1); j_k--) {
          blas::xrotg(&s[j_k - 1], &f, &b_cs, &sn);
          if (j_k > (c_q + 1)) {
            double f_tmp;
            f_tmp = e[j_k - 2];
            f = (-sn) * f_tmp;
            e[j_k - 2] = f_tmp * b_cs;
          }
        }
      } break;
      case 2: {
        f = e[c_q - 1];
        e[c_q - 1] = 0.0;
        for (int k_k{c_q + 1}; k_k <= (m + 1); k_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[k_k - 1], &a__1, &c_cs, &b_sn);
          b_f_tmp = e[k_k - 1];
          f = (-b_sn) * b_f_tmp;
          e[k_k - 1] = b_f_tmp * c_cs;
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
                      std::abs(s[c_q])),
            std::abs(e[c_q]));
        sm = s[m] / scale;
        smm1 = scale_tmp / scale;
        emm1 = b_scale_tmp / scale;
        sqds = s[c_q] / scale;
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
        g = sqds * (e[c_q] / scale);
        for (int o_k{c_q + 1}; o_k <= m; o_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
          if (o_k > (c_q + 1)) {
            e[o_k - 2] = b_f;
          }
          f_tmp_tmp = e[o_k - 1];
          c_f_tmp = s[o_k - 1];
          e[o_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * c_f_tmp);
          a__3 = c_sn * s[o_k];
          s[o_k] = s[o_k] * d_cs;
          s[o_k - 1] = (d_cs * c_f_tmp) + (c_sn * f_tmp_tmp);
          blas::xrotg(&s[o_k - 1], &a__3, &e_cs, &d_sn);
          f = (e_cs * e[o_k - 1]) + (d_sn * s[o_k]);
          s[o_k] = ((-d_sn) * e[o_k - 1]) + (e_cs * s[o_k]);
          g = d_sn * e[o_k];
          e[o_k] *= e_cs;
        }
        e[m - 1] = f;
        iter++;
      } break;
      default: {
        int qp1;
        if (s[c_q] < 0.0) {
          s[c_q] = -s[c_q];
        }
        qp1 = c_q + 1;
        exitg2 = false;
        while ((!exitg2) && ((c_q + 1) < (mm + 1))) {
          if (s[c_q] < s[qp1]) {
            rt = s[c_q];
            s[c_q] = s[qp1];
            s[qp1] = rt;
            c_q = qp1;
            qp1++;
          } else {
            exitg2 = true;
          }
        }
        iter = 0;
        m--;
      } break;
      }
    }
  }
  U.set_size(minnp);
  for (int k{0}; k < minnp; k++) {
    U[k] = s[k];
  }
}

//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double s[3]
//                double V[3][3]
// Return Type  : void
//
void c_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3])
{
  double e_A[3][3];
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
  double f;
  double rt;
  double sn;
  double snorm;
  int iter;
  int m;
  int qjj;
  int qp1;
  int qq;
  for (int b_i{0}; b_i < 3; b_i++) {
    s[b_i] = 0.0;
    e[b_i] = 0.0;
    work[b_i] = 0.0;
    e_A[b_i][0] = A[b_i][0];
    U[b_i][0] = 0.0;
    V[b_i][0] = 0.0;
    e_A[b_i][1] = A[b_i][1];
    U[b_i][1] = 0.0;
    V[b_i][1] = 0.0;
    e_A[b_i][2] = A[b_i][2];
    U[b_i][2] = 0.0;
    V[b_i][2] = 0.0;
  }
  for (int q{0}; q < 2; q++) {
    double nrm;
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (3 * q)) + 1;
    apply_transform = false;
    nrm = blas::c_xnrm2(3 - q, e_A, qq);
    if (nrm > 0.0) {
      double d;
      apply_transform = true;
      if ((&e_A[0][0])[qq - 1] < 0.0) {
        d = -nrm;
      } else {
        d = nrm;
      }
      s[q] = d;
      if (std::abs(d) >= 1.0020841800044864E-292) {
        double b_a;
        int i1;
        b_a = 1.0 / d;
        i1 = (qq - q) + 2;
        for (int b_k{qq}; b_k <= i1; b_k++) {
          (&e_A[0][0])[b_k - 1] *= b_a;
        }
      } else {
        int c_i;
        c_i = (qq - q) + 2;
        for (int k{qq}; k <= c_i; k++) {
          (&e_A[0][0])[k - 1] /= s[q];
        }
      }
      (&e_A[0][0])[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (int b_jj{qp1}; b_jj < 4; b_jj++) {
      qjj = q + (3 * (b_jj - 1));
      if (apply_transform) {
        blas::xaxpy(3 - q,
                    -(blas::xdotc(3 - q, e_A, qq, e_A, qjj + 1) / e_A[q][q]),
                    qq, e_A, qjj + 1);
      }
      e[b_jj - 1] = (&e_A[0][0])[qjj];
    }
    for (int c_ii{q + 1}; c_ii < 4; c_ii++) {
      U[q][c_ii - 1] = e_A[q][c_ii - 1];
    }
    if ((q + 1) <= 1) {
      nrm = blas::f_xnrm2(e);
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
        for (int d_jj{qp1}; d_jj < 4; d_jj++) {
          blas::e_xaxpy(e[d_jj - 1], e_A, (3 * (d_jj - 1)) + 2, work);
        }
        for (int e_jj{qp1}; e_jj < 4; e_jj++) {
          blas::f_xaxpy((-e[e_jj - 1]) / e[1], work, e_A, (3 * (e_jj - 1)) + 2);
        }
      }
      for (int f_ii{qp1}; f_ii < 4; f_ii++) {
        V[0][f_ii - 1] = e[f_ii - 1];
      }
    }
  }
  m = 1;
  s[2] = e_A[2][2];
  e[1] = e_A[2][1];
  e[2] = 0.0;
  U[2][0] = 0.0;
  U[2][1] = 0.0;
  U[2][2] = 1.0;
  for (int b_q{1}; b_q >= 0; b_q--) {
    qp1 = b_q + 2;
    qq = b_q + (3 * b_q);
    if (s[b_q] != 0.0) {
      for (int c_jj{qp1}; c_jj < 4; c_jj++) {
        qjj = (b_q + (3 * (c_jj - 1))) + 1;
        blas::xaxpy(3 - b_q,
                    -(blas::xdotc(3 - b_q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
                    qq + 1, U, qjj);
      }
      for (int e_ii{b_q + 1}; e_ii < 4; e_ii++) {
        U[b_q][e_ii - 1] = -U[b_q][e_ii - 1];
      }
      (&U[0][0])[qq]++;
      if (0 <= (b_q - 1)) {
        U[b_q][0] = 0.0;
      }
    } else {
      U[b_q][0] = 0.0;
      U[b_q][1] = 0.0;
      U[b_q][2] = 0.0;
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (int c_q{2}; c_q >= 0; c_q--) {
    if (((c_q + 1) <= 1) && (e[0] != 0.0)) {
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V, 5);
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V, 8);
    }
    V[c_q][0] = 0.0;
    V[c_q][1] = 0.0;
    V[c_q][2] = 0.0;
    V[c_q][c_q] = 1.0;
  }
  iter = 0;
  snorm = 0.0;
  for (int d_q{0}; d_q < 3; d_q++) {
    double b_d1;
    double r;
    b_d1 = s[d_q];
    if (b_d1 != 0.0) {
      int i2;
      int ix0;
      rt = std::abs(b_d1);
      r = b_d1 / rt;
      s[d_q] = rt;
      if ((d_q + 1) < 3) {
        e[d_q] /= r;
      }
      ix0 = 3 * d_q;
      i2 = ix0 + 3;
      for (int f_k{ix0 + 1}; f_k <= i2; f_k++) {
        (&U[0][0])[f_k - 1] *= r;
      }
    }
    if ((d_q + 1) < 3) {
      double d2;
      d2 = e[d_q];
      if (d2 != 0.0) {
        int b_ix0;
        int i3;
        rt = std::abs(d2);
        r = rt / d2;
        e[d_q] = rt;
        s[d_q + 1] *= r;
        b_ix0 = 3 * (d_q + 1);
        i3 = b_ix0 + 3;
        for (int g_k{b_ix0 + 1}; g_k <= i3; g_k++) {
          (&V[0][0])[g_k - 1] *= r;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[d_q]), std::abs(e[d_q])));
  }
  while (((m + 2) > 0) && (iter < 75)) {
    int e_q;
    int g_ii;
    int kase;
    g_ii = m;
    int exitg1;
    do {
      exitg1 = 0;
      e_q = g_ii + 1;
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
                   ((iter > 20) &&
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
      int k_ii;
      int qs;
      bool exitg2;
      qs = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= (g_ii + 1))) {
        qs = k_ii;
        if (k_ii == (g_ii + 1)) {
          exitg2 = true;
        } else {
          double test;
          double ztest;
          test = 0.0;
          if (k_ii < (m + 2)) {
            test = std::abs(e[k_ii - 1]);
          }
          if (k_ii > (g_ii + 2)) {
            test += std::abs(e[k_ii - 2]);
          }
          ztest = std::abs(s[k_ii - 1]);
          if ((ztest <= (2.2204460492503131E-16 * test)) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }
      if (qs == (g_ii + 1)) {
        kase = 3;
      } else if (qs == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        e_q = qs;
      }
    }
    switch (kase) {
    case 1: {
      int i4;
      f = e[m];
      e[m] = 0.0;
      i4 = m + 1;
      for (int i_k{i4}; i_k >= (e_q + 1); i_k--) {
        blas::xrotg(&s[i_k - 1], &f, &b_cs, &sn);
        if (i_k > (e_q + 1)) {
          f = (-sn) * e[0];
          e[0] *= b_cs;
        }
        blas::xrot(V, (3 * (i_k - 1)) + 1, (3 * (m + 1)) + 1, b_cs, sn);
      }
    } break;
    case 2: {
      f = e[e_q - 1];
      e[e_q - 1] = 0.0;
      for (int h_k{e_q + 1}; h_k <= (m + 2); h_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[h_k - 1], &a__1, &c_cs, &b_sn);
        f_tmp = e[h_k - 1];
        f = (-b_sn) * f_tmp;
        e[h_k - 1] = f_tmp * c_cs;
        blas::xrot(U, (3 * (h_k - 1)) + 1, (3 * (e_q - 1)) + 1, c_cs, b_sn);
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
                    std::abs(s[e_q])),
          std::abs(e[e_q]));
      sm = scale_tmp / scale;
      smm1 = s[m] / scale;
      emm1 = e[m] / scale;
      sqds = s[e_q] / scale;
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
      g = sqds * (e[e_q] / scale);
      for (int k_k{e_q + 1}; k_k <= mm1; k_k++) {
        double b_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
        if (k_k > (e_q + 1)) {
          e[0] = b_f;
        }
        f_tmp_tmp = e[k_k - 1];
        b_f_tmp = s[k_k - 1];
        e[k_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * b_f_tmp);
        a__3 = c_sn * s[k_k];
        s[k_k] *= d_cs;
        blas::xrot(V, (3 * (k_k - 1)) + 1, (3 * k_k) + 1, d_cs, c_sn);
        s[k_k - 1] = (d_cs * b_f_tmp) + (c_sn * f_tmp_tmp);
        blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &d_sn);
        f = (e_cs * e[k_k - 1]) + (d_sn * s[k_k]);
        s[k_k] = ((-d_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
        g = d_sn * e[k_k];
        e[k_k] *= e_cs;
        blas::xrot(U, (3 * (k_k - 1)) + 1, (3 * k_k) + 1, e_cs, d_sn);
      }
      e[m] = f;
      iter++;
    } break;
    default: {
      if (s[e_q] < 0.0) {
        int c_ix0;
        int i5;
        s[e_q] = -s[e_q];
        c_ix0 = 3 * e_q;
        i5 = c_ix0 + 3;
        for (int j_k{c_ix0 + 1}; j_k <= i5; j_k++) {
          (&V[0][0])[j_k - 1] = -(&V[0][0])[j_k - 1];
        }
      }
      qp1 = e_q + 1;
      while (((e_q + 1) < 3) && (s[e_q] < s[qp1])) {
        rt = s[e_q];
        s[e_q] = s[qp1];
        s[qp1] = rt;
        blas::xswap(V, (3 * e_q) + 1, (3 * (e_q + 1)) + 1);
        blas::xswap(U, (3 * e_q) + 1, (3 * (e_q + 1)) + 1);
        e_q = qp1;
        qp1++;
      }
      iter = 0;
      m--;
    } break;
    }
  }
}

//
// Arguments    : const double A[9][9]
//                double U[9][9]
//                double s[9]
//                double V[9][9]
// Return Type  : void
//
void d_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9])
{
  double e_A[9][9];
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
  double f;
  double rt;
  double sn;
  double snorm;
  int iter;
  int m;
  int qjj;
  int qp1;
  int qq;
  for (int b_i{0}; b_i < 9; b_i++) {
    s[b_i] = 0.0;
    e[b_i] = 0.0;
    work[b_i] = 0.0;
    for (int c_i{0}; c_i < 9; c_i++) {
      e_A[b_i][c_i] = A[b_i][c_i];
      U[b_i][c_i] = 0.0;
      V[b_i][c_i] = 0.0;
    }
  }
  for (int q{0}; q < 8; q++) {
    double nrm;
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (9 * q)) + 1;
    apply_transform = false;
    nrm = blas::d_xnrm2(9 - q, e_A, qq);
    if (nrm > 0.0) {
      double d;
      apply_transform = true;
      if ((&e_A[0][0])[qq - 1] < 0.0) {
        d = -nrm;
      } else {
        d = nrm;
      }
      s[q] = d;
      if (std::abs(d) >= 1.0020841800044864E-292) {
        double b_a;
        int i2;
        b_a = 1.0 / d;
        i2 = (qq - q) + 8;
        for (int b_k{qq}; b_k <= i2; b_k++) {
          (&e_A[0][0])[b_k - 1] *= b_a;
        }
      } else {
        int i1;
        i1 = (qq - q) + 8;
        for (int k{qq}; k <= i1; k++) {
          (&e_A[0][0])[k - 1] /= s[q];
        }
      }
      (&e_A[0][0])[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (int b_jj{qp1}; b_jj < 10; b_jj++) {
      qjj = q + (9 * (b_jj - 1));
      if (apply_transform) {
        blas::b_xaxpy(
            9 - q, -(blas::b_xdotc(9 - q, e_A, qq, e_A, qjj + 1) / e_A[q][q]),
            qq, e_A, qjj + 1);
      }
      e[b_jj - 1] = (&e_A[0][0])[qjj];
    }
    for (int c_ii{q + 1}; c_ii < 10; c_ii++) {
      U[q][c_ii - 1] = e_A[q][c_ii - 1];
    }
    if ((q + 1) <= 7) {
      nrm = blas::e_xnrm2(8 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        double c_a;
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        c_a = e[q];
        if (std::abs(e[q]) >= 1.0020841800044864E-292) {
          double d_a;
          d_a = 1.0 / e[q];
          for (int d_k{qp1}; d_k < 10; d_k++) {
            e[d_k - 1] *= d_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 10; c_k++) {
            e[c_k - 1] /= c_a;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (int o_ii{qp1}; o_ii < 10; o_ii++) {
          work[o_ii - 1] = 0.0;
        }
        for (int e_jj{qp1}; e_jj < 10; e_jj++) {
          blas::c_xaxpy(8 - q, e[e_jj - 1], e_A, (q + (9 * (e_jj - 1))) + 2,
                        work, q + 2);
        }
        for (int f_jj{qp1}; f_jj < 10; f_jj++) {
          blas::d_xaxpy(8 - q, (-e[f_jj - 1]) / e[q + 1], work, q + 2, e_A,
                        (q + (9 * (f_jj - 1))) + 2);
        }
      }
      for (int m_ii{qp1}; m_ii < 10; m_ii++) {
        V[q][m_ii - 1] = e[m_ii - 1];
      }
    }
  }
  m = 7;
  s[8] = e_A[8][8];
  e[7] = e_A[8][7];
  e[8] = 0.0;
  (void)std::memset(&U[8][0], 0, 9U * (sizeof(double)));
  U[8][8] = 1.0;
  for (int b_q{7}; b_q >= 0; b_q--) {
    qp1 = b_q + 2;
    qq = b_q + (9 * b_q);
    if (s[b_q] != 0.0) {
      for (int c_jj{qp1}; c_jj < 10; c_jj++) {
        qjj = (b_q + (9 * (c_jj - 1))) + 1;
        blas::b_xaxpy(
            9 - b_q,
            -(blas::b_xdotc(9 - b_q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (int g_ii{b_q + 1}; g_ii < 10; g_ii++) {
        U[b_q][g_ii - 1] = -U[b_q][g_ii - 1];
      }
      (&U[0][0])[qq]++;
      for (int k_ii{0}; k_ii < b_q; k_ii++) {
        U[b_q][k_ii] = 0.0;
      }
    } else {
      for (int e_ii{0}; e_ii < 9; e_ii++) {
        U[b_q][e_ii] = 0.0;
      }
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (int c_q{8}; c_q >= 0; c_q--) {
    if (((c_q + 1) <= 7) && (e[c_q] != 0.0)) {
      int qp1q;
      qp1 = c_q + 2;
      qp1q = (c_q + (9 * c_q)) + 2;
      for (int d_jj{qp1}; d_jj < 10; d_jj++) {
        int qp1jj;
        qp1jj = (c_q + (9 * (d_jj - 1))) + 2;
        blas::b_xaxpy(
            8 - c_q,
            -(blas::b_xdotc(8 - c_q, V, qp1q, V, qp1jj) / (&V[0][0])[qp1q - 1]),
            qp1q, V, qp1jj);
      }
    }
    for (int f_ii{0}; f_ii < 9; f_ii++) {
      V[c_q][f_ii] = 0.0;
    }
    V[c_q][c_q] = 1.0;
  }
  iter = 0;
  snorm = 0.0;
  for (int d_q{0}; d_q < 9; d_q++) {
    double b_d1;
    double r;
    b_d1 = s[d_q];
    if (b_d1 != 0.0) {
      int i3;
      int ix0;
      rt = std::abs(b_d1);
      r = b_d1 / rt;
      s[d_q] = rt;
      if ((d_q + 1) < 9) {
        e[d_q] /= r;
      }
      ix0 = 9 * d_q;
      i3 = ix0 + 9;
      for (int f_k{ix0 + 1}; f_k <= i3; f_k++) {
        (&U[0][0])[f_k - 1] *= r;
      }
    }
    if ((d_q + 1) < 9) {
      double d2;
      d2 = e[d_q];
      if (d2 != 0.0) {
        int b_ix0;
        int i4;
        rt = std::abs(d2);
        r = rt / d2;
        e[d_q] = rt;
        s[d_q + 1] *= r;
        b_ix0 = 9 * (d_q + 1);
        i4 = b_ix0 + 9;
        for (int g_k{b_ix0 + 1}; g_k <= i4; g_k++) {
          (&V[0][0])[g_k - 1] *= r;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[d_q]), std::abs(e[d_q])));
  }
  while (((m + 2) > 0) && (iter < 75)) {
    int e_q;
    int h_ii;
    int kase;
    h_ii = m;
    int exitg1;
    do {
      exitg1 = 0;
      e_q = h_ii + 1;
      if ((h_ii + 1) == 0) {
        exitg1 = 1;
      } else {
        double ztest0;
        ztest0 = std::abs(e[h_ii]);
        if (ztest0 <= (2.2204460492503131E-16 *
                       (std::abs(s[h_ii]) + std::abs(s[h_ii + 1])))) {
          e[h_ii] = 0.0;
          exitg1 = 1;
        } else if ((ztest0 <= 1.0020841800044864E-292) ||
                   ((iter > 20) &&
                    (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
          e[h_ii] = 0.0;
          exitg1 = 1;
        } else {
          h_ii--;
        }
      }
    } while (exitg1 == 0);
    if ((h_ii + 1) == (m + 1)) {
      kase = 4;
    } else {
      int p_ii;
      int qs;
      bool exitg2;
      qs = m + 2;
      p_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (p_ii >= (h_ii + 1))) {
        qs = p_ii;
        if (p_ii == (h_ii + 1)) {
          exitg2 = true;
        } else {
          double test;
          double ztest;
          test = 0.0;
          if (p_ii < (m + 2)) {
            test = std::abs(e[p_ii - 1]);
          }
          if (p_ii > (h_ii + 2)) {
            test += std::abs(e[p_ii - 2]);
          }
          ztest = std::abs(s[p_ii - 1]);
          if ((ztest <= (2.2204460492503131E-16 * test)) ||
              (ztest <= 1.0020841800044864E-292)) {
            s[p_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            p_ii--;
          }
        }
      }
      if (qs == (h_ii + 1)) {
        kase = 3;
      } else if (qs == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        e_q = qs;
      }
    }
    switch (kase) {
    case 1: {
      int i5;
      f = e[m];
      e[m] = 0.0;
      i5 = m + 1;
      for (int i_k{i5}; i_k >= (e_q + 1); i_k--) {
        blas::xrotg(&s[i_k - 1], &f, &b_cs, &sn);
        if (i_k > (e_q + 1)) {
          double b_f_tmp;
          b_f_tmp = e[i_k - 2];
          f = (-sn) * b_f_tmp;
          e[i_k - 2] = b_f_tmp * b_cs;
        }
        blas::b_xrot(V, (9 * (i_k - 1)) + 1, (9 * (m + 1)) + 1, b_cs, sn);
      }
    } break;
    case 2: {
      f = e[e_q - 1];
      e[e_q - 1] = 0.0;
      for (int h_k{e_q + 1}; h_k <= (m + 2); h_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[h_k - 1], &a__1, &c_cs, &b_sn);
        f_tmp = e[h_k - 1];
        f = (-b_sn) * f_tmp;
        e[h_k - 1] = f_tmp * c_cs;
        blas::b_xrot(U, (9 * (h_k - 1)) + 1, (9 * (e_q - 1)) + 1, c_cs, b_sn);
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
                    std::abs(s[e_q])),
          std::abs(e[e_q]));
      sm = scale_tmp / scale;
      smm1 = s[m] / scale;
      emm1 = e[m] / scale;
      sqds = s[e_q] / scale;
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
      g = sqds * (e[e_q] / scale);
      for (int k_k{e_q + 1}; k_k <= mm1; k_k++) {
        double c_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
        if (k_k > (e_q + 1)) {
          e[k_k - 2] = b_f;
        }
        f_tmp_tmp = e[k_k - 1];
        c_f_tmp = s[k_k - 1];
        e[k_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * c_f_tmp);
        a__3 = c_sn * s[k_k];
        s[k_k] *= d_cs;
        blas::b_xrot(V, (9 * (k_k - 1)) + 1, (9 * k_k) + 1, d_cs, c_sn);
        s[k_k - 1] = (d_cs * c_f_tmp) + (c_sn * f_tmp_tmp);
        blas::xrotg(&s[k_k - 1], &a__3, &e_cs, &d_sn);
        f = (e_cs * e[k_k - 1]) + (d_sn * s[k_k]);
        s[k_k] = ((-d_sn) * e[k_k - 1]) + (e_cs * s[k_k]);
        g = d_sn * e[k_k];
        e[k_k] *= e_cs;
        blas::b_xrot(U, (9 * (k_k - 1)) + 1, (9 * k_k) + 1, e_cs, d_sn);
      }
      e[m] = f;
      iter++;
    } break;
    default: {
      if (s[e_q] < 0.0) {
        int c_ix0;
        int i6;
        s[e_q] = -s[e_q];
        c_ix0 = 9 * e_q;
        i6 = c_ix0 + 9;
        for (int j_k{c_ix0 + 1}; j_k <= i6; j_k++) {
          (&V[0][0])[j_k - 1] = -(&V[0][0])[j_k - 1];
        }
      }
      qp1 = e_q + 1;
      while (((e_q + 1) < 9) && (s[e_q] < s[qp1])) {
        rt = s[e_q];
        s[e_q] = s[qp1];
        s[qp1] = rt;
        blas::b_xswap(V, (9 * e_q) + 1, (9 * (e_q + 1)) + 1);
        blas::b_xswap(U, (9 * e_q) + 1, (9 * (e_q + 1)) + 1);
        e_q = qp1;
        qp1++;
      }
      iter = 0;
      m--;
    } break;
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
