//4. Напишете програма, която приема от входа три числа - страни на триъгълник.
//   Програмата да проверява дали това е валиден триъгълник.

#include <iostream>

using namespace std;

int main(){

    double a, b, c;
    cout << "Please enter the sides of the triangle!" << endl;
    cin >> a >> b >> c;

    //validation
    if (a <= 0 || b <= 0 || c <= 0){
        cout << "You have to enter only positive numbers!";
        return -1;
    }

    if ((a + b) > c && (a + c) > b && (b + c) > a)
        cout << "The sides can build a real triangle!" << endl;
    else
        cout << "NOT REAL" << endl;

    return 0;
}
