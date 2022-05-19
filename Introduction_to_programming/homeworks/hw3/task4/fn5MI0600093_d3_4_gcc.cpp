/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 4
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';
const int STRING_MAX_LENGTH = 100;

int longestSubstrWithUniqueSymbolsLength(const char str[]);

bool isValidInput(const char line[]);

bool isLowerLetter(char symbol);

unsigned getLength(const char str[]);

void substr(char str[], int start, int length);

int charAt(const char str[], char symbol);

int max(int first, int second);

int main() {
    char str[STRING_MAX_LENGTH + 1];
    cin >> str;
    str[STRING_MAX_LENGTH] = TERMINATE_SYMBOL;

    if (!isValidInput(str)) {
        cout << "-1";
        return 0;
    }

    cout << longestSubstrWithUniqueSymbolsLength(str);

    return 0;
}

int longestSubstrWithUniqueSymbolsLength(const char str[]) {
    unsigned inputLength = getLength(str);

    int result = 1;

    for (int i = 0; i < inputLength - result; ++i) {
        char substring[inputLength - i]; //the string from the next letter till the end
        for (int j = 0; j < inputLength - i - 1; ++j) {
            substring[j] = str[j + i + 1];
        }
        substring[inputLength - i - 1] = TERMINATE_SYMBOL;

        int counter = 0;
        unsigned substringLength;
        do {
            /* position of the second appearance of the current letter in the string:
             * Example:
             * abca
             * position will be equal to 2,
             * because we search for 'a' in "bca"
             * */
            int position = charAt(substring, str[i + counter]);
            if (position != -1) {
                /* If the same letter appears second time, we cut the substring till that letter
                 * Example:
                 * We get "bc" from "bca"
                 */
                substr(substring, 0, position);
            } else {
                //If the current letter does not appear second time, we remove the first letter of the substring and continue checking with it
                substr(substring, 1, inputLength); // "abc" -> "bc"
                counter++;
            }

            substringLength = getLength(substring);

        } while (substringLength > 0);

        result = max(result, counter + 1);
    }

    return result;
}

bool isValidInput(const char line[]) {
    for (int i = 0; i < STRING_MAX_LENGTH; ++i) {
        if (line[i] == TERMINATE_SYMBOL) {
            return true;
        }

        if (!isLowerLetter(line[i])) {
            return false;
        }
    }

    return true;
}

bool isLowerLetter(char symbol) {
    if (symbol < 'a' || symbol > 'z') return false;
    return true;
}

unsigned getLength(const char str[]) {
    unsigned length = 0;
    while (str[length] != TERMINATE_SYMBOL) {
        length++;
    }

    return length;
}

void substr(char str[], int start, int length) {
    int i = 0;
    for (; i < length; ++i) {
        str[i] = str[start + i];
        if (str[start + i] == TERMINATE_SYMBOL) break;
    }

    str[length] = TERMINATE_SYMBOL;
}

int charAt(const char str[], char symbol) {
    unsigned length = getLength(str);

    for (int i = 0; i < length; ++i) {
        if (str[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int max(int first, int second) {
    return (first > second ? first : second);
}