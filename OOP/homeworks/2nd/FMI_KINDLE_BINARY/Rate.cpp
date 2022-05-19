//
// Created by nikola354 on 01.05.22.
//

#include "Rate.h"

Rate::Rate() {
    value = -1;
    author = new char[1];
}

Rate::Rate(const Rate &other) {
    copyFrom(other);
}

Rate &Rate::operator=(const Rate &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Rate::Rate(int value, const String &author) {
    this->value = value;

    this->author = author;
}

void Rate::free() {
}

void Rate::copyFrom(const Rate &other) {
    value = other.value;

    author = other.author;
}

int Rate::getValue() const {
    return value;
}

const String &Rate::getAuthor() const {
    return author;
}

std::ostream &operator<<(std::ostream &out, const Rate &rate) {
    out << rate.author << " rated " << rate.value << " stars!";
    return out;
}

void Rate::writeToFile(std::ofstream &writeFile) const {
    writeFile.write((const char *) &value, sizeof(value));
    author.writeToFile(writeFile);
}

void Rate::readFromFile(std::ifstream &readFile) {
    free();

    readFile.read((char *) &value, sizeof(value));
    author.readFromFile(readFile);
}
