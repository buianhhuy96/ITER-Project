################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Checkerboard.cpp \
../CoderTimeAPI.cpp \
../ComputeCamExtrinsics.cpp \
../HandeyeShah.cpp \
../ImageTransformer.cpp \
../NeighborhoodProcessor.cpp \
../Test.cpp \
../algbwmorph.cpp \
../bsearch.cpp \
../bwlookup.cpp \
../calibrateHandEye.cpp \
../calibrateHandeye_data.cpp \
../calibrateHandeye_initialize.cpp \
../calibrateHandeye_rtwutil.cpp \
../calibrateHandeye_terminate.cpp \
../cat.cpp \
../colon.cpp \
../combineVectorElements.cpp \
../computeErrors.cpp \
../conv2AXPYValidCMP.cpp \
../det.cpp \
../detectCheckerboard.cpp \
../detectCheckerboardPoints.cpp \
../eml_setop.cpp \
../find.cpp \
../find_peaks.cpp \
../fitgeotrans.cpp \
../flip.cpp \
../imfilter.cpp \
../interp2.cpp \
../inv.cpp \
../isequal.cpp \
../ismember.cpp \
../main.cpp \
../mean.cpp \
../minOrMax.cpp \
../mldivide.cpp \
../norm.cpp \
../normalizeControlPoints.cpp \
../polyfit.cpp \
../preprocessImages.cpp \
../qrsolve.cpp \
../readRobotPoses.cpp \
../rgb2gray.cpp \
../rot90.cpp \
../rotm2axang.cpp \
../rtGetInf.cpp \
../rtGetNaN.cpp \
../rt_nonfinite.cpp \
../sort.cpp \
../sortIdx.cpp \
../sqrt.cpp \
../squeeze.cpp \
../subPixelLocation.cpp \
../svd.cpp \
../svd1.cpp \
../tic.cpp \
../timeKeeper.cpp \
../toc.cpp \
../xaxpy.cpp \
../xdotc.cpp \
../xgeqp3.cpp \
../xnrm2.cpp \
../xrot.cpp \
../xrotg.cpp \
../xswap.cpp 

C_SRCS += \
../coder_posix_time.c 

OBJS += \
./Checkerboard.o \
./CoderTimeAPI.o \
./ComputeCamExtrinsics.o \
./HandeyeShah.o \
./ImageTransformer.o \
./NeighborhoodProcessor.o \
./Test.o \
./algbwmorph.o \
./bsearch.o \
./bwlookup.o \
./calibrateHandEye.o \
./calibrateHandeye_data.o \
./calibrateHandeye_initialize.o \
./calibrateHandeye_rtwutil.o \
./calibrateHandeye_terminate.o \
./cat.o \
./coder_posix_time.o \
./colon.o \
./combineVectorElements.o \
./computeErrors.o \
./conv2AXPYValidCMP.o \
./det.o \
./detectCheckerboard.o \
./detectCheckerboardPoints.o \
./eml_setop.o \
./find.o \
./find_peaks.o \
./fitgeotrans.o \
./flip.o \
./imfilter.o \
./interp2.o \
./inv.o \
./isequal.o \
./ismember.o \
./main.o \
./mean.o \
./minOrMax.o \
./mldivide.o \
./norm.o \
./normalizeControlPoints.o \
./polyfit.o \
./preprocessImages.o \
./qrsolve.o \
./readRobotPoses.o \
./rgb2gray.o \
./rot90.o \
./rotm2axang.o \
./rtGetInf.o \
./rtGetNaN.o \
./rt_nonfinite.o \
./sort.o \
./sortIdx.o \
./sqrt.o \
./squeeze.o \
./subPixelLocation.o \
./svd.o \
./svd1.o \
./tic.o \
./timeKeeper.o \
./toc.o \
./xaxpy.o \
./xdotc.o \
./xgeqp3.o \
./xnrm2.o \
./xrot.o \
./xrotg.o \
./xswap.o 

CPP_DEPS += \
./Checkerboard.d \
./CoderTimeAPI.d \
./ComputeCamExtrinsics.d \
./HandeyeShah.d \
./ImageTransformer.d \
./NeighborhoodProcessor.d \
./Test.d \
./algbwmorph.d \
./bsearch.d \
./bwlookup.d \
./calibrateHandEye.d \
./calibrateHandeye_data.d \
./calibrateHandeye_initialize.d \
./calibrateHandeye_rtwutil.d \
./calibrateHandeye_terminate.d \
./cat.d \
./colon.d \
./combineVectorElements.d \
./computeErrors.d \
./conv2AXPYValidCMP.d \
./det.d \
./detectCheckerboard.d \
./detectCheckerboardPoints.d \
./eml_setop.d \
./find.d \
./find_peaks.d \
./fitgeotrans.d \
./flip.d \
./imfilter.d \
./interp2.d \
./inv.d \
./isequal.d \
./ismember.d \
./main.d \
./mean.d \
./minOrMax.d \
./mldivide.d \
./norm.d \
./normalizeControlPoints.d \
./polyfit.d \
./preprocessImages.d \
./qrsolve.d \
./readRobotPoses.d \
./rgb2gray.d \
./rot90.d \
./rotm2axang.d \
./rtGetInf.d \
./rtGetNaN.d \
./rt_nonfinite.d \
./sort.d \
./sortIdx.d \
./sqrt.d \
./squeeze.d \
./subPixelLocation.d \
./svd.d \
./svd1.d \
./tic.d \
./timeKeeper.d \
./toc.d \
./xaxpy.d \
./xdotc.d \
./xgeqp3.d \
./xnrm2.d \
./xrot.d \
./xrotg.d \
./xswap.d 

C_DEPS += \
./coder_posix_time.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++1z -I"..\cute" -O3 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"..\cute" -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


