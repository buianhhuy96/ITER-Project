//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationTree.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

// Include Files
#include "ITER_API_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  static void b_transform(coderutils::Transform c_transform,
                          const ::coder::array<double, 2U> &scoresIn,
                          ::coder::array<double, 2U> &scoresOut);
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  double CutPredictorIndex[15];
  double Children[15][2];
  double CutPoint[15];
  bool NanCutPoints[15];
  bool InfCutPoints[15];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][15];
};

class b_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void m_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  void u_init();
  void v_init();
  void w_init();
  void x_init();
  void y_init();
  double CutPredictorIndex[17];
  double Children[17][2];
  double CutPoint[17];
  bool NanCutPoints[17];
  bool InfCutPoints[17];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][17];
};

class c_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void m_init();
  void o_init();
  void p_init();
  void q_init();
  void r_init();
  void s_init();
  void t_init();
  double CutPredictorIndex[19];
  double Children[19][2];
  double CutPoint[19];
  bool NanCutPoints[19];
  bool InfCutPoints[19];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][19];
};

class d_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  void m_init();
  void o_init();
  double CutPredictorIndex[13];
  double Children[13][2];
  double CutPoint[13];
  bool NanCutPoints[13];
  bool InfCutPoints[13];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][13];
};

class e_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  void i_init();
  void j_init();
  void k_init();
  double CutPredictorIndex[21];
  double Children[21][2];
  double CutPoint[21];
  bool NanCutPoints[21];
  bool InfCutPoints[21];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][21];
};

class f_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  double CutPredictorIndex[7];
  double Children[7][2];
  double CutPoint[7];
  bool NanCutPoints[7];
  bool InfCutPoints[7];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][7];
};

class g_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  void g_init();
  void h_init();
  double CutPredictorIndex[11];
  double Children[11][2];
  double CutPoint[11];
  bool NanCutPoints[11];
  bool InfCutPoints[11];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][11];
};

class h_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  void f_init();
  double CutPredictorIndex[25];
  double Children[25][2];
  double CutPoint[25];
  bool NanCutPoints[25];
  bool InfCutPoints[25];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][25];
};

class i_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  void c_init();
  void d_init();
  void e_init();
  double CutPredictorIndex[23];
  double Children[23][2];
  double CutPoint[23];
  bool NanCutPoints[23];
  bool InfCutPoints[23];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][23];
};

class j_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[27];
  double Children[27][2];
  double CutPoint[27];
  bool NanCutPoints[27];
  bool InfCutPoints[27];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][27];
};

class k_CompactClassificationTree {
public:
  void init();
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &scores) const;
  void b_init();
  double CutPredictorIndex[9];
  double Children[9][2];
  double CutPoint[9];
  bool NanCutPoints[9];
  bool InfCutPoints[9];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
  double ClassProbability[2][9];
};

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for CompactClassificationTree.h
//
// [EOF]
//
