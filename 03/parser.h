#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "callbacks.h"


typedef void (*HandlerPtr)();

class Parser
{
public:
    Parser();
    void parse(const char* s, size_t n);
    void registerStartCallback(CallbackPtr startCallback);
    void registerFinishCallback(CallbackPtr finishCallback);
    void registerStringCallback(CallbackPtr stringCallback);
    void registerNumberCallback(CallbackPtr numberCallback);


private:
    std::vector<char> separators;
    std::vector<char> digits;
    bool isNumber(std::string token);
    void defineTokenType(const std::string& s, size_t* head, size_t tail);
    CallbackPtr startCallback;
    CallbackPtr finishCallback;
    CallbackPtr stringCallback;
    CallbackPtr numberCallback;
};

#endif // PARSER_H
