//
// Created by nikola354 on 01.05.22.
//
#include "helpers.h"

int toDigit(char a) {
    return (int) (a - '0');
}

int toNumber(const char *str) {
    int length = strlen(str);
    int result = 0;

    for (int i = 0; i < length; ++i) {
        result *= 10;
        result += toDigit(str[i]);
    }

    return result;
}

bool checkName(const char *name) {
    int len = strlen(name);
    return len >= MIN_NAME_LENGTH && len <= MAX_NAME_LENGTH;
}

bool checkPassword(const char *pass) {
    int len = strlen(pass);
    return len >= MIN_PASS_LENGTH && len <= MAX_PASS_LENGTH;
}

bool isDigit(char a) {
    return a >= '0' && a <= '9';
}

bool isNumber(const char *str) {
    int length = strlen(str);

    for (int i = 0; i < length; ++i) {
        if (!isDigit(str[i]))
            return false;
    }
    return true;
}

int countDigits(int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number > 0);
    return count;
}

char *toStr(int number) {
    int count = countDigits(number);
    char *result = new char[count + 1];

    for (int i = count - 1; i >= 0; --i) {
        result[i] = toChar(number % 10);
        number /= 10;
    }
    result[count] = TERMINATE_SYMBOL;
    return result;
}

char toChar(int digit) {
    return (char) (digit + '0');
}


void getNextWord(char *dest, const char *&source) {
    while (*source != ' ' && *source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    source++;
    *dest = '\0';
}