################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Handeye_Calibrate
BUILD_ARTIFACT_EXTENSION := 
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Handeye_Calibrate

# Tool invocations
Handeye_Calibrate: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
		@echo 'Set library path'
		export LD_LIBRARY_PATH=../lib/Linux/runtime/glnxa64:../lib/Linux/bin/glnxa64:../lib/Linux/sys/os/glnxa64:../lib/Linux/extern/bin/glnxa64
		export LIBRARY_PATH=../lib/Linux/runtime/glnxa64:../lib/Linux/bin/glnxa64:../lib/Linux/sys/os/glnxa64:../lib/Linux/extern/bin/glnxa64
		@echo 'Building target: $@'
		@echo 'Invoking: Cygwin C++ Linker'
		g++ -L"../lib/Linux/bin/glnxa64" -fopenmp -o ../Handeye_Calibrate $(OBJS) $(USER_OBJS) $(LIBS) -Wl,-rpath=..\lib\Linux\bin\glnxa64
		@echo 'Finished building target: $@'

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(C_DEPS) ../Handeye_Calibrate
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
