//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_SAVINGSACCOUNT_H
#define BANK_SYSTEM_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account{
private:
    double interestRate;

public:
    SavingsAccount() = default;

    SavingsAccount(const SavingsAccount &other) = default;

    SavingsAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount, double interestRate);

    void display() const;

    bool withdraw(double) override;

    double getInterestRate() const;

    Account *clone() const override;

};


#endif //BANK_SYSTEM_SAVINGSACCOUNT_H
