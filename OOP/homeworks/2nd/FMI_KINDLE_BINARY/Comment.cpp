//
// Created by nikola354 on 30.04.22.
//

#include "Comment.h"

Comment::Comment(const Comment &other) {
    copyFrom(other);
}

Comment &Comment::operator=(const Comment &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Comment::~Comment() {
    free();
}

Comment::Comment(const String &text, const String &author) {
    this->text = text;

    this->author = author;
}

void Comment::free() {}

void Comment::copyFrom(const Comment &other) {
    text = other.text;

    author = other.author;
}

String Comment::getText() const {
    return text;
}

String Comment::getAuthor() const {
    return author;
}

void Comment::print(bool isBookAuthor) const {
    std::cout << author << (isBookAuthor ? "(author)" : "") << ": " << text << std::endl;
}

void Comment::writeToFile(std::ofstream &writeFile) const {
    text.writeToFile(writeFile);
    author.writeToFile(writeFile);
}

void Comment::readFromFile(std::ifstream &readFile) {
    free();

    text.readFromFile(readFile);
    author.readFromFile(readFile);
}
