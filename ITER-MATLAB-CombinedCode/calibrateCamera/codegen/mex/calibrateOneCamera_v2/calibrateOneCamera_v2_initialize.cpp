//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2_initialize.cpp
//
// Code generation for function 'calibrateOneCamera_v2_initialize'
//

// Include files
#include "calibrateOneCamera_v2_initialize.h"
#include "_coder_calibrateOneCamera_v2_mex.h"
#include "calibrateOneCamera_v2_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Declarations
static void calibrateOneCamera_v2_once();

// Function Definitions
static void calibrateOneCamera_v2_once()
{
  const int32_T postfix_exprs_1_0[7]{0, 1, -1, 2, -1, -3, -2};
  const int32_T cond_ends_1_0[3]{645, 685, 728};
  const int32_T cond_starts_1_0[3]{610, 667, 690};
  const int32_T postfix_exprs_1_1[2]{0, -1};
  const int32_T postfix_exprs_1_2[2]{0, -1};
  const int32_T postfix_exprs_2_0[2]{0, -1};
  const int32_T postfix_exprs_2_1[2]{0, -1};
  const int32_T postfix_exprs_2_2[2]{0, -1};
  const int32_T postfix_exprs_2_3[2]{0, -1};
  const int32_T cond_ends_1_1{994};
  const int32_T cond_ends_1_2{1349};
  const int32_T cond_ends_2_0{1536};
  const int32_T cond_ends_2_1{1804};
  const int32_T cond_ends_2_2{4049};
  const int32_T cond_ends_2_3{5870};
  const int32_T cond_starts_1_1{948};
  const int32_T cond_starts_1_2{1336};
  const int32_T cond_starts_2_0{1516};
  const int32_T cond_starts_2_1{1780};
  const int32_T cond_starts_2_2{4036};
  const int32_T cond_starts_2_3{5861};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
                  "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m",
                  0U, 5U, 22U, 7U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "calibrateOneCamera_v2", 3911,
               -1, 6009);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 2U, "reprojectWrapper", 6011, -1,
               6765);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 3U, "serialize", 6767, -1, 7469);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 4U, "unpackSerializedParams", 7471,
               -1, 9031);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U, "calibrateOneCamera_v2_anonFcn1",
               5539, -1, 5606);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 4453, -1, 4460);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 4928, -1, 4935);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 4944, -1, 6005);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 4642, -1, 4908);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 4058, -1, 4433);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 6395, -1, 6757);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 6100, -1, 6326);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 7357, -1, 7443);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 7302, -1, 7346);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 7151, -1, 7239);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 7106, -1, 7133);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 6804, -1, 7059);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 21U, 8453, -1, 9025);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 20U, 8354, -1, 8447);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 19U, 8294, -1, 8344);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 18U, 8240, -1, 8273);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 17U, 8146, -1, 8222);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 16U, 7998, -1, 8128);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 15U, 7712, -1, 7935);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 7646, -1, 7694);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 7577, -1, 7628);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 5539, -1, 5606);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 4435, 4448, 4910, 4939);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 4910, 4923, 4453, 4460);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 7069, 7097, -1, 7141);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 7249, 7293, -1, 7354);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 7540, 7568, 7633, 7702);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 7945, 7989, 8133, 8230);
  covrtIfInit(&emlrtCoverageInstance, 0U, 6U, 8276, 8289, 8345, 8451);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 6327, 6373, 6761);
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
                  1U, 1U, 12U, 6U, 0U, 0U, 0U, 2U, 0U, 5U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "extractCheckerboardPoint", 0,
               -1, 1897);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 1274, -1, 1325);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 1413, -1, 1487);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 1821, -1, 1892);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 1700, -1, 1737);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 1535, -1, 1650);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 1133, -1, 1172);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1075, -1, 1092);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1022, -1, 1040);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 837, -1, 930);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 745, -1, 763);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 397, -1, 551);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 136, -1, 314);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 606, 731, 772, 1106);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 787, 824, 939, 1055);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 939, 995, -1, 1055);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 1179, 1191, 1332, 1491);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 1332, 1349, 1651, 1749);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 1677, 1691, -1, 1745);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 610, 730, 3, 0,
                *(int32_T(*)[3]) & cond_starts_1_0[0],
                *(int32_T(*)[3]) & cond_ends_1_0[0], 7,
                *(int32_T(*)[7]) & postfix_exprs_1_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 947, 994, 1, 3,
                (int32_T *)&cond_starts_1_1, (int32_T *)&cond_ends_1_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 1335, 1349, 1, 4,
                (int32_T *)&cond_starts_1_2, (int32_T *)&cond_ends_1_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 365, 386, 1176);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 1651, 1672, 1749);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
      "CombinedCode\\calibrateCamera\\computeInitialParameterEstimate.m",
      2U, 10U, 29U, 6U, 0U, 0U, 0U, 6U, 0U, 4U, 4U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U,
               "computeInitialParameterEstimate", 0, -1, 1350);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 1U, "my_CameraParameters", 1352, -1,
               2947);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 2U, "computeHomography", 3024, -1,
               3318);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 3U, "computeHomographies", 3396, -1,
               4386);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 4U, "computeV", 4463, -1, 4741);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 5U, "computeLittleV", 4818, -1,
               5012);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 6U, "computeB", 5094, -1, 5321);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 7U, "computeIntrinsics", 5398, -1,
               5962);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 8U, "computeExtrinsics", 6039, -1,
               6881);
  covrtFcnInit(&emlrtCoverageInstance, 2U, 9U, "computeFocalLength", 7116, -1,
               8482);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 1273, -1, 1340);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 369, -1, 1141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 259, -1, 342);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 8U, 2044, -1, 2942);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 1981, -1, 2038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 1809, -1, 1971);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 1748, -1, 1770);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 1608, -1, 1734);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 1537, -1, 1581);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 9U, 3150, -1, 3314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 13U, 4211, -1, 4241);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 14U, 4348, -1, 4378);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 12U, 3987, -1, 4031);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 11U, 3807, -1, 3903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 10U, 3516, -1, 3765);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 16U, 4597, -1, 4733);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 15U, 4509, -1, 4572);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 17U, 4859, -1, 5008);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 18U, 5185, -1, 5317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 20U, 5936, -1, 5954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 19U, 5470, -1, 5856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 23U, 6800, -1, 6877);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 22U, 6346, -1, 6794);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 21U, 6190, -1, 6321);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 28U, 8417, -1, 8477);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 27U, 8101, -1, 8410);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 26U, 7810, -1, 8086);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 25U, 7578, -1, 7785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 24U, 7178, -1, 7268);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 350, 363, 1144, 1345);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 1512, 1536, 1739, 1774);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 1776, 1804, 1972, 2042);
  covrtIfInit(&emlrtCoverageInstance, 2U, 3U, 4032, 4049, 4247, 4382);
  covrtIfInit(&emlrtCoverageInstance, 2U, 4U, 4247, 4275, -1, 4382);
  covrtIfInit(&emlrtCoverageInstance, 2U, 5U, 5857, 5870, -1, 5958);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 0U, 1515, 1536, 1, 0,
                (int32_T *)&cond_starts_2_0, (int32_T *)&cond_ends_2_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_2_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 1U, 1779, 1804, 1, 1,
                (int32_T *)&cond_starts_2_1, (int32_T *)&cond_ends_2_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_2_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 2U, 4035, 4049, 1, 2,
                (int32_T *)&cond_starts_2_2, (int32_T *)&cond_ends_2_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_2_2[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 3U, 5860, 5870, 1, 3,
                (int32_T *)&cond_starts_2_3, (int32_T *)&cond_ends_2_3, 2,
                *(int32_T(*)[2]) & postfix_exprs_2_3[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 1582, 1603, 1738);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 3766, 3785, 3958);
  covrtForInit(&emlrtCoverageInstance, 2U, 2U, 4573, 4592, 4737);
  covrtForInit(&emlrtCoverageInstance, 2U, 3U, 6322, 6341, 6798);
  covrtForInit(&emlrtCoverageInstance, 2U, 4U, 7552, 7573, 8415);
  covrtForInit(&emlrtCoverageInstance, 2U, 5U, 7790, 7801, 8095);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  subPixelLocationImpl_init();
}

void calibrateOneCamera_v2_initialize()
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
  emlrtLicenseCheckR2012b(&st, (const char_T *)"optimization_toolbox", 2);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"statistics_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    calibrateOneCamera_v2_once();
  }
}

// End of code generation (calibrateOneCamera_v2_initialize.cpp)
