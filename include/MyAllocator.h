#pragma once

#include <cstddef>
#include <stdexcept>
#include <cstdlib>
#include <vector>

template <typename T, size_t MemorySize = 500000>
class MyAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    template <typename U>
    struct rebind {
        using other = MyAllocator<U, MemorySize>;
    };

    MyAllocator() {
        allocatedMemory.push_back(std::vector<T>(MemorySize));
        currentBlockOfMemory = &allocatedMemory.back();
        currentFreeIndex = 0;
    }

    template <typename U>
    MyAllocator(const MyAllocator<U, MemorySize>&) {}

    pointer allocate(size_type n) {
        if (currentFreeIndex + n > currentBlockOfMemory->size()) {
            allocatedMemory.push_back(std::vector<T>(MemorySize));
            currentBlockOfMemory = &allocatedMemory.back();
            currentFreeIndex = 0;
        }
        pointer p = &(*currentBlockOfMemory)[currentFreeIndex];
        currentFreeIndex += n;
        return p;
    }

    void deallocate(pointer p, size_type n) {
    }
    
private:
    std::vector<std::vector<T>> allocatedMemory;
    std::vector<T>* currentBlockOfMemory;
    size_type currentFreeIndex;
}; 