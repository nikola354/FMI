#ifndef INC_1_HELPERS_H
#define INC_1_HELPERS_H

int my_pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }
    return length;
}

bool isDigit(char a) {
    return a >= '0' && a <= '9';
}

bool isUpper(char a) {
    return a >= 'A' && a <= 'Z';
}

bool isLower(char a) {
    return a >= 'a' && a <= 'z';
}

int toDigit(char a) {
    return (int) (a - '0');
}

int toNumber(const char *str) {
    int length = my_strlen(str);

    int result = 0;
    for (int i = 0; i < length; ++i) {
        result *= 10;
        result += toDigit(str[i]);
    }
    return result;
}

bool isByteLetter(char a) {
    return (a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F');
}

bool isRealByte(const char *byte) {
    int length = my_strlen(byte);

    if (length != BYTE_LENGTH)
        return false;

    for (int i = 0; i < BYTE_LENGTH; ++i) {
        if (!isDigit(byte[i]) && !isByteLetter(byte[i]))
            return false;
    }
    return true;
}

int hexSymbolToDigit(char symbol) {
    if (isDigit(symbol))
        return toDigit(symbol);

    if (isLower(symbol))
        return (int) (symbol - 'a') + 10;

    return (int) (symbol - 'A') + 10;

}

int hexToDec(const char *byte) {
    if (!isRealByte(byte))
        return -1;

    int result = 0;

    for (int i = 0; i < BYTE_LENGTH; ++i) {
        result += hexSymbolToDigit(byte[i]) * my_pow(16, BYTE_LENGTH - 1 - i);
    }

    return result;
}

char digitToHexSymbol(unsigned n) {
    if (n > 15)
        return TERMINATE_SYMBOL;

    if (n <= 9)
        return (char) (n + '0');

    return (char) (n - 10 + 'a');
}

char *decToHex(unsigned num) {
    char *result = new char[3]; //the length of a byte is not more than 2 characters + '\0';

    int secondNumber = num % 16;
    num /= 16;
    int firstNumber = num % 16;

    result[0] = digitToHexSymbol(firstNumber);
    result[1] = digitToHexSymbol(secondNumber);
    result[2] = TERMINATE_SYMBOL;

    return result;
}

bool areStrEqual(const char *str1, const char *str2) {
    unsigned length1 = my_strlen(str1);
    unsigned length2 = my_strlen(str2);

    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; ++i) {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

void getNextWord(const char *str, char *word, size_t &index) {
    size_t wordIndex = 0;
    while (str[index] != ' ' && str[index] != TERMINATE_SYMBOL) {
        word[wordIndex] = str[index];
        wordIndex++;
        index++;
    }
    word[wordIndex] = TERMINATE_SYMBOL;
    index++;
}

void getNextWord(char *dest, const char *source) { //better than this above, but not implemented
    while (*source != ' ' && *source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }

    source++;
    *dest = '\0';
}

#endif
