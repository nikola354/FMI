#ifndef FACULTY_COURSE_ASSISTANT_H
#define FACULTY_COURSE_ASSISTANT_H

#include <cstring>

class Assistant {
private:
    char *name;

public:
    Assistant();

    Assistant(const Assistant &other);

    Assistant(const char *name);

    Assistant& operator=(const Assistant &other);

    ~Assistant();

private:
    void free();

    void copyFrom(const Assistant &other);
};


#endif //FACULTY_COURSE_ASSISTANT_H
