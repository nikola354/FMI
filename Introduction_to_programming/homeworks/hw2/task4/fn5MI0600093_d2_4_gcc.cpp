/**
*
* Solution to homework assignment 2
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

int pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int countDigits(int number) {
    int counter = 0;
    while (number > 0) {
        counter++;
        number /= 10;
    }
    return counter;
}

int swapDigits(int number, int pos1, int pos2, int length) {
    int digit1Dec = pow(10, length - pos1 - 1);
    int digit2Dec = pow(10, length - pos2 - 1);

    int digit1 = (number / digit1Dec) % 10;
    int digit2 = (number / digit2Dec) % 10;

    int removed = number - (digit1Dec * digit1) - (digit2Dec * digit2);

    return removed + (digit1Dec * digit2) + (digit2Dec * digit1);
}

int addNumber(int number, int added) {
    return number * 10 + added;
}

int removeLastDigit(int number) {
    return number /= 10;
}

int indexOf(int digit, int number, int length) {
    int counter = 0;
    while (number > 0) {
        counter++;
        if (number % 10 == digit) {
            return length - counter;
        }
        number /= 10;
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    bool ok = false;
    while (!ok) {
        ok = true;
        int lengthN = countDigits(n);
        int lengthK = countDigits(k);

        int pos = indexOf(n % 10, k, lengthK);
        if (pos == -1){
            removeLastDigit(n); //removing last digit from n because it is not in k
            ok = false;
        }else if (pos < lengthN - 1){
            swapDigits(n, pos, lengthN - 1, lengthN);
            ok = false;
        }
    }

}