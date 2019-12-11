#include <iostream>
#include "bigint.h"
#include <cassert>
#include <cstdlib>
#include <string>
#include <sstream>

int main()
{

    BigInt bi(1234);
    bi = bi + 567;
    assert(bi == 1801);

    BigInt bi1(1234);
    bi1 = bi1 + 89567;
    assert(bi1 == 90801);

    BigInt bi2(999);
    bi2 = bi2 + 1;
    assert(bi2 == 1000);

    BigInt bi3(123);
    bi3 = bi3 + 234;
    assert(bi3 == 357);

    BigInt bi4(123);
    BigInt bi5(456);
    BigInt bi6 = bi4 + bi5;
    assert(bi6 == 579);

    BigInt bi7(234);
    bi7 = bi7 - 123;
    assert(bi7 == 111);

    BigInt bi8(92);
    bi8 = bi8 - 7;
    assert(bi8 == 85);

    BigInt bi9(1009);
    bi9 = bi9 - 225;
    assert(bi9 == 784);

    BigInt bi10(300);
    bi10 = bi10 - 500;
    assert(bi10 == -200);

    BigInt bi11(800);
    bi11 = bi11 + 356;
    assert(bi11 == 1156);

    BigInt bi12(250);
    bi12 = bi12 - 1000;
    assert(bi12 == -750);

    BigInt bi13(250);
    bi13 = bi13 - 1500;
    assert(bi13 == -1250);

    BigInt bi14(300);
    BigInt bi15(250);
    BigInt bi16 = bi14 - bi15;
    assert(bi16 == 50);

    BigInt bi17(2);
    BigInt bi18(50);
    BigInt bi19(-10);
    BigInt bi20(-20);
    BigInt bi21(50);
    BigInt bi22(1024);
    BigInt bi23(-1024);

    assert(bi17 > 1);
    assert(bi18 > bi17);
    assert(!(bi17 < 1));
    assert(!(bi17 <= 1));
    assert(bi17 != 1);
    assert(bi17 < bi18);
    assert(!(bi18 < bi17));
    assert(!(bi18 <= bi17));
    assert(bi17 != bi18);
    assert(bi18 > bi19);
    assert(bi19 < bi18);
    assert(bi19 <= bi18);
    assert(bi20 < bi19);
    assert(bi19 >= bi20);
    assert(bi19 > bi20);
    assert(bi18 == bi21);
    assert(bi22 != bi23);
    assert(bi22 == -bi23);
    assert(bi18 < 60);
    assert(bi17 > -100);
    assert(bi18 > -2000);
    assert(bi20 > -2000);
    assert(bi23 > -1500);
    assert(bi23 < -20);
    assert(bi23 < 100);
    assert(bi23 == -1024);

    BigInt bi24(10);
    bi24 = bi24 + -100;
    assert(bi24 == -90);

    BigInt bi25(23);
    BigInt bi26(-24);
    BigInt bi27 = bi25 + bi26;
    assert(bi27 == -1);

    BigInt bi28 = bi26 + bi25;
    assert(bi28 == -1);

    BigInt bi29 = 100;
    bi29 = bi29 - 1000;
    assert(bi29 == -900);

    BigInt bi30 = -100;
    bi30 = bi30 - 200;
    assert(bi30 == -300);

    BigInt bi31 = -250;
    bi31 = bi31 - -251;
    assert(bi31 == 1);

    BigInt bi32 = 123456;
    std::cout << bi32;
    std::cout << std::endl;
    BigInt bi33 = 123;
    BigInt bi34 = 256;

    BigInt bi35(std::move(bi33));
    assert(bi35 == 123);

    BigInt bi36 = std::move(bi34);
    assert(bi36 == 256);

    BigInt bi37(1000);
    BigInt bi38(2000);
    BigInt bi39(-5000);

    BigInt bi40 = bi37 + bi38 + bi39 + 10000;
    assert(bi40 == 8000);

    BigInt bi41 = 2147483647;
    bi41 = bi41 + 2147483647;

    std::cout << 2147483647 << "+" << 2147483647 << "=";
    std::cout << bi41;

//    std::ostringstream res("");
//    for(size_t i = 0; i < bi41.getSize(); i++) {
//        res << bi41.getData*///()[i];
//    }

//    std::string result = res.str();


    //assert(result == "4294967294");


    return 0;
}
