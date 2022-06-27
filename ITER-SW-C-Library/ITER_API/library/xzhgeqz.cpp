//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xzhgeqz.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlartg.h"
#include "rtGetNaN.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : creal_T A[4][4]
//                int b_ilo
//                int ihi
//                creal_T b_Z[4][4]
//                int *info
//                creal_T alpha1[4]
//                creal_T beta1[4]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzhgeqz(creal_T A[4][4], int b_ilo, int ihi, creal_T b_Z[4][4], int *info,
             creal_T alpha1[4], creal_T beta1[4])
{
  static creal_T dc{
      0.0, // re
      0.0  // im
  };
  creal_T b_ascale;
  creal_T b_ctemp;
  creal_T rtdisc;
  creal_T s;
  double anorm;
  double ascale;
  double b_atol;
  double b_x;
  double c;
  double eshift_im;
  double eshift_re;
  double y;
  int c_i;
  int i4;
  int i5;
  int ilast;
  bool failed;
  bool guard1{false};
  bool guard2{false};
  dc.re = rtGetNaN();
  *info = 0;
  for (int b_i{0}; b_i < 4; b_i++) {
    alpha1[b_i].re = 0.0;
    alpha1[b_i].im = 0.0;
    beta1[b_i].re = 1.0;
    beta1[b_i].im = 0.0;
  }
  eshift_re = 0.0;
  eshift_im = 0.0;
  b_ctemp.re = 0.0;
  b_ctemp.im = 0.0;
  anorm = 0.0;
  if (b_ilo <= ihi) {
    double scale;
    double ssq;
    int b_nm1;
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    b_nm1 = ihi - b_ilo;
    for (int j{0}; j <= b_nm1; j++) {
      double colscale;
      double colssq;
      int b_y;
      int col;
      int i1;
      int u0;
      colscale = 3.3121686421112381E-170;
      colssq = 0.0;
      col = (b_ilo + j) - 1;
      u0 = j + 1;
      if (u0 <= b_nm1) {
        b_y = u0;
      } else {
        b_y = b_nm1;
      }
      i1 = b_ilo + b_y;
      for (int row{b_ilo}; row <= i1; row++) {
        double absxk;
        double b_t;
        absxk = std::abs(A[col][row - 1].re);
        if (absxk > colscale) {
          b_t = colscale / absxk;
          colssq = ((colssq * b_t) * b_t) + 1.0;
          colscale = absxk;
        } else {
          b_t = absxk / colscale;
          colssq += b_t * b_t;
        }
        absxk = std::abs(A[col][row - 1].im);
        if (absxk > colscale) {
          b_t = colscale / absxk;
          colssq = ((colssq * b_t) * b_t) + 1.0;
          colscale = absxk;
        } else {
          b_t = absxk / colscale;
          colssq += b_t * b_t;
        }
      }
      if (scale >= colscale) {
        double c_a;
        c_a = colscale / scale;
        ssq += (c_a * c_a) * colssq;
      } else {
        double b_a;
        b_a = scale / colscale;
        ssq = colssq + ((b_a * b_a) * ssq);
        scale = colscale;
      }
    }
    anorm = scale * std::sqrt(ssq);
  }
  y = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (y > 2.2250738585072014E-308) {
    b_atol = y;
  }
  b_x = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    b_x = anorm;
  }
  ascale = 1.0 / b_x;
  failed = true;
  c_i = ihi + 1;
  if ((static_cast<int>((4 - ihi) < 4)) != 0) {
    for (int b_j{c_i}; b_j < 5; b_j++) {
      alpha1[b_j - 1] = A[b_j - 1][b_j - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_j = c_i; b_j < 5; b_j++) {
      alpha1[b_j - 1] = A[b_j - 1][b_j - 1];
    }
  }
  guard1 = false;
  guard2 = false;
  if (ihi >= b_ilo) {
    int ifirst;
    int iiter;
    int ilastm1;
    int istart;
    int jiter;
    bool goto60;
    bool goto70;
    bool goto90;
    ifirst = b_ilo;
    istart = b_ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (jiter <= ((30 * ((ihi - b_ilo) + 1)) - 1)) {
        int d_j;
        bool b_guard1{false};
        bool exitg2;
        b_guard1 = false;
        if ((ilast + 1) == b_ilo) {
          goto60 = true;
          b_guard1 = true;
        } else if ((std::abs(A[ilastm1][ilast].re) +
                    std::abs(A[ilastm1][ilast].im)) <= b_atol) {
          A[ilastm1][ilast].re = 0.0;
          A[ilastm1][ilast].im = 0.0;
          goto60 = true;
          b_guard1 = true;
        } else {
          bool guard3{false};
          d_j = ilastm1;
          guard3 = false;
          exitg2 = false;
          while ((!exitg2) && ((d_j + 1) >= b_ilo)) {
            if ((d_j + 1) == b_ilo) {
              guard3 = true;
              exitg2 = true;
            } else if ((std::abs(A[d_j - 1][d_j].re) +
                        std::abs(A[d_j - 1][d_j].im)) <= b_atol) {
              A[d_j - 1][d_j].re = 0.0;
              A[d_j - 1][d_j].im = 0.0;
              guard3 = true;
              exitg2 = true;
            } else {
              d_j--;
              guard3 = false;
            }
          }
          if (guard3) {
            ifirst = d_j + 1;
            goto70 = true;
          }
          if (goto70) {
            b_guard1 = true;
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5)

            for (int d_i = 0; d_i < 4; d_i++) {
              alpha1[d_i] = dc;
              beta1[d_i] = dc;
              for (i5 = 0; i5 < 4; i5++) {
                b_Z[d_i][i5] = dc;
              }
            }
            *info = 1;
            exitg1 = 1;
          }
        }
        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast][ilast];
            ilast = ilastm1;
            ilastm1--;
            if ((ilast + 1) < b_ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              jiter++;
            }
          } else {
            if (goto70) {
              double shift_im;
              double shift_re;
              int jm1;
              int jp1;
              goto70 = false;
              iiter++;
              if ((iiter - ((iiter / 10) * 10)) != 0) {
                double ad11_im;
                double ad11_re;
                double ad22_im;
                double ad22_re;
                double b_ar;
                double b_ascale_im;
                double b_ascale_re;
                double c_ar;
                double c_ascale_im;
                double c_ascale_re;
                double d_ai;
                double d_ar;
                double e_ai;
                double e_ar;
                double f_ai;
                double g_ai;
                double t1_im;
                double t1_im_tmp;
                double t1_re;
                b_ar = ascale * A[ilastm1][ilastm1].re;
                d_ai = ascale * A[ilastm1][ilastm1].im;
                if (d_ai == 0.0) {
                  ad11_re = b_ar / 0.5;
                  ad11_im = 0.0;
                } else if (b_ar == 0.0) {
                  ad11_re = 0.0;
                  ad11_im = d_ai / 0.5;
                } else {
                  ad11_re = b_ar / 0.5;
                  ad11_im = d_ai / 0.5;
                }
                c_ar = ascale * A[ilast][ilast].re;
                e_ai = ascale * A[ilast][ilast].im;
                if (e_ai == 0.0) {
                  ad22_re = c_ar / 0.5;
                  ad22_im = 0.0;
                } else if (c_ar == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = e_ai / 0.5;
                } else {
                  ad22_re = c_ar / 0.5;
                  ad22_im = e_ai / 0.5;
                }
                t1_re = 0.5 * (ad11_re + ad22_re);
                t1_im = 0.5 * (ad11_im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                d_ar = ascale * A[ilast][ilastm1].re;
                f_ai = ascale * A[ilast][ilastm1].im;
                if (f_ai == 0.0) {
                  b_ascale_re = d_ar / 0.5;
                  b_ascale_im = 0.0;
                } else if (d_ar == 0.0) {
                  b_ascale_re = 0.0;
                  b_ascale_im = f_ai / 0.5;
                } else {
                  b_ascale_re = d_ar / 0.5;
                  b_ascale_im = f_ai / 0.5;
                }
                e_ar = ascale * A[ilastm1][ilast].re;
                g_ai = ascale * A[ilastm1][ilast].im;
                if (g_ai == 0.0) {
                  c_ascale_re = e_ar / 0.5;
                  c_ascale_im = 0.0;
                } else if (e_ar == 0.0) {
                  c_ascale_re = 0.0;
                  c_ascale_im = g_ai / 0.5;
                } else {
                  c_ascale_re = e_ar / 0.5;
                  c_ascale_im = g_ai / 0.5;
                }
                rtdisc.re = (((t1_re * t1_re) - (t1_im * t1_im)) +
                             ((b_ascale_re * c_ascale_re) -
                              (b_ascale_im * c_ascale_im))) -
                            ((ad11_re * ad22_re) - (ad11_im * ad22_im));
                rtdisc.im =
                    ((t1_im_tmp + t1_im_tmp) + ((b_ascale_re * c_ascale_im) +
                                                (b_ascale_im * c_ascale_re))) -
                    ((ad11_re * ad22_im) + (ad11_im * ad22_re));
                scalar::b_sqrt(&rtdisc);
                if ((((t1_re - ad22_re) * rtdisc.re) +
                     ((t1_im - ad22_im) * rtdisc.im)) <= 0.0) {
                  shift_re = t1_re + rtdisc.re;
                  shift_im = t1_im + rtdisc.im;
                } else {
                  shift_re = t1_re - rtdisc.re;
                  shift_im = t1_im - rtdisc.im;
                }
              } else {
                double ar;
                double ascale_im;
                double ascale_re;
                double c_ai;
                ar = ascale * A[ilastm1][ilast].re;
                c_ai = ascale * A[ilastm1][ilast].im;
                if (c_ai == 0.0) {
                  ascale_re = ar / 0.5;
                  ascale_im = 0.0;
                } else if (ar == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = c_ai / 0.5;
                } else {
                  ascale_re = ar / 0.5;
                  ascale_im = c_ai / 0.5;
                }
                eshift_re += ascale_re;
                eshift_im += ascale_im;
                shift_re = eshift_re;
                shift_im = eshift_im;
              }
              d_j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && ((d_j + 1) > ifirst)) {
                double b_tempr;
                double temp;
                double temp2;
                istart = d_j + 1;
                b_ctemp.re = (ascale * A[d_j][d_j].re) - (shift_re * 0.5);
                b_ctemp.im = (ascale * A[d_j][d_j].im) - (shift_im * 0.5);
                temp = std::abs(b_ctemp.re) + std::abs(b_ctemp.im);
                temp2 = ascale *
                        (std::abs(A[d_j][jp1].re) + std::abs(A[d_j][jp1].im));
                b_tempr = temp;
                if (temp2 > temp) {
                  b_tempr = temp2;
                }
                if ((b_tempr < 1.0) && (b_tempr != 0.0)) {
                  temp /= b_tempr;
                  temp2 /= b_tempr;
                }
                if (((std::abs(A[d_j - 1][d_j].re) +
                      std::abs(A[d_j - 1][d_j].im)) *
                     temp2) <= (temp * b_atol)) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = d_j;
                  d_j--;
                }
              }
              if (!goto90) {
                istart = ifirst;
                b_ctemp.re =
                    (ascale * A[ifirst - 1][ifirst - 1].re) - (shift_re * 0.5);
                b_ctemp.im =
                    (ascale * A[ifirst - 1][ifirst - 1].im) - (shift_im * 0.5);
              }
              goto90 = false;
              b_ascale.re = ascale * A[istart - 1][istart].re;
              b_ascale.im = ascale * A[istart - 1][istart].im;
              b_xzlartg(b_ctemp, b_ascale, &c, &s);
              d_j = istart;
              jm1 = istart - 2;
              while (d_j < (ilast + 1)) {
                int g_x;
                if (d_j > istart) {
                  xzlartg(A[jm1][d_j - 1], A[jm1][d_j], &c, &s,
                          &A[jm1][d_j - 1]);
                  A[jm1][d_j].re = 0.0;
                  A[jm1][d_j].im = 0.0;
                }
                for (int e_j{d_j}; e_j < 5; e_j++) {
                  double s_re_tmp;
                  double s_re_tmp_tmp;
                  double stemp_im_tmp;
                  double stemp_re_tmp;
                  s_re_tmp_tmp = A[e_j - 1][d_j].im;
                  s_re_tmp = A[e_j - 1][d_j].re;
                  stemp_re_tmp = A[e_j - 1][d_j - 1].re;
                  stemp_im_tmp = A[e_j - 1][d_j - 1].im;
                  A[e_j - 1][d_j].re = (c * s_re_tmp) - ((s.re * stemp_re_tmp) +
                                                         (s.im * stemp_im_tmp));
                  A[e_j - 1][d_j].im =
                      (c * A[e_j - 1][d_j].im) -
                      ((s.re * stemp_im_tmp) - (s.im * stemp_re_tmp));
                  A[e_j - 1][d_j - 1].re =
                      (c * stemp_re_tmp) +
                      ((s.re * s_re_tmp) - (s.im * s_re_tmp_tmp));
                  A[e_j - 1][d_j - 1].im =
                      (c * stemp_im_tmp) +
                      ((s.re * s_re_tmp_tmp) + (s.im * s_re_tmp));
                }
                s.re = -s.re;
                s.im = -s.im;
                g_x = d_j;
                if ((ilast + 1) < (d_j + 2)) {
                  g_x = ilast - 1;
                }
                for (int e_i{1}; e_i <= (g_x + 2); e_i++) {
                  double b_s_re_tmp;
                  double b_s_re_tmp_tmp;
                  double b_stemp_im_tmp;
                  double b_stemp_re_tmp;
                  b_s_re_tmp_tmp = A[d_j - 1][e_i - 1].im;
                  b_s_re_tmp = A[d_j - 1][e_i - 1].re;
                  b_stemp_re_tmp = A[d_j][e_i - 1].re;
                  b_stemp_im_tmp = A[d_j][e_i - 1].im;
                  A[d_j - 1][e_i - 1].re =
                      (c * b_s_re_tmp) -
                      ((s.re * b_stemp_re_tmp) + (s.im * b_stemp_im_tmp));
                  A[d_j - 1][e_i - 1].im =
                      (c * A[d_j - 1][e_i - 1].im) -
                      ((s.re * b_stemp_im_tmp) - (s.im * b_stemp_re_tmp));
                  A[d_j][e_i - 1].re =
                      (c * b_stemp_re_tmp) +
                      ((s.re * b_s_re_tmp) - (s.im * b_s_re_tmp_tmp));
                  A[d_j][e_i - 1].im =
                      (c * b_stemp_im_tmp) +
                      ((s.re * b_s_re_tmp_tmp) + (s.im * b_s_re_tmp));
                }
                for (int g_i{0}; g_i < 4; g_i++) {
                  double c_s_re_tmp;
                  double c_s_re_tmp_tmp;
                  double c_stemp_im_tmp;
                  double c_stemp_re_tmp;
                  c_s_re_tmp_tmp = b_Z[d_j - 1][g_i].im;
                  c_s_re_tmp = b_Z[d_j - 1][g_i].re;
                  c_stemp_re_tmp = b_Z[d_j][g_i].re;
                  c_stemp_im_tmp = b_Z[d_j][g_i].im;
                  b_Z[d_j - 1][g_i].re =
                      (c * c_s_re_tmp) -
                      ((s.re * c_stemp_re_tmp) + (s.im * c_stemp_im_tmp));
                  b_Z[d_j - 1][g_i].im =
                      (c * b_Z[d_j - 1][g_i].im) -
                      ((s.re * c_stemp_im_tmp) - (s.im * c_stemp_re_tmp));
                  b_Z[d_j][g_i].re =
                      (c * c_stemp_re_tmp) +
                      ((s.re * c_s_re_tmp) - (s.im * c_s_re_tmp_tmp));
                  b_Z[d_j][g_i].im =
                      (c * c_stemp_im_tmp) +
                      ((s.re * c_s_re_tmp_tmp) + (s.im * c_s_re_tmp));
                }
                jm1 = d_j - 1;
                d_j++;
              }
            }
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }
  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      if ((static_cast<int>((ilast + 1) < 4)) != 0) {
        for (int k{0}; k <= ilast; k++) {
          alpha1[k] = dc;
          beta1[k] = dc;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int k = 0; k <= ilast; k++) {
          alpha1[k] = dc;
          beta1[k] = dc;
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

      for (int i3 = 0; i3 < 4; i3++) {
        for (i4 = 0; i4 < 4; i4++) {
          b_Z[i3][i4] = dc;
        }
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    int i2;
    i2 = b_ilo;
    if ((static_cast<int>((b_ilo - 1) < 4)) != 0) {
      for (int c_j{0}; c_j <= (b_ilo - 2); c_j++) {
        alpha1[c_j] = A[c_j][c_j];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_j = 0; c_j <= (i2 - 2); c_j++) {
        alpha1[c_j] = A[c_j][c_j];
      }
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
