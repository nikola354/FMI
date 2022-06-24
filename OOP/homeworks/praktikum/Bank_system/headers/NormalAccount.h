//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_NORMALACCOUNT_H
#define BANK_SYSTEM_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account{

public:
    NormalAccount() = default;

    NormalAccount(const NormalAccount &other) = default;

    NormalAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount);

    bool withdraw(double value);

    void display() const;

    Account *clone() const override;
};


#endif //BANK_SYSTEM_NORMALACCOUNT_H
