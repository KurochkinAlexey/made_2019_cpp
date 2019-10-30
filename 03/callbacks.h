#ifndef CALLBACKS_H
#define CALLBACKS_H


#include <iostream>
#include <cstring>

typedef void (*TimingCallbackPtr)();
typedef std::string (*TokenFoundCallbackPtr)(const std::string&);

void parsingStartCallback();
void parsingFinishedCallback();
std::string stringTokenFoundCallback(const std::string& s);
std::string numberTokenFoundCallback(const std::string& s);



#endif // CALLBACKS_H
