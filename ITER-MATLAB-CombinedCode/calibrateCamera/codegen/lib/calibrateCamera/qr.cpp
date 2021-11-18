//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "qr.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                ::coder::array<real_T, 2U> &b_Q
//                ::coder::array<real_T, 2U> &b_R
// Return Type  : void
//
namespace Codegen {
namespace coder {
void qr(const ::coder::array<real_T, 2U> &A, ::coder::array<real_T, 2U> &b_Q,
        ::coder::array<real_T, 2U> &b_R)
{
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> tau;
  ::coder::array<real_T, 1U> work;
  int32_T b_i;
  int32_T d_i;
  int32_T i1;
  int32_T m;
  int32_T minmana;
  int32_T minmn;
  int32_T minsz;
  int32_T u0;
  e_A.set_size(A.size(0), A.size(1));
  minmn = A.size(1);
  for (b_i = 0; b_i < minmn; b_i++) {
    minmana = A.size(0);
    for (i1 = 0; i1 < minmana; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  u0 = A.size(0);
  minmana = A.size(1);
  if (u0 <= minmana) {
    minmana = u0;
  }
  u0 = A.size(0);
  minmn = A.size(1);
  if (u0 <= minmn) {
    minmn = u0;
  }
  tau.set_size(minmana);
  for (b_i = 0; b_i < minmana; b_i++) {
    tau[b_i] = 0.0;
  }
  if (A.size(0) != 0) {
    if (minmn >= 1) {
      internal::reflapack::qrf(e_A, A.size(0), A.size(1), minmn, tau);
    }
  }
  m = e_A.size(0);
  minmana = e_A.size(1);
  u0 = e_A.size(0);
  minsz = e_A.size(1);
  if (u0 <= minsz) {
    minsz = u0;
  }
  b_R.set_size(minsz, e_A.size(1));
  for (u0 = 0; u0 < minsz; u0++) {
    for (d_i = 0; d_i <= u0; d_i++) {
      b_R[d_i + (b_R.size(0) * u0)] = e_A[d_i + (e_A.size(0) * u0)];
    }
    b_i = u0 + 2;
    for (d_i = b_i; d_i <= minsz; d_i++) {
      b_R[(d_i + (b_R.size(0) * u0)) - 1] = 0.0;
    }
  }
  b_i = e_A.size(0) + 1;
  for (u0 = b_i; u0 <= minmana; u0++) {
    for (d_i = 0; d_i < minsz; d_i++) {
      b_R[d_i + (b_R.size(0) * (u0 - 1))] = e_A[d_i + (e_A.size(0) * (u0 - 1))];
    }
  }
  if (minsz >= 1) {
    int32_T ia;
    int32_T itau;
    b_i = minsz - 1;
    for (u0 = minsz; u0 <= b_i; u0++) {
      ia = u0 * m;
      i1 = m - 1;
      for (d_i = 0; d_i <= i1; d_i++) {
        e_A[ia + d_i] = 0.0;
      }
      e_A[ia + u0] = 1.0;
    }
    itau = minsz - 1;
    work.set_size(e_A.size(1));
    minmn = e_A.size(1);
    for (b_i = 0; b_i < minmn; b_i++) {
      work[b_i] = 0.0;
    }
    for (d_i = minsz; d_i >= 1; d_i--) {
      int32_T iaii;
      iaii = d_i + ((d_i - 1) * m);
      if (d_i < minsz) {
        int32_T jA;
        int32_T lastv;
        e_A[iaii - 1] = 1.0;
        jA = iaii + m;
        if (tau[itau] != 0.0) {
          boolean_T exitg1;
          lastv = (m - d_i) + 1;
          minmana = (iaii + m) - d_i;
          exitg1 = false;
          while ((!exitg1) && (lastv > 0)) {
            if (e_A[minmana - 1] == 0.0) {
              lastv--;
              minmana--;
            } else {
              exitg1 = true;
            }
          }
          minmn = minsz - d_i;
          exitg1 = false;
          while ((!exitg1) && (minmn > 0)) {
            int32_T exitg2;
            minmana = jA + ((minmn - 1) * m);
            ia = minmana;
            do {
              exitg2 = 0;
              if (ia <= ((minmana + lastv) - 1)) {
                if (e_A[ia - 1] != 0.0) {
                  exitg2 = 1;
                } else {
                  ia++;
                }
              } else {
                minmn--;
                exitg2 = 2;
              }
            } while (exitg2 == 0);
            if (exitg2 == 1) {
              exitg1 = true;
            }
          }
        } else {
          lastv = 0;
          minmn = 0;
        }
        if (lastv > 0) {
          real_T c;
          if (minmn != 0) {
            for (minmana = 0; minmana < minmn; minmana++) {
              work[minmana] = 0.0;
            }
            minmana = 0;
            b_i = jA + (m * (minmn - 1));
            u0 = jA;
            while (((m > 0) && (u0 <= b_i)) || ((m < 0) && (u0 >= b_i))) {
              c = 0.0;
              i1 = (u0 + lastv) - 1;
              for (ia = u0; ia <= i1; ia++) {
                c += e_A[ia - 1] * e_A[((iaii + ia) - u0) - 1];
              }
              work[minmana] = work[minmana] + c;
              minmana++;
              u0 += m;
            }
          }
          c = -tau[itau];
          if (!(c == 0.0)) {
            for (u0 = 0; u0 < minmn; u0++) {
              if (work[u0] != 0.0) {
                real_T temp;
                temp = work[u0] * c;
                b_i = lastv + jA;
                for (minmana = jA; minmana < b_i; minmana++) {
                  e_A[minmana - 1] = e_A[minmana - 1] +
                                     (e_A[((iaii + minmana) - jA) - 1] * temp);
                }
              }
              jA += m;
            }
          }
        }
      }
      if (d_i < m) {
        minmana = iaii + 1;
        b_i = (iaii + m) - d_i;
        for (minmn = minmana; minmn <= b_i; minmn++) {
          e_A[minmn - 1] = (-tau[itau]) * e_A[minmn - 1];
        }
      }
      e_A[iaii - 1] = 1.0 - tau[itau];
      for (u0 = 0; u0 <= (d_i - 2); u0++) {
        e_A[(iaii - u0) - 2] = 0.0;
      }
      itau--;
    }
  }
  b_Q.set_size(m, minsz);
  for (u0 = 0; u0 < minsz; u0++) {
    for (d_i = 0; d_i < m; d_i++) {
      b_Q[d_i + (b_Q.size(0) * u0)] = e_A[d_i + (e_A.size(0) * u0)];
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for qr.cpp
//
// [EOF]
//
