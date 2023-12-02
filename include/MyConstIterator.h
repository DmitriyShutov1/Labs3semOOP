#include <iterator>

template <typename T>
class MyConstIterator {
public:
    using reference = const T&;
    using pointer = const T*;

    MyConstIterator(pointer ptr) : data_(ptr) {}

    MyConstIterator& operator++() {
        ++data_;
        return *this;
    }

    MyConstIterator operator++() {
        MyConstIterator temp = *this;
        ++ptr_;
        return temp;
    }

    bool operator==(const MyConstIterator& other) const {
        return data_ == other.data_;
    }

    bool operator!=(const MyConstIterator& other) const {
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