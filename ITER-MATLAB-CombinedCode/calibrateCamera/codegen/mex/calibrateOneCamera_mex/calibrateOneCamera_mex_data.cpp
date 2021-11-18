//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_data.cpp
//
// Code generation for function 'calibrateOneCamera_mex_data'
//

// Include files
#include "calibrateOneCamera_mex_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131611U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "calibrateOneCamera_mex",                             // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {1119371377U, 1415814266U, 2793307332U, 3107132454U}, // fSigWrd
    nullptr                                               // fSigMem
};

emlrtRSInfo p_emlrtRSI{
    76,                   // lineNo
    "validateattributes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" // pathName
};

emlrtRSInfo bb_emlrtRSI{
    8,                    // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo cb_emlrtRSI{
    11,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo db_emlrtRSI{
    12,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo eb_emlrtRSI{
    20,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo fb_emlrtRSI{
    37,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo gb_emlrtRSI{
    38,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo hb_emlrtRSI{
    43,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo ib_emlrtRSI{
    44,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo jb_emlrtRSI{
    45,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo kb_emlrtRSI{
    47,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo lb_emlrtRSI{
    48,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo mb_emlrtRSI{
    49,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo nb_emlrtRSI{
    21,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo ob_emlrtRSI{
    39,                   // lineNo
    "detectCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo pb_emlrtRSI{
    8,                         // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo qb_emlrtRSI{
    13,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo rb_emlrtRSI{
    14,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo sb_emlrtRSI{
    17,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo tb_emlrtRSI{
    34,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo ub_emlrtRSI{
    35,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo vb_emlrtRSI{
    40,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo wb_emlrtRSI{
    42,                        // lineNo
    "secondDerivCornerMetric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pathName
};

emlrtRSInfo xb_emlrtRSI{
    106,        // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo yb_emlrtRSI{
    110,        // lineNo
    "imfilter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo ec_emlrtRSI{
    28,       // lineNo
    "repmat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

emlrtRSInfo hc_emlrtRSI{
    21,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" // pathName
};

emlrtRSInfo ic_emlrtRSI{
    928,                 // lineNo
    "filterPartOrWhole", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo jc_emlrtRSI{
    1002,           // lineNo
    "imfiltercore", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pathName
};

emlrtRSInfo qc_emlrtRSI{
    58,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo rc_emlrtRSI{
    59,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo sc_emlrtRSI{
    64,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo tc_emlrtRSI{
    65,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo uc_emlrtRSI{
    66,                       // lineNo
    "computeJacobianEntries", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

emlrtRSInfo wc_emlrtRSI{
    66,      // lineNo
    "ixfun", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

emlrtRSInfo xc_emlrtRSI{
    66,                          // lineNo
    "applyBinaryScalarFunction", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

emlrtRSInfo
    ad_emlrtRSI{
        103,                  // lineNo
        "flatVectorAllOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

emlrtRSInfo kd_emlrtRSI{
    15,    // lineNo
    "max", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

emlrtRSInfo
    ld_emlrtRSI{
        44,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

emlrtRSInfo
    md_emlrtRSI{
        79,        // lineNo
        "maximum", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

emlrtRSInfo nd_emlrtRSI{
    186,             // lineNo
    "unaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

emlrtRSInfo od_emlrtRSI{
    897,                    // lineNo
    "maxRealVectorOmitNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

emlrtRSInfo pd_emlrtRSI{
    62,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo qd_emlrtRSI{
    54,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo rd_emlrtRSI{
    103,         // lineNo
    "findFirst", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo sd_emlrtRSI{
    120,                        // lineNo
    "minOrMaxRealVectorKernel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" // pathName
};

emlrtRSInfo
    td_emlrtRSI{
        46,    // lineNo
        "eps", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\eps.m" // pathName
    };

emlrtRSInfo je_emlrtRSI{
    39,     // lineNo
    "find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo ke_emlrtRSI{
    144,        // lineNo
    "eml_find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo me_emlrtRSI{
    382,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo ne_emlrtRSI{
    402,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

emlrtRSInfo qe_emlrtRSI{
    16,        // lineNo
    "sub2ind", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m" // pathName
};

emlrtRSInfo ef_emlrtRSI{
    27,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pathName
};

emlrtRSInfo lf_emlrtRSI{
    50,         // lineNo
    "prodsize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\+coder\\+"
    "internal\\prodsize.m" // pathName
};

emlrtRSInfo mf_emlrtRSI{
    105,       // lineNo
    "sortIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo nf_emlrtRSI{
    308,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo of_emlrtRSI{
    316,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo pf_emlrtRSI{
    317,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo qf_emlrtRSI{
    325,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo rf_emlrtRSI{
    333,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo
    gh_emlrtRSI{
        90,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

emlrtRSInfo
    hh_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

emlrtRSInfo ih_emlrtRSI{
    142,      // lineNo
    "mtimes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

emlrtRSInfo jh_emlrtRSI{
    178,           // lineNo
    "mtimes_blas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

emlrtRSInfo
    rh_emlrtRSI{
        143,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

emlrtRSInfo
    sh_emlrtRSI{
        13,    // lineNo
        "all", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m" // pathName
    };

emlrtRSInfo wj_emlrtRSI{
    49,     // lineNo
    "mean", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" // pathName
};

emlrtRSInfo xj_emlrtRSI{
    74,                      // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

emlrtRSInfo ak_emlrtRSI{
    22,                    // lineNo
    "sumMatrixIncludeNaN", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo bk_emlrtRSI{
    42,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo dk_emlrtRSI{
    57,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

emlrtRSInfo pk_emlrtRSI{
    61,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo rk_emlrtRSI{
    85,        // lineNo
    "qrsolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo sk_emlrtRSI{
    63,       // lineNo
    "xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo tk_emlrtRSI{
    158,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo uk_emlrtRSI{
    154,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo vk_emlrtRSI{
    151,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo wk_emlrtRSI{
    148,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo xk_emlrtRSI{
    143,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo yk_emlrtRSI{
    141,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo al_emlrtRSI{
    138,            // lineNo
    "ceval_xgeqp3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pathName
};

emlrtRSInfo ol_emlrtRSI{
    119,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo pl_emlrtRSI{
    128,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo ql_emlrtRSI{
    138,         // lineNo
    "LSQFromQR", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pathName
};

emlrtRSInfo rl_emlrtRSI{
    31,         // lineNo
    "xunormqr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" // pathName
};

emlrtRSInfo sl_emlrtRSI{
    102,              // lineNo
    "ceval_xunormqr", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xunormqr.m" // pathName
};

emlrtRSInfo pm_emlrtRSI{
    145,       // lineNo
    "sortIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

emlrtRSInfo
    qm_emlrtRSI{
        57,          // lineNo
        "mergesort", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pathName
    };

emlrtRSInfo
    rm_emlrtRSI{
        113,         // lineNo
        "mergesort", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pathName
    };

emlrtRSInfo bn_emlrtRSI{
    26,    // lineNo
    "cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

emlrtRSInfo cn_emlrtRSI{
    100,        // lineNo
    "cat_impl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

emlrtRSInfo gn_emlrtRSI{
    99,        // lineNo
    "sumprod", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" // pathName
};

emlrtRSInfo xo_emlrtRSI{
    107,                // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

emlrtRSInfo
    fq_emlrtRSI{
        136,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

emlrtRSInfo ur_emlrtRSI{
    36,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtRSInfo vr_emlrtRSI{
    44,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo wr_emlrtRSI{
    81,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo xr_emlrtRSI{
    73,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo yr_emlrtRSI{
    209,      // lineNo
    "xgesdd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" // pathName
};

emlrtRSInfo as_emlrtRSI{
    31,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

emlrtRSInfo bs_emlrtRSI{
    197,            // lineNo
    "ceval_xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

emlrtRSInfo ut_emlrtRSI{
    14,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtRSInfo wt_emlrtRSI{
    29,             // lineNo
    "anyNonFinite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite."
    "m" // pathName
};

emlrtRSInfo
    xt_emlrtRSI{
        44,          // lineNo
        "vAllOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

emlrtRSInfo au_emlrtRSI{
    99,           // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

emlrtRSInfo mv_emlrtRSI{
    42,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" // pathName
};

emlrtRSInfo ww_emlrtRSI{
    6,                             // lineNo
    "HandleCodegen/HandleCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "enforcescalar\\HandleCodegen.m" // pathName
};

emlrtRSInfo yw_emlrtRSI{
    209,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo ax_emlrtRSI{
    281,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo bx_emlrtRSI{
    301,                                         // lineNo
    "CameraParametersImpl/CameraParametersImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo cx_emlrtRSI{
    346,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo dx_emlrtRSI{
    352,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo ex_emlrtRSI{
    357,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo fx_emlrtRSI{
    360,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo gx_emlrtRSI{
    362,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo jx_emlrtRSI{
    392,                                       // lineNo
    "CameraParametersImpl/parseInputsCodegen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo nx_emlrtRSI{
    425,                                  // lineNo
    "CameraParametersImpl/set.ImageSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\CameraParametersImpl.m" // pathName
};

emlrtRSInfo sx_emlrtRSI{
    43,                                  // lineNo
    "ImageTransformer/ImageTransformer", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\ImageTransformer.m" // pathName
};

emlrtRSInfo vx_emlrtRSI{
    28,    // lineNo
    "cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

emlrtRSInfo ly_emlrtRSI{
    63,                               // lineNo
    "function_handle/parenReference", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pathName
};

emlrtRSInfo py_emlrtRSI{
    119,                                                            // lineNo
    "@(x)CalculateCost(x,options,calibration,genPoints,detPoints)", // fcnName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pathName
};

emlrtMCInfo c_emlrtMCI{
    53,        // lineNo
    19,        // colNo
    "flt2str", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" // pName
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t calibrateOneCamera_nestLockGlobal;

emlrtRTEInfo emlrtRTEI{
    275,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

emlrtRTEInfo e_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" // pName
};

emlrtRTEInfo g_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" // pName
};

emlrtECInfo b_emlrtECI{
    2,                         // nDims
    30,                        // lineNo
    12,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo c_emlrtECI{
    2,                         // nDims
    31,                        // lineNo
    13,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo d_emlrtECI{
    2,                         // nDims
    37,                        // lineNo
    15,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo e_emlrtECI{
    2,                         // nDims
    40,                        // lineNo
    47,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo f_emlrtECI{
    2,                         // nDims
    40,                        // lineNo
    11,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo g_emlrtECI{
    2,                         // nDims
    42,                        // lineNo
    51,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo h_emlrtECI{
    2,                         // nDims
    42,                        // lineNo
    11,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtECInfo i_emlrtECI{
    2,                        // nDims
    60,                       // lineNo
    7,                        // colNo
    "computeJacobianEntries", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtBCInfo y_emlrtBCI{
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

emlrtBCInfo ab_emlrtBCI{
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

emlrtBCInfo bb_emlrtBCI{
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

emlrtBCInfo cb_emlrtBCI{
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

emlrtRTEInfo k_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" // pName
};

emlrtRTEInfo l_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatenonnan", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" // pName
};

emlrtRTEInfo m_emlrtRTEI{
    13,               // lineNo
    13,               // colNo
    "toLogicalCheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\toLogicalCheck.m" // pName
};

emlrtRTEInfo o_emlrtRTEI{
    130,             // lineNo
    27,              // colNo
    "unaryMinOrMax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pName
};

emlrtRTEInfo q_emlrtRTEI{
    392,                  // lineNo
    1,                    // colNo
    "find_first_indices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo u_emlrtRTEI{
    13,     // lineNo
    9,      // colNo
    "sqrt", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" // pName
};

emlrtRTEInfo v_emlrtRTEI{
    53,       // lineNo
    15,       // colNo
    "bsxfun", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pName
};

emlrtRTEInfo
    y_emlrtRTEI{
        129,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

emlrtRTEInfo
    ab_emlrtRTEI{
        134,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

emlrtRTEInfo fb_emlrtRTEI{
    44,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

emlrtRTEInfo gb_emlrtRTEI{
    47,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

emlrtRTEInfo ob_emlrtRTEI{
    52,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo sb_emlrtRTEI{
    103,          // lineNo
    5,            // colNo
    "callLAPACK", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

emlrtBCInfo mt_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "hasFiniteBounds", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "utils\\hasFiniteBounds.p", // pName
    0                           // checkKind
};

emlrtRTEInfo bd_emlrtRTEI{
    138,                  // lineNo
    1,                    // colNo
    "calibrateOneCamera", // fName
    "D:\\TUT_Research\\Gitlab\\f4e-grt\\ITER-SW-CameraCalibration\\Matlab-code-"
    "V2\\calibrateOneCamera.m" // pName
};

emlrtRTEInfo ed_emlrtRTEI{
    8,                         // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo fd_emlrtRTEI{
    13,                        // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo gd_emlrtRTEI{
    17,                        // lineNo
    1,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo hd_emlrtRTEI{
    30,                        // lineNo
    12,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo id_emlrtRTEI{
    30,                        // lineNo
    26,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo jd_emlrtRTEI{
    30,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo kd_emlrtRTEI{
    31,                        // lineNo
    30,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo ld_emlrtRTEI{
    34,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo md_emlrtRTEI{
    35,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo nd_emlrtRTEI{
    31,                        // lineNo
    13,                        // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo od_emlrtRTEI{
    40,                        // lineNo
    5,                         // colNo
    "secondDerivCornerMetric", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\secondDerivCornerMetric.m" // pName
};

emlrtRTEInfo pd_emlrtRTEI{
    8,                    // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo qd_emlrtRTEI{
    20,                   // lineNo
    34,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo rd_emlrtRTEI{
    20,                   // lineNo
    49,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo sd_emlrtRTEI{
    20,                   // lineNo
    15,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo td_emlrtRTEI{
    20,                   // lineNo
    11,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ud_emlrtRTEI{
    23,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo vd_emlrtRTEI{
    38,                   // lineNo
    39,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo wd_emlrtRTEI{
    38,                   // lineNo
    55,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo xd_emlrtRTEI{
    38,                   // lineNo
    20,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo yd_emlrtRTEI{
    38,                   // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ae_emlrtRTEI{
    42,                   // lineNo
    17,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo be_emlrtRTEI{
    42,                   // lineNo
    43,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

emlrtRTEInfo ce_emlrtRTEI{
    16,      // lineNo
    13,      // colNo
    "isnan", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\isnan.m" // pName
};

emlrtRTEInfo de_emlrtRTEI{
    1024,       // lineNo
    26,         // colNo
    "imfilter", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imfilter.m" // pName
};

emlrtRTEInfo he_emlrtRTEI{
    129,                         // lineNo
    6,                           // colNo
    "applyBinaryScalarFunction", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pName
};

emlrtRTEInfo ne_emlrtRTEI{
    369,    // lineNo
    24,     // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo re_emlrtRTEI{
    27,     // lineNo
    6,      // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pName
};

emlrtRTEInfo ue_emlrtRTEI{
    25,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo ve_emlrtRTEI{
    26,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo we_emlrtRTEI{
    27,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo xe_emlrtRTEI{
    28,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo ye_emlrtRTEI{
    29,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo af_emlrtRTEI{
    30,             // lineNo
    13,             // colNo
    "Checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\Checkerboard.m" // pName
};

emlrtRTEInfo if_emlrtRTEI{
    60,       // lineNo
    20,       // colNo
    "bsxfun", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" // pName
};

emlrtRTEInfo mg_emlrtRTEI{
    218,      // lineNo
    20,       // colNo
    "mtimes", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pName
};

emlrtRTEInfo xi_emlrtRTEI{
    1,        // lineNo
    32,       // colNo
    "xgeqp3", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeqp3.m" // pName
};

emlrtRTEInfo bj_emlrtRTEI{
    119,       // lineNo
    5,         // colNo
    "qrsolve", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m" // pName
};

emlrtRTEInfo
    ck_emlrtRTEI{
        52,          // lineNo
        9,           // colNo
        "mergesort", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\mergesort.m" // pName
    };

emlrtRTEInfo rm_emlrtRTEI{
    364,    // lineNo
    24,     // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

emlrtRTEInfo
    qo_emlrtRTEI{
        56,    // lineNo
        20,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

emlrtRTEInfo
    ar_emlrtRTEI{
        31,            // lineNo
        30,            // colNo
        "unsafeSxfun", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" // pName
    };

emlrtRTEInfo ls_emlrtRTEI{
    61,        // lineNo
    5,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

emlrtRTEInfo ms_emlrtRTEI{
    386,       // lineNo
    1,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

emlrtRTEInfo ns_emlrtRTEI{
    388,       // lineNo
    1,         // colNo
    "sortIdx", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pName
};

const char_T cv[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                    '_', 'd', 'g', 'e', 'q', 'p', '3'};

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

const char_T cv1[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                     '_', 'd', 'g', 'e', 's', 'v', 'd'};

const char_T cv2[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                     '_', 'd', 'g', 'e', 's', 'd', 'd'};

const int8_T iv[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};

const char_T cv3[128]{
    '\x00',     '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12',     '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b',     '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',        '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',        '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',        '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',        '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',        'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',        'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',        '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',        'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',        'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',        'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',        '\x7f'};

emlrtRSInfo lbb_emlrtRSI{
    53,        // lineNo
    "flt2str", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m" // pathName
};

covrtInstance emlrtCoverageInstance;

// End of code generation (calibrateOneCamera_mex_data.cpp)
