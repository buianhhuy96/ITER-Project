//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rodriguesMatrixToVector.h
//
// Code generation for function 'rodriguesMatrixToVector'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(const emlrtStack *sp, real_T rotationMatrix[9],
                             real_T rotationVector[3]);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (rodriguesMatrixToVector.h)
