//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xrotg.cpp
//
// Code generation for function 'xrotg'
//

// Include files
#include "xrotg.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"
#include "blas.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  *c = 0.0;
  *s = 0.0;
  drotg(a, b, c, s);
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xrotg.cpp)
