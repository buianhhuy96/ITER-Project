//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rgb2gray.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef RGB2GRAY_H
#define RGB2GRAY_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void rgb2gray(const ::coder::array<unsigned char, 3U> &d_X,
              ::coder::array<unsigned char, 2U> &o_I);

}

#endif
//
// File trailer for rgb2gray.h
//
// [EOF]
//
