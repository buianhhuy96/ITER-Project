###########################################################################
## Makefile generated for component 'calibrateOneCamera'. 
## 
## Makefile     : calibrateOneCamera_rtw.mk
## Generated on : Mon Oct 25 12:46:30 2021
## Final product: ./calibrateOneCamera.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = calibrateOneCamera
MAKEFILE                  = calibrateOneCamera_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/TUT_Research/Gitlab/f4e-grt/ITER-SW-CameraCalibration/Matlab-code-V2
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = calibrateOneCamera_rtw_comp.rsp
CMD_FILE                  = calibrateOneCamera_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = calibrateOneCamera.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3 -fno-loop-optimize -fno-aggressive-loop-optimizations
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./calibrateOneCamera.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=calibrateOneCamera

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_data.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rt_nonfinite.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rtGetNaN.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rtGetInf.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_initialize.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_terminate.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/generateCheckerboardPoints.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/isequal.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/detectCheckerboardPoints.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/imfilter.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/conv2AXPYValidCMP.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/find_peaks.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/bwlookup.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/detectCheckerboard.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/minOrMax.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/mean.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/find.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/polyfit.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/qrsolve.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xnrm2.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/eml_setop.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/sortIdx.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/colon.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/squeeze.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/ismember.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/norm.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/combineVectorElements.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rot90.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/cat.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/computeInitialParameterEstimate.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/fitgeotrans.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/normalizeControlPoints.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/svd.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/inv.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xdotc.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rodriguesMatrixToVector.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rodriguesVectorToMatrix.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/CalculateCost.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/unserializeCalib.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/nanmean.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/preprocessImages.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/rgb2gray.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/subPixelLocation.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xrotg.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/algbwmorph.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/sort.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xzlarfg.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xzlarf.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xunormqr.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/flip.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/mldivide.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xgeqp3.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xaxpy.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xrot.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xswap.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/lsqnonlin.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/xgemv.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/linearLeastSquares.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/unsafeSxfun.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/factoryConstruct.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/jacobianFiniteDifference.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/driver.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/checkStoppingCriteria.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/computeCentralDifferences.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/finDiffEvalAndChkErr.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/Checkerboard.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/NeighborhoodProcessor.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/cameraParameters.cpp $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = calibrateOneCamera_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj calibrateOneCamera_initialize.obj calibrateOneCamera_terminate.obj calibrateOneCamera.obj generateCheckerboardPoints.obj isequal.obj detectCheckerboardPoints.obj imfilter.obj conv2AXPYValidCMP.obj find_peaks.obj bwlookup.obj detectCheckerboard.obj minOrMax.obj mean.obj find.obj polyfit.obj qrsolve.obj xnrm2.obj eml_setop.obj sortIdx.obj colon.obj squeeze.obj ismember.obj norm.obj combineVectorElements.obj rot90.obj cat.obj computeInitialParameterEstimate.obj fitgeotrans.obj normalizeControlPoints.obj svd.obj inv.obj xdotc.obj rodriguesMatrixToVector.obj rodriguesVectorToMatrix.obj CalculateCost.obj unserializeCalib.obj nanmean.obj preprocessImages.obj rgb2gray.obj subPixelLocation.obj xrotg.obj algbwmorph.obj sort.obj xzlarfg.obj xzlarf.obj xunormqr.obj flip.obj mldivide.obj xgeqp3.obj xaxpy.obj xrot.obj xswap.obj lsqnonlin.obj xgemv.obj linearLeastSquares.obj unsafeSxfun.obj factoryConstruct.obj jacobianFiniteDifference.obj driver.obj checkStoppingCriteria.obj computeFiniteDifferences.obj computeCentralDifferences.obj finDiffEvalAndChkErr.obj Checkerboard.obj NeighborhoodProcessor.obj cameraParameters.obj calibrateOneCamera_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_OPTS = -fopenmp
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_OPTS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_OPTS = -fopenmp
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_OPTS) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -fopenmp

CPP_LDFLAGS += $(CPP_LDFLAGS_)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -fopenmp

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_)

#-----------
# Linker
#-----------

LDFLAGS_ = -fopenmp

LDFLAGS += $(LDFLAGS_)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -fopenmp

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera_data.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera_initialize.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera_terminate.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


generateCheckerboardPoints.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/generateCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboardPoints.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/detectCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


conv2AXPYValidCMP.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/conv2AXPYValidCMP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find_peaks.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/find_peaks.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwlookup.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/bwlookup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboard.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/detectCheckerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/mean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


polyfit.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/polyfit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


qrsolve.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/qrsolve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_setop.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/eml_setop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ismember.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/ismember.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rot90.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rot90.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cat.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/cat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeInitialParameterEstimate.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/computeInitialParameterEstimate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fitgeotrans.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/fitgeotrans.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


normalizeControlPoints.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/normalizeControlPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inv.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/inv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rodriguesMatrixToVector.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rodriguesMatrixToVector.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rodriguesVectorToMatrix.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rodriguesVectorToMatrix.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CalculateCost.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/CalculateCost.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unserializeCalib.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/unserializeCalib.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nanmean.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/nanmean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


preprocessImages.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/preprocessImages.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rgb2gray.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/rgb2gray.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


subPixelLocation.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/subPixelLocation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


algbwmorph.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/algbwmorph.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xunormqr.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xunormqr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


flip.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/flip.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/mldivide.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lsqnonlin.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/lsqnonlin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearLeastSquares.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/linearLeastSquares.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


jacobianFiniteDifference.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/jacobianFiniteDifference.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingCriteria.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/checkStoppingCriteria.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeCentralDifferences.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/computeCentralDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/finDiffEvalAndChkErr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Checkerboard.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/Checkerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


NeighborhoodProcessor.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/NeighborhoodProcessor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cameraParameters.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/cameraParameters.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera_rtwutil.obj : $(START_DIR)/codegen/lib/calibrateOneCamera/calibrateOneCamera_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


