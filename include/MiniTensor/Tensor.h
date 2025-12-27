#pragma once
#include<vector>
#include<iostream> 
namespace MiniTensor{
    class Tensor{
        private:
            int m_rows;
            int m_cols; 
            std::vector<int> m_data;
        public:
            // Constructor
            Tensor(int rows, int cols);
            // Display function
            void print() const;
    };
};