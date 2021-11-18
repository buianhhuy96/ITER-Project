//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// HandeyeShah.h
//
// Code generation for function 'HandeyeShah'
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
void HandeyeShah(const emlrtStack *sp, const real_T As[240],
                 const real_T Bs[240], real_T b_X[16], real_T Y[16],
                 int32_T *err);

// End of code generation (HandeyeShah.h)
