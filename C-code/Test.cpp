#include "Test.h"

std::vector<std::string> get_directories(const std::string &s) {
	std::vector<std::string> r;
	for (auto &p : std::filesystem::recursive_directory_iterator(s))
		if (p.is_directory())
			r.push_back(p.path().string() + "/");
	return r;
}

template <typename T, int N>
bool getArrayData(MATFile* input, const char* field, coder::array<T, N> &data_out){
	mxArray *arr = matGetVariable(input, field);
	if (arr == NULL || mxIsEmpty(arr)) {
		return false;
	} else {
		const mwSize *arr_size = mxGetDimensions(arr);
		if constexpr(N == 1)
			data_out.set_size(*arr_size);
		else if constexpr(N == 2)
			data_out.set_size(*arr_size, *(arr_size + 1));
		else if constexpr(N == 3)
			data_out.set_size(*arr_size, *(arr_size + 1), *(arr_size + 2));
		else if constexpr(N == 4)
			data_out.set_size(*arr_size, *(arr_size + 1), *(arr_size + 2),
					*(arr_size + 3));
		else
			return false;

		// copy data
		T *data;
		if constexpr(std::is_same<T,mxInt8>::value)
			data = mxGetInt8s(arr);
		else if constexpr(std::is_same<T,mxUint8>::value)
			data = mxGetUint8s(arr);
		else if constexpr(std::is_same<T,mxInt16>::value)
			data = mxGetInt16s(arr);
		else if constexpr(std::is_same<T,mxUint16>::value)
			data = mxGetUint16s(arr);
		else if constexpr(std::is_same<T,mxInt32>::value)
			data = mxGetInt32s(arr);
		else if constexpr(std::is_same<T,mxUint32>::value)
			data = mxGetUint32s(arr);
		else if constexpr(std::is_same<T,mxInt64>::value)
			data = mxGetInt64s(arr);
		else if constexpr(std::is_same<T,mxUint64>::value)
			data = mxGetUint64s(arr);
		else if constexpr(std::is_same<T,mxSingle>::value)
			data = mxGetSingles(arr);
		else if constexpr(std::is_same<T,mxDouble>::value)
			data = mxGetDoubles(arr);
		else if constexpr(std::is_same<T,mxLogical>::value)
			data = mxGetLogicals(arr);
		else
			return false;

		mwSize num = mxGetNumberOfElements(arr);
		if (data != NULL) {
			for (mwSize index=0; index<num; index++)  {
				data_out[index] = *(data + index);
			}
		}
	}
	return true;
}

template <typename T>
struct assertion{
	static void assert2D(string test_case, string array_name, coder::array<T, 2U> &actual, coder::array<T, 2U> &ref, double delta){
		int d1 = ref.size(1);
		int d0 = ref.size(0);
		for (int i1 = 0; i1 < d1; i1++) {
					for (int i0 = 0; i0 < d0; i0++) {
						ASSERT_EQUAL_DELTA_DDTM(
								"ERROR: Trace back " + test_case + ":",
								ref[i0 + (d0 * i1)],
								actual[i0 + (d0 * i1)], delta,
								DDTM(" Failed at: "+ array_name + "[" + to_string(i0) + "][" + to_string(i1) + "]"));
					}
				}
	}

	static void assert3D(string test_case, string array_name, coder::array<T, 3U> &actual, coder::array<T, 3U> &ref, double delta){
		int d2 = ref.size(2);
		int d1 = ref.size(1);
		int d0 = ref.size(0);
			for (int i2 = 0; i2 < d2; i2++) {
					for (int i1 = 0; i1 < d1; i1++) {
						for (int i0 = 0; i0 < d0; i0++) {
							ASSERT_EQUAL_DELTA_DDTM(
									"ERROR: Trace back " + test_case + ":",
									ref[i0 + (d0 * i1) + (d1 * d0 * i2)],
									actual[i0 + (d0 * i1) + (d1 * d0 * i2)], delta,
									DDTM(" Failed at: "+ array_name + "[" + to_string(i0) + "][" + to_string(i1) + "][" + to_string(i2) + "]"));
						}
					}
		}
	}

};


testReadRobotPoses::testReadRobotPoses(string test_directory) :
		test_directory_(test_directory) {
}

testReadRobotPoses::~testReadRobotPoses() {
}

bool testReadRobotPoses::readInputMat(string file,
		coder::array<double, 3U> &robot_poses,
		coder::array<boolean_T, 2U> &valid_idx) {
	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "robot_poses",
			robot_poses);

	data_retrieval &= getArrayData<boolean_T, 2U>(pmat, "valid_idx",
			valid_idx);

	return data_retrieval;
}

bool testReadRobotPoses::readExpectedOutputMat(string file,
		coder::array<double, 3U> &poses, coder::array<double, 3U> &extrinsics) {
	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "poses",
			poses);
	data_retrieval &= getArrayData<double, 3U>(pmat, "extrinsics",
			extrinsics);

	return data_retrieval;
}

void testReadRobotPoses::operator()() {

	string input = test_directory_ + "Input-RobotPoses.mat";
	string output = test_directory_ + "Output-RobotPoses.mat";

	coder::array<double, 3U> robot_poses;
	coder::array<boolean_T, 2U> valid_idx;
	coder::array<double, 3U> poses;
	coder::array<double, 3U> extrinsics;

	coder::array<double, 3U> expected_poses;
	coder::array<double, 3U> expected_extrinsics;

	if (!testReadRobotPoses::readInputMat(input, robot_poses, valid_idx)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	if (!testReadRobotPoses::readExpectedOutputMat(output, expected_poses,
			expected_extrinsics)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}

	// DUT
	readRobotPoses(robot_poses, valid_idx, poses, extrinsics);

	// Comparing actual outputs vs expected outputs
	int num = expected_poses.size(2);
	int width = expected_poses.size(1);
	int height = expected_poses.size(0);
	//flagPoses = true;
	for (int i2 = 0; i2 < num; i2++) {
		for (int i1 = 0; i1 < width; i1++) {
			for (int i0 = 0; i0 < height; i0++) {
				ASSERT_EQUAL_DDTM("ERROR: Trace back " + test_directory_ + ":",
						expected_poses[i0 + (height * i1)
								+ (width * height * i2)],
						poses[i0 + (height * i1) + (width * height * i2)],
						DDTM(" Failed at: Poses[" + to_string(i0) + "][" + to_string(i1) + "][" + to_string(i2) + "]"));
			}
		}
	}

	num = expected_extrinsics.size(2);
	width = expected_extrinsics.size(1);
	height = expected_extrinsics.size(0);
	for (int i2 = 0; i2 < num; i2++) {
		for (int i1 = 0; i1 < width; i1++) {
			for (int i0 = 0; i0 < height; i0++) {
				ASSERT_EQUAL_DDTM("ERROR: Trace back " + test_directory_ + ":",
						expected_extrinsics[i0 + (height * i1)
								+ (width * height * i2)],
						extrinsics[i0 + (height * i1) + (width * height * i2)],
						DDTM("Failed at: Extrinsics[" + to_string(i0) + "][" + to_string(i1) + "][" + to_string(i2) + "]"));
			}
		}
	}

}

testComputeCamExtrinsics::testComputeCamExtrinsics(string test_directory) :
		test_directory_(test_directory) {
}

testComputeCamExtrinsics::~testComputeCamExtrinsics() {
}

bool testComputeCamExtrinsics::readInputMat(string file,
		coder::array<uint8_T, 4U> &images, double &square_size,
		struct0_T &camera_params) {

	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
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

			// World Points - Not required in this API
			camera_params.WorldPoints.set_size(100, 2);
			camera_params.WorldPoints[0] = 0;
			camera_params.WorldPoints[1] = 0;

			// World Units - Not required in this API
			camera_params.WorldUnits = 0;

			// Estimate Skew - Not required in this API
			camera_params.EstimateSkew = false;

			// Num Radial Distortion Coefficients - Not required in this API
			camera_params.NumRadialDistortionCoefficients = 0;

			// Estimate Tangential Distortion - Not required in this API
			camera_params.EstimateTangentialDistortion = 0;

			// Rotation Vectors - Not required in this API
			camera_params.RotationVectors.set_size(100, 3);
			camera_params.RotationVectors[0] = 0;
			camera_params.RotationVectors[1] = 0;
			camera_params.RotationVectors[2] = 0;

			// Translation Vectors - Not required in this API
			camera_params.TranslationVectors.set_size(100, 3);
			camera_params.TranslationVectors[0] = 0;
			camera_params.TranslationVectors[1] = 0;
			camera_params.TranslationVectors[2] = 0;

			// Reprojection Errors - Not required in this API
			camera_params.ReprojectionErrors.set_size(100, 2, 100);
			camera_params.ReprojectionErrors[0] = 0;
			camera_params.ReprojectionErrors[1] = 0;

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
			if (!strcmp(field_name, "DetectedKeypoints")) {
				// Detected Keypoints
				camera_params.DetectedKeypoints.set_size(100, 2);
				camera_params.DetectedKeypoints[0] = 0;
				camera_params.DetectedKeypoints[1] = 0;
			}
		}
		double *pr = mxGetDoubles(square_size_arr);
		square_size = *pr;
	}

	data_retrieval &= getArrayData<uint8_T, 4U>(pmat, "images",
			images);
	return data_retrieval;
}

bool testComputeCamExtrinsics::readExpectedOutputMat(string file,
		coder::array<double, 3U> &image_points,
		coder::array<bool, 1U> &valid_idx,
		coder::array<double, 3U> &cam_extrinsics,
		coder::array<double, 3U> &camera_poses,
		coder::array<double, 2U> &world_points) {

	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
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

	string input = test_directory_ + "Input-ComputeCamExtrinsics.mat";
	string output = test_directory_ + "Output-ComputeCamExtrinsics.mat";

	coder::array<uint8_T, 4U> images;
	double squareSize;
	struct0_T camera_params;

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

	if (!testComputeCamExtrinsics::readInputMat(input, images, squareSize,
			camera_params)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	if (!testComputeCamExtrinsics::readExpectedOutputMat(output, r_image_points,
			r_valid_idx, r_cam_extrinsics, r_camera_poses, r_world_points)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}
	ComputeCamExtrinsics(images, squareSize, &camera_params, image_points,
			valid_idx, cam_extrinsics, camera_poses, world_points);

	// Comparing actual outputs vs expected outputs
	int d0, d1, d2;
	d2 = r_image_points.size(2);
	d1 = r_image_points.size(1);
	d0 = r_image_points.size(0);

	for (int i2 = 0; i2 < d2; i2++) {
		for (int i1 = 0; i1 < d1; i1++) {
			for (int i0 = 0; i0 < d0; i0++) {
				ASSERT_EQUAL_DELTA_DDTM(
						"ERROR: Trace back " + test_directory_ + ":",
						r_image_points[i0 + (d0 * i1) + (d1 * d0 * i2)],
						image_points[i0 + (d0 * i1) + (d1 * d0 * i2)], 0.25,
						DDTM(" Failed at: image_points[" + to_string(i0) + "][" + to_string(i1) + "][" + to_string(i2) + "]" ));
			}
		}
	}

	d0 = r_valid_idx.size(0);
	for (int i0 = 0; i0 < d0; i0++) {
		ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_directory_ + ":",
				r_valid_idx[i0], valid_idx[i0], 0.0001,
				DDTM(" Failed at: valid_idx[" + to_string(i0) + "]"));
	}

	assertion<double>::assert3D(test_directory_, "cam_extrinsics", cam_extrinsics, r_cam_extrinsics, 0.0001);

	assertion<double>::assert3D(test_directory_, "camera_poses", camera_poses, r_camera_poses, 0.0001);

	assertion<double>::assert2D(test_directory_, "world_points", world_points, r_world_points, 0.0001);

}

testHandeyeShah::testHandeyeShah(string test_directory) :
		test_directory_(test_directory) {
}

testHandeyeShah::~testHandeyeShah() {
}

bool testHandeyeShah::readInputMat(string file,
		coder::array<double, 3U> &extrinsics,
		coder::array<double, 3U> &cam_extrinsics) {

	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
	if (pmat == NULL)
		return !data_retrieval;

	data_retrieval &= getArrayData<double, 3U>(pmat, "extrinsics",
			extrinsics);

	data_retrieval &= getArrayData<double, 3U>(pmat, "cam_extrinsics",
			cam_extrinsics);

	return data_retrieval;
}

bool testHandeyeShah::readExpectedOutputMat(string file, double base2grid[4][4],
		double hand_eye_HT[4][4]) {
	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
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

	string input = test_directory_ + "Input-HandeyeShah.mat";
	string output = test_directory_ + "Output-HandeyeShah.mat";

	coder::array<double, 3U> extrinsics;
	coder::array<double, 3U> cam_extrinsics;

	double base2grid[4][4];
	double hand_eye_HT[4][4];
	double time;

	double r_base2grid[4][4];
	double r_hand_eye_HT[4][4];

	if (!testHandeyeShah::readInputMat(input, extrinsics, cam_extrinsics)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	if (!testHandeyeShah::readExpectedOutputMat(output, r_base2grid,
			r_hand_eye_HT)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}
	HandeyeShah(extrinsics, cam_extrinsics, base2grid, hand_eye_HT, &time);
	// Comparing actual outputs vs expected outputs

	for (int i1 = 0; i1 < 4; i1++) {
			for (int i0 = 0; i0 < 4; i0++) {
				ASSERT_EQUAL_DELTA_DDTM(
						"ERROR: Trace back " + test_directory_ + ":",
						r_hand_eye_HT[i0][i1], hand_eye_HT[i0][i1], 0.0001,
						DDTM(" Failed at: hand_eye_HT[" + to_string(i0) + "][" + to_string(i1) + "]"));
			}
		}

	for (int i1 = 0; i1 < 4; i1++) {
		for (int i0 = 0; i0 < 4; i0++) {
			ASSERT_EQUAL_DELTA_DDTM(
					"ERROR: Trace back " + test_directory_ + ":",
					r_base2grid[i0][i1], base2grid[i0][i1], 0.0001,
					DDTM(" Failed at: base2grid[" + to_string(i0) + "][" + to_string(i1) + "]"));
		}
	}



}

testComputeErrors::testComputeErrors(string test_directory) :
		test_directory_(test_directory) {
}

testComputeErrors::~testComputeErrors() {
}

bool testComputeErrors::readInputMat(string file,
		coder::array<double, 3U> &extrinsics, double hand_eye_HT[4][4],
		double base2grid[4][4], coder::array<double, 3U> &cam_extrinsics,
		coder::array<double, 3U> &image_points,
		coder::array<double, 2U> &world_points, double KM[4][3]) {

	// get data flag
	bool data_retrieval = true;

	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
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

bool testComputeErrors::readExpectedOutputMat(string file, double errors[5]) {
	// declaring character array
	char *file_array = new char[file.length() + 1];

	// copying the contents of the
	// string to char array
	strcpy(file_array, file.c_str());

	// open MAT-file
	MATFile *pmat = matOpen(file_array, "r");
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

	string input = test_directory_ + "Input-ComputeErrors.mat";
	string output = test_directory_ + "Output-ComputeErrors.mat";

	coder::array<double, 3U> extrinsics;
	double hand_eye_HT[4][4];
	double base2grid[4][4];
	coder::array<double, 3U> cam_extrinsics;
	coder::array<double, 3U> image_points;
	coder::array<double, 2U> world_points;

	double KM[4][3];
	double errors[3];
	double r_errors[3];

	if (!testComputeErrors::readInputMat(input, extrinsics, hand_eye_HT,
			base2grid, cam_extrinsics, image_points, world_points, KM)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read input file!");
	}
	if (!testComputeErrors::readExpectedOutputMat(output, r_errors)) {
		FAILM("ERROR: " + test_directory_ + ": " + "Cannot read output file!");
	}
	computeErrors(extrinsics, hand_eye_HT, base2grid, cam_extrinsics,
			image_points, world_points, KM, errors);

	// Comparing actual outputs vs expected outputs

	for (int i0 = 0; i0 < 3; i0++) {
		ASSERT_EQUAL_DELTA_DDTM("ERROR: Trace back " + test_directory_ + ":",
				r_errors[i0], errors[i0], 0.0001,
				DDTM(" Failed at: errors[" + to_string(i0) + "]"));
	}

}

