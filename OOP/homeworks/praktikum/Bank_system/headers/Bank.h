//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_BANK_H
#define BANK_SYSTEM_BANK_H

#include "SavingsAccount.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "String.h"
#include "Customer.h"
#include "Vector.h"
#include "AccountsContainer.h"
#include "Log.h"

class Bank {
    String name;
    String address;
    Vector<Customer> customers;
    AccountsContainer accounts;
    Log log;

public:
    Bank() = default;

    Bank(const String &name, const String &address);

    bool addCustomer(const Customer &customer);

    bool addAccount(const Account *account);

    const Customer *getCustomerById(size_t id) const;

    int getCustomerIndexById(size_t id) const; //returns -1 if not exists

    bool deleteCustomer(size_t id);

    bool deleteAccount(const String &iban);

    void exportLog();

    void listCustomers() const;

    void listAccounts() const;

    bool listCustomerAccount(size_t customerId) const;

    void display() const;

    bool transfer(double amount, const String &fromIban, const String &toIban);

    void displayLog() const;

    const Account *getAccountByIban(const String &iban) const;

    bool withdraw(double amount, const String &fromIban);

    bool deposit(double amount, const String &iban);
};


#endif //BANK_SYSTEM_BANK_H
