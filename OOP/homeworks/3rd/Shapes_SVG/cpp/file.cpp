//
// Created by nikola354 on 27.05.22.
//

#include "../headers/file.h"

bool checkFile(const String &filename) {
    std::ifstream readFile(filename.c_str());

    if (!readFile.is_open())
        return false;

    readFile.close();
    return true;
}

String fileToString(const String &filename) {
    std::ifstream readFile(filename.c_str());

    String result;
    String line;

    while(!readFile.eof()) {
        line.getLine(readFile);

        result += line;
    }

    readFile.close();
    return result;
}