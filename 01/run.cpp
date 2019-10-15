//#include <iostream>
#include "calculate.h"



int main(int argc, const char** argv)
{


    std::string expr = argv[1];

    try {
        double result = calculate(expr);
        std::cout << result << std::endl;
        return 0;
    } catch (std::overflow_error& e) {
        std::cout << e.what() << std::endl;
        return -1;
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return -1;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
        return -1;
    } catch (...) {
        std::cout << "Unknown error" << std::endl;
        return -1;
    }
}
