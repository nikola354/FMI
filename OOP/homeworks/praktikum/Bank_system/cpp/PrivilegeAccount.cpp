//
// Created by nikola354 on 01.06.22.
//

#include "../headers/PrivilegeAccount.h"

double PrivilegeAccount::getOverdraft() const {
    return overdraft;
}

bool PrivilegeAccount::withdraw(double value) {
    if (overdraft + amount < value)
        return false;

    amount -= value;
    return true;
}

void PrivilegeAccount::display() const {
    std::cout << "Savings account| Overdraft: " << overdraft << "| ";
    Account::display();
    std::cout << std::endl;
}

Account *PrivilegeAccount::clone() const {
    return new PrivilegeAccount(*this);
}

PrivilegeAccount::PrivilegeAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount, double overdraft)
        : Account(username, password, iban, ownerId, amount) {
    this->overdraft = overdraft;
    type = Account::Type::PRIVILEGE;
}
