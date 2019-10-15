#include "calculate.h"

std::pair<double, std::string> splitBySign(const std::string &expr)
{
    unsigned int i = 0;
    bool unaryMinus = false;
    while(true) {
        if(expr[i]=='-'){
            unaryMinus = !unaryMinus;
            i++;
        } else {
            break;
        }
    }
    std::string subexpr = expr.substr(i);

    for(i=0; i<subexpr.length(); i++) {
        if(subexpr[i] == '+' || subexpr[i] == '-' || subexpr[i] == '*' || subexpr[i] == '/')
            break;
    }
    std::string left_str = subexpr.substr(0, i);
    std::string right_str = subexpr.substr(i);
    double left_value = std::stod(left_str);
    if(unaryMinus)
        left_value *= -1;
    std::pair<double, std::string> result(left_value, right_str);
    return result;

}

std::pair<double, std::string> parseMultAndDiv(const std::string &expr)
{
    auto split = splitBySign(expr);
    double currentValue = split.first;
    std::string restExpr = split.second;
    while(restExpr.length() > 0) {
        char sign = restExpr[0];
        if(sign != '*' && sign != '/') {
            std::pair<double, std::string> result(currentValue, restExpr);
            return result;
        } else {
            restExpr = restExpr.substr(1);
            auto anotherSplit = splitBySign(restExpr);
            double anotherValue = anotherSplit.first;
            restExpr = anotherSplit.second;
            if(sign == '*')  {
                currentValue *= anotherValue;
            } else if(sign == '/') {
                if(anotherValue == 0.0)
                    throw std::overflow_error("Division by zero");
                currentValue /= anotherValue;
            }
        }
    }
    std::pair<double, std::string> result(currentValue, restExpr);
    return result;
}

double calculate(const std::string &expr)
{
    auto firstSplit = parseMultAndDiv(expr);
    double currentValue = firstSplit.first;
    std::string restExpr = firstSplit.second;
    while(restExpr.length() > 0) {
        char sign = restExpr[0];
        restExpr = restExpr.substr(1);
        auto anotherSplit = parseMultAndDiv(restExpr);
        double anotherValue = anotherSplit.first;
        restExpr = anotherSplit.second;
        if(sign == '+') {
            currentValue += anotherValue;
        } else if (sign == '-') {
            currentValue -= anotherValue;
        }
    }
    return currentValue;
}
