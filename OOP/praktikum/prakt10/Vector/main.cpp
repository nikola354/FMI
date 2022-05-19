#include <iostream>

#include "Vector.h"

int main() {
    Vector<int> v;

    v.pushBack(5);

    Vector<int> v2(std::move(v));

    v.popBack();

    Vector<int> v3;

    v3 = Vector<int>();

    return 0;
}
