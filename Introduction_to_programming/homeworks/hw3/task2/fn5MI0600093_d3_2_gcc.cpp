/**
*
* Solution to homework assignment 3
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

const int ARRAY_MIN_SIZE = 2;
const int ARRAY_MAX_SIZE = 100;

int longestDist(const int arr[], const int arrSize);

int main() {
    int n;
    cin >> n;

    //validation:
    if (n > ARRAY_MAX_SIZE) {
        cout << "-1"; //end program
        return 0;
    }

    int arr[n];

    //fill the array
    int index = 0;
    while (index < n) {
        cin >> arr[index];
        index++;
    }

    cout << longestDist(arr, n);

    return 0;
}

int longestDist(const int arr[], const int arrSize) {
    if (arrSize < ARRAY_MIN_SIZE) return -2;

    int longestDist = 0;
    int index = -1; //index of the number with the longest distance
    for (int i = 0; i < arrSize - longestDist; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if (arr[i] == arr[j] && (j - i) > longestDist) {
                longestDist = j - i;
                index = i;
            }
        }
    }

    return index;
}
