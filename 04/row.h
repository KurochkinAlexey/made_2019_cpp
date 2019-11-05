#ifndef ROW_H
#define ROW_H
#include <iostream>

class Row
{
public:
    Row(const size_t n);
    ~Row();
    int& operator[](size_t i) {
        if(i >= N)
            throw std::out_of_range("");
        return data[i];
    }
    const int& operator[](size_t i) const {
        if(i >= N)
            throw std::out_of_range("");
        return data[i];
    }
    void operator*=(const int n) {
        for(size_t i = 0; i < N; i++)
            data[i] *= n;
    }
    bool operator==(const Row& r) {
        bool result = true;
        for(size_t i = 0; i < N; i++)
            if(data[i] != r[i]) {
                result = false;
                break;
            }
        return result;
    }
    size_t getColumns() const;
private:
    int* data;
    const size_t N;
};

#endif // ROW_H
