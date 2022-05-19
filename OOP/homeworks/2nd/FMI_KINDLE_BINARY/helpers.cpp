//
// Created by nikola354 on 01.05.22.
//
#include <iostream>
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

unsigned closestPowerOfTwo(unsigned n) {
    unsigned count = 0;

    // First n in the below condition
    // is for the case where n is 0
    if (n && !(n & (n - 1)))
        return n;

    while (n != 0) {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
}