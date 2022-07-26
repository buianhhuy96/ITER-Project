//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2quat.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "rotm2quat.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "xzggev.h"
#include "rtGetNaN.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double b_R[3][3]
//                double quat[4]
// Return Type  : void
//
namespace ITER {
namespace coder {
void rotm2quat(const double b_R[3][3], double quat[4])
{
  static creal_T dc{
      0.0, // re
      0.0  // im
  };
  creal_T At[4][4];
  creal_T V[4][4];
  creal_T alpha1[4];
  creal_T b_D[4];
  creal_T beta1[4];
  double T[4][4];
  double U[4][4];
  double f_K[4][4];
  double j_V[4][4];
  double varargin_1[4];
  double K12;
  double K13;
  double K14;
  double K23;
  double K24;
  double K34;
  int d_i;
  int i1;
  int i4;
  int i7;
  int idx;
  int iindx;
  int info;
  bool exitg2;
  bool p;
  dc.re = rtGetNaN();
  K12 = b_R[1][0] + b_R[0][1];
  K13 = b_R[2][0] + b_R[0][2];
  K14 = b_R[1][2] - b_R[2][1];
  K23 = b_R[2][1] + b_R[1][2];
  K24 = b_R[2][0] - b_R[0][2];
  K34 = b_R[0][1] - b_R[1][0];
  f_K[0][0] = ((b_R[0][0] - b_R[1][1]) - b_R[2][2]) / 3.0;
  f_K[1][0] = K12 / 3.0;
  f_K[2][0] = K13 / 3.0;
  f_K[3][0] = K14 / 3.0;
  f_K[0][1] = K12 / 3.0;
  f_K[1][1] = ((b_R[1][1] - b_R[0][0]) - b_R[2][2]) / 3.0;
  f_K[2][1] = K23 / 3.0;
  f_K[3][1] = K24 / 3.0;
  f_K[0][2] = K13 / 3.0;
  f_K[1][2] = K23 / 3.0;
  f_K[2][2] = ((b_R[2][2] - b_R[0][0]) - b_R[1][1]) / 3.0;
  f_K[3][2] = K34 / 3.0;
  f_K[0][3] = K14 / 3.0;
  f_K[1][3] = K24 / 3.0;
  f_K[2][3] = K34 / 3.0;
  f_K[3][3] = ((b_R[0][0] + b_R[1][1]) + b_R[2][2]) / 3.0;
  p = true;
  for (int k{0}; k < 4; k++) {
    for (int b_k{0}; b_k < 4; b_k++) {
      if (p) {
        if ((std::isinf(f_K[k][b_k])) || (std::isnan(f_K[k][b_k]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (!p) {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_i)

    for (int b_i = 0; b_i < 4; b_i++) {
      for (d_i = 0; d_i < 4; d_i++) {
        V[b_i][d_i] = dc;
      }
      b_D[b_i] = dc;
    }
  } else {
    int exitg1;
    int j;
    bool b_p;
    b_p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 4)) {
      int e_i;
      e_i = 0;
      do {
        exitg1 = 0;
        if (e_i <= j) {
          if (!(f_K[j][e_i] == f_K[e_i][j])) {
            b_p = false;
            exitg1 = 1;
          } else {
            e_i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (b_p) {
      b_schur(f_K, j_V, T);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

      for (int c_k = 0; c_k < 4; c_k++) {
        for (i1 = 0; i1 < 4; i1++) {
          V[c_k][i1].re = j_V[c_k][i1];
          V[c_k][i1].im = 0.0;
        }
        b_D[c_k].re = T[c_k][c_k];
        b_D[c_k].im = 0.0;
      }
    } else {
      int b_j;
      bool c_p;
      c_p = true;
      b_j = 0;
      exitg2 = false;
      while ((!exitg2) && (b_j < 4)) {
        int g_i;
        g_i = 0;
        do {
          exitg1 = 0;
          if (g_i <= b_j) {
            if (!(f_K[b_j][g_i] == (-f_K[g_i][b_j]))) {
              c_p = false;
              exitg1 = 1;
            } else {
              g_i++;
            }
          } else {
            b_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (c_p) {
        int c_j;
        int h_i;
        b_schur(f_K, U, T);
        h_i = 1;
        do {
          exitg1 = 0;
          if (h_i <= 4) {
            bool guard1{false};
            guard1 = false;
            if (h_i != 4) {
              double b_d1;
              b_d1 = T[h_i - 1][h_i];
              if (b_d1 != 0.0) {
                double lambda;
                lambda = std::abs(b_d1);
                b_D[h_i - 1].re = 0.0;
                b_D[h_i - 1].im = lambda;
                b_D[h_i].re = 0.0;
                b_D[h_i].im = -lambda;
                h_i += 2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
            if (guard1) {
              b_D[h_i - 1].re = 0.0;
              b_D[h_i - 1].im = 0.0;
              h_i++;
            }
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

        for (int i6 = 0; i6 < 4; i6++) {
          for (i7 = 0; i7 < 4; i7++) {
            V[i6][i7].re = U[i6][i7];
            V[i6][i7].im = 0.0;
          }
        }
        c_j = 1;
        while (c_j <= 4) {
          if ((c_j != 4) && (T[c_j - 1][c_j] != 0.0)) {
            int sgn;
            if (T[c_j - 1][c_j] < 0.0) {
              sgn = 1;
            } else {
              sgn = -1;
            }
            for (int m_i{0}; m_i < 4; m_i++) {
              double ar_tmp;
              double d_ai;
              ar_tmp = V[c_j - 1][m_i].re;
              d_ai = (static_cast<double>(sgn)) * V[c_j][m_i].re;
              if (d_ai == 0.0) {
                V[c_j - 1][m_i].re = ar_tmp / 1.4142135623730951;
                V[c_j - 1][m_i].im = 0.0;
              } else if (ar_tmp == 0.0) {
                V[c_j - 1][m_i].re = 0.0;
                V[c_j - 1][m_i].im = d_ai / 1.4142135623730951;
              } else {
                V[c_j - 1][m_i].re = ar_tmp / 1.4142135623730951;
                V[c_j - 1][m_i].im = d_ai / 1.4142135623730951;
              }
              V[c_j][m_i].re = V[c_j - 1][m_i].re;
              V[c_j][m_i].im = -V[c_j - 1][m_i].im;
            }
            c_j += 2;
          } else {
            c_j++;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

        for (int i3 = 0; i3 < 4; i3++) {
          for (i4 = 0; i4 < 4; i4++) {
            At[i3][i4].re = f_K[i3][i4];
            At[i3][i4].im = 0.0;
          }
        }
        internal::reflapack::xzggev(At, &info, alpha1, beta1, V);
        for (int coltop{0}; coltop <= 12; coltop += 4) {
          double colnorm;
          double scale;
          int kend_tmp;
          colnorm = 0.0;
          scale = 3.3121686421112381E-170;
          kend_tmp = coltop + 4;
          for (int g_k{coltop + 1}; g_k <= kend_tmp; g_k++) {
            double absxk;
            double b_t;
            absxk = std::abs((&V[0][0])[g_k - 1].re);
            if (absxk > scale) {
              b_t = scale / absxk;
              colnorm = ((colnorm * b_t) * b_t) + 1.0;
              scale = absxk;
            } else {
              b_t = absxk / scale;
              colnorm += b_t * b_t;
            }
            absxk = std::abs((&V[0][0])[g_k - 1].im);
            if (absxk > scale) {
              b_t = scale / absxk;
              colnorm = ((colnorm * b_t) * b_t) + 1.0;
              scale = absxk;
            } else {
              b_t = absxk / scale;
              colnorm += b_t * b_t;
            }
          }
          colnorm = scale * std::sqrt(colnorm);
          for (int d_j{coltop + 1}; d_j <= kend_tmp; d_j++) {
            double b_ar;
            double c_ai;
            double im;
            double re;
            b_ar = (&V[0][0])[d_j - 1].re;
            c_ai = (&V[0][0])[d_j - 1].im;
            if (c_ai == 0.0) {
              re = b_ar / colnorm;
              im = 0.0;
            } else if (b_ar == 0.0) {
              re = 0.0;
              im = c_ai / colnorm;
            } else {
              re = b_ar / colnorm;
              im = c_ai / colnorm;
            }
            (&V[0][0])[d_j - 1].re = re;
            (&V[0][0])[d_j - 1].im = im;
          }
        }
        for (int k_i{0}; k_i < 4; k_i++) {
          double ar;
          double b_ai;
          double b_br;
          double c_bi;
          ar = alpha1[k_i].re;
          b_ai = alpha1[k_i].im;
          b_br = beta1[k_i].re;
          c_bi = beta1[k_i].im;
          if (c_bi == 0.0) {
            if (b_ai == 0.0) {
              b_D[k_i].re = ar / b_br;
              b_D[k_i].im = 0.0;
            } else if (ar == 0.0) {
              b_D[k_i].re = 0.0;
              b_D[k_i].im = b_ai / b_br;
            } else {
              b_D[k_i].re = ar / b_br;
              b_D[k_i].im = b_ai / b_br;
            }
          } else if (b_br == 0.0) {
            if (ar == 0.0) {
              b_D[k_i].re = b_ai / c_bi;
              b_D[k_i].im = 0.0;
            } else if (b_ai == 0.0) {
              b_D[k_i].re = 0.0;
              b_D[k_i].im = -(ar / c_bi);
            } else {
              b_D[k_i].re = b_ai / c_bi;
              b_D[k_i].im = -(ar / c_bi);
            }
          } else {
            double bim;
            double brm;
            brm = std::abs(b_br);
            bim = std::abs(c_bi);
            if (brm > bim) {
              double c_d;
              double s;
              s = c_bi / b_br;
              c_d = b_br + (s * c_bi);
              b_D[k_i].re = (ar + (s * b_ai)) / c_d;
              b_D[k_i].im = (b_ai - (s * ar)) / c_d;
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
              b_D[k_i].re = ((ar * sgnbr) + (b_ai * sgnbi)) / brm;
              b_D[k_i].im = ((b_ai * sgnbr) - (ar * sgnbi)) / brm;
            } else {
              double c_d;
              double s;
              s = b_br / c_bi;
              c_d = c_bi + (s * b_br);
              b_D[k_i].re = ((s * ar) + b_ai) / c_d;
              b_D[k_i].im = ((s * b_ai) - ar) / c_d;
            }
          }
        }
      }
    }
  }
  for (int c_i{0}; c_i < 4; c_i++) {
    varargin_1[c_i] = b_D[c_i].re;
  }
  if (!std::isnan(varargin_1[0])) {
    idx = 1;
  } else {
    int d_k;
    idx = 0;
    d_k = 2;
    exitg2 = false;
    while ((!exitg2) && (d_k < 5)) {
      if (!std::isnan(varargin_1[d_k - 1])) {
        idx = d_k;
        exitg2 = true;
      } else {
        d_k++;
      }
    }
  }
  if (idx == 0) {
    iindx = 0;
  } else {
    double b_ex;
    int i2;
    b_ex = varargin_1[idx - 1];
    iindx = idx - 1;
    i2 = idx + 1;
    for (int e_k{i2}; e_k < 5; e_k++) {
      double d;
      d = varargin_1[e_k - 1];
      if (b_ex < d) {
        b_ex = d;
        iindx = e_k - 1;
      }
    }
  }
  quat[0] = V[iindx][3].re;
  quat[1] = V[iindx][0].re;
  quat[2] = V[iindx][1].re;
  quat[3] = V[iindx][2].re;
  if (quat[0] < 0.0) {
    for (int i5{0}; i5 < 4; i5++) {
      quat[i5] = -quat[i5];
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for rotm2quat.cpp
//
// [EOF]
//
