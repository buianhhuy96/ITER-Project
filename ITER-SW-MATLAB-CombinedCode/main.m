
%% Load ITER library
addpath ('./shared/');
addpath ('./calibrateCamera/');
addpath ('./calibrateHandeye/');
addpath ('./computeCalibrationPoses/');
addpath ('./estimatePoseReflective/');
addpath ('./matlab_pose/');
% First is calibrate_Camera, second is calibrate_Handeye
executed_API = logical([0; 0; 0; 0; 1]);

%% Calibrate Camera
if (executed_API(1))
    %%  Load Calibration Images
clearvars -except executed_API camera_params;
addpath ('./calibrateCamera/auxiliaries/');
%% Replace with own values
% Change to calibration image directory

%set dataset info
% Step 1: Choose Dataset
% CS_synthetic_1 has 15 images
% kuka_2 has 28 images
% TestSet has 15 images
DatasetName='CS_synthetic_1'; % CS_synthetic_1,'kuka_2', 'TestSet' NOTE: %d should be replaced with the dataset number
image_path=['.\calibrateCamera\Datasets\',DatasetName,'\'];


%% Load Images


images=LoadImages(image_path);
if (strcmp(DatasetName,'TestSet'))
square_size = 0.025;  % in units of 'meters'
board_size = int32([18,29]);
elseif (strcmp(DatasetName,'CS_synthetic_1'))
square_size = 0.2000;  % in units of 'meters'
board_size = int32([7,10]);
elseif (strcmp(DatasetName,'kuka_2'))
square_size = 0.0150;  % in units of 'meters'
board_size = int32([18,25]);
elseif (strcmp(DatasetName,'CalibTest'))
square_size = 0.0250;  % in units of 'meters'
board_size = int32([18,25]);
end

% Step 2: Choose valid images to create test cases
number_of_images = size(images,4);
% valid images: 1,2,3,...
valid = true(number_of_images,1);

images=images(:,:,:,valid);

save('Input-CameraCalibration.mat','images','square_size', 'board_size');
save('Input-preprocessImages.mat','images');
images = preprocessImages(images,toStruct(cameraParameters),false);
save('Output-preprocessImages.mat','images');

save('Input-calibrateCamera.mat','images','square_size', 'board_size');
[camera_params, errorOptimized, MREf, valid_idx, err] = calibrateOneCamera(images, square_size, board_size);
if (err == 0)
save('Output-calibrateCamera.mat','camera_params','errorOptimized','MREf','valid_idx','err');
save('Output-CameraCalibration.mat','camera_params','errorOptimized','MREf','valid_idx','err');
end
end

%% Calibrate Handeye
if (executed_API(2))

%clearvars -except executed_API; close all;
%% Loading input data, not to be QA'd

%set dataset info
DatasetName='kuka_2_1'; % CS_synthetic_1,'kuka_2'     NOTE: %d should be replaced with the dataset number
image_path=['.\calibrateHandeye\Datasets\',DatasetName,'\'];
image_path2=['.\calibrateHandeye\Datasets\','kuka_3','\'];
if strcmp(DatasetName(1:end-1),'CS_synthetic_')
    GT_hand2eye=[1 0 0 0;    0 -1 0 0;   0.0001 0.0001 -1 0;    0 0 0 1]; % ground truth hand eye pose (4x4 matrix) to compare, if exist,otherwise []
    square_size=0.2; % in meters.  For  CS_synthetic_1=0.2
else
    GT_hand2eye=[]; 
    square_size=0.015; % in meters.  For kuka_2 =0.015 
end

% Load camera parameters
load(['.\calibrateHandeye\Datasets\',DatasetName,'\CameraParameters.mat']);

% Load undistorted Images
images=LoadImages(image_path);
images2 = LoadImages(image_path2);
%valid_idx = logical([0,0,0,0,0,1,1,1,1,1,1,1,1,1,1])';
valid_idx = true(size(images,4),1);

camera_params = toStruct(cameraParameters('RadialDistortion',cameraParams.RadialDistortion, ...
                                        'TangentialDistortion',cameraParams.TangentialDistortion, ...
                                        'ImageSize',cameraParams.ImageSize, ...
                                        'WorldUnits',cameraParams.WorldUnits, ...
                                        'EstimateSkew',cameraParams.EstimateSkew, ...
                                        'NumRadialDistortionCoefficients',cameraParams.NumRadialDistortionCoefficients, ...
                                        'EstimateTangentialDistortion',cameraParams.EstimateTangentialDistortion, ...
                                        'IntrinsicMatrix',cameraParams.IntrinsicMatrix));

% Load robot poses
robotPosesVec=dlmread(['.\calibrateHandeye\Datasets\',DatasetName,'\RobotPosesVec.txt']);
for i=1:size(robotPosesVec,1)
    robot_poses(:,:,i)=reshape(robotPosesVec(i,:),4,[])';
end

images = images(:,:,:,valid_idx);
robot_poses = robot_poses(:,:,valid_idx);
%images = images(:,:,:,1:5);
%images2 = images2(:,:,:,1:5);
save("Input.mat","images","camera_params","robot_poses","square_size");

% Undistord images
save('Input-preprocessImages.mat','images','camera_params');
images = uint8(preprocessImages(images, camera_params, true));
save('Output-preprocessImages.mat','images');

save('Input-RobotPoses.mat','robot_poses','valid_idx');
[poses,extrinsics]=readRobotPoses(robot_poses);
save('Output-RobotPoses.mat','poses','extrinsics');

%% Library functionality starts here
% Compute Camera extrinsics 
save('Input-ComputeCamExtrinsics.mat','images','square_size','camera_params');
[image_points, valid_idx, cam_extrinsics, camera_poses, world_points, err] = ComputeCamExtrinsics(images, square_size, camera_params);

if (err ~= 0)
    error("ComputeCamExtrinsics error");
else
    save('Output-ComputeCamExtrinsics.mat','image_points','valid_idx','cam_extrinsics','camera_poses','world_points','err');
end
%}
% Compute hand-eye- transformation (AX=ZB)
save('Input-HandeyeShah.mat','extrinsics','cam_extrinsics');
[base2grid,hand_eye_HT, err] = HandeyeShah(extrinsics,cam_extrinsics) ; 
if (err ~= 0)
    error("HandeyeShah error");
else
    save('Output-HandeyeShah.mat','base2grid','hand_eye_HT');
end
% Computing Errors
% This should be reduced to only errors which can be computed without
% ground truth

KM=[cameraParams.IntrinsicMatrix' [0;0;0]];% matlabs interpretation of intrinsic matrix is different than general approach
save('Input-ComputeErrors.mat','extrinsics','hand_eye_HT','base2grid','cam_extrinsics','image_points','world_points','KM');
[errors]=computeErrors(extrinsics,hand_eye_HT,base2grid,cam_extrinsics,image_points,world_points,KM);

save('Output-ComputeErrors.mat','errors');

save("Output.mat","hand_eye_HT","errors");
fprintf('\n Rerr(deg): %f \n terr(mm): %f \n reproj_px: %f \n', errors(1),errors(2)*1000,errors(3));

end

if (executed_API(3))
   % clearvars -except executed_API






f = 1056/3; cx = 1200/6; cy = 1920/6;
K = [[f,0,0];[0,f,0];[cy, cx, 1]];
factoryCamParam = toStruct(cameraParameters('IntrinsicMatrix',K,'ImageSize',[1 1]));
factoryCamParam = rmfield(factoryCamParam,'DetectedKeypoints');
factoryCamParam = rmfield(factoryCamParam,'WorldPoints');
factoryCamParam = rmfield(factoryCamParam,'RotationVectors');
factoryCamParam = rmfield(factoryCamParam,'TranslationVectors');
factoryCamParam = rmfield(factoryCamParam,'ReprojectionErrors');
initialImage = imread ('.\computeCalibrationPoses\exampleIMG.bmp');

squareSize = 0.015;
boardSize = int32([18,25]); 

DatasetName='kuka_2'; % CS_synthetic_1,'kuka_2'     NOTE: %d should be replaced with the dataset number
image_path=['.\calibrateCamera\Datasets\',DatasetName,'\'];
load(['.\calibrateCamera\Datasets\',DatasetName,'\CameraParameters.mat']);
images=LoadImages(image_path);
dirr = dir('D:\eclipse-workspace\Handeye_Calibration_2.0\TestData\Unit_Test\computeCalibrationPoses');

if (strcmp(DatasetName,'TestSet'))
squareSize = 0.025;  % in units of 'meters'
boardSize = int32([18,29]);
elseif (strcmp(DatasetName,'CS_synthetic_1'))
squareSize = 0.2000;  % in units of 'meters'
boardSize = int32([7,10]);
elseif (strcmp(DatasetName,'kuka_2'))
squareSize = 0.0150;  % in units of 'meters'
boardSize = int32([18,25]);
elseif (strcmp(DatasetName,'CalibTest'))
squareSize = 0.0250;  % in units of 'meters'
boardSize = int32([18,25]);
end

handEyeEstimate = RTtoTransform(rotz(180)*roty(0)*rotx(0),[100,100,-160]);

% Convert robot output to float4X4 matrix
R12= eul2rotm([150,-20,-60], 'ZYX')';
T12= [80,-1700,530];
initialRobotPose= RTtoTransform(R12, T12);

angularBounds = repmat([-10;10],[1, 3]);
roughDistance = 700;
requestedNumPoses = int32([3 3 5]);

validPoses = isT(initialRobotPose);

save("Input-computeCPoses.mat","initialImage","initialRobotPose","handEyeEstimate","roughDistance","angularBounds","squareSize","boardSize","factoryCamParam","requestedNumPoses");
[robotPoses, err] = computeCalibrationPoses_internal(initialImage, initialRobotPose, handEyeEstimate, roughDistance, angularBounds, squareSize, boardSize, factoryCamParam, requestedNumPoses);
save("Output-computeCPoses.mat","robotPoses","err");

end

if (executed_API(4))
load('.\matlab_pose\CamParameters_vga.mat')
seq='_1';
dataAddPI=['.\matlab_pose\seq1\seq',seq,'\'];
imagePoints=readImagePoints(dataAddPI)
images = LoadImages('.\matlab_pose\seq1\seq_2\');

%% PITAG

robotPose = eye(4);
handeye = eye(4);
% Tags Initialization
scale=[66.0723];%66.0723 
%dataAddPIL=[dataAddPI,'\']
Tag1Model.l0.AB=0.35; Tag1Model.l0.AC=0.60; Tag1Model.l1.AB=0.25; Tag1Model.l1.AC=0.70;

% Tag World Points
CrossRatioLine0_L1.AB=Tag1Model.l0.AB; CrossRatioLine0_L1.AC=Tag1Model.l0.AC;
CrossRatioLine1_L1.AB=Tag1Model.l1.AB; CrossRatioLine1_L1.AC=Tag1Model.l1.AC;
worldPts=[0,0;   CrossRatioLine0_L1.AB,0;   CrossRatioLine0_L1.AC,0;   1,0;... 
                   1,CrossRatioLine1_L1.AB;   1,CrossRatioLine1_L1.AC;   1,1; ...
            	   CrossRatioLine1_L1.AC,1;   CrossRatioLine1_L1.AB,1;   0,1; ...
                   0,CrossRatioLine0_L1.AC;   0,CrossRatioLine0_L1.AB  ]*scale;

%estimate pose
cameraParams = toStruct(cameraParams);
% inputImage is read manually and imagePoints will be chosen to match the
% image
% inputImage = imread(...);
imagePoints = imagePoints(:,:,1);
%save("Input-PoseEstimation.mat","inputImage","robotPose","handeye","cameraParams");
save("Input-estimatePitagPose.mat","imagePoints","robotPose","worldPts","handeye","cameraParams");

[poseCamera, poseRobot]=estimatePitagPose(imagePoints, robotPose, worldPts, handeye, cameraParams);
confidence = sum(any(imagePoints,2))/size(worldPts,1);
imagePoints = imagePoints(any(imagePoints,2),:);
save("Output-estimatePitagPose.mat","poseCamera","poseRobot");
save("Output-PoseEstimation.mat","imagePoints","poseCamera","poseRobot","confidence");
end


if (executed_API(5))
    clear all; close all;
% Inputs
directoryRoot = 'estimatePoseReflective\In Lab V6\';
directory = 'estimatePoseReflective\In Lab V6\Knuckle\';
files = struct2cell(dir([directory,'date*']));

for n = 1:50
fprintf("n = %d; \n",n)
ImgVGA = imread([directory, files{1,n}]);

% Setup Params
params.minArea = 10;
params.maxArea = 200;
params.ThresholdDelta = 4.0;

% Camera Parameters - Real Data
load ([directoryRoot,'HandEye\cameraParams.mat']);
intrinsics = cameraParams;
K = intrinsics.IntrinsicMatrix;

% Actual Implementation
% Candidate Generation
[ImgVGAUndist,newOrigin] = undistortImage(ImgVGA,cameraParams);
ImgVGA = ImgVGAUndist;

image = ImgVGAUndist;
minArea = params.minArea;
maxArea = params.maxArea;
ThresholdDelta = params.ThresholdDelta;
save('Input-RRDetectionKnuckle.mat','image','minArea',"maxArea","ThresholdDelta","K");
[markerCentroidsOrdered] =  RRDetectionKnuckle(image, params, K);
save('Output-RRDetectionKnuckle.mat','markerCentroidsOrdered');

%save('Input-estimatePose.mat','markerCentroidsOrdered');
cameraParams = toStruct(cameraParams);
worldPoints = [35.2562210880816,72.5554786100645,0;28.0603663023432,232.262285096071,0;23.2887388570091,309.676692896166,0;-56.5990827609301,66.9572681843282,0;-56.9389781150676,307.144770747125,0];
[RT34est, finalMRE, err] = estimateKnucklePose(markerCentroidsOrdered, worldPoints, cameraParams);
[RT34est_r, finalMRE_r, err_r] = estimateKnucklePose_orig(markerCentroidsOrdered, worldPoints, cameraParams);

if (any(abs(RT34est - RT34est_r) > ones(4,4)*0.001,'all'))
   disp("test failed");

    for i=1:4
        for j=1:4
            fprintf('RT34est(%d,%d) = %f; \n',i,j,RT34est(i,j)-RT34est_r(i,j));
        
        end
    end
   continue;
end
fprintf('finalMRE = %f || %f; \n',finalMRE,finalMRE_r);

if (err)
    fprintf('Size: ImagePoint = %d; \n Error = %d; \n',size(markerCentroidsOrdered,1),err)
end
%{
if (true)
    f = figure;

    imshow(image);
    hold on

    plot (markerCentroidsOrdered(:,1),markerCentroidsOrdered(:,2), 'g', 'LineWidth', 1);

    for mk=1:size(markerCentroidsOrdered,1)
        scatter (markerCentroidsOrdered(mk,1), markerCentroidsOrdered(mk,2), 25,'gx');
        text(markerCentroidsOrdered(mk,1)-23, markerCentroidsOrdered(mk,2)-7, ['#',num2str(mk)],'Color', 'white', 'FontSize', 10);
    end

    hold off;
end
%}
%exportgraphics(f,'C:\Users\ribeirol\TUNI.fi\TG-3DMedia-F4E-GRT - General\Grant 3.0\General\PR photos\RR Knuckle Detected.png','BackgroundColor','none');
%copygraphics(f,'BackgroundColor','none');

end
end