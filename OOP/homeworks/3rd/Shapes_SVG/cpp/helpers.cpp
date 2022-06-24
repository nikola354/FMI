//
// Created by nikola354 on 31.05.22.
//
#include "../headers/helpers.h"

bool isBetween(double number, double first, double second) {
    if (first < second) {
        return number >= first && number <= second;
    } else {
        return number <= first && number >= second;
    }
}

double min(double f, double s) {
    return (f < s) ? f : s;
}

double max(double f, double s) {
    return (f > s) ? f : s;
}