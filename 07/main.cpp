#include <iostream>
#include "format.h"
#include <cassert>

struct testStruct
{

};

int main()
{
    std::cout << "Running tests..." << std::endl;
    std::string str1 = format("{1}+{1} != {0}", 2, 3.14);
    //std::cout << str1 << std::endl;
    assert(str1 == "3.140000+3.140000 != 2");

    std::string str2 = format("{1}+{1} = {0}", 2, "one");
    assert(str2 == "one+one = 2");

    std::string str3 = format("{0}+{1}+{2}+{3}+{4}+{5}={6}", 0, 1, 2, 3, 4, 5, 15);
    assert(str3 == "0+1+2+3+4+5=15");

    std::string str4 = format("{0} is {1}, but {1} is not {0}", "foo", "bar");
    assert(str4 == "foo is bar, but bar is not foo");

    std::string str5 = format("{0}{1}{2}{3}{4}{5}{6}","M", 'A', "D", 'E','-', 2.0, 19);
    assert(str5 == "MADE-2.00000019");

    try {
        format("{1}+{1} = {2}", 2, "one");
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Argument numbers do not match position in function");
    }

    try {
        format("{1}+{1 = {0}", 2, "one");
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Number of parentheses do not match");
    }

    try {
        format("{1}+{1}={2}", 2);
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Number of arguments do not match");
    }

    try {
        format("{}+{1}={0}", 2, 1);
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Invalid argument number given");
    }

    try {
        format("{1}+{-1}={0}", 2, 1);
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Invalid argument number given");
    }


    try {
        format("{123456789987654321}+{1}={0}", 2, 1);
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Argument number is too big");
    }

    try {
        format("{1}+{1}={0}", testStruct(), 1);
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "Unknown type given");
    }

    try {
        format("{1}+{1}={0}", "{2}", '1');
    } catch(std::runtime_error re) {
        std::string w = re.what();
        assert(w == "{ and } symbols are reserved");
    }

    std::cout << "All tests are passed" << std::endl;
    return 0;
}
