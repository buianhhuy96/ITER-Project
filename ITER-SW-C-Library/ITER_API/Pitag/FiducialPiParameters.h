#ifndef __IPA_FIDUCIAL_PI_PARAMETERS_H__
#define __IPA_FIDUCIAL_PI_PARAMETERS_H__

#include "../Pitag/AbstractFiducialParameters.h"

namespace ipa_Fiducials
{

/// @class AbstractFiduciaParameters
///
/// Abstract class to represent the parameters of a fiducial
class __DLL_LIBFIDUCIALS__ FiducialPiParameters : public AbstractFiducialParameters
{
public:
	double line_width_height; ///< Common width and height of fiducial

	// Assert that cross_ratio(line0) > cross_ratio(line1)
	double d_line0_AB; ///< Distance of from A to B of 4pt line A-B-C-D
	double d_line0_AC; ///< Distance of from A to C of 4pt line A-B-C-D

	double d_line1_AB; ///< Distance of from A to B of 4pt line A-B-C-D
	double d_line1_AC; ///< Distance of from A to C of 4pt line A-B-C-D
};

} // end namespace ipa_Fiducials



//classes to represent the parameters for procesing and filtering detections
/// Blob detection paramters
class __DLL_LIBFIDUCIALS__ blobDetectParams
{
public:
	float delta;
	float min_area_px;
	float max_area_per;
	float max_var;
};

/// Blob filtering paramters
class __DLL_LIBFIDUCIALS__ blobFilteringParams 
{
public:
	float min_aspect;
	float max_aspect;
	float solidity;
	float min_ext;
	float max_ext;
	float max_Subregions;
};

/// Ellipse Fitting paramters
class __DLL_LIBFIDUCIALS__ ellipseFitParams 
{
public:
	float min_size;
	float max_aspect;
};

/// Parametersfor Tag Line length and angle test
class __DLL_LIBFIDUCIALS__ tagLenAngParams 
{
public:
	float minAng;
	float maxAng;
	float minRatio;
	float maxRatio;
};



#endif // __IPA_FIDUCIAL_PI_PARAMETERS_H__



