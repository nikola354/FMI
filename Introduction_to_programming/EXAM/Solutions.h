// 5MI0600093 - Nikola Manolov
// Created by nikola354 on 26.01.22 г..
//

#ifndef EXAM_SOLUTIONS_H
#define EXAM_SOLUTIONS_H

int *newArr(int *arr, int len) {
    //get the average value of the array and count the even numbers
    int average = 0;
    int evenNumbers = 0;

    for (int i = 0; i < len; ++i) {
        average += arr[i];
        if (arr[i] % 2 == 0)
            evenNumbers++;
    }
    average /= len;

    int *result = new int[evenNumbers];
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        if (arr[i] % 2 == 0) {
            result[counter] = arr[i] + average;
            counter++;
        }
    }

    return result;
}

//-----------------------TASK 2-----------------------------

int *revArr(int *arr, int len, int k) {
    k--; // I count from 0

    if (k < 0 || k >= len)
        return nullptr;

    //get the numbers to be reversed
    int reversedSize = len - k;
    int *toBeReversed = new int[reversedSize];
    for (int i = k; i < len; ++i) {
        toBeReversed[i - k] = arr[i];
    }

    //add the normal numbers at the end
    int *result = new int[len];
    for (int i = 0; i < k; ++i) {
        result[reversedSize + i] = arr[i];
    }

    //add the reversed numbers in the front
    for (int i = 0; i < reversedSize; ++i) {
        result[i] = toBeReversed[reversedSize - i - 1];
    }

    delete[] toBeReversed;
    return result;
}


//-----------------------TASK 3---------------------

const char TERMINATE_SYMBOL = '\0';
const char CHANGE_SYMBOL = '*';
const char TAB_SYMBOL = '\t';
const char SPACE_SYMBOL = ' ';

unsigned strLength(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }
    return length;
}

bool isPartOfWord(char a) {
    return a != TAB_SYMBOL && a != SPACE_SYMBOL;
}

char *changeWord(char *str, char k) {
    unsigned length = strLength(str);

    bool changeNext = false;
    for (int i = 0; i < length; ++i) {
        if (!isPartOfWord(str[i])) {
            changeNext = false;
            continue;
        }

        if (str[i] == k && (i == 0 || !isPartOfWord(str[i - 1])))
            changeNext = true;

        if (changeNext) {
            str[i] = CHANGE_SYMBOL;
        }
    }

    return str;
}

#endif //EXAM_SOLUTIONS_H
