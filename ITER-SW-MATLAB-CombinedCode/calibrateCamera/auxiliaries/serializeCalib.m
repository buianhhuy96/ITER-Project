% Changed for just 1 camera - 1/10/2021
function x = serializeCalib(calibration, options)
cameraParams= calibration.CameraParameters;
%RTcnc1 = calibration.Extrinsics;
RTpnc1 = calibration.PatternPositions;

% options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
x = zeros(0,1);
coder.varsize('x');
% x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
if (~options(1))
    v = [cameraParams.IntrinsicMatrix(1,1); cameraParams.IntrinsicMatrix(2,2); cameraParams.IntrinsicMatrix(3,1); cameraParams.IntrinsicMatrix(3,2)];
    if isempty(x)
        x = v;
    else
        x = cat(1,x,v);
    end
    if cameraParams.EstimateSkew
        x = cat(1,x, cameraParams.IntrinsicMatrix(1,2));
    end
end
if (~options(2))
    v = [cameraParams.RadialDistortion(1:cameraParams.NumRadialDistortionCoefficients)'];
    if isempty(x)
        x = v;
    else
        x = cat(1,x,v);
    end
    if cameraParams.EstimateTangentialDistortion
        x = cat(1,x,cameraParams.TangentialDistortion');
    end
end

% Extrinsics
% x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx; Ty; Tz];

if (~options(3))
    for i=1:numel(RTpnc1)
        rvec = rotationMatrixToVector(RTpnc1{i}(1:3, 1:3));
         if isempty(x)
        x = [rvec(:); RTpnc1{i}(4, 1:3)'];
         else
        x = cat(1,x,[rvec(:); RTpnc1{i}(4, 1:3)']);
         end
    end
    numel(x);
end
end