//
// Created by nikola354 on 01.06.22.
//

#include "../headers/SavingsAccount.h"

void SavingsAccount::display() const {
    std::cout << "Savings account| Interest rate: " << interestRate << "| ";
    Account::display();
    std::cout << std::endl;
}

bool SavingsAccount::withdraw(double value) {
    return false;
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}

Account *SavingsAccount::clone() const {
    return new SavingsAccount(*this);
}

SavingsAccount::SavingsAccount(const String &username, const String &password, const String &iban, size_t ownerId, double amount, double interestRate)
        : Account(username,
                  password,
                  iban,
                  ownerId,
                  amount) {
    this->interestRate = interestRate;
    type = Account::Type::SAVINGS;
}
