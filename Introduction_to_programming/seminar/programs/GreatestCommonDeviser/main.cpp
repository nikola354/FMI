#include <iostream>

using namespace std;

int main() {

    int num1, num2, deviser = 1;

    cout << "Enter 2 numbers!: " << endl;
    cin >> num1 >> num2;

    for (int i = 1; i <= abs(num1 - num2); i++){
        if(num1 % i == 0 && num2 % i == 0){
            deviser = i;
        }
    }

    cout << deviser << endl;

    return 0;
}
