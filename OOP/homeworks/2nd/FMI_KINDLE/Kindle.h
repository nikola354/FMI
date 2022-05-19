//
// Created by nikola354 on 01.05.22.
//

#ifndef FMI_KINDLE_KINDLE_H
#define FMI_KINDLE_KINDLE_H

#include <iostream>
#include <cstring>
#include <fstream>

#include "helpers.h"
#include "constants.h"
#include "Book.h"
#include "User.h"

class Kindle {
private:
    int booksCount;
    int booksCapacity;
    Book *books;
    int usersCount;
    int usersCapacity;
    User *users;

public:
    Kindle();

    Kindle(const Kindle &other);

    Kindle &operator=(const Kindle &other);

    ~Kindle();

private:
    void free();

    void copyFrom(const Kindle &other);

    User *findUser(const char *name);

    Book *findBook(const char *title);

    Book *findBook(unsigned id);

public:
    void addUser(const char *name, const char *password);

    void save() const;

    void saveUsers() const;

    void saveBooks() const;

    const User *getUser(const char *name) const;

    const Book *getBook(const char *title) const;

    int getBooksCount() const;

    User *copyUser(const char *name) const;

    void printBooks() const;

    void addBook(const Book &book);

    void updateUser(const User &user);

    void insertPageToBook(unsigned bookId, const Page &page);

    void addPageToBook(unsigned bookId, const Page &page);

    bool changeTitle(unsigned bookId, const String &title);

    bool editPageOfBook(unsigned bookId, int pageNumber, const Page &page);

    bool rateBook(unsigned bookId, int rateValue, const String &authorName);

    bool commentBook(unsigned bookId, const String &text, const String &authorName);
};

#endif //FMI_KINDLE_KINDLE_H
