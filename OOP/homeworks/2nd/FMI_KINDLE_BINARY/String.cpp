//
// Created by nikola354 on 04.05.22.
//

#include "String.h"

void String::copy(const String &other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}

void String::free() {
    delete[] str;
}

String::String() {
    size = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *data) {
    size = strlen(data);
    str = new char[size + 1];
    strcpy(str, data);
}

String::String(const String &other) {
    copy(other);
}

String &String::operator=(const String &other) {
    if (this != &other) {
        free();
        copy(other);
    }
    return *this;
}

String::~String() {
    free();
}

size_t String::getSize() const {
    return size;
}

const char *String::c_str() const {
    return str;
}

void String::setName(const char *data) {
    delete[] str;
    size = strlen(data);
    str = new char[size + 1];
    strcpy(str, data);
}

void String::concat(const String &other) {
    size = size + other.size;
    char *temp = new char[size + 1];
    strcpy(temp, str);
    strcat(temp, other.str);

    delete[] str;
    str = temp;
}

String &String::operator+=(const String &other) {
    concat(other.str);
    return *this;
}

std::ostream &operator<<(std::ostream &out, const String &obj) {
    out << obj.str;
    return out;
}

std::istream &operator>>(std::istream &in, String &obj) {
    char buffer[1024];
    in >> buffer;

    obj.free();
    obj.size = strlen(buffer);
    obj.str = new char[obj.size + 1];
    strcpy(obj.str, buffer);

    return in;
}

bool String::operator==(const String &other) const {
    return strcmp(this->c_str(), other.c_str()) == 0;
}

bool String::operator!=(const String &other) const {
    return !(*this == other);
}

void String::writeToFile(std::ofstream &writeFile) const {
    writeFile.write((const char *) &size, sizeof(size));
    writeFile.write(str, size);
}

void String::readFromFile(std::ifstream &readFile) {
    free();

    readFile.read((char *) &size, sizeof(size));

    str = new char[size + 1];
    readFile.read(str, size);
    str[size] = '\0';
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

String *String::popNextWord() {
    trim();

    char nextWord[CONSOLE_BUFFER_SIZE];

    int index = 0;
    while (str[index] != ' ' && str[index] != TERMINATE_SYMBOL) {
        nextWord[index] = str[index];
        index++;
    }
    nextWord[index] = TERMINATE_SYMBOL;
    index++;

    int newSize = size - index;
    char *newStr = new char[newSize + 1];

    for (int i = 0; i < newSize; ++i) {
        newStr[i] = str[i + index];
    }
    newStr[newSize] = TERMINATE_SYMBOL;

    *this = String(newStr);

    delete[] newStr;

    String *result = new String(nextWord);
    return result;
}

String operator+(const String &lhs, const String &rhs) {
    String temp(lhs);
    temp += rhs;
    return temp;
}