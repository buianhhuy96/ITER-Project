function imagePoints=readImagePoints(dataAdd)

subdir='';
datapointsFile=[dataAdd,subdir,'results\ImagePoints.txt'];

%% reading and parsing marker points 
%get the subset extract of the log with indices and pose in form of strings
filetext = fileread( datapointsFile ) ;
expropen = '[';
exprclose = ']';
expTag='Detected Tag';

[~,samplestartingInd1,sampleendingInd1] = regexp(filetext,'img','match');
[~,samplestartingInd2,sampleendingInd2] = regexp(filetext,':','match');

[~,tagStartInd,tagEndInd] = regexp(filetext,expTag,'match');
[~,OpenstartingInd,OpenendingInd] = regexp(filetext,expropen,'match');
[~,ClosestartingInd,CloseendingInd] = regexp(filetext,exprclose,'match');
%seperate Each data unit
for k=1:length(tagStartInd)   
    %meta data
    meta=split(filetext(tagStartInd(k):OpenstartingInd(k)-3)," ");
    tagnum(k,1)= str2double(meta(3));
    temp= meta(4);
    imgnum(k,1)=str2double(temp{:}(4:end));
    
    %img points
    LOGroi=filetext(OpenstartingInd(k)+1:ClosestartingInd(k)-1);
    LOGroi= convertCharsToStrings(LOGroi);
    newStr = splitlines(LOGroi);
    LOGstrgs = split(newStr,",");
    LOGstrgs(:,2)=erase(LOGstrgs(:,2),';');
    data=str2double(LOGstrgs);
   
    %extract valid matches
    idx{k} = any(data,2);
    validMarkerSet{imgnum(k,1),tagnum(k,1)+1}=data(idx{k},:);
    
    %identify existing lines
    intidx{imgnum(k,1),tagnum(k,1)+1}=find(idx{k});
    line1= all(ismember([1 2 3 4],[intidx{imgnum(k,1),tagnum(k,1)+1}]));
    line2= all(ismember([4 5 6 7],[intidx{imgnum(k,1),tagnum(k,1)+1}]));
    line3= all(ismember([7 8 9 10],[intidx{imgnum(k,1),tagnum(k,1)+1}]));
    line4= all(ismember([10 11 12 1],[intidx{imgnum(k,1),tagnum(k,1)+1}]));
    linestag{imgnum(k,1),tagnum(k,1)+1}=nonzeros([1 2 3 4].*[line1 line2 line3 line4])';

end
    

sampleID=unique(imgnum);  
    

%% visualize detected points on images
readLoc=[dataAdd,subdir];
files = dir([readLoc '/*.png']);
% figure
strr= {'1','2','3','4','5','6','7','8','9','10','11','12'};
% figure
for id = 1:size(validMarkerSet,1)
    imgid=id;
    
    filename=[readLoc,files(imgid).name];
    img=imread(filename);
    if length(size(img))==3
         I{id}=rgb2gray(imread(filename));
    else
         I{id}=imread(filename);
    end
    
    
 % reshape for output
imagePoints=cat(3,validMarkerSet{:});


imshow (I{id}),
        hold on
        scatter(imagePoints(:,1,id),imagePoints(:,2,id),'gx');hold on
        text(imagePoints(:,1,id)+10, imagePoints(:,2,id)+10,strr ,'Color','green', 'Fontsize', 20);hold on
        %disp('Press any button to see next image...')
       % waitforbuttonpress,     
        hold off
end
