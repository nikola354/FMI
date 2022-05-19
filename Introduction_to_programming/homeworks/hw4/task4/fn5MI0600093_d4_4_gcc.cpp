/**
*
* Solution to homework assignment 4
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

const int MIN_ARRAY_SIZE = 3;

const int MAX_ARRAY_SIZE = 1000;

const char ERROR_MSG[] = "-1";

const char SUCCESS_MSG[] = "yes";

const char FAILURE_MSG[] = "no";

void initialize(int *arr, int size);

bool isHacksaw(int *arr, int index, int size, bool firstMustGreater);

bool isValidArraySize(int n);

void runUnitTests();

int main() {
    int N; //array size
    cin >> N;

    //validation:
    if (!isValidArraySize(N)) {
        cout << ERROR_MSG;
        return 0; //terminate
    }

    //initialize:
    int *arr = new int[N];
    initialize(arr, N);

    // x1 > x2 < x3 > x4....                               OR       x1 < x2 > x3 < x4....
    if (isHacksaw(arr, 0, N, true) || isHacksaw(arr, 0, N, false)) {
        cout << SUCCESS_MSG;
    } else {
        cout << FAILURE_MSG;
    }

    return 0;
}

void initialize(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

bool isHacksaw(int *arr, int index, int size, bool firstMustGreater) {
    //If the index points to the last element of the array and did not return false, the sequence is a hacksaw
    if (index >= size - 1) return true;

    if ((firstMustGreater && arr[index] <= arr[index + 1]) ||
        (!firstMustGreater && arr[index] >= arr[index + 1]))
        return false;

    //if the current elements are hacksaw, continue to the next ones
    return isHacksaw(arr, index + 1, size, !firstMustGreater);
}

bool isValidArraySize(int n) {
    if (n < MIN_ARRAY_SIZE || n > MAX_ARRAY_SIZE) return false;
    return true;
}


// ---------UNIT TESTS WITH RANDOM VALUES------------

#include <stdlib.h> //used ONLY for rand and NOT for the main task

bool isEven(int n) {
    return (n % 2 == 0);
}

void runUnitTests() {
    const int INPUTS_SIZE = 10;
    const int MAX_NUMBER = 2147483647 - MAX_ARRAY_SIZE;

    int **goodInputs = new int *[INPUTS_SIZE];
    int arraySize = 50;

    for (int i = 0; i < INPUTS_SIZE; ++i) {
        goodInputs[i] = new int[arraySize];

        bool firstIsGreater = isEven(i); //alternating x1 > x2 < x3... with x1 < x2 > x3...
        goodInputs[i][0] = (rand() % MAX_NUMBER) - (rand() % MAX_NUMBER);

        for (int j = 1; j < arraySize; ++j) {
            if (firstIsGreater) {
                goodInputs[i][j] = goodInputs[i][j - 1] - j;
            } else {
                goodInputs[i][j] = goodInputs[i][j - 1] + j;
            }

            firstIsGreater = !firstIsGreater;
        }
    }

    //check good inputs
    for (int i = 0; i < INPUTS_SIZE; ++i) {
        if (isHacksaw(goodInputs[i], 0, arraySize, true) ||
            isHacksaw(goodInputs[i], 0, arraySize, false)) {
            cout << "TEST #" << i + 1 << " PASSED!" << endl;

        } else {
            cout << "TEST #" << i + 1 << " FAILED!" << endl;
        }
    }
}