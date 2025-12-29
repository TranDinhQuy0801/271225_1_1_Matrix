#include<iostream>
#include <MiniTensor/Tensor.h>

int main(){
    std::cout << "Starting MiniTensor Project..." << std::endl;

    // Testing on a 3x4 Tensor
    MiniTensor::Tensor t_1(3,4);
    MiniTensor::Tensor t_2(3,4);
    t_1.random_matrix (0,1);
    t_2.random_matrix (0,1);
    MiniTensor::Tensor t_3 = t_1 + t_2;
    t_1.print_matrix();
    t_2.print_matrix();
    t_3.print_matrix();
    std::cout << "Test successed!";
}

