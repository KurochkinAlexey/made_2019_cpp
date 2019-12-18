#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>


template <
        typename _Category,
        typename _Tp,
        typename _Distance = ptrdiff_t,
        typename _Pointer = _Tp*,
        typename _Reference = _Tp&>
class Iterator: public std::iterator<std::random_access_iterator_tag, _Tp>
{

public:
    typedef _Category  iterator_category;
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer;
    typedef _Reference reference;
    explicit Iterator(pointer ptr_):ptr(ptr_)  {}

    bool operator==(const Iterator<std::random_access_iterator_tag, value_type>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const Iterator<std::random_access_iterator_tag, value_type>& other) const {
        return !(*this == other);
    }

    reference operator*() const {
        return *ptr;
    }

    Iterator& operator++() {
        ++ptr;
        return *this;
    }

    Iterator& operator--() {
        --ptr;
        return *this;
    }

    Iterator& operator+=(const size_t n) {
        ptr += n;
        return *this;
    }

    Iterator& operator-=(const size_t n) {
        ptr -= n;
        return *this;
    }

//    difference_type operator-(const Iterator& it) {
//        return ptr - it.ptr;
//    }

//    difference_type operator-(const size_t val) {
//        return ptr - val;
//    }

//    difference_type operator+(const Iterator& it) {
//        return ptr + it.ptr;
//    }

//    difference_type operator+(const size_t val) {
//        return ptr + val;
//    }
private:
    pointer ptr;
};

template <
        typename _Category,
        typename _Tp,
        typename _Distance = ptrdiff_t,
        typename _Pointer = _Tp*,
        typename _Reference = _Tp&>
class ConstantIterator: public std::iterator<std::random_access_iterator_tag, _Tp>
{
public:
    typedef _Category  iterator_category;
    typedef _Tp        value_type;
    typedef _Distance  difference_type;
    typedef _Pointer   pointer;
    typedef _Reference reference;
    explicit ConstantIterator(pointer ptr_):ptr(ptr_)  {}

    bool operator==(const ConstantIterator<std::random_access_iterator_tag, value_type>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const ConstantIterator<std::random_access_iterator_tag, value_type>& other) const {
        return !(*this == other);
    }

    const reference operator*() const {
        return *ptr;
    }

    ConstantIterator& operator++() {
        ++ptr;
        return *this;
    }


    ConstantIterator& operator--() {
        --ptr;
        return *this;
    }

    ConstantIterator& operator+=(const size_t n) {
        ptr += n;
        return *this;
    }

    ConstantIterator& operator-=(const size_t n) {
        ptr -= n;
        return *this;
    }
private:
    pointer ptr;
};


#endif // ITERATOR_H
