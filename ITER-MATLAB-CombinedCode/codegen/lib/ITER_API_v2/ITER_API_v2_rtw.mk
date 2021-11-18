###########################################################################
## Makefile generated for component 'ITER_API_v2'. 
## 
## Makefile     : ITER_API_v2_rtw.mk
## Generated on : Tue Oct 26 15:23:47 2021
## Final product: ./ITER_API_v2.lib
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

PRODUCT_NAME              = ITER_API_v2
MAKEFILE                  = ITER_API_v2_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/TUT_Research/Gitlab/f4e-grt/ITER-MATLAB-CombinedCode
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = ITER_API_v2_rtw_comp.rsp
CMD_FILE                  = ITER_API_v2_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = ITER_API_v2.lib

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

PRODUCT = ./ITER_API_v2.lib
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
DEFINES_STANDARD = -DMODEL=ITER_API_v2

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_data.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rt_nonfinite.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rtGetNaN.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rtGetInf.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_initialize.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_terminate.cpp $(START_DIR)/codegen/lib/ITER_API_v2/calibrateOneCamera.cpp $(START_DIR)/codegen/lib/ITER_API_v2/isequal.cpp $(START_DIR)/codegen/lib/ITER_API_v2/detectCheckerboardPoints.cpp $(START_DIR)/codegen/lib/ITER_API_v2/imfilter.cpp $(START_DIR)/codegen/lib/ITER_API_v2/conv2AXPYValidCMP.cpp $(START_DIR)/codegen/lib/ITER_API_v2/mod.cpp $(START_DIR)/codegen/lib/ITER_API_v2/find_peaks.cpp $(START_DIR)/codegen/lib/ITER_API_v2/bwlookup.cpp $(START_DIR)/codegen/lib/ITER_API_v2/detectCheckerboard.cpp $(START_DIR)/codegen/lib/ITER_API_v2/minOrMax.cpp $(START_DIR)/codegen/lib/ITER_API_v2/mean.cpp $(START_DIR)/codegen/lib/ITER_API_v2/find.cpp $(START_DIR)/codegen/lib/ITER_API_v2/polyfit.cpp $(START_DIR)/codegen/lib/ITER_API_v2/qrsolve.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xnrm2.cpp $(START_DIR)/codegen/lib/ITER_API_v2/eml_setop.cpp $(START_DIR)/codegen/lib/ITER_API_v2/sortIdx.cpp $(START_DIR)/codegen/lib/ITER_API_v2/colon.cpp $(START_DIR)/codegen/lib/ITER_API_v2/squeeze.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ismember.cpp $(START_DIR)/codegen/lib/ITER_API_v2/norm.cpp $(START_DIR)/codegen/lib/ITER_API_v2/combineVectorElements.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rot90.cpp $(START_DIR)/codegen/lib/ITER_API_v2/cat.cpp $(START_DIR)/codegen/lib/ITER_API_v2/computeInitialParameterEstimate.cpp $(START_DIR)/codegen/lib/ITER_API_v2/fitgeotrans.cpp $(START_DIR)/codegen/lib/ITER_API_v2/normalizeControlPoints.cpp $(START_DIR)/codegen/lib/ITER_API_v2/svd.cpp $(START_DIR)/codegen/lib/ITER_API_v2/inv.cpp $(START_DIR)/codegen/lib/ITER_API_v2/det.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xdotc.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rodriguesMatrixToVector.cpp $(START_DIR)/codegen/lib/ITER_API_v2/svd1.cpp $(START_DIR)/codegen/lib/ITER_API_v2/CalculateCost.cpp $(START_DIR)/codegen/lib/ITER_API_v2/unserializeCalib.cpp $(START_DIR)/codegen/lib/ITER_API_v2/distortPoints.cpp $(START_DIR)/codegen/lib/ITER_API_v2/nanmean.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ComputeCamExtrinsics.cpp $(START_DIR)/codegen/lib/ITER_API_v2/mldivide.cpp $(START_DIR)/codegen/lib/ITER_API_v2/computeErrors.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rotm2axang.cpp $(START_DIR)/codegen/lib/ITER_API_v2/HandeyeShah.cpp $(START_DIR)/codegen/lib/ITER_API_v2/preprocessImages.cpp $(START_DIR)/codegen/lib/ITER_API_v2/rgb2gray.cpp $(START_DIR)/codegen/lib/ITER_API_v2/interp2.cpp $(START_DIR)/codegen/lib/ITER_API_v2/bsearch.cpp $(START_DIR)/codegen/lib/ITER_API_v2/readRobotPoses.cpp $(START_DIR)/codegen/lib/ITER_API_v2/subPixelLocation.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xrotg.cpp $(START_DIR)/codegen/lib/ITER_API_v2/algbwmorph.cpp $(START_DIR)/codegen/lib/ITER_API_v2/sort.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xgeqp3.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xzlarfg.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xzlarf.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xunormqr.cpp $(START_DIR)/codegen/lib/ITER_API_v2/flip.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xaxpy.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xrot.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xswap.cpp $(START_DIR)/codegen/lib/ITER_API_v2/lsqnonlin.cpp $(START_DIR)/codegen/lib/ITER_API_v2/xgemv.cpp $(START_DIR)/codegen/lib/ITER_API_v2/linearLeastSquares.cpp $(START_DIR)/codegen/lib/ITER_API_v2/sqrt.cpp $(START_DIR)/codegen/lib/ITER_API_v2/unsafeSxfun.cpp $(START_DIR)/codegen/lib/ITER_API_v2/factoryConstruct.cpp $(START_DIR)/codegen/lib/ITER_API_v2/jacobianFiniteDifference.cpp $(START_DIR)/codegen/lib/ITER_API_v2/driver.cpp $(START_DIR)/codegen/lib/ITER_API_v2/checkStoppingCriteria.cpp $(START_DIR)/codegen/lib/ITER_API_v2/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/ITER_API_v2/computeCentralDifferences.cpp $(START_DIR)/codegen/lib/ITER_API_v2/finDiffEvalAndChkErr.cpp $(START_DIR)/codegen/lib/ITER_API_v2/Checkerboard.cpp $(START_DIR)/codegen/lib/ITER_API_v2/NeighborhoodProcessor.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ImageTransformer.cpp $(START_DIR)/codegen/lib/ITER_API_v2/cameraParameters.cpp $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = ITER_API_v2_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj ITER_API_v2_initialize.obj ITER_API_v2_terminate.obj calibrateOneCamera.obj isequal.obj detectCheckerboardPoints.obj imfilter.obj conv2AXPYValidCMP.obj mod.obj find_peaks.obj bwlookup.obj detectCheckerboard.obj minOrMax.obj mean.obj find.obj polyfit.obj qrsolve.obj xnrm2.obj eml_setop.obj sortIdx.obj colon.obj squeeze.obj ismember.obj norm.obj combineVectorElements.obj rot90.obj cat.obj computeInitialParameterEstimate.obj fitgeotrans.obj normalizeControlPoints.obj svd.obj inv.obj det.obj xdotc.obj rodriguesMatrixToVector.obj svd1.obj CalculateCost.obj unserializeCalib.obj distortPoints.obj nanmean.obj ComputeCamExtrinsics.obj mldivide.obj computeErrors.obj rotm2axang.obj HandeyeShah.obj preprocessImages.obj rgb2gray.obj interp2.obj bsearch.obj readRobotPoses.obj subPixelLocation.obj xrotg.obj algbwmorph.obj sort.obj xgeqp3.obj xzlarfg.obj xzlarf.obj xunormqr.obj flip.obj xaxpy.obj xrot.obj xswap.obj lsqnonlin.obj xgemv.obj linearLeastSquares.obj sqrt.obj unsafeSxfun.obj factoryConstruct.obj jacobianFiniteDifference.obj driver.obj checkStoppingCriteria.obj computeFiniteDifferences.obj computeCentralDifferences.obj finDiffEvalAndChkErr.obj Checkerboard.obj NeighborhoodProcessor.obj ImageTransformer.obj cameraParameters.obj ITER_API_v2_rtwutil.obj

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


%.obj : $(START_DIR)/codegen/lib/ITER_API_v2/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/ITER_API_v2/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_v2_data.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_v2_initialize.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_v2_terminate.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera.obj : $(START_DIR)/codegen/lib/ITER_API_v2/calibrateOneCamera.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.obj : $(START_DIR)/codegen/lib/ITER_API_v2/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboardPoints.obj : $(START_DIR)/codegen/lib/ITER_API_v2/detectCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/ITER_API_v2/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


conv2AXPYValidCMP.obj : $(START_DIR)/codegen/lib/ITER_API_v2/conv2AXPYValidCMP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mod.obj : $(START_DIR)/codegen/lib/ITER_API_v2/mod.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find_peaks.obj : $(START_DIR)/codegen/lib/ITER_API_v2/find_peaks.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwlookup.obj : $(START_DIR)/codegen/lib/ITER_API_v2/bwlookup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboard.obj : $(START_DIR)/codegen/lib/ITER_API_v2/detectCheckerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/ITER_API_v2/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/ITER_API_v2/mean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/ITER_API_v2/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


polyfit.obj : $(START_DIR)/codegen/lib/ITER_API_v2/polyfit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


qrsolve.obj : $(START_DIR)/codegen/lib/ITER_API_v2/qrsolve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_setop.obj : $(START_DIR)/codegen/lib/ITER_API_v2/eml_setop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/ITER_API_v2/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.obj : $(START_DIR)/codegen/lib/ITER_API_v2/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/lib/ITER_API_v2/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ismember.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ismember.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.obj : $(START_DIR)/codegen/lib/ITER_API_v2/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.obj : $(START_DIR)/codegen/lib/ITER_API_v2/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rot90.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rot90.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cat.obj : $(START_DIR)/codegen/lib/ITER_API_v2/cat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeInitialParameterEstimate.obj : $(START_DIR)/codegen/lib/ITER_API_v2/computeInitialParameterEstimate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fitgeotrans.obj : $(START_DIR)/codegen/lib/ITER_API_v2/fitgeotrans.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


normalizeControlPoints.obj : $(START_DIR)/codegen/lib/ITER_API_v2/normalizeControlPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/ITER_API_v2/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inv.obj : $(START_DIR)/codegen/lib/ITER_API_v2/inv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


det.obj : $(START_DIR)/codegen/lib/ITER_API_v2/det.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rodriguesMatrixToVector.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rodriguesMatrixToVector.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd1.obj : $(START_DIR)/codegen/lib/ITER_API_v2/svd1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CalculateCost.obj : $(START_DIR)/codegen/lib/ITER_API_v2/CalculateCost.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unserializeCalib.obj : $(START_DIR)/codegen/lib/ITER_API_v2/unserializeCalib.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


distortPoints.obj : $(START_DIR)/codegen/lib/ITER_API_v2/distortPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


nanmean.obj : $(START_DIR)/codegen/lib/ITER_API_v2/nanmean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ComputeCamExtrinsics.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ComputeCamExtrinsics.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.obj : $(START_DIR)/codegen/lib/ITER_API_v2/mldivide.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeErrors.obj : $(START_DIR)/codegen/lib/ITER_API_v2/computeErrors.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotm2axang.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rotm2axang.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


HandeyeShah.obj : $(START_DIR)/codegen/lib/ITER_API_v2/HandeyeShah.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


preprocessImages.obj : $(START_DIR)/codegen/lib/ITER_API_v2/preprocessImages.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rgb2gray.obj : $(START_DIR)/codegen/lib/ITER_API_v2/rgb2gray.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


interp2.obj : $(START_DIR)/codegen/lib/ITER_API_v2/interp2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bsearch.obj : $(START_DIR)/codegen/lib/ITER_API_v2/bsearch.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


readRobotPoses.obj : $(START_DIR)/codegen/lib/ITER_API_v2/readRobotPoses.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


subPixelLocation.obj : $(START_DIR)/codegen/lib/ITER_API_v2/subPixelLocation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


algbwmorph.obj : $(START_DIR)/codegen/lib/ITER_API_v2/algbwmorph.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/ITER_API_v2/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xunormqr.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xunormqr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


flip.obj : $(START_DIR)/codegen/lib/ITER_API_v2/flip.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lsqnonlin.obj : $(START_DIR)/codegen/lib/ITER_API_v2/lsqnonlin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/ITER_API_v2/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearLeastSquares.obj : $(START_DIR)/codegen/lib/ITER_API_v2/linearLeastSquares.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.obj : $(START_DIR)/codegen/lib/ITER_API_v2/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.obj : $(START_DIR)/codegen/lib/ITER_API_v2/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/codegen/lib/ITER_API_v2/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


jacobianFiniteDifference.obj : $(START_DIR)/codegen/lib/ITER_API_v2/jacobianFiniteDifference.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/ITER_API_v2/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingCriteria.obj : $(START_DIR)/codegen/lib/ITER_API_v2/checkStoppingCriteria.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/ITER_API_v2/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeCentralDifferences.obj : $(START_DIR)/codegen/lib/ITER_API_v2/computeCentralDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/ITER_API_v2/finDiffEvalAndChkErr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Checkerboard.obj : $(START_DIR)/codegen/lib/ITER_API_v2/Checkerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


NeighborhoodProcessor.obj : $(START_DIR)/codegen/lib/ITER_API_v2/NeighborhoodProcessor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ImageTransformer.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ImageTransformer.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cameraParameters.obj : $(START_DIR)/codegen/lib/ITER_API_v2/cameraParameters.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_v2_rtwutil.obj : $(START_DIR)/codegen/lib/ITER_API_v2/ITER_API_v2_rtwutil.cpp
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


