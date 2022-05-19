#ifndef FACULTY_COURSE_OOPCOURSE_H
#define FACULTY_COURSE_OOPCOURSE_H

#pragma warning(disable: 4996)

#include "Lecturer.h"
#include "Student.h"
#include "Assistant.h"

const int ASSISTANTS_COUNT = 3;

class OOPCourse {
private:
    int studentsCount;
    int studentsMaxSize;
    Student *students;
    Lecturer lecturer;
    int assistantsCount;
    Assistant assistants[ASSISTANTS_COUNT];
public:
    OOPCourse();

    OOPCourse(const OOPCourse &other);

    OOPCourse(const char *lecturer, const char *assist1 = "\0", const char *assist2 = "\0",
              const char *assist3 = "\0");

    OOPCourse &operator=(const OOPCourse &other);

    ~OOPCourse();

private:
    void free();

    void copyFrom(const OOPCourse &other);

    Student *findStudent(int fn);

public:
    void addStudent(const char *name, int fn);

    void addGrade(int fn, const char *assignment, double value, const char *teacherName);

    double getAverageFromTeacher(const char *teacherName) const;

    double getAverageGradePerTask(const char *assigment) const;

    double getAverageForCourse() const;

    void removeStudent(int fn);

    void changeGrade(int fn, double newValue, const char *assignment);

};
#endif
