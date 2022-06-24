//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_ACCOUNT_H
#define BANK_SYSTEM_ACCOUNT_H

#include <ctime>

#include "String.h"

class Account { //abstract class
protected:
    enum Type{
        NORMAL,
        PRIVILEGE,
        SAVINGS
    }type;

    String username;
    String password;
    String iban;
    size_t ownerId;
    double amount;
    time_t dateOfCreation;

public:
    Account() = default;

    Account(const Account &other) = default;

    Account(const String &username, const String &password, const String &iban, size_t ownerId, double amount);

    virtual ~Account() = default;

    double getBalance() const;

    size_t getOwnerId() const;

    const String &getIban() const;

    const String& getUsername() const;

    const String &getPassword() const;

    void deposit(double value);

    virtual bool withdraw(double value) = 0;

    virtual void display() const;

    virtual Account *clone() const = 0;
};


#endif //BANK_SYSTEM_ACCOUNT_H
