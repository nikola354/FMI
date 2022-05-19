//5. Напишете програма, която намира корените на квадратно уравнение.
//За целта потребителя да въведе коефицентите на уравнението - *a*, *b*, и *c*
//при уравнение с вид *a \* x^2 + b \* x + c = 0*.

#include <iostream>
#include <valarray>
#include <cmath>

using namespace ::std;

int main() {

    double a, b, c; //coefficients of the equation
    cout << "Please enter 3 coefficients of the equation!" << endl;
    cin >> a >> b >> c;

    if (a == 0){
        cout << "The coefficient before x^2 cannot be 0!";
        return -1;
    }

    double D = pow(b, 2) - (4 * a * c); // discriminant

    if (D < 0){
        cout << "No real solutions!" << endl;
        return 0;
    }

    double x1 = (- b + sqrt(D)) / (2 * a);
    double x2 = (- b - sqrt(D)) / (2 * a);

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;

    return 0;
}
