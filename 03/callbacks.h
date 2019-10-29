#ifndef CALLBACKS_H
#define CALLBACKS_H


#include <iostream>

typedef void (*CallbackPtr)();

void parsingStartCallback();
void parsingFinishedCallback();
void stringTokenFoundCallback();
void numberTokenFoundCallback();



#endif // CALLBACKS_H
