//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const double varargin_1[2]
//                const double varargin_2[2]
// Return Type  : boolean_T
//
namespace coder {
boolean_T isequal(const double varargin_1[2], const double varargin_2[2])
{
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
    }
    if (!b_p) {
      exitg1 = true;
    } else {
      k++;
    }
  }
  return b_p || p;
}

//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                double varargin_2
// Return Type  : boolean_T
//
boolean_T isequal(const ::coder::array<double, 2U> &varargin_1,
                  double varargin_2)
{
  boolean_T b_p;
  boolean_T p;
  p = false;
  b_p = (varargin_1.size(1) == 1);
  if (b_p) {
    if (varargin_1.size(1) != 0) {
      int k;
      boolean_T exitg1;
      b_p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
        b_p = ((varargin_1[k] == varargin_2) && b_p);
        if (!b_p) {
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
  }
  return b_p || p;
}

} // namespace coder

//
// File trailer for isequal.cpp
//
// [EOF]
//
