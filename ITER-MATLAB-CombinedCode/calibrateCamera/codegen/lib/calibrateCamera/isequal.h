//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef ISEQUAL_H
#define ISEQUAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
boolean_T b_isequal(const ::coder::array<boolean_T, 2U> &varargin_1,
                    const ::coder::array<boolean_T, 2U> &varargin_2);

boolean_T c_isequal(const real_T varargin_1_data[],
                    const int32_T varargin_1_size[2], real_T varargin_2);

boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2]);

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for isequal.h
//
// [EOF]
//
