//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics_mex_data.cpp
//
// Code generation for function 'ComputeCamExtrinsics_mex_data'
//

// Include files
#include "ComputeCamExtrinsics_mex_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                               // bFirstTime
    false,                                              // bInitialized
    131611U,                                            // fVersionInfo
    nullptr,                                            // fErrorFunction
    "ComputeCamExtrinsics_mex",                         // fFunctionName
    nullptr,                                            // fRTCallStack
    false,                                              // bDebugMode
    {484843642U, 120961338U, 3062646369U, 3495121251U}, // fSigWrd
    nullptr                                             // fSigMem
};

emlrtRSInfo f_emlrtRSI{
    209,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo g_emlrtRSI{
    281,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo h_emlrtRSI{
    291,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo i_emlrtRSI{
    301,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo j_emlrtRSI{
    6,                             // lineNo
    "HandleCodegen/HandleCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "enforcescalar\\HandleCodegen.m" // pathName
};

emlrtRSInfo l_emlrtRSI{
    346,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo m_emlrtRSI{
    352,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo n_emlrtRSI{
    357,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo o_emlrtRSI{
    360,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo p_emlrtRSI{
    362,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo q_emlrtRSI{
    367,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo r_emlrtRSI{
    372,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo s_emlrtRSI{
    392,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo t_emlrtRSI{
    413,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo v_emlrtRSI{
    76,                   // lineNo
    "validateattributes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" // pathName
};

emlrtRSInfo y_emlrtRSI{
    425,                                  // lineNo
    "CameraParametersImpl/set.ImageSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo ib_emlrtRSI{
    43,                                  // lineNo
    "ImageTransformer/ImageTransformer", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

emlrtRSInfo sb_emlrtRSI{
    44,              // lineNo
    "validateImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateImage.m" // pathName
};

emlrtRSInfo tb_emlrtRSI{
    51,              // lineNo
    "localValidate", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "inputValidation\\validateImage.m" // pathName
};

emlrtRSInfo wb_emlrtRSI{
    8,                    // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo xb_emlrtRSI{
    11,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo yb_emlrtRSI{
    12,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo ac_emlrtRSI{
    20,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo bc_emlrtRSI{
    37,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo cc_emlrtRSI{
    38,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo dc_emlrtRSI{
    42,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo ec_emlrtRSI{
    43,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo fc_emlrtRSI{
    44,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo gc_emlrtRSI{
    45,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo hc_emlrtRSI{
    47,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo ic_emlrtRSI{
    48,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo jc_emlrtRSI{
    49,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo kc_emlrtRSI{
    21,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo lc_emlrtRSI{
    39,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo mc_emlrtRSI{
    8,                         // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo nc_emlrtRSI{
    13,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo oc_emlrtRSI{
    14,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo pc_emlrtRSI{
    17,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo qc_emlrtRSI{
    34,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo rc_emlrtRSI{
    35,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo sc_emlrtRSI{
    40,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo tc_emlrtRSI{
    42,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo uc_emlrtRSI{
    106,        // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo vc_emlrtRSI{
    110,        // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo bd_emlrtRSI{
    28,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

emlrtRSInfo ed_emlrtRSI{
    21,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" // pathName
};

emlrtRSInfo fd_emlrtRSI{
    928,                 // lineNo
    "filterPartOrWhole", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo gd_emlrtRSI{
    1002,           // lineNo
    "imfiltercore", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo ld_emlrtRSI{
    58,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo md_emlrtRSI{
    59,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo nd_emlrtRSI{
    64,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo od_emlrtRSI{
    65,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo pd_emlrtRSI{
    66,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo
    qd_emlrtRSI{
        71,      // lineNo
        "power", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

emlrtRSInfo sd_emlrtRSI{
    66,      // lineNo
    "ixfun", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

emlrtRSInfo td_emlrtRSI{
    45,                          // lineNo
    "applyBinaryScalarFunction", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

emlrtRSInfo ud_emlrtRSI{
    66,                          // lineNo
    "applyBinaryScalarFunction", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

emlrtRSInfo vd_emlrtRSI{
    17,             // lineNo
    "scalexpAlloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc."
    "m" // pathName
};

emlrtRSInfo wd_emlrtRSI{
    20,                    // lineNo
    "scalexpAllocNoCheck", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\scalexpAllocNoCheck.m" // pathName
};

emlrtRSInfo xd_emlrtRSI{
    129,        // lineNo
    "flatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

emlrtRSInfo
    ae_emlrtRSI{
        103,                  // lineNo
        "flatVectorAllOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

emlrtRSInfo ke_emlrtRSI{
    15,    // lineNo
    "max", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

emlrtRSInfo
    le_emlrtRSI{
        44,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

emlrtRSInfo
    me_emlrtRSI{
        79,        // lineNo
        "maximum", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

emlrtRSInfo ne_emlrtRSI{
    186,             // lineNo
    "unaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

emlrtRSInfo oe_emlrtRSI{
    897,                    // lineNo
    "maxRealVectorOmitNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

emlrtRSInfo pe_emlrtRSI{
    54,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo qe_emlrtRSI{
    62,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo re_emlrtRSI{
    103,         // lineNo
    "findFirst", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo se_emlrtRSI{
    120,                        // lineNo
    "minOrMaxRealVectorKernel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo
    te_emlrtRSI{
        46,    // lineNo
        "eps", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m" // pathName
    };

emlrtRSInfo nf_emlrtRSI{
    39,     // lineNo
    "find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo of_emlrtRSI{
    144,        // lineNo
    "eml_find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo qf_emlrtRSI{
    382,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo rf_emlrtRSI{
    402,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo vf_emlrtRSI{
    16,        // lineNo
    "sub2ind", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m" // pathName
};

emlrtRSInfo kg_emlrtRSI{
    27,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pathName
};

emlrtRSInfo mi_emlrtRSI{
    66,       // lineNo
    "bsxfun", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pathName
};

emlrtRSInfo ni_emlrtRSI{
    98,                          // lineNo
    "applyBinaryScalarFunction", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pathName
};

emlrtRSInfo oi_emlrtRSI{
    108,                         // lineNo
    "applyBinaryScalarFunction", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pathName
};

emlrtRSInfo
    ui_emlrtRSI{
        90,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

emlrtRSInfo
    vi_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

emlrtRSInfo wi_emlrtRSI{
    142,      // lineNo
    "mtimes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

emlrtRSInfo xi_emlrtRSI{
    178,           // lineNo
    "mtimes_blas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

emlrtRSInfo
    fj_emlrtRSI{
        143,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

emlrtRSInfo
    gj_emlrtRSI{
        13,    // lineNo
        "all", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m" // pathName
    };

emlrtRSInfo nl_emlrtRSI{
    49,     // lineNo
    "mean", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" // pathName
};

emlrtRSInfo ol_emlrtRSI{
    74,                      // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

emlrtRSInfo ql_emlrtRSI{
    22,                    // lineNo
    "sumMatrixIncludeNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo rl_emlrtRSI{
    42,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo tl_emlrtRSI{
    57,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo bm_emlrtRSI{
    15,    // lineNo
    "nnz", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\sparfun\\nnz.m" // pathName
};

emlrtRSInfo im_emlrtRSI{
    61,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo km_emlrtRSI{
    85,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo lm_emlrtRSI{
    63,       // lineNo
    "xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo nm_emlrtRSI{
    138,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo pm_emlrtRSI{
    143,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo qm_emlrtRSI{
    148,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo rm_emlrtRSI{
    151,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo wm_emlrtRSI{
    23,       // lineNo
    "ixamax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\ixamax.m" // pathName
};

emlrtRSInfo xm_emlrtRSI{
    24,       // lineNo
    "ixamax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\ixamax.m" // pathName
};

emlrtRSInfo
    bn_emlrtRSI{
        45,     // lineNo
        "xger", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" // pathName
    };

emlrtRSInfo cn_emlrtRSI{
    15,     // lineNo
    "xger", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" // pathName
};

emlrtRSInfo dn_emlrtRSI{
    41,      // lineNo
    "xgerx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" // pathName
};

emlrtRSInfo en_emlrtRSI{
    54,      // lineNo
    "xgerx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" // pathName
};

emlrtRSInfo ko_emlrtRSI{
    145,       // lineNo
    "sortIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo
    lo_emlrtRSI{
        52,          // lineNo
        "mergesort", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pathName
    };

emlrtRSInfo
    mo_emlrtRSI{
        57,          // lineNo
        "mergesort", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pathName
    };

emlrtRSInfo
    no_emlrtRSI{
        113,         // lineNo
        "mergesort", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pathName
    };

emlrtRSInfo po_emlrtRSI{
    40,       // lineNo
    "safeEq", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\safeEq.m" // pathName
};

emlrtRSInfo
    to_emlrtRSI{
        117,     // lineNo
        "colon", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

emlrtRSInfo wo_emlrtRSI{
    26,    // lineNo
    "cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

emlrtRSInfo xo_emlrtRSI{
    100,        // lineNo
    "cat_impl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

emlrtRSInfo bp_emlrtRSI{
    20,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

emlrtRSInfo cp_emlrtRSI{
    99,        // lineNo
    "sumprod", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" // pathName
};

emlrtRSInfo fr_emlrtRSI{
    107,                // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

emlrtRSInfo
    os_emlrtRSI{
        136,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

emlrtRSInfo ju_emlrtRSI{
    36,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtRSInfo ku_emlrtRSI{
    44,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo lu_emlrtRSI{
    73,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo mu_emlrtRSI{
    81,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo nu_emlrtRSI{
    99,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo ou_emlrtRSI{
    209,      // lineNo
    "xgesdd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" // pathName
};

emlrtRSInfo pu_emlrtRSI{
    31,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

emlrtRSInfo ru_emlrtRSI{
    197,            // lineNo
    "ceval_xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

emlrtRSInfo cy_emlrtRSI{
    14,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtRSInfo fy_emlrtRSI{
    29,             // lineNo
    "anyNonFinite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite."
    "m" // pathName
};

emlrtRSInfo
    gy_emlrtRSI{
        44,          // lineNo
        "vAllOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

emlrtRSInfo iy_emlrtRSI{
    20,         // lineNo
    "mldivide", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

emlrtRSInfo ky_emlrtRSI{
    44,      // lineNo
    "mldiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" // pathName
};

emlrtRSInfo sy_emlrtRSI{
    30,       // lineNo
    "xgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" // pathName
};

emlrtRSInfo vy_emlrtRSI{
    36,        // lineNo
    "xzgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" // pathName
};

emlrtRSInfo wy_emlrtRSI{
    50,        // lineNo
    "xzgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" // pathName
};

emlrtRSInfo xy_emlrtRSI{
    58,        // lineNo
    "xzgetrf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" // pathName
};

emlrtRSInfo yy_emlrtRSI{
    45,      // lineNo
    "xgeru", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" // pathName
};

emlrtRSInfo gab_emlrtRSI{
    72,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo hab_emlrtRSI{
    173,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo iab_emlrtRSI{
    172,          // lineNo
    "rankFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo sab_emlrtRSI{
    42,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtMCInfo c_emlrtMCI{
    53,        // lineNo
    19,        // colNo
    "flt2str", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" // pName
};

emlrtRTEInfo b_emlrtRTEI{
    284,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo c_emlrtRTEI{
    290,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo d_emlrtRTEI{
    294,                                         // lineNo
    13,                                          // colNo
    "CameraParametersImpl/CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo e_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" // pName
};

emlrtRTEInfo f_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" // pName
};

emlrtRTEInfo g_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" // pName
};

emlrtECInfo d_emlrtECI{
    2,                         // nDims
    30,                        // lineNo
    12,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo e_emlrtECI{
    2,                         // nDims
    31,                        // lineNo
    13,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo f_emlrtECI{
    2,                         // nDims
    37,                        // lineNo
    15,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo g_emlrtECI{
    2,                         // nDims
    40,                        // lineNo
    47,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo h_emlrtECI{
    2,                         // nDims
    40,                        // lineNo
    11,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo i_emlrtECI{
    2,                         // nDims
    42,                        // lineNo
    51,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo j_emlrtECI{
    2,                         // nDims
    42,                        // lineNo
    11,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo k_emlrtECI{
    2,                        // nDims
    60,                       // lineNo
    7,                        // colNo
    "computeJacobianEntries", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo j_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonempty.m" // pName
};

emlrtBCInfo m_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    41,                        // lineNo
    5,                         // colNo
    "",                        // aName
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m", // pName
    0                                                        // checkKind
};

emlrtBCInfo n_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    43,                        // lineNo
    5,                         // colNo
    "",                        // aName
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m", // pName
    0                                                        // checkKind
};

emlrtBCInfo o_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    20,                   // lineNo
    15,                   // colNo
    "",                   // aName
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

emlrtBCInfo p_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    38,                   // lineNo
    20,                   // colNo
    "",                   // aName
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

emlrtRTEInfo l_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatenonnan", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" // pName
};

emlrtDCInfo c_emlrtDCI{
    31,       // lineNo
    14,       // colNo
    "repmat", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", // pName
    4 // checkKind
};

emlrtRTEInfo p_emlrtRTEI{
    64,                   // lineNo
    15,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

emlrtRTEInfo s_emlrtRTEI{
    130,             // lineNo
    27,              // colNo
    "unaryMinOrMax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pName
};

emlrtRTEInfo u_emlrtRTEI{
    13,               // lineNo
    13,               // colNo
    "toLogicalCheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\toLogicalCheck.m" // pName
};

emlrtRTEInfo v_emlrtRTEI{
    392,                  // lineNo
    1,                    // colNo
    "find_first_indices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo ab_emlrtRTEI{
    13,     // lineNo
    9,      // colNo
    "sqrt", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" // pName
};

emlrtRTEInfo bb_emlrtRTEI{
    53,       // lineNo
    15,       // colNo
    "bsxfun", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pName
};

emlrtRTEInfo
    db_emlrtRTEI{
        129,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

emlrtRTEInfo
    eb_emlrtRTEI{
        134,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

emlrtRTEInfo kb_emlrtRTEI{
    44,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

emlrtRTEInfo lb_emlrtRTEI{
    47,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

emlrtRTEInfo mb_emlrtRTEI{
    275,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

emlrtRTEInfo tb_emlrtRTEI{
    52,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo ub_emlrtRTEI{
    59,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo yb_emlrtRTEI{
    103,          // lineNo
    5,            // colNo
    "callLAPACK", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

emlrtRTEInfo qc_emlrtRTEI{
    365,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo rc_emlrtRTEI{
    370,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo sc_emlrtRTEI{
    375,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo tc_emlrtRTEI{
    400,                    // lineNo
    13,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo uc_emlrtRTEI{
    410,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo vc_emlrtRTEI{
    408,                    // lineNo
    17,                     // colNo
    "CameraParametersImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pName
};

emlrtRTEInfo qd_emlrtRTEI{
    8,                         // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo rd_emlrtRTEI{
    13,                        // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo sd_emlrtRTEI{
    17,                        // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo td_emlrtRTEI{
    30,                        // lineNo
    12,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo ud_emlrtRTEI{
    30,                        // lineNo
    26,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo vd_emlrtRTEI{
    30,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo wd_emlrtRTEI{
    31,                        // lineNo
    30,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo xd_emlrtRTEI{
    34,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo yd_emlrtRTEI{
    35,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo ae_emlrtRTEI{
    31,                        // lineNo
    13,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo be_emlrtRTEI{
    40,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo ce_emlrtRTEI{
    8,                    // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo de_emlrtRTEI{
    20,                   // lineNo
    34,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ee_emlrtRTEI{
    20,                   // lineNo
    49,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo fe_emlrtRTEI{
    20,                   // lineNo
    15,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ge_emlrtRTEI{
    20,                   // lineNo
    11,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo he_emlrtRTEI{
    23,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ie_emlrtRTEI{
    38,                   // lineNo
    39,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo je_emlrtRTEI{
    38,                   // lineNo
    55,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ke_emlrtRTEI{
    38,                   // lineNo
    20,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo le_emlrtRTEI{
    38,                   // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo me_emlrtRTEI{
    42,                   // lineNo
    17,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ne_emlrtRTEI{
    42,                   // lineNo
    43,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo oe_emlrtRTEI{
    16,      // lineNo
    13,      // colNo
    "isnan", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\isnan.m" // pName
};

emlrtRTEInfo pe_emlrtRTEI{
    1024,       // lineNo
    26,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

emlrtRTEInfo te_emlrtRTEI{
    129,                         // lineNo
    6,                           // colNo
    "applyBinaryScalarFunction", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pName
};

emlrtRTEInfo df_emlrtRTEI{
    369,    // lineNo
    24,     // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo hf_emlrtRTEI{
    27,     // lineNo
    6,      // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pName
};

emlrtRTEInfo kf_emlrtRTEI{
    25,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo lf_emlrtRTEI{
    26,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo mf_emlrtRTEI{
    27,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo nf_emlrtRTEI{
    28,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo of_emlrtRTEI{
    29,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo pf_emlrtRTEI{
    30,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo xf_emlrtRTEI{
    60,       // lineNo
    20,       // colNo
    "bsxfun", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pName
};

emlrtRTEInfo ch_emlrtRTEI{
    218,      // lineNo
    20,       // colNo
    "mtimes", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pName
};

emlrtRTEInfo
    dh_emlrtRTEI{
        90,                  // lineNo
        5,                   // colNo
        "eml_mtimes_helper", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

emlrtRTEInfo
    tj_emlrtRTEI{
        28,      // lineNo
        9,       // colNo
        "colon", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

emlrtRTEInfo
    uk_emlrtRTEI{
        52,          // lineNo
        9,           // colNo
        "mergesort", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pName
    };

emlrtRTEInfo il_emlrtRTEI{
    39,     // lineNo
    5,      // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo tn_emlrtRTEI{
    364,    // lineNo
    24,     // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo pr_emlrtRTEI{
    92,       // lineNo
    22,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

emlrtRTEInfo qr_emlrtRTEI{
    97,       // lineNo
    5,        // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

emlrtRTEInfo
    vr_emlrtRTEI{
        31,            // lineNo
        30,            // colNo
        "unsafeSxfun", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" // pName
    };

const real_T dv[841]{
    4.762497578988648E-8,   1.1073138628049746E-7,  2.418595836966E-7,
    4.9626364363668783E-7,  9.5657320969368355E-7,  1.7321303136116663E-6,
    2.9464529177220853E-6,  4.70841835601366E-6,    7.0681731091607814E-6,
    9.96772173790034E-6,    1.320508583762077E-5,   1.643399484969634E-5,
    1.9213286523034621E-5,  2.1101667084725539E-5,  2.1771505901906385E-5,
    2.1101667084725539E-5,  1.9213286523034621E-5,  1.643399484969634E-5,
    1.320508583762077E-5,   9.96772173790034E-6,    7.0681731091607814E-6,
    4.70841835601366E-6,    2.9464529177220853E-6,  1.7321303136116663E-6,
    9.5657320969368355E-7,  4.9626364363668783E-7,  2.418595836966E-7,
    1.1073138628049746E-7,  4.762497578988648E-8,   1.1073138628049746E-7,
    2.5745818668121091E-7,  5.6234038010021961E-7,  1.15384754131824E-6,
    2.2240993476926882E-6,  4.02732363982478E-6,    6.8507082844306217E-6,
    1.0947400667459241E-5,  1.643399484969634E-5,   2.317564739487682E-5,
    3.0702744442407152E-5,  3.8210182822179428E-5,  4.4672229568919093E-5,
    4.9062845919963714E-5,  5.0620267831066813E-5,  4.9062845919963714E-5,
    4.4672229568919093E-5,  3.8210182822179428E-5,  3.0702744442407152E-5,
    2.317564739487682E-5,   1.643399484969634E-5,   1.0947400667459241E-5,
    6.8507082844306217E-6,  4.02732363982478E-6,    2.2240993476926882E-6,
    1.15384754131824E-6,    5.6234038010021961E-7,  2.5745818668121091E-7,
    1.1073138628049746E-7,  2.418595836966E-7,      5.6234038010021961E-7,
    1.2282643141692625E-6,  2.5202347353049072E-6,  4.8578795985648562E-6,
    8.79648355952219E-6,    1.4963322589514633E-5,  2.3911321414187913E-5,
    3.5895144875646433E-5,  5.0620267831066813E-5,  6.70609593053704E-5,
    8.3458712301617293E-5,  9.75731200453745E-5,    0.00010716310783930649,
    0.00011056483004031986, 0.00010716310783930649, 9.75731200453745E-5,
    8.3458712301617293E-5,  6.70609593053704E-5,    5.0620267831066813E-5,
    3.5895144875646433E-5,  2.3911321414187913E-5,  1.4963322589514633E-5,
    8.79648355952219E-6,    4.8578795985648562E-6,  2.5202347353049072E-6,
    1.2282643141692625E-6,  5.6234038010021961E-7,  2.418595836966E-7,
    4.9626364363668783E-7,  1.15384754131824E-6,    2.5202347353049072E-6,
    5.1711859147624051E-6,  9.96772173790034E-6,    1.8049212339316831E-5,
    3.0702744442407152E-5,  4.9062845919963714E-5,  7.3652055099876124E-5,
    0.00010386604562762829, 0.00013760015419691886, 0.00017124615872978079,
    0.00020020704300665763, 0.00021988442031918191, 0.00022686430107607769,
    0.00021988442031918191, 0.00020020704300665763, 0.00017124615872978079,
    0.00013760015419691886, 0.00010386604562762829, 7.3652055099876124E-5,
    4.9062845919963714E-5,  3.0702744442407152E-5,  1.8049212339316831E-5,
    9.96772173790034E-6,    5.1711859147624051E-6,  2.5202347353049072E-6,
    1.15384754131824E-6,    4.9626364363668783E-7,  9.5657320969368355E-7,
    2.2240993476926882E-6,  4.8578795985648562E-6,  9.96772173790034E-6,
    1.9213286523034621E-5,  3.4790767369819757E-5,  5.9181088871340979E-5,
    9.4571110739526937E-5,  0.00014196805196353105, 0.00020020704300665763,
    0.00026523123916539452, 0.00033008561034905177, 0.00038590917587419588,
    0.00042383831337106868, 0.00043729238566613893, 0.00042383831337106868,
    0.00038590917587419588, 0.00033008561034905177, 0.00026523123916539452,
    0.00020020704300665763, 0.00014196805196353105, 9.4571110739526937E-5,
    5.9181088871340979E-5,  3.4790767369819757E-5,  1.9213286523034621E-5,
    9.96772173790034E-6,    4.8578795985648562E-6,  2.2240993476926882E-6,
    9.5657320969368355E-7,  1.7321303136116663E-6,  4.02732363982478E-6,
    8.79648355952219E-6,    1.8049212339316831E-5,  3.4790767369819757E-5,
    6.2997941176267855E-5,  0.00010716310783930649, 0.00017124615872978079,
    0.00025707093182044413, 0.00036252812087580268, 0.00048027172914687926,
    0.000597707824114883,   0.00069879124259254743, 0.00076747203791663592,
    0.00079183421556039055, 0.00076747203791663592, 0.00069879124259254743,
    0.000597707824114883,   0.00048027172914687926, 0.00036252812087580268,
    0.00025707093182044413, 0.00017124615872978079, 0.00010716310783930649,
    6.2997941176267855E-5,  3.4790767369819757E-5,  1.8049212339316831E-5,
    8.79648355952219E-6,    4.02732363982478E-6,    1.7321303136116663E-6,
    2.9464529177220853E-6,  6.8507082844306217E-6,  1.4963322589514633E-5,
    3.0702744442407152E-5,  5.9181088871340979E-5,  0.00010716310783930649,
    0.00018229058707881985, 0.00029129952872078386, 0.00043729238566613893,
    0.00061668110714116378, 0.00081696973173665637, 0.0010167352585825414,
    0.00118868394567977,    0.0013055139140625664,  0.0013469553742324028,
    0.0013055139140625664,  0.00118868394567977,    0.0010167352585825414,
    0.00081696973173665637, 0.00061668110714116378, 0.00043729238566613893,
    0.00029129952872078386, 0.00018229058707881985, 0.00010716310783930649,
    5.9181088871340979E-5,  3.0702744442407152E-5,  1.4963322589514633E-5,
    6.8507082844306217E-6,  2.9464529177220853E-6,  4.70841835601366E-6,
    1.0947400667459241E-5,  2.3911321414187913E-5,  4.9062845919963714E-5,
    9.4571110739526937E-5,  0.00017124615872978079, 0.00029129952872078386,
    0.00046549532146857644, 0.00069879124259254743, 0.00098545360328209861,
    0.0013055139140625664,  0.0016247383170192816,  0.0018995115366256382,
    0.0020862052945192231,  0.0021524285593099318,  0.0020862052945192231,
    0.0018995115366256382,  0.0016247383170192816,  0.0013055139140625664,
    0.00098545360328209861, 0.00069879124259254743, 0.00046549532146857644,
    0.00029129952872078386, 0.00017124615872978079, 9.4571110739526937E-5,
    4.9062845919963714E-5,  2.3911321414187913E-5,  1.0947400667459241E-5,
    4.70841835601366E-6,    7.0681731091607814E-6,  1.643399484969634E-5,
    3.5895144875646433E-5,  7.3652055099876124E-5,  0.00014196805196353105,
    0.00025707093182044413, 0.00043729238566613893, 0.00069879124259254743,
    0.0010490099002144323,  0.0014793410721772144,  0.0019598085053819927,
    0.0024390210923189073,  0.0028515045496265278,  0.0031317650743749757,
    0.0032311779693223177,  0.0031317650743749757,  0.0028515045496265278,
    0.0024390210923189073,  0.0019598085053819927,  0.0014793410721772144,
    0.0010490099002144323,  0.00069879124259254743, 0.00043729238566613893,
    0.00025707093182044413, 0.00014196805196353105, 7.3652055099876124E-5,
    3.5895144875646433E-5,  1.643399484969634E-5,   7.0681731091607814E-6,
    9.96772173790034E-6,    2.317564739487682E-5,   5.0620267831066813E-5,
    0.00010386604562762829, 0.00020020704300665763, 0.00036252812087580268,
    0.00061668110714116378, 0.00098545360328209861, 0.0014793410721772144,
    0.0020862052945192231,  0.0027637729777585307,  0.0034395710441210686,
    0.0040212659545924428,  0.0044164966431546448,  0.0045566912958167217,
    0.0044164966431546448,  0.0040212659545924428,  0.0034395710441210686,
    0.0027637729777585307,  0.0020862052945192231,  0.0014793410721772144,
    0.00098545360328209861, 0.00061668110714116378, 0.00036252812087580268,
    0.00020020704300665763, 0.00010386604562762829, 5.0620267831066813E-5,
    2.317564739487682E-5,   9.96772173790034E-6,    1.320508583762077E-5,
    3.0702744442407152E-5,  6.70609593053704E-5,    0.00013760015419691886,
    0.00026523123916539452, 0.00048027172914687926, 0.00081696973173665637,
    0.0013055139140625664,  0.0019598085053819927,  0.0027637729777585307,
    0.0036614043175211934,  0.0045566912958167217,  0.0053273118474393517,
    0.0058509074398284712,  0.0060366351789304775,  0.0058509074398284712,
    0.0053273118474393517,  0.0045566912958167217,  0.0036614043175211934,
    0.0027637729777585307,  0.0019598085053819927,  0.0013055139140625664,
    0.00081696973173665637, 0.00048027172914687926, 0.00026523123916539452,
    0.00013760015419691886, 6.70609593053704E-5,    3.0702744442407152E-5,
    1.320508583762077E-5,   1.643399484969634E-5,   3.8210182822179428E-5,
    8.3458712301617293E-5,  0.00017124615872978079, 0.00033008561034905177,
    0.000597707824114883,   0.0010167352585825414,  0.0016247383170192816,
    0.0024390210923189073,  0.0034395710441210686,  0.0045566912958167217,
    0.0056708939425266546,  0.0066299467144788158,  0.0072815719575447758,
    0.0075127138634271586,  0.0072815719575447758,  0.0066299467144788158,
    0.0056708939425266546,  0.0045566912958167217,  0.0034395710441210686,
    0.0024390210923189073,  0.0016247383170192816,  0.0010167352585825414,
    0.000597707824114883,   0.00033008561034905177, 0.00017124615872978079,
    8.3458712301617293E-5,  3.8210182822179428E-5,  1.643399484969634E-5,
    1.9213286523034621E-5,  4.4672229568919093E-5,  9.75731200453745E-5,
    0.00020020704300665763, 0.00038590917587419588, 0.00069879124259254743,
    0.00118868394567977,    0.0018995115366256382,  0.0028515045496265278,
    0.0040212659545924428,  0.0053273118474393517,  0.0066299467144788158,
    0.0077511930010180849,  0.0085130200926761858,  0.0087832523585260544,
    0.0085130200926761858,  0.0077511930010180849,  0.0066299467144788158,
    0.0053273118474393517,  0.0040212659545924428,  0.0028515045496265278,
    0.0018995115366256382,  0.00118868394567977,    0.00069879124259254743,
    0.00038590917587419588, 0.00020020704300665763, 9.75731200453745E-5,
    4.4672229568919093E-5,  1.9213286523034621E-5,  2.1101667084725539E-5,
    4.9062845919963714E-5,  0.00010716310783930649, 0.00021988442031918191,
    0.00042383831337106868, 0.00076747203791663592, 0.0013055139140625664,
    0.0020862052945192231,  0.0031317650743749757,  0.0044164966431546448,
    0.0058509074398284712,  0.0072815719575447758,  0.0085130200926761858,
    0.0093497234669282052,  0.00964651554894283,    0.0093497234669282052,
    0.0085130200926761858,  0.0072815719575447758,  0.0058509074398284712,
    0.0044164966431546448,  0.0031317650743749757,  0.0020862052945192231,
    0.0013055139140625664,  0.00076747203791663592, 0.00042383831337106868,
    0.00021988442031918191, 0.00010716310783930649, 4.9062845919963714E-5,
    2.1101667084725539E-5,  2.1771505901906385E-5,  5.0620267831066813E-5,
    0.00011056483004031986, 0.00022686430107607769, 0.00043729238566613893,
    0.00079183421556039055, 0.0013469553742324028,  0.0021524285593099318,
    0.0032311779693223177,  0.0045566912958167217,  0.0060366351789304775,
    0.0075127138634271586,  0.0087832523585260544,  0.00964651554894283,
    0.0099527288229593527,  0.00964651554894283,    0.0087832523585260544,
    0.0075127138634271586,  0.0060366351789304775,  0.0045566912958167217,
    0.0032311779693223177,  0.0021524285593099318,  0.0013469553742324028,
    0.00079183421556039055, 0.00043729238566613893, 0.00022686430107607769,
    0.00011056483004031986, 5.0620267831066813E-5,  2.1771505901906385E-5,
    2.1101667084725539E-5,  4.9062845919963714E-5,  0.00010716310783930649,
    0.00021988442031918191, 0.00042383831337106868, 0.00076747203791663592,
    0.0013055139140625664,  0.0020862052945192231,  0.0031317650743749757,
    0.0044164966431546448,  0.0058509074398284712,  0.0072815719575447758,
    0.0085130200926761858,  0.0093497234669282052,  0.00964651554894283,
    0.0093497234669282052,  0.0085130200926761858,  0.0072815719575447758,
    0.0058509074398284712,  0.0044164966431546448,  0.0031317650743749757,
    0.0020862052945192231,  0.0013055139140625664,  0.00076747203791663592,
    0.00042383831337106868, 0.00021988442031918191, 0.00010716310783930649,
    4.9062845919963714E-5,  2.1101667084725539E-5,  1.9213286523034621E-5,
    4.4672229568919093E-5,  9.75731200453745E-5,    0.00020020704300665763,
    0.00038590917587419588, 0.00069879124259254743, 0.00118868394567977,
    0.0018995115366256382,  0.0028515045496265278,  0.0040212659545924428,
    0.0053273118474393517,  0.0066299467144788158,  0.0077511930010180849,
    0.0085130200926761858,  0.0087832523585260544,  0.0085130200926761858,
    0.0077511930010180849,  0.0066299467144788158,  0.0053273118474393517,
    0.0040212659545924428,  0.0028515045496265278,  0.0018995115366256382,
    0.00118868394567977,    0.00069879124259254743, 0.00038590917587419588,
    0.00020020704300665763, 9.75731200453745E-5,    4.4672229568919093E-5,
    1.9213286523034621E-5,  1.643399484969634E-5,   3.8210182822179428E-5,
    8.3458712301617293E-5,  0.00017124615872978079, 0.00033008561034905177,
    0.000597707824114883,   0.0010167352585825414,  0.0016247383170192816,
    0.0024390210923189073,  0.0034395710441210686,  0.0045566912958167217,
    0.0056708939425266546,  0.0066299467144788158,  0.0072815719575447758,
    0.0075127138634271586,  0.0072815719575447758,  0.0066299467144788158,
    0.0056708939425266546,  0.0045566912958167217,  0.0034395710441210686,
    0.0024390210923189073,  0.0016247383170192816,  0.0010167352585825414,
    0.000597707824114883,   0.00033008561034905177, 0.00017124615872978079,
    8.3458712301617293E-5,  3.8210182822179428E-5,  1.643399484969634E-5,
    1.320508583762077E-5,   3.0702744442407152E-5,  6.70609593053704E-5,
    0.00013760015419691886, 0.00026523123916539452, 0.00048027172914687926,
    0.00081696973173665637, 0.0013055139140625664,  0.0019598085053819927,
    0.0027637729777585307,  0.0036614043175211934,  0.0045566912958167217,
    0.0053273118474393517,  0.0058509074398284712,  0.0060366351789304775,
    0.0058509074398284712,  0.0053273118474393517,  0.0045566912958167217,
    0.0036614043175211934,  0.0027637729777585307,  0.0019598085053819927,
    0.0013055139140625664,  0.00081696973173665637, 0.00048027172914687926,
    0.00026523123916539452, 0.00013760015419691886, 6.70609593053704E-5,
    3.0702744442407152E-5,  1.320508583762077E-5,   9.96772173790034E-6,
    2.317564739487682E-5,   5.0620267831066813E-5,  0.00010386604562762829,
    0.00020020704300665763, 0.00036252812087580268, 0.00061668110714116378,
    0.00098545360328209861, 0.0014793410721772144,  0.0020862052945192231,
    0.0027637729777585307,  0.0034395710441210686,  0.0040212659545924428,
    0.0044164966431546448,  0.0045566912958167217,  0.0044164966431546448,
    0.0040212659545924428,  0.0034395710441210686,  0.0027637729777585307,
    0.0020862052945192231,  0.0014793410721772144,  0.00098545360328209861,
    0.00061668110714116378, 0.00036252812087580268, 0.00020020704300665763,
    0.00010386604562762829, 5.0620267831066813E-5,  2.317564739487682E-5,
    9.96772173790034E-6,    7.0681731091607814E-6,  1.643399484969634E-5,
    3.5895144875646433E-5,  7.3652055099876124E-5,  0.00014196805196353105,
    0.00025707093182044413, 0.00043729238566613893, 0.00069879124259254743,
    0.0010490099002144323,  0.0014793410721772144,  0.0019598085053819927,
    0.0024390210923189073,  0.0028515045496265278,  0.0031317650743749757,
    0.0032311779693223177,  0.0031317650743749757,  0.0028515045496265278,
    0.0024390210923189073,  0.0019598085053819927,  0.0014793410721772144,
    0.0010490099002144323,  0.00069879124259254743, 0.00043729238566613893,
    0.00025707093182044413, 0.00014196805196353105, 7.3652055099876124E-5,
    3.5895144875646433E-5,  1.643399484969634E-5,   7.0681731091607814E-6,
    4.70841835601366E-6,    1.0947400667459241E-5,  2.3911321414187913E-5,
    4.9062845919963714E-5,  9.4571110739526937E-5,  0.00017124615872978079,
    0.00029129952872078386, 0.00046549532146857644, 0.00069879124259254743,
    0.00098545360328209861, 0.0013055139140625664,  0.0016247383170192816,
    0.0018995115366256382,  0.0020862052945192231,  0.0021524285593099318,
    0.0020862052945192231,  0.0018995115366256382,  0.0016247383170192816,
    0.0013055139140625664,  0.00098545360328209861, 0.00069879124259254743,
    0.00046549532146857644, 0.00029129952872078386, 0.00017124615872978079,
    9.4571110739526937E-5,  4.9062845919963714E-5,  2.3911321414187913E-5,
    1.0947400667459241E-5,  4.70841835601366E-6,    2.9464529177220853E-6,
    6.8507082844306217E-6,  1.4963322589514633E-5,  3.0702744442407152E-5,
    5.9181088871340979E-5,  0.00010716310783930649, 0.00018229058707881985,
    0.00029129952872078386, 0.00043729238566613893, 0.00061668110714116378,
    0.00081696973173665637, 0.0010167352585825414,  0.00118868394567977,
    0.0013055139140625664,  0.0013469553742324028,  0.0013055139140625664,
    0.00118868394567977,    0.0010167352585825414,  0.00081696973173665637,
    0.00061668110714116378, 0.00043729238566613893, 0.00029129952872078386,
    0.00018229058707881985, 0.00010716310783930649, 5.9181088871340979E-5,
    3.0702744442407152E-5,  1.4963322589514633E-5,  6.8507082844306217E-6,
    2.9464529177220853E-6,  1.7321303136116663E-6,  4.02732363982478E-6,
    8.79648355952219E-6,    1.8049212339316831E-5,  3.4790767369819757E-5,
    6.2997941176267855E-5,  0.00010716310783930649, 0.00017124615872978079,
    0.00025707093182044413, 0.00036252812087580268, 0.00048027172914687926,
    0.000597707824114883,   0.00069879124259254743, 0.00076747203791663592,
    0.00079183421556039055, 0.00076747203791663592, 0.00069879124259254743,
    0.000597707824114883,   0.00048027172914687926, 0.00036252812087580268,
    0.00025707093182044413, 0.00017124615872978079, 0.00010716310783930649,
    6.2997941176267855E-5,  3.4790767369819757E-5,  1.8049212339316831E-5,
    8.79648355952219E-6,    4.02732363982478E-6,    1.7321303136116663E-6,
    9.5657320969368355E-7,  2.2240993476926882E-6,  4.8578795985648562E-6,
    9.96772173790034E-6,    1.9213286523034621E-5,  3.4790767369819757E-5,
    5.9181088871340979E-5,  9.4571110739526937E-5,  0.00014196805196353105,
    0.00020020704300665763, 0.00026523123916539452, 0.00033008561034905177,
    0.00038590917587419588, 0.00042383831337106868, 0.00043729238566613893,
    0.00042383831337106868, 0.00038590917587419588, 0.00033008561034905177,
    0.00026523123916539452, 0.00020020704300665763, 0.00014196805196353105,
    9.4571110739526937E-5,  5.9181088871340979E-5,  3.4790767369819757E-5,
    1.9213286523034621E-5,  9.96772173790034E-6,    4.8578795985648562E-6,
    2.2240993476926882E-6,  9.5657320969368355E-7,  4.9626364363668783E-7,
    1.15384754131824E-6,    2.5202347353049072E-6,  5.1711859147624051E-6,
    9.96772173790034E-6,    1.8049212339316831E-5,  3.0702744442407152E-5,
    4.9062845919963714E-5,  7.3652055099876124E-5,  0.00010386604562762829,
    0.00013760015419691886, 0.00017124615872978079, 0.00020020704300665763,
    0.00021988442031918191, 0.00022686430107607769, 0.00021988442031918191,
    0.00020020704300665763, 0.00017124615872978079, 0.00013760015419691886,
    0.00010386604562762829, 7.3652055099876124E-5,  4.9062845919963714E-5,
    3.0702744442407152E-5,  1.8049212339316831E-5,  9.96772173790034E-6,
    5.1711859147624051E-6,  2.5202347353049072E-6,  1.15384754131824E-6,
    4.9626364363668783E-7,  2.418595836966E-7,      5.6234038010021961E-7,
    1.2282643141692625E-6,  2.5202347353049072E-6,  4.8578795985648562E-6,
    8.79648355952219E-6,    1.4963322589514633E-5,  2.3911321414187913E-5,
    3.5895144875646433E-5,  5.0620267831066813E-5,  6.70609593053704E-5,
    8.3458712301617293E-5,  9.75731200453745E-5,    0.00010716310783930649,
    0.00011056483004031986, 0.00010716310783930649, 9.75731200453745E-5,
    8.3458712301617293E-5,  6.70609593053704E-5,    5.0620267831066813E-5,
    3.5895144875646433E-5,  2.3911321414187913E-5,  1.4963322589514633E-5,
    8.79648355952219E-6,    4.8578795985648562E-6,  2.5202347353049072E-6,
    1.2282643141692625E-6,  5.6234038010021961E-7,  2.418595836966E-7,
    1.1073138628049746E-7,  2.5745818668121091E-7,  5.6234038010021961E-7,
    1.15384754131824E-6,    2.2240993476926882E-6,  4.02732363982478E-6,
    6.8507082844306217E-6,  1.0947400667459241E-5,  1.643399484969634E-5,
    2.317564739487682E-5,   3.0702744442407152E-5,  3.8210182822179428E-5,
    4.4672229568919093E-5,  4.9062845919963714E-5,  5.0620267831066813E-5,
    4.9062845919963714E-5,  4.4672229568919093E-5,  3.8210182822179428E-5,
    3.0702744442407152E-5,  2.317564739487682E-5,   1.643399484969634E-5,
    1.0947400667459241E-5,  6.8507082844306217E-6,  4.02732363982478E-6,
    2.2240993476926882E-6,  1.15384754131824E-6,    5.6234038010021961E-7,
    2.5745818668121091E-7,  1.1073138628049746E-7,  4.762497578988648E-8,
    1.1073138628049746E-7,  2.418595836966E-7,      4.9626364363668783E-7,
    9.5657320969368355E-7,  1.7321303136116663E-6,  2.9464529177220853E-6,
    4.70841835601366E-6,    7.0681731091607814E-6,  9.96772173790034E-6,
    1.320508583762077E-5,   1.643399484969634E-5,   1.9213286523034621E-5,
    2.1101667084725539E-5,  2.1771505901906385E-5,  2.1101667084725539E-5,
    1.9213286523034621E-5,  1.643399484969634E-5,   1.320508583762077E-5,
    9.96772173790034E-6,    7.0681731091607814E-6,  4.70841835601366E-6,
    2.9464529177220853E-6,  1.7321303136116663E-6,  9.5657320969368355E-7,
    4.9626364363668783E-7,  2.418595836966E-7,      1.1073138628049746E-7,
    4.762497578988648E-8};

const char_T cv[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                    '_', 'd', 'g', 'e', 's', 'v', 'd'};

const char_T cv1[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                     '_', 'd', 'g', 'e', 's', 'd', 'd'};

const char_T cv2[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                     '_', 'd', 'g', 'e', 'q', 'p', '3'};

emlrtRSInfo xdb_emlrtRSI{
    53,        // lineNo
    "flt2str", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" // pathName
};

covrtInstance emlrtCoverageInstance;

// End of code generation (ComputeCamExtrinsics_mex_data.cpp)
