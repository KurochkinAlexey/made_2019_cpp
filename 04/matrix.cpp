#include "matrix.h"

Matrix::Matrix(const size_t N, const size_t M): nRows(N), nColumns(M)
{
    for(size_t i = 0; i < N; i++) {
        rows.push_back(Row(M));
    }
}


Matrix::~Matrix()
{
//    for(size_t i = 0; i < nRows; i++) {
//        delete rows[i];
//    }
}

size_t Matrix::getRows() const
{
    return nRows;
}

size_t Matrix::getColumns() const
{
    return nColumns;
}

void Matrix::print() const
{
    std::cout << std::endl;
    for(size_t i = 0; i < nRows; i++) {
        for(size_t j = 0; j < nColumns; j++) {
            std::cout << rows[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


