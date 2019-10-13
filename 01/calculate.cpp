#include "calculate.h"

std::pair<double, std::string> splitBySign(std::string& expr)
{
    unsigned int i = 0;
    bool unaryMinus = false;
    if(expr[i] == '-') {
        unaryMinus = true;
        i++;
    }
    for(; i<expr.length(); i++) {
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
            break;
    }
    if(!unaryMinus) {
        std::string left_str = expr.substr(0, i);
        std::string right_str = expr.substr(i);
        double left_value = std::stod(left_str);
        std::pair<double, std::string> result(left_value, right_str);
        return result;
    } else {
        std::string left_str = expr.substr(1, i);
        std::string right_str = expr.substr(i);
        double left_value = std::stod(left_str);
        std::pair<double, std::string> result(-left_value, right_str);
        return result;
    }

}

std::pair<double, std::string> parseMultAndDiv(std::string& expr)
{
    std::pair<double, std::string> split = splitBySign(expr);
    double currentValue = split.first;
    std::string restExpr = split.second;
    while(restExpr.length() > 0) {
        char sign = restExpr[0];
        if(sign != '*' && sign != '/') {
            std::pair<double, std::string> result(currentValue, restExpr);
            return result;
        } else {
            restExpr = restExpr.substr(1);
            std::pair<double, std::string> anotherSplit = splitBySign(restExpr);
            double anotherValue = anotherSplit.first;
            restExpr = anotherSplit.second;
            if(sign == '*')  {
                currentValue *= anotherValue;
            } else if(sign == '/') {
                currentValue /= anotherValue;
            }
        }
    }
    std::pair<double, std::string> result(currentValue, restExpr);
    return result;
}

double calculate(std::string& expr)
{
    std::pair<double, std::string> firstSplit = parseMultAndDiv(expr);
    double currentValue = firstSplit.first;
    std::string restExpr = firstSplit.second;
    while(restExpr.length() > 0) {
        char sign = restExpr[0];
        restExpr = restExpr.substr(1);
        std::pair<double, std::string> anotherSplit = parseMultAndDiv(restExpr);
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
