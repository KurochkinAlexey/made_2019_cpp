//#include <iostream>
#include "calculate.h"



int main(int argc, const char** argv)
{

    //std::string expr = "-2*3+3--4/4";

    std::string expr = argv[1];
    try {
        double result = calculate(expr);
        std::cout << result << std::endl;
        return 0;
    } catch (...) {
        std::cout << "Incorrect expression" << std::endl;
        return -1;
    }


}
