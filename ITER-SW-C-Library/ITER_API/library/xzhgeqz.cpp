//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xzhgeqz.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlartg.h"
#include "coder_array.h"
#include "rtGetNaN.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : creal_T A[4][4]
//                int b_ilo
//                int b_ihi
//                creal_T b_Z[4][4]
//                int *info
//                creal_T alpha1[4]
//                creal_T beta1[4]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace reflapack {
void b_xzhgeqz(creal_T A[4][4], int b_ilo, int b_ihi, creal_T b_Z[4][4],
               int *info, creal_T alpha1[4], creal_T beta1[4])
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
  if (b_ilo <= b_ihi) {
    double scale;
    double ssq;
    int b_nm1;
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    b_nm1 = b_ihi - b_ilo;
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
  c_i = b_ihi + 1;
  if ((static_cast<int>((4 - b_ihi) < 4)) != 0) {
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
  if (b_ihi >= b_ilo) {
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
    ilast = b_ihi - 1;
    ilastm1 = b_ihi - 2;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (jiter <= ((30 * ((b_ihi - b_ilo) + 1)) - 1)) {
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
                double c_ai;
                double c_ar;
                double c_ascale_im;
                double c_ascale_re;
                double d_ai;
                double d_ar;
                double e_ai;
                double e_ar;
                double f_ai;
                double t1_im;
                double t1_im_tmp;
                double t1_re;
                b_ar = ascale * A[ilastm1][ilastm1].re;
                c_ai = ascale * A[ilastm1][ilastm1].im;
                if (c_ai == 0.0) {
                  ad11_re = b_ar / 0.5;
                  ad11_im = 0.0;
                } else if (b_ar == 0.0) {
                  ad11_re = 0.0;
                  ad11_im = c_ai / 0.5;
                } else {
                  ad11_re = b_ar / 0.5;
                  ad11_im = c_ai / 0.5;
                }
                c_ar = ascale * A[ilast][ilast].re;
                d_ai = ascale * A[ilast][ilast].im;
                if (d_ai == 0.0) {
                  ad22_re = c_ar / 0.5;
                  ad22_im = 0.0;
                } else if (c_ar == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = d_ai / 0.5;
                } else {
                  ad22_re = c_ar / 0.5;
                  ad22_im = d_ai / 0.5;
                }
                t1_re = 0.5 * (ad11_re + ad22_re);
                t1_im = 0.5 * (ad11_im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                d_ar = ascale * A[ilast][ilastm1].re;
                e_ai = ascale * A[ilast][ilastm1].im;
                if (e_ai == 0.0) {
                  b_ascale_re = d_ar / 0.5;
                  b_ascale_im = 0.0;
                } else if (d_ar == 0.0) {
                  b_ascale_re = 0.0;
                  b_ascale_im = e_ai / 0.5;
                } else {
                  b_ascale_re = d_ar / 0.5;
                  b_ascale_im = e_ai / 0.5;
                }
                e_ar = ascale * A[ilastm1][ilast].re;
                f_ai = ascale * A[ilastm1][ilast].im;
                if (f_ai == 0.0) {
                  c_ascale_re = e_ar / 0.5;
                  c_ascale_im = 0.0;
                } else if (e_ar == 0.0) {
                  c_ascale_re = 0.0;
                  c_ascale_im = f_ai / 0.5;
                } else {
                  c_ascale_re = e_ar / 0.5;
                  c_ascale_im = f_ai / 0.5;
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
                double b_ai;
                ar = ascale * A[ilastm1][ilast].re;
                b_ai = ascale * A[ilastm1][ilast].im;
                if (b_ai == 0.0) {
                  ascale_re = ar / 0.5;
                  ascale_im = 0.0;
                } else if (ar == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = b_ai / 0.5;
                } else {
                  ascale_re = ar / 0.5;
                  ascale_im = b_ai / 0.5;
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
                int e_x;
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
                e_x = d_j;
                if ((ilast + 1) < (d_j + 2)) {
                  e_x = ilast - 1;
                }
                for (int e_i{1}; e_i <= (e_x + 2); e_i++) {
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

//
// Arguments    : const ::coder::array<creal_T, 2U> &A
//                int b_ilo
//                int b_ihi
//                int *info
//                ::coder::array<creal_T, 1U> &alpha1
//                ::coder::array<creal_T, 1U> &beta1
// Return Type  : void
//
void xzhgeqz(const ::coder::array<creal_T, 2U> &A, int b_ilo, int b_ihi,
             int *info, ::coder::array<creal_T, 1U> &alpha1,
             ::coder::array<creal_T, 1U> &beta1)
{
  static creal_T dc{
      0.0, // re
      0.0  // im
  };
  ::coder::array<creal_T, 2U> j_A;
  creal_T b_ascale;
  creal_T b_ctemp;
  creal_T rtdisc;
  creal_T s;
  double anorm;
  double ascale;
  double b_atol;
  double b_x;
  double bscale;
  double c;
  double eshift_im;
  double eshift_re;
  double y;
  int b_info;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int h_n;
  int i1;
  int i4;
  int ilast;
  int loop_ub;
  bool failed;
  bool guard1{false};
  bool guard2{false};
  dc.re = rtGetNaN();
  j_A.set_size(A.size(0), A.size(1));
  loop_ub = A.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = A.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      j_A[i1 + (j_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  b_info = 0;
  if ((A.size(0) == 1) && (A.size(1) == 1)) {
    b_ihi = 1;
  }
  h_n = A.size(0);
  alpha1.set_size(A.size(0));
  c_loop_ub = A.size(0);
  if ((static_cast<int>(A.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < c_loop_ub; i2++) {
      alpha1[i2].re = 0.0;
      alpha1[i2].im = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      alpha1[i2].re = 0.0;
      alpha1[i2].im = 0.0;
    }
  }
  beta1.set_size(A.size(0));
  d_loop_ub = A.size(0);
  if ((static_cast<int>(A.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < d_loop_ub; i3++) {
      beta1[i3].re = 1.0;
      beta1[i3].im = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < d_loop_ub; i3++) {
      beta1[i3].re = 1.0;
      beta1[i3].im = 0.0;
    }
  }
  eshift_re = 0.0;
  eshift_im = 0.0;
  b_ctemp.re = 0.0;
  b_ctemp.im = 0.0;
  anorm = 0.0;
  if (b_ilo <= b_ihi) {
    double scale;
    double ssq;
    int b_nm1;
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    b_nm1 = b_ihi - b_ilo;
    for (int j{0}; j <= b_nm1; j++) {
      double colscale;
      double colssq;
      int b_y;
      int col;
      int i5;
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
      i5 = b_ilo + b_y;
      for (int row{b_ilo}; row <= i5; row++) {
        double absxk;
        double b_t;
        absxk = std::abs(A[(row + (A.size(0) * col)) - 1].re);
        if (absxk > colscale) {
          b_t = colscale / absxk;
          colssq = ((colssq * b_t) * b_t) + 1.0;
          colscale = absxk;
        } else {
          b_t = absxk / colscale;
          colssq += b_t * b_t;
        }
        absxk = std::abs(A[(row + (A.size(0) * col)) - 1].im);
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
  bscale = 1.0 / std::sqrt(static_cast<double>(A.size(0)));
  failed = true;
  i4 = b_ihi + 1;
  if ((static_cast<int>((h_n - b_ihi) < 4)) != 0) {
    for (int b_j{i4}; b_j <= h_n; b_j++) {
      alpha1[b_j - 1] = A[(b_j + (A.size(0) * (b_j - 1))) - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_j = i4; b_j <= h_n; b_j++) {
      alpha1[b_j - 1] = A[(b_j + (A.size(0) * (b_j - 1))) - 1];
    }
  }
  guard1 = false;
  guard2 = false;
  if (b_ihi >= b_ilo) {
    int ifirst;
    int iiter;
    int ilastm;
    int ilastm1;
    int istart;
    int jiter;
    bool goto60;
    bool goto70;
    bool goto90;
    ifirst = b_ilo;
    istart = b_ilo;
    ilast = b_ihi - 1;
    ilastm1 = b_ihi - 2;
    ilastm = b_ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (jiter <= ((30 * ((b_ihi - b_ilo) + 1)) - 1)) {
        int d_j;
        bool b_guard1{false};
        bool exitg2;
        b_guard1 = false;
        if ((ilast + 1) == b_ilo) {
          goto60 = true;
          b_guard1 = true;
        } else if ((std::abs(j_A[ilast + (j_A.size(0) * ilastm1)].re) +
                    std::abs(j_A[ilast + (j_A.size(0) * ilastm1)].im)) <=
                   b_atol) {
          j_A[ilast + (j_A.size(0) * ilastm1)].re = 0.0;
          j_A[ilast + (j_A.size(0) * ilastm1)].im = 0.0;
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
            } else if ((std::abs(j_A[d_j + (j_A.size(0) * (d_j - 1))].re) +
                        std::abs(j_A[d_j + (j_A.size(0) * (d_j - 1))].im)) <=
                       b_atol) {
              j_A[d_j + (j_A.size(0) * (d_j - 1))].re = 0.0;
              j_A[d_j + (j_A.size(0) * (d_j - 1))].im = 0.0;
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
            int alpha1_idx_0;
            int beta1_idx_0;
            int e_loop_ub;
            int f_loop_ub;
            alpha1_idx_0 = alpha1.size(0);
            alpha1.set_size(alpha1_idx_0);
            e_loop_ub = alpha1_idx_0;
            if ((static_cast<int>(alpha1_idx_0 < 4)) != 0) {
              for (int i7{0}; i7 < alpha1_idx_0; i7++) {
                alpha1[i7] = dc;
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int i7 = 0; i7 < e_loop_ub; i7++) {
                alpha1[i7] = dc;
              }
            }
            beta1_idx_0 = beta1.size(0);
            beta1.set_size(beta1_idx_0);
            f_loop_ub = beta1_idx_0;
            if ((static_cast<int>(beta1_idx_0 < 4)) != 0) {
              for (int b_i8{0}; b_i8 < beta1_idx_0; b_i8++) {
                beta1[b_i8] = dc;
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                beta1[b_i8] = dc;
              }
            }
            b_info = 1;
            exitg1 = 1;
          }
        }
        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = j_A[ilast + (j_A.size(0) * ilast)];
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
              ilastm = ilast + 1;
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
                double c_ai;
                double c_ar;
                double c_ascale_im;
                double c_ascale_re;
                double d_ai;
                double d_ar;
                double e_ai;
                double e_ar;
                double f_ai;
                double t1_im;
                double t1_im_tmp;
                double t1_re;
                b_ar = ascale * j_A[ilastm1 + (j_A.size(0) * ilastm1)].re;
                c_ai = ascale * j_A[ilastm1 + (j_A.size(0) * ilastm1)].im;
                if (c_ai == 0.0) {
                  ad11_re = b_ar / bscale;
                  ad11_im = 0.0;
                } else if (b_ar == 0.0) {
                  ad11_re = 0.0;
                  ad11_im = c_ai / bscale;
                } else {
                  ad11_re = b_ar / bscale;
                  ad11_im = c_ai / bscale;
                }
                c_ar = ascale * j_A[ilast + (j_A.size(0) * ilast)].re;
                d_ai = ascale * j_A[ilast + (j_A.size(0) * ilast)].im;
                if (d_ai == 0.0) {
                  ad22_re = c_ar / bscale;
                  ad22_im = 0.0;
                } else if (c_ar == 0.0) {
                  ad22_re = 0.0;
                  ad22_im = d_ai / bscale;
                } else {
                  ad22_re = c_ar / bscale;
                  ad22_im = d_ai / bscale;
                }
                t1_re = 0.5 * (ad11_re + ad22_re);
                t1_im = 0.5 * (ad11_im + ad22_im);
                t1_im_tmp = t1_re * t1_im;
                d_ar = ascale * j_A[ilastm1 + (j_A.size(0) * ilast)].re;
                e_ai = ascale * j_A[ilastm1 + (j_A.size(0) * ilast)].im;
                if (e_ai == 0.0) {
                  b_ascale_re = d_ar / bscale;
                  b_ascale_im = 0.0;
                } else if (d_ar == 0.0) {
                  b_ascale_re = 0.0;
                  b_ascale_im = e_ai / bscale;
                } else {
                  b_ascale_re = d_ar / bscale;
                  b_ascale_im = e_ai / bscale;
                }
                e_ar = ascale * j_A[ilast + (j_A.size(0) * ilastm1)].re;
                f_ai = ascale * j_A[ilast + (j_A.size(0) * ilastm1)].im;
                if (f_ai == 0.0) {
                  c_ascale_re = e_ar / bscale;
                  c_ascale_im = 0.0;
                } else if (e_ar == 0.0) {
                  c_ascale_re = 0.0;
                  c_ascale_im = f_ai / bscale;
                } else {
                  c_ascale_re = e_ar / bscale;
                  c_ascale_im = f_ai / bscale;
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
                double b_ai;
                ar = ascale * j_A[ilast + (j_A.size(0) * ilastm1)].re;
                b_ai = ascale * j_A[ilast + (j_A.size(0) * ilastm1)].im;
                if (b_ai == 0.0) {
                  ascale_re = ar / bscale;
                  ascale_im = 0.0;
                } else if (ar == 0.0) {
                  ascale_re = 0.0;
                  ascale_im = b_ai / bscale;
                } else {
                  ascale_re = ar / bscale;
                  ascale_im = b_ai / bscale;
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
                b_ctemp.re = (ascale * j_A[d_j + (j_A.size(0) * d_j)].re) -
                             (shift_re * bscale);
                b_ctemp.im = (ascale * j_A[d_j + (j_A.size(0) * d_j)].im) -
                             (shift_im * bscale);
                temp = std::abs(b_ctemp.re) + std::abs(b_ctemp.im);
                temp2 = ascale * (std::abs(j_A[jp1 + (j_A.size(0) * d_j)].re) +
                                  std::abs(j_A[jp1 + (j_A.size(0) * d_j)].im));
                b_tempr = temp;
                if (temp2 > temp) {
                  b_tempr = temp2;
                }
                if ((b_tempr < 1.0) && (b_tempr != 0.0)) {
                  temp /= b_tempr;
                  temp2 /= b_tempr;
                }
                if (((std::abs(j_A[d_j + (j_A.size(0) * (d_j - 1))].re) +
                      std::abs(j_A[d_j + (j_A.size(0) * (d_j - 1))].im)) *
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
                    (ascale *
                     j_A[(ifirst + (j_A.size(0) * (ifirst - 1))) - 1].re) -
                    (shift_re * bscale);
                b_ctemp.im =
                    (ascale *
                     j_A[(ifirst + (j_A.size(0) * (ifirst - 1))) - 1].im) -
                    (shift_im * bscale);
              }
              goto90 = false;
              b_ascale.re =
                  ascale * j_A[istart + (j_A.size(0) * (istart - 1))].re;
              b_ascale.im =
                  ascale * j_A[istart + (j_A.size(0) * (istart - 1))].im;
              b_xzlartg(b_ctemp, b_ascale, &c, &s);
              d_j = istart;
              jm1 = istart - 2;
              while (d_j < (ilast + 1)) {
                int e_x;
                if (d_j > istart) {
                  xzlartg(j_A[(d_j + (j_A.size(0) * jm1)) - 1],
                          j_A[d_j + (j_A.size(0) * jm1)], &c, &s,
                          &j_A[(d_j + (j_A.size(0) * jm1)) - 1]);
                  j_A[d_j + (j_A.size(0) * jm1)].re = 0.0;
                  j_A[d_j + (j_A.size(0) * jm1)].im = 0.0;
                }
                for (int e_j{d_j}; e_j <= ilastm; e_j++) {
                  double b_s_re_tmp;
                  double s_re_tmp;
                  double stemp_im_tmp;
                  double stemp_re_tmp;
                  s_re_tmp = j_A[d_j + (j_A.size(0) * (e_j - 1))].im;
                  b_s_re_tmp = j_A[d_j + (j_A.size(0) * (e_j - 1))].re;
                  stemp_re_tmp = j_A[(d_j + (j_A.size(0) * (e_j - 1))) - 1].re;
                  stemp_im_tmp = j_A[(d_j + (j_A.size(0) * (e_j - 1))) - 1].im;
                  j_A[d_j + (j_A.size(0) * (e_j - 1))].re =
                      (c * b_s_re_tmp) -
                      ((s.re * stemp_re_tmp) + (s.im * stemp_im_tmp));
                  j_A[d_j + (j_A.size(0) * (e_j - 1))].im =
                      (c * s_re_tmp) -
                      ((s.re * stemp_im_tmp) - (s.im * stemp_re_tmp));
                  j_A[(d_j + (j_A.size(0) * (e_j - 1))) - 1].re =
                      (c * stemp_re_tmp) +
                      ((s.re * b_s_re_tmp) - (s.im * s_re_tmp));
                  j_A[(d_j + (j_A.size(0) * (e_j - 1))) - 1].im =
                      (c * stemp_im_tmp) +
                      ((s.re * s_re_tmp) + (s.im * b_s_re_tmp));
                }
                s.re = -s.re;
                s.im = -s.im;
                e_x = d_j;
                if ((ilast + 1) < (d_j + 2)) {
                  e_x = ilast - 1;
                }
                for (int c_i{ifirst}; c_i <= (e_x + 2); c_i++) {
                  double b_stemp_im_tmp;
                  double b_stemp_re_tmp;
                  double c_s_re_tmp;
                  double d_s_re_tmp;
                  c_s_re_tmp = j_A[(c_i + (j_A.size(0) * (d_j - 1))) - 1].im;
                  d_s_re_tmp = j_A[(c_i + (j_A.size(0) * (d_j - 1))) - 1].re;
                  b_stemp_re_tmp = j_A[(c_i + (j_A.size(0) * d_j)) - 1].re;
                  b_stemp_im_tmp = j_A[(c_i + (j_A.size(0) * d_j)) - 1].im;
                  j_A[(c_i + (j_A.size(0) * (d_j - 1))) - 1].re =
                      (c * d_s_re_tmp) -
                      ((s.re * b_stemp_re_tmp) + (s.im * b_stemp_im_tmp));
                  j_A[(c_i + (j_A.size(0) * (d_j - 1))) - 1].im =
                      (c * c_s_re_tmp) -
                      ((s.re * b_stemp_im_tmp) - (s.im * b_stemp_re_tmp));
                  j_A[(c_i + (j_A.size(0) * d_j)) - 1].re =
                      (c * b_stemp_re_tmp) +
                      ((s.re * d_s_re_tmp) - (s.im * c_s_re_tmp));
                  j_A[(c_i + (j_A.size(0) * d_j)) - 1].im =
                      (c * b_stemp_im_tmp) +
                      ((s.re * c_s_re_tmp) + (s.im * d_s_re_tmp));
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
      b_info = ilast + 1;
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
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    int i6;
    i6 = b_ilo;
    if ((static_cast<int>((b_ilo - 1) < 4)) != 0) {
      for (int c_j{0}; c_j <= (b_ilo - 2); c_j++) {
        alpha1[c_j] = j_A[c_j + (j_A.size(0) * c_j)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_j = 0; c_j <= (i6 - 2); c_j++) {
        alpha1[c_j] = j_A[c_j + (j_A.size(0) * c_j)];
      }
    }
  }
  *info = b_info;
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
