//
// Created by nikola354 on 20.04.22.
//

#include "Assistant.h"

Assistant::Assistant() {
    name = new char[1];
    name[0] = '\0';
}

Assistant::Assistant(const Assistant &other) {
    copyFrom(other);
}

Assistant::Assistant(const char *name) {
    int length = strlen(name);

    this->name = new char[length + 1];
    strcpy(this->name, name);
}

Assistant& Assistant::operator=(const Assistant &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Assistant::~Assistant(){
    free();
}

void Assistant::copyFrom(const Assistant &other) {
    int length = strlen(other.name);

    name = new char[length + 1];
    strcpy(name, other.name);
}

void Assistant::free() {
    delete[] name;
}