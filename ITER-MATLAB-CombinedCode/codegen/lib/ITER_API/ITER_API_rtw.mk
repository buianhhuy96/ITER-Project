###########################################################################
## Makefile generated for component 'ITER_API'. 
## 
## Makefile     : ITER_API_rtw.mk
## Generated on : Wed Nov 17 17:46:37 2021
## Final product: ./ITER_API.lib
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

PRODUCT_NAME              = ITER_API
MAKEFILE                  = ITER_API_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/TUT_Research/Gitlab/f4e-grt/ITER-MATLAB-CombinedCode
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = ITER_API_rtw_comp.rsp
CMD_FILE                  = ITER_API_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = ITER_API.lib

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

PRODUCT = ./ITER_API.lib
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
DEFINES_STANDARD = -DMODEL=ITER_API

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/ITER_API/ITER_API_data.cpp $(START_DIR)/codegen/lib/ITER_API/rt_nonfinite.cpp $(START_DIR)/codegen/lib/ITER_API/rtGetNaN.cpp $(START_DIR)/codegen/lib/ITER_API/rtGetInf.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_initialize.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_terminate.cpp $(START_DIR)/codegen/lib/ITER_API/calibrateOneCamera_v2.cpp $(START_DIR)/codegen/lib/ITER_API/isequal.cpp $(START_DIR)/codegen/lib/ITER_API/detectCheckerboardPoints.cpp $(START_DIR)/codegen/lib/ITER_API/imfilter.cpp $(START_DIR)/codegen/lib/ITER_API/conv2AXPYValidCMP.cpp $(START_DIR)/codegen/lib/ITER_API/mod.cpp $(START_DIR)/codegen/lib/ITER_API/find_peaks.cpp $(START_DIR)/codegen/lib/ITER_API/bwlookup.cpp $(START_DIR)/codegen/lib/ITER_API/detectCheckerboard.cpp $(START_DIR)/codegen/lib/ITER_API/minOrMax.cpp $(START_DIR)/codegen/lib/ITER_API/mean.cpp $(START_DIR)/codegen/lib/ITER_API/find.cpp $(START_DIR)/codegen/lib/ITER_API/polyfit.cpp $(START_DIR)/codegen/lib/ITER_API/qrsolve.cpp $(START_DIR)/codegen/lib/ITER_API/xnrm2.cpp $(START_DIR)/codegen/lib/ITER_API/eml_setop.cpp $(START_DIR)/codegen/lib/ITER_API/sortIdx.cpp $(START_DIR)/codegen/lib/ITER_API/colon.cpp $(START_DIR)/codegen/lib/ITER_API/squeeze.cpp $(START_DIR)/codegen/lib/ITER_API/ismember.cpp $(START_DIR)/codegen/lib/ITER_API/norm.cpp $(START_DIR)/codegen/lib/ITER_API/combineVectorElements.cpp $(START_DIR)/codegen/lib/ITER_API/rot90.cpp $(START_DIR)/codegen/lib/ITER_API/cat.cpp $(START_DIR)/codegen/lib/ITER_API/computeInitialParameterEstimate.cpp $(START_DIR)/codegen/lib/ITER_API/fitgeotrans.cpp $(START_DIR)/codegen/lib/ITER_API/normalizeControlPoints.cpp $(START_DIR)/codegen/lib/ITER_API/svd.cpp $(START_DIR)/codegen/lib/ITER_API/inv.cpp $(START_DIR)/codegen/lib/ITER_API/det.cpp $(START_DIR)/codegen/lib/ITER_API/xdotc.cpp $(START_DIR)/codegen/lib/ITER_API/svd1.cpp $(START_DIR)/codegen/lib/ITER_API/worldToImage.cpp $(START_DIR)/codegen/lib/ITER_API/ComputeCamExtrinsics.cpp $(START_DIR)/codegen/lib/ITER_API/mldivide.cpp $(START_DIR)/codegen/lib/ITER_API/computeErrors.cpp $(START_DIR)/codegen/lib/ITER_API/rotm2axang.cpp $(START_DIR)/codegen/lib/ITER_API/HandeyeShah.cpp $(START_DIR)/codegen/lib/ITER_API/preprocessImages.cpp $(START_DIR)/codegen/lib/ITER_API/rgb2gray.cpp $(START_DIR)/codegen/lib/ITER_API/interp2.cpp $(START_DIR)/codegen/lib/ITER_API/bsearch.cpp $(START_DIR)/codegen/lib/ITER_API/readRobotPoses.cpp $(START_DIR)/codegen/lib/ITER_API/subPixelLocation.cpp $(START_DIR)/codegen/lib/ITER_API/xrotg.cpp $(START_DIR)/codegen/lib/ITER_API/algbwmorph.cpp $(START_DIR)/codegen/lib/ITER_API/sort.cpp $(START_DIR)/codegen/lib/ITER_API/xgeqp3.cpp $(START_DIR)/codegen/lib/ITER_API/xzlarfg.cpp $(START_DIR)/codegen/lib/ITER_API/xzlarf.cpp $(START_DIR)/codegen/lib/ITER_API/xunormqr.cpp $(START_DIR)/codegen/lib/ITER_API/flip.cpp $(START_DIR)/codegen/lib/ITER_API/xaxpy.cpp $(START_DIR)/codegen/lib/ITER_API/xrot.cpp $(START_DIR)/codegen/lib/ITER_API/xswap.cpp $(START_DIR)/codegen/lib/ITER_API/lsqnonlin.cpp $(START_DIR)/codegen/lib/ITER_API/xgemv.cpp $(START_DIR)/codegen/lib/ITER_API/linearLeastSquares.cpp $(START_DIR)/codegen/lib/ITER_API/sqrt.cpp $(START_DIR)/codegen/lib/ITER_API/unsafeSxfun.cpp $(START_DIR)/codegen/lib/ITER_API/factoryConstruct.cpp $(START_DIR)/codegen/lib/ITER_API/jacobianFiniteDifference.cpp $(START_DIR)/codegen/lib/ITER_API/driver.cpp $(START_DIR)/codegen/lib/ITER_API/checkStoppingCriteria.cpp $(START_DIR)/codegen/lib/ITER_API/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/ITER_API/computeCentralDifferences.cpp $(START_DIR)/codegen/lib/ITER_API/finDiffEvalAndChkErr.cpp $(START_DIR)/codegen/lib/ITER_API/ImageTransformer.cpp $(START_DIR)/codegen/lib/ITER_API/cameraParameters.cpp $(START_DIR)/codegen/lib/ITER_API/Checkerboard.cpp $(START_DIR)/codegen/lib/ITER_API/NeighborhoodProcessor.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = ITER_API_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj ITER_API_initialize.obj ITER_API_terminate.obj calibrateOneCamera_v2.obj isequal.obj detectCheckerboardPoints.obj imfilter.obj conv2AXPYValidCMP.obj mod.obj find_peaks.obj bwlookup.obj detectCheckerboard.obj minOrMax.obj mean.obj find.obj polyfit.obj qrsolve.obj xnrm2.obj eml_setop.obj sortIdx.obj colon.obj squeeze.obj ismember.obj norm.obj combineVectorElements.obj rot90.obj cat.obj computeInitialParameterEstimate.obj fitgeotrans.obj normalizeControlPoints.obj svd.obj inv.obj det.obj xdotc.obj svd1.obj worldToImage.obj ComputeCamExtrinsics.obj mldivide.obj computeErrors.obj rotm2axang.obj HandeyeShah.obj preprocessImages.obj rgb2gray.obj interp2.obj bsearch.obj readRobotPoses.obj subPixelLocation.obj xrotg.obj algbwmorph.obj sort.obj xgeqp3.obj xzlarfg.obj xzlarf.obj xunormqr.obj flip.obj xaxpy.obj xrot.obj xswap.obj lsqnonlin.obj xgemv.obj linearLeastSquares.obj sqrt.obj unsafeSxfun.obj factoryConstruct.obj jacobianFiniteDifference.obj driver.obj checkStoppingCriteria.obj computeFiniteDifferences.obj computeCentralDifferences.obj finDiffEvalAndChkErr.obj ImageTransformer.obj cameraParameters.obj Checkerboard.obj NeighborhoodProcessor.obj ITER_API_rtwutil.obj

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


%.obj : $(START_DIR)/codegen/lib/ITER_API/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/ITER_API/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_data.obj : $(START_DIR)/codegen/lib/ITER_API/ITER_API_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/ITER_API/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/ITER_API/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/ITER_API/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_initialize.obj : $(START_DIR)/codegen/lib/ITER_API/ITER_API_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_terminate.obj : $(START_DIR)/codegen/lib/ITER_API/ITER_API_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateOneCamera_v2.obj : $(START_DIR)/codegen/lib/ITER_API/calibrateOneCamera_v2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.obj : $(START_DIR)/codegen/lib/ITER_API/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboardPoints.obj : $(START_DIR)/codegen/lib/ITER_API/detectCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/ITER_API/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


conv2AXPYValidCMP.obj : $(START_DIR)/codegen/lib/ITER_API/conv2AXPYValidCMP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mod.obj : $(START_DIR)/codegen/lib/ITER_API/mod.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find_peaks.obj : $(START_DIR)/codegen/lib/ITER_API/find_peaks.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwlookup.obj : $(START_DIR)/codegen/lib/ITER_API/bwlookup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboard.obj : $(START_DIR)/codegen/lib/ITER_API/detectCheckerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/ITER_API/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/ITER_API/mean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/ITER_API/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


polyfit.obj : $(START_DIR)/codegen/lib/ITER_API/polyfit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


qrsolve.obj : $(START_DIR)/codegen/lib/ITER_API/qrsolve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/ITER_API/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_setop.obj : $(START_DIR)/codegen/lib/ITER_API/eml_setop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/ITER_API/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.obj : $(START_DIR)/codegen/lib/ITER_API/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/lib/ITER_API/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ismember.obj : $(START_DIR)/codegen/lib/ITER_API/ismember.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.obj : $(START_DIR)/codegen/lib/ITER_API/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.obj : $(START_DIR)/codegen/lib/ITER_API/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rot90.obj : $(START_DIR)/codegen/lib/ITER_API/rot90.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cat.obj : $(START_DIR)/codegen/lib/ITER_API/cat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeInitialParameterEstimate.obj : $(START_DIR)/codegen/lib/ITER_API/computeInitialParameterEstimate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fitgeotrans.obj : $(START_DIR)/codegen/lib/ITER_API/fitgeotrans.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


normalizeControlPoints.obj : $(START_DIR)/codegen/lib/ITER_API/normalizeControlPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/ITER_API/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inv.obj : $(START_DIR)/codegen/lib/ITER_API/inv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


det.obj : $(START_DIR)/codegen/lib/ITER_API/det.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/ITER_API/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd1.obj : $(START_DIR)/codegen/lib/ITER_API/svd1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


worldToImage.obj : $(START_DIR)/codegen/lib/ITER_API/worldToImage.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ComputeCamExtrinsics.obj : $(START_DIR)/codegen/lib/ITER_API/ComputeCamExtrinsics.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.obj : $(START_DIR)/codegen/lib/ITER_API/mldivide.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeErrors.obj : $(START_DIR)/codegen/lib/ITER_API/computeErrors.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotm2axang.obj : $(START_DIR)/codegen/lib/ITER_API/rotm2axang.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


HandeyeShah.obj : $(START_DIR)/codegen/lib/ITER_API/HandeyeShah.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


preprocessImages.obj : $(START_DIR)/codegen/lib/ITER_API/preprocessImages.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rgb2gray.obj : $(START_DIR)/codegen/lib/ITER_API/rgb2gray.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


interp2.obj : $(START_DIR)/codegen/lib/ITER_API/interp2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bsearch.obj : $(START_DIR)/codegen/lib/ITER_API/bsearch.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


readRobotPoses.obj : $(START_DIR)/codegen/lib/ITER_API/readRobotPoses.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


subPixelLocation.obj : $(START_DIR)/codegen/lib/ITER_API/subPixelLocation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/ITER_API/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


algbwmorph.obj : $(START_DIR)/codegen/lib/ITER_API/algbwmorph.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/ITER_API/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/ITER_API/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/ITER_API/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/ITER_API/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xunormqr.obj : $(START_DIR)/codegen/lib/ITER_API/xunormqr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


flip.obj : $(START_DIR)/codegen/lib/ITER_API/flip.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/ITER_API/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/ITER_API/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/ITER_API/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lsqnonlin.obj : $(START_DIR)/codegen/lib/ITER_API/lsqnonlin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/ITER_API/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearLeastSquares.obj : $(START_DIR)/codegen/lib/ITER_API/linearLeastSquares.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.obj : $(START_DIR)/codegen/lib/ITER_API/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.obj : $(START_DIR)/codegen/lib/ITER_API/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/codegen/lib/ITER_API/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


jacobianFiniteDifference.obj : $(START_DIR)/codegen/lib/ITER_API/jacobianFiniteDifference.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/ITER_API/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingCriteria.obj : $(START_DIR)/codegen/lib/ITER_API/checkStoppingCriteria.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/ITER_API/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeCentralDifferences.obj : $(START_DIR)/codegen/lib/ITER_API/computeCentralDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/ITER_API/finDiffEvalAndChkErr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ImageTransformer.obj : $(START_DIR)/codegen/lib/ITER_API/ImageTransformer.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cameraParameters.obj : $(START_DIR)/codegen/lib/ITER_API/cameraParameters.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Checkerboard.obj : $(START_DIR)/codegen/lib/ITER_API/Checkerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


NeighborhoodProcessor.obj : $(START_DIR)/codegen/lib/ITER_API/NeighborhoodProcessor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ITER_API_rtwutil.obj : $(START_DIR)/codegen/lib/ITER_API/ITER_API_rtwutil.cpp
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


