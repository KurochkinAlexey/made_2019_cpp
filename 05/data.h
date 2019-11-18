#ifndef DATA_H
#define DATA_H

#include <iostream>
enum class Error
{
    NoError,
    TypeNotUnderstood,
    CorruptedArchive
};

struct Data1
{
    uint64_t a;
    bool b;
    uint64_t c;

    template<typename Serializer>
    Error serialize(Serializer& serializer) {
        return serializer(a, b, c);
    }

    template<typename Deserializer>
    Error deserialize(Deserializer& deserializer) {
        return deserializer(a, b, c);
    }
};

struct Data2
{
    uint64_t x;
    uint64_t y;
    bool z;
    bool t;

    template<typename Serializer>
    Error serialize(Serializer& serializer) {
        return serializer(x, y, z, t);
    }

    template<typename Deserializer>
    Error deserialize(Deserializer& deserializer) {
        return deserializer(x, y, z, t);
    }
};

struct Data3
{
    uint32_t a;
    char* b;
    uint32_t c;

    template<typename Serializer>
    Error serialize(Serializer& serializer) {
        return serializer(a, b, c);
    }

    template<typename Deserializer>
    Error deserialize(Deserializer& deserializer) {
        return deserializer(a, b, c);
    }
};


#endif // DATA_H
