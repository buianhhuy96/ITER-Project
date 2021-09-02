//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &varargin_1
//                const ::coder::array<bool, 2U> &varargin_2
// Return Type  : bool
//
namespace coder {
bool b_isequal(const ::coder::array<bool, 2U> &varargin_1,
               const ::coder::array<bool, 2U> &varargin_2)
{
  bool b_p;
  bool p;
  p = false;
  b_p = false;
  if (varargin_1.size(0) == varargin_2.size(0)) {
    if (varargin_1.size(1) == varargin_2.size(1)) {
      b_p = true;
    }
  }
  if (b_p) {
    if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
        int k;
        bool exitg1;
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
          int b_k;
          bool exitg2;
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k <= (varargin_1.size(0) - 1))) {
            b_p = ((varargin_1[b_k + (varargin_1.size(0) * k)] ==
                    varargin_2[b_k + (varargin_2.size(0) * k)]) &&
                   b_p);
            if (!b_p) {
              exitg2 = true;
            } else {
              b_k++;
            }
          }
          if (!b_p) {
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
    }
  }
  return b_p || p;
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
  bool p;
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
// Return Type  : bool
//
bool isequal(const ::coder::array<double, 2U> &varargin_1, double varargin_2)
{
  bool b_p;
  bool p;
  p = false;
  b_p = (varargin_1.size(1) == 1);
  if (b_p) {
    if (varargin_1.size(1) != 0) {
      int k;
      bool exitg1;
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
