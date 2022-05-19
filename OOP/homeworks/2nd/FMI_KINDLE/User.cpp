#include "User.h"

User::User() {
    booksCount = 0;
    booksCapacity = 1;
    readBooksIds = new unsigned[booksCapacity];
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

User::User(std::ifstream &usersFile) {
    char buffer[FILE_BUFFER_SIZE];

    //name:
    usersFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    name = buffer;

    //password:
    usersFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    password = buffer;

    //books count:
    usersFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
    booksCount = toNumber(buffer);
    booksCapacity = booksCount;

    //readBooksIds:
    readBooksIds = new unsigned[booksCapacity];
    for (int i = 0; i < booksCount; ++i) {
        usersFile.getline(buffer, FILE_BUFFER_SIZE, DELIMITER);
        readBooksIds[i] = toNumber(buffer);
    }
}

User::User(const char *name, const char *pass) {
    this->name = name;

    password = pass;

    booksCount = 0;

    booksCapacity = 1;

    readBooksIds = new unsigned[booksCapacity];
}

void User::free() {
    delete[] readBooksIds;
}

void User::copyFrom(const User &other) {
    name = other.name;

    password = other.password;

    booksCount = other.booksCount;

    readBooksIds = new unsigned[booksCount];
    for (int i = 0; i < booksCount; ++i) {
        readBooksIds[i] = other.readBooksIds[i];
    }
}

void User::writeToFile(std::ofstream &writeFile) const {
    writeFile << name << DELIMITER;
    writeFile << password << DELIMITER;
    writeFile << booksCount << DELIMITER;

    for (int i = 0; i < booksCount; ++i) {
        writeFile << readBooksIds[i] << DELIMITER;
    }
}

String User::getName() const {
    return name;
}

String User::getPassword() const {
    return password;
}

void User::readBook(const Book &book) {
    if (booksCount >= booksCapacity) { //resize:
        booksCapacity *= 2;
        unsigned *temp = new unsigned[booksCapacity];

        for (int i = 0; i < booksCount; ++i) {
            temp[i] = readBooksIds[i];
        }

        delete[] readBooksIds;

        readBooksIds = temp;
    }

    readBooksIds[booksCount++] = book.getId();
}

bool User::hasReadBook(const Book &book) const {
    for (int i = 0; i < booksCount; ++i) {
        if (readBooksIds[i] == book.getId())
            return true;
    }
    return false;
}
