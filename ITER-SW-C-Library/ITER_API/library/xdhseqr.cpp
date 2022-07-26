//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdhseqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xdhseqr.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double x_h[4][4]
//                double z[4][4]
// Return Type  : int
//
namespace ITER {
namespace coder {
namespace internal {
namespace reflapack {
int b_eml_dlahqr(double x_h[4][4], double z[4][4])
{
  double b_x[4][4];
  double e_v[3];
  double a__1;
  double a__2;
  double a__3;
  double a__4;
  double alpha;
  double b_cs;
  double b_d1;
  double b_sn;
  double d;
  double d2;
  int b_i;
  int info;
  bool exitg1;
  info = 0;
  e_v[0] = 0.0;
  e_v[1] = 0.0;
  e_v[2] = 0.0;
  x_h[0][2] = 0.0;
  x_h[0][3] = 0.0;
  x_h[1][3] = 0.0;
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
        d3 = std::abs(x_h[k - 1][k]);
        if (d3 <= 4.0083367200179456E-292) {
          exitg3 = true;
        } else {
          double tst;
          double tst_tmp;
          tst_tmp = std::abs(x_h[k][k]);
          tst = std::abs(x_h[k - 1][k - 1]) + tst_tmp;
          if (tst == 0.0) {
            if ((k - 1) >= 1) {
              tst = std::abs(x_h[k - 2][k - 1]);
            }
            if ((k + 2) <= 4) {
              tst += std::abs(x_h[k][k + 1]);
            }
          }
          if (d3 <= (2.2204460492503131E-16 * tst)) {
            double aa;
            double ab;
            double b_ba;
            double b_bb;
            double htmp2;
            htmp2 = std::abs(x_h[k][k - 1]);
            if (d3 > htmp2) {
              ab = d3;
              b_ba = htmp2;
            } else {
              ab = htmp2;
              b_ba = d3;
            }
            htmp2 = std::abs(x_h[k - 1][k - 1] - x_h[k][k]);
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
        x_h[k - 1][k] = 0.0;
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
        int m;
        if (its == 10) {
          s = std::abs(x_h[k][k + 1]) + std::abs(x_h[k + 1][k + 2]);
          b_h11 = (0.75 * s) + x_h[k][k];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = b_h11;
        } else if (its == 20) {
          s = std::abs(x_h[b_i - 1][b_i]) + std::abs(x_h[b_i - 2][b_i - 1]);
          b_h11 = (0.75 * s) + x_h[b_i][b_i];
          h12 = -0.4375 * s;
          h21 = s;
          h22 = b_h11;
        } else {
          b_h11 = x_h[b_i - 1][b_i - 1];
          h21 = x_h[b_i - 1][b_i];
          h12 = x_h[b_i][b_i - 1];
          h22 = x_h[b_i][b_i];
        }
        s = ((std::abs(b_h11) + std::abs(h12)) + std::abs(h21)) + std::abs(h22);
        if (s == 0.0) {
          rt1r = 0.0;
          rt1i = 0.0;
          rt2r = 0.0;
          rt2i = 0.0;
        } else {
          double c_det;
          double rtdisc;
          double tr;
          b_h11 /= s;
          h21 /= s;
          h12 /= s;
          h22 /= s;
          tr = (b_h11 + h22) / 2.0;
          c_det = ((b_h11 - tr) * (h22 - tr)) - (h12 * h21);
          rtdisc = std::sqrt(std::abs(c_det));
          if (c_det >= 0.0) {
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
        m = b_i - 1;
        exitg3 = false;
        while ((!exitg3) && (m >= (k + 1))) {
          double b_s_tmp;
          double c_s_tmp;
          double h21s;
          double s_tmp;
          s_tmp = x_h[m - 1][m];
          b_s_tmp = x_h[m - 1][m - 1];
          c_s_tmp = b_s_tmp - rt2r;
          s = (std::abs(c_s_tmp) + std::abs(rt2i)) + std::abs(s_tmp);
          h21s = s_tmp / s;
          e_v[0] =
              ((h21s * x_h[m][m - 1]) + ((b_s_tmp - rt1r) * (c_s_tmp / s))) -
              (rt1i * (rt2i / s));
          e_v[1] = h21s * (((b_s_tmp + x_h[m][m]) - rt1r) - rt2r);
          e_v[2] = h21s * x_h[m][m + 1];
          s = (std::abs(e_v[0]) + std::abs(e_v[1])) + std::abs(e_v[2]);
          e_v[0] /= s;
          e_v[1] /= s;
          e_v[2] /= s;
          if (m == (k + 1)) {
            exitg3 = true;
          } else if ((std::abs(x_h[m - 2][m - 1]) *
                      (std::abs(e_v[1]) + std::abs(e_v[2]))) <=
                     ((2.2204460492503131E-16 * std::abs(e_v[0])) *
                      ((std::abs(x_h[m - 2][m - 2]) + std::abs(b_s_tmp)) +
                       std::abs(x_h[m][m])))) {
            exitg3 = true;
          } else {
            m--;
          }
        }
        for (int e_k{m}; e_k <= b_i; e_k++) {
          double b_t1;
          double d4;
          double t2;
          int b_u1;
          int nr;
          b_u1 = (b_i - e_k) + 2;
          if (3 <= b_u1) {
            nr = 3;
          } else {
            nr = b_u1;
          }
          if (e_k > m) {
            int hoffset;
            hoffset = (e_k + ((e_k - 2) * 4)) - 1;
            for (int j{0}; j < nr; j++) {
              e_v[j] = (&x_h[0][0])[j + hoffset];
            }
          }
          alpha = e_v[0];
          b_t1 = b_xzlarfg(nr, &alpha, e_v);
          e_v[0] = alpha;
          if (e_k > m) {
            x_h[e_k - 2][e_k - 1] = alpha;
            x_h[e_k - 2][e_k] = 0.0;
            if (e_k < b_i) {
              x_h[e_k - 2][e_k + 1] = 0.0;
            }
          } else if (m > (k + 1)) {
            x_h[e_k - 2][e_k - 1] *= 1.0 - b_t1;
          } else {
            /* no actions */
          }
          d4 = e_v[1];
          t2 = b_t1 * e_v[1];
          if (nr == 3) {
            double d5;
            double sum1;
            double t3;
            int i2;
            d5 = e_v[2];
            t3 = b_t1 * e_v[2];
            for (int c_j{e_k}; c_j < 5; c_j++) {
              sum1 = (x_h[c_j - 1][e_k - 1] + (d4 * x_h[c_j - 1][e_k])) +
                     (d5 * x_h[c_j - 1][e_k + 1]);
              x_h[c_j - 1][e_k - 1] -= sum1 * b_t1;
              x_h[c_j - 1][e_k] -= sum1 * t2;
              x_h[c_j - 1][e_k + 1] -= sum1 * t3;
            }
            if ((e_k + 3) <= (b_i + 1)) {
              i2 = e_k + 2;
            } else {
              i2 = b_i;
            }
            for (int g_j{0}; g_j <= i2; g_j++) {
              sum1 = (x_h[e_k - 1][g_j] + (d4 * x_h[e_k][g_j])) +
                     (d5 * x_h[e_k + 1][g_j]);
              x_h[e_k - 1][g_j] -= sum1 * b_t1;
              x_h[e_k][g_j] -= sum1 * t2;
              x_h[e_k + 1][g_j] -= sum1 * t3;
            }
            for (int h_j{0}; h_j < 4; h_j++) {
              sum1 = (z[e_k - 1][h_j] + (d4 * z[e_k][h_j])) +
                     (d5 * z[e_k + 1][h_j]);
              z[e_k - 1][h_j] -= sum1 * b_t1;
              z[e_k][h_j] -= sum1 * t2;
              z[e_k + 1][h_j] -= sum1 * t3;
            }
          } else if (nr == 2) {
            double sum1;
            for (int b_j{e_k}; b_j < 5; b_j++) {
              double sum1_tmp;
              sum1_tmp = x_h[b_j - 1][e_k - 1];
              sum1 = sum1_tmp + (d4 * x_h[b_j - 1][e_k]);
              x_h[b_j - 1][e_k - 1] = sum1_tmp - (sum1 * b_t1);
              x_h[b_j - 1][e_k] -= sum1 * t2;
            }
            for (int d_j{0}; d_j <= b_i; d_j++) {
              sum1 = x_h[e_k - 1][d_j] + (d4 * x_h[e_k][d_j]);
              x_h[e_k - 1][d_j] -= sum1 * b_t1;
              x_h[e_k][d_j] -= sum1 * t2;
            }
            for (int e_j{0}; e_j < 4; e_j++) {
              double b_sum1_tmp;
              b_sum1_tmp = z[e_k - 1][e_j];
              sum1 = b_sum1_tmp + (d4 * z[e_k][e_j]);
              z[e_k - 1][e_j] = b_sum1_tmp - (sum1 * b_t1);
              z[e_k][e_j] -= sum1 * t2;
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
        d = x_h[b_i][b_i - 1];
        b_d1 = x_h[b_i - 1][b_i];
        d2 = x_h[b_i][b_i];
        xdlanv2(&x_h[b_i - 1][b_i - 1], &d, &b_d1, &d2, &a__1, &a__2, &a__3,
                &a__4, &b_cs, &b_sn);
        x_h[b_i][b_i - 1] = d;
        x_h[b_i - 1][b_i] = b_d1;
        x_h[b_i][b_i] = d2;
        if (4 > (b_i + 1)) {
          int h_n;
          int ix_tmp;
          h_n = 2 - b_i;
          (void)std::copy(&x_h[0][0], (&x_h[0][0]) + 16U, &b_x[0][0]);
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
          (void)std::copy(&b_x[0][0], (&b_x[0][0]) + 16U, &x_h[0][0]);
        }
        b = (b_i - 1) * 4;
        b_b = b_i * 4;
        (void)std::copy(&x_h[0][0], (&x_h[0][0]) + 16U, &b_x[0][0]);
        if ((b_i - 1) >= 1) {
          for (int c_k{0}; c_k <= (b_i - 2); c_k++) {
            double d_temp_tmp;
            double g_temp_tmp;
            int b_temp_tmp;
            int e_temp_tmp;
            b_temp_tmp = b_b + c_k;
            d_temp_tmp = (&b_x[0][0])[b_temp_tmp];
            e_temp_tmp = b + c_k;
            g_temp_tmp = (&b_x[0][0])[e_temp_tmp];
            (&b_x[0][0])[b_temp_tmp] =
                (b_cs * d_temp_tmp) - (b_sn * g_temp_tmp);
            (&b_x[0][0])[e_temp_tmp] =
                (b_cs * g_temp_tmp) + (b_sn * d_temp_tmp);
          }
        }
        for (int c_i{0}; c_i < 4; c_i++) {
          for (int i1{0}; i1 < 4; i1++) {
            x_h[c_i][i1] = b_x[c_i][i1];
            b_x[c_i][i1] = z[c_i][i1];
          }
        }
        for (int d_k{0}; d_k < 4; d_k++) {
          double h_temp_tmp;
          double j_temp_tmp;
          int f_temp_tmp;
          int i_temp_tmp;
          f_temp_tmp = b_b + d_k;
          h_temp_tmp = (&b_x[0][0])[f_temp_tmp];
          i_temp_tmp = b + d_k;
          j_temp_tmp = (&b_x[0][0])[i_temp_tmp];
          (&b_x[0][0])[f_temp_tmp] = (b_cs * h_temp_tmp) - (b_sn * j_temp_tmp);
          (&b_x[0][0])[i_temp_tmp] = (b_cs * j_temp_tmp) + (b_sn * h_temp_tmp);
        }
        (void)std::copy(&b_x[0][0], (&b_x[0][0]) + 16U, &z[0][0]);
      }
      b_i = ab_L - 2;
    }
  }
  return info;
}

//
// Arguments    : ::coder::array<double, 2U> &x_h
// Return Type  : int
//
int eml_dlahqr(::coder::array<double, 2U> &x_h)
{
  double e_v[3];
  double a__1;
  double a__2;
  double a__3;
  double a__4;
  double alpha;
  double b_cs;
  double b_d1;
  double b_sn;
  double d;
  double d2;
  int h_n;
  int info;
  int ldh;
  h_n = x_h.size(0);
  ldh = x_h.size(0);
  info = 0;
  if ((h_n != 0) && (1 != h_n)) {
    double SMLNUM;
    double itmax;
    int b_i;
    bool exitg1;
    e_v[0] = 0.0;
    e_v[1] = 0.0;
    e_v[2] = 0.0;
    for (int j{0}; j <= (h_n - 4); j++) {
      x_h[(j + (x_h.size(0) * j)) + 2] = 0.0;
      x_h[(j + (x_h.size(0) * j)) + 3] = 0.0;
    }
    if (1 <= (h_n - 2)) {
      x_h[(h_n + (x_h.size(0) * (h_n - 3))) - 1] = 0.0;
    }
    itmax = 30.0 * std::fmax(10.0, static_cast<double>(h_n));
    SMLNUM = 2.2250738585072014E-308 *
             ((static_cast<double>(h_n)) / 2.2204460492503131E-16);
    b_i = h_n - 1;
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
      while ((!exitg2) && (its <= (static_cast<int>(itmax)))) {
        double s;
        int k;
        bool exitg3;
        k = b_i;
        exitg3 = false;
        while ((!exitg3) && ((k + 1) > ab_L)) {
          double d3;
          d3 = std::abs(x_h[k + (x_h.size(0) * (k - 1))]);
          if (d3 <= SMLNUM) {
            exitg3 = true;
          } else {
            double tst;
            double tst_tmp;
            tst_tmp = std::abs(x_h[k + (x_h.size(0) * k)]);
            tst = std::abs(x_h[(k + (x_h.size(0) * (k - 1))) - 1]) + tst_tmp;
            if (tst == 0.0) {
              if ((k - 1) >= 1) {
                tst = std::abs(x_h[(k + (x_h.size(0) * (k - 2))) - 1]);
              }
              if ((k + 2) <= h_n) {
                tst += std::abs(x_h[(k + (x_h.size(0) * k)) + 1]);
              }
            }
            if (d3 <= (2.2204460492503131E-16 * tst)) {
              double aa;
              double ab;
              double b_ba;
              double b_bb;
              double htmp2;
              htmp2 = std::abs(x_h[(k + (x_h.size(0) * k)) - 1]);
              if (d3 > htmp2) {
                ab = d3;
                b_ba = htmp2;
              } else {
                ab = htmp2;
                b_ba = d3;
              }
              htmp2 = std::abs(x_h[(k + (x_h.size(0) * (k - 1))) - 1] -
                               x_h[k + (x_h.size(0) * k)]);
              if (tst_tmp > htmp2) {
                aa = tst_tmp;
                b_bb = htmp2;
              } else {
                aa = htmp2;
                b_bb = tst_tmp;
              }
              s = aa + ab;
              if ((b_ba * (ab / s)) <=
                  std::fmax(SMLNUM,
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
          x_h[k + (x_h.size(0) * (k - 1))] = 0.0;
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
          int m;
          if (its == 10) {
            s = std::abs(x_h[(k + (x_h.size(0) * k)) + 1]) +
                std::abs(x_h[(k + (x_h.size(0) * (k + 1))) + 2]);
            b_h11 = (0.75 * s) + x_h[k + (x_h.size(0) * k)];
            h12 = -0.4375 * s;
            h21 = s;
            h22 = b_h11;
          } else if (its == 20) {
            s = std::abs(x_h[b_i + (x_h.size(0) * (b_i - 1))]) +
                std::abs(x_h[(b_i + (x_h.size(0) * (b_i - 2))) - 1]);
            b_h11 = (0.75 * s) + x_h[b_i + (x_h.size(0) * b_i)];
            h12 = -0.4375 * s;
            h21 = s;
            h22 = b_h11;
          } else {
            b_h11 = x_h[(b_i + (x_h.size(0) * (b_i - 1))) - 1];
            h21 = x_h[b_i + (x_h.size(0) * (b_i - 1))];
            h12 = x_h[(b_i + (x_h.size(0) * b_i)) - 1];
            h22 = x_h[b_i + (x_h.size(0) * b_i)];
          }
          s = ((std::abs(b_h11) + std::abs(h12)) + std::abs(h21)) +
              std::abs(h22);
          if (s == 0.0) {
            rt1r = 0.0;
            rt1i = 0.0;
            rt2r = 0.0;
            rt2i = 0.0;
          } else {
            double c_det;
            double rtdisc;
            double tr;
            b_h11 /= s;
            h21 /= s;
            h12 /= s;
            h22 /= s;
            tr = (b_h11 + h22) / 2.0;
            c_det = ((b_h11 - tr) * (h22 - tr)) - (h12 * h21);
            rtdisc = std::sqrt(std::abs(c_det));
            if (c_det >= 0.0) {
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
          m = b_i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= (k + 1))) {
            double b_s_tmp;
            double c_s_tmp;
            double h21s;
            double s_tmp;
            s_tmp = x_h[m + (x_h.size(0) * (m - 1))];
            b_s_tmp = x_h[(m + (x_h.size(0) * (m - 1))) - 1];
            c_s_tmp = b_s_tmp - rt2r;
            s = (std::abs(c_s_tmp) + std::abs(rt2i)) + std::abs(s_tmp);
            h21s = s_tmp / s;
            e_v[0] = ((h21s * x_h[(m + (x_h.size(0) * m)) - 1]) +
                      ((b_s_tmp - rt1r) * (c_s_tmp / s))) -
                     (rt1i * (rt2i / s));
            e_v[1] =
                h21s * (((b_s_tmp + x_h[m + (x_h.size(0) * m)]) - rt1r) - rt2r);
            e_v[2] = h21s * x_h[(m + (x_h.size(0) * m)) + 1];
            s = (std::abs(e_v[0]) + std::abs(e_v[1])) + std::abs(e_v[2]);
            e_v[0] /= s;
            e_v[1] /= s;
            e_v[2] /= s;
            if (m == (k + 1)) {
              exitg3 = true;
            } else if ((std::abs(x_h[(m + (x_h.size(0) * (m - 2))) - 1]) *
                        (std::abs(e_v[1]) + std::abs(e_v[2]))) <=
                       ((2.2204460492503131E-16 * std::abs(e_v[0])) *
                        ((std::abs(x_h[(m + (x_h.size(0) * (m - 2))) - 2]) +
                          std::abs(b_s_tmp)) +
                         std::abs(x_h[m + (x_h.size(0) * m)])))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
          for (int d_k{m}; d_k <= b_i; d_k++) {
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
            if (d_k > m) {
              int hoffset;
              hoffset = (d_k + (ldh * (d_k - 2))) - 1;
              for (int b_j{0}; b_j < nr; b_j++) {
                e_v[b_j] = x_h[b_j + hoffset];
              }
            }
            alpha = e_v[0];
            b_t1 = b_xzlarfg(nr, &alpha, e_v);
            e_v[0] = alpha;
            if (d_k > m) {
              x_h[(d_k + (x_h.size(0) * (d_k - 2))) - 1] = alpha;
              x_h[d_k + (x_h.size(0) * (d_k - 2))] = 0.0;
              if (d_k < b_i) {
                x_h[(d_k + (x_h.size(0) * (d_k - 2))) + 1] = 0.0;
              }
            } else if (m > (k + 1)) {
              x_h[(d_k + (x_h.size(0) * (d_k - 2))) - 1] =
                  x_h[(d_k + (x_h.size(0) * (d_k - 2))) - 1] * (1.0 - b_t1);
            } else {
              /* no actions */
            }
            d4 = e_v[1];
            t2 = b_t1 * e_v[1];
            if (nr == 3) {
              double d5;
              double sum1;
              double t3;
              int c_i;
              d5 = e_v[2];
              t3 = b_t1 * e_v[2];
              for (int d_j{d_k}; d_j <= h_n; d_j++) {
                sum1 = (x_h[(d_k + (x_h.size(0) * (d_j - 1))) - 1] +
                        (d4 * x_h[d_k + (x_h.size(0) * (d_j - 1))])) +
                       (d5 * x_h[(d_k + (x_h.size(0) * (d_j - 1))) + 1]);
                x_h[(d_k + (x_h.size(0) * (d_j - 1))) - 1] =
                    x_h[(d_k + (x_h.size(0) * (d_j - 1))) - 1] - (sum1 * b_t1);
                x_h[d_k + (x_h.size(0) * (d_j - 1))] =
                    x_h[d_k + (x_h.size(0) * (d_j - 1))] - (sum1 * t2);
                x_h[(d_k + (x_h.size(0) * (d_j - 1))) + 1] =
                    x_h[(d_k + (x_h.size(0) * (d_j - 1))) + 1] - (sum1 * t3);
              }
              if ((d_k + 3) <= (b_i + 1)) {
                c_i = d_k + 2;
              } else {
                c_i = b_i;
              }
              for (int g_j{0}; g_j <= c_i; g_j++) {
                sum1 = (x_h[g_j + (x_h.size(0) * (d_k - 1))] +
                        (d4 * x_h[g_j + (x_h.size(0) * d_k)])) +
                       (d5 * x_h[g_j + (x_h.size(0) * (d_k + 1))]);
                x_h[g_j + (x_h.size(0) * (d_k - 1))] =
                    x_h[g_j + (x_h.size(0) * (d_k - 1))] - (sum1 * b_t1);
                x_h[g_j + (x_h.size(0) * d_k)] =
                    x_h[g_j + (x_h.size(0) * d_k)] - (sum1 * t2);
                x_h[g_j + (x_h.size(0) * (d_k + 1))] =
                    x_h[g_j + (x_h.size(0) * (d_k + 1))] - (sum1 * t3);
              }
            } else if (nr == 2) {
              double sum1;
              for (int c_j{d_k}; c_j <= h_n; c_j++) {
                double sum1_tmp;
                sum1_tmp = x_h[(d_k + (x_h.size(0) * (c_j - 1))) - 1];
                sum1 = sum1_tmp + (d4 * x_h[d_k + (x_h.size(0) * (c_j - 1))]);
                x_h[(d_k + (x_h.size(0) * (c_j - 1))) - 1] =
                    sum1_tmp - (sum1 * b_t1);
                x_h[d_k + (x_h.size(0) * (c_j - 1))] =
                    x_h[d_k + (x_h.size(0) * (c_j - 1))] - (sum1 * t2);
              }
              for (int e_j{0}; e_j <= b_i; e_j++) {
                sum1 = x_h[e_j + (x_h.size(0) * (d_k - 1))] +
                       (d4 * x_h[e_j + (x_h.size(0) * d_k)]);
                x_h[e_j + (x_h.size(0) * (d_k - 1))] =
                    x_h[e_j + (x_h.size(0) * (d_k - 1))] - (sum1 * b_t1);
                x_h[e_j + (x_h.size(0) * d_k)] =
                    x_h[e_j + (x_h.size(0) * d_k)] - (sum1 * t2);
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
          d = x_h[(b_i + (x_h.size(0) * b_i)) - 1];
          b_d1 = x_h[b_i + (x_h.size(0) * (b_i - 1))];
          d2 = x_h[b_i + (x_h.size(0) * b_i)];
          xdlanv2(&x_h[(b_i + (x_h.size(0) * (b_i - 1))) - 1], &d, &b_d1, &d2,
                  &a__1, &a__2, &a__3, &a__4, &b_cs, &b_sn);
          x_h[(b_i + (x_h.size(0) * b_i)) - 1] = d;
          x_h[b_i + (x_h.size(0) * (b_i - 1))] = b_d1;
          x_h[b_i + (x_h.size(0) * b_i)] = d2;
          if (h_n > (b_i + 1)) {
            int p_n;
            p_n = (h_n - b_i) - 2;
            if ((p_n + 1) >= 1) {
              int ix_tmp;
              ix_tmp = b_i + ((b_i + 1) * ldh);
              for (int b_k{0}; b_k <= p_n; b_k++) {
                double temp;
                int b_temp_tmp;
                int temp_tmp_tmp;
                temp_tmp_tmp = ix_tmp + (b_k * ldh);
                b_temp_tmp = temp_tmp_tmp - 1;
                temp = (b_cs * x_h[b_temp_tmp]) + (b_sn * x_h[temp_tmp_tmp]);
                x_h[temp_tmp_tmp] =
                    (b_cs * x_h[temp_tmp_tmp]) - (b_sn * x_h[b_temp_tmp]);
                x_h[b_temp_tmp] = temp;
              }
            }
          }
          if ((b_i - 1) >= 1) {
            int b_iy;
            int c_ix;
            c_ix = (b_i - 1) * ldh;
            b_iy = b_i * ldh;
            for (int c_k{0}; c_k <= (b_i - 2); c_k++) {
              double b_temp;
              int c_temp_tmp;
              int temp_tmp;
              temp_tmp = b_iy + c_k;
              c_temp_tmp = c_ix + c_k;
              b_temp = (b_cs * x_h[c_temp_tmp]) + (b_sn * x_h[temp_tmp]);
              x_h[temp_tmp] = (b_cs * x_h[temp_tmp]) - (b_sn * x_h[c_temp_tmp]);
              x_h[c_temp_tmp] = b_temp;
            }
          }
        }
        b_i = ab_L - 2;
      }
    }
  }
  return info;
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xdhseqr.cpp
//
// [EOF]
//
