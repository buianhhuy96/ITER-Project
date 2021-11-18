//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_ITER_API_v2_api.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "_coder_ITER_API_v2_api.h"
#include "_coder_ITER_API_v2_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "ITER_API_v2",                                        // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

static const int32_T iv[3]{-1, 2, -1};

// Function Declarations
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<real_T, 3U> &y);

static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y);

static const mxArray *b_emlrt_marshallOut(const real_T u[2]);

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                                const char_T *identifier,
                                coder::array<real_T, 2U> &y);

static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret);

static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *squareSize,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u);

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<real_T, 2U> &y);

static real_T (*cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][4];

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                    const char_T *identifier))[4][3];

static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *boardSize,
                                   const char_T *identifier))[2];

static const mxArray *e_emlrt_marshallOut(const int32_T u);

static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[4][3];

static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                             const char_T *identifier,
                             coder::array<uint8_T, 4U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const struct0_T *u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static const mxArray *f_emlrt_marshallOut(const coder::array<real_T, 3U> &u);

static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *As,
                                    const char_T *identifier))[15][4][4];

static real_T (*fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[4][3];

static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *camera_params,
                               const char_T *identifier, struct1_T *y);

static const mxArray *g_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u);

static real_T (
    *gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                         const emlrtMsgIdentifier *parentId))[15][4][4];

static real_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[15][4][4];

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct1_T *y);

static const mxArray *h_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                                const char_T *identifier,
                                coder::array<uint8_T, 4U> &y);

static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static const mxArray *i_emlrt_marshallOut(const real_T u[3]);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<uint8_T, 4U> &y);

static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<boolean_T, 1U> &ret);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static const mxArray *j_emlrt_marshallOut(const real_T u[4][4]);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *valid_idx,
                                const char_T *identifier,
                                coder::array<boolean_T, 1U> &y);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static const mxArray *k_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u);

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<boolean_T, 1U> &y);

static char_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret);

static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static real_T ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[2];

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y);

static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[3]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3][3]);

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<boolean_T, 2U> &y);

static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static char_T tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y);

static boolean_T ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y);

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret);

static real_T (*w_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[4][4];

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret);

static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4][4];

static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[3][3]);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y);

static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<boolean_T, 2U> &ret);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<real_T, 3U> &y)
{
  dc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : void
//
static void ac_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<uint8_T, 4U> &y)
{
  mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[2]
// Return Type  : const mxArray *
//
static const mxArray *b_emlrt_marshallOut(const real_T u[2])
{
  static const int32_T b_iv[2]{1, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&b_iv[0]),
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
//                const mxArray *Worldpts
//                const char_T *identifier
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Worldpts,
                                const char_T *identifier,
                                coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  cb_emlrt_marshallIn(sp, emlrtAlias(Worldpts), &thisId, y);
  emlrtDestroyArray(&Worldpts);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void bc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{4, 4, -1};
  int32_T b_iv[3];
  const boolean_T bv[3]{false, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.prealloc((b_iv[0] * b_iv[1]) * b_iv[2]);
  ret.set_size(b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
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
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<real_T, 2U> &y)
{
  ec_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[4][4]
//
static real_T (*cc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
// Return Type  : real_T
//
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<real_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *d_emlrt_marshallOut(const coder::array<real_T, 1U> &u)
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
//                const mxArray *K
//                const char_T *identifier
// Return Type  : real_T (*)[4][3]
//
static real_T (*db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K,
                                    const char_T *identifier))[4][3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4][3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = eb_emlrt_marshallIn(sp, emlrtAlias(K), &thisId);
  emlrtDestroyArray(&K);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void dc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret)
{
  int32_T b_iv[3];
  const boolean_T bv[3]{true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)(&iv[0]), &bv[0], &b_iv[0]);
  ret.prealloc((b_iv[0] * b_iv[1]) * b_iv[2]);
  ret.set_size(b_iv[0], b_iv[1], b_iv[2]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2));
  emlrtDestroyArray(&src);
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
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[4][3]
//
static real_T (*eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[4][3]
{
  real_T(*y)[4][3];
  y = fc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void ec_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T b_iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1]);
  ret.set_size(b_iv[0], b_iv[1]);
  ret.set((real_T *)emlrtMxGetData(src), ret.size(0), ret.size(1));
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
  static const int32_T b_iv[2]{1, 3};
  static const int32_T iv1[2]{0, 2};
  static const int32_T iv2[2]{1, 2};
  static const int32_T iv3[2]{0, 3};
  static const int32_T iv4[2]{0, 3};
  static const int32_T iv5[2]{0, 2};
  static const int32_T iv6[2]{3, 3};
  static const int32_T iv7[2]{0, 2};
  static const int32_T iv8[2]{0, 0};
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
  const mxArray *k_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m10;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m_y;
  const mxArray *y;
  real_T *b_pData;
  real_T *pData;
  int32_T b_i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 14, (const char_T **)(&sv[0])));
  b_y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&b_iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  pData = emlrtMxGetPr(m);
  pData[0] = u->RadialDistortion[0];
  pData[1] = u->RadialDistortion[1];
  pData[2] = u->RadialDistortion[2];
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
  g_y = nullptr;
  m5 = emlrtCreateNumericArray(2, (const void *)(&iv3[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&g_y, m5);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"RotationVectors", g_y, 8);
  h_y = nullptr;
  m6 = emlrtCreateNumericArray(2, (const void *)(&iv4[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&h_y, m6);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"TranslationVectors", h_y, 9);
  i_y = nullptr;
  m7 = emlrtCreateNumericArray(2, (const void *)(&iv5[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&i_y, m7);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ReprojectionErrors", i_y, 10);
  j_y = nullptr;
  m8 = emlrtCreateNumericArray(2, (const void *)(&iv6[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  b_pData = emlrtMxGetPr(m8);
  b_i = 0;
  for (int32_T c_i{0}; c_i < 3; c_i++) {
    b_pData[b_i] = u->IntrinsicMatrix[c_i][0];
    b_pData[b_i + 1] = u->IntrinsicMatrix[c_i][1];
    b_pData[b_i + 2] = u->IntrinsicMatrix[c_i][2];
    b_i += 3;
  }
  emlrtAssign(&j_y, m8);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"IntrinsicMatrix", j_y, 11);
  k_y = nullptr;
  m9 = emlrtCreateNumericArray(2, (const void *)(&iv7[0]),
                               static_cast<int32_T>(mxDOUBLE_CLASS),
                               static_cast<int32_T>(mxREAL));
  emlrtAssign(&k_y, m9);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"DetectedKeypoints", k_y, 12);
  m_y = nullptr;
  m10 = emlrtCreateNumericArray(2, (const void *)(&iv8[0]),
                                static_cast<int32_T>(mxDOUBLE_CLASS),
                                static_cast<int32_T>(mxREAL));
  emlrtAssign(&m_y, m10);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Version", m_y, 13);
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
  y = pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const coder::array<real_T, 3U> &u
// Return Type  : const mxArray *
//
static const mxArray *f_emlrt_marshallOut(const coder::array<real_T, 3U> &u)
{
  static const int32_T b_iv[3]{0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)(&b_iv[0]),
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
//                const mxArray *As
//                const char_T *identifier
// Return Type  : real_T (*)[15][4][4]
//
static real_T (*fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *As,
                                    const char_T *identifier))[15][4][4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[15][4][4];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = gb_emlrt_marshallIn(sp, emlrtAlias(As), &thisId);
  emlrtDestroyArray(&As);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[4][3]
//
static real_T (*fc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *camera_params
//                const char_T *identifier
//                struct1_T *y
// Return Type  : void
//
static void g_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *camera_params,
                               const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(camera_params), &thisId, y);
  emlrtDestroyArray(&camera_params);
}

//
// Arguments    : const coder::array<boolean_T, 1U> &u
// Return Type  : const mxArray *
//
static const mxArray *g_emlrt_marshallOut(const coder::array<boolean_T, 1U> &u)
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
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[15][4][4]
//
static real_T (
    *gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                         const emlrtMsgIdentifier *parentId))[15][4][4]
{
  real_T(*y)[15][4][4];
  y = gc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[15][4][4]
//
static real_T (*gc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[15][4][4]
{
  static const int32_T dims[3]{4, 4, 15};
  real_T(*ret)[15][4][4];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 3U, (void *)(&dims[0]));
  ret = (real_T(*)[15][4][4])emlrtMxGetData(src);
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
  static const char_T *fieldNames[14]{"RadialDistortion",
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
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 14,
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
  thisId.fIdentifier = "WorldPoints";
  k_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b(
                         (emlrtCTX)sp, u, 0, 3, (const char_T *)"WorldPoints")),
                     &thisId, y->WorldPoints);
  thisId.fIdentifier = "WorldUnits";
  y->WorldUnits = m_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 4,
                                     (const char_T *)"WorldUnits")),
      &thisId);
  thisId.fIdentifier = "EstimateSkew";
  y->EstimateSkew = o_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 5,
                                     (const char_T *)"EstimateSkew")),
      &thisId);
  thisId.fIdentifier = "NumRadialDistortionCoefficients";
  y->NumRadialDistortionCoefficients = d_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b(
          (emlrtCTX)sp, u, 0, 6,
          (const char_T *)"NumRadialDistortionCoefficients")),
      &thisId);
  thisId.fIdentifier = "EstimateTangentialDistortion";
  y->EstimateTangentialDistortion =
      o_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 7,
                             (const char_T *)"EstimateTangentialDistortion")),
                         &thisId);
  thisId.fIdentifier = "RotationVectors";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 8,
                                     (const char_T *)"RotationVectors")),
      &thisId, y->RotationVectors);
  thisId.fIdentifier = "TranslationVectors";
  p_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 9,
                                     (const char_T *)"TranslationVectors")),
      &thisId, y->TranslationVectors);
  thisId.fIdentifier = "ReprojectionErrors";
  q_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 10,
                                     (const char_T *)"ReprojectionErrors")),
      &thisId, y->ReprojectionErrors);
  thisId.fIdentifier = "IntrinsicMatrix";
  r_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 11,
                                     (const char_T *)"IntrinsicMatrix")),
      &thisId, y->IntrinsicMatrix);
  thisId.fIdentifier = "DetectedKeypoints";
  s_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 12,
                                     (const char_T *)"DetectedKeypoints")),
      &thisId, y->DetectedKeypoints);
  thisId.fIdentifier = "Version";
  t_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 13,
                                                    (const char_T *)"Version")),
                     &thisId);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<real_T, 2U> &u
// Return Type  : const mxArray *
//
static const mxArray *h_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T b_iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&b_iv[0]),
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
//                const mxArray *images
//                const char_T *identifier
//                coder::array<uint8_T, 4U> &y
// Return Type  : void
//
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *images,
                                const char_T *identifier,
                                coder::array<uint8_T, 4U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  ib_emlrt_marshallIn(sp, emlrtAlias(images), &thisId, y);
  emlrtDestroyArray(&images);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void hc_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 3, -1};
  int32_T b_iv[4];
  const boolean_T bv[4]{true, true, true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.prealloc(((b_iv[0] * b_iv[1]) * b_iv[2]) * b_iv[3]);
  ret.set_size(b_iv[0], b_iv[1], b_iv[2], b_iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
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
  qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[3]
// Return Type  : const mxArray *
//
static const mxArray *i_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{1, 3};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&b_iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  (void)emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
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
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<uint8_T, 4U> &y)
{
  hc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<boolean_T, 1U> &ret
// Return Type  : void
//
static void ic_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<boolean_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T b_i;
  const boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                            false, 1U, (void *)(&dims), &b, &b_i);
  ret.prealloc(b_i);
  ret.set_size(b_i);
  ret.set((boolean_T *)emlrtMxGetData(src), ret.size(0));
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
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const real_T u[4][4]
// Return Type  : const mxArray *
//
static const mxArray *j_emlrt_marshallOut(const real_T u[4][4])
{
  static const int32_T b_iv[2]{0, 0};
  static const int32_T iv1[2]{4, 4};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)(&b_iv[0]),
                              static_cast<int32_T>(mxDOUBLE_CLASS),
                              static_cast<int32_T>(mxREAL));
  emlrtMxSetData((mxArray *)m, (void *)(&u[0]));
  (void)emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *valid_idx
//                const char_T *identifier
//                coder::array<boolean_T, 1U> &y
// Return Type  : void
//
static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *valid_idx,
                                const char_T *identifier,
                                coder::array<boolean_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  kb_emlrt_marshallIn(sp, emlrtAlias(valid_idx), &thisId, y);
  emlrtDestroyArray(&valid_idx);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<uint8_T, 4U> &u
// Return Type  : const mxArray *
//
static const mxArray *k_emlrt_marshallOut(const coder::array<uint8_T, 4U> &u)
{
  static const int32_T b_iv[4]{0, 0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(4, (const void *)(&b_iv[0]),
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
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<boolean_T, 1U> &y
// Return Type  : void
//
static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                coder::array<boolean_T, 1U> &y)
{
  ic_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : char_T
//
static char_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  char_T y;
  y = tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<uint8_T, 4U> &ret
// Return Type  : void
//
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<uint8_T, 4U> &ret)
{
  static const int32_T dims[4]{-1, -1, 1, -1};
  int32_T b_iv[4];
  const boolean_T bv[4]{true, true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 4U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.prealloc(((b_iv[0] * b_iv[1]) * b_iv[2]) * b_iv[3]);
  ret.set_size(b_iv[0], b_iv[1], b_iv[2], b_iv[3]);
  ret.set((uint8_T *)emlrtMxGetData(src), ret.size(0), ret.size(1), ret.size(2),
          ret.size(3));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : boolean_T
//
static boolean_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T
//
static real_T ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 2U> &y
// Return Type  : void
//
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : real_T (*)[2]
//
static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y)
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[3]
// Return Type  : void
//
static void qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                real_T y[3][3]
// Return Type  : void
//
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[3][3])
{
  xb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[2]
// Return Type  : void
//
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                coder::array<boolean_T, 2U> &y
// Return Type  : void
//
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<boolean_T, 2U> &y)
{
  yb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
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
  int32_T b_iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : void
//
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  ac_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : char_T
//
static char_T tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  char_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 0U, (void *)(&dims));
  emlrtImportCharR2015b((emlrtCTX)sp, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Hhand2base
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Hhand2base,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  v_emlrt_marshallIn(sp, emlrtAlias(Hhand2base), &thisId, y);
  emlrtDestroyArray(&Hhand2base);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : boolean_T
//
static boolean_T ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 3U> &y)
{
  bc_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 2U> &ret
// Return Type  : void
//
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 3};
  int32_T b_iv[2];
  const boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *Hhand2eye
//                const char_T *identifier
// Return Type  : real_T (*)[4][4]
//
static real_T (*w_emlrt_marshallIn(const emlrtStack *sp,
                                   const mxArray *Hhand2eye,
                                   const char_T *identifier))[4][4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4][4];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = x_emlrt_marshallIn(sp, emlrtAlias(Hhand2eye), &thisId);
  emlrtDestroyArray(&Hhand2eye);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<real_T, 3U> &ret)
{
  int32_T b_iv[3];
  const boolean_T bv[3]{true, false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 3U, (void *)(&iv[0]), &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1], b_iv[2]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 8, false);
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : real_T (*)[4][4]
//
static real_T (*x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4][4]
{
  real_T(*y)[4][4];
  y = cc_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                real_T ret[3][3]
// Return Type  : void
//
static void xb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
//                const mxArray *imgPts
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *imgPts,
                               const char_T *identifier,
                               coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  ab_emlrt_marshallIn(sp, emlrtAlias(imgPts), &thisId, y);
  emlrtDestroyArray(&imgPts);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<boolean_T, 2U> &ret
// Return Type  : void
//
static void yb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                coder::array<boolean_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, -1};
  int32_T b_iv[2];
  const boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                            false, 2U, (void *)(&dims[0]), &bv[0], &b_iv[0]);
  ret.set_size(b_iv[0], b_iv[1]);
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret[0], 1, false);
  emlrtDestroyArray(&src);
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
  coder::array<real_T, 3U> cam_extrinsics;
  coder::array<real_T, 3U> camera_poses;
  coder::array<real_T, 3U> image_points;
  coder::array<real_T, 2U> b_world_points;
  coder::array<uint8_T, 4U> images;
  coder::array<boolean_T, 1U> valid_idx;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct1_T camera_params;
  real_T b_square_size;
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  b_square_size = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "square_size");
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "camera_params",
                     &camera_params);
  // Invoke the target function
  ComputeCamExtrinsics(images, b_square_size, &camera_params, image_points,
                       valid_idx, cam_extrinsics, camera_poses, b_world_points,
                       &err);
  // Marshall function outputs
  image_points.no_free();
  plhs[0] = f_emlrt_marshallOut(image_points);
  if (nlhs > 1) {
    valid_idx.no_free();
    plhs[1] = g_emlrt_marshallOut(valid_idx);
  }
  if (nlhs > 2) {
    cam_extrinsics.no_free();
    plhs[2] = f_emlrt_marshallOut(cam_extrinsics);
  }
  if (nlhs > 3) {
    camera_poses.no_free();
    plhs[3] = f_emlrt_marshallOut(camera_poses);
  }
  if (nlhs > 4) {
    b_world_points.no_free();
    plhs[4] = h_emlrt_marshallOut(b_world_points);
  }
  if (nlhs > 5) {
    plhs[5] = e_emlrt_marshallOut(err);
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
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*As)[15][4][4];
  real_T(*Bs)[15][4][4];
  real_T(*X)[4][4];
  real_T(*o_Y)[4][4];
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  X = (real_T(*)[4][4])mxMalloc(sizeof(real_T[4][4]));
  o_Y = (real_T(*)[4][4])mxMalloc(sizeof(real_T[4][4]));
  // Marshall function inputs
  As = fb_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "As");
  Bs = fb_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Bs");
  // Invoke the target function
  HandeyeShah(*As, *Bs, *X, *o_Y, &err);
  // Marshall function outputs
  plhs[0] = j_emlrt_marshallOut(*X);
  if (nlhs > 1) {
    plhs[1] = j_emlrt_marshallOut(*o_Y);
  }
  if (nlhs > 2) {
    plhs[2] = e_emlrt_marshallOut(err);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void ITER_API_v2_atexit()
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
  ITER_API_v2_xil_terminate();
  ITER_API_v2_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void ITER_API_v2_initialize()
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
void ITER_API_v2_terminate()
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
//                const mxArray *plhs[4]
// Return Type  : void
//
void calibrateOneCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                            const mxArray *plhs[4])
{
  coder::array<real_T, 1U> errorOptimized;
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T cameraParameters;
  real_T(*boardSize)[2];
  real_T calculation_err;
  real_T squareSize;
  int32_T err;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  squareSize = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "squareSize");
  boardSize = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "boardSize");
  // Invoke the target function
  calibrateOneCamera(images, squareSize, *boardSize, &cameraParameters,
                     errorOptimized, &calculation_err, &err);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(&st, &cameraParameters);
  if (nlhs > 1) {
    errorOptimized.no_free();
    plhs[1] = d_emlrt_marshallOut(errorOptimized);
  }
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(calculation_err);
  }
  if (nlhs > 3) {
    plhs[3] = e_emlrt_marshallOut(err);
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
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Hhand2base", Hhand2base);
  Hhand2eye = w_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Hhand2eye");
  Hbase2grid = w_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Hbase2grid");
  Hcam2grid.no_free();
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Hcam2grid", Hcam2grid);
  imgPts.no_free();
  y_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "imgPts", imgPts);
  Worldpts.no_free();
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "Worldpts", Worldpts);
  K = db_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "K");
  // Invoke the target function
  computeErrors(Hhand2base, *Hhand2eye, *Hbase2grid, Hcam2grid, imgPts,
                Worldpts, *K, *errors);
  // Marshall function outputs
  *plhs = i_emlrt_marshallOut(*errors);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[2]
//                const mxArray **plhs
// Return Type  : void
//
void preprocessImages_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  coder::array<uint8_T, 4U> gray_images;
  coder::array<uint8_T, 4U> images;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct1_T camera_params;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  images.no_free();
  hb_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "images", images);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "camera_params",
                     &camera_params);
  // Invoke the target function
  preprocessImages(images, &camera_params, gray_images);
  // Marshall function outputs
  gray_images.no_free();
  *plhs = k_emlrt_marshallOut(gray_images);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : const mxArray * const prhs[2]
//                int32_T nlhs
//                const mxArray *plhs[2]
// Return Type  : void
//
void readRobotPoses_api(const mxArray *const prhs[2], int32_T nlhs,
                        const mxArray *plhs[2])
{
  coder::array<real_T, 3U> extrinsics;
  coder::array<real_T, 3U> poses;
  coder::array<real_T, 3U> robot_poses_vec;
  coder::array<boolean_T, 1U> valid_idx;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  robot_poses_vec.no_free();
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "robot_poses_vec",
                     robot_poses_vec);
  valid_idx.no_free();
  jb_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "valid_idx", valid_idx);
  // Invoke the target function
  readRobotPoses(robot_poses_vec, valid_idx, poses, extrinsics);
  // Marshall function outputs
  poses.no_free();
  plhs[0] = f_emlrt_marshallOut(poses);
  if (nlhs > 1) {
    extrinsics.no_free();
    plhs[1] = f_emlrt_marshallOut(extrinsics);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// File trailer for _coder_ITER_API_v2_api.cpp
//
// [EOF]
//
