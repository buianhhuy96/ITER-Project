//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera_initialize.cpp
//
// Code generation for function 'calibrateCamera_initialize'
//

// Include files
#include "calibrateCamera_initialize.h"
#include "_coder_calibrateCamera_mex.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"

// Function Declarations
namespace Codegen {
static void calibrateCamera_once();

}

// Function Definitions
namespace Codegen {
static void calibrateCamera_once()
{
  const int32_T postfix_exprs_2_0[4]{0, -1, 1, -2};
  const int32_T postfix_exprs_6_0[3]{0, 1, -3};
  const int32_T cond_ends_2_0[2]{559, 593};
  const int32_T cond_ends_6_0[2]{686, 706};
  const int32_T cond_starts_2_0[2]{521, 564};
  const int32_T cond_starts_6_0[2]{660, 689};
  const int32_T postfix_exprs_2_1[2]{0, -1};
  const int32_T postfix_exprs_3_0[2]{0, -1};
  const int32_T postfix_exprs_3_1[2]{0, -1};
  const int32_T postfix_exprs_3_2[2]{0, -1};
  const int32_T postfix_exprs_3_3[2]{0, -1};
  const int32_T postfix_exprs_5_0[2]{0, -1};
  const int32_T postfix_exprs_5_1[2]{0, -1};
  const int32_T postfix_exprs_5_2[2]{0, -1};
  const int32_T postfix_exprs_7_0[2]{0, -1};
  const int32_T postfix_exprs_7_1[2]{0, -1};
  const int32_T postfix_exprs_7_2[2]{0, -1};
  const int32_T cond_ends_2_1{807};
  const int32_T cond_ends_3_0{990};
  const int32_T cond_ends_3_1{1258};
  const int32_T cond_ends_3_2{3502};
  const int32_T cond_ends_3_3{5292};
  const int32_T cond_ends_5_0{386};
  const int32_T cond_ends_5_1{729};
  const int32_T cond_ends_5_2{1128};
  const int32_T cond_ends_7_0{471};
  const int32_T cond_ends_7_1{743};
  const int32_T cond_ends_7_2{1417};
  const int32_T cond_starts_2_1{793};
  const int32_T cond_starts_3_0{970};
  const int32_T cond_starts_3_1{1234};
  const int32_T cond_starts_3_2{3489};
  const int32_T cond_starts_3_3{5283};
  const int32_T cond_starts_5_0{376};
  const int32_T cond_starts_5_1{719};
  const int32_T cond_starts_5_2{1118};
  const int32_T cond_starts_7_0{461};
  const int32_T cond_starts_7_1{733};
  const int32_T cond_starts_7_2{1407};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-"
                  "CameraCalibration\\Matlab-code-V2\\calibrateCamera.m",
                  0U, 2U, 4U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "calibrateCamera", 673, -1,
               4304);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U, "calibrateCamera_anonFcn1", 3374,
               -1, 3439);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 2076, -1, 4268);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1992, -1, 2043);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 782, -1, 1965);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 3374, -1, 3439);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 1966, 1987, 2047);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-"
                  "CameraCalibration\\Matlab-code-V2\\preprocessImages.m",
                  1U, 1U, 3U, 1U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "preprocessImages", 0, -1, 330);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 282, -1, 319);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 219, -1, 266);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 49, -1, 124);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 187, 211, 270, 326);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 125, 147, 330);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-"
                  "CameraCalibration\\Matlab-code-V2\\detectMyCheckerboard.m",
                  2U, 1U, 8U, 3U, 0U, 0U, 0U, 2U, 0U, 3U, 2U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "detectMyCheckerboard", 0, -1,
               1143);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 1082, -1, 1120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 897, -1, 1012);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 815, -1, 890);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 695, -1, 780);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 651, -1, 669);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 608, -1, 627);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 305, -1, 459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 72, -1, 225);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 516, 594, 636, 681);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 789, 807, 1013, 1138);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 1049, 1064, -1, 1133);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 0U, 520, 593, 2, 0,
                *(int32_T(*)[2]) & cond_starts_2_0[0],
                *(int32_T(*)[2]) & cond_ends_2_0[0], 4,
                *(int32_T(*)[4]) & postfix_exprs_2_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 1U, 792, 807, 1, 2,
                (int32_T *)&cond_starts_2_1, (int32_T *)&cond_ends_2_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_2_1[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 226, 247, 786);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 1013, 1040, 1138);
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
      "code-V2\\computeInitialParameterEstimate.m",
      3U, 10U, 29U, 6U, 0U, 0U, 0U, 6U, 0U, 4U, 4U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U,
               "computeInitialParameterEstimate", 0, -1, 804);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 1U, "my_CameraParameters", 806, -1,
               2401);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 2U, "computeHomography", 2478, -1,
               2772);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 3U, "computeHomographies", 2850, -1,
               3809);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 4U, "computeV", 3886, -1, 4164);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 5U, "computeLittleV", 4241, -1,
               4435);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 6U, "computeB", 4517, -1, 4744);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 7U, "computeIntrinsics", 4821, -1,
               5381);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 8U, "computeExtrinsics", 5458, -1,
               6300);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 9U, "computeFocalLength", 6535, -1,
               7901);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 670, -1, 795);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 362, -1, 658);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 260, -1, 342);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 8U, 1498, -1, 2396);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 7U, 1435, -1, 1492);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 6U, 1263, -1, 1425);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 5U, 1202, -1, 1224);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 4U, 1062, -1, 1188);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 3U, 991, -1, 1035);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 9U, 2604, -1, 2768);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 14U, 3786, -1, 3801);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 13U, 3664, -1, 3679);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 12U, 3440, -1, 3484);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 11U, 3260, -1, 3356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 10U, 2970, -1, 3218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 16U, 4020, -1, 4156);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 15U, 3932, -1, 3995);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 17U, 4282, -1, 4431);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 18U, 4608, -1, 4740);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 20U, 5358, -1, 5373);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 19U, 4893, -1, 5278);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 23U, 6219, -1, 6296);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 22U, 5765, -1, 6213);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 21U, 5609, -1, 5740);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 28U, 7836, -1, 7896);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 27U, 7520, -1, 7829);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 26U, 7229, -1, 7505);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 25U, 6997, -1, 7204);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 24U, 6597, -1, 6687);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 3U, 0U, 343, 356, 660, 799);
  covrtIfInit(&emlrtCoverageInstance, 3U, 1U, 966, 990, 1193, 1228);
  covrtIfInit(&emlrtCoverageInstance, 3U, 2U, 1230, 1258, 1426, 1496);
  covrtIfInit(&emlrtCoverageInstance, 3U, 3U, 3485, 3502, -1, 3683);
  covrtIfInit(&emlrtCoverageInstance, 3U, 4U, 3685, 3713, -1, 3805);
  covrtIfInit(&emlrtCoverageInstance, 3U, 5U, 5279, 5292, -1, 5377);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 0U, 969, 990, 1, 0,
                (int32_T *)&cond_starts_3_0, (int32_T *)&cond_ends_3_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 1U, 1233, 1258, 1, 1,
                (int32_T *)&cond_starts_3_1, (int32_T *)&cond_ends_3_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 2U, 3488, 3502, 1, 2,
                (int32_T *)&cond_starts_3_2, (int32_T *)&cond_ends_3_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_2[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 3U, 3U, 5282, 5292, 1, 3,
                (int32_T *)&cond_starts_3_3, (int32_T *)&cond_ends_3_3, 2,
                *(int32_T(*)[2]) & postfix_exprs_3_3[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 1036, 1057, 1192);
  covrtForInit(&emlrtCoverageInstance, 3U, 1U, 3219, 3238, 3411);
  covrtForInit(&emlrtCoverageInstance, 3U, 2U, 3996, 4015, 4160);
  covrtForInit(&emlrtCoverageInstance, 3U, 3U, 5741, 5760, 6217);
  covrtForInit(&emlrtCoverageInstance, 3U, 4U, 6971, 6992, 7834);
  covrtForInit(&emlrtCoverageInstance, 3U, 5U, 7209, 7220, 7514);
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
      "code-V2\\auxiliaries\\RTtoTransform.m",
      4U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "RTtoTransform", 63, -1, 225);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 109, -1, 221);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
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
      "code-V2\\auxiliaries\\serializeCalib.m",
      5U, 1U, 13U, 8U, 0U, 0U, 0U, 1U, 0U, 3U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "serializeCalib", 40, -1, 1390);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 12U, 1373, -1, 1382);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 11U, 1304, -1, 1347);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 10U, 1247, -1, 1281);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 9U, 1164, -1, 1215);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 8U, 952, -1, 1000);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 7U, 871, -1, 886);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 6U, 847, -1, 853);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 5U, 735, -1, 820);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 4U, 653, -1, 701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 3U, 588, -1, 603);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 564, -1, 570);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 392, -1, 537);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 90, -1, 306);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 5U, 0U, 371, 387, -1, 713);
  covrtIfInit(&emlrtCoverageInstance, 5U, 1U, 542, 555, 575, 611);
  covrtIfInit(&emlrtCoverageInstance, 5U, 2U, 616, 644, -1, 709);
  covrtIfInit(&emlrtCoverageInstance, 5U, 3U, 714, 730, -1, 1012);
  covrtIfInit(&emlrtCoverageInstance, 5U, 4U, 825, 838, 858, 894);
  covrtIfInit(&emlrtCoverageInstance, 5U, 5U, 899, 943, -1, 1008);
  covrtIfInit(&emlrtCoverageInstance, 5U, 6U, 1113, 1129, -1, 1386);
  covrtIfInit(&emlrtCoverageInstance, 5U, 7U, 1225, 1238, 1291, 1360);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 0U, 375, 386, 1, 0,
                (int32_T *)&cond_starts_5_0, (int32_T *)&cond_ends_5_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 1U, 718, 729, 1, 1,
                (int32_T *)&cond_starts_5_1, (int32_T *)&cond_ends_5_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 5U, 2U, 1117, 1128, 1, 2,
                (int32_T *)&cond_starts_5_2, (int32_T *)&cond_ends_5_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_5_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 5U, 0U, 1134, 1155, 1368);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\CalculateCost.m",
      6U, 1U, 3U, 1U, 0U, 0U, 0U, 1U, 0U, 2U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "CalculateCost", 23, -1, 1560);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 733, -1, 1512);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 413, -1, 638);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 110, -1, 355);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 6U, 0U, 656, 707, -1, 1547);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 6U, 0U, 660, 706, 2, 0,
                *(int32_T(*)[2]) & cond_starts_6_0[0],
                *(int32_T(*)[2]) & cond_ends_6_0[0], 3,
                *(int32_T(*)[3]) & postfix_exprs_6_0[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 6U, 0U, 361, 385, 1555);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 6U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-"
      "code-V2\\auxiliaries\\unserializeCalib.m",
      7U, 1U, 9U, 3U, 0U, 0U, 0U, 1U, 0U, 3U, 3U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 7U, 0U, "unserializeCalib", 8, -1, 1937);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 8U, 1875, -1, 1916);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 7U, 1540, -1, 1764);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 6U, 1431, -1, 1487);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 5U, 1174, -1, 1384);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 4U, 900, -1, 964);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 3U, 761, -1, 866);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 2U, 647, -1, 699);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 1U, 489, -1, 612);
  covrtBasicBlockInit(&emlrtCoverageInstance, 7U, 0U, 89, -1, 443);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 7U, 0U, 456, 472, 625, 715);
  covrtIfInit(&emlrtCoverageInstance, 7U, 1U, 728, 744, 879, 980);
  covrtIfInit(&emlrtCoverageInstance, 7U, 2U, 1402, 1418, -1, 1792);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 7U, 0U, 460, 471, 1, 0,
                (int32_T *)&cond_starts_7_0, (int32_T *)&cond_ends_7_0, 2,
                *(int32_T(*)[2]) & postfix_exprs_7_0[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 7U, 1U, 732, 743, 1, 1,
                (int32_T *)&cond_starts_7_1, (int32_T *)&cond_ends_7_1, 2,
                *(int32_T(*)[2]) & postfix_exprs_7_1[0]);
  covrtMcdcInit(&emlrtCoverageInstance, 7U, 2U, 1406, 1417, 1, 2,
                (int32_T *)&cond_starts_7_2, (int32_T *)&cond_ends_7_2, 2,
                *(int32_T(*)[2]) & postfix_exprs_7_2[0]);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 7U, 0U, 1500, 1523, 1780);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 7U);
  subPixelLocationImpl_init();
}

void calibrateCamera_initialize()
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
    calibrateCamera_once();
  }
}

} // namespace Codegen

// End of code generation (calibrateCamera_initialize.cpp)
