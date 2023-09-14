#include <iostream>
#include <string>
#include "lib.h"
#include <algorithm>

int vowel_count(std::string s){
    char vowel[] = {'a', 'o', 'e', 'i', 'u', 'y'};
    int k = 0;
    for(char elem: s){
        if (std::count(std::begin(vowel), std::end(vowel), elem))
            k += 1;
    }
    return k;
}
