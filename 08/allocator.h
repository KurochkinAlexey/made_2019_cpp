#ifndef ALLOCATOR_H
#define ALLOCATOR_H
#include <iostream>

template <typename T>
class Allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using size_type = size_t;

    pointer allocate(size_type count);
    void deallocate(pointer ptr, size_type count);
    void constructObjects(pointer ptr, size_type start, size_type finish);
    void constructObjects(pointer ptr, size_type start, size_type finish, const value_type& defaultValue);
};



template <typename T>
T* Allocator<T>::allocate(Allocator::size_type count) {
    //pointer p = static_cast<pointer>(std::malloc(count*sizeof (T)));
    pointer p = new T[count];
    return p;
}


template<typename T>
void Allocator<T>::deallocate(Allocator::pointer ptr, Allocator::size_type count)
{
    delete [] ptr;
    //std::free(ptr);
}


template <typename T>
void Allocator<T>::constructObjects(pointer ptr, size_type start, size_type finish) {
    for(size_type i = start; i < finish; i++) {
        ptr[i] = T();
    }
}


template <typename T>
void Allocator<T>::constructObjects(pointer ptr, size_type start, size_type finish, const value_type& defaultValue) {
    for(size_type i = start; i < finish; i++) {
        ptr[i] = defaultValue;
    }
}
#endif // ALLOCATOR_H
