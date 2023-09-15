#include <iostream>
#include <string>
#include <algorithm>
#include "lib.h"

int main() {
    std::string input;
    int vowelCount = 0;
    while(std::cin >> input){
        vowelCount += vowel_count(input);
    }
    std::cout << vowelCount;
}
