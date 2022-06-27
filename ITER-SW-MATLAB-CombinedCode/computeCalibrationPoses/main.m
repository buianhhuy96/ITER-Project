roughDistance = 700;
squareSize = 15;
boardSize = int32([18,25]); 
f = 1056/3; cx = 1200/6; cy = 1920/6;
K = [[f,0,0];[0,f,0];[cy, cx, 1]];
factoryCamParam = toStruct(cameraParameters('IntrinsicMatrix',K,'ImageSize',[1 1]));
factoryCamParam = rmfield(factoryCamParam,'DetectedKeypoints');
factoryCamParam = rmfield(factoryCamParam,'WorldPoints');
factoryCamParam = rmfield(factoryCamParam,'RotationVectors');
factoryCamParam = rmfield(factoryCamParam,'TranslationVectors');
factoryCamParam = rmfield(factoryCamParam,'ReprojectionErrors');

handEyeEstimate = RTtoTransform(rotz(180)*roty(0)*rotx(0),[100,100,-160]);

% Convert robot output to float4X4 matrix
R12= eul2rotm([150,-20,-60], 'ZYX')';
T12= [80,-1700,530];
initialRobotPose= RTtoTransform(R12, T12);

angularBounds = repmat([-10,10],[3, 1]);
requestedNumPoses = int32(3);
initialImage = imread ('.\exampleIMG.bmp');
%
[robotPoses, err] = computeCalibrationPoses_internal(initialImage, initialRobotPose, handEyeEstimate, roughDistance, angularBounds, squareSize, boardSize, factoryCamParam, requestedNumPoses);
if (err ~= 0)
    a = 1;
end