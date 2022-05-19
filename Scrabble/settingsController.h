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
* <file for settings functions>
*
*/

#ifndef SCRABBLE_SETTINGSCONTROLLER_H
#define SCRABBLE_SETTINGSCONTROLLER_H

const int MIN_ROUNDS = 3;
const int MAX_ROUNDS = 10;
const int MIN_LETTERS_COUNT = 5;
const int MAX_LETTERS_COUNT = 15;
const int MAX_SHUFFLES = 5;
const int MIN_SHUFFLES = 1;

void changeRounds();

void changeLettersCount();

void changeShuffles();

void settingsMenu() {
    ostringstream settingsMenu;
    settingsMenu << "Choose what do you want to change (1, 2, 3) or go back (4): " << endl;
    settingsMenu << "1. Number of rounds" << endl;
    settingsMenu << "2. Number of the given letters for every round" << endl;
    settingsMenu << "3. Number of allowed shuffles for the whole game" << endl;
    settingsMenu << "4. Back to main menu" << endl;

    cout << settingsMenu.str();

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
                changeRounds();
                break;
            case 2:
                changeLettersCount();
                break;
            case 3:
                changeShuffles();
                break;
            case 4:
                mainMenu();
                break;
            default:
                ok = false;
                cout << WRONG_INPUT_MSG << endl;
        }
    }
}

void changeRounds() {
    ostringstream menu;
    menu << "Choose the number of rounds (" << MIN_ROUNDS << "-" << MAX_ROUNDS << ") or type 0 to go back:" << endl;

    cout << menu.str();

    string input;
    cin >> input;

    if (!isNumber(input)) {
        cout << WRONG_INPUT_MSG << endl;
        return changeRounds();
    }

    int command = stoi(input);

    if (command == 0) {
        settingsMenu();
    } else if (command >= MIN_ROUNDS && command <= MAX_ROUNDS) {
        rounds = command; //change the rounds
        cout << "Rounds set to " << rounds << " successfully!" << endl;
        cout << "Returning to settings..." << endl;
        settingsMenu();
    } else {
        cout << WRONG_INPUT_MSG << endl;
        return changeRounds();
    }
}

void changeLettersCount() {
    ostringstream menu;
    menu << "Choose the number of given letters (" << MIN_LETTERS_COUNT << "-" << MAX_LETTERS_COUNT
         << ") or type 0 to go back:" << endl;

    cout << menu.str();

    string input;
    cin >> input;

    if (!isNumber(input)) {
        cout << WRONG_INPUT_MSG << endl;
        return changeLettersCount();
    }

    int command = stoi(input);

    if (command == 0) {
        settingsMenu();
    } else if (command >= MIN_LETTERS_COUNT && command <= MAX_LETTERS_COUNT) {
        lettersCount = command; //change the given letters
        cout << "Each round you will get " << lettersCount << " letters." << endl;
        cout << "Returning to settings..." << endl;
        settingsMenu();
    } else {
        cout << WRONG_INPUT_MSG << endl;
        return changeLettersCount();
    }
}

void changeShuffles() {
    ostringstream menu;
    menu << "Choose the maximum allowed shuffles for one game (" << MIN_SHUFFLES << "-" << MAX_SHUFFLES
         << ") or type 0 to go back:" << endl;

    cout << menu.str();

    string input;
    cin >> input;

    if (!isNumber(input)) {
        cout << WRONG_INPUT_MSG << endl;
        return changeShuffles();
    }

    int command = stoi(input);

    if (command == 0) {
        settingsMenu();
    } else if (command >= MIN_SHUFFLES && command <= MAX_SHUFFLES) {
        maxShuffles = command; //change the max shuffles allowed
        cout << "Each game you will have maximum " << maxShuffles << " shuffles." << endl;
        cout << "Returning to settings..." << endl;
        settingsMenu();
    } else {
        cout << WRONG_INPUT_MSG << endl;
        return changeShuffles();
    }
}
#endif