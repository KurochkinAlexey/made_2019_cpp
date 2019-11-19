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


template <typename T>
struct is_bool
{
    static constexpr bool value = false;
};

template <>
struct is_bool<bool>
{
    static constexpr bool value = true;
};

template <typename T>
struct is_uint64_t
{
    static constexpr bool value = false;
};

template <>
struct is_uint64_t<uint64_t>
{
    static constexpr bool value = true;
};



#endif // DATA_H
