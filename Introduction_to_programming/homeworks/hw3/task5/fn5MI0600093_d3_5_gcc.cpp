/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <vector>

using namespace std;

const char TERMINATE_SYMBOL = '\0';
const unsigned ASCII_UPPER_LOWER_DIFFERENCE = 'a' - 'A';
const int INPUT_MAX_LENGTH = 255;

void runProgram(char input[]);

bool isValidInput(const char line[]);

bool areEqualIgnoreCase(const char first[], const char second[]);

void splitStringIntoLowerUpper(const char str[], char lowerLetters[], char upperLetters[]);

bool isLowerLetter(char symbol);

bool isUpperLetter(char symbol);

char toUpper(char symbol);

unsigned getLength(const char str[]);

int main() {
    char input[INPUT_MAX_LENGTH + 1];
    cin >> input;
    input[INPUT_MAX_LENGTH] = TERMINATE_SYMBOL;

    if (!isValidInput(input)) {
        cout << "-1";
        return 0;
    }

    runProgram(input);

    return 0;
}

void runProgram(char input[]) {
    unsigned length = getLength(input);
    char lowerLetters[length + 1];
    char upperLetters[length + 1];

    splitStringIntoLowerUpper(input, lowerLetters, upperLetters);

    if (areEqualIgnoreCase(lowerLetters, upperLetters)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

bool isValidInput(const char line[]) {
    for (int i = 0; i < INPUT_MAX_LENGTH; ++i) {
        if (line[i] == TERMINATE_SYMBOL) {
            return true;
        }

        if (!isLowerLetter(line[i]) && !isUpperLetter(line[i])) {
            return false;
        }
    }

    return true;
}

bool areEqualIgnoreCase(const char first[], const char second[]) {
    unsigned firstLength = getLength(first);
    unsigned secondLength = getLength(second);

    if (firstLength != secondLength) return false;

    for (int i = 0; i < firstLength; ++i) {
        if (toUpper(first[i]) != toUpper(second[i])) return false;
    }

    return true;
}

void splitStringIntoLowerUpper(const char str[], char lowerLetters[], char upperLetters[]) {
    unsigned length = getLength(str);

    int lowerIndex = 0;
    int upperIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (isLowerLetter(str[i])) {
            lowerLetters[lowerIndex] = str[i];
            lowerIndex++;
        } else if (isUpperLetter(str[i])) {
            upperLetters[upperIndex] = str[i];
            upperIndex++;
        }
    }

    lowerLetters[lowerIndex] = TERMINATE_SYMBOL;
    upperLetters[upperIndex] = TERMINATE_SYMBOL;
}

bool isLowerLetter(char symbol) {
    if (symbol < 'a' || symbol > 'z') return false;
    return true;
}

bool isUpperLetter(char symbol) {
    if (symbol < 'A' || symbol > 'Z') return false;
    return true;
}

char toUpper(char symbol) {
    if (isLowerLetter(symbol)) {
        return (char) (symbol - ASCII_UPPER_LOWER_DIFFERENCE);
    }
    return symbol;
}

unsigned getLength(const char str[]) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}