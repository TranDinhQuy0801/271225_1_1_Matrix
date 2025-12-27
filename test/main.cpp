#include<iostream>
#include <MiniTensor/Tensor.h>

int main(){
    std::cout << "Starting MiniTensor Project..." << std::endl;

    // Testing on a 3x4 Tensor
    MiniTensor::Tensor test_object(3,4);

    test_object.print();
}

