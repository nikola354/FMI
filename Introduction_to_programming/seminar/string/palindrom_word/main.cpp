#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

char *reverseWord(char *word);

bool equal(const char *str1, const char *str2);

unsigned my_strlen(const char *str);

bool isPalindrome(const char *word);

bool isPalindrome2(const char *word);

int main() {
    char word[100];
    cin >> word;

    if (isPalindrome2(word)) cout << "palindrome" << endl;
    else cout << "NOT palindrome" << endl;

    return 0;
}

unsigned my_strlen(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

char *reverseWord(const char *word) {
    unsigned length = my_strlen(word);

    char *reversed = new char[length];

    for (int i = 0; i < length; ++i) {
        reversed[i] = word[length - 1 - i];
    }

    return reversed;
}

bool isPalindrome(const char *word) {
    char *reversed = reverseWord(word);

    return equal(word, reversed);
}

//better way:
bool isPalindrome2(const char *word) {
    int length = my_strlen(word);

    for (int i = 0; i < length / 2 + 1; ++i) {
        if (word[i] != word[length - i - 1]) return false;
    }

    return true;
}

bool equal(const char *str1, const char *str2) {
    unsigned str1Length = my_strlen(str1);
    unsigned str2Length = my_strlen(str2);

    if (str1Length != str2Length) return false;

    for (int i = 0; i < str1Length; ++i) {
        if (str1[i] != str2[i]) return false;
    }

    return true;
}