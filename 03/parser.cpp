#include "parser.h"


Parser::Parser():
    separators({' ', '\t', '\n'}),
    digits({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}),
    startCallback(nullptr),
    finishCallback(nullptr),
    stringCallback(nullptr),
    numberCallback(nullptr)
{

}


void Parser::parse(const char *stringToParse, size_t n)
{

    if(startCallback != nullptr)
        startCallback();
    else
        std::cout << "Start callback not registered" << std::endl;
    size_t head = 0;
    std::string s(stringToParse);
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < separators.size(); j++) {
            if(s[i] == separators[j]) {
                defineTokenType(s, &head, i);
            }
        }
    }
    defineTokenType(s, &head, n);
    if(finishCallback != nullptr)
        finishCallback();
    else
        std::cout << "Finish callback not registered" << std::endl;

}


void Parser::registerStartCallback(CallbackPtr startCallback)
{
    this->startCallback = startCallback;
}


void Parser::registerFinishCallback(CallbackPtr finishCallback)
{
    this->finishCallback = finishCallback;
}


void Parser::registerStringCallback(CallbackPtr stringCallback)
{
    this->stringCallback = stringCallback;
}


void Parser::registerNumberCallback(CallbackPtr numberCallback)
{
    this->numberCallback = numberCallback;
}


bool Parser::isNumber(std::string token)
{
    bool result = true;
    for(size_t i = 0; i < token.size(); i++) {
        bool isDigit = false;
        for(size_t j = 0; j < digits.size(); j++) {
            if(token[i] == digits[j])
                isDigit = true;
        }
        if(!isDigit){
            result = isDigit;
            break;
        }
    }
    return result;
}

void Parser::defineTokenType(const std::string &s, size_t *head, size_t tail)
{
    std::string token = s.substr(*head, tail-(*head));
    *head = tail + 1;
    if(isNumber(token)) {
        if(numberCallback != nullptr)
            numberCallback();
        else
            std::cout << "Number callback not registered" << std::endl;
    } else {
        if(stringCallback != nullptr)
            stringCallback();
        else
            std::cout << "String callback not registered" << std::endl;
    }
}
