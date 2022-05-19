//
// Created by nikola354 on 01.05.22.
//

#ifndef FMI_KINDLE_HELPERS_H
#define FMI_KINDLE_HELPERS_H

#include <cstring>

#include "constants.h"

int toDigit(char a);

int toNumber(const char *str);

bool checkName(const char *name);

bool checkPassword(const char *pass);

bool isDigit(char a);

bool isNumber(const char *str);

unsigned closestPowerOfTwo(unsigned n);

#endif //FMI_KINDLE_HELPERS_H
