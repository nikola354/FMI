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
* <main file>
*
*/

#include <iostream>
#include <sstream>


using namespace std;

int rounds = 5;
int lettersCount = 10;
int maxShuffles = 2;

const int MAX_TRIES = 3;
const char WRONG_INPUT_MSG[] = "Wrong input! Try again...";

void mainMenu();

void game();

//include headers after constants and declared functions in order to use them
#include "helpers.h"
#include "dictionaryController.h"
#include "settingsController.h"

int main() {
    cout << "Welcome to my scrabble game!" << endl << endl;

    mainMenu();

    return 0;
}

void mainMenu() {
    ostringstream welcomeMsgs;

    welcomeMsgs << "Choose one of the following options by typing 1, 2, 3 or 4:" << endl;
    welcomeMsgs << "1. Start new game" << endl;
    welcomeMsgs << "2. Settings" << endl;
    welcomeMsgs << "3. Add new word" << endl;
    welcomeMsgs << "4. Exit" << endl;

    cout << welcomeMsgs.str();

    string input;
    bool ok = false;
    while (!ok) {
        ok = true;

        cin >> input;
        if (!isNumber(input)) {
            ok = false;
            cout << WRONG_INPUT_MSG << endl;
            continue; //if the input is not real command, we go again to line 56 with ok = false
        }

        int command = stoi(input);

        switch (command) {
            case 1:
                game();
                break;
            case 2:
                settingsMenu();
                break;
            case 3:
                addNewWord();
                break;
            case 4:
                cout << "bye bye :)";
                return;
            default:
                ok = false;
                cout << WRONG_INPUT_MSG << endl;
        }
    }
}

void game() {
    int points = 0;
    int remainingShuffles = maxShuffles;

    for (int i = 0; i < rounds; ++i) {
        cout << "Round # " << i + 1 << ". Available letters: ";

        int *letters = generateLetters(lettersCount);
        printLetters(letters); // print the letters which the user can use to make a word

        int remainingTries = MAX_TRIES;
        string word;
        while (remainingTries > 0) {
            cin >> word;

            if (word == "1") { //Shuffle
                if (remainingShuffles == 0) {
                    cout << "No remaining shuffles! Continue with the same letters:" << endl;
                } else {
                    letters = generateLetters(lettersCount);

                    cout << "Remaining shuffles: " << --remainingShuffles << endl;
                    cout << "New letters: ";
                }

                printLetters(letters);
                continue;
            }

            if (word == "0") { //end game
                cout << "Game over! Returning to menu..." << endl;
                return mainMenu();
            }

            if (!isWord(word)) {
                cout << "You can use only lower latin letters or 0 to end the game or 1 to shuffle!" << endl;
                cout << "Try again with: ";
                printLetters(letters);
                continue;
            }

            //check if the word can be made from this letters
            bool isPossible = isPossibleWord(word, letters);
            if (!isPossible || !isInDictionary(word)) { //if it is not possible, or it is not in the dictionary
                remainingTries--;
                if (!isPossible) {
                    cout << "Invalid combination. You cannot make this word from the given letters." << endl;
                    cout << "Remaining tries: " << remainingTries << endl;
                } else {
                    cout << "This word is not in my dictionary. Remaining tries: " << remainingTries << endl;
                }

                if (remainingTries == 0) break;
                cout << "Try again with: ";
                printLetters(letters);
            } else {
                points += calculatePoints(word);

                if (i != rounds - 1) // if it is not the last round
                    cout << "Your points so far are: " << points << endl;

                break; //break the while cycle and continue to next round
            }
        }
    }

    cout << "Congrats! You reached the end of the game. Your total points are: " << points << endl;
    cout << "0. End game" << endl;
    cout << "1. Return to menu" << endl;

    int command;
    cin >> command;

    if (command == 0) return;

    mainMenu();
}