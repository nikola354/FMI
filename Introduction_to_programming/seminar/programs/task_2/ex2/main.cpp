//Напишете програма, която приема един символ от входа и проверява дали:
//
//* този символ е буква от латинската азбука;
//* ако да, дали тази буква е гласна или съгласна.
//
//**Програмата да работи както за малки, така и за главни букви**

#include <iostream>
#include <cctype>

using namespace std;

int main() {

    char c;
    cout << "Please input only one symbol!" << endl;
    cin >> c;

    if (isalpha(c)) {
        if (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' ||
                c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I') {
            cout << "The letter is vowel" << endl;
        } else {
            cout << "The letter is consonant" << endl;
        }
    } else {
        cout << "The symbol is not a latin letter!" << endl;
    }

    return 0;
}