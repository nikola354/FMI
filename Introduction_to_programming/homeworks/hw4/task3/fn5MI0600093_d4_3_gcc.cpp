/**
*
* Equation to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 3
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const char TERMINATE_SYMBOL = '\0';

const int DIGITS_COUNT = 10;
const int EQUATION_SIZE = 5;

//for each sign 0-9,  we make new row in a matrix (10x10)
//the value in each cell represents the possibility to make
// the index of the column from the index of the row by adding/removing/moving one stick

// 0 -> cannot make the index sign (which is the index in the array) from the sign in the name of the variable
// 1 -> make the index sign by ADDING one stick
// -1 -> make the index sign by REMOVING one stick
// 2 -> make the index sign only by MOVING one stick inside the number

// we can get "+" from "-" by ADDING one stick
// we can get "-" from "+" by REMOVING one stick
// we can NOT touch the equal sign "="

const int NUMBER_TRANSFORMATIONS[DIGITS_COUNT][DIGITS_COUNT] = {
        {0,  0,  0, 0,  0, 0,  2,  0, 1, 2},
        {0,  0,  0, 0,  0, 0,  0,  1, 0, 0},
        {0,  0,  0, 2,  0, 0,  0,  0, 0, 0},
        {0,  0,  2, 0,  0, 2,  0,  0, 0, 1},
        {0,  0,  0, 0,  0, 0,  0,  0, 0, 0},
        {0,  0,  0, 2,  0, 0,  1,  0, 0, 1},
        {2,  0,  0, 0,  0, -1, 0,  0, 1, 2},
        {0,  -1, 0, 0,  0, 0,  0,  0, 0, 0},
        {-1, 0,  0, 0,  0, 0,  -1, 0, 0, -1},
        {2,  0,  0, -1, 0, -1, 2,  0, 1, 0}
};

const char PLUS_SIGN = '+';
const char MINUS_SIGN = '-';
const char EQUALS_SIGN = '=';

const int ASCII_NUMBERS_BEGIN = 48;

char **findEquations(char *equation);

int toNumber(char a);

char toChar(int num);

bool isCorrectEquation(int firstNumber, char sign, int secondNumber, int result);

char *makeEquation(int firstNumber, char sign, int secondNumber, int result);

int compareStrings(const char *str1, const char *str2, int size);

int countEquations(char **equations);

void printAscending(char **equations);

int main() {
    char *equation = new char[EQUATION_SIZE];
    cin >> equation;

    char **equations = findEquations(equation);

    if (equations[0][0] == TERMINATE_SYMBOL) { //if the array is empty
        cout << "No" << endl;
    } else {
        printAscending(equations);
    }

    return 0;
}

char **findEquations(char *equation) {
    int firstNumber = toNumber(equation[0]);
    char sign = equation[1];
    int secondNumber = toNumber(equation[2]);
    int result = toNumber(equation[4]);

    char **correctEquations = new char *;
    int index = 0;

    for (int i = 0; i < DIGITS_COUNT; ++i) {
        //firstNumber can be changed to i by MOVING one stick INSIDE the number:
        if (NUMBER_TRANSFORMATIONS[firstNumber][i] == 2 && isCorrectEquation(i, sign, secondNumber, result)) {
            correctEquations[index] = makeEquation(i, sign, secondNumber, result);

            index++;
        } else if (NUMBER_TRANSFORMATIONS[firstNumber][i] == 1) {
            //we added one stick to the first number, now we search some symbol from which we can take it:

            if (sign == PLUS_SIGN && isCorrectEquation(i, MINUS_SIGN, secondNumber, result)) {
                correctEquations[index] = makeEquation(i, MINUS_SIGN, secondNumber, result);
                index++;
            }

            //check if we can take a stick from secondNumber or from the result:
            for (int j = 0; j < DIGITS_COUNT; ++j) {
                if (NUMBER_TRANSFORMATIONS[secondNumber][j] == -1 && isCorrectEquation(i, sign, j, result)) {
                    correctEquations[index] = makeEquation(i, sign, j, result);
                    index++;
                }

                if (NUMBER_TRANSFORMATIONS[result][j] == -1 && isCorrectEquation(i, sign, secondNumber, j)) {
                    correctEquations[index] = makeEquation(i, sign, secondNumber, j);
                    index++;
                }
            }
        } else if (NUMBER_TRANSFORMATIONS[firstNumber][i] == -1) { //REMOVE one stick
            //we removed one stick from the first number, now we search some symbol to which we can add it:

            if (sign == MINUS_SIGN && isCorrectEquation(i, PLUS_SIGN, secondNumber, result)) {
                correctEquations[index] = makeEquation(i, PLUS_SIGN, secondNumber, result);
                index++;
            }

            //check if we can add a stick to secondNumber or to the result:
            for (int j = 0; j < DIGITS_COUNT; ++j) {
                if (NUMBER_TRANSFORMATIONS[secondNumber][j] == 1 && isCorrectEquation(i, sign, j, result)) {
                    correctEquations[index] = makeEquation(i, sign, j, result);
                    index++;
                }

                if (NUMBER_TRANSFORMATIONS[result][j] == 1 && isCorrectEquation(i, sign, secondNumber, j)) {
                    correctEquations[index] = makeEquation(i, sign, secondNumber, j);
                    index++;
                }
            }
        }

        //-----SECOND NUMBER    -  what can we do with it:

        //move one stick inside the number:
        if (NUMBER_TRANSFORMATIONS[secondNumber][i] == 2 && isCorrectEquation(firstNumber, sign, i, result)) {
            correctEquations[index] = makeEquation(firstNumber, sign, i, result);
            index++;
        } else if (NUMBER_TRANSFORMATIONS[secondNumber][i] == 1) { //ADD a stick to the number
            //we added one stick to the second number, now we search some symbol from which we can take it:

            if (sign == PLUS_SIGN && isCorrectEquation(firstNumber, MINUS_SIGN, i, result)) {
                correctEquations[index] = makeEquation(firstNumber, MINUS_SIGN, i, result);
                index++;
            }

            //check if we can take a stick from the result:
            for (int j = 0; j < DIGITS_COUNT; ++j) {
                if (NUMBER_TRANSFORMATIONS[result][j] == -1 && isCorrectEquation(firstNumber, sign, i, j)) {
                    correctEquations[index] = makeEquation(firstNumber, sign, i, j);
                    index++;
                }
            }
        } else if (NUMBER_TRANSFORMATIONS[secondNumber][i] == -1) { //REMOVE one stick
            //we removed one stick from the second number, now we search some symbol to which we can add it:

            if (sign == MINUS_SIGN && isCorrectEquation(firstNumber, PLUS_SIGN, i, result)) {
                correctEquations[index] = makeEquation(firstNumber, PLUS_SIGN, i, result);
                index++;
            }

            //check if we can add a stick to the result:
            for (int j = 0; j < DIGITS_COUNT; ++j) {
                if (NUMBER_TRANSFORMATIONS[result][j] == 1 && isCorrectEquation(firstNumber, sign, i, j)) {
                    correctEquations[index] = makeEquation(firstNumber, sign, i, j);
                    index++;
                }
            }
        }

        //-------RESULT NUMBER      -  what can we do with it:

        //move one stick inside the number:
        if (NUMBER_TRANSFORMATIONS[result][i] == 2 && isCorrectEquation(firstNumber, sign, secondNumber, i)) {
            correctEquations[index] = makeEquation(firstNumber, sign, secondNumber, i);
            index++;
        } else if (NUMBER_TRANSFORMATIONS[result][i] == 1 && sign == PLUS_SIGN &&
                   isCorrectEquation(firstNumber, MINUS_SIGN, secondNumber,
                                     i)) {  //if we add a stick to the result and remove a stick from the plus sign
            correctEquations[index] = makeEquation(firstNumber, MINUS_SIGN, secondNumber, i);
            index++;
        } else if (NUMBER_TRANSFORMATIONS[result][i] == -1 && sign == MINUS_SIGN &&
                   isCorrectEquation(firstNumber, PLUS_SIGN, secondNumber,
                                     i)) { //if we remove a stick from the result and add a stick to the minus sign
            correctEquations[index] = makeEquation(firstNumber, PLUS_SIGN, secondNumber, i);
            index++;
        }
    }

    correctEquations[index] = new char[1];
    correctEquations[index][0] = TERMINATE_SYMBOL; //to show that the array is over

    return correctEquations;
}

int toNumber(char a) {
    return (int) a - ASCII_NUMBERS_BEGIN;
}

char toChar(int number) {
    return (char) (number + ASCII_NUMBERS_BEGIN);
}

bool isCorrectEquation(int firstNumber, char sign, int secondNumber, int result) {
    if (sign == PLUS_SIGN) {
        return (firstNumber + secondNumber == result);
    } else {
        return (firstNumber - secondNumber == result);
    }
}

char *makeEquation(int firstNumber, char sign, int secondNumber, int result) {
    char *equation = new char[EQUATION_SIZE];

    equation[0] = toChar(firstNumber);
    equation[1] = sign;
    equation[2] = toChar(secondNumber);
    equation[3] = EQUALS_SIGN;
    equation[4] = toChar(result);

    return equation;
}

int compareStrings(const char *str1, const char *str2, int size) {
    for (int i = 0; i < size; ++i) {
        if (str1[i] < str2[i]) return -1;

        if (str1[i] > str2[i]) return 1;
    }

    return 0;
}

int countEquations(char **equations) {
    int counter = 0;
    while (equations[counter][0] != TERMINATE_SYMBOL) {
        counter++;
    }

    return counter;
}

void printAscending(char **equations) {
    char *minString = equations[0];
    int equationsCount = countEquations(equations);

    for (int j = 0; j < equationsCount; ++j) {
        for (int i = 0; equations[i][0] != TERMINATE_SYMBOL; ++i) {
            if (compareStrings(equations[i], minString, EQUATION_SIZE) == -1) {
                minString = equations[i];
            }
        }

        cout << minString << endl;
        //enough big value, so the first equation will replace it
        minString[0] = (char) (ASCII_NUMBERS_BEGIN + DIGITS_COUNT);
    }
}