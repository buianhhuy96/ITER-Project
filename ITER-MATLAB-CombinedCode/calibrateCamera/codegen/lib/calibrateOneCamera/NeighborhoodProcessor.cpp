//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: NeighborhoodProcessor.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "NeighborhoodProcessor.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>

// Type Definitions
namespace Codegen {
struct b_struct_T {
  ::coder::array<bool, 2U> bw;
  float pixel;
  int ind;
  int nhInds[9];
  int imnhInds[9];
};

} // namespace Codegen

// Function Declarations
namespace Codegen {
static double rt_remd_snf(double u0, double u1);

}

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
namespace Codegen {
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (((std::isnan(u0)) || (std::isnan(u1))) || (std::isinf(u0))) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > (DBL_EPSILON * q))) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const int imSize[2]
//                const bool nhConn[3][3]
//                int loffsets[9]
//                int linds[9]
//                int soffsets[2][9]
//                int b_interiorStart[2]
//                int b_interiorEnd[2]
// Return Type  : void
//
namespace coder {
namespace images {
namespace internal {
namespace coder {
void NeighborhoodProcessor::computeParameters(
    const int imSize[2], const bool nhConn[3][3], int loffsets[9], int linds[9],
    int soffsets[2][9], int b_interiorStart[2], int b_interiorEnd[2])
{
  int indx;
  int k;
  int pixelsPerImPage1_idx_1;
  pixelsPerImPage1_idx_1 = imSize[0];
  b_interiorStart[0] = 2;
  b_interiorEnd[0] = imSize[0] - 1;
  b_interiorStart[1] = 2;
  b_interiorEnd[1] = imSize[1] - 1;
  indx = static_cast<int>((&nhConn[0][0])[0]);
  for (k = 0; k < 8; k++) {
    indx += static_cast<int>((&nhConn[0][0])[k + 1]);
  }
  if (indx != 0) {
    double b;
    indx = 0;
    for (int pind{0}; pind < 9; pind++) {
      if ((&nhConn[0][0])[pind]) {
        int subs_idx_1_tmp;
        k = static_cast<int>(
            rt_remd_snf(((static_cast<double>(pind)) + 1.0) - 1.0, 3.0));
        subs_idx_1_tmp = static_cast<int>(static_cast<double>(
            ((static_cast<double>(static_cast<int>((pind - k) - 1))) + 1.0) /
            3.0));
        soffsets[0][indx] = k + 1;
        soffsets[1][indx] = subs_idx_1_tmp + 1;
        linds[indx] = (k + (subs_idx_1_tmp * 3)) + 1;
        loffsets[indx] = (k + (subs_idx_1_tmp * pixelsPerImPage1_idx_1)) + 1;
        indx++;
      }
    }
    b = (static_cast<double>(imSize[0])) + 2.0;
    for (indx = 0; indx < 9; indx++) {
      loffsets[indx] -= static_cast<int>(b);
    }
    for (k = 0; k < 2; k++) {
      for (indx = 0; indx < 9; indx++) {
        soffsets[k][indx] -= 2;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &in
//                ::coder::array<bool, 2U> &out
//                const struct_T *fparams
// Return Type  : void
//
void NeighborhoodProcessor::process2D(const ::coder::array<float, 2U> &in,
                                      ::coder::array<bool, 2U> &out,
                                      const struct_T *fparams) const
{
  ::coder::array<float, 2U> b_imnh;
  ::coder::array<float, 2U> imnh;
  ::coder::array<float, 1U> b_in;
  ::coder::array<int, 1U> b_imnhInds;
  ::coder::array<int, 1U> c_imnhInds;
  ::coder::array<int, 1U> d_imnhInds;
  ::coder::array<int, 1U> e_imnhInds;
  ::coder::array<signed char, 1U> r;
  ::coder::array<signed char, 1U> r1;
  ::coder::array<signed char, 1U> r2;
  ::coder::array<signed char, 1U> r3;
  ::coder::array<bool, 1U> b_out_;
  b_struct_T fparamsAugmented;
  int imnhSubs[2][9];
  int b_imageNeighborLinearOffsets[9];
  int imnhInds[9];
  int pixelSub[2];
  int b_firstInd;
  int b_i;
  int c_i;
  int d_i;
  int i1;
  int imageSize1;
  int lb_loop;
  int pind;
  bool isInside[9];
  bool exitg1;
  pixelSub[0] = InteriorStart[0];
  pixelSub[1] = InteriorEnd[0];
  for (b_i = 0; b_i < 9; b_i++) {
    b_imageNeighborLinearOffsets[b_i] = ImageNeighborLinearOffsets[b_i];
  }
  imageSize1 = ImageSize[0];
  lb_loop = InteriorStart[1];
  b_i = InteriorEnd[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_out_, imnh, fparamsAugmented, imnhInds, pind, c_i, i1, b_firstInd, d_i,  \
    exitg1)

  for (int secondInd = lb_loop; secondInd <= b_i; secondInd++) {
    b_out_.set_size(out.size(0));
    c_i = pixelSub[0];
    i1 = pixelSub[1];
    for (b_firstInd = c_i; b_firstInd <= i1; b_firstInd++) {
      //  Process pixels with full neighborhood
      pind = ((secondInd - 1) * imageSize1) + b_firstInd;
      for (d_i = 0; d_i < 9; d_i++) {
        imnhInds[d_i] = b_imageNeighborLinearOffsets[d_i] + pind;
      }
      if (in.size(0) == 1) {
        imnh.set_size(1, 9);
        for (d_i = 0; d_i < 9; d_i++) {
          imnh[imnh.size(0) * d_i] = in[imnhInds[d_i] - 1];
        }
      } else {
        imnh.set_size(9, 1);
        for (d_i = 0; d_i < 9; d_i++) {
          imnh[d_i] = in[imnhInds[d_i] - 1];
        }
      }
      fparamsAugmented.pixel = in[pind - 1];
      b_out_[b_firstInd - 1] = fparams->bw[pind - 1];
      if (fparams->bw[pind - 1]) {
        //  Pixel has not already been set as non-max
        pind = 0;
        exitg1 = false;
        while ((!exitg1) && (pind <= ((imnh.size(0) * imnh.size(1)) - 1))) {
          if (imnh[pind] > fparamsAugmented.pixel) {
            //  Set pixel to zero if any neighbor is greater
            b_out_[b_firstInd - 1] = false;
            exitg1 = true;
          } else if (imnh[pind] == fparamsAugmented.pixel) {
            if (!fparams->bw[imnhInds[pind] - 1]) {
              //  Set pixel to zero if any equal neighbor is already set to zero
              b_out_[b_firstInd - 1] = false;
              exitg1 = true;
            } else {
              pind++;
            }
          } else {
            pind++;
          }
        }
      }
    }
    pind = b_out_.size(0);
    for (c_i = 0; c_i < pind; c_i++) {
      out[c_i + (out.size(0) * (secondInd - 1))] = b_out_[c_i];
    }
  }
  if (ProcessBorder) {
    float fparamsAugmented_pixel;
    float padValue_tmp;
    int b_pind;
    int b_secondInd;
    int b_x;
    int firstInd;
    int secondDimExtents_idx_0;
    int secondDimExtents_idx_1;
    int u1;
    int y;
    secondDimExtents_idx_1 = InteriorStart[1] - 1;
    padValue_tmp = static_cast<float>(PadValue);
    imageSize1 = ImageSize[0];
    u1 = ImageSize[0];
    if (imageSize1 <= u1) {
      u1 = imageSize1;
    }
    imageSize1 = ImageSize[1];
    if (secondDimExtents_idx_1 > imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = 0; b_secondInd < secondDimExtents_idx_1; b_secondInd++) {
      for (firstInd = 0; firstInd < u1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = (b_secondInd * ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          b_imageNeighborLinearOffsets[b_i] =
              (ImageNeighborLinearOffsets[b_i] + b_pind) + 1;
        }
        pixelSub[0] = ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            b_i = 0;
          } else if (lb_loop < 0) {
            b_i = MIN_int32_T;
          } else {
            b_i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          b_i = lb_loop;
        } else if (pixelSub[0] == -1) {
          b_i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            b_x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            b_x = MIN_int32_T;
          } else {
            b_x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          b_i = div_s32(b_x, y);
          b_x -= b_i * y;
          if ((b_x > 0) && (b_x >= (asr_s32(y, 1U) + (y & 1)))) {
            b_i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            b_i = -b_i;
          }
        }
        pixelSub[1] = b_i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (b_i = 0; b_i < 9; b_i++) {
          isInside[b_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1:
          lb_loop = 0;
          for (b_x = 0; b_x < 9; b_x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[b_x]) {
              lb_loop++;
            }
          }
          b_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (isInside[b_i]) {
              b_imnhInds[imageSize1] = b_imageNeighborLinearOffsets[b_i];
              imageSize1++;
            }
          }
          break;
        case 2:
          b_imnhInds.set_size(9);
          for (b_x = 0; b_x < 9; b_x++) {
            b_imnhInds[b_x] = b_imageNeighborLinearOffsets[b_x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                b_imnhInds[b_x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          b_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            b_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[0] = 1;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              pixelSub[0] = ImageSize[0];
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[1] = 1;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              pixelSub[1] = ImageSize[1];
            }
            if (!isInside[b_x]) {
              b_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        case 4:
          b_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            b_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[0] * 2;
              pixelSub[0] = lb_loop;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[0] * 2) - lb_loop) + 1;
              pixelSub[0] = lb_loop;
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[1] * 2;
              pixelSub[1] = lb_loop;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[1] * 2) - lb_loop) + 1;
              pixelSub[1] = lb_loop;
            }
            if (!isInside[b_x]) {
              b_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = b_imnhInds.size(0);
          b_imnh.set_size(1, b_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[b_imnh.size(0) * lb_loop] = in[b_imnhInds[lb_loop] - 1];
          }
        } else {
          imageSize1 = b_imnhInds.size(0);
          b_in.set_size(b_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_in[lb_loop] = in[b_imnhInds[lb_loop] - 1];
          }
          imageSize1 = b_imnhInds.size(0);
          b_imnh.set_size(b_imnhInds.size(0), 1);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[lb_loop] = b_in[lb_loop];
          }
        }
        if (Padding == 2.0) {
          lb_loop = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              lb_loop++;
            }
          }
          r.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              r[imageSize1] = static_cast<signed char>(b_i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r.size(0);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[(static_cast<int>(r[lb_loop])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[b_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = InteriorEnd[1] + 1;
    secondDimExtents_idx_1 = ImageSize[1];
    if (secondDimExtents_idx_0 < 1) {
      secondDimExtents_idx_0 = 1;
    }
    imageSize1 = ImageSize[1];
    if (secondDimExtents_idx_1 > imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = secondDimExtents_idx_0;
         b_secondInd <= secondDimExtents_idx_1; b_secondInd++) {
      for (firstInd = 0; firstInd < u1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = ((b_secondInd - 1) * ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          b_imageNeighborLinearOffsets[b_i] =
              (ImageNeighborLinearOffsets[b_i] + b_pind) + 1;
        }
        pixelSub[0] = ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            b_i = 0;
          } else if (lb_loop < 0) {
            b_i = MIN_int32_T;
          } else {
            b_i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          b_i = lb_loop;
        } else if (pixelSub[0] == -1) {
          b_i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            b_x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            b_x = MIN_int32_T;
          } else {
            b_x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          b_i = div_s32(b_x, y);
          b_x -= b_i * y;
          if ((b_x > 0) && (b_x >= (asr_s32(y, 1U) + (y & 1)))) {
            b_i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            b_i = -b_i;
          }
        }
        pixelSub[1] = b_i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (b_i = 0; b_i < 9; b_i++) {
          isInside[b_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1:
          lb_loop = 0;
          for (b_x = 0; b_x < 9; b_x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[b_x]) {
              lb_loop++;
            }
          }
          c_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (isInside[b_i]) {
              c_imnhInds[imageSize1] = b_imageNeighborLinearOffsets[b_i];
              imageSize1++;
            }
          }
          break;
        case 2:
          c_imnhInds.set_size(9);
          for (b_x = 0; b_x < 9; b_x++) {
            c_imnhInds[b_x] = b_imageNeighborLinearOffsets[b_x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                c_imnhInds[b_x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          c_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            c_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[0] = 1;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              pixelSub[0] = ImageSize[0];
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[1] = 1;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              pixelSub[1] = ImageSize[1];
            }
            if (!isInside[b_x]) {
              c_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        case 4:
          c_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            c_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[0] * 2;
              pixelSub[0] = lb_loop;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[0] * 2) - lb_loop) + 1;
              pixelSub[0] = lb_loop;
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[1] * 2;
              pixelSub[1] = lb_loop;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[1] * 2) - lb_loop) + 1;
              pixelSub[1] = lb_loop;
            }
            if (!isInside[b_x]) {
              c_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = c_imnhInds.size(0);
          b_imnh.set_size(1, c_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[b_imnh.size(0) * lb_loop] = in[c_imnhInds[lb_loop] - 1];
          }
        } else {
          imageSize1 = c_imnhInds.size(0);
          b_in.set_size(c_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_in[lb_loop] = in[c_imnhInds[lb_loop] - 1];
          }
          imageSize1 = c_imnhInds.size(0);
          b_imnh.set_size(c_imnhInds.size(0), 1);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[lb_loop] = b_in[lb_loop];
          }
        }
        if (Padding == 2.0) {
          lb_loop = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              lb_loop++;
            }
          }
          r1.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              r1[imageSize1] = static_cast<signed char>(b_i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r1.size(0);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[(static_cast<int>(r1[lb_loop])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[c_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_1 = InteriorStart[0] - 1;
    u1 = ImageSize[0];
    if (secondDimExtents_idx_1 > u1) {
      secondDimExtents_idx_1 = u1;
    }
    imageSize1 = ImageSize[1];
    u1 = ImageSize[1];
    if (imageSize1 <= u1) {
      u1 = imageSize1;
    }
    for (b_secondInd = 1; b_secondInd <= u1; b_secondInd++) {
      for (firstInd = 0; firstInd < secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = ((b_secondInd - 1) * ImageSize[0]) + firstInd;
        for (b_i = 0; b_i < 9; b_i++) {
          b_imageNeighborLinearOffsets[b_i] =
              (ImageNeighborLinearOffsets[b_i] + b_pind) + 1;
        }
        pixelSub[0] = ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            b_i = 0;
          } else if (lb_loop < 0) {
            b_i = MIN_int32_T;
          } else {
            b_i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          b_i = lb_loop;
        } else if (pixelSub[0] == -1) {
          b_i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            b_x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            b_x = MIN_int32_T;
          } else {
            b_x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          b_i = div_s32(b_x, y);
          b_x -= b_i * y;
          if ((b_x > 0) && (b_x >= (asr_s32(y, 1U) + (y & 1)))) {
            b_i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            b_i = -b_i;
          }
        }
        pixelSub[1] = b_i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (b_i = 0; b_i < 9; b_i++) {
          isInside[b_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1:
          lb_loop = 0;
          for (b_x = 0; b_x < 9; b_x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[b_x]) {
              lb_loop++;
            }
          }
          d_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (isInside[b_i]) {
              d_imnhInds[imageSize1] = b_imageNeighborLinearOffsets[b_i];
              imageSize1++;
            }
          }
          break;
        case 2:
          d_imnhInds.set_size(9);
          for (b_x = 0; b_x < 9; b_x++) {
            d_imnhInds[b_x] = b_imageNeighborLinearOffsets[b_x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                d_imnhInds[b_x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          d_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            d_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[0] = 1;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              pixelSub[0] = ImageSize[0];
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[1] = 1;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              pixelSub[1] = ImageSize[1];
            }
            if (!isInside[b_x]) {
              d_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        case 4:
          d_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            d_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[0] * 2;
              pixelSub[0] = lb_loop;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[0] * 2) - lb_loop) + 1;
              pixelSub[0] = lb_loop;
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[1] * 2;
              pixelSub[1] = lb_loop;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[1] * 2) - lb_loop) + 1;
              pixelSub[1] = lb_loop;
            }
            if (!isInside[b_x]) {
              d_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = d_imnhInds.size(0);
          b_imnh.set_size(1, d_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[b_imnh.size(0) * lb_loop] = in[d_imnhInds[lb_loop] - 1];
          }
        } else {
          imageSize1 = d_imnhInds.size(0);
          b_in.set_size(d_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_in[lb_loop] = in[d_imnhInds[lb_loop] - 1];
          }
          imageSize1 = d_imnhInds.size(0);
          b_imnh.set_size(d_imnhInds.size(0), 1);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[lb_loop] = b_in[lb_loop];
          }
        }
        if (Padding == 2.0) {
          lb_loop = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              lb_loop++;
            }
          }
          r2.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              r2[imageSize1] = static_cast<signed char>(b_i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r2.size(0);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[(static_cast<int>(r2[lb_loop])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[d_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
    secondDimExtents_idx_0 = InteriorEnd[0] + 1;
    secondDimExtents_idx_1 = ImageSize[0];
    if (secondDimExtents_idx_0 < 1) {
      secondDimExtents_idx_0 = 1;
    }
    imageSize1 = ImageSize[0];
    if (secondDimExtents_idx_1 > imageSize1) {
      secondDimExtents_idx_1 = imageSize1;
    }
    for (b_secondInd = 0; b_secondInd < u1; b_secondInd++) {
      for (firstInd = secondDimExtents_idx_0;
           firstInd <= secondDimExtents_idx_1; firstInd++) {
        //  Process pixels with partial neighborhood
        b_pind = ((b_secondInd * ImageSize[0]) + firstInd) - 1;
        for (b_i = 0; b_i < 9; b_i++) {
          b_imageNeighborLinearOffsets[b_i] =
              (ImageNeighborLinearOffsets[b_i] + b_pind) + 1;
        }
        pixelSub[0] = ImageSize[0];
        if (pixelSub[0] == 0) {
          imageSize1 = 0;
        } else {
          imageSize1 = b_pind - (pixelSub[0] * div_s32(b_pind, pixelSub[0]));
        }
        lb_loop = b_pind - imageSize1;
        if (pixelSub[0] == 0) {
          if (lb_loop == 0) {
            b_i = 0;
          } else if (lb_loop < 0) {
            b_i = MIN_int32_T;
          } else {
            b_i = MAX_int32_T;
          }
        } else if (pixelSub[0] == 1) {
          b_i = lb_loop;
        } else if (pixelSub[0] == -1) {
          b_i = -lb_loop;
        } else {
          if (lb_loop >= 0) {
            b_x = lb_loop;
          } else if (lb_loop == MIN_int32_T) {
            b_x = MIN_int32_T;
          } else {
            b_x = -lb_loop;
          }
          if (pixelSub[0] >= 0) {
            y = pixelSub[0];
          } else if (pixelSub[0] == MIN_int32_T) {
            y = MIN_int32_T;
          } else {
            y = -pixelSub[0];
          }
          b_i = div_s32(b_x, y);
          b_x -= b_i * y;
          if ((b_x > 0) && (b_x >= (asr_s32(y, 1U) + (y & 1)))) {
            b_i++;
          }
          if ((lb_loop < 0) != (pixelSub[0] < 0)) {
            b_i = -b_i;
          }
        }
        pixelSub[1] = b_i + 1;
        pixelSub[0] = imageSize1 + 1;
        for (imageSize1 = 0; imageSize1 < 2; imageSize1++) {
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            imnhSubs[imageSize1][lb_loop] =
                NeighborSubscriptOffsets[imageSize1][lb_loop] +
                pixelSub[imageSize1];
          }
        }
        for (b_i = 0; b_i < 9; b_i++) {
          isInside[b_i] = true;
        }
        switch (static_cast<int>(Padding)) {
        case 1:
          lb_loop = 0;
          for (b_x = 0; b_x < 9; b_x++) {
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
            if (isInside[b_x]) {
              lb_loop++;
            }
          }
          e_imnhInds.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (isInside[b_i]) {
              e_imnhInds[imageSize1] = b_imageNeighborLinearOffsets[b_i];
              imageSize1++;
            }
          }
          break;
        case 2:
          e_imnhInds.set_size(9);
          for (b_x = 0; b_x < 9; b_x++) {
            e_imnhInds[b_x] = b_imageNeighborLinearOffsets[b_x];
            imageSize1 = 0;
            exitg1 = false;
            while ((!exitg1) && (imageSize1 < 2)) {
              if ((imnhSubs[imageSize1][b_x] < 1) ||
                  (imnhSubs[imageSize1][b_x] > ImageSize[imageSize1])) {
                isInside[b_x] = false;
                e_imnhInds[b_x] = 1;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            }
          }
          break;
        case 3:
          e_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            e_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[0] = 1;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              pixelSub[0] = ImageSize[0];
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop = 1;
              pixelSub[1] = 1;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              pixelSub[1] = ImageSize[1];
            }
            if (!isInside[b_x]) {
              e_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        case 4:
          e_imnhInds.set_size(9);
          for (lb_loop = 0; lb_loop < 9; lb_loop++) {
            e_imnhInds[lb_loop] = b_imageNeighborLinearOffsets[lb_loop];
          }
          for (b_x = 0; b_x < 9; b_x++) {
            lb_loop = imnhSubs[0][b_x];
            pixelSub[0] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[0] * 2;
              pixelSub[0] = lb_loop;
            }
            if (lb_loop > ImageSize[0]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[0] * 2) - lb_loop) + 1;
              pixelSub[0] = lb_loop;
            }
            lb_loop = imnhSubs[1][b_x];
            pixelSub[1] = lb_loop;
            if (lb_loop < 1) {
              isInside[b_x] = false;
              lb_loop += ImageSize[1] * 2;
              pixelSub[1] = lb_loop;
            }
            if (lb_loop > ImageSize[1]) {
              isInside[b_x] = false;
              lb_loop = ((ImageSize[1] * 2) - lb_loop) + 1;
              pixelSub[1] = lb_loop;
            }
            if (!isInside[b_x]) {
              e_imnhInds[b_x] =
                  pixelSub[0] + ((pixelSub[1] - 1) * ImageSize[0]);
            }
          }
          break;
        default:
          /* no actions */
          break;
        }
        if (in.size(0) == 1) {
          imageSize1 = e_imnhInds.size(0);
          b_imnh.set_size(1, e_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[b_imnh.size(0) * lb_loop] = in[e_imnhInds[lb_loop] - 1];
          }
        } else {
          imageSize1 = e_imnhInds.size(0);
          b_in.set_size(e_imnhInds.size(0));
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_in[lb_loop] = in[e_imnhInds[lb_loop] - 1];
          }
          imageSize1 = e_imnhInds.size(0);
          b_imnh.set_size(e_imnhInds.size(0), 1);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[lb_loop] = b_in[lb_loop];
          }
        }
        if (Padding == 2.0) {
          lb_loop = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              lb_loop++;
            }
          }
          r3.set_size(lb_loop);
          imageSize1 = 0;
          for (b_i = 0; b_i < 9; b_i++) {
            if (!isInside[b_i]) {
              r3[imageSize1] = static_cast<signed char>(b_i + 1);
              imageSize1++;
            }
          }
          imageSize1 = r3.size(0);
          for (lb_loop = 0; lb_loop < imageSize1; lb_loop++) {
            b_imnh[(static_cast<int>(r3[lb_loop])) - 1] = padValue_tmp;
          }
        }
        fparamsAugmented_pixel = in[b_pind];
        out[b_pind] = fparams->bw[b_pind];
        if (fparams->bw[b_pind]) {
          //  Pixel has not already been set as non-max
          imageSize1 = 0;
          exitg1 = false;
          while ((!exitg1) &&
                 (imageSize1 <= ((b_imnh.size(0) * b_imnh.size(1)) - 1))) {
            if (b_imnh[imageSize1] > fparamsAugmented_pixel) {
              //  Set pixel to zero if any neighbor is greater
              out[b_pind] = false;
              exitg1 = true;
            } else if (b_imnh[imageSize1] == fparamsAugmented_pixel) {
              if (!fparams->bw[e_imnhInds[imageSize1] - 1]) {
                //  Set pixel to zero if any equal neighbor is already set to
                //  zero
                out[b_pind] = false;
                exitg1 = true;
              } else {
                imageSize1++;
              }
            } else {
              imageSize1++;
            }
          }
        }
      }
    }
  }
}

} // namespace coder
} // namespace internal
} // namespace images
} // namespace coder
} // namespace Codegen

//
// File trailer for NeighborhoodProcessor.cpp
//
// [EOF]
//
