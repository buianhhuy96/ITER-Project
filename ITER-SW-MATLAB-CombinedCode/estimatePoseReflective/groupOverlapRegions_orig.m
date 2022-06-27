function [uniqueRegions] = groupOverlapRegions(regions, ImgVGA)

numRegions = size(regions.Lengths,1);
lengths = regions.Lengths;
pixelList = regions.PixelList;

lengths1 = [1; lengths];
%i=55
%pixelList(sum(lengths1(1:i)):sum(lengths(1:i)))

groups = NaN(numRegions,1); %55
groupNum = 0;
sizes =0;

for i=1:numRegions
    if(isnan(groups(i)))
        groupNum = groupNum +1;
        groups(i) = groupNum;
    end
    array1 = pixelList(sum(lengths1(1:i)):sum(lengths(1:i)),:);
    for j=1:numRegions
        array2 = pixelList(sum(lengths1(1:j)):sum(lengths(1:j)),:);
        bolIntersect = numel(intersect(sortrows(array1), sortrows(array2), 'rows'))>1;
        if(bolIntersect && isnan(groups(j))) % && abs(size(array1,1)-size(array2,1))< 200
            abs(size(array1,1)-size(array2,1));
            groups(j) = groupNum;
        end
    end
end

regionPixelListUniqueSerial = zeros(1,2);
regionPixelListUnique = [];

indexes = [];
count = 0;

for group=1:numel(unique(groups))
    idx = find (groups == group);
    regionPixelListGroup = pixelList(sum(lengths1(1:idx(1))):sum(lengths(1:idx(1))),:)';
    
    ImgValues = ImgVGA(sub2ind(size(ImgVGA),regionPixelListGroup(2,:),regionPixelListGroup(1,:)));
    leastDarkInRegion = max(ImgValues(:));
    
    binaryImage = zeros (size(ImgVGA));
    binaryImage(sub2ind(size(ImgVGA),regionPixelListGroup(2, :),regionPixelListGroup(1, :))) =1;

    %dilatedImage = imdilate(binaryImage, true(3));

    %dilatedImage = bwmorph(binaryImage,'dilate');
    
    dilatedImage = bwdist(binaryImage,'chessboard') == 1;

    borderPixels = bwperim(dilatedImage);
    pixelValues = ImgVGA(borderPixels);
    darkestInNeighbourhood = min(pixelValues(:));
    if(leastDarkInRegion>darkestInNeighbourhood) %Keep only bright on dark polarity
        %regionPixelListUnique{numel(indexes)+1} = regionPixelListGroup; % keeping first element in each group, meaning smallest area
        regionPixelListUniqueSerial(end:end+size(regionPixelListGroup,2)-1, :) = regionPixelListGroup';
        sizes (group) = size(regionPixelListGroup,2);
        indexes = [indexes, idx(1)];
    end
end

uniqueRegions.PixelList = regionPixelListUniqueSerial;
uniqueRegions.Lengths = sizes;

end

