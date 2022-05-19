/**
*
* Solution to homework assignment 2
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

int main() {
    /*
     * We reverse the problem.
     * We try to get the starting number, beginning with the result
     * The operations will be:
     * (1) - divide by 2 if the number is even
     * (2) - add 1 to the number
     * * * * *  result + 1   OR   result / 2    * * * * * * *
     * */

    unsigned int start, result;
    cin >> start >> result;

    //if the result is less than the start, we add 1 until it becomes start
    if (start >= result){
        cout << (start - result);
        return 0;
    }

    int steps = 0;

    //cycle divides by 2 only even numbers until result is less than the start
    while (result > start){
        if (result % 2 == 1){
            result++;
            steps++;
        }

        result /= 2;
        steps++;
    }

    //when the result is less, we just add 1 until it becomes start. Then we print the number
    cout << (steps + start - result);
    return 0;
}