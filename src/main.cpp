
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "calibrateHandEye.h"
#include "linalg.h"
#include "mat.h"
#include "Test.h"


void readRobotPosesMat(string file, std::vector<aliases::float4x4> &v)
{
  // declaring character array
  char *file_array = new char[file.length() + 1];

  // copying the contents of the
  // string to char array
  strcpy(file_array, file.c_str());

  // open MAT-file
  MATFile *pmat = matOpen(file_array, "r");
  if (pmat == NULL)
    return;

  // extract the specified variable
  mxArray *arr = matGetVariable(pmat, "robotPoses");
  if (arr != NULL && !mxIsEmpty(arr)) {
    // copy data
    mwSize num = mxGetNumberOfElements(arr);
    double *pr = mxGetPr(arr);
    if (pr != NULL) {
      v.reserve(num); // is faster than resize :-)
      for (mwSize i = 0; i < num / 16; i++) {
        float4x4 pose;
        for (int j = 0; j < 4; j++) {
          float4 row{
              (float)*(pr + i * 16 + j * 4), (float)*(pr + i * 16 + j * 4 + 1),
              (float)*(pr + i * 16 + j * 4 + 2), (float)*(pr + i * 16 + j * 4 + 3)};
          pose[j] = row;
        }
        v.push_back(pose);
      }
    }
  }
}

void readCamParams(calibrationPatternParameters &calibPatternParam,
                      intrinsicParameters &camParam)
{
  calibPatternParam = {0.2, 1, 1};
  camParam = {{1079.922655625781, 1079.922655625781},                    // float2 focalLength;
              {960.6710724316486, 540.5455583795550},              // float2 principalPoint;
              {0.00004598307440515076, 0.00002588946184255906},         // float2 distortionsTangential;
              {-0.0002345631252071725, 0.0003393549810198432, -0.0002768876560200020},         // float3 distortionsRadial;
              0.037107823315083,        // float reprojectionError;
              15};                              // int numUsedImages;
}

void readImages(string file, std::vector<imageWrap> &Image, const int width, int height, int channel)
{
  // declaring character array
  char *file_array = new char[file.length() + 1];

  // copying the contents of the
  // string to char array
  strcpy(file_array, file.c_str());

  // open MAT-file
  MATFile *pmat = matOpen(file_array, "r");
  if (pmat == NULL)
    return;

  // extract the specified variable
  mxArray *arr = matGetVariable(pmat, "images");
  if (arr != NULL && !mxIsEmpty(arr)) {
    // copy data
    mwSize num = mxGetNumberOfElements(arr);
    unsigned char *pr = (unsigned char *)mxGetData(arr);
    if (pr != NULL) {

      //v.reserve(num); // is faster than resize :-)
      for (mwSize i = 0; i < num / (width * height * channel); i++) {

        imageWrap image;
        unsigned char *imageData = (unsigned char *)malloc(
            width * height * 3 * sizeof(unsigned char));
        image.width = width;
        image.height = height;
        image.numChannels = channel;

        for (int c = 0; c < 3; c++) {
            for (int w = 0; w < width; w++) {
                for (int h = 0; h < height; h++) {
                    (imageData[c + channel * w + width * channel * h]) =
                        *(pr);
                    if (channel == 3)
                     pr++;
                }
                if (channel < 3)
                    pr++;
            }
        }
        image.imageData = imageData;
        Image.push_back(image);
      }
    }
  }

}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	// Add test cases
	std::vector<string> test_cases = get_directories(test_directory);
	for (auto test_case : test_cases) {
		testReadRobotPoses test_read_robot_poses(test_case);
		testComputeCamExtrinsics test_compute_cam_extrinsics(test_case);
		testHandeyeShah test_handeye_shah(test_case);
		testComputeErrors test_compute_errors(test_case);

		s.push_back((test_read_robot_poses));
		s.push_back((test_compute_cam_extrinsics));
		s.push_back((test_handeye_shah));
		s.push_back((test_compute_errors));
	}
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

#define TEST

#ifdef TEST

int main(int argc, char const *argv[]) {

	std::cout << "Test starts" << std::endl;
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

#else


int main(void)
{
  string directory = "Dataset\\CS_synthetic_1\\";
  string robotPosesMat = "RobotPosesT.mat";
  string imagesMat = "Images.mat";
  std::vector<aliases::float4x4> robotPosesVec;

  calibrationPatternParameters calibPatternParam;
  intrinsicParameters camParam;
  readCamParams(calibPatternParam, camParam);

  std::vector<imageWrap> Images;

  float4x4 handEyeCalibration;
  int usedImages;
  float reprojectionError;
  float rotationError;
  float translationError;
  std::cout << "Function starts" << std::endl;
  // Load robot poses from file
  readRobotPosesMat(directory + robotPosesMat, robotPosesVec);

  // Load input images
  readImages(directory + imagesMat, Images, 1920, 1080, 3);

  calibrateHandEye(Images,
                    robotPosesVec,
                   calibPatternParam,
                   camParam,

                   handEyeCalibration, usedImages,
                   reprojectionError, rotationError,
                   translationError);



  std::cout << "reprojectionError: " << reprojectionError << std::endl;
  std::cout << "rotationError: " << rotationError << std::endl;
  std::cout << "translationError: " << translationError << std::endl;
  std::cout << "Function ends" << std::endl;
  return 0;
}

#endif
