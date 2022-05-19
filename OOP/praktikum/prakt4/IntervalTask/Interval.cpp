#include <iostream>
#include "Interval.h"

Interval::Interval() {
    a = 0;
    b = 0;
}

Interval::Interval(int a, int b) {
    if (a <= b) {
        this->a = a;
        this->b = b;
    } else {
        this->a = 0;
        this->b = 0;
    }
}

int Interval::length() const {
    return b - a;
}

bool Interval::isInInterval(int n) const {
    return n >= a && n <= b;
}

int Interval::countPrimeNumbers() const {
    int counter = 0;

    for (int i = a; i <= b; ++i) {
        if (isPrime(i)){
            counter++;
        }
    }

    return counter;
}

