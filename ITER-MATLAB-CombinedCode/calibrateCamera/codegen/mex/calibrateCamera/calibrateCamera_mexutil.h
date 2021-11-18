//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera_mexutil.h
//
// Code generation for function 'calibrateCamera_mexutil'
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
const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                         const mxArray *m2, emlrtMCInfo *location);

namespace coder {
void e_emlrt_marshallIn(const emlrtStack *sp,
                        const mxArray *a__output_of_sprintf_,
                        const char_T *identifier, char_T y[14]);

void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId, char_T y[14]);

} // namespace coder
void emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                      const emlrtMsgIdentifier *msgId, char_T ret[14]);

} // namespace Codegen

// End of code generation (calibrateCamera_mexutil.h)
