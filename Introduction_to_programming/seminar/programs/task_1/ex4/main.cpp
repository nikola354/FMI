//4.Напишете програма, която приема от входа две двойки реални числа, отговарящи на две точки в равнината.
//  Да се отпечата растоянието между точките закръглено до 2-рия знак след десетичната запетая.
//  **Потърсете математическата формула в интернет ако не я знаете!**

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x1, y1, x2, y2;

    cout << "Please enter the coordinates of the first point - x1 and y1" << endl;
    cin >> x1 >> y1;
    cout << "Please enter the coordinates of the second point - x2 and y2" << endl;
    cin >> x2 >> y2;

    double result = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    cout << fixed << setprecision(2) << result;
}
