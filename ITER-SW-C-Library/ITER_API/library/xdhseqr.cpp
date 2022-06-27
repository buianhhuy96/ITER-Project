//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdhseqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xdhseqr.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xnrm2.h"
#include "xrot.h"
#include <algorithm>
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double w_h[4][4]
//                double z[4][4]
// Return Type  : int
//
namespace coder {
namespace internal {
namespace reflapack {
int eml_dlahqr(double w_h[4][4], double z[4][4])
{
  double b_x[4][4];
  double b_v[3];
  double a__1;
  double a__2;
  double a__3;
  double a__4;
  double b_cs;
  double b_d1;
  double b_sn;
  double d;
  double d2;
  int b_i;
  int info;
  bool exitg1;
  info = 0;
  b_v[0] = 0.0;
  b_v[1] = 0.0;
  b_v[2] = 0.0;
  w_h[0][2] = 0.0;
  w_h[0][3] = 0.0;
  w_h[1][3] = 0.0;
  b_i = 3;
  exitg1 = false;
  while ((!exitg1) && ((b_i + 1) >= 1)) {
    int ab_L;
    int its;
    bool exitg2;
    bool goto150;
    ab_L = 1;
    goto150 = false;
    its = 0;
    exitg2 = false;
    while ((!exitg2) && (its < 301)) {
      double s;
      int k;
      bool exitg3;
      k = b_i;
      exitg3 = false;
      while ((!exitg3) && ((k + 1) > ab_L)) {
        double d3;
        d3 = std::abs(w_h[k - 1][k]);
        if (d3 <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          double tst;
          double tst_tmp;
          tst_tmp = std::abs(w_h[k][k]);
          tst = std::abs(w_h[k - 1][k - 1]) + tst_tmp;
          if (tst == 0.0) {
            if ((k - 1) >= 1) {
              tst = std::abs(w_h[k - 2][k - 1]);
            }
            if ((k + 2) <= 4) {
              tst += std::abs(w_h[k][k + 1]);
            }
          }
          if (d3 <= (2.2204460492503131E-16 * tst)) {
            double aa;
            double ab;
            double b_ba;
            double b_bb;
            double htmp2;
            htmp2 = std::abs(w_h[k][k - 1]);
            if (d3 > htmp2) {
              ab = d3;
              b_ba = htmp2;
            } else {
              ab = htmp2;
              b_ba = d3;
            }
            htmp2 = std::abs(w_h[k - 1][k - 1] - w_h[k][k]);
            if (tst_tmp > htmp2) {
              aa = tst_tmp;
              b_bb = htmp2;
            } else {
              aa = htmp2;
              b_bb = tst_tmp;
            }
            s = aa + ab;
            if ((b_ba * (ab / s)) <=
                std::fmax(4.0083367200179456E-292,
                          2.2204460492503131E-16 * (b_bb * (aa / s)))) {
              exitg3 = true;
            } else {
              k--;
            }
          } else {
            k--;
          }
        }
      }
      ab_L = k + 1;
      if ((k + 1) > 1) {
        w_h[k - 1][k] = 0.0;
      }
      if ((k + 1) >= b_i) {
        goto150 = true;
        exitg2 = true;
      } else {
        double b_h11;
        double h12;
        double h21;
        double h22;
        double rt1i;
        double rt1r;
        double rt2i;
        double rt2r;
        int b_m;
        if (its == 10) {
          s = std::abs(w_h[k][k + 1]) + std::abs(w_h[k + 1][k + 2]);
          b_h11 = (0.75 * s) + w_h[k][k];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = b_h11;
        } else if (its == 20) {
          s = std::abs(w_h[b_i - 1][b_i]) + std::abs(w_h[b_i - 2][b_i - 1]);
          b_h11 = (0.75 * s) + w_h[b_i][b_i];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = b_h11;
        } else {
          b_h11 = w_h[b_i - 1][b_i - 1];
          h21 = w_h[b_i - 1][b_i];
          h12 = w_h[b_i][b_i - 1];
          h22 = w_h[b_i][b_i];
        }
        s = ((std::abs(b_h11) + std::abs(h12)) + std::abs(h21)) + std::abs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          rt1i = 0.0;
          rt2r = 0.0;
          rt2i = 0.0;
        } else {
          double b_det;
          double rtdisc;
          double tr;
          b_h11 /= s;
          h21 /= s;
          h12 /= s;
          h22 /= s;
          tr = (b_h11 + h22) / 2.0;
          b_det = ((b_h11 - tr) * (h22 - tr)) - (h12 * h21);
          rtdisc = std::sqrt(std::abs(b_det));
          if (b_det >= 0.0) {
            rt1r = tr * s;
            rt2r = rt1r;
            rt1i = rtdisc * s;
            rt2i = -rt1i;
          } else {
            rt1r = tr + rtdisc;
            rt2r = tr - rtdisc;
            if (std::abs(rt1r - h22) <= std::abs(rt2r - h22)) {
              rt1r *= s;
              rt2r = rt1r;
            } else {
              rt2r *= s;
              rt1r = rt2r;
            }
            rt1i = 0.0;
            rt2i = 0.0;
          }
        }
        b_m = b_i - 1;
        exitg3 = false;
        while ((!exitg3) && (b_m >= (k + 1))) {
          double b_s_tmp;
          double c_s_tmp;
          double h21s;
          double s_tmp;
          s_tmp = w_h[b_m - 1][b_m];
          b_s_tmp = w_h[b_m - 1][b_m - 1];
          c_s_tmp = b_s_tmp - rt2r;
          s = (std::abs(c_s_tmp) + std::abs(rt2i)) + std::abs(s_tmp);
          h21s = s_tmp / s;
          b_v[0] = ((h21s * w_h[b_m][b_m - 1]) +
                    ((b_s_tmp - rt1r) * (c_s_tmp / s))) -
                   (rt1i * (rt2i / s));
          b_v[1] = h21s * (((b_s_tmp + w_h[b_m][b_m]) - rt1r) - rt2r);
          b_v[2] = h21s * w_h[b_m][b_m + 1];
          s = (std::abs(b_v[0]) + std::abs(b_v[1])) + std::abs(b_v[2]);
          b_v[0] /= s;
          b_v[1] /= s;
          b_v[2] /= s;
          if (b_m == (k + 1)) {
            exitg3 = true;
          } else if ((std::abs(w_h[b_m - 2][b_m - 1]) *
                      (std::abs(b_v[1]) + std::abs(b_v[2]))) <=
                     ((2.2204460492503131E-16 * std::abs(b_v[0])) *
                      ((std::abs(w_h[b_m - 2][b_m - 2]) + std::abs(b_s_tmp)) +
                       std::abs(w_h[b_m][b_m])))) {
            exitg3 = true;
          } else {
            b_m--;
          }
        }
        for (int d_k{b_m}; d_k <= b_i; d_k++) {
          double alpha;
          double b_t1;
          double d4;
          double t2;
          int b_u1;
          int nr;
          b_u1 = (b_i - d_k) + 2;
          if (3 <= b_u1) {
            nr = 3;
          } else {
            nr = b_u1;
          }
          if (d_k > b_m) {
            int hoffset;
            hoffset = (d_k + ((d_k - 2) * 4)) - 1;
            for (int j{0}; j < nr; j++) {
              b_v[j] = (&w_h[0][0])[j + hoffset];
            }
          }
          alpha = b_v[0];
          b_t1 = 0.0;
          if (nr > 0) {
            double xnorm_tmp_tmp;
            xnorm_tmp_tmp = blas::g_xnrm2(nr - 1, b_v);
            if (xnorm_tmp_tmp != 0.0) {
              double beta1;
              beta1 = rt_hypotd_snf(b_v[0], xnorm_tmp_tmp);
              if (b_v[0] >= 0.0) {
                beta1 = -beta1;
              }
              if (std::abs(beta1) < 1.0020841800044864E-292) {
                double c_a;
                int knt;
                knt = -1;
                do {
                  knt++;
                  for (int g_k{2}; g_k <= nr; g_k++) {
                    b_v[g_k - 1] *= 9.9792015476736E+291;
                  }
                  beta1 *= 9.9792015476736E+291;
                  alpha *= 9.9792015476736E+291;
                } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
                beta1 = rt_hypotd_snf(alpha, blas::g_xnrm2(nr - 1, b_v));
                if (alpha >= 0.0) {
                  beta1 = -beta1;
                }
                b_t1 = (beta1 - alpha) / beta1;
                c_a = 1.0 / (alpha - beta1);
                for (int h_k{2}; h_k <= nr; h_k++) {
                  b_v[h_k - 1] *= c_a;
                }
                for (int i_k{0}; i_k <= knt; i_k++) {
                  beta1 *= 1.0020841800044864E-292;
                }
                alpha = beta1;
              } else {
                double b_a;
                b_t1 = (beta1 - b_v[0]) / beta1;
                b_a = 1.0 / (b_v[0] - beta1);
                for (int e_k{2}; e_k <= nr; e_k++) {
                  b_v[e_k - 1] *= b_a;
                }
                alpha = beta1;
              }
            }
          }
          b_v[0] = alpha;
          if (d_k > b_m) {
            w_h[d_k - 2][d_k - 1] = alpha;
            w_h[d_k - 2][d_k] = 0.0;
            if (d_k < b_i) {
              w_h[d_k - 2][d_k + 1] = 0.0;
            }
          } else if (b_m > (k + 1)) {
            w_h[d_k - 2][d_k - 1] *= 1.0 - b_t1;
          } else {
            /* no actions */
          }
          d4 = b_v[1];
          t2 = b_t1 * b_v[1];
          if (nr == 3) {
            double d5;
            double sum1;
            double t3;
            int c_i;
            d5 = b_v[2];
            t3 = b_t1 * b_v[2];
            for (int c_j{d_k}; c_j < 5; c_j++) {
              sum1 = (w_h[c_j - 1][d_k - 1] + (d4 * w_h[c_j - 1][d_k])) +
                     (d5 * w_h[c_j - 1][d_k + 1]);
              w_h[c_j - 1][d_k - 1] -= sum1 * b_t1;
              w_h[c_j - 1][d_k] -= sum1 * t2;
              w_h[c_j - 1][d_k + 1] -= sum1 * t3;
            }
            if ((d_k + 3) <= (b_i + 1)) {
              c_i = d_k + 2;
            } else {
              c_i = b_i;
            }
            for (int h_j{0}; h_j <= c_i; h_j++) {
              sum1 = (w_h[d_k - 1][h_j] + (d4 * w_h[d_k][h_j])) +
                     (d5 * w_h[d_k + 1][h_j]);
              w_h[d_k - 1][h_j] -= sum1 * b_t1;
              w_h[d_k][h_j] -= sum1 * t2;
              w_h[d_k + 1][h_j] -= sum1 * t3;
            }
            for (int k_j{0}; k_j < 4; k_j++) {
              double c_sum1_tmp;
              c_sum1_tmp = z[d_k - 1][k_j];
              sum1 = (c_sum1_tmp + (d4 * z[d_k][k_j])) + (d5 * z[d_k + 1][k_j]);
              z[d_k - 1][k_j] = c_sum1_tmp - (sum1 * b_t1);
              z[d_k][k_j] -= sum1 * t2;
              z[d_k + 1][k_j] -= sum1 * t3;
            }
          } else if (nr == 2) {
            double sum1;
            for (int b_j{d_k}; b_j < 5; b_j++) {
              double sum1_tmp;
              sum1_tmp = w_h[b_j - 1][d_k - 1];
              sum1 = sum1_tmp + (d4 * w_h[b_j - 1][d_k]);
              w_h[b_j - 1][d_k - 1] = sum1_tmp - (sum1 * b_t1);
              w_h[b_j - 1][d_k] -= sum1 * t2;
            }
            for (int d_j{0}; d_j <= b_i; d_j++) {
              sum1 = w_h[d_k - 1][d_j] + (d4 * w_h[d_k][d_j]);
              w_h[d_k - 1][d_j] -= sum1 * b_t1;
              w_h[d_k][d_j] -= sum1 * t2;
            }
            for (int e_j{0}; e_j < 4; e_j++) {
              double b_sum1_tmp;
              b_sum1_tmp = z[d_k - 1][e_j];
              sum1 = b_sum1_tmp + (d4 * z[d_k][e_j]);
              z[d_k - 1][e_j] = b_sum1_tmp - (sum1 * b_t1);
              z[d_k][e_j] -= sum1 * t2;
            }
          } else {
            /* no actions */
          }
        }
        its++;
      }
    }
    if (!goto150) {
      info = b_i + 1;
      exitg1 = true;
    } else {
      if ((ab_L != (b_i + 1)) && (ab_L == b_i)) {
        int b;
        int b_b;
        d = w_h[b_i][b_i - 1];
        b_d1 = w_h[b_i - 1][b_i];
        d2 = w_h[b_i][b_i];
        xdlanv2(&w_h[b_i - 1][b_i - 1], &d, &b_d1, &d2, &a__1, &a__2, &a__3,
                &a__4, &b_cs, &b_sn);
        w_h[b_i][b_i - 1] = d;
        w_h[b_i - 1][b_i] = b_d1;
        w_h[b_i][b_i] = d2;
        if (4 > (b_i + 1)) {
          int h_n;
          int ix_tmp;
          h_n = 2 - b_i;
          (void)std::copy(&w_h[0][0], (&w_h[0][0]) + 16U, &b_x[0][0]);
          ix_tmp = b_i + ((b_i + 1) * 4);
          for (int b_k{0}; b_k <= h_n; b_k++) {
            double c_temp_tmp;
            double temp_tmp;
            int temp_tmp_tmp;
            temp_tmp_tmp = ix_tmp + (b_k * 4);
            temp_tmp = (&b_x[0][0])[temp_tmp_tmp];
            c_temp_tmp = (&b_x[0][0])[temp_tmp_tmp - 1];
            (&b_x[0][0])[temp_tmp_tmp] =
                (b_cs * temp_tmp) - (b_sn * c_temp_tmp);
            (&b_x[0][0])[temp_tmp_tmp - 1] =
                (b_cs * c_temp_tmp) + (b_sn * temp_tmp);
          }
          (void)std::copy(&b_x[0][0], (&b_x[0][0]) + 16U, &w_h[0][0]);
        }
        b = (b_i - 1) * 4;
        b_b = b_i * 4;
        blas::c_xrot(b_i - 1, w_h, b + 1, b_b + 1, b_cs, b_sn);
        (void)std::copy(&z[0][0], (&z[0][0]) + 16U, &b_x[0][0]);
        for (int c_k{0}; c_k < 4; c_k++) {
          double d_temp_tmp;
          double f_temp_tmp;
          int b_temp_tmp;
          int e_temp_tmp;
          b_temp_tmp = b_b + c_k;
          d_temp_tmp = (&b_x[0][0])[b_temp_tmp];
          e_temp_tmp = b + c_k;
          f_temp_tmp = (&b_x[0][0])[e_temp_tmp];
          (&b_x[0][0])[b_temp_tmp] = (b_cs * d_temp_tmp) - (b_sn * f_temp_tmp);
          (&b_x[0][0])[e_temp_tmp] = (b_cs * f_temp_tmp) + (b_sn * d_temp_tmp);
        }
        (void)std::copy(&b_x[0][0], (&b_x[0][0]) + 16U, &z[0][0]);
      }
      b_i = ab_L - 2;
    }
  }
  return info;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xdhseqr.cpp
//
// [EOF]
//
