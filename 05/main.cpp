#include <iostream>
#include "serializer.h"
#include "deserializer.h"
#include <cassert>
using namespace std;


int main()
{
    Data1 d1 = {1, false, 0};
    Data2 d2 = {10, 20, true, false};
    Data1 d3 = {2, true, 2};
    Data2 d4 = {0, 1, false, false};
    Data1 d5 = {5, true, 5};
    Data3 d6 = {1, nullptr, 10};

    std::stringstream s1;
    std::stringstream s2;

    Serializer ss1(s1);
    Serializer ss2(s2);
    Error saveRes1 = ss1.save(d1);
    Error saveRes2 = ss2.save(d2);
    assert(saveRes1 == Error::NoError);
    assert(saveRes2 == Error::NoError);

    Deserializer ds1(s1);
    Deserializer ds2(s2);
    Error loadRes1 = ds1.load(d3);
    Error loadRes2 = ds2.load(d4);
    assert(loadRes1 == Error::NoError);
    assert(loadRes2 == Error::NoError);
    assert(d1.a == d3.a);
    assert(d1.b == d3.b);
    assert(d1.c == d3.c);
    assert(d2.x == d4.x);
    assert(d2.y == d4.y);
    assert(d2.z == d4.z);
    assert(d2.t == d4.t);

    Error loadRes3 = ds2.load(d5);
    assert(loadRes3 != Error::NoError);

    Error saveRes3 = ss1.save(d6);
    assert(saveRes3 != Error::NoError);


    return 0;
}
