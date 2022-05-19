#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

const int UPPER_LOWER_DIF = (int)'a' - (int)'A';

unsigned my_strlen(const char *str);

const char *my_strcat(const char *dest, const char *source);

char *reverseString(const char *word);

char *my_toupper(const char *str);

int main() {
    char str1[100], str2[100];
    cin >> str1 >> str2;

    cout << my_strlen(str1) << " " << my_strlen(str2) << endl;

    cout << my_strcat(str1, str2) << endl;

    cout << my_toupper(str1) << " " << my_toupper(str2) << endl;

    return 0;
}

unsigned my_strlen(const char *str) {
    unsigned index = 0;

    while (str[index] != TERMINATE_SYMBOL) {
        index++;
    }
    return index;
}

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

char *reverseString(const char *word) {
    unsigned length = my_strlen(word);

    char *reversed = new char[length];

    for (int i = 0; i < length; ++i) {
        reversed[i] = word[length - 1 - i];
    }

    return reversed;
}

char *my_toupper(const char *str){
    unsigned length = my_strlen(str);

    char *result = new char[length];

    for (int i = 0; i < length; ++i) {
        result[i] = (char)((int)str[i] - UPPER_LOWER_DIF);
    }

    return result;
}