//
// Created by nikola354 on 25.01.22 г..
//

#ifndef FINAL_EXAM_PREPARATION_SOLUTIONS_H
#define FINAL_EXAM_PREPARATION_SOLUTIONS_H

const char TERMINATE_SYMBOL = '\0';

unsigned strLength(const char *str);

//1st TASK:

void reverseString(char *str, int length);

void replaceChars(char *str, int length);

char *revandreplace(char *str) {
    unsigned length = strLength(str);

    reverseString(str, length);

    replaceChars(str, length);

    return str;
}

unsigned strLength(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

void reverseString(char *str, int length) {
    char *temp = new char[length];

    //copy the input string to the temp var
    for (int i = 0; i < length; ++i) {
        temp[i] = str[i];
    }

    for (int i = 0; i < length; ++i) {
        str[i] = temp[length - 1 - i];
    }

    delete[] temp;
}

void replaceChars(char *str, int length) {
    for (int i = 0; i < length; ++i) {
        if (str[i] == 'e')
            str[i] = '!';
        else if (str[i] == 'y')
            str[i] = '*';
    }
}


//--------------------------2nd TASK----------------------------------

const int FORMAT_LENGTH = 7;

bool isDigit(char a);

int toNumber(char a);

int myPow(int base, int exponent);

bool isLeapYear(int year);

bool CheckDate(char input[]) {
    unsigned length = strLength(input);

    //it is not in the specified format:
    if (length != FORMAT_LENGTH)
        return false;

    //if the str does not end with " g."
    if (input[length - 3] != ' ' || input[length - 2] != 'g' || input[length - 1] != '.')
        return false;

    int year = 0;

    for (int i = 0; i < 4; ++i) {
        if (!isDigit(input[i]))
            return false;

        year += toNumber(input[i]) * myPow(10, 3 - i);
    }

    return isLeapYear(year);
}

bool isDigit(char a) {
    return a >= '0' && a <= '9';
}

int toNumber(char a) {
    return (int) (a - '0');
}

int myPow(int base, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0) || (year % 100 == 0 && year % 400 == 0));
}

// ----------------------task 3---------------------

bool isLowerLetter(int n);

bool isUpperLetter(int n);

int *countletters(int arr1[], int arr2[], int N) {
    int sum;
    int upperLetters = 0;
    int lowerLetters = 0;
    for (int i = 0; i < N; ++i) {
        sum = arr1[i] + arr2[i];

        if (isLowerLetter(sum))
            lowerLetters++;
        else if (isUpperLetter(sum))
            upperLetters++;
    }

    int *result = new int[2];
    result[0] = upperLetters;
    result[1] = lowerLetters;

    return result;
}

bool isLowerLetter(int n) {
    return n >= (int) 'a' && n <= (int) 'z';
}

bool isUpperLetter(int n) {
    return n >= (int) 'A' && n <= (int) 'Z';
}

#endif //FINAL_EXAM_PREPARATION_SOLUTIONS_H
