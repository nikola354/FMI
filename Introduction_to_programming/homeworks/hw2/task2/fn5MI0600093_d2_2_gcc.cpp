/**
*
* Solution to homework assignment 2
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

int reverseNumber(int number) {
    int reversed = 0;

    while (number > 0){
        reversed *= 10;
        reversed += number % 10;

        number /= 10;
    }
    return reversed;
}

bool isPalindrome(int n) {
    return (n == reverseNumber(n));
}

const int MIN_VALUE = 1;
const int MAX_VALUE = 1000 * 1000 * 1000;

int main() {
    int n;
    cin >> n;

    if (n < MIN_VALUE || n > MAX_VALUE) { //validation
        cout << "-1"; //end program
        return 0;
    }

    if (n <= 101) { // the lowest palindrome is 101
        cout << 101;
        return 0;
    }

    if (isPalindrome(n)) {
        cout << n;
        return 0;
    }

    int lowerPalindrome = 0;
    for (int j = n - 1; j > 0; j--) {
        if (isPalindrome(j)) {
            lowerPalindrome = j;
            break;
        }
    }

    int distance = n - lowerPalindrome;

    for (int i = n + 1; i <= MAX_VALUE; i++) {
        if (i - n >= distance){ // if the higher palindrome is more distanced, we print the lower
            cout << lowerPalindrome;
            return 0;
        }
        if (isPalindrome(i)) { // if we reach higher palindrome before reaching the distance between lower and the number, we print it
            cout << i;
            return 0;
        }
    }

    return 0;
}