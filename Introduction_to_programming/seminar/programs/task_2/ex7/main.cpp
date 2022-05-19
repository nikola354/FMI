//7. Да се състави програма, чрез която се въвежда 4-цифренo естествено число от интервала [1000.. 9999].
//   От това число се формират 2 нови 2-цифрени числа. Първото число се формира от 1-та и 4-та цифра на въведеното
//   число. Второто число се формира от 2-рa - 3-та цифра на въведеното число.На екрана да се изведе дали
//   1-то ново число e по-малко <, равно = или по-голямо от 2-то число.
//   Използвайте проверка на логическо условие - оператор if.
//   //Задачата е взета от [тук](http://1001zadachi.com/оператор_if_сравняване_числа.html).
//
//    **Пример: 3332 Изход: less (32<33)
//    **Пример: 1144 Изход: equal (14=14)
//    **Пример: 9875 Изход: greater (95>87)

#include <iostream>

using namespace std;

int main() {

    int input;

    cout << "Number:" << endl;
    cin >> input;

    int firstDigit = input / 1000;
    int secondDigit = (input / 100) % 10;
    int thirdDigit = (input / 10) % 10;
    int forthDigit = input % 10;

    int newNumber1 = firstDigit * 10 + forthDigit;
    int newNumber2 = secondDigit * 10 + thirdDigit;

    if (newNumber1 < newNumber2){
        cout << "less" << endl;
    }else if(newNumber1 > newNumber2){
        cout << "greater" << endl;
    }else{
        cout << "equal" << endl;
    }


    return 0;
}
