#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

unsigned my_strlen(const char *str);

int my_strcmp(const char *str1, const char *str2);

//return array
const char *my_strcat(char *dest, const char *source);

char *reverseString(const char *word);

int main() {

    char word1[100];
    char word2[100];

    cin >> word1 >> word2;

    int compared = my_strcmp(word1, word2);
    if (compared > 0) {
        cout << "Greater" << endl;
    } else if (compared < 0) {
        cout << "Smaller" << endl;
    } else {
        cout << "Equal" << endl;
    }

    return 0;
}

int min(int first, int second) {
    return (first < second ? first : second);
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

//return array
const char *my_strcat(const char *dest, const char *source) {
    unsigned destLength = my_strlen(dest);
    unsigned sourceLength = my_strlen(source);
    unsigned resultLength = destLength + sourceLength + 1;

    char *result = new char[resultLength];

    for (int i = 0; i < destLength; ++i) {
        result[i] = dest[i];
    }

    for (int j = 0; j < sourceLength; ++j) {
        result[destLength + j] = source[j];
    }

    result[resultLength - 1] = TERMINATE_SYMBOL;

    return result;
}

//return array
char *reverseString(const char *word) {
    unsigned length = my_strlen(word);

    char *reversed = new char[length];

    for (int i = 0; i < length; ++i) {
        reversed[i] = word[length - 1 - i];
    }

    return reversed;
}

