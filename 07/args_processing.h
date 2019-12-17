#ifndef ARGS_PROCESSING_H
#define ARGS_PROCESSING_H

#include <stack>
#include <type_traits>
#include <set>
#include <string>
#include <algorithm>


template <typename T>
std::string convertFuncArgumentToString(T val) {
    throw std::runtime_error("Unknown type given");
}


template<>
std::string convertFuncArgumentToString<int>(int val) {
    return std::to_string(val);
}


template<>
std::string convertFuncArgumentToString<double>(double val) {
    return std::to_string(val);
}


template<>
std::string convertFuncArgumentToString<char>(char val) {
    return std::string(1, val);
}

template<>
std::string convertFuncArgumentToString<const char*>(const char* val) {
    return std::string(val);
}


template<>
std::string convertFuncArgumentToString<bool>(bool val) {
    return std::to_string(static_cast<int>(val));
}


void checkParanthesisInArgument(const std::string& str) {
    for(const char c: str) {
        if((c=='{')||(c=='}')) {
            throw std::runtime_error("{ and } symbols are reserved");
        }
    }
}


size_t extractArgument(const std::string& str, size_t i, size_t& j) {
    j = i+1;
    for(; j < str.size(); j++) {
        if(str[j] == '}')
            break;
    }
    int argNumber;
    try {
        argNumber = std::stoi(str.substr(i+1, j-1));
    } catch (std::invalid_argument) {
        throw std::runtime_error("Invalid argument number given");
    } catch (std::out_of_range) {
        throw std::runtime_error("Argument number is too big");
    }
    if(argNumber < 0) {
        throw std::runtime_error("Invalid argument number given");
    }
    return static_cast<size_t>(argNumber);
}


void insertArgument(std::string& str, const std::string& argToInsert, size_t i, size_t j) {
    std::string leftSubStr = str.substr(0, i);
    std::string rightSubStr = str.substr(j+1, str.size());
    str = leftSubStr + argToInsert + rightSubStr;
}


//template <typename T>
//std::string convertFuncArgumentToString(T t) {
//    std::string argToInsert = convert(t);
//    return argToInsert;
//}


template <typename T>
void processArgs(std::string& str, size_t& argsCounter, T t) {
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '{') {
            size_t j;
            size_t argNumber = extractArgument(str, i, j);
            if(argNumber == argsCounter) {
                std::string argToInsert = convertFuncArgumentToString(t);
                checkParanthesisInArgument(argToInsert);
                insertArgument(str, argToInsert, i, j);
            }
        }
    }
    argsCounter++;
}


template <typename T, typename... Args>
void processArgs(std::string& str, size_t& argsCounter, T t, Args... args) {
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '{') {
            size_t j;
            size_t argNumber = extractArgument(str, i, j);
            if(argNumber == argsCounter) {
                std::string argToInsert = convertFuncArgumentToString(t);
                checkParanthesisInArgument(argToInsert);
                insertArgument(str, argToInsert, i, j);
            }
        }
    }
    argsCounter++;
    processArgs(str, argsCounter, args...);
}


size_t calculateNumberOfArgumentsInString(const std::string& str, size_t& maxArgumentNumber) {
    std::set<size_t> differentArgs;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '{') {
            size_t j;
            size_t argNumber = extractArgument(str, i, j);
            differentArgs.insert(argNumber);

        }
    }

    maxArgumentNumber = *(std::max_element(differentArgs.begin(), differentArgs.end()));
    return differentArgs.size();

}

#endif // ARGS_PROCESSING_H
