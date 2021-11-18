//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: colon.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double b_a
//                double b
//                ::coder::array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void eml_float_colon(double b_a, double b, ::coder::array<double, 2U> &y)
{
  double apnd;
  double b_b1;
  double cdiff;
  double ndbl;
  int h_n;
  ndbl = std::floor((b - b_a) + 0.5);
  apnd = b_a + ndbl;
  cdiff = apnd - b;
  if (std::abs(cdiff) <
      (4.4408920985006262E-16 * std::fmax(std::abs(b_a), std::abs(b)))) {
    ndbl++;
    b_b1 = b;
  } else if (cdiff > 0.0) {
    b_b1 = b_a + (ndbl - 1.0);
  } else {
    ndbl++;
    b_b1 = apnd;
  }
  if (ndbl >= 0.0) {
    h_n = static_cast<int>(ndbl);
  } else {
    h_n = 0;
  }
  y.set_size(1, h_n);
  if (h_n > 0) {
    y[0] = b_a;
    if (h_n > 1) {
      int nm1d2;
      y[h_n - 1] = b_b1;
      nm1d2 = (h_n - 1) / 2;
      for (int k{0}; k <= (nm1d2 - 2); k++) {
        y[k + 1] = b_a + ((static_cast<double>(k)) + 1.0);
        y[(h_n - k) - 2] = b_b1 - ((static_cast<double>(k)) + 1.0);
      }
      if ((nm1d2 * 2) == (h_n - 1)) {
        y[nm1d2] = (b_a + b_b1) / 2.0;
      } else {
        y[nm1d2] = b_a + (static_cast<double>(nm1d2));
        y[nm1d2 + 1] = b_b1 - (static_cast<double>(nm1d2));
      }
    }
  }
}

} // namespace coder

//
// File trailer for colon.cpp
//
// [EOF]
//
