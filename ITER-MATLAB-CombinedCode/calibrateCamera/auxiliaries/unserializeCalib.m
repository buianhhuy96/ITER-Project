        function [CameraParameters,PatternPositions] = unserializeCalib(x, options, refCalibration)
        numCams = numel(refCalibration.CameraParameters);
        
        % Start with original values. Overwrite if changed.
        %newCalibration=refCalibration;
        %RTcnc1 = refCalibration.Extrinsics;
        RTpnc1 = refCalibration.PatternPositions;
        %options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
        camLength = 0;
            if (~options(1))
                K = [[x(camLength+1),0,0];[0,x(camLength+2),0];[x(camLength+3),x(camLength+4),1]];
                camLength = camLength+4;
            else 
                K = refCalibration.CameraParameters.IntrinsicMatrix;
            end
            if (~options(2))
                radialCoeffs = [x(camLength+1), x(camLength+2), x(camLength+3)];
                camLength = camLength+3;
            else
                radialCoeffs = refCalibration.CameraParameters.RadialDistortion;
            end
            CameraParameters = toStruct(cameraParameters('IntrinsicMatrix', K, ...
                'RadialDistortion', radialCoeffs,  'NumRadialDistortionCoefficients', 3, 'ImageSize', refCalibration.CameraParameters.ImageSize));
            %{
            newCalibration.CameraParameters.IntrinsicMatrix = K;
            newCalibration.CameraParameters.FocalLength = [K(1, 1) K(2, 2)];
            newCalibration.CameraParameters.PrincipalPoint = [K(3, 1) K(3, 2)];
            newCalibration.CameraParameters.Skew = K(2, 1);
            newCalibration.CameraParameters.RadialDistortion = radialCoeffs;
            newCalibration.CameraParameters.NumRadialDistortionCoefficients = 3;
            %}
        if (~options(3))
            rotationVector = zeros(3,1);
            t = zeros(3,1);
            for i=0:numel(RTpnc1)-1
                rotationVector = x(camLength+1:camLength+3);
                t = x(camLength+4: camLength+6);
                RTpnc1{i+1} = RTtoTransform(rotationVectorToMatrix (rotationVector), t);
                camLength = camLength +6;
            end
        end
        

        %numel(x);
        %newCalibration.Extrinsics = RTcnc1;
        %newCalibration.PatternPositions = RTpnc1;
        PatternPositions = RTpnc1;
        end
