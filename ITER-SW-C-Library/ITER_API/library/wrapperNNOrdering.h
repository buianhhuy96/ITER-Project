//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: wrapperNNOrdering.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef WRAPPERNNORDERING_H
#define WRAPPERNNORDERING_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
void wrapperNNOrdering(const double markerPts[2][5], double labels[5]);

}

#endif
//
// File trailer for wrapperNNOrdering.h
//
// [EOF]
//
