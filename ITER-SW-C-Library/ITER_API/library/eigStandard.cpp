//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eigStandard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "eigStandard.h"
#include "ITER_API_data.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "coder_array.h"
#include "rtGetNaN.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<creal_T, 1U> &V
// Return Type  : void
//
namespace ITER {
namespace coder {
void eigStandard(const ::coder::array<double, 2U> &A,
                 ::coder::array<creal_T, 1U> &V)
{
  static creal_T dc{
      0.0, // re
      0.0  // im
  };
  ::coder::array<creal_T, 2U> At;
  ::coder::array<creal_T, 1U> alpha1;
  ::coder::array<creal_T, 1U> beta1;
  creal_T e_s;
  double b_ar;
  double b_bim;
  double b_brm;
  double b_s;
  double b_sgnbi;
  double b_sgnbr;
  double c;
  double c_ai;
  double c_br;
  double c_d;
  double d_bi;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i1;
  int info;
  int loop_ub;
  dc.re = rtGetNaN();
  At.set_size(A.size(0), A.size(1));
  loop_ub = A.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    c_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    c_loop_ub = A.size(0);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      At[i1 + (At.size(0) * b_i)].re = A[i1 + (A.size(0) * b_i)];
      At[i1 + (At.size(0) * b_i)].im = 0.0;
    }
  }
  alpha1.set_size(At.size(0));
  b_loop_ub = At.size(0);
  if ((static_cast<int>(At.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      alpha1[i2].re = 0.0;
      alpha1[i2].im = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      alpha1[i2].re = 0.0;
      alpha1[i2].im = 0.0;
    }
  }
  beta1.set_size(At.size(0));
  d_loop_ub = At.size(0);
  if ((static_cast<int>(At.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      beta1[i3].re = 0.0;
      beta1[i3].im = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < d_loop_ub; i3++) {
      beta1[i3].re = 0.0;
      beta1[i3].im = 0.0;
    }
  }
  if ((At.size(0) != 0) && (At.size(1) != 0)) {
    double anrm;
    int k;
    bool exitg1;
    anrm = 0.0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= ((At.size(0) * At.size(1)) - 1))) {
      double absxk;
      absxk = rt_hypotd_snf(At[k].re, At[k].im);
      if (std::isnan(absxk)) {
        anrm = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > anrm) {
          anrm = absxk;
        }
        k++;
      }
    }
    if ((std::isinf(anrm)) || (std::isnan(anrm))) {
      int f_loop_ub;
      int g_loop_ub;
      alpha1.set_size(At.size(0));
      f_loop_ub = At.size(0);
      if ((static_cast<int>(At.size(0) < 4)) != 0) {
        for (int i5{0}; i5 < f_loop_ub; i5++) {
          alpha1[i5] = dc;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i5 = 0; i5 < f_loop_ub; i5++) {
          alpha1[i5] = dc;
        }
      }
      beta1.set_size(At.size(0));
      g_loop_ub = At.size(0);
      if ((static_cast<int>(At.size(0) < 4)) != 0) {
        for (int i6{0}; i6 < g_loop_ub; i6++) {
          beta1[i6] = dc;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i6 = 0; i6 < g_loop_ub; i6++) {
          beta1[i6] = dc;
        }
      }
    } else {
      double anrmto;
      int b_ihi;
      int b_ilo;
      int h_n;
      bool guard1{false};
      bool ilascl;
      ilascl = false;
      anrmto = anrm;
      guard1 = false;
      if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
        anrmto = 6.7178761075670888E-139;
        ilascl = true;
        guard1 = true;
      } else if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
        guard1 = true;
      } else {
        /* no actions */
      }
      if (guard1) {
        double cfromc;
        double ctoc;
        bool notdone;
        cfromc = anrm;
        ctoc = anrmto;
        notdone = true;
        while (notdone) {
          double b_a;
          double cfrom1;
          double cto1;
          int h_loop_ub;
          cfrom1 = cfromc * 2.0041683600089728E-292;
          cto1 = ctoc / 4.9896007738368E+291;
          if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
            b_a = 2.0041683600089728E-292;
            cfromc = cfrom1;
          } else if (cto1 > cfromc) {
            b_a = 4.9896007738368E+291;
            ctoc = cto1;
          } else {
            b_a = ctoc / cfromc;
            notdone = false;
          }
          h_loop_ub = At.size(1);
          for (int i7{0}; i7 < h_loop_ub; i7++) {
            int i_loop_ub;
            i_loop_ub = At.size(0);
            for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
              At[b_i8 + (At.size(0) * i7)].re =
                  b_a * At[b_i8 + (At.size(0) * i7)].re;
              At[b_i8 + (At.size(0) * i7)].im =
                  b_a * At[b_i8 + (At.size(0) * i7)].im;
            }
          }
        }
      }
      b_ilo = 1;
      b_ihi = At.size(0);
      if (At.size(0) <= 1) {
        b_ihi = 1;
      } else {
        double atmp_im;
        double atmp_re;
        int c_i;
        int c_ii;
        int exitg3;
        int j;
        bool b_guard1{false};
        bool exitg4;
        bool found;
        do {
          exitg3 = 0;
          c_i = 0;
          j = 0;
          found = false;
          c_ii = b_ihi;
          exitg1 = false;
          while ((!exitg1) && (c_ii > 0)) {
            int jj;
            int nzcount;
            nzcount = 0;
            c_i = c_ii;
            j = b_ihi;
            jj = 0;
            exitg4 = false;
            while ((!exitg4) && (jj <= (b_ihi - 1))) {
              b_guard1 = false;
              if ((At[(c_ii + (At.size(0) * jj)) - 1].re != 0.0) ||
                  (At[(c_ii + (At.size(0) * jj)) - 1].im != 0.0)) {
                b_guard1 = true;
              } else if (c_ii == (jj + 1)) {
                b_guard1 = true;
              } else {
                jj++;
              }
              if (b_guard1) {
                if (nzcount == 0) {
                  j = jj + 1;
                  nzcount = 1;
                  jj++;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              }
            }
            if (nzcount < 2) {
              found = true;
              exitg1 = true;
            } else {
              c_ii--;
            }
          }
          if (!found) {
            exitg3 = 2;
          } else {
            int p_n;
            p_n = At.size(0);
            if (c_i != b_ihi) {
              for (int b_k{1}; b_k <= p_n; b_k++) {
                atmp_re = At[(c_i + (At.size(0) * (b_k - 1))) - 1].re;
                atmp_im = At[(c_i + (At.size(0) * (b_k - 1))) - 1].im;
                At[(c_i + (At.size(0) * (b_k - 1))) - 1] =
                    At[(b_ihi + (At.size(0) * (b_k - 1))) - 1];
                At[(b_ihi + (At.size(0) * (b_k - 1))) - 1].re = atmp_re;
                At[(b_ihi + (At.size(0) * (b_k - 1))) - 1].im = atmp_im;
              }
            }
            if (j != b_ihi) {
              for (int c_k{0}; c_k < b_ihi; c_k++) {
                atmp_re = At[c_k + (At.size(0) * (j - 1))].re;
                atmp_im = At[c_k + (At.size(0) * (j - 1))].im;
                At[c_k + (At.size(0) * (j - 1))] =
                    At[c_k + (At.size(0) * (b_ihi - 1))];
                At[c_k + (At.size(0) * (b_ihi - 1))].re = atmp_re;
                At[c_k + (At.size(0) * (b_ihi - 1))].im = atmp_im;
              }
            }
            b_ihi--;
            if (b_ihi == 1) {
              exitg3 = 1;
            }
          }
        } while (exitg3 == 0);
        if (exitg3 != 1) {
          int b_jj;
          int c_j;
          int d_i;
          int exitg2;
          bool b_found;
          do {
            exitg2 = 0;
            d_i = 0;
            c_j = 0;
            b_found = false;
            b_jj = b_ilo;
            exitg1 = false;
            while ((!exitg1) && (b_jj <= b_ihi)) {
              int b_nzcount;
              int e_ii;
              b_nzcount = 0;
              d_i = b_ihi;
              c_j = b_jj;
              e_ii = b_ilo;
              exitg4 = false;
              while ((!exitg4) && (e_ii <= b_ihi)) {
                b_guard1 = false;
                if ((At[(e_ii + (At.size(0) * (b_jj - 1))) - 1].re != 0.0) ||
                    (At[(e_ii + (At.size(0) * (b_jj - 1))) - 1].im != 0.0)) {
                  b_guard1 = true;
                } else if (e_ii == b_jj) {
                  b_guard1 = true;
                } else {
                  e_ii++;
                }
                if (b_guard1) {
                  if (b_nzcount == 0) {
                    d_i = e_ii;
                    b_nzcount = 1;
                    e_ii++;
                  } else {
                    b_nzcount = 2;
                    exitg4 = true;
                  }
                }
              }
              if (b_nzcount < 2) {
                b_found = true;
                exitg1 = true;
              } else {
                b_jj++;
              }
            }
            if (!b_found) {
              exitg2 = 1;
            } else {
              int q_n;
              q_n = At.size(0);
              if (d_i != b_ilo) {
                for (int d_k{b_ilo}; d_k <= q_n; d_k++) {
                  atmp_re = At[(d_i + (At.size(0) * (d_k - 1))) - 1].re;
                  atmp_im = At[(d_i + (At.size(0) * (d_k - 1))) - 1].im;
                  At[(d_i + (At.size(0) * (d_k - 1))) - 1] =
                      At[(b_ilo + (At.size(0) * (d_k - 1))) - 1];
                  At[(b_ilo + (At.size(0) * (d_k - 1))) - 1].re = atmp_re;
                  At[(b_ilo + (At.size(0) * (d_k - 1))) - 1].im = atmp_im;
                }
              }
              if (c_j != b_ilo) {
                for (int e_k{0}; e_k < b_ihi; e_k++) {
                  atmp_re = At[e_k + (At.size(0) * (c_j - 1))].re;
                  atmp_im = At[e_k + (At.size(0) * (c_j - 1))].im;
                  At[e_k + (At.size(0) * (c_j - 1))] =
                      At[e_k + (At.size(0) * (b_ilo - 1))];
                  At[e_k + (At.size(0) * (b_ilo - 1))].re = atmp_re;
                  At[e_k + (At.size(0) * (b_ilo - 1))].im = atmp_im;
                }
              }
              b_ilo++;
              if (b_ilo == b_ihi) {
                exitg2 = 1;
              }
            }
          } while (exitg2 == 0);
        }
      }
      h_n = At.size(0);
      if (At.size(0) > 1) {
        if (b_ihi >= (b_ilo + 2)) {
          int jcol;
          jcol = b_ilo - 1;
          while ((jcol + 1) < (b_ihi - 1)) {
            int jcolp1;
            int jrow;
            jcolp1 = jcol + 2;
            jrow = b_ihi - 1;
            while ((jrow + 1) > (jcol + 2)) {
              internal::reflapack::xzlartg(
                  At[(jrow + (At.size(0) * jcol)) - 1],
                  At[jrow + (At.size(0) * jcol)], &c, &e_s,
                  &At[(jrow + (At.size(0) * jcol)) - 1]);
              At[jrow + (At.size(0) * jcol)].re = 0.0;
              At[jrow + (At.size(0) * jcol)].im = 0.0;
              for (int b_j{jcolp1}; b_j <= h_n; b_j++) {
                double b_s_re_tmp;
                double s_re_tmp;
                double stemp_im_tmp;
                double stemp_re_tmp;
                s_re_tmp = At[jrow + (At.size(0) * (b_j - 1))].im;
                b_s_re_tmp = At[jrow + (At.size(0) * (b_j - 1))].re;
                stemp_re_tmp = At[(jrow + (At.size(0) * (b_j - 1))) - 1].re;
                stemp_im_tmp = At[(jrow + (At.size(0) * (b_j - 1))) - 1].im;
                At[jrow + (At.size(0) * (b_j - 1))].re =
                    (c * b_s_re_tmp) -
                    ((e_s.re * stemp_re_tmp) + (e_s.im * stemp_im_tmp));
                At[jrow + (At.size(0) * (b_j - 1))].im =
                    (c * s_re_tmp) -
                    ((e_s.re * stemp_im_tmp) - (e_s.im * stemp_re_tmp));
                At[(jrow + (At.size(0) * (b_j - 1))) - 1].re =
                    (c * stemp_re_tmp) +
                    ((e_s.re * b_s_re_tmp) - (e_s.im * s_re_tmp));
                At[(jrow + (At.size(0) * (b_j - 1))) - 1].im =
                    (c * stemp_im_tmp) +
                    ((e_s.re * s_re_tmp) + (e_s.im * b_s_re_tmp));
              }
              e_s.re = -e_s.re;
              e_s.im = -e_s.im;
              for (int e_i{1}; e_i <= b_ihi; e_i++) {
                double b_stemp_im_tmp;
                double b_stemp_re_tmp;
                double c_s_re_tmp;
                double d_s_re_tmp;
                c_s_re_tmp = At[(e_i + (At.size(0) * (jrow - 1))) - 1].im;
                d_s_re_tmp = At[(e_i + (At.size(0) * (jrow - 1))) - 1].re;
                b_stemp_re_tmp = At[(e_i + (At.size(0) * jrow)) - 1].re;
                b_stemp_im_tmp = At[(e_i + (At.size(0) * jrow)) - 1].im;
                At[(e_i + (At.size(0) * (jrow - 1))) - 1].re =
                    (c * d_s_re_tmp) -
                    ((e_s.re * b_stemp_re_tmp) + (e_s.im * b_stemp_im_tmp));
                At[(e_i + (At.size(0) * (jrow - 1))) - 1].im =
                    (c * c_s_re_tmp) -
                    ((e_s.re * b_stemp_im_tmp) - (e_s.im * b_stemp_re_tmp));
                At[(e_i + (At.size(0) * jrow)) - 1].re =
                    (c * b_stemp_re_tmp) +
                    ((e_s.re * d_s_re_tmp) - (e_s.im * c_s_re_tmp));
                At[(e_i + (At.size(0) * jrow)) - 1].im =
                    (c * b_stemp_im_tmp) +
                    ((e_s.re * c_s_re_tmp) + (e_s.im * d_s_re_tmp));
              }
              jrow--;
            }
            jcol++;
          }
        }
      }
      internal::reflapack::xzhgeqz(At, b_ilo, b_ihi, &info, alpha1, beta1);
      if ((info == 0) && ilascl) {
        double b_cfromc;
        double b_ctoc;
        bool b_notdone;
        b_cfromc = anrmto;
        b_ctoc = anrm;
        b_notdone = true;
        while (b_notdone) {
          double b_cfrom1;
          double b_cto1;
          double c_a;
          int j_loop_ub;
          b_cfrom1 = b_cfromc * 2.0041683600089728E-292;
          b_cto1 = b_ctoc / 4.9896007738368E+291;
          if ((b_cfrom1 > b_ctoc) && (b_ctoc != 0.0)) {
            c_a = 2.0041683600089728E-292;
            b_cfromc = b_cfrom1;
          } else if (b_cto1 > b_cfromc) {
            c_a = 4.9896007738368E+291;
            b_ctoc = b_cto1;
          } else {
            c_a = b_ctoc / b_cfromc;
            b_notdone = false;
          }
          j_loop_ub = alpha1.size(0);
          for (int i9{0}; i9 < j_loop_ub; i9++) {
            alpha1[i9].re = c_a * alpha1[i9].re;
            alpha1[i9].im = c_a * alpha1[i9].im;
          }
        }
      }
    }
  }
  V.set_size(alpha1.size(0));
  e_loop_ub = alpha1.size(0);
  if ((static_cast<int>(alpha1.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < e_loop_ub; i4++) {
      double ar;
      double b_ai;
      double b_br;
      double c_bi;
      ar = alpha1[i4].re;
      b_ai = alpha1[i4].im;
      b_br = beta1[i4].re;
      c_bi = beta1[i4].im;
      if (c_bi == 0.0) {
        if (b_ai == 0.0) {
          V[i4].re = ar / b_br;
          V[i4].im = 0.0;
        } else if (ar == 0.0) {
          V[i4].re = 0.0;
          V[i4].im = b_ai / b_br;
        } else {
          V[i4].re = ar / b_br;
          V[i4].im = b_ai / b_br;
        }
      } else if (b_br == 0.0) {
        if (ar == 0.0) {
          V[i4].re = b_ai / c_bi;
          V[i4].im = 0.0;
        } else if (b_ai == 0.0) {
          V[i4].re = 0.0;
          V[i4].im = -(ar / c_bi);
        } else {
          V[i4].re = b_ai / c_bi;
          V[i4].im = -(ar / c_bi);
        }
      } else {
        double bim;
        double brm;
        brm = std::abs(b_br);
        bim = std::abs(c_bi);
        if (brm > bim) {
          double d;
          double s;
          s = c_bi / b_br;
          d = b_br + (s * c_bi);
          V[i4].re = (ar + (s * b_ai)) / d;
          V[i4].im = (b_ai - (s * ar)) / d;
        } else if (bim == brm) {
          double sgnbi;
          double sgnbr;
          if (b_br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }
          if (c_bi > 0.0) {
            sgnbi = 0.5;
          } else {
            sgnbi = -0.5;
          }
          V[i4].re = ((ar * sgnbr) + (b_ai * sgnbi)) / brm;
          V[i4].im = ((b_ai * sgnbr) - (ar * sgnbi)) / brm;
        } else {
          double d;
          double s;
          s = b_br / c_bi;
          d = c_bi + (s * b_br);
          V[i4].re = ((s * ar) + b_ai) / d;
          V[i4].im = ((s * b_ai) - ar) / d;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_ar, c_ai, c_br, d_bi, b_brm, b_bim, b_s, c_d, b_sgnbr, b_sgnbi)

    for (int i4 = 0; i4 < e_loop_ub; i4++) {
      b_ar = alpha1[i4].re;
      c_ai = alpha1[i4].im;
      c_br = beta1[i4].re;
      d_bi = beta1[i4].im;
      if (d_bi == 0.0) {
        if (c_ai == 0.0) {
          V[i4].re = b_ar / c_br;
          V[i4].im = 0.0;
        } else if (b_ar == 0.0) {
          V[i4].re = 0.0;
          V[i4].im = c_ai / c_br;
        } else {
          V[i4].re = b_ar / c_br;
          V[i4].im = c_ai / c_br;
        }
      } else if (c_br == 0.0) {
        if (b_ar == 0.0) {
          V[i4].re = c_ai / d_bi;
          V[i4].im = 0.0;
        } else if (c_ai == 0.0) {
          V[i4].re = 0.0;
          V[i4].im = -(b_ar / d_bi);
        } else {
          V[i4].re = c_ai / d_bi;
          V[i4].im = -(b_ar / d_bi);
        }
      } else {
        b_brm = std::abs(c_br);
        b_bim = std::abs(d_bi);
        if (b_brm > b_bim) {
          b_s = d_bi / c_br;
          c_d = c_br + (b_s * d_bi);
          V[i4].re = (b_ar + (b_s * c_ai)) / c_d;
          V[i4].im = (c_ai - (b_s * b_ar)) / c_d;
        } else if (b_bim == b_brm) {
          if (c_br > 0.0) {
            b_sgnbr = 0.5;
          } else {
            b_sgnbr = -0.5;
          }
          if (d_bi > 0.0) {
            b_sgnbi = 0.5;
          } else {
            b_sgnbi = -0.5;
          }
          V[i4].re = ((b_ar * b_sgnbr) + (c_ai * b_sgnbi)) / b_brm;
          V[i4].im = ((c_ai * b_sgnbr) - (b_ar * b_sgnbi)) / b_brm;
        } else {
          b_s = c_br / d_bi;
          c_d = d_bi + (b_s * c_br);
          V[i4].re = ((b_s * b_ar) + c_ai) / c_d;
          V[i4].im = ((b_s * c_ai) - b_ar) / c_d;
        }
      }
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for eigStandard.cpp
//
// [EOF]
//
