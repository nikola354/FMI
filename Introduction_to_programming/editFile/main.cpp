#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int strLength (char *str){
    int length = 0;

    while (*str++ != '\0'){
        length++;
    }
    return length;
}

int main() {

    fstream dictionary;

    dictionary.open("../words10000.txt", fstream::in);

    string word;

    int counter = 1;
    while (getline(dictionary, word)) {
        if (word == "search") {
            cout << "word: " << word << endl;
        }

        counter++;
    }
    cout << counter;

    return 0;
}
