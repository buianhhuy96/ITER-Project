#pragma once
#ifndef PITAGDETECTOR_H
#define PITAGDETECTOR_H

#include <string>
#include "common_definitions.h"
#include "Pitag/FiducialDefines.h"
#include "Pitag/FiducialModelPi.h"


namespace estimatePose_ns {
struct algorithmParameters{
	blobDetectParams Param_blob;
	blobFilteringParams Param_filt;
	ellipseFitParams Param_ellip;
	tagLenAngParams Param_LenAng;
};

void pitagDetector(const coder::array<uint8_T, 4U> &gray_image,
		const std::string &constellation,
		const algorithmParameters &algorithmParams,

		std::vector<ipa_Fiducials::t_points> &vec_points,
		int *err);
}
#endif
