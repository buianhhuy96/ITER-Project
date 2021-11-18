//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_calibrateOneCamera_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "_coder_calibrateOneCamera_api.h"
#include "_coder_calibrateOneCamera_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "calibrateOneCamera",                                 // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static const mxArray *b_emlrt_marshallOut(const real_T u[2]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *squareSize,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static int32_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2];

static const mxArray *e_emlrt_marshallOut(const int32_T u);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static int32_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2];

static const mxArray *f_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               coder::array<uint8_T, 4U> &y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2];

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[2]
// Return Type  : const mxArray *
//
static const mxArray *b_emlrt_marshallOut(const real_T u[2])
{
  static const int32_T iv[2]{1, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  pData[0] = u[0];
  pData[1] = u[1];
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *squareSize
//                const char_T *identifier
// Return Type  : real_T
//
static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *squareSize,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(squareSize), &thisId);
  emlrtDestroyArray(&squareSize);
  return y;
}

//
// Arguments    : const real_T u
// Return Type  : const mxArray *
//
static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T
//
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T c_i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = 3;
  m = emlrtCreateNumericArray(2, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u.size(0)) {
    pData[b_i] = u[c_i];
    b_i++;
    c_i++;
  }
  c_i = 0;
  while (c_i < u.size(0)) {
    pData[b_i] = u[c_i + u.size(0)];
    b_i++;
    c_i++;
  }
  c_i = 0;
  while (c_i < u.size(0)) {
    pData[b_i] = u[c_i + (u.size(0) * 2)];
    b_i++;
    c_i++;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *boardSize
//                const char_T *identifier
// Return Type  : int32_T (*)[2]
//
static int32_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  int32_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(boardSize), &thisId);
  emlrtDestroyArray(&boardSize);
  return y;
}

//
// Arguments    : const int32_T u
// Return Type  : const mxArray *
//
static const mxArray *e_emlrt_marshallOut(const int32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, static_cast<int32_T>(mxINT32_CLASS),
                               static_cast<int32_T>(mxREAL));
  *((int32_T *)emlrtMxGetData(m)) = u;
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *images
//                const char_T *identifier
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
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

//
// Arguments    : const emlrtStack *sp
//                const struct0_T *u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u)
{
  static const int32_T iv[2]{1, 3};
  static const int32_T iv2[2]{0, 2};
  static const int32_T iv3[2]{3, 3};
  static const int32_T iv4[2]{0, 2};
  static const int32_T iv5[2]{0, 0};
  static const int32_T iv6[2]{4, 4};
  static const char_T *sv1[14]{"RadialDistortion",
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
  static const char_T *sv[4]{"CameraParameters", "PatternPositions",
                             "ImagePoints", "Error"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *y;
  real_T *pData;
  int32_T iv7[3];
  int32_T iv1[2];
  int32_T b_i;
  int32_T c_i;
  int32_T d_i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, (const char_T **)(&sv[0])));
  b_y = nullptr;
  emlrtAssign(&b_y,
              emlrtCreateStructMatrix(1, 1, 14, (const char_T **)(&sv1[0])));
  c_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  pData[0] = u->CameraParameters.RadialDistortion[0];
  pData[1] = u->CameraParameters.RadialDistortion[1];
  pData[2] = u->CameraParameters.RadialDistortion[2];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"RadialDistortion", c_y, 0);
  emlrtSetFieldR2017b(
      b_y, 0, (const char_T *)"TangentialDistortion",
      b_emlrt_marshallOut(u->CameraParameters.TangentialDistortion), 1);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"ImageSize",
                      b_emlrt_marshallOut(u->CameraParameters.ImageSize), 2);
  d_y = nullptr;
  iv1[0] = u->CameraParameters.WorldPoints.size(0);
  iv1[1] = 2;
  m = emlrtCreateNumericArray(2, &iv1[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u->CameraParameters.WorldPoints.size(0)) {
    pData[b_i] = u->CameraParameters.WorldPoints[c_i];
    b_i++;
    c_i++;
  }
  c_i = 0;
  while (c_i < u->CameraParameters.WorldPoints.size(0)) {
    pData[b_i] =
        u->CameraParameters
            .WorldPoints[c_i + u->CameraParameters.WorldPoints.size(0)];
    b_i++;
    c_i++;
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"WorldPoints", d_y, 3);
  e_y = nullptr;
  iv1[0] = 1;
  iv1[1] = u->CameraParameters.WorldUnits.size(1);
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u->CameraParameters.WorldUnits.size(1),
                           m, &u->CameraParameters.WorldUnits[0]);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"WorldUnits", e_y, 4);
  f_y = nullptr;
  m = emlrtCreateLogicalScalar(u->CameraParameters.EstimateSkew);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"EstimateSkew", f_y, 5);
  emlrtSetFieldR2017b(
      b_y, 0, (const char_T *)"NumRadialDistortionCoefficients",
      c_emlrt_marshallOut(u->CameraParameters.NumRadialDistortionCoefficients),
      6);
  g_y = nullptr;
  m = emlrtCreateLogicalScalar(
      u->CameraParameters.EstimateTangentialDistortion);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"EstimateTangentialDistortion",
                      g_y, 7);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"RotationVectors",
                      d_emlrt_marshallOut(u->CameraParameters.RotationVectors),
                      8);
  emlrtSetFieldR2017b(
      b_y, 0, (const char_T *)"TranslationVectors",
      d_emlrt_marshallOut(u->CameraParameters.TranslationVectors), 9);
  h_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv2[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"ReprojectionErrors", h_y, 10);
  i_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv3[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  for (c_i = 0; c_i < 3; c_i++) {
    pData[b_i] = u->CameraParameters.IntrinsicMatrix[c_i][0];
    pData[b_i + 1] = u->CameraParameters.IntrinsicMatrix[c_i][1];
    pData[b_i + 2] = u->CameraParameters.IntrinsicMatrix[c_i][2];
    b_i += 3;
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"IntrinsicMatrix", i_y, 11);
  j_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv4[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"DetectedKeypoints", j_y, 12);
  k_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv5[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"Version", k_y, 13);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"CameraParameters", b_y, 0);
  m_y = nullptr;
  emlrtAssign(
      &m_y,
      emlrtCreateCellArrayR2014a(
          2,
          ((coder::array<cell_wrap_0, 2U> *)(&u->PatternPositions))->size()));
  b_i = 0;
  while (b_i < u->PatternPositions.size(1)) {
    o_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)(&iv6[0]),
                                static_cast<int32_T>(mxDOUBLE_CLASS),
                                static_cast<int32_T>(mxREAL));
    pData = emlrtMxGetPr(m);
    d_i = 0;
    for (c_i = 0; c_i < 4; c_i++) {
      pData[d_i] = u->PatternPositions[b_i].f1[c_i][0];
      pData[d_i + 1] = u->PatternPositions[b_i].f1[c_i][1];
      pData[d_i + 2] = u->PatternPositions[b_i].f1[c_i][2];
      pData[d_i + 3] = u->PatternPositions[b_i].f1[c_i][3];
      d_i += 4;
    }
    emlrtAssign(&o_y, m);
    (void)emlrtSetCell(m_y, b_i, o_y);
    b_i++;
  }
  emlrtSetFieldR2017b(y, 0, (const char_T *)"PatternPositions", m_y, 1);
  p_y = nullptr;
  iv7[0] = u->ImagePoints.size(0);
  iv7[1] = u->ImagePoints.size(1);
  iv7[2] = u->ImagePoints.size(2);
  m = emlrtCreateNumericArray(3, &iv7[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u->ImagePoints.size(2)) {
    d_i = 0;
    while (d_i < u->ImagePoints.size(1)) {
      int32_T e_i;
      e_i = 0;
      while (e_i < u->ImagePoints.size(0)) {
        pData[b_i] =
            u->ImagePoints[(e_i + (u->ImagePoints.size(0) * d_i)) +
                           ((u->ImagePoints.size(0) * u->ImagePoints.size(1)) *
                            c_i)];
        b_i++;
        e_i++;
      }
      d_i++;
    }
    c_i++;
  }
  emlrtAssign(&p_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImagePoints", p_y, 2);
  q_y = nullptr;
  m = emlrtCreateNumericArray(
      1, ((coder::array<real_T, 1U> *)(&u->b_Error))->size(),
      static_cast<int32_T>(mxDOUBLE_CLASS), static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u->b_Error.size(0)) {
    pData[b_i] = u->b_Error[c_i];
    b_i++;
    c_i++;
  }
  emlrtAssign(&q_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Error", q_y, 3);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : int32_T (*)[2]
//
static int32_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2]
{
  int32_T(*y)[2];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<uint8_T, 4U> &u
// Return Type  : const mxArray *
//
static const mxArray *f_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u)
{
  static const int32_T iv[4]{0, 0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(4, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxUINT8_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<uint8_T, 4U> *)(&u))->data())[0]);
  (void)emlrtSetDimensions((mxArray *)m,
                           ((coder::array<uint8_T, 4U> *)(&u))->size(), 4);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *images
//                const char_T *identifier
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y)
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 1, -1};
  int32_T iv[4];
  const boolean_T bv[4]{true, true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)(&dims[0]), &bv[0], &iv[0]);
  ret.prealloc(((iv[0] * iv[1]) * iv[2]) * iv[3]);
  ret.set_size(iv[0], iv[1], iv[2], iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)(&dims));
  ret = *((real_T *)emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : int32_T (*)[2]
//
static int32_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  int32_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"int32",
                          false, 2U, (void *)(&dims[0]));
  ret = (int32_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 3, -1};
  int32_T iv[4];
  const boolean_T bv[4]{true, true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)(&dims[0]), &bv[0], &iv[0]);
  ret.prealloc(((iv[0] * iv[1]) * iv[2]) * iv[3]);
  ret.set_size(iv[0], iv[1], iv[2], iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
void calibrateOneCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                            const mxArray *plhs[3])
{
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T calibrationOptimized;
  real_T calculation_err;
  real_T squareSize;
  int32_T(*boardSize)[2];
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  squareSize = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateOneCamera(images, squareSize, *boardSize, &calibrationOptimized,
                     &calculation_err, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &calibrationOptimized);
  if (nlhs > 1) {
    plhs[1] = c_emlrt_marshallOut(calculation_err);
  }
  if (nlhs > 2) {
    plhs[2] = e_emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void calibrateOneCamera_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  (void)mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  calibrateOneCamera_xil_terminate();
  calibrateOneCamera_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void calibrateOneCamera_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  (void)mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  (void)emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void calibrateOneCamera_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// Arguments    : const mxArray *prhs
//                const mxArray **plhs
// Return Type  : void
//
void preprocessImages_api(const mxArray *prhs, const mxArray **plhs)
{
  coder::array<uint8_T, 4U> gray_images;
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  g_emlrt_marshallIn(&st, emlrtAlias(prhs), "images", images);
  // Invoke the target function
  preprocessImages(images, gray_images);
  // Marshall function outputs
  gray_images.no_free();
  *plhs = f_emlrt_marshallOut(gray_images);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_calibrateOneCamera_api.cpp
//
// [EOF]
//
