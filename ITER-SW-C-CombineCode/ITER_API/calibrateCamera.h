#pragma once
#ifndef CALIBRATECAMERA_H
#define CALIBRATECAMERA_H

// Include Files
#include "common_definitions.h"

#include "./library/preprocessImages.h"
#include "./library/calibrateOneCamera_v2.h"

void validateInputs(const std::vector<imageWrap> &images,
				      const calibrationPatternParameters &calibPatternParam);

void calibrateCamera(const std::vector<imageWrap> &calibrationImages,
				      const calibrationPatternParameters &calibPatternParam,
					  intrinsicParameters &camParam);

#endif
