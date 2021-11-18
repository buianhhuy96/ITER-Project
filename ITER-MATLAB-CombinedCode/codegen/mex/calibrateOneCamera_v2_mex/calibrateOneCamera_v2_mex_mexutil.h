//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2_mex_mexutil.h
//
// Code generation for function 'calibrateOneCamera_v2_mex_mexutil'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                         const mxArray *m2, emlrtMCInfo *location);

void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                        const emlrtMsgIdentifier *msgId, char_T ret[14]);

void emlrt_marshallIn(const emlrtStack *sp,
                      const mxArray *a__output_of_sprintf_,
                      const char_T *identifier, char_T y[14]);

void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                      const emlrtMsgIdentifier *parentId, char_T y[14]);

const mxArray *emlrt_marshallOut(const real_T u);

// End of code generation (calibrateOneCamera_v2_mex_mexutil.h)
