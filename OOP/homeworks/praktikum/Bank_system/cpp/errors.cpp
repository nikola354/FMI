//
// Created by nikola354 on 01.06.22.
//

#include "../headers/errors.h"

const String &positiveNumberError(const String &field) {
    String result = "The ";
    result += (field + " must be positive number!");
    return result;
}

const String &positiveDoubleError(const String &field) {
    String result = "The ";
    result += (field + " must be positive (decimal) number!");
    return result;
}