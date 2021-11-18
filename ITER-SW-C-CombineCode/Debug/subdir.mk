################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../API_Test.cpp \
../Unit_Test.cpp \
../fileHandler.cpp \
../main.cpp 

OBJS += \
./API_Test.o \
./Unit_Test.o \
./fileHandler.o \
./main.o 

CPP_DEPS += \
./API_Test.d \
./Unit_Test.d \
./fileHandler.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++1z -I"..\cute" -O3 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -fopenmp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


