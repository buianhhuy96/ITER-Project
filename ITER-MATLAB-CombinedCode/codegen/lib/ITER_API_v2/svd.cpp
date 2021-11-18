//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
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
// Arguments    : const ::coder::array<double, 2U> &d_A
//                ::coder::array<double, 1U> &d_U
// Return Type  : void
//
namespace coder {
namespace internal {
void b_svd(const ::coder::array<double, 2U> &d_A,
           ::coder::array<double, 1U> &d_U)
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
  int h_n;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  e_A.set_size(d_A.size(0), 8);
  loop_ub = d_A.size(0);
  for (int b_i{0}; b_i < 8; b_i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = d_A[i1 + (d_A.size(0) * b_i)];
    }
  }
  h_n = d_A.size(0);
  u0 = d_A.size(0);
  if (u0 <= 8) {
    minnp = u0;
  } else {
    minnp = 8;
  }
  b_u0 = d_A.size(0) + 1;
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
  work.set_size(d_A.size(0));
  b_loop_ub = d_A.size(0);
  for (int i3{0}; i3 < b_loop_ub; i3++) {
    work[i3] = 0.0;
  }
  if (d_A.size(0) != 0) {
    double rt;
    double snorm;
    int c_u0;
    int c_u1;
    int i4;
    int iter;
    int m;
    int mm;
    int nct;
    int nrt;
    c_u1 = d_A.size(0);
    if (6 <= c_u1) {
      nrt = 6;
    } else {
      nrt = c_u1;
    }
    c_u0 = d_A.size(0) - 1;
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
      qq = (q + (h_n * q)) + 1;
      nmq = (h_n - q) - 1;
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
            double a;
            int i6;
            a = 1.0 / d;
            i6 = qq + nmq;
            for (int e_k{qq}; e_k <= i6; e_k++) {
              e_A[e_k - 1] = a * e_A[e_k - 1];
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
        qjj = q + (h_n * (b_jj - 1));
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
          double b_a;
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }
          b_a = e[q];
          if (std::abs(e[q]) >= 1.0020841800044864E-292) {
            double c_a;
            c_a = 1.0 / e[q];
            for (int g_k{qp1_tmp}; g_k < 9; g_k++) {
              e[g_k - 1] *= c_a;
            }
          } else {
            for (int f_k{qp1_tmp}; f_k < 9; f_k++) {
              e[f_k - 1] /= b_a;
            }
          }
          e[q + 1]++;
          e[q] = -e[q];
          if ((q + 2) <= h_n) {
            for (int e_ii{qp1_tmp}; e_ii <= h_n; e_ii++) {
              work[e_ii - 1] = 0.0;
            }
            for (int c_jj{qp1_tmp}; c_jj < 9; c_jj++) {
              double f_a;
              int ix0;
              f_a = e[c_jj - 1];
              ix0 = (q + (h_n * (c_jj - 1))) + 2;
              if ((nmq >= 1) && (!(f_a == 0.0))) {
                int i8;
                i8 = nmq - 1;
                for (int h_k{0}; h_k <= i8; h_k++) {
                  int i10;
                  i10 = (q + h_k) + 1;
                  work[i10] = work[i10] + (f_a * e_A[(ix0 + h_k) - 1]);
                }
              }
            }
            for (int d_jj{qp1_tmp}; d_jj < 9; d_jj++) {
              double g_a;
              int iy0;
              g_a = (-e[d_jj - 1]) / e[q + 1];
              iy0 = (q + (h_n * (d_jj - 1))) + 2;
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
    if (8 <= (d_A.size(0) + 1)) {
      m = 7;
    } else {
      m = d_A.size(0);
    }
    if (nct < 8) {
      s[nct] = e_A[nct + (e_A.size(0) * nct)];
    }
    if (d_A.size(0) < (m + 1)) {
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
        for (int i_k{m}; i_k >= (c_q + 1); i_k--) {
          blas::xrotg(&s[i_k - 1], &f, &b_cs, &sn);
          if (i_k > (c_q + 1)) {
            double f_tmp;
            f_tmp = e[i_k - 2];
            f = (-sn) * f_tmp;
            e[i_k - 2] = f_tmp * b_cs;
          }
        }
      } break;
      case 2: {
        f = e[c_q - 1];
        e[c_q - 1] = 0.0;
        for (int j_k{c_q + 1}; j_k <= (m + 1); j_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[j_k - 1], &a__1, &c_cs, &b_sn);
          b_f_tmp = e[j_k - 1];
          f = (-b_sn) * b_f_tmp;
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
  d_U.set_size(minnp);
  for (int k{0}; k < minnp; k++) {
    d_U[k] = s[k];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &d_A
//                ::coder::array<double, 2U> &d_U
//                ::coder::array<double, 1U> &s
//                double e_V[6][6]
// Return Type  : void
//
void c_svd(const ::coder::array<double, 2U> &d_A,
           ::coder::array<double, 2U> &d_U, ::coder::array<double, 1U> &s,
           double e_V[6][6])
{
  array<double, 2U> e_A;
  array<double, 1U> e_S;
  array<double, 1U> work;
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
  double f;
  double sn;
  int b_loop_ub;
  int b_u0;
  int c_loop_ub;
  int e_loop_ub;
  int h_n;
  int loop_ub;
  int minnp;
  int u0;
  int unnamed_idx_0;
  e_A.set_size(d_A.size(0), 6);
  loop_ub = d_A.size(0);
  for (int b_i{0}; b_i < 6; b_i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = d_A[i1 + (d_A.size(0) * b_i)];
    }
  }
  h_n = d_A.size(0);
  u0 = d_A.size(0);
  if (u0 <= 6) {
    minnp = u0;
  } else {
    minnp = 6;
  }
  b_u0 = d_A.size(0) + 1;
  if (b_u0 <= 6) {
    unnamed_idx_0 = b_u0;
  } else {
    unnamed_idx_0 = 6;
  }
  s.set_size(unnamed_idx_0);
  for (int i2{0}; i2 < unnamed_idx_0; i2++) {
    s[i2] = 0.0;
  }
  for (int c_i{0}; c_i < 6; c_i++) {
    e[c_i] = 0.0;
  }
  work.set_size(d_A.size(0));
  b_loop_ub = d_A.size(0);
  for (int i3{0}; i3 < b_loop_ub; i3++) {
    work[i3] = 0.0;
  }
  d_U.set_size(d_A.size(0), d_A.size(0));
  c_loop_ub = d_A.size(0);
  for (int i4{0}; i4 < c_loop_ub; i4++) {
    int d_loop_ub;
    d_loop_ub = d_A.size(0);
    for (int i5{0}; i5 < d_loop_ub; i5++) {
      d_U[i5 + (d_U.size(0) * i4)] = 0.0;
    }
  }
  (void)std::memset(&e_V[0][0], 0, 36U * (sizeof(double)));
  if (d_A.size(0) == 0) {
    for (int c_ii{0}; c_ii < 6; c_ii++) {
      e_V[c_ii][c_ii] = 1.0;
    }
  } else {
    double b_t;
    double rt;
    double snorm;
    int c_u0;
    int c_u1;
    int i7;
    int iter;
    int m;
    int mm;
    int nct;
    int nctp1;
    int nrt;
    int qjj;
    int qp1;
    int qq;
    c_u1 = d_A.size(0);
    if (4 <= c_u1) {
      nrt = 4;
    } else {
      nrt = c_u1;
    }
    c_u0 = d_A.size(0) - 1;
    if (c_u0 <= 6) {
      nct = c_u0;
    } else {
      nct = 6;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      i7 = nct;
    } else {
      i7 = nrt;
    }
    for (int q{0}; q < i7; q++) {
      double nrm;
      int nmq;
      int qp1_tmp;
      bool apply_transform;
      qp1_tmp = q + 2;
      qq = (q + (h_n * q)) + 1;
      nmq = (h_n - q) - 1;
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
            double a;
            int i9;
            a = 1.0 / d;
            i9 = qq + nmq;
            for (int e_k{qq}; e_k <= i9; e_k++) {
              e_A[e_k - 1] = a * e_A[e_k - 1];
            }
          } else {
            int i8;
            i8 = qq + nmq;
            for (int c_k{qq}; c_k <= i8; c_k++) {
              e_A[c_k - 1] = e_A[c_k - 1] / s[q];
            }
          }
          e_A[qq - 1] = e_A[qq - 1] + 1.0;
          s[q] = -s[q];
        } else {
          s[q] = 0.0;
        }
      }
      for (int b_jj{qp1_tmp}; b_jj < 7; b_jj++) {
        qjj = q + (h_n * (b_jj - 1));
        if (apply_transform) {
          b_t = 0.0;
          if ((nmq + 1) >= 1) {
            for (int b_k{0}; b_k <= nmq; b_k++) {
              b_t += e_A[(qq + b_k) - 1] * e_A[qjj + b_k];
            }
          }
          b_t = -(b_t / e_A[q + (e_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(b_t == 0.0))) {
            for (int d_k{0}; d_k <= nmq; d_k++) {
              int i10;
              i10 = qjj + d_k;
              e_A[i10] = e_A[i10] + (b_t * e_A[(qq + d_k) - 1]);
            }
          }
        }
        e[b_jj - 1] = e_A[qjj];
      }
      if ((q + 1) <= nct) {
        for (int e_ii{q + 1}; e_ii <= h_n; e_ii++) {
          d_U[(e_ii + (d_U.size(0) * q)) - 1] =
              e_A[(e_ii + (e_A.size(0) * q)) - 1];
        }
      }
      if ((q + 1) <= nrt) {
        nrm = blas::c_xnrm2(5 - q, e, q + 2);
        if (nrm == 0.0) {
          e[q] = 0.0;
        } else {
          double b_a;
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }
          b_a = e[q];
          if (std::abs(e[q]) >= 1.0020841800044864E-292) {
            double c_a;
            c_a = 1.0 / e[q];
            for (int g_k{qp1_tmp}; g_k < 7; g_k++) {
              e[g_k - 1] *= c_a;
            }
          } else {
            for (int f_k{qp1_tmp}; f_k < 7; f_k++) {
              e[f_k - 1] /= b_a;
            }
          }
          e[q + 1]++;
          e[q] = -e[q];
          if ((q + 2) <= h_n) {
            for (int q_ii{qp1_tmp}; q_ii <= h_n; q_ii++) {
              work[q_ii - 1] = 0.0;
            }
            for (int f_jj{qp1_tmp}; f_jj < 7; f_jj++) {
              double f_a;
              int b_ix0;
              f_a = e[f_jj - 1];
              b_ix0 = (q + (h_n * (f_jj - 1))) + 2;
              if ((nmq >= 1) && (!(f_a == 0.0))) {
                int i13;
                i13 = nmq - 1;
                for (int m_k{0}; m_k <= i13; m_k++) {
                  int i15;
                  i15 = (q + m_k) + 1;
                  work[i15] = work[i15] + (f_a * e_A[(b_ix0 + m_k) - 1]);
                }
              }
            }
            for (int g_jj{qp1_tmp}; g_jj < 7; g_jj++) {
              double g_a;
              int iy0;
              g_a = (-e[g_jj - 1]) / e[q + 1];
              iy0 = (q + (h_n * (g_jj - 1))) + 2;
              if ((nmq >= 1) && (!(g_a == 0.0))) {
                int i14;
                i14 = nmq - 1;
                for (int o_k{0}; o_k <= i14; o_k++) {
                  int i16;
                  i16 = (iy0 + o_k) - 1;
                  e_A[i16] = e_A[i16] + (g_a * work[(q + o_k) + 1]);
                }
              }
            }
          }
        }
        for (int g_ii{qp1_tmp}; g_ii < 7; g_ii++) {
          e_V[q][g_ii - 1] = e[g_ii - 1];
        }
      }
    }
    if (6 <= (d_A.size(0) + 1)) {
      m = 5;
    } else {
      m = d_A.size(0);
    }
    if (nct < 6) {
      s[nct] = e_A[nct + (e_A.size(0) * nct)];
    }
    if (d_A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = e_A[nrt + (e_A.size(0) * m)];
    }
    e[m] = 0.0;
    if ((nct + 1) <= d_A.size(0)) {
      for (int c_jj{nctp1}; c_jj <= h_n; c_jj++) {
        for (int f_ii{0}; f_ii < h_n; f_ii++) {
          d_U[f_ii + (d_U.size(0) * (c_jj - 1))] = 0.0;
        }
        d_U[(c_jj + (d_U.size(0) * (c_jj - 1))) - 1] = 1.0;
      }
    }
    for (int b_q{nct}; b_q >= 1; b_q--) {
      int nmq_tmp;
      qp1 = b_q + 1;
      nmq_tmp = h_n - b_q;
      qq = (b_q + (h_n * (b_q - 1))) - 1;
      if (s[b_q - 1] != 0.0) {
        for (int d_jj{qp1}; d_jj <= h_n; d_jj++) {
          qjj = b_q + (h_n * (d_jj - 1));
          b_t = 0.0;
          if ((nmq_tmp + 1) >= 1) {
            for (int h_k{0}; h_k <= nmq_tmp; h_k++) {
              b_t += d_U[qq + h_k] * d_U[(qjj + h_k) - 1];
            }
          }
          b_t = -(b_t / d_U[qq]);
          blas::xaxpy(nmq_tmp + 1, b_t, qq + 1, d_U, qjj);
        }
        for (int m_ii{b_q}; m_ii <= h_n; m_ii++) {
          d_U[(m_ii + (d_U.size(0) * (b_q - 1))) - 1] =
              -d_U[(m_ii + (d_U.size(0) * (b_q - 1))) - 1];
        }
        d_U[qq] = d_U[qq] + 1.0;
        for (int p_ii{0}; p_ii <= (b_q - 2); p_ii++) {
          d_U[p_ii + (d_U.size(0) * (b_q - 1))] = 0.0;
        }
      } else {
        for (int k_ii{0}; k_ii < h_n; k_ii++) {
          d_U[k_ii + (d_U.size(0) * (b_q - 1))] = 0.0;
        }
        d_U[qq] = 1.0;
      }
    }
    for (int c_q{5}; c_q >= 0; c_q--) {
      if (((c_q + 1) <= nrt) && (e[c_q] != 0.0)) {
        int qp1q;
        qp1 = c_q + 2;
        qp1q = (c_q + (6 * c_q)) + 2;
        for (int e_jj{qp1}; e_jj < 7; e_jj++) {
          int qp1jj;
          qp1jj = (c_q + (6 * (e_jj - 1))) + 2;
          blas::b_xaxpy(5 - c_q,
                        -(blas::xdotc(5 - c_q, e_V, qp1q, e_V, qp1jj) /
                          (&e_V[0][0])[qp1q - 1]),
                        qp1q, e_V, qp1jj);
        }
      }
      for (int h_ii{0}; h_ii < 6; h_ii++) {
        e_V[c_q][h_ii] = 0.0;
      }
      e_V[c_q][c_q] = 1.0;
    }
    mm = m;
    iter = 0;
    snorm = 0.0;
    for (int d_q{0}; d_q <= m; d_q++) {
      double r;
      if (s[d_q] != 0.0) {
        rt = std::abs(s[d_q]);
        r = s[d_q] / rt;
        s[d_q] = rt;
        if ((d_q + 1) < (m + 1)) {
          e[d_q] /= r;
        }
        if ((d_q + 1) <= h_n) {
          int i11;
          int ix0;
          ix0 = h_n * d_q;
          i11 = ix0 + h_n;
          for (int i_k{ix0 + 1}; i_k <= i11; i_k++) {
            d_U[i_k - 1] = r * d_U[i_k - 1];
          }
        }
      }
      if ((d_q + 1) < (m + 1)) {
        double b_d1;
        b_d1 = e[d_q];
        if (b_d1 != 0.0) {
          int c_ix0;
          int i12;
          rt = std::abs(b_d1);
          r = rt / b_d1;
          e[d_q] = rt;
          s[d_q + 1] = s[d_q + 1] * r;
          c_ix0 = 6 * (d_q + 1);
          i12 = c_ix0 + 6;
          for (int j_k{c_ix0 + 1}; j_k <= i12; j_k++) {
            (&e_V[0][0])[j_k - 1] *= r;
          }
        }
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(s[d_q]), std::abs(e[d_q])));
    }
    while (((m + 1) > 0) && (iter < 75)) {
      int e_q;
      int kase;
      int o_ii;
      bool exitg2;
      o_ii = m;
      int exitg1;
      do {
        exitg1 = 0;
        e_q = o_ii;
        if (o_ii == 0) {
          exitg1 = 1;
        } else {
          double ztest0;
          ztest0 = std::abs(e[o_ii - 1]);
          if (ztest0 <= (2.2204460492503131E-16 *
                         (std::abs(s[o_ii - 1]) + std::abs(s[o_ii])))) {
            e[o_ii - 1] = 0.0;
            exitg1 = 1;
          } else if ((ztest0 <= 1.0020841800044864E-292) ||
                     ((iter > 20) &&
                      (ztest0 <= (2.2204460492503131E-16 * snorm)))) {
            e[o_ii - 1] = 0.0;
            exitg1 = 1;
          } else {
            o_ii--;
          }
        }
      } while (exitg1 == 0);
      if (o_ii == m) {
        kase = 4;
      } else {
        int qs;
        int r_ii;
        qs = m + 1;
        r_ii = m + 1;
        exitg2 = false;
        while ((!exitg2) && (r_ii >= o_ii)) {
          qs = r_ii;
          if (r_ii == o_ii) {
            exitg2 = true;
          } else {
            double test;
            double ztest;
            test = 0.0;
            if (r_ii < (m + 1)) {
              test = std::abs(e[r_ii - 1]);
            }
            if (r_ii > (o_ii + 1)) {
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
        if (qs == o_ii) {
          kase = 3;
        } else if (qs == (m + 1)) {
          kase = 1;
        } else {
          kase = 2;
          e_q = qs;
        }
      }
      switch (kase) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (int p_k{m}; p_k >= (e_q + 1); p_k--) {
          blas::xrotg(&s[p_k - 1], &f, &b_cs, &sn);
          if (p_k > (e_q + 1)) {
            double f_tmp;
            f_tmp = e[p_k - 2];
            f = (-sn) * f_tmp;
            e[p_k - 2] = f_tmp * b_cs;
          }
          blas::xrot(e_V, (6 * (p_k - 1)) + 1, (6 * m) + 1, b_cs, sn);
        }
      } break;
      case 2: {
        f = e[e_q - 1];
        e[e_q - 1] = 0.0;
        for (int q_k{e_q + 1}; q_k <= (m + 1); q_k++) {
          double b_f_tmp;
          a__1 = f;
          blas::xrotg(&s[q_k - 1], &a__1, &c_cs, &b_sn);
          b_f_tmp = e[q_k - 1];
          f = (-b_sn) * b_f_tmp;
          e[q_k - 1] = b_f_tmp * c_cs;
          if (h_n >= 1) {
            int b_ix;
            int c_iy;
            b_ix = h_n * (q_k - 1);
            c_iy = h_n * (e_q - 1);
            for (int s_k{0}; s_k < h_n; s_k++) {
              double temp;
              int b_temp_tmp;
              int temp_tmp;
              temp_tmp = c_iy + s_k;
              b_temp_tmp = b_ix + s_k;
              temp = (c_cs * d_U[b_temp_tmp]) + (b_sn * d_U[temp_tmp]);
              d_U[temp_tmp] = (c_cs * d_U[temp_tmp]) - (b_sn * d_U[b_temp_tmp]);
              d_U[b_temp_tmp] = temp;
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
                      std::abs(s[e_q])),
            std::abs(e[e_q]));
        sm = s[m] / scale;
        smm1 = scale_tmp / scale;
        emm1 = b_scale_tmp / scale;
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
        for (int u_k{e_q + 1}; u_k <= m; u_k++) {
          double c_f_tmp;
          double f_tmp_tmp;
          b_f = f;
          a__2 = g;
          blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
          if (u_k > (e_q + 1)) {
            e[u_k - 2] = b_f;
          }
          f_tmp_tmp = e[u_k - 1];
          c_f_tmp = s[u_k - 1];
          e[u_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * c_f_tmp);
          a__3 = c_sn * s[u_k];
          s[u_k] = s[u_k] * d_cs;
          blas::xrot(e_V, (6 * (u_k - 1)) + 1, (6 * u_k) + 1, d_cs, c_sn);
          s[u_k - 1] = (d_cs * c_f_tmp) + (c_sn * f_tmp_tmp);
          blas::xrotg(&s[u_k - 1], &a__3, &e_cs, &d_sn);
          f = (e_cs * e[u_k - 1]) + (d_sn * s[u_k]);
          s[u_k] = ((-d_sn) * e[u_k - 1]) + (e_cs * s[u_k]);
          g = d_sn * e[u_k];
          e[u_k] *= e_cs;
          if ((u_k < h_n) && (h_n >= 1)) {
            int d_ix;
            int e_iy;
            d_ix = h_n * (u_k - 1);
            e_iy = h_n * u_k;
            for (int v_k{0}; v_k < h_n; v_k++) {
              double c_temp;
              int d_temp_tmp;
              int e_temp_tmp;
              d_temp_tmp = e_iy + v_k;
              e_temp_tmp = d_ix + v_k;
              c_temp = (e_cs * d_U[e_temp_tmp]) + (d_sn * d_U[d_temp_tmp]);
              d_U[d_temp_tmp] =
                  (e_cs * d_U[d_temp_tmp]) - (d_sn * d_U[e_temp_tmp]);
              d_U[e_temp_tmp] = c_temp;
            }
          }
        }
        e[m - 1] = f;
        iter++;
      } break;
      default: {
        if (s[e_q] < 0.0) {
          int d_ix0;
          int i17;
          s[e_q] = -s[e_q];
          d_ix0 = 6 * e_q;
          i17 = d_ix0 + 6;
          for (int r_k{d_ix0 + 1}; r_k <= i17; r_k++) {
            (&e_V[0][0])[r_k - 1] = -(&e_V[0][0])[r_k - 1];
          }
        }
        qp1 = e_q + 1;
        exitg2 = false;
        while ((!exitg2) && ((e_q + 1) < (mm + 1))) {
          if (s[e_q] < s[qp1]) {
            rt = s[e_q];
            s[e_q] = s[qp1];
            s[qp1] = rt;
            if ((e_q + 1) < 6) {
              blas::xswap(e_V, (6 * e_q) + 1, (6 * (e_q + 1)) + 1);
            }
            if ((e_q + 1) < h_n) {
              int c_ix;
              int d_iy;
              c_ix = h_n * e_q;
              d_iy = h_n * (e_q + 1);
              for (int t_k{0}; t_k < h_n; t_k++) {
                double b_temp;
                int c_temp_tmp;
                int i18;
                c_temp_tmp = c_ix + t_k;
                b_temp = d_U[c_temp_tmp];
                i18 = d_iy + t_k;
                d_U[c_temp_tmp] = d_U[i18];
                d_U[i18] = b_temp;
              }
            }
            e_q = qp1;
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
  e_S.set_size(minnp);
  for (int k{0}; k < minnp; k++) {
    e_S[k] = s[k];
  }
  s.set_size(e_S.size(0));
  e_loop_ub = e_S.size(0);
  for (int i6{0}; i6 < e_loop_ub; i6++) {
    s[i6] = e_S[i6];
  }
}

//
// Arguments    : const double d_A[3][3]
//                double d_U[3][3]
//                double s[3]
//                double e_V[3][3]
// Return Type  : void
//
void d_svd(const double d_A[3][3], double d_U[3][3], double s[3],
           double e_V[3][3])
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
    e_A[b_i][0] = d_A[b_i][0];
    d_U[b_i][0] = 0.0;
    e_V[b_i][0] = 0.0;
    e_A[b_i][1] = d_A[b_i][1];
    d_U[b_i][1] = 0.0;
    e_V[b_i][1] = 0.0;
    e_A[b_i][2] = d_A[b_i][2];
    d_U[b_i][2] = 0.0;
    e_V[b_i][2] = 0.0;
  }
  for (int q{0}; q < 2; q++) {
    double nrm;
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (3 * q)) + 1;
    apply_transform = false;
    nrm = blas::d_xnrm2(3 - q, e_A, qq);
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
        double a;
        int i1;
        a = 1.0 / d;
        i1 = (qq - q) + 2;
        for (int b_k{qq}; b_k <= i1; b_k++) {
          (&e_A[0][0])[b_k - 1] *= a;
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
        blas::c_xaxpy(
            3 - q, -(blas::b_xdotc(3 - q, e_A, qq, e_A, qjj + 1) / e_A[q][q]),
            qq, e_A, qjj + 1);
      }
      e[b_jj - 1] = (&e_A[0][0])[qjj];
    }
    for (int c_ii{q + 1}; c_ii < 4; c_ii++) {
      d_U[q][c_ii - 1] = e_A[q][c_ii - 1];
    }
    if ((q + 1) <= 1) {
      nrm = blas::g_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        double b_a;
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        b_a = e[0];
        if (std::abs(e[0]) >= 1.0020841800044864E-292) {
          double c_a;
          c_a = 1.0 / e[0];
          for (int d_k{qp1}; d_k < 4; d_k++) {
            e[d_k - 1] *= c_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 4; c_k++) {
            e[c_k - 1] /= b_a;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (int h_ii{qp1}; h_ii < 4; h_ii++) {
          work[h_ii - 1] = 0.0;
        }
        for (int d_jj{qp1}; d_jj < 4; d_jj++) {
          blas::g_xaxpy(e[d_jj - 1], e_A, (3 * (d_jj - 1)) + 2, work);
        }
        for (int e_jj{qp1}; e_jj < 4; e_jj++) {
          blas::h_xaxpy((-e[e_jj - 1]) / e[1], work, e_A, (3 * (e_jj - 1)) + 2);
        }
      }
      for (int f_ii{qp1}; f_ii < 4; f_ii++) {
        e_V[0][f_ii - 1] = e[f_ii - 1];
      }
    }
  }
  m = 1;
  s[2] = e_A[2][2];
  e[1] = e_A[2][1];
  e[2] = 0.0;
  d_U[2][0] = 0.0;
  d_U[2][1] = 0.0;
  d_U[2][2] = 1.0;
  for (int b_q{1}; b_q >= 0; b_q--) {
    qp1 = b_q + 2;
    qq = b_q + (3 * b_q);
    if (s[b_q] != 0.0) {
      for (int c_jj{qp1}; c_jj < 4; c_jj++) {
        qjj = (b_q + (3 * (c_jj - 1))) + 1;
        blas::c_xaxpy(
            3 - b_q,
            -(blas::b_xdotc(3 - b_q, d_U, qq + 1, d_U, qjj) / (&d_U[0][0])[qq]),
            qq + 1, d_U, qjj);
      }
      for (int e_ii{b_q + 1}; e_ii < 4; e_ii++) {
        d_U[b_q][e_ii - 1] = -d_U[b_q][e_ii - 1];
      }
      (&d_U[0][0])[qq]++;
      if (0 <= (b_q - 1)) {
        d_U[b_q][0] = 0.0;
      }
    } else {
      d_U[b_q][0] = 0.0;
      d_U[b_q][1] = 0.0;
      d_U[b_q][2] = 0.0;
      (&d_U[0][0])[qq] = 1.0;
    }
  }
  for (int c_q{2}; c_q >= 0; c_q--) {
    if (((c_q + 1) <= 1) && (e[0] != 0.0)) {
      blas::c_xaxpy(2, -(blas::b_xdotc(2, e_V, 2, e_V, 5) / (&e_V[0][0])[1]), 2,
                    e_V, 5);
      blas::c_xaxpy(2, -(blas::b_xdotc(2, e_V, 2, e_V, 8) / (&e_V[0][0])[1]), 2,
                    e_V, 8);
    }
    e_V[c_q][0] = 0.0;
    e_V[c_q][1] = 0.0;
    e_V[c_q][2] = 0.0;
    e_V[c_q][c_q] = 1.0;
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
      for (int e_k{ix0 + 1}; e_k <= i2; e_k++) {
        (&d_U[0][0])[e_k - 1] *= r;
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
        for (int f_k{b_ix0 + 1}; f_k <= i3; f_k++) {
          (&e_V[0][0])[f_k - 1] *= r;
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
      for (int h_k{i4}; h_k >= (e_q + 1); h_k--) {
        blas::xrotg(&s[h_k - 1], &f, &b_cs, &sn);
        if (h_k > (e_q + 1)) {
          f = (-sn) * e[0];
          e[0] *= b_cs;
        }
        blas::b_xrot(e_V, (3 * (h_k - 1)) + 1, (3 * (m + 1)) + 1, b_cs, sn);
      }
    } break;
    case 2: {
      f = e[e_q - 1];
      e[e_q - 1] = 0.0;
      for (int g_k{e_q + 1}; g_k <= (m + 2); g_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[g_k - 1], &a__1, &c_cs, &b_sn);
        f_tmp = e[g_k - 1];
        f = (-b_sn) * f_tmp;
        e[g_k - 1] = f_tmp * c_cs;
        blas::b_xrot(d_U, (3 * (g_k - 1)) + 1, (3 * (e_q - 1)) + 1, c_cs, b_sn);
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
      for (int j_k{e_q + 1}; j_k <= mm1; j_k++) {
        double b_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
        if (j_k > (e_q + 1)) {
          e[0] = b_f;
        }
        f_tmp_tmp = e[j_k - 1];
        b_f_tmp = s[j_k - 1];
        e[j_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * b_f_tmp);
        a__3 = c_sn * s[j_k];
        s[j_k] *= d_cs;
        blas::b_xrot(e_V, (3 * (j_k - 1)) + 1, (3 * j_k) + 1, d_cs, c_sn);
        s[j_k - 1] = (d_cs * b_f_tmp) + (c_sn * f_tmp_tmp);
        blas::xrotg(&s[j_k - 1], &a__3, &e_cs, &d_sn);
        f = (e_cs * e[j_k - 1]) + (d_sn * s[j_k]);
        s[j_k] = ((-d_sn) * e[j_k - 1]) + (e_cs * s[j_k]);
        g = d_sn * e[j_k];
        e[j_k] *= e_cs;
        blas::b_xrot(d_U, (3 * (j_k - 1)) + 1, (3 * j_k) + 1, e_cs, d_sn);
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
        for (int i_k{c_ix0 + 1}; i_k <= i5; i_k++) {
          (&e_V[0][0])[i_k - 1] = -(&e_V[0][0])[i_k - 1];
        }
      }
      qp1 = e_q + 1;
      while (((e_q + 1) < 3) && (s[e_q] < s[qp1])) {
        rt = s[e_q];
        s[e_q] = s[qp1];
        s[qp1] = rt;
        blas::b_xswap(e_V, (3 * e_q) + 1, (3 * (e_q + 1)) + 1);
        blas::b_xswap(d_U, (3 * e_q) + 1, (3 * (e_q + 1)) + 1);
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
// Arguments    : const double d_A[9][9]
//                double d_U[9][9]
//                double s[9]
//                double e_V[9][9]
// Return Type  : void
//
void e_svd(const double d_A[9][9], double d_U[9][9], double s[9],
           double e_V[9][9])
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
      e_A[b_i][c_i] = d_A[b_i][c_i];
      d_U[b_i][c_i] = 0.0;
      e_V[b_i][c_i] = 0.0;
    }
  }
  for (int q{0}; q < 8; q++) {
    double nrm;
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (9 * q)) + 1;
    apply_transform = false;
    nrm = blas::e_xnrm2(9 - q, e_A, qq);
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
        double a;
        int i2;
        a = 1.0 / d;
        i2 = (qq - q) + 8;
        for (int b_k{qq}; b_k <= i2; b_k++) {
          (&e_A[0][0])[b_k - 1] *= a;
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
        blas::d_xaxpy(
            9 - q, -(blas::c_xdotc(9 - q, e_A, qq, e_A, qjj + 1) / e_A[q][q]),
            qq, e_A, qjj + 1);
      }
      e[b_jj - 1] = (&e_A[0][0])[qjj];
    }
    for (int c_ii{q + 1}; c_ii < 10; c_ii++) {
      d_U[q][c_ii - 1] = e_A[q][c_ii - 1];
    }
    if ((q + 1) <= 7) {
      nrm = blas::f_xnrm2(8 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        double b_a;
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        b_a = e[q];
        if (std::abs(e[q]) >= 1.0020841800044864E-292) {
          double c_a;
          c_a = 1.0 / e[q];
          for (int d_k{qp1}; d_k < 10; d_k++) {
            e[d_k - 1] *= c_a;
          }
        } else {
          for (int c_k{qp1}; c_k < 10; c_k++) {
            e[c_k - 1] /= b_a;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (int o_ii{qp1}; o_ii < 10; o_ii++) {
          work[o_ii - 1] = 0.0;
        }
        for (int e_jj{qp1}; e_jj < 10; e_jj++) {
          blas::e_xaxpy(8 - q, e[e_jj - 1], e_A, (q + (9 * (e_jj - 1))) + 2,
                        work, q + 2);
        }
        for (int f_jj{qp1}; f_jj < 10; f_jj++) {
          blas::f_xaxpy(8 - q, (-e[f_jj - 1]) / e[q + 1], work, q + 2, e_A,
                        (q + (9 * (f_jj - 1))) + 2);
        }
      }
      for (int m_ii{qp1}; m_ii < 10; m_ii++) {
        e_V[q][m_ii - 1] = e[m_ii - 1];
      }
    }
  }
  m = 7;
  s[8] = e_A[8][8];
  e[7] = e_A[8][7];
  e[8] = 0.0;
  (void)std::memset(&d_U[8][0], 0, 9U * (sizeof(double)));
  d_U[8][8] = 1.0;
  for (int b_q{7}; b_q >= 0; b_q--) {
    qp1 = b_q + 2;
    qq = b_q + (9 * b_q);
    if (s[b_q] != 0.0) {
      for (int c_jj{qp1}; c_jj < 10; c_jj++) {
        qjj = (b_q + (9 * (c_jj - 1))) + 1;
        blas::d_xaxpy(
            9 - b_q,
            -(blas::c_xdotc(9 - b_q, d_U, qq + 1, d_U, qjj) / (&d_U[0][0])[qq]),
            qq + 1, d_U, qjj);
      }
      for (int g_ii{b_q + 1}; g_ii < 10; g_ii++) {
        d_U[b_q][g_ii - 1] = -d_U[b_q][g_ii - 1];
      }
      (&d_U[0][0])[qq]++;
      for (int k_ii{0}; k_ii < b_q; k_ii++) {
        d_U[b_q][k_ii] = 0.0;
      }
    } else {
      for (int e_ii{0}; e_ii < 9; e_ii++) {
        d_U[b_q][e_ii] = 0.0;
      }
      (&d_U[0][0])[qq] = 1.0;
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
        blas::d_xaxpy(8 - c_q,
                      -(blas::c_xdotc(8 - c_q, e_V, qp1q, e_V, qp1jj) /
                        (&e_V[0][0])[qp1q - 1]),
                      qp1q, e_V, qp1jj);
      }
    }
    for (int f_ii{0}; f_ii < 9; f_ii++) {
      e_V[c_q][f_ii] = 0.0;
    }
    e_V[c_q][c_q] = 1.0;
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
      for (int e_k{ix0 + 1}; e_k <= i3; e_k++) {
        (&d_U[0][0])[e_k - 1] *= r;
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
        for (int f_k{b_ix0 + 1}; f_k <= i4; f_k++) {
          (&e_V[0][0])[f_k - 1] *= r;
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
      for (int h_k{i5}; h_k >= (e_q + 1); h_k--) {
        blas::xrotg(&s[h_k - 1], &f, &b_cs, &sn);
        if (h_k > (e_q + 1)) {
          double b_f_tmp;
          b_f_tmp = e[h_k - 2];
          f = (-sn) * b_f_tmp;
          e[h_k - 2] = b_f_tmp * b_cs;
        }
        blas::c_xrot(e_V, (9 * (h_k - 1)) + 1, (9 * (m + 1)) + 1, b_cs, sn);
      }
    } break;
    case 2: {
      f = e[e_q - 1];
      e[e_q - 1] = 0.0;
      for (int g_k{e_q + 1}; g_k <= (m + 2); g_k++) {
        double f_tmp;
        a__1 = f;
        blas::xrotg(&s[g_k - 1], &a__1, &c_cs, &b_sn);
        f_tmp = e[g_k - 1];
        f = (-b_sn) * f_tmp;
        e[g_k - 1] = f_tmp * c_cs;
        blas::c_xrot(d_U, (9 * (g_k - 1)) + 1, (9 * (e_q - 1)) + 1, c_cs, b_sn);
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
      for (int j_k{e_q + 1}; j_k <= mm1; j_k++) {
        double c_f_tmp;
        double f_tmp_tmp;
        b_f = f;
        a__2 = g;
        blas::xrotg(&b_f, &a__2, &d_cs, &c_sn);
        if (j_k > (e_q + 1)) {
          e[j_k - 2] = b_f;
        }
        f_tmp_tmp = e[j_k - 1];
        c_f_tmp = s[j_k - 1];
        e[j_k - 1] = (d_cs * f_tmp_tmp) - (c_sn * c_f_tmp);
        a__3 = c_sn * s[j_k];
        s[j_k] *= d_cs;
        blas::c_xrot(e_V, (9 * (j_k - 1)) + 1, (9 * j_k) + 1, d_cs, c_sn);
        s[j_k - 1] = (d_cs * c_f_tmp) + (c_sn * f_tmp_tmp);
        blas::xrotg(&s[j_k - 1], &a__3, &e_cs, &d_sn);
        f = (e_cs * e[j_k - 1]) + (d_sn * s[j_k]);
        s[j_k] = ((-d_sn) * e[j_k - 1]) + (e_cs * s[j_k]);
        g = d_sn * e[j_k];
        e[j_k] *= e_cs;
        blas::c_xrot(d_U, (9 * (j_k - 1)) + 1, (9 * j_k) + 1, e_cs, d_sn);
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
        for (int i_k{c_ix0 + 1}; i_k <= i6; i_k++) {
          (&e_V[0][0])[i_k - 1] = -(&e_V[0][0])[i_k - 1];
        }
      }
      qp1 = e_q + 1;
      while (((e_q + 1) < 9) && (s[e_q] < s[qp1])) {
        rt = s[e_q];
        s[e_q] = s[qp1];
        s[qp1] = rt;
        blas::c_xswap(e_V, (9 * e_q) + 1, (9 * (e_q + 1)) + 1);
        blas::c_xswap(d_U, (9 * e_q) + 1, (9 * (e_q + 1)) + 1);
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
