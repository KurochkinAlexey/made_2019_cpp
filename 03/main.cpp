#include <iostream>
#include "parser.h"
#include <cstring>

int main()
{
    Parser p;
    p.registerStartCallback(parsingStartCallback);
    p.registerFinishCallback(parsingFinishedCallback);
    p.registerNumberCallback(numberTokenFoundCallback);
    p.registerStringCallback(stringTokenFoundCallback);
    std::string s = "123 sdfsdf g1g\t1234r\nbg5\n1 23219\t19";
    p.parse(s);

    return 0;
}
