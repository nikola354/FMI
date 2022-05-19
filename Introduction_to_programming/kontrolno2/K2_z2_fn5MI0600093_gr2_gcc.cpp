/**
 @author Nikola Manolov
 @idnumber 5MI0600093
 @compiler GCC
 * */

#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

void encode(const char *s1, const char *r1, char *s2, char *r2);

int main() {

    char result[] = {TERMINATE_SYMBOL};
    encode("hello","worrd","love",result);

    cout << result;

    return 0;
}

unsigned my_strlen(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

int my_strcmp(const char *str1, const char *str2) {
    unsigned str1Length = my_strlen(str1);
    unsigned str2Length = my_strlen(str2);

    for (int i = 0; i < min(str1Length, str2Length); ++i) {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
    }

    return 0;
}

void encode(const char *s1, const char *r1, char *s2, char *r2) {
    int mappings[128] = {0};
    
    unsigned s1Length = my_strlen(s1);
    unsigned r1Length = my_strlen(r1);

    if (s1Length != r1Length){
        r2[0] = TERMINATE_SYMBOL;
        return;
    }

    if (my_strcmp(s1, r1) == 0){
        r2 = s2;
        return;
    }

    for (int i = 0; i < s1Length; ++i) {
        if (s1[i] != r1[i]){
            mappings[s1[i]] = (int)r1[i];
        }
    }

    int s2Length = my_strlen(s2);

    for (int j = 0; j < s2Length; ++j) {
        if (mappings[s2[j]] == 0){
            r2[j] = s2[j];
        }else{
            r2[j] = (char) mappings[s2[j]];
        }
    }



}