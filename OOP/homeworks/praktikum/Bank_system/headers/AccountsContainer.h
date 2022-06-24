//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_ACCOUNTSCONTAINER_H
#define BANK_SYSTEM_ACCOUNTSCONTAINER_H

#include "Account.h"
#include "Customer.h"
#include "Log.h"


class AccountsContainer {
    Account **accounts;
    size_t size;
    size_t capacity;

public:
    AccountsContainer();

    ~AccountsContainer();

private:
    void free();

    void resize();

    void deleteAccount(size_t index, Log &log);

public:
    size_t getSize() const;

    void addAccount(const Account *obj);

    const Account *getAccountByIban(const String &iban) const;

    Account *getAccountByIban(const String &iban);

    void deleteRelatedAccounts(const Customer &customer, Log &log);

    bool deleteAccount(const String &iban, Log &log);

    void listAccounts() const;

    void listAccounts(size_t customerId) const;
};


#endif //BANK_SYSTEM_ACCOUNTSCONTAINER_H
