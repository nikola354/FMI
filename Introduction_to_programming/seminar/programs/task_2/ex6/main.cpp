//6. Напишете прост калкулатор, който поддържа операциите +, -, *, / на две реални числа.
//   **Внимавайте с делението на 0**

#include <iostream>
//#include <Windows.h>

using namespace std;

int main() {

    double num1, num2;
    char op;

    cout << "First number:" << endl;
    cin >> num1;

    cout << "Operator (+ - * /):" << endl;
    cin >> op;

    cout << "Second number:" << endl;
    cin >> num2;

    //action:
    double result;

    if (op == '+') {
        result = num1 + num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '/') {
        if (num2 == 0) {
            cout << "Cannot divide by zero!" << endl;
            return -1;
        } else {
            result = num1 / num2;
        }
    } else {
        cout << "Only the following signs are allowed: + - * /";
        return -1;
    }

    cout << result << endl;

    return 0;
}