###########################################################################
## Makefile generated for component 'calibrateCamera'. 
## 
## Makefile     : calibrateCamera_rtw.mk
## Generated on : Wed Oct 06 21:51:31 2021
## Final product: ./calibrateCamera.lib
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

PRODUCT_NAME              = calibrateCamera
MAKEFILE                  = calibrateCamera_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/TUT_Research/Gitlab/f4e-grt/ITER-SW-CameraCalibration/Matlab-code-V2
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = calibrateCamera_rtw_comp.rsp
CMD_FILE                  = calibrateCamera_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = calibrateCamera.lib

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

PRODUCT = ./calibrateCamera.lib
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
DEFINES_STANDARD = -DMODEL=calibrateCamera

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_data.cpp $(START_DIR)/codegen/lib/calibrateCamera/rt_nonfinite.cpp $(START_DIR)/codegen/lib/calibrateCamera/rtGetNaN.cpp $(START_DIR)/codegen/lib/calibrateCamera/rtGetInf.cpp $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_initialize.cpp $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_terminate.cpp $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera.cpp $(START_DIR)/codegen/lib/calibrateCamera/isequal.cpp $(START_DIR)/codegen/lib/calibrateCamera/detectCheckerboardPoints.cpp $(START_DIR)/codegen/lib/calibrateCamera/imfilter.cpp $(START_DIR)/codegen/lib/calibrateCamera/find_peaks.cpp $(START_DIR)/codegen/lib/calibrateCamera/imregionalmax.cpp $(START_DIR)/codegen/lib/calibrateCamera/bwlookup.cpp $(START_DIR)/codegen/lib/calibrateCamera/detectCheckerboard.cpp $(START_DIR)/codegen/lib/calibrateCamera/minOrMax.cpp $(START_DIR)/codegen/lib/calibrateCamera/mean.cpp $(START_DIR)/codegen/lib/calibrateCamera/find.cpp $(START_DIR)/codegen/lib/calibrateCamera/polyfit.cpp $(START_DIR)/codegen/lib/calibrateCamera/qrsolve.cpp $(START_DIR)/codegen/lib/calibrateCamera/xnrm2.cpp $(START_DIR)/codegen/lib/calibrateCamera/eml_setop.cpp $(START_DIR)/codegen/lib/calibrateCamera/sortIdx.cpp $(START_DIR)/codegen/lib/calibrateCamera/squeeze.cpp $(START_DIR)/codegen/lib/calibrateCamera/norm.cpp $(START_DIR)/codegen/lib/calibrateCamera/combineVectorElements.cpp $(START_DIR)/codegen/lib/calibrateCamera/cat.cpp $(START_DIR)/codegen/lib/calibrateCamera/computeInitialParameterEstimate.cpp $(START_DIR)/codegen/lib/calibrateCamera/fitgeotrans.cpp $(START_DIR)/codegen/lib/calibrateCamera/normalizeControlPoints.cpp $(START_DIR)/codegen/lib/calibrateCamera/svd.cpp $(START_DIR)/codegen/lib/calibrateCamera/inv.cpp $(START_DIR)/codegen/lib/calibrateCamera/xdotc.cpp $(START_DIR)/codegen/lib/calibrateCamera/rodriguesMatrixToVector.cpp $(START_DIR)/codegen/lib/calibrateCamera/unserializeCalib.cpp $(START_DIR)/codegen/lib/calibrateCamera/CalculateCost.cpp $(START_DIR)/codegen/lib/calibrateCamera/factoryConstruct.cpp $(START_DIR)/codegen/lib/calibrateCamera/my_nlparci.cpp $(START_DIR)/codegen/lib/calibrateCamera/qr.cpp $(START_DIR)/codegen/lib/calibrateCamera/mldivide.cpp $(START_DIR)/codegen/lib/calibrateCamera/eml_betainc.cpp $(START_DIR)/codegen/lib/calibrateCamera/subPixelLocation.cpp $(START_DIR)/codegen/lib/calibrateCamera/xrotg.cpp $(START_DIR)/codegen/lib/calibrateCamera/sort.cpp $(START_DIR)/codegen/lib/calibrateCamera/xgeqp3.cpp $(START_DIR)/codegen/lib/calibrateCamera/xzlarfg.cpp $(START_DIR)/codegen/lib/calibrateCamera/xzlarf.cpp $(START_DIR)/codegen/lib/calibrateCamera/xgerc.cpp $(START_DIR)/codegen/lib/calibrateCamera/xunormqr.cpp $(START_DIR)/codegen/lib/calibrateCamera/flip.cpp $(START_DIR)/codegen/lib/calibrateCamera/xaxpy.cpp $(START_DIR)/codegen/lib/calibrateCamera/xrot.cpp $(START_DIR)/codegen/lib/calibrateCamera/xswap.cpp $(START_DIR)/codegen/lib/calibrateCamera/lsqnonlin.cpp $(START_DIR)/codegen/lib/calibrateCamera/jacobianFiniteDifference.cpp $(START_DIR)/codegen/lib/calibrateCamera/computeFiniteDifferences.cpp $(START_DIR)/codegen/lib/calibrateCamera/xgemv.cpp $(START_DIR)/codegen/lib/calibrateCamera/linearLeastSquares.cpp $(START_DIR)/codegen/lib/calibrateCamera/xzgeqp3.cpp $(START_DIR)/codegen/lib/calibrateCamera/gammaln.cpp $(START_DIR)/codegen/lib/calibrateCamera/finDiffEvalAndChkErr.cpp $(START_DIR)/codegen/lib/calibrateCamera/unsafeSxfun.cpp $(START_DIR)/codegen/lib/calibrateCamera/cat1.cpp $(START_DIR)/codegen/lib/calibrateCamera/string1.cpp $(START_DIR)/codegen/lib/calibrateCamera/Checkerboard.cpp $(START_DIR)/codegen/lib/calibrateCamera/NeighborhoodProcessor.cpp $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = calibrateCamera_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj calibrateCamera_initialize.obj calibrateCamera_terminate.obj calibrateCamera.obj isequal.obj detectCheckerboardPoints.obj imfilter.obj find_peaks.obj imregionalmax.obj bwlookup.obj detectCheckerboard.obj minOrMax.obj mean.obj find.obj polyfit.obj qrsolve.obj xnrm2.obj eml_setop.obj sortIdx.obj squeeze.obj norm.obj combineVectorElements.obj cat.obj computeInitialParameterEstimate.obj fitgeotrans.obj normalizeControlPoints.obj svd.obj inv.obj xdotc.obj rodriguesMatrixToVector.obj unserializeCalib.obj CalculateCost.obj factoryConstruct.obj my_nlparci.obj qr.obj mldivide.obj eml_betainc.obj subPixelLocation.obj xrotg.obj sort.obj xgeqp3.obj xzlarfg.obj xzlarf.obj xgerc.obj xunormqr.obj flip.obj xaxpy.obj xrot.obj xswap.obj lsqnonlin.obj jacobianFiniteDifference.obj computeFiniteDifferences.obj xgemv.obj linearLeastSquares.obj xzgeqp3.obj gammaln.obj finDiffEvalAndChkErr.obj unsafeSxfun.obj cat1.obj string1.obj Checkerboard.obj NeighborhoodProcessor.obj calibrateCamera_rtwutil.obj

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

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

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


%.obj : $(START_DIR)/codegen/lib/calibrateCamera/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/calibrateCamera/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateCamera_data.obj : $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/calibrateCamera/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/calibrateCamera/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/calibrateCamera/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateCamera_initialize.obj : $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateCamera_terminate.obj : $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateCamera.obj : $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.obj : $(START_DIR)/codegen/lib/calibrateCamera/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboardPoints.obj : $(START_DIR)/codegen/lib/calibrateCamera/detectCheckerboardPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imfilter.obj : $(START_DIR)/codegen/lib/calibrateCamera/imfilter.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find_peaks.obj : $(START_DIR)/codegen/lib/calibrateCamera/find_peaks.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imregionalmax.obj : $(START_DIR)/codegen/lib/calibrateCamera/imregionalmax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwlookup.obj : $(START_DIR)/codegen/lib/calibrateCamera/bwlookup.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


detectCheckerboard.obj : $(START_DIR)/codegen/lib/calibrateCamera/detectCheckerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


minOrMax.obj : $(START_DIR)/codegen/lib/calibrateCamera/minOrMax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mean.obj : $(START_DIR)/codegen/lib/calibrateCamera/mean.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find.obj : $(START_DIR)/codegen/lib/calibrateCamera/find.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


polyfit.obj : $(START_DIR)/codegen/lib/calibrateCamera/polyfit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


qrsolve.obj : $(START_DIR)/codegen/lib/calibrateCamera/qrsolve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/calibrateCamera/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_setop.obj : $(START_DIR)/codegen/lib/calibrateCamera/eml_setop.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.obj : $(START_DIR)/codegen/lib/calibrateCamera/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squeeze.obj : $(START_DIR)/codegen/lib/calibrateCamera/squeeze.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.obj : $(START_DIR)/codegen/lib/calibrateCamera/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.obj : $(START_DIR)/codegen/lib/calibrateCamera/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cat.obj : $(START_DIR)/codegen/lib/calibrateCamera/cat.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeInitialParameterEstimate.obj : $(START_DIR)/codegen/lib/calibrateCamera/computeInitialParameterEstimate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fitgeotrans.obj : $(START_DIR)/codegen/lib/calibrateCamera/fitgeotrans.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


normalizeControlPoints.obj : $(START_DIR)/codegen/lib/calibrateCamera/normalizeControlPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.obj : $(START_DIR)/codegen/lib/calibrateCamera/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inv.obj : $(START_DIR)/codegen/lib/calibrateCamera/inv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.obj : $(START_DIR)/codegen/lib/calibrateCamera/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rodriguesMatrixToVector.obj : $(START_DIR)/codegen/lib/calibrateCamera/rodriguesMatrixToVector.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unserializeCalib.obj : $(START_DIR)/codegen/lib/calibrateCamera/unserializeCalib.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CalculateCost.obj : $(START_DIR)/codegen/lib/calibrateCamera/CalculateCost.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/codegen/lib/calibrateCamera/factoryConstruct.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_nlparci.obj : $(START_DIR)/codegen/lib/calibrateCamera/my_nlparci.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


qr.obj : $(START_DIR)/codegen/lib/calibrateCamera/qr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.obj : $(START_DIR)/codegen/lib/calibrateCamera/mldivide.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eml_betainc.obj : $(START_DIR)/codegen/lib/calibrateCamera/eml_betainc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


subPixelLocation.obj : $(START_DIR)/codegen/lib/calibrateCamera/subPixelLocation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/calibrateCamera/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.obj : $(START_DIR)/codegen/lib/calibrateCamera/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/calibrateCamera/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/calibrateCamera/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/calibrateCamera/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgerc.obj : $(START_DIR)/codegen/lib/calibrateCamera/xgerc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xunormqr.obj : $(START_DIR)/codegen/lib/calibrateCamera/xunormqr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


flip.obj : $(START_DIR)/codegen/lib/calibrateCamera/flip.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.obj : $(START_DIR)/codegen/lib/calibrateCamera/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.obj : $(START_DIR)/codegen/lib/calibrateCamera/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.obj : $(START_DIR)/codegen/lib/calibrateCamera/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lsqnonlin.obj : $(START_DIR)/codegen/lib/calibrateCamera/lsqnonlin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


jacobianFiniteDifference.obj : $(START_DIR)/codegen/lib/calibrateCamera/jacobianFiniteDifference.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/calibrateCamera/computeFiniteDifferences.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/calibrateCamera/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearLeastSquares.obj : $(START_DIR)/codegen/lib/calibrateCamera/linearLeastSquares.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzgeqp3.obj : $(START_DIR)/codegen/lib/calibrateCamera/xzgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


gammaln.obj : $(START_DIR)/codegen/lib/calibrateCamera/gammaln.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/calibrateCamera/finDiffEvalAndChkErr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


unsafeSxfun.obj : $(START_DIR)/codegen/lib/calibrateCamera/unsafeSxfun.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cat1.obj : $(START_DIR)/codegen/lib/calibrateCamera/cat1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


string1.obj : $(START_DIR)/codegen/lib/calibrateCamera/string1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Checkerboard.obj : $(START_DIR)/codegen/lib/calibrateCamera/Checkerboard.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


NeighborhoodProcessor.obj : $(START_DIR)/codegen/lib/calibrateCamera/NeighborhoodProcessor.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


calibrateCamera_rtwutil.obj : $(START_DIR)/codegen/lib/calibrateCamera/calibrateCamera_rtwutil.cpp
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


