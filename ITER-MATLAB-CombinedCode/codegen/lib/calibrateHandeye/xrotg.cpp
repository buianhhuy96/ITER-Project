//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrotg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double *b_a
//                double *b
//                double *c
//                double *s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xrotg(double *b_a, double *b, double *c, double *s)
{
  double absa;
  double absb;
  double b_c;
  double b_s;
  double roe;
  double scale;
  roe = *b;
  absa = std::abs(*b_a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *b_a;
  }
  scale = absa + absb;
  if (scale == 0.0) {
    b_s = 0.0;
    b_c = 1.0;
    *b_a = 0.0;
    *b = 0.0;
  } else {
    double ads;
    double bds;
    double r;
    ads = absa / scale;
    bds = absb / scale;
    r = scale * std::sqrt((ads * ads) + (bds * bds));
    if (roe < 0.0) {
      r = -r;
    }
    b_c = (*b_a) / r;
    b_s = (*b) / r;
    if (absa > absb) {
      *b = b_s;
    } else if (b_c != 0.0) {
      *b = 1.0 / b_c;
    } else {
      *b = 1.0;
    }
    *b_a = r;
  }
  *c = b_c;
  *s = b_s;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xrotg.cpp
//
// [EOF]
//
