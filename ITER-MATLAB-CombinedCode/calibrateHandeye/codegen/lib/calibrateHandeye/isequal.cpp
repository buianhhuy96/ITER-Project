//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
  bool p;
  p = false;
  if (varargin_1.size(0) == varargin_2.size(0)) {
    if (varargin_1.size(1) == varargin_2.size(1)) {
      p = true;
    }
  }
  if (p) {
    if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      if ((varargin_2.size(0) != 0) && (varargin_2.size(1) != 0)) {
        int k;
        bool exitg1;
        p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
          int c_k;
          bool exitg2;
          c_k = 0;
          exitg2 = false;
          while ((!exitg2) && (c_k <= (varargin_1.size(0) - 1))) {
            if (varargin_1[c_k + (varargin_1.size(0) * k)] !=
                varargin_2[c_k + (varargin_2.size(0) * k)]) {
              p = false;
              exitg2 = true;
            } else {
              c_k++;
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
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                double varargin_2
// Return Type  : bool
//
bool c_isequal(const ::coder::array<double, 2U> &varargin_1, double varargin_2)
{
  bool p;
  p = (varargin_1.size(1) == 1);
  if (p) {
    if (varargin_1.size(1) != 0) {
      int k;
      bool exitg1;
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (varargin_1.size(1) - 1))) {
        if (!(varargin_1[k] == varargin_2)) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
  }
  return p;
}

//
// Arguments    : const double varargin_1[2]
//                const double varargin_2[2]
// Return Type  : bool
//
bool isequal(const double varargin_1[2], const double varargin_2[2])
{
  int k;
  bool exitg1;
  bool p;
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

//
// File trailer for isequal.cpp
//
// [EOF]
//
