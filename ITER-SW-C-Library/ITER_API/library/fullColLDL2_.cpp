//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fullColLDL2_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "fullColLDL2_.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : y_struct_T *obj
//                int NColsRemain
//                double REG_PRIMAL
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(y_struct_T *obj, int NColsRemain, double REG_PRIMAL)
{
  int LDimSizeP1;
  int lastDiag;
  LDimSizeP1 = obj->ldm;
  for (int k{0}; k < NColsRemain; k++) {
    double alpha1;
    double y;
    int LD_diagOffset;
    int subMatrixDim;
    LD_diagOffset = (LDimSizeP1 + 1) * k;
    if (std::abs((&obj->FMat[0][0])[LD_diagOffset]) <= obj->regTol_) {
      (&obj->FMat[0][0])[LD_diagOffset] += REG_PRIMAL;
    }
    alpha1 = -1.0 / (&obj->FMat[0][0])[LD_diagOffset];
    subMatrixDim = (NColsRemain - k) - 2;
    for (int idx{0}; idx <= subMatrixDim; idx++) {
      obj->b_workspace_ = (&obj->FMat[0][0])[(LD_diagOffset + idx) + 1];
    }
    y = obj->b_workspace_;
    if (!(alpha1 == 0.0)) {
      int b_jA;
      b_jA = LD_diagOffset + LDimSizeP1;
      for (int j{0}; j <= subMatrixDim; j++) {
        if (y != 0.0) {
          double temp;
          int i1;
          int i2;
          temp = y * alpha1;
          i1 = b_jA + 2;
          i2 = subMatrixDim + b_jA;
          for (int ijA{i1}; ijA <= (i2 + 2); ijA++) {
            (&obj->FMat[0][0])[ijA - 1] += obj->b_workspace_ * temp;
          }
        }
        b_jA += obj->ldm;
      }
    }
    for (int b_idx{0}; b_idx <= subMatrixDim; b_idx++) {
      int b_i;
      b_i = (LD_diagOffset + b_idx) + 1;
      (&obj->FMat[0][0])[b_i] /= (&obj->FMat[0][0])[LD_diagOffset];
    }
  }
  lastDiag = (obj->ldm + 1) * (NColsRemain - 1);
  if (std::abs((&obj->FMat[0][0])[lastDiag]) <= obj->regTol_) {
    (&obj->FMat[0][0])[lastDiag] += REG_PRIMAL;
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for fullColLDL2_.cpp
//
// [EOF]
//
