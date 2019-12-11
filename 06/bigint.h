#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cmath>

class BigInt
{
public:
    BigInt();
    BigInt(const int& x);
    BigInt(const BigInt& x);
    BigInt(BigInt&& x);
    ~BigInt();

    BigInt operator+(const int& x);
    BigInt operator+(const BigInt& x);
    BigInt operator-(const int& x);
    BigInt operator-(const BigInt& x);
    bool operator>(const int& x);
    bool operator==(const int& x);
    bool operator!=(const int& x);
    bool operator<(const int& x);
    bool operator>=(const int& x);
    bool operator<=(const int& x);
    bool operator>(const BigInt& x);
    bool operator==(const BigInt& x);
    bool operator!=(const BigInt& x);
    bool operator<(const BigInt& x);
    bool operator>=(const BigInt& x);
    bool operator<=(const BigInt& x);
    BigInt operator-() const;
    void operator=(const int& x);
    void operator=(const BigInt& x);
    void operator=(BigInt&& x);

    size_t size = 0;
    int* data = nullptr;
private:
    BigInt(const int* data_, const size_t size_, bool isNegative);
//    size_t size = 0;
//    int* data = nullptr;
    bool isNegative = false;
    size_t getNumberOfDigits(int x);
    void splitIntoDigits(int x, size_t i, int* data);
    void extendByZeros(int*& data, size_t& size, size_t nZeros);
    void extendByOne(int*& data, size_t& size);
    void squeezeZeros(int*& data, size_t &size);
    int* addTwoNumbers(int*& data, size_t& size, int*& xData, size_t& xSize, size_t& resultSize);
    int* subtractNumberFromAnother(int*& data, size_t& size, int*& xData, size_t& xSize, size_t& resultSize);
    bool isGreater(int* data, size_t size, int* xData, size_t xSize);
    bool isEqual(int* data, size_t size, int* xData, size_t xSize);
    bool isLess(int* data, size_t size, int* xData, size_t xSize);
    bool isGreaterEqual(int* data, size_t size, int* xData, size_t xSize);
    bool isLessEqual(int* data, size_t size, int* xData, size_t xSize);



};

std::ostream &operator<<(std::ostream& os, const BigInt& x);
#endif // BIGINT_H
