###########################################################################
## Makefile generated for component 'ITER_API'. 
## 
## Makefile     : ITER_API_rtw.mk
## Generated on : Tue Apr 05 09:11:45 2022
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
START_DIR                 = D:/TUT_Research/Gitlab/f4e-grt/ITER-SW-MATLAB-CombinedCode
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

SRCS = $(START_DIR)/codegen/lib/ITER_API/ITER_API_data.cpp $(START_DIR)/codegen/lib/ITER_API/rt_nonfinite.cpp $(START_DIR)/codegen/lib/ITER_API/rtGetNaN.cpp $(START_DIR)/codegen/lib/ITER_API/rtGetInf.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_initialize.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_terminate.cpp $(START_DIR)/codegen/lib/ITER_API/calibrateOneCamera.cpp $(START_DIR)/codegen/lib/ITER_API/isequal.cpp $(START_DIR)/codegen/lib/ITER_API/detectCheckerboardPoints.cpp $(START_DIR)/codegen/lib/ITER_API/secondDerivCornerMetric.cpp $(START_DIR)/codegen/lib/ITER_API/imfilter.cpp $(START_DIR)/codegen/lib/ITER_API/xnrm2.cpp $(START_DIR)/codegen/lib/ITER_API/conv2AXPYValidCMP.cpp $(START_DIR)/codegen/lib/ITER_API/mod.cpp $(START_DIR)/codegen/lib/ITER_API/find_peaks.cpp $(START_DIR)/codegen/lib/ITER_API/bwlookup.cpp $(START_DIR)/codegen/lib/ITER_API/detectCheckerboard.cpp $(START_DIR)/codegen/lib/ITER_API/hypot.cpp $(START_DIR)/codegen/lib/ITER_API/minOrMax.cpp $(START_DIR)/codegen/lib/ITER_API/mean.cpp $(START_DIR)/codegen/lib/ITER_API/find.cpp $(START_DIR)/codegen/lib/ITER_API/polyfit.cpp $(START_DIR)/codegen/lib/ITER_API/qrsolve.cpp $(START_DIR)/codegen/lib/ITER_API/eml_setop.cpp $(START_DIR)/codegen/lib/ITER_API/sortIdx.cpp $(START_DIR)/codegen/lib/ITER_API/colon.cpp $(START_DIR)/codegen/lib/ITER_API/squeeze.cpp $(START_DIR)/codegen/lib/ITER_API/bsxfun.cpp $(START_DIR)/codegen/lib/ITER_API/ismember.cpp $(START_DIR)/codegen/lib/ITER_API/norm.cpp $(START_DIR)/codegen/lib/ITER_API/combineVectorElements.cpp $(START_DIR)/codegen/lib/ITER_API/rot90.cpp $(START_DIR)/codegen/lib/ITER_API/cat.cpp $(START_DIR)/codegen/lib/ITER_API/computeInitialParameterEstimate.cpp $(START_DIR)/codegen/lib/ITER_API/fitgeotrans.cpp $(START_DIR)/codegen/lib/ITER_API/normalizeControlPoints.cpp $(START_DIR)/codegen/lib/ITER_API/power.cpp $(START_DIR)/codegen/lib/ITER_API/rank.cpp $(START_DIR)/codegen/lib/ITER_API/svd.cpp $(START_DIR)/codegen/lib/ITER_API/mldivide.cpp $(START_DIR)/codegen/lib/ITER_API/inv.cpp $(START_DIR)/codegen/lib/ITER_API/det.cpp $(START_DIR)/codegen/lib/ITER_API/xdotc.cpp $(START_DIR)/codegen/lib/ITER_API/svd1.cpp $(START_DIR)/codegen/lib/ITER_API/worldToImage.cpp $(START_DIR)/codegen/lib/ITER_API/sum.cpp $(START_DIR)/codegen/lib/ITER_API/computeCalibrationPoses_internal.cpp $(START_DIR)/codegen/lib/ITER_API/rgb2gray.cpp $(START_DIR)/codegen/lib/ITER_API/linspace.cpp $(START_DIR)/codegen/lib/ITER_API/ComputeCamExtrinsics.cpp $(START_DIR)/codegen/lib/ITER_API/computeErrors.cpp $(START_DIR)/codegen/lib/ITER_API/rotm2axang.cpp $(START_DIR)/codegen/lib/ITER_API/estimatePitagPose.cpp $(START_DIR)/codegen/lib/ITER_API/rotm2quat.cpp $(START_DIR)/codegen/lib/ITER_API/schur.cpp $(START_DIR)/codegen/lib/ITER_API/xzlartg.cpp $(START_DIR)/codegen/lib/ITER_API/fmincon.cpp $(START_DIR)/codegen/lib/ITER_API/quat2rotm.cpp $(START_DIR)/codegen/lib/ITER_API/optimizeCamPose.cpp $(START_DIR)/codegen/lib/ITER_API/computePrimalFeasError.cpp $(START_DIR)/codegen/lib/ITER_API/computeDualFeasError.cpp $(START_DIR)/codegen/lib/ITER_API/computeComplError.cpp $(START_DIR)/codegen/lib/ITER_API/ixamax.cpp $(START_DIR)/codegen/lib/ITER_API/printInfo.cpp $(START_DIR)/codegen/lib/ITER_API/HandeyeShah.cpp $(START_DIR)/codegen/lib/ITER_API/isT.cpp $(START_DIR)/codegen/lib/ITER_API/preprocessImages.cpp $(START_DIR)/codegen/lib/ITER_API/interp2.cpp $(START_DIR)/codegen/lib/ITER_API/bsearch.cpp $(START_DIR)/codegen/lib/ITER_API/readRobotPoses.cpp $(START_DIR)/codegen/lib/ITER_API/subPixelLocation.cpp $(START_DIR)/codegen/lib/ITER_API/xrotg.cpp $(START_DIR)/codegen/lib/ITER_API/algbwmorph.cpp $(START_DIR)/codegen/lib/ITER_API/sort.cpp $(START_DIR)/codegen/lib/ITER_API/xgeqp3.cpp $(START_DIR)/codegen/lib/ITER_API/xzlarfg.cpp $(START_DIR)/codegen/lib/ITER_API/xzlarf.cpp $(START_DIR)/codegen/lib/ITER_API/xunormqr.cpp $(START_DIR)/codegen/lib/ITER_API/flip.cpp $(START_DIR)/codegen/lib/ITER_API/xaxpy.cpp $(START_DIR)/codegen/lib/ITER_API/xrot.cpp $(START_DIR)/codegen/lib/ITER_API/xswap.cpp $(START_DIR)/codegen/lib/ITER_API/lsqnonlin.cpp $(START_DIR)/codegen/lib/ITER_API/projectBox.cpp $(START_DIR)/codegen/lib/ITER_API/fwdFinDiffInsideBnds.cpp $(START_DIR)/codegen/lib/ITER_API/cntrlFinDiffInsideBnds.cpp $(START_DIR)/codegen/lib/ITER_API/xgemv.cpp $(START_DIR)/codegen/lib/ITER_API/driver.cpp $(START_DIR)/codegen/lib/ITER_API/linearLeastSquares.cpp $(START_DIR)/codegen/lib/ITER_API/sqrt.cpp $(START_DIR)/codegen/lib/ITER_API/xdhseqr.cpp $(START_DIR)/codegen/lib/ITER_API/xdlanv2.cpp $(START_DIR)/codegen/lib/ITER_API/xzggev.cpp $(START_DIR)/codegen/lib/ITER_API/xzhgeqz.cpp $(START_DIR)/codegen/lib/ITER_API/xztgevc.cpp $(START_DIR)/codegen/lib/ITER_API/computeForwardDifferences.cpp $(START_DIR)/codegen/lib/ITER_API/finDiffEvalAndChkErr.cpp $(START_DIR)/codegen/lib/ITER_API/computeCentralDifferences.cpp $(START_DIR)/codegen/lib/ITER_API/setProblemType.cpp $(START_DIR)/codegen/lib/ITER_API/modifyOverheadPhaseOne_.cpp $(START_DIR)/codegen/lib/ITER_API/computeGradLag.cpp $(START_DIR)/codegen/lib/ITER_API/updateWorkingSetForNewQP.cpp $(START_DIR)/codegen/lib/ITER_API/test_exit.cpp $(START_DIR)/codegen/lib/ITER_API/computeLambdaLSQ.cpp $(START_DIR)/codegen/lib/ITER_API/computeQ_.cpp $(START_DIR)/codegen/lib/ITER_API/sortLambdaQP.cpp $(START_DIR)/codegen/lib/ITER_API/countsort.cpp $(START_DIR)/codegen/lib/ITER_API/removeConstr.cpp $(START_DIR)/codegen/lib/ITER_API/RemoveDependentIneq_.cpp $(START_DIR)/codegen/lib/ITER_API/step.cpp $(START_DIR)/codegen/lib/ITER_API/driver1.cpp $(START_DIR)/codegen/lib/ITER_API/PresolveWorkingSet.cpp $(START_DIR)/codegen/lib/ITER_API/feasibleX0ForWorkingSet.cpp $(START_DIR)/codegen/lib/ITER_API/factorQR.cpp $(START_DIR)/codegen/lib/ITER_API/maxConstraintViolation.cpp $(START_DIR)/codegen/lib/ITER_API/computeFval.cpp $(START_DIR)/codegen/lib/ITER_API/linearForm_.cpp $(START_DIR)/codegen/lib/ITER_API/iterate.cpp $(START_DIR)/codegen/lib/ITER_API/computeGrad_StoreHx.cpp $(START_DIR)/codegen/lib/ITER_API/computeFval_ReuseHx.cpp $(START_DIR)/codegen/lib/ITER_API/squareQ_appendCol.cpp $(START_DIR)/codegen/lib/ITER_API/deleteColMoveEnd.cpp $(START_DIR)/codegen/lib/ITER_API/compute_deltax.cpp $(START_DIR)/codegen/lib/ITER_API/xpotrf.cpp $(START_DIR)/codegen/lib/ITER_API/factor.cpp $(START_DIR)/codegen/lib/ITER_API/solve.cpp $(START_DIR)/codegen/lib/ITER_API/solve1.cpp $(START_DIR)/codegen/lib/ITER_API/xgemm.cpp $(START_DIR)/codegen/lib/ITER_API/feasibleratiotest.cpp $(START_DIR)/codegen/lib/ITER_API/addBoundToActiveSetMatrix_.cpp $(START_DIR)/codegen/lib/ITER_API/checkStoppingAndUpdateFval.cpp $(START_DIR)/codegen/lib/ITER_API/relaxed.cpp $(START_DIR)/codegen/lib/ITER_API/BFGSUpdate.cpp $(START_DIR)/codegen/lib/ITER_API/driver2.cpp $(START_DIR)/codegen/lib/ITER_API/xzgeqp3.cpp $(START_DIR)/codegen/lib/ITER_API/fullColLDL2_.cpp $(START_DIR)/codegen/lib/ITER_API/unsafeSxfun.cpp $(START_DIR)/codegen/lib/ITER_API/costFunc1.cpp $(START_DIR)/codegen/lib/ITER_API/factoryConstruct.cpp $(START_DIR)/codegen/lib/ITER_API/jacobianFiniteDifference.cpp $(START_DIR)/codegen/lib/ITER_API/checkStoppingCriteria.cpp $(START_DIR)/codegen/lib/ITER_API/hasFiniteBounds.cpp $(START_DIR)/codegen/lib/ITER_API/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/ITER_API/ratiotest.cpp $(START_DIR)/codegen/lib/ITER_API/ImageTransformer.cpp $(START_DIR)/codegen/lib/ITER_API/cameraParameters.cpp $(START_DIR)/codegen/lib/ITER_API/Checkerboard.cpp $(START_DIR)/codegen/lib/ITER_API/NeighborhoodProcessor.cpp $(START_DIR)/codegen/lib/ITER_API/ITER_API_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = ITER_API_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj ITER_API_initialize.obj ITER_API_terminate.obj calibrateOneCamera.obj isequal.obj detectCheckerboardPoints.obj secondDerivCornerMetric.obj imfilter.obj xnrm2.obj conv2AXPYValidCMP.obj mod.obj find_peaks.obj bwlookup.obj detectCheckerboard.obj hypot.obj minOrMax.obj mean.obj find.obj polyfit.obj qrsolve.obj eml_setop.obj sortIdx.obj colon.obj squeeze.obj bsxfun.obj ismember.obj norm.obj combineVectorElements.obj rot90.obj cat.obj computeInitialParameterEstimate.obj fitgeotrans.obj normalizeControlPoints.obj power.obj rank.obj svd.obj mldivide.obj inv.obj det.obj xdotc.obj svd1.obj worldToImage.obj sum.obj computeCalibrationPoses_internal.obj rgb2gray.obj linspace.obj ComputeCamExtrinsics.obj computeErrors.obj rotm2axang.obj estimatePitagPose.obj rotm2quat.obj schur.obj xzlartg.obj fmincon.obj quat2rotm.obj optimizeCamPose.obj computePrimalFeasError.obj computeDualFeasError.obj computeComplError.obj ixamax.obj printInfo.obj HandeyeShah.obj isT.obj preprocessImages.obj interp2.obj bsearch.obj readRobotPoses.obj subPixelLocation.obj xrotg.obj algbwmorph.obj sort.obj xgeqp3.obj xzlarfg.obj xzlarf.obj xunormqr.obj flip.obj xaxpy.obj xrot.obj xswap.obj lsqnonlin.obj projectBox.obj fwdFinDiffInsideBnds.obj cntrlFinDiffInsideBnds.obj xgemv.obj driver.obj linearLeastSquares.obj sqrt.obj xdhseqr.obj xdlanv2.obj xzggev.obj xzhgeqz.obj xztgevc.obj computeForwardDifferences.obj finDiffEvalAndChkErr.obj computeCentralDifferences.obj setProblemType.obj modifyOverheadPhaseOne_.obj computeGradLag.obj updateWorkingSetForNewQP.obj test_exit.obj computeLambdaLSQ.obj computeQ_.obj sortLambdaQP.obj countsort.obj removeConstr.obj RemoveDependentIneq_.obj step.obj driver1.obj PresolveWorkingSet.obj feasibleX0ForWorkingSet.obj factorQR.obj maxConstraintViolation.obj computeFval.obj linearForm_.obj iterate.obj computeGrad_StoreHx.obj computeFval_ReuseHx.obj squareQ_appendCol.obj deleteColMoveEnd.obj compute_deltax.obj xpotrf.obj factor.obj solve.obj solve1.obj xgemm.obj feasibleratiotest.obj addBoundToActiveSetMatrix_.obj checkStoppingAndUpdateFval.obj relaxed.obj BFGSUpdate.obj driver2.obj xzgeqp3.obj fullColLDL2_.obj unsafeSxfun.obj costFunc1.obj factoryConstruct.obj jacobianFiniteDifference.obj checkStoppingCriteria.obj hasFiniteBounds.obj computeFiniteDifferences.obj ratiotest.obj ImageTransformer.obj cameraParameters.obj Checkerboard.obj NeighborhoodProcessor.obj ITER_API_rtwutil.obj

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


calibrateOneCamera.obj : $(START_DIR)/codegen/lib/ITER_API/calibrateOneCamera.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.obj : $(START_DIR)/codegen/lib/ITER_API/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboardPoints.obj : $(START_DIR)/codegen/lib/ITER_API/detectCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


secondDerivCornerMetric.obj : $(START_DIR)/codegen/lib/ITER_API/secondDerivCornerMetric.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/ITER_API/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/ITER_API/xnrm2.cpp
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


hypot.obj : $(START_DIR)/codegen/lib/ITER_API/hypot.cpp
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


eml_setop.obj : $(START_DIR)/codegen/lib/ITER_API/eml_setop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/ITER_API/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.obj : $(START_DIR)/codegen/lib/ITER_API/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/lib/ITER_API/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bsxfun.obj : $(START_DIR)/codegen/lib/ITER_API/bsxfun.cpp
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


power.obj : $(START_DIR)/codegen/lib/ITER_API/power.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rank.obj : $(START_DIR)/codegen/lib/ITER_API/rank.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/ITER_API/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.obj : $(START_DIR)/codegen/lib/ITER_API/mldivide.cpp
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


sum.obj : $(START_DIR)/codegen/lib/ITER_API/sum.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeCalibrationPoses_internal.obj : $(START_DIR)/codegen/lib/ITER_API/computeCalibrationPoses_internal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rgb2gray.obj : $(START_DIR)/codegen/lib/ITER_API/rgb2gray.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linspace.obj : $(START_DIR)/codegen/lib/ITER_API/linspace.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ComputeCamExtrinsics.obj : $(START_DIR)/codegen/lib/ITER_API/ComputeCamExtrinsics.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeErrors.obj : $(START_DIR)/codegen/lib/ITER_API/computeErrors.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotm2axang.obj : $(START_DIR)/codegen/lib/ITER_API/rotm2axang.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


estimatePitagPose.obj : $(START_DIR)/codegen/lib/ITER_API/estimatePitagPose.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotm2quat.obj : $(START_DIR)/codegen/lib/ITER_API/rotm2quat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


schur.obj : $(START_DIR)/codegen/lib/ITER_API/schur.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlartg.obj : $(START_DIR)/codegen/lib/ITER_API/xzlartg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fmincon.obj : $(START_DIR)/codegen/lib/ITER_API/fmincon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


quat2rotm.obj : $(START_DIR)/codegen/lib/ITER_API/quat2rotm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


optimizeCamPose.obj : $(START_DIR)/codegen/lib/ITER_API/optimizeCamPose.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computePrimalFeasError.obj : $(START_DIR)/codegen/lib/ITER_API/computePrimalFeasError.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeDualFeasError.obj : $(START_DIR)/codegen/lib/ITER_API/computeDualFeasError.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeComplError.obj : $(START_DIR)/codegen/lib/ITER_API/computeComplError.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ixamax.obj : $(START_DIR)/codegen/lib/ITER_API/ixamax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


printInfo.obj : $(START_DIR)/codegen/lib/ITER_API/printInfo.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


HandeyeShah.obj : $(START_DIR)/codegen/lib/ITER_API/HandeyeShah.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isT.obj : $(START_DIR)/codegen/lib/ITER_API/isT.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


preprocessImages.obj : $(START_DIR)/codegen/lib/ITER_API/preprocessImages.cpp
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


projectBox.obj : $(START_DIR)/codegen/lib/ITER_API/projectBox.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fwdFinDiffInsideBnds.obj : $(START_DIR)/codegen/lib/ITER_API/fwdFinDiffInsideBnds.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cntrlFinDiffInsideBnds.obj : $(START_DIR)/codegen/lib/ITER_API/cntrlFinDiffInsideBnds.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/ITER_API/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/ITER_API/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearLeastSquares.obj : $(START_DIR)/codegen/lib/ITER_API/linearLeastSquares.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.obj : $(START_DIR)/codegen/lib/ITER_API/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdhseqr.obj : $(START_DIR)/codegen/lib/ITER_API/xdhseqr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdlanv2.obj : $(START_DIR)/codegen/lib/ITER_API/xdlanv2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzggev.obj : $(START_DIR)/codegen/lib/ITER_API/xzggev.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzhgeqz.obj : $(START_DIR)/codegen/lib/ITER_API/xzhgeqz.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xztgevc.obj : $(START_DIR)/codegen/lib/ITER_API/xztgevc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeForwardDifferences.obj : $(START_DIR)/codegen/lib/ITER_API/computeForwardDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/ITER_API/finDiffEvalAndChkErr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeCentralDifferences.obj : $(START_DIR)/codegen/lib/ITER_API/computeCentralDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


setProblemType.obj : $(START_DIR)/codegen/lib/ITER_API/setProblemType.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


modifyOverheadPhaseOne_.obj : $(START_DIR)/codegen/lib/ITER_API/modifyOverheadPhaseOne_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeGradLag.obj : $(START_DIR)/codegen/lib/ITER_API/computeGradLag.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


updateWorkingSetForNewQP.obj : $(START_DIR)/codegen/lib/ITER_API/updateWorkingSetForNewQP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


test_exit.obj : $(START_DIR)/codegen/lib/ITER_API/test_exit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeLambdaLSQ.obj : $(START_DIR)/codegen/lib/ITER_API/computeLambdaLSQ.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeQ_.obj : $(START_DIR)/codegen/lib/ITER_API/computeQ_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortLambdaQP.obj : $(START_DIR)/codegen/lib/ITER_API/sortLambdaQP.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


countsort.obj : $(START_DIR)/codegen/lib/ITER_API/countsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


removeConstr.obj : $(START_DIR)/codegen/lib/ITER_API/removeConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


RemoveDependentIneq_.obj : $(START_DIR)/codegen/lib/ITER_API/RemoveDependentIneq_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


step.obj : $(START_DIR)/codegen/lib/ITER_API/step.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver1.obj : $(START_DIR)/codegen/lib/ITER_API/driver1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PresolveWorkingSet.obj : $(START_DIR)/codegen/lib/ITER_API/PresolveWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleX0ForWorkingSet.obj : $(START_DIR)/codegen/lib/ITER_API/feasibleX0ForWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factorQR.obj : $(START_DIR)/codegen/lib/ITER_API/factorQR.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


maxConstraintViolation.obj : $(START_DIR)/codegen/lib/ITER_API/maxConstraintViolation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval.obj : $(START_DIR)/codegen/lib/ITER_API/computeFval.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearForm_.obj : $(START_DIR)/codegen/lib/ITER_API/linearForm_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


iterate.obj : $(START_DIR)/codegen/lib/ITER_API/iterate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeGrad_StoreHx.obj : $(START_DIR)/codegen/lib/ITER_API/computeGrad_StoreHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval_ReuseHx.obj : $(START_DIR)/codegen/lib/ITER_API/computeFval_ReuseHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squareQ_appendCol.obj : $(START_DIR)/codegen/lib/ITER_API/squareQ_appendCol.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


deleteColMoveEnd.obj : $(START_DIR)/codegen/lib/ITER_API/deleteColMoveEnd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


compute_deltax.obj : $(START_DIR)/codegen/lib/ITER_API/compute_deltax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xpotrf.obj : $(START_DIR)/codegen/lib/ITER_API/xpotrf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factor.obj : $(START_DIR)/codegen/lib/ITER_API/factor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


solve.obj : $(START_DIR)/codegen/lib/ITER_API/solve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


solve1.obj : $(START_DIR)/codegen/lib/ITER_API/solve1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemm.obj : $(START_DIR)/codegen/lib/ITER_API/xgemm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleratiotest.obj : $(START_DIR)/codegen/lib/ITER_API/feasibleratiotest.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


addBoundToActiveSetMatrix_.obj : $(START_DIR)/codegen/lib/ITER_API/addBoundToActiveSetMatrix_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingAndUpdateFval.obj : $(START_DIR)/codegen/lib/ITER_API/checkStoppingAndUpdateFval.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


relaxed.obj : $(START_DIR)/codegen/lib/ITER_API/relaxed.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


BFGSUpdate.obj : $(START_DIR)/codegen/lib/ITER_API/BFGSUpdate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver2.obj : $(START_DIR)/codegen/lib/ITER_API/driver2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzgeqp3.obj : $(START_DIR)/codegen/lib/ITER_API/xzgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fullColLDL2_.obj : $(START_DIR)/codegen/lib/ITER_API/fullColLDL2_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.obj : $(START_DIR)/codegen/lib/ITER_API/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


costFunc1.obj : $(START_DIR)/codegen/lib/ITER_API/costFunc1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/codegen/lib/ITER_API/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


jacobianFiniteDifference.obj : $(START_DIR)/codegen/lib/ITER_API/jacobianFiniteDifference.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingCriteria.obj : $(START_DIR)/codegen/lib/ITER_API/checkStoppingCriteria.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


hasFiniteBounds.obj : $(START_DIR)/codegen/lib/ITER_API/hasFiniteBounds.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/ITER_API/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ratiotest.obj : $(START_DIR)/codegen/lib/ITER_API/ratiotest.cpp
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


