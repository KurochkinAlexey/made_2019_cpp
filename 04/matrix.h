#ifndef MATRIX_H
#define MATRIX_H

#include "row.h"
#include <vector>

class Matrix
{
public:
    Matrix(const size_t N, const size_t M);
    ~Matrix();
    Row& operator[](size_t i) {
        if(i >= nRows)
            throw std::out_of_range("");
        return *rows[i];
    }
    const Row& operator[](size_t i) const {
        if(i >= nRows)
            throw std::out_of_range("");
        return *rows[i];
    }
    void operator*=(const int n) {
        for(size_t i = 0; i < nRows; i++) {
            *rows[i] *= n;
        }
    }
    bool operator==(const Matrix& m) {
        bool result = true;
        for(size_t i = 0; i < nRows; i++) {
            if(!(*rows[i]==m[i])) {
                result = false;
                break;
            }
        }
        return result;
    }
    size_t getRows() const;
    size_t getColumns() const;
    void print() const;


private:
    std::vector<Row*> rows;
    const size_t nRows;
    const size_t nColumns;
};

#endif // MATRIX_H
