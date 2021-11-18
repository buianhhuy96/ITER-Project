//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_calibrateCamera_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "_coder_calibrateCamera_api.h"
#include "_coder_calibrateCamera_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "calibrateCamera",                                    // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T *u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *squareSize,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u[3]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u[2]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *boardSize,
                                   const char_T *identifier))[2];

static const mxArray *e_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static const mxArray *
f_emlrt_marshallOut(const coder::array<cell_wrap_0, 2U> &u);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

static const mxArray *g_emlrt_marshallOut(const coder::array<real_T, 3U> &u);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static const mxArray *h_emlrt_marshallOut(const emlrtStack *sp,
                                          const rtString u);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

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
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const struct1_T *u
// Return Type  : const mxArray *
//
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const struct1_T *u)
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv2[2]{0, 0};
  static const int32_T iv3[2]{3, 3};
  static const int32_T iv4[2]{0, 0};
  static const int32_T iv6[2]{0, 0};
  static const char_T *sv[20]{"RadialDistortion",
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
                              "NumPatterns",
                              "FocalLength",
                              "PrincipalPoint",
                              "Skew",
                              "RotationMatrices",
                              "MeanReprojectionError",
                              "ReprojectedPoints"};
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
  int32_T iv5[3];
  int32_T iv1[2];
  int32_T b_i;
  int32_T d_i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 20, (const char_T **)(&sv[0])));
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RadialDistortion",
                      c_emlrt_marshallOut(u->RadialDistortion), 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TangentialDistortion",
                      d_emlrt_marshallOut(u->TangentialDistortion), 1);
  b_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImageSize", b_y, 2);
  c_y = nullptr;
  iv1[0] = u->WorldPoints.size(0);
  iv1[1] = 2;
  m = emlrtCreateNumericArray(2, &iv1[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u->WorldPoints.size(0)) {
    pData[b_i] = u->WorldPoints[d_i];
    b_i++;
    d_i++;
  }
  d_i = 0;
  while (d_i < u->WorldPoints.size(0)) {
    pData[b_i] = u->WorldPoints[d_i + u->WorldPoints.size(0)];
    b_i++;
    d_i++;
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldPoints", c_y, 3);
  d_y = nullptr;
  iv1[0] = 1;
  iv1[1] = u->WorldUnits.size[1];
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u->WorldUnits.size[1], m,
                           &u->WorldUnits.data[0]);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldUnits", d_y, 4);
  e_y = nullptr;
  m = emlrtCreateLogicalScalar(u->EstimateSkew);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateSkew", e_y, 5);
  f_y = nullptr;
  m = emlrtCreateDoubleScalar(u->NumRadialDistortionCoefficients);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"NumRadialDistortionCoefficients",
                      f_y, 6);
  g_y = nullptr;
  m = emlrtCreateLogicalScalar(u->EstimateTangentialDistortion);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateTangentialDistortion", g_y,
                      7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RotationVectors",
                      e_emlrt_marshallOut(u->RotationVectors), 8);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TranslationVectors",
                      e_emlrt_marshallOut(u->TranslationVectors), 9);
  h_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv2[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ReprojectionErrors", h_y, 10);
  i_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv3[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  for (d_i = 0; d_i < 3; d_i++) {
    pData[b_i] = u->IntrinsicMatrix[d_i][0];
    pData[b_i + 1] = u->IntrinsicMatrix[d_i][1];
    pData[b_i + 2] = u->IntrinsicMatrix[d_i][2];
    b_i += 3;
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"IntrinsicMatrix", i_y, 11);
  j_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv4[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"DetectedKeypoints", j_y, 12);
  k_y = nullptr;
  iv1[0] = u->NumPatterns.size[0];
  iv1[1] = u->NumPatterns.size[1];
  m = emlrtCreateNumericArray(2, &iv1[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u->NumPatterns.size[1]) {
    d_i = 0;
    while (d_i < u->NumPatterns.size[0]) {
      pData[b_i] = u->NumPatterns.data[0];
      b_i++;
      d_i = 1;
    }
    d_i = 1;
  }
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"NumPatterns", k_y, 13);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"FocalLength",
                      d_emlrt_marshallOut(u->FocalLength), 14);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"PrincipalPoint",
                      d_emlrt_marshallOut(u->PrincipalPoint), 15);
  m_y = nullptr;
  m = emlrtCreateDoubleScalar(u->Skew);
  emlrtAssign(&m_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Skew", m_y, 16);
  o_y = nullptr;
  iv5[0] = u->RotationMatrices.size(0);
  iv5[1] = u->RotationMatrices.size(1);
  iv5[2] = u->RotationMatrices.size(2);
  m = emlrtCreateNumericArray(3, &iv5[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u->RotationMatrices.size(2)) {
    int32_T e_i;
    e_i = 0;
    while (e_i < u->RotationMatrices.size(1)) {
      int32_T g_i;
      g_i = 0;
      while (g_i < u->RotationMatrices.size(0)) {
        pData[b_i] =
            u->RotationMatrices[(g_i + (u->RotationMatrices.size(0) * e_i)) +
                                ((u->RotationMatrices.size(0) *
                                  u->RotationMatrices.size(1)) *
                                 d_i)];
        b_i++;
        g_i++;
      }
      e_i++;
    }
    d_i++;
  }
  emlrtAssign(&o_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RotationMatrices", o_y, 17);
  p_y = nullptr;
  m = emlrtCreateDoubleScalar(u->MeanReprojectionError);
  emlrtAssign(&p_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"MeanReprojectionError", p_y, 18);
  q_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv6[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtAssign(&q_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ReprojectedPoints", q_y, 19);
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
// Arguments    : const real_T u[3]
// Return Type  : const mxArray *
//
static const mxArray *c_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[2]{1, 3};
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
  pData[2] = u[2];
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
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const real_T u[2]
// Return Type  : const mxArray *
//
static const mxArray *d_emlrt_marshallOut(const real_T u[2])
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
//                const mxArray *boardSize
//                const char_T *identifier
// Return Type  : real_T (*)[2]
//
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *boardSize,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(boardSize), &thisId);
  emlrtDestroyArray(&boardSize);
  return y;
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *e_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T d_i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = 3;
  m = emlrtCreateNumericArray(2, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u.size(0)) {
    pData[b_i] = u[d_i];
    b_i++;
    d_i++;
  }
  d_i = 0;
  while (d_i < u.size(0)) {
    pData[b_i] = u[d_i + u.size(0)];
    b_i++;
    d_i++;
  }
  d_i = 0;
  while (d_i < u.size(0)) {
    pData[b_i] = u[d_i + (u.size(0) * 2)];
    b_i++;
    d_i++;
  }
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
  static const char_T *sv[7]{"CameraParameters",
                             "PatternPositions",
                             "ImagePoints",
                             "OptimizationOptions",
                             "Jacobian",
                             "Error",
                             "CI"};
  static const char_T *sv1[3]{"CameraParameters", "PatternPositions",
                              "ImagePoints"};
  coder::array<cell_wrap_0, 2U> u_PatternPositions;
  coder::array<real_T, 3U> u_ImagePoints;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T d_i;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 7, (const char_T **)(&sv[0])));
  emlrtSetFieldR2017b(y, 0, (const char_T *)"CameraParameters",
                      b_emlrt_marshallOut(sp, &u->CameraParameters), 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"PatternPositions",
                      f_emlrt_marshallOut(u->PatternPositions), 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImagePoints",
                      g_emlrt_marshallOut(u->ImagePoints), 2);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"OptimizationOptions",
                      c_emlrt_marshallOut(u->OptimizationOptions), 3);
  b_y = nullptr;
  iv[0] = u->Jacobian.size(0);
  iv[1] = u->Jacobian.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u->Jacobian.size(1)) {
    loop_ub = 0;
    while (loop_ub < u->Jacobian.size(0)) {
      pData[b_i] = u->Jacobian[loop_ub + (u->Jacobian.size(0) * d_i)];
      b_i++;
      loop_ub++;
    }
    d_i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Jacobian", b_y, 4);
  c_y = nullptr;
  m = emlrtCreateNumericArray(
      1, ((coder::array<real_T, 1U> *)(&u->b_Error))->size(),
      static_cast<int32_T>(mxDOUBLE_CLASS), static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u->b_Error.size(0)) {
    pData[b_i] = u->b_Error[d_i];
    b_i++;
    d_i++;
  }
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Error", c_y, 5);
  d_y = nullptr;
  iv[0] = 1;
  iv[1] = 2;
  emlrtAssign(&d_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  for (b_i = 0; b_i < 2; b_i++) {
    int32_T i1;
    d_i = u->CI[b_i].PatternPositions.size(1);
    u_PatternPositions.set_size(1, u->CI[b_i].PatternPositions.size(1));
    for (i1 = 0; i1 < d_i; i1++) {
      u_PatternPositions[i1] = u->CI[b_i].PatternPositions[i1];
    }
    u_ImagePoints.set_size(u->CI[b_i].ImagePoints.size(0),
                           u->CI[b_i].ImagePoints.size(1),
                           u->CI[b_i].ImagePoints.size(2));
    d_i = u->CI[b_i].ImagePoints.size(2);
    for (i1 = 0; i1 < d_i; i1++) {
      loop_ub = u->CI[b_i].ImagePoints.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = u->CI[b_i].ImagePoints.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          u_ImagePoints[(i3 + (u_ImagePoints.size(0) * i2)) +
                        ((u_ImagePoints.size(0) * u_ImagePoints.size(1)) *
                         i1)] =
              u->CI[b_i]
                  .ImagePoints[(i3 + (u->CI[b_i].ImagePoints.size(0) * i2)) +
                               ((u->CI[b_i].ImagePoints.size(0) *
                                 u->CI[b_i].ImagePoints.size(1)) *
                                i1)];
        }
      }
    }
    e_y = nullptr;
    emlrtAssign(&e_y,
                emlrtCreateStructMatrix(1, 1, 3, (const char_T **)(&sv1[0])));
    emlrtSetFieldR2017b(e_y, 0, (const char_T *)"CameraParameters",
                        b_emlrt_marshallOut(sp, &u->CI[b_i].CameraParameters),
                        0);
    emlrtSetFieldR2017b(e_y, 0, (const char_T *)"PatternPositions",
                        f_emlrt_marshallOut(u_PatternPositions), 1);
    emlrtSetFieldR2017b(e_y, 0, (const char_T *)"ImagePoints",
                        g_emlrt_marshallOut(u_ImagePoints), 2);
    (void)emlrtSetCell(d_y, b_i, e_y);
  }
  emlrtSetFieldR2017b(y, 0, (const char_T *)"CI", d_y, 6);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[2]
//
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<cell_wrap_0, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *
f_emlrt_marshallOut(const coder::array<cell_wrap_0, 2U> &u)
{
  static const int32_T iv[2]{4, 4};
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(
                      2, ((coder::array<cell_wrap_0, 2U> *)(&u))->size()));
  b_i = 0;
  while (b_i < u.size(1)) {
    int32_T i1;
    b_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                                static_cast<int32_T>(mxDOUBLE_CLASS),
                                static_cast<int32_T>(mxREAL));
    pData = emlrtMxGetPr(m);
    i1 = 0;
    for (int32_T d_i{0}; d_i < 4; d_i++) {
      pData[i1] = u[b_i].f1[d_i][0];
      pData[i1 + 1] = u[b_i].f1[d_i][1];
      pData[i1 + 2] = u[b_i].f1[d_i][2];
      pData[i1 + 3] = u[b_i].f1[d_i][3];
      i1 += 4;
    }
    emlrtAssign(&b_y, m);
    (void)emlrtSetCell(y, b_i, b_y);
    b_i++;
  }
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
// Arguments    : const coder::array<real_T, 3U> &u
// Return Type  : const mxArray *
//
static const mxArray *g_emlrt_marshallOut(const coder::array<real_T, 3U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[3];
  int32_T b_i;
  int32_T d_i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  iv[2] = u.size(2);
  m = emlrtCreateNumericArray(3, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  d_i = 0;
  while (d_i < u.size(2)) {
    int32_T e_i;
    e_i = 0;
    while (e_i < u.size(1)) {
      int32_T g_i;
      g_i = 0;
      while (g_i < u.size(0)) {
        pData[b_i] =
            u[(g_i + (u.size(0) * e_i)) + ((u.size(0) * u.size(1)) * d_i)];
        b_i++;
        g_i++;
      }
      e_i++;
    }
    d_i++;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const rtString u
// Return Type  : const mxArray *
//
static const mxArray *h_emlrt_marshallOut(const emlrtStack *sp,
                                          const rtString u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *propValues;
  const mxArray *y;
  int32_T iv[2];
  const char_T *propClasses{"coder.internal.string"};
  const char_T *propNames{"Value"};
  y = nullptr;
  m = nullptr;
  emlrtAssign(
      &y, emlrtCreateClassInstance((const char_T *)"coder.internal.string"));
  m = nullptr;
  b_y = nullptr;
  iv[0] = 1;
  iv[1] = u.Value.size[1];
  propValues = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u.Value.size[1], propValues,
                           &u.Value.data[0]);
  emlrtAssign(&b_y, propValues);
  emlrtAssign(&m, b_y);
  propValues = m;
  (void)emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 1,
                              (const char_T **)(&propNames),
                              (const char_T **)(&propClasses), &propValues);
  emlrtAssign(&y,
              emlrtConvertInstanceToRedirectSource(
                  (emlrtCTX)sp, y, 0, (const char_T *)"coder.internal.string"));
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[2]
//
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2]{1, 2};
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void calibrateCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                         const mxArray *plhs[2])
{
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  rtString err;
  struct0_T calibrationOptimized;
  real_T(*boardSize)[2];
  real_T squareSize;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  squareSize = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateCamera(images, squareSize, *boardSize, &calibrationOptimized, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &calibrationOptimized);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(&st, err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void calibrateCamera_atexit()
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
  calibrateCamera_xil_terminate();
  calibrateCamera_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void calibrateCamera_initialize()
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
void calibrateCamera_terminate()
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
// File trailer for _coder_calibrateCamera_api.cpp
//
// [EOF]
//
