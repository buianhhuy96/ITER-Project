//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_calibrateOneCamera_v2_api.cpp
//
// Code generation for function '_coder_calibrateOneCamera_v2_api'
//

// Include files
#include "_coder_calibrateOneCamera_v2_api.h"
#include "calibrateOneCamera_v2.h"
#include "calibrateOneCamera_v2_data.h"
#include "calibrateOneCamera_v2_mexutil.h"
#include "calibrateOneCamera_v2_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret);

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2];

static int32_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2];

static const mxArray *b_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static int32_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<uint8_T, 4U> &y);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *squareSize,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const int32_T u);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static const mxArray *emlrt_marshallOut(const real_T u[2]);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 1, -1};
  int32_T iv[4];
  const boolean_T bv[4]{true, true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1] * iv[2] * iv[3]);
  ret.set_size((emlrtRTEInfo *)nullptr, sp, iv[0], iv[1], iv[2], iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
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
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
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

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<uint8_T, 4U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 14, (const char_T **)&sv[0]));
  b_y = nullptr;
  iv[0] = 1;
  iv[1] = u->RadialDistortion.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
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

static const mxArray *emlrt_marshallOut(const real_T u[2])
{
  static const int32_T iv[2]{1, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u[0];
  pData[1] = u[1];
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
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

// End of code generation (_coder_calibrateOneCamera_v2_api.cpp)
