/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 1
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

const int ASCII_UPPER_LOWER_DIFFERENCE = 'a' - 'A';

char **letterCasePermutation(char *str);

unsigned strLength(const char *str);

bool isLowerLetter(char symbol);

void toUpperCase(char &symbol);

void duplicateCharPtr(char *target, char *source, int length);

void print(char **casePermutations);

unsigned countPermutations(const char *str, int length);

unsigned countLowerLetters(const char *str, int length);

unsigned my_pow(int base, int exponent);

int main() {
    char *str = new char;
    cin >> str;

    char **casePermutations = letterCasePermutation(str);

    print(casePermutations);

    return 0;
}

char **letterCasePermutation(char *str) {
    unsigned length = strLength(str);

    unsigned permutationsNumber = countPermutations(str, length); //count all possible permutations

    //we will add the permutations in lexicographical order
    char **resultPermutations = new char *[permutationsNumber];

    resultPermutations[0] = new char[length]; //the first permutation in the array is always the string because it is with lower letters
    duplicateCharPtr(resultPermutations[0], str, length);

    int madePermutations = 1; //number of permutations so far

    char *newPermutation = new char[length];
    for (int i = length - 1; i >= 0; --i) { //start with the last letter of the given string
        if (isLowerLetter(str[i])) { //if the current symbol is a letter, we make the permutations with it
            //we go through all the permutations we already have, change the cur. symbol toUpper and save it in the result array
            for (int j = 0; j < madePermutations; ++j) {
                duplicateCharPtr(newPermutation, resultPermutations[j], length); //get the permutation

                toUpperCase(newPermutation[i]); //upper the current symbol

                //save to the result array:
                resultPermutations[j + madePermutations] = new char[length];
                duplicateCharPtr(resultPermutations[j + madePermutations], newPermutation, length);
            }
            madePermutations *= 2;
        }
    }
    delete[] newPermutation;

    return resultPermutations;
}

unsigned strLength(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

bool isLowerLetter(char symbol) {
    if (symbol < 'a' || symbol > 'z') return false;
    return true;
}

void toUpperCase(char &symbol) {
    if (isLowerLetter(symbol)) {
        symbol -= ASCII_UPPER_LOWER_DIFFERENCE;
    }
}

void duplicateCharPtr(char *target, char *source, int length) {
    for (int i = 0; i < length; ++i) {
        target[i] = source[i];
    }
}

void print(char **casePermutations) {
    for (int i = 0; casePermutations[i] != nullptr; i++) {
        cout << casePermutations[i] << ' ';
    }
}

unsigned countPermutations(const char *str, int length) {
    return my_pow(2, countLowerLetters(str, length));
}

unsigned countLowerLetters(const char *str, int length) {
    unsigned counter = 0;

    for (int i = 0; i < length; ++i) {
        if (isLowerLetter(str[i])) {
            counter++;
        }
    }

    return counter;
}

unsigned my_pow(int base, int exponent) {
    unsigned result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}