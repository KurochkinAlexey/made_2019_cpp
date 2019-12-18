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
};



template <typename T>
T* Allocator<T>::allocate(Allocator::size_type count) {
    pointer p = static_cast<pointer>(std::malloc(count*sizeof (T)));
    return p;
}


template<typename T>
void Allocator<T>::deallocate(Allocator::pointer ptr, Allocator::size_type count)
{
    std::free(ptr);
}

#endif // ALLOCATOR_H
