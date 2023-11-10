#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* arr;
    int size;
    int capacity;
public:
    Vector() : size(0), capacity(10) {
        arr = new T[capacity];
    }

    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector(std::initializer_list<T> initList) : size(0), capacity(initList.size()) {
        arr = new T[capacity];
        for (const auto& item : initList) {
            push_back(item);
        }
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(const T& item) {
        if (size == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[size++] = item;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < size) {
            return arr[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;

            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

bool operator==(const Vector& other) const {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++) {
            if (!(arr[i] == other.arr[i]))
                return false;
        }

        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    T& operator()(int index) {
        return operator[](index);
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};