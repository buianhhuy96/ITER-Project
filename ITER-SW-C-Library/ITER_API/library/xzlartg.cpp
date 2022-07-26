//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlartg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "xzlartg.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const creal_T f
//                const creal_T g
//                double *b_cs
//                creal_T *b_sn
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
namespace reflapack {
void b_xzlartg(const creal_T f, const creal_T g, double *b_cs, creal_T *b_sn)
{
  double b_y;
  double c_y;
  double fs_im;
  double fs_re;
  double gs_im;
  double gs_re;
  double scale;
  double scale_tmp;
  double y;
  bool guard1{false};
  scale_tmp = std::abs(f.re);
  y = std::abs(f.im);
  if (y > scale_tmp) {
    scale_tmp = y;
  }
  b_y = std::abs(g.re);
  c_y = std::abs(g.im);
  if (c_y > b_y) {
    b_y = c_y;
  }
  scale = scale_tmp;
  if (b_y > scale_tmp) {
    scale = b_y;
  }
  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *b_cs = 1.0;
      b_sn->re = 0.0;
      b_sn->im = 0.0;
    } else {
      do {
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    double b_f2;
    double b_x;
    double g2;
    b_f2 = (fs_re * fs_re) + (fs_im * fs_im);
    g2 = (gs_re * gs_re) + (gs_im * gs_im);
    b_x = g2;
    if (1.0 > g2) {
      b_x = 1.0;
    }
    if (b_f2 <= (b_x * 2.0041683600089728E-292)) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        double d;
        *b_cs = 0.0;
        d = rt_hypotd_snf(gs_re, gs_im);
        b_sn->re = gs_re / d;
        b_sn->im = (-gs_im) / d;
      } else {
        double b_gs_im;
        double b_gs_re;
        double ff_im;
        double ff_re;
        double g2s;
        g2s = std::sqrt(g2);
        *b_cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        if (scale_tmp > 1.0) {
          double d;
          d = rt_hypotd_snf(f.re, f.im);
          ff_re = f.re / d;
          ff_im = f.im / d;
        } else {
          double b_dr;
          double c_di;
          double d;
          b_dr = 7.4428285367870146E+137 * f.re;
          c_di = 7.4428285367870146E+137 * f.im;
          d = rt_hypotd_snf(b_dr, c_di);
          ff_re = b_dr / d;
          ff_im = c_di / d;
        }
        b_gs_re = gs_re / g2s;
        b_gs_im = (-gs_im) / g2s;
        b_sn->re = (ff_re * b_gs_re) - (ff_im * b_gs_im);
        b_sn->im = (ff_re * b_gs_im) + (ff_im * b_gs_re);
      }
    } else {
      double d;
      double f2s;
      double r_im;
      double r_re;
      f2s = std::sqrt((g2 / b_f2) + 1.0);
      *b_cs = 1.0 / f2s;
      d = b_f2 + g2;
      r_re = (f2s * fs_re) / d;
      r_im = (f2s * fs_im) / d;
      b_sn->re = (r_re * gs_re) - (r_im * (-gs_im));
      b_sn->im = (r_re * (-gs_im)) + (r_im * gs_re);
    }
  }
}

//
// Arguments    : const creal_T f
//                const creal_T g
//                double *b_cs
//                creal_T *b_sn
//                creal_T *r
// Return Type  : void
//
void xzlartg(const creal_T f, const creal_T g, double *b_cs, creal_T *b_sn,
             creal_T *r)
{
  double b_y;
  double c_y;
  double fs_im;
  double fs_re;
  double gs_im;
  double gs_re;
  double scale;
  double scale_tmp;
  double y;
  int count;
  int rescaledir;
  bool guard1{false};
  scale_tmp = std::abs(f.re);
  y = std::abs(f.im);
  if (y > scale_tmp) {
    scale_tmp = y;
  }
  b_y = std::abs(g.re);
  c_y = std::abs(g.im);
  if (c_y > b_y) {
    b_y = c_y;
  }
  scale = scale_tmp;
  if (b_y > scale_tmp) {
    scale = b_y;
  }
  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = -1;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));
    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *b_cs = 1.0;
      b_sn->re = 0.0;
      b_sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));
      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    double b_f2;
    double b_x;
    double g2;
    b_f2 = (fs_re * fs_re) + (fs_im * fs_im);
    g2 = (gs_re * gs_re) + (gs_im * gs_im);
    b_x = g2;
    if (1.0 > g2) {
      b_x = 1.0;
    }
    if (b_f2 <= (b_x * 2.0041683600089728E-292)) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        double d;
        *b_cs = 0.0;
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        d = rt_hypotd_snf(gs_re, gs_im);
        b_sn->re = gs_re / d;
        b_sn->im = (-gs_im) / d;
      } else {
        double b_gs_im;
        double b_gs_re;
        double ff_im;
        double ff_re;
        double g2s;
        g2s = std::sqrt(g2);
        *b_cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        if (scale_tmp > 1.0) {
          double d;
          d = rt_hypotd_snf(f.re, f.im);
          ff_re = f.re / d;
          ff_im = f.im / d;
        } else {
          double b_dr;
          double c_di;
          double d;
          b_dr = 7.4428285367870146E+137 * f.re;
          c_di = 7.4428285367870146E+137 * f.im;
          d = rt_hypotd_snf(b_dr, c_di);
          ff_re = b_dr / d;
          ff_im = c_di / d;
        }
        b_gs_re = gs_re / g2s;
        b_gs_im = (-gs_im) / g2s;
        b_sn->re = (ff_re * b_gs_re) - (ff_im * b_gs_im);
        b_sn->im = (ff_re * b_gs_im) + (ff_im * b_gs_re);
        r->re = ((*b_cs) * f.re) + ((b_sn->re * g.re) - (b_sn->im * g.im));
        r->im = ((*b_cs) * f.im) + ((b_sn->re * g.im) + (b_sn->im * g.re));
      }
    } else {
      double d;
      double f2s;
      double r_im;
      double r_re;
      f2s = std::sqrt((g2 / b_f2) + 1.0);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *b_cs = 1.0 / f2s;
      d = b_f2 + g2;
      r_re = r->re / d;
      r_im = r->im / d;
      b_sn->re = (r_re * gs_re) - (r_im * (-gs_im));
      b_sn->im = (r_re * (-gs_im)) + (r_im * gs_re);
      if (rescaledir > 0) {
        for (int b_i{0}; b_i <= count; b_i++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else if (rescaledir < 0) {
        for (int c_i{0}; c_i <= count; c_i++) {
          r->re *= 1.3435752215134178E-138;
          r->im *= 1.3435752215134178E-138;
        }
      } else {
        /* no actions */
      }
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for xzlartg.cpp
//
// [EOF]
//
