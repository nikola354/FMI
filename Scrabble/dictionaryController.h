/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @compiler GCC
*
* <files for actions with the dictionary>
*
*/

#ifndef SCRABBLE_DICTIONARYCONTROLLER_H
#define SCRABBLE_DICTIONARYCONTROLLER_H

#include <fstream>

const char path[] = "../words.txt";

const int WORD_MIN_LENGTH = 2;
const int WORD_MAX_LENGTH = 30;


bool isInDictionary(const string &word) {
    fstream dictionary;

    dictionary.open(path, fstream::in);
    if (!dictionary.is_open()) {
        std::cout << "System error! Could not open dictionary!" << endl;
        return false;
    }

    string vocabulary;
    while (getline(dictionary, vocabulary)) {
        if (word == vocabulary) {
            dictionary.close();
            return true;
        }
    }

    dictionary.close();
    return false;
}

bool addToDictionary(const string &word) {
    fstream dictionary;

    dictionary.open(path, fstream::out | fstream::app);
    if (!dictionary.is_open()) {
        std::cout << "System error! Could not open dictionary!" << endl;
        return false;
    }

    dictionary << word << endl;

    dictionary.close();

    return isInDictionary(word); //if the word is not added, return false
}

void addNewWord() {
    cout << "Type a word which has between " << WORD_MIN_LENGTH << " and " << WORD_MAX_LENGTH
         << " lower letters or type 0 to go back:" << endl;

    string input;
    cin >> input;

    if (input == "0")
        return mainMenu();

    if (input.size() < WORD_MIN_LENGTH || input.size() > WORD_MAX_LENGTH) {
        cout << "The length of the word must be between " << WORD_MIN_LENGTH << " and " << WORD_MAX_LENGTH
             << " characters!" << endl;
        return addNewWord();
    }

    if (!isWord(input)) {
        cout << "You can use only lower latin letters to make a word!" << endl;
        return addNewWord();
    }

    if (isInDictionary(input)) {
        cout << "Nothing added! The word is already in the dictionary!" << endl;
    } else {
        bool added = addToDictionary(input);

        if (!added) {
            cout << "Nothing added! Something went wrong. ";
        } else {
            cout << "Successfully added the word: \"" << input << "\". ";
        }
    }

    cout << "Returning to main menu..." << endl;
    mainMenu();
}

#endif //SCRABBLE_DICTIONARYCONTROLLER_H