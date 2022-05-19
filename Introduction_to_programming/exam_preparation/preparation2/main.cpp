#include <iostream>

#include "Solutions.h"

using namespace std;

int main() {
    long test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    ConvertArr(test, 3, 5);

    for (int i = 0; i < 9; ++i) {
        cout << test[i] << ' ';
    }

    return 0;
}
