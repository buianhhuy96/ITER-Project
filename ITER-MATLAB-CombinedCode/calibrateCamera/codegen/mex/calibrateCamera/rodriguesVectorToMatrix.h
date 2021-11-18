//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rodriguesVectorToMatrix.h
//
// Code generation for function 'rodriguesVectorToMatrix'
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
void rodriguesVectorToMatrix(const real_T rotationVector[3],
                             real_T rotationMatrix[9]);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (rodriguesVectorToMatrix.h)
