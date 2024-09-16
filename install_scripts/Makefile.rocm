
CPU_CXX := g++
DEV_CXX := /opt/rocm/bin/hipcc


TOP_DIR := $(shell pwd)

include make.src.hpl

LD_CPU_FLAGS :=
LD_DEV_FLAGS :=

CPU_OBJ := $(CPU_SRC:.cpp=.cpp.o)
DEV_OBJ := $(DEV_SRC:.hip=.hip.o)


CXX_FLAGS_EXE := -O3 -DNDEBUG -fopenmp -Wl,-rpath \
-Wl,$(TOP_DIR)/tpl/openmpi/build/../lib \
-Wl,--enable-new-dtags \
 -Wl,-rpath,/opt/rocm-6.0.2/lib:/opt/rocm/lib:$(TOP_DIR)/tpl/openmpi/lib:$(TOP_DIR)/tpl/blis/lib: \
 /opt/rocm-6.0.2/lib/librocblas.so.4.0.60002 \
 /opt/rocm/lib/libroctracer64.so \
 /opt/rocm/lib/libroctx64.so \
 $(TOP_DIR)/tpl/openmpi/lib/libmpi.so \
 /usr/lib/gcc/x86_64-linux-gnu/12/libgomp.so \
 /usr/lib/x86_64-linux-gnu/libpthread.a \
 $(TOP_DIR)/tpl/blis/lib/libblis.so \
 /opt/rocm/lib/libamdhip64.so.6.0.60002

EXE := rochpl_from_make

all: $(EXE)

$(EXE): $(CPU_OBJ) $(DEV_OBJ)
	g++ $^ -o $@ $(CXX_FLAGS_EXE) 	




#############################################

CPU_CXX_FLAGS := -O3 -DNDEBUG -std=c++11 -O3 -march=native -fopenmp
CPU_CXX_FLAGS += -DHPL_DETAILED_TIMING -DHPL_PROGRESS_REPORT -DHPL_VERBOSE_PRINT -DUSE_PROF_API=1 -D__HIP_PLATFORM_AMD__=1



INC_CPU := 	-I$(TOP_DIR)/include \
			-I$(TOP_DIR)/build/include \
			-isystem $(TOP_DIR)/tpl/openmpi/include

INC_ROCM :=	-I/opt/rocm/include/roctracer \
			-isystem /opt/rocm/include

INC_CPU += $(INC_ROCM)

%.cpp.o: %.cpp
	$(CPU_CXX) -c $^ -o $@ $(INC_CPU) $(CPU_CXX_FLAGS)




#############################################

DEV_CXX_FLAGS := -Wno-unused-command-line-argument -fPIE -fopenmp -O3 -march=native -ffp-contract=fast -ffast-math -funsafe-math-optimizations
DEV_CXX_FLAGS += --offload-arch=gfx900 --offload-arch=gfx906 --offload-arch=gfx908 --offload-arch=gfx90a --offload-arch=gfx940 --offload-arch=gfx941 --offload-arch=gfx942
DEV_CXX_FLAGS += -DHPL_VERBOSE_PRINT -DHPL_DETAILED_TIMING -DHPL_PROGRESS_REPORT -D__HIP_PLATFORM_AMD__=1 -DUSE_PROF_API=1

INC_HPL := \
-I$(TOP_DIR)/include \
-I$(TOP_DIR)/build/include \
-I$(TOP_DIR)/tpl/openmpi/include


INC_DEV := \
-I/opt/rocm/include \
-I/opt/rocm/include/roctracer

INC_DEV += $(INC_HPL)


%.hip.o: %.hip
	$(DEV_CXX) -c $^ $(INC_DEV) $(DEV_CXX_FLAGS) -o $@





.PHONY: clean
clean:
	-rm -rf $(CPU_OBJ) $(DEV_OBJ) $(EXE) 


.PHONY: echo
echo:
	@echo "CPU_OBJ is"	$(CPU_OBJ)

#	@echo "CPU_SRC is "	$(CPU_SRC)
