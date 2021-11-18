//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef XZLARFG_H
#define XZLARFG_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int h_n, double *alpha1, ::coder::array<double, 2U> &b_x,
               int ix0);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzlarfg.h
//
// [EOF]
//
