#ifndef FACULTY_COURSE_GRADE_H
#define FACULTY_COURSE_GRADE_H

#include <cstring>

class Grade {
private:
    double value;
    char *assignment;
    char *teacherName;

public:
    Grade();

    Grade(const Grade &other);

    Grade(double value, const char *assignment, const char *teacherName);

    Grade &operator=(const Grade &other);

    ~Grade();


private:
    void free();

    void copyFrom(const Grade &other);

public:
    const char *getAssignment() const;

    const char *getTeacherName() const;

    double getValue() const;

    void setValue(double value);
};


#endif //FACULTY_COURSE_GRADE_H
