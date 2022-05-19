#ifndef INC_2_STUDENTSCONTROLLER_H
#define INC_2_STUDENTSCONTROLLER_H

enum Gender {
    female,
    male
};

struct Student {
    char name[MAX_NAME_LENGTH]; //between 1 and MAX_NAME_LENGTH chars
    int fn; //unique
    int age; //from 15 to 65
    Gender gender;
    char email[MAX_EMAIL_LENGTH]; //between 1 and MAX_EMAIL_LENGTH chars | contains '@'
    double grade; //between 2.00 and 6.00

    void print() const {
        cout << name << endl;
        cout << "FN: " << fn << endl;
        cout << "Age: " << age << endl;

        cout << "Gender: ";
        if (gender == male) {
            cout << "Male" << endl;
        } else {
            cout << "Female" << endl;
        }

        cout << "Email: " << email << endl;
        cout << "Grade: " << grade << endl;
        cout << endl;
    }

    void writeToFile(ofstream &writeFile) const {
        writeFile << OPENING_SYMBOL << STUDENT_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << NAME_TAG << CLOSING_SYMBOL;
        writeFile << name;
        writeFile << OPENING_SYMBOL << BACKSLASH << NAME_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << FN_TAG << CLOSING_SYMBOL;
        writeFile << fn;
        writeFile << OPENING_SYMBOL << BACKSLASH << FN_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << AGE_TAG << CLOSING_SYMBOL;
        writeFile << age;
        writeFile << OPENING_SYMBOL << BACKSLASH << AGE_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << GENDER_TAG << CLOSING_SYMBOL;
        if (gender == female) {
            writeFile << "Female";
        } else {
            writeFile << "Male";
        }
        writeFile << OPENING_SYMBOL << BACKSLASH << GENDER_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << EMAIL_TAG << CLOSING_SYMBOL;
        writeFile << email;
        writeFile << OPENING_SYMBOL << BACKSLASH << EMAIL_TAG << CLOSING_SYMBOL << endl;

        writeFile << TAB << OPENING_SYMBOL << GRADE_TAG << CLOSING_SYMBOL;
        writeFile << grade;
        writeFile << OPENING_SYMBOL << BACKSLASH << GRADE_TAG << CLOSING_SYMBOL << endl;

        writeFile << OPENING_SYMBOL << BACKSLASH << STUDENT_TAG << CLOSING_SYMBOL << endl;
    }
};

//validation:
bool isValidName(const char *name, int length) {
    if (length > MAX_NAME_LENGTH || length < 1)
        return false;

    return true;
}

bool isValidAge(int age) {
    return age >= MIN_AGE && age <= MAX_AGE;
}

bool isValidEmail(const char *email, int length) {
    if (length < 1 || length > MAX_EMAIL_LENGTH)
        return false;

    for (int i = 1; i < length - 1; ++i) {
        if (email[i] == '@')
            return true;
    }

    return false;
}

bool isValidGrade(double grade) {
    return grade >= MIN_GRADE && grade <= MAX_GRADE;
}

bool fnExists(const Student *students, int studentsCount, int fn) {
    for (int i = 0; i < studentsCount; ++i) {
        if (students[i].fn == fn) {
            return true;
        }
    }
    return false;
}

Student &getStudent(Student *students, int studentsCount, int fn) {
    for (int i = 0; i < studentsCount; ++i) {
        if (students[i].fn == fn)
            return students[i];
    }
}

void copyStudent(Student &student, const Student &source) {
    student.fn = source.fn;
    student.grade = source.grade;
    student.age = source.age;
    student.gender = source.gender;

    my_strcopy(student.email, source.email, my_strlen(source.email));
    my_strcopy(student.name, source.name, my_strlen(source.name));
}

void swap(Student &s1, Student &s2) {
    Student temp;
    copyStudent(temp, s1);

    copyStudent(s1, s2);
    copyStudent(s2, temp);
}

//SORT:

void sortByName(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (my_strcmp(students[i + 1].name, students[i].name) == -1) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void sortByFn(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (students[i + 1].fn < students[i].fn) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void sortByAge(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (students[i + 1].age < students[i].age) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void sortByGender(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (students[i + 1].gender < students[i].gender) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void sortByEmail(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (my_strcmp(students[i + 1].email, students[i].email) == -1) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void sortByGrade(Student *students, int studentsCount) {
    bool sorted;

    int index = 0;
    do {
        sorted = true;
        for (int i = 0; i < studentsCount - 1 - index; ++i) {
            if (students[i + 1].grade < students[i].grade) {
                swap(students[i], students[i + 1]);
                sorted = false;
            }
        }
        index++;
    } while (!sorted);
}

void print(const Student *students, int studentsCount) {
    for (int i = 0; i < studentsCount; ++i) {
        students[i].print();
    }
}

#endif
