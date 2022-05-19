/**
*
* Solution to homework assignment 2
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

bool hasAlternatingBits(unsigned n);

int main() {
    int n;
    cin >> n;

    if (n < 0){ //validation
        cout << "-1"; //end program
        return 0;
    }

    cout << boolalpha << hasAlternatingBits(n);

    return 0;
}

/*
 *  100001 -> false
 *  101010 -> true
 * */
bool hasAlternatingBits(unsigned n) {
    bool prevBit = n % 2;
    n /= 2;

    while (n > 0){
        bool currBit = n % 2;

        // if current bit is same as previous, the bits are not alternating and return false
        if (currBit == prevBit)
            return false;

        prevBit = currBit; // initialize the value of the current bit to the prevBit variable
        n /= 2;
    }

    return true;
}