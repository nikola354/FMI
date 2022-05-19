#include <iostream>
#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Vector v(3);
    Vector v1(3);

    cin >> v >> v1;

    Vector v2 = v * 5;

    cout << std::boolalpha << v.isParallelTo(v2) << endl;

    cout << v << endl;
    cout << v1 << endl;
    cout << v2 << endl;

//    int *elements = new int[3];
//    int *p = nullptr;
//
//    element = p; //address elements = address p

    return 0;
}
