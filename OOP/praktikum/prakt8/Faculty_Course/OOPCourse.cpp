#include "OOPCourse.h"

bool isValidStr2(const char *str) {
    return str != nullptr && strlen(str) > 0;
}

OOPCourse::OOPCourse() {
    studentsCount = 0;
    studentsMaxSize = studentsCount;
    students = nullptr;
    assistantsCount = 0;
}

OOPCourse::OOPCourse(const OOPCourse &other) {
    copyFrom(other);
}

OOPCourse::OOPCourse(const char *lecturer, const char *assist1, const char *assist2,
                     const char *assist3) { // assistants are default parameters
    studentsCount = 0;

    studentsMaxSize = studentsCount;

    students = nullptr;

    assistantsCount = 0;

    this->lecturer = Lecturer(lecturer);

    if (*assist1 != '\0') {
        assistants[0] = Assistant(assist1);
        assistantsCount++;

        if (*assist2 != '\0') {
            assistants[1] = Assistant(assist2);
            assistantsCount++;

            if (*assist3 != '\0') {
                assistants[2] = Assistant(assist3);
                assistantsCount++;
            }
        }
    }
}

OOPCourse &OOPCourse::operator=(const OOPCourse &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

OOPCourse::~OOPCourse() {
    free();
}

void OOPCourse::free() {
    delete[] students;
}

void OOPCourse::copyFrom(const OOPCourse &other) {
    studentsCount = other.studentsCount;
    studentsMaxSize = other.studentsMaxSize;
    students = new Student[studentsMaxSize];

    for (int i = 0; i < studentsCount; ++i) {
        students[i] = other.students[i];
    }

    lecturer = other.lecturer;

    assistantsCount = other.assistantsCount;

    for (int i = 0; i < assistantsCount; ++i) {
        assistants[i] = other.assistants[i];
    }
}

Student *OOPCourse::findStudent(int fn) { //returns a pointer to the actual student from students array
    Student *student = nullptr;
    for (int i = 0; i < studentsCount; ++i) { //find the student
        if (students[i].getFn() == fn) {
            student = &students[i];
            break;
        }
    }

    return student;
}

void OOPCourse::addStudent(const char *name, int fn) { //todo: test that
    //check for unique fn:
//    if (findStudent(fn) != nullptr) {
//        throw "A student with this fn already exists!";
//    }
//
//    //copy current data:
//    Student *temp = new Student[studentsCount];
//    for (int i = 0; i < studentsCount; ++i) {
//        temp[i] = students[i];
//    }
//
//    studentsCount++;
//    students = new Student[studentsCount]; //extend the array by 1
//    for (int i = 0; i < studentsCount - 1; ++i) {
//        students[i] = temp[i];
//    }
//
//    students[studentsCount - 1] = Student(name, fn);
//    delete[] temp;


    //check for unique fn:
    if (findStudent(fn) != nullptr) {
        throw "A student with this fn already exists!";
    }

    if (studentsCount < studentsMaxSize) {
        students[studentsCount] = Student(name, fn);
    } else { // resize array
        if (studentsMaxSize == 0){ //if the student is the first added
            studentsMaxSize = 2;
            students = new Student[studentsMaxSize];
            students[0] = Student(name, fn);
        } else {
            Student *temp = new Student[studentsCount];
            for (int i = 0; i < studentsCount; ++i) { //copy the array
                temp[i] = students[i];
            }

            studentsMaxSize *= 2;
            students = new Student[studentsMaxSize];

            for (int i = 0; i < studentsCount; ++i) {
                students[i] = temp[i];
            }
            students[studentsCount] = Student(name, fn);

            delete[]temp;
        }
    }
    studentsCount++;
}

void OOPCourse::addGrade(int fn, const char *assignment, double value, const char *teacherName) {
    Student *studentToChange = findStudent(fn);

    if (studentToChange == nullptr) {
        throw "Could not find student with this fn!";
    }

    studentToChange->addGrade(value, assignment, teacherName);
}

double OOPCourse::getAverageFromTeacher(const char *teacherName) const {
    if (!isValidStr2(teacherName)) {
        throw "Invalid teacher name!";
    }

    double sum = 0;
    int count = 0;

    for (int i = 0; i < studentsCount; ++i) {
        int gradesCount = students[i].getGradesCount();
        const Grade *grades = students[i].getGrades();

        for (int j = 0; j < gradesCount; ++j) {
            if (strcmp(grades[j].getTeacherName(), teacherName) == 0) {
                sum += grades[j].getValue();
                count++;
            }
        }

        delete[] grades;
    }

    if (count == 0) {
        throw "There are no grades from this teacher!";
    }

    return sum / count;
}

double OOPCourse::getAverageGradePerTask(const char *assigment) const {
    if (!isValidStr2(assigment)) {
        throw "Invalid assignment!";
    }

    double sum = 0;
    int count = 0;

    for (int i = 0; i < studentsCount; ++i) {
        int gradesCount = students[i].getGradesCount();
        const Grade *grades = students[i].getGrades();

        for (int j = 0; j < gradesCount; ++j) {
            if (strcmp(grades[j].getAssignment(), assigment) == 0) {
                sum += grades[j].getValue();
                count++;
            }
        }

        delete[] grades;
    }

    if (count == 0) {
        throw "There are no grades for this task!";
    }

    return sum / count;
}

double OOPCourse::getAverageForCourse() const {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < studentsCount; ++i) {
        sum += students[i].getSumOfGrades();
        count += students[i].getGradesCount();
    }

    if (count == 0)
        throw "There are no grades in this course yet!";

    return sum / count;
}

void OOPCourse::removeStudent(int fn) {
    int removedIndex = -1;
    for (int i = 0; i < studentsCount; ++i) {
        if (students[i].getFn() == fn) {
            removedIndex = i;
            break;
        }
    }

    if (removedIndex == -1) {
        throw "Could not find student with this fn!";
    }

    students[removedIndex] = students[studentsCount - 1];
    students[studentsCount - 1] = Student(); //set default student for the empty place
    studentsCount--;
}

void OOPCourse::changeGrade(int fn, double newValue, const char *assignment) {
    Student *student = findStudent(fn);

    if (student == nullptr) {
        throw "Could not find student with this fn!";
    }

    student->changeGrade(newValue, assignment);
}
