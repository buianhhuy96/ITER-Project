//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_ITER_API_v2_mex.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef _CODER_ITER_API_V2_MEX_H
#define _CODER_ITER_API_V2_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_ComputeCamExtrinsics_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                             int32_T nrhs,
                                             const mxArray *prhs[3]);

void unsafe_HandeyeShah_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                    int32_T nrhs, const mxArray *prhs[2]);

void unsafe_calibrateOneCamera_mexFunction(int32_T nlhs, mxArray *plhs[4],
                                           int32_T nrhs,
                                           const mxArray *prhs[3]);

void unsafe_computeErrors_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                      int32_T nrhs, const mxArray *prhs[7]);

void unsafe_preprocessImages_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs, const mxArray *prhs[2]);

void unsafe_readRobotPoses_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                       int32_T nrhs, const mxArray *prhs[2]);

#endif
//
// File trailer for _coder_ITER_API_v2_mex.h
//
// [EOF]
//
