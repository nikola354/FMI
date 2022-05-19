#ifndef INTERVALTASK_INTERVAL_H
#define INTERVALTASK_INTERVAL_H

#include "helpers.h"


class Interval {
private:
    int a;
    int b;

public:
    Interval();

    Interval(int a, int b);


    //methods:
    int length() const;

    bool isInInterval(int n) const;

    int countPrimeNumbers() const;
};

#endif //INTERVALTASK_INTERVAL_H
