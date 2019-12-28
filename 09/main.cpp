#include <iostream>
#include "threadpool.h"
#include <cmath>
#include <cassert>


int dummy() {
    return 2+2;
}

struct Point
{
    int x = 10;
    int y = 20;
};


double radius(const Point& p) {
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
}


int main()
{
    Point point;
    ThreadPool pool(2);
    auto task1 = pool.exec(dummy);
    auto task2 = pool.exec(radius, point);
    auto task3 = pool.exec([](int x, int y, int z) {
       return x + y*z;
    }, 2, 2, 2);
    auto res1 = task1.get();
    assert(res1 == 4);
    auto res2 = task2.get();
    assert(std::abs(res2 - 22.3607) < 0.0001);
    auto res3 = task3.get();
    assert(res3 == 6);
    std::cout << res1 << " " << res2 << " " << res3 << std::endl;

    return 0;
}
