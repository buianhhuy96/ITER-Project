//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef IMFILTER_H
#define IMFILTER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_conv2_separable_valid(const double hCol[29], const double hRow[29],
                             const ::coder::array<double, 2U> &inImg,
                             const double finalSize[2],
                             ::coder::array<double, 2U> &outImg);

void conv2_separable_valid(const double hCol[15], const double hRow[15],
                           const ::coder::array<double, 2U> &inImg,
                           const double finalSize[2],
                           ::coder::array<double, 2U> &outImg);

void imfilter(::coder::array<float, 2U> &varargin_1);

void padImage_outSize(const ::coder::array<float, 2U> &a_tmp,
                      const double pad[2], ::coder::array<float, 2U> &a);

} // namespace coder

#endif
//
// File trailer for imfilter.h
//
// [EOF]
//
