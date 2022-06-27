function [label, score] = filteringPredictor(X) 
% Classifies marker candidates into into Marker/ Not marker
% using templateTree Model in the file SVMIris.mat, and 
% returns class labels in label.
Mdl = loadLearnerForCoder('randForestFilter');
[label, score] = predict(Mdl,X);
end