#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <sstream>
#include "data.h"


class Serializer
{
    static constexpr char Separator = ' ';

public:
    Serializer(std::ostream &out);

    template<typename T>
    Error save(T &object)
    {
        return object.serialize(*this);
    }

    template<typename... ArgsT>
    Error operator()(ArgsT... args) {
        Error result = this->process(args...);
        return result;
    }


    template<typename First, typename... Rest>
    Error process(First firstValue, Rest... rest)
    {
        Error err1 = process(firstValue);
        if(err1 != Error::NoError)
            return err1;
        Error err2 = process(rest...);
        if(err1 != Error::NoError)
            return err1;
        if(err2 != Error::NoError)
            return err2;
        return err1;
    }

    template<typename T>
    Error process(T value)
    {

        if(is_bool<T>::value) {
            if(value)
                out_ << "true" << Separator;
            else
                out_ << "false" << Separator;
            return Error::NoError;
        } else if(is_uint64_t<T>::value) {
            out_ << value << Separator;
            return Error::NoError;
        } else
            return Error::TypeNotUnderstood;
    }

private:
    std::ostream& out_;

};

#endif // SERIALIZER_H
