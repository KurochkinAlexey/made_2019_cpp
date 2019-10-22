#include <iostream>
#include <cassert>
using namespace std;

class LinearAllocator
{
public:
    LinearAllocator(size_t maxSize): maxSize(maxSize) {
        startHead = reinterpret_cast<char*>(malloc(maxSize));
        if(!startHead) {
            throw std::bad_alloc();
        }
        head = startHead;

    }

    ~LinearAllocator() {
        if(startHead != nullptr) {
            delete [] startHead;
        }
    }

    char* allocate(size_t size) {
        if(shift + static_cast<ptrdiff_t>(size) > static_cast<ptrdiff_t>(maxSize)) {
            return nullptr;
        }
        char* result = head;
        head += size;
        shift += size;
        return result;

    }

    void reset() {
        head = startHead;
        shift = 0;
    }

    ptrdiff_t getShift() {
        return shift;
    }

    void* getHead() {
        return head;
    }

private:
    char* startHead = nullptr;
    char* head = nullptr;
    ptrdiff_t shift = 0;
    size_t maxSize = 0;
};


void testAlloc() {
    std::cout << "Testing allocation..." << std::endl;
    size_t size1 = 10;
    size_t size2 = 5;
    LinearAllocator allocator(4*1024);
    char* allocatedArray1 = allocator.allocate(size1*sizeof (char));
    assert(allocator.getShift() == static_cast<ptrdiff_t>(size1));
    char* allocatedArray2 = allocator.allocate(size2*sizeof (char));
    assert(allocator.getShift() == static_cast<ptrdiff_t>(size1 + size2));
    std::cout << "Test passed" << std::endl;
}

void testReset() {
    std::cout << "Testing reset ability..." << std::endl;
    LinearAllocator allocator(4*1024);
    void* head1 = allocator.getHead();
    char* allocatedArray = allocator.allocate(10*sizeof (char));
    allocator.reset();
    void* head2 = allocator.getHead();
    assert(head1 == head2);
    std::cout << "Test passed" << std::endl;

}


void testOverflow() {
    std::cout << "Testing overflow..." << std::endl;
    LinearAllocator allocator(4*1024);
    char* allocatedArray1 = allocator.allocate(5*1024);
    assert(allocatedArray1 == nullptr);
    char* allocatedArray2 = allocator.allocate(3*1024);
    char* allocatedArray3 = allocator.allocate(2*1024);
    assert(allocatedArray3 == nullptr);
    std::cout << "Test passed" << std::endl;
}


int main(int argc, char** argv)
{
    testAlloc();
    testReset();
    testOverflow();

    return 0;
}
