//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predictOneWithCache.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationTree;

class b_CompactClassificationTree;

class c_CompactClassificationTree;

class d_CompactClassificationTree;

class e_CompactClassificationTree;

class f_CompactClassificationTree;

class g_CompactClassificationTree;

class h_CompactClassificationTree;

class i_CompactClassificationTree;

class j_CompactClassificationTree;

class k_CompactClassificationTree;

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void b_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               b_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void c_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               c_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void d_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               d_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void e_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               e_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void f_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               f_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void g_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               g_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void h_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               h_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void i_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               i_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void j_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               j_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void k_predictOneWithCache(const ::coder::array<double, 2U> &d_X,
                           ::coder::array<double, 2U> &cachedScore,
                           ::coder::array<double, 1U> &cachedWeights,
                           const char combiner[15],
                           const ::ITER::coder::classreg::learning::classif::
                               k_CompactClassificationTree *weak_learner,
                           double b_learnerWeights, bool *cached,
                           const double c_classnames[2],
                           const bool b_classlogicalindices[2],
                           const ::coder::array<bool, 1U> &useObsForLearner,
                           bool initCache, ::coder::array<double, 2U> &score);

void predictOneWithCache(
    const ::coder::array<double, 2U> &d_X,
    ::coder::array<double, 2U> &cachedScore,
    ::coder::array<double, 1U> &cachedWeights, const char combiner[15],
    const ::ITER::coder::classreg::learning::classif::CompactClassificationTree
        *weak_learner,
    double b_learnerWeights, bool *cached, const double c_classnames[2],
    const bool b_classlogicalindices[2],
    const ::coder::array<bool, 1U> &useObsForLearner, bool initCache,
    ::coder::array<double, 2U> &score);

} // namespace ensembleutils
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for predictOneWithCache.h
//
// [EOF]
//
