#include <iostream>
#include "matrix.h"
#include <cassert>

using namespace std;

int main()
{


    const size_t N = 2;
    const size_t M = 2;
    Matrix m1(N, M);
    Matrix m2(N, M);
    Matrix m3(N, M);
    assert(m1.getRows() == N);
    assert(m1.getColumns() == M);

    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            m1[i][j] = i + j;
            m2[i][j] = i + j;
            m3[i][j] = i + j + 1;
        }
    }
    std::cout << "m1" << std::endl;
    m1.print();
    std::cout << "m2" << std::endl;
    m2.print();
    std::cout << "m3" << std::endl;
    m3.print();

    std::cout << "m1 = m2" << std::endl;
    if(m1 == m2)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;


    std::cout << "m1 != m3" << std::endl;
    if(m1 != m3)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    m1 *= 3;
    std::cout << "m1 *= 3" << std::endl;
    m1.print();

    return 0;
}
