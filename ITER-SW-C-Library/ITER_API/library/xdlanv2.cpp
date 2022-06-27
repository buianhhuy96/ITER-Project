//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdlanv2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "xdlanv2.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double *b_a
//                double *b
//                double *c
//                double *d
//                double *rt1r
//                double *rt1i
//                double *rt2r
//                double *rt2i
//                double *b_cs
//                double *b_sn
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xdlanv2(double *b_a, double *b, double *c, double *d, double *rt1r,
             double *rt1i, double *rt2r, double *rt2i, double *b_cs,
             double *b_sn)
{
  if ((*c) == 0.0) {
    *b_cs = 1.0;
    *b_sn = 0.0;
  } else if ((*b) == 0.0) {
    double temp;
    *b_cs = 0.0;
    *b_sn = 1.0;
    temp = *d;
    *d = *b_a;
    *b_a = temp;
    *b = -(*c);
    *c = 0.0;
  } else {
    double c_d;
    c_d = (*b_a) - (*d);
    if ((c_d == 0.0) && (((*b) < 0.0) != ((*c) < 0.0))) {
      *b_cs = 1.0;
      *b_sn = 0.0;
    } else {
      double b_bcmax_tmp;
      double bcmax;
      double bcmax_tmp;
      double bcmis;
      double p;
      double scale;
      double z;
      int b_b;
      int c_c;
      p = 0.5 * c_d;
      bcmax_tmp = std::abs(*b);
      b_bcmax_tmp = std::abs(*c);
      bcmax = std::fmax(bcmax_tmp, b_bcmax_tmp);
      if (!((*b) < 0.0)) {
        b_b = 1;
      } else {
        b_b = -1;
      }
      if (!((*c) < 0.0)) {
        c_c = 1;
      } else {
        c_c = -1;
      }
      bcmis = (std::fmin(bcmax_tmp, b_bcmax_tmp) * (static_cast<double>(b_b))) *
              (static_cast<double>(c_c));
      scale = std::fmax(std::abs(p), bcmax);
      z = ((p / scale) * p) + ((bcmax / scale) * bcmis);
      if (z >= 8.8817841970012523E-16) {
        double b_p;
        double c_a;
        double tau;
        c_a = std::sqrt(scale) * std::sqrt(z);
        if (!(p < 0.0)) {
          b_p = c_a;
        } else {
          b_p = -c_a;
        }
        z = p + b_p;
        *b_a = (*d) + z;
        *d -= (bcmax / z) * bcmis;
        tau = rt_hypotd_snf(*c, z);
        *b_cs = z / tau;
        *b_sn = (*c) / tau;
        *b -= *c;
        *c = 0.0;
      } else {
        double aa;
        double b_bb;
        double b_cc;
        double dd;
        double sigma;
        double tau;
        double temp;
        int b_sigma;
        sigma = (*b) + (*c);
        tau = rt_hypotd_snf(sigma, c_d);
        *b_cs = std::sqrt(0.5 * ((std::abs(sigma) / tau) + 1.0));
        if (!(sigma < 0.0)) {
          b_sigma = 1;
        } else {
          b_sigma = -1;
        }
        *b_sn = (-(p / (tau * (*b_cs)))) * (static_cast<double>(b_sigma));
        aa = ((*b_a) * (*b_cs)) + ((*b) * (*b_sn));
        b_bb = ((-(*b_a)) * (*b_sn)) + ((*b) * (*b_cs));
        b_cc = ((*c) * (*b_cs)) + ((*d) * (*b_sn));
        dd = ((-(*c)) * (*b_sn)) + ((*d) * (*b_cs));
        *b = (b_bb * (*b_cs)) + (dd * (*b_sn));
        *c = ((-aa) * (*b_sn)) + (b_cc * (*b_cs));
        temp = 0.5 * (((aa * (*b_cs)) + (b_cc * (*b_sn))) +
                      (((-b_bb) * (*b_sn)) + (dd * (*b_cs))));
        *b_a = temp;
        *d = temp;
        if ((*c) != 0.0) {
          if ((*b) != 0.0) {
            if (((*b) < 0.0) == ((*c) < 0.0)) {
              double cs1;
              double d_a;
              double sab;
              double sac;
              double sn1;
              sab = std::sqrt(std::abs(*b));
              sac = std::sqrt(std::abs(*c));
              d_a = sab * sac;
              if (!((*c) < 0.0)) {
                p = d_a;
              } else {
                p = -d_a;
              }
              tau = 1.0 / std::sqrt(std::abs((*b) + (*c)));
              *b_a = temp + p;
              *d = temp - p;
              *b -= *c;
              *c = 0.0;
              cs1 = sab * tau;
              sn1 = sac * tau;
              temp = ((*b_cs) * cs1) - ((*b_sn) * sn1);
              *b_sn = ((*b_cs) * sn1) + ((*b_sn) * cs1);
              *b_cs = temp;
            }
          } else {
            *b = -(*c);
            *c = 0.0;
            temp = *b_cs;
            *b_cs = -(*b_sn);
            *b_sn = temp;
          }
        }
      }
    }
  }
  *rt1r = *b_a;
  *rt2r = *d;
  if ((*c) == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = std::sqrt(std::abs(*b)) * std::sqrt(std::abs(*c));
    *rt2i = -(*rt1i);
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xdlanv2.cpp
//
// [EOF]
//
