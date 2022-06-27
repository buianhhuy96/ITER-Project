function [poseCamera, poseRobot]=estimatePitagPose(imagePoints, robotpose, worldpts, handeye, cameraParams)

%initialize


poseCamera = zeros(4,4);
rotationMatrix = zeros(3,3);
translationVector = zeros(1,3);
validPoints = any(imagePoints,2);
validImagePoints = imagePoints(validPoints,:);
validWorldPoints = worldpts(validPoints,:);
cameraParams = cameraParameters(cameraParams);
% Estimate extrinsics and optimise results per sample
    
    
%compute the extrinsic
[rotationMatrix, translationVector] = extrinsics(validImagePoints,validWorldPoints,cameraParams);
    
% Optimize the extrinsic
init=createHT(inv(rotationMatrix),translationVector);
K=cameraParams.IntrinsicMatrix;K=[K' [0;0;0]];  
wpts4=[validWorldPoints ,repmat([0 1],size(validWorldPoints,1),1) ] ;
poseCamera=optimizeCamPose(init,validImagePoints,K,wpts4);
poseRobot = robotpose*handeye*poseCamera;
end