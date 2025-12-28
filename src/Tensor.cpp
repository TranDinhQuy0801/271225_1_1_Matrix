#include"MiniTensor/Tensor.h"
#include<stdexcept> // EXCEPTION HANDLING
#include<random>
namespace MiniTensor{
    //Default values
    Tensor::Tensor(int rows, int cols)
        : m_rows(rows), m_cols(cols){ // Initializer lists
        m_data.resize(rows*cols, 0.0);
    };
    void Tensor::random_matrix(double mean, double stddev){
        static std::random_device rd; // create static var -> initialize once -> optimize
        static std::mt19937 gen(rd());

        std::normal_distribution<double> dist(mean, stddev); // Define the distribution
        for(size_t i = 0; i < m_rows; i++){
            for(size_t j = 0; j < m_cols; j++){
                m_data[j + m_cols*i] = dist(gen);
            }
        }
    }
    const double& Tensor::at(int r, int c) const{
        if(r >= m_rows || c >= m_cols){
            throw std::out_of_range("INDEX OUT OF BOUNDS!!");
        }
        return m_data[r*m_cols + c];
    };
    double& Tensor::at(int r, int c){
        if(r >= m_rows || c >= m_cols){
            throw std::out_of_range("INDEX OUT OF BOUNDS!!");
        }
        return m_data[r*m_cols + c];
    };
    void Tensor::print_shape() const{
        std::cout << "Tensor Shape: (" << m_rows << "," << m_cols << ")" << std::endl;
    }
    void Tensor::print_matrix() const{
        for(size_t i = 0; i < m_rows; i++){
            for(size_t j = 0; j < m_cols; j++){
                std::cout << std::setw(4) <<  m_data[i*m_cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

}

