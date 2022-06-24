//
// Created by nikola354 on 01.06.22.
//

#ifndef BANK_SYSTEM_PRIVILEGEACCOUNT_H
#define BANK_SYSTEM_PRIVILEGEACCOUNT_H

#include "Account.h"

class PrivilegeAccount : public Account{
    double overdraft;

public:
    PrivilegeAccount() = default;

    PrivilegeAccount(const PrivilegeAccount &other) = default;

    PrivilegeAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount, double overdraft);

    double getOverdraft() const;

    bool withdraw(double value) override;

    void display() const override;

    Account *clone() const override;
};


#endif //BANK_SYSTEM_PRIVILEGEACCOUNT_H
