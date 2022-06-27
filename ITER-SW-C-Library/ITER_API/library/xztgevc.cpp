//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xztgevc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xztgevc.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : const creal_T A[4][4]
//                creal_T V[4][4]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xztgevc(const creal_T A[4][4], creal_T V[4][4])
{
  creal_T work1[4];
  creal_T work2[4];
  double rworka[4];
  double anorm;
  double ascale;
  double b_x;
  for (int b_i{0}; b_i < 4; b_i++) {
    rworka[b_i] = 0.0;
  }
  anorm = std::abs(A[0][0].re) + std::abs(A[0][0].im);
  for (int j{0}; j < 3; j++) {
    double y;
    for (int c_i{0}; c_i <= j; c_i++) {
      rworka[j + 1] += std::abs(A[j + 1][c_i].re) + std::abs(A[j + 1][c_i].im);
    }
    y = rworka[j + 1] +
        (std::abs(A[j + 1][j + 1].re) + std::abs(A[j + 1][j + 1].im));
    if (y > anorm) {
      anorm = y;
    }
  }
  b_x = anorm;
  if (2.2250738585072014E-308 > anorm) {
    b_x = 2.2250738585072014E-308;
  }
  ascale = 1.0 / b_x;
  for (int je{3}; je >= 0; je--) {
    double acoeff;
    double b_x_tmp;
    double bcoeff_im;
    double bcoeff_re;
    double c_y;
    double dmin;
    double e_y;
    double g_x;
    double salpha_im;
    double salpha_re;
    double scale;
    double temp;
    double x_tmp;
    double xmx;
    double z;
    bool lscalea;
    bool lscaleb;
    x_tmp = A[je][je].re;
    b_x_tmp = A[je][je].im;
    g_x = (std::abs(x_tmp) + std::abs(b_x_tmp)) * ascale;
    if (1.0 > g_x) {
      g_x = 1.0;
    }
    temp = 1.0 / g_x;
    salpha_re = ascale * (temp * x_tmp);
    salpha_im = ascale * (temp * b_x_tmp);
    acoeff = temp * ascale;
    bcoeff_re = salpha_re;
    bcoeff_im = salpha_im;
    if ((temp >= 2.2250738585072014E-308) &&
        (acoeff < 4.0083367200179456E-292)) {
      lscalea = true;
    } else {
      lscalea = false;
    }
    z = std::abs(salpha_re) + std::abs(salpha_im);
    if ((z >= 2.2250738585072014E-308) && (z < 4.0083367200179456E-292)) {
      lscaleb = true;
    } else {
      lscaleb = false;
    }
    scale = 1.0;
    if (lscalea) {
      double j_x;
      j_x = anorm;
      if (2.4948003869184E+291 < anorm) {
        j_x = 2.4948003869184E+291;
      }
      scale = (4.0083367200179456E-292 / temp) * j_x;
    }
    if (lscaleb) {
      double b_y;
      b_y = 4.0083367200179456E-292 / z;
      if (b_y > scale) {
        scale = b_y;
      }
    }
    if (lscalea || lscaleb) {
      double d_y;
      double k_x;
      k_x = acoeff;
      if (1.0 > acoeff) {
        k_x = 1.0;
      }
      if (z > k_x) {
        k_x = z;
      }
      d_y = 1.0 / (2.2250738585072014E-308 * k_x);
      if (d_y < scale) {
        scale = d_y;
      }
      if (lscalea) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }
      bcoeff_re = scale * salpha_re;
      bcoeff_im = scale * salpha_im;
    }
    (void)std::memset(&work1[0], 0, 4U * (sizeof(creal_T)));
    work1[je].re = 1.0;
    work1[je].im = 0.0;
    dmin = (2.2204460492503131E-16 * acoeff) * anorm;
    c_y = 2.2204460492503131E-16 * (std::abs(bcoeff_re) + std::abs(bcoeff_im));
    if (c_y > dmin) {
      dmin = c_y;
    }
    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }
    for (int jr{0}; jr < je; jr++) {
      work1[jr].re = acoeff * A[je][jr].re;
      work1[jr].im = acoeff * A[je][jr].im;
    }
    work1[je].re = 1.0;
    work1[je].im = 0.0;
    for (int b_j{je}; b_j >= 1; b_j--) {
      double ai_tmp;
      double ar_tmp;
      double b_d_im;
      double bim;
      double brm;
      double d;
      double d_re;
      double im;
      double re;
      d_re = (acoeff * A[b_j - 1][b_j - 1].re) - bcoeff_re;
      b_d_im = (acoeff * A[b_j - 1][b_j - 1].im) - bcoeff_im;
      if ((std::abs(d_re) + std::abs(b_d_im)) <= dmin) {
        d_re = dmin;
        b_d_im = 0.0;
      }
      brm = std::abs(d_re);
      bim = std::abs(b_d_im);
      d = brm + bim;
      if (d < 1.0) {
        double b_d1;
        b_d1 = std::abs(work1[b_j - 1].re) + std::abs(work1[b_j - 1].im);
        if (b_d1 >= (1.1235582092889474E+307 * d)) {
          temp = 1.0 / b_d1;
          for (int c_jr{0}; c_jr <= je; c_jr++) {
            work1[c_jr].re *= temp;
            work1[c_jr].im *= temp;
          }
        }
      }
      ar_tmp = work1[b_j - 1].re;
      ai_tmp = work1[b_j - 1].im;
      if (b_d_im == 0.0) {
        if ((-ai_tmp) == 0.0) {
          re = (-ar_tmp) / d_re;
          im = 0.0;
        } else if ((-ar_tmp) == 0.0) {
          re = 0.0;
          im = (-ai_tmp) / d_re;
        } else {
          re = (-ar_tmp) / d_re;
          im = (-ai_tmp) / d_re;
        }
      } else if (d_re == 0.0) {
        if ((-ar_tmp) == 0.0) {
          re = (-ai_tmp) / b_d_im;
          im = 0.0;
        } else if ((-ai_tmp) == 0.0) {
          re = 0.0;
          im = -((-ar_tmp) / b_d_im);
        } else {
          re = (-ai_tmp) / b_d_im;
          im = -((-ar_tmp) / b_d_im);
        }
      } else if (brm > bim) {
        double c_d;
        double s;
        s = b_d_im / d_re;
        c_d = d_re + (s * b_d_im);
        re = ((-ar_tmp) + (s * (-ai_tmp))) / c_d;
        im = ((-ai_tmp) - (s * (-ar_tmp))) / c_d;
      } else if (bim == brm) {
        double sgnbi;
        double sgnbr;
        if (d_re > 0.0) {
          sgnbr = 0.5;
        } else {
          sgnbr = -0.5;
        }
        if (b_d_im > 0.0) {
          sgnbi = 0.5;
        } else {
          sgnbi = -0.5;
        }
        re = (((-ar_tmp) * sgnbr) + ((-ai_tmp) * sgnbi)) / brm;
        im = (((-ai_tmp) * sgnbr) - ((-ar_tmp) * sgnbi)) / brm;
      } else {
        double c_d;
        double s;
        s = d_re / b_d_im;
        c_d = b_d_im + (s * d_re);
        re = ((s * (-ar_tmp)) + (-ai_tmp)) / c_d;
        im = ((s * (-ai_tmp)) - (-ar_tmp)) / c_d;
      }
      work1[b_j - 1].re = re;
      work1[b_j - 1].im = im;
      if (b_j > 1) {
        double ca_im;
        double ca_re;
        double d2;
        d2 = std::abs(re) + std::abs(im);
        if (d2 > 1.0) {
          temp = 1.0 / d2;
          if ((acoeff * rworka[b_j - 1]) >= (1.1235582092889474E+307 * temp)) {
            for (int f_jr{0}; f_jr <= je; f_jr++) {
              work1[f_jr].re *= temp;
              work1[f_jr].im *= temp;
            }
          }
        }
        ca_re = acoeff * work1[b_j - 1].re;
        ca_im = acoeff * work1[b_j - 1].im;
        for (int g_jr{0}; g_jr <= (b_j - 2); g_jr++) {
          double b_ca_re_tmp;
          double ca_re_tmp;
          ca_re_tmp = A[b_j - 1][g_jr].im;
          b_ca_re_tmp = A[b_j - 1][g_jr].re;
          work1[g_jr].re += (ca_re * b_ca_re_tmp) - (ca_im * ca_re_tmp);
          work1[g_jr].im += (ca_re * ca_re_tmp) + (ca_im * b_ca_re_tmp);
        }
      }
    }
    (void)std::memset(&work2[0], 0, 4U * (sizeof(creal_T)));
    for (int jc{0}; jc <= je; jc++) {
      double V_re_tmp;
      double b_V_re_tmp;
      V_re_tmp = work1[jc].im;
      b_V_re_tmp = work1[jc].re;
      for (int b_jr{0}; b_jr < 4; b_jr++) {
        double c_V_re_tmp;
        double d_V_re_tmp;
        c_V_re_tmp = V[jc][b_jr].re;
        d_V_re_tmp = V[jc][b_jr].im;
        work2[b_jr].re += (c_V_re_tmp * b_V_re_tmp) - (d_V_re_tmp * V_re_tmp);
        work2[b_jr].im += (c_V_re_tmp * V_re_tmp) + (d_V_re_tmp * b_V_re_tmp);
      }
    }
    xmx = std::abs(work2[0].re) + std::abs(work2[0].im);
    e_y = std::abs(work2[1].re) + std::abs(work2[1].im);
    if (e_y > xmx) {
      xmx = e_y;
    }
    e_y = std::abs(work2[2].re) + std::abs(work2[2].im);
    if (e_y > xmx) {
      xmx = e_y;
    }
    e_y = std::abs(work2[3].re) + std::abs(work2[3].im);
    if (e_y > xmx) {
      xmx = e_y;
    }
    if (xmx > 2.2250738585072014E-308) {
      temp = 1.0 / xmx;
      for (int e_jr{0}; e_jr < 4; e_jr++) {
        V[je][e_jr].re = temp * work2[e_jr].re;
        V[je][e_jr].im = temp * work2[e_jr].im;
      }
    } else {
      for (int d_jr{0}; d_jr < 4; d_jr++) {
        V[je][d_jr].re = 0.0;
        V[je][d_jr].im = 0.0;
      }
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xztgevc.cpp
//
// [EOF]
//
