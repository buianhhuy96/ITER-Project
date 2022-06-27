function [HT]=optimizeCamPose(W2Cam_initial,undist_imgMarkerPts,K11,MarkerPts)


%% optimizer options
% options.Algorithm = 'levenberg-marquardt';
% options.ScaleProblem='jacobian';
% options.Display='off';
options = optimoptions('fmincon','Algorithm','sqp','MaxFunctionEvaluations',2500);% use :'interior-point' , if not generating C code, gives better results

%% Create World Points
WptsTrio=MarkerPts';

%% Define Function and optimize
    cF1 = @(est) costFunc1(undist_imgMarkerPts,double(WptsTrio),K11,est);

    x1=[0 0 0 0 0 0 0];%dummy initialization 
    x0 = [rotm2quat(W2Cam_initial(1:3,1:3)) W2Cam_initial(1:3,4)'];
    lb = -ones(size(x0))*realmax;
    ub = ones(size(x0))*realmax;
    XR=eye(3);Xt=zeros(1,3);
    [x1] = fmincon(cF1,x0,[],[],[],[],lb,ub,[],options);
    
    XR=quat2rotm(x1(1:4));
    Xt=x1(5:7);
    
    HT=createHT(XR,Xt);
