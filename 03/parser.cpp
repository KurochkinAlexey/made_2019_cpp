#include "parser.h"


Parser::Parser():
    separators({' ', '\t', '\n'}),
    startCallback(nullptr),
    finishCallback(nullptr),
    stringCallback(nullptr),
    numberCallback(nullptr)
{

}


void Parser::parse(const std::string& stringToParse)
{

    if(startCallback != nullptr)
        startCallback();

    size_t head = 0;
    size_t& headRef = head;
    std::string s(stringToParse);
    for(size_t i = 0; i < stringToParse.size(); i++) {
        for(size_t j = 0; j < separators.size(); j++) {
            if(s[i] == separators[j]) {
                defineTokenType(s, headRef, i);
            }
        }
    }
    defineTokenType(s, headRef, stringToParse.size());
    if(finishCallback != nullptr)
        finishCallback();
}


void Parser::registerStartCallback(TimingCallbackPtr startCallback)
{
    this->startCallback = startCallback;
}


void Parser::registerFinishCallback(TimingCallbackPtr finishCallback)
{
    this->finishCallback = finishCallback;
}


void Parser::registerStringCallback(TokenFoundCallbackPtr stringCallback)
{
    this->stringCallback = stringCallback;
}


void Parser::registerNumberCallback(TokenFoundCallbackPtr numberCallback)
{
    this->numberCallback = numberCallback;
}


bool Parser::isNumber(std::string token)
{
    bool result = true;
    for(size_t i = 0; i < token.size(); i++) {
        if(!std::isdigit(token[i])){
            result = false;
            break;
        }
    }
    return result;
}

void Parser::defineTokenType(const std::string &s, size_t& head, size_t tail)
{
    std::string token = s.substr(head, tail-(head));
    head = tail + 1;
    if(isNumber(token)) {
        if(numberCallback != nullptr)
            numberCallback(token);
    } else {
        if(stringCallback != nullptr)
            stringCallback(token);
    }
}
