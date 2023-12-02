#include <vector>
#include "MyAllocator.h"
#include "MyIterator.h"

template <class T, typename Allocator = MyAllocator<T>>
class MyQueue {
private:
    std::vector<T, Allocator> data_;

public:

    MyQueue(){}

    int size() const {
        return data_.size();
    }

    bool empty() const {
        return data_.empty();
    }

    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        data_.erase(data_.begin());
    }

    const T& front() const {
        return data_.front();
    }

    T& back() {
        return data_.back();
    }

    using iterator = MyIterator<T>;

    iterator begin() {
        return iterator(&data_[0]);
    }

    iterator end() {
        return iterator(&data_[data_.size()]);
    }
};

