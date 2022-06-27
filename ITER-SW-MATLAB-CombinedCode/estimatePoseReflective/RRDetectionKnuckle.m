function [markerCentroidsOrdered] =  RRDetectionKnuckle(ImgVGA, params, K)
minNumMarkers =3;
numExpectedMarkers = 5;

% Detect MSER
[regions] = detectMSERFeatures(ImgVGA, 'RegionAreaRange', [params.minArea, params.maxArea], 'ThresholdDelta',params.ThresholdDelta);

if (coder.target('MATLAB')) %true if running from Matlab. To false if coder runs it.
    % Converting Matlab to Coder Output
    regionsCoder.PixelList = cell2mat (regions.PixelList);
    lengths = cell2mat(cellfun(@size,regions.PixelList,'uni',false));
    regionsCoder.Lengths = lengths(:,1);
    regions = regionsCoder;
end

% Group Overlappign Regions
uniqueRegions = groupOverlapRegions(regions, ImgVGA);

candidates = uniqueRegions.PixelList;

BWImg = false(size(ImgVGA));
BWImg(sub2ind(size(ImgVGA),candidates(:,2), candidates(:,1))) = true;
%figure; imshow (BWImg, []);

% Filtering Candidates
stats = regionprops(BWImg, 'Area', 'Circularity', 'Extent', 'BoundingBox', 'PixelList');
stats_grey = regionprops(BWImg,ImgVGA, 'MinIntensity', 'MeanIntensity', 'MaxIntensity', 'WeightedCentroid');

properties = NaN(size(stats,1), 8);
properties(:,1) = [stats.Area];
properties(:,1) = properties(:,1)./params.maxArea;
%properties(:,1) = [stats.Area]./mean([stats.Area]);

properties(:,2) = [stats.Circularity]; %(4*Area*pi)/(Perimeter2)
%properties(:,3) = [stats.Solidity]; % Area/ConvexArea
properties(:,4) = [stats.Extent]; % Area/ bounding box Area
properties(:,5) = [stats_grey.MeanIntensity]./255;

% Feature: centroid with respect to average of centroids.
allCentroids = [stats_grey.WeightedCentroid];
allCentroid2D = reshape (allCentroids, [2, size(allCentroids,2)/2])';
meanAllCentroids = mean(allCentroid2D, 1);

diffCentroids = allCentroid2D-meanAllCentroids;

properties(:,7) = diffCentroids(:,1)./size(ImgVGA,2);
properties(:,8) = diffCentroids(:,2)./size(ImgVGA,2);

[label, score] = filteringPredictor(properties);
%
allCentroids = [stats_grey.WeightedCentroid];
allCentroids2D = reshape (allCentroids, [2, size(allCentroids,2)/2])';

% Which candidates were classified as markers?
markerIdxs = find(label);

% Temporary solution for false positives: if more than 7, take the 7
% with highest score.
if (numel(markerIdxs)) >numExpectedMarkers
    [sorted,sortedIdx] = sort(score(:,2), 'descend');
    markerIdxs = sortedIdx(1:numExpectedMarkers);
end

if (numel(markerIdxs)) < minNumMarkers
    % Should stop here
end

markerCentroids = allCentroids2D(markerIdxs,:);
numMarkers = size (markerCentroids,1);

normImagePts = [markerCentroids ones(size(markerCentroids, 1), 1)] *inv(K); % normalize
normImagePts(:,3) = [];

% If detected markers less than expected, need pad with NANS
fullImagePts = NaN(numExpectedMarkers,2);
fullImagePts(1:numMarkers, :) = normImagePts;

fullMkCentroids= NaN(numExpectedMarkers,2);
fullMkCentroids(1:numMarkers, :) = markerCentroids;

estimatedLabels = wrapperNNOrdering(fullImagePts);

[~,IdxsOrdered] = sort(estimatedLabels); %Get correspondance from pipeline, not GT

nanRow = find(isnan (fullImagePts(:,1)));
IdxsOrdered(nanRow) = [];

markerCentroidsOrdered = fullMkCentroids (IdxsOrdered, :);

markerCentroidsOrdered(estimatedLabels(nanRow),:) = NaN;

end

