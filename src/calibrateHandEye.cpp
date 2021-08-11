#include "calibrateHandEye.h"


void generateCamParamStruct(const calibrationPatternParameters &calibPatternParam, const intrinsicParameters &camParam,
							 struct0_T &cameraParams)
{
	// Radial Distortion
	cameraParams.RadialDistortion[0] = camParam.distortionsRadial.x;
	cameraParams.RadialDistortion[1] = camParam.distortionsRadial.y;
	cameraParams.RadialDistortion[2] = camParam.distortionsRadial.z;
	
	// Tangential Distortion
	cameraParams.TangentialDistortion[0] = camParam.distortionsTangential.x;
	cameraParams.TangentialDistortion[1] = camParam.distortionsTangential.y;
	
	// ImageSize - Not required in this API
	cameraParams.ImageSize[0] = 0;
	cameraParams.ImageSize[1] = 0;

	// World Points - Not required in this API
	cameraParams.WorldPoints.set_size(1,2);
	cameraParams.WorldPoints[0] = 0;
	cameraParams.WorldPoints[1] = 0;
	
	// World Units - Not required in this API
	cameraParams.WorldUnits = 0;
    
	// Estimate Skew - Not required in this API
	cameraParams.EstimateSkew = 0;
	
	// Num Radial Distortion Coefficients - Not required in this API
	cameraParams.NumRadialDistortionCoefficients = 0;
	
	// Estimate Tangential Distortion - Not required in this API
	cameraParams.EstimateTangentialDistortion = 0;

	// Rotation Vectors - Not required in this API 
	cameraParams.RotationVectors.set_size(1,2);				
	cameraParams.RotationVectors[0] = 0;
	cameraParams.RotationVectors[1] = 0;

    // Translation Vectors - Not required in this API
	cameraParams.TranslationVectors.set_size(1,2);					
	cameraParams.TranslationVectors[0] = 0;
	cameraParams.TranslationVectors[1] = 0;

	// Reprojection Errors - Not required in this API
	cameraParams.ReprojectionErrors.set_size(1,3,1);	
	cameraParams.ReprojectionErrors[0] = 0;
	cameraParams.ReprojectionErrors[1] = 0;
	cameraParams.ReprojectionErrors[2] = 0;
	
	// Intrinsic Matrix
	float focalLengthx = camParam.focalLength[0];
	float focalLengthy = camParam.focalLength[1];

	cameraParams.IntrinsicMatrix[0][0] = focalLengthx;
	cameraParams.IntrinsicMatrix[1][0] = 0;
	cameraParams.IntrinsicMatrix[2][0] = 0;
	cameraParams.IntrinsicMatrix[0][1] = 0;
	cameraParams.IntrinsicMatrix[1][1] = focalLengthy;
	cameraParams.IntrinsicMatrix[2][1] = 0;
	cameraParams.IntrinsicMatrix[0][2] = camParam.principalPoint.x;
	cameraParams.IntrinsicMatrix[1][2] = camParam.principalPoint.y;
	cameraParams.IntrinsicMatrix[2][2] = 1;

	// Detected Keypoints
	cameraParams.DetectedKeypoints.set_size(1,2);				  
	cameraParams.DetectedKeypoints[0] = 0;
	cameraParams.DetectedKeypoints[1] = 0;
}


void convertImages2Array(const std::vector<imageWrap> &ImagesV, coder::array<uint8_T, 4U> &Images)
{
  imageWrap image = ImagesV.front();
  int width = image.width;
  int height = image.height;
  int channel = image.numChannels;
  int numImg = ImagesV.size();
  // Image iterator
  int iImg = 0;
  // Array size heigh x width x channel x num_of_images
  Images.set_size(height, width, channel, numImg);
  for (imageWrap image : ImagesV) {
		unsigned char* imageData = image.imageData;

		for (int iC = 0; iC < channel; iC++) {
			for (int iW = 0; iW < width; iW++) {
				for (int iH = 0; iH < height; iH++) {
                     Images[iH + height * iW + width * height * iC + width * height * channel * iImg] = 
								*(imageData + iC + channel * iW + width * channel * iH);
				}
			}
		}
		iImg++;
	}
}

void convertRobotPoses2Array(const std::vector<float4x4> &robotPosesVec,
                             coder::array<double, 3U> &robotPoses)
{
  int numPoses = robotPosesVec.size();
  robotPoses.set_size(4, 4, numPoses);
  int i2 = 0;
  for (float4x4 pose : robotPosesVec) {
    for (int i1 = 0; i1 < 4; i1++) {
      for (int i0 = 0; i0 < 4; i0++) {
        robotPoses[i0 + (4 * i1) + (16 * i2)] = pose[i1][i0];
      }
    }
    i2++;
  }
}


void calibrateHandEye(const std::vector<imageWrap> &Images, 
					  const std::vector<float4x4> &robotPosesVec,
				      const calibrationPatternParameters &calibPatternParam,
					  const intrinsicParameters &camParam,
					  
					  float4x4 &handEyeCalibration,
					  int &usedImages,
					  float &reprojectionError,
					  float &rotationError,
					  float &translationError)
{
  // Load robot poses
  coder::array<double, 3U> robotPoses;
  coder::array<boolean_T, 2U> validIdx;
  coder::array<double, 3U> Poses;
  coder::array<double, 3U> Extrinsics;	

  int num = robotPosesVec.size();
  validIdx.set_size(1, num);
  for (int i = 0; i < num; i++) {
    validIdx[i] = 1;
  }

  // Compute Camera extrinsics  
  double squareSize = calibPatternParam.squareSize;
  coder::array<uint8_T, 4U> Images_array;
  coder::array<double, 3U> imagePoints;
  coder::array<uint8_T, 4U> validImgz;
  coder::array<bool, 1U> validIdx2;
  coder::array<double, 3U> camExtrinsics;
  coder::array<double, 3U> cameraPoses;
  coder::array<double, 2U> worldPoints;
  struct0_T cameraParams;

  // Handeye Shah 
  double base2grid[4][4];
  double handEyeHT[4][4];
  double time;  

  // Computing Errors
  double errors[5];
  double GT[4][4];
  double KM[4][3];
  

  convertRobotPoses2Array(robotPosesVec, robotPoses);
  convertImages2Array(Images, Images_array);
  generateCamParamStruct(calibPatternParam, camParam, cameraParams);
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      KM[j][k] = cameraParams.IntrinsicMatrix[k][j];
    }
  }
  KM[3][0] = 0;
  KM[3][1] = 0;
  KM[3][2] = 0;
  readRobotPoses(robotPoses, validIdx, 			
							Poses, Extrinsics); 

  ComputeCamExtrinsics(Images_array, squareSize, &cameraParams, 
							imagePoints, validIdx2, camExtrinsics, cameraPoses, worldPoints);

  // Compute hand-eye- transformation (AX=ZB)
  HandeyeShah(Extrinsics, camExtrinsics, 															 
							base2grid, handEyeHT, &time);    
  
 // This should be reduced to only errors which can be computed without
 // ground truth
 
  computeErrors(Extrinsics, handEyeHT, base2grid, camExtrinsics, imagePoints,  worldPoints, KM,
							errors);  

  

 //  Output 							
  rotationError = errors[0];
  translationError = errors[1]*1000;
  reprojectionError = errors[2];
  
  for (int i0 = 0; i0 < 4; i0++){
	for (int i1 = 0; i1 < 4; i1++){
	  handEyeCalibration[i0][i1] = handEyeHT[i0][i1];
	}
  }
							
  
}
