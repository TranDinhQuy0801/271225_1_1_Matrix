#pragma once
#include<vector>
#include<iostream> 
namespace MiniTensor{
    class Tensor{
        private:
            int m_rows;
            int m_cols; 
            std::vector<double> m_data;
        public:
            // Constructor
            Tensor(int rows, int cols);
            // Function to add members for the matrix
            double& at(int r, int c);
            const double& at(int r, int c) const; //const -> function can't change member of this class ( rows and cols)
            // Function to get the size
            int getRows() const{return m_rows;};
            int getCols() const{return m_cols;};
            // Display function
            void print_shape() const;
            void print_matrix() const;
    };
};