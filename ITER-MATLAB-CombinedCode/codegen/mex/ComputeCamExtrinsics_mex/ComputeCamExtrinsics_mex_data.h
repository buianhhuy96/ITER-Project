//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics_mex_data.h
//
// Code generation for function 'ComputeCamExtrinsics_mex_data'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo f_emlrtRSI;
extern emlrtRSInfo g_emlrtRSI;
extern emlrtRSInfo h_emlrtRSI;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo j_emlrtRSI;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo m_emlrtRSI;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo q_emlrtRSI;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo s_emlrtRSI;
extern emlrtRSInfo t_emlrtRSI;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo y_emlrtRSI;
extern emlrtRSInfo ib_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
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
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo kc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo tc_emlrtRSI;
extern emlrtRSInfo uc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo ed_emlrtRSI;
extern emlrtRSInfo fd_emlrtRSI;
extern emlrtRSInfo gd_emlrtRSI;
extern emlrtRSInfo ld_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo wd_emlrtRSI;
extern emlrtRSInfo xd_emlrtRSI;
extern emlrtRSInfo ae_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo me_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo pe_emlrtRSI;
extern emlrtRSInfo qe_emlrtRSI;
extern emlrtRSInfo re_emlrtRSI;
extern emlrtRSInfo se_emlrtRSI;
extern emlrtRSInfo te_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo of_emlrtRSI;
extern emlrtRSInfo qf_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo kg_emlrtRSI;
extern emlrtRSInfo mi_emlrtRSI;
extern emlrtRSInfo ni_emlrtRSI;
extern emlrtRSInfo oi_emlrtRSI;
extern emlrtRSInfo ui_emlrtRSI;
extern emlrtRSInfo vi_emlrtRSI;
extern emlrtRSInfo wi_emlrtRSI;
extern emlrtRSInfo xi_emlrtRSI;
extern emlrtRSInfo fj_emlrtRSI;
extern emlrtRSInfo gj_emlrtRSI;
extern emlrtRSInfo nl_emlrtRSI;
extern emlrtRSInfo ol_emlrtRSI;
extern emlrtRSInfo ql_emlrtRSI;
extern emlrtRSInfo rl_emlrtRSI;
extern emlrtRSInfo tl_emlrtRSI;
extern emlrtRSInfo bm_emlrtRSI;
extern emlrtRSInfo im_emlrtRSI;
extern emlrtRSInfo km_emlrtRSI;
extern emlrtRSInfo lm_emlrtRSI;
extern emlrtRSInfo nm_emlrtRSI;
extern emlrtRSInfo pm_emlrtRSI;
extern emlrtRSInfo qm_emlrtRSI;
extern emlrtRSInfo rm_emlrtRSI;
extern emlrtRSInfo wm_emlrtRSI;
extern emlrtRSInfo xm_emlrtRSI;
extern emlrtRSInfo bn_emlrtRSI;
extern emlrtRSInfo cn_emlrtRSI;
extern emlrtRSInfo dn_emlrtRSI;
extern emlrtRSInfo en_emlrtRSI;
extern emlrtRSInfo ko_emlrtRSI;
extern emlrtRSInfo lo_emlrtRSI;
extern emlrtRSInfo mo_emlrtRSI;
extern emlrtRSInfo no_emlrtRSI;
extern emlrtRSInfo po_emlrtRSI;
extern emlrtRSInfo to_emlrtRSI;
extern emlrtRSInfo wo_emlrtRSI;
extern emlrtRSInfo xo_emlrtRSI;
extern emlrtRSInfo bp_emlrtRSI;
extern emlrtRSInfo cp_emlrtRSI;
extern emlrtRSInfo fr_emlrtRSI;
extern emlrtRSInfo os_emlrtRSI;
extern emlrtRSInfo ju_emlrtRSI;
extern emlrtRSInfo ku_emlrtRSI;
extern emlrtRSInfo lu_emlrtRSI;
extern emlrtRSInfo mu_emlrtRSI;
extern emlrtRSInfo nu_emlrtRSI;
extern emlrtRSInfo ou_emlrtRSI;
extern emlrtRSInfo pu_emlrtRSI;
extern emlrtRSInfo ru_emlrtRSI;
extern emlrtRSInfo cy_emlrtRSI;
extern emlrtRSInfo fy_emlrtRSI;
extern emlrtRSInfo gy_emlrtRSI;
extern emlrtRSInfo iy_emlrtRSI;
extern emlrtRSInfo ky_emlrtRSI;
extern emlrtRSInfo sy_emlrtRSI;
extern emlrtRSInfo vy_emlrtRSI;
extern emlrtRSInfo wy_emlrtRSI;
extern emlrtRSInfo xy_emlrtRSI;
extern emlrtRSInfo yy_emlrtRSI;
extern emlrtRSInfo gab_emlrtRSI;
extern emlrtRSInfo hab_emlrtRSI;
extern emlrtRSInfo iab_emlrtRSI;
extern emlrtRSInfo sab_emlrtRSI;
extern emlrtMCInfo c_emlrtMCI;
extern emlrtRTEInfo b_emlrtRTEI;
extern emlrtRTEInfo c_emlrtRTEI;
extern emlrtRTEInfo d_emlrtRTEI;
extern emlrtRTEInfo e_emlrtRTEI;
extern emlrtRTEInfo f_emlrtRTEI;
extern emlrtRTEInfo g_emlrtRTEI;
extern emlrtECInfo d_emlrtECI;
extern emlrtECInfo e_emlrtECI;
extern emlrtECInfo f_emlrtECI;
extern emlrtECInfo g_emlrtECI;
extern emlrtECInfo h_emlrtECI;
extern emlrtECInfo i_emlrtECI;
extern emlrtECInfo j_emlrtECI;
extern emlrtECInfo k_emlrtECI;
extern emlrtRTEInfo j_emlrtRTEI;
extern emlrtBCInfo m_emlrtBCI;
extern emlrtBCInfo n_emlrtBCI;
extern emlrtBCInfo o_emlrtBCI;
extern emlrtBCInfo p_emlrtBCI;
extern emlrtRTEInfo l_emlrtRTEI;
extern emlrtDCInfo c_emlrtDCI;
extern emlrtRTEInfo p_emlrtRTEI;
extern emlrtRTEInfo s_emlrtRTEI;
extern emlrtRTEInfo u_emlrtRTEI;
extern emlrtRTEInfo v_emlrtRTEI;
extern emlrtRTEInfo ab_emlrtRTEI;
extern emlrtRTEInfo bb_emlrtRTEI;
extern emlrtRTEInfo db_emlrtRTEI;
extern emlrtRTEInfo eb_emlrtRTEI;
extern emlrtRTEInfo kb_emlrtRTEI;
extern emlrtRTEInfo lb_emlrtRTEI;
extern emlrtRTEInfo mb_emlrtRTEI;
extern emlrtRTEInfo tb_emlrtRTEI;
extern emlrtRTEInfo ub_emlrtRTEI;
extern emlrtRTEInfo yb_emlrtRTEI;
extern emlrtRTEInfo qc_emlrtRTEI;
extern emlrtRTEInfo rc_emlrtRTEI;
extern emlrtRTEInfo sc_emlrtRTEI;
extern emlrtRTEInfo tc_emlrtRTEI;
extern emlrtRTEInfo uc_emlrtRTEI;
extern emlrtRTEInfo vc_emlrtRTEI;
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
extern emlrtRTEInfo ie_emlrtRTEI;
extern emlrtRTEInfo je_emlrtRTEI;
extern emlrtRTEInfo ke_emlrtRTEI;
extern emlrtRTEInfo le_emlrtRTEI;
extern emlrtRTEInfo me_emlrtRTEI;
extern emlrtRTEInfo ne_emlrtRTEI;
extern emlrtRTEInfo oe_emlrtRTEI;
extern emlrtRTEInfo pe_emlrtRTEI;
extern emlrtRTEInfo te_emlrtRTEI;
extern emlrtRTEInfo df_emlrtRTEI;
extern emlrtRTEInfo hf_emlrtRTEI;
extern emlrtRTEInfo kf_emlrtRTEI;
extern emlrtRTEInfo lf_emlrtRTEI;
extern emlrtRTEInfo mf_emlrtRTEI;
extern emlrtRTEInfo nf_emlrtRTEI;
extern emlrtRTEInfo of_emlrtRTEI;
extern emlrtRTEInfo pf_emlrtRTEI;
extern emlrtRTEInfo xf_emlrtRTEI;
extern emlrtRTEInfo ch_emlrtRTEI;
extern emlrtRTEInfo dh_emlrtRTEI;
extern emlrtRTEInfo tj_emlrtRTEI;
extern emlrtRTEInfo uk_emlrtRTEI;
extern emlrtRTEInfo il_emlrtRTEI;
extern emlrtRTEInfo tn_emlrtRTEI;
extern emlrtRTEInfo pr_emlrtRTEI;
extern emlrtRTEInfo qr_emlrtRTEI;
extern emlrtRTEInfo vr_emlrtRTEI;
extern const real_T dv[841];
extern const char_T cv[14];
extern const char_T cv1[14];
extern const char_T cv2[14];
extern emlrtRSInfo xdb_emlrtRSI;
extern covrtInstance emlrtCoverageInstance;

// End of code generation (ComputeCamExtrinsics_mex_data.h)
