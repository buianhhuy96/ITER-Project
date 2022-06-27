//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzggev.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xzggev.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "xztgevc.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : creal_T A[4][4]
//                int *info
//                creal_T alpha1[4]
//                creal_T beta1[4]
//                creal_T V[4][4]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzggev(creal_T A[4][4], int *info, creal_T alpha1[4], creal_T beta1[4],
            creal_T V[4][4])
{
  creal_T s;
  double anrm;
  double c;
  double vtemp;
  double y;
  int rscale[4];
  int b_info;
  int c_i;
  int i4;
  int jr;
  int k;
  bool exitg1;
  *info = 0;
  anrm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16)) {
    double absxk;
    absxk = rt_hypotd_snf((&A[0][0])[k].re, (&A[0][0])[k].im);
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
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i)

    for (int b_i = 0; b_i < 4; b_i++) {
      alpha1[b_i].re = rtNaN;
      alpha1[b_i].im = 0.0;
      beta1[b_i].re = rtNaN;
      beta1[b_i].im = 0.0;
      for (c_i = 0; c_i < 4; c_i++) {
        V[b_i][c_i].re = rtNaN;
        V[b_i][c_i].im = 0.0;
      }
    }
  } else {
    double anrmto;
    double atmp_im;
    double atmp_re;
    int b_ilo;
    int exitg3;
    int ihi;
    bool exitg4;
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
        for (int i1{0}; i1 < 4; i1++) {
          for (int i2{0}; i2 < 4; i2++) {
            A[i1][i2].re *= b_a;
            A[i1][i2].im *= b_a;
          }
        }
      }
    }
    for (int d_i{0}; d_i < 4; d_i++) {
      rscale[d_i] = 1;
    }
    b_ilo = 1;
    ihi = 4;
    int c_ii;
    int e_i;
    int j;
    bool found;
    do {
      exitg3 = 0;
      e_i = 0;
      j = 0;
      found = false;
      c_ii = ihi;
      exitg1 = false;
      while ((!exitg1) && (c_ii > 0)) {
        int jj;
        int nzcount;
        nzcount = 0;
        e_i = c_ii;
        j = ihi;
        jj = 0;
        exitg4 = false;
        while ((!exitg4) && (jj <= (ihi - 1))) {
          if (((A[jj][c_ii - 1].re != 0.0) || (A[jj][c_ii - 1].im != 0.0)) ||
              (c_ii == (jj + 1))) {
            if (nzcount == 0) {
              j = jj + 1;
              nzcount = 1;
              jj++;
            } else {
              nzcount = 2;
              exitg4 = true;
            }
          } else {
            jj++;
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
        if (e_i != ihi) {
          for (int b_k{0}; b_k < 4; b_k++) {
            atmp_re = A[b_k][e_i - 1].re;
            atmp_im = A[b_k][e_i - 1].im;
            A[b_k][e_i - 1] = A[b_k][ihi - 1];
            A[b_k][ihi - 1].re = atmp_re;
            A[b_k][ihi - 1].im = atmp_im;
          }
        }
        if (j != ihi) {
          for (int c_k{0}; c_k < ihi; c_k++) {
            atmp_re = A[j - 1][c_k].re;
            atmp_im = A[j - 1][c_k].im;
            A[j - 1][c_k] = A[ihi - 1][c_k];
            A[ihi - 1][c_k].re = atmp_re;
            A[ihi - 1][c_k].im = atmp_im;
          }
        }
        rscale[ihi - 1] = j;
        ihi--;
        if (ihi == 1) {
          rscale[0] = 1;
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);
    if (exitg3 != 1) {
      int b_j;
      int b_jj;
      int exitg2;
      int g_i;
      bool b_found;
      do {
        exitg2 = 0;
        g_i = 0;
        b_j = 0;
        b_found = false;
        b_jj = b_ilo;
        exitg1 = false;
        while ((!exitg1) && (b_jj <= ihi)) {
          int b_nzcount;
          int e_ii;
          b_nzcount = 0;
          g_i = ihi;
          b_j = b_jj;
          e_ii = b_ilo;
          exitg4 = false;
          while ((!exitg4) && (e_ii <= ihi)) {
            if (((A[b_jj - 1][e_ii - 1].re != 0.0) ||
                 (A[b_jj - 1][e_ii - 1].im != 0.0)) ||
                (e_ii == b_jj)) {
              if (b_nzcount == 0) {
                g_i = e_ii;
                b_nzcount = 1;
                e_ii++;
              } else {
                b_nzcount = 2;
                exitg4 = true;
              }
            } else {
              e_ii++;
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
          if (g_i != b_ilo) {
            for (int e_k{b_ilo}; e_k < 5; e_k++) {
              atmp_re = A[e_k - 1][g_i - 1].re;
              atmp_im = A[e_k - 1][g_i - 1].im;
              A[e_k - 1][g_i - 1] = A[e_k - 1][b_ilo - 1];
              A[e_k - 1][b_ilo - 1].re = atmp_re;
              A[e_k - 1][b_ilo - 1].im = atmp_im;
            }
          }
          if (b_j != b_ilo) {
            for (int g_k{0}; g_k < ihi; g_k++) {
              atmp_re = A[b_j - 1][g_k].re;
              atmp_im = A[b_j - 1][g_k].im;
              A[b_j - 1][g_k] = A[b_ilo - 1][g_k];
              A[b_ilo - 1][g_k].re = atmp_re;
              A[b_ilo - 1][g_k].im = atmp_im;
            }
          }
          rscale[b_ilo - 1] = b_j;
          b_ilo++;
          if (b_ilo == ihi) {
            rscale[b_ilo - 1] = b_ilo;
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int i3 = 0; i3 < 4; i3++) {
      for (i4 = 0; i4 < 4; i4++) {
        V[i3][i4].re = 0.0;
        V[i3][i4].im = 0.0;
      }
    }
    for (int d_k{0}; d_k < 4; d_k++) {
      V[d_k][d_k].re = 1.0;
      V[d_k][d_k].im = 0.0;
    }
    if (ihi >= (b_ilo + 2)) {
      int jcol;
      jcol = b_ilo - 1;
      while ((jcol + 1) < (ihi - 1)) {
        int jcolp1;
        int jrow;
        jcolp1 = jcol + 2;
        jrow = ihi - 1;
        while ((jrow + 1) > (jcol + 2)) {
          xzlartg(A[jcol][jrow - 1], A[jcol][jrow], &c, &s, &A[jcol][jrow - 1]);
          A[jcol][jrow].re = 0.0;
          A[jcol][jrow].im = 0.0;
          for (int c_j{jcolp1}; c_j < 5; c_j++) {
            double s_re_tmp;
            double s_re_tmp_tmp;
            double stemp_im_tmp;
            double stemp_re_tmp;
            s_re_tmp_tmp = A[c_j - 1][jrow].im;
            s_re_tmp = A[c_j - 1][jrow].re;
            stemp_re_tmp = A[c_j - 1][jrow - 1].re;
            stemp_im_tmp = A[c_j - 1][jrow - 1].im;
            A[c_j - 1][jrow].re = (c * s_re_tmp) - ((s.re * stemp_re_tmp) +
                                                    (s.im * stemp_im_tmp));
            A[c_j - 1][jrow].im =
                (c * A[c_j - 1][jrow].im) -
                ((s.re * stemp_im_tmp) - (s.im * stemp_re_tmp));
            A[c_j - 1][jrow - 1].re =
                (c * stemp_re_tmp) +
                ((s.re * s_re_tmp) - (s.im * s_re_tmp_tmp));
            A[c_j - 1][jrow - 1].im =
                (c * stemp_im_tmp) +
                ((s.re * s_re_tmp_tmp) + (s.im * s_re_tmp));
          }
          s.re = -s.re;
          s.im = -s.im;
          for (int m_i{1}; m_i <= ihi; m_i++) {
            double b_s_re_tmp;
            double b_s_re_tmp_tmp;
            double b_stemp_im_tmp;
            double b_stemp_re_tmp;
            b_s_re_tmp_tmp = A[jrow - 1][m_i - 1].im;
            b_s_re_tmp = A[jrow - 1][m_i - 1].re;
            b_stemp_re_tmp = A[jrow][m_i - 1].re;
            b_stemp_im_tmp = A[jrow][m_i - 1].im;
            A[jrow - 1][m_i - 1].re =
                (c * b_s_re_tmp) -
                ((s.re * b_stemp_re_tmp) + (s.im * b_stemp_im_tmp));
            A[jrow - 1][m_i - 1].im =
                (c * A[jrow - 1][m_i - 1].im) -
                ((s.re * b_stemp_im_tmp) - (s.im * b_stemp_re_tmp));
            A[jrow][m_i - 1].re =
                (c * b_stemp_re_tmp) +
                ((s.re * b_s_re_tmp) - (s.im * b_s_re_tmp_tmp));
            A[jrow][m_i - 1].im =
                (c * b_stemp_im_tmp) +
                ((s.re * b_s_re_tmp_tmp) + (s.im * b_s_re_tmp));
          }
          for (int q_i{0}; q_i < 4; q_i++) {
            double c_s_re_tmp;
            double c_stemp_im_tmp;
            double c_stemp_re_tmp;
            double d_s_re_tmp;
            c_s_re_tmp = V[jrow - 1][q_i].im;
            d_s_re_tmp = V[jrow - 1][q_i].re;
            c_stemp_re_tmp = V[jrow][q_i].re;
            c_stemp_im_tmp = V[jrow][q_i].im;
            V[jrow - 1][q_i].re = (c * d_s_re_tmp) - ((s.re * c_stemp_re_tmp) +
                                                      (s.im * c_stemp_im_tmp));
            V[jrow - 1][q_i].im = (c * c_s_re_tmp) - ((s.re * c_stemp_im_tmp) -
                                                      (s.im * c_stemp_re_tmp));
            V[jrow][q_i].re = (c * c_stemp_re_tmp) +
                              ((s.re * d_s_re_tmp) - (s.im * c_s_re_tmp));
            V[jrow][q_i].im = (c * c_stemp_im_tmp) +
                              ((s.re * c_s_re_tmp) + (s.im * d_s_re_tmp));
          }
          jrow--;
        }
        jcol++;
      }
    }
    xzhgeqz(A, b_ilo, ihi, V, &b_info, alpha1, beta1);
    *info = b_info;
    if (b_info == 0) {
      double tmp_im;
      double tmp_re;
      xztgevc(A, V);
      if (b_ilo > 1) {
        int h_i;
        h_i = b_ilo - 2;
        while ((h_i + 1) >= 1) {
          int h_k;
          h_k = rscale[h_i] - 1;
          if (rscale[h_i] != (h_i + 1)) {
            for (int d_j{0}; d_j < 4; d_j++) {
              tmp_re = V[d_j][h_i].re;
              tmp_im = V[d_j][h_i].im;
              V[d_j][h_i] = V[d_j][h_k];
              V[d_j][h_k].re = tmp_re;
              V[d_j][h_k].im = tmp_im;
            }
          }
          h_i--;
        }
      }
      if (ihi < 4) {
        int i5;
        i5 = ihi + 1;
        for (int k_i{i5}; k_i < 5; k_i++) {
          int i6;
          i6 = rscale[k_i - 1];
          if (i6 != k_i) {
            for (int e_j{0}; e_j < 4; e_j++) {
              tmp_re = V[e_j][k_i - 1].re;
              tmp_im = V[e_j][k_i - 1].im;
              V[e_j][k_i - 1] = V[e_j][i6 - 1];
              V[e_j][i6 - 1].re = tmp_re;
              V[e_j][i6 - 1].im = tmp_im;
            }
          }
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(jr, y,     \
                                                                    vtemp)

      for (int jc = 0; jc < 4; jc++) {
        vtemp = std::abs(V[jc][0].re) + std::abs(V[jc][0].im);
        y = std::abs(V[jc][1].re) + std::abs(V[jc][1].im);
        if (y > vtemp) {
          vtemp = y;
        }
        y = std::abs(V[jc][2].re) + std::abs(V[jc][2].im);
        if (y > vtemp) {
          vtemp = y;
        }
        y = std::abs(V[jc][3].re) + std::abs(V[jc][3].im);
        if (y > vtemp) {
          vtemp = y;
        }
        if (vtemp >= 6.7178761075670888E-139) {
          vtemp = 1.0 / vtemp;
          for (jr = 0; jr < 4; jr++) {
            V[jc][jr].re *= vtemp;
            V[jc][jr].im *= vtemp;
          }
        }
      }
      if (ilascl) {
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
          for (int i7{0}; i7 < 4; i7++) {
            alpha1[i7].re *= c_a;
            alpha1[i7].im *= c_a;
          }
        }
      }
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzggev.cpp
//
// [EOF]
//
