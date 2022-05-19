/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 3
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

//A is between 35 and 55
const char A_MIN = 35;
const char A_MAX = 55;

//B is between 64 and 96
const char B_MIN = 64;
const char B_MAX = 96;

const char SEPARATOR = '|';

const int MIN_XY_VALUE = 1;
const int MAX_XY_VALUE = 1000;

const int GENERATED_PASSWORDS_MAX_VALUE = 1000 * 1000;
const int GENERATED_PASSWORDS_MIN_VALUE = 1;

bool isValidSize(int x);

int main() {
    //password style -> ABxyBA

    unsigned xMax, yMax;
    cin >> xMax >> yMax;

    //validation:
    if (!isValidSize(xMax) || !isValidSize(yMax)) {
        cout << "-1"; //end program
        return 0;
    }

    unsigned maxGeneratedPasswords;
    cin >> maxGeneratedPasswords;

    if (maxGeneratedPasswords > GENERATED_PASSWORDS_MAX_VALUE ||
        maxGeneratedPasswords < GENERATED_PASSWORDS_MIN_VALUE) {
        cout << "-1"; //end program
        return 0;
    }

    int generatedPasswords = 0; //number of generated and printed passwords so far
    for (int x = 1; x <= xMax; ++x) {
        for (int y = 1; y <= yMax; ++y) {
            if (generatedPasswords >= maxGeneratedPasswords)
                return 0; // If enough passwords are printed, we terminate the program

            char currentA = A_MIN + (generatedPasswords %
                                     (A_MAX - A_MIN + 1)); // 35 + generatedPasswords % 21 => always in range [35, 55]
            char currentB = B_MIN + (generatedPasswords %
                                     (B_MAX - B_MIN + 1)); // 64 + generatedPasswords % 33 => always in range [64, 96]

            cout << currentA << currentB << x << y << currentB << currentA << SEPARATOR;

            generatedPasswords++;
        }
    }

    return 0;
}

bool isValidSize(int x) {
    if (x > MAX_XY_VALUE || x < MIN_XY_VALUE) return false;
    return true;
}