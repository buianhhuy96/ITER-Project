//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// normalizeControlPoints.h
//
// Code generation for function 'normalizeControlPoints'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
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
namespace images {
namespace geotrans {
namespace internal {
void b_normalizeControlPoints(const emlrtStack *sp,
                              const ::coder::array<real_T, 2U> &pts,
                              ::coder::array<real_T, 2U> &ptsNorm,
                              real_T normMatrixInv[9]);

void normalizeControlPoints(const emlrtStack *sp,
                            const ::coder::array<real_T, 2U> &pts,
                            ::coder::array<real_T, 2U> &ptsNorm,
                            real_T normMatrixInv[9]);

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder
} // namespace Codegen

// End of code generation (normalizeControlPoints.h)
