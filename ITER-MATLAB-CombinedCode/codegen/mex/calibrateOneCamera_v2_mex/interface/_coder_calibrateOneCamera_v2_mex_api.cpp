//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_v2_mex_api.cpp
//
// Code generation for function '_coder_calibrateOneCamera_v2_mex_api'
//

// Include files
#include "_coder_calibrateOneCamera_v2_mex_api.h"
#include "ComputeCamExtrinsics.h"
#include "HandeyeShah.h"
#include "calibrateOneCamera_v2.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_mexutil.h"
#include "calibrateOneCamera_v2_mex_types.h"
#include "computeErrors.h"
#include "preprocessImages.h"
#include "readRobotPoses.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               coder::array<uint8_T, 4U> &y);

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2];

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2];

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[2]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static const mxArray *b_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[16];

static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *c_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *c_emlrt_marshallOut(const real_T u[3]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[2]);

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                   const char_T *identifier))[12];

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

static const mxArray *d_emlrt_marshallOut(const real_T u[16]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16];

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *undistort,
                                    const char_T *identifier);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *cameraParams,
                             const char_T *identifier, struct1_T *y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T *y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[3]);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *squareSize,
                               const char_T *identifier);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<uint8_T, 4U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static const mxArray *emlrt_marshallOut(const int32_T u);

static const mxArray *emlrt_marshallOut(const coder::array<uint8_T, 4U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 3U> &u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[12];

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2];

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16];

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[12];

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  int32_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(boardSize), &thisId);
  emlrtDestroyArray(&boardSize);
  return y;
}

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2]
{
  int32_T(*y)[2];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T b_iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, b_iv[0], b_iv[1]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[2])
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(imgPts), &thisId, y);
  emlrtDestroyArray(&imgPts);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateLogicalArray(1, &i);
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<boolean_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<boolean_T, 1U> *)&u)->size(),
                     1);
  emlrtAssign(&y, m);
  return y;
}

static boolean_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 1, -1};
  int32_T b_iv[4];
  const boolean_T bv[4]{true, true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2] * b_iv[3]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, b_iv[0], b_iv[1], b_iv[2], b_iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[16]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[16];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(Hhand2eye), &thisId);
  emlrtDestroyArray(&Hhand2eye);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{4, 4, -1};
  int32_T b_iv[3];
  const boolean_T bv[3]{false, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

static const mxArray *c_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{1, 3};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 2);
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                   const char_T *identifier))[12]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[12];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(K), &thisId);
  emlrtDestroyArray(&K);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, 2, -1};
  int32_T b_iv[3];
  const boolean_T bv[3]{true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2]{1, 3};
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 3, -1};
  int32_T b_iv[4];
  const boolean_T bv[4]{true, true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1] * b_iv[2] * b_iv[3]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, b_iv[0], b_iv[1], b_iv[2], b_iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
}

static const mxArray *d_emlrt_marshallOut(const real_T u[16])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{4, 4};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static boolean_T e_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *undistort,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(undistort), &thisId);
  emlrtDestroyArray(&undistort);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[16]
{
  real_T(*y)[16];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(Worldpts), &thisId, y);
  emlrtDestroyArray(&Worldpts);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *cameraParams,
                             const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(cameraParams), &thisId, y);
  emlrtDestroyArray(&cameraParams);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[9]{"RadialDistortion",
                                     "TangentialDistortion",
                                     "ImageSize",
                                     "WorldUnits",
                                     "EstimateSkew",
                                     "NumRadialDistortionCoefficients",
                                     "EstimateTangentialDistortion",
                                     "IntrinsicMatrix",
                                     "Version"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 9,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "RadialDistortion";
  emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"RadialDistortion")),
      &thisId, y->RadialDistortion);
  thisId.fIdentifier = "TangentialDistortion";
  b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"TangentialDistortion")),
      &thisId, y->TangentialDistortion);
  thisId.fIdentifier = "ImageSize";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 2, (const char_T *)"ImageSize")),
                     &thisId, y->ImageSize);
  thisId.fIdentifier = "WorldUnits";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 3, (const char_T *)"WorldUnits")),
                     &thisId, y->WorldUnits);
  thisId.fIdentifier = "EstimateSkew";
  y->EstimateSkew = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"EstimateSkew")),
      &thisId);
  thisId.fIdentifier = "NumRadialDistortionCoefficients";
  y->NumRadialDistortionCoefficients =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b(
                           (emlrtCTX)sp, u, 0, 5,
                           (const char_T *)"NumRadialDistortionCoefficients")),
                       &thisId);
  thisId.fIdentifier = "EstimateTangentialDistortion";
  y->EstimateTangentialDistortion =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 6,
                             (const char_T *)"EstimateTangentialDistortion")),
                         &thisId);
  thisId.fIdentifier = "IntrinsicMatrix";
  c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"IntrinsicMatrix")),
      &thisId, y->IntrinsicMatrix);
  thisId.fIdentifier = "Version";
  d_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                                    (const char_T *)"Version")),
                     &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[3])
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *squareSize,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(squareSize), &thisId);
  emlrtDestroyArray(&squareSize);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(Hhand2base), &thisId, y);
  emlrtDestroyArray(&Hhand2base);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<uint8_T, 4U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_iv[2];
  int32_T i;
  y = nullptr;
  b_iv[0] = u.size(0);
  b_iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(1); b_i++) {
    for (int32_T c_i{0}; c_i < u.size(0); c_i++) {
      pData[i] = u[c_i + u.size(0) * b_i];
      i++;
    }
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  static const int32_T b_iv[2]{1, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u[0];
  pData[1] = u[1];
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u)
{
  static const int32_T iv1[2]{0, 2};
  static const int32_T iv2[2]{1, 2};
  static const int32_T iv3[2]{0, 2};
  static const int32_T iv4[2]{3, 3};
  static const int32_T iv5[2]{0, 2};
  static const int32_T iv6[2]{0, 0};
  static const char_T *sv[14]{"RadialDistortion",
                              "TangentialDistortion",
                              "ImageSize",
                              "WorldPoints",
                              "WorldUnits",
                              "EstimateSkew",
                              "NumRadialDistortionCoefficients",
                              "EstimateTangentialDistortion",
                              "RotationVectors",
                              "TranslationVectors",
                              "ReprojectionErrors",
                              "IntrinsicMatrix",
                              "DetectedKeypoints",
                              "Version"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 14, (const char_T **)&sv[0]));
  b_y = nullptr;
  b_iv[0] = 1;
  b_iv[1] = u->RadialDistortion.size(1);
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->RadialDistortion.size(1); b_i++) {
    pData[i] = u->RadialDistortion[b_i];
    i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RadialDistortion", b_y, 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TangentialDistortion",
                      emlrt_marshallOut(u->TangentialDistortion), 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImageSize",
                      emlrt_marshallOut(u->ImageSize), 2);
  c_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldPoints", c_y, 3);
  d_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 2, m, &u->WorldUnits[0]);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldUnits", d_y, 4);
  e_y = nullptr;
  m = emlrtCreateLogicalScalar(u->EstimateSkew);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateSkew", e_y, 5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"NumRadialDistortionCoefficients",
                      emlrt_marshallOut(u->NumRadialDistortionCoefficients), 6);
  f_y = nullptr;
  m = emlrtCreateLogicalScalar(u->EstimateTangentialDistortion);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateTangentialDistortion", f_y,
                      7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RotationVectors",
                      emlrt_marshallOut(u->RotationVectors), 8);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TranslationVectors",
                      emlrt_marshallOut(u->TranslationVectors), 9);
  g_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ReprojectionErrors", g_y, 10);
  h_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv4[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    pData[i] = u->IntrinsicMatrix[3 * b_i];
    pData[i + 1] = u->IntrinsicMatrix[3 * b_i + 1];
    pData[i + 2] = u->IntrinsicMatrix[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"IntrinsicMatrix", h_y, 11);
  i_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv5[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"DetectedKeypoints", i_y, 12);
  j_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv6[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Version", j_y, 13);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<uint8_T, 4U> &u)
{
  static const int32_T b_iv[4]{0, 0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(4, (const void *)&b_iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<uint8_T, 4U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<uint8_T, 4U> *)&u)->size(),
                     4);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 3U> &u)
{
  static const int32_T b_iv[3]{0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 3U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 3U> *)&u)->size(), 3);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const int32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[12]
{
  real_T(*y)[12];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2]{3, 3};
  real_T(*r)[9];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (int32_T i{0}; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  int32_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"int32",
                          false, 2U, (void *)&dims[0]);
  ret = (int32_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 0U, (void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2]{0, 0};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[16]
{
  static const int32_T dims[2]{4, 4};
  real_T(*ret)[16];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[16])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[12]
{
  static const int32_T dims[2]{3, 4};
  real_T(*ret)[12];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void ComputeCamExtrinsics_api(const mxArray *const prhs[3], int32_T nlhs,
                              const mxArray *plhs[6])
{
  coder::array<real_T, 3U> camExtrinsics;
  coder::array<real_T, 3U> cameraPoses;
  coder::array<real_T, 3U> imagePoints;
  coder::array<real_T, 2U> worldPoints;
  coder::array<uint8_T, 4U> images;
  coder::array<boolean_T, 1U> validIdx;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct1_T cameraParams;
  real_T squareSize;
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  squareSize = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "cameraParams", &cameraParams);
  // Invoke the target function
  ComputeCamExtrinsics(&st, images, squareSize, &cameraParams, imagePoints,
                       validIdx, camExtrinsics, cameraPoses, worldPoints, &err);
  // Marshall function outputs
  imagePoints.no_free();
  plhs[0] = emlrt_marshallOut(imagePoints);
  if (nlhs > 1) {
    validIdx.no_free();
    plhs[1] = b_emlrt_marshallOut(validIdx);
  }
  if (nlhs > 2) {
    camExtrinsics.no_free();
    plhs[2] = emlrt_marshallOut(camExtrinsics);
  }
  if (nlhs > 3) {
    cameraPoses.no_free();
    plhs[3] = emlrt_marshallOut(cameraPoses);
  }
  if (nlhs > 4) {
    worldPoints.no_free();
    plhs[4] = c_emlrt_marshallOut(worldPoints);
  }
  if (nlhs > 5) {
    plhs[5] = emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void HandeyeShah_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[3])
{
  coder::array<real_T, 3U> As;
  coder::array<real_T, 3U> Bs;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*Y)[16];
  real_T(*b_X)[16];
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  b_X = (real_T(*)[16])mxMalloc(sizeof(real_T[16]));
  Y = (real_T(*)[16])mxMalloc(sizeof(real_T[16]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  As.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "As", As);
  Bs.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Bs", Bs);
  // Invoke the target function
  HandeyeShah(&st, As, Bs, *b_X, *Y, &err);
  // Marshall function outputs
  plhs[0] = d_emlrt_marshallOut(*b_X);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(*Y);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void calibrateOneCamera_v2_api(const mxArray *const prhs[3], int32_T nlhs,
                               const mxArray *plhs[5])
{
  coder::array<real_T, 1U> errorOptimized;
  coder::array<uint8_T, 4U> images;
  coder::array<boolean_T, 1U> validIdx;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T cameraParams;
  real_T MREf;
  real_T squareSize;
  int32_T(*boardSize)[2];
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  squareSize = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateOneCamera_v2(&st, images, squareSize, *boardSize, &cameraParams,
                        errorOptimized, &MREf, validIdx, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &cameraParams);
  if (nlhs > 1) {
    errorOptimized.no_free();
    plhs[1] = emlrt_marshallOut(errorOptimized);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(MREf);
  }
  if (nlhs > 3) {
    validIdx.no_free();
    plhs[3] = b_emlrt_marshallOut(validIdx);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void computeErrors_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  coder::array<real_T, 3U> Hcam2grid;
  coder::array<real_T, 3U> Hhand2base;
  coder::array<real_T, 3U> imgPts;
  coder::array<real_T, 2U> Worldpts;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*Hbase2grid)[16];
  real_T(*Hhand2eye)[16];
  real_T(*K)[12];
  real_T(*errors)[3];
  st.tls = emlrtRootTLSGlobal;
  errors = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  Hhand2base.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Hhand2base", Hhand2base);
  Hhand2eye = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Hhand2eye");
  Hbase2grid = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Hbase2grid");
  Hcam2grid.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Hcam2grid", Hcam2grid);
  imgPts.no_free();
  b_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "imgPts", imgPts);
  Worldpts.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "Worldpts", Worldpts);
  K = d_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "K");
  // Invoke the target function
  computeErrors(&st, Hhand2base, *Hhand2eye, *Hbase2grid, Hcam2grid, imgPts,
                Worldpts, *K, *errors);
  // Marshall function outputs
  *plhs = c_emlrt_marshallOut(*errors);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void preprocessImages_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  coder::array<uint8_T, 4U> gray_images;
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct1_T cameraParams;
  boolean_T undistort;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  b_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "cameraParams", &cameraParams);
  undistort = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "undistort");
  // Invoke the target function
  preprocessImages(&st, images, &cameraParams, undistort, gray_images);
  // Marshall function outputs
  gray_images.no_free();
  *plhs = emlrt_marshallOut(gray_images);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void readRobotPoses_api(const mxArray *prhs, int32_T nlhs,
                        const mxArray *plhs[2])
{
  coder::array<real_T, 3U> extrinsics;
  coder::array<real_T, 3U> poses;
  coder::array<real_T, 3U> robotPosesVec;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  robotPosesVec.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs), "robotPosesVec", robotPosesVec);
  // Invoke the target function
  readRobotPoses(&st, robotPosesVec, poses, extrinsics);
  // Marshall function outputs
  poses.no_free();
  plhs[0] = emlrt_marshallOut(poses);
  if (nlhs > 1) {
    extrinsics.no_free();
    plhs[1] = emlrt_marshallOut(extrinsics);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_calibrateOneCamera_v2_mex_api.cpp)
