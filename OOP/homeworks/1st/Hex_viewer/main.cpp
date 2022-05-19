#include <iostream>
#include <fstream>

using namespace std;

#include "constants.h"
#include "helpers.h"

struct File {
    char name[MAX_FILENAME_LENGTH];
    unsigned size;
    int bytes[MAX_FILE_SIZE];

    bool setBytes() {
        ifstream stream;
        stream.open(name, std::ios_base::binary);

        if (stream.bad()) {
            return false;
        }

        for (int i = 0; i < size; ++i) {
            char c;
            stream.read((char *) &c, 1);

            bytes[i] = (int) c;
        }

        stream.close();
        return true;
    }

    bool save(const char *filename) const {
        ofstream writeFile;
        writeFile.open(filename, ios::trunc | ios::binary);

        if (!writeFile.is_open())
            return false;

        for (int i = 0; i < size; ++i) {
            writeFile.write((char *) &bytes[i], 1);
        }

        writeFile.close();
        return true;
    }

    bool save() const {
        return save(name);
    }

    void add(int byte) {
        bytes[size] = byte;
        size++;
    }

    void change(int index, int byte) {
        bytes[index] = byte;
    }
};

void initFile(File &myFile);

void menu(File &myFile);

void severalWordsMenu(const char *command, File &myFile);

void viewFile(const File &myFile);

int main() {
    File myFile;

    initFile(myFile);

    menu(myFile);

    return 0;
}

//returns -1 if not opened
int sizeOfFile(const char *filename) {
    ifstream readFile(filename);

    if (!readFile.is_open())
        return -1;

    unsigned currentPos = readFile.tellg();

    readFile.seekg(0, ios::end);
    unsigned result = readFile.tellg();

    readFile.seekg(currentPos);

    readFile.close();
    return result;
}

void initFile(File &myFile) {
    bool ok;

    do {
        ok = true;
        cout << "Enter a file path:" << endl;
        cin.getline(myFile.name, MAX_FILENAME_LENGTH);

        int size = sizeOfFile(myFile.name);
        if (size == -1) {
            cout << "Error while opening the file! Try again!" << endl;
            ok = false;
        } else {
            myFile.size = size;
            ok = myFile.setBytes();

            if (ok) {
                cout << "File loaded successfully! Size: " << myFile.size << " bytes" << endl;
            }
        }
    } while (!ok);

}

void menu(File &myFile) {
    while (true) {
        cout << "Enter a command:" << endl;
        char command[BUFFER_SIZE_CONSOLE];
        cin.getline(command, BUFFER_SIZE_CONSOLE);

        if (areStrEqual(command, VIEW_CMD)) { //view
            viewFile(myFile);
        } else if (areStrEqual(command, REMOVE_CMD)) { //remove
            if (myFile.size > 0) {
                myFile.size--;
                cout << "Removed 1 byte from the end!" << endl;
            } else {
                cout << "The size of this file is 0 bytes! Cannot remove bytes." << endl;
            }
        } else if (areStrEqual(command, SAVE_CMD)) { //save
            if (myFile.save()) {
                cout << "File successfully saved!" << endl;
            } else {
                cout << "Something went wrong!" << endl;
            }
            return;
        } else { //commands with more than 1 word (or wrong command)
            severalWordsMenu(command, myFile);
        }
    }
}

void severalWordsMenu(const char *command, File &myFile) {
    size_t index = 0;

    char first[BUFFER_SIZE_CONSOLE] = "";
    getNextWord(command, first, index);

    char second[BUFFER_SIZE_CONSOLE] = "";
    getNextWord(command, second, index);

    char as[] = "as";
    if (areStrEqual(first, SAVE_CMD) && areStrEqual(second, as)) { //save as <filename>
        char filename[BUFFER_SIZE_CONSOLE] = "";
        getNextWord(command, filename, index);

        if (myFile.save(filename)) {
            cout << "Saved successfully as " << filename << endl;
            return;
        } else {
            cout << "Something went wrong!" << endl;
        }
    } else if (areStrEqual(first, ADD_CMD)) { //add <byte>
        //byte = second
        int byteDec = hexToDec(second);
        if (byteDec == -1) {
            cout << "You must enter a valid byte that is 2 characters long!" << endl;
            return;
        }

        myFile.add(byteDec);
        cout << "Byte " << second << " added successfully!" << endl;
    } else if (areStrEqual(first, CHANGE_CMD)) { //change <index> <value>
        int byteIndex = toNumber(second);
        if (byteIndex < 0 || byteIndex >= myFile.size) {
            cout << "The index of the byte to change must be greater than 0 and lower than the size of the file ("
                 << myFile.size << " bytes)!" << endl;
            return;
        }

        char value[BUFFER_SIZE_CONSOLE] = "";
        getNextWord(command, value, index);

        int byteDec = hexToDec(value);
        if (byteDec == -1) {
            cout << "You must enter a valid byte that is 2 characters long!" << endl;
            return;
        }

        myFile.change(byteIndex, byteDec);
        cout << "Successfully changed the byte on index " << byteIndex << " to value " << value << "!" << endl;
    } else {
        cout << "Invalid command!" << endl;
    }
}

void viewFile(const File &myFile) {
    for (int i = 0; i < myFile.size; ++i) {
        char *toPrint = decToHex(myFile.bytes[i]);
        cout << toPrint << " ";
        delete[] toPrint;
    }

    cout << endl;
    for (int i = 0; i < myFile.size; ++i) {
        char toPrint = (char) myFile.bytes[i];

        if (isLower(toPrint) || isUpper(toPrint)) {
            cout << toPrint << " ";
        } else {
            cout << ". ";
        }
    }
    cout << endl;
}
