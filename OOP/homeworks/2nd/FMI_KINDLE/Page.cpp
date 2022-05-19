//
// Created by nikola354 on 02.05.22.
//

#include "Page.h"

Page::Page() {
    linesCount = 0;
    linesCapacity = 1;
    lines = new String[linesCapacity];
}

Page::Page(const Page &other) {
    copyFrom(other);
}

Page &Page::operator=(const Page &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Page::~Page() {
    free();
}

void Page::free() {
    delete[] lines;
}

void Page::copyFrom(const Page &other) {
    linesCount = other.linesCount;
    linesCapacity = other.linesCapacity;
    lines = new String[linesCapacity];

    for (int i = 0; i < linesCount; ++i) {
        lines[i] = other.lines[i];
    }
}

void Page::addLine(const String &line) {
    if (linesCount >= linesCapacity) { //resize:
        linesCapacity *= 2;

        String *temp = new String[linesCapacity];
        for (int i = 0; i < linesCount; ++i) {
            temp[i] = lines[i];
        }

        delete[] lines;
        lines = temp;
    }

    lines[linesCount++] = line;
}

void Page::writeToFile(std::ofstream &writeFile) const {
    writeFile << linesCount << std::endl;

    for (int i = 0; i < linesCount; ++i) {
        writeFile << lines[i].c_str() << std::endl;
    }
}

void Page::print() const {
    for (int i = 0; i < linesCount; ++i) {
        std::cout << lines[i] << std::endl;
    }

    std::cout << std::endl;
}

Page::Page(std::ifstream &readFile) {
    readFile >> linesCount;
    linesCapacity = linesCount * 2;

    lines = new String[linesCapacity];
    for (int i = 0; i < linesCount; ++i) {
        readFile >> lines[i];
    }
}
