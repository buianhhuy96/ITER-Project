function images=LoadImages(calibImgPath)

% Get Image names
fileList = [dir(fullfile(calibImgPath,'*png')); dir(fullfile(calibImgPath,'*jpg'));dir(fullfile(calibImgPath,'*bmp')); dir(fullfile(calibImgPath,'*tiff'))];
calibImgNames = extractfield(fileList,'name');
calibImgFullname=strcat(calibImgPath,calibImgNames);

for i=1:length(calibImgFullname)
    images(:,:,:,i)=imread([calibImgPath,'\',calibImgNames{i}]);
end