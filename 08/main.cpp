#include "vector.h"
#include <iostream>

struct Point {
    Point(): x(1), y(-1) {}
    Point(double x_, double y_) : x(x_), y(y_) {}
    ~Point() {std::cout << "destruction" << std::endl;}
    double x;
    double y;
};

int main()
{
    std::cout << "creating empty vector" << std::endl;
    vector<int> v;

    std::cout << "check if vector is empty" << std::endl;
    std::cout << v.empty() << std::endl;

    std::cout << "creating vector of size 10" << std::endl;
    vector<double> v1(10);
    for(size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "check if vector is empty" << std::endl;
    std::cout << v1.empty() << std::endl;

    std::cout << "filling vector" << std::endl;
    for(size_t i = 0; i < v1.size(); i++) {
        v1[i] = i;
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "creating vector of size 10 with default value 3" << std::endl;
    vector<double> v2(10, 3);
    for(size_t i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "creating vector with initializer list {1, 2, 3, 4, 5}" << std::endl;
    vector<double> v3 = {1, 2, 3, 4, 5};
    for(size_t i = 0; i < v3.size(); i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "clearing vector" << std::endl;
    v3.clear();
    std::cout << "check if vector is empty" << std::endl;
    std::cout << v3.empty() << std::endl;

    std::cout << "resizing vector of {1, 2, 3} to size of 6" << std::endl;
    vector<int> v4 = {1, 2, 3};
    v4.resize(6);
    for(size_t i = 0; i < v4.size(); i++) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "pop last value from vector of {1, 2, 3}" << std::endl;
    vector<int> v5 = {1, 2, 3};
    v5.pop_back();
    for(size_t i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "pushing back 8 value to vector of {1, 2, 3, 4}" << std::endl;
    vector<size_t> v6 = {1, 2, 3, 4};
    for(size_t i = 5; i < 13; i++) {
        v6.push_back(i);
    }

    for(size_t i = 0; i < v6.size(); i++) {
        std::cout << v6[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "iterating through vector with iterator" << std::endl;
    for(vector<size_t>::iterator i = v6.begin(); i!= v6.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "filling vector with iterator" << std::endl;
    size_t j = v6.size();
    for(vector<size_t>::iterator i = v6.begin(); i!= v6.end(); ++i, j--) {
        *i = j;
    }

    for(vector<size_t>::iterator i = v6.begin(); i!= v6.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "iterating through vector with reverse iterator" << std::endl;
    for(vector<size_t>::reverse_iterator i = v6.rbegin(); i!= v6.rend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "Complex objects" << std::endl;
    vector<Point> vecOfPoints;
    vecOfPoints.push_back(Point(4, 5));
    vecOfPoints.resize(3);

    for(vector<Point>::iterator i = vecOfPoints.begin(); i != vecOfPoints.end(); ++i) {
        std::cout << (*i).x << " " << (*i).y << std::endl;
    }


    return 0;
}
