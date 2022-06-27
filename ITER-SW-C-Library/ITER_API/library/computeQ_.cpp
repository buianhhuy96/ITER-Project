//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeQ_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "computeQ_.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : struct_T *obj
//                int b_nrows
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void computeQ_(struct_T *obj, int b_nrows)
{
  double work[15];
  int b_i;
  int b_m;
  int d_lda;
  int k;
  b_i = obj->minRowCol;
  for (int idx{0}; idx < b_i; idx++) {
    int h_n;
    int iQR0;
    iQR0 = (obj->ldq * idx) + idx;
    h_n = obj->mrows - idx;
    for (int b_k{0}; b_k <= (h_n - 2); b_k++) {
      int i2;
      i2 = (iQR0 + b_k) + 1;
      (&obj->Q[0][0])[i2] = (&obj->QR[0][0])[i2];
    }
  }
  b_m = obj->mrows;
  k = obj->minRowCol;
  d_lda = obj->ldq;
  if (b_nrows >= 1) {
    int i1;
    int itau;
    i1 = b_nrows - 1;
    for (int j{k}; j <= i1; j++) {
      int i3;
      int ia;
      ia = j * d_lda;
      i3 = b_m - 1;
      for (int d_i{0}; d_i <= i3; d_i++) {
        (&obj->Q[0][0])[ia + d_i] = 0.0;
      }
      (&obj->Q[0][0])[ia + j] = 1.0;
    }
    itau = obj->minRowCol - 1;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i < 15; c_i++) {
      work[c_i] = 0.0;
    }
    for (int e_i = obj->minRowCol; e_i >= 1; e_i--) {
      int iaii;
      iaii = (e_i + ((e_i - 1) * d_lda)) - 1;
      if (e_i < b_nrows) {
        int ic0;
        int lastc;
        int lastv;
        (&obj->Q[0][0])[iaii] = 1.0;
        ic0 = (iaii + d_lda) + 1;
        if (obj->tau[itau] != 0.0) {
          int b_lastc;
          int g_i;
          bool exitg2;
          lastv = b_m - e_i;
          g_i = (iaii + b_m) - e_i;
          while (((lastv + 1) > 0) && ((&obj->Q[0][0])[g_i] == 0.0)) {
            lastv--;
            g_i--;
          }
          b_lastc = (b_nrows - e_i) - 1;
          exitg2 = false;
          while ((!exitg2) && ((b_lastc + 1) > 0)) {
            int b_ia;
            int coltop;
            int exitg1;
            coltop = ic0 + (b_lastc * d_lda);
            b_ia = coltop;
            do {
              exitg1 = 0;
              if (b_ia <= (coltop + lastv)) {
                if ((&obj->Q[0][0])[b_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  b_ia++;
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
          lastc = -1;
        }
        if ((lastv + 1) > 0) {
          if ((lastc + 1) != 0) {
            int b_iy;
            int i5;
            int iac;
            if (0 <= lastc) {
              (void)std::memset(
                  &work[0], 0,
                  (static_cast<unsigned int>(static_cast<int>(lastc + 1))) *
                      (sizeof(double)));
            }
            b_iy = 0;
            i5 = ic0 + (d_lda * lastc);
            iac = ic0;
            while (((d_lda > 0) && (iac <= i5)) ||
                   ((d_lda < 0) && (iac >= i5))) {
              double c;
              int i7;
              c = 0.0;
              i7 = iac + lastv;
              for (int c_ia{iac}; c_ia <= i7; c_ia++) {
                c += (&obj->Q[0][0])[c_ia - 1] *
                     (&obj->Q[0][0])[(iaii + c_ia) - iac];
              }
              work[b_iy] += c;
              b_iy++;
              iac += d_lda;
            }
          }
          if (!((-obj->tau[itau]) == 0.0)) {
            int jA;
            jA = ic0;
            for (int c_j{0}; c_j <= lastc; c_j++) {
              double d;
              d = work[c_j];
              if (d != 0.0) {
                double temp;
                int i6;
                temp = d * (-obj->tau[itau]);
                i6 = lastv + jA;
                for (int ijA{jA}; ijA <= i6; ijA++) {
                  (&obj->Q[0][0])[ijA - 1] +=
                      (&obj->Q[0][0])[(iaii + ijA) - jA] * temp;
                }
              }
              jA += d_lda;
            }
          }
        }
      }
      if (e_i < b_m) {
        int i4;
        int ix0;
        ix0 = iaii + 2;
        i4 = ((iaii + b_m) - e_i) + 1;
        for (int c_k{ix0}; c_k <= i4; c_k++) {
          (&obj->Q[0][0])[c_k - 1] *= -obj->tau[itau];
        }
      }
      (&obj->Q[0][0])[iaii] = 1.0 - obj->tau[itau];
      for (int b_j{0}; b_j <= (e_i - 2); b_j++) {
        (&obj->Q[0][0])[(iaii - b_j) - 1] = 0.0;
      }
      itau--;
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeQ_.cpp
//
// [EOF]
//
