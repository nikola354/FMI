/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 2
* @compiler GCC
*
*/

#include <vector>
#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

const int MAX_STR_SIZE = 1024; // 1KB

const int MAX_TEXT_SIZE = 4 * 1024; // 4 KB

int replace(char *text, const char *str1, const char *str2);

int indexOf(const char *str, int strLength, const char *segment, int segmentLength);

unsigned strLength(const char *str);

char *substring(const char *str, int start, int newLength);

void duplicateCharPtr(char *target, const char *source, int targetStartIndex, int length);

int main() {
    char *text = new char[MAX_TEXT_SIZE]; //1 char = 1 byte
    char *str1 = new char[MAX_STR_SIZE];
    char *str2 = new char[MAX_STR_SIZE];

    cin.getline(text, MAX_TEXT_SIZE);
    cin.getline(str1, MAX_STR_SIZE);
    cin.getline(str2, MAX_STR_SIZE);

    cout << replace(text, str1, str2) << endl;

    cout << text << endl;

    return 0;
}

int replace(char *text, const char *const str1, const char *const str2) {
    unsigned textLength = strLength(text);
    unsigned str1Length = strLength(str1);
    unsigned str2Length = strLength(str2);

    //get the index of str1 in text
    //If the text does not contain the str1 -> indexOf returns -1
    int str1Position = indexOf(text, textLength, str1, str1Length);
    int occurrences = 0;
    while (str1Position != -1) {
        int afterStr1Length = textLength - (str1Position + str1Length);
        char *afterStr1 = new char[afterStr1Length];
        afterStr1 = substring(text, str1Position + str1Length, afterStr1Length);

        //change str1 with str2:
        duplicateCharPtr(text, str2, str1Position, str2Length);
        //place the unchanged string on the right of the changed string
        duplicateCharPtr(text, afterStr1, str1Position + str2Length, afterStr1Length);

        //get the next occurrence of the str1 (if there is any)
        str1Position = indexOf(text, textLength, str1, str1Length);

        //update the actual length of the text:
        textLength -= str1Length;
        textLength += str2Length;

        delete[] afterStr1;
        occurrences++;
    }

    return occurrences;
}

int indexOf(const char *str, int strLength, const char *segment, int segmentLength) {
    for (int i = 0; i <= strLength - segmentLength; ++i) {
        bool match = true;
        for (int j = 0; j < segmentLength; ++j) {
            if (str[i + j] != segment[j]) {
                match = false;
                break;
            }
        }

        if (match) return i;
    }

    return -1;
}

char *substring(const char *str, int start, int newLength) {
    char *result = new char[newLength];

    for (int i = 0; i < newLength; ++i) {
        result[i] = str[i + start];
    }

    return result;
}

unsigned strLength(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

void duplicateCharPtr(char *target, const char *source, int targetStartIndex, int length) {
    int i = 0;
    for (; i < length; ++i) {
        target[i + targetStartIndex] = source[i];
    }
    target[i + targetStartIndex] = TERMINATE_SYMBOL;
}