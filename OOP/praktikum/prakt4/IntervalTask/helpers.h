#ifndef INTERVALTASK_HELPERS_H
#define INTERVALTASK_HELPERS_H

#include <cmath>


bool isPrime(int num) {
    int square = sqrt(num);

    for (int i = 2; i <= square; ++i) {
        if (num % i == 0)
            return false;
    }

    return true;
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

bool isPalindrome(int num) {
    int reversed = 0;
    int input = num;

    while (input != 0) {
        reversed *= 10;
        reversed += input % 10;

        input /= 10;
    }

    return num == reversed;
}

#endif

