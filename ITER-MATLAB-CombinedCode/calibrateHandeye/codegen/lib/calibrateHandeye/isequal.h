//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

#ifndef ISEQUAL_H
#define ISEQUAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
bool b_isequal(const ::coder::array<bool, 2U> &varargin_1,
               const ::coder::array<bool, 2U> &varargin_2);

bool c_isequal(const ::coder::array<double, 2U> &varargin_1, double varargin_2);

bool isequal(const double varargin_1[2], const double varargin_2[2]);

} // namespace coder

#endif
//
// File trailer for isequal.h
//
// [EOF]
//
