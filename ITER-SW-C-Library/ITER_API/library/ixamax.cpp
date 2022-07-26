//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixamax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ixamax.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int h_n
//                const double b_x[15][15]
//                int incx
// Return Type  : int
//
namespace ITER {
namespace coder {
namespace internal {
namespace blas {
int ixamax(int h_n, const double b_x[15][15], int incx)
{
  int idxmax;
  if ((h_n < 1) || (incx < 1)) {
    idxmax = 0;
  } else {
    idxmax = 1;
    if (h_n > 1) {
      double smax;
      smax = std::abs((&b_x[0][0])[0]);
      for (int k{2}; k <= h_n; k++) {
        double s;
        s = std::abs((&b_x[0][0])[(k - 1) * incx]);
        if (s > smax) {
          idxmax = k;
          smax = s;
        }
      }
    }
  }
  return idxmax;
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for ixamax.cpp
//
// [EOF]
//
