#include <iostream>

using namespace std;

int main() {
    double length, width;

    cout << "Please enter the length of the rectangle:" << endl;
    cin >> length;
    cout << "Please enter the width of the rectangle:" << endl;
    cin >> width;

    cout << "The perimeter of the rectangle is: " << 2 * (length + width) << endl;
    cout << "The area of the rectangle is: " << width * length << endl;

}
