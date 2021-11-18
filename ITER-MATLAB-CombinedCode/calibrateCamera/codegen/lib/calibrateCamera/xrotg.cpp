//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrotg.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xrotg.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : real_T *b_a
//                real_T *b
//                real_T *c
//                real_T *s
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void xrotg(real_T *b_a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = std::abs(*b_a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *b_a;
  }
  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b_a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt((ads * ads) + (bds * bds));
    if (roe < 0.0) {
      scale = -scale;
    }
    *c = (*b_a) / scale;
    *s = (*b) / scale;
    if (absa > absb) {
      *b = *s;
    } else if ((*c) != 0.0) {
      *b = 1.0 / (*c);
    } else {
      *b = 1.0;
    }
    *b_a = scale;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xrotg.cpp
//
// [EOF]
//
