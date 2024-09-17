
VERSION := 6.0.0
CU_CXX  := /usr/local/cuda/bin/nvcc
CPP_CXX := g++
EXE_CXX := g++

include make.cuda.src
include make.cpp.src

CPP_OBJ := $(CPP_SRC:.cpp=.cpp.o)
CU_OBJ := $(CU_SRC:.cu=.cu.o)

EXE := ixhpl

all: $(EXE)-$(VERSION)

INC_EXE 	:= -I ./include/  -I/usr/local/cuda/include -I ./tpl/openmpi/include/
LD_FLAGS_EXE 	:= -L ./tpl/openmpi/lib/ -L ./tpl/blis/lib -L /usr/local/cuda/lib64 -lcudart -lcublas -lmpi -lblis
LD_FLAGS_EXE	+= -Wl,-rpath,$(shell pwd)/tpl/openmpi/lib:$(shell pwd)/tpl/blis/lib:

$(EXE)-$(VERSION) : $(CPP_OBJ) $(CU_OBJ)
	$(EXE_CXX)  -fopenmp -DCUDA_ENV $^ -o $@ $(INC_EXE) $(LD_FLAGS_EXE)


#g++ -DCUDA_ENV  -c  panel/HPL_pdpanel_free.cpp -I ../include/  -I/usr/local/cuda/include -I ../tpl/openmpi/include/ -L ../tpl/openmpi/lib/  -L /usr/local/cuda/lib64 -lcudart -lmpi

INC_CPP 	:= -I ./include/  -I/usr/local/cuda/include -I ./tpl/openmpi/include/
#LD_FLAGS_CPP 	:= -L ../tpl/openmpi/lib/ -L ../tpl/blis/lib -L /usr/local/cuda/lib64 -lcudart -lcublas -lmpi -lblis
CPP_CXX_FLAGS := -O3 -DNDEBUG -std=c++11 -march=native -fopenmp
CPP_CXX_FLAGS += -DHPL_DETAILED_TIMING -DHPL_PROGRESS_REPORT -DHPL_VERBOSE_PRINT -DUSE_PROF_API=1
# -D__HIP_PLATFORM_AMD__=1

%.cpp.o: %.cpp
	g++ -DCUDA_ENV $(CPP_CXX_FLAGS) $(INC_CPP) -c $< -o $@







INC_CU      := -I /usr/local/cuda/include -I tpl/openmpi/include/ -I ./include
#LD_FLAGS_CU := -L /usr/local/cuda/lib64 -lcudart
CU_CXX_FLAGS := -O3
#CU_CXX_FLAGS +=  -DHPL_VERBOSE_PRINT -DHPL_DETAILED_TIMING -DHPL_PROGRESS_REPORT -DUSE_PROF_API=1
#nvcc fatal   : Unknown option '-Wno-unused-command-line-argument'
#-D__HIP_PLATFORM_AMD__=1
#Unknown option '-fPIE'
%.cu.o: %.cu
	nvcc -DCUDA_ENV $(CU_CXX_FLAGS) -c $< -o $@ $(INC_CU)

# $(LD_FLAGS_CU)

PREFIX ?= ../local


.PHONY: install
install:
	mkdir -p $(PREFIX)/bin
	cp scripts/HPL.dat $(PREFIX)
	mv ./build/run_rochpl $(PREFIX)
	mv ./build/mpirun_rochpl $(PREFIX)
	cp $(EXE)-$(VERSION) $(PREFIX)/bin/
	cd $(PREFIX)/bin && rm -rf $(EXE) && ln -s $(EXE)-$(VERSION) $(EXE)


.PHONY: clean
clean:
	-rm -rf $(CPP_OBJ) $(CU_OBJ) $(EXE)-$(VERSION)


.PHONY: echo
echo:
	@echo "hello world!"
	@echo "CPP_SRC		is	" $(CPP_SRC)
	@echo "CU_SRC		is	" $(CU_SRC)


