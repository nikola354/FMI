//3.Напишете програма, която взима две числа от стандартния вход и извежда *true* ако първото е по - малко от второто
//  и *false* в противен случай.

#include <iostream>

using namespace std;

int main() {
    double num1, num2;

    cout << "Please enter 2 numbers:" << endl;
    cin >> num1 >> num2;

    cout << (num1 < num2 ? "true" : "false") << endl;

    return 0;
}
