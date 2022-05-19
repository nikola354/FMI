#ifndef FMI_KINDLE_USER_H
#define FMI_KINDLE_USER_H

#include <cstring>
#include <fstream>

#include "String.h"
#include "helpers.h"
#include "constants.h"
#include "Book.h"

class User {
private:
    String name; //unique
    String password;
    int readBooksCount;
    int readBooksCapacity;
    unsigned *readBooksIds;

public:
    User();

    User(const User &other);

    User &operator=(const User &other);

    ~User();

    User(const char *name, const char *pass);

private:
    void free();

    void copyFrom(const User &other);

public:
    void writeToFile(std::ofstream &writeFile) const;

    void readFromFile(std::ifstream &readFile);

    String getName() const;

    String getPassword() const;

    void readBook(const Book &book);

    bool hasReadBook(const Book &book) const;
};


#endif //FMI_KINDLE_USER_H
