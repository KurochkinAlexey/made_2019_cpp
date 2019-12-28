#ifndef FORMAT_H
#define FORMAT_H

#include "args_processing.h"


template <typename... Args>
std::string format(const std::string& input, Args... args) {
    std::string inputCopy = input;
    std::unordered_map<std::string, std::string> argsAsString;
    size_t argsCounter = 0;
    processArgs(argsAsString, argsCounter, args...);
    insertArgs(inputCopy, argsAsString);

    return inputCopy;
}

#endif // FORMAT_H
