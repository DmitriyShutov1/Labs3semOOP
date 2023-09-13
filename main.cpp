#include <iostream>
#include <string>
#include <algorithm>

#include "lib.h"

using namespace std;

int vowel_count(string s){
    char vowel[] = {'a', 'o', 'e', 'i', 'u', 'y'};
    int k = 0;
    for(char elem: s){
        if (count(begin(vowel), end(vowel), elem)){
            k += 1;
        }
    }
    return k;
}

int main() {
    string s;
    int b = 0;
    while(cin >> s){
        b += vowel_count(s);
    }
    cout << b;
}