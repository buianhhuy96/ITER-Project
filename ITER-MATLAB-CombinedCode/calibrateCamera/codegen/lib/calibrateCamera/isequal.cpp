//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &varargin_1
//                const ::coder::array<boolean_T, 2U> &varargin_2
// Return Type  : boolean_T
//
namespace Codegen {
namespace coder {
boolean_T b_isequal(const ::coder::array<boolean_T, 2U> &varargin_1,
                    const ::coder::array<boolean_T, 2U> &varargin_2)
{
  boolean_T p;
  p = false;
  if (varargin_1.size(0) == varargin_2.size(0)) {
    if (varargin_1.size(1) == varargin_2.size(1)) {
      p = true;
    }
  }
  if (p) {
    if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
        int32_T k;
        boolean_T exitg1;
        p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
          int32_T b_k;
          boolean_T exitg2;
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k <= (varargin_1.size(0) - 1))) {
            if (varargin_1[b_k + (varargin_1.size(0) * k)] !=
                varargin_2[b_k + (varargin_2.size(0) * k)]) {
              p = false;
              exitg2 = true;
            } else {
              b_k++;
            }
          }
          if (!p) {
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
    }
  }
  return p;
}

//
// Arguments    : const real_T varargin_1_data[]
//                const int32_T varargin_1_size[2]
//                real_T varargin_2
// Return Type  : boolean_T
//
boolean_T c_isequal(const real_T varargin_1_data[],
                    const int32_T varargin_1_size[2], real_T varargin_2)
{
  boolean_T p;
  p = (varargin_1_size[1] == 1);
  if (p && (varargin_1_size[1] != 0)) {
    p = true;
    p = ((varargin_1_data[0] == varargin_2) && p);
  }
  return p;
}

//
// Arguments    : const real_T varargin_1[2]
//                const real_T varargin_2[2]
// Return Type  : boolean_T
//
boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return p;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for isequal.cpp
//
// [EOF]
//
