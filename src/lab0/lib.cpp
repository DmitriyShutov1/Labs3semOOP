#include <iostream>
#include <string>
#include "lib.h"
#include <algorithm>

int vowel_count(std::string input){
    char vowel[] = {'a', 'o', 'e', 'i', 'u', 'y'};
    int result = 0;
    for(char elem: input){
        if (std::count(std::begin(vowel), std::end(vowel), elem))
            result += 1;
    }
    return result;
}
