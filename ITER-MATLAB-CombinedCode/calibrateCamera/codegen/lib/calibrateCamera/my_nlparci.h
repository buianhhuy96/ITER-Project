//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: my_nlparci.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef MY_NLPARCI_H
#define MY_NLPARCI_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
void my_nlparci(const ::coder::array<real_T, 1U> &beta,
                ::coder::array<real_T, 1U> &resid,
                const ::coder::array<real_T, 2U> &b_jacobian,
                ::coder::array<real_T, 2U> &b_ci);

}

#endif
//
// File trailer for my_nlparci.h
//
// [EOF]
//
