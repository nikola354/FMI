#include <iostream>

using namespace std;

const short int leapCondition1 = 4;
const short int leapCondition2 = 100;
const short int leapCondition3 = 400;

int main() {
    long long unsigned year;

    cout << "Enter an year: " << endl;
    cin >> year;

    if (year % leapCondition1 == 0 && (year % leapCondition2 != 0 || year % 400 == 0)){
        cout << "The year is leap." << endl;
    }else{
        cout << "NOT LEAP" << endl;
    }

    return 0;
}
