#pragma once

#include <string>

class Money {
private:
    unsigned char* array;
    int size = 0;
public:
    Money(double data);
    Money(Money &&other) noexcept; 
    Money(const std::initializer_list<unsigned char> &t);
    Money(const std::string &t); 
    Money();
    Money(const Money& other);
    void set_value(double data);
    void print() const;
    int get_size() const;
    double get_value() const;
    void serialization(std::string file_name);
    void deserialization(std::string file_name);
    unsigned char& operator[](int i) const;
    Money operator+(Money& other) const;
    Money operator-(Money& other) const;
    Money operator+(double data) const;
    Money operator-(double data) const;
    bool operator<(Money& other) const;
    bool operator<(double data) const;
    bool operator>(Money& other) const;
    bool operator>(double data) const;
    bool operator==(Money& other) const;
    bool operator==(double data) const;
    Money& operator=(const Money& other);
    Money& operator=(double data);
    ~Money();
};
