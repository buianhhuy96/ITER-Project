addpath ('./auxiliaries/');
addpath ('../shared/');
%% Replace with own values
% Change to calibration image directory


%set dataset info
% Step 1: Choose Dataset
% CS_synthetic_1 has 15 images
% kuka_2 has 28 images
% TestSet has 15 images
DatasetName='CS_synthetic_1'; % CS_synthetic_1,'kuka_2', 'TestSet' NOTE: %d should be replaced with the dataset number
image_path=[pwd,'\Datasets\',DatasetName,'\'];


%% Load Images


%images=LoadImages(image_path);
load("temp.mat");
if (strcmp(DatasetName,'TestSet'))
square_size = 0.025;  % in units of 'meters'
board_size = int32([18,29]);
elseif (strcmp(DatasetName,'CS_synthetic_1'))
square_size = 0.2000;  % in units of 'meters'
board_size = int32([7,10]);
elseif (strcmp(DatasetName,'kuka_2'))
square_size = 0.0150;  % in units of 'meters'
board_size = int32([18,25]);
end

% Step 2: Choose valid images
number_of_images = size(images,4);
valid = true(number_of_images,1);
% valid images: 1,2,3,...
%valid = [1,1,1,1,1,1,1,1,1,1];

images=images(:,:,:,valid);

save('Input.mat','images','square_size', 'board_size');
save('Input-preprocessImages.mat','images');
images = preprocessImages(images,toStruct(cameraParameters),false);
save('Output-preprocessImages.mat','images');

save('Input-calibrateCamera.mat','images','square_size', 'board_size');
[camera_params, errorOptimized, MREf, valid_idx, err] = calibrateOneCamera_v2(images, square_size, board_size);
save('Output-calibrateCamera.mat','camera_params','errorOptimized','MREf','valid_idx','err');
save('Output.mat','camera_params','errorOptimized','MREf','valid_idx','err');