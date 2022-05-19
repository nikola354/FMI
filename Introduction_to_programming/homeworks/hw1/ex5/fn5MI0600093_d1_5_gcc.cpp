/**
*
* Solution to homework assignment 1
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

using namespace std;

int pow(int base, int exponent);

int main() {
    int number;
    cin >> number;

    //validation:
    if (number < 0){
        cout << "-1"; //end program
        return 0;
    }

    //get the length of the number:
    int length = 0;
    int base = number;
    do {
        length++;
        base /= 10;
    } while (base);

    bool printedSomething = false; // if we print at least 1 digit, it gets true
    for (int i = length - 1; i >= 0; i--){
        int digit = number / pow(10, i) % 10; // 12345 / 10^4 = 1 % 10 = 1

        if (digit % 2 != 0){ //if the number is even, we print it
            cout << digit;
            printedSomething = true;
        }
    }

    if (!printedSomething) cout << 0;

    return 0;
}

int pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}