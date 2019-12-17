#ifndef FORMAT_H
#define FORMAT_H

#include "args_processing.h"


template <typename... Args>
std::string format(const std::string& input, Args... args) {
    std::string inputCopy = input;
    std::stack<char> paranthesesStack;
    size_t maxArgumentNumber;
    size_t argsCounterInString = calculateNumberOfArgumentsInString(inputCopy, maxArgumentNumber);
    size_t argsCounterInFunc = 0;

    for(const char c: input) {
        if(c == '{') {
            paranthesesStack.push(c);
        }
        if(c == '}')
            paranthesesStack.pop();
    }
    if(!paranthesesStack.empty()) {
        throw std::runtime_error("Number of parentheses do not match");
    }
    processArgs(inputCopy, argsCounterInFunc, args...);
    if(argsCounterInFunc != argsCounterInString) {
        throw std::runtime_error("Number of arguments do not match");
    }

    if(argsCounterInFunc-1 != maxArgumentNumber) {
        throw std::runtime_error("Argument numbers do not match position in function");
    }

    return inputCopy;
}

#endif // FORMAT_H
