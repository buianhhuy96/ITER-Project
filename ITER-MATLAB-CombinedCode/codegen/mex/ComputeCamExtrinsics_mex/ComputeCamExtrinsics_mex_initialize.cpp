//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics_mex_initialize.cpp
//
// Code generation for function 'ComputeCamExtrinsics_mex_initialize'
//

// Include files
#include "ComputeCamExtrinsics_mex_initialize.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "_coder_ComputeCamExtrinsics_mex_mex.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Declarations
static void ComputeCamExtrinsics_mex_once();

// Function Definitions
static void ComputeCamExtrinsics_mex_once()
{
  const int32_T postfix_exprs_1_0[7]{0, 1, -1, 2, -1, -3, -2};
  const int32_T cond_ends_1_0[3]{662, 703, 747};
  const int32_T cond_starts_1_0[3]{627, 684, 708};
  const int32_T postfix_exprs_1_1[2]{0, -1};
  const int32_T postfix_exprs_1_2[2]{0, -1};
  const int32_T cond_ends_1_1{1014};
  const int32_T cond_ends_1_2{1291};
  const int32_T cond_starts_1_1{968};
  const int32_T cond_starts_1_2{1277};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateHandeye\\ComputeCamExtrinsics.m",
                  0U, 1U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "ComputeCamExtrinsics", 162, -1,
               2526);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 2191, -1, 2516);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 304, -1, 2069);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 2071, 2100, 2522);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\shared\\extractCheckerboardPoint.m",
                  1U, 1U, 11U, 5U, 0U, 0U, 0U, 2U, 0U, 5U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "extractCheckerboardPoint", 0,
               -1, 1794);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 1716, -1, 1789);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 1594, -1, 1632);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 1426, -1, 1543);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 1345, -1, 1419);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 1227, -1, 1266);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1168, -1, 1186);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1042, -1, 1124);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 857, -1, 950);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 764, -1, 783);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 415, -1, 569);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 116, -1, 334);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 623, 750, 792, 1200);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 807, 844, 959, 1148);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 959, 1015, -1, 1148);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 1273, 1291, 1544, 1644);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 1570, 1585, -1, 1640);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 627, 749, 3, 0,
                *(int32_T(*)[3]) & cond_starts_1_0[0],
                *(int32_T(*)[3]) & cond_ends_1_0[0], 7,
                *(int32_T(*)[7]) & postfix_exprs_1_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 967, 1014, 1, 3,
                (int32_T *)&cond_starts_1_1, (int32_T *)&cond_ends_1_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 1276, 1291, 1, 4,
                (int32_T *)&cond_starts_1_2, (int32_T *)&cond_ends_1_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 336, 357, 1270);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 1544, 1565, 1644);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateHandeye\\computeErrors.m",
                  2U, 3U, 11U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "computeErrors", 0, -1, 3743);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 1U, "computeErrors_anonFcn1", 1911,
               -1, 1924);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 2U, "computeErrors_anonFcn2", 1936,
               -1, 1996);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 10U, 3714, -1, 3743);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 9U, 3667, -1, 3701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 8U, 3266, -1, 3636);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 3105, -1, 3231);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 2891, -1, 3069);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 2728, -1, 2855);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 2491, -1, 2715);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 2343, -1, 2405);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 1843, -1, 2238);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 1911, -1, 1924);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 1936, -1, 1996);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 2259, 2284, 3712);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 2461, 2482, 2723);
  covrtForInit(&emlrtCoverageInstance, 2U, 2U, 2860, 2881, 3100);
  covrtForInit(&emlrtCoverageInstance, 2U, 3U, 3236, 3257, 3662);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateHandeye\\HandeyeShah.m",
                  3U, 1U, 10U, 3U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "HandeyeShah", 0, -1, 1175);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 9U, 1112, -1, 1175);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 8U, 982, -1, 1107);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 7U, 902, -1, 965);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 6U, 881, -1, 897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 5U, 743, -1, 834);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 4U, 722, -1, 738);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 3U, 569, -1, 674);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 548, -1, 564);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 418, -1, 498);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 257, -1, 401);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 3U, 0U, 524, 543, -1, 568);
  covrtIfInit(&emlrtCoverageInstance, 3U, 1U, 697, 717, -1, 742);
  covrtIfInit(&emlrtCoverageInstance, 3U, 2U, 856, 876, -1, 901);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 402, 413, 502);
  covrtForInit(&emlrtCoverageInstance, 3U, 1U, 966, 977, 1111);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateHandeye\\preprocessImages.m",
                  4U, 1U, 4U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "preprocessImages", 0, -1, 444);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 3U, 371, -1, 440);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 317, -1, 360);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 214, -1, 245);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 63, -1, 187);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 4U, 0U, 285, 309, -1, 367);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 4U, 0U, 188, 210, 444);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateHandeye\\readRobotPoses.m",
                  5U, 1U, 3U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "readRobotPoses", 0, -1, 526);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 454, -1, 519);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 250, -1, 370);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 72, -1, 164);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 5U, 0U, 217, 248, 374);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  subPixelLocationImpl_init();
}

void ComputeCamExtrinsics_mex_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"video_and_image_blockset", 2);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    ComputeCamExtrinsics_mex_once();
  }
}

// End of code generation (ComputeCamExtrinsics_mex_initialize.cpp)
