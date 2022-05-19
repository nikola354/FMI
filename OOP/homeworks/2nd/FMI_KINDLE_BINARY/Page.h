//
// Created by nikola354 on 02.05.22.
//

#ifndef FMI_KINDLE_PAGE_H
#define FMI_KINDLE_PAGE_H

#include <cstring>
#include <fstream>
#include <iostream>

#include "constants.h"
#include "helpers.h"
#include "String.h"

class Page {
private:
    int linesCount;
    int linesCapacity;
    String *lines;

public:
    Page();

    Page(const Page &other);

    Page &operator=(const Page &other);

    ~Page();

private:
    void free();

    void copyFrom(const Page &other);

public:
    void addLine(const String &line);

    void writeToFile(std::ofstream &writeFile) const;

    void readFromFile(std::ifstream &readFile);

    void print() const;
};


#endif //FMI_KINDLE_PAGE_H
