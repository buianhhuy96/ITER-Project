### 1.10.2021 
Changed to work for single camera

### Original Text
# Photogrammetric Multi-Camera Calibration Toolbox V1
## 1. Introduction 

We implement a generalization of Zhang's widely used single camera calibration algorithm to N cameras. Solutions are found through overall optimization of the cameras' parameters. The user can choose which subset of cameras' parameters to re-optimize: re-optimize all parameters, fixed intrinsic parameters or fixed lens distortions.

## 2. Input: Calibration Images

## 2.1 Calibration Object
The toolbox expects the calibration object to be a standard planar checkerboard pattern.
The checkerboard pattern should be asymmetric and of even and odd dimentions. Example: 28 X 17 corners.

## 2.2 Calibration Image Capture
Capture as many images as necessary to satisfy the following conditions:
- Each camera sees at least 3 fully visible pattern positions.
- Account for as much of each camera�s image frames as possible.
- In 10 to 20 pattern positions the checkerboard is fully visible by all cameras.
- In each image, the checkerboard pattern must be at different orientations relative to the camera.
- The checkerboard should preferably ?ll at least 20% of the image frame.
- The checkerboard must be at an angle of less than 45 degrees relative to the camera plane.


## 2.3 Image Naming Convension
PositionXXX_CameraXX.

## 3. Test Dataset
A test dataset is provided 

## 2. Dependencies
The implementation depends on the image precessing, camera calibration and optimization toolboxes of matlab.


## 3. How to Cite?


Publication is under review.

## 3. How to Use?


Run script main.m.

## Contact
Laura Ribeiro
Tampere University, Finland 
Mailing address: Korkeakoulunkatu 1, TE309
laura.goncalvesribeiro@tuni.fi