#include "Grade.h"

Grade::Grade() {
    value = 0;

    assignment = new char[1];
    assignment[0] = '\0';

    teacherName = new char[1];
    teacherName[0] = '\0';
}

Grade::Grade(const Grade &other) {
    copyFrom(other);
}

Grade::Grade(double value, const char *assignment, const char *teacherName) {
    this->value = value;

    int assignmentLength = strlen(assignment);
    this->assignment = new char[assignmentLength + 1];
    strcpy(this->assignment, assignment);

    int teacherNameLength = strlen(teacherName);
    this->teacherName = new char[teacherNameLength + 1];
    strcpy(this->teacherName, teacherName);
}

Grade &Grade::operator=(const Grade &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Grade::~Grade() {
    free();
}

void Grade::free() {
    delete[] assignment;
    delete[] teacherName;
}

void Grade::copyFrom(const Grade &other) {
    value = other.value;

    int length = strlen(other.assignment);

    assignment = new char[length + 1];
    strcpy(assignment, other.assignment);

    int nameLength = strlen(other.teacherName);

    teacherName = new char[nameLength + 1];
    strcpy(teacherName, other.teacherName);
}

const char *Grade::getAssignment() const {
    return assignment;
}

const char *Grade::getTeacherName() const {
    int length = strlen(teacherName);

    char *result = new char[length + 1];
    strcpy(result, teacherName);

    return result;
}

double Grade::getValue() const {
    return value;
}

void Grade::setValue(double value) {
    this->value = value;
}