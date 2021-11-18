#include "Unit_Test.h"

testPreprocessImages::testPreprocessImages(string test_directory, bool trigger_error) :
	test_directory_(test_directory), trigger_error_(trigger_error) {
}

testPreprocessImages::~testPreprocessImages() {
}

bool testPreprocessImages::readInputMat( coder::array<unsigned char, 4U> &images, cam_struct_t &camera_params) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL){
		return !data_retrieval;
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
				camera_params.RadialDistortion[0] = *data_pointer_lf;
				camera_params.RadialDistortion[1] = *(data_pointer_lf + 1);
				camera_params.RadialDistortion[2] = *(data_pointer_lf + 2);
			}
			if (!strcmp(field_name, "TangentialDistortion")) {
				// Tangential Distortion
				camera_params.TangentialDistortion[0] = *data_pointer_lf;
				camera_params.TangentialDistortion[1] = *(data_pointer_lf + 1);
			}
			// ImageSize - Not required in this API
			camera_params.ImageSize[0] = 0;
			camera_params.ImageSize[1] = 0;

			// Estimate Skew - Not required in this API
			camera_params.EstimateSkew = false;

			// Num Radial Distortion Coefficients - Not required in this API
			camera_params.NumRadialDistortionCoefficients = 0;

			// Estimate Tangential Distortion - Not required in this API
			camera_params.EstimateTangentialDistortion = 0;

			if (!strcmp(field_name, "IntrinsicMatrix")) {
				// Intrinsic Matrix
				camera_params.IntrinsicMatrix[0][0] = *data_pointer_lf;
				camera_params.IntrinsicMatrix[0][1] = *(data_pointer_lf + 1);
				camera_params.IntrinsicMatrix[0][2] = *(data_pointer_lf + 2);
				camera_params.IntrinsicMatrix[1][0] = *(data_pointer_lf + 3);
				camera_params.IntrinsicMatrix[1][1] = *(data_pointer_lf + 4);
				camera_params.IntrinsicMatrix[1][2] = *(data_pointer_lf + 5);
				camera_params.IntrinsicMatrix[2][0] = *(data_pointer_lf + 6);
				camera_params.IntrinsicMatrix[2][1] = *(data_pointer_lf + 7);
				camera_params.IntrinsicMatrix[2][2] = *(data_pointer_lf + 8);
			}
		}
	}

	data_retrieval &= getArrayData<uint8_T, 4U>(pmat, "images",
			images);
	return data_retrieval;
}



bool testPreprocessImages::readExpectedOutputMat( coder::array<unsigned char, 4U> &gray_images) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<uint8_T, 4U>(pmat, "images", gray_images);
	return data_retrieval;
}

void testPreprocessImages::operator()() {

	coder::array<uint8_T, 4U> images;
	cam_struct_t camera_params;

	coder::array<uint8_T, 4U> gray_images;
	coder::array<uint8_T, 4U> r_gray_images;

	std::cout << test_directory_ << std::endl;
	
	if (!testPreprocessImages::readInputMat(images, camera_params)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}

	if (!testPreprocessImages::readExpectedOutputMat(r_gray_images)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}
	preprocessImages(images, &camera_params, true, gray_images );

	ITER_API_terminate();
	// Comparing actual outputs vs expected outputs
	assertion<uint8_T>::assert4D(test_directory_, "images", gray_images, r_gray_images, 2);

}

testReadRobotPoses::testReadRobotPoses(string test_directory, bool trigger_error) :
		test_directory_(test_directory), trigger_error_(trigger_error) {
}

testReadRobotPoses::~testReadRobotPoses() {
}

bool testReadRobotPoses::readInputMat(
		coder::array<double, 3U> &robot_poses) {
	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "robot_poses",
			robot_poses);

	return data_retrieval;
}

bool testReadRobotPoses::readExpectedOutputMat(
		coder::array<double, 3U> &poses, coder::array<double, 3U> &extrinsics) {
	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "poses",
			poses);
	data_retrieval &= getArrayData<double, 3U>(pmat, "extrinsics",
			extrinsics);

	return data_retrieval;
}

void testReadRobotPoses::operator()() {


	coder::array<double, 3U> robot_poses;
	coder::array<boolean_T, 1U> valid_idx;
	coder::array<double, 3U> poses;
	coder::array<double, 3U> extrinsics;

	coder::array<double, 3U> r_poses;
	coder::array<double, 3U> r_extrinsics;

	std::cout << test_directory_ << std::endl;

	if (!testReadRobotPoses::readInputMat(robot_poses)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	if (!testReadRobotPoses::readExpectedOutputMat(r_poses,
			r_extrinsics)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}

	// DUT
	readRobotPoses(robot_poses, poses, extrinsics);

	ITER_API_terminate();
	// Comparing actual outputs vs expected outputs

	assertion<double>::assert3D(test_directory_, "poses", poses, r_poses, 0);

	assertion<double>::assert3D(test_directory_, "extrinsics", extrinsics, r_extrinsics, 0);
}

testComputeCamExtrinsics::testComputeCamExtrinsics(string test_directory, bool trigger_error) :
			test_directory_(test_directory), trigger_error_(trigger_error) {
}

testComputeCamExtrinsics::~testComputeCamExtrinsics() {
}

bool testComputeCamExtrinsics::readInputMat(coder::array<uint8_T, 4U> &images, double &square_size,
		cam_struct_t &camera_params) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return !data_retrieval;



	mxArray *cam_arr = matGetVariable(pmat, "camera_params");
	mxArray *square_size_arr = matGetVariable(pmat, "square_size");
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
				camera_params.RadialDistortion[0] = *data_pointer_lf;
				camera_params.RadialDistortion[1] = *(data_pointer_lf + 1);
				camera_params.RadialDistortion[2] = *(data_pointer_lf + 2);
			}
			if (!strcmp(field_name, "TangentialDistortion")) {
				// Tangential Distortion
				camera_params.TangentialDistortion[0] = *data_pointer_lf;
				camera_params.TangentialDistortion[1] = *(data_pointer_lf + 1);
			}
			// ImageSize - Not required in this API
			camera_params.ImageSize[0] = 0;
			camera_params.ImageSize[1] = 0;

			// Estimate Skew - Not required in this API
			camera_params.EstimateSkew = false;

			// Num Radial Distortion Coefficients - Not required in this API
			camera_params.NumRadialDistortionCoefficients = 0;

			// Estimate Tangential Distortion - Not required in this API
			camera_params.EstimateTangentialDistortion = 0;

			if (!strcmp(field_name, "IntrinsicMatrix")) {
				// Intrinsic Matrix
				camera_params.IntrinsicMatrix[0][0] = *data_pointer_lf;
				camera_params.IntrinsicMatrix[0][1] = *(data_pointer_lf + 1);
				camera_params.IntrinsicMatrix[0][2] = *(data_pointer_lf + 2);
				camera_params.IntrinsicMatrix[1][0] = *(data_pointer_lf + 3);
				camera_params.IntrinsicMatrix[1][1] = *(data_pointer_lf + 4);
				camera_params.IntrinsicMatrix[1][2] = *(data_pointer_lf + 5);
				camera_params.IntrinsicMatrix[2][0] = *(data_pointer_lf + 6);
				camera_params.IntrinsicMatrix[2][1] = *(data_pointer_lf + 7);
				camera_params.IntrinsicMatrix[2][2] = *(data_pointer_lf + 8);
			}
		}
		double *pr = mxGetDoubles(square_size_arr);
		square_size = *pr;
	}

	data_retrieval &= getArrayData<uint8_T, 4U>(pmat, "images",
			images);
	return data_retrieval;
}

bool testComputeCamExtrinsics::readExpectedOutputMat(
		coder::array<double, 3U> &image_points,
		coder::array<bool, 1U> &valid_idx,
		coder::array<double, 3U> &cam_extrinsics,
		coder::array<double, 3U> &camera_poses,
		coder::array<double, 2U> &world_points) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "image_points",
			image_points);

	data_retrieval &= getArrayData<bool, 1U>(pmat, "valid_idx",
			valid_idx);

	data_retrieval &= getArrayData<double, 3U>(pmat, "cam_extrinsics",
			cam_extrinsics);

	data_retrieval &= getArrayData<double, 3U>(pmat, "camera_poses",
			camera_poses);

	data_retrieval &= getArrayData<double, 2U>(pmat, "world_points",
			world_points);

	// extract the specified variable


	return data_retrieval;
}

void testComputeCamExtrinsics::operator()() {

	coder::array<uint8_T, 4U> images;
	double squareSize;
	cam_struct_t camera_params;

	coder::array<double, 3U> image_points;
	coder::array<boolean_T, 1U> valid_idx;
	coder::array<double, 3U> cam_extrinsics;
	coder::array<double, 3U> camera_poses;
	coder::array<double, 2U> world_points;

	coder::array<double, 3U> r_image_points;
	coder::array<uint8_T, 4U> r_valid_imgz;
	coder::array<boolean_T, 1U> r_valid_idx;
	coder::array<double, 3U> r_cam_extrinsics;
	coder::array<double, 3U> r_camera_poses;
	coder::array<double, 2U> r_world_points;
	int err;
	
	std::cout << test_directory_ << std::endl;
	
	if (!testComputeCamExtrinsics::readInputMat(images, squareSize,
			camera_params)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}

	ComputeCamExtrinsics(images, squareSize, &camera_params, image_points,
			valid_idx, cam_extrinsics, camera_poses, world_points, &err);

	ITER_API_terminate();
	if(!trigger_error_)
		{
	if (!testComputeCamExtrinsics::readExpectedOutputMat(r_image_points,
			r_valid_idx, r_cam_extrinsics, r_camera_poses, r_world_points)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}

	// Comparing actual outputs vs expected outputs

	assertion<double>::assert3D(test_directory_, "image_points", image_points, r_image_points, 0.25);

	assertion<boolean_T>::assert1D(test_directory_, "valid_idx", valid_idx, r_valid_idx, 0);

	assertion<double>::assert3D(test_directory_, "cam_extrinsics", cam_extrinsics, r_cam_extrinsics, 0.05);

	assertion<double>::assert3D(test_directory_, "camera_poses", camera_poses, r_camera_poses, 0.01);

	assertion<double>::assert2D(test_directory_, "world_points", world_points, r_world_points, 0.0001);
	}
	else{		ASSERT_NOT_EQUAL_TO(err, 0);
	}
}

testHandeyeShah::testHandeyeShah(string test_directory, bool trigger_error) :
				test_directory_(test_directory), trigger_error_(trigger_error){
}

testHandeyeShah::~testHandeyeShah() {
}

bool testHandeyeShah::readInputMat(
		coder::array<double, 3U> &extrinsics,
		coder::array<double, 3U> &cam_extrinsics) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "extrinsics",
			extrinsics);

	data_retrieval &= getArrayData<double, 3U>(pmat, "cam_extrinsics",
			cam_extrinsics);

	return data_retrieval;
}

bool testHandeyeShah::readExpectedOutputMat( double base2grid[4][4],
		double hand_eye_HT[4][4]) {
	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return false;

	// extract the specified variable
	mxArray *base2grid_arr = matGetVariable(pmat, "base2grid");
	mxArray *hand_eye_HT_arr = matGetVariable(pmat, "hand_eye_HT");
	if (base2grid_arr == NULL || mxIsEmpty(base2grid_arr)
			|| hand_eye_HT_arr == NULL || mxIsEmpty(hand_eye_HT_arr)) {
		return false;
	} else {
		// copy data
		mxDouble *base2grid_pr = mxGetDoubles(base2grid_arr);
		if (base2grid_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 4; j++) {
					base2grid[i][j] = *(base2grid_pr + i * 4 + j);
				}
			}
		}

		mxDouble *hand_eye_HT_pr = mxGetDoubles(hand_eye_HT_arr);
		if (hand_eye_HT_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 4; j++) {
					hand_eye_HT[i][j] = *(hand_eye_HT_pr + i * 4 + j);
				}
			}
		}
	}

	return true;
}

void testHandeyeShah::operator()() {

	coder::array<double, 3U> extrinsics;
	coder::array<double, 3U> cam_extrinsics;

	double base2grid[4][4];
	double hand_eye_HT[4][4];
	int err;

	double r_base2grid[4][4];
	double r_hand_eye_HT[4][4];
	
	std::cout << test_directory_ << std::endl;
	
	if (!testHandeyeShah::readInputMat(extrinsics, cam_extrinsics)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}

	HandeyeShah(extrinsics, cam_extrinsics, base2grid, hand_eye_HT, &err);

	ITER_API_terminate();
	// Comparing actual outputs vs expected outputs
	if(!trigger_error_)
	{
		if (!testHandeyeShah::readExpectedOutputMat(r_base2grid, r_hand_eye_HT)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}

		assertion<double>::assertStatic2D(test_directory_, "hand_eye_HT", hand_eye_HT, r_hand_eye_HT, 0.0001);

		assertion<double>::assertStatic2D(test_directory_, "base2grid", base2grid, r_base2grid, 0.0001);
	}
	else{
		ASSERT_NOT_EQUAL_TO(err, 0);
	}



}

testComputeErrors::testComputeErrors(string test_directory, bool trigger_error) :
				test_directory_(test_directory), trigger_error_(trigger_error){
}

testComputeErrors::~testComputeErrors() {
}

bool testComputeErrors::readInputMat(
		coder::array<double, 3U> &extrinsics, double hand_eye_HT[4][4],
		double base2grid[4][4], coder::array<double, 3U> &cam_extrinsics,
		coder::array<double, 3U> &image_points,
		coder::array<double, 2U> &world_points, double KM[4][3]) {

	// get data flag
	bool data_retrieval = true;

	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + input_);
	if (pmat == NULL)
		return !data_retrieval;


	// extract the specified variable
	mxArray *hand_eye_HT_arr = matGetVariable(pmat, "hand_eye_HT");
	mxArray *base2grid_arr = matGetVariable(pmat, "base2grid");
	mxArray *KM_arr = matGetVariable(pmat, "KM");
	if (hand_eye_HT_arr == NULL || mxIsEmpty(hand_eye_HT_arr)
			|| base2grid_arr == NULL || mxIsEmpty(base2grid_arr)
			|| KM_arr == NULL || mxIsEmpty(KM_arr)) {
		return !data_retrieval;
	} else {

		mxDouble *hand_eye_HT_pr = mxGetDoubles(hand_eye_HT_arr);
		if (hand_eye_HT_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 4; j++) {
					hand_eye_HT[i][j] = *(hand_eye_HT_pr + i * 4 + j);
				}
			}
		}

		mxDouble *base2grid_pr = mxGetDoubles(base2grid_arr);
		if (base2grid_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 4; j++) {
					base2grid[i][j] = *(base2grid_pr + i * 4 + j);
				}
			}
		}


		mxDouble *KM_pr = mxGetDoubles(KM_arr);
		if (KM_pr != NULL) {
			for (mwSize i = 0; i < 4; i++) {
				for (mwSize j = 0; j < 3; j++) {
					KM[i][j] = *(KM_pr + i * 3 + j);
				}
			}
		}
		data_retrieval &= getArrayData<double, 3U>(pmat, "extrinsics",
				extrinsics);


		data_retrieval &= getArrayData<double, 3U>(pmat, "cam_extrinsics",
				cam_extrinsics);


		data_retrieval &= getArrayData<double, 3U>(pmat, "image_points",
				image_points);


		data_retrieval &= getArrayData<double, 2U>(pmat, "world_points",
				world_points);
	}

	return data_retrieval;
}

bool testComputeErrors::readExpectedOutputMat( double errors[5]) {
	// open MAT-file
	MATFile *pmat = readMatfile(test_directory_ + output_);
	if (pmat == NULL)
		return false;

	// extract the specified variable
	mxArray *errors_arr = matGetVariable(pmat, "errors");
	if (errors_arr == NULL || mxIsEmpty(errors_arr)) {
		return false;
	} else {
		// copy data
		mxDouble *errors_pr = mxGetDoubles(errors_arr);
		if (errors_pr != NULL) {
			for (mwSize i = 0; i < 5; i++) {
				errors[i] = *(errors_pr + i);
			}
		}
	}

	return true;
}

void testComputeErrors::operator()() {

	coder::array<double, 3U> extrinsics;
	double hand_eye_HT[4][4];
	double base2grid[4][4];
	coder::array<double, 3U> cam_extrinsics;
	coder::array<double, 3U> image_points;
	coder::array<double, 2U> world_points;

	double KM[4][3];
	double errors[3];
	double r_errors[3];

	std::cout << test_directory_ << std::endl;
	if (!testComputeErrors::readInputMat(extrinsics, hand_eye_HT,
			base2grid, cam_extrinsics, image_points, world_points, KM)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	
	coder::array<double, 2U> world_points_redundant;
	world_points_redundant.set_size(world_points.size(0),world_points.size(1));
	for (int i=0; i < world_points.size(0)*world_points.size(1); i++){
		world_points_redundant[i] = world_points[i];
	}
	
	
	if (!testComputeErrors::readExpectedOutputMat(r_errors)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}
	
	computeErrors(extrinsics, hand_eye_HT, base2grid, cam_extrinsics,
			image_points, world_points_redundant, KM, errors);
	
	ITER_API_terminate();
	
	// Comparing actual outputs vs expected outputs

	for (int i0 = 0; i0 < 3; i0++) {
		double refi = r_errors[i0];
		double actuali = errors[i0];
		if ((!isnan(refi) && !isnan(actuali))
				&& (!isinf(refi) && !isinf(actuali))) {
			ASSERT_EQUAL_DELTA_DDTM(
					"ERROR: Trace back " + test_directory_ + ":", refi,
					actuali, 0.0001,
					DDTM(" Failed at: errors[" + std::to_string(i0) + "]"));

		}
	}

}

