% Changed for 1 camera
function [cost] = CalculateCost(calib, options, refCalibration, genPoints, detPoints)

[CameraParameters, PatternPositions] = unserializeCalib(calib, options, refCalibration);

cameraParams= CameraParameters;
RTpnc1 = PatternPositions;

cost = zeros(numel(RTpnc1)*size(genPoints,1),1);
RTcnc1 = eye(4,4);

    for n = 1: numel(RTpnc1) % for each image
 
        points = detPoints(:,2*1-1:2*1,n);
        
        rR = RTcnc1(1:3, 1:3);
        rt = RTcnc1(4, 1:3)';
        Rext =RTpnc1{n}(1:3, 1:3);
        text = RTpnc1{n}(4, 1:3)';
        
        K = cameraParams.IntrinsicMatrix;
        
        if (all(isnan(points(:))) == 0 & all(all(Rext))~=0)
            
            R = Rext*rR;
            t = (rt +rR'*text)';
            
            
            cameraMatrix = [R; t(:)'] * K;
            r_dist = cameraParams.RadialDistortion;
            t_dist = cameraParams.TangentialDistortion;
            
            projectedPointsraw = [genPoints ones(size(genPoints, 1), 1)] * cameraMatrix;
            
            projectedPointsnorm = bsxfun(@rdivide, projectedPointsraw(:, 1:2), projectedPointsraw(:, 3));
            
            distortedPoints = vision.internal.calibration.distortPoints(projectedPointsnorm, K, r_dist, t_dist);
            
        
            difference = (distortedPoints - points);
            error = sqrt(sum((difference).^2, 2));
            count = size(error,1);
            cost((n-1)*count+1:n*count) = error;
            
         
        end
    end

end