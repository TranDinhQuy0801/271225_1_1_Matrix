#include"MiniTensor/Tensor.h"
#include<stdexcept> // EXCEPTION HANDLING
#include<random>
#include<cmath>
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
    Tensor Tensor::operator+(const Tensor other){ //m_3 = m_1 + m_2 ~ m_3 = m_1.operator+ (m_2);
        Tensor result(this->m_rows, this->m_cols);
        for(int i = 0; i < m_rows; i++){
            for(int j = 0; j < m_cols; j++){
                result.m_data[i*m_cols + j] = this->m_data[i*m_cols + j] + other.m_data[i*m_cols + j];
            }
        }
        return result;
    };
    Tensor Tensor::matmul(const Tensor other) const{
        if(this->m_cols != other.m_rows){
            throw std::invalid_argument("Dimension mismatch: Cols of A must match Rows of B");
        }
        double rows = this->m_rows;
        double cols = other.m_cols;
        double K = this->m_cols; // K : shared dimension -> the same size of these 2.
        Tensor result(rows,cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                double addition = 0;
                for(int k = 0; k < K;k++){
                    addition += (this->at(i,k)*other.at(k,j));
                };
                result.at(i,j) += addition;
            };
        };
        return result;
    };
    void Tensor::print_shape() const{
        std::cout << "Tensor Shape: (" << m_rows << "," << m_cols << ")" << std::endl;
    };
    void Tensor::print_matrix() const{
        for(size_t i = 0; i < m_rows; i++){
            for(size_t j = 0; j < m_cols; j++){
                std::cout << std::setw(4) <<  m_data[i*m_cols + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    };

}

