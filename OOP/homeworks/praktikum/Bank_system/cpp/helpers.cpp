//
// Created by nikola354 on 01.06.22.
//

#include "../headers/helpers.h"

int countDigits(int number) {
    int count = 0;

    do {
        count++;
        number /= 10;
    } while (number > 0);
    return count;
}


char toChar(int digit) {
    return (char) (digit + '0');
}

String toStr(int number) {
    int count = countDigits(number);
    char *result = new char[count + 1];

    for (int i = count - 1; i >= 0; --i) {
        result[i] = toChar(number % 10);
        number /= 10;
    }
    result[count] = TERMINATE_SYMBOL;
    return String(result);
}
