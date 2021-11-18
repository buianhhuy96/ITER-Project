//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_initialize.cpp
//
// Code generation for function 'calibrateOneCamera_mex_initialize'
//

// Include files
#include "calibrateOneCamera_mex_initialize.h"
#include "_coder_calibrateOneCamera_mex_mex.h"
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Declarations
namespace Codegen {
static void calibrateOneCamera_mex_once();

}

// Function Definitions
namespace Codegen {
static void calibrateOneCamera_mex_once()
{
  const int32_T postfix_exprs_4_0[3]{0, 1, -3};
  const int32_T cond_ends_4_0[2]{658, 678};
  const int32_T cond_starts_4_0[2]{632, 661};
  const int32_T postfix_exprs_0_0[2]{0, -1};
  const int32_T postfix_exprs_0_1[2]{0, -1};
  const int32_T postfix_exprs_1_0[2]{0, -1};
  const int32_T postfix_exprs_1_1[2]{0, -1};
  const int32_T postfix_exprs_1_2[2]{0, -1};
  const int32_T postfix_exprs_1_3[2]{0, -1};
  const int32_T postfix_exprs_3_0[2]{0, -1};
  const int32_T postfix_exprs_3_1[2]{0, -1};
  const int32_T postfix_exprs_3_2[2]{0, -1};
  const int32_T postfix_exprs_5_0[2]{0, -1};
  const int32_T postfix_exprs_5_1[2]{0, -1};
  const int32_T postfix_exprs_5_2[2]{0, -1};
  const int32_T cond_ends_0_0{1604};
  const int32_T cond_ends_0_1{1818};
  const int32_T cond_ends_1_0{1536};
  const int32_T cond_ends_1_1{1804};
  const int32_T cond_ends_1_2{4049};
  const int32_T cond_ends_1_3{5870};
  const int32_T cond_ends_3_0{386};
  const int32_T cond_ends_3_1{729};
  const int32_T cond_ends_3_2{1128};
  const int32_T cond_ends_5_0{482};
  const int32_T cond_ends_5_1{754};
  const int32_T cond_ends_5_2{1715};
  const int32_T cond_starts_0_0{1566};
  const int32_T cond_starts_0_1{1804};
  const int32_T cond_starts_1_0{1516};
  const int32_T cond_starts_1_1{1780};
  const int32_T cond_starts_1_2{4036};
  const int32_T cond_starts_1_3{5861};
  const int32_T cond_starts_3_0{376};
  const int32_T cond_starts_3_1{719};
  const int32_T cond_starts_3_2{1118};
  const int32_T cond_starts_5_0{472};
  const int32_T cond_starts_5_1{744};
  const int32_T cond_starts_5_2{1705};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-"
                  "CameraCalibration\\Matlab-code-V2\\calibrateOneCamera.m",
                  0U, 2U, 15U, 4U, 0U, 0U, 0U, 4U, 0U, 2U, 2U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "calibrateOneCamera", 673, -1,
               5526);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U, "calibrateOneCamera_anonFcn1",
               4443, -1, 4508);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 3140, -1, 5522);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 3056, -1, 3107);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 2902, -1, 3029);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 2766, -1, 2895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 2677, -1, 2730);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 2338, -1, 2613);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 2082, -1, 2120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 1897, -1, 2012);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1872, -1, 1890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1706, -1, 1791);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1662, -1, 1680);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1619, -1, 1638);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1350, -1, 1504);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 810, -1, 1165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 4443, -1, 4508);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1561, 1605, 1647, 1692);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1800, 1818, -1, 1894);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 2049, 2064, -1, 2133);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 2614, 2627, -1, 2644);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 1565, 1604, 1, 0,
                (int32_T *)&cond_starts_0_0, (int32_T *)&cond_ends_0_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_0_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 1U, 1803, 1818, 1, 1,
                (int32_T *)&cond_starts_0_1, (int32_T *)&cond_ends_0_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_0_1[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1271, 1292, 1797);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 2013, 2040, 2138);
  covrtForInit(&emlrtCoverageInstance, 0U, 2U, 2731, 2761, 2899);
  covrtForInit(&emlrtCoverageInstance, 0U, 3U, 3030, 3051, 3111);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\computeInitialParameterEstimate.m",
      1U, 10U, 29U, 6U, 0U, 0U, 0U, 6U, 0U, 4U, 4U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U,
               "computeInitialParameterEstimate", 0, -1, 1350);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 1U, "my_CameraParameters", 1352, -1,
               2947);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 2U, "computeHomography", 3024, -1,
               3318);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 3U, "computeHomographies", 3396, -1,
               4386);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 4U, "computeV", 4463, -1, 4741);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 5U, "computeLittleV", 4818, -1,
               5012);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 6U, "computeB", 5094, -1, 5321);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 7U, "computeIntrinsics", 5398, -1,
               5962);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 8U, "computeExtrinsics", 6039, -1,
               6881);
  covrtFcnInit(&emlrtCoverageInstance, 1U, 9U, "computeFocalLength", 7116, -1,
               8482);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1273, -1, 1340);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 369, -1, 1141);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 259, -1, 342);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 2044, -1, 2942);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 1981, -1, 2038);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 1809, -1, 1971);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1748, -1, 1770);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1608, -1, 1734);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1537, -1, 1581);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 9U, 3150, -1, 3314);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 13U, 4211, -1, 4241);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 14U, 4348, -1, 4378);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 12U, 3987, -1, 4031);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 11U, 3807, -1, 3903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 10U, 3516, -1, 3765);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 16U, 4597, -1, 4733);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 15U, 4509, -1, 4572);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 17U, 4859, -1, 5008);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 18U, 5185, -1, 5317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 20U, 5936, -1, 5954);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 19U, 5470, -1, 5856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 23U, 6800, -1, 6877);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 22U, 6346, -1, 6794);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 21U, 6190, -1, 6321);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 28U, 8417, -1, 8477);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 27U, 8101, -1, 8410);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 26U, 7810, -1, 8086);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 25U, 7578, -1, 7785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 24U, 7178, -1, 7268);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 350, 363, 1144, 1345);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 1512, 1536, 1739, 1774);
  covrtIfInit(&emlrtCoverageInstance, 1U, 2U, 1776, 1804, 1972, 2042);
  covrtIfInit(&emlrtCoverageInstance, 1U, 3U, 4032, 4049, 4247, 4382);
  covrtIfInit(&emlrtCoverageInstance, 1U, 4U, 4247, 4275, -1, 4382);
  covrtIfInit(&emlrtCoverageInstance, 1U, 5U, 5857, 5870, -1, 5958);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 1515, 1536, 1, 0,
                (int32_T *)&cond_starts_1_0, (int32_T *)&cond_ends_1_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 1779, 1804, 1, 1,
                (int32_T *)&cond_starts_1_1, (int32_T *)&cond_ends_1_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 2U, 4035, 4049, 1, 2,
                (int32_T *)&cond_starts_1_2, (int32_T *)&cond_ends_1_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_2[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 3U, 5860, 5870, 1, 3,
                (int32_T *)&cond_starts_1_3, (int32_T *)&cond_ends_1_3, 2,
                *(int32_T(*)[2]) & postfix_exprs_1_3[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 1582, 1603, 1738);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 3766, 3785, 3958);
  covrtForInit(&emlrtCoverageInstance, 1U, 2U, 4573, 4592, 4737);
  covrtForInit(&emlrtCoverageInstance, 1U, 3U, 6322, 6341, 6798);
  covrtForInit(&emlrtCoverageInstance, 1U, 4U, 7552, 7573, 8415);
  covrtForInit(&emlrtCoverageInstance, 1U, 5U, 7790, 7801, 8095);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\RTtoTransform.m",
      2U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "RTtoTransform", 63, -1, 225);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 109, -1, 221);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\serializeCalib.m",
      3U, 1U, 13U, 8U, 0U, 0U, 0U, 1U, 0U, 3U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "serializeCalib", 40, -1, 1390);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 12U, 1373, -1, 1382);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 11U, 1304, -1, 1347);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 10U, 1247, -1, 1281);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 9U, 1164, -1, 1215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 8U, 952, -1, 1000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 7U, 871, -1, 886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 6U, 847, -1, 853);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 5U, 735, -1, 820);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 4U, 653, -1, 701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 3U, 588, -1, 603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 564, -1, 570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 392, -1, 537);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 90, -1, 306);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 3U, 0U, 371, 387, -1, 713);
  covrtIfInit(&emlrtCoverageInstance, 3U, 1U, 542, 555, 575, 611);
  covrtIfInit(&emlrtCoverageInstance, 3U, 2U, 616, 644, -1, 709);
  covrtIfInit(&emlrtCoverageInstance, 3U, 3U, 714, 730, -1, 1012);
  covrtIfInit(&emlrtCoverageInstance, 3U, 4U, 825, 838, 858, 894);
  covrtIfInit(&emlrtCoverageInstance, 3U, 5U, 899, 943, -1, 1008);
  covrtIfInit(&emlrtCoverageInstance, 3U, 6U, 1113, 1129, -1, 1386);
  covrtIfInit(&emlrtCoverageInstance, 3U, 7U, 1225, 1238, 1291, 1360);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 0U, 375, 386, 1, 0,
                (int32_T *)&cond_starts_3_0, (int32_T *)&cond_ends_3_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 1U, 718, 729, 1, 1,
                (int32_T *)&cond_starts_3_1, (int32_T *)&cond_ends_3_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 2U, 1117, 1128, 1, 2,
                (int32_T *)&cond_starts_3_2, (int32_T *)&cond_ends_3_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 1134, 1155, 1368);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\CalculateCost.m",
      4U, 1U, 3U, 1U, 0U, 0U, 0U, 1U, 0U, 2U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "CalculateCost", 23, -1, 1532);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 705, -1, 1484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 385, -1, 610);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 110, -1, 327);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 4U, 0U, 628, 679, -1, 1519);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 4U, 0U, 632, 678, 2, 0,
                *(int32_T(*)[2]) & cond_starts_4_0[0],
                *(int32_T(*)[2]) & cond_ends_4_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_4_0[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 4U, 0U, 333, 357, 1527);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\unserializeCalib.m",
      5U, 1U, 9U, 3U, 0U, 0U, 0U, 1U, 0U, 3U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "unserializeCalib", 8, -1, 2262);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 8U, 2224, -1, 2250);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 7U, 1838, -1, 2062);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 6U, 1729, -1, 1785);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 5U, 1004, -1, 1221);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 4U, 911, -1, 975);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 3U, 772, -1, 877);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 658, -1, 710);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 500, -1, 623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 108, -1, 454);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 5U, 0U, 467, 483, 636, 726);
  covrtIfInit(&emlrtCoverageInstance, 5U, 1U, 739, 755, 890, 991);
  covrtIfInit(&emlrtCoverageInstance, 5U, 2U, 1700, 1716, -1, 2090);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 0U, 471, 482, 1, 0,
                (int32_T *)&cond_starts_5_0, (int32_T *)&cond_ends_5_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 1U, 743, 754, 1, 1,
                (int32_T *)&cond_starts_5_1, (int32_T *)&cond_ends_5_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 2U, 1704, 1715, 1, 2,
                (int32_T *)&cond_starts_5_2, (int32_T *)&cond_ends_5_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 5U, 0U, 1798, 1821, 2078);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-"
                  "CameraCalibration\\Matlab-code-V2\\preprocessImages.m",
                  6U, 1U, 3U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "preprocessImages", 0, -1, 330);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 282, -1, 319);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 219, -1, 266);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 49, -1, 124);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 187, 211, 270, 326);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 6U, 0U, 125, 147, 330);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 6U);
  subPixelLocationImpl_init();
}

void calibrateOneCamera_mex_initialize()
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
    calibrateOneCamera_mex_once();
  }
}

} // namespace Codegen

// End of code generation (calibrateOneCamera_mex_initialize.cpp)
