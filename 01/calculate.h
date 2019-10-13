#ifndef CALCULATE_H
#define CALCULATE_H
#include<iostream>



std::pair<double, std::string> splitBySign(std::string& expr);

std::pair<double, std::string> parseMultAndDiv(std::string& expr);

double calculate(std::string& expr);

#endif // CALCULATE_H
