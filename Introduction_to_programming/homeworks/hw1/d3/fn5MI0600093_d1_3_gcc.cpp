/**
*
* Solution to homework assignment 1
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

const int FACEBOOKFINE = 150;
const int INSTAGRAMFINE = 100;
const int REDDITFINE = 50;

int main() {
    int openTabs, salary, counter = 0;
    char tab;

    cin >> openTabs >> salary;

    //validation:
    if (openTabs < 1 || openTabs > 10 || salary < 700 || salary > 1500){
        cout << "-1"; //end program
        return 0;
    }

    while(cin >> tab){
        if (tab == 'f' || tab == 'F')
            salary -= FACEBOOKFINE;
        else if (tab == 'i' || tab == 'I')
            salary -= INSTAGRAMFINE;
        else if (tab == 'r' || tab == 'R')
            salary -= REDDITFINE;
        else if (tab != 'd' && tab != 'D'){ //wrong entry
            cout << "-1"; //end program
            return 0;
        }

        if (salary <= 0){
            cout << "You have lost your salary.";
            return 0;
        }

        if (++counter >= openTabs) break;
    }

    //if there is salary left, we print it
    cout << salary;

    return 0;
}