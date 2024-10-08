#pragma once
#include <cuda_runtime.h>
#include <cublas_v2.h>
//#include <cublas.h>

#define roctxRangePush(X)
#define roctxRangePop()

//2. rocblas -> cublas
//2.1 rocblas API
////////////////////////////////////////////////////////////////////////////
#define rocblas_dasum	cublasDasum
#define rocblas_dcopy	cublasDcopy
#define rocblas_idamax	cublasIdamax
#define rocblas_daxpy	cublasDaxpy
#define rocblas_dtrsv	cublasDtrsv
#define rocblas_dgemv	cublasDgemv
#define rocblas_dtrsm	cublasDtrsm
#define rocblas_dgemm	cublasDgemm
#define rocblas_set_atomics_mode    cublasSetAtomicsMode
#define rocblas_set_math_mode       cublasSetMathMode
#define rocblas_get_stream          cublasGetStream
#define rocblas_create_handle       cublasCreate
#define rocblas_set_pointer_mode    cublasSetPointerMode
#define rocblas_initialize          cublasInit
#define rocblas_destroy_handle      cublasDestroy
#define rocblas_status_to_string    cublasGetStatusString
#define rocblas_set_stream          cublasSetStream
//2.2 enum and type
#define rocblas_diagonal_non_unit   CUBLAS_DIAG_NON_UNIT
#define rocblas_side_left           CUBLAS_SIDE_LEFT
#define rocblas_fill_upper          CUBLAS_FILL_MODE_UPPER
#define rocblas_fill_lower          CUBLAS_FILL_MODE_LOWER
#define rocblas_operation_transpose CUBLAS_OP_T
#define rocblas_operation_none      CUBLAS_OP_N
#define rocblas_side_right          CUBLAS_SIDE_RIGHT
#define rocblas_diagonal_unit       CUBLAS_DIAG_UNIT
#define rocblas_handle              cublasHandle_t
#define rocblas_status              cublasStatus_t
#define rocblas_status_success      CUBLAS_STATUS_SUCCESS
#define rocblas_pointer_mode_host   CUBLAS_POINTER_MODE_HOST
#define rocblas_atomics_not_allowed CUBLAS_ATOMICS_NOT_ALLOWED

//3. hip API -> cuda API
//3.1 hip API
///////////////////////////////////////////////////////////////////////////////////
#define hipFree                 cudaFree
#define hipHostFree             cudaFreeHost
#define hipHostMalloc           cudaMallocHost
#define hipMemcpy               cudaMemcpy
#define hipMemcpyAsync          cudaMemcpyAsync
#define hipMemcpy2DAsync        cudaMemcpy2DAsync
#define hipMemcpyHostToDevice   cudaMemcpyHostToDevice
#define hipMemcpyDeviceToHost   cudaMemcpyDeviceToHost
#define hipMemcpyDeviceToDevice cudaMemcpyDeviceToDevice
#define hipStreamSynchronize    cudaStreamSynchronize
#define hipGetLastError         cudaGetLastError
#define hipGetDeviceCount       cudaGetDeviceCount
#define hipStreamWaitEvent      cudaStreamWaitEvent
#define hipEventSynchronize     cudaEventSynchronize
#define hipEventElapsedTime     cudaEventElapsedTime
#define hipDeviceSynchronize    cudaThreadSynchronize
#define hipEventRecord          cudaEventRecord
#define hipGetDeviceProperties  cudaGetDeviceProperties
#define hipSetDevice            cudaSetDevice
#define hipStreamCreate         cudaStreamCreate
#define hipStreamDestroy        cudaStreamDestroy
#define hipEventCreate          cudaEventCreate
#define hipEventDestroy         cudaEventDestroy
#define hipMalloc               cudaMalloc
#define hipGetErrorString       cudaGetErrorString

//3.2 enum and type
#define hipStream_t             cudaStream_t
#define hipEvent_t              cudaEvent_t
#define hipSuccess              cudaSuccess
#define hipError_t              cudaError_t
#define hipDeviceProp_t         cudaDeviceProp
