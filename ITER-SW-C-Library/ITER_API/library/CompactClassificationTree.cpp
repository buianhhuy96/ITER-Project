//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationTree.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "CompactClassificationTree.h"
#include "ITER_API_data.h"
#include "ITER_API_internal_types.h"
#include "invlogit.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Variable Definitions
namespace ITER
{
  static const double dv1[2]{ 0.12875536480686695, 0.871244635193133 };

  static const signed char iv1[11][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 6, 7 }, {
      8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

  static const bool bv[11]{ false, true, false, false, false, true, true, false,
    true, true, true };

  static const signed char iv2[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 0, 0 }, {
      6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
      0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 } };

  static const bool bv1[17]{ false, true, false, true, false, false, true, false,
    false, true, true, true, false, true, false, true, true };

  static const signed char iv3[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 6, 7 }, {
      8, 9 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
      0, 0 }, { 0, 0 } };

  static const bool bv2[13]{ false, true, false, false, false, true, true, true,
    false, true, false, true, true };

  static const signed char iv4[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 }, { 0, 0 }, {
      8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, { 14, 15 },
      { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 0, 0 },
      { 0, 0 } };

  static const bool bv3[19]{ false, false, false, true, false, false, true, true,
    false, true, false, true, true, true, false, true, false, true, true };

  static const signed char iv5[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 0, 0 }, {
      6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, {
      0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 } };

  static const bool bv4[17]{ false, true, false, true, false, false, false, true,
    true, true, false, true, false, true, false, true, true };

  static const signed char iv6[9][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 0, 0 }, {
      6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

  static const bool bv5[9]{ false, true, false, true, false, false, true, true,
    true };

  static const signed char iv7[21][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 0, 0 }, {
      6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, {
      0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 18, 19 }, { 0, 0 }, { 0, 0 },
      { 20, 21 }, { 0, 0 }, { 0, 0 } };

  static const bool bv6[21]{ false, true, false, true, false, false, false, true,
    true, true, false, true, false, true, false, false, true, true, false, true,
    true };

  static const signed char iv8[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 }, { 6, 7 }, {
      8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
      0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 } };

  static const bool bv7[17]{ false, true, false, false, false, false, true, true,
    false, true, true, true, false, true, false, true, true };
}

// Function Definitions
//
// Arguments    : coderutils::Transform c_transform
//                const ::coder::array<double, 2U> &scoresIn
//                ::coder::array<double, 2U> &scoresOut
// Return Type  : void
//
namespace ITER
{
  namespace coder
  {
    namespace classreg
    {
      namespace learning
      {
        namespace classif
        {
          void CompactClassificationTree::b_transform(coderutils::Transform
            c_transform, const ::coder::array<double, 2U> &scoresIn, ::coder::
            array<double, 2U> &scoresOut)
          {
            int i12;
            int i13;
            int i14;
            int i15;
            switch (c_transform) {
             case coderutils::Logit:
              {
                int b_i;
                int i4;
                scoresOut.set_size(scoresIn.size(0), 2);
                b_i = (scoresIn.size(0) * 2) - 1;
                i4 = b_i;
                if ((static_cast<int>((b_i + 1) < 4)) != 0) {
                  for (int c_i{0}; c_i <= b_i; c_i++) {
                    scoresOut[c_i] = 1.0 / (std::exp(-scoresIn[c_i]) + 1.0);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int c_i = 0; c_i <= i4; c_i++) {
                    scoresOut[c_i] = 1.0 / (std::exp(-scoresIn[c_i]) + 1.0);
                  }
                }
              }
              break;

             case coderutils::Doublelogit:
              {
                int i1;
                int i5;
                scoresOut.set_size(scoresIn.size(0), 2);
                i1 = (scoresIn.size(0) * 2) - 1;
                i5 = i1;
                if ((static_cast<int>((i1 + 1) < 4)) != 0) {
                  for (int d_i{0}; d_i <= i1; d_i++) {
                    scoresOut[d_i] = 1.0 / (std::exp(-2.0 * scoresIn[d_i]) + 1.0);
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int d_i = 0; d_i <= i5; d_i++) {
                    scoresOut[d_i] = 1.0 / (std::exp(-2.0 * scoresIn[d_i]) + 1.0);
                  }
                }
              }
              break;

             case coderutils::Invlogit:
              coder::transform::b_invlogit(scoresIn, scoresOut);
              break;

             case coderutils::Ismax:
              {
                int b_loop_ub;
                int i16;
                scoresOut.set_size(scoresIn.size(0), 2);
                b_loop_ub = scoresIn.size(0);
                if ((static_cast<int>((scoresIn.size(0) * 2) < 4)) != 0) {
                  for (int i9{0}; i9 < 2; i9++) {
                    for (i13 = 0; i13 < b_loop_ub; i13++) {
                      scoresOut[i13 + (scoresOut.size(0) * i9)] = 0.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i13)

                  for (int i9 = 0; i9 < 2; i9++) {
                    for (i13 = 0; i13 < b_loop_ub; i13++) {
                      scoresOut[i13 + (scoresOut.size(0) * i9)] = 0.0;
                    }
                  }
                }

                i16 = scoresIn.size(0);
                for (int h_n{0}; h_n < i16; h_n++) {
                  int inmaxind;
                  inmaxind = 0;
                  if (scoresIn[h_n + scoresIn.size(0)] > scoresIn[h_n]) {
                    inmaxind = 1;
                  }

                  scoresOut[h_n + (scoresOut.size(0) * inmaxind)] = 1.0;
                }
              }
              break;

             case coderutils::b_Sign:
              {
                int i2;
                int i6;
                scoresOut.set_size(scoresIn.size(0), 2);
                i2 = (scoresIn.size(0) * 2) - 1;
                i6 = i2;
                if ((static_cast<int>((i2 + 1) < 4)) != 0) {
                  for (int e_i{0}; e_i <= i2; e_i++) {
                    if (scoresIn[e_i] < 0.0) {
                      scoresOut[e_i] = -1.0;
                    } else if (scoresIn[e_i] > 0.0) {
                      scoresOut[e_i] = 1.0;
                    } else {
                      scoresOut[e_i] = 0.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int e_i = 0; e_i <= i6; e_i++) {
                    if (scoresIn[e_i] < 0.0) {
                      scoresOut[e_i] = -1.0;
                    } else if (scoresIn[e_i] > 0.0) {
                      scoresOut[e_i] = 1.0;
                    } else {
                      scoresOut[e_i] = 0.0;
                    }
                  }
                }
              }
              break;

             case coderutils::Symmetric:
              {
                int c_loop_ub;
                scoresOut.set_size(scoresIn.size(0), 2);
                c_loop_ub = scoresIn.size(0);
                if ((static_cast<int>((scoresIn.size(0) * 2) < 4)) != 0) {
                  for (int i10{0}; i10 < 2; i10++) {
                    for (i14 = 0; i14 < c_loop_ub; i14++) {
                      scoresOut[i14 + (scoresOut.size(0) * i10)] = (2.0 *
                        scoresIn[i14 + (scoresIn.size(0) * i10)]) - 1.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                  for (int i10 = 0; i10 < 2; i10++) {
                    for (i14 = 0; i14 < c_loop_ub; i14++) {
                      scoresOut[i14 + (scoresOut.size(0) * i10)] = (2.0 *
                        scoresIn[i14 + (scoresIn.size(0) * i10)]) - 1.0;
                    }
                  }
                }
              }
              break;

             case coderutils::Symmetricismax:
              {
                int d_loop_ub;
                int i17;
                scoresOut.set_size(scoresIn.size(0), 2);
                d_loop_ub = scoresIn.size(0);
                if ((static_cast<int>((scoresIn.size(0) * 2) < 4)) != 0) {
                  for (int i11{0}; i11 < 2; i11++) {
                    for (i15 = 0; i15 < d_loop_ub; i15++) {
                      scoresOut[i15 + (scoresOut.size(0) * i11)] = -1.0;
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i15)

                  for (int i11 = 0; i11 < 2; i11++) {
                    for (i15 = 0; i15 < d_loop_ub; i15++) {
                      scoresOut[i15 + (scoresOut.size(0) * i11)] = -1.0;
                    }
                  }
                }

                i17 = scoresIn.size(0);
                for (int p_n{0}; p_n < i17; p_n++) {
                  int b_inmaxind;
                  b_inmaxind = 0;
                  if (scoresIn[p_n + scoresIn.size(0)] > scoresIn[p_n]) {
                    b_inmaxind = 1;
                  }

                  scoresOut[p_n + (scoresOut.size(0) * b_inmaxind)] = 1.0;
                }
              }
              break;

             case coderutils::Symmetriclogit:
              {
                int i3;
                int i7;
                scoresOut.set_size(scoresIn.size(0), 2);
                i3 = (scoresIn.size(0) * 2) - 1;
                i7 = i3;
                if ((static_cast<int>((i3 + 1) < 4)) != 0) {
                  for (int g_i{0}; g_i <= i3; g_i++) {
                    scoresOut[g_i] = (2.0 * (1.0 / (std::exp(-scoresIn[g_i]) +
                      1.0))) - 1.0;
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                  for (int g_i = 0; g_i <= i7; g_i++) {
                    scoresOut[g_i] = (2.0 * (1.0 / (std::exp(-scoresIn[g_i]) +
                      1.0))) - 1.0;
                  }
                }
              }
              break;

             default:
              {
                int loop_ub;
                scoresOut.set_size(scoresIn.size(0), 2);
                loop_ub = scoresIn.size(0);
                if ((static_cast<int>((scoresIn.size(0) * 2) < 4)) != 0) {
                  for (int b_i8{0}; b_i8 < 2; b_i8++) {
                    for (i12 = 0; i12 < loop_ub; i12++) {
                      scoresOut[i12 + (scoresOut.size(0) * b_i8)] = scoresIn[i12
                        + (scoresIn.size(0) * b_i8)];
                    }
                  }
                } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i12)

                  for (int b_i8 = 0; b_i8 < 2; b_i8++) {
                    for (i12 = 0; i12 < loop_ub; i12++) {
                      scoresOut[i12 + (scoresOut.size(0) * b_i8)] = scoresIn[i12
                        + (scoresIn.size(0) * b_i8)];
                    }
                  }
                }
              }
              break;
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void j_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][27]{ { 0.15879828326180315,
                0.888888888888889, 0.06310679611650509, 0.923076923076923, 0.0,
                1.0, 0.053921568627451177, 1.0, 0.6, 0.89999999999999991,
                0.010309278350515502, 1.0, 0.0, 0.0, 1.0, 0.099999999999999978,
                0.0054347826086956711, 1.0, 0.0, 0.0, 0.028571428571428553, 0.2,
                0.0, 0.0, 0.5, 0.0, 1.0 }, { 0.84120171673819688,
                0.11111111111111106, 0.936893203883495, 0.076923076923076886,
                1.0, 0.0, 0.94607843137254877, 0.0, 0.4, 0.099999999999999978,
                0.98969072164948457, 0.0, 1.0, 1.0, 0.0, 0.89999999999999991,
                0.99456521739130432, 0.0, 1.0, 1.0, 0.97142857142857142, 0.8,
                1.0, 1.0, 0.5, 1.0, 0.0 } };

            static const double b_dv[27]{ 0.91833333333333333,
              0.10782986030844129, 0.61010101010101, 1.1339161115625978, 0.0,
              0.0, 0.74617898441427855, 0.0, 0.601530612244898,
              0.79166666666666674, 0.68375000000000008, 0.0, 0.0, 0.0, 0.0,
              0.10250000000000001, 1.4206264937901973, 0.0, 0.0, 0.0,
              1.4241593551424103, 0.98333333333333339, 0.0, 0.0,
              0.94239350912778908, 0.0, 0.0 };

            static const signed char b_iv1[27][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                18, 19 }, { 20, 21 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 22, 23 },
                { 24, 25 }, { 0, 0 }, { 0, 0 }, { 26, 27 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[27]{ 3, 7, 4, 2, 0, 0, 5, 0, 4, 4, 4,
              0, 0, 0, 0, 1, 2, 0, 0, 0, 2, 3, 0, 0, 5, 0, 0 };

            static const bool b_bv[27]{ false, false, false, false, true, true,
              false, true, false, false, false, true, true, true, true, false,
              false, true, true, true, false, false, true, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 27; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 27; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void i_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][23]{ { 0.15450643776824091, 1.0,
                0.10454545454545494, 0.92857142857142849, 0.048543689320388529,
                1.0, 0.0, 0.034482758620689773, 1.0, 1.0, 0.024875621890547352,
                0.8, 0.0051020408163265493, 1.0, 0.0, 0.0, 0.018181818181818171,
                0.0, 0.14285714285714285, 0.5, 0.0, 1.0, 0.0 }, {
                0.84549356223175909, 0.0, 0.89545454545454506,
                0.071428571428571411, 0.95145631067961145, 0.0, 1.0,
                0.96551724137931016, 0.0, 0.0, 0.97512437810945263, 0.2,
                0.99489795918367352, 0.0, 1.0, 1.0, 0.98181818181818181, 1.0,
                0.8571428571428571, 0.5, 1.0, 0.0, 1.0 } };

            static const double b_dv[23]{ 0.0925, 0.0, 0.91596045197740117,
              0.70430672268907557, 0.49, 0.0, 0.0, -0.3104525542231954, 0.0, 0.0,
              0.70841503267973849, 0.15430870006017719, 0.97913823836744718, 0.0,
              0.0, 0.0, 0.069422891913429485, 0.0, 0.15, 0.83611111111111114,
              0.0, 0.0, 0.0 };

            static const signed char b_iv1[23][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 22, 23 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[23]{ 1, 0, 3, 4, 1, 0, 0, 7, 0, 0, 5,
              8, 5, 0, 0, 0, 7, 0, 1, 4, 0, 0, 0 };

            static const bool b_bv[23]{ false, true, false, false, false, true,
              true, false, true, true, false, false, false, true, true, true,
              false, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 23; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 23; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.69098712446351929 * (static_cast<double>(b_kk)))
                + 0.15450643776824036;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][21]{ { 0.12875536480686745, 1.0,
                0.060185185185185418, 1.0, 0.028708133971291971,
                0.013157894736842146, 0.070175438596491183, 0.048780487804878016,
                0.0, 0.6, 0.019230769230769218, 0.4, 0.0, 0.0, 1.0,
                0.083333333333333315, 0.0, 1.0, 0.0, 1.0, 0.0 }, {
                0.87124463519313255, 0.0, 0.93981481481481455, 0.0,
                0.9712918660287081, 0.986842105263158, 0.92982456140350878,
                0.95121951219512191, 1.0, 0.4, 0.98076923076923073, 0.6, 1.0,
                1.0, 0.0, 0.91666666666666663, 1.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.89146782953160164, 0.0, 0.0825, 0.0,
              0.1020704819559759, 0.95311355311355306, 0.71954248366013074,
              0.1125, 0.0, 0.47988823352285809, 0.1475, 0.73333333333333339, 0.0,
              0.0, 0.0, 0.10321408363818549, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, {
                14, 15 }, { 16, 17 }, { 18, 19 }, { 0, 0 }, { 0, 0 }, { 0, 0 },
                { 20, 21 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 2, 0, 1, 0, 8, 3, 5, 1, 0, 5, 1,
              4, 0, 0, 0, 8, 0, 0, 0, 0, 0 };

            static const bool b_bv[21]{ false, true, false, true, false, false,
              false, false, true, false, false, false, true, true, true, false,
              true, true, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][15]{ { 0.14163090128755418, 1.0,
                0.099099099099099475, 1.0, 0.038461538461538596,
                0.024390243902439112, 1.0, 0.4, 0.015000000000000053, 1.0, 0.0,
                0.0, 0.11538461538461534, 1.0, 0.0 }, { 0.85836909871244582, 0.0,
                0.90090090090090058, 0.0, 0.96153846153846134, 0.975609756097561,
                0.0, 0.6, 0.98499999999999988, 0.0, 1.0, 1.0,
                0.88461538461538469, 0.0, 1.0 } };

            static const double b_dv[15]{ 0.0925, 0.0, 0.89518679155439274, 0.0,
              0.92428571428571438, 0.10500000000000001, 0.0, 0.73333333333333339,
              0.83503401360544216, 0.0, 0.0, 0.0, 0.70669381836133349, 0.0, 0.0
            };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 1, 0, 2, 0, 4, 1, 0, 4, 4, 0, 0,
              0, 5, 0, 0 };

            static const bool b_bv[15]{ false, true, false, true, false, false,
              true, false, false, true, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][11]{ { 0.16309012875536541, 1.0,
                0.053398058252427376, 1.0, 0.039408866995074031, 1.0,
                0.020100502512562887, 0.8, 0.0, 0.0, 1.0 }, {
                0.83690987124463467, 0.0, 0.94660194174757251, 0.0,
                0.96059113300492593, 0.0, 0.9798994974874371, 0.2, 1.0, 1.0, 0.0
              } };

            static const double b_dv[11]{ 0.63208616780045346, 0.0,
              0.91349206349206347, 0.0, 0.0825, 0.0, 0.63877450980392159,
              1.2331338170279325, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 4, 0, 3, 0, 1, 0, 5, 2, 0, 0, 0 };

            static const bool b_bv[11]{ false, true, false, true, false, true,
              false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][25]{ { 0.14163090128755418,
                0.696969696969697, 0.050000000000000183, 1.0, 0.5, 1.0,
                0.02564102564102573, 1.0, 0.090909090909090884, 1.0,
                0.015544041450777257, 0.2, 0.0, 0.010416666666666704, 1.0, 1.0,
                0.0, 0.0, 0.05882352941176467, 0.2, 0.0, 0.0,
                0.66666666666666663, 0.0, 1.0 }, { 0.85836909871244582,
                0.30303030303030293, 0.94999999999999984, 0.0, 0.5, 0.0,
                0.97435897435897423, 0.0, 0.90909090909090906, 0.0,
                0.98445595854922274, 0.8, 1.0, 0.98958333333333337, 0.0, 0.0,
                1.0, 1.0, 0.94117647058823528, 0.8, 1.0, 1.0,
                0.33333333333333331, 1.0, 0.0 } };

            static const double b_dv[25]{ 0.84600804424333842,
              0.70833333333333326, 0.63208616780045346, 0.0, 0.095, 0.0,
              0.8981900452488687, 0.0, 0.195, 0.0, 0.49749999999999994,
              0.68292483660130721, 0.0, 1.4206264937901973, 0.0, 0.0, 0.0, 0.0,
              1.4241593551424103, 0.98333333333333339, 0.0, 0.0,
              0.030589196429267409, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 20, 21 }, { 22, 23 }, { 0, 0 },
                { 0, 0 }, { 24, 25 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 5, 4, 4, 0, 1, 0, 3, 0, 1, 0, 1,
              5, 0, 2, 0, 0, 0, 0, 2, 3, 0, 0, 7, 0, 0 };

            static const bool b_bv[25]{ false, false, false, true, false, true,
              false, true, false, true, false, false, true, false, true, true,
              true, true, false, false, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][13]{ { 0.17596566523605212,
                0.85294117647058842, 0.060301507537688662, 0.0,
                0.93548387096774188, 0.015789473684210582, 1.0, 0.0, 1.0, 1.0,
                0.01058201058201062, 1.0, 0.0 }, { 0.82403433476394783,
                0.14705882352941171, 0.9396984924623113, 1.0,
                0.064516129032258021, 0.98421052631578942, 0.0, 1.0, 0.0, 0.0,
                0.98941798941798942, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.84600804424333842,
              -0.17418049357378684, 0.42000000000000004, 0.0, 0.4242137310764762,
              0.866413430861722, 0.0, 0.0, 0.0, 0.0, 0.0925, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 5, 8, 1, 0, 5, 2, 0, 0, 0, 0, 1,
              0, 0 };

            static const bool b_bv[13]{ false, false, false, true, false, false,
              true, true, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.648068669527897 * (static_cast<double>(b_kk))) +
                0.17596566523605151;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][17]{ { 0.1244635193133052,
                0.78947368421052633, 0.065420560747663808, 0.0,
                0.88235294117647056, 1.0, 0.0049751243781094709, 0.0, 1.0,
                0.015873015873015869, 0.0, 0.0, 0.16666666666666666, 0.0, 0.5,
                0.0, 1.0 }, { 0.87553648068669476, 0.21052631578947362,
                0.93457943925233622, 1.0, 0.11764705882352935, 0.0,
                0.99502487562189057, 1.0, 0.0, 0.98412698412698418, 1.0, 1.0,
                0.83333333333333337, 1.0, 0.5, 1.0, 0.0 } };

            static const double b_dv[17]{ 0.68292483660130721,
              0.40755783794999478, 0.91587239086203553, 0.0,
              -0.13020172346382736, 0.0, 0.1475, 0.0, 0.0, 0.071900528125343977,
              0.0, 0.0, 1.4132363606378191, 0.0, 0.970136455836253, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12,
                13 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 5, 2, 0, 7, 0, 1, 0, 0, 7, 0,
              0, 2, 0, 5, 0, 0 };

            static const bool b_bv[17]{ false, false, false, true, false, true,
              false, true, true, false, true, true, false, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][19]{ { 0.12017167381974295, 1.0,
                0.063926940639269653, 0.8, 0.028708133971291971, 0.0, 1.0, 1.0,
                0.019323671497584613, 0.044943820224719155, 0.0, 1.0,
                0.022988505747126464, 0.0, 0.045454545454545421, 0.0,
                0.22222222222222221, 0.0, 1.0 }, { 0.87982832618025708, 0.0,
                0.93607305936073038, 0.2, 0.9712918660287081, 1.0, 0.0, 0.0,
                0.98067632850241537, 0.95505617977528079, 1.0, 0.0,
                0.97701149425287348, 1.0, 0.95454545454545459, 1.0,
                0.77777777777777768, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.0925, 0.0, 0.91596045197740117,
              0.070244231542525279, 0.87121720128794056, 0.0, 0.0, 0.0, 0.1525,
              0.70841503267973849, 0.0, 0.0, 1.4132363606378191, 0.0,
              0.97766422218754867, 0.0, 0.059014082294321438, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 1, 0, 3, 8, 2, 0, 0, 0, 1, 5, 0,
              0, 2, 0, 5, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, false, true,
              true, true, false, false, true, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.759656652360515 * (static_cast<double>(b_kk))) +
                0.12017167381974249;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void k_CompactClassificationTree::b_init()
          {
            static const double b_dv1[2][9]{ { 0.1244635193133052, 1.0,
                0.059907834101382715, 1.0, 0.0192307692307693,
                0.66666666666666663, 0.0, 0.0, 1.0 }, { 0.87553648068669476, 0.0,
                0.94009216589861733, 0.0, 0.98076923076923073,
                0.33333333333333331, 1.0, 1.0, 0.0 } };

            static const double b_dv[9]{ 0.09, 0.0, 0.84021126200879515, 0.0,
              0.68517973856209147, 1.2806160168613097, 0.0, 0.0, 0.0 };

            static const signed char b_iv[9]{ 1, 0, 2, 0, 5, 2, 0, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 9; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv6[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv6[b_i][1]);
              NanCutPoints[b_i] = bv5[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 9; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void i_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][23]{ { 0.12875536480686745,
                0.83333333333333337, 0.04784688995215329, 0.0,
                0.90909090909090906, 0.7142857142857143, 0.02475247524752484,
                1.0, 0.5, 0.5, 1.0, 1.0, 0.015000000000000053, 1.0, 0.0, 1.0,
                0.0, 1.0, 0.010050251256281444, 0.0, 0.038461538461538436, 1.0,
                0.0 }, { 0.87124463519313255, 0.1666666666666666,
                0.95215311004784675, 1.0, 0.090909090909090856,
                0.2857142857142857, 0.97524752475247523, 0.0, 0.5, 0.5, 0.0, 0.0,
                0.98499999999999988, 0.0, 1.0, 0.0, 1.0, 0.0,
                0.98994974874371866, 1.0, 0.96153846153846156, 0.0, 1.0 } };

            static const double b_dv[23]{ 0.84600804424333842,
              0.40755783794999478, 0.91762711864406787, 0.0, 0.83305272019362309,
              0.984932211313698, 0.90100180447745748, 0.0, 0.91895424836601314,
              0.1075, 0.0, 0.0, 0.095, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.97913823836744718, 0.0, 0.97948814263892015, 0.0, 0.0 };

            static const signed char b_iv1[23][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 14, 15 },
                { 16, 17 }, { 0, 0 }, { 0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 },
                { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[23]{ 5, 5, 3, 0, 5, 5, 2, 0, 3, 1, 0,
              0, 1, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0 };

            static const bool b_bv[23]{ false, false, false, true, false, false,
              false, true, false, false, true, true, false, true, true, true,
              true, true, false, true, false, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 23; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 23; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][15]{ { 0.18454935622317661, 1.0,
                0.059405940594059618, 0.62500000000000011, 0.01075268817204305,
                1.0, 0.14285714285714285, 0.0, 0.047619047619047589, 0.0, 0.5,
                1.0, 0.0, 0.0, 1.0 }, { 0.81545064377682341, 0.0,
                0.94059405940594032, 0.375, 0.989247311827957, 0.0,
                0.8571428571428571, 1.0, 0.95238095238095233, 1.0, 0.5, 0.0, 1.0,
                1.0, 0.0 } };

            static const double b_dv[15]{ 0.89953678983356467, 0.0,
              0.80173054070112881, 0.11, 1.4115793345695291, 0.0,
              1.3757920942713162, 0.0, 0.72888888888888892, 0.0, 0.14, 0.0, 0.0,
              0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 2, 0, 5, 1, 2, 0, 2, 0, 4, 0, 1,
              0, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, false, false, true,
              false, true, false, true, false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.63090128755364816 * (static_cast<double>(b_kk)))
                + 0.18454935622317598;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][11]{ { 0.12875536480686745,
                0.88000000000000012, 0.038461538461538596, 1.0, 0.625, 1.0,
                0.0049751243781094709, 1.0, 0.0, 1.0, 0.0 }, {
                0.87124463519313255, 0.11999999999999995, 0.96153846153846134,
                0.0, 0.375, 0.0, 0.99502487562189057, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[11]{ 0.83305272019362309,
              1.3609488352758139, 0.92406838360406507, 0.0, 0.70841503267973849,
              0.0, 0.0925, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 5, 2, 2, 0, 5, 0, 1, 0, 0, 0, 0 };

            static const bool b_bv[11]{ false, false, false, true, false, true,
              false, true, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][17]{ { 0.18025751072961438, 1.0,
                0.10747663551401909, 1.0, 0.077294685990338452,
                0.65000000000000013, 0.016042780748663155, 0.3, 1.0,
                0.14999999999999994, 0.0, 1.0, 0.125, 1.0, 0.0, 0.0, 1.0 }, {
                0.81974248927038562, 0.0, 0.892523364485981, 0.0,
                0.92270531400966149, 0.34999999999999992, 0.98395721925133683,
                0.7, 0.0, 0.85000000000000009, 1.0, 0.0, 0.875, 0.0, 1.0, 1.0,
                0.0 } };

            static const double b_dv[17]{ 0.90949060036385687, 0.0,
              0.88984996360278412, 0.0, 0.70841503267973849, 0.51516954360091616,
              0.68027777777777776, -0.29155790226991007, 0.0,
              0.11000000000000001, 0.0, 0.0, 1.4703205667261163, 0.0, 0.0, 0.0,
              0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 3, 0, 2, 0, 5, 5, 4, 7, 0, 1, 0,
              0, 2, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, true, false, true, false, false,
              false, false, true, false, true, true, false, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.63948497854077258 * (static_cast<double>(b_kk)))
                + 0.18025751072961374;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][25]{ { 0.19742489270386335, 1.0,
                0.12616822429906588, 1.0, 0.10096153846153884, 1.0,
                0.060301507537688662, 1.0, 0.055555555555555754,
                0.33333333333333331, 0.037634408602150664, 0.0, 1.0, 1.0,
                0.032432432432432545, 0.0, 0.099999999999999936, 1.0,
                0.018181818181818171, 0.0, 0.0769230769230769, 0.0, 0.25, 1.0,
                0.0 }, { 0.80257510729613668, 0.0, 0.87383177570093407, 0.0,
                0.89903846153846112, 0.0, 0.9396984924623113, 0.0,
                0.9444444444444442, 0.66666666666666663, 0.96236559139784927,
                1.0, 0.0, 0.0, 0.96756756756756745, 1.0, 0.90000000000000013,
                0.0, 0.98181818181818181, 1.0, 0.923076923076923, 1.0, 0.75, 0.0,
                1.0 } };

            static const double b_dv[25]{ 0.909163802978236, 0.0,
              0.60425685425685427, 0.0, 0.0925, 0.0, 0.89518679155439274, 0.0,
              0.66927083333333326, 1.3256943931743947, -0.29155790226991007, 0.0,
              0.0, 0.0, 0.80456349206349209, 0.0, 0.74617898441427855, 0.0,
              0.10164380064021053, 0.0, 0.98837209302325579, 0.0,
              0.83333333333333337, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 }, { 0,
                0 }, { 24, 25 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 3, 0, 4, 0, 1, 0, 2, 0, 4, 2, 7,
              0, 0, 0, 4, 0, 5, 0, 8, 0, 3, 0, 4, 0, 0 };

            static const bool b_bv[25]{ false, true, false, true, false, true,
              false, true, false, false, false, true, true, true, false, true,
              false, true, false, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.60515021459227469 * (static_cast<double>(b_kk)))
                + 0.19742489270386265;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][19]{ { 0.16738197424892762,
                0.787878787878788, 0.065000000000000238, 0.96153846153846156,
                0.14285714285714285, 0.020942408376963425, 1.0, 1.0,
                0.923076923076923, 1.0, 0.0, 1.0, 0.01058201058201062, 0.0, 1.0,
                0.0, 0.071428571428571383, 1.0, 0.0 }, { 0.83261802575107235,
                0.21212121212121204, 0.93499999999999972, 0.038461538461538443,
                0.8571428571428571, 0.97905759162303652, 0.0, 0.0,
                0.0769230769230769, 0.0, 1.0, 0.0, 0.98941798941798942, 1.0, 0.0,
                1.0, 0.9285714285714286, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.83305272019362309,
              0.16624391843619052, 0.435, 1.2026636357213709,
              0.89791892390474715, 0.09, 0.0, 0.0, -0.17447330093742128, 0.0,
              0.0, 0.0, 0.073822651979343984, 0.0, 0.0, 0.0,
              0.074626002628498389, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, { 14, 15 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 5, 8, 1, 2, 2, 1, 0, 0, 8, 0, 0,
              0, 7, 0, 0, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, false, false, false, false, false,
              true, true, false, true, true, true, false, true, true, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.66523605150214582 * (static_cast<double>(b_kk)))
                + 0.16738197424892703;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][13]{ { 0.15879828326180315, 1.0,
                0.071090047393365191, 1.0, 0.029702970297029809,
                0.7142857142857143, 0.0051282051282051473, 1.0, 0.0, 0.0,
                0.038461538461538443, 1.0, 0.0 }, { 0.84120171673819688, 0.0,
                0.92890995260663478, 0.0, 0.97029702970297027,
                0.2857142857142857, 0.99487179487179489, 0.0, 1.0, 1.0,
                0.96153846153846156, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.89791892390474715, 0.0, 0.0925, 0.0,
              0.70841503267973849, 0.2375, 0.073822651979343984, 0.0, 0.0, 0.0,
              0.074395283670663309, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 2, 0, 1, 0, 5, 1, 7, 0, 0, 0, 7,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, true, false, false,
              false, true, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::c_init()
          {
            static const double b_dv1[2][21]{ { 0.17167381974248988,
                0.84375000000000011, 0.064676616915423119, 0.0,
                0.9642857142857143, 1.0, 0.03589743589743602, 1.0, 0.5, 1.0,
                0.020833333333333405, 1.0, 0.0, 1.0, 0.00529100529100531, 0.0,
                0.023255813953488358, 0.0769230769230769, 0.0, 0.0, 1.0 }, {
                0.82832618025751015, 0.15624999999999994, 0.93532338308457685,
                1.0, 0.035714285714285691, 0.0, 0.9641025641025639, 0.0, 0.5,
                0.0, 0.97916666666666663, 0.0, 1.0, 0.0, 0.99470899470899476,
                1.0, 0.97674418604651159, 0.923076923076923, 1.0, 1.0, 0.0 } };

            static const double b_dv[21]{ 0.83227752639517338,
              -0.17418049357378684, 0.91349206349206347, 0.0,
              0.16820026441433156, 0.0, 0.09, 0.0, 0.89791892390474715, 0.0,
              0.90234518344402359, 0.0, 0.0, 0.0, 0.990909090909091, 0.0,
              0.80753968253968256, 0.80456349206349209, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 20, 21 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 8, 3, 0, 8, 0, 1, 0, 2, 0, 2,
              0, 0, 0, 3, 0, 4, 4, 0, 0, 0 };

            static const bool b_bv[21]{ false, false, false, true, false, true,
              false, true, false, true, false, true, true, true, false, true,
              false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6566523605150214 * (static_cast<double>(b_kk))) +
                0.17167381974248927;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][15]{ { 0.12875536480686745, 1.0,
                0.073059360730593881, 0.83333333333333337, 0.051643192488263108,
                1.0, 0.5, 1.0, 0.014634146341463468, 0.0, 1.0,
                0.42857142857142855, 0.0, 0.0, 1.0 }, { 0.87124463519313255, 0.0,
                0.92694063926940606, 0.16666666666666666, 0.9483568075117369,
                0.0, 0.5, 0.0, 0.98536585365853646, 1.0, 0.0, 0.5714285714285714,
                1.0, 1.0, 0.0 } };

            static const double b_dv[15]{ 0.63208616780045346, 0.0,
              0.91349206349206347, 0.68267973856209152, 0.0925, 0.0,
              0.093713672058892847, 0.0, 0.70841503267973849, 0.0, 0.0,
              0.53268416671094809, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 4, 0, 3, 4, 1, 0, 8, 0, 5, 0, 0,
              5, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, false, false, true,
              false, true, false, true, true, false, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void i_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][23]{ { 0.13733905579399192,
                0.090497737556561431, 1.0, 0.86666666666666659,
                0.033980582524271961, 1.0, 0.33333333333333331, 1.0,
                0.014851485148514905, 0.0, 1.0, 0.4, 0.0050761421319797141, 0.0,
                1.0, 0.0, 0.0526315789473684, 0.0, 0.125, 0.0,
                0.33333333333333331, 1.0, 0.0 }, { 0.862660944206008,
                0.90950226244343857, 0.0, 0.13333333333333328, 0.966019417475728,
                0.0, 0.66666666666666663, 0.0, 0.985148514851485, 1.0, 0.0, 0.6,
                0.99492385786802029, 1.0, 0.0, 1.0, 0.94736842105263153, 1.0,
                0.875, 1.0, 0.66666666666666663, 0.0, 1.0 } };

            static const double b_dv[23]{ 0.41500000000000004,
              0.10500000000000001, 0.0, 0.90855614973262033, 0.9065359477124183,
              0.0, 0.964766587749651, 0.0, 0.65116013071895429, 0.0, 0.0,
              0.79861111111111116, 0.073476390117155968, 0.0, 0.0, 0.0,
              0.80073696145124718, 0.0, 0.092057679949335364, 0.0,
              0.83333333333333337, 0.0, 0.0 };

            static const signed char b_iv1[23][2]{ { 2, 3 }, { 4, 5 }, { 0, 0 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 },
                { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[23]{ 1, 1, 0, 5, 3, 0, 5, 0, 5, 0, 0,
              4, 7, 0, 0, 0, 4, 0, 8, 0, 4, 0, 0 };

            static const bool b_bv[23]{ false, false, true, false, false, true,
              false, true, false, true, true, false, false, true, true, true,
              false, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 23; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 23; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][21]{ { 0.12875536480686745,
                0.82608695652173925, 0.05238095238095257, 0.94736842105263153,
                0.25, 1.0, 0.014851485148514905, 0.0, 1.0, 0.0, 1.0, 0.0,
                0.068181818181818135, 1.0, 0.046511627906976716,
                0.14285714285714282, 0.0, 0.0, 0.5, 1.0, 0.0 }, {
                0.87124463519313255, 0.17391304347826081, 0.94761904761904736,
                0.0526315789473684, 0.75, 0.0, 0.985148514851485, 1.0, 0.0, 1.0,
                0.0, 1.0, 0.93181818181818177, 0.0, 0.95348837209302328,
                0.85714285714285721, 1.0, 1.0, 0.5, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.7971782302664655,
              0.16585889686156663, 0.89051404721179506, -0.17447330093742128,
              0.586547138588283, 0.0, 0.97913823836744718, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.0975, 0.0, 0.1475, 1.4132363606378191, 0.0, 0.0,
              0.98039215686274517, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, {
                18, 19 }, { 0, 0 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 8, 2, 8, 5, 0, 5, 0, 0, 0, 0,
              0, 1, 0, 1, 2, 0, 0, 5, 0, 0 };

            static const bool b_bv[21]{ false, false, false, false, false, true,
              false, true, true, true, true, true, false, true, false, false,
              true, true, false, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][17]{ { 0.15021459227467868,
                0.73529411764705888, 0.050251256281407218, 0.83333333333333348,
                0.0, 1.0, 0.015625000000000056, 1.0, 0.61538461538461531, 0.0,
                0.053571428571428534, 0.0, 1.0, 0.0, 0.19999999999999996, 0.0,
                1.0 }, { 0.84978540772532141, 0.26470588235294107,
                0.94974874371859286, 0.1666666666666666, 1.0, 0.0,
                0.98437499999999989, 0.0, 0.38461538461538458, 1.0,
                0.9464285714285714, 1.0, 0.0, 1.0, 0.8, 1.0, 0.0 } };

            static const double b_dv[17]{ 0.8536601307189543,
              0.08703684256668924, 0.91873155565245646, 0.73611111111111116, 0.0,
              0.0, 0.9907407407407407, 0.0, 0.81666666666666665, 0.0,
              0.97913823836744718, 0.0, 0.0, 0.0, 0.099185926175775624, 0.0, 0.0
            };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 7, 2, 4, 0, 0, 3, 0, 4, 0, 5,
              0, 0, 0, 8, 0, 0 };

            static const bool b_bv[17]{ false, false, false, false, true, true,
              false, true, false, true, false, true, true, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][25]{ { 0.15021459227467868,
                0.91999999999999993, 0.057692307692307904, 1.0, 0.6,
                0.66666666666666663, 0.020408163265306194, 0.0, 1.0, 0.2, 1.0,
                1.0, 0.015384615384615439, 0.0, 1.0, 0.0, 0.088235294117647009,
                0.0, 0.42857142857142855, 1.0, 0.33333333333333331,
                0.66666666666666663, 0.0, 1.0, 0.0 }, { 0.84978540772532141,
                0.07999999999999996, 0.94230769230769207, 0.0, 0.4,
                0.33333333333333331, 0.97959183673469374, 1.0, 0.0, 0.8, 0.0,
                0.0, 0.98461538461538456, 1.0, 0.0, 1.0, 0.91176470588235292,
                1.0, 0.5714285714285714, 0.0, 0.66666666666666663,
                0.33333333333333331, 1.0, 0.0, 1.0 } };

            static const double b_dv[25]{ 0.91596045197740117, 0.945106031543052,
              0.7825445688994388, 0.0, 0.42500000000000004, 1.2253725942317486,
              0.889170668245229, 0.0, 0.0, 0.63934307177637306, 0.0, 0.0,
              1.4115793345695291, 0.0, 0.0, 0.0, 0.97836375929682218, 0.0,
              1.4199218022824849, 0.0, 1.437801245298477, 0.9869506423258958,
              0.0, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 },
                { 24, 25 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 3, 5, 5, 0, 1, 2, 2, 0, 0, 5, 0,
              0, 2, 0, 0, 0, 5, 0, 2, 0, 2, 5, 0, 0, 0 };

            static const bool b_bv[25]{ false, false, false, true, false, false,
              false, true, true, false, true, true, false, true, true, true,
              false, true, false, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][13]{ { 0.1244635193133052, 1.0,
                0.051162790697674612, 1.0, 0.0192307692307693, 0.0,
                0.061538461538461507, 1.0, 0.03174603174603173, 0.0,
                0.16666666666666666, 1.0, 0.0 }, { 0.87553648068669476, 0.0,
                0.9488372093023254, 0.0, 0.98076923076923073, 1.0,
                0.93846153846153846, 0.0, 0.96825396825396826, 1.0,
                0.83333333333333337, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.89791892390474715, 0.0, 0.0825, 0.0,
              1.3585827729601645, 0.0, 0.68892408245349412, 0.0,
              0.073718094802731893, 0.0, 0.074395283670663309, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 2, 0, 1, 0, 2, 0, 5, 0, 7, 0, 7,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, true, false, true,
              false, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][19]{ { 0.12017167381974295,
                0.60000000000000009, 0.035353535353535477, 1.0,
                0.29999999999999993, 0.010362694300518173, 1.0, 0.0,
                0.54545454545454553, 0.0, 0.051282051282051253, 1.0, 0.0, 1.0,
                0.026315789473684195, 0.0, 0.1111111111111111, 0.0, 1.0 }, {
                0.87982832618025708, 0.39999999999999997, 0.96464646464646442,
                0.0, 0.70000000000000018, 0.98963730569948194, 0.0, 1.0,
                0.45454545454545459, 1.0, 0.94871794871794868, 0.0, 1.0, 0.0,
                0.97368421052631582, 1.0, 0.88888888888888884, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.84600804424333842,
              0.73611111111111116, 0.42500000000000004, 0.0,
              -0.13591292461965229, 1.4115793345695291, 0.0, 0.0, 0.25, 0.0,
              0.95299145299145294, 0.0, 0.0, 0.0, 0.10164380064021053, 0.0,
              0.070875220641048967, 0.0, 0.0 };

            static const signed char b_iv[19]{ 5, 4, 1, 0, 8, 2, 0, 0, 1, 0, 3,
              0, 0, 0, 8, 0, 7, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv4[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv4[b_i][1]);
              NanCutPoints[b_i] = bv3[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.759656652360515 * (static_cast<double>(b_kk))) +
                0.12017167381974249;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::d_init()
          {
            static const double b_dv1[2][11]{ { 0.098712446351931715,
                0.80952380952380953, 0.028301886792452935, 0.94117647058823528,
                0.25, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 }, { 0.90128755364806823,
                0.19047619047619041, 0.97169811320754707, 0.058823529411764677,
                0.75, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[11]{ 0.80173054070112881, 0.25,
              0.626984126984127, 0.17027135106985389, 0.61706349206349209, 0.0,
              0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 5, 1, 4, 8, 4, 0, 0, 0, 0, 0, 0 };

            static const bool b_bv[11]{ false, false, false, false, false, true,
              true, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.80257510729613735 * (static_cast<double>(b_kk)))
                + 0.098712446351931327;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][15]{ { 0.13304721030042968, 1.0,
                0.0691244239631339, 0.036649214659685986, 0.3076923076923076,
                0.8571428571428571, 0.0054347826086956711, 0.88888888888888884,
                0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0 }, { 0.86695278969957024, 0.0,
                0.930875576036866, 0.96335078534031393, 0.6923076923076924,
                0.14285714285714285, 0.99456521739130432, 0.1111111111111111,
                1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[15]{ 0.89680465748321025, 0.0,
              0.074455154667477208, 0.75482026143790848, 0.71999497234791354,
              1.2253725942317486, 0.09, 0.1675, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 14, 15 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 2, 0, 7, 5, 5, 2, 1, 1, 0, 0, 0,
              0, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, false, false, false,
              false, false, true, true, true, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.73390557939914158 * (static_cast<double>(b_kk)))
                + 0.13304721030042918;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][11]{ { 0.13733905579399192,
                0.75000000000000011, 0.03980099502487576, 0.0, 0.923076923076923,
                1.0, 0.0, 0.96, 0.0, 1.0, 0.0 }, { 0.862660944206008,
                0.24999999999999989, 0.96019900497512423, 1.0,
                0.076923076923076886, 0.0, 1.0, 0.03999999999999998, 1.0, 0.0,
                1.0 } };

            static const double b_dv[11]{ 0.83697838109602807,
              -0.17418049357378684, 0.92406838360406507, 0.0,
              0.12636110069692014, 0.0, 0.0, 0.17740702811790754, 0.0, 0.0, 0.0
            };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 5, 8, 2, 0, 7, 0, 0, 8, 0, 0, 0 };

            static const bool b_bv[11]{ false, false, false, true, false, true,
              true, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void i_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][23]{ { 0.11158798283261846,
                0.059139784946236756, 0.31914893617021273, 1.0,
                0.02777777777777787, 1.0, 0.1999999999999999, 1.0,
                0.016853932584269718, 1.0, 0.08571428571428566,
                0.0056818181818182011, 1.0, 0.0, 0.21428571428571427, 1.0, 0.0,
                1.0, 0.083333333333333315, 0.0, 0.33333333333333331, 1.0, 0.0 },
              { 0.88841201716738161, 0.94086021505376316, 0.68085106382978733,
                0.0, 0.9722222222222221, 0.0, 0.8, 0.0, 0.98314606741573018, 0.0,
                0.91428571428571426, 0.99431818181818188, 0.0, 1.0,
                0.78571428571428581, 0.0, 1.0, 0.0, 0.91666666666666663, 1.0,
                0.66666666666666663, 0.0, 1.0 } };

            static const double b_dv[23]{ 0.061984517160834932, 0.085,
              0.89680465748321025, 0.0, 0.889170668245229, 0.0, 0.08, 0.0,
              0.92428571428571438, 0.0, 1.3886966894238384, 0.638121712099474,
              0.0, 0.0, 0.9682459677419355, 0.0, 0.0, 0.0, 0.97766422218754867,
              0.0, 0.081671544582348779, 0.0, 0.0 };

            static const signed char b_iv1[23][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 18, 19 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 },
                { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[23]{ 7, 1, 2, 0, 2, 0, 1, 0, 4, 0, 2,
              5, 0, 0, 3, 0, 0, 0, 5, 0, 7, 0, 0 };

            static const bool b_bv[23]{ false, false, false, true, false, true,
              false, true, false, true, false, false, true, true, false, true,
              true, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 23; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 23; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.77682403433476388 * (static_cast<double>(b_kk)))
                + 0.11158798283261803;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][21]{ { 0.11587982832618071,
                0.75000000000000011, 0.043062200956937954, 0.0,
                0.85714285714285721, 0.019607843137254975, 1.0,
                0.94736842105263153, 0.0, 1.0, 0.0099009900990099375, 0.0, 1.0,
                1.0, 0.0049751243781094709, 0.0, 0.019607843137254888, 0.0,
                0.16666666666666666, 0.0, 1.0 }, { 0.8841201716738194,
                0.24999999999999994, 0.95693779904306209, 1.0,
                0.14285714285714282, 0.98039215686274506, 0.0,
                0.0526315789473684, 1.0, 0.0, 0.99009900990099009, 1.0, 0.0, 0.0,
                0.99502487562189057, 1.0, 0.98039215686274506, 1.0,
                0.83333333333333337, 1.0, 0.0 } };

            static const double b_dv[21]{ 0.832242619478399, 0.40755783794999478,
              0.435, 0.0, 0.17261271862261879, 0.90625978090766823, 0.0,
              -0.17447330093742128, 0.0, 0.0, 0.09, 0.0, 0.0, 0.0,
              0.990909090909091, 0.0, 0.071900528125343977, 0.0,
              0.10164380064021053, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 5, 1, 0, 8, 3, 0, 8, 0, 0, 1,
              0, 0, 0, 3, 0, 7, 0, 8, 0, 0 };

            static const bool b_bv[21]{ false, false, false, true, false, false,
              true, false, true, true, false, true, true, true, false, true,
              false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.76824034334763946 * (static_cast<double>(b_kk)))
                + 0.11587982832618025;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][25]{ { 0.15879828326180315, 1.0,
                0.066666666666666916, 0.030303030303030398, 0.1999999999999999,
                0.66666666666666663, 0.0062893081761006492, 1.0,
                0.12195121951219506, 1.0, 0.33333333333333331, 0.0,
                0.023809523809523794, 0.0, 0.31249999999999994, 0.0, 1.0, 1.0,
                0.0, 0.55555555555555547, 0.0, 1.0, 0.33333333333333331, 1.0,
                0.0 }, { 0.84120171673819688, 0.0, 0.93333333333333313,
                0.96969696969696961, 0.8, 0.33333333333333331,
                0.99371069182389937, 0.0, 0.878048780487805, 0.0,
                0.66666666666666663, 1.0, 0.97619047619047616, 1.0, 0.6875, 1.0,
                0.0, 0.0, 1.0, 0.44444444444444442, 1.0, 0.0,
                0.66666666666666663, 0.0, 1.0 } };

            static const double b_dv[25]{ 0.89791892390474715, 0.0,
              0.065766109381383719, 0.10250000000000001, 0.09,
              0.85341354723707663, 0.9907407407407407, 0.0, 1.3886966894238384,
              0.0, 1.4109636716450562, 0.0, 0.638121712099474, 0.0,
              0.087310847950136466, 0.0, 0.0, 0.0, 0.0, 1.3969961214570714, 0.0,
              0.0, 0.0755177392353529, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 14, 15 },
                { 0, 0 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 },
              { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 22, 23 }, { 0, 0 }, { 0,
                0 }, { 24, 25 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 2, 0, 7, 1, 1, 5, 3, 0, 2, 0, 2,
              0, 5, 0, 7, 0, 0, 0, 0, 2, 0, 0, 7, 0, 0 };

            static const bool b_bv[25]{ false, true, false, false, false, false,
              false, true, false, true, false, true, false, true, false, true,
              true, true, true, false, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][13]{ { 0.16309012875536541, 1.0,
                0.084507042253521444, 0.83333333333333337, 0.015384615384615439,
                1.0, 0.0, 0.0, 0.049999999999999968, 1.0, 0.033898305084745742,
                1.0, 0.0 }, { 0.83690987124463467, 0.0, 0.91549295774647854,
                0.16666666666666663, 0.98461538461538456, 0.0, 1.0, 1.0,
                0.95000000000000007, 0.0, 0.96610169491525422, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.89928016178387926, 0.0,
              0.70841503267973849, 0.2375, 0.97913823836744718, 0.0, 0.0, 0.0,
              0.97948814263892015, 0.0, 0.0975, 0.0, 0.0 };

            static const signed char b_iv[13]{ 2, 0, 5, 1, 5, 0, 0, 0, 5, 0, 1,
              0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv3[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv3[b_i][1]);
              NanCutPoints[b_i] = bv2[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][17]{ { 0.14163090128755418,
                0.87878787878787878, 0.020000000000000073, 0.93333333333333335,
                0.33333333333333331, 0.0050761421319797141, 1.0,
                0.7142857142857143, 1.0, 0.0, 1.0, 0.055555555555555532, 0.0,
                1.0, 0.0, 1.0, 0.0 }, { 0.85836909871244582, 0.12121212121212113,
                0.97999999999999987, 0.066666666666666624, 0.66666666666666663,
                0.99492385786802029, 0.0, 0.2857142857142857, 0.0, 1.0, 0.0,
                0.94444444444444442, 1.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.84718954248366019,
              0.093953287354896942, 0.48, 0.016776371338047633,
              0.93116609634114234, 0.68027777777777776, 0.0, 0.73611111111111116,
              0.0, 0.0, 0.0, 0.10250000000000001, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 7, 1, 7, 3, 4, 0, 4, 0, 0, 0,
              1, 0, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, false, false, false, false, false,
              true, false, true, true, true, false, true, true, true, true, true
            };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::e_init()
          {
            static const double b_dv1[2][19]{ { 0.15879828326180315,
                0.91666666666666663, 0.071770334928229929, 0.0,
                0.95652173913043481, 1.0, 0.030000000000000106, 1.0, 0.0, 1.0,
                0.010204081632653099, 0.0, 0.038461538461538436, 0.0,
                0.14285714285714282, 1.0, 0.0769230769230769, 1.0, 0.0 }, {
                0.84120171673819688, 0.083333333333333287, 0.92822966507177, 1.0,
                0.043478260869565195, 0.0, 0.97, 0.0, 1.0, 0.0,
                0.98979591836734693, 1.0, 0.96153846153846156, 1.0,
                0.85714285714285721, 0.0, 0.923076923076923, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.80173054070112881,
              -0.17447330093742128, 0.626984126984127, 0.0, 0.1797196359730272,
              0.0, 0.913140258511681, 0.0, 0.0, 0.0, 0.97908283537086782, 0.0,
              0.046079734491242121, 0.0, 0.97991066855164211, 0.0,
              0.04806114605455758, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 5, 8, 4, 0, 8, 0, 2, 0, 0, 0, 5,
              0, 7, 0, 5, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, false, false, true, false, true,
              false, true, true, true, false, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][17]{ { 0.16738197424892762, 1.0,
                0.097674418604651536, 1.0, 0.067307692307692554,
                0.06280193236715, 1.0, 0.91666666666666663, 0.010256410256410295,
                1.0, 0.0, 0.0, 0.051282051282051253, 0.0, 0.5, 1.0, 0.0 }, {
                0.83261802575107235, 0.0, 0.90232558139534846, 0.0,
                0.93269230769230749, 0.93719806763285, 0.0, 0.083333333333333315,
                0.98974358974358978, 0.0, 1.0, 1.0, 0.94871794871794868, 1.0,
                0.5, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.09, 0.0, 0.60846560846560849, 0.0,
              0.43, 0.75482026143790848, 0.0, 0.25, 1.4206264937901973, 0.0, 0.0,
              0.0, 0.97836375929682218, 0.0, 0.98162821162947933, 0.0, 0.0 };

            static const signed char b_iv[17]{ 1, 0, 4, 0, 1, 5, 0, 1, 2, 0, 0,
              0, 5, 0, 5, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv2[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv2[b_i][1]);
              NanCutPoints[b_i] = bv1[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.66523605150214582 * (static_cast<double>(b_kk)))
                + 0.16738197424892703;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][25]{ { 0.15021459227467868,
                0.80000000000000016, 0.035353535353535477, 1.0,
                0.58823529411764708, 1.0, 0.030456852791878281,
                0.76923076923076927, 0.0, 1.0, 0.010362694300518173, 0.25, 1.0,
                0.0, 0.039999999999999973, 0.0, 1.0, 1.0, 0.020408163265306107,
                0.0, 0.125, 0.0, 0.5, 1.0, 0.0 }, { 0.84978540772532141,
                0.1999999999999999, 0.96464646464646442, 0.0,
                0.41176470588235292, 0.0, 0.96954314720812174,
                0.23076923076923075, 1.0, 0.0, 0.98963730569948194, 0.75, 0.0,
                1.0, 0.96, 1.0, 0.0, 0.0, 0.97959183673469385, 1.0, 0.875, 1.0,
                0.5, 0.0, 1.0 } };

            static const double b_dv[25]{ 0.83697838109602807,
              0.73611111111111116, 0.90625978090766823, 0.0, 0.70841503267973849,
              0.0, 0.60425685425685427, 0.95755517826825121, 0.0, 0.0,
              1.4115793345695291, 0.60022102238641029, 0.0, 0.0,
              0.72888888888888892, 0.0, 0.0, 0.0, 0.071900528125343977, 0.0,
              0.97766422218754867, 0.0, 0.83333333333333337, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, {
                0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 18, 19 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 22, 23 },
                { 0, 0 }, { 24, 25 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 5, 4, 3, 0, 5, 0, 4, 3, 0, 0, 2,
              5, 0, 0, 4, 0, 0, 0, 7, 0, 5, 0, 4, 0, 0 };

            static const bool b_bv[25]{ false, false, false, true, false, true,
              false, false, true, true, false, false, true, true, false, true,
              true, true, false, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][21]{ { 0.14592274678111641, 1.0,
                0.074418604651163067, 1.0, 0.05238095238095257,
                0.69230769230769229, 0.010152284263959428, 1.0, 0.0, 0.0,
                0.045454545454545421, 1.0, 0.023255813953488358, 0.0,
                0.083333333333333315, 0.25, 0.0, 0.0, 0.5, 1.0, 0.0 }, {
                0.85407725321888361, 0.0, 0.92558139534883688, 0.0,
                0.94761904761904736, 0.30769230769230765, 0.98984771573604058,
                0.0, 1.0, 1.0, 0.95454545454545459, 0.0, 0.97674418604651159,
                1.0, 0.91666666666666663, 0.75, 1.0, 1.0, 0.5, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.6219851576994434, 0.0,
              0.852275025127967, 0.0, 0.690893665158371, 0.2375,
              1.4115793345695291, 0.0, 0.0, 0.0, 1.4189694677219074, 0.0,
              0.10164380064021053, 0.0, 0.81944444444444442, 0.1275, 0.0, 0.0,
              0.11598415821548753, 0.0, 0.0 };

            static const signed char b_iv[21]{ 4, 0, 2, 0, 5, 1, 2, 0, 0, 0, 2,
              0, 8, 0, 4, 1, 0, 0, 8, 0, 0 };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv7[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv7[b_i][1]);
              NanCutPoints[b_i] = bv6[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][15]{ { 0.12875536480686745, 1.0,
                0.0514018691588787, 0.66666666666666663, 0.0050251256281407218,
                0.83333333333333337, 0.0, 0.0, 0.018867924528301872, 0.5, 1.0,
                1.0, 0.0, 1.0, 0.0 }, { 0.87124463519313255, 0.0,
                0.94859813084112121, 0.33333333333333326, 0.99497487437185927,
                0.16666666666666666, 1.0, 1.0, 0.98113207547169812, 0.5, 0.0,
                0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[15]{ 0.89146782953160164, 0.0,
              0.817825311942959, 0.2375, 0.1020704819559759,
              0.022970431472307082, 0.0, 0.0, 0.10321408363818549,
              0.15872115426846445, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 2, 0, 5, 1, 8, 7, 0, 0, 8, 8, 0,
              0, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, false, false, false,
              true, true, false, false, true, true, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][11]{ { 0.13304721030042968, 1.0,
                0.051643192488263108, 1.0, 0.038095238095238231,
                0.028846153846153952, 1.0, 0.8571428571428571, 0.0, 0.0, 1.0 },
                { 0.86695278969957024, 0.0, 0.9483568075117369, 0.0,
                0.96190476190476171, 0.971153846153846, 0.0, 0.14285714285714285,
                1.0, 1.0, 0.0 } };

            static const double b_dv[11]{ 0.89680465748321025, 0.0,
              0.626984126984127, 0.0, 1.5717835343699613, 0.75482026143790848,
              0.0, 1.121083443282985, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 2, 0, 4, 0, 2, 5, 0, 2, 0, 0, 0 };

            static const bool b_bv[11]{ false, true, false, true, false, false,
              true, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.73390557939914158 * (static_cast<double>(b_kk)))
                + 0.13304721030042918;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][19]{ { 0.19742489270386335,
                0.70454545454545459, 0.079365079365079638, 1.0,
                0.56666666666666665, 1.0, 0.038674033149171394, 0.0,
                0.89473684210526316, 0.016949152542372937, 1.0, 1.0, 0.0, 0.0,
                0.059999999999999956, 1.0, 0.020833333333333318, 1.0, 0.0 }, {
                0.80257510729613668, 0.29545454545454541, 0.92063492063492025,
                0.0, 0.43333333333333329, 0.0, 0.96132596685082849, 1.0,
                0.10526315789473679, 0.983050847457627, 0.0, 0.0, 1.0, 1.0, 0.94,
                0.0, 0.97916666666666663, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.84718954248366019,
              0.73611111111111116, 0.63208616780045346, 0.0, 0.81666666666666665,
              0.0, 0.44, 0.0, 0.74617898441427855, 0.97908283537086782, 0.0, 0.0,
              0.0, 0.0, 0.0975, 0.0, 0.97980565120996266, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 5, 4, 4, 0, 4, 0, 1, 0, 5, 5, 0,
              0, 0, 0, 1, 0, 5, 0, 0 };

            static const bool b_bv[19]{ false, false, false, true, false, true,
              false, true, false, false, true, true, true, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.60515021459227469 * (static_cast<double>(b_kk)))
                + 0.19742489270386265;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::f_init()
          {
            static const double b_dv1[2][13]{ { 0.16309012875536541, 1.0,
                0.075829383886256208, 0.93333333333333335, 0.010204081632653099,
                0.0, 1.0, 1.0, 0.0051282051282051473, 0.0, 0.022727272727272711,
                1.0, 0.0 }, { 0.83690987124463467, 0.0, 0.92417061611374374,
                0.066666666666666638, 0.98979591836734693, 1.0, 0.0, 0.0,
                0.99487179487179489, 1.0, 0.97727272727272729, 0.0, 1.0 } };

            static const double b_dv[13]{ 1.0535253460633887, 0.0,
              0.74617898441427855, -0.17447330093742128, 0.09, 0.0, 0.0, 0.0,
              0.97913823836744718, 0.0, 0.97948814263892015, 0.0, 0.0 };

            static const signed char b_iv[13]{ 2, 0, 5, 8, 1, 0, 0, 0, 5, 0, 5,
              0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv3[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv3[b_i][1]);
              NanCutPoints[b_i] = bv2[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][17]{ { 0.13304721030042968,
                0.67741935483870974, 0.049504950495049688, 1.0,
                0.33333333333333326, 1.0, 0.030303030303030411, 1.0, 0.0, 0.0,
                0.065934065934066, 1.0, 0.011627906976744201, 0.0,
                0.062499999999999972, 1.0, 0.0 }, { 0.86695278969957024,
                0.32258064516129026, 0.95049504950495034, 0.0,
                0.66666666666666663, 0.0, 0.96969696969696961, 0.0, 1.0, 1.0,
                0.934065934065934, 0.0, 0.9883720930232559, 1.0, 0.9375, 0.0,
                1.0 } };

            static const double b_dv[17]{ 0.67752100840336138, 0.920235388841527,
              0.0825, 0.0, 0.92497139474390955, 0.0, 0.80277777777777781, 0.0,
              0.0, 0.0, 0.77679738562091494, 0.0, 0.071900528125343977, 0.0,
              0.075156649252890742, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 5, 1, 0, 2, 0, 4, 0, 0, 0, 5,
              0, 7, 0, 7, 0, 0 };

            static const bool b_bv[17]{ false, false, false, true, false, true,
              false, true, true, true, false, true, false, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.73390557939914158 * (static_cast<double>(b_kk)))
                + 0.13304721030042918;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][13]{ { 0.094420600858369466, 1.0,
                0.049549549549549737, 1.0, 0.027649769585253559,
                0.023148148148148234, 1.0, 0.6, 0.0094786729857820259, 1.0, 0.0,
                1.0, 0.0 }, { 0.90557939914163055, 0.0, 0.95045045045045018, 0.0,
                0.97235023041474644, 0.97685185185185175, 0.0, 0.4,
                0.990521327014218, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.626984126984127, 0.0,
              0.909163802978236, 0.0, 1.633304236099054, 0.77091503267973849,
              0.0, 0.15430870006017719, 0.0925, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 4, 0, 3, 0, 2, 5, 0, 8, 1, 0, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, true, false, false,
              true, false, false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.81115879828326176 * (static_cast<double>(b_kk)))
                + 0.0944206008583691;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][11]{ { 0.098712446351931715, 1.0,
                0.041095890410959054, 0.83333333333333337, 0.018779342723004765,
                1.0, 0.0, 0.66666666666666663, 0.0, 1.0, 0.0 }, {
                0.90128755364806823, 0.0, 0.95890410958904093,
                0.16666666666666666, 0.98122065727699526, 0.0, 1.0,
                0.33333333333333331, 1.0, 0.0, 1.0 } };

            static const double b_dv[11]{ 0.63208616780045346, 0.0,
              0.91349206349206347, 0.92406838360406507, 0.65279411764705886, 0.0,
              0.0, 0.2325, 0.0, 0.0, 0.0 };

            static const signed char b_iv[11]{ 4, 0, 3, 2, 5, 0, 0, 1, 0, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv1[b_i][1]);
              NanCutPoints[b_i] = bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.80257510729613735 * (static_cast<double>(b_kk)))
                + 0.098712446351931327;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][21]{ { 0.15021459227467868,
                0.79411764705882359, 0.040201005025125768, 1.0,
                0.63157894736842113, 1.0, 0.025510204081632744, 0.0,
                0.85714285714285721, 1.0, 0.01546391752577325, 0.0, 1.0, 1.0,
                0.010362694300518173, 0.0, 0.036363636363636341, 0.0,
                0.13333333333333328, 1.0, 0.0 }, { 0.84978540772532141,
                0.20588235294117638, 0.9597989949748742, 0.0,
                0.36842105263157893, 0.0, 0.97448979591836726, 1.0,
                0.14285714285714282, 0.0, 0.98453608247422675, 1.0, 0.0, 0.0,
                0.98963730569948194, 1.0, 0.96363636363636362, 1.0,
                0.86666666666666659, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.84600804424333842,
              0.70833333333333326, 0.90625978090766823, 0.0,
              -0.13591292461965229, 0.0, 0.60425685425685427, 0.0,
              0.81666666666666665, 0.0, 0.09, 0.0, 0.0, 0.0, 0.97913823836744718,
              0.0, 0.80277777777777781, 0.0, 0.98039215686274517, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 4, 3, 0, 8, 0, 4, 0, 4, 0, 1,
              0, 0, 0, 5, 0, 4, 0, 5, 0, 0 };

            static const bool b_bv[21]{ false, false, false, true, false, true,
              false, true, false, true, false, true, true, true, false, true,
              false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][15]{ { 0.16309012875536541, 1.0,
                0.084507042253521444, 1.0, 0.0714285714285717,
                0.76470588235294124, 0.010362694300518173, 0.2, 1.0,
                0.046511627906976716, 0.0, 0.0, 1.0, 0.0, 1.0 }, {
                0.83690987124463467, 0.0, 0.91549295774647854, 0.0,
                0.92857142857142838, 0.23529411764705876, 0.98963730569948194,
                0.8, 0.0, 0.95348837209302328, 1.0, 1.0, 0.0, 1.0, 0.0 } };

            static const double b_dv[15]{ 0.89791892390474715, 0.0,
              0.626984126984127, 0.0, 0.74617898441427855, 0.51516954360091616,
              0.94519519519519513, 0.81944444444444442, 0.0, 1.3954118224833336,
              0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 2, 0, 4, 0, 5, 5, 3, 4, 0, 2, 0,
              0, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, true, false, false,
              false, false, true, false, true, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::g_init()
          {
            static const double b_dv1[2][19]{ { 0.13733905579399192, 1.0,
                0.0737327188940095, 0.75000000000000011, 0.034146341463414755,
                0.0, 1.0, 0.019801980198019875, 1.0, 0.0, 0.062499999999999965,
                1.0, 0.032258064516129011, 0.0, 0.11764705882352935, 0.0,
                0.66666666666666663, 1.0, 0.0 }, { 0.862660944206008, 0.0,
                0.92626728110599044, 0.25, 0.96585365853658522, 1.0, 0.0,
                0.98019801980198007, 0.0, 1.0, 0.9375, 0.0, 0.967741935483871,
                1.0, 0.88235294117647056, 1.0, 0.33333333333333331, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.63282828282828285, 0.0,
              0.68292483660130721, 1.1763268659125461, 0.44, 0.0, 0.0,
              0.047147492271505873, 0.0, 0.0, 0.048102975596082231, 0.0,
              0.9893617021276595, 0.0, 0.97766422218754867, 0.0,
              0.83611111111111114, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 4, 0, 5, 2, 1, 0, 0, 7, 0, 0, 7,
              0, 3, 0, 5, 0, 4, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, false, true,
              true, false, true, true, false, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][19]{ { 0.15879828326180315, 1.0,
                0.096774193548387469, 0.93333333333333335, 0.034653465346534774,
                0.66666666666666663, 1.0, 0.020100502512562887, 1.0, 0.0, 1.0,
                0.005586592178770969, 0.14999999999999994, 1.0, 0.0, 0.0,
                0.42857142857142855, 1.0, 0.0 }, { 0.84120171673819688, 0.0,
                0.90322580645161255, 0.066666666666666638, 0.9653465346534652,
                0.33333333333333331, 0.0, 0.9798994974874371, 0.0, 1.0, 0.0,
                0.99441340782122911, 0.85000000000000009, 0.0, 1.0, 1.0,
                0.5714285714285714, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.626984126984127, 0.0,
              0.77091503267973849, 0.7857142857142857, 0.42500000000000004,
              -0.13502125395286996, 0.0, 0.073822651979343984, 0.0, 0.0, 0.0,
              0.0925, 1.4132363606378191, 0.0, 0.0, 0.0, 0.83611111111111114,
              0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, {
                0, 0 }, { 0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 4, 0, 5, 4, 1, 8, 0, 7, 0, 0, 0,
              1, 2, 0, 0, 0, 4, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, false, false,
              true, false, true, true, true, false, false, true, true, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][21]{ { 0.15021459227467868, 1.0,
                0.10000000000000038, 0.061611374407583172, 1.0,
                0.052631578947368619, 1.0, 0.025316455696202608,
                0.13725490196078424, 0.8, 0.0, 0.0, 0.5, 1.0, 0.0,
                0.77777777777777768, 0.0, 0.5, 1.0, 1.0, 0.0 }, {
                0.84978540772532141, 0.0, 0.89999999999999969,
                0.93838862559241687, 0.0, 0.94736842105263142, 0.0,
                0.97468354430379733, 0.86274509803921573, 0.2, 1.0, 1.0, 0.5,
                0.0, 1.0, 0.22222222222222221, 1.0, 0.5, 0.0, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.909163802978236, 0.0, 0.435,
              1.5717835343699613, 0.0, 1.3886966894238384, 0.0,
              0.690893665158371, 0.074453405960369826, 0.2375, 0.0, 0.0,
              0.84722222222222232, 0.0, 0.0, 0.79166666666666674, 0.0,
              1.4368934841675558, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 3, 0, 1, 2, 0, 2, 0, 5, 8, 1, 0,
              0, 4, 0, 0, 4, 0, 2, 0, 0, 0 };

            static const bool b_bv[21]{ false, true, false, false, true, false,
              true, false, false, false, true, true, false, true, true, false,
              true, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][17]{ { 0.17167381974248988, 1.0,
                0.10232558139534922, 1.0, 0.06310679611650509,
                0.044554455445544712, 1.0, 0.66666666666666663,
                0.0052631578947368611, 1.0, 0.0, 0.0, 0.041666666666666644, 0.0,
                0.2, 1.0, 0.0 }, { 0.82832618025751015, 0.0, 0.8976744186046508,
                0.0, 0.936893203883495, 0.95544554455445529, 0.0,
                0.33333333333333331, 0.99473684210526314, 0.0, 1.0, 1.0,
                0.95833333333333337, 1.0, 0.8, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.63208616780045346, 0.0, 0.0925, 0.0,
              0.43, 0.70841503267973849, 0.0, 0.16585889686156663,
              0.073822651979343984, 0.0, 0.0, 0.0, 0.97819683908045973, 0.0,
              0.077021677160233, 0.0, 0.0 };

            static const signed char b_iv[17]{ 4, 0, 1, 0, 1, 5, 0, 8, 7, 0, 0,
              0, 5, 0, 7, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv2[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv2[b_i][1]);
              NanCutPoints[b_i] = bv1[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6566523605150214 * (static_cast<double>(b_kk))) +
                0.17167381974248927;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][13]{ { 0.17596566523605212, 1.0,
                0.098591549295775016, 0.95, 0.010362694300518173,
                0.66666666666666663, 1.0, 0.0, 0.039215686274509776, 0.0, 1.0,
                1.0, 0.0 }, { 0.82403433476394783, 0.0, 0.901408450704225,
                0.049999999999999975, 0.98963730569948194, 0.33333333333333331,
                0.0, 1.0, 0.96078431372549022, 1.0, 0.0, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.89928016178387926, 0.0,
              0.80173054070112881, 0.016776371338047633, 0.1020704819559759,
              0.1575, 0.0, 0.0, 0.10321408363818549, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 2, 0, 5, 7, 8, 1, 0, 0, 8, 0, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, false, false, false,
              true, true, false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.648068669527897 * (static_cast<double>(b_kk))) +
                0.17596566523605151;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][11]{ { 0.10729613733905621, 1.0,
                0.054545454545454751, 0.73333333333333339, 0.0048780487804878231,
                0.91666666666666663, 0.0, 1.0, 0.0, 0.0, 1.0 }, {
                0.89270386266094381, 0.0, 0.94545454545454521,
                0.26666666666666661, 0.99512195121951219, 0.083333333333333315,
                1.0, 0.0, 1.0, 1.0, 0.0 } };

            static const double b_dv[11]{ 0.89791892390474715, 0.0,
              0.690893665158371, 0.089709032861629151, 0.87863247863247862,
              0.949874686716792, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[11][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[11]{ 2, 0, 5, 7, 3, 3, 0, 0, 0, 0, 0 };

            static const bool b_bv[11]{ false, true, false, false, false, false,
              true, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.78540772532188852 * (static_cast<double>(b_kk)))
                + 0.1072961373390558;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::h_init()
          {
            static const double b_dv1[2][15]{ { 0.14592274678111641, 1.0,
                0.08294930875576069, 1.0, 0.038647342995169219,
                0.029268292682926935, 1.0, 0.02463054187192127, 0.5,
                0.55555555555555547, 0.0, 1.0, 0.0, 1.0, 0.0 }, {
                0.85407725321888361, 0.0, 0.91705069124423932, 0.0,
                0.96135265700483075, 0.97073170731707314, 0.0,
                0.97536945812807874, 0.5, 0.44444444444444442, 1.0, 0.0, 1.0,
                0.0, 1.0 } };

            static const double b_dv[15]{ 0.09, 0.0, 0.909163802978236, 0.0,
              0.49749999999999994, 0.92428571428571438, 0.0, 0.70841503267973849,
              0.93928571428571428, 0.21000000000000002, 0.0, 0.0, 0.0, 0.0, 0.0
            };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 1, 0, 3, 0, 1, 4, 0, 5, 4, 1, 0,
              0, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, true, false, false,
              true, false, false, false, true, true, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::i_init()
          {
            static const double b_dv1[2][17]{ { 0.13733905579399192, 1.0,
                0.077981651376147085, 0.03365384615384627, 1.0, 1.0,
                0.019512195121951289, 0.0057142857142857342,
                0.099999999999999936, 0.0, 0.020408163265306107, 0.0,
                0.21428571428571427, 1.0, 0.0, 1.0, 0.0 }, { 0.862660944206008,
                0.0, 0.9220183486238529, 0.96634615384615363, 0.0, 0.0,
                0.98048780487804865, 0.99428571428571433, 0.9, 1.0,
                0.97959183673469385, 1.0, 0.78571428571428581, 0.0, 1.0, 0.0,
                1.0 } };

            static const double b_dv[17]{ 0.09, 0.0, 0.41500000000000004,
              0.83753183881204962, 0.0, 0.0, 0.065056890826711247, 0.2025,
              1.3780626873727555, 0.0, 0.68452694085764376, 0.0,
              0.84722222222222232, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 0, 0 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 1, 0, 1, 2, 0, 0, 7, 1, 2, 0, 5,
              0, 4, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, true, false, false, true, true,
              false, false, false, true, false, true, false, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::i_init()
          {
            static const double b_dv1[2][13]{ { 0.1244635193133052, 1.0,
                0.064220183486238785, 0.042253521126760722, 1.0,
                0.75000000000000011, 0.0, 0.0, 0.89999999999999991,
                0.66666666666666663, 1.0, 1.0, 0.0 }, { 0.87553648068669476, 0.0,
                0.9357798165137613, 0.95774647887323927, 0.0, 0.25, 1.0, 1.0,
                0.099999999999999978, 0.33333333333333331, 0.0, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.89791892390474715, 0.0,
              1.5717835343699613, 0.70841503267973849, 0.0, 0.43135299703927155,
              0.0, 0.0, 0.79166666666666674, 0.1625, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 2, 0, 2, 5, 0, 5, 0, 0, 4, 1, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, false, true, false,
              true, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::i_init()
          {
            static const double b_dv1[2][19]{ { 0.16309012875536541, 1.0,
                0.10550458715596371, 1.0, 0.0714285714285717, 1.0,
                0.053398058252427376, 0.83333333333333337, 0.0051546391752577509,
                1.0, 0.0, 0.0, 0.017241379310344817, 0.0, 0.066666666666666638,
                0.0, 0.33333333333333331, 1.0, 0.0 }, { 0.83690987124463467, 0.0,
                0.89449541284403633, 0.0, 0.92857142857142838, 0.0,
                0.94660194174757251, 0.16666666666666666, 0.99484536082474229,
                0.0, 1.0, 1.0, 0.98275862068965514, 1.0, 0.93333333333333335,
                1.0, 0.66666666666666663, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.63282828282828285, 0.0,
              0.92497139474390955, 0.0, 0.0925, 0.0, 0.70841503267973849, 0.2375,
              0.97913823836744718, 0.0, 0.0, 0.0, 0.990909090909091, 0.0, 0.14,
              0.0, 0.1525, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 4, 0, 2, 0, 1, 0, 5, 1, 5, 0, 0,
              0, 3, 0, 1, 0, 1, 0, 0 };

            static const bool b_bv[19]{ false, true, false, true, false, true,
              false, false, false, true, true, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::i_init()
          {
            static const double b_dv1[2][21]{ { 0.14163090128755418,
                0.838709677419355, 0.034653465346534774, 0.0, 0.9285714285714286,
                1.0, 0.020100502512562887, 1.0, 0.81818181818181823,
                0.0058139534883721129, 0.11111111111111106, 0.0, 1.0, 1.0, 0.0,
                1.0, 0.076923076923076886, 0.0, 0.16666666666666666, 0.0, 1.0 },
              { 0.85836909871244582, 0.1612903225806451, 0.9653465346534652, 1.0,
                0.071428571428571383, 0.0, 0.9798994974874371, 0.0,
                0.1818181818181818, 0.9941860465116279, 0.888888888888889, 1.0,
                0.0, 0.0, 1.0, 0.0, 0.923076923076923, 1.0, 0.83333333333333337,
                1.0, 0.0 } };

            static const double b_dv[21]{ 0.83227752639517338,
              -0.17418049357378684, 0.8484126984126984, 0.0, 0.11, 0.0,
              0.073476390117155968, 0.0, 0.135, 0.60425685425685427,
              0.90234518344402359, 0.0, 0.0, 0.0, 0.0, 0.0, 1.4206264937901973,
              0.0, 0.97766422218754867, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 8, 3, 0, 1, 0, 7, 0, 1, 4, 2,
              0, 0, 0, 0, 0, 2, 0, 5, 0, 0 };

            static const bool b_bv[21]{ false, false, false, true, false, true,
              false, true, false, false, false, true, true, true, true, true,
              false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::i_init()
          {
            static const double b_dv1[2][15]{ { 0.15021459227467868,
                0.82142857142857151, 0.05853658536585387, 0.91999999999999993,
                0.0, 1.0, 0.015306122448979647, 0.0, 1.0, 1.0,
                0.0051546391752577509, 0.058823529411764677, 0.0, 0.0, 1.0 }, {
                0.84978540772532141, 0.17857142857142849, 0.94146341463414607,
                0.07999999999999996, 1.0, 0.0, 0.98469387755102034, 1.0, 0.0,
                0.0, 0.99484536082474229, 0.94117647058823528, 1.0, 1.0, 0.0 } };

            static const double b_dv[15]{ 0.78853695324283557,
              0.17740702811790754, 0.63208616780045346, -0.17447330093742128,
              0.0, 0.0, 0.89786324786324778, 0.0, 0.0, 0.0, 0.67774146695715332,
              0.674969987995198, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 5, 8, 4, 8, 0, 0, 3, 0, 0, 0, 4,
              4, 0, 0, 0 };

            static const bool b_bv[15]{ false, false, false, false, true, true,
              false, true, true, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void i_CompactClassificationTree::init()
          {
            static const double b_dv1[2][23]{ { 0.13733905579399192,
                0.86666666666666681, 0.029556650246305525, 0.96153846153846156,
                0.25, 1.0, 0.02475247524752484, 0.0, 1.0, 1.0, 0.0,
                0.011173184357541938, 0.13043478260869559, 0.057142857142857106,
                0.0, 0.047619047619047596, 1.0, 1.0, 0.029411764705882335, 0.0,
                1.0, 0.0, 1.0 }, { 0.862660944206008, 0.13333333333333328,
                0.97044334975369451, 0.038461538461538443, 0.75, 0.0,
                0.97524752475247523, 1.0, 0.0, 0.0, 1.0, 0.98882681564245811,
                0.86956521739130443, 0.94285714285714284, 1.0,
                0.95238095238095233, 0.0, 0.0, 0.97058823529411764, 1.0, 0.0,
                1.0, 0.0 } };

            static const double b_dv[23]{ 0.83697838109602807,
              0.1675783547401179, 0.89786324786324778, -0.17447330093742128,
              0.89791892390474715, 0.0, 0.073718094802731893, 0.0, 0.0, 0.0, 0.0,
              0.94519519519519513, 0.18265166052722254, 0.60425685425685427, 0.0,
              0.97819683908045973, 0.0, 0.0, 1.3954118224833336, 0.0, 0.0, 0.0,
              0.0 };

            static const signed char b_iv1[23][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 }, { 14, 15 }, { 16, 17 }, { 18, 19 }, { 0, 0 },
                { 20, 21 }, { 0, 0 }, { 0, 0 }, { 22, 23 }, { 0, 0 }, { 0, 0 },
                { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[23]{ 5, 8, 3, 8, 2, 0, 7, 0, 0, 0, 0,
              3, 8, 4, 0, 5, 0, 0, 2, 0, 0, 0, 0 };

            static const bool b_bv[23]{ false, false, false, false, false, true,
              false, true, true, true, true, false, false, false, true, false,
              true, true, false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 23; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 23; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void f_CompactClassificationTree::init()
          {
            static const double b_dv1[2][7]{ { 0.15450643776824091, 1.0,
                0.052884615384615578, 1.0, 0.010050251256281444, 1.0, 0.0 }, {
                0.84549356223175909, 0.0, 0.94711538461538436, 0.0,
                0.98994974874371866, 0.0, 1.0 } };

            static const double b_dv[7]{ 0.63208616780045346, 0.0,
              0.70841503267973849, 0.0, 0.882059628317484, 0.0, 0.0 };

            static const signed char b_iv1[7][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
                { 0, 0 }, { 6, 7 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[7]{ 4, 0, 5, 0, 2, 0, 0 };

            static const bool b_bv[7]{ false, true, false, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 7; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 7; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.69098712446351929 * (static_cast<double>(b_kk)))
                + 0.15450643776824036;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::init()
          {
            static const double b_dv1[2][15]{ { 0.16309012875536541,
                0.88461538461538469, 0.0724637681159423, 0.0,
                0.95833333333333337, 1.0, 0.025380710659898567, 1.0, 0.0, 1.0,
                0.015384615384615439, 0.0, 0.1071428571428571, 1.0, 0.0 }, {
                0.83690987124463467, 0.11538461538461534, 0.92753623188405765,
                1.0, 0.041666666666666644, 0.0, 0.97461928934010145, 0.0, 1.0,
                0.0, 0.98461538461538456, 1.0, 0.8928571428571429, 0.0, 1.0 } };

            static const double b_dv[15]{ 0.78853695324283557,
              0.41425202248731663, 0.913140258511681, 0.0, 0.17740702811790754,
              0.0, 0.09, 0.0, 0.0, 0.0, 0.073476390117155968, 0.0,
              0.074395283670663309, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 5, 5, 2, 0, 8, 0, 1, 0, 0, 0, 7,
              0, 7, 0, 0 };

            static const bool b_bv[15]{ false, false, false, true, false, true,
              false, true, true, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.67381974248927046 * (static_cast<double>(b_kk)))
                + 0.1630901287553648;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void j_CompactClassificationTree::init()
          {
            static const double b_dv1[2][27]{ { 0.15021459227467868, 1.0,
                0.079069767441860769, 1.0, 0.070422535211267873, 1.0,
                0.061611374407583172, 0.024539877300613574, 0.18749999999999992,
                0.375, 0.0064516129032258264, 0.0, 0.26470588235294107, 0.0, 1.0,
                1.0, 0.0, 0.1666666666666666, 1.0, 1.0, 0.13793103448275856, 1.0,
                0.074074074074074028, 0.25, 0.0, 0.0, 1.0 }, {
                0.84978540772532141, 0.0, 0.92093023255813922, 0.0,
                0.929577464788732, 0.0, 0.93838862559241687, 0.97546012269938642,
                0.81250000000000011, 0.625, 0.99354838709677418, 1.0,
                0.73529411764705888, 1.0, 0.0, 0.0, 1.0, 0.83333333333333348,
                0.0, 0.0, 0.86206896551724144, 0.0, 0.92592592592592593, 0.75,
                1.0, 1.0, 0.0 } };

            static const double b_dv[27]{ 0.91587239086203553, 0.0,
              0.626984126984127, 0.0, -0.3104525542231954, 0.0,
              0.061983630596466541, 0.690893665158371, 0.9660138248847927,
              1.2253725942317486, 0.0925, 0.0, 1.5717835343699613, 0.0, 0.0, 0.0,
              0.0, -0.079019954086885114, 0.0, 0.0, 0.75149694286316682, 0.0,
              0.80902777777777779, 0.9750632891488592, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[27][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, {
                14, 15 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 }, { 22, 23 },
                { 0, 0 }, { 24, 25 }, { 26, 27 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[27]{ 2, 0, 4, 0, 7, 0, 7, 5, 3, 2, 1,
              0, 2, 0, 0, 0, 0, 8, 0, 0, 5, 0, 4, 5, 0, 0, 0 };

            static const bool b_bv[27]{ false, true, false, true, false, true,
              false, false, false, false, false, true, false, true, true, true,
              true, false, true, true, false, true, false, false, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 27; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 27; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void k_CompactClassificationTree::init()
          {
            static const double b_dv1[2][9]{ { 0.15879828326180315, 1.0,
                0.075471698113207836, 1.0, 0.0439024390243904,
                0.64285714285714279, 0.0, 0.0, 1.0 }, { 0.84120171673819688, 0.0,
                0.92452830188679214, 0.0, 0.95609756097560961,
                0.3571428571428571, 1.0, 1.0, 0.0 } };

            static const double b_dv[9]{ 0.89791892390474715, 0.0, 0.0925, 0.0,
              0.70841503267973849, 0.53268416671094809, 0.0, 0.0, 0.0 };

            static const signed char b_iv[9]{ 2, 0, 1, 0, 5, 5, 0, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 9; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv6[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv6[b_i][1]);
              NanCutPoints[b_i] = bv5[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 9; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void g_CompactClassificationTree::init()
          {
            static const double b_dv1[2][11]{ { 0.18884120171673885, 1.0,
                0.073529411764706162, 0.93333333333333335, 0.00529100529100531,
                1.0, 0.0, 0.0526315789473684, 0.0, 0.0, 1.0 }, {
                0.8111587982832611, 0.0, 0.92647058823529393,
                0.066666666666666638, 0.99470899470899476, 0.0, 1.0,
                0.94736842105263153, 1.0, 1.0, 0.0 } };

            static const double b_dv[11]{ 0.89953678983356467, 0.0,
              0.80173054070112881, 0.17253059325246123, 0.68027777777777776, 0.0,
              0.0, 1.3632415069389996, 0.0, 0.0, 0.0 };

            static const signed char b_iv[11]{ 2, 0, 5, 8, 4, 0, 0, 2, 0, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 11; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv1[b_i][1]);
              NanCutPoints[b_i] = bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 11; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.62231759656652352 * (static_cast<double>(b_kk)))
                + 0.18884120171673821;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void h_CompactClassificationTree::init()
          {
            static const double b_dv1[2][25]{ { 0.15879828326180315,
                0.77142857142857157, 0.050505050505050685, 0.0,
                0.87096774193548387, 0.025906735751295429, 1.0, 0.9, 0.0, 1.0,
                0.015706806282722568, 0.66666666666666663, 1.0,
                0.12499999999999994, 0.0057142857142857342, 1.0, 0.0, 0.0, 1.0,
                0.0, 0.043478260869565195, 0.0, 0.25, 1.0, 0.0 }, {
                0.84120171673819688, 0.22857142857142848, 0.94949494949494939,
                1.0, 0.12903225806451604, 0.97409326424870457, 0.0,
                0.099999999999999936, 1.0, 0.0, 0.98429319371727741,
                0.33333333333333331, 0.0, 0.875, 0.99428571428571433, 0.0, 1.0,
                1.0, 0.0, 1.0, 0.95652173913043481, 1.0, 0.75, 0.0, 1.0 } };

            static const double b_dv[25]{ 0.83227752639517338,
              -0.17447330093742128, 0.435, 0.0, 0.12636110069692014,
              0.56090561224489788, 0.0, 0.012756794207965161, 0.0, 0.0,
              0.68027777777777776, -0.007068687213689407, 0.0,
              0.67950617283950621, 0.073822651979343984, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.97803570981393828, 0.0, 0.98029400859342619, 0.0, 0.0 };

            static const signed char b_iv1[25][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, { 0, 0 }, {
                0, 0 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 18, 19 }, { 20, 21 },
              { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 22, 23 }, { 0,
                0 }, { 24, 25 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[25]{ 5, 8, 1, 0, 7, 4, 0, 7, 0, 0, 4,
              7, 0, 4, 7, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0 };

            static const bool b_bv[25]{ false, false, false, true, false, false,
              true, false, true, true, false, false, true, false, false, true,
              true, true, true, true, false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 25; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 25; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::init()
          {
            static const double b_dv1[2][19]{ { 0.13733905579399192,
                0.86956521739130443, 0.057142857142857356, 0.0,
                0.95238095238095233, 1.0, 0.048076923076923253, 1.0, 0.5,
                0.69230769230769229, 0.0051282051282051473, 0.0, 1.0, 1.0, 0.0,
                0.0, 0.030303030303030283, 1.0, 0.0 }, { 0.862660944206008,
                0.13043478260869559, 0.94285714285714262, 1.0,
                0.047619047619047596, 0.0, 0.95192307692307676, 0.0, 0.5,
                0.30769230769230765, 0.99487179487179489, 1.0, 0.0, 0.0, 1.0,
                1.0, 0.96969696969696972, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.91596045197740117,
              -0.074928641918938554, 0.61010101010101, 0.0, 0.0746066731980656,
              0.0, 0.690893665158371, 0.0, 0.35000000000000003, 0.2375,
              0.073718094802731893, 0.0, 0.0, 0.0, 0.0, 0.0,
              0.074626002628498389, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 3, 8, 4, 0, 7, 0, 5, 0, 1, 1, 7,
              0, 0, 0, 0, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, false, false, true, false, true,
              false, true, false, false, false, true, true, true, true, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.72532188841201717 * (static_cast<double>(b_kk)))
                + 0.13733905579399142;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::init()
          {
            static const double b_dv1[2][21]{ { 0.14163090128755418,
                0.76923076923076938, 0.06280193236715, 0.0, 0.86956521739130443,
                0.66666666666666663, 0.015625000000000056, 0.0,
                0.95238095238095233, 1.0, 0.0, 1.0, 0.0052631578947368611, 1.0,
                0.0, 0.0, 0.019230769230769218, 0.0, 0.099999999999999978, 0.0,
                1.0 }, { 0.85836909871244582, 0.2307692307692307,
                0.93719806763285, 1.0, 0.13043478260869559, 0.33333333333333326,
                0.98437499999999989, 1.0, 0.047619047619047596, 0.0, 1.0, 0.0,
                0.99473684210526314, 0.0, 1.0, 1.0, 0.98076923076923073, 1.0,
                0.89999999999999991, 1.0, 0.0 } };

            static const double b_dv[21]{ 0.83146742567994947,
              0.40755783794999478, 0.91762711864406787, 0.0,
              -0.16119265494506418, 0.92406838360406507, 0.9073279610636874, 0.0,
              0.17740702811790754, 0.0, 0.0, 0.0, 0.1020704819559759, 0.0, 0.0,
              0.0, 0.97898850574712637, 0.0, 0.98958333333333326, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 14, 15 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 5, 5, 3, 0, 8, 2, 2, 0, 8, 0, 0,
              0, 8, 0, 0, 0, 5, 0, 3, 0, 0 };

            static const bool b_bv[21]{ false, false, false, true, false, false,
              false, true, false, true, true, true, false, true, true, true,
              false, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::init()
          {
            static const double b_dv1[2][13]{ { 0.15450643776824091,
                0.84615384615384626, 0.067632850241546152, 0.0,
                0.88000000000000012, 1.0, 0.010256410256410295, 1.0, 0.0, 0.0,
                0.048780487804878016, 1.0, 0.0 }, { 0.84549356223175909,
                0.15384615384615377, 0.93236714975845392, 1.0,
                0.11999999999999995, 0.0, 0.98974358974358978, 0.0, 1.0, 1.0,
                0.95121951219512191, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.83227752639517338,
              -0.14771146936850046, 0.92406838360406507, 0.0,
              0.16820026441433156, 0.0, 1.4115793345695291, 0.0, 0.0, 0.0, 0.09,
              0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 5, 7, 2, 0, 8, 0, 2, 0, 0, 0, 1,
              0, 0 };

            static const bool b_bv[13]{ false, false, false, true, false, true,
              false, true, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.69098712446351929 * (static_cast<double>(b_kk)))
                + 0.15450643776824036;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::init()
          {
            static const double b_dv1[2][17]{ { 0.1244635193133052, 1.0,
                0.076923076923077219, 0.013513513513513554, 0.20547945205479445,
                1.0, 0.0068027210884353947, 0.90909090909090906,
                0.080645161290322537, 0.25, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 },
              { 0.87553648068669476, 0.0, 0.9230769230769228,
                0.98648648648648651, 0.79452054794520544, 0.0,
                0.99319727891156462, 0.090909090909090884, 0.91935483870967749,
                0.75, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.63208616780045346, 0.0,
              0.8169642857142857, 0.0825, 1.2510846287159143, 0.0,
              0.66515151515151516, 0.265, 0.74617898441427855,
              0.91194158075601373, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, { 14, 15 },
                { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 0, 4, 1, 2, 0, 5, 1, 5, 3, 0,
              0, 0, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, true, false, false, false, true,
              false, false, false, false, true, true, true, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::j_init()
          {
            static const double b_dv1[2][17]{ { 0.11158798283261846,
                0.80769230769230771, 0.024154589371980766, 0.87500000000000011,
                0.0, 1.0, 0.014634146341463468, 0.94736842105263153, 0.6, 0.0,
                1.0, 0.75, 1.0, 1.0, 0.0, 1.0, 0.0 }, { 0.88841201716738161,
                0.19230769230769224, 0.97584541062801922, 0.12499999999999994,
                1.0, 0.0, 0.98536585365853646, 0.0526315789473684, 0.4, 1.0, 0.0,
                0.25, 0.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.78853695324283557,
              0.12636110069692014, 0.89786324786324778, 0.70841503267973849, 0.0,
              0.0, 0.42000000000000004, 1.2253725942317486, 0.96564885496183206,
              0.0, 0.0, 0.94450041295755871, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, { 14, 15 },
                { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 7, 3, 5, 0, 0, 1, 2, 3, 0, 0,
              2, 0, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, false, false, false, true, true,
              false, false, false, true, true, false, true, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.77682403433476388 * (static_cast<double>(b_kk)))
                + 0.11158798283261803;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::j_init()
          {
            static const double b_dv1[2][13]{ { 0.1244635193133052,
                0.86363636363636376, 0.04739336492891013, 1.0, 0.0, 1.0,
                0.0049504950495049688, 0.066666666666666638, 0.0, 0.0,
                0.16666666666666666, 0.0, 1.0 }, { 0.87553648068669476,
                0.13636363636363633, 0.95260663507108989, 0.0, 1.0, 0.0,
                0.995049504950495, 0.93333333333333335, 1.0, 1.0,
                0.83333333333333337, 1.0, 0.0 } };

            static const double b_dv[13]{ 0.83697838109602807,
              0.17740702811790754, 0.942289252512589, 0.0, 0.0, 0.0,
              0.68375000000000008, 0.034780241416133825, 0.0, 0.0,
              0.67928571428571427, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 0, 0 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 5, 8, 2, 0, 0, 0, 4, 7, 0, 0, 4,
              0, 0 };

            static const bool b_bv[13]{ false, false, false, true, true, true,
              false, false, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::j_init()
          {
            static const double b_dv1[2][21]{ { 0.15879828326180315, 1.0,
                0.071090047393365191, 0.03184713375796188, 0.18518518518518512,
                1.0, 0.019354838709677476, 0.0, 0.43478260869565216, 1.0,
                0.0065359477124183208, 1.0, 0.13333333333333328,
                0.020833333333333318, 0.0, 0.0, 0.4, 1.0, 0.0, 1.0, 0.0 }, {
                0.84120171673819688, 0.0, 0.92890995260663478,
                0.96815286624203811, 0.81481481481481488, 0.0,
                0.98064516129032242, 1.0, 0.56521739130434789, 0.0,
                0.99346405228758172, 0.0, 0.86666666666666659,
                0.97916666666666663, 1.0, 1.0, 0.6, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.89791892390474715, 0.0,
              0.1020704819559759, -0.3104525542231954, 0.79563492063492069, 0.0,
              0.0775, 0.0, 0.76048722519310763, 0.0, 0.95293466223698786, 0.0,
              0.071900528125343977, 0.68517973856209147, 0.0, 0.0,
              0.1083918686826795, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[21][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 18, 19 }, { 0, 0 },
                { 0, 0 }, { 20, 21 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[21]{ 2, 0, 8, 7, 4, 0, 1, 0, 5, 0, 3,
              0, 7, 5, 0, 0, 8, 0, 0, 0, 0 };

            static const bool b_bv[21]{ false, true, false, false, false, true,
              false, true, false, true, false, true, false, false, true, true,
              false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::j_init()
          {
            static const double b_dv1[2][19]{ { 0.15879828326180315, 1.0,
                0.071090047393365191, 0.83333333333333337, 0.025125628140703609,
                1.0, 0.0, 0.5, 0.010362694300518173, 0.0, 1.0, 0.0,
                0.060606060606060566, 1.0, 0.031249999999999983, 0.0, 0.125, 1.0,
                0.0 }, { 0.84120171673819688, 0.0, 0.92890995260663478,
                0.16666666666666666, 0.97487437185929637, 0.0, 1.0, 0.5,
                0.98963730569948194, 1.0, 0.0, 1.0, 0.93939393939393934, 0.0,
                0.96875, 1.0, 0.875, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.63208616780045346, 0.0,
              0.70565856777493607, 0.16585889686156663, 0.91349206349206347, 0.0,
              0.0, 0.082459722037225874, 1.4115793345695291, 0.0, 0.0, 0.0,
              0.70666666666666667, 0.0, 0.070875220641048967, 0.0,
              0.075156649252890742, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 4, 0, 5, 8, 3, 0, 0, 8, 2, 0, 0,
              0, 4, 0, 7, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, false, true,
              true, false, false, true, true, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::j_init()
          {
            static const double b_dv1[2][15]{ { 0.14163090128755418,
                0.82758620689655182, 0.044117647058823685, 0.0,
                0.923076923076923, 1.0, 0.015151515151515206, 1.0, 0.0,
                0.0051020408163265493, 1.0, 0.0, 0.019999999999999987, 1.0, 0.0
              }, { 0.85836909871244582, 0.1724137931034482, 0.95588235294117629,
                1.0, 0.076923076923076886, 0.0, 0.98484848484848475, 0.0, 1.0,
                0.99489795918367352, 0.0, 1.0, 0.98, 0.0, 1.0 } };

            static const double b_dv[15]{ 0.838349632657033,
              -0.17447330093742128, 0.63591269841269837, 0.0,
              0.16820026441433156, 0.0, 0.49749999999999994, 0.0, 0.0,
              1.4115793345695291, 0.0, 0.0, 0.70666666666666667, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12,
                13 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 5, 8, 4, 0, 8, 0, 1, 0, 0, 2, 0,
              0, 4, 0, 0 };

            static const bool b_bv[15]{ false, false, false, true, false, true,
              false, true, true, false, true, true, false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::k_init()
          {
            static const double b_dv1[2][13]{ { 0.14592274678111641, 1.0,
                0.074418604651163067, 1.0, 0.043269230769230928,
                0.63636363636363646, 0.010152284263959428, 1.0,
                0.33333333333333331, 1.0, 0.0, 1.0, 0.0 }, { 0.85407725321888361,
                0.0, 0.92558139534883688, 0.0, 0.956730769230769,
                0.36363636363636365, 0.98984771573604058, 0.0,
                0.66666666666666663, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.626984126984127, 0.0, 0.085, 0.0,
              0.70841503267973849, 0.25, 0.92406838360406507, 0.0,
              0.91912548880199074, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 4, 0, 1, 0, 5, 1, 2, 0, 3, 0, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, true, false, false,
              false, true, false, true, true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::k_init()
          {
            static const double b_dv1[2][19]{ { 0.12875536480686745, 1.0,
                0.0814479638009053, 1.0, 0.0424528301886794, 0.41666666666666669,
                0.020000000000000073, 0.0, 1.0, 0.66666666666666663,
                0.010152284263959428, 0.0, 1.0, 0.0, 0.036363636363636341, 0.0,
                0.25, 1.0, 0.0 }, { 0.87124463519313255, 0.0,
                0.91855203619909476, 0.0, 0.9575471698113206,
                0.58333333333333337, 0.97999999999999987, 1.0, 0.0,
                0.33333333333333331, 0.98984771573604058, 1.0, 0.0, 1.0,
                0.96363636363636362, 1.0, 0.75, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.09, 0.0, 0.613567649281935, 0.0,
              0.68292483660130721, 0.53268416671094809, 0.91349206349206347, 0.0,
              0.0, -0.0028550255955261533, 0.1020704819559759, 0.0, 0.0, 0.0,
              0.97898850574712637, 0.0, 0.98029400859342619, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 1, 0, 4, 0, 5, 5, 3, 0, 0, 8, 8,
              0, 0, 0, 5, 0, 5, 0, 0 };

            static const bool b_bv[19]{ false, true, false, true, false, false,
              false, true, true, false, false, true, true, true, false, true,
              false, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::k_init()
          {
            static const double b_dv1[2][17]{ { 0.15879828326180315, 1.0,
                0.08837209302325616, 1.0, 0.066666666666666916,
                0.66666666666666663, 0.020512820512820586, 0.0, 1.0, 1.0,
                0.01546391752577325, 0.0, 0.083333333333333287, 0.0,
                0.42857142857142855, 1.0, 0.0 }, { 0.84120171673819688, 0.0,
                0.9116279069767439, 0.0, 0.93333333333333313,
                0.33333333333333326, 0.97948717948717945, 1.0, 0.0, 0.0,
                0.98453608247422675, 1.0, 0.91666666666666663, 1.0,
                0.5714285714285714, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.909163802978236, 0.0,
              0.89791892390474715, 0.0, 0.728657616892911, 0.949874686716792,
              0.09, 0.0, 0.0, 0.0, 0.10164380064021053, 0.0, 0.97819683908045973,
              0.0, 0.98029400859342619, 0.0, 0.0 };

            static const signed char b_iv[17]{ 3, 0, 2, 0, 5, 3, 1, 0, 0, 0, 8,
              0, 5, 0, 5, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv5[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv5[b_i][1]);
              NanCutPoints[b_i] = bv4[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void CompactClassificationTree::k_init()
          {
            static const double b_dv1[2][15]{ { 0.11158798283261846, 1.0,
                0.059090909090909319, 0.8, 0.041860465116279222, 0.0, 1.0,
                0.037383177570093594, 1.0, 1.0, 0.032863849765258336,
                0.63636363636363646, 0.0, 0.0, 1.0 }, { 0.88841201716738161, 0.0,
                0.9409090909090907, 0.2, 0.95813953488372072, 1.0, 0.0,
                0.96261682242990643, 0.0, 0.0, 0.96713615023474164,
                0.36363636363636365, 1.0, 1.0, 0.0 } };

            static const double b_dv[15]{ 0.63208616780045346, 0.0,
              0.91349206349206347, 0.082459722037225874, 1.633304236099054, 0.0,
              0.0, 0.075000000000000011, 0.0, 0.0, 0.68892408245349412,
              1.2331338170279325, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[15][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[15]{ 4, 0, 3, 8, 2, 0, 0, 1, 0, 0, 5,
              2, 0, 0, 0 };

            static const bool b_bv[15]{ false, true, false, false, false, true,
              true, false, true, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 15; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 15; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.77682403433476388 * (static_cast<double>(b_kk)))
                + 0.11158798283261803;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void e_CompactClassificationTree::k_init()
          {
            static const double b_dv1[2][21]{ { 0.13304721030042968, 1.0,
                0.073394495412844318, 1.0, 0.060465116279069996,
                0.81818181818181823, 0.019607843137254975, 0.0, 1.0, 1.0,
                0.014778325123152762, 0.0, 0.065217391304347783, 1.0,
                0.044444444444444411, 0.12499999999999994, 0.0, 0.0, 0.5, 1.0,
                0.0 }, { 0.86695278969957024, 0.0, 0.92660550458715563, 0.0,
                0.93953488372093, 0.1818181818181818, 0.98039215686274506, 1.0,
                0.0, 0.0, 0.9852216748768472, 1.0, 0.93478260869565222, 0.0,
                0.9555555555555556, 0.875, 1.0, 1.0, 0.5, 0.0, 1.0 } };

            static const double b_dv[21]{ 0.89680465748321025, 0.0,
              -0.28508967385645057, 0.0, 0.70841503267973849,
              0.40755783794999478, 0.87895927601809953, 0.0, 0.0, 0.0,
              1.4115793345695291, 0.0, 0.95299145299145294, 0.0,
              1.4355397451283602, 0.059080551084978075, 0.0, 0.0,
              0.081671544582348779, 0.0, 0.0 };

            static const signed char b_iv[21]{ 2, 0, 7, 0, 5, 5, 3, 0, 0, 0, 2,
              0, 3, 0, 2, 7, 0, 0, 7, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 21; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv7[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv7[b_i][1]);
              NanCutPoints[b_i] = bv6[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 21; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.73390557939914158 * (static_cast<double>(b_kk)))
                + 0.13304721030042918;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::m_init()
          {
            static const double b_dv1[2][19]{ { 0.12017167381974295, 1.0,
                0.037558685446009522, 1.0, 0.014423076923076976, 0.0,
                0.044117647058823525, 0.031249999999999986, 0.25, 0.0,
                0.10526315789473679, 1.0, 0.0, 1.0, 0.055555555555555532, 0.25,
                0.0, 0.0, 1.0 }, { 0.87982832618025708, 0.0, 0.9624413145539904,
                0.0, 0.985576923076923, 1.0, 0.95588235294117652, 0.96875, 0.75,
                1.0, 0.89473684210526316, 0.0, 1.0, 0.0, 0.94444444444444442,
                0.75, 1.0, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.91587239086203553, 0.0, 0.09, 0.0,
              1.3585827729601645, 0.0, 0.13317867883176462, 0.064850583461661351,
              0.13994515223192586, 0.0, 0.74617898441427855, 0.0, 0.0, 0.0,
              0.81944444444444442, 0.974741328088184, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, {
                0, 0 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, {
                18, 19 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 2, 0, 1, 0, 2, 0, 8, 7, 8, 0, 5,
              0, 0, 0, 4, 5, 0, 0, 0 };

            static const bool b_bv[19]{ false, true, false, true, false, true,
              false, false, false, true, false, true, true, true, false, false,
              true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.759656652360515 * (static_cast<double>(b_kk))) +
                0.12017167381974249;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::m_init()
          {
            static const double b_dv1[2][13]{ { 0.15021459227467868, 1.0,
                0.10000000000000038, 0.029069767441860558, 0.35416666666666663,
                1.0, 0.005952380952380972, 1.0, 0.031249999999999983, 1.0, 0.0,
                1.0, 0.0 }, { 0.84978540772532141, 0.0, 0.89999999999999969,
                0.97093023255813948, 0.64583333333333337, 0.0,
                0.99404761904761907, 0.0, 0.96875, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[13]{ 0.09, 0.0, 0.13611808593841193,
              0.72933006535947709, 0.94737615988598511, 0.0, 0.57087450364761283,
              0.0, 0.13847413938990133, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 1, 0, 8, 5, 2, 0, 4, 0, 8, 0, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, false, false, true,
              false, true, false, true, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::m_init()
          {
            static const double b_dv1[2][17]{ { 0.15450643776824091, 0.95,
                0.079812206572770258, 1.0, 0.66666666666666663,
                0.78947368421052633, 0.010309278350515502, 1.0, 0.0, 0.2, 1.0,
                0.0, 0.076923076923076886, 0.0, 1.0, 1.0, 0.0 }, {
                0.84549356223175909, 0.049999999999999975, 0.92018779342722978,
                0.0, 0.33333333333333331, 0.21052631578947362,
                0.98969072164948457, 0.0, 1.0, 0.8, 0.0, 1.0, 0.923076923076923,
                1.0, 0.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.66416040100250617, 0.995349262456313,
              0.70841503267973849, 0.0, -0.037403591303126177,
              1.2253725942317486, 0.073718094802731893, 0.0, 0.0,
              0.54735657225853307, 0.0, 0.0, 0.074743637834655055, 0.0, 0.0, 0.0,
              0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, {
                14, 15 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 2, 5, 0, 7, 2, 7, 0, 0, 5, 0,
              0, 7, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, false, false, true, false, false,
              false, true, true, false, true, true, false, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.69098712446351929 * (static_cast<double>(b_kk)))
                + 0.15450643776824036;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::o_init()
          {
            static const double b_dv1[2][19]{ { 0.11587982832618071,
                0.67741935483870974, 0.029702970297029809, 0.0,
                0.80769230769230771, 0.015075376884422164, 1.0, 1.0,
                0.16666666666666666, 1.0, 0.0050761421319797141, 1.0, 0.0, 0.0,
                0.015873015873015869, 0.0, 0.125, 0.0, 1.0 }, {
                0.8841201716738194, 0.32258064516129026, 0.97029702970297027,
                1.0, 0.19230769230769224, 0.98492462311557782, 0.0, 0.0,
                0.83333333333333337, 0.0, 0.99492385786802029, 0.0, 1.0, 1.0,
                0.98412698412698418, 1.0, 0.875, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.84600804424333842,
              -0.17418049357378684, 0.44, 0.0, 0.16820026441433156,
              0.79730741665488636, 0.0, 0.0, 0.83389080030636709, 0.0,
              0.990909090909091, 0.0, 0.0, 0.0, 0.070875220641048967, 0.0,
              0.97766422218754867, 0.0, 0.0 };

            static const signed char b_iv[19]{ 5, 8, 1, 0, 8, 2, 0, 0, 2, 0, 3,
              0, 0, 0, 7, 0, 5, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv4[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv4[b_i][1]);
              NanCutPoints[b_i] = bv3[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.76824034334763946 * (static_cast<double>(b_kk)))
                + 0.11587982832618025;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::o_init()
          {
            static const double b_dv1[2][17]{ { 0.14163090128755418,
                0.79310344827586221, 0.049019607843137435, 0.94117647058823528,
                0.58333333333333337, 0.010204081632653099, 1.0, 1.0, 0.0, 1.0,
                0.0, 1.0, 0.0051282051282051473, 0.0, 0.023255813953488358, 1.0,
                0.0 }, { 0.85836909871244582, 0.20689655172413784,
                0.95098039215686259, 0.058823529411764677, 0.41666666666666669,
                0.98979591836734693, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
                0.99487179487179489, 1.0, 0.97674418604651159, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.83227752639517338,
              0.7825445688994388, 0.44, 0.12636110069692014, 0.68055555555555558,
              0.86731644200156666, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
              1.4115793345695291, 0.0, 1.4189694677219074, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 5, 1, 7, 4, 2, 0, 0, 0, 0, 0,
              0, 2, 0, 2, 0, 0 };

            static const bool b_bv[17]{ false, false, false, false, false, false,
              true, true, true, true, true, true, false, true, false, true, true
            };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void d_CompactClassificationTree::o_init()
          {
            static const double b_dv1[2][13]{ { 0.15879828326180315, 1.0,
                0.096774193548387469, 0.062200956937799277, 1.0, 1.0,
                0.029702970297029809, 1.0, 0.010101010101010138,
                0.22222222222222221, 0.0, 0.0, 1.0 }, { 0.84120171673819688, 0.0,
                0.90322580645161255, 0.93779904306220074, 0.0, 0.0,
                0.97029702970297027, 0.0, 0.98989898989899, 0.77777777777777768,
                1.0, 1.0, 0.0 } };

            static const double b_dv[13]{ 0.909163802978236, 0.0,
              1.5717835343699613, 0.89791892390474715, 0.0, 0.0, 0.0825, 0.0,
              0.65116013071895429, 0.79861111111111116, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[13][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 0, 0 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[13]{ 3, 0, 2, 2, 0, 0, 1, 0, 5, 4, 0,
              0, 0 };

            static const bool b_bv[13]{ false, true, false, false, true, true,
              false, true, false, false, true, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 13; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 13; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::p_init()
          {
            static const double b_dv1[2][19]{ { 0.14592274678111641, 1.0,
                0.074418604651163067, 0.736842105263158, 0.010204081632653099,
                0.875, 0.0, 0.0, 0.062499999999999965, 0.923076923076923,
                0.66666666666666663, 1.0, 0.0, 0.5, 1.0, 1.0, 0.0, 1.0, 0.0 }, {
                0.85407725321888361, 0.0, 0.92558139534883688,
                0.26315789473684204, 0.98979591836734693, 0.12499999999999994,
                1.0, 1.0, 0.9375, 0.0769230769230769, 0.33333333333333331, 0.0,
                1.0, 0.5, 0.0, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.88984996360278412, 0.0,
              0.80173054070112881, 0.11590153812599358, 0.073822651979343984,
              0.74617898441427855, 0.0, 0.0, 0.074626002628498389,
              1.2253725942317486, 1.2239669748349122, 0.0, 0.0,
              1.2026636357213709, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12, 13 }, {
                14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 18, 19 }, { 0, 0 },
                { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 2, 0, 5, 7, 7, 5, 0, 0, 7, 2, 2,
              0, 0, 2, 0, 0, 0, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, false, false,
              true, true, false, false, false, true, true, false, true, true,
              true, true, true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::p_init()
          {
            static const double b_dv1[2][17]{ { 0.19742489270386335,
                0.83720930232558155, 0.052631578947368605, 0.0,
                0.923076923076923, 0.034090909090909206, 0.2857142857142857, 1.0,
                0.625, 1.0, 0.011627906976744226, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 },
              { 0.80257510729613668, 0.16279069767441853, 0.94736842105263142,
                1.0, 0.076923076923076872, 0.96590909090909083,
                0.7142857142857143, 0.0, 0.375, 0.0, 0.98837209302325579, 0.0,
                1.0, 1.0, 0.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.84600804424333842,
              -0.17418049357378684, 0.08029147642245453, 0.0,
              0.16820026441433156, 0.9107336628351711, 0.93930719958402209, 0.0,
              0.17299457390962028, 0.0, 0.0925, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 12, 13 }, { 0, 0 }, { 14, 15 },
                { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 5, 8, 7, 0, 8, 2, 2, 0, 8, 0, 1,
              0, 0, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, false, false, true, false, false,
              false, true, false, true, false, true, true, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.60515021459227469 * (static_cast<double>(b_kk)))
                + 0.19742489270386265;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void e_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 21) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 21) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void d_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 13) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 13) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void c_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 19) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 19) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void h_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 25) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 25) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void f_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 7) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 7) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void k_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 9) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 9) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void j_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 27) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 27) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void g_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 11) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 11) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void i_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 23) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 23) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 15) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 15) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : const ::coder::array<double, 2U> &Xin
          //                ::coder::array<double, 1U> &labels
          //                ::coder::array<double, 2U> &scores
          // Return Type  : void
          //
          void b_CompactClassificationTree::predict(const ::coder::array<double,
            2U> &Xin, ::coder::array<double, 1U> &labels, ::coder::array<double,
            2U> &scores) const
          {
            ::coder::array<double, 2U> a__6;
            ::coder::array<double, 2U> r2;
            ::coder::array<double, 2U> rawScores;
            ::coder::array<double, 1U> r1;
            ::coder::array<unsigned int, 1U> node;
            ::coder::array<signed char, 1U> r;
            double b_d1;
            double d2;
            double d3;
            double s;
            double val;
            int c_i;
            int c_iindx;
            int i1;
            int i14;
            int i3;
            int i4;
            int m;
            bool exitg1;
            if (Xin.size(0) == 0) {
              scores.set_size(0, 2);
              labels.set_size(0);
            } else {
              int b_iindx;
              int b_loop_ub;
              int b_m;
              int b_rawScores;
              int b_u1;
              int c_loop_ub;
              int d_loop_ub;
              int d_m;
              int e_loop_ub;
              int f_loop_ub;
              int g_loop_ub;
              int h_loop_ub;
              int i10;
              int i6;
              int i7;
              int i9;
              int i_loop_ub;
              int iindx;
              int loop_ub;
              int numberOfObservations;
              int u0;
              int y;
              numberOfObservations = Xin.size(0);
              node.set_size(Xin.size(0));
              if ((static_cast<int>((Xin.size(0) * 10) < 4)) != 0) {
                for (int h_n{0}; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 17) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    double d;
                    d = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(d)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (d < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(val,m,exitg1,b_d1)

                for (int h_n = 0; h_n < numberOfObservations; h_n++) {
                  m = 0;
                  exitg1 = false;
                  while ((!exitg1) && (((m + 1) <= 17) && (!(CutPredictorIndex[m]
                            == 0.0)))) {
                    b_d1 = Xin[h_n + (Xin.size(0) * ((static_cast<int>
                      (CutPredictorIndex[m])) - 1))];
                    if (std::isnan(b_d1)) {
                      exitg1 = true;
                    } else if (NanCutPoints[m]) {
                      exitg1 = true;
                    } else {
                      if (InfCutPoints[m]) {
                        val = rtInf;
                      } else {
                        val = CutPoint[m];
                      }

                      if (b_d1 < val) {
                        m = (static_cast<int>(Children[m][0])) - 1;
                      } else {
                        m = (static_cast<int>(Children[m][1])) - 1;
                      }
                    }
                  }

                  node[h_n] = static_cast<unsigned int>(static_cast<int>(m + 1));
                }
              }

              rawScores.set_size(node.size(0), 2);
              loop_ub = node.size(0);
              if ((static_cast<int>((node.size(0) * 2) < 4)) != 0) {
                for (int b_i{0}; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i1)

                for (int b_i = 0; b_i < 2; b_i++) {
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    rawScores[i1 + (rawScores.size(0) * b_i)] = 0.0;
                  }
                }
              }

              scores.set_size(node.size(0), 2);
              b_loop_ub = node.size(0);
              c_loop_ub = node.size(0);
              d_loop_ub = node.size(0);
              u0 = node.size(0);
              b_u1 = node.size(0);
              if (u0 >= b_u1) {
                y = u0;
              } else {
                y = b_u1;
              }

              if ((static_cast<int>((y * 2) < 4)) != 0) {
                for (int i2{0}; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < b_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i4,i3)

                for (int i2 = 0; i2 < 2; i2++) {
                  for (i3 = 0; i3 < c_loop_ub; i3++) {
                    scores[i3 + (scores.size(0) * i2)] = 0.0;
                  }

                  for (i4 = 0; i4 < d_loop_ub; i4++) {
                    rawScores[i4 + (rawScores.size(0) * i2)] =
                      ClassProbability[i2][(static_cast<int>(node[i4])) - 1];
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  iindx = 1;
                } else {
                  iindx = 0;
                }
              } else {
                iindx = 0;
              }

              labels.set_size(node.size(0));
              e_loop_ub = node.size(0);
              if ((static_cast<int>(node.size(0) < 4)) != 0) {
                for (int i5{0}; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i5 = 0; i5 < e_loop_ub; i5++) {
                  labels[i5] = ClassNames[iindx];
                }
              }

              b_m = rawScores.size(0) - 1;
              d_m = rawScores.size(0) - 1;
              a__6.set_size(rawScores.size(0), 2);
              if ((static_cast<int>((rawScores.size(0) * 4) < 4)) != 0) {
                for (int j{0}; j < 2; j++) {
                  for (c_i = 0; c_i <= b_m; c_i++) {
                    a__6[c_i + (a__6.size(0) * j)] = (rawScores[c_i] * Cost[j][0])
                      + (rawScores[c_i + rawScores.size(0)] * Cost[j][1]);
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(s,c_i)

                for (int j = 0; j < 2; j++) {
                  for (c_i = 0; c_i <= d_m; c_i++) {
                    s = (rawScores[c_i] * Cost[j][0]) + (rawScores[c_i +
                      rawScores.size(0)] * Cost[j][1]);
                    a__6[c_i + (a__6.size(0) * j)] = s;
                  }
                }
              }

              if (Prior[0] < Prior[1]) {
                b_iindx = 1;
              } else if (std::isnan(Prior[0])) {
                if (!std::isnan(Prior[1])) {
                  b_iindx = 1;
                } else {
                  b_iindx = 0;
                }
              } else {
                b_iindx = 0;
              }

              r.set_size(rawScores.size(0));
              i6 = rawScores.size(0) - 1;
              i7 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int idx{0}; idx <= i6; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(c_iindx,d3,d2)

                for (int idx = 0; idx <= i7; idx++) {
                  d2 = a__6[idx];
                  d3 = a__6[idx + a__6.size(0)];
                  if (d2 > d3) {
                    c_iindx = 2;
                  } else if (std::isnan(d2)) {
                    if (!std::isnan(d3)) {
                      c_iindx = 2;
                    } else {
                      c_iindx = 1;
                    }
                  } else {
                    c_iindx = 1;
                  }

                  r[idx] = static_cast<signed char>(c_iindx);
                }
              }

              r1.set_size(rawScores.size(0));
              f_loop_ub = rawScores.size(0);
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
                  r1[b_i8] = ClassNames[b_iindx];
                }
              }

              i9 = rawScores.size(0) - 1;
              i10 = rawScores.size(0) - 1;
              if ((static_cast<int>(rawScores.size(0) < 4)) != 0) {
                for (int b_idx{0}; b_idx <= i9; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int b_idx = 0; b_idx <= i10; b_idx++) {
                  r1[b_idx] = ClassNames[r[b_idx] - 1];
                }
              }

              b_rawScores = rawScores.size(0) - 1;
              g_loop_ub = rawScores.size(0);
              for (int i11{0}; i11 < 2; i11++) {
                for (int i12{0}; i12 < g_loop_ub; i12++) {
                  rawScores[i12 + ((b_rawScores + 1) * i11)] = rawScores[i12 +
                    (rawScores.size(0) * i11)];
                }
              }

              rawScores.set_size(b_rawScores + 1, 2);
              CompactClassificationTree::b_transform(ScoreTransform, rawScores,
                r2);
              h_loop_ub = r2.size(0);
              if ((static_cast<int>((r2.size(0) * 2) < 4)) != 0) {
                for (int i13{0}; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(i14)

                for (int i13 = 0; i13 < 2; i13++) {
                  for (i14 = 0; i14 < h_loop_ub; i14++) {
                    scores[i14 + (scores.size(0) * i13)] = r2[i14 + (r2.size(0) *
                      i13)];
                  }
                }
              }

              i_loop_ub = r1.size(0);
              if ((static_cast<int>(r1.size(0) < 4)) != 0) {
                for (int i15{0}; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              } else {

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

                for (int i15 = 0; i15 < i_loop_ub; i15++) {
                  labels[i15] = r1[i15];
                }
              }
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::q_init()
          {
            static const double b_dv1[2][19]{ { 0.15021459227467868,
                0.08837209302325616, 0.88888888888888884, 1.0,
                0.053140096618357689, 1.0, 0.0, 0.048543689320388529, 1.0,
                0.75000000000000011, 0.0051546391752577509, 1.0, 0.0, 0.0,
                0.019607843137254888, 0.0, 0.33333333333333331, 0.0, 1.0 }, {
                0.84978540772532141, 0.9116279069767439, 0.11111111111111106,
                0.0, 0.94685990338164239, 0.0, 1.0, 0.95145631067961145, 0.0,
                0.25, 0.99484536082474229, 0.0, 1.0, 1.0, 0.98039215686274506,
                1.0, 0.66666666666666663, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.3725, 0.9065359477124183,
              0.19737154729623579, 0.0, 1.5717835343699613, 0.0, 0.0,
              0.74617898441427855, 0.0, 0.2375, 0.97913823836744718, 0.0, 0.0,
              0.0, 0.067577491896989667, 0.0, 1.4132363606378191, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 1, 3, 8, 0, 2, 0, 0, 5, 0, 1, 5,
              0, 0, 0, 7, 0, 2, 0, 0 };

            static const bool b_bv[19]{ false, false, false, true, false, true,
              true, false, true, false, false, true, true, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::q_init()
          {
            static const double b_dv1[2][17]{ { 0.16738197424892762,
                0.95238095238095233, 0.089622641509434289, 1.0,
                0.66666666666666663, 0.044554455445544712, 1.0, 0.0, 1.0,
                0.021739130434782684, 0.27777777777777768, 0.66666666666666663,
                0.0, 1.0, 0.0, 0.0, 1.0 }, { 0.83261802575107235,
                0.047619047619047596, 0.91037735849056567, 0.0,
                0.33333333333333331, 0.95544554455445529, 0.0, 1.0, 0.0,
                0.97826086956521729, 0.72222222222222221, 0.33333333333333331,
                1.0, 0.0, 1.0, 1.0, 0.0 } };

            static const double b_dv[17]{ 0.10250000000000001, 0.085, 0.435, 0.0,
              -0.1178019490069466, 0.1592347817061413, 0.0, 0.0, 0.0,
              0.67588566383401383, 0.90931372549019607, 0.96118421052631575, 0.0,
              0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 12,
                13 }, { 14, 15 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 1, 1, 1, 0, 8, 8, 0, 0, 0, 5, 3,
              3, 0, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, false, false, true, false, false,
              true, true, true, false, false, false, true, true, true, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.66523605150214582 * (static_cast<double>(b_kk)))
                + 0.16738197424892703;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::r_init()
          {
            static const double b_dv1[2][19]{ { 0.10300429184549396, 1.0,
                0.02790697674418615, 0.014150943396226467, 1.0,
                0.16666666666666666, 0.0097087378640777072, 0.0, 1.0, 0.0,
                0.037037037037037014, 0.0, 0.11111111111111106, 1.0,
                0.058823529411764677, 0.0, 0.2, 0.0, 1.0 }, { 0.896995708154506,
                0.0, 0.97209302325581393, 0.98584905660377353, 0.0,
                0.83333333333333337, 0.99029126213592233, 1.0, 0.0, 1.0,
                0.96296296296296291, 1.0, 0.88888888888888884, 0.0,
                0.94117647058823528, 1.0, 0.8, 1.0, 0.0 } };

            static const double b_dv[19]{ 0.89953678983356467, 0.0,
              1.5717835343699613, 0.66927083333333326, 0.0, 1.3256943931743947,
              1.3886966894238384, 0.0, 0.0, 0.0, 0.14250000000000002, 0.0,
              0.71973223698081379, 0.0, 0.065266009681589271, 0.0,
              1.4206264937901973, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 0, 0 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 2, 0, 2, 4, 0, 2, 2, 0, 0, 0, 1,
              0, 5, 0, 7, 0, 2, 0, 0 };

            static const bool b_bv[19]{ false, true, false, false, true, false,
              false, true, true, true, false, true, false, true, false, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.79399141630901293 * (static_cast<double>(b_kk)))
                + 0.10300429184549356;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::r_init()
          {
            static const double b_dv1[2][17]{ { 0.14592274678111641, 1.0,
                0.0700934579439255, 1.0, 0.04784688995215329, 1.0,
                0.024509803921568717, 0.0, 0.071428571428571425,
                0.017857142857142846, 0.2857142857142857, 0.0,
                0.058823529411764677, 1.0, 0.0, 1.0, 0.0 }, {
                0.85407725321888361, 0.0, 0.92990654205607459, 0.0,
                0.95215311004784675, 0.0, 0.97549019607843135, 1.0,
                0.9285714285714286, 0.9821428571428571, 0.7142857142857143, 1.0,
                0.94117647058823528, 0.0, 1.0, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.63282828282828285, 0.0, 0.09, 0.0,
              0.89518679155439274, 0.0, 0.82738095238095233, 0.0,
              0.12006194704975895, 0.065141858470548278, 0.75130718954248366,
              0.0, 0.066594187198167759, 0.0, 0.0, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 0, 1, 0, 2, 0, 4, 0, 8, 7, 5,
              0, 7, 0, 0, 0, 0 };

            static const bool b_bv[17]{ false, true, false, true, false, true,
              false, true, false, false, false, true, false, true, true, true,
              true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::s_init()
          {
            static const double b_dv1[2][19]{ { 0.17167381974248988,
                0.9285714285714286, 0.068292682926829523, 1.0,
                0.84615384615384615, 0.020512820512820586, 1.0, 0.0,
                0.91666666666666663, 1.0, 0.010362694300518173, 1.0, 0.0, 1.0,
                0.0052083333333333521, 0.0, 0.035714285714285691, 1.0, 0.0 }, {
                0.82832618025751015, 0.071428571428571383, 0.93170731707317056,
                0.0, 0.15384615384615383, 0.97948717948717945, 0.0, 1.0,
                0.083333333333333315, 0.0, 0.98963730569948194, 0.0, 1.0, 0.0,
                0.99479166666666663, 1.0, 0.9642857142857143, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.84600804424333842, 0.11,
              0.42000000000000004, 0.0, -0.14240200381655138,
              0.90784708249496981, 0.0, 0.0, 0.17783168210074501, 0.0, 0.09, 0.0,
              0.0, 0.0, 0.073822651979343984, 0.0, 0.074626002628498389, 0.0,
              0.0 };

            static const signed char b_iv[19]{ 5, 1, 1, 0, 8, 3, 0, 0, 8, 0, 1,
              0, 0, 0, 7, 0, 7, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv4[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv4[b_i][1]);
              NanCutPoints[b_i] = bv3[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6566523605150214 * (static_cast<double>(b_kk))) +
                0.17167381974248927;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::s_init()
          {
            static const double b_dv1[2][17]{ { 0.15879828326180315, 1.0,
                0.066666666666666916, 1.0, 0.0439024390243904,
                0.013513513513513554, 0.12280701754385957, 1.0, 0.0, 0.0, 0.4375,
                1.0, 0.25, 0.0, 0.6, 1.0, 0.0 }, { 0.84120171673819688, 0.0,
                0.93333333333333313, 0.0, 0.95609756097560961,
                0.98648648648648651, 0.87719298245614041, 0.0, 1.0, 1.0, 0.5625,
                0.0, 0.75000000000000011, 1.0, 0.4, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.89791892390474715, 0.0, 0.09, 0.0,
              1.3886966894238384, -0.3104525542231954, 0.059107777100636527, 0.0,
              0.0, 0.0, 0.066594187198167759, 0.0, 0.13, 0.0,
              0.83333333333333337, 0.0, 0.0 };

            static const signed char b_iv[17]{ 2, 0, 1, 0, 2, 7, 7, 0, 0, 0, 7,
              0, 1, 0, 4, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv5[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv5[b_i][1]);
              NanCutPoints[b_i] = bv4[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.68240343347639487 * (static_cast<double>(b_kk)))
                + 0.15879828326180256;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::t_init()
          {
            static const double b_dv1[2][17]{ { 0.14163090128755418, 1.0,
                0.069767441860465379, 0.85714285714285721, 0.014925373134328412,
                0.0, 0.923076923076923, 1.0, 0.010000000000000037, 0.0, 1.0, 0.0,
                0.035714285714285691, 1.0, 0.018181818181818171, 1.0, 0.0 }, {
                0.85836909871244582, 0.0, 0.93023255813953454,
                0.14285714285714282, 0.9850746268656716, 1.0, 0.0769230769230769,
                0.0, 0.99, 1.0, 0.0, 1.0, 0.9642857142857143, 0.0,
                0.98181818181818181, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.626984126984127, 0.0,
              0.70841503267973849, 0.41425202248731663, 0.87022849208525543, 0.0,
              -0.13620573198328673, 0.0, 0.97908283537086782, 0.0, 0.0, 0.0,
              0.97948814263892015, 0.0, 0.1, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 0, 0 }, { 12, 13 }, {
                0, 0 }, { 0, 0 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, {
                0, 0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 0, 5, 5, 2, 0, 8, 0, 5, 0, 0,
              0, 5, 0, 1, 0, 0 };

            static const bool b_bv[17]{ false, true, false, false, false, true,
              false, true, false, true, true, true, false, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.71673819742489275 * (static_cast<double>(b_kk)))
                + 0.14163090128755365;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void c_CompactClassificationTree::t_init()
          {
            static const double b_dv1[2][19]{ { 0.15021459227467868,
                0.79310344827586221, 0.05882352941176492, 0.0,
                0.88461538461538469, 1.0, 0.0051813471502590866, 0.95,
                0.66666666666666663, 0.0, 0.043478260869565195, 1.0, 0.0, 1.0,
                0.0, 0.0, 0.33333333333333331, 1.0, 0.0 }, { 0.84978540772532141,
                0.20689655172413784, 0.94117647058823506, 1.0,
                0.11538461538461534, 0.0, 0.99481865284974091,
                0.049999999999999975, 0.33333333333333331, 1.0,
                0.95652173913043481, 0.0, 1.0, 0.0, 1.0, 1.0,
                0.66666666666666663, 0.0, 1.0 } };

            static const double b_dv[19]{ 0.83227752639517338,
              -0.13020172346382736, 0.93129755133013958, 0.0, 1.3528281936191691,
              0.0, 0.073476390117155968, 0.18513585514252959,
              0.68292483660130721, 0.0, 1.4206264937901973, 0.0, 0.0, 0.0, 0.0,
              0.0, 0.076839822612238123, 0.0, 0.0 };

            static const signed char b_iv1[19][2]{ { 2, 3 }, { 4, 5 }, { 6, 7 },
              { 0, 0 }, { 8, 9 }, { 0, 0 }, { 10, 11 }, { 12, 13 }, { 14, 15 },
                { 0, 0 }, { 16, 17 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, {
                0, 0 }, { 18, 19 }, { 0, 0 }, { 0, 0 } };

            static const signed char b_iv[19]{ 5, 7, 2, 0, 2, 0, 7, 8, 5, 0, 2,
              0, 0, 0, 0, 0, 7, 0, 0 };

            static const bool b_bv[19]{ false, false, false, true, false, true,
              false, false, false, true, false, true, true, true, true, true,
              false, true, true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 19; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 19; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.6995708154506437 * (static_cast<double>(b_kk))) +
                0.15021459227467812;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::u_init()
          {
            static const double b_dv1[2][17]{ { 0.15450643776824091, 1.0,
                0.083720930232558458, 0.761904761904762, 0.010309278350515502,
                0.88888888888888884, 0.0, 0.0, 0.033333333333333312, 0.0, 1.0,
                1.0, 0.016949152542372871, 0.0, 0.062499999999999972, 1.0, 0.0 },
              { 0.84549356223175909, 0.0, 0.91627906976744156,
                0.23809523809523803, 0.98969072164948457, 0.11111111111111106,
                1.0, 1.0, 0.96666666666666679, 1.0, 0.0, 0.0,
                0.98305084745762716, 1.0, 0.9375, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.89518679155439274, 0.0,
              0.80173054070112881, 0.16038931201955192, 0.97913823836744718,
              -0.18747370488400306, 0.0, 0.0, 0.97980565120996266, 0.0, 0.0, 0.0,
              0.046571618702046888, 0.0, 0.10750000000000001, 0.0, 0.0 };

            static const signed char b_iv[17]{ 2, 0, 5, 8, 5, 8, 0, 0, 5, 0, 0,
              0, 7, 0, 1, 0, 0 };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv8[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv8[b_i][1]);
              NanCutPoints[b_i] = bv7[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.69098712446351929 * (static_cast<double>(b_kk)))
                + 0.15450643776824036;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::v_init()
          {
            static const double b_dv1[2][17]{ { 0.12875536480686745, 1.0,
                0.0514018691588787, 0.66666666666666663, 0.014851485148514905,
                0.88888888888888884, 0.0, 1.0, 0.0099502487562189417, 0.0, 1.0,
                0.0, 0.039999999999999973, 0.0, 0.66666666666666663, 0.0, 1.0 },
              { 0.87124463519313255, 0.0, 0.94859813084112121,
                0.33333333333333331, 0.985148514851485, 0.1111111111111111, 1.0,
                0.0, 0.99004975124378114, 1.0, 0.0, 1.0, 0.96, 1.0,
                0.33333333333333331, 1.0, 0.0 } };

            static const double b_dv[17]{ 0.91075110456553754, 0.0,
              0.74617898441427855, 0.15386626420227806, 0.88765643985071319,
              -0.17447330093742128, 0.0, 0.0, 0.97892245827550617, 0.0, 0.0, 0.0,
              1.4132363606378191, 0.0, -0.02449714592786166, 0.0, 0.0 };

            static const signed char b_iv[17]{ 3, 0, 5, 8, 2, 8, 0, 0, 5, 0, 0,
              0, 2, 0, 8, 0, 0 };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(iv8[b_i][0]);
              Children[b_i][1] = static_cast<double>(iv8[b_i][1]);
              NanCutPoints[b_i] = bv7[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::w_init()
          {
            static const double b_dv1[2][17]{ { 0.1244635193133052, 1.0,
                0.064220183486238785, 0.8, 0.046948356807511915, 1.0, 0.0, 1.0,
                0.019323671497584613, 0.25, 0.010050251256281444, 0.0, 1.0, 0.0,
                0.086956521739130391, 1.0, 0.0 }, { 0.87553648068669476, 0.0,
                0.9357798165137613, 0.2, 0.95305164319248814, 0.0, 1.0, 0.0,
                0.98067632850241537, 0.75, 0.98994974874371866, 1.0, 0.0, 1.0,
                0.91304347826086951, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.626984126984127, 0.0,
              0.91349206349206347, 1.0044591491032739, 0.09, 0.0, 0.0, 0.0,
              0.65116013071895429, 1.2887366585179545, 0.073476390117155968, 0.0,
              0.0, 0.0, 0.074395283670663309, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 0, 3, 2, 1, 0, 0, 0, 5, 2, 7,
              0, 0, 0, 7, 0, 0 };

            static const bool b_bv[17]{ false, true, false, false, false, true,
              true, true, false, false, false, true, true, true, false, true,
              true };

            int b_kk;
            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            b_kk = 0;
            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = (0.75107296137339064 * (static_cast<double>(b_kk)))
                + 0.12446351931330472;
              b_kk++;
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::x_init()
          {
            static const double b_dv1[2][17]{ { 0.14592274678111641, 1.0,
                0.08294930875576069, 1.0, 0.04784688995215329, 0.875,
                0.014925373134328412, 1.0, 0.0, 0.25, 0.010152284263959428, 0.0,
                1.0, 0.0, 0.076923076923076886, 1.0, 0.0 }, {
                0.85407725321888361, 0.0, 0.91705069124423932, 0.0,
                0.95215311004784675, 0.125, 0.9850746268656716, 0.0, 1.0, 0.75,
                0.98984771573604058, 1.0, 0.0, 1.0, 0.923076923076923, 0.0, 1.0
              } };

            static const double b_dv[17]{ 0.626984126984127, 0.0, 0.09, 0.0,
              0.74617898441427855, 0.25, 0.91349206349206347, 0.0, 0.0,
              0.9122315592903828, 0.073822651979343984, 0.0, 0.0, 0.0,
              0.074395283670663309, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 0, 0 }, { 6, 7 }, { 8, 9 }, { 10, 11 }, { 0, 0 }, { 0, 0 }, { 12,
                13 }, { 14, 15 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 4, 0, 1, 0, 5, 1, 3, 0, 0, 3, 7,
              0, 0, 0, 7, 0, 0 };

            static const bool b_bv[17]{ false, true, false, true, false, false,
              false, true, true, false, false, true, true, true, false, true,
              true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }

          //
          // Arguments    : void
          // Return Type  : void
          //
          void b_CompactClassificationTree::y_init()
          {
            static const double b_dv1[2][17]{ { 0.12875536480686745, 1.0,
                0.0814479638009053, 0.92857142857142849, 0.024154589371980766,
                1.0, 0.0, 1.0, 0.014634146341463468, 0.0, 0.058823529411764663,
                1.0, 0.039999999999999973, 0.0, 0.22222222222222221, 1.0, 0.0 },
              { 0.87124463519313255, 0.0, 0.91855203619909476,
                0.071428571428571411, 0.97584541062801922, 0.0, 1.0, 0.0,
                0.98536585365853646, 1.0, 0.94117647058823528, 0.0, 0.96, 1.0,
                0.77777777777777768, 0.0, 1.0 } };

            static const double b_dv[17]{ 0.909163802978236, 0.0,
              0.70841503267973849, 0.11444361890727524, 0.56577246283128635, 0.0,
              0.0, 0.0, 0.97913823836744718, 0.0, 0.97948814263892015, 0.0,
              1.4109020164511108, 0.0, 1.4189694677219074, 0.0, 0.0 };

            static const signed char b_iv1[17][2]{ { 2, 3 }, { 0, 0 }, { 4, 5 },
              { 6, 7 }, { 8, 9 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 10, 11 }, { 0,
                0 }, { 12, 13 }, { 0, 0 }, { 14, 15 }, { 0, 0 }, { 16, 17 }, { 0,
                0 }, { 0, 0 } };

            static const signed char b_iv[17]{ 3, 0, 5, 7, 4, 0, 0, 0, 5, 0, 5,
              0, 2, 0, 2, 0, 0 };

            static const bool b_bv[17]{ false, true, false, false, false, true,
              true, true, false, true, false, true, false, true, false, true,
              true };

            signed char o_I[2][2];
            ClassNames[0] = 0.0;
            ClassNamesLength[0] = 1;
            ClassLogicalIndices[0] = true;
            ClassNames[1] = 1.0;
            ClassNamesLength[1] = 1;
            ClassLogicalIndices[1] = true;
            ScoreTransform = coderutils::Identity;
            for (int b_i{0}; b_i < 17; b_i++) {
              CutPoint[b_i] = b_dv[b_i];
              CutPredictorIndex[b_i] = static_cast<double>(b_iv[b_i]);
              Children[b_i][0] = static_cast<double>(b_iv1[b_i][0]);
              Children[b_i][1] = static_cast<double>(b_iv1[b_i][1]);
              NanCutPoints[b_i] = b_bv[b_i];
              InfCutPoints[b_i] = false;
            }

            for (int c_ii{0}; c_ii < 2; c_ii++) {
              for (int c_i{0}; c_i < 17; c_i++) {
                ClassProbability[c_ii][c_i] = b_dv1[c_ii][c_i];
              }

              Prior[c_ii] = dv1[c_ii];
              o_I[c_ii][0] = 0;
              o_I[c_ii][1] = 0;
            }

            o_I[0][0] = 1;
            o_I[1][1] = 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads())

            for (int i1 = 0; i1 < 2; i1++) {
              Cost[i1][0] = 1.0 - (static_cast<double>(o_I[i1][0]));
              Cost[i1][1] = 1.0 - (static_cast<double>(o_I[i1][1]));
            }
          }
        }
      }
    }
  }
}

//
// File trailer for CompactClassificationTree.cpp
//
// [EOF]
//
