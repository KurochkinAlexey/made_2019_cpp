#include "callbacks.h"


void parsingStartCallback()
{
    std::cout << "Parsing start..." << std::endl;

}


void parsingFinishedCallback()
{
    std::cout << "Parsing finished" << std::endl;
}



void stringTokenFoundCallback()
{
    std::cout << "String token found!" << std::endl;
}



void numberTokenFoundCallback()
{
    std::cout << "Number token found!" << std::endl;
}

