#ifndef FACULTY_COURSE_LECTURER_H
#define FACULTY_COURSE_LECTURER_H

#include <cstring>

class Lecturer {
private:
    char *name;

public:
    Lecturer();

    Lecturer(const Lecturer &other);

    Lecturer(const char *name);

    Lecturer &operator=(const Lecturer &other);

    ~Lecturer();

private:

    void free();

    void copyFrom(const Lecturer &other);
};

#endif //FACULTY_COURSE_LECTURER_H
