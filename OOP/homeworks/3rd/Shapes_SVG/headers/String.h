#pragma once

#include <fstream>
#include <iostream>
#include <cstring>

const short BUFFER_SIZE = 1024;

const char TERMINATE_SYMBOL = '\0';

const char DECIMAL_SIGN = '.';
const char DECIMAL_SIGN2 = ',';


class String {
    char *str;
    size_t size;

    void copyFrom(const String &other);

    void free();

public:
    String();

    String(const char *);

    String(const String &);

    String(String &&); //move constructor that accepts rvalue;

    String &operator=(const String &other);

    String &operator=(String &&other);  //move op= that accepts rvalue;

    ~String();

    size_t getSize() const;

    void concat(const String &other);

    const char *c_str() const;

    String &operator+=(const String &other);

    friend std::ostream &operator<<(std::ostream &stream, const String &str);

    friend std::istream &operator>>(std::istream &stream, String &str);

    void getLine(std::istream &in);

    void goTo(char a); //erases the str before the char

    void goTo(const char *word); //erases the string before and including the given str

    void cut(unsigned index); //takes only the str after the index

    void trim();

    String takeTo(char symbol);

    void move(unsigned n); //moves the pointer n times forward

    double toDouble() const;

    static bool isDigit(char a);

    bool isDouble() const;

    bool isNumber() const;

    bool isPositiveNumber() const;

    bool isPositiveDouble() const;

    int toNumber() const;

};

String operator+(const String &lhs, const String &rhs);

bool operator==(const String &lhs, const String &rhs);

bool operator<=(const String &lhs, const String &rhs);

bool operator<(const String &lhs, const String &rhs);