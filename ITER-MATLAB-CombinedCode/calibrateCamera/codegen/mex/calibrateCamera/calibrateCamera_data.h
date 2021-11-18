//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera_data.h
//
// Code generation for function 'calibrateCamera_data'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo kb_emlrtRSI;
extern emlrtRSInfo lb_emlrtRSI;
extern emlrtRSInfo mb_emlrtRSI;
extern emlrtRSInfo nb_emlrtRSI;
extern emlrtRSInfo ob_emlrtRSI;
extern emlrtRSInfo pb_emlrtRSI;
extern emlrtRSInfo qb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo wb_emlrtRSI;
extern emlrtRSInfo xb_emlrtRSI;
extern emlrtRSInfo yb_emlrtRSI;
extern emlrtRSInfo ac_emlrtRSI;
extern emlrtRSInfo bc_emlrtRSI;
extern emlrtRSInfo cc_emlrtRSI;
extern emlrtRSInfo dc_emlrtRSI;
extern emlrtRSInfo ec_emlrtRSI;
extern emlrtRSInfo fc_emlrtRSI;
extern emlrtRSInfo gc_emlrtRSI;
extern emlrtRSInfo hc_emlrtRSI;
extern emlrtRSInfo ic_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo ad_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo cd_emlrtRSI;
extern emlrtRSInfo dd_emlrtRSI;
extern emlrtRSInfo ed_emlrtRSI;
extern emlrtRSInfo gd_emlrtRSI;
extern emlrtRSInfo hd_emlrtRSI;
extern emlrtRSInfo jd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo wd_emlrtRSI;
extern emlrtRSInfo xd_emlrtRSI;
extern emlrtRSInfo yd_emlrtRSI;
extern emlrtRSInfo ae_emlrtRSI;
extern emlrtRSInfo be_emlrtRSI;
extern emlrtRSInfo ce_emlrtRSI;
extern emlrtRSInfo de_emlrtRSI;
extern emlrtRSInfo se_emlrtRSI;
extern emlrtRSInfo te_emlrtRSI;
extern emlrtRSInfo ve_emlrtRSI;
extern emlrtRSInfo we_emlrtRSI;
extern emlrtRSInfo af_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo uf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo wf_emlrtRSI;
extern emlrtRSInfo xf_emlrtRSI;
extern emlrtRSInfo yf_emlrtRSI;
extern emlrtRSInfo ag_emlrtRSI;
extern emlrtRSInfo bg_emlrtRSI;
extern emlrtRSInfo ph_emlrtRSI;
extern emlrtRSInfo qh_emlrtRSI;
extern emlrtRSInfo rh_emlrtRSI;
extern emlrtRSInfo sh_emlrtRSI;
extern emlrtRSInfo bi_emlrtRSI;
extern emlrtRSInfo ci_emlrtRSI;
extern emlrtRSInfo gk_emlrtRSI;
extern emlrtRSInfo hk_emlrtRSI;
extern emlrtRSInfo jk_emlrtRSI;
extern emlrtRSInfo kk_emlrtRSI;
extern emlrtRSInfo mk_emlrtRSI;
extern emlrtRSInfo yk_emlrtRSI;
extern emlrtRSInfo bl_emlrtRSI;
extern emlrtRSInfo cl_emlrtRSI;
extern emlrtRSInfo dl_emlrtRSI;
extern emlrtRSInfo el_emlrtRSI;
extern emlrtRSInfo fl_emlrtRSI;
extern emlrtRSInfo gl_emlrtRSI;
extern emlrtRSInfo hl_emlrtRSI;
extern emlrtRSInfo il_emlrtRSI;
extern emlrtRSInfo jl_emlrtRSI;
extern emlrtRSInfo xl_emlrtRSI;
extern emlrtRSInfo yl_emlrtRSI;
extern emlrtRSInfo am_emlrtRSI;
extern emlrtRSInfo bm_emlrtRSI;
extern emlrtRSInfo cm_emlrtRSI;
extern emlrtRSInfo ym_emlrtRSI;
extern emlrtRSInfo an_emlrtRSI;
extern emlrtRSInfo bn_emlrtRSI;
extern emlrtRSInfo kn_emlrtRSI;
extern emlrtRSInfo ln_emlrtRSI;
extern emlrtRSInfo pn_emlrtRSI;
extern emlrtRSInfo hp_emlrtRSI;
extern emlrtRSInfo oq_emlrtRSI;
extern emlrtRSInfo es_emlrtRSI;
extern emlrtRSInfo fs_emlrtRSI;
extern emlrtRSInfo gs_emlrtRSI;
extern emlrtRSInfo hs_emlrtRSI;
extern emlrtRSInfo is_emlrtRSI;
extern emlrtRSInfo js_emlrtRSI;
extern emlrtRSInfo ks_emlrtRSI;
extern emlrtRSInfo eu_emlrtRSI;
extern emlrtRSInfo gu_emlrtRSI;
extern emlrtRSInfo hu_emlrtRSI;
extern emlrtRSInfo ju_emlrtRSI;
extern emlrtRSInfo sv_emlrtRSI;
extern emlrtRSInfo dx_emlrtRSI;
extern emlrtRSInfo sy_emlrtRSI;
extern emlrtRSInfo wy_emlrtRSI;
extern emlrtMCInfo c_emlrtMCI;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t calibrateCamera_nestLockGlobal;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo d_emlrtRTEI;
extern emlrtRTEInfo g_emlrtRTEI;
extern emlrtECInfo e_emlrtECI;
extern emlrtECInfo f_emlrtECI;
extern emlrtECInfo g_emlrtECI;
extern emlrtECInfo h_emlrtECI;
extern emlrtECInfo i_emlrtECI;
extern emlrtECInfo j_emlrtECI;
extern emlrtECInfo k_emlrtECI;
extern emlrtECInfo l_emlrtECI;
extern emlrtBCInfo db_emlrtBCI;
extern emlrtBCInfo eb_emlrtBCI;
extern emlrtBCInfo fb_emlrtBCI;
extern emlrtBCInfo gb_emlrtBCI;
extern emlrtRTEInfo l_emlrtRTEI;
extern emlrtRTEInfo m_emlrtRTEI;
extern emlrtRTEInfo o_emlrtRTEI;
extern emlrtRTEInfo q_emlrtRTEI;
extern emlrtRTEInfo u_emlrtRTEI;
extern emlrtRTEInfo v_emlrtRTEI;
extern emlrtRTEInfo y_emlrtRTEI;
extern emlrtRTEInfo ab_emlrtRTEI;
extern emlrtRTEInfo fb_emlrtRTEI;
extern emlrtRTEInfo gb_emlrtRTEI;
extern emlrtRTEInfo ob_emlrtRTEI;
extern emlrtRTEInfo sb_emlrtRTEI;
extern emlrtBCInfo wt_emlrtBCI;
extern emlrtRTEInfo rc_emlrtRTEI;
extern emlrtRTEInfo jd_emlrtRTEI;
extern emlrtRTEInfo kd_emlrtRTEI;
extern emlrtRTEInfo ld_emlrtRTEI;
extern emlrtRTEInfo md_emlrtRTEI;
extern emlrtRTEInfo nd_emlrtRTEI;
extern emlrtRTEInfo od_emlrtRTEI;
extern emlrtRTEInfo pd_emlrtRTEI;
extern emlrtRTEInfo qd_emlrtRTEI;
extern emlrtRTEInfo rd_emlrtRTEI;
extern emlrtRTEInfo sd_emlrtRTEI;
extern emlrtRTEInfo td_emlrtRTEI;
extern emlrtRTEInfo ud_emlrtRTEI;
extern emlrtRTEInfo vd_emlrtRTEI;
extern emlrtRTEInfo wd_emlrtRTEI;
extern emlrtRTEInfo xd_emlrtRTEI;
extern emlrtRTEInfo yd_emlrtRTEI;
extern emlrtRTEInfo ae_emlrtRTEI;
extern emlrtRTEInfo be_emlrtRTEI;
extern emlrtRTEInfo ce_emlrtRTEI;
extern emlrtRTEInfo de_emlrtRTEI;
extern emlrtRTEInfo ee_emlrtRTEI;
extern emlrtRTEInfo fe_emlrtRTEI;
extern emlrtRTEInfo ge_emlrtRTEI;
extern emlrtRTEInfo he_emlrtRTEI;
extern emlrtRTEInfo le_emlrtRTEI;
extern emlrtRTEInfo re_emlrtRTEI;
extern emlrtRTEInfo ve_emlrtRTEI;
extern emlrtRTEInfo ye_emlrtRTEI;
extern emlrtRTEInfo af_emlrtRTEI;
extern emlrtRTEInfo bf_emlrtRTEI;
extern emlrtRTEInfo cf_emlrtRTEI;
extern emlrtRTEInfo df_emlrtRTEI;
extern emlrtRTEInfo ef_emlrtRTEI;
extern emlrtRTEInfo mf_emlrtRTEI;
extern emlrtRTEInfo qg_emlrtRTEI;
extern emlrtRTEInfo cj_emlrtRTEI;
extern emlrtRTEInfo fj_emlrtRTEI;
extern emlrtRTEInfo gk_emlrtRTEI;
extern emlrtRTEInfo vm_emlrtRTEI;
extern emlrtRTEInfo uo_emlrtRTEI;
extern emlrtRTEInfo ar_emlrtRTEI;
extern emlrtRTEInfo is_emlrtRTEI;
extern emlrtRTEInfo js_emlrtRTEI;
extern emlrtRTEInfo ks_emlrtRTEI;
extern const char_T cv[14];
extern const real_T dv[841];
extern const char_T cv1[14];
extern const char_T cv2[14];
extern const char_T cv3[128];
extern emlrtRSInfo sab_emlrtRSI;
extern covrtInstance emlrtCoverageInstance;

// End of code generation (calibrateCamera_data.h)
