#include<iostream>
#include <MiniTensor/Tensor.h>

int main(){
    std::cout << "Starting MiniTensor Project..." << std::endl;

    // Testing on a 3x4 Tensor
    MiniTensor::Tensor t_1(3,4);
    t_1.random_matrix (0,1);
    t_1.print_matrix();
    std::cout << "Test successed!";
}

