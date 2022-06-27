%%Calculates reprojection error. One camera. 
function [error] = calculateReprErr(RT34serial,detPoints, genPoints, stereoParams)

genPoints = cat(2,genPoints,zeros(5,1));
T = RT34serial(1:3);
R = vision.internal.calibration.rodriguesVectorToMatrix(RT34serial(4:6));

RT34 = RTtoTransform(R, T);


R = RT34(1:3, 1:3);
t = RT34(4, 1:3)';

projectedPoints_Cam1 = worldToImage(stereoParams, R, t, genPoints);
%diff = projectedPoints_Cam1-detPoints(:,:);
error = abs(projectedPoints_Cam1-detPoints(:,:));
end