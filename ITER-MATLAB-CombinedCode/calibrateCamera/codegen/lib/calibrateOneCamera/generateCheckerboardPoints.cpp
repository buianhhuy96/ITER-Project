//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: generateCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "generateCheckerboardPoints.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const int boardSize[2]
//                double squareSize
//                ::coder::array<double, 2U> &c_worldPoints
// Return Type  : void
//
namespace Codegen {
namespace coder {
void generateCheckerboardPoints(const int boardSize[2], double squareSize,
                                ::coder::array<double, 2U> &c_worldPoints)
{
  double boardSize_idx_0_tmp;
  int b_i;
  int boardSize_idx_0;
  int i1;
  unsigned int k;
  boardSize_idx_0_tmp = (static_cast<double>(boardSize[0])) - 1.0;
  boardSize_idx_0 = static_cast<int>(
      static_cast<double>(((static_cast<double>(boardSize[0])) - 1.0) *
                          ((static_cast<double>(boardSize[1])) - 1.0)));
  c_worldPoints.set_size(boardSize_idx_0, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < boardSize_idx_0; i1++) {
      c_worldPoints[i1 + (c_worldPoints.size(0) * b_i)] = 0.0;
    }
  }
  k = 1U;
  b_i = static_cast<int>(static_cast<double>(
      (((static_cast<double>(boardSize[1])) - 1.0) - 1.0) + 1.0));
  for (int j{0}; j < b_i; j++) {
    i1 = static_cast<int>(
        static_cast<double>((boardSize_idx_0_tmp - 1.0) + 1.0));
    for (int c_i{0}; c_i < i1; c_i++) {
      boardSize_idx_0 = (static_cast<int>(static_cast<unsigned int>(
                            k + (static_cast<unsigned int>(c_i))))) -
                        1;
      c_worldPoints[boardSize_idx_0] = (static_cast<double>(j)) * squareSize;
      c_worldPoints[boardSize_idx_0 + c_worldPoints.size(0)] =
          (static_cast<double>(c_i)) * squareSize;
    }
    k += static_cast<unsigned int>(static_cast<int>(
        static_cast<double>((boardSize_idx_0_tmp - 1.0) + 1.0)));
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for generateCheckerboardPoints.cpp
//
// [EOF]
//
