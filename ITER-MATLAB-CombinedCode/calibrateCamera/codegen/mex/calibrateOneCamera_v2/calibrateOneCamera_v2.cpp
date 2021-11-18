//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2.cpp
//
// Code generation for function 'calibrateOneCamera_v2'
//

// Include files
#include "calibrateOneCamera_v2.h"
#include "anonymous_function1.h"
#include "any1.h"
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_internal_types11.h"
#include "calibrateOneCamera_v2_types.h"
#include "cameraParameters.h"
#include "combineVectorElements.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateCheckerboardPoints.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "lsqnonlin.h"
#include "nanmean.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "worldToImage.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Type Definitions
struct cell_wrap_12 {
  coder::array<real_T, 2U> f1;
};

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    107,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    113,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    125,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    133,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    145,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    148,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    149,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    152,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    747,                            // lineNo
    "CameraParametersImpl/saveobj", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    14,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    41,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    50,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    60,                         // lineNo
    "extractCheckerboardPoint", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pathName
};

static emlrtRSInfo wq_emlrtRSI{
    39,     // lineNo
    "norm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" // pathName
};

static emlrtRSInfo xq_emlrtRSI{
    197,        // lineNo
    "genpnorm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" // pathName
};

static emlrtRSInfo iw_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo wbb_emlrtRSI{
    171,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo xbb_emlrtRSI{
    174,         // lineNo
    "serialize", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo ybb_emlrtRSI{
    175,         // lineNo
    "serialize", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo acb_emlrtRSI{
    178,         // lineNo
    "serialize", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo bcb_emlrtRSI{
    188,         // lineNo
    "serialize", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo kcb_emlrtRSI{
    504,                             // lineNo
    "CameraParametersImpl/get.Skew", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo wcb_emlrtRSI{
    156,                // lineNo
    "reprojectWrapper", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo xcb_emlrtRSI{
    156,                     // lineNo
    "calibrateOneCamera_v2", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo ycb_emlrtRSI{
    157,                // lineNo
    "reprojectWrapper", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo adb_emlrtRSI{
    161,                // lineNo
    "reprojectWrapper", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo bdb_emlrtRSI{
    165,                // lineNo
    "reprojectWrapper", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo cdb_emlrtRSI{
    207,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo ddb_emlrtRSI{
    210,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo edb_emlrtRSI{
    214,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo fdb_emlrtRSI{
    221,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo gdb_emlrtRSI{
    228,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo hdb_emlrtRSI{
    236,                      // lineNo
    "unpackSerializedParams", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pathName
};

static emlrtRSInfo idb_emlrtRSI{
    480,                                         // lineNo
    "CameraParametersImpl/get.RotationMatrices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo jdb_emlrtRSI{
    481,                                         // lineNo
    "CameraParametersImpl/get.RotationMatrices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo kdb_emlrtRSI{
    483,                                         // lineNo
    "CameraParametersImpl/get.RotationMatrices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

static emlrtRSInfo ldb_emlrtRSI{
    38,                        // lineNo
    "rodriguesVectorToMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m" // pathName
};

static emlrtRSInfo mdb_emlrtRSI{
    50,                               // lineNo
    "rodriguesVectorToMatrixCodeGen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m" // pathName
};

static emlrtRSInfo keb_emlrtRSI{
    12,     // lineNo
    "sqrt", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" // pathName
};

static emlrtRSInfo leb_emlrtRSI{
    16,     // lineNo
    "sqrt", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" // pathName
};

static emlrtRSInfo meb_emlrtRSI{
    33,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    1,                               // iFirst
    3,                               // iLast
    181,                             // lineNo
    45,                              // colNo
    "cameraParams.RadialDistortion", // aName
    "serialize",                     // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo emlrtDCI{
    181,         // lineNo
    45,          // colNo
    "serialize", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    54,                         // lineNo
    43,                         // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                         // nDims
    54,                         // lineNo
    9,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    54,                         // lineNo
    25,                         // colNo
    "imagePoints",              // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    13,                         // lineNo
    32,                         // colNo
    "images",                   // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    31,                         // lineNo
    18,                         // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    113,                     // lineNo
    1,                       // colNo
    "board_points",          // aName
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    19,                         // lineNo
    18,                         // colNo
    "validIdx",                 // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    27,                         // lineNo
    18,                         // colNo
    "validIdx",                 // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    31,                         // lineNo
    5,                          // colNo
    "board_points",             // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    53,                         // lineNo
    17,                         // colNo
    "validIdx",                 // aName
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    149,                     // lineNo
    27,                      // colNo
    "tmp",                   // aName
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo ju_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    160,                // lineNo
    30,                 // colNo
    "ImagePoints",      // aName
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo ku_emlrtBCI{
    -1,                             // iFirst
    -1,                             // iLast
    161,                            // lineNo
    81,                             // colNo
    "paramStruct.RotationMatrices", // aName
    "reprojectWrapper",             // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo lu_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    161,                              // lineNo
    116,                              // colNo
    "paramStruct.TranslationVectors", // aName
    "reprojectWrapper",               // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo cd_emlrtECI{
    1,                  // nDims
    164,                // lineNo
    19,                 // colNo
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtECInfo dd_emlrtECI{
    2,                  // nDims
    164,                // lineNo
    19,                 // colNo
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtBCInfo mu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    166,                // lineNo
    10,                 // colNo
    "cost",             // aName
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo nu_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    166,                // lineNo
    38,                 // colNo
    "cost",             // aName
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo ed_emlrtECI{
    -1,                 // nDims
    166,                // lineNo
    5,                  // colNo
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtBCInfo ou_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    482,                                         // lineNo
    42,                                          // colNo
    "",                                          // aName
    "CameraParametersImpl/get.RotationMatrices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo pu_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    484,                                         // lineNo
    40,                                          // colNo
    "",                                          // aName
    "CameraParametersImpl/get.RotationMatrices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo qu_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    73,                               // lineNo
    8,                                // colNo
    "",                               // aName
    "rodriguesVectorToMatrixCodeGen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo ru_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    74,                               // lineNo
    8,                                // colNo
    "",                               // aName
    "rodriguesVectorToMatrixCodeGen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo su_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    75,                               // lineNo
    8,                                // colNo
    "",                               // aName
    "rodriguesVectorToMatrixCodeGen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m", // pName
    0                                         // checkKind
};

static emlrtECInfo fd_emlrtECI{
    2,                                // nDims
    87,                               // lineNo
    18,                               // colNo
    "rodriguesVectorToMatrixCodeGen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m" // pName
};

static emlrtDCInfo qg_emlrtDCI{
    480,                                         // lineNo
    44,                                          // colNo
    "CameraParametersImpl/get.RotationMatrices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m", // pName
    4                                      // checkKind
};

static emlrtDCInfo rg_emlrtDCI{
    158,                // lineNo
    1,                  // colNo
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo sg_emlrtDCI{
    158,                // lineNo
    1,                  // colNo
    "reprojectWrapper", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    4                                                         // checkKind
};

static emlrtDCInfo tg_emlrtDCI{
    56,    // lineNo
    52,    // colNo
    "cat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m", // pName
    4 // checkKind
};

static emlrtRTEInfo jc_emlrtRTEI{
    116,               // lineNo
    9,                 // colNo
    "computeDimsData", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtBCInfo tu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    221,                      // lineNo
    33,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo uu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    221,                      // lineNo
    11,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo ug_emlrtDCI{
    221,                      // lineNo
    11,                       // colNo
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo vu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    210,                      // lineNo
    28,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo vg_emlrtDCI{
    210,                      // lineNo
    28,                       // colNo
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo wu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    210,                      // lineNo
    26,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo xu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    207,                      // lineNo
    11,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo yu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    205,                      // lineNo
    12,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo av_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    204,                      // lineNo
    12,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo bv_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    203,                      // lineNo
    12,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo cv_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    202,                      // lineNo
    12,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo dv_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    195,                      // lineNo
    18,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo ev_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    214,                      // lineNo
    15,                       // colNo
    "x",                      // aName
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo wg_emlrtDCI{
    214,                      // lineNo
    15,                       // colNo
    "unpackSerializedParams", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m", // pName
    1                                                         // checkKind
};

static emlrtRTEInfo xc_emlrtRTEI{
    107,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    108,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    113,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    13,                         // lineNo
    19,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    31,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    50,                         // lineNo
    27,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    51,                         // lineNo
    1,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    54,                         // lineNo
    21,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    54,                         // lineNo
    23,                         // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo hd_emlrtRTEI{
    60,                         // lineNo
    1,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo id_emlrtRTEI{
    44,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo jd_emlrtRTEI{
    45,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo kd_emlrtRTEI{
    36,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo ld_emlrtRTEI{
    37,                         // lineNo
    5,                          // colNo
    "extractCheckerboardPoint", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\shared\\extractCheckerboardPoint.m" // pName
};

static emlrtRTEInfo md_emlrtRTEI{
    133,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo nd_emlrtRTEI{
    100,                     // lineNo
    64,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo od_emlrtRTEI{
    188,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo pd_emlrtRTEI{
    149,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo at_emlrtRTEI{
    156,                     // lineNo
    69,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo bt_emlrtRTEI{
    157,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo
    ct_emlrtRTEI{
        67,    // lineNo
        9,     // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

static emlrtRTEInfo dt_emlrtRTEI{
    158,                     // lineNo
    1,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo et_emlrtRTEI{
    161,                     // lineNo
    48,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo ft_emlrtRTEI{
    482,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

static emlrtRTEInfo gt_emlrtRTEI{
    71,                        // lineNo
    1,                         // colNo
    "rodriguesVectorToMatrix", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m" // pName
};

static emlrtRTEInfo
    ht_emlrtRTEI{
        85,                  // lineNo
        13,                  // colNo
        "eml_mtimes_helper", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

static emlrtRTEInfo it_emlrtRTEI{
    87,                        // lineNo
    70,                        // colNo
    "rodriguesVectorToMatrix", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\rodriguesVectorToMatrix.m" // pName
};

static emlrtRTEInfo jt_emlrtRTEI{
    161,                     // lineNo
    85,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo lt_emlrtRTEI{
    166,                     // lineNo
    10,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo mt_emlrtRTEI{
    207,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo nt_emlrtRTEI{
    210,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo ot_emlrtRTEI{
    221,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo pt_emlrtRTEI{
    229,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo qt_emlrtRTEI{
    230,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo rt_emlrtRTEI{
    225,                     // lineNo
    23,                      // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRTEInfo st_emlrtRTEI{
    226,                     // lineNo
    5,                       // colNo
    "calibrateOneCamera_v2", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-MATLAB-"
    "CombinedCode\\calibrateCamera\\calibrateOneCamera_v2.m" // pName
};

static emlrtRSInfo
    ufb_emlrtRSI{
        31,            // lineNo
        "unsafeSxfun", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" // pathName
    };

// Function Declarations
static void unpackSerializedParams(const emlrtStack *sp,
                                   const struct_T *cameraParams,
                                   coder::array<real_T, 1U> &x,
                                   struct0_T *outputParams);

// Function Definitions
static void unpackSerializedParams(const emlrtStack *sp,
                                   const struct_T *cameraParams,
                                   coder::array<real_T, 1U> &x,
                                   struct0_T *outputParams)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T cx;
  real_T cy;
  real_T fx;
  real_T fy;
  real_T numDistortionCoeffs;
  real_T skew;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T numIntrinsicMatrixEntries;
  boolean_T b_outputParams[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 0, 4);
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 4, cameraParams->EstimateSkew)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 13);
    if (5 > x.size(0)) {
      emlrtDynamicBoundsCheckR2012b(5, 1, x.size(0), &dv_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    skew = x[4];
    numIntrinsicMatrixEntries = 6;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 14);
    skew = 0.0;
    numIntrinsicMatrixEntries = 5;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 15);
  if (1 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, x.size(0), &cv_emlrtBCI, (emlrtCTX)sp);
  }
  fx = x[0];
  if (2 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, x.size(0), &bv_emlrtBCI, (emlrtCTX)sp);
  }
  fy = x[1];
  if (3 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(3, 1, x.size(0), &av_emlrtBCI, (emlrtCTX)sp);
  }
  cx = x[2];
  if (4 > x.size(0)) {
    emlrtDynamicBoundsCheckR2012b(4, 1, x.size(0), &yu_emlrtBCI, (emlrtCTX)sp);
  }
  cy = x[3];
  if (numIntrinsicMatrixEntries > x.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    if (numIntrinsicMatrixEntries > x.size(0)) {
      emlrtDynamicBoundsCheckR2012b(6, 1, x.size(0), &xu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = numIntrinsicMatrixEntries - 1;
    i1 = x.size(0);
  }
  iv[0] = 1;
  numIntrinsicMatrixEntries = i1 - i;
  iv[1] = numIntrinsicMatrixEntries;
  st.site = &cdb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, x.size(0), iv);
  for (i1 = 0; i1 < numIntrinsicMatrixEntries; i1++) {
    x[i1] = x[i + i1];
  }
  x.set_size(&mt_emlrtRTEI, sp, numIntrinsicMatrixEntries);
  if (1.0 > cameraParams->NumRadialDistortionCoefficients) {
    loop_ub = 0;
  } else {
    if (1 > numIntrinsicMatrixEntries) {
      emlrtDynamicBoundsCheckR2012b(1, 1, numIntrinsicMatrixEntries,
                                    &wu_emlrtBCI, (emlrtCTX)sp);
    }
    if (cameraParams->NumRadialDistortionCoefficients !=
        static_cast<int32_T>(muDoubleScalarFloor(
            cameraParams->NumRadialDistortionCoefficients))) {
      emlrtIntegerCheckR2012b(cameraParams->NumRadialDistortionCoefficients,
                              &vg_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients) <
         1) ||
        (static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients) >
         numIntrinsicMatrixEntries)) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients),
          1, numIntrinsicMatrixEntries, &vu_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub =
        static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients);
  }
  iv[0] = 1;
  iv[1] = loop_ub;
  st.site = &ddb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, numIntrinsicMatrixEntries, iv);
  outputParams->RadialDistortion.set_size(&nt_emlrtRTEI, sp, 1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    outputParams->RadialDistortion[i] = x[i];
  }
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 5,
                 cameraParams->EstimateTangentialDistortion)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 16);
    st.site = &edb_emlrtRSI;
    coder::internal::indexShapeCheck(&st, numIntrinsicMatrixEntries);
    if (cameraParams->NumRadialDistortionCoefficients + 1.0 !=
        static_cast<int32_T>(muDoubleScalarFloor(
            cameraParams->NumRadialDistortionCoefficients + 1.0))) {
      emlrtIntegerCheckR2012b(cameraParams->NumRadialDistortionCoefficients +
                                  1.0,
                              &wg_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                              1.0) < 1) ||
        (static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                              1.0) > numIntrinsicMatrixEntries)) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                               1.0),
          1, numIntrinsicMatrixEntries, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    outputParams->TangentialDistortion[0] =
        x[static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                               1.0) -
          1];
    if (cameraParams->NumRadialDistortionCoefficients + 2.0 !=
        static_cast<int32_T>(muDoubleScalarFloor(
            cameraParams->NumRadialDistortionCoefficients + 2.0))) {
      emlrtIntegerCheckR2012b(cameraParams->NumRadialDistortionCoefficients +
                                  2.0,
                              &wg_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                              2.0) < 1) ||
        (static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                              2.0) > numIntrinsicMatrixEntries)) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                               2.0),
          1, numIntrinsicMatrixEntries, &ev_emlrtBCI, (emlrtCTX)sp);
    }
    outputParams->TangentialDistortion[1] =
        x[static_cast<int32_T>(cameraParams->NumRadialDistortionCoefficients +
                               2.0) -
          1];
    numDistortionCoeffs = cameraParams->NumRadialDistortionCoefficients + 2.0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 17);
    outputParams->TangentialDistortion[0] = 0.0;
    outputParams->TangentialDistortion[1] = 0.0;
    numDistortionCoeffs = cameraParams->NumRadialDistortionCoefficients;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 18);
  if (numDistortionCoeffs + 1.0 > numIntrinsicMatrixEntries) {
    i = 0;
    i1 = 0;
  } else {
    if (numDistortionCoeffs + 1.0 !=
        static_cast<int32_T>(muDoubleScalarFloor(numDistortionCoeffs + 1.0))) {
      emlrtIntegerCheckR2012b(numDistortionCoeffs + 1.0, &ug_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(numDistortionCoeffs + 1.0) < 1) ||
        (static_cast<int32_T>(numDistortionCoeffs + 1.0) >
         numIntrinsicMatrixEntries)) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(numDistortionCoeffs + 1.0), 1,
          numIntrinsicMatrixEntries, &uu_emlrtBCI, (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(numDistortionCoeffs + 1.0) - 1;
    if (numIntrinsicMatrixEntries < 1) {
      emlrtDynamicBoundsCheckR2012b(numIntrinsicMatrixEntries, 1,
                                    numIntrinsicMatrixEntries, &tu_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = numIntrinsicMatrixEntries;
  }
  iv[0] = 1;
  loop_ub = i1 - i;
  iv[1] = loop_ub;
  st.site = &fdb_emlrtRSI;
  coder::internal::indexShapeCheck(&st, numIntrinsicMatrixEntries, iv);
  for (i1 = 0; i1 < loop_ub; i1++) {
    x[i1] = x[i + i1];
  }
  x.set_size(&ot_emlrtRTEI, sp, loop_ub);
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 6, loop_ub == 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 19);
    outputParams->RotationVectors.set_size(&rt_emlrtRTEI, sp, 0, 0);
    outputParams->TranslationVectors.set_size(&st_emlrtRTEI, sp, 0, 0);
  } else {
    int32_T calclen;
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 20);
    st.site = &gdb_emlrtRSI;
    b_st.site = &lp_emlrtRSI;
    calclen = loop_ub / 6;
    if (calclen > loop_ub) {
      emlrtErrorWithMessageIdR2018a(&b_st, &jc_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    numIntrinsicMatrixEntries = muIntScalarMax_sint32(loop_ub, loop_ub);
    if (6 > numIntrinsicMatrixEntries) {
      emlrtErrorWithMessageIdR2018a(
          &st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (calclen > numIntrinsicMatrixEntries) {
      emlrtErrorWithMessageIdR2018a(
          &st, &qb_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    if (6 * calclen != loop_ub) {
      emlrtErrorWithMessageIdR2018a(
          &st, &rb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
    }
    outputParams->RotationVectors.set_size(&pt_emlrtRTEI, sp, calclen, 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < calclen; i1++) {
        outputParams
            ->RotationVectors[i1 + outputParams->RotationVectors.size(0) * i] =
            x[i + 6 * i1];
      }
    }
    outputParams->TranslationVectors.set_size(&qt_emlrtRTEI, sp, calclen, 3);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < calclen; i1++) {
        outputParams
            ->TranslationVectors[i1 + outputParams->TranslationVectors.size(0) *
                                          i] = x[(i + 6 * i1) + 3];
      }
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 21);
  st.site = &hdb_emlrtRSI;
  outputParams->IntrinsicMatrix[0] = fx;
  outputParams->IntrinsicMatrix[1] = skew;
  outputParams->IntrinsicMatrix[2] = cx;
  outputParams->IntrinsicMatrix[3] = 0.0;
  outputParams->IntrinsicMatrix[4] = fy;
  outputParams->IntrinsicMatrix[5] = cy;
  outputParams->IntrinsicMatrix[6] = 0.0;
  outputParams->IntrinsicMatrix[7] = 0.0;
  outputParams->IntrinsicMatrix[8] = 1.0;
  b_st.site = &i_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  b_st.site = &j_emlrtRSI;
  c_st.site = &obb_emlrtRSI;
  coder::cameraParameters::checkIntrinsicMatrix(&c_st,
                                                outputParams->IntrinsicMatrix);
  c_st.site = &n_emlrtRSI;
  coder::cameraParameters::checkRadialDistortion(
      &c_st, outputParams->RadialDistortion);
  c_st.site = &o_emlrtRSI;
  coder::cameraParameters::checkTangentialDistortion(
      &c_st, outputParams->TangentialDistortion);
  c_st.site = &p_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  coder::cameraParameters::checkImageSize(&d_st, cameraParams->ImageSize);
  c_st.site = &q_emlrtRSI;
  coder::cameraParameters::checkImageSize(&c_st, cameraParams->ImageSize);
  c_st.site = &pbb_emlrtRSI;
  coder::cameraParameters::b_checkRotationVectors(
      &c_st, outputParams->RotationVectors);
  c_st.site = &qbb_emlrtRSI;
  coder::cameraParameters::b_checkTranslationVectors(
      &c_st, outputParams->TranslationVectors);
  c_st.site = &r_emlrtRSI;
  coder::cameraParameters::checkNumRadialCoeffs(
      &c_st, cameraParams->NumRadialDistortionCoefficients);
  if ((((outputParams->RotationVectors.size(0) == 0) ||
        (outputParams->RotationVectors.size(1) == 0)) &&
       ((outputParams->TranslationVectors.size(0) != 0) &&
        (outputParams->TranslationVectors.size(1) != 0))) ||
      (((outputParams->TranslationVectors.size(0) == 0) ||
        (outputParams->TranslationVectors.size(1) == 0)) &&
       ((outputParams->RotationVectors.size(0) != 0) &&
        (outputParams->RotationVectors.size(1) != 0)))) {
    emlrtErrorWithMessageIdR2018a(
        &st, &gc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether",
        "vision:calibrate:rotationAndTranslationVectorsMustBeSetTogether", 0);
  }
  b_outputParams[0] = (outputParams->RotationVectors.size(0) !=
                       outputParams->TranslationVectors.size(0));
  b_outputParams[1] = (outputParams->RotationVectors.size(1) !=
                       outputParams->TranslationVectors.size(1));
  b_st.site = &nbb_emlrtRSI;
  if (coder::any(b_outputParams)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &hc_emlrtRTEI,
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize",
        "vision:calibrate:rotationAndTranslationVectorsNotSameSize", 0);
  }
  b_st.site = &k_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  st.site = &hdb_emlrtRSI;
  b_st.site = &cb_emlrtRSI;
  outputParams->ImageSize[0] = cameraParams->ImageSize[0];
  outputParams->WorldUnits[0] = 'm';
  outputParams->ImageSize[1] = cameraParams->ImageSize[1];
  outputParams->WorldUnits[1] = 'm';
  outputParams->EstimateSkew = cameraParams->EstimateSkew;
  outputParams->NumRadialDistortionCoefficients =
      cameraParams->NumRadialDistortionCoefficients;
  outputParams->EstimateTangentialDistortion =
      cameraParams->EstimateTangentialDistortion;
  c_st.site = &db_emlrtRSI;
}

void calibrateOneCamera_v2(const emlrtStack *sp,
                           const coder::array<uint8_T, 4U> &images,
                           real_T squareSize, const int32_T boardSize[2],
                           struct0_T *cameraParams,
                           coder::array<real_T, 1U> &errorOptimized,
                           real_T *MREf, coder::array<boolean_T, 1U> &validIdx,
                           int32_T *err)
{
  coder::anonymous_function b_this;
  coder::b_cameraParameters b_cameraParams;
  coder::cameraParameters lobj_0;
  coder::array<cell_wrap_12, 2U> board_points;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 2U> rt;
  coder::array<real_T, 1U> initialParamsSerial;
  coder::array<real_T, 1U> tmp;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<uint8_T, 2U> b_images;
  coder::array<boolean_T, 1U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T intrinsicMatrix[9];
  real_T t12_RadialDistortion[3];
  real_T b_dv[2];
  real_T board_size_detected[2];
  real_T board_size_valid[2];
  real_T image_size[2];
  real_T a__3;
  real_T c_t12_NumRadialDistortionCoeffi;
  int32_T result[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T nz;
  int32_T sizes_idx_0;
  int32_T sizes_idx_1;
  boolean_T c_t12_EstimateTangentialDistort;
  boolean_T empty_non_axis_sizes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  Multiple Camera Calibration Toolbox - V1
  //  Laura Ribeiro, Tampere University, Finland
  //  (laura.goncalvesribeiro@tuni.fi)
  //  Step 1
  //  Calibrates each camera independently using Matlab Camera Calibrator
  //  Application Calculates extrinsic parameters between camera N and camera 1
  //  Inputs: directory of calibration images, squareSize, boardSize
  //  Follow the naming convetion for calibration images: PositionXXX_CameraXX
  //  Step 2
  //  Overall Optimization
  //  Options:
  //  Re-estimate all: [1, 1, 1 ,1];
  //  Fixed Intrinsics: [1, 1, 0 ,0];
  //  Fixed lens distortions: [0, 1, 0 ,0];
  //  Default: Fixed intrinsics.
  // {
  //  ITER API ALGORITHM IMPLEMENTATION STARTS HERE
  //  Calibrate One Camera
  // function [CameraParameters,errorOptimized, calculation_err, err] =
  // calibrateOneCamera(images, squareSize, boardSize)
  //
  //  Generate world coordinates of the checkerboard keypoints
  // worldPoints = generateCheckerboardPoints(boardSize, squareSize);
  //
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  // [ImagePoints, boardSizeDetected , checkFound] =
  // detectCheckerboardPoints(imageFileNames(:)); % detect checkerboard for
  // every position of camera i
  //
  // disp(boardSize == boardSizeDetected);
  //
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  // cameraModel.EstimateSkew = false;
  // cameraModel.EstimateTangentialDistortion = false;
  // cameraModel.NumRadialDistortionCoefficients =3;
  //
  // [initialParams, imagesUsed] = computeInitialParameterEstimate(...
  //     worldPoints, ImagePoints, [], cameraModel, 'millimeters', [], []);
  //
  //  Convert Extrinsics to my way
  // clear RTc1pn
  // tempR= initialParams.RotationMatrices(:,:,imagesUsed);
  // tempt= initialParams.TranslationVectors(imagesUsed,:);
  // for i=1:size(tempR,3)
  //     RTc1pn{i} = RTtoTransform(tempR(:,:,i),tempt(i,:));
  // end
  //  Crete Calibration Struct
  // calibration.CameraParameters = initialParams;
  // calibration.PatternPositions = RTc1pn;
  // calibration.ImagePoints = ImagePoints;
  //  Minimization options
  //  Default options give better outcome
  //  minimization_options=optimset('LargeScale','on',...
  //      'Algorithm','levenberg-marquardt',...
  //      'TolFun',1e-10,...
  //      'Display','on',...
  //      'TolX',1e-10,...
  //      'MaxFunEvals',200000,...
  //      'MaxIter',10000,...
  //      'UseParallel', false);
  //
  //  Optimization options: fixedK, fixedDistortions, fixedRTpnc1
  // options = [0,0,0];
  // World and Image Points
  // genPoints = [worldPoints, ones(size(worldPoints,1),1)];
  // detPoints = calibration.ImagePoints;
  //  Convert initial estimate
  // serialCalib = serializeCalib(calibration, options);
  //
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration); errorInitial = CalculateCost(serialCalib, options,
  // calibration, genPoints, detPoints); tmp = errorInitial;
  // tmp(tmp<0.000001)=NaN; MREi = mean(tmp(~isnan(tmp(:)))); disp (['Mean
  // Reprojection Error - Before Optimization: ', num2str(MREi)]);
  //  Optimization
  // h = waitbar(0, 'Running global Optimization...','Name', 'Global
  // Optimization');
  //
  // [optimizedSerialCalib,~,residual,~,~,~,jacobian] = lsqnonlin(@(x)
  // CalculateCost(x, options, calibration, genPoints, detPoints),serialCalib,
  // [],[]);
  //
  // delete(h);
  //
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  // CI(:,1) = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI(:,2) = unserializeCalib(serialCI(:,2)', options, calibration);
  //
  // errorOptimized = CalculateCost(optimizedSerialCalib, options, calibration,
  // genPoints, detPoints); tmp = errorOptimized; tmp(tmp<0.000001)=NaN; MREf =
  // nanmean(tmp(:)); disp (['Mean Reprojection Error - After Optimization: ',
  // num2str(MREf)]);
  //
  // [calibrationOptimized] = unserializeCalib(optimizedSerialCalib, options,
  // calibration);
  //
  // calibrationOptimized.OptimizationOptions = options;
  // calibrationOptimized.Jacobian = jacobian;
  // calibrationOptimized.Error = errorOptimized;
  // calibrationOptimized.CI = CI;
  //
  // end
  // }
  //  Retrieve useful information
  image_size[0] = static_cast<uint32_T>(images.size(0));
  image_size[1] = static_cast<uint32_T>(images.size(1));
  //  Initalize error flag
  st.site = &emlrtRSI;
  lobj_0.init(&st, image_size)
      ->toStruct(t12_RadialDistortion, cameraParams->TangentialDistortion,
                 cameraParams->ImageSize, cameraParams->WorldUnits,
                 &empty_non_axis_sizes, &c_t12_NumRadialDistortionCoeffi,
                 &c_t12_EstimateTangentialDistort,
                 cameraParams->IntrinsicMatrix);
  cameraParams->RadialDistortion.set_size(&xc_emlrtRTEI, sp, 1, 3);
  cameraParams->RadialDistortion[0] = t12_RadialDistortion[0];
  cameraParams->RadialDistortion[1] = t12_RadialDistortion[1];
  cameraParams->RadialDistortion[2] = t12_RadialDistortion[2];
  cameraParams->EstimateSkew = empty_non_axis_sizes;
  cameraParams->NumRadialDistortionCoefficients =
      c_t12_NumRadialDistortionCoeffi;
  cameraParams->EstimateTangentialDistortion = c_t12_EstimateTangentialDistort;
  cameraParams->RotationVectors.set_size(&xc_emlrtRTEI, sp, 0, 3);
  cameraParams->TranslationVectors.set_size(&xc_emlrtRTEI, sp, 0, 3);
  errorOptimized.set_size(&yc_emlrtRTEI, sp, 0);
  *MREf = rtInf;
  st.site = &b_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  //  Initialize error flags
  *err = 0;
  board_size_valid[0] = 0.0;
  sizes_idx_0 = 0;
  board_size_valid[1] = 0.0;
  sizes_idx_1 = 0;
  validIdx.set_size(&ad_emlrtRTEI, &st, images.size(3));
  result[1] = images.size(3);
  board_points.set_size(&ad_emlrtRTEI, &st, 1, images.size(3));
  for (i = 0; i < result[1]; i++) {
    nz = board_points.size(1) - 1;
    if (i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, board_points.size(1) - 1, &f_emlrtBCI,
                                    &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &ad_emlrtRTEI, &st, 0,
        board_points[board_points.size(0) * i].f1.size(1));
    if (i > nz) {
      emlrtDynamicBoundsCheckR2012b(i, 0, nz, &f_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * i].f1.set_size(
        &ad_emlrtRTEI, &st, board_points[board_points.size(0) * i].f1.size(0),
        0);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  //  perform checkerboards detection in each image
  i = images.size(3);
  board_points.set_size(&ad_emlrtRTEI, &st, 1, images.size(3));
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T guard1{false};
    covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    if (b_i + 1 > images.size(3)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, images.size(3), &d_emlrtBCI,
                                    &st);
    }
    loop_ub = images.size(0);
    nz = images.size(1);
    b_images.set_size(&bd_emlrtRTEI, &st, images.size(0), images.size(1));
    for (i1 = 0; i1 < nz; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_images[i2 + b_images.size(0) * i1] =
            images[(i2 + images.size(0) * i1) +
                   images.size(0) * images.size(1) * b_i];
      }
    }
    b_st.site = &eb_emlrtRSI;
    coder::detectCheckerboardPoints(&b_st, b_images, rt, board_size_detected);
    //  mark if checkerboards is detected or not
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    guard1 = false;
    if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 0,
                     coder::isequal(board_size_detected, b_dv))) {
      guard1 = true;
    } else {
      boolean_T exitg1;
      covrtLogCond(&emlrtCoverageInstance, 1, 0, 1, false);
      empty_non_axis_sizes = true;
      nz = 0;
      exitg1 = false;
      while ((!exitg1) && (nz < 2)) {
        if (!(board_size_detected[nz] == boardSize[nz])) {
          empty_non_axis_sizes = false;
          exitg1 = true;
        } else {
          nz++;
        }
      }
      if (!covrtLogCond(&emlrtCoverageInstance, 1, 0, 2,
                        empty_non_axis_sizes)) {
        guard1 = true;
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, false);
        covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, false);
        b_dv[0] = 0.0;
        b_dv[1] = 0.0;
        if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 1,
                       coder::isequal(board_size_valid, b_dv))) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 1, 3);
          board_size_valid[0] = board_size_detected[0];
          sizes_idx_0 = rt.size(0);
          board_size_valid[1] = board_size_detected[1];
          sizes_idx_1 = rt.size(1);
        } else if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 2,
                              covrtLogMcdc(
                                  &emlrtCoverageInstance, 1, 0, 1,
                                  !covrtLogCond(
                                      &emlrtCoverageInstance, 1, 0, 3,
                                      coder::isequal(board_size_valid,
                                                     board_size_detected))))) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 1, 4);
          *err = -102;
        }
        covrtLogBasicBlock(&emlrtCoverageInstance, 1, 5);
        if (b_i + 1 > validIdx.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0),
                                        &h_emlrtBCI, &st);
        }
        validIdx[b_i] = true;
      }
    }
    if (guard1) {
      covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
      if (b_i + 1 > validIdx.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0), &g_emlrtBCI,
                                      &st);
      }
      validIdx[b_i] = false;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 6);
    loop_ub = rt.size(0) * rt.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &cd_emlrtRTEI, &st, rt.size(0),
        board_points[board_points.size(0) * b_i].f1.size(1));
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    board_points[board_points.size(0) * b_i].f1.set_size(
        &cd_emlrtRTEI, &st, board_points[board_points.size(0) * b_i].f1.size(0),
        rt.size(1));
    i1 = board_points.size(1);
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    if (b_i > board_points.size(1) - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                    &e_emlrtBCI, &st);
    }
    for (i2 = 0; i2 < loop_ub; i2++) {
      if (b_i > i1 - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &i_emlrtBCI, &st);
      }
      board_points[b_i].f1[i2] = rt[i2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1, 0, 0, 0);
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 3, *err != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 7);
    // err = "Checkerboards detected has different size from given boardSize";
    b_this.workspace.image_points.set_size(&kd_emlrtRTEI, &st, 0, 0, 1);
    b_this.workspace.world_points.set_size(&ld_emlrtRTEI, &st, 0, 0);
  } else {
    b_st.site = &fb_emlrtRSI;
    if (covrtLogIf(
            &emlrtCoverageInstance, 1, 0, 4,
            covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 2,
                         !covrtLogCond(&emlrtCoverageInstance, 1, 0, 4,
                                       coder::b_any(&b_st, validIdx))))) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 8);
      // err = "No detect of checkerboard in all images";
      *err = -101;
      b_this.workspace.image_points.set_size(&id_emlrtRTEI, &st, 0, 0, 1);
      b_this.workspace.world_points.set_size(&jd_emlrtRTEI, &st, 0, 0);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 9);
      //  Extract valid image points into matrix
      b_st.site = &gb_emlrtRSI;
      x.set_size(&dd_emlrtRTEI, &b_st, validIdx.size(0));
      loop_ub = validIdx.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[i] = validIdx[i];
      }
      c_st.site = &iw_emlrtRSI;
      d_st.site = &yo_emlrtRSI;
      nz = coder::combineVectorElements(&d_st, x);
      b_this.workspace.image_points.set_size(&ed_emlrtRTEI, &st, sizes_idx_0,
                                             sizes_idx_1, nz);
      loop_ub = sizes_idx_0 * sizes_idx_1 * nz;
      for (i = 0; i < loop_ub; i++) {
        b_this.workspace.image_points[i] = 0.0;
      }
      i = images.size(3);
      for (b_i = 0; b_i < i; b_i++) {
        covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 1);
        if (b_i + 1 > validIdx.size(0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validIdx.size(0),
                                        &j_emlrtBCI, &st);
        }
        if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 5, validIdx[b_i])) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 1, 10);
          loop_ub = b_this.workspace.image_points.size(0);
          r1.set_size(&fd_emlrtRTEI, &st,
                      b_this.workspace.image_points.size(0));
          for (i1 = 0; i1 < loop_ub; i1++) {
            r1[i1] = i1;
          }
          loop_ub = b_this.workspace.image_points.size(1);
          r2.set_size(&gd_emlrtRTEI, &st,
                      b_this.workspace.image_points.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            r2[i1] = i1;
          }
          if (b_i + 1 > b_this.workspace.image_points.size(2)) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                                          b_this.workspace.image_points.size(2),
                                          &c_emlrtBCI, &st);
          }
          if (b_i > board_points.size(1) - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, board_points.size(1) - 1,
                                          &b_emlrtBCI, &st);
          }
          result[0] = r1.size(0);
          result[1] = r2.size(0);
          emlrtSubAssignSizeCheckR2012b(
              &result[0], 2, board_points[b_i].f1.size(), 2, &emlrtECI, &st);
          loop_ub = board_points[b_i].f1.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            nz = board_points[b_i].f1.size(0);
            for (i2 = 0; i2 < nz; i2++) {
              b_this.workspace.image_points
                  [(r1[i2] + b_this.workspace.image_points.size(0) * r2[i1]) +
                   b_this.workspace.image_points.size(0) *
                       b_this.workspace.image_points.size(1) * b_i] =
                  board_points[b_i].f1[i2 + board_points[b_i].f1.size(0) * i1];
            }
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      covrtLogFor(&emlrtCoverageInstance, 1, 0, 1, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1, 11);
      //  Generate world coordinates of the corners of the squares in meters
      b_st.site = &hb_emlrtRSI;
      coder::generateCheckerboardPoints(&b_st, board_size_valid, squareSize, r);
      b_this.workspace.world_points.set_size(&hd_emlrtRTEI, &st, r.size(0), 2);
      loop_ub = r.size(0) * 2;
      for (i = 0; i < loop_ub; i++) {
        b_this.workspace.world_points[i] = r[i];
      }
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, *err != 0)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
    //  Inital Parameter Estimate
    // If want different values of EstimateSkew, EstimateTangentialDistortion,
    // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
    st.site = &c_emlrtRSI;
    computeInitialParameterEstimate(&st, b_this.workspace.world_points,
                                    b_this.workspace.image_points, image_size,
                                    &b_this.workspace.initialParams, x, err);
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, *err != 0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
    } else {
      int8_T input_sizes_idx_1;
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
      //
      st.site = &d_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 0, 3);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
      b_st.site = &wbb_emlrtRSI;
      b_cameraParams.init(&b_st, &b_this.workspace.initialParams);
      //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
      b_st.site = &xbb_emlrtRSI;
      b_cameraParams.get_FocalLength(image_size);
      b_st.site = &xbb_emlrtRSI;
      b_cameraParams.get_FocalLength(board_size_valid);
      b_st.site = &ybb_emlrtRSI;
      b_cameraParams.get_PrincipalPoint(board_size_detected);
      b_st.site = &ybb_emlrtRSI;
      b_cameraParams.get_PrincipalPoint(b_dv);
      initialParamsSerial.set_size(&md_emlrtRTEI, &st, 4);
      initialParamsSerial[0] = image_size[0];
      initialParamsSerial[1] = board_size_valid[1];
      initialParamsSerial[2] = board_size_detected[0];
      initialParamsSerial[3] = b_dv[1];
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 2,
                     b_cameraParams.EstimateSkew)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
        b_st.site = &acb_emlrtRSI;
        c_st.site = &kcb_emlrtRSI;
        for (i = 0; i < 3; i++) {
          intrinsicMatrix[3 * i] = b_cameraParams.IntrinsicMatrixInternal[i];
          intrinsicMatrix[3 * i + 1] =
              b_cameraParams.IntrinsicMatrixInternal[i + 3];
          intrinsicMatrix[3 * i + 2] =
              b_cameraParams.IntrinsicMatrixInternal[i + 6];
        }
        initialParamsSerial.set_size(&nd_emlrtRTEI, &st, 5);
        initialParamsSerial[4] = intrinsicMatrix[1];
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 10);
      c_t12_NumRadialDistortionCoeffi =
          b_cameraParams.NumRadialDistortionCoefficients;
      if (1.0 > c_t12_NumRadialDistortionCoeffi) {
        loop_ub = 0;
      } else {
        if (c_t12_NumRadialDistortionCoeffi !=
            static_cast<int32_T>(
                muDoubleScalarFloor(c_t12_NumRadialDistortionCoeffi))) {
          emlrtIntegerCheckR2012b(c_t12_NumRadialDistortionCoeffi, &emlrtDCI,
                                  &st);
        }
        if ((static_cast<int32_T>(c_t12_NumRadialDistortionCoeffi) < 1) ||
            (static_cast<int32_T>(c_t12_NumRadialDistortionCoeffi) > 3)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(c_t12_NumRadialDistortionCoeffi), 1, 3,
              &emlrtBCI, &st);
        }
        loop_ub = static_cast<int32_T>(c_t12_NumRadialDistortionCoeffi);
      }
      i = initialParamsSerial.size(0);
      initialParamsSerial.set_size(&nd_emlrtRTEI, &st,
                                   initialParamsSerial.size(0) + loop_ub);
      for (i1 = 0; i1 < loop_ub; i1++) {
        initialParamsSerial[i + i1] = b_cameraParams.RadialDistortion[i1];
      }
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 3,
                     b_cameraParams.EstimateTangentialDistortion)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 11);
        i = initialParamsSerial.size(0);
        initialParamsSerial.set_size(&nd_emlrtRTEI, &st,
                                     initialParamsSerial.size(0) + 2);
        initialParamsSerial[i] = b_cameraParams.TangentialDistortion[0];
        initialParamsSerial[i + 1] = b_cameraParams.TangentialDistortion[1];
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 12);
      b_st.site = &bcb_emlrtRSI;
      c_st.site = &lcb_emlrtRSI;
      if (b_cameraParams.RotationVectors.size(0) != 0) {
        nz = b_cameraParams.RotationVectors.size(0);
      } else if (b_cameraParams.TranslationVectors.size(0) != 0) {
        nz = b_cameraParams.TranslationVectors.size(0);
      } else {
        nz = 0;
      }
      d_st.site = &uo_emlrtRSI;
      if ((b_cameraParams.RotationVectors.size(0) != nz) &&
          (b_cameraParams.RotationVectors.size(0) != 0)) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
      }
      if ((b_cameraParams.TranslationVectors.size(0) != nz) &&
          (b_cameraParams.TranslationVectors.size(0) != 0)) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
            "MATLAB:catenate:matrixDimensionMismatch", 0);
      }
      empty_non_axis_sizes = (nz == 0);
      if (empty_non_axis_sizes ||
          (b_cameraParams.RotationVectors.size(0) != 0)) {
        input_sizes_idx_1 = 3;
      } else {
        input_sizes_idx_1 = 0;
      }
      if (empty_non_axis_sizes ||
          (b_cameraParams.TranslationVectors.size(0) != 0)) {
        sizes_idx_1 = 3;
      } else {
        sizes_idx_1 = 0;
      }
      rt.set_size(&od_emlrtRTEI, &st, input_sizes_idx_1 + sizes_idx_1, nz);
      for (i = 0; i < nz; i++) {
        loop_ub = input_sizes_idx_1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          rt[i1 + rt.size(0) * i] = b_cameraParams.RotationVectors[i + nz * i1];
        }
      }
      for (i = 0; i < nz; i++) {
        for (i1 = 0; i1 < sizes_idx_1; i1++) {
          rt[(i1 + input_sizes_idx_1) + rt.size(0) * i] =
              b_cameraParams.TranslationVectors[i + nz * i1];
        }
      }
      i = initialParamsSerial.size(0);
      initialParamsSerial.set_size(&nd_emlrtRTEI, &st,
                                   initialParamsSerial.size(0) +
                                       rt.size(0) * rt.size(1));
      nz = rt.size(0) * rt.size(1);
      for (i1 = 0; i1 < nz; i1++) {
        initialParamsSerial[i + i1] = rt[i1];
      }
      //  r1, t1, r2, t2, ...
      // unpackedCameraParams = unpackSerializedParams(initialParams,
      // initialParamsSerial, 0);
      //  Calculate mre - before optimization
      // [errorInitial] = reprojectWrapper(initialParamsSerial, initialParams,
      // 0, worldPoints, ImagePoints); tmp = errorInitial;
      // tmp(tmp<0.000001)=NaN; MREi = nanmean(tmp(:)); disp (['Mean
      // Reprojection Error - Before Optimization: ', num2str(MREi)]); Optimize
      //  Optimization
      st.site = &e_emlrtRSI;
      coder::lsqnonlin(&st, &b_this, initialParamsSerial,
                       &c_t12_NumRadialDistortionCoeffi, tmp, &a__3, rt);
      //  Calculate mre - after optimization
      st.site = &f_emlrtRSI;
      reprojectWrapper(&st, initialParamsSerial,
                       &b_this.workspace.initialParams,
                       b_this.workspace.world_points,
                       b_this.workspace.image_points, errorOptimized);
      tmp.set_size(&pd_emlrtRTEI, sp, errorOptimized.size(0));
      loop_ub = errorOptimized.size(0);
      for (i = 0; i < loop_ub; i++) {
        tmp[i] = errorOptimized[i];
      }
      nz = errorOptimized.size(0);
      for (b_i = 0; b_i < nz; b_i++) {
        if (errorOptimized[b_i] < 1.0E-6) {
          if (b_i + 1 > errorOptimized.size(0)) {
            emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, errorOptimized.size(0),
                                          &k_emlrtBCI, (emlrtCTX)sp);
          }
          tmp[b_i] = rtNaN;
        }
      }
      st.site = &g_emlrtRSI;
      *MREf = coder::nanmean(&st, tmp);
      // disp (['Mean Reprojection Error - After Optimization: ',
      // num2str(MREf)]);
      st.site = &h_emlrtRSI;
      unpackSerializedParams(&st, &b_this.workspace.initialParams,
                             initialParamsSerial, cameraParams);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void calibrateOneCamera_v2_anonFcn1(
    const emlrtStack *sp, const struct_T *initialParams,
    const coder::array<real_T, 2U> &world_points,
    const coder::array<real_T, 3U> &image_points,
    const coder::array<real_T, 1U> &x, coder::array<real_T, 1U> &varargout_1)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
  st.site = &vcb_emlrtRSI;
  reprojectWrapper(&st, x, initialParams, world_points, image_points,
                   varargout_1);
}

void reprojectWrapper(const emlrtStack *sp,
                      const coder::array<real_T, 1U> &paramsVector,
                      const struct_T *cameraParams,
                      const coder::array<real_T, 2U> &worldPoints,
                      const coder::array<real_T, 3U> &ImagePoints,
                      coder::array<real_T, 1U> &cost)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  coder::d_cameraParameters paramStruct;
  coder::array<real_T, 3U> r;
  coder::array<real_T, 2U> b_v;
  coder::array<real_T, 2U> internal_worldPoints;
  coder::array<real_T, 2U> projectedPoints;
  coder::array<real_T, 2U> r1;
  coder::array<real_T, 2U> v;
  coder::array<real_T, 1U> b_error;
  coder::array<int32_T, 2U> r2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  struct0_T expl_temp;
  real_T R[9];
  real_T theta;
  int32_T iv[2];
  int32_T ysize[2];
  int32_T b;
  int32_T i;
  int32_T iy;
  int32_T j;
  int8_T a[9];
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 2);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
  b_error.set_size(&at_emlrtRTEI, sp, paramsVector.size(0));
  iy = paramsVector.size(0) - 1;
  for (i = 0; i <= iy; i++) {
    b_error[i] = paramsVector[i];
  }
  st.site = &wcb_emlrtRSI;
  unpackSerializedParams(&st, cameraParams, b_error, &expl_temp);
  st.site = &xcb_emlrtRSI;
  paramStruct.init(
      &st, expl_temp.RadialDistortion, expl_temp.TangentialDistortion,
      expl_temp.ImageSize, expl_temp.WorldUnits, expl_temp.EstimateSkew,
      expl_temp.NumRadialDistortionCoefficients,
      expl_temp.EstimateTangentialDistortion, expl_temp.RotationVectors,
      expl_temp.TranslationVectors, expl_temp.IntrinsicMatrix);
  st.site = &ycb_emlrtRSI;
  ysize[1] = worldPoints.size(1) + 1;
  ysize[0] = worldPoints.size(0);
  if (worldPoints.size(1) + 1 < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(worldPoints.size(1) + 1),
                                &tg_emlrtDCI, &st);
  }
  internal_worldPoints.set_size(&bt_emlrtRTEI, &st, worldPoints.size(0),
                                worldPoints.size(1));
  iy = worldPoints.size(0) * worldPoints.size(1);
  for (i = 0; i < iy; i++) {
    internal_worldPoints[i] = worldPoints[i];
  }
  internal_worldPoints.set_size(&ct_emlrtRTEI, &st, worldPoints.size(0),
                                worldPoints.size(1) + 1);
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if ((j + 1 != 2) && (ysize[j] != worldPoints.size(j))) {
      emlrtErrorWithMessageIdR2018a(
          &st, &tb_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      j++;
    }
  }
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    if (j + 1 != 2) {
      if (j + 1 <= 1) {
        iy = worldPoints.size(0);
      } else {
        iy = 1;
      }
      if (ysize[j] != iy) {
        emlrtErrorWithMessageIdR2018a(
            &st, &tb_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        j++;
      }
    } else {
      j++;
    }
  }
  iy = worldPoints.size(0) * worldPoints.size(1);
  b = worldPoints.size(0);
  b_st.site = &ks_emlrtRSI;
  if ((1 <= worldPoints.size(0)) && (worldPoints.size(0) > 2147483646)) {
    c_st.site = &yc_emlrtRSI;
    coder::check_forloop_overflow_error(&c_st);
  }
  for (j = 0; j < b; j++) {
    internal_worldPoints[iy + j] = 0.0;
  }
  theta = static_cast<real_T>(paramStruct.RotationVectors.size(0)) *
          static_cast<real_T>(ImagePoints.size(0));
  if (!(theta >= 0.0)) {
    emlrtNonNegativeCheckR2012b(theta, &sg_emlrtDCI, (emlrtCTX)sp);
  }
  if (theta != static_cast<int32_T>(theta)) {
    emlrtIntegerCheckR2012b(theta, &rg_emlrtDCI, (emlrtCTX)sp);
  }
  cost.set_size(&dt_emlrtRTEI, sp, static_cast<int32_T>(theta));
  theta = static_cast<real_T>(paramStruct.RotationVectors.size(0)) *
          static_cast<real_T>(ImagePoints.size(0));
  if (!(theta >= 0.0)) {
    emlrtNonNegativeCheckR2012b(theta, &sg_emlrtDCI, (emlrtCTX)sp);
  }
  if (theta != static_cast<int32_T>(theta)) {
    emlrtIntegerCheckR2012b(theta, &rg_emlrtDCI, (emlrtCTX)sp);
  }
  iy = static_cast<int32_T>(theta);
  for (i = 0; i < iy; i++) {
    cost[i] = 0.0;
  }
  i = paramStruct.RotationVectors.size(0) - 1;
  for (int32_T n{0}; n <= i; n++) {
    real_T alpha;
    int32_T i1;
    int32_T i2;
    boolean_T p;
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
    //  for each image
    if ((n + 1 < 1) || (n + 1 > ImagePoints.size(2))) {
      emlrtDynamicBoundsCheckR2012b(n + 1, 1, ImagePoints.size(2), &ju_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &adb_emlrtRSI;
    b_st.site = &idb_emlrtRSI;
    iy = paramStruct.RotationVectors.size(0);
    r.set_size(&et_emlrtRTEI, &st, 3, 3, r.size(2));
    if (iy < 0) {
      emlrtNonNegativeCheckR2012b(static_cast<real_T>(iy), &qg_emlrtDCI, &st);
    }
    r.set_size(&et_emlrtRTEI, &st, r.size(0), r.size(1), iy);
    iy *= 9;
    for (i1 = 0; i1 < iy; i1++) {
      r[i1] = 0.0;
    }
    b_st.site = &jdb_emlrtRSI;
    i1 = paramStruct.RotationVectors.size(0) - 1;
    for (j = 0; j <= i1; j++) {
      i2 = paramStruct.RotationVectors.size(0);
      if ((static_cast<int32_T>(j + 1U) < 1) ||
          (static_cast<int32_T>(j + 1U) > i2)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1, i2,
                                      &ou_emlrtBCI, &st);
      }
      iy = paramStruct.RotationVectors.size(1);
      v.set_size(&ft_emlrtRTEI, &st, 1, iy);
      for (i2 = 0; i2 < iy; i2++) {
        v[i2] =
            paramStruct
                .RotationVectors[j + paramStruct.RotationVectors.size(0) * i2];
      }
      b_st.site = &kdb_emlrtRSI;
      c_st.site = &ldb_emlrtRSI;
      d_st.site = &mdb_emlrtRSI;
      if (v.size(1) == 0) {
        theta = 0.0;
      } else {
        e_st.site = &wq_emlrtRSI;
        f_st.site = &xq_emlrtRSI;
        n_t = (ptrdiff_t)v.size(1);
        incx_t = (ptrdiff_t)1;
        theta = dnrm2(&n_t, &v[0], &incx_t);
      }
      if (theta < 1.0E-6) {
        std::memset(&R[0], 0, 9U * sizeof(real_T));
        R[0] = 1.0;
        R[4] = 1.0;
        R[8] = 1.0;
      } else {
        v.set_size(&gt_emlrtRTEI, &c_st, 1, v.size(1));
        iy = v.size(1) - 1;
        for (i2 = 0; i2 <= iy; i2++) {
          v[i2] = v[i2] / theta;
        }
        if (1 > v.size(1)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v.size(1), &qu_emlrtBCI, &c_st);
        }
        if (2 > v.size(1)) {
          emlrtDynamicBoundsCheckR2012b(2, 1, v.size(1), &ru_emlrtBCI, &c_st);
        }
        if (3 > v.size(1)) {
          emlrtDynamicBoundsCheckR2012b(3, 1, v.size(1), &su_emlrtBCI, &c_st);
        }
        alpha = muDoubleScalarCos(theta);
        theta = muDoubleScalarSin(theta);
        b_v.set_size(&ht_emlrtRTEI, &c_st, v.size(1), v.size(1));
        iy = v.size(1);
        for (i2 = 0; i2 < iy; i2++) {
          b = v.size(1);
          for (int32_T i3{0}; i3 < b; i3++) {
            b_v[i3 + b_v.size(0) * i2] = v[i3] * v[i2];
          }
        }
        r1.set_size(&it_emlrtRTEI, &c_st, b_v.size(0), b_v.size(1));
        iy = b_v.size(0) * b_v.size(1);
        for (i2 = 0; i2 < iy; i2++) {
          r1[i2] = (1.0 - alpha) * b_v[i2];
        }
        ysize[0] = 3;
        ysize[1] = 3;
        iv[0] = (*(int32_T(*)[2])r1.size())[0];
        iv[1] = (*(int32_T(*)[2])r1.size())[1];
        emlrtSizeEqCheckNDR2012b(&ysize[0], &iv[0], &fd_emlrtECI, &c_st);
        for (i2 = 0; i2 < 9; i2++) {
          a[i2] = 0;
        }
        a[0] = 1;
        a[4] = 1;
        a[8] = 1;
        R[0] = theta * 0.0;
        R[3] = theta * -v[2];
        R[6] = theta * v[1];
        R[1] = theta * v[2];
        R[4] = theta * 0.0;
        R[7] = theta * -v[0];
        R[2] = theta * -v[1];
        R[5] = theta * v[0];
        R[8] = theta * 0.0;
        for (i2 = 0; i2 < 9; i2++) {
          R[i2] = (static_cast<real_T>(a[i2]) * alpha + R[i2]) + r1[i2];
        }
      }
      if ((static_cast<int32_T>(j + 1U) < 1) ||
          (static_cast<int32_T>(j + 1U) > r.size(2))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1U), 1,
                                      r.size(2), &pu_emlrtBCI, &st);
      }
      for (i2 = 0; i2 < 3; i2++) {
        r[3 * i2 + 9 * j] = R[i2];
        r[(3 * i2 + 9 * j) + 1] = R[i2 + 3];
        r[(3 * i2 + 9 * j) + 2] = R[i2 + 6];
      }
    }
    if ((static_cast<int32_T>(n + 1U) < 1) ||
        (static_cast<int32_T>(n + 1U) > r.size(2))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n + 1U), 1, r.size(2),
                                    &ku_emlrtBCI, (emlrtCTX)sp);
    }
    i1 = paramStruct.TranslationVectors.size(0);
    if ((static_cast<int32_T>(n + 1U) < 1) ||
        (static_cast<int32_T>(n + 1U) > i1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n + 1U), 1, i1,
                                    &lu_emlrtBCI, (emlrtCTX)sp);
    }
    iy = paramStruct.TranslationVectors.size(1);
    v.set_size(&jt_emlrtRTEI, sp, 1, iy);
    for (i1 = 0; i1 < iy; i1++) {
      v[i1] =
          paramStruct
              .TranslationVectors[n +
                                  paramStruct.TranslationVectors.size(0) * i1];
    }
    std::copy(&(*(real_T(*)[9]) & r[9 * n])[0],
              &(*(real_T(*)[9]) & r[9 * n])[9], &R[0]);
    st.site = &adb_emlrtRSI;
    coder::worldToImage(&st, &paramStruct, R, v, internal_worldPoints,
                        projectedPoints);
    if ((projectedPoints.size(0) != ImagePoints.size(0)) &&
        ((projectedPoints.size(0) != 1) && (ImagePoints.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(projectedPoints.size(0), ImagePoints.size(0),
                                  &cd_emlrtECI, (emlrtCTX)sp);
    }
    if ((2 != ImagePoints.size(1)) && (ImagePoints.size(1) != 1)) {
      emlrtDimSizeImpxCheckR2021b(2, ImagePoints.size(1), &dd_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if ((projectedPoints.size(0) == ImagePoints.size(0)) &&
        (2 == ImagePoints.size(1))) {
      projectedPoints.set_size(&kt_emlrtRTEI, sp, projectedPoints.size(0), 2);
      for (i1 = 0; i1 < 2; i1++) {
        iy = projectedPoints.size(0);
        for (i2 = 0; i2 < iy; i2++) {
          theta = projectedPoints[i2 + projectedPoints.size(0) * i1] -
                  ImagePoints[(i2 + ImagePoints.size(0) * i1) +
                              ImagePoints.size(0) * ImagePoints.size(1) * n];
          projectedPoints[i2 + projectedPoints.size(0) * i1] = theta * theta;
        }
      }
    } else {
      st.site = &ufb_emlrtRSI;
      binary_expand_op(&st, projectedPoints, ImagePoints, n);
    }
    st.site = &bdb_emlrtRSI;
    b_st.site = &xo_emlrtRSI;
    c_st.site = &yo_emlrtRSI;
    d_st.site = &jl_emlrtRSI;
    if (projectedPoints.size(0) == 0) {
      b_error.set_size(&kl_emlrtRTEI, &d_st, 0);
    } else {
      e_st.site = &ap_emlrtRSI;
      iy = projectedPoints.size(0) - 1;
      b_error.set_size(&jl_emlrtRTEI, &e_st, projectedPoints.size(0));
      f_st.site = &bp_emlrtRSI;
      if (projectedPoints.size(0) > 2147483646) {
        g_st.site = &yc_emlrtRSI;
        coder::check_forloop_overflow_error(&g_st);
      }
      for (b = 0; b <= iy; b++) {
        b_error[b] = projectedPoints[b];
      }
      f_st.site = &cp_emlrtRSI;
      if (projectedPoints.size(0) > 2147483646) {
        g_st.site = &yc_emlrtRSI;
        coder::check_forloop_overflow_error(&g_st);
      }
      for (b = 0; b <= iy; b++) {
        b_error[b] = b_error[b] + projectedPoints[projectedPoints.size(0) + b];
      }
    }
    st.site = &bdb_emlrtRSI;
    b_st.site = &keb_emlrtRSI;
    p = false;
    i1 = b_error.size(0);
    for (b = 0; b < i1; b++) {
      if (p || (b_error[b] < 0.0)) {
        p = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    b_st.site = &leb_emlrtRSI;
    iy = b_error.size(0);
    c_st.site = &meb_emlrtRSI;
    if ((1 <= b_error.size(0)) && (b_error.size(0) > 2147483646)) {
      d_st.site = &yc_emlrtRSI;
      coder::check_forloop_overflow_error(&d_st);
    }
    for (b = 0; b < iy; b++) {
      b_error[b] = muDoubleScalarSqrt(b_error[b]);
    }
    theta = ((static_cast<real_T>(n) + 1.0) - 1.0) *
                static_cast<real_T>(ImagePoints.size(0)) +
            1.0;
    alpha = (static_cast<real_T>(n) + 1.0) *
            static_cast<real_T>(ImagePoints.size(0));
    if (theta > alpha) {
      i1 = 0;
      i2 = 0;
    } else {
      if ((static_cast<int32_T>(theta) < 1) ||
          (static_cast<int32_T>(theta) > cost.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(theta), 1,
                                      cost.size(0), &mu_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = static_cast<int32_T>(theta) - 1;
      if ((static_cast<int32_T>(alpha) < 1) ||
          (static_cast<int32_T>(alpha) > cost.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alpha), 1,
                                      cost.size(0), &nu_emlrtBCI, (emlrtCTX)sp);
      }
      i2 = static_cast<int32_T>(alpha);
    }
    iy = i2 - i1;
    if (iy != b_error.size(0)) {
      emlrtSubAssignSizeCheck1dR2017a(iy, b_error.size(0), &ed_emlrtECI,
                                      (emlrtCTX)sp);
    }
    r2.set_size(&lt_emlrtRTEI, sp, 1, iy);
    for (i2 = 0; i2 < iy; i2++) {
      r2[i2] = i1 + i2;
    }
    iy = r2.size(1);
    for (i1 = 0; i1 < iy; i1++) {
      cost[r2[i1]] = b_error[i1];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (calibrateOneCamera_v2.cpp)
