#include <iostream>
#include <fstream>

using namespace std;

const int MAX_PAIRS = 25;
const char READFILE[] = "relation.txt";
const char WRITEFILE[] = "relation_write.txt";


struct Pair {
    int x;
    int y;
};

struct Relation {
    Pair pairs[MAX_PAIRS];
    int size = 0;
};

bool readRelationFromFile(Relation &r);

void writeRelationToFile(const Relation &r);

int main() {
    Relation relation = *new Relation();

    cout << boolalpha << readRelationFromFile(relation) << endl;
    cout << relation.size << endl;

    writeRelationToFile(relation);

    return 0;
}

void readPairFromFile(ifstream &readFile, Pair &pair) {
    readFile >> pair.x >> pair.y;
}

bool readRelationFromFile(Relation &r) {
    ifstream readFile(READFILE);

    if (!readFile.is_open()) {
        return false;
    }

    while (!readFile.eof()) {
        readPairFromFile(readFile, r.pairs[r.size]);
        r.size++;
    }
    r.size--;

    readFile.close();
    return true;
}

void writePairToFile(ofstream &writeFile, const Pair &pair) {
    writeFile << pair.x << " " << pair.y << endl;
}

void writeRelationToFile(const Relation &r) {
    ofstream writeFile(WRITEFILE);

    for (int i = 0; i < r.size; ++i) {
        writePairToFile(writeFile, r.pairs[i]);
    }
    writeFile.close();
}