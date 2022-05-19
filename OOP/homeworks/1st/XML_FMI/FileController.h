#ifndef INC_2_FILECONTROLLER_H
#define INC_2_FILECONTROLLER_H

bool writeToFile(const Student *students, int studentsCount, const char *filename) {
    ofstream writeFile(filename, ios::in);

    if (writeFile.fail()) { //the file does not exist
        return false;
    }

    for (int i = 0; i < studentsCount; ++i) {
        students[i].writeToFile(writeFile);
    }

    writeFile.close();
    return true;
}


int getFileSize(const char *filename) { //returns -1 if the file is not open
    ifstream readFile(filename);

    if (!readFile.is_open())
        return -1;

    readFile.seekg(0, ios::end);
    int size = readFile.tellg();

    readFile.close();
    return size;
}

bool fillBuffer(const char *filename, char *buffer) { //fills the buffer with the content of the whole file
    ifstream readFile(filename);

    if (!readFile.is_open())
        return false;

    size_t bufferIndex = 0;
    while (!readFile.eof()) {
        char line[FILE_BUFFER_SIZE];
        readFile.getline(line, FILE_BUFFER_SIZE);

        size_t index = 0;
        while (line[index] != TERMINATE_SYMBOL) {
            buffer[bufferIndex] = line[index];
            index++;
            bufferIndex++;
        }
    }
    buffer[bufferIndex] = TERMINATE_SYMBOL;

    readFile.close();
    return true;
}

#endif
