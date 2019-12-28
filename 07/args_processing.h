#ifndef ARGS_PROCESSING_H
#define ARGS_PROCESSING_H

#include <stack>
#include <type_traits>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>


template <typename T>
std::string convertFuncArgumentToString(T val) {
    throw std::runtime_error("Unknown type given");
}



std::string convertFuncArgumentToString(int val) {
    return std::to_string(val);
}


std::string convertFuncArgumentToString(double val) {
    return std::to_string(val);
}


std::string convertFuncArgumentToString(char val) {
    return std::string(1, val);
}


std::string convertFuncArgumentToString(const char* val) {
    return std::string(val);
}


std::string convertFuncArgumentToString(bool val) {
    return std::to_string(static_cast<int>(val));
}


void checkParanthesisInArgument(const std::string& str) {
    for(const char c: str) {
        if((c=='{')||(c=='}')) {
            throw std::runtime_error("{ and } symbols are reserved");
        }
    }
}


template <typename T>
void processArgs(std::unordered_map<std::string, std::string>& argsAsString,
                 size_t& argsCounter,
                 T& t) {
    std::string argToInsert = convertFuncArgumentToString(t);
    checkParanthesisInArgument(argToInsert);
    argsAsString[std::to_string(argsCounter)] = argToInsert;
    argsCounter++;
}


template <typename T, typename... Args>
void processArgs(std::unordered_map<std::string, std::string>& argsAsString,
                 size_t& argsCounter,
                 T& t, Args&... args) {
    std::string argToInsert = convertFuncArgumentToString(t);
    checkParanthesisInArgument(argToInsert);
    argsAsString[std::to_string(argsCounter)] = argToInsert;
    argsCounter++;
    processArgs(argsAsString, argsCounter, args...);
}


void insertArgs(std::string& str,
                std::unordered_map<std::string, std::string>& argsAsString) {
    std::stack<char> paranthesesStack;
    for(size_t i = 0; i < str.length(); i++) {
        if(str[i] == '{') {
            paranthesesStack.push('{');
            size_t j = i+1;
            for(; j < str.size(); j++) {
                if(str[j] == '}') {
                    paranthesesStack.pop();
                    break;
                }
            }
            std::string argNumber = str.substr(i+1, j - i - 1);
            std::string argToInsert;
            try {
                argToInsert = argsAsString.at(argNumber);
            } catch (std::out_of_range) {
                throw std::runtime_error("Arguments do not match");
            }
            std::string leftSubStr = str.substr(0, i);
            std::string rightSubStr = str.substr(j+1, str.size());
            str = leftSubStr + argToInsert + rightSubStr;
            //i = i + argToInsert.length();

        }
    }
    if(!paranthesesStack.empty()) {
        throw std::runtime_error("Number of parentheses do not match");
    }

}




#endif // ARGS_PROCESSING_H
