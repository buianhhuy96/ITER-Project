//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_v2_mex_api.h
//
// Code generation for function '_coder_calibrateOneCamera_v2_mex_api'
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
void ComputeCamExtrinsics_api(const mxArray *const prhs[3], int32_T nlhs,
                              const mxArray *plhs[6]);

void HandeyeShah_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[3]);

void calibrateOneCamera_v2_api(const mxArray *const prhs[3], int32_T nlhs,
                               const mxArray *plhs[5]);

void computeErrors_api(const mxArray *const prhs[7], const mxArray **plhs);

void preprocessImages_api(const mxArray *const prhs[3], const mxArray **plhs);

void readRobotPoses_api(const mxArray *prhs, int32_T nlhs,
                        const mxArray *plhs[2]);

// End of code generation (_coder_calibrateOneCamera_v2_mex_api.h)
