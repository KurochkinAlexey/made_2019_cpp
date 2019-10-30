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
    std::cout << "String token found!" << std::endl;
    return s;
}



std::string numberTokenFoundCallback(const std::string &s)
{
    std::cout << "Number token found!" << std::endl;
    return s;
}

