/**
*
* Solution to homework assignment 1
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

int main() {
    int number;
    cin >> number;

    //validation: number between 1 and 9
    if (number < 1 || number > 9) {
        cout << "-1"; //end program
        return 0;
    }

    //using while instead of for to avoid one empty row in the end of the output
    int line = 1;
    while (true) { // for every row of the output // the number of rows is (number * 2 - 1)
        for (int k = number; k > number - line + 1 && k > 1; k--) { //spaces
            cout << " ";
        }
        if (line <= number) { // separate the output in 2 halves
            for (int j = line; j <= number; j++) { // until we reach the until number
                cout << j;
            }
        } else {
            for (int i = number; i >= 2 * number - line; i--) {
                cout << i;
            }
        }

        if (line >= number * 2 - 1) break; // break before the last endl to avoid empty row
        cout << endl;

        line++;
    }

    return 0;
}