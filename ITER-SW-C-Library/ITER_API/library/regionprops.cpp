//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: regionprops.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "regionprops.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_rtwutil.h"
#include "bwconncomp.h"
#include "colon.h"
#include "combineVectorElements.h"
#include "minOrMax.h"
#include "mod.h"
#include "padarray.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Type Definitions
namespace ITER {
struct d_struct_T {
  bool Area;
  bool Centroid;
  bool BoundingBox;
  bool MajorAxisLength;
  bool MinorAxisLength;
  bool Eccentricity;
  bool Orientation;
  bool Image;
  bool FilledImage;
  bool FilledArea;
  bool EulerNumber;
  bool Extrema;
  bool EquivDiameter;
  bool Extent;
  bool PixelIdxList;
  bool PixelList;
  bool Perimeter;
  bool Circularity;
  bool PixelValues;
  bool WeightedCentroid;
  bool MeanIntensity;
  bool MinIntensity;
  bool MaxIntensity;
  bool SubarrayIdx;
};

struct i_struct_T {
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  ::coder::array<bool, 2U> Image;
  ::coder::array<bool, 2U> FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[2][8];
  double EquivDiameter;
  double Extent;
  ::coder::array<double, 1U> PixelIdxList;
  ::coder::array<double, 2U> PixelList;
  double Perimeter;
  double Circularity;
  ::coder::array<double, 1U> PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  double MinIntensity;
  double MaxIntensity;
  ::coder::array<double, 2U> SubarrayIdx;
  double SubarrayIdxLengths[2];
};

struct j_struct_T {
  double Area;
  double Centroid[2];
  double BoundingBox[4];
  double MajorAxisLength;
  double MinorAxisLength;
  double Eccentricity;
  double Orientation;
  ::coder::array<bool, 2U> Image;
  ::coder::array<bool, 2U> FilledImage;
  double FilledArea;
  double EulerNumber;
  double Extrema[2][8];
  double EquivDiameter;
  double Extent;
  ::coder::array<double, 1U> PixelIdxList;
  ::coder::array<double, 2U> PixelList;
  double Perimeter;
  double Circularity;
  ::coder::array<unsigned char, 1U> PixelValues;
  double WeightedCentroid[2];
  double MeanIntensity;
  unsigned char MinIntensity;
  unsigned char MaxIntensity;
  ::coder::array<double, 2U> SubarrayIdx;
  double SubarrayIdxLengths[2];
};

} // namespace ITER

// Variable Definitions
namespace ITER {
static const double dv2[4]{0.5, 0.5, 0.0, 0.0};

}

// Function Declarations
namespace ITER {
namespace coder {
static void ComputeArea(::coder::array<i_struct_T, 1U> &stats,
                        d_struct_T *statsAlreadyComputed);

static void ComputeBoundingBox(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed);

static void ComputeCircularity(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed);

static void ComputeExtent(const double c_imageSize[2],
                          ::coder::array<i_struct_T, 1U> &stats,
                          d_struct_T *statsAlreadyComputed);

static void ComputeImage(const double c_imageSize[2],
                         ::coder::array<i_struct_T, 1U> &stats,
                         d_struct_T *statsAlreadyComputed);

static void ComputeMaxIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<j_struct_T, 1U> &stats,
                                d_struct_T *statsAlreadyComputed);

static void ComputeMeanIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                 ::coder::array<j_struct_T, 1U> &stats,
                                 d_struct_T *statsAlreadyComputed);

static void ComputeMinIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<j_struct_T, 1U> &stats,
                                d_struct_T *statsAlreadyComputed);

static void
ComputePerimeterWithPixelIdxList(const double c_imageSize[2],
                                 ::coder::array<i_struct_T, 1U> &stats,
                                 d_struct_T *statsAlreadyComputed);

static void
ComputePixelIdxList(const ::coder::array<double, 1U> &CC_RegionIndices,
                    const ::coder::array<int, 1U> &CC_RegionLengths,
                    double numObjs, ::coder::array<i_struct_T, 1U> &stats,
                    d_struct_T *statsAlreadyComputed);

static void ComputePixelList(const double c_imageSize[2],
                             ::coder::array<i_struct_T, 1U> &stats,
                             d_struct_T *statsAlreadyComputed);

static void ComputePixelValues(const ::coder::array<unsigned char, 2U> &o_I,
                               ::coder::array<j_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed);

static void ComputeSubarrayIdx(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed);

static void ComputeWeightedCentroid(
    const double c_imageSize[2], const ::coder::array<unsigned char, 2U> &o_I,
    ::coder::array<j_struct_T, 1U> &stats, d_struct_T *statsAlreadyComputed);

static void
b_ComputePixelIdxList(const ::coder::array<double, 1U> &CC_RegionIndices,
                      const ::coder::array<int, 1U> &CC_RegionLengths,
                      double numObjs, ::coder::array<j_struct_T, 1U> &stats,
                      d_struct_T *statsAlreadyComputed);

static void b_ComputePixelList(const double c_imageSize[2],
                               ::coder::array<j_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed);

static void
b_populateOutputStatsStructure(::coder::array<f_struct_T, 1U> &outstats,
                               const ::coder::array<j_struct_T, 1U> &stats);

static double
computePerimeterFromBoundary(const ::coder::array<double, 2U> &e_B);

static void
populateOutputStatsStructure(::coder::array<h_struct_T, 1U> &outstats,
                             const ::coder::array<i_struct_T, 1U> &stats);

static void traceRegionBoundary(const ::coder::array<double, 2U> &ab_L,
                                ::coder::array<double, 2U> &L_pad, int idx,
                                const int fOffsets[8],
                                ::coder::array<double, 2U> &boundary);

} // namespace coder
} // namespace ITER

// Function Definitions
//
// Arguments    : ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
namespace ITER {
namespace coder {
static void ComputeArea(::coder::array<i_struct_T, 1U> &stats,
                        d_struct_T *statsAlreadyComputed)
{
  if (!statsAlreadyComputed->Area) {
    int b_i;
    statsAlreadyComputed->Area = true;
    b_i = stats.size(0);
    if ((static_cast<int>(b_i < 4)) != 0) {
      for (int k{0}; k < b_i; k++) {
        stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < b_i; k++) {
        stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeBoundingBox(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed)
{
  double b_dv[2];
  if (!statsAlreadyComputed->BoundingBox) {
    int b_i;
    statsAlreadyComputed->BoundingBox = true;
    ComputePixelList(c_imageSize, stats, statsAlreadyComputed);
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      if (stats[k].PixelList.size(0) == 0) {
        for (int i1{0}; i1 < 4; i1++) {
          stats[k].BoundingBox[i1] = dv2[i1];
        }
      } else {
        double min_corner_idx_0;
        double min_corner_idx_1;
        internal::e_minimum(stats[k].PixelList, b_dv);
        min_corner_idx_0 = b_dv[0] - 0.5;
        stats[k].BoundingBox[0] = b_dv[0] - 0.5;
        min_corner_idx_1 = b_dv[1] - 0.5;
        stats[k].BoundingBox[1] = b_dv[1] - 0.5;
        internal::c_maximum(stats[k].PixelList, b_dv);
        stats[k].BoundingBox[2] = (b_dv[0] + 0.5) - min_corner_idx_0;
        stats[k].BoundingBox[3] = (b_dv[1] + 0.5) - min_corner_idx_1;
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeCircularity(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed)
{
  if (!statsAlreadyComputed->Circularity) {
    int i1;
    statsAlreadyComputed->Circularity = true;
    if (!statsAlreadyComputed->Area) {
      int b_i;
      statsAlreadyComputed->Area = true;
      b_i = stats.size(0);
      if ((static_cast<int>(b_i < 4)) != 0) {
        for (int k{0}; k < b_i; k++) {
          stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int k = 0; k < b_i; k++) {
          stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
        }
      }
    }
    if (!statsAlreadyComputed->Perimeter) {
      ComputePerimeterWithPixelIdxList(c_imageSize, stats,
                                       statsAlreadyComputed);
    }
    i1 = stats.size(0);
    if ((static_cast<int>(i1 < 4)) != 0) {
      for (int b_k{0}; b_k < i1; b_k++) {
        double d;
        d = stats[b_k].Perimeter;
        stats[b_k].Circularity =
            (12.566370614359172 * stats[b_k].Area) / (d * d);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_k = 0; b_k < i1; b_k++) {
        stats[b_k].Circularity = (12.566370614359172 * stats[b_k].Area) /
                                 (stats[b_k].Perimeter * stats[b_k].Perimeter);
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeExtent(const double c_imageSize[2],
                          ::coder::array<i_struct_T, 1U> &stats,
                          d_struct_T *statsAlreadyComputed)
{
  double b_dv[2];
  if (!statsAlreadyComputed->Extent) {
    int i1;
    statsAlreadyComputed->Extent = true;
    if (!statsAlreadyComputed->Area) {
      int b_i;
      statsAlreadyComputed->Area = true;
      b_i = stats.size(0);
      if ((static_cast<int>(b_i < 4)) != 0) {
        for (int k{0}; k < b_i; k++) {
          stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int k = 0; k < b_i; k++) {
          stats[k].Area = static_cast<double>(stats[k].PixelIdxList.size(0));
        }
      }
    }
    if (!statsAlreadyComputed->BoundingBox) {
      int i2;
      statsAlreadyComputed->BoundingBox = true;
      ComputePixelList(c_imageSize, stats, statsAlreadyComputed);
      i2 = stats.size(0);
      for (int c_k{0}; c_k < i2; c_k++) {
        if (stats[c_k].PixelList.size(0) == 0) {
          for (int i3{0}; i3 < 4; i3++) {
            stats[c_k].BoundingBox[i3] = dv2[i3];
          }
        } else {
          double min_corner_idx_0;
          double min_corner_idx_1;
          internal::e_minimum(stats[c_k].PixelList, b_dv);
          min_corner_idx_0 = b_dv[0] - 0.5;
          stats[c_k].BoundingBox[0] = b_dv[0] - 0.5;
          min_corner_idx_1 = b_dv[1] - 0.5;
          stats[c_k].BoundingBox[1] = b_dv[1] - 0.5;
          internal::c_maximum(stats[c_k].PixelList, b_dv);
          stats[c_k].BoundingBox[2] = (b_dv[0] + 0.5) - min_corner_idx_0;
          stats[c_k].BoundingBox[3] = (b_dv[1] + 0.5) - min_corner_idx_1;
        }
      }
    }
    i1 = stats.size(0);
    if ((static_cast<int>(i1 < 4)) != 0) {
      for (int b_k{0}; b_k < i1; b_k++) {
        if (stats[b_k].Area == 0.0) {
          stats[b_k].Extent = rtNaN;
        } else {
          stats[b_k].Extent = stats[b_k].Area / (stats[b_k].BoundingBox[2] *
                                                 stats[b_k].BoundingBox[3]);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_k = 0; b_k < i1; b_k++) {
        if (stats[b_k].Area == 0.0) {
          stats[b_k].Extent = rtNaN;
        } else {
          stats[b_k].Extent = stats[b_k].Area / (stats[b_k].BoundingBox[2] *
                                                 stats[b_k].BoundingBox[3]);
        }
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeImage(const double c_imageSize[2],
                         ::coder::array<i_struct_T, 1U> &stats,
                         d_struct_T *statsAlreadyComputed)
{
  ::coder::array<double, 2U> b_stats;
  ::coder::array<double, 1U> c;
  ::coder::array<double, 1U> r;
  ::coder::array<bool, 2U> o_I;
  double sizeOfSubImage[2];
  if (!statsAlreadyComputed->Image) {
    int b_i;
    statsAlreadyComputed->Image = true;
    ComputeSubarrayIdx(c_imageSize, stats, statsAlreadyComputed);
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      double x_idx_1;
      double x_idx_2;
      int i1;
      x_idx_1 = stats[k].SubarrayIdxLengths[0];
      x_idx_2 = x_idx_1 + stats[k].SubarrayIdxLengths[1];
      if (1.0 > ((x_idx_1 + 1.0) - 1.0)) {
        i1 = 0;
      } else {
        i1 = static_cast<int>(static_cast<double>((x_idx_1 + 1.0) - 1.0));
      }
      if (i1 == 0) {
        stats[k].Image.set_size(0, 0);
      } else {
        int i2;
        int i3;
        if ((x_idx_1 + 1.0) > ((x_idx_2 + 1.0) - 1.0)) {
          i2 = 0;
          i3 = 0;
        } else {
          i2 = (static_cast<int>(static_cast<double>(x_idx_1 + 1.0))) - 1;
          i3 = static_cast<int>(static_cast<double>((x_idx_2 + 1.0) - 1.0));
        }
        if ((i3 - i2) == 0) {
          stats[k].Image.set_size(0, 0);
        } else {
          double maxBound_idx_0;
          double maxBound_idx_1;
          double minBound_idx_0;
          int b_loop_ub;
          int c_loop_ub;
          int d_loop_ub;
          int i10;
          int i5;
          int i6;
          int i9;
          int loop_ub;
          if (1.0 > ((x_idx_1 + 1.0) - 1.0)) {
            loop_ub = 0;
          } else {
            loop_ub =
                static_cast<int>(static_cast<double>((x_idx_1 + 1.0) - 1.0));
          }
          b_stats.set_size(1, loop_ub);
          for (int i4{0}; i4 < loop_ub; i4++) {
            b_stats[i4] = stats[k].SubarrayIdx[i4];
          }
          maxBound_idx_0 = internal::d_maximum(b_stats);
          if ((x_idx_1 + 1.0) > ((x_idx_2 + 1.0) - 1.0)) {
            i5 = 0;
            i6 = 0;
          } else {
            i5 = (static_cast<int>(static_cast<double>(x_idx_1 + 1.0))) - 1;
            i6 = static_cast<int>(static_cast<double>((x_idx_2 + 1.0) - 1.0));
          }
          b_loop_ub = i6 - i5;
          b_stats.set_size(1, b_loop_ub);
          for (int i7{0}; i7 < b_loop_ub; i7++) {
            b_stats[i7] = stats[k].SubarrayIdx[i5 + i7];
          }
          maxBound_idx_1 = internal::d_maximum(b_stats);
          if (1.0 > ((x_idx_1 + 1.0) - 1.0)) {
            c_loop_ub = 0;
          } else {
            c_loop_ub =
                static_cast<int>(static_cast<double>((x_idx_1 + 1.0) - 1.0));
          }
          b_stats.set_size(1, c_loop_ub);
          for (int b_i8{0}; b_i8 < c_loop_ub; b_i8++) {
            b_stats[b_i8] = stats[k].SubarrayIdx[b_i8];
          }
          minBound_idx_0 = internal::f_minimum(b_stats);
          if ((x_idx_1 + 1.0) > ((x_idx_2 + 1.0) - 1.0)) {
            i9 = 0;
            i10 = 0;
          } else {
            i9 = (static_cast<int>(static_cast<double>(x_idx_1 + 1.0))) - 1;
            i10 = static_cast<int>(static_cast<double>((x_idx_2 + 1.0) - 1.0));
          }
          d_loop_ub = i10 - i9;
          b_stats.set_size(1, d_loop_ub);
          for (int i11{0}; i11 < d_loop_ub; i11++) {
            b_stats[i11] = stats[k].SubarrayIdx[i9 + i11];
          }
          sizeOfSubImage[0] = (maxBound_idx_0 - minBound_idx_0) + 1.0;
          sizeOfSubImage[1] =
              (maxBound_idx_1 - internal::f_minimum(b_stats)) + 1.0;
          if (internal::g_minimum(sizeOfSubImage) == 0.0) {
            stats[k].Image.set_size(1, 2);
            stats[k].Image[0] = (sizeOfSubImage[0] != 0.0);
            stats[k].Image[stats[k].Image.size(0)] = (sizeOfSubImage[1] != 0.0);
          } else {
            double subtractby_idx_0;
            double subtractby_idx_1;
            int b_loop_ub_tmp;
            int e_loop_ub;
            int f_loop_ub;
            int g_loop_ub;
            int i16;
            int loop_ub_tmp;
            subtractby_idx_0 = maxBound_idx_1 - sizeOfSubImage[1];
            subtractby_idx_1 = maxBound_idx_0 - sizeOfSubImage[0];
            loop_ub_tmp = static_cast<int>(sizeOfSubImage[0]);
            b_loop_ub_tmp = static_cast<int>(sizeOfSubImage[1]);
            o_I.set_size(loop_ub_tmp, b_loop_ub_tmp);
            for (int i12{0}; i12 < b_loop_ub_tmp; i12++) {
              for (int i13{0}; i13 < loop_ub_tmp; i13++) {
                o_I[i13 + (o_I.size(0) * i12)] = false;
              }
            }
            e_loop_ub = stats[k].PixelList.size(0);
            r.set_size(e_loop_ub);
            for (int i14{0}; i14 < e_loop_ub; i14++) {
              r[i14] = stats[k].PixelList[i14 + stats[k].PixelList.size(0)] -
                       subtractby_idx_1;
            }
            f_loop_ub = stats[k].PixelList.size(0);
            c.set_size(f_loop_ub);
            for (int i15{0}; i15 < f_loop_ub; i15++) {
              c[i15] = stats[k].PixelList[i15] - subtractby_idx_0;
            }
            i16 = r.size(0);
            for (int p{0}; p < i16; p++) {
              o_I[((static_cast<int>(r[p])) +
                   (o_I.size(0) * ((static_cast<int>(c[p])) - 1))) -
                  1] = true;
            }
            stats[k].Image.set_size(o_I.size(0), o_I.size(1));
            g_loop_ub = o_I.size(1);
            for (int i17{0}; i17 < g_loop_ub; i17++) {
              int h_loop_ub;
              h_loop_ub = o_I.size(0);
              for (int i18{0}; i18 < h_loop_ub; i18++) {
                stats[k].Image[i18 + (stats[k].Image.size(0) * i17)] =
                    o_I[i18 + (o_I.size(0) * i17)];
              }
            }
          }
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeMaxIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<j_struct_T, 1U> &stats,
                                d_struct_T *statsAlreadyComputed)
{
  int b_k;
  int istop;
  unsigned char c_u;
  unsigned char maxval;
  if (!statsAlreadyComputed->MaxIntensity) {
    int b_i;
    statsAlreadyComputed->MaxIntensity = true;
    ComputePixelValues(o_I, stats, statsAlreadyComputed);
    b_i = stats.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_k, maxval, istop, c_u)

    for (int k = 0; k < b_i; k++) {
      if (stats[k].PixelValues.size(0) != 0) {
        istop = stats[k].PixelValues.size(0);
        maxval = 0U;
        if (stats[k].PixelValues.size(0) >= 1) {
          maxval = stats[k].PixelValues[0];
          for (b_k = 2; b_k <= istop; b_k++) {
            c_u = stats[k].PixelValues[b_k - 1];
            if (maxval < c_u) {
              maxval = c_u;
            }
          }
        }
        stats[k].MaxIntensity = maxval;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeMeanIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                 ::coder::array<j_struct_T, 1U> &stats,
                                 d_struct_T *statsAlreadyComputed)
{
  if (!statsAlreadyComputed->MeanIntensity) {
    int b_i;
    statsAlreadyComputed->MeanIntensity = true;
    ComputePixelValues(o_I, stats, statsAlreadyComputed);
    b_i = stats.size(0);
    if ((static_cast<int>(b_i < 4)) != 0) {
      for (int k{0}; k < b_i; k++) {
        stats[k].MeanIntensity =
            d_combineVectorElements(stats[k].PixelValues) /
            (static_cast<double>(stats[k].PixelValues.size(0)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k < b_i; k++) {
        stats[k].MeanIntensity =
            d_combineVectorElements(stats[k].PixelValues) /
            (static_cast<double>(stats[k].PixelValues.size(0)));
      }
    }
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeMinIntensity(const ::coder::array<unsigned char, 2U> &o_I,
                                ::coder::array<j_struct_T, 1U> &stats,
                                d_struct_T *statsAlreadyComputed)
{
  int b_k;
  int istop;
  unsigned char c_u;
  unsigned char minval;
  if (!statsAlreadyComputed->MinIntensity) {
    int b_i;
    statsAlreadyComputed->MinIntensity = true;
    ComputePixelValues(o_I, stats, statsAlreadyComputed);
    b_i = stats.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_k, minval, istop, c_u)

    for (int k = 0; k < b_i; k++) {
      if (stats[k].PixelValues.size(0) != 0) {
        istop = stats[k].PixelValues.size(0);
        minval = 0U;
        if (stats[k].PixelValues.size(0) >= 1) {
          minval = stats[k].PixelValues[0];
          for (b_k = 2; b_k <= istop; b_k++) {
            c_u = stats[k].PixelValues[b_k - 1];
            if (minval > c_u) {
              minval = c_u;
            }
          }
        }
        stats[k].MinIntensity = minval;
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void
ComputePerimeterWithPixelIdxList(const double c_imageSize[2],
                                 ::coder::array<i_struct_T, 1U> &stats,
                                 d_struct_T *statsAlreadyComputed)
{
  ::coder::array<double, 2U> L_pad;
  ::coder::array<double, 2U> ab_L;
  ::coder::array<double, 2U> boundary;
  int fOffsets[8];
  int i4;
  int siz_idx_0;
  if (!statsAlreadyComputed->Perimeter) {
    int b_i;
    statsAlreadyComputed->Perimeter = true;
    ComputeImage(c_imageSize, stats, statsAlreadyComputed);
    b_i = stats.size(0);
    if (0 <= (b_i - 1)) {
      fOffsets[0] = -1;
      fOffsets[4] = 1;
    }
    for (int k{0}; k < b_i; k++) {
      int currentLabel;
      int i3;
      int idxOrig;
      int loop_ub;
      int numPadRows;
      bool visitedLabels;
      ab_L.set_size(stats[k].Image.size(0), stats[k].Image.size(1));
      loop_ub = stats[k].Image.size(1);
      for (int i1{0}; i1 < loop_ub; i1++) {
        int b_loop_ub;
        b_loop_ub = stats[k].Image.size(0);
        for (int i2{0}; i2 < b_loop_ub; i2++) {
          ab_L[i2 + (ab_L.size(0) * i1)] = static_cast<double>(
              stats[k].Image[i2 + (stats[k].Image.size(0) * i1)]);
        }
      }
      padarray(ab_L, L_pad);
      numPadRows = L_pad.size(0);
      visitedLabels = false;
      fOffsets[1] = L_pad.size(0) - 1;
      fOffsets[2] = L_pad.size(0);
      fOffsets[3] = L_pad.size(0) + 1;
      fOffsets[5] = 1 - L_pad.size(0);
      fOffsets[6] = -L_pad.size(0);
      fOffsets[7] = (-L_pad.size(0)) - 1;
      idxOrig = 0;
      currentLabel = -1;
      i3 = L_pad.size(1);
      if (0 <= (L_pad.size(1) - 3)) {
        i4 = L_pad.size(0);
        if (0 <= (L_pad.size(0) - 3)) {
          siz_idx_0 = ab_L.size(0);
        }
      }
      for (int c{0}; c <= (i3 - 3); c++) {
        for (int r{0}; r <= (i4 - 3); r++) {
          int b_vk;
          int i5;
          int varargout_3;
          b_vk = div_s32(idxOrig, siz_idx_0);
          varargout_3 = idxOrig - (b_vk * siz_idx_0);
          i5 = static_cast<int>(ab_L[varargout_3 + (ab_L.size(0) * b_vk)]);
          if (i5 > 0) {
            if (ab_L[varargout_3 + (ab_L.size(0) * b_vk)] > 0.0) {
              if ((i5 != currentLabel) && (!visitedLabels)) {
                currentLabel = 1;
                traceRegionBoundary(ab_L, L_pad,
                                    (((c + 1) * numPadRows) + r) + 2, fOffsets,
                                    boundary);
                stats[k].Perimeter = computePerimeterFromBoundary(boundary);
                visitedLabels = true;
              }
            }
          }
          idxOrig++;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &CC_RegionIndices
//                const ::coder::array<int, 1U> &CC_RegionLengths
//                double numObjs
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void
ComputePixelIdxList(const ::coder::array<double, 1U> &CC_RegionIndices,
                    const ::coder::array<int, 1U> &CC_RegionLengths,
                    double numObjs, ::coder::array<i_struct_T, 1U> &stats,
                    d_struct_T *statsAlreadyComputed)
{
  ::coder::array<int, 1U> idxCount;
  ::coder::array<int, 1U> regionLengths;
  int c_loop_ub;
  int i4;
  int i5;
  int i6;
  int i7;
  if (!statsAlreadyComputed->PixelIdxList) {
    statsAlreadyComputed->PixelIdxList = true;
    if (numObjs != 0.0) {
      int b_loop_ub;
      int i3;
      int loop_ub;
      regionLengths.set_size(CC_RegionLengths.size(0));
      loop_ub = CC_RegionLengths.size(0);
      if ((static_cast<int>(CC_RegionLengths.size(0) < 4)) != 0) {
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          regionLengths[b_i] = CC_RegionLengths[b_i];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i = 0; b_i < loop_ub; b_i++) {
          regionLengths[b_i] = CC_RegionLengths[b_i];
        }
      }
      if (CC_RegionLengths.size(0) != 1) {
        if (CC_RegionLengths.size(0) != 0) {
          if (CC_RegionLengths.size(0) != 1) {
            int i1;
            i1 = CC_RegionLengths.size(0);
            for (int k{0}; k <= (i1 - 2); k++) {
              regionLengths[k + 1] = regionLengths[k] + regionLengths[k + 1];
            }
          }
        }
      }
      idxCount.set_size(regionLengths.size(0) + 1);
      idxCount[0] = 0;
      b_loop_ub = regionLengths.size(0);
      if ((static_cast<int>(regionLengths.size(0) < 4)) != 0) {
        for (int i2{0}; i2 < b_loop_ub; i2++) {
          idxCount[i2 + 1] = regionLengths[i2];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i2 = 0; i2 < b_loop_ub; i2++) {
          idxCount[i2 + 1] = regionLengths[i2];
        }
      }
      i3 = stats.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i4, i5, i6, i7, c_loop_ub)

      for (int b_k = 0; b_k < i3; b_k++) {
        i7 = idxCount[b_k + 1];
        if ((idxCount[b_k] + 1) > i7) {
          i6 = 0;
          i5 = 0;
        } else {
          i6 = idxCount[b_k];
          i5 = i7;
        }
        c_loop_ub = i5 - i6;
        stats[b_k].PixelIdxList.set_size(c_loop_ub);
        for (i4 = 0; i4 < c_loop_ub; i4++) {
          stats[b_k].PixelIdxList[i4] = CC_RegionIndices[i6 + i4];
        }
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputePixelList(const double c_imageSize[2],
                             ::coder::array<i_struct_T, 1U> &stats,
                             d_struct_T *statsAlreadyComputed)
{
  ::coder::array<int, 1U> b_vk;
  ::coder::array<int, 1U> e_v1;
  if (!statsAlreadyComputed->PixelList) {
    int b_i;
    statsAlreadyComputed->PixelList = true;
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      if (stats[k].PixelIdxList.size(0) != 0) {
        int b_loop_ub;
        int c_loop_ub;
        int d_loop_ub;
        int e_loop_ub;
        int loop_ub;
        e_v1.set_size(stats[k].PixelIdxList.size(0));
        loop_ub = stats[k].PixelIdxList.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          e_v1[i1] = (static_cast<int>(stats[k].PixelIdxList[i1])) - 1;
        }
        b_vk.set_size(e_v1.size(0));
        b_loop_ub = e_v1.size(0);
        for (int i2{0}; i2 < b_loop_ub; i2++) {
          b_vk[i2] = div_s32(e_v1[i2], static_cast<int>(c_imageSize[0]));
        }
        c_loop_ub = e_v1.size(0);
        for (int i3{0}; i3 < c_loop_ub; i3++) {
          e_v1[i3] = e_v1[i3] - (b_vk[i3] * (static_cast<int>(c_imageSize[0])));
        }
        stats[k].PixelList.set_size(b_vk.size(0), 2);
        d_loop_ub = b_vk.size(0);
        for (int i4{0}; i4 < d_loop_ub; i4++) {
          stats[k].PixelList[i4] =
              static_cast<double>(static_cast<int>(b_vk[i4] + 1));
        }
        e_loop_ub = e_v1.size(0);
        for (int i5{0}; i5 < e_loop_ub; i5++) {
          stats[k].PixelList[i5 + stats[k].PixelList.size(0)] =
              static_cast<double>(static_cast<int>(e_v1[i5] + 1));
        }
      } else {
        stats[k].PixelList.set_size(0, 2);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputePixelValues(const ::coder::array<unsigned char, 2U> &o_I,
                               ::coder::array<j_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed)
{
  ::coder::array<int, 1U> b_vk;
  ::coder::array<int, 1U> c;
  ::coder::array<int, 1U> e_v1;
  ::coder::array<int, 1U> r;
  unsigned int siz_idx_0;
  if (!statsAlreadyComputed->PixelValues) {
    int b_i;
    statsAlreadyComputed->PixelValues = true;
    b_i = stats.size(0);
    if (0 <= (b_i - 1)) {
      siz_idx_0 = static_cast<unsigned int>(o_I.size(0));
    }
    for (int k{0}; k < b_i; k++) {
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int e_loop_ub;
      int i6;
      int loop_ub;
      stats[k].PixelValues.set_size(stats[k].PixelIdxList.size(0));
      e_v1.set_size(stats[k].PixelIdxList.size(0));
      loop_ub = stats[k].PixelIdxList.size(0);
      for (int i1{0}; i1 < loop_ub; i1++) {
        e_v1[i1] = (static_cast<int>(stats[k].PixelIdxList[i1])) - 1;
      }
      b_vk.set_size(e_v1.size(0));
      b_loop_ub = e_v1.size(0);
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        b_vk[i2] = div_s32(e_v1[i2], static_cast<int>(siz_idx_0));
      }
      c_loop_ub = e_v1.size(0);
      for (int i3{0}; i3 < c_loop_ub; i3++) {
        e_v1[i3] = e_v1[i3] - (b_vk[i3] * (static_cast<int>(siz_idx_0)));
      }
      r.set_size(e_v1.size(0));
      d_loop_ub = e_v1.size(0);
      for (int i4{0}; i4 < d_loop_ub; i4++) {
        r[i4] = e_v1[i4] + 1;
      }
      c.set_size(b_vk.size(0));
      e_loop_ub = b_vk.size(0);
      for (int i5{0}; i5 < e_loop_ub; i5++) {
        c[i5] = b_vk[i5] + 1;
      }
      i6 = stats[k].PixelValues.size(0);
      for (int idx{0}; idx < i6; idx++) {
        stats[k].PixelValues[idx] =
            o_I[(r[idx] + (o_I.size(0) * (c[idx] - 1))) - 1];
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<i_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeSubarrayIdx(const double c_imageSize[2],
                               ::coder::array<i_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed)
{
  ::coder::array<double, 2U> idx;
  ::coder::array<double, 2U> y;
  double b_dv[2];
  double idxLengths[2];
  if (!statsAlreadyComputed->SubarrayIdx) {
    int b_i;
    statsAlreadyComputed->SubarrayIdx = true;
    if (!statsAlreadyComputed->BoundingBox) {
      int i1;
      statsAlreadyComputed->BoundingBox = true;
      ComputePixelList(c_imageSize, stats, statsAlreadyComputed);
      i1 = stats.size(0);
      for (int b_k{0}; b_k < i1; b_k++) {
        if (stats[b_k].PixelList.size(0) == 0) {
          for (int i2{0}; i2 < 4; i2++) {
            stats[b_k].BoundingBox[i2] = dv2[i2];
          }
        } else {
          double min_corner_idx_0;
          double min_corner_idx_1;
          internal::e_minimum(stats[b_k].PixelList, b_dv);
          min_corner_idx_0 = b_dv[0] - 0.5;
          stats[b_k].BoundingBox[0] = b_dv[0] - 0.5;
          min_corner_idx_1 = b_dv[1] - 0.5;
          stats[b_k].BoundingBox[1] = b_dv[1] - 0.5;
          internal::c_maximum(stats[b_k].PixelList, b_dv);
          stats[b_k].BoundingBox[2] = (b_dv[0] + 0.5) - min_corner_idx_0;
          stats[b_k].BoundingBox[3] = (b_dv[1] + 0.5) - min_corner_idx_1;
        }
      }
    }
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      int loop_ub;
      idx.set_size(1, 0);
      for (int p{0}; p < 2; p++) {
        double last;
        double last_tmp;
        int c_loop_ub;
        int i4;
        bool guard1{false};
        bool guard2{false};
        bool guard3{false};
        last_tmp = stats[k].BoundingBox[1 - p] + 0.5;
        last = (last_tmp + stats[k].BoundingBox[3 - p]) - 1.0;
        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (std::isnan(last_tmp)) {
          guard2 = true;
        } else if (std::isnan(last)) {
          guard2 = true;
        } else if (last < last_tmp) {
          y.set_size(1, 0);
        } else if (std::isinf(last_tmp)) {
          guard3 = true;
        } else if (std::isinf(last)) {
          guard3 = true;
        } else {
          guard1 = true;
        }
        if (guard3) {
          if (last_tmp == last) {
            y.set_size(1, 1);
            y[0] = rtNaN;
          } else {
            guard1 = true;
          }
        }
        if (guard2) {
          y.set_size(1, 1);
          y[0] = rtNaN;
        }
        if (guard1) {
          if (std::floor(last_tmp) == last_tmp) {
            int b_loop_ub;
            b_loop_ub = static_cast<int>(std::floor(last - last_tmp));
            y.set_size(1, b_loop_ub + 1);
            for (int i5{0}; i5 <= b_loop_ub; i5++) {
              y[i5] = last_tmp + (static_cast<double>(i5));
            }
          } else {
            eml_float_colon(last_tmp, last, y);
          }
        }
        i4 = idx.size(1);
        c_loop_ub = y.size(1);
        idx.set_size(idx.size(0), idx.size(1) + y.size(1));
        for (int i6{0}; i6 < c_loop_ub; i6++) {
          idx[i4 + i6] = y[i6];
        }
        idxLengths[p] = (last - (stats[k].BoundingBox[1 - p] + 0.5)) + 1.0;
      }
      stats[k].SubarrayIdx.set_size(1, idx.size(1));
      loop_ub = idx.size(1);
      for (int i3{0}; i3 < loop_ub; i3++) {
        stats[k].SubarrayIdx[i3] = idx[i3];
      }
      stats[k].SubarrayIdxLengths[0] = idxLengths[0];
      stats[k].SubarrayIdxLengths[1] = idxLengths[1];
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                const ::coder::array<unsigned char, 2U> &o_I
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void ComputeWeightedCentroid(
    const double c_imageSize[2], const ::coder::array<unsigned char, 2U> &o_I,
    ::coder::array<j_struct_T, 1U> &stats, d_struct_T *statsAlreadyComputed)
{
  ::coder::array<double, 1U> b_stats;
  double wc[2];
  if (!statsAlreadyComputed->WeightedCentroid) {
    int b_i;
    statsAlreadyComputed->WeightedCentroid = true;
    b_ComputePixelList(c_imageSize, stats, statsAlreadyComputed);
    ComputePixelValues(o_I, stats, statsAlreadyComputed);
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      double sumIntensity;
      int loop_ub;
      sumIntensity = d_combineVectorElements(stats[k].PixelValues);
      loop_ub = stats[k].PixelList.size(0);
      for (int h_n{0}; h_n < 2; h_n++) {
        b_stats.set_size(loop_ub);
        for (int i1{0}; i1 < loop_ub; i1++) {
          b_stats[i1] =
              stats[k].PixelList[i1 + (stats[k].PixelList.size(0) * h_n)] *
              (static_cast<double>(stats[k].PixelValues[i1]));
        }
        wc[h_n] = b_combineVectorElements(b_stats) / sumIntensity;
      }
      stats[k].WeightedCentroid[0] = wc[0];
      stats[k].WeightedCentroid[1] = wc[1];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &CC_RegionIndices
//                const ::coder::array<int, 1U> &CC_RegionLengths
//                double numObjs
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void
b_ComputePixelIdxList(const ::coder::array<double, 1U> &CC_RegionIndices,
                      const ::coder::array<int, 1U> &CC_RegionLengths,
                      double numObjs, ::coder::array<j_struct_T, 1U> &stats,
                      d_struct_T *statsAlreadyComputed)
{
  ::coder::array<int, 1U> idxCount;
  ::coder::array<int, 1U> regionLengths;
  int c_loop_ub;
  int i4;
  int i5;
  int i6;
  int i7;
  if (!statsAlreadyComputed->PixelIdxList) {
    statsAlreadyComputed->PixelIdxList = true;
    if (numObjs != 0.0) {
      int b_loop_ub;
      int i3;
      int loop_ub;
      regionLengths.set_size(CC_RegionLengths.size(0));
      loop_ub = CC_RegionLengths.size(0);
      if ((static_cast<int>(CC_RegionLengths.size(0) < 4)) != 0) {
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          regionLengths[b_i] = CC_RegionLengths[b_i];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i = 0; b_i < loop_ub; b_i++) {
          regionLengths[b_i] = CC_RegionLengths[b_i];
        }
      }
      if (CC_RegionLengths.size(0) != 1) {
        if (CC_RegionLengths.size(0) != 0) {
          if (CC_RegionLengths.size(0) != 1) {
            int i1;
            i1 = CC_RegionLengths.size(0);
            for (int k{0}; k <= (i1 - 2); k++) {
              regionLengths[k + 1] = regionLengths[k] + regionLengths[k + 1];
            }
          }
        }
      }
      idxCount.set_size(regionLengths.size(0) + 1);
      idxCount[0] = 0;
      b_loop_ub = regionLengths.size(0);
      if ((static_cast<int>(regionLengths.size(0) < 4)) != 0) {
        for (int i2{0}; i2 < b_loop_ub; i2++) {
          idxCount[i2 + 1] = regionLengths[i2];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i2 = 0; i2 < b_loop_ub; i2++) {
          idxCount[i2 + 1] = regionLengths[i2];
        }
      }
      i3 = stats.size(0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i4, i5, i6, i7, c_loop_ub)

      for (int b_k = 0; b_k < i3; b_k++) {
        i7 = idxCount[b_k + 1];
        if ((idxCount[b_k] + 1) > i7) {
          i6 = 0;
          i5 = 0;
        } else {
          i6 = idxCount[b_k];
          i5 = i7;
        }
        c_loop_ub = i5 - i6;
        stats[b_k].PixelIdxList.set_size(c_loop_ub);
        for (i4 = 0; i4 < c_loop_ub; i4++) {
          stats[b_k].PixelIdxList[i4] = CC_RegionIndices[i6 + i4];
        }
      }
    }
  }
}

//
// Arguments    : const double c_imageSize[2]
//                ::coder::array<j_struct_T, 1U> &stats
//                d_struct_T *statsAlreadyComputed
// Return Type  : void
//
static void b_ComputePixelList(const double c_imageSize[2],
                               ::coder::array<j_struct_T, 1U> &stats,
                               d_struct_T *statsAlreadyComputed)
{
  ::coder::array<int, 1U> b_vk;
  ::coder::array<int, 1U> e_v1;
  if (!statsAlreadyComputed->PixelList) {
    int b_i;
    statsAlreadyComputed->PixelList = true;
    b_i = stats.size(0);
    for (int k{0}; k < b_i; k++) {
      if (stats[k].PixelIdxList.size(0) != 0) {
        int b_loop_ub;
        int c_loop_ub;
        int d_loop_ub;
        int e_loop_ub;
        int loop_ub;
        e_v1.set_size(stats[k].PixelIdxList.size(0));
        loop_ub = stats[k].PixelIdxList.size(0);
        for (int i1{0}; i1 < loop_ub; i1++) {
          e_v1[i1] = (static_cast<int>(stats[k].PixelIdxList[i1])) - 1;
        }
        b_vk.set_size(e_v1.size(0));
        b_loop_ub = e_v1.size(0);
        for (int i2{0}; i2 < b_loop_ub; i2++) {
          b_vk[i2] = div_s32(e_v1[i2], static_cast<int>(c_imageSize[0]));
        }
        c_loop_ub = e_v1.size(0);
        for (int i3{0}; i3 < c_loop_ub; i3++) {
          e_v1[i3] = e_v1[i3] - (b_vk[i3] * (static_cast<int>(c_imageSize[0])));
        }
        stats[k].PixelList.set_size(b_vk.size(0), 2);
        d_loop_ub = b_vk.size(0);
        for (int i4{0}; i4 < d_loop_ub; i4++) {
          stats[k].PixelList[i4] =
              static_cast<double>(static_cast<int>(b_vk[i4] + 1));
        }
        e_loop_ub = e_v1.size(0);
        for (int i5{0}; i5 < e_loop_ub; i5++) {
          stats[k].PixelList[i5 + stats[k].PixelList.size(0)] =
              static_cast<double>(static_cast<int>(e_v1[i5] + 1));
        }
      } else {
        stats[k].PixelList.set_size(0, 2);
      }
    }
  }
}

//
// Arguments    : ::coder::array<f_struct_T, 1U> &outstats
//                const ::coder::array<j_struct_T, 1U> &stats
// Return Type  : void
//
static void
b_populateOutputStatsStructure(::coder::array<f_struct_T, 1U> &outstats,
                               const ::coder::array<j_struct_T, 1U> &stats)
{
  int b_i;
  b_i = stats.size(0);
  if ((static_cast<int>((b_i * 2) < 4)) != 0) {
    for (int k{0}; k < b_i; k++) {
      outstats[k].MinIntensity = stats[k].MinIntensity;
      outstats[k].MeanIntensity = stats[k].MeanIntensity;
      outstats[k].MaxIntensity = stats[k].MaxIntensity;
      outstats[k].WeightedCentroid[0] = stats[k].WeightedCentroid[0];
      outstats[k].WeightedCentroid[1] = stats[k].WeightedCentroid[1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < b_i; k++) {
      outstats[k].MinIntensity = stats[k].MinIntensity;
      outstats[k].MeanIntensity = stats[k].MeanIntensity;
      outstats[k].MaxIntensity = stats[k].MaxIntensity;
      outstats[k].WeightedCentroid[0] = stats[k].WeightedCentroid[0];
      outstats[k].WeightedCentroid[1] = stats[k].WeightedCentroid[1];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &e_B
// Return Type  : double
//
static double
computePerimeterFromBoundary(const ::coder::array<double, 2U> &e_B)
{
  ::coder::array<double, 2U> delta;
  ::coder::array<double, 2U> temp;
  ::coder::array<bool, 1U> isCorner;
  ::coder::array<bool, 1U> isEven;
  double b_a;
  double b_perimeter;
  double c_a;
  int b_i;
  delta.set_size(e_B.size(0) - 1, 2);
  b_i = e_B.size(0) - 1;
  if ((static_cast<int>((e_B.size(0) - 1) < 4)) != 0) {
    for (int idx{0}; idx < b_i; idx++) {
      c_a = e_B[idx + 1] - e_B[idx];
      delta[idx] = c_a * c_a;
      b_a = e_B[(idx + e_B.size(0)) + 1] - e_B[idx + e_B.size(0)];
      delta[idx + delta.size(0)] = b_a * b_a;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_a, c_a)

    for (int idx = 0; idx < b_i; idx++) {
      c_a = e_B[idx + 1] - e_B[idx];
      delta[idx] = c_a * c_a;
      b_a = e_B[(idx + e_B.size(0)) + 1] - e_B[idx + e_B.size(0)];
      delta[idx + delta.size(0)] = b_a * b_a;
    }
  }
  b_perimeter = 0.0;
  if (delta.size(0) > 1) {
    int i1;
    temp.set_size(delta.size(0), 2);
    isCorner.set_size(delta.size(0));
    isEven.set_size(delta.size(0));
    i1 = delta.size(0);
    for (int b_idx{0}; b_idx <= (i1 - 2); b_idx++) {
      double b_d1;
      double d;
      double d2;
      double d3;
      bool b;
      bool b_b1;
      d = delta[b_idx];
      b_d1 = delta[b_idx + 1] - d;
      temp[b_idx] = b_d1;
      d2 = delta[b_idx + delta.size(0)];
      d3 = delta[(b_idx + delta.size(0)) + 1] - d2;
      temp[b_idx + temp.size(0)] = d3;
      if ((b_d1 != 0.0) || (d3 != 0.0)) {
        b = true;
        isCorner[b_idx] = true;
      } else {
        b = false;
        isCorner[b_idx] = false;
      }
      if ((!(d != 0.0)) || (!(d2 != 0.0))) {
        b_b1 = true;
        isEven[b_idx] = true;
      } else {
        b_b1 = false;
        isEven[b_idx] = false;
      }
      b_perimeter = ((b_perimeter + ((static_cast<double>(b_b1)) * 0.98)) +
                     ((static_cast<double>(!b_b1)) * 1.406)) -
                    ((static_cast<double>(b)) * 0.091);
    }
    temp[temp.size(0) - 1] = delta[delta.size(0) - 1] - delta[0];
    temp[(temp.size(0) + temp.size(0)) - 1] =
        delta[(delta.size(0) + delta.size(0)) - 1] - delta[delta.size(0)];
    if (temp[temp.size(0) - 1] != 0.0) {
      isCorner[isCorner.size(0) - 1] = true;
    } else if (temp[(temp.size(0) + temp.size(0)) - 1] != 0.0) {
      isCorner[isCorner.size(0) - 1] = true;
    } else {
      isCorner[isCorner.size(0) - 1] = false;
    }
    if (!(delta[delta.size(0) - 1] != 0.0)) {
      isEven[isEven.size(0) - 1] = true;
    } else if (!(delta[(delta.size(0) + delta.size(0)) - 1] != 0.0)) {
      isEven[isEven.size(0) - 1] = true;
    } else {
      isEven[isEven.size(0) - 1] = false;
    }
    b_perimeter =
        ((b_perimeter +
          ((static_cast<double>(isEven[isEven.size(0) - 1])) * 0.98)) +
         ((static_cast<double>(!isEven[isEven.size(0) - 1])) * 1.406)) -
        ((static_cast<double>(isCorner[isCorner.size(0) - 1])) * 0.091);
  }
  return b_perimeter;
}

//
// Arguments    : ::coder::array<h_struct_T, 1U> &outstats
//                const ::coder::array<i_struct_T, 1U> &stats
// Return Type  : void
//
static void
populateOutputStatsStructure(::coder::array<h_struct_T, 1U> &outstats,
                             const ::coder::array<i_struct_T, 1U> &stats)
{
  int b_i;
  b_i = stats.size(0);
  for (int k{0}; k < b_i; k++) {
    int i1;
    outstats[k].Area = stats[k].Area;
    outstats[k].Circularity = stats[k].Circularity;
    outstats[k].Extent = stats[k].Extent;
    for (int vIdx{0}; vIdx < 4; vIdx++) {
      outstats[k].BoundingBox[vIdx] = stats[k].BoundingBox[vIdx];
    }
    outstats[k].PixelList.set_size(stats[k].PixelList.size(0), 2);
    i1 = (outstats[k].PixelList.size(0) * 2) - 1;
    for (int b_vIdx{0}; b_vIdx <= i1; b_vIdx++) {
      outstats[k].PixelList[b_vIdx] = stats[k].PixelList[b_vIdx];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &ab_L
//                ::coder::array<double, 2U> &L_pad
//                int idx
//                const int fOffsets[8]
//                ::coder::array<double, 2U> &boundary
// Return Type  : void
//
static void traceRegionBoundary(const ::coder::array<double, 2U> &ab_L,
                                ::coder::array<double, 2U> &L_pad, int idx,
                                const int fOffsets[8],
                                ::coder::array<double, 2U> &boundary)
{
  static const signed char b_iv[8]{8, 8, 2, 2, 4, 4, 6, 6};
  static const signed char b_iv1[8]{2, 3, 4, 5, 6, 7, 8, 1};
  ::coder::array<int, 1U> b_fScratch;
  ::coder::array<int, 1U> fScratch;
  double numPixels;
  int b_i;
  int b_varargout_3;
  int b_vk;
  int c_vk;
  int currentPixel;
  int d_vk;
  int i1;
  int initDepartureDir;
  int neighbor;
  int nextSearchDir;
  int numPadRows;
  int siz_idx_0;
  int varargout_3;
  bool done;
  fScratch.set_size(1);
  fScratch[0] = idx;
  siz_idx_0 = L_pad.size(0);
  b_vk = div_s32(idx - 1, siz_idx_0);
  L_pad[((idx - (b_vk * siz_idx_0)) + (L_pad.size(0) * b_vk)) - 1] = -2.0;
  done = false;
  numPixels = 1.0;
  currentPixel = idx;
  nextSearchDir = 1;
  initDepartureDir = -1;
  numPadRows = L_pad.size(0);
  while (!done) {
    int direction;
    int k;
    bool exitg1;
    bool foundNextPixel;
    bool guard1{false};
    bool guard2{false};
    direction = nextSearchDir;
    foundNextPixel = false;
    k = 0;
    guard1 = false;
    guard2 = false;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      bool isBoundaryPix;
      neighbor = (currentPixel + fOffsets[direction - 1]) - 1;
      siz_idx_0 = L_pad.size(0);
      d_vk = div_s32(neighbor, siz_idx_0);
      b_varargout_3 = neighbor - (d_vk * siz_idx_0);
      isBoundaryPix = false;
      if (L_pad[b_varargout_3 + (L_pad.size(0) * d_vk)] != 0.0) {
        int ndx;
        ndx = (b_mod(neighbor, static_cast<double>(L_pad.size(0))) +
               (((static_cast<int>(
                     std::floor((static_cast<double>(neighbor)) /
                                (static_cast<double>(L_pad.size(0)))))) -
                 1) *
                ab_L.size(0))) -
              1;
        isBoundaryPix = (ab_L[ndx] == 1.0);
      }
      if (isBoundaryPix) {
        siz_idx_0 = L_pad.size(0);
        c_vk = div_s32(currentPixel - 1, siz_idx_0);
        varargout_3 = (currentPixel - (c_vk * siz_idx_0)) - 1;
        if (L_pad[varargout_3 + (L_pad.size(0) * c_vk)] == -2.0) {
          if (initDepartureDir == -1) {
            initDepartureDir = direction;
            guard1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        exitg1 = true;
      } else {
        direction = static_cast<int>(b_iv1[direction - 1]);
        k++;
        guard1 = false;
        guard2 = false;
      }
    }
    if (guard2) {
      if (L_pad[varargout_3 + (L_pad.size(0) * c_vk)] == -2.0) {
        if (initDepartureDir == direction) {
          done = true;
          foundNextPixel = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if (guard1) {
      int i2;
      nextSearchDir = static_cast<int>(b_iv[direction - 1]);
      foundNextPixel = true;
      numPixels++;
      i2 = fScratch.size(0);
      fScratch.set_size(fScratch.size(0) + 1);
      fScratch[i2] = neighbor + 1;
      if (L_pad[b_varargout_3 + (L_pad.size(0) * d_vk)] != -2.0) {
        L_pad[b_varargout_3 + (L_pad.size(0) * d_vk)] = -3.0;
      }
      currentPixel = neighbor + 1;
    }
    if (!foundNextPixel) {
      int b_loop_ub;
      int c_loop_ub;
      int loop_ub;
      numPixels = 2.0;
      b_fScratch.set_size(fScratch.size(0) + fScratch.size(0));
      loop_ub = fScratch.size(0);
      for (int i3{0}; i3 < loop_ub; i3++) {
        b_fScratch[i3] = fScratch[i3];
      }
      b_loop_ub = fScratch.size(0);
      for (int i4{0}; i4 < b_loop_ub; i4++) {
        b_fScratch[i4 + fScratch.size(0)] = fScratch[i4];
      }
      fScratch.set_size(b_fScratch.size(0));
      c_loop_ub = b_fScratch.size(0);
      for (int i5{0}; i5 < c_loop_ub; i5++) {
        fScratch[i5] = b_fScratch[i5];
      }
      done = true;
    }
  }
  b_i = static_cast<int>(numPixels);
  boundary.set_size(b_i, 2);
  i1 = static_cast<int>(numPixels);
  if ((static_cast<int>((static_cast<int>(numPixels)) < 4)) != 0) {
    for (int b_idx{0}; b_idx < b_i; b_idx++) {
      boundary[b_idx] = static_cast<double>(
          b_mod(fScratch[b_idx] - 1, static_cast<double>(numPadRows)));
      boundary[b_idx + boundary.size(0)] = std::floor(
          (static_cast<double>(static_cast<int>(fScratch[b_idx] - 1))) /
          (static_cast<double>(numPadRows)));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_idx = 0; b_idx < i1; b_idx++) {
      boundary[b_idx] = static_cast<double>(
          b_mod(fScratch[b_idx] - 1, static_cast<double>(numPadRows)));
      boundary[b_idx + boundary.size(0)] = std::floor(
          (static_cast<double>(static_cast<int>(fScratch[b_idx] - 1))) /
          (static_cast<double>(numPadRows)));
    }
  }
}

//
// Arguments    : const ::coder::array<bool, 2U> &varargin_1
//                const ::coder::array<unsigned char, 2U> &varargin_2
//                ::coder::array<f_struct_T, 1U> &outstats
// Return Type  : void
//
void b_regionprops(const ::coder::array<bool, 2U> &varargin_1,
                   const ::coder::array<unsigned char, 2U> &varargin_2,
                   ::coder::array<f_struct_T, 1U> &outstats)
{
  ::coder::array<j_struct_T, 1U> stats;
  ::coder::array<double, 1U> CC_RegionIndices;
  ::coder::array<int, 1U> CC_RegionLengths;
  d_struct_T statsAlreadyComputed;
  j_struct_T statsOneObj;
  double CC_ImageSize[2];
  double CC_NumObjects;
  double expl_temp;
  int loop_ub_tmp;
  bwconncomp(varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  b_repmat(CC_NumObjects, outstats);
  statsAlreadyComputed.Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed.Centroid = false;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsAlreadyComputed.BoundingBox = false;
  for (int b_i{0}; b_i < 4; b_i++) {
    statsOneObj.BoundingBox[b_i] = 0.0;
  }
  statsAlreadyComputed.MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed.MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed.Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed.Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed.Image = false;
  statsOneObj.Image.set_size(0, 0);
  statsAlreadyComputed.FilledImage = false;
  statsOneObj.FilledImage.set_size(0, 0);
  statsAlreadyComputed.FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed.EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed.Extrema = false;
  statsAlreadyComputed.EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed.Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed.PixelIdxList = false;
  statsOneObj.PixelIdxList.set_size(0);
  statsAlreadyComputed.PixelList = false;
  statsOneObj.PixelList.set_size(0, 2);
  statsAlreadyComputed.Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed.Circularity = false;
  statsOneObj.Circularity = 0.0;
  statsAlreadyComputed.PixelValues = false;
  statsOneObj.PixelValues.set_size(0);
  statsAlreadyComputed.WeightedCentroid = false;
  statsAlreadyComputed.MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed.MinIntensity = false;
  statsOneObj.MinIntensity = 0U;
  statsAlreadyComputed.MaxIntensity = false;
  statsOneObj.MaxIntensity = 0U;
  statsAlreadyComputed.SubarrayIdx = false;
  statsOneObj.SubarrayIdx.set_size(1, 0);
  (void)std::memset(&statsOneObj.Extrema[0][0], 0, 16U * (sizeof(double)));
  for (int i1{0}; i1 < 2; i1++) {
    statsOneObj.WeightedCentroid[i1] = 0.0;
    statsOneObj.SubarrayIdxLengths[i1] = 0.0;
  }
  loop_ub_tmp = static_cast<int>(CC_NumObjects);
  stats.set_size(loop_ub_tmp);
  for (int i2{0}; i2 < loop_ub_tmp; i2++) {
    stats[i2] = statsOneObj;
  }
  b_ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                        stats, &statsAlreadyComputed);
  ComputeMinIntensity(varargin_2, stats, &statsAlreadyComputed);
  b_ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                        stats, &statsAlreadyComputed);
  ComputeMeanIntensity(varargin_2, stats, &statsAlreadyComputed);
  b_ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                        stats, &statsAlreadyComputed);
  ComputeMaxIntensity(varargin_2, stats, &statsAlreadyComputed);
  b_ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects,
                        stats, &statsAlreadyComputed);
  ComputeWeightedCentroid(CC_ImageSize, varargin_2, stats,
                          &statsAlreadyComputed);
  b_populateOutputStatsStructure(outstats, stats);
}

//
// Arguments    : const ::coder::array<bool, 2U> &varargin_1
//                ::coder::array<h_struct_T, 1U> &outstats
// Return Type  : void
//
void regionprops(const ::coder::array<bool, 2U> &varargin_1,
                 ::coder::array<h_struct_T, 1U> &outstats)
{
  ::coder::array<i_struct_T, 1U> stats;
  ::coder::array<double, 1U> CC_RegionIndices;
  ::coder::array<int, 1U> CC_RegionLengths;
  d_struct_T statsAlreadyComputed;
  h_struct_T b_expl_temp;
  i_struct_T statsOneObj;
  double CC_ImageSize[2];
  double CC_NumObjects;
  double expl_temp;
  int loop_ub_tmp;
  bwconncomp(varargin_1, &expl_temp, CC_ImageSize, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  b_expl_temp.PixelList.set_size(0, 2);
  for (int b_i{0}; b_i < 4; b_i++) {
    b_expl_temp.BoundingBox[b_i] = 0.0;
  }
  b_expl_temp.Extent = 0.0;
  b_expl_temp.Circularity = 0.0;
  b_expl_temp.Area = 0.0;
  repmat(&b_expl_temp, CC_NumObjects, outstats);
  statsAlreadyComputed.Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed.Centroid = false;
  statsOneObj.Centroid[0] = 0.0;
  statsOneObj.Centroid[1] = 0.0;
  statsAlreadyComputed.BoundingBox = false;
  for (int i1{0}; i1 < 4; i1++) {
    statsOneObj.BoundingBox[i1] = 0.0;
  }
  statsAlreadyComputed.MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed.MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed.Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed.Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed.Image = false;
  statsOneObj.Image.set_size(0, 0);
  statsAlreadyComputed.FilledImage = false;
  statsOneObj.FilledImage.set_size(0, 0);
  statsAlreadyComputed.FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed.EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed.Extrema = false;
  statsAlreadyComputed.EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed.Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed.PixelIdxList = false;
  statsOneObj.PixelIdxList.set_size(0);
  statsAlreadyComputed.PixelList = false;
  statsOneObj.PixelList.set_size(0, 2);
  statsAlreadyComputed.Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed.Circularity = false;
  statsOneObj.Circularity = 0.0;
  statsAlreadyComputed.PixelValues = false;
  statsOneObj.PixelValues.set_size(0);
  statsAlreadyComputed.WeightedCentroid = false;
  statsAlreadyComputed.MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed.MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed.MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed.SubarrayIdx = false;
  statsOneObj.SubarrayIdx.set_size(1, 0);
  (void)std::memset(&statsOneObj.Extrema[0][0], 0, 16U * (sizeof(double)));
  for (int i2{0}; i2 < 2; i2++) {
    statsOneObj.WeightedCentroid[i2] = 0.0;
    statsOneObj.SubarrayIdxLengths[i2] = 0.0;
  }
  loop_ub_tmp = static_cast<int>(CC_NumObjects);
  stats.set_size(loop_ub_tmp);
  for (int i3{0}; i3 < loop_ub_tmp; i3++) {
    stats[i3] = statsOneObj;
  }
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeArea(stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeCircularity(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeExtent(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputeBoundingBox(CC_ImageSize, stats, &statsAlreadyComputed);
  ComputePixelIdxList(CC_RegionIndices, CC_RegionLengths, CC_NumObjects, stats,
                      &statsAlreadyComputed);
  ComputePixelList(CC_ImageSize, stats, &statsAlreadyComputed);
  populateOutputStatsStructure(outstats, stats);
}

} // namespace coder
} // namespace ITER

//
// File trailer for regionprops.cpp
//
// [EOF]
//
