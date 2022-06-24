//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_DIALOG_H
#define BANK_SYSTEM_DIALOG_H

#include "Bank.h"
#include "errors.h"

class Dialog {
    Bank bank;
    size_t customerId;

public:
    Dialog();

    void welcomeDialog();

    void editDialog();

    void editCustomerDialog();

    void editAccountDialog();

    void addCustomerDialog();

    void deleteCustomerDialog();

    void addAccountDialog();

    void deleteAccountDialog();

    void listDialog();

    void listCustomerAccountsDialog();

    size_t getCustomerIdDialog();

    void actionDialog();

    String getAccountIbanDialog();

    void withdrawDialog();

    void depositDialog();

    void transferDialog();

    double getAmountDialog();
};


#endif //BANK_SYSTEM_DIALOG_H
