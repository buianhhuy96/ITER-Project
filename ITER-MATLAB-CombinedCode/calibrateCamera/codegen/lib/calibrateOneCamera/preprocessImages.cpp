//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "preprocessImages.h"
#include "calibrateOneCamera_data.h"
#include "calibrateOneCamera_initialize.h"
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 4U> &images
//                ::coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
namespace Codegen {
void preprocessImages(const ::coder::array<unsigned char, 4U> &images,
                      ::coder::array<unsigned char, 4U> &gray_images)
{
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<unsigned char, 3U> b_images;
  ::coder::array<unsigned char, 2U> r2;
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int i1;
  int i2;
  int loop_ub;
  if (!isInitialized_calibrateOneCamera) {
    calibrateOneCamera_initialize();
  }
  gray_images.set_size(images.size(0), images.size(1), 1, images.size(3));
  loop_ub = images.size(3);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = images.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_loop_ub = images.size(0);
      for (i2 = 0; i2 < c_loop_ub; i2++) {
        gray_images[(i2 + (gray_images.size(0) * i1)) +
                    ((gray_images.size(0) * gray_images.size(1)) * b_i)] = 0U;
      }
    }
  }
  b_i = images.size(3);
  for (int c_i{0}; c_i < b_i; c_i++) {
    //  If gray images, convert to RGB
    if (images.size(2) == 3) {
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      b_images.set_size(images.size(0), images.size(1), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (int i3{0}; i3 < loop_ub; i3++) {
            b_images[(i3 + (b_images.size(0) * i2)) +
                     ((b_images.size(0) * b_images.size(1)) * i1)] =
                images[((i3 + (images.size(0) * i2)) +
                        ((images.size(0) * images.size(1)) * i1)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
      coder::rgb2gray(b_images, r2);
      loop_ub = r2.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r2.size(0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          gray_images[(i2 + (gray_images.size(0) * i1)) +
                      ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
              r2[i2 + (r2.size(0) * i1)];
        }
      }
    } else {
      loop_ub = gray_images.size(0);
      r.set_size(gray_images.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        r[i1] = i1;
      }
      loop_ub = gray_images.size(1);
      r1.set_size(gray_images.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        r1[i1] = i1;
      }
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      c_loop_ub = images.size(2);
      b_images.set_size(images.size(0), images.size(1), images.size(2));
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (int i3{0}; i3 < loop_ub; i3++) {
            b_images[(i3 + (b_images.size(0) * i2)) +
                     ((b_images.size(0) * b_images.size(1)) * i1)] =
                images[((i3 + (images.size(0) * i2)) +
                        ((images.size(0) * images.size(1)) * i1)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
      b_loop_ub = r.size(0);
      loop_ub = r1.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          gray_images[(r[i2] + (gray_images.size(0) * r1[i1])) +
                      ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
              b_images[i2 + (b_loop_ub * i1)];
        }
      }
    }
  }
}

} // namespace Codegen

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
