#ifndef DATE_DATE_H
#define DATE_DATE_H

class Date {

private:
    unsigned date;
    unsigned month;
    unsigned year;

public:
    Date();

    Date(unsigned, unsigned, unsigned);

    bool isValid() const;

    int toDays () const;
};

#endif
