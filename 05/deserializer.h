#ifndef DESERIALIZER_H
#define DESERIALIZER_H
#include <iostream>
#include "data.h"

class Deserializer
{
public:
    Deserializer(std::istream& in);

    template<typename T>
    Error load(T &object)
    {
        return object.deserialize(*this);
    }

    template<typename... ArgsT>
    Error operator()(ArgsT&... args) {
        Error result = this->process(args...);
        return result;
    }

    template<typename First, typename... Rest>
    Error process(First& firstValue, Rest&... rest)
    {
        Error err1 = process(firstValue);
        if(err1 != Error::NoError)
            return err1;
        Error err2 = process(rest...);
        if(err2 != Error::NoError)
            return err2;
        return err1;
    }

    template<typename T>
    Error process(T& value)
    {
        if(is_bool<T>::value) {
            std::string text;
            in_ >> text;
            if(text == "true")
                value = true;
            else if(text == "false")
                value = false;
            else
                return Error::CorruptedArchive;
            return Error::NoError;


        } else if(is_uint64_t<T>::value) {
            uint64_t val;
            in_ >> val;
            value = val;
            return Error::NoError;
        } else
            return Error::TypeNotUnderstood;
    }
private:
    std::istream& in_;
};

#endif // DESERIALIZER_H
