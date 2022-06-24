#include "../headers/String.h"

void String::copyFrom(const String &other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
    size = other.size;
}

void String::free() {
    delete[] str;
}

String::String() {
    str = new char[1];
    str[0] = '\0';
    size = 0;
}

String::String(const char *data) {
    if (data == nullptr) {
        str = new char[1];
        str[0] = '\0';
        size = 0;
    } else {
        size = strlen(data);
        str = new char[size + 1];
        strcpy(str, data);
    }
}

String::String(const String &other) {
    copyFrom(other);
}

String &String::operator=(const String &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String::~String() {
    free();
}


size_t String::getSize() const {
    return size;
}

void String::concat(const String &other) {
    char *temp = new char[getSize() + other.getSize() + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    delete[] str;
    str = temp;
    size = size + other.getSize();
}

const char *String::c_str() const {
    return str;
}

String &String::operator+=(const String &other) {
    concat(other);
    return *this;
}

void String::getLine(std::istream &in) {
    delete[] str;
    char buff[1024];

    in.getline(buff, 1024, '\n');
    size_t len = strlen(buff);
    str = new char[len + 1];
    for (size_t i = 0; i < len; i++)
        str[i] = buff[i];
    str[len] = '\0';
    size = len;
}

String operator+(const String &lhs, const String &rhs) {
    String copyOfLeft(lhs);
    copyOfLeft += rhs;
    return copyOfLeft;
}

std::ostream &operator<<(std::ostream &stream, const String &str) {
    stream << str.str;
    return stream;
}

std::istream &operator>>(std::istream &stream, String &str) {
    delete[] str.str;
    char buff[1024];
    stream >> buff;

    str.size = strlen(buff);
    str.str = new char[str.size + 1];
    strcpy(str.str, buff);

    return stream;
}

bool operator==(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<=(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;

}

bool operator<(const String &lhs, const String &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}

String::String(String &&otherString) {
    str = otherString.str;
    size = otherString.size;
    otherString.str = nullptr;
}

String &String::operator=(String &&otherString) {
    if (this != &otherString) {
        free();
        str = otherString.str;
        otherString.str = nullptr;
        size = otherString.size;
    }
    return *this;
}

void String::trim() {
    int startIndex = 0;
    while (str[startIndex] == ' ') {
        startIndex++;
    }

    int endIndex = size - 1;
    while (str[endIndex] == ' ') {
        endIndex--;
    }

    int newLength = endIndex - startIndex + 1;
    if (newLength < size) {
        size = newLength;
        char *result = new char[size + 1];

        for (int i = 0; i < size; ++i) {
            result[i] = str[i + startIndex];
        }
        result[size] = '\0';

        delete[] str;
        str = result;
    }
}

double String::toDouble() const {
    double result = 0;

    //before decimal:

    bool minus = (*str == '-');
    int i = (int) minus;
    for (; i < size; ++i) {
        if (str[i] == DECIMAL_SIGN || str[i] == DECIMAL_SIGN2)
            break;

        result *= 10;
        result += (str[i] - '0');
    }

    //after decimal:
    double multiplier = 0.1;
    i++;
    for (; i < size; ++i) {
        result += (multiplier * (str[i] - '0'));
        multiplier *= 0.1;
    }

    return minus ? -result : result;
}

int String::toNumber() const {
    int length = strlen(str);
    int result = 0;

    bool minus = (*str == '-');

    for (int i = (int) minus; i < length; ++i) {
        result *= 10;
        result += (str[i] - '0');
    }

    return minus ? -result : result;
}

bool String::isDouble() const {
    if (this->isNumber())
        return true;

    int i = 0;
    if (*str == '-')
        i = 1;

    bool decimalPassed = false;
    for (; i < size; ++i) {
        if (i != 0 && i != size - 1 && !decimalPassed && str[i] == DECIMAL_SIGN) {
            //the char can be a decimal sign (first 3 conditions) and is a decimal sign (last condition)
            decimalPassed = true;
        } else if (!String::isDigit(str[i]))
            return false;
    }

    return true;
}

bool String::isNumber() const {
    int i = 0;
    if (*str == '-')
        i = 1;

    for (; i < size; ++i) {
        if (!String::isDigit(str[i]))
            return false;
    }

    return true;
}

bool String::isDigit(char a) {
    return a >= '0' && a <= '9';
}

bool String::isPositiveNumber() const {
    for (int i = 0; i < size; ++i) {
        if (!String::isDigit(str[i]))
            return false;
    }

    return true;
}

bool String::isPositiveDouble() const {
    if (this->isPositiveNumber())
        return true;

    bool decimalPassed = false;
    for (int i = 0; i < size; ++i) {
        if (i != 0 && i != size - 1 && !decimalPassed && str[i] == DECIMAL_SIGN) {
            //the char can be a decimal sign (first 3 conditions) and is a decimal sign (last condition)
            decimalPassed = true;
        } else if (!String::isDigit(str[i]))
            return false;
    }

    return true;
}

bool String::isEqualIgnoreCase(const String &other) const {
    return strcasecmp(this->c_str(), other.c_str()) == 0;
}


