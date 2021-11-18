################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ITER_API/calibrateCamera.cpp \
../ITER_API/calibrateHandEye.cpp \
../ITER_API/common_definitions.cpp 

OBJS += \
./ITER_API/calibrateCamera.o \
./ITER_API/calibrateHandEye.o \
./ITER_API/common_definitions.o 

CPP_DEPS += \
./ITER_API/calibrateCamera.d \
./ITER_API/calibrateHandEye.d \
./ITER_API/common_definitions.d 


# Each subdirectory must supply rules for building sources it contributes
ITER_API/%.o: ../ITER_API/%.cpp ITER_API/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++1z -I"D:\eclipse-workspace\Handeye_Calibration_2.0\cute" -O3 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


