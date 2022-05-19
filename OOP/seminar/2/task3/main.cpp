#include <iostream>
#include <fstream>

using namespace std;

const int MAX_FIELD = 100;
const int BUFFER_LINE_SIZE = 1000;
const char SEPARATOR = ',';
const char TERMINATE_SYMBOL = '\n';

struct Student {
    char firstName[MAX_FIELD];
    char lastName[MAX_FIELD];
    char email[MAX_FIELD];
    int fn = 0;

    void print() const {
        cout << "Name: " << firstName << " " << lastName << ", " << "Email: " << email << ", " << "FN: " << fn << endl;
    }

    void read(const char *line) {
        int index = 0;

        //first name:
        while(line[index] != SEPARATOR) {
            firstName[index] = line[index];
            index++;
        }
        firstName[index] = TERMINATE_SYMBOL;
        index++;

        //last name:
        int lastNameIndex = 0;
        while (line[index] != SEPARATOR) {
            lastName[lastNameIndex] = line[index];
            index++;
            lastNameIndex++;
        }
        lastName[lastNameIndex] = TERMINATE_SYMBOL;
        index++;

        //email
        int emailIndex = 0;
        while (line[index] != SEPARATOR) {
            email[emailIndex] = line[index];
            index++;
            emailIndex++;
        }
        email[emailIndex] = TERMINATE_SYMBOL;
        index++;

        //FN:
        while (line[index] != '\n') {
            fn *= 10;
            fn += (line[index] - '0');
            index++;
        }
    }
};

bool checkFile(const char *filename, int &lines);

int countLines(ifstream &readFile);

void readStudents(const char *fileName, Student *students, int studentsCount);

int main() {
    bool repeat;
    do {
        repeat = false;

        cout << "Open file:" << endl;
        char filename[MAX_FIELD];
        cin >> filename;

        int lines = 0;

        if (!checkFile(filename, lines)) {
            cout << "Invalid or empty file!" << endl;
            repeat = true;
            continue;
        }

        cout << "Successfully opened!" << endl;

        int studentsCount = lines - 1; //the first line of the file are the columns names
        Student *students = new Student[studentsCount];

        readStudents(filename, students, studentsCount);

        //todo: all commands

    } while (repeat);

}

bool checkFile(const char *filename, int &lines) {
    ifstream readFile(filename);

    if (!readFile.is_open())
        return false;

    lines = countLines(readFile);

    if (lines <= 1) {
        readFile.close();
        return false;
    }

    readFile.close();
    return true;
}

int countLines(ifstream &readFile) {
    int counter = 0;
    while (!readFile.eof()) {
        char buffer[BUFFER_LINE_SIZE];
        readFile.getline(buffer, BUFFER_LINE_SIZE);
        counter++;
    }

    return counter;
}


void readStudents(const char *fileName, Student *students, int studentsCount) {
    ifstream readFile(fileName);

    char line[BUFFER_LINE_SIZE];
    readFile.getline(line, BUFFER_LINE_SIZE); //just skip the 1st row

    for (int i = 0; i < studentsCount; ++i) {
        if (readFile.eof())
            break;

        readFile.getline(line, BUFFER_LINE_SIZE);

        students[i].read(line);
    }

    readFile.close();
}

