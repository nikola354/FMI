/**
*
* Solution to homework assignment 3
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
const int WORD_MAX_SIZE = 20;

unsigned my_strlen(const char *str);

bool isCorrect(const char sequence[][WORD_MAX_SIZE], int sequenceSize);

int main() {
    int n;
    cin >> n;

    //Validation:
    if (n < 2 || n > 50) {
        cout << "-1";
        return 0;
    }

    char sequence[n][WORD_MAX_SIZE];
    int index = 0;
    while (index < n) { //Get all words
        cin >> sequence[index];
        sequence[index][WORD_MAX_SIZE - 1] = TERMINATE_SYMBOL;

        index++;
    }

    if (isCorrect(sequence, n)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}

unsigned my_abs(int number) {
    if (number < 0) return number * -1;
    return number;
}

bool isCorrect(const char sequence[][WORD_MAX_SIZE], int sequenceSize) {
    for (int i = 0; i < sequenceSize - 1; ++i) {
        unsigned currentWordLength = my_strlen(sequence[i]);
        unsigned nextWordLength = my_strlen(sequence[i + 1]);

        //If the abs difference is greater than 1 we cannot get to one word from another by only adding or removing 1 letter
        if (my_abs((currentWordLength - nextWordLength)) > 1)
            return false;

        if (currentWordLength == nextWordLength) { //Operation: change a letter
            int differences = 0;
            //Compare the letters in 2 words one by one
            for (int j = 0; j < currentWordLength; ++j) {
                if (sequence[i][j] != sequence[i + 1][j]) differences++;
            }

            //If we have to change more than 1 letter to get the next word, or we do not have to change anything
            if (differences != 1) return false;
        } else if (currentWordLength > nextWordLength) { //Operation: remove a letter
            for (int j = 0; j < nextWordLength; ++j) {
                /* To get the next word, we remove a letter from the current word
                 * We check if this is possible:
                 *
                 * The current letter of the current word must be equal to the current letter of the next word (left case in the if statement)
                 * OR
                 * if the current letter in the current word will be the removed one ->
                 * -> the next letter of the current word must be equal to the current letter in the next word
                 *
                 * */
                if (sequence[i][j] != sequence[i + 1][j] && sequence[i][j + 1] != sequence[i + 1][j])
                    return false;
            }
        } else { //Operation: add a letter
            for (int j = 0; j < currentWordLength; ++j) {
                if (sequence[i][j] != sequence[i + 1][j] && sequence[i][j] != sequence[i + 1][j + 1])
                    return false;
            }
        }
    }

    return true;
}

unsigned my_strlen(const char *str) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}