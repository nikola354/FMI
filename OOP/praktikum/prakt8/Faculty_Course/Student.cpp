#include "Student.h"

bool isValidStr(const char *str) {
    return str != nullptr && strlen(str) > 0;
}

Student::Student() {
    gradesCount = 0;
    name = new char[1];
    name[0] = '\0';
    fn = 0;
}

Student::Student(const Student &other) {
    copyFrom(other);
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Student::~Student() {
    free();
}

void Student::copyFrom(const Student &other) {
    gradesCount = other.gradesCount;

    int length = strlen(other.name);

    name = new char[length + 1];
    strcpy(name, other.name);

    for (int i = 0; i < gradesCount; ++i) {
        grades[i] = other.grades[i];
    }

    fn = other.fn;
}

void Student::free() {
    delete[] name;
}

Grade *Student::findGrade(const char *assignment) {
    Grade *grade = nullptr;

    for (int i = 0; i < gradesCount; ++i) {
        if (strcmp(grades[i].getAssignment(), assignment) == 0) {
            grade = &grades[i];
            break;
        }
    }

    return grade;
}

Student::Student(const char *name, int fn) {
    gradesCount = 0;

    int length = strlen(name);
    this->name = new char[length + 1];
    strcpy(this->name, name);

    this->fn = fn;

}

unsigned Student::getFn() const {
    return fn;
}

void Student::addGrade(double value, const char *assignment, const char *teacherName) {
    if (gradesCount >= GRADES_COUNT)
        throw "The max number of grades has been reached!";

    if (value < 2 || value > 6)
        throw "The grade must be between 2 and 6!";

    if (!isValidStr(assignment) || !isValidStr(teacherName)) {
        throw "Invalid assignment or teacher name!";
    }

    if (findGrade(assignment) != nullptr) { //check for duplicated assignments
        throw "The student has already a grade for this assignment!";
    }

    grades[gradesCount] = Grade(value, assignment, teacherName);
    gradesCount++;
}

void Student::changeGrade(double newValue, const char *assignment) {
    if (newValue < 2 || newValue > 6)
        throw "The grade must be between 2 and 6!";

    if (!isValidStr(assignment)) {
        throw "Invalid assignment!";
    }

    Grade *toChange = findGrade(assignment);
    if (toChange == nullptr) {
        throw "No grade for this student and task was found!";
    }

    toChange->setValue(newValue);
}

int Student::getGradesCount() const {
    return gradesCount;
}

const Grade *Student::getGrades() const {
    return grades;
}

double Student::getSumOfGrades() const {
    double sum = 0;

    for (int i = 0; i < gradesCount; ++i) {
        sum += grades[i].getValue();
    }

    return sum;
}