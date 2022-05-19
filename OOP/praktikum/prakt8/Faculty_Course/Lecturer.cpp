#include "Lecturer.h"

Lecturer::Lecturer() {
    name = new char[1];
    name[0] = '\0';
}

Lecturer::Lecturer(const Lecturer &other) {
    copyFrom(other);
}

Lecturer::Lecturer(const char *name) {
    int length = strlen(name);

    this->name = new char[length + 1];
    strcpy(this->name, name);
}

Lecturer &Lecturer::operator=(const Lecturer &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Lecturer::~Lecturer() {
    free();
}

void Lecturer::copyFrom(const Lecturer &other) {
    int length = strlen(other.name);

    name = new char[length + 1];
    strcpy(name, other.name);
}

void Lecturer::free() {
    delete[] name;
}
