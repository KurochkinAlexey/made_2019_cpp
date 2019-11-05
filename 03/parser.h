#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "callbacks.h"




class Parser
{
public:
    Parser();
    void parse(const std::string &s);
    void registerStartCallback(TimingCallbackPtr startCallback);
    void registerFinishCallback(TimingCallbackPtr finishCallback);
    void registerStringCallback(StringTokenFoundCallbackPtr stringCallback);
    void registerNumberCallback(NumberTokenFoundCallbackPtr numberCallback);


private:
    std::vector<char> separators;
    bool isNumber(std::string token);
    void defineTokenType(const std::string& s, size_t& head, size_t tail);
    TimingCallbackPtr startCallback;
    TimingCallbackPtr finishCallback;
    StringTokenFoundCallbackPtr stringCallback;
    NumberTokenFoundCallbackPtr numberCallback;
};

#endif // PARSER_H
