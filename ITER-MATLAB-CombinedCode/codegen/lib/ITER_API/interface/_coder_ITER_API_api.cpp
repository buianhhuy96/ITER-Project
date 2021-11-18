//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_ITER_API_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "_coder_ITER_API_api.h"
#include "_coder_ITER_API_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "ITER_API",                                           // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[4][3];

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static const mxArray *b_emlrt_marshallOut(const real_T u[2]);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                                const char_T *identifier,
                                coder::array<uint8_T, 4U> &y);

static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *squareSize,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<uint8_T, 4U> &y);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static boolean_T db_emlrt_marshallIn(const emlrtStack *sp,
                                     const mxArray *undistort,
                                     const char_T *identifier);

static int32_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                    const mxArray *boardSize,
                                    const char_T *identifier))[2];

static const mxArray *e_emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static int32_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[2];

static const mxArray *f_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u);

static real_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *cameraParams,
                               const char_T *identifier, struct1_T *y);

static const mxArray *g_emlrt_marshallOut(const int32_T u);

static int32_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId))[2];

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static const mxArray *h_emlrt_marshallOut(const coder::array<real_T, 3U> &u);

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static const mxArray *i_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static const mxArray *j_emlrt_marshallOut(const real_T u[3]);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[2]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[2]);

static const mxArray *k_emlrt_marshallOut(const real_T u[4][4]);

static boolean_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId);

static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *m_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[3][3]);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3][3]);

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y);

static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][4];

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret);

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[4][4];

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret);

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4][4];

static real_T (*tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][3];

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y);

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                   const char_T *identifier))[4][3];

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[4][3]
//
static real_T (*ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[4][3]
{
  real_T(*y)[4][3];
  y = tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

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
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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
//                const mxArray *images
//                const char_T *identifier
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                                const char_T *identifier,
                                coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  cb_emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
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
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<uint8_T, 4U> &y)
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
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
  y = fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
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
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u.size(1)) {
    int32_T d_i;
    d_i = 0;
    while (d_i < u.size(0)) {
      pData[b_i] = u[d_i + (u.size(0) * c_i)];
      b_i++;
      d_i++;
    }
    c_i++;
  }
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *undistort
//                const char_T *identifier
// Return Type  : boolean_T
//
static boolean_T db_emlrt_marshallIn(const emlrtStack *sp,
                                     const mxArray *undistort,
                                     const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = m_emlrt_marshallIn(sp, emlrtAlias(undistort), &thisId);
  emlrtDestroyArray(&undistort);
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
// Arguments    : const coder::array<real_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *e_emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T b_i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)(&b_i),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<real_T, 1U> *)(&u))->data())[0]);
  (void)emlrtSetDimensions((mxArray *)m,
                           ((coder::array<real_T, 1U> *)(&u))->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *y;
  real_T *b_pData;
  real_T *pData;
  int32_T iv[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i1;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 14, (const char_T **)(&sv[0])));
  b_y = nullptr;
  iv[0] = 1;
  iv[1] = u->RadialDistortion.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  b_i = 0;
  c_i = 0;
  while (c_i < u->RadialDistortion.size(1)) {
    pData[b_i] = u->RadialDistortion[c_i];
    b_i++;
    c_i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RadialDistortion", b_y, 0);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TangentialDistortion",
                      b_emlrt_marshallOut(u->TangentialDistortion), 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ImageSize",
                      b_emlrt_marshallOut(u->ImageSize), 2);
  c_y = nullptr;
  m1 = emlrtCreateNumericArray(2, (const void *)(&iv1[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&c_y, m1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldPoints", c_y, 3);
  d_y = nullptr;
  m2 = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 2, m2, &u->WorldUnits[0]);
  emlrtAssign(&d_y, m2);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"WorldUnits", d_y, 4);
  e_y = nullptr;
  m3 = emlrtCreateLogicalScalar(u->EstimateSkew);
  emlrtAssign(&e_y, m3);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateSkew", e_y, 5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"NumRadialDistortionCoefficients",
                      c_emlrt_marshallOut(u->NumRadialDistortionCoefficients),
                      6);
  f_y = nullptr;
  m4 = emlrtCreateLogicalScalar(u->EstimateTangentialDistortion);
  emlrtAssign(&f_y, m4);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"EstimateTangentialDistortion", f_y,
                      7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RotationVectors",
                      d_emlrt_marshallOut(u->RotationVectors), 8);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TranslationVectors",
                      d_emlrt_marshallOut(u->TranslationVectors), 9);
  g_y = nullptr;
  m5 = emlrtCreateNumericArray(2, (const void *)(&iv3[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&g_y, m5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ReprojectionErrors", g_y, 10);
  h_y = nullptr;
  m6 = emlrtCreateNumericArray(2, (const void *)(&iv4[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  b_pData = emlrtMxGetPr(m6);
  i1 = 0;
  for (int32_T d_i{0}; d_i < 3; d_i++) {
    b_pData[i1] = u->IntrinsicMatrix[d_i][0];
    b_pData[i1 + 1] = u->IntrinsicMatrix[d_i][1];
    b_pData[i1 + 2] = u->IntrinsicMatrix[d_i][2];
    i1 += 3;
  }
  emlrtAssign(&h_y, m6);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"IntrinsicMatrix", h_y, 11);
  i_y = nullptr;
  m7 = emlrtCreateNumericArray(2, (const void *)(&iv5[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&i_y, m7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"DetectedKeypoints", i_y, 12);
  j_y = nullptr;
  m8 = emlrtCreateNumericArray(2, (const void *)(&iv6[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&j_y, m8);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Version", j_y, 13);
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
  y = gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<boolean_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *f_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u)
{
  static const int32_T b_i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateLogicalArray(1, &b_i);
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<boolean_T, 1U> *)(&u))->data())[0]);
  (void)emlrtSetDimensions((mxArray *)m,
                           ((coder::array<boolean_T, 1U> *)(&u))->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *cameraParams
//                const char_T *identifier
//                struct1_T *y
// Return Type  : void
//
static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *cameraParams,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(cameraParams), &thisId, y);
  emlrtDestroyArray(&cameraParams);
}

//
// Arguments    : const int32_T u
// Return Type  : const mxArray *
//
static const mxArray *g_emlrt_marshallOut(const int32_T u)
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
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : int32_T (*)[2]
//
static int32_T (*gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                struct1_T *y
// Return Type  : void
//
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
                         (const char_T **)(&fieldNames[0]), 0U,
                         (void *)(&dims));
  thisId.fIdentifier = "RadialDistortion";
  i_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"RadialDistortion")),
      &thisId, y->RadialDistortion);
  thisId.fIdentifier = "TangentialDistortion";
  j_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"TangentialDistortion")),
      &thisId, y->TangentialDistortion);
  thisId.fIdentifier = "ImageSize";
  j_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 2, (const char_T *)"ImageSize")),
                     &thisId, y->ImageSize);
  thisId.fIdentifier = "WorldUnits";
  k_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 3, (const char_T *)"WorldUnits")),
                     &thisId, y->WorldUnits);
  thisId.fIdentifier = "EstimateSkew";
  y->EstimateSkew = m_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"EstimateSkew")),
      &thisId);
  thisId.fIdentifier = "NumRadialDistortionCoefficients";
  y->NumRadialDistortionCoefficients = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b(
          (emlrtCTX)sp, u, 0, 5,
          (const char_T *)"NumRadialDistortionCoefficients")),
      &thisId);
  thisId.fIdentifier = "EstimateTangentialDistortion";
  y->EstimateTangentialDistortion =
      m_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 6,
                             (const char_T *)"EstimateTangentialDistortion")),
                         &thisId);
  thisId.fIdentifier = "IntrinsicMatrix";
  o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 7,
                                     (const char_T *)"IntrinsicMatrix")),
      &thisId, y->IntrinsicMatrix);
  thisId.fIdentifier = "Version";
  p_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                                    (const char_T *)"Version")),
                     &thisId);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<real_T, 3U> &u
// Return Type  : const mxArray *
//
static const mxArray *h_emlrt_marshallOut(const coder::array<real_T, 3U> &u)
{
  static const int32_T iv[3]{0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<real_T, 3U> *)(&u))->data())[0]);
  (void)emlrtSetDimensions((mxArray *)m,
                           ((coder::array<real_T, 3U> *)(&u))->size(), 3);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[3]
// Return Type  : void
//
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2]{1, 3};
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                real_T y[3]
// Return Type  : void
//
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *i_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m,
                 &(((coder::array<real_T, 2U> *)(&u))->data())[0]);
  (void)emlrtSetDimensions((mxArray *)m,
                           ((coder::array<real_T, 2U> *)(&u))->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[2]
// Return Type  : void
//
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                real_T y[2]
// Return Type  : void
//
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[3]
// Return Type  : const mxArray *
//
static const mxArray *j_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{1, 3};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  (void)emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                char_T ret[2]
// Return Type  : void
//
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)(&dims[0]));
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 2);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                char_T y[2]
// Return Type  : void
//
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[2])
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[4][4]
// Return Type  : const mxArray *
//
static const mxArray *k_emlrt_marshallOut(const real_T u[4][4])
{
  static const int32_T iv[2]{0, 0};
  static const int32_T iv1[2]{4, 4};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  (void)emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : boolean_T
//
static boolean_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 0U, (void *)(&dims));
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : boolean_T
//
static boolean_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<uint8_T, 4U> &u
// Return Type  : const mxArray *
//
static const mxArray *m_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u)
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
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[3][3]
// Return Type  : void
//
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[3][3])
{
  static const int32_T dims[2]{3, 3};
  real_T(*r)[3][3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  r = (real_T(*)[3][3])emlrtMxGetData(src);
  for (int32_T b_i{0}; b_i < 3; b_i++) {
    ret[b_i][0] = (*r)[b_i][0];
    ret[b_i][1] = (*r)[b_i][1];
    ret[b_i][2] = (*r)[b_i][2];
  }
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                real_T y[3][3]
// Return Type  : void
//
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3][3])
{
  mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : void
//
static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2]{0, 0};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  (void)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : void
//
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{4, 4, -1};
  int32_T iv[3];
  const boolean_T bv[3]{false, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)(&dims[0]), &bv[0], &iv[0]);
  ret.prealloc((iv[0] * iv[1]) * iv[2]);
  ret.set_size(iv[0], iv[1], iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Hhand2base
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(Hhand2base), &thisId, y);
  emlrtDestroyArray(&Hhand2base);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[4][4]
//
static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][4]
{
  static const int32_T dims[2]{4, 4};
  real_T(*ret)[4][4];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  ret = (real_T(*)[4][4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y)
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, 2, -1};
  int32_T iv[3];
  const boolean_T bv[3]{true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)(&dims[0]), &bv[0], &iv[0]);
  ret.prealloc((iv[0] * iv[1]) * iv[2]);
  ret.set_size(iv[0], iv[1], iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Hhand2eye
//                const char_T *identifier
// Return Type  : real_T (*)[4][4]
//
static real_T (*s_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[4][4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4][4];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = t_emlrt_marshallIn(sp, emlrtAlias(Hhand2eye), &thisId);
  emlrtDestroyArray(&Hhand2eye);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)(&dims[0]), &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(iv[0], iv[1]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[4][4]
//
static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4][4]
{
  real_T(*y)[4][4];
  y = qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[4][3]
//
static real_T (*tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][3]
{
  static const int32_T dims[2]{3, 4};
  real_T(*ret)[4][3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)(&dims[0]));
  ret = (real_T(*)[4][3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *imgPts
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  v_emlrt_marshallIn(sp, emlrtAlias(imgPts), &thisId, y);
  emlrtDestroyArray(&imgPts);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y)
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Worldpts
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  x_emlrt_marshallIn(sp, emlrtAlias(Worldpts), &thisId, y);
  emlrtDestroyArray(&Worldpts);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *K
//                const char_T *identifier
// Return Type  : real_T (*)[4][3]
//
static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                   const char_T *identifier))[4][3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4][3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = ab_emlrt_marshallIn(sp, emlrtAlias(K), &thisId);
  emlrtDestroyArray(&K);
  return y;
}

//
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[6]
// Return Type  : void
//
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
  squareSize = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "cameraParams", &cameraParams);
  // Invoke the target function
  ComputeCamExtrinsics(images, squareSize, &cameraParams, imagePoints, validIdx,
                       camExtrinsics, cameraPoses, worldPoints, &err);
  // Marshall function outputs
  imagePoints.no_free();
  plhs[0] = h_emlrt_marshallOut(imagePoints);
  if (nlhs > 1) {
    validIdx.no_free();
    plhs[1] = f_emlrt_marshallOut(validIdx);
  }
  if (nlhs > 2) {
    camExtrinsics.no_free();
    plhs[2] = h_emlrt_marshallOut(camExtrinsics);
  }
  if (nlhs > 3) {
    cameraPoses.no_free();
    plhs[3] = h_emlrt_marshallOut(cameraPoses);
  }
  if (nlhs > 4) {
    worldPoints.no_free();
    plhs[4] = i_emlrt_marshallOut(worldPoints);
  }
  if (nlhs > 5) {
    plhs[5] = g_emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[3]
// Return Type  : void
//
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
  real_T(*X)[4][4];
  real_T(*k_Y)[4][4];
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  X = (real_T(*)[4][4])mxMalloc(sizeof(real_T[4][4]));
  k_Y = (real_T(*)[4][4])mxMalloc(sizeof(real_T[4][4]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  As.no_free();
  q_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "As", As);
  Bs.no_free();
  q_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Bs", Bs);
  // Invoke the target function
  HandeyeShah(As, Bs, *X, *k_Y, &err);
  // Marshall function outputs
  plhs[0] = k_emlrt_marshallOut(*X);
  if (nlhs > 1) {
    plhs[1] = k_emlrt_marshallOut(*k_Y);
  }
  if (nlhs > 2) {
    plhs[2] = g_emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void ITER_API_atexit()
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
  ITER_API_xil_terminate();
  ITER_API_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void ITER_API_initialize()
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
void ITER_API_terminate()
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
// Arguments    : const mxArray * const prhs[3]
//                int32_T nlhs
//                const mxArray *plhs[5]
// Return Type  : void
//
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
  squareSize = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateOneCamera_v2(images, squareSize, *boardSize, &cameraParams,
                        errorOptimized, &MREf, validIdx, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &cameraParams);
  if (nlhs > 1) {
    errorOptimized.no_free();
    plhs[1] = e_emlrt_marshallOut(errorOptimized);
  }
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(MREf);
  }
  if (nlhs > 3) {
    validIdx.no_free();
    plhs[3] = f_emlrt_marshallOut(validIdx);
  }
  if (nlhs > 4) {
    plhs[4] = g_emlrt_marshallOut(err);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[7]
//                const mxArray **plhs
// Return Type  : void
//
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
  real_T(*Hbase2grid)[4][4];
  real_T(*Hhand2eye)[4][4];
  real_T(*K)[4][3];
  real_T(*errors)[3];
  st.tls = emlrtRootTLSGlobal;
  errors = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  Hhand2base.no_free();
  q_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Hhand2base", Hhand2base);
  Hhand2eye = s_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Hhand2eye");
  Hbase2grid = s_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Hbase2grid");
  Hcam2grid.no_free();
  q_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Hcam2grid", Hcam2grid);
  imgPts.no_free();
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "imgPts", imgPts);
  Worldpts.no_free();
  w_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "Worldpts", Worldpts);
  K = y_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "K");
  // Invoke the target function
  computeErrors(Hhand2base, *Hhand2eye, *Hbase2grid, Hcam2grid, imgPts,
                Worldpts, *K, *errors);
  // Marshall function outputs
  *plhs = j_emlrt_marshallOut(*errors);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[3]
//                const mxArray **plhs
// Return Type  : void
//
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
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "cameraParams", &cameraParams);
  undistort = db_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "undistort");
  // Invoke the target function
  preprocessImages(images, &cameraParams, undistort, gray_images);
  // Marshall function outputs
  gray_images.no_free();
  *plhs = m_emlrt_marshallOut(gray_images);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray *prhs
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
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
  q_emlrt_marshallIn(&st, emlrtAlias(prhs), "robotPosesVec", robotPosesVec);
  // Invoke the target function
  readRobotPoses(robotPosesVec, poses, extrinsics);
  // Marshall function outputs
  poses.no_free();
  plhs[0] = h_emlrt_marshallOut(poses);
  if (nlhs > 1) {
    extrinsics.no_free();
    plhs[1] = h_emlrt_marshallOut(extrinsics);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_ITER_API_api.cpp
//
// [EOF]
//
