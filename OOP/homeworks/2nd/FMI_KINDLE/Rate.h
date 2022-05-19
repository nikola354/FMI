//
// Created by nikola354 on 01.05.22.
//

#ifndef FMI_KINDLE_RATE_H
#define FMI_KINDLE_RATE_H

#include <cstring>

#include "constants.h"
#include "String.h"


class Rate {
private:
    int value; // 0-10
    String author;

public:
    Rate();

    Rate(const Rate &other);

    Rate &operator=(const Rate &other);

    ~Rate() = default;

    Rate(int value, const String &author);

private:
    void free();

    void copyFrom(const Rate &other);

public:
    int getValue() const;

    const String &getAuthor() const;

    friend std::ostream &operator<<(std::ostream &out, const Rate &rate);
};


#endif //FMI_KINDLE_RATE_H
