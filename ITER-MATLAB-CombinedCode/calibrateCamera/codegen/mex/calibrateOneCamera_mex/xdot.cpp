//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdot.cpp
//
// Code generation for function 'xdot'
//

// Include files
#include "xdot.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>

// Function Definitions
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
real_T xdot(int32_T n, const ::coder::array<real_T, 1U> &x,
            const ::coder::array<real_T, 1U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T d;
  if (n < 1) {
    d = 0.0;
  } else {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    d = ddot(&n_t, &(((::coder::array<real_T, 1U> *)&x)->data())[0], &incx_t,
             &(((::coder::array<real_T, 1U> *)&y)->data())[0], &incy_t);
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xdot.cpp)
