#ifndef VECTOR_H
#define VECTOR_H

#include "allocator.h"
#include <initializer_list>
#include "iterator.h"

const int DEFAULT_BUFFER_SIZE = 10;


template<typename T, class Alloc = Allocator<T> >
class vector
{
public:
    using size_type = size_t;
    using value_type = T;
    using referenace = T&;
    using const_reference = const T&;
    using allocator_type = Alloc;
    using iterator = Iterator<std::random_access_iterator_tag, T>;
    using const_iterator = ConstantIterator<std::random_access_iterator_tag, T>;
    using reverse_iterator = std::reverse_iterator<Iterator<std::random_access_iterator_tag, T> >;
    using const_reverse_iterator = std::reverse_iterator<ConstantIterator<std::random_access_iterator_tag, T> >;


    vector(allocator_type alloc = allocator_type());
    explicit vector(size_type count, allocator_type alloc = allocator_type());
    vector(size_type count, const_reference defaultValue, allocator_type alloc = allocator_type());
    vector(std::initializer_list<value_type> init, allocator_type alloc = allocator_type());
    ~vector();


    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator crbegin() const noexcept;

    iterator end() noexcept;
    reverse_iterator rend() noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crend() const noexcept;

    void push_back(value_type&& value);
    void push_back(const_reference value);
    void pop_back() noexcept;

    void reserve(size_type count);
    size_type size() const noexcept;
    bool empty() const noexcept;
    void clear() noexcept;
    void resize(size_type newSize);
    void resize(size_type newSize, const_reference defaultValue);

    referenace operator[](size_type i) {
        if(i > size_)
            throw std::out_of_range("Index out of range");
        return data_[i];
    }
    const_reference operator[](size_type i) const {
        if(i > size_)
            throw std::out_of_range("Index out of range");
        return data_[i];
    }

private:
    Alloc alloc_;
    size_type defaultBufferSize_;
    value_type* data_;
    size_type size_;
    size_type allocated;

};


template<typename T, class Alloc>
vector<T, Alloc>::vector(allocator_type alloc):
    alloc_(alloc),
    defaultBufferSize_(DEFAULT_BUFFER_SIZE),
    data_(nullptr),
    size_(0),
    allocated(0)
{
    reserve(defaultBufferSize_);
    allocated = defaultBufferSize_;
}


template<typename T, class Alloc>
vector<T, Alloc>::vector(vector::size_type count, vector::allocator_type alloc):
    alloc_(alloc),
    defaultBufferSize_(DEFAULT_BUFFER_SIZE),
    data_(nullptr),
    size_(count),
    allocated(0)
{
    if(count >= defaultBufferSize_) {
        reserve(count*2);
        allocated = count*2;
    } else {
        reserve(defaultBufferSize_);
        allocated = defaultBufferSize_;
    }
    alloc_.constructObjects(data_, 0, size_);
}


template<typename T, class Alloc>
vector<T, Alloc>::vector(vector::size_type count, const_reference defaultValue, vector::allocator_type alloc):
    alloc_(alloc),
    defaultBufferSize_(DEFAULT_BUFFER_SIZE),
    data_(nullptr),
    size_(count),
    allocated(0)
{
    if(count >= defaultBufferSize_) {
        reserve(count*2);
        allocated = count*2;
    } else {
        reserve(defaultBufferSize_);
        allocated = defaultBufferSize_;
    }
    alloc_.constructObjects(data_, 0, size_, defaultValue);
}


template<typename T, class Alloc>
vector<T, Alloc>::vector(std::initializer_list<vector::value_type> init, vector::allocator_type alloc):
    alloc_(alloc),
    defaultBufferSize_(DEFAULT_BUFFER_SIZE),
    data_(nullptr),
    size_(init.size()),
    allocated(0)
{
    if(size_ >= defaultBufferSize_) {
        reserve(size_*2);
        allocated = size_*2;
    } else {
        reserve(defaultBufferSize_);
        allocated = defaultBufferSize_;
    }
    size_t i = 0;
    auto current = init.begin();
    const auto end = init.end();
    while(current != end) {
        data_[i++] = *current++;
    }

}


template<typename T, class Alloc>
vector<T, Alloc>::~vector()
{
    alloc_.deallocate(data_, size_);
}


template<typename T, class Alloc>
std::reverse_iterator<ConstantIterator<std::random_access_iterator_tag, T> > vector<T, Alloc>::crbegin() const noexcept
{
    std::reverse_iterator<ConstantIterator<std::random_access_iterator_tag, T> > it(end());
    return it;
}


template<typename T, class Alloc>
std::reverse_iterator<ConstantIterator<std::random_access_iterator_tag, T> > vector<T, Alloc>::crend() const noexcept
{
    std::reverse_iterator<ConstantIterator<std::random_access_iterator_tag, T> > it(begin());
    return it;
}


template<typename T, class Alloc>
std::reverse_iterator<Iterator<std::random_access_iterator_tag, T> > vector<T, Alloc>::rend() noexcept
{
    std::reverse_iterator<Iterator<std::random_access_iterator_tag, T> > it(begin());
    return it;
}


template<typename T, class Alloc>
std::reverse_iterator<Iterator<std::random_access_iterator_tag, T> > vector<T, Alloc>::rbegin() noexcept
{
    std::reverse_iterator<Iterator<std::random_access_iterator_tag, T> > it(end());
    return it;
}


template<typename T, class Alloc>
ConstantIterator<std::random_access_iterator_tag, T> vector<T, Alloc>::cbegin() const noexcept
{
    ConstantIterator<std::random_access_iterator_tag, T> it(data_);
    return it;
}


template<typename T, class Alloc>
ConstantIterator<std::random_access_iterator_tag, T> vector<T, Alloc>::cend() const noexcept
{
    ConstantIterator<std::random_access_iterator_tag, T> it(data_+size_);
    return it;
}


template<typename T, class Alloc>
Iterator<std::random_access_iterator_tag, T> vector<T, Alloc>::end() noexcept
{
    Iterator<std::random_access_iterator_tag, T> it(data_+size_);
    return it;

}


template<typename T, class Alloc>
Iterator<std::random_access_iterator_tag, T> vector<T, Alloc>::begin() noexcept
{
    Iterator<std::random_access_iterator_tag, T> it(data_);
    return it;
}


template<typename T, class Alloc>
void vector<T, Alloc>::push_back(vector::value_type &&value)
{
    if(size_ >= allocated) {
        reserve(size_*2);
        allocated = size_*2;
    }

    data_[size_] = value;
    size_++;
}


template<typename T, class Alloc>
void vector<T, Alloc>::push_back(vector::const_reference value)
{
    if(size_ >= allocated) {
        reserve(size_*2);
        allocated = size_*2;
    }

    data_[size_] = value;
    size_++;
}


template<typename T, class Alloc>
void vector<T, Alloc>::pop_back() noexcept
{
    if(size_ > 0)
        size_--;
}


template <typename T, class Alloc>
void vector<T, Alloc>::reserve(vector::size_type count)
{   if(count > size_) {
       value_type* p = alloc_.allocate(count);
       if(data_ == nullptr) {
           data_ = p;
       } else {
           for(size_t i = 0; i < size_; i++) {
               p[i] = data_[i];
           }
           alloc_.deallocate(data_, size_);
           data_ = p;
       }
    }
}


template<typename T, class Alloc>
size_t vector<T, Alloc>::size() const noexcept
{
    return size_;
}


template<typename T, class Alloc>
bool vector<T, Alloc>::empty() const noexcept
{
    if(size_ != 0)
        return false;
    else
        return true;
}


template<typename T, class Alloc>
void vector<T, Alloc>::clear() noexcept
{
    if(data_ != nullptr) {
        alloc_.deallocate(data_, size_);
        data_ = alloc_.allocate(defaultBufferSize_);
        allocated = defaultBufferSize_;
        size_ = 0;
    }
}


template<typename T, class Alloc>
void vector<T, Alloc>::resize(vector::size_type newSize)
{
    if(newSize > allocated){
       value_type* p = alloc_.allocate(2*newSize);
       for(size_t i = 0; i < size_; i++) {
           p[i] = data_[i];
       }
       alloc_.deallocate(data_, size_);
       data_ = p;
       allocated = 2*newSize;

    }
    alloc_.constructObjects(data_, size_, newSize);
    size_ = newSize;
}


template<typename T, class Alloc>
void vector<T, Alloc>::resize(vector::size_type newSize, vector::const_reference defaultValue)
{
    if(newSize > allocated){
       value_type* p = alloc_.allocate(2*newSize);
       for(size_t i = 0; i < size_; i++) {
           p[i] = data_[i];
       }
       alloc_.deallocate(data_, size_);
       data_ = p;
       allocated = 2*newSize;

    }
    alloc_.constructObjects(data_, size_, newSize, defaultValue);
    size_ = newSize;
}


#endif // VECTOR_H
