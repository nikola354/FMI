//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_LOG_H
#define BANK_SYSTEM_LOG_H

#include <fstream>

#include "String.h"
#include "Vector.h"
#include "Customer.h"
#include "helpers.h"
#include "Account.h"

const char LOG_FILENAME[] = "log.txt";

class Log {
    size_t exportedTillIIndex = 0; //the log file is never truncated, so we have to export only the not exported stuff
    Vector<String> log;

public:
    void addCustomer(const Customer &customer);

    void addAccount(const Account *account);

    void deleteCustomer(const Customer &customer);

    void deleteAccount(const Account *account);

    void exportLog();

    void display() const;

    void withdraw(const Account *account);

    void deposit(const Account *account);
};


#endif //BANK_SYSTEM_LOG_H
