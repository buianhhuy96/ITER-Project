#include "API_Test.h"

testHandeyeCalibration::testHandeyeCalibration(string test_directory,
		bool trigger_error) :
		test_directory_(test_directory), trigger_error_(trigger_error) {
}

testHandeyeCalibration::~testHandeyeCalibration() {
}

bool testHandeyeCalibration::readInputMat(std::vector<imageWrap> &images,
		std::vector<double4x4> &robotPosesVec,
		calibrationPatternParameters &calibPatternParam,
		intrinsicParameters &camParam) {
	// get data flag
	bool data_retrieval = true;

	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return false;

	mxArray *img_arr = matGetVariable(pmat, "images");
	if (img_arr == NULL || mxIsEmpty(img_arr)) {
		return !data_retrieval;
	} else {
		// copy data
		const mwSize *img_size = mxGetDimensions(img_arr);

		mwSize height = *img_size;
		mwSize width = *(img_size + 1);
		mwSize channel = *(img_size + 2);

		mwSize num_of_images = 1;
		if (mxGetNumberOfDimensions(img_arr) == 4)
			num_of_images = *(img_size + 3);
		mxUint8 *img_pr = mxGetUint8s(img_arr);

		if (img_pr != NULL) {

			for (mwSize i = 0; i < num_of_images; i++) {

				imageWrap image;
				mxUint8 *imageData = (mxUint8*) malloc(
						width * height * channel * sizeof(unsigned char));
				image.width = width;
				image.height = height;
				image.numChannels = channel;

				for (mwSize c = 0; c < channel; c++) {
					for (mwSize w = 0; w < width; w++) {
						for (mwSize h = 0; h < height; h++) {
							(imageData[c + channel * w + width * channel * h]) =
									*(img_pr);
							img_pr++;
						}
					}
				}
				image.imageData = imageData;
				images.push_back(image);
			}
		}
	}
	mxArray *img2_arr = matGetVariable(pmat, "images2");
	if (img2_arr != NULL && !mxIsEmpty(img2_arr)) {
		// copy data
		const mwSize *img_size = mxGetDimensions(img2_arr);

		mwSize height = *img_size;
		mwSize width = *(img_size + 1);
		mwSize channel = *(img_size + 2);
		mwSize num_of_images = 1;
		if (mxGetNumberOfDimensions(img2_arr) == 4)
			num_of_images = *(img_size + 3);
		mxUint8 *img_pr = mxGetUint8s(img2_arr);

		if (img_pr != NULL) {

			for (mwSize i = 0; i < num_of_images; i++) {

				imageWrap image;
				mxUint8 *imageData = (mxUint8*) malloc(
						width * height * channel * sizeof(unsigned char));
				image.width = width;
				image.height = height;
				image.numChannels = channel;

				for (mwSize c = 0; c < channel; c++) {
					for (mwSize w = 0; w < width; w++) {
						for (mwSize h = 0; h < height; h++) {
							(imageData[c + channel * w + width * channel * h]) =
									*(img_pr);
							img_pr++;
						}
					}
				}
				image.imageData = imageData;
				images.push_back(image);
			}
		}
	}

	mxArray *robot_poses_arr = matGetVariable(pmat, "robot_poses");
	if (robot_poses_arr == NULL || mxIsEmpty(robot_poses_arr)) {
		return !data_retrieval;
	} else {
		// copy data

		mwSize num_of_poses = *(mxGetDimensions(robot_poses_arr) + 2);
		mxDouble *poses_pr = mxGetDoubles(robot_poses_arr);

		if (poses_pr != NULL) {

			for (mwSize i = 0; i < num_of_poses; i++) {
				double4x4 pose;
				for (int j = 0; j < 4; j++) {
					double4 row { (double) *(poses_pr + i * 16 + j * 4),
							(double) *(poses_pr + i * 16 + j * 4 + 1),
							(double) *(poses_pr + i * 16 + j * 4 + 2),
							(double) *(poses_pr + i * 16 + j * 4 + 3) };
					pose[j] = row;
				}
				robotPosesVec.push_back(pose);
			}
		}
	}

	mxArray *square_size_arr = matGetVariable(pmat, "square_size");
	if (square_size_arr == NULL || mxIsEmpty(square_size_arr)) {
		return !data_retrieval;
	} else {
		// copy data
		double *pr = mxGetDoubles(square_size_arr);
		calibPatternParam.squareSize = *pr;
	}

	mxArray *cam_arr = matGetVariable(pmat, "camera_params");
	if (cam_arr == NULL || mxIsEmpty(cam_arr)) {
		return !data_retrieval;
	} else {
		int num_of_param = mxGetNumberOfFields(cam_arr);
		if (num_of_param == 0) {
			return false;
		}
		for (int field_index = 0; field_index < num_of_param; field_index++) {
			const char *field_name = mxGetFieldNameByNumber(cam_arr,
					field_index);
			mxArray *field_array_ptr = mxGetFieldByNumber(cam_arr, 0,
					field_index);
			mxDouble *data_pointer_lf = mxGetDoubles(field_array_ptr);

			if (!strcmp(field_name, "RadialDistortion")) {
				// Radial Distortion
				camParam.distortionsRadial.x = *data_pointer_lf;
				camParam.distortionsRadial.y = *(data_pointer_lf + 1);
				camParam.distortionsRadial.z = *(data_pointer_lf + 2);
			}
			if (!strcmp(field_name, "TangentialDistortion")) {
				// Tangential Distortion
				camParam.distortionsTangential.x = *data_pointer_lf;
				camParam.distortionsTangential.y = *(data_pointer_lf + 1);
			}

			if (!strcmp(field_name, "IntrinsicMatrix")) {
				// Intrinsic Matrix
				camParam.focalLength.x = *data_pointer_lf;
				camParam.focalLength.y = *(data_pointer_lf + 4);
				camParam.principalPoint.x = *(data_pointer_lf + 2);
				camParam.principalPoint.y = *(data_pointer_lf + 5);
			}
		}
	}

	return data_retrieval;
}

bool testHandeyeCalibration::readExpectedOutputMat(
		double4x4 &handEyeCalibration, int &usedImages,
		double &reprojectionError, double &rotationError,
		double &translationError) {
// get data flag
	bool data_retrieval = true;

	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return false;

	mxArray *hand_eye_HT_arr = matGetVariable(pmat, "hand_eye_HT");
	if (hand_eye_HT_arr == NULL || mxIsEmpty(hand_eye_HT_arr)) {
		return false;
	} else {
		mxDouble *hand_eye_HT_pr = mxGetDoubles(hand_eye_HT_arr);
		if (hand_eye_HT_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 4; j++) {
					handEyeCalibration[i][j] = *(hand_eye_HT_pr + i * 4 + j);
				}
			}
		}
	}
	mxArray *errors_arr = matGetVariable(pmat, "errors");
	if (errors_arr == NULL || mxIsEmpty(errors_arr)) {
		return false;
	} else {
		// copy data
		mxDouble *errors_pr = mxGetDoubles(errors_arr);
		if (errors_pr != NULL) {
			rotationError = *(errors_pr);
			translationError = *(errors_pr + 1);
			reprojectionError = *(errors_pr + 2);
		}
	}

	return data_retrieval;
}

void testHandeyeCalibration::operator()() {

	std::vector<imageWrap> images;
	std::vector<double4x4> robotPosesVec;
	calibrationPatternParameters calibPatternParam;
	intrinsicParameters camParam;

	double4x4 handEyeCalibration;
	int usedImages;
	double reprojectionError;
	double rotationError;
	double translationError;

	double4x4 r_handEyeCalibration;
	int r_usedImages;
	double r_reprojectionError;
	double r_rotationError;
	double r_translationError;

	std::cout << split(test_directory_,'/') << std::endl;

	if (!testHandeyeCalibration::readInputMat(images, robotPosesVec,
			calibPatternParam, camParam)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}

	if (!trigger_error_) {

		if (!testHandeyeCalibration::readExpectedOutputMat(r_handEyeCalibration,
				r_usedImages, r_reprojectionError, r_rotationError,
				r_translationError)) {
			FAILM(
					"ERROR: " + test_directory_ + ": "
							+ "Cannot read output file!");
		}

		// DUT
		calibrateHandEye(images, robotPosesVec, calibPatternParam, camParam,

		handEyeCalibration, usedImages, reprojectionError, rotationError,
				translationError);

		std::cout << "Used images = " << usedImages << std::endl;

		// Comparing actual outputs vs expected outputs
		for (int i1 = 0; i1 < 4; i1++) {
			for (int i0 = 0; i0 < 4; i0++) {
				double ref = r_handEyeCalibration[i0][i1];
				double actual = handEyeCalibration[i0][i1];
				double delta = 0;
				if (std::fabs(ref) < 0.1)
					delta = 0.005;
				else
					delta = ref*0.005;
				ASSERT_EQUAL_DELTA_DDTM(
						"ERROR: Trace back " + test_directory_ + ":",
						ref, actual, delta,
						DDTM(" Failed at: hand_eye_HT[" + std::to_string(i0) + "][" + std::to_string(i1) + "]"));
			}
		}

		ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_directory_ + ":",
				r_reprojectionError, reprojectionError, reprojectionError*0.07,
				DDTM(" Failed at: reprojectionError"));

		ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_directory_ + ":",
				r_rotationError, rotationError, rotationError*0.07, DDTM(" Failed at: rotationError"));

		ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_directory_ + ":",
				r_translationError, translationError, translationError*0.07,
				DDTM(" Failed at: translationError"));
	} else {

		// DUT
		ASSERT_THROWS_MSG(
				calibrateHandEye(images, robotPosesVec, calibPatternParam,
						camParam,

						handEyeCalibration, usedImages, reprojectionError,
						rotationError, translationError), char const*);
	}

}


testCameraCalibration::testCameraCalibration(string test_directory,
		bool trigger_error) :
		test_directory_(test_directory), trigger_error_(trigger_error) {
}

testCameraCalibration::~testCameraCalibration() {
}

bool testCameraCalibration::readInputMat(std::vector<imageWrap> &images,
	      calibrationPatternParameters &calibPatternParam) {
	// get data flag
	bool data_retrieval = true;

	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return false;

	mxArray *img_arr = matGetVariable(pmat, "images");
	if (img_arr == NULL || mxIsEmpty(img_arr)) {
		return !data_retrieval;
	} else {
		// copy data
		const mwSize *img_size = mxGetDimensions(img_arr);

		mwSize height = *img_size;
		mwSize width = *(img_size + 1);
		mwSize channel = *(img_size + 2);

		mwSize num_of_images = 1;
		if (mxGetNumberOfDimensions(img_arr) == 4)
			num_of_images = *(img_size + 3);
		mxUint8 *img_pr = mxGetUint8s(img_arr);

		if (img_pr != NULL) {

			for (mwSize i = 0; i < num_of_images; i++) {

				imageWrap image;
				mxUint8 *imageData = (mxUint8*) malloc(
						width * height * channel * sizeof(unsigned char));
				image.width = width;
				image.height = height;
				image.numChannels = channel;

				for (mwSize c = 0; c < channel; c++) {
					for (mwSize w = 0; w < width; w++) {
						for (mwSize h = 0; h < height; h++) {
							(imageData[c + channel * w + width * channel * h]) =
									*(img_pr);
							img_pr++;
						}
					}
				}
				image.imageData = imageData;
				images.push_back(image);
			}
		}
	}
	mxArray *img2_arr = matGetVariable(pmat, "images2");
	if (img2_arr != NULL && !mxIsEmpty(img2_arr)) {
		// copy data
		const mwSize *img_size = mxGetDimensions(img2_arr);

		mwSize height = *img_size;
		mwSize width = *(img_size + 1);
		mwSize channel = *(img_size + 2);
		mwSize num_of_images = 1;
		if (mxGetNumberOfDimensions(img2_arr) == 4)
			num_of_images = *(img_size + 3);
		mxUint8 *img_pr = mxGetUint8s(img2_arr);

		if (img_pr != NULL) {

			for (mwSize i = 0; i < num_of_images; i++) {

				imageWrap image;
				mxUint8 *imageData = (mxUint8*) malloc(
						width * height * channel * sizeof(unsigned char));
				image.width = width;
				image.height = height;
				image.numChannels = channel;

				for (mwSize c = 0; c < channel; c++) {
					for (mwSize w = 0; w < width; w++) {
						for (mwSize h = 0; h < height; h++) {
							(imageData[c + channel * w + width * channel * h]) =
									*(img_pr);
							img_pr++;
						}
					}
				}
				image.imageData = imageData;
				images.push_back(image);
			}
		}
	}

	mxArray *square_size_arr = matGetVariable(pmat, "square_size");
	if (square_size_arr == NULL || mxIsEmpty(square_size_arr)) {
		return !data_retrieval;
	} else {
		// copy data
		double *pr = mxGetDoubles(square_size_arr);
		calibPatternParam.squareSize = *pr;
	}

	mxArray *board_size_arr = matGetVariable(pmat, "board_size");
		if (board_size_arr == NULL || mxIsEmpty(board_size_arr)) {
			return !data_retrieval;
		} else {
			// copy data
			int *pr = mxGetInt32s(board_size_arr);
			calibPatternParam.numSquaresHor = *pr;
			calibPatternParam.numSquaresVer = *(pr+1);
		}


	return data_retrieval;
}

bool testCameraCalibration::readExpectedOutputMat(
		intrinsicParameters &camParam) {

	// get data flag
	bool data_retrieval = true;

	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return false;

	 coder::array<bool, 1U> valid_idx;
	data_retrieval &= getArrayData<boolean_T, 1U>(pmat, "valid_idx",
			valid_idx);

		int img_counter = 0;
		  for (int i0 = 0; i0 < valid_idx.size(0); i0++){
			if (valid_idx[i0] == true){
				img_counter++;
			}
		  }
		camParam.numUsedImages = static_cast<int>(img_counter);


	mxArray *calculation_err_arr = matGetVariable(pmat, "MREf");
	if (calculation_err_arr == NULL || mxIsEmpty(calculation_err_arr)) {
		return !data_retrieval;
	} else {
		// copy data
		double *pr = mxGetDoubles(calculation_err_arr);
		camParam.reprojectionError = *pr;
	}

	mxArray *cam_arr = matGetVariable(pmat, "camera_params");
	if (cam_arr == NULL || mxIsEmpty(cam_arr)) {
		return !data_retrieval;
	} else {
		int num_of_param = mxGetNumberOfFields(cam_arr);
		if (num_of_param == 0) {
			return false;
		}
		for (int field_index = 0; field_index < num_of_param; field_index++) {
			const char *field_name = mxGetFieldNameByNumber(cam_arr,
					field_index);
			mxArray *field_array_ptr = mxGetFieldByNumber(cam_arr, 0,
					field_index);
			mxDouble *data_pointer_lf = mxGetDoubles(field_array_ptr);

			if (!strcmp(field_name, "RadialDistortion")) {
				// Radial Distortion
				camParam.distortionsRadial.x = *data_pointer_lf;
				camParam.distortionsRadial.y = *(data_pointer_lf + 1);
				camParam.distortionsRadial.z = *(data_pointer_lf + 2);
			}
			if (!strcmp(field_name, "TangentialDistortion")) {
				// Tangential Distortion
				camParam.distortionsTangential.x = *data_pointer_lf;
				camParam.distortionsTangential.y = *(data_pointer_lf + 1);
			}

			if (!strcmp(field_name, "IntrinsicMatrix")) {
				// Intrinsic Matrix

				std::cout << *(data_pointer_lf + 0) << std::endl;
				std::cout << *(data_pointer_lf + 1) << std::endl;
				std::cout << *(data_pointer_lf + 2) << std::endl;
				std::cout << *(data_pointer_lf + 3) << std::endl;
				std::cout << *(data_pointer_lf + 4) << std::endl;
				std::cout << *(data_pointer_lf + 5) << std::endl;
				std::cout << *(data_pointer_lf + 6) << std::endl;
				std::cout << *(data_pointer_lf + 7) << std::endl;
				std::cout << *(data_pointer_lf + 8) << std::endl;

				camParam.focalLength.x = *data_pointer_lf;
				camParam.focalLength.y = *(data_pointer_lf + 4);
				camParam.principalPoint.x = *(data_pointer_lf + 2);
				camParam.principalPoint.y = *(data_pointer_lf + 5);
			}
		}
	}

	return data_retrieval;
}


void testCameraCalibration::operator()() {

	std::vector<imageWrap> images;
	calibrationPatternParameters calibPatternParam;
	intrinsicParameters camParam;


	intrinsicParameters r_camParam;
	std::cout << split(test_directory_,'/') << std::endl;

	if (!testCameraCalibration::readInputMat(images, calibPatternParam)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}

	if (!trigger_error_) {

		if (!testCameraCalibration::readExpectedOutputMat(r_camParam)) {
			FAILM(
					"ERROR: " + test_directory_ + ": "
							+ "Cannot read output file!");
		}

		// DUT
		calibrateCamera(images, calibPatternParam, camParam);

		// Comparing actual outputs vs expected outputs
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.focalLength.x ,camParam.focalLength.x,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.focalLength.y ,camParam.focalLength.y,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.distortionsRadial.x ,camParam.distortionsRadial.x,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.distortionsRadial.y ,camParam.distortionsRadial.y,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.distortionsRadial.z ,camParam.distortionsRadial.z,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.distortionsTangential.x ,camParam.distortionsTangential.x,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.distortionsTangential.y ,camParam.distortionsTangential.y,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.principalPoint.x ,camParam.principalPoint.x,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.principalPoint.y ,camParam.principalPoint.y,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.reprojectionError ,camParam.reprojectionError,0);
		ASSERT_EQUAL_DELTAM("ERROR: Trace back " + test_directory_ + ":", r_camParam.numUsedImages ,camParam.numUsedImages,0);

	} else {

		// DUT
		ASSERT_THROWS_MSG(
				calibrateCamera(images, calibPatternParam, camParam), char const*);
	}

}
