   
% 1. Get constellation model
% 2. Detect image points
% 3. Estimate pose

% Corresponds with API definition
function [ imagePoints, targetPoseCamera, targetPoseRobot, confidence ] = estimatePose(...
                    inputimage, ...
                    robotpose, ...
                    constellation_json_string, ...
                    camParam, ...
                    handeye, ...
                    algorithmparameters_json_string) ...


% 1. EXAMPLE: worldpts = generateCheckerboardPoints([10 10], 10); 
worldpts = jsondecode( constellation_json_string)

% 2. EXAMPLE: imagePoints = detectCheckerboardPoints(inputimage);
% In Matlab
imagePoints = readDetected(worldpts) % In the Matlab implementation, reads what the c-program has written
% In C
imagePoints = detectPitag(worldpts, img, constellation_json_string, algorithmparameters_json_string) % This is the c-function for the API implementation

% 3. EXAMPLE: [R, t] = extrinsics(imgpts, worldpts, cameraParameters);
targetPoseCamera = estimatePitagPose( imagePoints, worldpts, camParam); 


targetPoseRobot = robotpose * handeye * targetPoseCamera;

confidence = ? % Ihtisham, any good ideas? :) Reprojection error of some sort...?

