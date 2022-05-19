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

int countDigits(int number);

char *toStr(int number);

char toChar(int digit);


void getNextWord(char *dest, const char *&source);

#endif //FMI_KINDLE_HELPERS_H
