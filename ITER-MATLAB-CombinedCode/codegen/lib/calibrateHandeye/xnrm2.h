//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

#ifndef XNRM2_H
#define XNRM2_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
double b_xnrm2(int c_n, const double b_x[8], int ix0);

double c_xnrm2(int c_n, const double b_x[3][3], int ix0);

double d_xnrm2(int c_n, const double b_x[9][9], int ix0);

double e_xnrm2(int c_n, const double b_x[9], int ix0);

double f_xnrm2(const double b_x[3]);

double xnrm2(int c_n, const ::coder::array<double, 2U> &b_x, int ix0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xnrm2.h
//
// [EOF]
//
