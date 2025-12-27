#LIBRARY: library named MiniTensor
add_library(MiniTensor Tensor.cpp)
target_include_directories(MiniTensor PUBLIC #POINT TO THE INCLUDE
    "${PROJECT_SOURCE_DIR}/include")