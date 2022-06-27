function [labels] = wrapperNNOrdering(markerPts)
%% Calculate Features
numPts = size(markerPts,1);
numFeatures = (numPts)*2;
numMarkers =numPts;

inputMatrix = NaN(numPts, numFeatures);

% normImagePts = [markerPts ones(size(markerPts, 1), 1)] *inv(K); % normalize
% normImagePts(:,3) = [];

normImagePts = markerPts;

for pt1=1: numPts
    [dists, ~]= sortrows(repmat(normImagePts(pt1,:), size(normImagePts,1),1)-normImagePts);
    inputMatrix(pt1,:) = dists(:);
end

x1 = NaN (numFeatures*2, numPts);
isNaNInputMatrix = isnan(inputMatrix);
avgRowsRep = repmat(mean (inputMatrix,1, 'omitnan'), numPts, 1);
avgRowsRep(~isNaNInputMatrix) = inputMatrix(~isNaNInputMatrix);

if (sum(isnan(inputMatrix))==0)
    x1(1:2:2*2*numMarkers,:) = inputMatrix(:,1:2*numMarkers)';
    x1(2:2:2*2*numMarkers,:) = ones;
else
    
    %[x1,~] = fixunknowns(inputMatrix');
    x1(1:2:2*2*numPts,:) = avgRowsRep';
    x1(2:2:2*2*numPts,:) = isNaNInputMatrix';
end

%% Call to NN
[y1] = exportedNNKnuckle(x1);

%%
probMatrix = y1;
p = savedPerms(numMarkers);
     
sumProb = zeros (1,size(p,1));
for i=1:size(p,1)
    sumProb(i)=0;
    for j=1:numMarkers
        sumProb(i) = sumProb(i) + probMatrix(p(i,j), j);
    end
end
[~, I] = max(sumProb);
labels = p(I,:);
for j=1:numMarkers
    %tmp(j) = probMatrix(labels(j),j);
    if(probMatrix(labels(j),j))==0
        labels(j)=0;
    end
end
end