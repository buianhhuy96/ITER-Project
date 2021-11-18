//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_mex_api.h
//
// Code generation for function '_coder_calibrateOneCamera_mex_api'
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
void calibrateOneCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                            const mxArray *plhs[3]);

void preprocessImages_api(const mxArray *prhs, const mxArray **plhs);

} // namespace Codegen

// End of code generation (_coder_calibrateOneCamera_mex_api.h)
