//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.h
//
// Code generation for function 'svd'
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
namespace coder {
void svd(const emlrtStack *sp, real_T U[841], real_T S[841], real_T V[841]);

void svd(const emlrtStack *sp, const real_T A[9], real_T U[9], real_T S[9],
         real_T V[9]);

} // namespace coder

// End of code generation (svd.h)
