#ifndef CALLBACKS_H
#define CALLBACKS_H


#include <iostream>
#include <cstring>

typedef void (*TimingCallbackPtr)();
typedef std::string (*StringTokenFoundCallbackPtr)(const std::string&);
typedef long long int (*NumberTokenFoundCallbackPtr)(long long int);


void parsingStartCallback();
void parsingFinishedCallback();
std::string stringTokenFoundCallback(const std::string& s);
long long int numberTokenFoundCallback(long long int s);



#endif // CALLBACKS_H
