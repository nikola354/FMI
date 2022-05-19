/**
*
* Solution to homework assignment 1
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

#include <iostream>

using namespace std;

int pow(int base, int exponent);

int main() {
    int number;
    cin >> number;

    //validation: whole number between 1 and 10^9
    if (number < 1 || number > pow(10, 9)) {
        cout << "-1";
        return 0;
    }

    //get the length of the integer:
    double length = 0;
    int base = number;
    do {
        length++;
        base /= 10;
    } while (base);
//   5/2 = 2    12345 / 100
    for (int i = 0; i < length / 2; i++) {
        int leftDigit = number / pow(10, length - i - 1); // removing the digits on the right of this digit
        leftDigit = leftDigit % 10;

        int rightDigit = number / pow(10, i); // removing the digits on the right of this digit
        rightDigit = rightDigit % 10;

        /*
         * if leftDigit = rightDigit, they can be both the middle digit or just 2 equal digits
         * if they are 2 equal digits they lose, and we do not do anything
         * if they are the middle digit we have to print it
         * it does not matter which digit (right or left) we print if it is the middle number:
         */
        if (leftDigit > rightDigit ||
            (leftDigit == rightDigit && (length / 2) - i < 1)) { // length = 5 -> 5/2 - 2(i=2) < 1
            cout << leftDigit;
            if (i < (length / 2) - 1)
                cout << " ";
        }else if (rightDigit > leftDigit) {
            cout << rightDigit;
            if (i < (length / 2) - 1)
                cout << " ";
        }
    }

    return 0;
}

int pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}