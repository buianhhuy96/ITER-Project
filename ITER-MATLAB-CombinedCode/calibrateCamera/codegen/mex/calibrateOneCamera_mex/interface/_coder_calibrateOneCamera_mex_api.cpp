//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_mex_api.cpp
//
// Code generation for function '_coder_calibrateOneCamera_mex_api'
//

// Include files
#include "_coder_calibrateOneCamera_mex_api.h"
#include "calibrateOneCamera.h"
#include "calibrateOneCamera_mex_data.h"
#include "calibrateOneCamera_mex_mexutil.h"
#include "calibrateOneCamera_mex_types.h"
#include "preprocessImages.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace Codegen {
static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2];

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2];

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               ::coder::array<uint8_T, 4U> &y);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<uint8_T, 4U> &y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<uint8_T, 4U> &ret);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static int32_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2];

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<uint8_T, 4U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             ::coder::array<uint8_T, 4U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             ::coder::array<uint8_T, 4U> &y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *squareSize,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const int32_T u);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static const mxArray *emlrt_marshallOut(const ::coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const ::coder::array<uint8_T, 4U> &u);

} // namespace Codegen

// Function Definitions
namespace Codegen {
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
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                               const char_T *identifier,
                               ::coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<uint8_T, 4U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<uint8_T, 4U> &ret)
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

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static int32_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<uint8_T, 4U> &ret)
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

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             ::coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             ::coder::array<uint8_T, 4U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
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

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u)
{
  static const int32_T b_iv[2]{1, 3};
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
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *y;
  real_T *pData;
  int32_T iv7[3];
  int32_T iv1[2];
  int32_T b_i;
  int32_T c_i;
  int32_T d_i;
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, (const char_T **)&sv[0]));
  b_y = nullptr;
  emlrtAssign(&b_y,
              emlrtCreateStructMatrix(1, 1, 14, (const char_T **)&sv1[0]));
  c_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&b_iv[0], mxDOUBLE_CLASS,
                              mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->CameraParameters.RadialDistortion[0];
  pData[1] = u->CameraParameters.RadialDistortion[1];
  pData[2] = u->CameraParameters.RadialDistortion[2];
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"RadialDistortion", c_y, 0);
  emlrtSetFieldR2017b(
      b_y, 0, (const char_T *)"TangentialDistortion",
      emlrt_marshallOut(u->CameraParameters.TangentialDistortion), 1);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"ImageSize",
                      emlrt_marshallOut(u->CameraParameters.ImageSize), 2);
  d_y = nullptr;
  iv1[0] = u->CameraParameters.WorldPoints.size(0);
  iv1[1] = 2;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->CameraParameters.WorldPoints.size(0); b_i++) {
    pData[i] = u->CameraParameters.WorldPoints[b_i];
    i++;
  }
  for (b_i = 0; b_i < u->CameraParameters.WorldPoints.size(0); b_i++) {
    pData[i] = u->CameraParameters
                   .WorldPoints[b_i + u->CameraParameters.WorldPoints.size(0)];
    i++;
  }
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"WorldPoints", d_y, 3);
  e_y = nullptr;
  iv1[0] = 1;
  iv1[1] = u->CameraParameters.WorldUnits.size[1];
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u->CameraParameters.WorldUnits.size[1],
                           m, &u->CameraParameters.WorldUnits.data[0]);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"WorldUnits", e_y, 4);
  f_y = nullptr;
  m = emlrtCreateLogicalScalar(u->CameraParameters.EstimateSkew);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"EstimateSkew", f_y, 5);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"NumRadialDistortionCoefficients",
                      coder::b_emlrt_marshallOut(
                          u->CameraParameters.NumRadialDistortionCoefficients),
                      6);
  g_y = nullptr;
  m = emlrtCreateLogicalScalar(
      u->CameraParameters.EstimateTangentialDistortion);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"EstimateTangentialDistortion",
                      g_y, 7);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"RotationVectors",
                      emlrt_marshallOut(u->CameraParameters.RotationVectors),
                      8);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"TranslationVectors",
                      emlrt_marshallOut(u->CameraParameters.TranslationVectors),
                      9);
  h_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&h_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"ReprojectionErrors", h_y, 10);
  i_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 3; b_i++) {
    pData[i] = u->CameraParameters.IntrinsicMatrix[3 * b_i];
    pData[i + 1] = u->CameraParameters.IntrinsicMatrix[3 * b_i + 1];
    pData[i + 2] = u->CameraParameters.IntrinsicMatrix[3 * b_i + 2];
    i += 3;
  }
  emlrtAssign(&i_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"IntrinsicMatrix", i_y, 11);
  j_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv4[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&j_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"DetectedKeypoints", j_y, 12);
  k_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv5[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&k_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"Version", k_y, 13);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"CameraParameters", b_y, 0);
  l_y = nullptr;
  emlrtAssign(
      &l_y,
      emlrtCreateCellArrayR2014a(
          2,
          ((::coder::array<cell_wrap_0, 2U> *)&u->PatternPositions)->size()));
  for (i = 0; i < u->PatternPositions.size(1); i++) {
    m_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv6[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    c_i = 0;
    for (b_i = 0; b_i < 4; b_i++) {
      d_i = b_i << 2;
      pData[c_i] = u->PatternPositions[i].f1[d_i];
      pData[c_i + 1] = u->PatternPositions[i].f1[d_i + 1];
      pData[c_i + 2] = u->PatternPositions[i].f1[d_i + 2];
      pData[c_i + 3] = u->PatternPositions[i].f1[d_i + 3];
      c_i += 4;
    }
    emlrtAssign(&m_y, m);
    emlrtSetCell(l_y, i, m_y);
  }
  emlrtSetFieldR2017b(y, 0, (const char_T *)"PatternPositions", l_y, 1);
  n_y = nullptr;
  iv7[0] = u->ImagePoints.size(0);
  iv7[1] = u->ImagePoints.size(1);
  iv7[2] = u->ImagePoints.size(2);
  m = emlrtCreateNumericArray(3, &iv7[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->ImagePoints.size(2); b_i++) {
    for (c_i = 0; c_i < u->ImagePoints.size(1); c_i++) {
      for (d_i = 0; d_i < u->ImagePoints.size(0); d_i++) {
        pData[i] = u->ImagePoints[(d_i + u->ImagePoints.size(0) * c_i) +
                                  u->ImagePoints.size(0) *
                                      u->ImagePoints.size(1) * b_i];
        i++;
      }
    }
  }
  emlrtAssign(&n_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImagePoints", n_y, 2);
  o_y = nullptr;
  m = emlrtCreateNumericArray(1,
                              ((::coder::array<real_T, 1U> *)&u->Error)->size(),
                              mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->Error.size(0); b_i++) {
    pData[i] = u->Error[b_i];
    i++;
  }
  emlrtAssign(&o_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Error", o_y, 3);
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

static const mxArray *emlrt_marshallOut(const ::coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_i;
  int32_T i;
  y = nullptr;
  b_iv[0] = u.size(0);
  b_iv[1] = 3;
  m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0)];
    i++;
  }
  for (b_i = 0; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0) * 2];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const ::coder::array<uint8_T, 4U> &u)
{
  static const int32_T b_iv[4]{0, 0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(4, (const void *)&b_iv[0], mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m,
                 &(((::coder::array<uint8_T, 4U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((::coder::array<uint8_T, 4U> *)&u)->size(),
                     4);
  emlrtAssign(&y, m);
  return y;
}

void calibrateOneCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                            const mxArray *plhs[3])
{
  ::coder::array<uint8_T, 4U> images;
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
  squareSize = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = b_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateOneCamera(&st, images, squareSize, *boardSize, &calibrationOptimized,
                     &calculation_err, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &calibrationOptimized);
  if (nlhs > 1) {
    plhs[1] = coder::b_emlrt_marshallOut(calculation_err);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void preprocessImages_api(const mxArray *prhs, const mxArray **plhs)
{
  ::coder::array<uint8_T, 4U> gray_images;
  ::coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  b_emlrt_marshallIn(&st, emlrtAlias(prhs), "images", images);
  // Invoke the target function
  preprocessImages(&st, images, gray_images);
  // Marshall function outputs
  gray_images.no_free();
  *plhs = emlrt_marshallOut(gray_images);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

} // namespace Codegen

// End of code generation (_coder_calibrateOneCamera_mex_api.cpp)
