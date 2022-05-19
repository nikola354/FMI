//3. Напишете програма, която приема две **различни** числа и казва кое е по голямо.
//   **Използвайте тернарен оператор**

#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main(){
    double num1, num2;

    cout << "Insert 2 numbers" << endl;
    cin >> num1 >> num2;

    if (fabs(num1 - num2) <= DBL_EPSILON * fabs(num1))
    {
        cout << "Numbers must be different!\n";
        return 1;
    }

    cout << "The bigger number is: " << (num1 > num2 ? num1 : num2);

}
