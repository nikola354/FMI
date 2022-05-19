#ifndef INC_2_HELPERS_H
#define INC_2_HELPERS_H

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

void toUpper(char &a) {
    if (isLower(a)) {
        a -= DIFFERENCE_LOWER_UPPER;
    }
}

int toDigit(char a) {
    return (int) (a - '0');
}

bool isNumber(const char *str) {
    int length = my_strlen(str);

    for (int i = 0; i < length; ++i) {
        if (!isDigit(str[i]))
            return false;
    }

    return true;
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

bool isDouble(const char *str) {
    if (isNumber(str))
        return true;

    int length = my_strlen(str);
    bool decimalPassed = false;
    for (int i = 0; i < length; ++i) {
        if (i != 0 && i != length - 1 && !decimalPassed && str[i] == DECIMAL_SIGN) {
            //the char can be a decimal sign (first 3 conditions) and is a decimal sign (last condition)
            decimalPassed = true;
        } else if (!isDigit(str[i]))
            return false;
    }

    return true;
}

double toDouble(const char *str) {
    int length = my_strlen(str);

    double result = 0;

    //before decimal:
    int i = 0;
    for (; i < length; ++i) {
        if (str[i] == DECIMAL_SIGN)
            break;

        result *= 10;
        result += toDigit(str[i]);
    }

    //after decimal:
    double multiplier = 0.1;
    i++;
    for (; i < length; ++i) {
        result += (multiplier * toDigit(str[i]));
        multiplier *= 0.1;
    }

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

bool areStrEqualIgnoreCase(const char *str1, const char *str2) {
    int length1 = my_strlen(str1);
    int length2 = my_strlen(str2);

    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; ++i) {
        char a = str1[i];
        char b = str2[i];

        toUpper(a);
        toUpper(b);

        if (a != b)
            return false;
    }

    return true;
}

bool isAlpha(const char *str, int length) {
    for (int i = 0; i < length; ++i) {
        if (!isLower(str[i]) && !isUpper(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

void my_strcopy(char *dest, const char *source, int length) {
    int i = 0;
    for (; i < length; ++i) {
        dest[i] = source[i];
    }
    dest[i] = TERMINATE_SYMBOL;
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

int my_strcmp(const char *str1, const char *str2) {
    for (int i = 0;; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] < str2[i] ? -1 : 1;
        }

        if (str1[i] == '\0') {
            return 0;
        }
    }
}

#endif
