// #include "Vector.h"

// template <typename T>
// Vector<T>::Vector(): size(0), capacity(10) {
//         arr = new T[capacity];
//     }

//     template <typename T>
// Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
//         arr = new T[capacity];
//         for (int i = 0; i < size; i++) {
//             arr[i] = other.arr[i];
//         }
//     }

//     template <typename T>
// Vector<T>::Vector(std::initializer_list<T> initList) : size(0), capacity(initList.size()) {
//         arr = new T[capacity];
//         for (const auto& item : initList) {
//             push_back(item);
//         }
//     }

//     template <typename T>
// Vector<T>::~Vector() {
//         delete[] arr;
//     }

//      template <typename T>
// void Vector<T>::push_back(const T& item) {
//         if (size == capacity) {
//             capacity *= 2;
//             T* temp = new T[capacity];
//             for (int i = 0; i < size; i++) {
//                 temp[i] = arr[i];
//             }
//             delete[] arr;
//             arr = temp;
//         }
//         arr[size++] = item;
//     }

// template <typename T>
//     void Vector<T>::Vector::pop_back() {
//         if (size > 0) {
//             size--;
//         } else {
//             throw std::out_of_range("Vector is empty");
//         }
//     }

// template <typename T>
//     T& Vector<T>::operator[](int index) {
//         if (index >= 0 && index < size) {
//             return arr[index];
//         } else {
//             throw std::out_of_range("Index out of range");
//         }
//     }

// template <typename T>
//     const T& Vector<T>::operator[](int index) const {
//         if (index >= 0 && index < size) {
//             return arr[index];
//         } else {
//             throw std::out_of_range("Index out of range");
//         }
//     }

// template <typename T>
// Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
//     if (this != &other) {
//         delete[] arr;

//         size = other.size;
//         capacity = other.capacity;
//         arr = new T[capacity];
//         for (int i = 0; i < size; i++) {
//             arr[i] = other.arr[i];
//         }
//     }
//     return *this;
// }

// template <typename T>
// bool Vector<T>::operator==(const Vector& other) const {
//         if (size != other.size)
//             return false;

//         for (int i = 0; i < size; i++) {
//             if (!(arr[i] == other.arr[i]))
//                 return false;
//         }

//         return true;
//     }

// template <typename T>
//     bool Vector<T>::operator!=(const Vector& other) const {
//         return !(*this == other);
//     }

// template <typename T>
//     T& Vector<T>::operator()(int index) {
//         return operator[](index);
//     }

// template <typename T>
//     int Vector<T>::getSize() const {
//         return size;
//     }

// template <typename T>
//     int Vector<T>::getCapacity() const {
//         return capacity;
//     }