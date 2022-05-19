#include <iostream>
#include <fstream>

using namespace std;

#include "constants.h"
#include "helpers.h"
#include "StudentsController.h"
#include "FileController.h"

void menu(Student *students, int studentsCount, const char *filename);

char *loadFileMenu(char *);

int countStudents(const char *);

void readStudents(const char *buffer, Student *students, int &studentsCount);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char *buffer = loadFileMenu(filename);

    int studentsCount = countStudents(buffer);
    Student students[studentsCount];

    cout << "Students count: " << studentsCount << endl;

    readStudents(buffer, students, studentsCount);

    menu(students, studentsCount, filename);

    return 0;
}

void menu(Student *students, int studentsCount, const char *filename) {
    while (true) {
        cout << "Enter a command:" << endl;
        char command[BUFFER_SIZE_CONSOLE];
        cin.getline(command, BUFFER_SIZE_CONSOLE);

        if (areStrEqual(command, SAVE_CMD)) { // SAVE TO FILE AND END PROGRAM
            if (writeToFile(students, studentsCount, filename)) {
                cout << "File saved successfully!" << endl;
            } else {
                cout << "Error while saving file!" << endl;
            }
            return;
        } else if (areStrEqual(command, VIEW_CMD)) { //PRINT
            for (int i = 0; i < studentsCount; ++i) {
                students[i].print();
            }
        } else { //several words command or invalid
            size_t index = 0;

            char firstWord[CONSOLE_BUFFER_SIZE];
            getNextWord(command, firstWord, index);

            char secondWord[CONSOLE_BUFFER_SIZE];
            getNextWord(command, secondWord, index);

            if (areStrEqual(firstWord, EDIT_CMD)) { //EDIT <FN> <tag> <value>
                if (!isNumber(secondWord)) {
                    cout << "The faculty number must be a number!" << endl;
                    continue;
                }
                int fn = toNumber(secondWord);

                if (!fnExists(students, studentsCount, fn)) {
                    cout << "We could not find any student with this faculty number!" << endl;
                    continue;
                }

                Student &studentToEdit = getStudent(students, studentsCount, fn);

                //property to edit:
                char property[CONSOLE_BUFFER_SIZE];
                getNextWord(command, property, index);

                //value to set:
                char value[CONSOLE_BUFFER_SIZE];
                getNextWord(command, value, index);

                if (areStrEqual(property, NAME_TAG)) {
                    int length = my_strlen(value);

                    if (!isValidName(value, length)) {
                        cout << "The format of the name you entered is not valid!" << endl;
                        continue;
                    }

                    my_strcopy(studentToEdit.name, value, length);
                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else if (areStrEqual(property, AGE_TAG)) {
                    if (!isNumber(value)) {
                        cout << "The age must be an integer!" << endl;
                        continue;
                    }

                    int age = toNumber(value);

                    if (!isValidAge(age)) {
                        cout << "The age must be between " << MIN_GRADE << " and " << MAX_AGE << " years!" << endl;
                        continue;
                    }

                    studentToEdit.age = age;
                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else if (areStrEqual(property, GENDER_TAG)) {
                    if (areStrEqualIgnoreCase(value, MALE)) {
                        studentToEdit.gender = male;
                    } else if (areStrEqualIgnoreCase(value, FEMALE)) {
                        studentToEdit.gender = female;
                    } else {
                        cout << "We accept only 2 genders! Male or female." << endl;
                        continue;
                    }

                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else if (areStrEqual(property, EMAIL_TAG)) {
                    int length = my_strlen(value);
                    if (!isValidEmail(value, length)) {
                        cout << "You must enter a valid email address!" << endl;
                        continue;
                    }

                    my_strcopy(studentToEdit.email, value, length);
                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else if (areStrEqual(property, GRADE_TAG)) {
                    if (!isDouble(value)) {
                        cout << "Invalid format of the decimal number!" << endl;
                        continue;
                    }

                    double grade = toDouble(value);
                    if (!isValidGrade(grade)) {
                        cout << "The grade must be a decimal number between " << MIN_GRADE << " and " << MAX_GRADE
                             << "!" << endl;
                        continue;
                    }

                    studentToEdit.grade = grade;
                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else if (areStrEqual(property, FN_TAG)) {
                    if (!isNumber(value)) {
                        cout << "The faculty number must be a number!" << endl;
                        continue;
                    }

                    int newFn = toNumber(value);

                    if (fnExists(students, studentsCount, newFn)) {
                        cout << "The new faculty number is already taken!" << endl;
                        continue;
                    }

                    studentToEdit.fn = newFn;
                    cout << "Successfully changed the " << property << " to " << value << endl;
                } else {
                    cout << "The field that you choose to edit does not exist!" << endl;
                    continue;
                }
            } else if (areStrEqual(firstWord, SORT_CMD)) {
                if (areStrEqual(secondWord, NAME_TAG)) {
                    sortByName(students, studentsCount);
                } else if (areStrEqual(secondWord, AGE_TAG)) {
                    sortByAge(students, studentsCount);
                } else if (areStrEqual(secondWord, GENDER_TAG)) {
                    sortByGender(students, studentsCount);
                } else if (areStrEqual(secondWord, EMAIL_TAG)) {
                    sortByEmail(students, studentsCount);
                } else if (areStrEqual(secondWord, GRADE_TAG)) {
                    sortByGrade(students, studentsCount);
                } else if (areStrEqual(secondWord, FN_TAG)) {
                    sortByFn(students, studentsCount);
                } else {
                    cout << "The field that you choose to sort by does not exist!" << endl;
                    continue;
                }
            } else {
                cout << "Invalid command!" << endl;
                continue;
            }
        }

    }
}

char *loadFileMenu(char *filename) {
    do {
        cout << "Enter a file path:" << endl;
        cin.getline(filename, CONSOLE_BUFFER_SIZE);


        int fileSize = getFileSize(filename);
        if (fileSize == -1) {
            cout << "Error while opening the file! Try again." << endl;
            continue;
        }

        if (fileSize == 0) {
            cout << "This file has no students in it! Try entering another filepath." << endl;
            continue;
        }
        cout << "File loaded successfully!" << endl;

        char *buffer = new char[fileSize + 1];
        bool isFilled = fillBuffer(filename, buffer);

        if (!isFilled) {
            cout << "Critical error!" << endl;
            delete[] buffer;
            continue;
        }

        return buffer;
    } while (1);
}

void getTag(const char *buffer, char *tag, size_t &index) {
    if (buffer[index] == OPENING_SYMBOL)
        index++; //skip the <

    int tagIndex = 0;
    while (buffer[index] != CLOSING_SYMBOL && buffer[index] != TERMINATE_SYMBOL) {
        tag[tagIndex] = buffer[index];
        tagIndex++;
        index++;
    }
    tag[tagIndex] = TERMINATE_SYMBOL;
    index++;
}

void getValue(const char *buffer, char *value, size_t &index) {
    int valueIndex = 0;

    while (buffer[index] != OPENING_SYMBOL && buffer[index] != TERMINATE_SYMBOL) {
        value[valueIndex] = buffer[index];
        valueIndex++;
        index++;
    }
    value[valueIndex] = TERMINATE_SYMBOL;
}

int countStudents(const char *buffer) {
    int studentsCount = 0;
    size_t index = 0;
    while (buffer[index] != TERMINATE_SYMBOL) {
        if (buffer[index] == OPENING_SYMBOL && buffer[index + 1] != BACKSLASH) {
            char tag[MAX_TAG_LENGTH];
            getTag(buffer, tag, index);

            if (areStrEqual(tag, STUDENT_TAG))
                studentsCount++;
        } else {
            index++;
        }
    }
    return studentsCount;
}

//returns false if the student from the file is with wrong data
bool readStudent(const char *buffer, size_t &index, Student &student) {
    //skip the <student> tag:
    while (buffer[index] != OPENING_SYMBOL) {
        index++;
    }
    index += my_strlen(STUDENT_TAG);

    bool isValid = true;
    int parametersCount = 0;
    while (parametersCount < TAGS_NUMBER) {
        if (buffer[index] == OPENING_SYMBOL && buffer[index + 1] != BACKSLASH) {
            char tag[MAX_TAG_LENGTH];
            getTag(buffer, tag, index);

            char value[MAX_VALUE_LENGTH];
            getValue(buffer, value, index);
            if (areStrEqual(tag, NAME_TAG)) {
                int length = my_strlen(value);
                if (!isValidName(value, length))
                    isValid = false;

                my_strcopy(student.name, value, length);

                index += my_strlen(NAME_TAG);
            } else if (areStrEqual(tag, FN_TAG)) {
                if (!isNumber(value))
                    isValid = false;

                int fn = toNumber(value);
                student.fn = fn;

                index += my_strlen(FN_TAG);
            } else if (areStrEqual(tag, AGE_TAG)) {
                if (!isNumber(value))
                    isValid = false;

                int age = toNumber(value);

                if (!isValidAge(age))
                    isValid = false;

                student.age = age;

                index += my_strlen(AGE_TAG);
            } else if (areStrEqual(tag, GENDER_TAG)) {
                if (areStrEqualIgnoreCase(value, MALE)) {
                    student.gender = male;
                } else if (areStrEqualIgnoreCase(value, FEMALE)) {
                    student.gender = female;
                } else {
                    isValid = false;
                }

                index += my_strlen(GENDER_TAG);
            } else if (areStrEqual(tag, EMAIL_TAG)) {
                int length = my_strlen(value);
                if (!isValidEmail(value, length))
                    isValid = false;

                my_strcopy(student.email, value, length);

                index += my_strlen(EMAIL_TAG);
            } else if (areStrEqual(tag, GRADE_TAG)) {
                if (!isDouble(value))
                    isValid = false;

                double grade = toDouble(value);

                if (!isValidGrade(grade))
                    isValid = false;

                student.grade = grade;

                index += my_strlen(GRADE_TAG);
            } else {
                index -= my_strlen(STUDENT_TAG);
                return false;
            }
            parametersCount++;
        }
        index++;
    }

    //skip the student closing tag
    index += my_strlen(STUDENT_TAG);

    return isValid;
}

//decrease students count if a student is with wrong data
void readStudents(const char *buffer, Student *students, int &studentsCount) {
    size_t index = 0;
    for (int i = 0; i < studentsCount; ++i) {
        bool isStudentValid = readStudent(buffer, index, students[i]);

        if (!isStudentValid) {
            cout << "A student with wrong data was skipped while reading the file!" << endl;
            i--;
            studentsCount--;
        }
    }
}