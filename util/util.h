/*
 * util.h
 *
 *  Created on: Dec 10, 2010
 *      Author: hans
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>
#include <string>

#define p(d) thrust::raw_pointer_cast(&(d)[0])
static const uint32_t SHARED_MEMORY_SIZE = 48 * 1024;
static const uint32_t WARP_SIZE = 32;

inline void checkCUDAError(std::string msg)
{
    cudaError_t err = cudaGetLastError();
    if( cudaSuccess != err)
    {
        std::cerr << "Cuda error during " <<  msg << ": " << cudaGetErrorString(err);
        exit(EXIT_FAILURE);
    }
}

inline uint32_t divideAndCeil(uint32_t what, uint32_t divisor){
    return (what + divisor - 1) / divisor;
}

uint32_t getNumMultiprocessors(){
    cudaDeviceProp deviceProp;
    int id=0; cudaGetDevice(&id);
    cudaGetDeviceProperties(&deviceProp, id);
    //		return thrust::detail::device::cuda::arch::num_multiprocessors();
    return deviceProp.multiProcessorCount;
}

std::string getFileName(const std::string &filePath) {
    size_t found;
    found=filePath.find_last_of("/\\");
    return filePath.substr(found+1);
}


#endif /* UTIL_H_ */
