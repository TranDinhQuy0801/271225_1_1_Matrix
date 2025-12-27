#include"MiniTensor/Tensor.h"

namespace MiniTensor{
    //Default values
    Tensor::Tensor(int rows, int cols): m_rows(rows), m_cols(cols){
        m_data.resize(rows*cols, 0.0f);
    }

    void Tensor::print() const{
        std::cout << "Tensor Shape: (" << m_rows << "," << m_cols << ")" << std::endl;
    }

}

