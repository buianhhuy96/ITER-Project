//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

#ifndef POLYFIT_H
#define POLYFIT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void polyfit(const ::coder::array<double, 1U> &x,
             const ::coder::array<double, 1U> &y, double n,
             ::coder::array<double, 2U> &p);

void polyfit(const ::coder::array<double, 2U> &x,
             const ::coder::array<double, 2U> &y, double n,
             ::coder::array<double, 2U> &p);

} // namespace coder

#endif
//
// File trailer for polyfit.h
//
// [EOF]
//
