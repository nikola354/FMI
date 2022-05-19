//
// Created by nikola354 on 02.05.22.
//

#ifndef FMI_KINDLE_MENU_H
#define FMI_KINDLE_MENU_H

#include <iostream>

#include "constants.h"
#include "Kindle.h"

void loadMenu(Kindle &k);

void signUp(Kindle &k, User &auth);

void login(Kindle &k, User &auth);

void writeBook(Kindle &k, User &auth);

void readBook(Kindle &k, User &auth, const char *title);

void editBook(Kindle &k, User &auth, const char *title);

void insertPage(Kindle &k, const Book &book);

void addPage(Kindle &k, const Book &book);

void changeTitle(Kindle &k, const Book &book);

void editPage(Kindle &k, const Book &book, int pageNumber);

void editPageMenu(Kindle &k, const Book &book);

void rateBook(Kindle &k, User &auth, const char *title, int rate);

void printRates(Kindle &k, const char *title);

void commentBook(Kindle &k, User &auth, const char *title, const char *comment);

void printComments(Kindle &k, const char *title);

#endif //FMI_KINDLE_MENU_H
