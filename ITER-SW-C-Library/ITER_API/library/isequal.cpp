//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                double varargin_2
// Return Type  : bool
//
namespace ITER {
namespace coder {
bool b_isequal(const ::coder::array<double, 2U> &varargin_1, double varargin_2)
{
  bool b_p;
  bool c_p;
  b_p = (varargin_1.size(1) == 1);
  c_p = b_p;
  if (b_p) {
    if (varargin_1.size(1) != 0) {
      int k;
      bool exitg1;
      c_p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
        if (!(varargin_1[k] == varargin_2)) {
          c_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
  }
  return c_p;
}

//
// Arguments    : const double varargin_1[2]
//                const double varargin_2[2]
// Return Type  : bool
//
bool isequal(const double varargin_1[2], const double varargin_2[2])
{
  int k;
  bool b_p;
  bool exitg1;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return b_p;
}

} // namespace coder
} // namespace ITER

//
// File trailer for isequal.cpp
//
// [EOF]
//
