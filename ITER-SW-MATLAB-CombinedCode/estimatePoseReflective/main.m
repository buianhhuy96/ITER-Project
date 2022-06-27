clear all; close all;
% Inputs
directoryRoot = 'In Lab V6\';
directory = 'In Lab V6\Knuckle\';
files = struct2cell(dir([directory,'date*']));

n =1;
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

[markerCentroidsOrdered] =  RRDetectionKnuckle(ImgVGA, params, K);


%%
if (true)
    f = figure;

    imshow(ImgVGA);
    hold on

    plot (markerCentroidsOrdered(:,1),markerCentroidsOrdered(:,2), 'g', 'LineWidth', 1);

    for mk=1:size(markerCentroidsOrdered,1)
        scatter (markerCentroidsOrdered(mk,1), markerCentroidsOrdered(mk,2), 25,'gx');
        text(markerCentroidsOrdered(mk,1)-23, markerCentroidsOrdered(mk,2)-7, ['#',num2str(mk)],'Color', 'white', 'FontSize', 10);
    end

    hold off;
end

%exportgraphics(f,'C:\Users\ribeirol\TUNI.fi\TG-3DMedia-F4E-GRT - General\Grant 3.0\General\PR photos\RR Knuckle Detected.png','BackgroundColor','none');
%copygraphics(f,'BackgroundColor','none');

