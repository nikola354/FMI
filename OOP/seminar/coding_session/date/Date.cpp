#include "Date.h"

const int BEGIN_YEAR = 1970;

bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

Date::Date() {
    date = 1;
    month = 1;
    year = 2000;
}

Date::Date(unsigned date, unsigned month, unsigned year) {
    this->date = date;
    this->month = month;
    this->year = year;
}

int Date::toDays() const {
    if (this->year < BEGIN_YEAR)
        return -1;

    int days = 0;
    int currentYear = BEGIN_YEAR;

    while (!isLeapYear(currentYear) && currentYear < this->year) {
        days += 365;
        currentYear++;
    }

    if (this->year == currentYear) {

    } else {
        days += 366;
    }

    for (int i = currentYear; i < this->year; i+=4) {

    }

}

//bool Date::isValid() const {
//    if (month < 1 || month > 12)
//        return false;
//
//    if (month == 1 || month == 3 || month == 5 || month == 7 || month || month == 8 || month == 10 || month == 12) {
//        if (date != 31)
//            return false;
//    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
//        if (date != 30)
//            return false;
//    } else if (month == 2) {
//
//    }
//
//}
