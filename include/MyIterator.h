#include <iterator>

template <typename T>
class MyIterator {
public:
    using reference = T&;
    using pointer = T*;

    MyIterator(pointer ptr) : data_(ptr) {}

    MyIterator& operator++() {
        ++data_;
        return *this;
    }

    bool operator==(const MyIterator& other) const {
        return data_ == other.data_;
    }

    bool operator!=(const MyIterator& other) const {
        return data_ != other.data_;
    }

    reference operator*() const {
        return *data_;
    }

    pointer operator->() const {
        return data_;
    }

private:
    pointer data_;
};