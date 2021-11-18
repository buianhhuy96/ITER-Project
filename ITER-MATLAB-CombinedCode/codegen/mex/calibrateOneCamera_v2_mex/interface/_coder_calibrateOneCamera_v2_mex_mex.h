//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_v2_mex_mex.h
//
// Code generation for function '_coder_calibrateOneCamera_v2_mex_mex'
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
void ComputeCamExtrinsics_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                      int32_T nrhs, const mxArray *prhs[3]);

void HandeyeShah_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                             const mxArray *prhs[2]);

void calibrateOneCamera_v2_mexFunction(int32_T nlhs, mxArray *plhs[5],
                                       int32_T nrhs, const mxArray *prhs[3]);

void computeErrors_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                               const mxArray *prhs[7]);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void preprocessImages_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                  const mxArray *prhs[3]);

void readRobotPoses_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
                                const mxArray *prhs[1]);

// End of code generation (_coder_calibrateOneCamera_v2_mex_mex.h)
