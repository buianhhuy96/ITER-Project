//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solveP3P.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "solveP3P.h"
#include "ITER_API_rtwutil.h"
#include "abs.h"
#include "combineVectorElements.h"
#include "det.h"
#include "mrdivide_helper.h"
#include "roots.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
static double whichComponent(double b_a, double b, double p, double b_q,
                             double r);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

// Function Definitions
//
// Arguments    : double b_a
//                double b
//                double p
//                double b_q
//                double r
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
static double whichComponent(double b_a, double b, double p, double b_q,
                             double r)
{
  double c;
  double d;
  d = r * r;
  if ((((((b_a * b_a) + ((((2.0 * b) + -2.0) - (b * d)) * b_a)) - (2.0 * b)) +
        (b * b)) +
       1.0) == 0.0) {
    c = 2.0;
  } else {
    double b_F_tmp_tmp;
    double c_F;
    double d_F_tmp;
    double e_F_tmp;
    double f_F_tmp;
    double g_F_tmp;
    double pqr;
    pqr = (p * b_q) * r;
    d_F_tmp = p * p;
    e_F_tmp = b_q * b_q;
    b_F_tmp_tmp = d * d_F_tmp;
    f_F_tmp = 4.0 * e_F_tmp;
    g_F_tmp = d * e_F_tmp;
    c_F = (((((-4.0 * d_F_tmp) + (4.0 * pqr)) + b_F_tmp_tmp) + g_F_tmp) -
           ((rt_powd_snf(r, 3.0) * p) * b_q)) -
          f_F_tmp;
    if ((((((c_F * b_a) + b_F_tmp_tmp) - (4.0 * pqr)) + f_F_tmp) == 0.0) &&
        (((((c_F * b) + g_F_tmp) + (4.0 * d_F_tmp)) - (4.0 * pqr)) == 0.0)) {
      c = 3.0;
    } else if ((((b_a + b) - 1.0) == 0.0) && (r == 0.0)) {
      c = 4.0;
    } else {
      double h_F_tmp;
      h_F_tmp = d_F_tmp + d;
      if (((((h_F_tmp * b_a) - d) == 0.0) &&
           (((h_F_tmp * b) - d_F_tmp) == 0.0)) &&
          (b_q == 0.0)) {
        c = 5.0;
      } else {
        double d_F;
        double i_F_tmp;
        double j_F_tmp;
        i_F_tmp = d * d;
        j_F_tmp = d_F_tmp * d_F_tmp;
        d_F = (j_F_tmp - ((2.0 * d_F_tmp) * d)) + i_F_tmp;
        if ((((((d_F * b_a) - b_F_tmp_tmp) - i_F_tmp) == 0.0) &&
             ((((d_F * b) - b_F_tmp_tmp) - j_F_tmp) == 0.0)) &&
            (((h_F_tmp * b_q) - ((4.0 * p) * r)) == 0.0)) {
          c = 6.0;
        } else {
          double b_d1;
          double d2;
          double d3;
          double d4;
          b_d1 = rt_powd_snf(b_q, 3.0);
          d2 = rt_powd_snf(p, 3.0);
          d3 = rt_powd_snf(p, 4.0);
          d4 = rt_powd_snf(b_q, 4.0);
          if ((((((((((((((f_F_tmp + b_F_tmp_tmp) + d3) - d4) -
                        ((d2 * r) * b_q)) +
                       ((p * b_d1) * r)) -
                      (((4.0 * r) * p) * b_q)) *
                     b) +
                    ((2.0 * p) * b_d1)) -
                   ((2.0 * d_F_tmp) * e_F_tmp)) +
                  (((2.0 * d2) * r) * b_q)) -
                 (b_F_tmp_tmp * e_F_tmp)) -
                d3) -
               d4) == 0.0) {
            c = 7.0;
          } else {
            bool tf;
            if ((p == 0.0) && (r == 0.0)) {
              tf = true;
            } else {
              tf = false;
            }
            if (tf) {
              c = 9.0;
            } else {
              c = 1.0;
            }
          }
        }
      }
    }
  }
  return c;
}

//
// Arguments    : const double imagePointsIn[2][4]
//                const ::coder::array<double, 2U> &worldPointsIn
//                const double f_K[3][3]
//                ::coder::array<double, 3U> &b_Rs
//                ::coder::array<double, 2U> &Ts
// Return Type  : void
//
void solveP3P(const double imagePointsIn[2][4],
              const ::coder::array<double, 2U> &worldPointsIn,
              const double f_K[3][3], ::coder::array<double, 3U> &b_Rs,
              ::coder::array<double, 2U> &Ts)
{
  ::coder::array<creal_T, 1U> d_X;
  ::coder::array<double, 2U> A;
  ::coder::array<double, 2U> U1;
  ::coder::array<double, 2U> b_R;
  ::coder::array<double, 2U> b_a;
  ::coder::array<double, 2U> b_z1;
  ::coder::array<double, 2U> c_C;
  ::coder::array<double, 2U> c_y;
  ::coder::array<double, 2U> c_z1;
  ::coder::array<double, 2U> centroid1;
  ::coder::array<double, 2U> e_B;
  ::coder::array<double, 2U> e_C;
  ::coder::array<double, 2U> e_R;
  ::coder::array<double, 2U> e_v;
  ::coder::array<double, 2U> e_y;
  ::coder::array<double, 2U> g_U;
  ::coder::array<double, 2U> g_b;
  ::coder::array<double, 2U> k_y;
  ::coder::array<double, 2U> normPoints1;
  ::coder::array<double, 2U> r2;
  ::coder::array<double, 1U> c_r;
  ::coder::array<double, 1U> j_X;
  ::coder::array<double, 1U> k_X;
  ::coder::array<double, 1U> s;
  ::coder::array<double, 1U> s1;
  ::coder::array<bool, 1U> r1;
  double U[3][4];
  double b_imagePointsIn[3][4];
  double z1[3][4];
  double V[3][3];
  double V1[3][3];
  double c_q[3][3];
  double normPoints2[3][3];
  double coeffs[5];
  double b_x[4];
  double centroid2[3];
  double d_y[3];
  double AB2;
  double b;
  double b_U;
  double b_q;
  double c_a;
  double cosUV;
  double d;
  double p;
  double r;
  int b_loop_ub;
  int c_k;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i13;
  int i15;
  int i2;
  int i_N;
  int i_loop_ub;
  int k_N;
  int loop_ub;
  int m_N;
  bool b_b[5];
  bool b_b1;
  bool c_b;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

  for (int b_i = 0; b_i < 2; b_i++) {
    for (i2 = 0; i2 < 4; i2++) {
      b_imagePointsIn[b_i][i2] = imagePointsIn[b_i][i2];
    }
  }
  for (int i1{0}; i1 < 4; i1++) {
    b_imagePointsIn[2][i1] = 1.0;
  }
  ::ITER::coder::internal::mrdiv(b_imagePointsIn, f_K, U);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k)

  for (int k = 0; k < 3; k++) {
    for (c_k = 0; c_k < 4; c_k++) {
      z1[k][c_k] = rt_powd_snf(U[k][c_k], 2.0);
    }
  }
  b_sum(z1, b_x);
  for (int b_k{0}; b_k < 4; b_k++) {
    b_x[b_k] = std::sqrt(b_x[b_k]);
  }
  b_U = 0.0;
  for (int d_k{0}; d_k < 3; d_k++) {
    for (int e_k{0}; e_k < 4; e_k++) {
      U[d_k][e_k] /= b_x[e_k];
    }
    b_U += U[d_k][0] * U[d_k][1];
  }
  cosUV = b_U;
  loop_ub = worldPointsIn.size(1);
  A.set_size(1, worldPointsIn.size(1));
  b_loop_ub = worldPointsIn.size(1);
  if ((static_cast<int>(worldPointsIn.size(1) < 4)) != 0) {
    for (int i3{0}; i3 < loop_ub; i3++) {
      A[i3] = worldPointsIn[4 * i3];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < b_loop_ub; i3++) {
      A[i3] = worldPointsIn[4 * i3];
    }
  }
  c_loop_ub = worldPointsIn.size(1);
  e_B.set_size(1, worldPointsIn.size(1));
  d_loop_ub = worldPointsIn.size(1);
  if ((static_cast<int>(worldPointsIn.size(1) < 4)) != 0) {
    for (int i4{0}; i4 < c_loop_ub; i4++) {
      e_B[i4] = worldPointsIn[(4 * i4) + 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < d_loop_ub; i4++) {
      e_B[i4] = worldPointsIn[(4 * i4) + 1];
    }
  }
  e_loop_ub = worldPointsIn.size(1);
  c_C.set_size(1, worldPointsIn.size(1));
  f_loop_ub = worldPointsIn.size(1);
  if ((static_cast<int>(worldPointsIn.size(1) < 4)) != 0) {
    for (int i5{0}; i5 < e_loop_ub; i5++) {
      c_C[i5] = worldPointsIn[(4 * i5) + 2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < f_loop_ub; i5++) {
      c_C[i5] = worldPointsIn[(4 * i5) + 2];
    }
  }
  b_a.set_size(1, A.size(1));
  g_loop_ub = A.size(1);
  if ((static_cast<int>(A.size(1) < 4)) != 0) {
    for (int i6{0}; i6 < g_loop_ub; i6++) {
      b_a[i6] = A[i6] - e_B[i6];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < g_loop_ub; i6++) {
      b_a[i6] = A[i6] - e_B[i6];
    }
  }
  b_z1.set_size(1, b_a.size(1));
  i_N = b_a.size(1);
  if ((static_cast<int>(b_a.size(1) < 4)) != 0) {
    for (int g_k{0}; g_k < i_N; g_k++) {
      b_z1[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int g_k = 0; g_k < i_N; g_k++) {
      b_z1[g_k] = rt_powd_snf(b_a[g_k], 2.0);
    }
  }
  AB2 = combineVectorElements(b_z1);
  b_a.set_size(1, e_B.size(1));
  h_loop_ub = e_B.size(1);
  if ((static_cast<int>(e_B.size(1) < 4)) != 0) {
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      b_a[i7] = e_B[i7] - c_C[i7];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < h_loop_ub; i7++) {
      b_a[i7] = e_B[i7] - c_C[i7];
    }
  }
  b_z1.set_size(1, b_a.size(1));
  k_N = b_a.size(1);
  if ((static_cast<int>(b_a.size(1) < 4)) != 0) {
    for (int h_k{0}; h_k < k_N; h_k++) {
      b_z1[h_k] = rt_powd_snf(b_a[h_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int h_k = 0; h_k < k_N; h_k++) {
      b_z1[h_k] = rt_powd_snf(b_a[h_k], 2.0);
    }
  }
  b_a.set_size(1, A.size(1));
  i_loop_ub = A.size(1);
  if ((static_cast<int>(A.size(1) < 4)) != 0) {
    for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
      b_a[b_i8] = A[b_i8] - c_C[b_i8];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < i_loop_ub; b_i8++) {
      b_a[b_i8] = A[b_i8] - c_C[b_i8];
    }
  }
  c_z1.set_size(1, b_a.size(1));
  m_N = b_a.size(1);
  if ((static_cast<int>(b_a.size(1) < 4)) != 0) {
    for (int i_k{0}; i_k < m_N; i_k++) {
      c_z1[i_k] = rt_powd_snf(b_a[i_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i_k = 0; i_k < m_N; i_k++) {
      c_z1[i_k] = rt_powd_snf(b_a[i_k], 2.0);
    }
  }
  c_a = combineVectorElements(b_z1) / AB2;
  b = combineVectorElements(c_z1) / AB2;
  p = 2.0 * (((U[0][1] * U[0][2]) + (U[1][1] * U[1][2])) + (U[2][1] * U[2][2]));
  b_q =
      2.0 * (((U[0][0] * U[0][2]) + (U[1][0] * U[1][2])) + (U[2][0] * U[2][2]));
  r = 2.0 * cosUV;
  if (whichComponent(c_a, b, p, b_q, r) != 1.0) {
    b_Rs.set_size(3, 3, 0);
    Ts.set_size(0, 3);
  } else {
    double b_coeffs_tmp;
    double b_coeffs_tmp_tmp;
    double c_coeffs_tmp;
    double c_coeffs_tmp_tmp;
    double coeffs_tmp;
    double coeffs_tmp_tmp;
    double coeffs_tmp_tmp_tmp;
    double d_coeffs_tmp;
    double d_coeffs_tmp_tmp;
    double e_coeffs_tmp;
    double f_coeffs_tmp;
    double g_coeffs_tmp;
    double h_coeffs_tmp;
    double i_coeffs_tmp;
    double pbr;
    int j_k;
    bool exitg1;
    bool y;
    pbr = (p * b) * r;
    coeffs_tmp_tmp = c_a * c_a;
    coeffs_tmp_tmp_tmp = r * r;
    coeffs_tmp = b * coeffs_tmp_tmp_tmp;
    b_coeffs_tmp_tmp = b * b;
    b_coeffs_tmp = coeffs_tmp * c_a;
    c_coeffs_tmp = (2.0 * b) * c_a;
    coeffs[0] = ((((((-2.0 * b) + b_coeffs_tmp_tmp) + coeffs_tmp_tmp) + 1.0) -
                  b_coeffs_tmp) +
                 c_coeffs_tmp) -
                (2.0 * c_a);
    d_coeffs_tmp = pbr * c_a;
    e_coeffs_tmp = 2.0 * coeffs_tmp_tmp;
    f_coeffs_tmp = e_coeffs_tmp * b_q;
    g_coeffs_tmp = (2.0 * b) * b_q;
    h_coeffs_tmp = (4.0 * c_a) * b_q;
    coeffs[1] = ((((((((((-2.0 * b) * b_q) * c_a) - f_coeffs_tmp) +
                      ((coeffs_tmp * b_q) * c_a)) -
                     (2.0 * b_q)) +
                    g_coeffs_tmp) +
                   h_coeffs_tmp) +
                  pbr) +
                 d_coeffs_tmp) -
                ((b_coeffs_tmp_tmp * r) * p);
    c_coeffs_tmp_tmp = p * p;
    d_coeffs_tmp_tmp = b_q * b_q;
    i_coeffs_tmp = b * c_coeffs_tmp_tmp;
    coeffs[2] =
        (((((((((((d_coeffs_tmp_tmp + (b_coeffs_tmp_tmp * coeffs_tmp_tmp_tmp)) -
                  i_coeffs_tmp) -
                 (b_q * pbr)) +
                (b_coeffs_tmp_tmp * c_coeffs_tmp_tmp)) -
               b_coeffs_tmp) +
              2.0) -
             (2.0 * b_coeffs_tmp_tmp)) -
            (d_coeffs_tmp * b_q)) +
           e_coeffs_tmp) -
          (4.0 * c_a)) -
         ((2.0 * d_coeffs_tmp_tmp) * c_a)) +
        (d_coeffs_tmp_tmp * coeffs_tmp_tmp);
    coeffs[3] =
        ((((((((((-b_coeffs_tmp_tmp) * r) * p) + d_coeffs_tmp) - f_coeffs_tmp) +
             ((b_q * c_coeffs_tmp_tmp) * b)) +
            (g_coeffs_tmp * c_a)) +
           h_coeffs_tmp) +
          pbr) -
         g_coeffs_tmp) -
        (2.0 * b_q);
    coeffs[4] = (((((1.0 - (2.0 * c_a)) + (2.0 * b)) + b_coeffs_tmp_tmp) -
                  i_coeffs_tmp) +
                 coeffs_tmp_tmp) -
                c_coeffs_tmp;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_b, b_b1, \
                                                                    d)

    for (int i9 = 0; i9 < 5; i9++) {
      d = coeffs[i9];
      b_b1 = std::isinf(d);
      c_b = std::isnan(d);
      b_b[i9] = ((!b_b1) && (!c_b));
    }
    y = true;
    j_k = 0;
    exitg1 = false;
    while ((!exitg1) && (j_k < 5)) {
      if (!b_b[j_k]) {
        y = false;
        exitg1 = true;
      } else {
        j_k++;
      }
    }
    if (!y) {
      b_Rs.set_size(3, 3, 0);
      Ts.set_size(0, 3);
    } else {
      double a_tmp;
      double d_a;
      double e_b1;
      int end;
      int i16;
      int j_loop_ub;
      int k_loop_ub;
      int m_loop_ub;
      int o_loop_ub;
      int partialTrueCount;
      int trueCount;
      roots(coeffs, d_X);
      j_X.set_size(d_X.size(0));
      j_loop_ub = d_X.size(0);
      if ((static_cast<int>(d_X.size(0) < 4)) != 0) {
        for (int i10{0}; i10 < j_loop_ub; i10++) {
          j_X[i10] = d_X[i10].im;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i10 = 0; i10 < j_loop_ub; i10++) {
          j_X[i10] = d_X[i10].im;
        }
      }
      b_abs(j_X, c_r);
      r1.set_size(c_r.size(0));
      k_loop_ub = c_r.size(0);
      if ((static_cast<int>(c_r.size(0) < 4)) != 0) {
        for (int i11{0}; i11 < k_loop_ub; i11++) {
          r1[i11] = (c_r[i11] < 1.0E-8);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i11 = 0; i11 < k_loop_ub; i11++) {
          r1[i11] = (c_r[i11] < 1.0E-8);
        }
      }
      end = r1.size(0) - 1;
      trueCount = 0;
      for (int c_i{0}; c_i <= end; c_i++) {
        if (r1[c_i]) {
          trueCount++;
        }
      }
      k_X.set_size(trueCount);
      partialTrueCount = 0;
      for (int d_i{0}; d_i <= end; d_i++) {
        if (r1[d_i]) {
          k_X[partialTrueCount] = d_X[d_i].re;
          partialTrueCount++;
        }
      }
      b_Rs.set_size(3, 3, k_X.size(0));
      m_loop_ub = k_X.size(0);
      if ((static_cast<int>((k_X.size(0) * 9) < 4)) != 0) {
        for (int i12{0}; i12 < m_loop_ub; i12++) {
          for (i13 = 0; i13 < 3; i13++) {
            b_Rs[(3 * i13) + (9 * i12)] = 0.0;
            b_Rs[((3 * i13) + (9 * i12)) + 1] = 0.0;
            b_Rs[((3 * i13) + (9 * i12)) + 2] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13)

        for (int i12 = 0; i12 < m_loop_ub; i12++) {
          for (i13 = 0; i13 < 3; i13++) {
            b_Rs[(3 * i13) + (9 * i12)] = 0.0;
            b_Rs[((3 * i13) + (9 * i12)) + 1] = 0.0;
            b_Rs[((3 * i13) + (9 * i12)) + 2] = 0.0;
          }
        }
      }
      Ts.set_size(k_X.size(0), 3);
      o_loop_ub = k_X.size(0);
      if ((static_cast<int>((3 * k_X.size(0)) < 4)) != 0) {
        for (int i14{0}; i14 < 3; i14++) {
          for (i15 = 0; i15 < o_loop_ub; i15++) {
            Ts[i15 + (Ts.size(0) * i14)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i15)

        for (int i14 = 0; i14 < 3; i14++) {
          for (i15 = 0; i15 < o_loop_ub; i15++) {
            Ts[i15 + (Ts.size(0) * i14)] = 0.0;
          }
        }
      }
      a_tmp = (p * b_q) * r;
      d_a = (((((((p * p) - a_tmp) + (r * r)) * c_a) +
               (((p * p) - (r * r)) * b)) -
              (p * p)) +
             a_tmp) -
            (r * r);
      e_b1 = b * (d_a * d_a);
      i16 = k_X.size(0);
      for (int e_i{0}; e_i < i16; e_i++) {
        double PA;
        double PB;
        double PC;
        double b_y;
        double d_y_tmp;
        double e_y_tmp;
        double f_y_tmp;
        double g_y_tmp;
        double h_y_tmp;
        double i_y_tmp;
        double j_y_tmp;
        double k_y_tmp;
        double m_y_tmp;
        double o_y_tmp;
        double p_y_tmp;
        double q_y_tmp;
        double r_y_tmp;
        double s_y_tmp;
        double t_y_tmp;
        d_y_tmp = (2.0 * r) * b_q;
        e_y_tmp = rt_powd_snf(r, 3.0);
        f_y_tmp = (2.0 * p) * c_a;
        g_y_tmp = p * (r * r);
        h_y_tmp = k_X[e_i] * k_X[e_i];
        i_y_tmp = (2.0 * p) * b_q;
        j_y_tmp = 2.0 * (p * p);
        k_y_tmp = j_y_tmp * c_a;
        m_y_tmp = rt_powd_snf(p, 3.0);
        o_y_tmp = (2.0 * p) * (r * r);
        p_y_tmp = rt_powd_snf(r, 4.0) * p;
        q_y_tmp = (j_y_tmp * b_q) * r;
        r_y_tmp = 2.0 * m_y_tmp;
        s_y_tmp = (p * (b_q * b_q)) * (r * r);
        t_y_tmp = (2.0 * e_y_tmp) * b_q;
        b_y = ((((((((1.0 - c_a) - b) * h_y_tmp) +
                   (((c_a - 1.0) * b_q) * k_X[e_i])) -
                  c_a) +
                 b) +
                1.0) *
               ((((((((((((((e_y_tmp *
                             ((((((c_a * c_a) + (b * b)) - (2.0 * c_a)) -
                                (2.0 * b)) +
                               (((2.0 - (r * r)) * c_a) * b)) +
                              1.0)) *
                            rt_powd_snf(k_X[e_i], 3.0)) +
                           (((r * r) * (((((((((((((p + (p * (c_a * c_a))) -
                                                   ((d_y_tmp * c_a) * b)) +
                                                  (d_y_tmp * b)) -
                                                 d_y_tmp) -
                                                f_y_tmp) -
                                               ((2.0 * p) * b)) +
                                              (g_y_tmp * b)) +
                                             (((4.0 * r) * b_q) * c_a)) +
                                            (((b_q * e_y_tmp) * c_a) * b)) -
                                           (d_y_tmp * (c_a * c_a))) +
                                          (f_y_tmp * b)) +
                                         (p * (b * b))) -
                                        (g_y_tmp * (b * b)))) *
                            h_y_tmp)) +
                          ((((((rt_powd_snf(r, 5.0) * ((b * b) - (c_a * b))) -
                               ((p_y_tmp * b_q) * b)) +
                              (e_y_tmp * (((((((b_q * b_q) - (4.0 * c_a)) -
                                              ((2.0 * (b_q * b_q)) * c_a)) +
                                             ((b_q * b_q) * (c_a * c_a))) +
                                            (2.0 * (c_a * c_a))) -
                                           (2.0 * (b * b))) +
                                          2.0))) +
                             ((r * r) * (((((((4.0 * p) * b_q) * c_a) -
                                            ((i_y_tmp * c_a) * b)) +
                                           (i_y_tmp * b)) -
                                          i_y_tmp) -
                                         (i_y_tmp * (c_a * c_a))))) +
                            (r * (((((((p * p) * (b * b)) - (j_y_tmp * b)) +
                                     (k_y_tmp * b)) -
                                    k_y_tmp) +
                                   (p * p)) +
                                  ((p * p) * (c_a * c_a))))) *
                           k_X[e_i])) +
                         (((((o_y_tmp - t_y_tmp) + m_y_tmp) - q_y_tmp) +
                           s_y_tmp) *
                          (c_a * c_a))) +
                        ((m_y_tmp - o_y_tmp) * (b * b))) +
                       (((((((4.0 * b_q) * e_y_tmp) - ((4.0 * p) * (r * r))) -
                           r_y_tmp) +
                          (((4.0 * (p * p)) * b_q) * r)) -
                         (((2.0 * p) * (b_q * b_q)) * (r * r))) *
                        c_a)) +
                      ((((((-2.0 * b_q) * e_y_tmp) + p_y_tmp) + q_y_tmp) -
                        r_y_tmp) *
                       b)) +
                     ((((r_y_tmp + ((2.0 * b_q) * e_y_tmp)) - q_y_tmp) * c_a) *
                      b)) +
                    s_y_tmp) -
                   q_y_tmp) +
                  o_y_tmp) +
                 m_y_tmp) -
                t_y_tmp)) /
              e_b1;
        PC = std::sqrt(AB2 / ((h_y_tmp + (b_y * b_y)) -
                              (((2.0 * k_X[e_i]) * b_y) * cosUV)));
        PB = b_y * PC;
        PA = k_X[e_i] * PC;
        if (((PC > 0.0) && (PB > 0.0)) && (PA > 0.0)) {
          double c_u;
          int b_inner;
          int b_nv;
          int c_inner;
          int h_n;
          int i19;
          int i20;
          int i22;
          int inner;
          int m;
          int mc;
          int nc;
          int p_loop_ub;
          int t_loop_ub;
          int u_loop_ub;
          int w_loop_ub;
          bool b_p;
          c_q[0][0] = U[0][0] * PA;
          c_q[0][1] = U[0][1] * PB;
          c_q[0][2] = U[0][2] * PC;
          c_q[1][0] = U[1][0] * PA;
          c_q[1][1] = U[1][1] * PB;
          c_q[1][2] = U[1][2] * PC;
          c_q[2][0] = U[2][0] * PA;
          c_q[2][1] = U[2][1] * PB;
          c_q[2][2] = U[2][2] * PC;
          if (worldPointsIn.size(1) == 0) {
            c_y.set_size(1, 0);
          } else {
            int i17;
            c_y.set_size(1, worldPointsIn.size(1));
            i17 = worldPointsIn.size(1) - 1;
            for (int k_k{0}; k_k <= i17; k_k++) {
              c_y[k_k] = worldPointsIn[4 * k_k];
              c_y[k_k] = c_y[k_k] + worldPointsIn[(4 * k_k) + 1];
              c_y[k_k] = c_y[k_k] + worldPointsIn[(4 * k_k) + 2];
            }
          }
          centroid1.set_size(1, c_y.size(1));
          p_loop_ub = c_y.size(1);
          for (int i18{0}; i18 < p_loop_ub; i18++) {
            centroid1[i18] = c_y[i18] / 3.0;
          }
          for (int m_k{0}; m_k < 3; m_k++) {
            d_y[m_k] = (c_q[m_k][0] + c_q[m_k][1]) + c_q[m_k][2];
          }
          centroid2[0] = d_y[0] / 3.0;
          centroid2[1] = d_y[1] / 3.0;
          centroid2[2] = d_y[2] / 3.0;
          if (centroid1.size(1) == 1) {
            i19 = worldPointsIn.size(1);
            i20 = worldPointsIn.size(1);
          } else {
            i19 = worldPointsIn.size(1);
            if (worldPointsIn.size(1) == 1) {
              i20 = centroid1.size(1);
            } else if (worldPointsIn.size(1) == centroid1.size(1)) {
              i20 = worldPointsIn.size(1);
            } else if (centroid1.size(1) < worldPointsIn.size(1)) {
              i20 = centroid1.size(1);
            } else {
              i20 = worldPointsIn.size(1);
            }
          }
          normPoints1.set_size(3, i20);
          if (i20 != 0) {
            int acoef;
            int bcoef;
            int i21;
            acoef = static_cast<int>(i19 != 1);
            bcoef = static_cast<int>(centroid1.size(1) != 1);
            i21 = i20 - 1;
            for (int p_k{0}; p_k <= i21; p_k++) {
              int varargin_2;
              int varargin_3;
              varargin_2 = acoef * p_k;
              varargin_3 = bcoef * p_k;
              normPoints1[3 * p_k] =
                  worldPointsIn[4 * varargin_2] - centroid1[varargin_3];
              normPoints1[(3 * p_k) + 1] =
                  worldPointsIn[(4 * varargin_2) + 1] - centroid1[varargin_3];
              normPoints1[(3 * p_k) + 2] =
                  worldPointsIn[(4 * varargin_2) + 2] - centroid1[varargin_3];
            }
          }
          m = normPoints1.size(1);
          e_C.set_size(normPoints1.size(1), 3);
          for (int o_k{0}; o_k < 3; o_k++) {
            double b_d1;
            b_d1 = centroid2[o_k];
            normPoints2[o_k][0] = c_q[o_k][0] - b_d1;
            normPoints2[o_k][1] = c_q[o_k][1] - b_d1;
            normPoints2[o_k][2] = c_q[o_k][2] - b_d1;
            for (int g_i{0}; g_i < m; g_i++) {
              e_C[g_i + (e_C.size(0) * o_k)] =
                  ((normPoints1[3 * g_i] * normPoints2[o_k][0]) +
                   (normPoints1[(3 * g_i) + 1] * normPoints2[o_k][1])) +
                  (normPoints1[(3 * g_i) + 2] * normPoints2[o_k][2]);
            }
          }
          b_p = true;
          i22 = e_C.size(0);
          for (int q_k{0}; q_k < 3; q_k++) {
            for (int r_k{0}; r_k < i22; r_k++) {
              double e_x;
              e_x = e_C[r_k + (e_C.size(0) * q_k)];
              if (b_p) {
                if ((std::isinf(e_x)) || (std::isnan(e_x))) {
                  b_p = false;
                }
              } else {
                b_p = false;
              }
            }
          }
          if (b_p) {
            ::ITER::coder::internal::g_svd(e_C, g_U, s, V);
          } else {
            int q_loop_ub;
            int r_loop_ub;
            r2.set_size(e_C.size(0), 3);
            q_loop_ub = e_C.size(0);
            for (int i23{0}; i23 < 3; i23++) {
              for (int i24{0}; i24 < q_loop_ub; i24++) {
                r2[i24 + (r2.size(0) * i23)] = 0.0;
              }
            }
            ::ITER::coder::internal::g_svd(r2, U1, s1, V1);
            g_U.set_size(U1.size(0), U1.size(1));
            r_loop_ub = U1.size(1);
            for (int i25{0}; i25 < r_loop_ub; i25++) {
              int s_loop_ub;
              s_loop_ub = U1.size(0);
              for (int i27{0}; i27 < s_loop_ub; i27++) {
                g_U[i27 + (g_U.size(0) * i25)] = rtNaN;
              }
            }
            for (int i26{0}; i26 < 3; i26++) {
              V[i26][0] = rtNaN;
              V[i26][1] = rtNaN;
              V[i26][2] = rtNaN;
            }
          }
          mc = g_U.size(0) - 1;
          inner = g_U.size(1);
          e_y.set_size(g_U.size(0), 3);
          for (int j{0}; j < 3; j++) {
            for (int h_i{0}; h_i <= mc; h_i++) {
              e_y[h_i + (e_y.size(0) * j)] = 0.0;
            }
            for (int s_k{0}; s_k < inner; s_k++) {
              for (int k_i{0}; k_i <= mc; k_i++) {
                e_y[k_i + (e_y.size(0) * j)] =
                    e_y[k_i + (e_y.size(0) * j)] +
                    (g_U[k_i + (g_U.size(0) * s_k)] * V[s_k][j]);
              }
            }
          }
          c_u = b_det(e_y);
          e_v.set_size(1, worldPointsIn.size(1));
          t_loop_ub = worldPointsIn.size(1) - 1;
          for (int i28{0}; i28 < t_loop_ub; i28++) {
            e_v[i28] = 1.0;
          }
          if (c_u < 0.0) {
            e_v[worldPointsIn.size(1) - 1] = -1.0;
          } else if (c_u > 0.0) {
            e_v[worldPointsIn.size(1) - 1] = 1.0;
          } else if (c_u == 0.0) {
            e_v[worldPointsIn.size(1) - 1] = 0.0;
          } else {
            e_v[worldPointsIn.size(1) - 1] = rtNaN;
          }
          b_nv = e_v.size(1);
          g_b.set_size(e_v.size(1), e_v.size(1));
          u_loop_ub = e_v.size(1);
          for (int i29{0}; i29 < u_loop_ub; i29++) {
            int v_loop_ub;
            v_loop_ub = e_v.size(1);
            for (int i30{0}; i30 < v_loop_ub; i30++) {
              g_b[i30 + (g_b.size(0) * i29)] = 0.0;
            }
          }
          for (int b_j{0}; b_j < b_nv; b_j++) {
            g_b[b_j + (g_b.size(0) * b_j)] = e_v[b_j];
          }
          h_n = g_b.size(1);
          k_y.set_size(3, g_b.size(1));
          for (int c_j{0}; c_j < h_n; c_j++) {
            for (int m_i{0}; m_i < 3; m_i++) {
              k_y[m_i + (3 * c_j)] =
                  ((V[0][m_i] * g_b[g_b.size(0) * c_j]) +
                   (V[1][m_i] * g_b[(g_b.size(0) * c_j) + 1])) +
                  (V[2][m_i] * g_b[(g_b.size(0) * c_j) + 2]);
            }
          }
          b_inner = k_y.size(1);
          nc = g_U.size(0);
          b_R.set_size(3, g_U.size(0));
          for (int d_j{0}; d_j < nc; d_j++) {
            b_R[3 * d_j] = 0.0;
            b_R[(3 * d_j) + 1] = 0.0;
            b_R[(3 * d_j) + 2] = 0.0;
            for (int t_k{0}; t_k < b_inner; t_k++) {
              double bkj;
              bkj = g_U[d_j + (g_U.size(0) * t_k)];
              b_R[3 * d_j] = b_R[3 * d_j] + (k_y[3 * t_k] * bkj);
              b_R[(3 * d_j) + 1] =
                  b_R[(3 * d_j) + 1] + (k_y[(3 * t_k) + 1] * bkj);
              b_R[(3 * d_j) + 2] =
                  b_R[(3 * d_j) + 2] + (k_y[(3 * t_k) + 2] * bkj);
            }
          }
          c_inner = b_R.size(1);
          d_y[0] = 0.0;
          d_y[1] = 0.0;
          d_y[2] = 0.0;
          for (int u_k{0}; u_k < c_inner; u_k++) {
            double b_bkj;
            b_bkj = centroid1[u_k];
            d_y[0] += b_R[3 * u_k] * b_bkj;
            d_y[1] += b_R[(3 * u_k) + 1] * b_bkj;
            d_y[2] += b_R[(3 * u_k) + 2] * b_bkj;
          }
          e_R.set_size(b_R.size(1), 3);
          w_loop_ub = b_R.size(1);
          for (int i31{0}; i31 < 3; i31++) {
            for (int i33{0}; i33 < w_loop_ub; i33++) {
              e_R[i33 + (e_R.size(0) * i31)] = b_R[i31 + (3 * i33)];
            }
          }
          for (int i32{0}; i32 < 3; i32++) {
            b_Rs[(3 * i32) + (9 * e_i)] = e_R[3 * i32];
            b_Rs[((3 * i32) + (9 * e_i)) + 1] = e_R[(3 * i32) + 1];
            b_Rs[((3 * i32) + (9 * e_i)) + 2] = e_R[(3 * i32) + 2];
            Ts[e_i + (Ts.size(0) * i32)] = centroid2[i32] - d_y[i32];
          }
        }
      }
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for solveP3P.cpp
//
// [EOF]
//
