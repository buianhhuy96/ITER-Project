#ifndef COMPUTECALIBRATIONPOSES_H
#define COMPUTECALIBRATIONPOSES_H

// Include Files
#include <map>
#include "common_definitions.h"
#include "./library/computeCalibrationPoses_internal.h"

namespace computeCalibrationPoses_ns {

/* API Error List */
const std::map<int, char const*> API_error_codes = {
		{1,"Error 0001: Function only supports gray or RGB images."},
		{2,"Error 0002: Robot pose is not a homogeneous transformation matrix."},
		{3,"Error 0003: Hand-eye estimation is not a homogeneous transformation matrix."},
		{4,"Error 0004: Angular bounds are not in valid range."},
		{5,"Error 0005: Square size is not in valid range."},
		{6,"Error 0006: Board sizes are not in valid range."},
		{7,"Error 0007: Camera intrinsics contain NaN."},
		{8,"Error 0008: Number of requested poses are not positive."},
		{9,"Error 0009: Number of requested poses exceeds maximum capability."},
		{10,"Error 0010: Calculation results contain inf or nan."},
		{101,"Error 0101: Cannot detect any checkerboard in the given image."},
		{102,"Error 0102: Size of checkerboard does not match with given size."}
};

void convertDataType4ArrayInputs(const double4x4 initialRobotPose, const double4x4 handEyeEstimate,
							const double2x3 angularBounds, const int3 &requestedNumPoses,
							double initialRobotPose_d[4][4], double handEyeEstimate_d[4][4],
							double angularBounds_d[3][2], int requestedNumPoses_d[3]);

void validateInputs(const imageWrap &images, const double4x4 initialRobotPose, const double4x4 handEyeEstimate,
					const double &roughDistance, const double2x3 angularBounds, const calibrationPatternParameters &calibPatternParam,
					const cam_struct_t *factoryCamParam, const int &requestedNumPoses);

}
void computeCalibrationPoses(const imageWrap &initialImage,
					const double4x4 initialRobotPose, const double4x4 handEyeEstimate,
					const double &roughDistance, const double2x3 angularBounds, 
					const calibrationPatternParameters &calibPatternParam,
					const intrinsicParameters &factoryCamParam, const int3 &requestedNumPoses,

					std::vector<double4x4> &robotPoses);

#endif
