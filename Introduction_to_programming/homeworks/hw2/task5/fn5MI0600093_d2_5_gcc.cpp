/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Nikola Manolov
* @idnumber 5MI0600093
* @task 5
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

const int MINUTE = 60; //60seconds
const int HOUR = MINUTE * 60; // 60 * 60 = 3600 seconds
const int DAY = HOUR * 24; // 24 * 60 * 60 = 86400
const int START_YEAR = 1970;

const int LONG_MONTH = 31;
const int SHORT_MONTH = 30;
const int FEBRUARY_DAYS = 28;

int sumMonthDays(int arr[12], int month) {
    int sum = 0;
    for (int i = 0; i <= month; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int seconds;
    cin >> seconds;

    if (seconds < 0){ //validation
        cout << "-1"; //end program
        return 0;
    }

    int years = seconds / (365.242196 * DAY); //one year has approx. 365.25 days

    int leapDays = (years + 2) / 4; //starting in 1970, the first leap year is 1972, then 1976, 1980...
    seconds -= ((years * 365 + leapDays) * DAY); //seconds left without the years

    int days = seconds / DAY + 1; //number of day in the year
    seconds -= (days-1) * DAY; //seconds left without the days
    int monthDays[12] = {LONG_MONTH, FEBRUARY_DAYS, LONG_MONTH, SHORT_MONTH, LONG_MONTH, SHORT_MONTH, LONG_MONTH,
                         LONG_MONTH, SHORT_MONTH, LONG_MONTH, SHORT_MONTH, LONG_MONTH};

    if ((years + 2) % 4 == 0) { //in leap years february has 29 days
        monthDays[1] = 29;
        days++;
    }

    //find the month and date
    int month = 0;
    int date = 0;
    for (int i = 0; i <= 11; i++) {
        if (days <= sumMonthDays(monthDays, i)) {
            date = days - (sumMonthDays(monthDays, i - 1));
            month = i + 1;
            break;
        }
    }

    //print date.month.year
    cout << (date < 10 ? "0" : "") << date << "." << (month < 10 ? "0" : "") << month << "." << years + START_YEAR
         << " ";

    int hours = seconds / HOUR;

    seconds -= hours * HOUR; //seconds left without hours (only minutes and seconds)
    int minutes = seconds / MINUTE;

    seconds -= minutes * MINUTE;

    cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;

    return 0;
}
