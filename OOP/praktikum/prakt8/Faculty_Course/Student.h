#pragma once

#include "Grade.h"

const int GRADES_COUNT = 7;

class Student {
private:
    int gradesCount;
    char *name;
    Grade grades[GRADES_COUNT];
    unsigned fn;

public:
    Student();

    Student(const Student &other);

    Student(const char *name, int fn);

    Student &operator=(const Student &other);

    ~Student();

private:
    void copyFrom(const Student &other);

    void free();

    Grade *findGrade(const char *assignment);
public:
    unsigned getFn() const;

    void addGrade(double value, const char *assignment, const char *teacherName);

    void changeGrade(double newValue, const char *assignment);

    int getGradesCount() const;

    const Grade *getGrades() const;

    double getSumOfGrades() const;

};