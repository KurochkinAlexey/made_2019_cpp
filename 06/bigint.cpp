#include "bigint.h"

BigInt::BigInt()
{
    data = new int[1];
    data[0] = 0;

}


BigInt::BigInt(const int& x)
{
    size = getNumberOfDigits(x);
    data = new int[size];
    if(x < 0) {
        isNegative = true;
    }
    splitIntoDigits(x, size, data);
//    for(size_t i = 0; i < size; i++)
//        std::cout << data[i] << " ";

}


BigInt::BigInt(const BigInt &x)
{
    size = x.getSize();
    data = new int[size];
    for(size_t i = 0; i < size; i++)
        data[i] = x.getData()[i];
    isNegative = x.getIsNegative();
}


BigInt::BigInt(const int* data_, const size_t size_, bool isNegative_)
{
    size = size_;
    data = new int[size];
    for(size_t i = 0; i < size; i++)
        data[i] = data_[i];
    isNegative = isNegative_;
}

BigInt::BigInt(BigInt &&x):size(x.getSize()), data(x.getData()), isNegative(x.getIsNegative())
{
    x.data = nullptr;
    x.size = 0;
}

BigInt::~BigInt()
{
    delete[] data;
}


size_t BigInt::getSize() const
{
    return size;
}


int *BigInt::getData() const
{
    return data;
}

bool BigInt::getIsNegative() const
{
    return isNegative;
}

void BigInt::setIsNegative(bool isNegative_)
{
    isNegative = isNegative_;
}


BigInt BigInt::operator+(const int &x)
{
    size_t xSize = getNumberOfDigits(x);
    int* xData = new int[xSize];
    splitIntoDigits(x, xSize, xData);

    size_t ySize = size;
    int* yData = new int[ySize];
    for(size_t i = 0; i < ySize; i++)
        yData[i] = data[i];

    size_t resultSize = size;
    int* resultData = nullptr;
    bool isResultNegative = false;
    if((!isNegative)&&(x>=0)) {
        isResultNegative = false;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }
    if((isNegative)&&(x<0)) {
        isResultNegative = true;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }
    if((!isNegative)&&(x<0)) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }
    if((isNegative)&&(x>=0)) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }

    BigInt result(resultData, resultSize, isResultNegative);
//    for(size_t i = 0; i < resultSize; i++) {
//        std::cout << resultData[i] << " ";
//    }
//      std::cout << std::endl;
    delete [] xData;
    delete [] yData;
    return result;
}

BigInt BigInt::operator+(const BigInt &x)
{
    size_t xSize = x.getSize();
    int* xData = new int[xSize];
    for(size_t i = 0; i < xSize; i++)
        xData[i] = x.getData()[i];

    size_t ySize = size;
    int* yData = new int[ySize];
    for(size_t i = 0; i < ySize; i++)
        yData[i] = data[i];

    size_t resultSize = size;
    int* resultData = nullptr;
    bool isResultNegative = false;
    if((!isNegative)&&(!x.getIsNegative())) {
        isResultNegative = false;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }
    if((isNegative)&&(x.getIsNegative())) {
        isResultNegative = true;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }
    if((!isNegative)&&(x.getIsNegative())) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }
    if((isNegative)&&(!x.getIsNegative())) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }
    BigInt result(resultData, resultSize, isResultNegative);
//    for(size_t i = 0; i < resultSize; i++) {
//        std::cout << resultData[i] << " ";
//    }
//    std::cout << std::endl;
    delete [] xData;
    delete [] yData;
    return result;
}

BigInt BigInt::operator-(const int &x)
{
    size_t xSize = getNumberOfDigits(x);
    int* xData = new int[xSize];
    splitIntoDigits(x, xSize, xData);

    size_t ySize = size;
    int* yData = new int[ySize];
    for(size_t i = 0; i < ySize; i++)
        yData[i] = data[i];

    size_t resultSize = size;
    int* resultData = nullptr;
    bool isResultNegative = false;
    if((!isNegative)&&(x>=0)) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }

    if((isNegative)&&(x<0)) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }
    if(!(isNegative)&&(x<0)) {
        isResultNegative = false;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }

    if((isNegative)&&(x>=0)) {
        isResultNegative = true;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }

    BigInt result(resultData, resultSize, isResultNegative);
//    for(size_t i = 0; i < resultSize; i++) {
//        std::cout << resultData[i] << " ";
//    }
//    std::cout << std::endl;
    delete [] xData;
    delete [] yData;
    return result;

}

BigInt BigInt::operator-(const BigInt &x)
{
    size_t xSize = x.getSize();
    int* xData = new int[xSize];
    for(size_t i = 0; i < xSize; i++)
        xData[i] = x.getData()[i];

    size_t ySize = size;
    int* yData = new int[ySize];
    for(size_t i = 0; i < ySize; i++)
        yData[i] = data[i];

    size_t resultSize = size;
    int* resultData = nullptr;
    bool isResultNegative = false;
    if((!isNegative)&&(!x.getIsNegative())) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }

    if((isNegative)&&(x.getIsNegative())) {
        if(isGreaterEqual(yData, ySize, xData, xSize)) {
            isResultNegative = true;
            resultData = subtractNumberFromAnother(yData, ySize, xData, xSize, resultSize);
        }
        else {
            isResultNegative = false;
            resultData = subtractNumberFromAnother(xData, xSize, yData, ySize, resultSize);
        }
    }
    if(!(isNegative)&&(x.getIsNegative())) {
        isResultNegative = false;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }

    if((isNegative)&&(!x.getIsNegative())) {
        isResultNegative = true;
        resultData = addTwoNumbers(yData, ySize, xData, xSize, resultSize);
    }

    BigInt result(resultData, resultSize, isResultNegative);
//    for(size_t i = 0; i < resultSize; i++) {
//        std::cout << resultData[i] << " ";
//    }
//    std::cout << std::endl;
    delete [] xData;
    delete [] yData;
    return result;
}

bool BigInt::operator>(const int &x)
{
    if((!isNegative)&&(x < 0))
        return true;
    if((isNegative)&&(x >= 0))
        return false;

    size_t xSize = getNumberOfDigits(x);
    int* xData = new int[xSize];
    splitIntoDigits(x, xSize, xData);

    bool result = false;
    if((!isNegative)&&(x >= 0))
        result = isGreater(data, size, xData, xSize);
    if((isNegative)&&(x < 0))
        result = isLess(data, size, xData, xSize);

    delete [] xData;
    return result;
}

bool BigInt::operator==(const int &x)
{
    if(((isNegative)&&(x>=0))||((!isNegative)&&(x<0)))
        return false;


    size_t xSize = getNumberOfDigits(x);
    int* xData = new int[xSize];
    splitIntoDigits(x, xSize, xData);

//    std::cout << "!**" << std::endl;
//    for(size_t i = 0; i < size; i++)
//        std::cout << data[i] << " ";
//    std::cout << std::endl;
//    for(size_t i = 0; i < xSize; i++)
//        std::cout << xData[i] << " ";
//    std::cout << std::endl;
//    std::cout << "**!" << std::endl;

    bool result;
    result = isEqual(data, size, xData, xSize);
    return result;
}

bool BigInt::operator!=(const int &x)
{
    bool result = operator==(x);
    return !result;
}

bool BigInt::operator<(const int &x)
{
    if((!isNegative)&&(x < 0))
        return false;
    if((isNegative)&&(x >= 0))
        return true;

    size_t xSize = getNumberOfDigits(x);
    int* xData = new int[xSize];
    splitIntoDigits(x, xSize, xData);

    bool result = false;
    if((!isNegative)&&(x >= 0))
        result = isLess(data, size, xData, xSize);
    if((isNegative)&&(x < 0))
        result = isGreater(data, size, xData, xSize);

    delete [] xData;
    return result;
}


bool BigInt::operator>=(const int &x)
{
    bool result = operator<(x);
    return !result;
}


bool BigInt::operator<=(const int &x)
{
    bool result = operator>(x);
    return !result;
}

bool BigInt::operator>(const BigInt &x)
{
    if((!isNegative)&&(x.getIsNegative()))
        return true;
    if((isNegative)&&(!x.getIsNegative()))
        return false;

    size_t xSize = x.getSize();
    int* xData = new int[xSize];
    for(size_t i = 0; i < xSize; i++)
        xData[i] = x.getData()[i];

    bool result = false;
    if((!isNegative)&&(!x.getIsNegative()))
        result = isGreater(data, size, xData, xSize);
    if((isNegative)&&(x.getIsNegative()))
        result = isLess(data, size, xData, xSize);

    delete [] xData;
    return result;
}

bool BigInt::operator==(const BigInt &x)
{
    if(((isNegative)&&(!x.getIsNegative()))||((!isNegative)&&(x.getIsNegative())))
        return false;

    size_t xSize = x.getSize();
    int* xData = new int[xSize];
    for(size_t i = 0; i < xSize; i++)
        xData[i] = x.getData()[i];

    bool result;
    result = isEqual(data, size, xData, xSize);
    return result;
}

bool BigInt::operator!=(const BigInt &x)
{
    bool result = operator==(x);
    return !result;
}

bool BigInt::operator<(const BigInt &x)
{
    if((!isNegative)&&(x.getIsNegative()))
        return false;
    if((isNegative)&&(!x.getIsNegative()))
        return true;

    size_t xSize = x.getSize();
    int* xData = new int[xSize];
    for(size_t i = 0; i < xSize; i++)
        xData[i] = x.getData()[i];

    bool result = false;
    if((!isNegative)&&(!x.getIsNegative()))
        result = isLess(data, size, xData, xSize);

    if((isNegative)&&(x.getIsNegative()))
        result = isGreater(data, size, xData, xSize);

    delete [] xData;
    return result;
}

bool BigInt::operator>=(const BigInt &x)
{
    bool result = operator<(x);
    return !result;
}

bool BigInt::operator<=(const BigInt &x)
{
    bool result = operator>(x);
    return !result;
}

BigInt BigInt::operator-() const
{
    BigInt tmp(*this);
    tmp.setIsNegative(!isNegative);
    return tmp;
}

void BigInt::operator=(const int &x)
{
    if(data != nullptr)
        delete [] data;
    size = getNumberOfDigits(x);
    data = new int[size];
    if(x < 0) {
        isNegative = true;
    }
    splitIntoDigits(x, size, data);
}

void BigInt::operator=(const BigInt &x)
{
    if(data == x.data)
        return;
    if(data != nullptr)
        delete [] data;
    size = x.getSize();
    data = new int[size];
    for(size_t i = 0; i < size; i++)
        data[i] = x.getData()[i];
    isNegative = x.getIsNegative();
}

void BigInt::operator=(BigInt &&x)
{
    if(x.data == data)
        return;
    if(data != nullptr)
        delete [] data;
    size = x.getSize();
    data = x.data;
    isNegative = x.isNegative;
    x.data = nullptr;
    x.size = 0;
}



size_t BigInt::getNumberOfDigits(int x)
{
    size_t number = 1;
    int i = 1;
    while(x%static_cast<int>(pow(10, i)) != x) {
        i++;
        number++;
    }
    return number;
}


void BigInt::splitIntoDigits(int x, size_t i, int* data)
{
    if(x < 0)
        x *= -1;
    if(x >= 10)
       splitIntoDigits(x / 10, --i, data);

    int digit = x % 10;

    if(x < 10)
        data[0] = digit;
    else
        data[i] = digit;
}


void BigInt::extendByZeros(int*& data, size_t& size, size_t nZeros)
{
    int* tmpData = new int[size+nZeros];
    size_t i = 0;
    for(; i < nZeros; i++)
        tmpData[i] = 0;
    for(size_t j = 0; j < size; j++, i++)
        tmpData[i] = data[j];

    delete [] data;
    data = tmpData;
    size += nZeros;
}


void BigInt::extendByOne(int*& data, size_t &size)
{
    int* tmpData = new int[size + 1];
    tmpData[0] = 1;
    for(size_t i = 0; i < size; i++)
        tmpData[i + 1] = data[i];

    delete [] data;
    data = tmpData;
    size += 1;
}


void BigInt::squeezeZeros(int *&data, size_t &size)
{
    size_t nZeros = 0;
    for(size_t i = 0; i < size; i++) {
        if(data[i] != 0) {
            nZeros = i;
            break;
        }
    }
    int* tmpData = new int[size - nZeros];
    for(size_t i = nZeros; i < size; i++)
        tmpData[i-nZeros] = data[i];

    delete [] data;
    data = tmpData;
    size -= nZeros;
}


int* BigInt::addTwoNumbers(int *&data, size_t &size, int *&xData, size_t &xSize, size_t& resultSize)
{
    resultSize = size;
    if(xSize > size) {
        extendByZeros(data, size, xSize - size);
        resultSize = xSize;
    }

    if(xSize < size) {
        extendByZeros(xData, xSize, size - xSize);
    }


    int* resultData = new int[resultSize];
    bool keepOneInMind = false;
    for(int i = resultSize-1; i >= 0; i--) {
        int res = data[i] + xData[i];
        if(keepOneInMind) {
            res++;
            keepOneInMind = false;
        }
        if(res>=10)
            keepOneInMind = true;
        resultData[i] = res%10;
        //std::cout << data[i] << " " << xData[i] << " " << res << " " << resultData[i] << std::endl;
        if((res>=10)&&(i==0))
            extendByOne(resultData, resultSize);
    }

    return resultData;
}


int* BigInt::subtractNumberFromAnother(int *&data, size_t &size, int *&xData, size_t &xSize, size_t& resultSize)
{
    resultSize = size;
    if(xSize > size) {
        extendByZeros(data, size, xSize - size);
        resultSize = xSize;
    }

    if(xSize < size) {
        extendByZeros(xData, xSize, size - xSize);
    }


    int* resultData = new int[resultSize];
    bool keepOneInMind = false;
    for(int i = resultSize-1; i >= 0; i--) {
        int res = data[i] - xData[i];
        if(keepOneInMind) {
            res--;
            keepOneInMind = false;
        }
        if((res < 0)&&(i != 0)) {
            keepOneInMind = true;
            res += 10;
        }
        resultData[i] = res%10;
        //std::cout << data[i] << " " << xData[i] << " " << res << " " << resultData[i] << std::endl;
        if((res==0)&&(i==0))
            squeezeZeros(resultData, resultSize);
        if((res < 0)&&(i==0)) {
            resultData[i] *= -1;
            isNegative = true;
        }
    }
    return resultData;
}


bool BigInt::isGreater(int *data, size_t size, int *xData, size_t xSize)
{
    if(size > xSize)
        return true;
    if(size < xSize)
        return false;
    for(size_t i = 0; i < size; i++) {
        if(data[i] > xData[i])
            return true;
        if(data[i] < xData[i])
            return false;
    }
    return false;
}


bool BigInt::isEqual(int *data, size_t size, int *xData, size_t xSize)
{
    if(size != xSize)
        return false;
    for(size_t i = 0; i < size; i++) {
        if(data[i] != xData[i])
            return false;
    }
    return true;
}


bool BigInt::isLess(int *data, size_t size, int *xData, size_t xSize)
{
    if(size > xSize)
        return false;
    if(size < xSize)
        return true;
    for(size_t i = 0; i < size; i++) {
        if(data[i] > xData[i])
            return false;
        if(data[i] < xData[i])
            return true;
    }
    return false;
}


bool BigInt::isGreaterEqual(int *data, size_t size, int *xData, size_t xSize)
{
    if(size > xSize)
        return true;
    if(size < xSize)
        return false;
    for(size_t i = 0; i < size; i++) {
        if(data[i] > xData[i])
            return true;
        if(data[i] < xData[i])
            return false;
    }
    return true;
}


bool BigInt::isLessEqual(int *data, size_t size, int *xData, size_t xSize)
{
    if(size > xSize)
        return false;
    if(size < xSize)
        return true;
    for(size_t i = 0; i < size; i++) {
        if(data[i] > xData[i])
            return false;
        if(data[i] < xData[i])
            return true;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const BigInt &x)
{
    for(size_t i = 0; i < x.getSize(); i++)
        os << x.getData()[i];
    return os;
}
