#include <iostream>

#include "../headers/System.h"
#include "../headers/file.h"

void welcomeDialog();

int main() {
    try {
        welcomeDialog();
    } catch (const char *e) {
        std::cout << e << std::endl;
    }

    return 0;
}

void welcomeDialog() {
    using namespace std;

    cout << "Welcome!" << endl;

    String filename;
    while (true) {
        cout << "Enter filename: ";
        filename.getLine(cin);

        if (checkFile(filename)) {
            break;
        } else {
            std::cout << "Could not find a file with this name! Try again..." << std::endl;
        }
    }

    System sys;
    sys.loadFromFile(filename);
    sys.displayDialog();
}