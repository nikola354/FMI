//
// Created by nikola354 on 01.05.22.
//

#ifndef FMI_KINDLE_BOOK_H
#define FMI_KINDLE_BOOK_H

#include <iostream>
#include <cstring>
#include <fstream>

#include "String.h"
#include "constants.h"
#include "helpers.h"
#include "Comment.h"
#include "Rate.h"
#include "Page.h"

const int MAX_COMMENTS_COUNT = 64;
const int MAX_RATES_COUNT = 64;
const char BOOK_FILE_FORMAT[] = ".txt";

class Book {
private:
    unsigned id;
    String title;
    String author;
    int pagesCount;
    int pagesCapacity;
    Page *pages;
    int commentsCount;
    Comment comments[MAX_COMMENTS_COUNT];
    int ratesCount;
    Rate rates[MAX_RATES_COUNT];

public:
    Book();

    Book(const Book &other);

    Book &operator=(const Book &other);

    ~Book();

    Book(std::ifstream &booksFile);

    Book(int id, const char *title, const char *author, int pagesCount);

private:
    void free();

    void copyFrom(const Book &other);

    Rate *findRate(const String &authorName);

public:
    void writeToFile(std::ofstream &writeFile) const;

    String getTitle() const;

    String getAuthor() const;

    void addPage(const Page &p);

    void writePages() const;

    const Page &getPage(int index) const;

    int getPagesCount() const;

    unsigned getId() const;

    String generateFileName() const;

    void setTitle(const String &title);

    void setPage(int index, const Page &page);

    void addRate(int rateValue, const String &authorName);

    int getRatesCount() const;

    void printRates() const;

    void printComments() const;

    double calcRating() const;
    
    void addComment(const String &comment, const String &authorName);
};


#endif //FMI_KINDLE_BOOK_H
