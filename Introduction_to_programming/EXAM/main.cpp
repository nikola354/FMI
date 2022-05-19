#include <iostream>

using namespace std;

#include "Solutions.h"

void testEx1() {
    int test[] = {1, 2, 0, 4, 5, 6, 7, 8, 9, 10};

    int *result = newArr(test, 10);

    for (int i = 0; i < 10; ++i) {
        cout << result[i] << ' ';
    }

    cout << endl;
}

void testEx2() {
    int test[] = {1, 2, 3, 4, 5, 6, 7, 8, -5, 10};

    int k = 5;

    int length = 10;

    int *result = revArr(test, length, k);

    for (int i = 0; i < length; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
}

void testEx3() {
    char test[] = "t attt 7ttttttt";

    char k = 't';

    char *result = changeWord(test, k);
    int length = strLength(result);

    cout << result << endl;
}

int main() {
    testEx2();

    return 0;
}
