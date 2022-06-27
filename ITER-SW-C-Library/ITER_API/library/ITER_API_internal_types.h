//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef ITER_API_INTERNAL_TYPES_H
#define ITER_API_INTERNAL_TYPES_H

// Include Files
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct struct_T {
  int ldq;
  double QR[15][15];
  double Q[15][15];
  int jpvt[15];
  int mrows;
  int ncols;
  double tau[15];
  int minRowCol;
  bool usedPivoting;
};

struct b_struct_T {
  double workspace_double[8][15];
  int workspace_int[15];
  int workspace_sort[15];
};

struct c_struct_T {
  bool gradOK;
  bool fevalOK;
  bool done;
  bool stepAccepted;
  bool failedLineSearch;
  int stepType;
};

struct d_struct_T {
  char SolverName[7];
  int MaxIterations;
  double StepTolerance;
  double OptimalityTolerance;
  double ConstraintTolerance;
  double ObjectiveLimit;
  double PricingTolerance;
  double ConstrRelTolFactor;
  double ProbRelTolFactor;
  bool RemainFeasible;
  bool IterDisplayQP;
};

struct cell_wrap_19 {
  coder::array<double, 2U> f1;
};

struct e_struct_T {
  coder::array<bool, 2U> bw;
};

struct i_struct_T {
  int nVarMax;
  int mNonlinIneq;
  int mNonlinEq;
  int mIneq;
  int mEq;
  int iNonIneq0;
  int iNonEq0;
  double sqpFval;
  double sqpFval_old;
  double xstarsqp[7];
  double xstarsqp_old[7];
  double grad[8];
  double grad_old[8];
  int FunctionEvaluations;
  int sqpIterations;
  int sqpExitFlag;
  double lambdasqp[15];
  double lambdaStopTest[15];
  double lambdaStopTestPrev[15];
  double steplength;
  double delta_x[8];
  double socDirection[8];
  int workingset_old[15];
  double gradLag[8];
  double delta_gradLag[8];
  double xstar[8];
  double fstar;
  double firstorderopt;
  double lambda[15];
  int state;
  double maxConstr;
  int iterations;
  double searchDir[8];
};

struct j_struct_T {
  int mConstr;
  int mConstrOrig;
  int mConstrMax;
  int nVar;
  int nVarOrig;
  int nVarMax;
  int ldA;
  double lb[8];
  double ub[8];
  int indexLB[8];
  int indexUB[8];
  int indexFixed[8];
  int mEqRemoved;
  double ATwset[120];
  double bwset[15];
  int nActiveConstr;
  double maxConstrWorkspace[15];
  int sizes[5];
  int sizesNormal[5];
  int sizesPhaseOne[5];
  int sizesRegularized[5];
  int sizesRegPhaseOne[5];
  int isActiveIdx[6];
  int isActiveIdxNormal[6];
  int isActiveIdxPhaseOne[6];
  int isActiveIdxRegularized[6];
  int isActiveIdxRegPhaseOne[6];
  bool isActiveConstr[15];
  int Wid[15];
  int Wlocalidx[15];
  int nWConstr[5];
  int probType;
  double SLACK0;
};

struct k_struct_T {
  coder::anonymous_function objfun;
  int nVar;
  int mCineq;
  int mCeq;
  bool NonFiniteSupport;
  bool SpecifyObjectiveGradient;
  bool SpecifyConstraintGradient;
  bool ScaleProblem;
};

struct o_struct_T {
  coder::anonymous_function objfun;
  double b_f_1;
  double f_2;
  int nVar;
  int mIneq;
  int mEq;
  int numEvals;
  bool SpecifyObjectiveGradient;
  bool SpecifyConstraintGradient;
  bool isEmptyNonlcon;
  bool hasLB[7];
  bool hasUB[7];
  bool hasBounds;
  int FiniteDifferenceType;
};

struct p_struct_T {
  double penaltyParam;
  double threshold;
  int nPenaltyDecreases;
  double linearizedConstrViol;
  double initFval;
  double initConstrViolationEq;
  double initConstrViolationIneq;
  double phi;
  double phiPrimePlus;
  double phiFullStep;
  double feasRelativeFactor;
  double nlpPrimalFeasError;
  double nlpDualFeasError;
  double nlpComplError;
  double b_firstOrderOpt;
  bool hasObjective;
};

struct r_struct_T {
  double grad[8];
  double Hx[7];
  bool hasLinear;
  int b_nvar;
  int maxVar;
  double beta;
  double rho;
  int objtype;
  int prev_objtype;
  int prev_nvar;
  bool prev_hasLinear;
  double gammaScalar;
};

struct s_struct_T {
  double FMat[15][15];
  int ldm;
  int ndims;
  int info;
  double scaleFactor;
  bool ConvexCheck;
  double regTol_;
  double b_workspace_;
  double workspace2_;
};

struct t_struct_T {
  coder::c_anonymous_function nonlin;
  double b_f_1;
  coder::array<double, 1U> cEq_1;
  double f_2;
  coder::array<double, 1U> cEq_2;
  int nVar;
  int mIneq;
  int mEq;
  int numEvals;
  bool SpecifyObjectiveGradient;
  bool SpecifyConstraintGradient;
  bool isEmptyNonlcon;
  coder::array<bool, 1U> hasLB;
  coder::array<bool, 1U> hasUB;
  bool hasBounds;
  int FiniteDifferenceType;
};

#endif
//
// File trailer for ITER_API_internal_types.h
//
// [EOF]
//
