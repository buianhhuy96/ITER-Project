//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: schur.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "schur.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "xdhseqr.h"
#include "xnrm2.h"
#include "xzlarf.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : const double A[4][4]
//                double V[4][4]
//                double T[4][4]
// Return Type  : void
//
namespace coder {
void schur(const double A[4][4], double V[4][4], double T[4][4])
{
  double work[4];
  double tau[3];
  int i1;
  int i3;
  int i5;
  int i6;
  bool p;
  p = true;
  for (int k{0}; k < 4; k++) {
    for (int b_k{0}; b_k < 4; b_k++) {
      if (p) {
        if ((std::isinf(A[k][b_k])) || (std::isnan(A[k][b_k]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (!p) {
    int istart;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int c_i = 0; c_i < 4; c_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        V[c_i][i1] = rtNaN;
      }
    }
    istart = 2;
    for (int j{0}; j < 3; j++) {
      for (int e_i{istart}; e_i < 5; e_i++) {
        V[j][e_i - 1] = 0.0;
      }
      istart++;
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6)

    for (int i4 = 0; i4 < 4; i4++) {
      for (i6 = 0; i6 < 4; i6++) {
        T[i4][i6] = rtNaN;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

    for (int b_i = 0; b_i < 4; b_i++) {
      for (i3 = 0; i3 < 4; i3++) {
        T[b_i][i3] = A[b_i][i3];
      }
      work[b_i] = 0.0;
    }
    for (int d_i{0}; d_i < 3; d_i++) {
      double alpha1;
      double alpha1_tmp;
      double b_xnorm;
      int b_in;
      int ic0;
      int im1n_tmp;
      int iv0;
      int ix0;
      int k_i;
      int lastc;
      int lastv;
      im1n_tmp = (d_i * 4) + 2;
      b_in = (d_i + 1) * 4;
      alpha1_tmp = T[d_i][d_i + 1];
      alpha1 = alpha1_tmp;
      if ((d_i + 3) <= 4) {
        k_i = d_i + 1;
      } else {
        k_i = 2;
      }
      ix0 = k_i + im1n_tmp;
      tau[d_i] = 0.0;
      b_xnorm = internal::blas::f_xnrm2(2 - d_i, T, ix0);
      if (b_xnorm != 0.0) {
        double beta1;
        beta1 = rt_hypotd_snf(alpha1_tmp, b_xnorm);
        if (alpha1_tmp >= 0.0) {
          beta1 = -beta1;
        }
        if (std::abs(beta1) < 1.0020841800044864E-292) {
          double c_a;
          int i10;
          int i15;
          int knt;
          knt = -1;
          i10 = (ix0 - d_i) + 1;
          do {
            knt++;
            for (int e_k{ix0}; e_k <= i10; e_k++) {
              (&T[0][0])[e_k - 1] *= 9.9792015476736E+291;
            }
            beta1 *= 9.9792015476736E+291;
            alpha1 *= 9.9792015476736E+291;
          } while (!(std::abs(beta1) >= 1.0020841800044864E-292));
          beta1 =
              rt_hypotd_snf(alpha1, internal::blas::f_xnrm2(2 - d_i, T, ix0));
          if (alpha1 >= 0.0) {
            beta1 = -beta1;
          }
          tau[d_i] = (beta1 - alpha1) / beta1;
          c_a = 1.0 / (alpha1 - beta1);
          i15 = (ix0 - d_i) + 1;
          for (int g_k{ix0}; g_k <= i15; g_k++) {
            (&T[0][0])[g_k - 1] *= c_a;
          }
          for (int h_k{0}; h_k <= knt; h_k++) {
            beta1 *= 1.0020841800044864E-292;
          }
          alpha1 = beta1;
        } else {
          double b_a;
          int i11;
          tau[d_i] = (beta1 - alpha1_tmp) / beta1;
          b_a = 1.0 / (alpha1_tmp - beta1);
          i11 = (ix0 - d_i) + 1;
          for (int d_k{ix0}; d_k <= i11; d_k++) {
            (&T[0][0])[d_k - 1] *= b_a;
          }
          alpha1 = beta1;
        }
      }
      T[d_i][d_i + 1] = 1.0;
      iv0 = (d_i + im1n_tmp) - 1;
      ic0 = b_in + 1;
      if (tau[d_i] != 0.0) {
        int b_lastc;
        int w_i;
        bool exitg2;
        lastv = 2 - d_i;
        w_i = (iv0 - d_i) + 2;
        while (((lastv + 1) > 0) && ((&T[0][0])[w_i] == 0.0)) {
          lastv--;
          w_i--;
        }
        b_lastc = 4;
        exitg2 = false;
        while ((!exitg2) && (b_lastc > 0)) {
          int b_ia;
          int exitg1;
          int rowleft;
          rowleft = b_in + b_lastc;
          b_ia = rowleft;
          do {
            exitg1 = 0;
            if (b_ia <= (rowleft + (lastv * 4))) {
              if ((&T[0][0])[b_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                b_ia += 4;
              }
            } else {
              b_lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
        lastc = b_lastc;
      } else {
        lastv = -1;
        lastc = 0;
      }
      if ((lastv + 1) > 0) {
        if (lastc != 0) {
          int b_ix;
          int i12;
          if (0 <= (lastc - 1)) {
            (void)std::memset(&work[0], 0,
                              (static_cast<unsigned int>(lastc)) *
                                  (sizeof(double)));
          }
          b_ix = iv0;
          i12 = (b_in + (lastv * 4)) + 1;
          for (int iac{ic0}; iac <= i12; iac += 4) {
            int i13;
            i13 = (iac + lastc) - 1;
            for (int c_ia{iac}; c_ia <= i13; c_ia++) {
              int work_tmp;
              work_tmp = c_ia - iac;
              work[work_tmp] += (&T[0][0])[c_ia - 1] * (&T[0][0])[b_ix];
            }
            b_ix++;
          }
        }
        if (!((-tau[d_i]) == 0.0)) {
          int jA;
          jA = b_in;
          for (int d_j{0}; d_j <= lastv; d_j++) {
            double d;
            d = (&T[0][0])[iv0 + d_j];
            if (d != 0.0) {
              double temp;
              int i14;
              int i16;
              temp = d * (-tau[d_i]);
              i14 = jA + 1;
              i16 = lastc + jA;
              for (int ijA{i14}; ijA <= i16; ijA++) {
                (&T[0][0])[ijA - 1] += work[(ijA - jA) - 1] * temp;
              }
            }
            jA += 4;
          }
        }
      }
      internal::reflapack::b_xzlarf(3 - d_i, 3 - d_i, d_i + im1n_tmp, tau[d_i],
                                    T, (d_i + b_in) + 2, work);
      T[d_i][d_i + 1] = alpha1;
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5)

    for (int i2 = 0; i2 < 4; i2++) {
      for (i5 = 0; i5 < 4; i5++) {
        V[i2][i5] = T[i2][i5];
      }
    }
    for (int b_j{2}; b_j >= 0; b_j--) {
      int i7;
      int ia;
      ia = (b_j + 1) * 4;
      for (int h_i{0}; h_i <= b_j; h_i++) {
        (&V[0][0])[ia + h_i] = 0.0;
      }
      i7 = b_j + 3;
      for (int q_i{i7}; q_i < 5; q_i++) {
        int b_i8;
        b_i8 = ia + q_i;
        (&V[0][0])[b_i8 - 1] = (&V[0][0])[b_i8 - 5];
      }
    }
    for (int g_i{0}; g_i < 4; g_i++) {
      (&V[0][0])[g_i] = 0.0;
    }
    (&V[0][0])[0] = 1.0;
    for (int m_i{0}; m_i < 4; m_i++) {
      work[m_i] = 0.0;
    }
    for (int t_i{2}; t_i >= 0; t_i--) {
      int iaii;
      iaii = (t_i + (t_i * 4)) + 5;
      if ((t_i + 1) < 3) {
        int b_ix0;
        int i9;
        (&V[0][0])[iaii] = 1.0;
        internal::reflapack::b_xzlarf(3 - t_i, 2 - t_i, iaii + 1, tau[t_i], V,
                                      iaii + 5, work);
        b_ix0 = iaii + 2;
        i9 = (iaii - t_i) + 3;
        for (int c_k{b_ix0}; c_k <= i9; c_k++) {
          (&V[0][0])[c_k - 1] *= -tau[t_i];
        }
      }
      (&V[0][0])[iaii] = 1.0 - tau[t_i];
      for (int c_j{0}; c_j < t_i; c_j++) {
        (&V[0][0])[(iaii - c_j) - 1] = 0.0;
      }
    }
    (void)internal::reflapack::eml_dlahqr(T, V);
    T[0][3] = 0.0;
  }
}

} // namespace coder

//
// File trailer for schur.cpp
//
// [EOF]
//
