//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    int32_T b;
    b = n - 1;
    for (int32_T k{0}; k <= b; k++) {
      int32_T i;
      i = (iy0 + k) - 1;
      y[i] += a * y[(ix0 + k) - 1];
    }
  }
}

void xaxpy(real_T a, const real_T x[3], real_T y[9], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (int32_T k{0}; k < 2; k++) {
      int32_T i;
      i = (iy0 + k) - 1;
      y[i] += a * x[k + 1];
    }
  }
}

void xaxpy(real_T a, const real_T x[9], int32_T ix0, real_T y[3])
{
  if (!(a == 0.0)) {
    for (int32_T k{0}; k < 2; k++) {
      y[k + 1] += a * x[(ix0 + k) - 1];
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.cpp)
