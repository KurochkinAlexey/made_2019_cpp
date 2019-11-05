#include "callbacks.h"


void parsingStartCallback()
{
    std::cout << "Parsing start..." << std::endl;

}


void parsingFinishedCallback()
{
    std::cout << "Parsing finished" << std::endl;
}



std::string stringTokenFoundCallback(const std::string &s)
{
    std::cout << "String token found! " << s << std::endl;
    return s;
}



long long numberTokenFoundCallback(long long s)
{
    std::cout << "Number token found! " << s <<  std::endl;
    return s;
}

