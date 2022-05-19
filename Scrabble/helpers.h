/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @compiler GCC
*
* <file with helper functions>
*
*/

#ifndef SCRABBLE_HELPERS_H
#define SCRABBLE_HELPERS_H

#include <stdlib.h>
#include<time.h>

using namespace std;

const int ALPHABET_COUNT = 26;
//for each letter in the alphabet (0-25) we have different point, depending on how difficult is to form a word using that letter:
const int lettersPoints[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1,
        8, 5, 1, 3, 1, 1, 3, 10,
        1, 1, 1, 1, 4, 4, 8, 4, 10
};

bool isDigit(char a) {
    return a - '0' <= 9 && a - '0' >= 0;
}

bool isNumber(const string &str) {
    for (char const &c: str) {
        if (!isDigit(c)) return false;
    }
    return true;
}

int randomLetter() {
    int random = rand() % ALPHABET_COUNT;

    return random;
}

// returns arr[26], where the index in the array correspondents to the index of the letter in the alphabet.
// the value of each element of the array is the number of occurrences the letter has
int *generateLetters(int quantity) {
    int *result = new int[ALPHABET_COUNT];

    //set every letter to 0 occurrences
    for (int i = 0; i < ALPHABET_COUNT; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i < quantity; ++i) {
        srand(i + i * time(0)); //the seed for every letter is unique
        result[randomLetter()]++; //increase the occurrences of the letter by 1
    }

    return result;
}

void printLetters(const int *letters) {
    for (int i = 0; i < ALPHABET_COUNT; ++i) {
        for (int j = 0; j < letters[i]; ++j) {
            cout << (char) (i + 'a') << ' ';
        }
    }

    cout << endl;
    cout << "Try with word or type 1 for new letters or 0 to end the game:" << endl;
}

bool isLowerLetter(const char a) {
    return a >= 'a' && a <= 'z';
}

bool isWord(const string &word) {
    for (char const &c: word) {
        if (!isLowerLetter(c)) return false;
    }

    return true;
}

bool isPossibleWord(const string &word, const int *letters) {
    // copy the letters array:
    int *lettersArr = new int[ALPHABET_COUNT];
    for (int i = 0; i < ALPHABET_COUNT; ++i) {
        lettersArr[i] = letters[i];
    }

    for (const char &letter: word) { //for every letter in the word
        if (lettersArr[letter - 'a'] == 0) //if on the position of the current letter we do not have given letters
            return false;
        lettersArr[letter - 'a']--;
    }
    return true;
}

int getPoints(char a) {
    return lettersPoints[a - 'a'];
}

int calculatePoints(const string &word) {
    int sum = 0;
    for (const char &c: word) {
        cout << c << " -> " << getPoints(c) << endl;
        sum += getPoints(c);
    }
    return sum;
}

#endif