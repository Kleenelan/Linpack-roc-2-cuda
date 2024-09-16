

#set(CMAKE_INSTALL_PREFIX "../local/")
#set(ROCM_PATH "/usr/local/cuda")
#set(ROCBLAS_LIB_PATH "/usr/local/cuda/lib64")
#set(HPL_BLAS_DIR "")

#configure_file("run_rochpl.in" "run_rochpl" @ONLY)


configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../scripts/run_rochpl.in"
               "./run_rochpl"
               @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/../scripts/mpirun_rochpl.in"
               "./mpirun_rochpl"
               @ONLY)






