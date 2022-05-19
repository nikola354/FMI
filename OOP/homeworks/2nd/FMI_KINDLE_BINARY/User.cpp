#include "User.h"

User::User() {
    readBooksCount = 0;
    readBooksCapacity = 1;
    readBooksIds = new unsigned[readBooksCapacity];
}

User::User(const User &other) {
    copyFrom(other);
}

User &User::operator=(const User &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

User::~User() {
    free();
}

User::User(const char *name, const char *pass) {
    this->name = name;

    password = pass;

    readBooksCount = 0;

    readBooksCapacity = 1;

    readBooksIds = new unsigned[readBooksCapacity];
}

void User::free() {
    delete[] readBooksIds;
}

void User::copyFrom(const User &other) {
    name = other.name;

    password = other.password;

    readBooksCount = other.readBooksCount;

    readBooksIds = new unsigned[readBooksCount];
    for (int i = 0; i < readBooksCount; ++i) {
        readBooksIds[i] = other.readBooksIds[i];
    }
}

void User::writeToFile(std::ofstream &writeFile) const {
    name.writeToFile(writeFile);
    password.writeToFile(writeFile);

    writeFile.write((const char *) &readBooksCount, sizeof(readBooksCount));
    for (int i = 0; i < readBooksCount; ++i) {
        writeFile.write((const char *) &readBooksIds[i], sizeof(unsigned));
    }
}

String User::getName() const {
    return name;
}

String User::getPassword() const {
    return password;
}

void User::readBook(const Book &book) {
    if (readBooksCount >= readBooksCapacity) { //resize:
        readBooksCapacity *= 2;
        unsigned *temp = new unsigned[readBooksCapacity];

        for (int i = 0; i < readBooksCount; ++i) {
            temp[i] = readBooksIds[i];
        }

        delete[] readBooksIds;

        readBooksIds = temp;
    }

    readBooksIds[readBooksCount++] = book.getId();
}

bool User::hasReadBook(const Book &book) const {
    for (int i = 0; i < readBooksCount; ++i) {
        if (readBooksIds[i] == book.getId())
            return true;
    }
    return false;
}

void User::readFromFile(std::ifstream &readFile) {
    free();

    name.readFromFile(readFile);
    password.readFromFile(readFile);

    readFile.read((char *) &readBooksCount, sizeof(readBooksCount));
    readBooksCapacity = closestPowerOfTwo(readBooksCount);

    readBooksIds = new unsigned[readBooksCapacity];
    for (int i = 0; i < readBooksCount; ++i) {
        readFile.read((char *) &readBooksIds[i], sizeof(unsigned));
    }
}
