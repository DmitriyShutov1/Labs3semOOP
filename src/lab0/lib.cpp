#include <iostream>
#include <fstream>
#include "lib.h"
#include <string>



Money::Money(Money &&other) noexcept{
    size = other.size;
    array = other.array;
    other.size = 0;
    other.array = nullptr;
}

Money::Money(const std::initializer_list<unsigned char> &t){
    array = new unsigned char[t.size()];
    size_t i{0};
    for (auto &c : t)
        array[i++] = c;
    size = t.size();
    double d = this->get_value();
    if(static_cast<int>(d * 100) / 100.0 != d){
            throw "Wrong parametr";
    }
}

Money::Money(){
        size = 0;
        array = nullptr;
}

Money::Money(const std::string &t){
        double data = stod(t);
        if(static_cast<int>(data * 100) / 100.0 != data){
            throw "Wrong parametr";
        }
        else{
                data *= 100;
                int data_int = (int) data;
                int count = 0;
                int temp = data_int;
                while (temp != 0) {
                        temp /= 10;
                        count++;
                }
                size = count;
                //создаем массив и записываем в него число
                array = new unsigned char[size + 1];
                int temporary_data = data_int;
                for (int i = 0; i < size; ++i) {
                        char elem = (temporary_data % 10) + '0';
                        array[size - 1 - i] = elem;
                        temporary_data /= 10;
                }
                array[size] = '\0';
        }
}


Money::Money(double data) {
        if(static_cast<int>(data * 100) / 100.0 != data){
            throw "Wrong parametr";
        }
        else{
            data *= 100;
            int data_int = (int) data;
            //определяем количество цифр в числе
            int count = 0;
            int temp = data_int;
            while (temp != 0) {
                temp /= 10;
                count++;
            }
            size = count;
            //создаем массив и записываем в него число
            array = new unsigned char[size + 1];
            int temporary_data = data_int;
            for (int i = 0; i < size; ++i) {
                char elem = (temporary_data % 10) + '0';
                array[size - 1 - i] = elem;
                temporary_data /= 10;
            }
            array[size] = '\0';
        }
}

Money::Money(const Money& other) {
        size = other.get_size();
        array = new unsigned char[size + 1];
        double temporary_data = other.get_value();
        temporary_data *= 100;
        int temporary_data_int = (int) temporary_data;
        for (int i = 0; i < size; ++i) {
            char elem = (temporary_data_int % 10) + '0';
            array[size - 1 - i] = elem;
            temporary_data_int /= 10;
        }
        array[size] = '\0';
}

void Money::set_value(double data) {
        if(static_cast<int>(data * 100) / 100.0 != data){
            throw "Wrong parametr";
        }
        else{
            data *= 100;
            int data_int = (int) data;

            int count = 0;
            int temp = data_int;
            while (temp != 0) {
                temp /= 10;
                count++;
            }
            if (count != size) {
                size = count;
                unsigned char* new_array = new unsigned char[size + 1];
                int temporary_data = data_int;
                for (int i = 0; i < size; ++i) {
                    char elem = (temporary_data % 10) + '0';
                    new_array[size - 1 - i] = elem;
                    temporary_data /= 10;
                }
                new_array[size] = '\0';
                delete[] array;
                array = new_array;
            }
            else {
                int temporary_data = data_int;
                for (int i = 0; i < size; ++i) {
                    char elem = (temporary_data % 10) + '0';
                    array[size - 1 - i] = elem;
                    temporary_data /= 10;
                }
                array[size] = '\0';
            }
        }
}

void Money::print() const{
        std::cout << "The amount of money in the account: " << get_value() << std::endl;
    }

int Money::get_size() const {
        return size;
}

double Money::get_value() const {
        if (size != 0) {
            double result = 0;
            int ct = 1;
            for (int i = 0; i < size; ++i) {
                int elem = array[size - 1 - i] - '0';
                result += ct * elem;
                ct *= 10;
            }
            result /= 100;
            return result;
        }
        else {
            return 0;
        }
} 


void Money::serialization(std::string file_name){
        std::ifstream file(file_name);
        std::string input;
        if(file.is_open()){
            std::getline(file, input);
            double data = stod(input);
            data *= 100;
            int data_int = (int) data;
            //определяем количество цифр в числе
            int count = 0;
            int temp = data_int;
            while (temp != 0) {
                temp /= 10;
                count++;
            }
            size = count;
            //создаем массив и записываем в него число
            array = new unsigned char[size + 1];
            int temporary_data = data_int;
            for (int i = 0; i < size; ++i) {
                char elem = (temporary_data % 10) + '0';
                array[size - 1 - i] = elem;
                temporary_data /= 10;
            }
            array[size] = '\0';
            file.close();
        }
        else{
            throw "File not open";
        }
}


void Money::deserialization(std::string file_name){
        std::ofstream file(file_name, std::ios::binary);
        if (!file) {
            throw "File not open";
        }
        double result = 0;
            int ct = 1;
            for (int i = 0; i < size; ++i) {
                int elem = array[size - 1 - i] - '0';
                result += ct * elem;
                ct *= 10;
            }
        result /= 100;
        std::string output = std::to_string(result);
        file.write(output.c_str(), output.size());
        file.close();
        std::cout << "Массив char'ов успешно записан в файл." << std::endl;
}


unsigned char& Money::operator[](int i) const{
        if ((i < size) and (i >= 0)) {
            return array[i];
        }
        if (i == -1){
            return array[size-1];
        }
        else{
            throw "Wrong parametr";
        }
}

Money Money::operator+(Money& other) const{
        double data = get_value() + other.get_value();
        Money sum(data);
        return sum;
}

Money Money::operator-(Money& other) const{
        double data = get_value() - other.get_value();
        Money difference(data);
        return difference;
}

Money Money::operator+(double data) const{
        double data_temp = get_value() + data;
        Money sum(data_temp);
        return sum;
}

Money Money::operator-(double data) const{
        double data_temp = get_value() - data;
        Money difference(data_temp);
        return difference;
}

bool Money::operator<(Money& other) const{
        if (get_value() < other.get_value()) {
            return 1;
        }
        else {
            return 0;
        }
}

bool Money::operator<(double data) const{
        if (get_value() < data) {
            return 1;
        }
        else {
            return 0;
        }
}

bool Money::operator>(Money& other) const{
        if (get_value() > other.get_value()) {
            return 1;
        }
        else {
            return 0;
        }
}

bool Money::operator>(double data) const{
        if (get_value() > data) {
            return 1;
        }
        else {
            return 0;
        }
}

bool Money::operator==(Money& other) const{
        if (get_value() == other.get_value()) {
            return 1;
        }
        else {
            return 0;
        }
}

bool Money::operator==(double data) const{
        if (get_value() == data) {
            return 1;
        }
        else {
            return 0;
        }
}

Money& Money::operator=(const Money& other) {
        if (other.get_size() != size) {
            size = other.get_size();
            unsigned char* new_array = new unsigned char[size + 1];
            double temporary_data = other.get_value();
            temporary_data *= 100;
            int temporary_data_int = (int)temporary_data;
            for (int i = 0; i < size; ++i) {
                char elem = (temporary_data_int % 10) + '0';
                new_array[size - 1 - i] = elem;
                temporary_data_int /= 10;
            }
            new_array[size] = '\0';
            delete[] array;
            array = new_array;
            return *this;
        }
        else {
            double temporary_data = other.get_value();
            temporary_data *= 100;
            int temporary_data_int = (int)temporary_data;
            for (int i = 0; i < size; ++i) {
                char elem = (temporary_data_int % 10) + '0';
                array[size - 1 - i] = elem;
                temporary_data_int /= 10;
            }
            array[size] = '\0';
            return *this;
        }
}

Money& Money::operator=(double data) {
        if(static_cast<int>(data * 100) / 100.0 != data){
            throw "wrong parametr";
        }
        else{
            int count = 0;
            data*=100;
            int temp = (int)data;
            while (temp != 0) {
                temp /= 10;
                count++;
            }
            if (count != size) {
                size = count;
                unsigned char* new_array = new unsigned char[size + 1];
                int temporary_data_int = (int)data;
                for (int i = 0; i < size; ++i) {
                    char elem = (temporary_data_int % 10) + '0';
                    new_array[size - 1 - i] = elem;
                    temporary_data_int /= 10;
                }
                new_array[size] = '\0';
                delete[] array;
                array = new_array;
                return *this;
            }
            else {
                int temporary_data_int = (int)data;
                for (int i = 0; i < size; ++i) {
                    char elem = (temporary_data_int % 10) + '0';
                    array[size - 1 - i] = elem;
                    temporary_data_int /= 10;
                }
                array[size] = '\0';
                return *this;
            }
        }
}

Money::~Money() {
        delete[] array;
}
